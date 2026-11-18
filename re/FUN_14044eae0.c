
void FUN_14044eae0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4,
                  longlong *param_5,undefined8 *param_6,undefined8 *param_7,uint *param_8,
                  undefined8 *param_9)

{
  undefined8 *puVar1;
  char *pcVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  uint uVar5;
  undefined4 uVar6;
  ulonglong uVar7;
  ushort uVar8;
  code *pcVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  char cVar14;
  char cVar15;
  char cVar16;
  char cVar17;
  char cVar18;
  char cVar19;
  char cVar20;
  char cVar21;
  char cVar22;
  char cVar23;
  char cVar24;
  char cVar25;
  char cVar26;
  char cVar27;
  char cVar28;
  longlong lVar29;
  ulonglong *puVar30;
  undefined4 uVar31;
  undefined1 uVar32;
  undefined4 uVar33;
  char cVar34;
  char cVar35;
  ushort uVar36;
  int iVar37;
  longlong *plVar38;
  byte *pbVar39;
  ulonglong uVar40;
  undefined8 uVar41;
  int *piVar42;
  int *piVar43;
  undefined4 *puVar44;
  ulonglong uVar45;
  longlong lVar46;
  undefined8 *puVar47;
  ulonglong uVar48;
  longlong lVar49;
  longlong lVar50;
  longlong lVar51;
  longlong *plVar52;
  longlong *plVar53;
  longlong *plVar54;
  longlong lVar55;
  longlong lVar56;
  undefined8 *puVar57;
  ulonglong uVar58;
  longlong *plVar59;
  longlong lVar60;
  ulonglong *puVar61;
  int *piVar62;
  longlong *plVar63;
  undefined8 *puVar64;
  undefined4 *puVar65;
  undefined1 *puVar66;
  ulonglong *puVar67;
  ulonglong uVar68;
  undefined **ppuVar69;
  longlong lVar70;
  longlong *plVar71;
  ulonglong *puVar72;
  ulonglong *puVar73;
  undefined8 *puVar74;
  byte bVar75;
  undefined1 auVar76 [16];
  undefined1 auVar77 [16];
  undefined1 auVar78 [16];
  undefined1 auVar82 [16];
  undefined1 auVar83 [16];
  undefined1 unaff_XMM10_Ba;
  undefined1 unaff_XMM10_Bb;
  char cVar84;
  undefined1 unaff_XMM10_Bc;
  char cVar85;
  undefined1 unaff_XMM10_Bd;
  char cVar86;
  undefined1 unaff_XMM10_Be;
  undefined1 unaff_XMM10_Bf;
  char cVar87;
  undefined1 unaff_XMM10_Bg;
  char cVar88;
  undefined1 unaff_XMM10_Bh;
  char cVar89;
  undefined1 unaff_XMM10_Bi;
  undefined1 unaff_XMM10_Bj;
  char cVar90;
  undefined1 unaff_XMM10_Bk;
  char cVar91;
  undefined1 unaff_XMM10_Bl;
  char cVar92;
  undefined1 unaff_XMM10_Bm;
  undefined1 unaff_XMM10_Bn;
  char cVar93;
  undefined1 unaff_XMM10_Bo;
  char cVar94;
  undefined1 unaff_XMM10_Bp;
  char cVar95;
  undefined4 local_268;
  undefined4 uStack_264;
  undefined1 uStack_260;
  undefined1 uStack_25f;
  undefined2 uStack_25e;
  undefined4 uStack_25c;
  undefined8 local_258;
  undefined8 *local_250;
  longlong local_248;
  ulonglong *local_240;
  ulonglong *local_238;
  longlong local_230;
  undefined8 local_228;
  undefined8 uStack_220;
  undefined8 local_218;
  undefined8 uStack_210;
  undefined8 local_208;
  undefined8 uStack_200;
  undefined4 local_1f8;
  undefined4 uStack_1f4;
  undefined1 uStack_1f0;
  undefined1 uStack_1ef;
  char cStack_1ee;
  char cStack_1ed;
  uint uStack_1ec;
  char *local_1e8;
  undefined4 local_1e0;
  undefined1 local_1dc;
  undefined4 local_1d8;
  undefined1 local_1d4;
  undefined4 local_1d0;
  undefined1 local_1cc;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  ulonglong *local_1b8;
  undefined4 local_1b0;
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  ulonglong *local_1a0;
  undefined4 local_198;
  undefined1 local_194;
  undefined4 local_193;
  undefined1 local_18f;
  char local_18e;
  undefined1 local_18d;
  undefined1 local_18c;
  ulonglong *local_188;
  undefined4 *local_180;
  int *local_178;
  longlong local_170;
  undefined8 *local_168;
  longlong local_160;
  ulonglong local_158;
  uint local_14c;
  longlong local_148;
  ulonglong *local_140;
  ulonglong *local_138;
  ulonglong *puStack_130;
  undefined4 local_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined8 local_118;
  undefined8 local_110;
  longlong local_108;
  ulonglong *puStack_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  uint *local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  char cVar79;
  char cVar80;
  char cVar81;
  
  local_138 = (ulonglong *)*param_4;
  puStack_130 = (ulonglong *)param_4[1];
  local_128 = *(undefined4 *)(param_4 + 2);
  uStack_124 = *(undefined4 *)((longlong)param_4 + 0x14);
  uStack_120 = *(undefined4 *)(param_4 + 3);
  uStack_11c = *(undefined4 *)((longlong)param_4 + 0x1c);
  uVar7 = param_5[2];
  lVar29 = *param_5;
  puVar30 = (ulonglong *)param_5[1];
  local_e0 = param_6[2];
  local_f0 = *param_6;
  uStack_e8 = param_6[1];
  local_d8 = *param_7;
  uStack_d0 = param_7[1];
  local_c8 = param_7[2];
  local_c0 = param_8;
  local_a8 = param_9[2];
  local_b8 = *param_9;
  uStack_b0 = param_9[1];
  uVar40 = *local_138;
  uVar68 = 0;
  uVar48 = uVar40 - *puStack_130;
  if (uVar40 < *puStack_130) {
    uVar48 = uVar68;
  }
  uVar45 = uVar40 - puStack_130[1];
  if (uVar40 < puStack_130[1]) {
    uVar45 = uVar68;
  }
  plVar52 = (longlong *)(uVar48 * 8 + puStack_130[4]);
  uVar40 = puStack_130[5] - uVar48;
  if (puStack_130[5] < uVar48) {
    plVar52 = &DAT_1424629f0;
    uVar40 = uVar68;
  }
  plVar63 = (longlong *)(uVar45 * 8 + puStack_130[7]);
  uVar48 = puStack_130[8];
  if (uVar48 < uVar45) {
    plVar63 = &DAT_1424629f0;
  }
  uVar58 = uVar48 - uVar45;
  if (uVar48 < uVar45) {
    uVar58 = uVar68;
  }
  uVar48 = (puStack_130[2] - uVar58) - uVar40;
  *local_138 = uVar48;
  if ((char)puStack_130[9] == '\0') {
    plVar38 = plVar63 + uVar58;
    plVar71 = plVar52 + uVar40;
    plVar54 = plVar52;
    plVar53 = plVar52;
    if (plVar63 == plVar38) goto LAB_14044ec8b;
  }
  else {
    plVar38 = plVar52 + uVar40;
    plVar71 = plVar63 + uVar58;
    plVar54 = plVar63;
    plVar53 = plVar63;
    plVar63 = plVar52;
    if (plVar52 == plVar38) {
LAB_14044ec8b:
      if (plVar54 == plVar71) {
        return;
      }
      plVar53 = plVar54 + 1;
      plVar52 = (longlong *)0x0;
      goto LAB_14044ec99;
    }
  }
  plVar54 = plVar63;
  plVar52 = plVar54 + 1;
LAB_14044ec99:
  if (uVar48 < *plVar54 + 1U) {
    uVar48 = *plVar54 + 1U;
  }
  *local_138 = uVar48;
  if (plVar54 != (longlong *)0x0) {
    do {
      if ((plVar52 == (longlong *)0x0) || (plVar52 == plVar38)) {
        if ((plVar53 == (longlong *)0x0) || (plVar53 == plVar71)) break;
        plVar59 = plVar53 + 1;
        plVar52 = (longlong *)0x0;
        plVar63 = plVar53;
      }
      else {
        plVar63 = plVar52;
        plVar52 = plVar52 + 1;
        plVar59 = plVar53;
      }
      if (uVar48 < *plVar63 + 1U) {
        uVar48 = *plVar63 + 1U;
      }
      *local_138 = uVar48;
      plVar53 = plVar59;
    } while (plVar63 != (longlong *)0x0);
    if (plVar54 != (longlong *)0x0) {
      local_14c = *param_8 + 1 & 0xffff;
      *param_8 = local_14c;
      local_f8._4_4_ = (undefined4)(uVar7 >> 0x20);
      uVar33 = local_f8._4_4_;
      local_118 = param_2;
      local_110 = param_3;
      local_108 = lVar29;
      puStack_100 = puVar30;
      local_f8 = uVar7;
      FUN_14221def0(lVar29,puVar30,uVar7 & 0xffffffff);
      puVar72 = (ulonglong *)puVar30[0xf];
      local_140 = puVar72 + puVar30[0x10];
      local_160 = 0x10;
      local_148 = 0;
      iVar10 = -(uint)(CONCAT13(unaff_XMM10_Bd,
                                CONCAT12(unaff_XMM10_Bc,CONCAT11(unaff_XMM10_Bb,unaff_XMM10_Ba))) ==
                      CONCAT13(unaff_XMM10_Bd,
                               CONCAT12(unaff_XMM10_Bc,CONCAT11(unaff_XMM10_Bb,unaff_XMM10_Ba))));
      cVar84 = (char)((uint)iVar10 >> 8);
      cVar85 = (char)((uint)iVar10 >> 0x10);
      cVar86 = (char)((uint)iVar10 >> 0x18);
      iVar11 = -(uint)(CONCAT13(unaff_XMM10_Bh,
                                CONCAT12(unaff_XMM10_Bg,CONCAT11(unaff_XMM10_Bf,unaff_XMM10_Be))) ==
                      CONCAT13(unaff_XMM10_Bh,
                               CONCAT12(unaff_XMM10_Bg,CONCAT11(unaff_XMM10_Bf,unaff_XMM10_Be))));
      cVar87 = (char)((uint)iVar11 >> 8);
      cVar88 = (char)((uint)iVar11 >> 0x10);
      cVar89 = (char)((uint)iVar11 >> 0x18);
      iVar12 = -(uint)(CONCAT13(unaff_XMM10_Bl,
                                CONCAT12(unaff_XMM10_Bk,CONCAT11(unaff_XMM10_Bj,unaff_XMM10_Bi))) ==
                      CONCAT13(unaff_XMM10_Bl,
                               CONCAT12(unaff_XMM10_Bk,CONCAT11(unaff_XMM10_Bj,unaff_XMM10_Bi))));
      cVar90 = (char)((uint)iVar12 >> 8);
      cVar91 = (char)((uint)iVar12 >> 0x10);
      cVar92 = (char)((uint)iVar12 >> 0x18);
      iVar13 = -(uint)(CONCAT13(unaff_XMM10_Bp,
                                CONCAT12(unaff_XMM10_Bo,CONCAT11(unaff_XMM10_Bn,unaff_XMM10_Bm))) ==
                      CONCAT13(unaff_XMM10_Bp,
                               CONCAT12(unaff_XMM10_Bo,CONCAT11(unaff_XMM10_Bn,unaff_XMM10_Bm))));
      cVar93 = (char)((uint)iVar13 >> 8);
      cVar94 = (char)((uint)iVar13 >> 0x10);
      cVar95 = (char)((uint)iVar13 >> 0x18);
      local_170 = 0;
      puVar74 = (undefined8 *)0x0;
      lVar70 = 0;
      puVar64 = (undefined8 *)0x0;
      piVar62 = (int *)&DAT_00000004;
      lVar55 = 8;
      puVar73 = (ulonglong *)&DAT_00000008;
LAB_14044eddf:
      puVar47 = puVar64;
      if (puVar47 != puVar74) {
        if (lVar70 == 0) {
          return;
        }
        lVar46 = lVar55 + (longlong)puVar47 * 0x18;
        local_238 = puVar73 + (longlong)puVar47 * 7;
        piVar42 = piVar62 + (longlong)puVar47 * 4;
        puVar64 = (undefined8 *)((longlong)puVar47 + 1);
        uVar5 = (&switchD_14044ef2f::switchdataD_1404504bc)
                [*(byte *)(piVar62 + (longlong)puVar47 * 4 + 1)];
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
        switch(*(byte *)(piVar62 + (longlong)puVar47 * 4 + 1)) {
        case 1:
          goto switchD_14044ef2f_caseD_1;
        case 2:
          goto switchD_14044ef2f_caseD_2;
        case 3:
          goto switchD_14044ef2f_caseD_3;
        case 4:
          goto switchD_14044ef2f_caseD_4;
        }
switchD_14044ef2f_caseD_0:
        if (*(longlong *)(lVar46 + 0x10) == 0) {
          ppuVar69 = &PTR_s_src_net_tester_rs_14243ab38;
          goto LAB_1404503c4;
        }
        puVar57 = *(undefined8 **)(lVar46 + 8);
        if (*(char *)((longlong)puVar57 + 0x3a) != '\x02') {
          local_250 = (undefined8 *)((longlong)puVar57 + 0x35);
          lVar46 = (longlong)puVar47 * 0x10;
          puVar66 = (undefined1 *)((longlong)piVar62 + lVar46 + 5);
          local_248 = lVar55;
          cVar34 = FUN_1406b6550(local_250,puVar66);
          if ((((cVar34 == '\0') ||
               (cVar34 = FUN_1406b6550(puVar57 + 6,(undefined1 *)((longlong)piVar62 + lVar46 + 10)),
               cVar34 == '\0')) || (puVar57[5] != 4)) || (*(int *)puVar57[4] != 0x474e4f50)) {
            cVar34 = FUN_1406b6550(puVar57 + 6,puVar66);
            if (((cVar34 == '\0') ||
                (cVar34 = FUN_1406b6550(local_250,(undefined1 *)((longlong)piVar62 + lVar46 + 10)),
                cVar34 == '\0')) || ((puVar57[5] != 4 || (*(int *)puVar57[4] != 0x474e4950)))) {
              uStack_1c0 = CONCAT44(uStack_1c0._4_4_,
                                    *(undefined4 *)(local_160 + 0x18 + (longlong)puVar47 * 0x30));
              local_1c8 = *(char **)(local_160 + 0x10 + (longlong)puVar47 * 0x30);
              uStack_264 = CONCAT31(uStack_264._1_3_,*(undefined1 *)((longlong)puVar57 + 0x34));
              local_268 = *(undefined4 *)(puVar57 + 6);
              uVar6 = *(undefined4 *)local_250;
              uVar3 = *(undefined1 *)((longlong)local_250 + 4);
              puVar67 = (ulonglong *)puVar57[2];
              uVar4 = *(undefined2 *)((longlong)puVar57 + 0x3a);
              FUN_1423a1b30(&uStack_210,puVar57 + 3);
              local_228 = (char *)*puVar57;
              uStack_220 = puVar57[1];
              local_1e0 = (undefined4)uStack_1c0;
              local_1e8 = local_1c8;
              local_1dc = 1;
              local_1f8 = local_268;
              uStack_1f4._1_3_ = (undefined3)uVar6;
              uStack_1f4 = CONCAT31(uStack_1f4._1_3_,(char)uStack_264);
              uStack_1f0 = (undefined1)((uint)uVar6 >> 0x18);
              cStack_1ee = (char)uVar4;
              cStack_1ed = (char)((ushort)uVar4 >> 8);
              uStack_1ec = CONCAT31(uStack_1ec._1_3_,*(undefined1 *)((longlong)puVar57 + 0x3c));
              local_218 = puVar67;
              uStack_1ef = uVar3;
              FUN_140516d40(&local_b8,&local_228);
              lVar55 = local_248;
              goto LAB_14044eddf;
            }
          }
          puVar67 = local_238;
          lVar55 = local_248;
          *(undefined4 *)(local_170 + 4 + (longlong)puVar47 * 8) = uVar33;
          if ((uint)puVar73[(longlong)puVar47 * 7 + 6] < 0x10000000) {
            puVar61 = puVar73 + (longlong)puVar47 * 7 + 6;
            local_268 = *(undefined4 *)(puVar57 + 6);
            uStack_25f = *(undefined1 *)((longlong)local_250 + 4);
            uStack_264._1_3_ = (undefined3)*(undefined4 *)local_250;
            uStack_264 = CONCAT31(uStack_264._1_3_,*(undefined1 *)((longlong)puVar57 + 0x34));
            uStack_260 = (undefined1)((uint)*(undefined4 *)local_250 >> 0x18);
            *(uint *)puVar61 = (uint)puVar73[(longlong)puVar47 * 7 + 6] + 1;
            piVar42 = (int *)FUN_14037de30(local_238,&local_268);
            if (piVar42 == (int *)0x0) {
              uStack_1c0 = CONCAT62(uStack_1c0._2_6_,CONCAT11(uStack_25f,uStack_260));
              local_1c8 = (char *)CONCAT44(uStack_264,local_268);
              FUN_14037bf80(&local_228,puVar67,&local_1c8,1,(int)*puVar61);
            }
            else {
              *piVar42 = *piVar42 + 1;
              piVar42[1] = (int)*puVar61;
            }
          }
        }
        goto LAB_14044eddf;
      }
      do {
        if (puVar72 == local_140) {
          return;
        }
        uVar7 = *puVar72;
        if (*(ulonglong *)(lVar29 + 0xd8) <= uVar7) {
          FUN_1423ab620(uVar7,*(ulonglong *)(lVar29 + 0xd8),
                        &PTR_s__home_puzzled_squid_src_tunnet_d_14243a5e0);
                    /* WARNING: Does not return */
          pcVar9 = (code *)invalidInstructionException();
          (*pcVar9)();
        }
        lVar70 = *(longlong *)(lVar29 + 0xd0);
        lVar55 = uVar7 * 0x60;
        uVar7 = *(ulonglong *)(lVar70 + 0x40 + lVar55);
        if (uVar7 <= *puVar30) {
LAB_1404503e1:
          ppuVar69 = &PTR_s__home_puzzled_squid_src_tunnet_d_142439290;
LAB_140450411:
          FUN_1423ab4f0("called `Option::unwrap()` on a `None` value",0x2b,ppuVar69);
                    /* WARNING: Does not return */
          pcVar9 = (code *)invalidInstructionException();
          (*pcVar9)();
        }
        lVar56 = *(longlong *)(lVar70 + lVar55 + 0x38);
        lVar46 = *puVar30 * 0x10;
        if ((((*(longlong *)(lVar56 + lVar46) == 0) || (uVar7 <= puVar30[1])) ||
            (lVar50 = puVar30[1] * 0x10, *(longlong *)(lVar56 + lVar50) == 0)) ||
           ((uVar7 <= puVar30[2] ||
            (lVar60 = puVar30[2] * 0x10, *(longlong *)(lVar56 + lVar60) == 0)))) goto LAB_1404503e1;
        if ((uVar7 <= puVar30[3]) ||
           (lVar49 = puVar30[3] * 0x10, *(longlong *)(lVar56 + lVar49) == 0)) {
          ppuVar69 = &PTR_s__home_puzzled_squid_src_tunnet_d_142438a78;
          goto LAB_140450411;
        }
        puVar72 = puVar72 + 1;
        puVar74 = *(undefined8 **)(lVar70 + 0x58 + lVar55);
      } while (puVar74 == (undefined8 *)0x0);
      lVar46 = *(longlong *)(lVar56 + 8 + lVar46) * 0x58;
      lVar55 = *(longlong *)(lVar70 + lVar55 + 8);
      lVar70 = *(longlong *)(lVar55 + 0x10 + lVar46);
      lVar51 = *(longlong *)(lVar56 + 8 + lVar50) * 0x58;
      lVar46 = *(longlong *)(lVar55 + 0x40 + lVar46);
      local_170 = *(longlong *)(lVar55 + 0x10 + lVar51);
      lVar50 = *(longlong *)(lVar56 + 8 + lVar60) * 0x58;
      puVar73 = *(ulonglong **)(lVar55 + 0x40 + lVar51);
      local_148 = *(longlong *)(lVar55 + 0x10 + lVar50);
      piVar62 = *(int **)(lVar55 + 0x40 + lVar50);
      local_160 = *(longlong *)(lVar55 + 0x40 + *(longlong *)(lVar56 + 8 + lVar49) * 0x58);
      puVar64 = (undefined8 *)0x1;
      uVar5 = (&switchD_14044ef2f::switchdataD_1404504bc)[*(byte *)(piVar62 + 1)];
      puVar47 = (undefined8 *)0x0;
      lVar55 = lVar46;
      piVar42 = piVar62;
      local_238 = puVar73;
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
      switch(*(byte *)(piVar62 + 1)) {
      case 0:
        goto switchD_14044ef2f_caseD_0;
      case 1:
switchD_14044ef2f_caseD_1:
        local_250 = puVar47;
        if (*(longlong *)(lVar46 + 0x10) == 0) {
          ppuVar69 = (undefined **)0x14243aac0;
          goto LAB_1404503c4;
        }
        puVar57 = *(undefined8 **)(lVar46 + 8);
        local_240 = puVar73;
        if (*(char *)((longlong)puVar57 + 0x3a) != '\x02') {
          puVar44 = (undefined4 *)((longlong)puVar57 + 0x35);
          lVar56 = (longlong)puVar47 * 0x10;
          puVar66 = (undefined1 *)((longlong)piVar62 + lVar56 + 5);
          local_248 = lVar55;
          local_230 = lVar46;
          cVar34 = FUN_1406b6550(puVar44,puVar66);
          if ((((cVar34 == '\0') ||
               (cVar34 = FUN_1406b6550(puVar57 + 6,(undefined1 *)((longlong)piVar62 + lVar56 + 10)),
               cVar34 == '\0')) || (puVar57[5] != 4)) || (*(int *)puVar57[4] != 0x474e4f50)) {
            cVar34 = FUN_1406b6550(puVar57 + 6,puVar66);
            if (((cVar34 == '\0') ||
                (cVar34 = FUN_1406b6550(puVar44,(undefined1 *)((longlong)piVar62 + lVar56 + 10)),
                cVar34 == '\0')) || ((puVar57[5] != 4 || (*(int *)puVar57[4] != 0x474e4950)))) {
              uStack_1c0 = CONCAT44(uStack_1c0._4_4_,
                                    *(undefined4 *)(local_160 + 0x18 + (longlong)local_250 * 0x30));
              local_1c8 = *(char **)(local_160 + 0x10 + (longlong)local_250 * 0x30);
              uStack_264 = CONCAT31(uStack_264._1_3_,*(undefined1 *)((longlong)puVar57 + 0x34));
              local_268 = *(undefined4 *)(puVar57 + 6);
              uVar6 = *puVar44;
              uVar3 = *(undefined1 *)((longlong)puVar57 + 0x39);
              puVar73 = (ulonglong *)puVar57[2];
              uVar4 = *(undefined2 *)((longlong)puVar57 + 0x3a);
              FUN_1423a1b30(&uStack_210,puVar57 + 3);
              local_228 = (char *)*puVar57;
              uStack_220 = puVar57[1];
              local_1e0 = (undefined4)uStack_1c0;
              local_1e8 = local_1c8;
              local_1dc = 1;
              local_1f8 = local_268;
              uStack_1f4._1_3_ = (undefined3)uVar6;
              uStack_1f4 = CONCAT31(uStack_1f4._1_3_,(char)uStack_264);
              uStack_1f0 = (undefined1)((uint)uVar6 >> 0x18);
              cStack_1ee = (char)uVar4;
              cStack_1ed = (char)((ushort)uVar4 >> 8);
              uStack_1ec = CONCAT31(uStack_1ec._1_3_,*(undefined1 *)((longlong)puVar57 + 0x3c));
              local_218 = puVar73;
              uStack_1ef = uVar3;
              FUN_140516d40(&local_b8);
              lVar46 = local_230;
              lVar55 = local_248;
              goto LAB_14044f77c;
            }
          }
          puVar73 = local_238;
          *(undefined4 *)(local_170 + 4 + (longlong)local_250 * 8) = uVar33;
          lVar46 = local_230;
          lVar55 = local_248;
          if ((uint)local_240[(longlong)local_250 * 7 + 6] < 0x10000000) {
            puVar67 = local_240 + (longlong)local_250 * 7 + 6;
            local_268 = *(undefined4 *)(puVar57 + 6);
            uStack_25f = *(undefined1 *)((longlong)puVar57 + 0x39);
            uStack_264 = *(undefined4 *)((longlong)puVar57 + 0x34);
            uStack_260 = (undefined1)((uint)*puVar44 >> 0x18);
            *(uint *)puVar67 = (uint)local_240[(longlong)local_250 * 7 + 6] + 1;
            piVar43 = (int *)FUN_14037de30(local_238);
            lVar55 = local_248;
            if (piVar43 == (int *)0x0) {
              uStack_1c0 = CONCAT62(uStack_1c0._2_6_,CONCAT11(uStack_25f,uStack_260));
              local_1c8 = (char *)CONCAT44(uStack_264,local_268);
              FUN_14037bf80(&local_228,puVar73,&local_1c8,1,(int)*puVar67);
              lVar46 = local_230;
            }
            else {
              *piVar43 = *piVar43 + 1;
              piVar43[1] = (int)*puVar67;
              lVar46 = local_230;
            }
          }
        }
LAB_14044f77c:
        iVar37 = *piVar42;
        if (iVar37 < 1) {
          *(undefined4 *)(local_148 + 4 + (longlong)local_250 * 8) = uVar33;
          *piVar42 = 1;
          iVar37 = 1;
        }
        uVar7 = (ulonglong)local_14c;
        puVar73 = local_240;
        if ((int)((longlong)uVar7 % (longlong)iVar37) != 0) goto LAB_14044eddf;
        plVar52 = (longlong *)FUN_14204d800();
        lVar56 = (longlong)local_250 * 0x10;
        local_1c8 = (char *)CONCAT44(CONCAT31(local_1c8._5_3_,
                                              *(undefined1 *)((longlong)piVar62 + lVar56 + 9)),
                                     *(undefined4 *)((longlong)piVar62 + lVar56 + 5));
        uVar41 = FUN_1406b6400((undefined1 *)((longlong)piVar62 + lVar56 + 10),
                               (longlong)uVar7 / (longlong)iVar37 & 0xffffffff);
        puVar44 = (undefined4 *)thunk_FUN_142351260(4,1);
        if (puVar44 != (undefined4 *)0x0) {
          *puVar44 = 0x474e4950;
          uStack_264 = CONCAT31(uStack_264._1_3_,local_1c8._4_1_);
          local_268 = (undefined4)local_1c8;
          *plVar52 = *plVar52 + -1;
          local_248 = lVar55;
          if (*plVar52 == 0) {
            plVar63 = plVar52 + 1;
            *plVar63 = *plVar63 + -1;
            if (*plVar63 == 0) {
              FUN_1408192a0(plVar52,0x170,0x10);
            }
          }
          local_228 = "a0938e";
          uStack_220 = 6;
          local_218 = (ulonglong *)&DAT_00000008;
          uStack_210 = 4;
          uStack_200 = 4;
          local_1f8 = local_268;
          uStack_1ef = (undefined1)((ulonglong)uVar41 >> 0x20);
          uStack_1f4._1_3_ = (undefined3)uVar41;
          uStack_1f4 = CONCAT31(uStack_1f4._1_3_,(char)uStack_264);
          uStack_1f0 = (undefined1)((ulonglong)uVar41 >> 0x18);
          cStack_1ee = '\0';
          cStack_1ed = '\0';
          uStack_1ec = uStack_1ec & 0xffffff00;
          *(undefined4 *)(lVar70 + 4 + (longlong)local_250 * 8) = uVar33;
          local_208 = puVar44;
          if (*(longlong *)(lVar46 + 0x10) == 0) {
            FUN_1423ab620(0,0,&PTR_s_src_net_tester_rs_14243ab20);
            break;
          }
          lVar55 = *(longlong *)(lVar46 + 8);
          if ((*(char *)(lVar55 + 0x7a) != '\x02') &&
             (uVar7 = *(ulonglong *)(lVar55 + 0x58), uVar7 != 0)) {
            FUN_1408192a0(*(undefined8 *)(lVar55 + 0x60),uVar7,~uVar7 >> 0x3f);
          }
          *(ulonglong *)(lVar55 + 0x70) = CONCAT44(uStack_1f4,local_1f8);
          *(ulonglong *)(lVar55 + 0x78) =
               CONCAT44(uStack_1ec,
                        CONCAT13(cStack_1ed,CONCAT12(cStack_1ee,CONCAT11(uStack_1ef,uStack_1f0))));
          *(undefined4 **)(lVar55 + 0x60) = local_208;
          *(undefined8 *)(lVar55 + 0x68) = uStack_200;
          *(ulonglong **)(lVar55 + 0x50) = local_218;
          *(undefined8 *)(lVar55 + 0x58) = uStack_210;
          *(char **)(lVar55 + 0x40) = local_228;
          *(undefined8 *)(lVar55 + 0x48) = uStack_220;
          lVar55 = local_248;
          puVar73 = local_240;
          goto LAB_14044eddf;
        }
        FUN_14239ef70(4,1);
        break;
      case 2:
switchD_14044ef2f_caseD_2:
        if (*(longlong *)(lVar46 + 0x10) == 0) {
          ppuVar69 = &PTR_s_src_net_tester_rs_14243aa70;
          goto LAB_1404503c4;
        }
        puVar57 = *(undefined8 **)(lVar46 + 8);
        if (*(char *)((longlong)puVar57 + 0x3a) == '\x02') goto LAB_14044eddf;
        puVar44 = (undefined4 *)((longlong)puVar57 + 0x35);
        puVar65 = (undefined4 *)((longlong)piVar62 + (longlong)puVar47 * 0x10 + 5);
        local_248 = lVar55;
        local_230 = lVar46;
        cVar34 = FUN_1406b6550(puVar44,puVar65);
        puVar67 = local_238;
        if (cVar34 != '\0') {
          *(undefined4 *)(local_170 + 4 + (longlong)puVar47 * 8) = uVar33;
          lVar55 = local_248;
          local_250 = puVar47;
          if ((uint)puVar73[(longlong)puVar47 * 7 + 6] < 0x10000000) {
            local_268 = *(undefined4 *)(puVar57 + 6);
            uStack_25f = *(undefined1 *)((longlong)puVar57 + 0x39);
            uStack_264 = *(undefined4 *)((longlong)puVar57 + 0x34);
            uStack_260 = (undefined1)((uint)*puVar44 >> 0x18);
            iVar37 = (uint)puVar73[(longlong)puVar47 * 7 + 6] + 1;
            *(int *)(puVar73 + (longlong)puVar47 * 7 + 6) = iVar37;
            if (local_238[2] != 0) {
              local_240 = puVar73;
              local_188 = puVar73 + (longlong)puVar47 * 7 + 6;
              local_180 = puVar65;
              local_178 = piVar62;
              local_168 = puVar57;
              uVar40 = FUN_140766420(local_238 + 4,&local_268);
              uVar7 = *puVar67;
              local_158 = puVar67[3];
              bVar75 = (byte)(uVar40 >> 0x39);
              auVar77 = ZEXT216(CONCAT11(bVar75,bVar75));
              auVar77 = pshuflw(auVar77,auVar77,0);
              lVar55 = local_158 - 0x14;
              lVar46 = 0;
              local_238 = puVar67;
              while( true ) {
                uVar40 = uVar40 & uVar7;
                pcVar2 = (char *)(local_158 + uVar40);
                cVar34 = *pcVar2;
                cVar14 = pcVar2[1];
                cVar15 = pcVar2[2];
                cVar16 = pcVar2[3];
                cVar17 = pcVar2[4];
                cVar18 = pcVar2[5];
                cVar19 = pcVar2[6];
                cVar20 = pcVar2[7];
                cVar21 = pcVar2[8];
                cVar22 = pcVar2[9];
                cVar23 = pcVar2[10];
                cVar24 = pcVar2[0xb];
                cVar25 = pcVar2[0xc];
                cVar26 = pcVar2[0xd];
                cVar27 = pcVar2[0xe];
                cVar28 = pcVar2[0xf];
                cVar35 = auVar77[0];
                auVar76[0] = -(cVar35 == cVar34);
                cVar79 = auVar77[1];
                auVar76[1] = -(cVar79 == cVar14);
                cVar80 = auVar77[2];
                auVar76[2] = -(cVar80 == cVar15);
                cVar81 = auVar77[3];
                auVar76[3] = -(cVar81 == cVar16);
                auVar76[4] = -(cVar35 == cVar17);
                auVar76[5] = -(cVar79 == cVar18);
                auVar76[6] = -(cVar80 == cVar19);
                auVar76[7] = -(cVar81 == cVar20);
                auVar76[8] = -(cVar35 == cVar21);
                auVar76[9] = -(cVar79 == cVar22);
                auVar76[10] = -(cVar80 == cVar23);
                auVar76[0xb] = -(cVar81 == cVar24);
                auVar76[0xc] = -(cVar35 == cVar25);
                auVar76[0xd] = -(cVar79 == cVar26);
                auVar76[0xe] = -(cVar80 == cVar27);
                auVar76[0xf] = -(cVar81 == cVar28);
                puVar73 = local_240;
                puVar65 = local_180;
                piVar62 = local_178;
                puVar57 = local_168;
                for (uVar36 = (ushort)(SUB161(auVar76 >> 7,0) & 1) |
                              (ushort)(SUB161(auVar76 >> 0xf,0) & 1) << 1 |
                              (ushort)(SUB161(auVar76 >> 0x17,0) & 1) << 2 |
                              (ushort)(SUB161(auVar76 >> 0x1f,0) & 1) << 3 |
                              (ushort)(SUB161(auVar76 >> 0x27,0) & 1) << 4 |
                              (ushort)(SUB161(auVar76 >> 0x2f,0) & 1) << 5 |
                              (ushort)(SUB161(auVar76 >> 0x37,0) & 1) << 6 |
                              (ushort)(SUB161(auVar76 >> 0x3f,0) & 1) << 7 |
                              (ushort)(SUB161(auVar76 >> 0x47,0) & 1) << 8 |
                              (ushort)(SUB161(auVar76 >> 0x4f,0) & 1) << 9 |
                              (ushort)(SUB161(auVar76 >> 0x57,0) & 1) << 10 |
                              (ushort)(SUB161(auVar76 >> 0x5f,0) & 1) << 0xb |
                              (ushort)(SUB161(auVar76 >> 0x67,0) & 1) << 0xc |
                              (ushort)(SUB161(auVar76 >> 0x6f,0) & 1) << 0xd |
                              (ushort)(SUB161(auVar76 >> 0x77,0) & 1) << 0xe |
                              (ushort)(auVar76[0xf] >> 7) << 0xf; local_240 = puVar73,
                    local_180 = puVar65, local_178 = piVar62, local_168 = puVar57, uVar36 != 0;
                    uVar36 = uVar36 - 1 & uVar36) {
                  uVar8 = 0;
                  if (uVar36 != 0) {
                    for (; (uVar36 >> uVar8 & 1) == 0; uVar8 = uVar8 + 1) {
                    }
                  }
                  lVar56 = (uVar8 + uVar40 & uVar7) * -0x14 + lVar55;
                  cVar35 = FUN_1406b6550(&local_268,lVar56);
                  if ((cVar35 != '\0') &&
                     (cVar35 = FUN_1406b6550((longlong)&uStack_264 + 1,lVar56 + 5), cVar35 != '\0'))
                  {
                    *(int *)(lVar56 + 0xc) = *(int *)(lVar56 + 0xc) + 1;
                    *(int *)(lVar56 + 0x10) = (int)*local_188;
                    puVar57 = local_168;
                    piVar62 = local_178;
                    puVar65 = local_180;
                    lVar55 = local_248;
                    puVar73 = local_240;
                    goto LAB_140450011;
                  }
                  puVar73 = local_240;
                  puVar65 = local_180;
                  piVar62 = local_178;
                  puVar57 = local_168;
                }
                auVar82[0] = -(cVar34 == (char)iVar10);
                auVar82[1] = -(cVar14 == cVar84);
                auVar82[2] = -(cVar15 == cVar85);
                auVar82[3] = -(cVar16 == cVar86);
                auVar82[4] = -(cVar17 == (char)iVar11);
                auVar82[5] = -(cVar18 == cVar87);
                auVar82[6] = -(cVar19 == cVar88);
                auVar82[7] = -(cVar20 == cVar89);
                auVar82[8] = -(cVar21 == (char)iVar12);
                auVar82[9] = -(cVar22 == cVar90);
                auVar82[10] = -(cVar23 == cVar91);
                auVar82[0xb] = -(cVar24 == cVar92);
                auVar82[0xc] = -(cVar25 == (char)iVar13);
                auVar82[0xd] = -(cVar26 == cVar93);
                auVar82[0xe] = -(cVar27 == cVar94);
                auVar82[0xf] = -(cVar28 == cVar95);
                if ((((((((((((((((SUB161(auVar82 >> 7,0) & 1) != 0 ||
                                 (SUB161(auVar82 >> 0xf,0) & 1) != 0) ||
                                (SUB161(auVar82 >> 0x17,0) & 1) != 0) ||
                               (SUB161(auVar82 >> 0x1f,0) & 1) != 0) ||
                              (SUB161(auVar82 >> 0x27,0) & 1) != 0) ||
                             (SUB161(auVar82 >> 0x2f,0) & 1) != 0) ||
                            (SUB161(auVar82 >> 0x37,0) & 1) != 0) ||
                           (SUB161(auVar82 >> 0x3f,0) & 1) != 0) ||
                          (SUB161(auVar82 >> 0x47,0) & 1) != 0) ||
                         (SUB161(auVar82 >> 0x4f,0) & 1) != 0) ||
                        (SUB161(auVar82 >> 0x57,0) & 1) != 0) ||
                       (SUB161(auVar82 >> 0x5f,0) & 1) != 0) || (SUB161(auVar82 >> 0x67,0) & 1) != 0
                      ) || (SUB161(auVar82 >> 0x6f,0) & 1) != 0) ||
                    (SUB161(auVar82 >> 0x77,0) & 1) != 0) || auVar82[0xf] < '\0') break;
                uVar40 = uVar40 + lVar46 + 0x10;
                lVar46 = lVar46 + 0x10;
              }
              iVar37 = (int)*local_188;
            }
            lVar55 = local_248;
            uStack_1c0 = CONCAT62(uStack_1c0._2_6_,CONCAT11(uStack_25f,uStack_260));
            local_1c8 = (char *)CONCAT44(uStack_264,local_268);
            FUN_14037bf80(&local_228,local_238,&local_1c8,1,iVar37);
          }
LAB_140450011:
          if ((puVar57[5] == 4) && (*(int *)puVar57[4] == 0x474e4950)) {
            local_1c8 = (char *)CONCAT44(CONCAT31(local_1c8._5_3_,*(undefined1 *)(puVar65 + 1)),
                                         *puVar65);
            local_268 = *(undefined4 *)(puVar57 + 6);
            uStack_264 = CONCAT31(uStack_264._1_3_,*(undefined1 *)((longlong)puVar57 + 0x34));
            puVar44 = (undefined4 *)thunk_FUN_142351260(4,1);
            if (puVar44 == (undefined4 *)0x0) {
              FUN_14239ef70(4,1);
                    /* WARNING: Does not return */
              pcVar9 = (code *)invalidInstructionException();
              (*pcVar9)();
            }
            *puVar44 = 0x474e4f50;
            local_228 = (char *)*puVar57;
            uStack_220 = puVar57[1];
            local_1f8 = (undefined4)local_1c8;
            local_218 = (ulonglong *)&DAT_00000008;
            uStack_210 = 4;
            uStack_200 = 4;
            uStack_1ef = (undefined1)uStack_264;
            uStack_1f4._1_3_ = (undefined3)local_268;
            uStack_1f4 = CONCAT31(uStack_1f4._1_3_,local_1c8._4_1_);
            uStack_1f0 = (undefined1)((uint)local_268 >> 0x18);
            cStack_1ee = '\x01';
            cStack_1ed = '\0';
            uStack_1ec = uStack_1ec & 0xffffff00;
            *(undefined4 *)(lVar70 + 4 + (longlong)local_250 * 8) = uVar33;
            local_208 = puVar44;
            if (*(longlong *)(local_230 + 0x10) == 0) {
              FUN_1423ab620(0,0,"");
              break;
            }
            lVar46 = *(longlong *)(local_230 + 8);
            if ((*(char *)(lVar46 + 0x7a) != '\x02') &&
               (uVar7 = *(ulonglong *)(lVar46 + 0x58), uVar7 != 0)) {
              FUN_1408192a0(*(undefined8 *)(lVar46 + 0x60),uVar7,~uVar7 >> 0x3f);
            }
            *(ulonglong *)(lVar46 + 0x70) = CONCAT44(uStack_1f4,local_1f8);
            *(ulonglong *)(lVar46 + 0x78) =
                 CONCAT44(uStack_1ec,
                          CONCAT13(cStack_1ed,CONCAT12(cStack_1ee,CONCAT11(uStack_1ef,uStack_1f0))))
            ;
            *(undefined4 **)(lVar46 + 0x60) = local_208;
            *(undefined8 *)(lVar46 + 0x68) = uStack_200;
            *(ulonglong **)(lVar46 + 0x50) = local_218;
            *(undefined8 *)(lVar46 + 0x58) = uStack_210;
            *(char **)(lVar46 + 0x40) = local_228;
            *(undefined8 *)(lVar46 + 0x48) = uStack_220;
          }
          goto LAB_14044eddf;
        }
        puVar1 = puVar57 + 6;
        cVar34 = FUN_1406b6550(puVar1,puVar65);
        lVar55 = local_248;
        if (cVar34 != '\0') goto LAB_14044eddf;
        local_238 = (ulonglong *)CONCAT71(local_238._1_7_,*(char *)((longlong)puVar57 + 0x3a));
        local_240 = (ulonglong *)puVar57[2];
        cVar34 = *(char *)((longlong)puVar57 + 0x3b);
        if ((local_240 == (ulonglong *)0x1 && *(char *)((longlong)puVar57 + 0x3a) != '\0') ||
           (cVar34 != '\0')) {
          uStack_1c0 = CONCAT44(uStack_1c0._4_4_,
                                *(undefined4 *)(local_160 + 0x18 + (longlong)puVar47 * 0x30));
          local_1c8 = *(char **)(local_160 + 0x10 + (longlong)puVar47 * 0x30);
          local_268 = *(undefined4 *)puVar1;
          uStack_264 = CONCAT31(uStack_264._1_3_,*(undefined1 *)((longlong)puVar57 + 0x34));
          uVar6 = *puVar44;
          uVar3 = *(undefined1 *)((longlong)puVar57 + 0x39);
          local_250 = puVar47;
          FUN_1423a1b30(&uStack_210,puVar57 + 3);
          local_228 = (char *)*puVar57;
          uStack_220 = puVar57[1];
          local_1e0 = (undefined4)uStack_1c0;
          local_1e8 = local_1c8;
          local_1dc = 1;
          local_218 = local_240;
          local_1f8 = local_268;
          uStack_1f4._1_3_ = (undefined3)uVar6;
          uStack_1f4 = CONCAT31(uStack_1f4._1_3_,(char)uStack_264);
          uStack_1f0 = (undefined1)((uint)uVar6 >> 0x18);
          cStack_1ee = (char)local_238;
          uStack_1ec = CONCAT31(uStack_1ec._1_3_,*(undefined1 *)((longlong)puVar57 + 0x3c));
          uStack_1ef = uVar3;
          cStack_1ed = cVar34;
          FUN_140516d40(&local_b8,&local_228);
          lVar55 = local_248;
          goto LAB_14044eddf;
        }
        uVar3 = *(undefined1 *)((longlong)puVar57 + 0x34);
        uVar6 = *(undefined4 *)puVar1;
        uStack_264 = CONCAT31(uStack_264._1_3_,*(undefined1 *)((longlong)puVar57 + 0x39));
        local_268 = *puVar44;
        local_250 = puVar47;
        FUN_1423a1b30(&local_228,puVar57 + 3);
        uVar31 = local_268;
        local_18c = *(undefined1 *)((longlong)puVar57 + 0x3c);
        local_1c8 = (char *)*puVar57;
        uStack_1c0 = puVar57[1];
        uVar32 = (undefined1)uStack_264;
        local_18f = (undefined1)uStack_264;
        local_193 = local_268;
        cVar34 = (char)local_238;
        local_18e = (char)local_238;
        local_18d = 0;
        local_1b0 = (undefined4)local_228;
        uStack_1ac = local_228._4_4_;
        uStack_1a8 = (undefined4)uStack_220;
        uStack_1a4 = uStack_220._4_4_;
        local_1a0 = local_218;
        puVar67 = local_240;
        if ((char)local_238 != '\0') {
          puVar67 = (ulonglong *)((longlong)local_240 + -1);
        }
        local_1d0 = uVar6;
        local_1cc = uVar3;
        local_1b8 = puVar67;
        local_198 = uVar6;
        local_194 = uVar3;
        FUN_1423a1b30(&local_268);
        local_1f8 = local_1d0;
        local_1d8 = uVar31;
        local_1d4 = uVar32;
        uStack_200 = local_258;
        uStack_210 = CONCAT44(uStack_264,local_268);
        local_208 = (undefined4 *)
                    CONCAT44(uStack_25c,CONCAT22(uStack_25e,CONCAT11(uStack_25f,uStack_260)));
        local_228 = local_1c8;
        uStack_220 = uStack_1c0;
        uStack_1ef = uVar32;
        uStack_1f4._1_3_ = (undefined3)uVar31;
        uStack_1f4 = CONCAT31(uStack_1f4._1_3_,local_1cc);
        uStack_1f0 = (undefined1)((uint)uVar31 >> 0x18);
        cStack_1ee = cVar34;
        cStack_1ed = '\0';
        uStack_1ec = CONCAT31(uStack_1ec._1_3_,local_18c);
        *(undefined4 *)(lVar70 + 4 + (longlong)local_250 * 8) = uVar33;
        local_218 = puVar67;
        if (*(longlong *)(local_230 + 0x10) != 0) {
          lVar55 = *(longlong *)(local_230 + 8);
          if ((*(char *)(lVar55 + 0x7a) != '\x02') &&
             (uVar7 = *(ulonglong *)(lVar55 + 0x58), uVar7 != 0)) {
            FUN_1408192a0(*(undefined8 *)(lVar55 + 0x60),uVar7,~uVar7 >> 0x3f);
          }
          *(undefined4 *)(lVar55 + 0x70) = local_1f8;
          *(undefined4 *)(lVar55 + 0x74) = uStack_1f4;
          *(uint *)(lVar55 + 0x78) =
               CONCAT13(cStack_1ed,CONCAT12(cStack_1ee,CONCAT11(uStack_1ef,uStack_1f0)));
          *(uint *)(lVar55 + 0x7c) = uStack_1ec;
          *(undefined4 *)(lVar55 + 0x60) = (undefined4)local_208;
          *(undefined4 *)(lVar55 + 100) = local_208._4_4_;
          *(undefined4 *)(lVar55 + 0x68) = (undefined4)uStack_200;
          *(undefined4 *)(lVar55 + 0x6c) = uStack_200._4_4_;
          *(undefined4 *)(lVar55 + 0x50) = (undefined4)local_218;
          *(undefined4 *)(lVar55 + 0x54) = local_218._4_4_;
          *(undefined4 *)(lVar55 + 0x58) = (undefined4)uStack_210;
          *(undefined4 *)(lVar55 + 0x5c) = uStack_210._4_4_;
          *(char **)(lVar55 + 0x40) = local_228;
          *(undefined8 *)(lVar55 + 0x48) = uStack_220;
          uVar7 = CONCAT44(uStack_1ac,local_1b0);
          lVar55 = local_248;
          if (uVar7 != 0) {
            FUN_1408192a0(CONCAT44(uStack_1a4,uStack_1a8),uVar7,~uVar7 >> 0x3f);
            lVar55 = local_248;
          }
          goto LAB_14044eddf;
        }
        FUN_1423ab620(0,0,0x14243aaa8);
        break;
      case 3:
switchD_14044ef2f_caseD_3:
        if (*(longlong *)(lVar46 + 0x10) == 0) {
          ppuVar69 = &PTR_s_src_net_tester_rs_14243aa40;
LAB_1404503c4:
          FUN_1423ab620(0,0,ppuVar69);
                    /* WARNING: Does not return */
          pcVar9 = (code *)invalidInstructionException();
          (*pcVar9)();
        }
        puVar57 = *(undefined8 **)(lVar46 + 8);
        if (*(char *)((longlong)puVar57 + 0x3a) == '\x02') goto LAB_14044eddf;
        puVar44 = (undefined4 *)((longlong)puVar57 + 0x35);
        local_248 = lVar55;
        local_230 = lVar46;
        local_178 = piVar62;
        cVar34 = FUN_1406b6550(puVar44,(undefined1 *)
                                       ((longlong)piVar62 + (longlong)puVar47 * 0x10 + 10));
        local_168 = puVar47;
        if (cVar34 != '\0') {
          cVar34 = FUN_1406b6550(puVar57 + 6,
                                 (undefined1 *)((longlong)local_178 + (longlong)puVar47 * 0x10 + 5))
          ;
          puVar67 = local_238;
          if (cVar34 != '\0') {
            *(undefined4 *)(local_170 + 4 + (longlong)puVar47 * 8) = uVar33;
            if ((uint)puVar73[(longlong)puVar47 * 7 + 6] < 0x10000000) {
              local_268 = *(undefined4 *)(puVar57 + 6);
              uStack_25f = *(undefined1 *)((longlong)puVar57 + 0x39);
              uStack_264 = *(undefined4 *)((longlong)puVar57 + 0x34);
              uStack_260 = (undefined1)((uint)*puVar44 >> 0x18);
              iVar37 = (uint)puVar73[(longlong)puVar47 * 7 + 6] + 1;
              *(int *)(puVar73 + (longlong)puVar47 * 7 + 6) = iVar37;
              local_180 = puVar44;
              if (local_238[2] != 0) {
                local_240 = puVar73;
                local_188 = puVar73 + (longlong)puVar47 * 7 + 6;
                uVar40 = FUN_140766420(local_238 + 4,&local_268);
                local_250 = (undefined8 *)*puVar67;
                uVar7 = puVar67[3];
                bVar75 = (byte)(uVar40 >> 0x39);
                auVar77 = ZEXT216(CONCAT11(bVar75,bVar75));
                auVar77 = pshuflw(auVar77,auVar77,0);
                local_158 = uVar7 - 0x14;
                lVar55 = 0;
                local_238 = puVar67;
                while( true ) {
                  uVar40 = uVar40 & (ulonglong)local_250;
                  pcVar2 = (char *)(uVar7 + uVar40);
                  cVar34 = *pcVar2;
                  cVar14 = pcVar2[1];
                  cVar15 = pcVar2[2];
                  cVar16 = pcVar2[3];
                  cVar17 = pcVar2[4];
                  cVar18 = pcVar2[5];
                  cVar19 = pcVar2[6];
                  cVar20 = pcVar2[7];
                  cVar21 = pcVar2[8];
                  cVar22 = pcVar2[9];
                  cVar23 = pcVar2[10];
                  cVar24 = pcVar2[0xb];
                  cVar25 = pcVar2[0xc];
                  cVar26 = pcVar2[0xd];
                  cVar27 = pcVar2[0xe];
                  cVar28 = pcVar2[0xf];
                  cVar35 = auVar77[0];
                  auVar78[0] = -(cVar35 == cVar34);
                  cVar79 = auVar77[1];
                  auVar78[1] = -(cVar79 == cVar14);
                  cVar80 = auVar77[2];
                  auVar78[2] = -(cVar80 == cVar15);
                  cVar81 = auVar77[3];
                  auVar78[3] = -(cVar81 == cVar16);
                  auVar78[4] = -(cVar35 == cVar17);
                  auVar78[5] = -(cVar79 == cVar18);
                  auVar78[6] = -(cVar80 == cVar19);
                  auVar78[7] = -(cVar81 == cVar20);
                  auVar78[8] = -(cVar35 == cVar21);
                  auVar78[9] = -(cVar79 == cVar22);
                  auVar78[10] = -(cVar80 == cVar23);
                  auVar78[0xb] = -(cVar81 == cVar24);
                  auVar78[0xc] = -(cVar35 == cVar25);
                  auVar78[0xd] = -(cVar79 == cVar26);
                  auVar78[0xe] = -(cVar80 == cVar27);
                  auVar78[0xf] = -(cVar81 == cVar28);
                  puVar73 = local_240;
                  for (uVar36 = (ushort)(SUB161(auVar78 >> 7,0) & 1) |
                                (ushort)(SUB161(auVar78 >> 0xf,0) & 1) << 1 |
                                (ushort)(SUB161(auVar78 >> 0x17,0) & 1) << 2 |
                                (ushort)(SUB161(auVar78 >> 0x1f,0) & 1) << 3 |
                                (ushort)(SUB161(auVar78 >> 0x27,0) & 1) << 4 |
                                (ushort)(SUB161(auVar78 >> 0x2f,0) & 1) << 5 |
                                (ushort)(SUB161(auVar78 >> 0x37,0) & 1) << 6 |
                                (ushort)(SUB161(auVar78 >> 0x3f,0) & 1) << 7 |
                                (ushort)(SUB161(auVar78 >> 0x47,0) & 1) << 8 |
                                (ushort)(SUB161(auVar78 >> 0x4f,0) & 1) << 9 |
                                (ushort)(SUB161(auVar78 >> 0x57,0) & 1) << 10 |
                                (ushort)(SUB161(auVar78 >> 0x5f,0) & 1) << 0xb |
                                (ushort)(SUB161(auVar78 >> 0x67,0) & 1) << 0xc |
                                (ushort)(SUB161(auVar78 >> 0x6f,0) & 1) << 0xd |
                                (ushort)(SUB161(auVar78 >> 0x77,0) & 1) << 0xe |
                                (ushort)(auVar78[0xf] >> 7) << 0xf; local_240 = puVar73, uVar36 != 0
                      ; uVar36 = uVar36 - 1 & uVar36) {
                    uVar8 = 0;
                    if (uVar36 != 0) {
                      for (; (uVar36 >> uVar8 & 1) == 0; uVar8 = uVar8 + 1) {
                      }
                    }
                    lVar46 = local_158 + (uVar8 + uVar40 & (ulonglong)local_250) * -0x14;
                    cVar35 = FUN_1406b6550(&local_268,lVar46);
                    if ((cVar35 != '\0') &&
                       (cVar35 = FUN_1406b6550((longlong)&uStack_264 + 1,lVar46 + 5), cVar35 != '\0'
                       )) {
                      *(int *)(lVar46 + 0xc) = *(int *)(lVar46 + 0xc) + 1;
                      *(int *)(lVar46 + 0x10) = (int)*local_188;
                      puVar44 = local_180;
                      puVar73 = local_240;
                      goto LAB_1404501fa;
                    }
                    puVar73 = local_240;
                  }
                  auVar83[0] = -(cVar34 == (char)iVar10);
                  auVar83[1] = -(cVar14 == cVar84);
                  auVar83[2] = -(cVar15 == cVar85);
                  auVar83[3] = -(cVar16 == cVar86);
                  auVar83[4] = -(cVar17 == (char)iVar11);
                  auVar83[5] = -(cVar18 == cVar87);
                  auVar83[6] = -(cVar19 == cVar88);
                  auVar83[7] = -(cVar20 == cVar89);
                  auVar83[8] = -(cVar21 == (char)iVar12);
                  auVar83[9] = -(cVar22 == cVar90);
                  auVar83[10] = -(cVar23 == cVar91);
                  auVar83[0xb] = -(cVar24 == cVar92);
                  auVar83[0xc] = -(cVar25 == (char)iVar13);
                  auVar83[0xd] = -(cVar26 == cVar93);
                  auVar83[0xe] = -(cVar27 == cVar94);
                  auVar83[0xf] = -(cVar28 == cVar95);
                  if ((((((((((((((((SUB161(auVar83 >> 7,0) & 1) != 0 ||
                                   (SUB161(auVar83 >> 0xf,0) & 1) != 0) ||
                                  (SUB161(auVar83 >> 0x17,0) & 1) != 0) ||
                                 (SUB161(auVar83 >> 0x1f,0) & 1) != 0) ||
                                (SUB161(auVar83 >> 0x27,0) & 1) != 0) ||
                               (SUB161(auVar83 >> 0x2f,0) & 1) != 0) ||
                              (SUB161(auVar83 >> 0x37,0) & 1) != 0) ||
                             (SUB161(auVar83 >> 0x3f,0) & 1) != 0) ||
                            (SUB161(auVar83 >> 0x47,0) & 1) != 0) ||
                           (SUB161(auVar83 >> 0x4f,0) & 1) != 0) ||
                          (SUB161(auVar83 >> 0x57,0) & 1) != 0) ||
                         (SUB161(auVar83 >> 0x5f,0) & 1) != 0) ||
                        (SUB161(auVar83 >> 0x67,0) & 1) != 0) ||
                       (SUB161(auVar83 >> 0x6f,0) & 1) != 0) || (SUB161(auVar83 >> 0x77,0) & 1) != 0
                      ) || auVar83[0xf] < '\0') break;
                  uVar40 = uVar40 + lVar55 + 0x10;
                  lVar55 = lVar55 + 0x10;
                }
                iVar37 = (int)*local_188;
              }
              uStack_1c0 = CONCAT62(uStack_1c0._2_6_,CONCAT11(uStack_25f,uStack_260));
              local_1c8 = (char *)CONCAT44(uStack_264,local_268);
              FUN_14037bf80(&local_228,local_238,&local_1c8,1,iVar37);
              puVar44 = local_180;
            }
          }
        }
LAB_1404501fa:
        lVar55 = local_248;
        local_1c8 = (char *)CONCAT44(CONCAT31(local_1c8._5_3_,
                                              *(undefined1 *)((longlong)puVar57 + 0x34)),
                                     *(undefined4 *)(puVar57 + 6));
        local_268 = *puVar44;
        uStack_264 = CONCAT31(uStack_264._1_3_,*(undefined1 *)(puVar44 + 1));
        puVar67 = (ulonglong *)puVar57[2];
        uVar4 = *(undefined2 *)((longlong)puVar57 + 0x3a);
        FUN_1423a1b30(&uStack_210,puVar57 + 3);
        local_228 = (char *)*puVar57;
        uStack_220 = puVar57[1];
        local_1f8 = (undefined4)local_1c8;
        uStack_1ef = (undefined1)uStack_264;
        uStack_1f4._1_3_ = (undefined3)local_268;
        uStack_1f4 = CONCAT31(uStack_1f4._1_3_,local_1c8._4_1_);
        uStack_1f0 = (undefined1)((uint)local_268 >> 0x18);
        cStack_1ee = (char)uVar4;
        cStack_1ed = (char)((ushort)uVar4 >> 8);
        uStack_1ec = CONCAT31(uStack_1ec._1_3_,*(undefined1 *)((longlong)puVar57 + 0x3c));
        *(undefined4 *)(lVar70 + 4 + (longlong)local_168 * 8) = uVar33;
        local_218 = puVar67;
        if (*(longlong *)(local_230 + 0x10) != 0) {
          lVar46 = *(longlong *)(local_230 + 8);
          if ((*(char *)(lVar46 + 0x7a) != '\x02') &&
             (uVar7 = *(ulonglong *)(lVar46 + 0x58), uVar7 != 0)) {
            FUN_1408192a0(*(undefined8 *)(lVar46 + 0x60),uVar7,~uVar7 >> 0x3f);
          }
          *(ulonglong *)(lVar46 + 0x70) = CONCAT44(uStack_1f4,local_1f8);
          *(ulonglong *)(lVar46 + 0x78) =
               CONCAT44(uStack_1ec,
                        CONCAT13(cStack_1ed,CONCAT12(cStack_1ee,CONCAT11(uStack_1ef,uStack_1f0))));
          *(undefined4 **)(lVar46 + 0x60) = local_208;
          *(undefined8 *)(lVar46 + 0x68) = uStack_200;
          *(ulonglong **)(lVar46 + 0x50) = local_218;
          *(undefined8 *)(lVar46 + 0x58) = uStack_210;
          *(char **)(lVar46 + 0x40) = local_228;
          *(undefined8 *)(lVar46 + 0x48) = uStack_220;
          piVar62 = local_178;
          goto LAB_14044eddf;
        }
        FUN_1423ab620(0,0,&PTR_s_src_net_tester_rs_14243aa58);
        break;
      case 4:
switchD_14044ef2f_caseD_4:
        pbVar39 = (byte *)((longlong)&switchD_14044ef2f::switchdataD_1404504bc +
                          (longlong)(int)uVar5);
        *pbVar39 = *pbVar39 | (byte)pbVar39;
        if (*pbVar39 != 0) {
          if ((*(longlong *)(piVar62 + 6) != 0) && (uVar7 = *(ulonglong *)(piVar62 + 4), uVar7 != 0)
             ) {
            FUN_1408192a0(*(longlong *)(piVar62 + 6),uVar7,~uVar7 >> 0x3f);
          }
          if ((*(longlong *)(piVar62 + 0xc) != 0) &&
             (uVar7 = *(ulonglong *)(piVar62 + 10), uVar7 != 0)) {
            FUN_1408192a0(*(longlong *)(piVar62 + 0xc),uVar7,~uVar7 >> 0x3f);
          }
          if ((*(longlong *)(piVar62 + 0x12) != 0) &&
             (uVar7 = *(ulonglong *)(piVar62 + 0x10), uVar7 != 0)) {
            FUN_1408192a0(*(longlong *)(piVar62 + 0x12),uVar7,~uVar7 >> 0x3f);
            return;
          }
        }
        return;
      }
                    /* WARNING: Does not return */
      pcVar9 = (code *)invalidInstructionException();
      (*pcVar9)();
    }
  }
  return;
}

