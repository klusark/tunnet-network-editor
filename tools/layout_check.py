"""Check a generated save's physical layout: cable shapes (level / vertical / sloped),
longest cable, and whether each built node sits on the floor, in the air or inside rock.
    python tools/layout_check.py save.json
"""
import json,math,sys,os,collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import terrain as TR
s=json.load(open(sys.argv[1]))
T=TR.Terrain(s)
N=s['nodes']
typ={}
for lst in ('relays','hubs','filters','endpoints','bridges','antennas','testers'):
    for r in s[lst]: typ[r['node']]=lst
kinds=collections.Counter(); longest=0
for (a,pa),(b,pb),_ in s['edges']:
    A,B=N[a]['pos'],N[b]['pos']
    d=math.dist(A,B); longest=max(longest,d)
    dy=abs(A[1]-B[1]); h=math.hypot(A[0]-B[0],A[2]-B[2])
    kinds['level' if dy<1e-6 else 'vertical' if h<1e-6 else 'sloped']+=1
print('edges',dict(kinds),'longest',round(longest,2))
on=collections.Counter()
for i,n in enumerate(N):
    t=typ[i]
    if t in('endpoints','bridges','antennas'): continue
    x,y,z=n['pos']; f=T.floor_below(x,y+0.01,z,reach=1.0)
    on[(t, 'floor' if f is not None and abs(f-y)<0.76 else 'air' if not T.solid(x,y+0.01,z) else 'rock')]+=1
print(dict(on))
