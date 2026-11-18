// Voxel layer for the network viewer's 3D mode (index.html): the save's map voxels drawn
// with WebGL behind the 2D canvas, at full detail. Faces are greedy-meshed (one material
// class, direction and kind per rectangle) and culled to what can be seen from outside
// (air flood-filled from the sky and from the cut down). A height cut leaves solid lids.
// Data: the server's /api/voxels?save=NAME (tools/voxel_data.py) or a save's JSON.
import * as THREE from "https://unpkg.com/three@0.160.0/build/three.module.js";

// ---------- materials (voxel values; see tools/dig.py and NOTES.md) ----------
export const MAT = {
  dirt:  { c: [139, 98, 62],  vals: [1, 3, 10], name: "dirt (diggable)" },
  hard:  { c: [112, 112, 118], vals: [43, 44], name: "hard rock" },
  metal: { c: [120, 140, 160], vals: [6, 8, 16], name: "metal" },
  wood:  { c: [160, 112, 60],  vals: [14], name: "wood" },
  water: { c: [58, 120, 200],  vals: [18, 19, 20, 21], name: "water" },
  stone: { c: [168, 164, 148], vals: [], name: "stone / other" },
};
const COLOR = new Array(256).fill(MAT.stone.c);
for (const m of Object.values(MAT)) for (const v of m.vals) COLOR[v] = m.c;
const DIRT = new Uint8Array(256); for (const v of MAT.dirt.vals) DIRT[v] = 1;

const workerSrc = `
let keys = null, data = null, nb = null, ext = null, colTop = null, gen = 0;
let meshedKey = new Map();
const N = 32, S = 0.5, V = 32768;
const DX = [1, -1, 0, 0, 0, 0], DY = [0, 0, 1, -1, 0, 0], DZ = [0, 0, 0, 0, 1, -1];
const SHADE = [[0.80, 0.70], [1.00, 0.45], [0.88, 0.62]];
const CUT_SHADE = 0.58;
let air = null;                                   // per material value: counts as air?
let CLASS = null, COLOR = null;
let index = new Map();
function relink() {                                // neighbours, column tops, flood buffer
  index = new Map(); keys.forEach((k, i) => index.set(k.join(","), i));
  nb = new Int32Array(keys.length * 6);
  // the highest stored chunk of each column: above it is open sky
  colTop = new Map();
  for (const [x, y, z] of keys) { const k = x + "," + z; if (!(colTop.get(k) >= y)) colTop.set(k, y); }
  keys.forEach(([x, y, z], i) => { for (let d = 0; d < 6; d++) { const j = index.get((x + DX[d]) + "," + (y + DY[d]) + "," + (z + DZ[d])); nb[i * 6 + d] = j === undefined ? -1 : j; } });
  ext = new Uint8Array(keys.length * V);
}
function init(m) {
  keys = m.keys; data = new Uint8Array(m.buf);
  relink();
  meshedKey = new Map();
}
// changed chunks from the live game: replace their voxels (adding new chunks), and make
// them and their neighbours re-mesh on the next build
function update(m) {
  const buf = new Uint8Array(m.buf), touched = [], fresh = [];
  m.keys.forEach((k, n) => {
    const i = index.get(k.join(","));
    if (i === undefined) fresh.push([k, n]);
    else { data.set(buf.subarray(n * V, (n + 1) * V), i * V); touched.push(i); }
  });
  if (fresh.length) {
    const nd = new Uint8Array((keys.length + fresh.length) * V);
    nd.set(data);
    for (const [k, n] of fresh) { nd.set(buf.subarray(n * V, (n + 1) * V), keys.length * V); touched.push(keys.length); keys.push(k); }
    data = nd;
    relink();
  }
  for (const i of touched) {
    meshedKey.delete(i);
    for (let d = 0; d < 6; d++) { const j = nb[i * 6 + d]; if (j >= 0) meshedKey.delete(j); }
  }
}
// flood the air reachable from outside: the sky above the top chunks, and the open space
// above the top cut (clip) and below the bottom cut (lo); only voxels in the slab are kept
function flood(clip, lo) {
  ext.fill(0);
  let q = new Uint32Array(1 << 22), head = 0, tail = 0;
  const push = (i, l) => { if (tail >= q.length) { const n = new Uint32Array(q.length * 2); n.set(q); q = n; } q[tail++] = i * V + l; };
  for (let i = 0; i < keys.length; i++) {
    const cy = keys[i][1], base = i * V, sky = colTop.get(keys[i][0] + "," + keys[i][2]) === cy;
    for (let y = 0; y < N; y++) {
      const yb = (cy * N + y) * S;
      if (yb >= clip) break;                                      // above the top cut
      if (yb < lo) continue;                                      // below the bottom cut
      const edge = yb + S >= clip || (y === N - 1 && sky) || yb - S < lo;
      if (!edge) continue;
      for (let z = 0; z < N; z++) for (let x = 0; x < N; x++) {
        const l = (z * N + y) * N + x;
        if (air[data[base + l]] && !ext[base + l]) { ext[base + l] = 1; push(i, l); }
      }
    }
  }
  while (head < tail) {
    const g = q[head++], i = (g / V) | 0, l = g - i * V;
    const x = l & 31, y = (l >> 5) & 31, z = l >> 10, cy = keys[i][1];
    for (let d = 0; d < 6; d++) {
      let X = x + DX[d], Y = y + DY[d], Z = z + DZ[d], j = i;
      if (X < 0 || Y < 0 || Z < 0 || X >= N || Y >= N || Z >= N) {
        j = nb[i * 6 + d]; if (j < 0) continue;
        X &= 31; Y &= 31; Z &= 31;
      }
      const yb = (keys[j][1] * N + Y) * S;
      if (yb >= clip || yb < lo) continue;                      // outside the slab: open anyway
      const L = (Z * N + Y) * N + X, G = j * V + L;
      if (!ext[G] && air[data[G]]) { ext[G] = 1; push(j, L); }
    }
  }
}
function sig(i) {                                  // FNV of a chunk's reached-air bits
  let h = 0x811C9DC5 | 0; const b = i * V;
  for (let l = 0; l < V; l += 4) h = Math.imul(h ^ (ext[b + l] | ext[b + l + 1] << 1 | ext[b + l + 2] << 2 | ext[b + l + 3] << 3), 16777619);
  return h >>> 0;
}
function mesh(i, clip, lo) {
  const [cx, cy, cz] = keys[i], base = i * V, o = [cx * N, cy * N, cz * N];
  const kept = y => { const yb = (o[1] + y) * S; return yb < clip && yb >= lo; };
  const pos = [], col = [], idx = [];
  const mask = new Int32Array(N * N), p = [0, 0, 0];
  for (let a = 0; a < 3; a++) {
    const b = (a + 1) % 3, c = (a + 2) % 3;
    for (const sgn of [1, -1]) {
      const d = a * 2 + (sgn > 0 ? 0 : 1);
      // our axis order is x, y, z = 0, 1, 2; neighbour directions DX/DY/DZ index d
      for (let t = 0; t < N; t++) {
        let any = false;
        for (let u = 0; u < N; u++) for (let v = 0; v < N; v++) {
          p[a] = t; p[b] = u; p[c] = v;
          const l = (p[2] * N + p[1]) * N + p[0], m = data[base + l];
          let k = 0;
          if (!air[m] && kept(p[1])) {
            let X = p[0] + DX[d], Y = p[1] + DY[d], Z = p[2] + DZ[d], j = i;
            const cut = !kept(Y);
            if (X < 0 || Y < 0 || Z < 0 || X >= N || Y >= N || Z >= N) { j = nb[i * 6 + d]; X &= 31; Y &= 31; Z &= 31; }
            const G = j >= 0 ? j * V + (Z * N + Y) * N + X : -1;
            if (cut) k = G >= 0 && air[data[G]] ? CLASS[m] : CLASS[m] + 256;   // open air above the cut / a lid
            else if (G >= 0 && air[data[G]] && ext[G]) k = CLASS[m];          // air reached from outside
          }
          mask[u * N + v] = k; if (k) any = true;
        }
        if (!any) continue;
        for (let u = 0; u < N; u++) for (let v = 0; v < N; ) {
          const k = mask[u * N + v];
          if (!k) { v++; continue; }
          let w = 1; while (v + w < N && mask[u * N + v + w] === k) w++;
          let h = 1;
          outer: while (u + h < N) { for (let x = 0; x < w; x++) if (mask[(u + h) * N + v + x] !== k) break outer; h++; }
          for (let y = 0; y < h; y++) for (let x = 0; x < w; x++) mask[(u + y) * N + v + x] = 0;
          const plane = t + (sgn > 0 ? 1 : 0), c0 = COLOR[k & 255];
          const sh = k > 255 ? CUT_SHADE : SHADE[a][sgn > 0 ? 0 : 1];
          const jit = 0.95 + 0.1 * (((u * 73856093) ^ (v * 19349663) ^ (t * 83492791) ^ (a * 2654435761)) & 255) / 255;
          const r = Math.min(255, c0[0] * sh * jit), g = Math.min(255, c0[1] * sh * jit), bl = Math.min(255, c0[2] * sh * jit);
          const first = pos.length / 3;
          const corners = sgn > 0 ? [[u, v], [u + h, v], [u + h, v + w], [u, v + w]]
                                  : [[u, v], [u, v + w], [u + h, v + w], [u + h, v]];
          for (const [U, Vv] of corners) {
            const P = [0, 0, 0]; P[a] = plane; P[b] = U; P[c] = Vv;
            pos.push((o[0] + P[0]) * S, (o[1] + P[1]) * S, (o[2] + P[2]) * S);
            col.push(r, g, bl);
          }
          idx.push(first, first + 1, first + 2, first, first + 2, first + 3);
          v += w;
        }
      }
    }
  }
  return { pos: new Float32Array(pos), col: new Uint8Array(col), idx: new Uint32Array(idx) };
}
async function build(m) {
  const my = gen = m.gen;
  air = new Uint8Array(256); air[0] = 1;
  if (m.hideDirt) for (let v = 0; v < 256; v++) if (m.DIRT[v]) air[v] = 1;
  CLASS = m.CLASS; COLOR = m.COLORS;
  if (m.reset) meshedKey = new Map();
  const t0 = performance.now();
  flood(m.clip, m.lo);
  const t1 = performance.now();
  const s = keys.map((_, i) => sig(i));
  // a chunk's mesh depends on a cut only while the cut is inside it (or at its edge, where
  // the neighbour's voxels next to it are cut away)
  const eff = i => {
    const bottom = keys[i][1] * 16, top = bottom + 16;
    const h = m.clip > top ? "f" : m.clip <= bottom ? "e" : String(Math.ceil(m.clip / S));
    const l = m.lo <= bottom - S ? "f" : m.lo >= top ? "e" : String(Math.ceil(m.lo / S));
    return h + "/" + l;
  };
  const todo = [];
  keys.forEach((_, i) => {
    let k = s[i] + ":" + eff(i) + ":" + (m.hideDirt ? 1 : 0);
    for (let d = 0; d < 6; d++) { const j = nb[i * 6 + d]; k += "," + (j < 0 ? "-" : s[j]); }
    if (meshedKey.get(i) !== k) { meshedKey.set(i, k); todo.push(i); }
  });
  const [px, py, pz] = m.cam;
  const dist = i => { const [x, y, z] = keys[i]; return (x * 16 + 8 - px) ** 2 + (y * 16 + 8 - py) ** 2 + (z * 16 + 8 - pz) ** 2; };
  todo.sort((a, b) => dist(a) - dist(b));
  postMessage({ gen: my, epoch: m.epoch, start: true, todo: todo.length, floodMs: Math.round(t1 - t0) });
  for (let k = 0; k < todo.length; k += 24) {
    if (gen !== my) { for (const i of todo.slice(k)) meshedKey.delete(i); return; }   // superseded
    const out = [];
    for (const i of todo.slice(k, k + 24)) { const r = mesh(i, m.clip, m.lo); out.push({ i, pos: r.pos, col: r.col, idx: r.idx }); }
    postMessage({ gen: my, epoch: m.epoch, out, left: Math.max(0, todo.length - k - 24) }, out.flatMap(o => [o.pos.buffer, o.col.buffer, o.idx.buffer]));
    await new Promise(r => setTimeout(r, 0));
  }
  postMessage({ gen: my, epoch: m.epoch, done: true, ms: Math.round(performance.now() - t0) });
}
onmessage = e => { const m = e.data; if (m.init) init(m); else if (m.update) update(m); else build(m); };`;

// ---------- the layer ----------
// A WebGL canvas behind the viewer's 2D canvas. Its orthographic camera is built from the
// viewer's 3D orbit (index.html proj3: yaw about Y, pitch down, centre, pan cam.x/cam.y,
// zoom cam.s in device pixels per unit), so voxels line up with the drawn nodes.
export function createVoxelLayer(stage, { onUpdate = () => {}, onStatus = () => {} } = {}) {
  const canvas = document.createElement("canvas");
  canvas.style.cssText = "position:absolute;inset:0;width:100%;height:100%;display:none";
  stage.insertBefore(canvas, stage.firstChild);
  const renderer = new THREE.WebGLRenderer({ canvas, antialias: true });
  const scene = new THREE.Scene();
  const camera = new THREE.OrthographicCamera(-1, 1, 1, -1, 0.1, 6000);
  const mat = new THREE.MeshBasicMaterial({ vertexColors: true, side: THREE.FrontSide });
  const group = new THREE.Group(); scene.add(group);
  const worker = new Worker(URL.createObjectURL(new Blob([workerSrc], { type: "text/javascript" })));
  const meshes = new Map();
  let world = null, gen = 0, epoch = 0, quads = 0, left = 0, floodMs = 0, lastMs = 0, building = false;
  let cut = 1e9, cutLo = -1e9, showDirt = true, visible = false, bg = "#111";

  const CLASS = new Uint8Array(256), COLORS = new Array(256).fill(MAT.stone.c);
  for (let v = 1; v < 256; v++) CLASS[v] = 250;
  COLORS[250] = MAT.stone.c;
  for (const m of Object.values(MAT)) for (const v of m.vals) { CLASS[v] = m.vals[0]; COLORS[m.vals[0]] = m.c; }

  function report() {
    if (!world) { onStatus(""); return; }
    onStatus((building ? `meshing voxels… ${left} chunks left · ` : "")
      + `${world.keys.length} chunks, ${(quads / 1e6).toFixed(2)}M faces`
      + (!building && lastMs ? ` · built in ${(lastMs / 1000).toFixed(1)} s` : ""));
  }
  // A mesh the worker finished is always applied (the worker counts it as done even if a
  // newer build started meanwhile; dropping it left stale chunks). Only meshes from before a
  // reload or a dirt on/off reset (an older epoch) are thrown away. gen is for the status.
  worker.onmessage = e => {
    const m = e.data;
    if (m.epoch !== epoch) return;
    if (m.start || m.done) {
      if (m.gen !== gen) return;
      if (m.start) { floodMs = m.floodMs; left = m.todo; building = m.todo > 0; }
      else { building = false; lastMs = m.ms; }
      report(); return;
    }
    for (const { i, pos, col, idx } of m.out) {
      const old = meshes.get(i);
      if (old) { group.remove(old); old.geometry.dispose(); meshes.delete(i); quads -= old.userData.quads; }
      if (!idx.length) continue;
      const g = new THREE.BufferGeometry();
      g.setAttribute("position", new THREE.BufferAttribute(pos, 3));
      g.setAttribute("color", new THREE.BufferAttribute(col, 3, true));
      g.setIndex(new THREE.BufferAttribute(idx, 1));
      g.computeBoundingSphere();
      const mm = new THREE.Mesh(g, mat);
      mm.userData = { quads: idx.length / 6 };
      meshes.set(i, mm); group.add(mm); quads += idx.length / 6;
    }
    if (m.gen === gen) left = m.left;
    report();
    onUpdate();
  };
  function rebuild(reset) {
    if (!world) return;
    gen++;
    if (reset) { epoch++; for (const mm of meshes.values()) { group.remove(mm); mm.geometry.dispose(); } meshes.clear(); quads = 0; }
    building = true;
    worker.postMessage({ gen, epoch, reset, clip: cut, lo: cutLo, hideDirt: !showDirt, DIRT, CLASS, COLORS, cam: lastCam });
    report();
  }
  let timer = null, lastCam = [0, 0, 0];
  const later = () => { clearTimeout(timer); timer = setTimeout(() => rebuild(false), 150); };

  function start(keys, voxels) {
    for (const mm of meshes.values()) { group.remove(mm); mm.geometry.dispose(); }
    meshes.clear(); quads = 0;
    world = { keys };
    worker.postMessage({ init: true, keys, buf: voxels }, [voxels]);
    rebuild(true);
  }
  return {
    canvas,
    get loaded() { return !!world; },
    // binary payload from the server's /api/voxels (tools/voxel_data.py)
    rev: null,                     // live voxel revision of what is loaded (server's VOX.rev)
    loadBinary(buf) {
      const dv = new DataView(buf), n = dv.getUint32(0, true);
      const head = JSON.parse(new TextDecoder().decode(new Uint8Array(buf, 4, n)));
      this.rev = head.rev ?? null;
      start(head.chunks, buf.slice(4 + n));
      return head;
    },
    // only the chunks that changed (server: /api/voxels?save=live&since=REV); a full
    // payload (a save was loaded) replaces everything
    updateBinary(buf) {
      const dv = new DataView(buf), n = dv.getUint32(0, true);
      const head = JSON.parse(new TextDecoder().decode(new Uint8Array(buf, 4, n)));
      if (!head.partial || !world) return this.loadBinary(buf);
      this.rev = head.rev;
      if (head.chunks.length) {
        const data = buf.slice(4 + n);
        worker.postMessage({ update: true, keys: head.chunks, buf: data }, [data]);
        for (const k of head.chunks) if (!world.keys.some(w => w[0] === k[0] && w[1] === k[1] && w[2] === k[2])) world.keys.push(k);
        rebuild(false);
      }
      return head;
    },
    // a save file's JSON (offline mode)
    loadSave(save) {
      const keys = [], parts = [];
      for (const [c, rle] of save.chunks || []) {
        const a = new Uint8Array(32768); let o = 0;
        for (const [cnt, v] of rle) { a.fill(Math.min(v, 255), o, o + cnt); o += cnt; }
        if (o !== 32768) continue;
        keys.push([c.x, c.y, c.z]); parts.push(a);
      }
      const vox = new Uint8Array(parts.length * 32768);
      parts.forEach((p, i) => vox.set(p, i * 32768));
      start(keys, vox.buffer);
    },
    clear() { gen++; world = null; for (const mm of meshes.values()) { group.remove(mm); mm.geometry.dispose(); } meshes.clear(); quads = 0; report(); },
    // keep only the slab lo <= y < hi (solid lids where either cut passes through rock)
    setCut(hi, lo = -1e9) {
      const h = Math.min(1e9, hi), l = Math.max(-1e9, lo);
      if (h !== cut || l !== cutLo) { cut = h; cutLo = l; later(); }
    },
    setShowDirt(b) { if (b !== showDirt) { showDirt = b; rebuild(true); } },
    setVisible(b) { visible = b; canvas.style.display = b ? "block" : "none"; },
    // orbit: { yaw, pitch, c: [x, y, z] }, cam: { x, y, s }, W/H: canvas size in device pixels
    render(orbit, cam, W, H, background) {
      if (!visible) return;
      if (renderer.getPixelRatio() !== 1) renderer.setPixelRatio(1);
      const sz = renderer.getSize(new THREE.Vector2());
      if (sz.x !== W || sz.y !== H) renderer.setSize(W, H, false);
      if (background && background !== bg) { bg = background; scene.background = new THREE.Color(bg.trim() || "#111"); }
      const cy = Math.cos(orbit.yaw), sy = Math.sin(orbit.yaw), cp = Math.cos(orbit.pitch), sp = Math.sin(orbit.pitch);
      const R = new THREE.Vector3(cy, 0, -sy), U = new THREE.Vector3(-sp * sy, cp, -sp * cy), F = new THREE.Vector3(cp * sy, sp, cp * cy);
      const C = new THREE.Vector3(...orbit.c).addScaledVector(R, cam.x).addScaledVector(U, -cam.y);
      camera.position.copy(C).addScaledVector(F, 3000);
      camera.quaternion.setFromRotationMatrix(new THREE.Matrix4().makeBasis(R, U, F));
      camera.left = -W / 2 / cam.s; camera.right = W / 2 / cam.s; camera.top = H / 2 / cam.s; camera.bottom = -H / 2 / cam.s;
      camera.updateProjectionMatrix();
      lastCam = [C.x + F.x * 100, C.y + F.y * 100, C.z + F.z * 100];
      renderer.render(scene, camera);
    },
  };
}
