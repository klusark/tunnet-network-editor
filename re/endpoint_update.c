
/* WARNING: Instruction at (ram,0x0001402f8ba0) overlaps instruction at (ram,0x0001402f8b9c)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0001402f5b0f) */

void FUN_1402f5840(undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 *param_4)

{
  byte *pbVar1;
  longlong lVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  ulonglong *puVar6;
  longlong lVar7;
  ulonglong *puVar8;
  undefined8 uVar9;
  longlong lVar10;
  uint *puVar11;
  ushort uVar12;
  code *pcVar13;
  undefined2 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined4 uVar18;
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
  char cVar29;
  char cVar30;
  char cVar31;
  char cVar32;
  byte bVar33;
  byte bVar34;
  int iVar35;
  uint uVar36;
  ulonglong uVar37;
  uint *puVar38;
  uint7 uVar47;
  uint *puVar39;
  char (*pacVar40) [8];
  int *piVar41;
  char *pcVar42;
  undefined4 *puVar43;
  ulonglong uVar44;
  undefined8 *puVar45;
  longlong lVar46;
  byte bVar49;
  byte bVar50;
  undefined1 uVar51;
  ulonglong uVar52;
  uint *puVar53;
  undefined8 uVar54;
  longlong *plVar55;
  ulonglong uVar56;
  uint *puVar57;
  longlong lVar58;
  ushort uVar59;
  longlong *plVar60;
  uint *puVar61;
  longlong lVar62;
  undefined8 *puVar63;
  undefined1 *puVar64;
  undefined1 *puVar65;
  undefined8 *puVar66;
  undefined8 *puVar67;
  undefined8 *puVar68;
  undefined8 *puVar69;
  undefined8 *puVar70;
  ulonglong uVar71;
  longlong lVar72;
  uint *puVar73;
  undefined8 uVar74;
  longlong *plVar75;
  longlong *plVar76;
  longlong *plVar77;
  char *pcVar78;
  uint *puVar79;
  uint *puVar80;
  longlong lVar81;
  int iVar82;
  longlong *plVar83;
  uint *_Src;
  longlong lVar84;
  longlong *plVar85;
  undefined1 *puVar86;
  ulonglong *puVar87;
  undefined2 in_FS;
  bool bVar88;
  undefined4 uVar89;
  undefined1 auVar90 [16];
  undefined1 auVar91 [16];
  undefined1 auVar92 [16];
  undefined1 auVar96 [16];
  undefined1 auVar97 [16];
  undefined1 auVar98 [16];
  undefined4 uVar102;
  undefined1 auVar103 [16];
  undefined1 auVar104 [16];
  undefined1 unaff_XMM13_Ba;
  char cVar105;
  undefined1 unaff_XMM13_Bb;
  char cVar106;
  undefined1 unaff_XMM13_Bc;
  char cVar107;
  undefined1 unaff_XMM13_Bd;
  char cVar108;
  undefined1 unaff_XMM13_Be;
  char cVar109;
  undefined1 unaff_XMM13_Bf;
  char cVar110;
  undefined1 unaff_XMM13_Bg;
  char cVar111;
  undefined1 unaff_XMM13_Bh;
  char cVar112;
  undefined1 unaff_XMM13_Bi;
  char cVar113;
  undefined1 unaff_XMM13_Bj;
  char cVar114;
  undefined1 unaff_XMM13_Bk;
  char cVar115;
  undefined1 unaff_XMM13_Bl;
  char cVar116;
  undefined1 unaff_XMM13_Bm;
  char cVar117;
  undefined1 unaff_XMM13_Bn;
  char cVar118;
  undefined1 unaff_XMM13_Bo;
  char cVar119;
  undefined1 unaff_XMM13_Bp;
  char cVar120;
  uint *in_stack_00000040;
  undefined1 auStack_408 [136];
  undefined **local_380;
  uint local_308 [56];
  undefined8 local_228;
  undefined8 local_220;
  undefined8 local_218;
  undefined4 local_20c;
  undefined **local_168;
  undefined4 local_160;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  longlong local_e0;
  undefined8 local_d8;
  ulonglong *local_d0;
  undefined7 uVar48;
  char cVar93;
  char cVar94;
  char cVar95;
  char cVar99;
  char cVar100;
  char cVar101;
  
  puVar66 = (undefined8 *)auStack_408;
  puVar6 = (ulonglong *)*param_3;
  puVar87 = (ulonglong *)param_3[1];
  uVar37 = *puVar6;
  uVar56 = 0;
  uVar52 = uVar37 - *puVar87;
  if (uVar37 < *puVar87) {
    uVar52 = uVar56;
  }
  uVar44 = uVar37 - puVar87[1];
  if (uVar37 < puVar87[1]) {
    uVar44 = uVar56;
  }
  plVar75 = (longlong *)(uVar52 * 8 + puVar87[4]);
  uVar37 = puVar87[5] - uVar52;
  if (puVar87[5] < uVar52) {
    plVar75 = &DAT_1424629f0;
    uVar37 = uVar56;
  }
  plVar60 = (longlong *)(uVar44 * 8 + puVar87[7]);
  uVar52 = puVar87[8];
  if (uVar52 < uVar44) {
    plVar60 = &DAT_1424629f0;
  }
  uVar71 = uVar52 - uVar44;
  if (uVar52 < uVar44) {
    uVar71 = uVar56;
  }
  uVar52 = (puVar87[2] - uVar71) - uVar37;
  *puVar6 = uVar52;
  if ((char)puVar87[9] == '\0') {
    plVar55 = plVar60 + uVar71;
    plVar85 = plVar75 + uVar37;
    plVar77 = plVar75;
    plVar76 = plVar75;
    if (plVar60 != plVar55) goto LAB_1402f5933;
  }
  else {
    plVar55 = plVar75 + uVar37;
    plVar85 = plVar60 + uVar71;
    plVar77 = plVar60;
    plVar76 = plVar60;
    plVar60 = plVar75;
    if (plVar75 != plVar55) {
LAB_1402f5933:
      plVar77 = plVar60;
      plVar75 = plVar77 + 1;
      goto LAB_1402f595e;
    }
  }
  if (plVar77 == plVar85) {
    return;
  }
  plVar76 = plVar77 + 1;
  plVar75 = (longlong *)0x0;
LAB_1402f595e:
  if (uVar52 < *plVar77 + 1U) {
    uVar52 = *plVar77 + 1U;
  }
  *puVar6 = uVar52;
  if (plVar77 == (longlong *)0x0) {
    return;
  }
  do {
    if ((plVar75 == (longlong *)0x0) || (plVar75 == plVar55)) {
      if ((plVar76 == (longlong *)0x0) || (plVar76 == plVar85)) break;
      plVar83 = plVar76 + 1;
      plVar75 = (longlong *)0x0;
      plVar60 = plVar76;
    }
    else {
      plVar60 = plVar75;
      plVar75 = plVar75 + 1;
      plVar83 = plVar76;
    }
    if (uVar52 < *plVar60 + 1U) {
      uVar52 = *plVar60 + 1U;
    }
    *puVar6 = uVar52;
    plVar76 = plVar83;
  } while (plVar60 != (longlong *)0x0);
  if (plVar77 == (longlong *)0x0) {
    return;
  }
  *in_stack_00000040 = *in_stack_00000040 + 1 & 0xffff;
  local_228 = param_1;
  local_220 = param_2;
  local_218 = FUN_14204d800();
  uVar74 = *param_4;
  lVar7 = param_4[1];
  uVar89 = *(undefined4 *)(param_4 + 2);
  uVar102 = *(undefined4 *)((longlong)param_4 + 0x14);
  local_e0 = lVar7 + 0x50;
  local_108 = FUN_14221bbe0(uVar74,local_e0,uVar89,uVar102);
  FUN_14221def0(uVar74,lVar7,uVar89,uVar102);
  local_160 = uVar102;
  local_d8 = uVar74;
  local_d0 = *(ulonglong **)(lVar7 + 0x80) + *(longlong *)(lVar7 + 0x88);
  local_120 = 1;
  local_128 = 0x10;
  local_100 = 8;
  local_168 = &PTR_s__home_puzzled_squid_src_tunnet_d_14241fb50;
  iVar82 = -(uint)(CONCAT13(unaff_XMM13_Bd,
                            CONCAT12(unaff_XMM13_Bc,CONCAT11(unaff_XMM13_Bb,unaff_XMM13_Ba))) ==
                  CONCAT13(unaff_XMM13_Bd,
                           CONCAT12(unaff_XMM13_Bc,CONCAT11(unaff_XMM13_Bb,unaff_XMM13_Ba))));
  cVar105 = (char)iVar82;
  cVar106 = (char)((uint)iVar82 >> 8);
  cVar107 = (char)((uint)iVar82 >> 0x10);
  cVar108 = (char)((uint)iVar82 >> 0x18);
  iVar82 = -(uint)(CONCAT13(unaff_XMM13_Bh,
                            CONCAT12(unaff_XMM13_Bg,CONCAT11(unaff_XMM13_Bf,unaff_XMM13_Be))) ==
                  CONCAT13(unaff_XMM13_Bh,
                           CONCAT12(unaff_XMM13_Bg,CONCAT11(unaff_XMM13_Bf,unaff_XMM13_Be))));
  cVar109 = (char)iVar82;
  cVar110 = (char)((uint)iVar82 >> 8);
  cVar111 = (char)((uint)iVar82 >> 0x10);
  cVar112 = (char)((uint)iVar82 >> 0x18);
  iVar82 = -(uint)(CONCAT13(unaff_XMM13_Bl,
                            CONCAT12(unaff_XMM13_Bk,CONCAT11(unaff_XMM13_Bj,unaff_XMM13_Bi))) ==
                  CONCAT13(unaff_XMM13_Bl,
                           CONCAT12(unaff_XMM13_Bk,CONCAT11(unaff_XMM13_Bj,unaff_XMM13_Bi))));
  cVar113 = (char)iVar82;
  cVar114 = (char)((uint)iVar82 >> 8);
  cVar115 = (char)((uint)iVar82 >> 0x10);
  cVar116 = (char)((uint)iVar82 >> 0x18);
  iVar82 = -(uint)(CONCAT13(unaff_XMM13_Bp,
                            CONCAT12(unaff_XMM13_Bo,CONCAT11(unaff_XMM13_Bn,unaff_XMM13_Bm))) ==
                  CONCAT13(unaff_XMM13_Bp,
                           CONCAT12(unaff_XMM13_Bo,CONCAT11(unaff_XMM13_Bn,unaff_XMM13_Bm))));
  cVar117 = (char)iVar82;
  cVar118 = (char)((uint)iVar82 >> 8);
  cVar119 = (char)((uint)iVar82 >> 0x10);
  cVar120 = (char)((uint)iVar82 >> 0x18);
  puVar39 = local_308;
  local_380 = &PTR_s__home_puzzled_squid_src_tunnet_d_14241fb50;
  local_20c = 0;
  local_118 = 8;
  local_110 = 0;
  puVar6 = *(ulonglong **)(lVar7 + 0x80);
LAB_1402f94f4:
  puVar87 = puVar6;
  if (puVar87 == *(ulonglong **)((longlong)puVar66 + 0x338)) {
    plVar75 = *(longlong **)((longlong)puVar66 + 0x1f0);
    *plVar75 = *plVar75 + -1;
    if (*plVar75 != 0) {
      return;
    }
    plVar60 = plVar75 + 1;
    *plVar60 = *plVar60 + -1;
    if (*plVar60 != 0) {
      return;
    }
    *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f9723;
    FUN_1408192a0(plVar75,0x170,0x10);
    return;
  }
  uVar37 = *puVar87;
  uVar52 = *(ulonglong *)(*(longlong *)((longlong)puVar66 + 0x330) + 0xd8);
  if (uVar37 < uVar52) {
    lVar72 = *(longlong *)(*(longlong *)((longlong)puVar66 + 0x330) + 0xd0);
    lVar62 = uVar37 * 0x60;
    uVar37 = *(ulonglong *)(lVar72 + 0x40 + lVar62);
    if (**(ulonglong **)((longlong)puVar66 + 0x328) < uVar37) {
      lVar2 = lVar72 + lVar62;
      lVar10 = *(longlong *)(lVar2 + 0x38);
      lVar46 = **(ulonglong **)((longlong)puVar66 + 0x328) * 0x10;
      if (*(longlong *)(lVar10 + lVar46) != 0) {
        if ((*(ulonglong *)(lVar7 + 0x58) < uVar37) &&
           (lVar84 = *(ulonglong *)(lVar7 + 0x58) * 0x10, *(longlong *)(lVar10 + lVar84) != 0)) {
          if ((((*(ulonglong *)(lVar7 + 0x60) < uVar37) &&
               (lVar81 = *(ulonglong *)(lVar7 + 0x60) * 0x10, *(longlong *)(lVar10 + lVar81) != 0))
              && (*(ulonglong *)(lVar7 + 0x68) < uVar37)) &&
             (*(longlong *)(lVar10 + *(ulonglong *)(lVar7 + 0x68) * 0x10) != 0)) {
            if ((*(ulonglong *)(lVar7 + 0x70) < uVar37) &&
               (lVar58 = *(ulonglong *)(lVar7 + 0x70) * 0x10, *(longlong *)(lVar10 + lVar58) != 0))
            {
              uVar74 = *(undefined8 *)
                        (*(longlong *)(lVar2 + 8) + 0x40 + *(longlong *)(lVar10 + 8 + lVar58) * 0x58
                        );
              *(undefined8 *)((longlong)puVar66 + 0x308) = uVar74;
              uVar89 = (undefined4)CONCAT71((int7)((ulonglong)uVar74 >> 8),1);
              puVar11 = *(uint **)(lVar72 + 0x58 + lVar62);
            }
            else {
              uVar89 = 0;
              puVar11 = *(uint **)(lVar72 + 0x58 + lVar62);
            }
            puVar6 = puVar87 + 1;
            if (puVar11 != (uint *)0x0) {
              *(undefined4 *)((longlong)puVar66 + 0x1fc) = uVar89;
              lVar72 = *(longlong *)(lVar2 + 8);
              *(undefined8 *)((longlong)puVar66 + 0x300) = *(undefined8 *)(lVar2 + 0x50);
              *(undefined8 *)((longlong)puVar66 + 0x2e8) =
                   *(undefined8 *)(lVar72 + 0x40 + *(longlong *)(lVar10 + 8 + lVar46) * 0x58);
              lVar62 = *(longlong *)(lVar10 + 8 + lVar84) * 0x58;
              *(undefined8 *)((longlong)puVar66 + 0x2f8) = *(undefined8 *)(lVar72 + 0x10 + lVar62);
              *(undefined8 *)((longlong)puVar66 + 0x2f0) = *(undefined8 *)(lVar72 + 0x40 + lVar62);
              *(undefined8 *)((longlong)puVar66 + 0x2e0) =
                   *(undefined8 *)(lVar72 + 0x40 + *(longlong *)(lVar10 + 8 + lVar81) * 0x58);
              puVar73 = (uint *)0x0;
LAB_1402f9657:
              do {
                uVar89 = *(undefined4 *)
                          (*(longlong *)((longlong)puVar66 + 0x300) + (longlong)puVar73 * 8);
                uVar102 = *(undefined4 *)
                           (*(longlong *)((longlong)puVar66 + 0x300) + 4 + (longlong)puVar73 * 8);
                *(undefined ***)((longlong)puVar66 + 0x20) = &PTR_s_src_net_endpoint_rs_1424241e0;
                *(undefined4 *)((longlong)puVar66 + 0x7c) = uVar89;
                *(undefined4 *)((longlong)puVar66 + 0x78) = uVar102;
                *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f968e;
                FUN_142244e00(puVar39,(undefined1 *)((longlong)puVar66 + 0x1e0));
                uVar89 = *(undefined4 *)((longlong)puVar66 + 0x100);
                uVar102 = *(undefined4 *)((longlong)puVar66 + 0x104);
                puVar80 = (uint *)**(undefined8 **)((longlong)puVar66 + 0x108);
                puVar61 = *(uint **)(puVar80 + 4);
                lVar72 = *(longlong *)(puVar80 + 10);
                if (lVar72 == *(longlong *)(puVar80 + 6)) {
                  *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f96b9;
                  FUN_14079f6c0(puVar80 + 6);
                  lVar72 = *(longlong *)(puVar80 + 10);
                }
                lVar62 = *(longlong *)(puVar80 + 8);
                *(uint **)(lVar62 + lVar72 * 0x10) = puVar61;
                *(code **)(lVar62 + 8 + lVar72 * 0x10) = FUN_140692ea0;
                *(longlong *)(puVar80 + 10) = *(longlong *)(puVar80 + 10) + 1;
                _Src = puVar73;
                if ((ulonglong)(*(longlong *)puVar80 - *(longlong *)(puVar80 + 4)) < 8) {
                  *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f96fb;
                  FUN_1407a1510(puVar80);
                }
LAB_1402f5b20:
                puVar38 = (uint *)((longlong)_Src * 3);
                puVar57 = (uint *)(*(longlong *)((longlong)puVar66 + 0x2f0) + (longlong)_Src * 0x18)
                ;
                puVar73 = (uint *)((longlong)_Src + 1);
                lVar72 = *(longlong *)(puVar80 + 2);
                *(undefined4 *)(lVar72 + (longlong)puVar61) = uVar89;
                *(undefined4 *)((byte *)(lVar72 + (longlong)puVar61) + 4) = uVar102;
                *(uint **)(puVar80 + 4) = puVar61 + 2;
                *(undefined4 *)(*(longlong *)((longlong)puVar66 + 0x2f8) + 4 + (longlong)_Src * 8) =
                     *(undefined4 *)((longlong)puVar66 + 0x2a8);
                puVar53 = *(uint **)(puVar57 + 4);
                puVar6 = puVar87 + 1;
                if (puVar53 != (uint *)0x0) {
LAB_1402f5b72:
                  *(uint **)((longlong)puVar66 + 0x318) = puVar73;
                  puVar61 = *(uint **)(puVar57 + 2);
                  *(longlong *)((longlong)puVar66 + 0x68) =
                       (longlong)_Src * 5 + *(longlong *)((longlong)puVar66 + 0x2e8);
                  *(longlong *)((longlong)puVar66 + 0x298) =
                       (longlong)puVar38 * 0x10 + *(longlong *)((longlong)puVar66 + 0x2e0) + 0x10;
                  *(uint **)((longlong)puVar66 + 800) = puVar61 + (longlong)puVar53 * 0x26;
                  *(bool *)((longlong)puVar66 + 0x57) =
                       *(longlong *)((longlong)puVar66 + 0x308) == 0 ||
                       *(char *)((longlong)puVar66 + 0x1fc) == '\0';
LAB_1402f5bf5:
                  bVar33 = *(byte *)((longlong)puVar61 + 0x7a);
                  puVar66[0xc] = puVar61;
                  if (bVar33 != 2) goto LAB_1402f5f3c;
                  puVar8 = *(ulonglong **)(puVar66[0x88] + 0x10);
                  uVar4 = *(undefined4 *)puVar66[0x89];
                  puVar66[-1] = 0x1402f5c2b;
                  FUN_1402f9a40(puVar39,puVar8,puVar66[0xd],uVar4);
                  lVar72 = puVar66[0xc];
                  if ((*(char *)(lVar72 + 0x7a) != '\x02') && (*(longlong *)(lVar72 + 0x58) != 0)) {
                    uVar74 = *(undefined8 *)(lVar72 + 0x60);
                    puVar66[-1] = 0x1402f5c56;
                    FUN_1408192a0(uVar74);
                  }
                  uVar74 = puVar66[0x20];
                  uVar54 = puVar66[0x21];
                  uVar9 = puVar66[0x22];
                  uVar15 = puVar66[0x23];
                  uVar16 = puVar66[0x24];
                  uVar17 = puVar66[0x25];
                  uVar4 = *(undefined4 *)((longlong)puVar66 + 0x134);
                  uVar5 = *(undefined4 *)(puVar66 + 0x27);
                  uVar18 = *(undefined4 *)((longlong)puVar66 + 0x13c);
                  *(undefined4 *)(lVar72 + 0x70) = *(undefined4 *)(puVar66 + 0x26);
                  *(undefined4 *)(lVar72 + 0x74) = uVar4;
                  *(undefined4 *)(lVar72 + 0x78) = uVar5;
                  *(undefined4 *)(lVar72 + 0x7c) = uVar18;
                  *(undefined8 *)(lVar72 + 0x60) = uVar16;
                  *(undefined8 *)(lVar72 + 0x68) = uVar17;
                  *(undefined8 *)(lVar72 + 0x50) = uVar9;
                  *(undefined8 *)(lVar72 + 0x58) = uVar15;
                  *(undefined8 *)(lVar72 + 0x40) = uVar74;
                  *(undefined8 *)(lVar72 + 0x48) = uVar54;
                  *(undefined1 *)((longlong)puVar66 + 0x104) = 0;
                  *(undefined4 *)(puVar66 + 0x20) = 0x3020101;
                  if ((4 < *(byte *)puVar66[0xd]) || (*(byte *)puVar66[0xd] == 1)) {
                    lVar72 = puVar66[0xd];
                    if (1 < *(byte *)(lVar72 + 3)) {
                      puVar66[-1] = 0x1402f6b3e;
                      FUN_1406b6550(lVar72,puVar39);
                      goto switchD_1402f62f9_caseD_402f6b3e;
                    }
                    if (*(byte *)(lVar72 + 2) < 2) {
                      puVar61 = (uint *)puVar66[0xc];
                      if (puVar61[0x20] != 1) goto LAB_1402f5cbd;
                      if (*(char *)((longlong)puVar8 + 0x1c4) != '\x05') goto LAB_1402f5cbd;
                      *(undefined4 *)(*(longlong *)puVar66[0x88] + 4) =
                           *(undefined4 *)((longlong)puVar66[0x88] + 0xc);
                      if (*(char *)((longlong)puVar8 + 0x1c4) == '\x06') goto LAB_1402f5cbd;
                      *(undefined1 *)((longlong)puVar8 + 0x1c4) = 6;
                      *(undefined2 *)(puVar66 + 0x40) = 0xf;
                      puVar66[-1] = 0x1402f5e7f;
                      FUN_1405211a0(puVar66 + 0x21,puVar66 + 0x40);
                      *(undefined2 *)(puVar66 + 0x20) = 0xf;
                      uVar37 = *puVar8;
                      uVar52 = puVar8[3];
                      puVar61 = (uint *)puVar66[0xc];
                      if (uVar52 == uVar37) {
                        puVar66[-1] = 0x1402f5ea2;
                        FUN_140293030(puVar8);
                        uVar37 = *puVar8;
                        uVar52 = puVar8[3];
                      }
                      uVar56 = puVar8[2];
                      uVar44 = 0;
                      if (uVar37 <= uVar52 + uVar56) {
                        uVar44 = uVar37;
                      }
                      uVar37 = puVar8[1];
                      puVar66[-1] = 0x1402f5ed6;
                      memcpy((void *)(((uVar52 + uVar56) - uVar44) * 0x90 + uVar37),puVar39,0x90);
                      puVar8[3] = puVar8[3] + 1;
                      goto LAB_1402f5cbd;
                    }
                  }
LAB_1402f5cb8:
                  puVar61 = (uint *)puVar66[0xc];
LAB_1402f5cbd:
                  if (*(byte *)((longlong)puVar61 + 0x7a) != 2) {
                    *(undefined4 *)(puVar66 + 0x21) =
                         *(undefined4 *)((undefined8 *)puVar66[0x53] + 1);
                    puVar66[0x20] = *(undefined8 *)puVar66[0x53];
                    lVar72 = puVar66[0x3e];
                    uVar37 = *(ulonglong *)(lVar72 + 0x110);
                    do {
                      if (0x3f < uVar37) {
                        puVar66[-1] = 0x1402f5d4b;
                        lVar62 = FUN_14204e720();
                        if ((*(longlong *)(lVar72 + 0x158) < 1) ||
                           (*(longlong *)(lVar72 + 0x160) - lVar62 < 0)) {
                          puVar66[-1] = 0x1402f5d0e;
                          FUN_1404628b0(lVar72 + 0x120,lVar72 + 0x10);
                        }
                        else {
                          *(longlong *)(lVar72 + 0x158) = *(longlong *)(lVar72 + 0x158) + -0x100;
                          puVar66[-1] = 0x1402f5d7e;
                          FUN_14204f0e0(lVar72 + 0x120,6);
                        }
                        *(undefined8 *)(lVar72 + 0x110) = 0;
                        uVar37 = 0;
                      }
                      uVar36 = *(uint *)(lVar72 + 0x10 + uVar37 * 4);
                      uVar37 = uVar37 + 1;
                      *(ulonglong *)(lVar72 + 0x110) = uVar37;
                      uVar52 = (ulonglong)uVar36 * 7;
                    } while ((~(uint)uVar52 & 0xe0000000) == 0);
                    pcVar78 = 
                    "beep_send6beep_send5beep_send4beep_send3beep_send2beep_send1beep_send0PINGPONG"
                    ;
                    if ((uint)(uVar52 >> 0x20) < 6) {
                      pcVar78 = &DAT_1424257c0 + *(int *)(&DAT_1424257c0 + (uVar52 >> 0x20) * 4);
                    }
                    *(undefined4 *)(puVar66 + 0x41) = *(undefined4 *)(puVar66 + 0x21);
                    puVar66[0x40] = puVar66[0x20];
                    plVar75 = (longlong *)puVar66[0x8a];
                    *(undefined4 *)(*plVar75 + 4) = *(undefined4 *)((longlong)plVar75 + 0xc);
                    lVar72 = plVar75[2];
                    uVar74 = *(undefined8 *)(lVar72 + 0x10);
                    if (*(char *)(lVar72 + 0x48) == '\0') {
                      plVar75 = (longlong *)(lVar72 + 0x28);
                      lVar62 = *(longlong *)(lVar72 + 0x28);
                      if (lVar62 == *(longlong *)(lVar72 + 0x18)) {
                        puVar66[-1] = 0x1402f5ef6;
                        FUN_14079f430(lVar72 + 0x18);
                        lVar62 = *plVar75;
                      }
                      plVar60 = (longlong *)(lVar72 + 0x20);
                    }
                    else {
                      plVar75 = (longlong *)(lVar72 + 0x40);
                      lVar62 = *(longlong *)(lVar72 + 0x40);
                      if (lVar62 == *(longlong *)(lVar72 + 0x30)) {
                        puVar66[-1] = 0x1402f5df6;
                        FUN_14079f430(lVar72 + 0x30);
                        lVar62 = *plVar75;
                      }
                      plVar60 = (longlong *)(lVar72 + 0x38);
                    }
                    lVar2 = *plVar60;
                    *(char **)(lVar2 + lVar62 * 0x28) = pcVar78;
                    *(undefined8 *)(lVar2 + 8 + lVar62 * 0x28) = 10;
                    *(undefined8 *)(lVar2 + 0x10 + lVar62 * 0x28) = puVar66[0x40];
                    *(undefined4 *)(lVar2 + 0x18 + lVar62 * 0x28) = *(undefined4 *)(puVar66 + 0x41);
                    *(undefined8 *)(lVar2 + 0x20 + lVar62 * 0x28) = uVar74;
                    *plVar75 = *plVar75 + 1;
                    *(longlong *)(lVar72 + 0x10) = *(longlong *)(lVar72 + 0x10) + 1;
                    puVar61 = (uint *)puVar66[0xc];
                  }
LAB_1402f5f3c:
                  bVar33 = *(byte *)((longlong)puVar61 + 0x3a);
                  if (bVar33 == 2) goto LAB_1402f8b9c;
                  *(byte *)((longlong)puVar66 + 0xc4) = (byte)puVar61[0xd];
                  *(uint *)(puVar66 + 0x18) = puVar61[0xc];
                  *(byte *)((longlong)puVar66 + 0x204) = *(byte *)((longlong)puVar61 + 0x39);
                  *(undefined4 *)(puVar66 + 0x40) = *(undefined4 *)((longlong)puVar61 + 0x35);
                  uVar74 = *(undefined8 *)(puVar61 + 4);
                  bVar34 = *(byte *)((longlong)puVar61 + 0x3b);
                  puVar66[-1] = 0x1402f5f8a;
                  FUN_1423a1b30(puVar39,puVar61 + 6);
                  puVar45 = (undefined8 *)puVar66[0xc];
                  uVar51 = *(undefined1 *)((longlong)puVar45 + 0x3c);
                  uVar54 = *puVar45;
                  uVar9 = puVar45[1];
                  *(undefined4 *)(puVar66 + 0x3b) = *(undefined4 *)(puVar66 + 0x18);
                  *(undefined1 *)((longlong)puVar66 + 0x1dc) =
                       *(undefined1 *)((longlong)puVar66 + 0xc4);
                  *(undefined4 *)(puVar66 + 0x3a) = *(undefined4 *)(puVar66 + 0x40);
                  *(undefined1 *)((longlong)puVar66 + 0x1d4) =
                       *(undefined1 *)((longlong)puVar66 + 0x204);
                  puVar66[0x56] = puVar66[0x20];
                  puVar66[0x57] = puVar66[0x21];
                  puVar66[0x58] = puVar66[0x22];
                  puVar66[0x18] = uVar54;
                  puVar66[0x19] = uVar9;
                  puVar66[0x1a] = uVar74;
                  puVar66[0x1d] = puVar66[0x58];
                  puVar66[0x1b] = puVar66[0x56];
                  puVar66[0x1c] = puVar66[0x57];
                  *(undefined1 *)((longlong)puVar66 + 0xf4) =
                       *(undefined1 *)((longlong)puVar66 + 0x1dc);
                  *(undefined4 *)(puVar66 + 0x1e) = *(undefined4 *)(puVar66 + 0x3b);
                  *(undefined1 *)((longlong)puVar66 + 0xf9) =
                       *(undefined1 *)((longlong)puVar66 + 0x1d4);
                  *(undefined4 *)((longlong)puVar66 + 0xf5) = *(undefined4 *)(puVar66 + 0x3a);
                  *(byte *)((longlong)puVar66 + 0xfa) = bVar33;
                  *(byte *)((longlong)puVar66 + 0xfb) = bVar34;
                  *(undefined1 *)((longlong)puVar66 + 0xfc) = uVar51;
                  puVar66[-1] = 0x1402f607c;
                  cVar31 = FUN_1406b6550(puVar66 + 0x1e,puVar66[0xd]);
                  if (cVar31 != '\0') {
                    puVar66[-1] = 0x1402f6092;
                    cVar31 = FUN_1406b6550((longlong)puVar66 + 0xf5,puVar66[0xd]);
                    if (cVar31 == '\0') {
                      *(undefined4 *)(puVar66 + 0x35) =
                           *(undefined4 *)((undefined8 *)puVar66[0x53] + 1);
                      puVar66[0x34] = *(undefined8 *)puVar66[0x53];
                      *(undefined1 *)((longlong)puVar66 + 0x44) =
                           *(undefined1 *)((longlong)puVar66 + 0xf4);
                      *(undefined4 *)(puVar66 + 8) = *(undefined4 *)(puVar66 + 0x1e);
                      *(undefined1 *)((longlong)puVar66 + 0x74) =
                           *(undefined1 *)((longlong)puVar66 + 0xf9);
                      *(undefined4 *)(puVar66 + 0xe) = *(undefined4 *)((longlong)puVar66 + 0xf5);
                      uVar74 = puVar66[0x1a];
                      uVar51 = *(undefined1 *)((longlong)puVar66 + 0xfa);
                      uVar3 = *(undefined1 *)((longlong)puVar66 + 0xfb);
                      puVar66[-1] = 0x1402f6634;
                      FUN_1423a1b30(puVar66 + 0x40,puVar66 + 0x1b);
                      *(undefined4 *)(puVar66 + 0x26) = *(undefined4 *)(puVar66 + 8);
                      *(undefined1 *)((longlong)puVar66 + 0x134) =
                           *(undefined1 *)((longlong)puVar66 + 0x44);
                      *(undefined4 *)(puVar66 + 7) = *(undefined4 *)(puVar66 + 0xe);
                      *(undefined1 *)((longlong)puVar66 + 0x3c) =
                           *(undefined1 *)((longlong)puVar66 + 0x74);
                      puVar66[0x25] = puVar66[0x42];
                      puVar66[0x23] = puVar66[0x40];
                      puVar66[0x24] = puVar66[0x41];
                      *(undefined4 *)(puVar66 + 0x29) = *(undefined4 *)(puVar66 + 0x35);
                      puVar66[0x28] = puVar66[0x34];
                      *(undefined1 *)((longlong)puVar66 + 0x14c) = 1;
                      puVar66[0x20] = puVar66[0x18];
                      puVar66[0x21] = puVar66[0x19];
                      puVar66[0x22] = uVar74;
                      *(undefined1 *)((longlong)puVar66 + 0x139) =
                           *(undefined1 *)((longlong)puVar66 + 0x3c);
                      *(undefined4 *)((longlong)puVar66 + 0x135) = *(undefined4 *)(puVar66 + 7);
                      *(undefined1 *)((longlong)puVar66 + 0x13a) = uVar51;
                      *(undefined1 *)((longlong)puVar66 + 0x13b) = uVar3;
                      *(undefined1 *)((longlong)puVar66 + 0x13c) =
                           *(undefined1 *)((longlong)puVar66 + 0xfc);
                      puVar66[-1] = 0x1402f66ef;
                      FUN_140516d40(puVar66[0x8c],puVar66 + 0x20);
                      goto LAB_1402f83b0;
                    }
                  }
                  puVar66[-1] = 0x1402f60ac;
                  cVar31 = FUN_1406b6550((longlong)puVar66 + 0xf5,puVar66[0xd]);
                  if (cVar31 == '\0') {
                    bVar33 = *(byte *)((longlong)puVar66 + 0xfa);
                    lVar72 = puVar66[0x1a];
                    cVar31 = *(char *)((longlong)puVar66 + 0xfb);
                    if ((lVar72 == 1 && bVar33 != 0) || (cVar31 != '\0')) {
                      *(undefined4 *)(puVar66 + 0x35) =
                           *(undefined4 *)((undefined8 *)puVar66[0x53] + 1);
                      puVar66[0x34] = *(undefined8 *)puVar66[0x53];
                      *(undefined1 *)((longlong)puVar66 + 0x44) =
                           *(undefined1 *)((longlong)puVar66 + 0xf4);
                      *(undefined4 *)(puVar66 + 8) = *(undefined4 *)(puVar66 + 0x1e);
                      *(undefined1 *)((longlong)puVar66 + 0x74) =
                           *(undefined1 *)((longlong)puVar66 + 0xf9);
                      *(undefined4 *)(puVar66 + 0xe) = *(undefined4 *)((longlong)puVar66 + 0xf5);
                      puVar66[-1] = 0x1402f6752;
                      FUN_1423a1b30(puVar66 + 0x40,puVar66 + 0x1b);
                      *(undefined4 *)(puVar66 + 0x26) = *(undefined4 *)(puVar66 + 8);
                      *(undefined1 *)((longlong)puVar66 + 0x134) =
                           *(undefined1 *)((longlong)puVar66 + 0x44);
                      *(undefined4 *)(puVar66 + 7) = *(undefined4 *)(puVar66 + 0xe);
                      *(undefined1 *)((longlong)puVar66 + 0x3c) =
                           *(undefined1 *)((longlong)puVar66 + 0x74);
                      puVar66[0x25] = puVar66[0x42];
                      puVar66[0x23] = puVar66[0x40];
                      puVar66[0x24] = puVar66[0x41];
                      *(undefined4 *)(puVar66 + 0x29) = *(undefined4 *)(puVar66 + 0x35);
                      puVar66[0x28] = puVar66[0x34];
                      *(undefined1 *)((longlong)puVar66 + 0x14c) = 1;
                      puVar66[0x20] = puVar66[0x18];
                      puVar66[0x21] = puVar66[0x19];
                      puVar66[0x22] = lVar72;
                      *(undefined1 *)((longlong)puVar66 + 0x139) =
                           *(undefined1 *)((longlong)puVar66 + 0x3c);
                      *(undefined4 *)((longlong)puVar66 + 0x135) = *(undefined4 *)(puVar66 + 7);
                      *(byte *)((longlong)puVar66 + 0x13a) = bVar33;
                      *(char *)((longlong)puVar66 + 0x13b) = cVar31;
                      *(undefined1 *)((longlong)puVar66 + 0x13c) =
                           *(undefined1 *)((longlong)puVar66 + 0xfc);
                      puVar66[-1] = 0x1402f680d;
                      FUN_140516d40(puVar66[0x8c],puVar66 + 0x20);
                    }
                    else {
                      *(undefined1 *)((longlong)puVar66 + 0x74) =
                           *(undefined1 *)((longlong)puVar66 + 0xf4);
                      *(undefined4 *)(puVar66 + 0xe) = *(undefined4 *)(puVar66 + 0x1e);
                      *(undefined1 *)((longlong)puVar66 + 0x1a4) =
                           *(undefined1 *)((longlong)puVar66 + 0xf9);
                      *(undefined4 *)(puVar66 + 0x34) = *(undefined4 *)((longlong)puVar66 + 0xf5);
                      puVar66[-1] = 0x1402f64cb;
                      FUN_1423a1b30(puVar66 + 0x20,puVar66 + 0x1b);
                      uVar51 = *(undefined1 *)((longlong)puVar66 + 0xfc);
                      uVar74 = puVar66[0x18];
                      uVar54 = puVar66[0x19];
                      *(undefined4 *)(puVar66 + 8) = *(undefined4 *)(puVar66 + 0xe);
                      *(undefined1 *)((longlong)puVar66 + 0x44) =
                           *(undefined1 *)((longlong)puVar66 + 0x74);
                      *(undefined4 *)(puVar66 + 7) = *(undefined4 *)(puVar66 + 0x34);
                      *(undefined1 *)((longlong)puVar66 + 0x3c) =
                           *(undefined1 *)((longlong)puVar66 + 0x1a4);
                      puVar66[0x40] = puVar66[0x20];
                      puVar66[0x41] = puVar66[0x21];
                      puVar66[0x42] = puVar66[0x22];
                      lVar62 = puVar66[0xc];
                      if ((*(char *)(lVar62 + 0x7a) != '\x02') &&
                         (uVar37 = *(ulonglong *)(lVar62 + 0x58), uVar37 != 0)) {
                        *(undefined1 *)(puVar66 + 9) = uVar51;
                        uVar9 = *(undefined8 *)(lVar62 + 0x60);
                        puVar66[-1] = 0x1402f655e;
                        FUN_1408192a0(uVar9,uVar37,~uVar37 >> 0x3f);
                        uVar51 = *(undefined1 *)(puVar66 + 9);
                      }
                      *(undefined8 *)(lVar62 + 0x40) = uVar74;
                      *(undefined8 *)(lVar62 + 0x48) = uVar54;
                      *(ulonglong *)(lVar62 + 0x50) = lVar72 - (ulonglong)bVar33;
                      *(undefined8 *)(lVar62 + 0x68) = puVar66[0x42];
                      uVar74 = puVar66[0x41];
                      *(undefined8 *)(lVar62 + 0x58) = puVar66[0x40];
                      *(undefined8 *)(lVar62 + 0x60) = uVar74;
                      *(undefined4 *)(lVar62 + 0x70) = *(undefined4 *)(puVar66 + 8);
                      *(undefined1 *)(lVar62 + 0x74) = *(undefined1 *)((longlong)puVar66 + 0x44);
                      *(undefined1 *)(lVar62 + 0x79) = *(undefined1 *)((longlong)puVar66 + 0x3c);
                      *(undefined4 *)(lVar62 + 0x75) = *(undefined4 *)(puVar66 + 7);
                      *(byte *)(lVar62 + 0x7a) = bVar33;
                      *(undefined1 *)(lVar62 + 0x7b) = 0;
                      *(undefined1 *)(lVar62 + 0x7c) = uVar51;
                    }
                    goto LAB_1402f83b0;
                  }
                  lVar72 = *(longlong *)puVar66[0x88];
                  uVar4 = *(undefined4 *)((longlong)puVar66[0x88] + 0xc);
                  puVar66[0x52] = lVar72;
                  *(undefined4 *)((longlong)puVar66 + 0x19c) = uVar4;
                  *(undefined4 *)(lVar72 + 4) = uVar4;
                  bVar33 = *(byte *)(puVar66 + 0x1e);
                  if ((bVar33 & 0xfd) == 0) {
                    bVar33 = 1;
                  }
                  lVar72 = *(longlong *)(puVar66[0x88] + 0x10);
                  *(char *)((longlong)puVar66 + 0x74) =
                       (char)((uint)*(int *)((longlong)puVar66 + 0xf1) >> 0x18);
                  *(uint *)(puVar66 + 0xe) = (uint)bVar33 | *(int *)((longlong)puVar66 + 0xf1) << 8;
                  puVar66[0x12] = lVar72;
                  if (*(longlong *)(lVar72 + 0x50) != 0) {
                    puVar66[-1] = 0x1402f6135;
                    puVar38 = (uint *)FUN_140765640(puVar66[0x12] + 0x60,puVar66 + 0xe);
                    uVar37 = *(ulonglong *)(puVar66[0x12] + 0x40);
                    lVar72 = *(longlong *)(puVar66[0x12] + 0x58);
                    bVar33 = (byte)((ulonglong)puVar38 >> 0x39);
                    auVar90 = ZEXT216(CONCAT11(bVar33,bVar33));
                    auVar90 = pshuflw(auVar90,auVar90,0);
                    puVar66[0x10] = lVar72;
                    _Src = (uint *)(lVar72 + -0x38);
                    bVar33 = *(byte *)(puVar66 + 0xe);
                    uVar52 = (ulonglong)bVar33;
                    puVar39 = (uint *)(ulonglong)*(byte *)((longlong)puVar66 + 0x71);
                    *(uint *)(puVar66 + 9) = (uint)*(byte *)((longlong)puVar66 + 0x72);
                    bVar34 = *(byte *)((longlong)puVar66 + 0x73);
                    puVar53 = (uint *)0x0;
LAB_1402f6187:
                    do {
                      puVar66[0xb] = puVar53;
                      puVar38 = (uint *)((ulonglong)puVar38 & uVar37);
                      auVar91 = *(undefined1 (*) [16])(puVar66[0x10] + (longlong)puVar38);
                      cVar31 = auVar90[0];
                      auVar98[0] = -(cVar31 == auVar91[0]);
                      cVar99 = auVar90[1];
                      auVar98[1] = -(cVar99 == auVar91[1]);
                      cVar100 = auVar90[2];
                      auVar98[2] = -(cVar100 == auVar91[2]);
                      cVar101 = auVar90[3];
                      auVar98[3] = -(cVar101 == auVar91[3]);
                      auVar98[4] = -(cVar31 == auVar91[4]);
                      auVar98[5] = -(cVar99 == auVar91[5]);
                      auVar98[6] = -(cVar100 == auVar91[6]);
                      auVar98[7] = -(cVar101 == auVar91[7]);
                      auVar98[8] = -(cVar31 == auVar91[8]);
                      auVar98[9] = -(cVar99 == auVar91[9]);
                      auVar98[10] = -(cVar100 == auVar91[10]);
                      auVar98[0xb] = -(cVar101 == auVar91[0xb]);
                      auVar98[0xc] = -(cVar31 == auVar91[0xc]);
                      auVar98[0xd] = -(cVar99 == auVar91[0xd]);
                      auVar98[0xe] = -(cVar100 == auVar91[0xe]);
                      auVar98[0xf] = -(cVar101 == auVar91[0xf]);
                      uVar59 = (ushort)(SUB161(auVar98 >> 7,0) & 1) |
                               (ushort)(SUB161(auVar98 >> 0xf,0) & 1) << 1 |
                               (ushort)(SUB161(auVar98 >> 0x17,0) & 1) << 2 |
                               (ushort)(SUB161(auVar98 >> 0x1f,0) & 1) << 3 |
                               (ushort)(SUB161(auVar98 >> 0x27,0) & 1) << 4 |
                               (ushort)(SUB161(auVar98 >> 0x2f,0) & 1) << 5 |
                               (ushort)(SUB161(auVar98 >> 0x37,0) & 1) << 6 |
                               (ushort)(SUB161(auVar98 >> 0x3f,0) & 1) << 7 |
                               (ushort)(SUB161(auVar98 >> 0x47,0) & 1) << 8 |
                               (ushort)(SUB161(auVar98 >> 0x4f,0) & 1) << 9 |
                               (ushort)(SUB161(auVar98 >> 0x57,0) & 1) << 10 |
                               (ushort)(SUB161(auVar98 >> 0x5f,0) & 1) << 0xb |
                               (ushort)(SUB161(auVar98 >> 0x67,0) & 1) << 0xc |
                               (ushort)(SUB161(auVar98 >> 0x6f,0) & 1) << 0xd |
                               (ushort)(SUB161(auVar98 >> 0x77,0) & 1) << 0xe |
                               (ushort)(auVar98[0xf] >> 7) << 0xf;
                      puVar61 = (uint *)(ulonglong)uVar59;
                      if (uVar59 != 0) {
LAB_1402f61ec:
                        uVar59 = 0;
                        if ((ushort)puVar61 != 0) {
                          for (; ((ushort)puVar61 >> uVar59 & 1) == 0; uVar59 = uVar59 + 1) {
                          }
                        }
                        uVar56 = (ulonglong)((ulonglong)uVar59 + (longlong)puVar38) & uVar37;
                        puVar73 = (uint *)(uVar56 * -0x38);
                        bVar49 = (byte)_Src[uVar56 * -0xe];
                        puVar57 = (uint *)(ulonglong)bVar49;
                        cVar99 = (char)((ulonglong)puVar61 >> 8);
                        cVar31 = (char)puVar38;
                        uVar47 = (uint7)((ulonglong)puVar38 >> 8);
                        iVar82 = (int)puVar38;
                        if (bVar49 == 0) goto switchD_1402f6219_caseD_0;
                        puVar53 = &switchD_1402f6219::switchdataD_1402f9974;
                        uVar56 = (ulonglong)(int)(&switchD_1402f6219::switchdataD_1402f9974)[uVar52]
                        ;
                        puVar80 = (uint *)((longlong)&switchD_1402f6219::switchdataD_1402f9974 +
                                          uVar56);
                        puVar79 = puVar80;
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
                        switch(bVar33) {
                        case 0:
                          break;
                        case 1:
                          if (bVar49 == 1) break;
                          goto LAB_1402f61e0;
                        case 2:
                          if (bVar49 != 2) goto LAB_1402f61e0;
                          break;
                        case 3:
                          if (bVar49 != 3) goto LAB_1402f61e0;
                          break;
                        case 4:
                          if (bVar49 != 4) goto LAB_1402f61e0;
                          break;
                        case 5:
                    /* WARNING: Bad instruction - Truncating control flow here */
                          halt_baddata();
                        case 6:
                    /* WARNING: Bad instruction - Truncating control flow here */
                          halt_baddata();
                        case 7:
                          *_Src = *_Src + 0x402f9974;
                    /* WARNING: Bad instruction - Truncating control flow here */
                          halt_baddata();
                        case 8:
                    /* WARNING: Bad instruction - Truncating control flow here */
                          halt_baddata();
                        case 9:
                          goto switchD_1402f6219_caseD_9;
                        case 10:
                          halt_baddata();
                        case 0xb:
                    /* WARNING: Bad instruction - Truncating control flow here */
                          halt_baddata();
                        case 0xc:
                          goto switchD_1402f6219_caseD_c;
                        case 0xd:
                          puVar38 = (uint *)((ulonglong)puVar38 ^ 0xb1);
                          goto switchD_1402f625c_caseD_402f62a3;
                        case 0xe:
                          *(byte *)_Src = *(byte *)_Src + 0x74;
                          puVar57 = (uint *)(ulonglong)CONCAT11(0x55,bVar49);
                          puVar38 = (uint *)CONCAT71(uVar47,cVar31 + *(char *)((longlong)puVar57 * 9
                                                                              + 0x748b4874));
switchD_1402f6219_caseD_c:
                          puVar38 = (uint *)((ulonglong)puVar38 & 0xffffffffffffff48);
                          goto switchD_1402f625c_caseD_402f6298;
                        case 0xf:
                          goto switchD_1402f6219_caseD_f;
                        case 0x10:
                    /* WARNING: Bad instruction - Truncating control flow here */
                          halt_baddata();
                        case 0x11:
                    /* WARNING: Could not emulate address calculation at 0x0001402f62d5 */
                    /* WARNING: Treating indirect jump as call */
                          (**(code **)((longlong)&UINT_1402f99a0 + uVar56 + 2))();
                          return;
                        case 0x12:
                          *(byte *)puVar38 = (byte)*puVar38;
                          goto LAB_1402f6187;
                        case 0x13:
                    /* WARNING: Bad instruction - Truncating control flow here */
                          halt_baddata();
                        case 0x14:
                          pacVar40 = (char (*) [8])((ulonglong)puVar38 & 0xffffffffffffff48);
                          goto code_r0x0001402f6972;
                        case 0x15:
                          goto switchD_1402f6219_caseD_15;
                        case 0x16:
                          goto switchD_1402f6219_caseD_16;
                        case 0x17:
                          bVar88 = iVar82 == 0;
                          goto code_r0x0001402f6b9f;
                        case 0x18:
                          goto switchD_1402f6219_caseD_18;
                        case 0x19:
                          *puVar38 = *puVar38 + iVar82;
                          *(byte *)((longlong)puVar38 + -0x39) =
                               *(byte *)((longlong)puVar38 + -0x39) + 0x74;
                          *puVar38 = *puVar38 + iVar82;
                          *(byte *)puVar38 = (byte)*puVar38 + cVar31;
                          *(byte *)puVar38 = (byte)*puVar38 + cVar31;
                          *(byte *)((longlong)puVar38 + -0x73) =
                               *(byte *)((longlong)puVar38 + -0x73) + 0x74;
                          puVar38 = (uint *)(ulonglong)(iVar82 + 0x212daa7);
                          goto code_r0x0001402f7339;
                        case 0x1a:
                          goto switchD_1402f6219_caseD_1a;
                        case 0x1b:
                          *(byte *)puVar38 = (byte)*puVar38 + cVar31;
                          goto code_r0x0001402f7279;
                        case 0x1c:
                          *(byte *)puVar38 = (byte)*puVar38 + cVar31;
                          goto switchD_1402f6219_caseD_16;
                        case 0x1d:
                          uVar37 = CONCAT71(uVar47,*(undefined1 *)((ulonglong)uVar47 << 8));
                          pcVar78 = (char *)(uVar37 - 0x73);
                          *pcVar78 = *pcVar78 + 't';
                          puVar64 = (undefined1 *)(uVar37 & 0xffffffff);
                          piVar41 = (int *)((ulonglong)puVar66 & 0xffffff00);
                          *piVar41 = *piVar41 + (int)piVar41;
                          *(undefined8 *)(puVar64 + 0xb8) = *(undefined8 *)(puVar64 + 0x200);
                          puVar73 = *(uint **)(puVar64 + 0x208);
                          puVar66 = (undefined8 *)puVar64;
                          goto code_r0x0001402f71c2;
                        case 0x1e:
                          goto switchD_1402f6219_caseD_1e;
                        case 0x1f:
                          puVar73 = (uint *)((ulonglong)puVar38 & 0xffffffff);
                          goto code_r0x0001402f700d;
                        case 0x20:
                        case 0x24:
                          cRam0000000640edffbb = cRam0000000640edffbb + 't';
                    /* WARNING: Bad instruction - Truncating control flow here */
                          halt_baddata();
                        case 0x21:
                          goto switchD_1402f6219_caseD_21;
                        case 0x22:
                          goto switchD_1402f6219_caseD_22;
                        case 0x23:
                          goto switchD_1402f6219_caseD_23;
                        case 0x25:
                          *(char *)(((ulonglong)puVar66 & 0xffffff58) - 0x75) =
                               *(char *)(((ulonglong)puVar66 & 0xffffff58) - 0x75) + 't';
                          puVar66 = (undefined8 *)((ulonglong)puVar38 & 0xffffffff);
                          goto code_r0x0001402f86b3;
                        case 0x26:
                          puVar38 = (uint *)((ulonglong)puVar38 & 0xfffffffffffffff0);
                          goto switchD_1402f625c_caseD_3bdb3fe8;
                        case 0x27:
                          *(byte *)puVar38 = (byte)*puVar38 + cVar31;
                          goto code_r0x0001402f89c8;
                        case 0x28:
                          goto switchD_1402f6219_caseD_28;
                        case 0x29:
                          goto switchD_1402f6219_caseD_29;
                        case 0x2a:
                          bVar33 = in((ushort)bVar49);
                          *(byte *)_Src = bVar33;
                    /* WARNING: Bad instruction - Truncating control flow here */
                          halt_baddata();
                        case 0x2b:
                          goto switchD_1402f6219_caseD_2b;
                        default:
                          *(uint *)((longlong)puVar38 + -0x7d) =
                               (*(int *)((longlong)puVar38 + -0x7d) + -0x402f9974) -
                               (uint)(0xfffffffebfd0668b < uVar56);
                          return;
                        case 0x2f:
                          goto switchD_1402f6219_caseD_2f;
                        }
switchD_1402f6219_caseD_0:
                        puVar73 = (uint *)((longlong)puVar73 + (longlong)_Src);
                        puVar57 = (uint *)(ulonglong)*(byte *)((longlong)puVar73 + 1);
                        if (*(byte *)((longlong)puVar73 + 1) == 0)
                        goto switchD_1402f625c_caseD_402f6290;
                        puVar53 = &switchD_1402f625c::switchdataD_1402f9988;
                        puVar80 = puVar39;
switchD_1402f6219_caseD_9:
                        uVar56 = (ulonglong)(int)puVar53[(longlong)puVar80];
                        puVar80 = (uint *)(uVar56 + (longlong)puVar53);
                        bVar49 = (byte)puVar53;
                        cVar100 = (char)puVar57;
                        puVar79 = puVar80;
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                        switch(puVar80) {
                        case (uint *)0x3bdb3fe8:
                          goto switchD_1402f625c_caseD_3bdb3fe8;
                        case (uint *)0x1402f5b50:
                          *(byte *)(puVar53 + 0x12013ed3) = (byte)puVar53[0x12013ed3] + bVar49;
                          goto LAB_1402f5b20;
                        case (uint *)0x1402f61a7:
                          goto LAB_1402f61ac;
                        case (uint *)0x1402f625e:
                          if (cVar100 == '\x01') break;
                          goto LAB_1402f61e0;
                        case (uint *)0x1402f6269:
                          if (cVar100 != '\x04') goto LAB_1402f61e0;
                          break;
                        case (uint *)0x1402f6274:
                          if (cVar100 != '\x02') goto LAB_1402f61e0;
                          break;
                        case (uint *)0x1402f627f:
                          if (cVar100 != '\x03') goto LAB_1402f61e0;
                          break;
                        case (uint *)0x1402f6298:
                          goto switchD_1402f625c_caseD_402f6298;
                        case (uint *)0x1402f62a3:
                          goto switchD_1402f625c_caseD_402f62a3;
                        case (uint *)0x1402f62ae:
                          *_Src = *_Src + (int)puVar53;
                    /* WARNING: Bad instruction - Truncating control flow here */
                          halt_baddata();
                        case (uint *)0x1402f62b9:
                    /* WARNING: Bad instruction - Truncating control flow here */
                          halt_baddata();
                        case (uint *)0x1402f62cc:
                    /* WARNING: Bad instruction - Truncating control flow here */
                          halt_baddata();
                        case (uint *)0x1402f62d3:
                    /* WARNING: Bad instruction - Truncating control flow here */
                          halt_baddata();
                        case (uint *)0x1402f62de:
switchD_1402f6219_caseD_f:
                          *(byte *)puVar38 = (byte)*puVar38 + cVar31;
                          goto switchD_1402f62aa_caseD_402f62e0;
                        case (uint *)0x1402f62e9:
                          puVar79 = puVar61;
                          goto code_r0x0001402f62eb;
                        case (uint *)0x1402f62f2:
                          goto switchD_1402f625c_caseD_402f62f2;
                        case (uint *)0x1402f6999:
                          goto switchD_1402f625c_caseD_402f6999;
                        case (uint *)0x1402f6b07:
                          *puVar38 = *puVar38 + iVar82;
                          *(byte *)puVar53 = (byte)*puVar53;
                          pbVar1 = (byte *)((longlong)puVar38 + -0x77);
                          *pbVar1 = *pbVar1 >> 4 | *pbVar1 << 4;
                          puVar38 = (uint *)((ulonglong)puVar38 & 0xffffffffffffff88);
                          *(byte *)puVar38 = (byte)*puVar38 + (char)puVar38;
                          *(byte *)((longlong)puVar38 + -0x75) =
                               *(byte *)((longlong)puVar38 + -0x75) + bVar49;
                        case (uint *)0x1402f6b16:
                          *(byte *)puVar38 = (byte)*puVar38 + (char)puVar38;
                          goto switchD_1402f62aa_caseD_402f6b1b;
                        case (uint *)0x1402f6bb1:
                          out(*puVar80,(short)puVar57);
                          *(byte *)puVar38 = (byte)*puVar38 + cVar31;
                          *(byte *)((longlong)puVar38 + -0x77) =
                               *(byte *)((longlong)puVar38 + -0x77) + bVar49;
                    /* WARNING: Bad instruction - Truncating control flow here */
                          halt_baddata();
                        case (uint *)0x1402f6bd0:
                          *puVar38 = *puVar38 + iVar82;
                          *(byte *)(puVar61 + -0x1db1f6ef) = (byte)puVar61[-0x1db1f6ef] + bVar49;
                          *puVar38 = *puVar38 + iVar82;
                          *(byte *)((longlong)puVar38 + 0x4030203) =
                               *(byte *)((longlong)puVar38 + 0x4030203) + cVar99;
                          goto LAB_1402f727e;
                        case (uint *)0x1402f6c99:
                          *(byte *)puVar38 = (byte)*puVar38 + cVar31;
                          *puVar38 = *puVar38 + iVar82;
                          *(byte *)puVar38 = (byte)*puVar38 + cVar31;
                          goto switchD_1402f6219_caseD_15;
                        case (uint *)0x1402f6f67:
                          *puVar38 = *puVar38 + 0x48 + (uint)CARRY8(uVar56,(ulonglong)puVar53);
                          puVar38 = (uint *)(ulonglong)(iVar82 + 1);
                          goto LAB_1402f6f65;
                        case (uint *)0x1402f701f:
                          goto code_r0x0001402f700d;
                        case (uint *)0x1402f70aa:
                          if (SCARRY8(uVar56,(longlong)puVar53) == (longlong)puVar80 < 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
                            halt_baddata();
                          }
                          goto code_r0x0001402f70d0;
                        case (uint *)0x1402f71ac:
                          cVar31 = cVar31 + (byte)*puVar38;
                          pcVar78 = (char *)CONCAT71(uVar47,cVar31);
                          pcVar78[-0x77] = pcVar78[-0x77] + bVar49;
                          *pcVar78 = *pcVar78 + cVar31;
                          pcVar78[-0x75] = pcVar78[-0x75] + bVar49;
                          pcVar78 = (char *)(CONCAT71(uVar47,(byte)*puVar80) & 0xffffffffffffff08);
                          uVar48 = (undefined7)((ulonglong)pcVar78 >> 8);
                          cVar31 = (char)pcVar78 + *pcVar78;
                          pcVar42 = (char *)CONCAT71(uVar48,cVar31);
                          pcVar78 = pcVar42 + -0x75;
                          *pcVar78 = *pcVar78 + bVar49;
                          cVar31 = cVar31 + *pcVar42;
                          pcVar78 = (char *)CONCAT71(uVar48,cVar31);
                          pcVar78[-0x77] = pcVar78[-0x77] + bVar49;
                          *pcVar78 = *pcVar78 + cVar31;
                          *(byte *)(puVar57 + 3) = (byte)puVar57[3] + cVar99;
                          goto code_r0x0001402f71d7;
                        case (uint *)0x1402f7285:
                          *(byte *)((longlong)puVar38 + 5) =
                               *(byte *)((longlong)puVar38 + 5) + cVar99;
                          goto code_r0x0001402f728b;
                        case (uint *)0x1402f7337:
                          puVar38 = (uint *)CONCAT71(uVar47,cVar31 + (byte)*puVar57 +
                                                            CARRY8(uVar56,(ulonglong)puVar53));
                          goto code_r0x0001402f7339;
                        case (uint *)0x1402f85c9:
                          puVar67 = puVar66 + -1;
                          puVar66 = puVar66 + -1;
                          *puVar67 = 0x19;
                          puVar57 = _Src;
                          goto LAB_1402f85b6;
                        case (uint *)0x1402f86c9:
                          goto code_r0x0001402f86b3;
                        case (uint *)0x1402f86f1:
                          goto switchD_1402f625c_caseD_402f86f1;
                        case (uint *)0x1402f8873:
                          if (puVar80 != (uint *)0x0 &&
                              SCARRY8(uVar56,(longlong)puVar53) == (longlong)puVar80 < 0)
                          goto switchD_1402f8633_caseD_2;
                          puVar66 = puVar66 + 1;
                          goto code_r0x0001402f8886;
                        case (uint *)0x1402f89ef:
switchD_1402f6219_caseD_28:
                          *puVar38 = *puVar38 + iVar82;
                          *(byte *)puVar38 = (byte)*puVar38 + cVar31;
                          goto LAB_1402f89ee;
                        case (uint *)0x1402f8a18:
                          *(byte *)((longlong)puVar38 + -0x73) =
                               *(byte *)((longlong)puVar38 + -0x73) + bVar49;
                          *(undefined2 *)((longlong)puVar80 * 8 + 0x48000000) = in_FS;
                          goto code_r0x0001402f8a21;
                        case (uint *)0x1402f8b04:
                          piVar41 = (int *)((ulonglong)uVar47 << 8);
                          *piVar41 = *piVar41 + (int)piVar41;
                          puVar45 = puVar66;
                          goto LAB_1402f8b13;
                        case (uint *)0x1402f8b7f:
                          *(undefined2 *)puVar38 = in_FS;
                          *(byte *)puVar38 = (byte)*puVar38 + cVar31;
                          *(byte *)((longlong)puVar53 + -0x77) =
                               *(byte *)((longlong)puVar53 + -0x77) + bVar49;
                          pbVar1 = (byte *)((longlong)puVar53 + -9);
                          *pbVar1 = *pbVar1 >> 1 | *pbVar1 << 7;
                          pbVar1 = (byte *)((longlong)puVar53 + -0x3f);
                          *pbVar1 = *pbVar1 >> 1 | *pbVar1 << 7;
                          puVar66[-1] = 0x1402f8b92;
                          puVar38 = (uint *)func_0x0001473c73d1();
switchD_1402f6219_caseD_2b:
                          puVar69 = puVar66 + -1;
                          puVar66 = puVar66 + -1;
                          *puVar69 = puVar57;
                          goto switchD_1402f62aa_caseD_402f8b93;
                        case (uint *)0x1402f8ba6:
                          *(int *)((longlong)puVar38 + -0x75) =
                               *(int *)((longlong)puVar38 + -0x75) + (int)puVar53;
                          puVar70 = puVar66 + -1;
                          puVar66 = puVar66 + -1;
                          *puVar70 = puVar53;
                          *(byte *)((longlong)puVar61 + 0x498b1041) =
                               *(byte *)((longlong)puVar61 + 0x498b1041) | bVar49;
                          uVar36 = (uint)CONCAT71(uVar47,cVar31 + -0x77) & 0xffffff30;
                          goto code_r0x0001402f8bb5;
                        case (uint *)0x1402f8bb4:
                          *(byte *)(puVar53 + -0x1d35f6ef) = (byte)puVar53[-0x1d35f6ef] ^ bVar49;
                          goto switchD_1402f62aa_caseD_402f8bba;
                        case (uint *)0x1402f8be3:
                          return;
                        }
switchD_1402f625c_caseD_402f6290:
                        puVar57 = (uint *)(ulonglong)*(byte *)((longlong)puVar73 + 2);
                        if (*(byte *)((longlong)puVar73 + 2) == 0)
                        goto switchD_1402f62aa_caseD_402f62e0;
switchD_1402f625c_caseD_402f6298:
                        puVar80 = (uint *)(ulonglong)*(uint *)(puVar66 + 9);
                        puVar53 = &switchD_1402f62aa::switchdataD_1402f999c;
switchD_1402f625c_caseD_402f62a3:
                        puVar79 = (uint *)((longlong)(int)puVar53[(longlong)puVar80] +
                                          (longlong)puVar53);
                        bVar88 = puVar79 == (uint *)0x0;
                        bVar49 = (byte)puVar38;
                        cVar31 = (char)puVar57;
                        puVar80 = puVar79;
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                        switch(puVar79) {
                        case (uint *)0x1402f5b64:
                          goto switchD_1402f62aa_caseD_402f5b64;
                        case (uint *)0x1402f61bb:
                          *(byte *)puVar38 = (byte)*puVar38 + bVar49;
                          goto code_r0x0001402f61bd;
                        case (uint *)0x1402f62ac:
                          if (cVar31 == '\x01') break;
                          goto LAB_1402f61e0;
                        case (uint *)0x1402f62b7:
                          if (cVar31 != '\x04') goto LAB_1402f61e0;
                          break;
                        case (uint *)0x1402f62c2:
                          if (cVar31 != '\x02') goto LAB_1402f61e0;
                          break;
                        case (uint *)0x1402f62cd:
                          if (cVar31 != '\x03') goto LAB_1402f61e0;
                          break;
                        case (uint *)0x1402f62e7:
                          puVar38 = (uint *)CONCAT71((int7)((ulonglong)puVar38 >> 8),
                                                     bVar49 ^ *(byte *)((longlong)puVar53 * 5 +
                                                                       -0x22));
                          goto code_r0x0001402f62eb;
                        case (uint *)0x1402f62f2:
                          goto switchD_1402f625c_caseD_402f62f2;
                        case (uint *)0x1402f62fd:
                          *_Src = *_Src + (int)puVar53;
                    /* WARNING: Bad instruction - Truncating control flow here */
                          halt_baddata();
                        case (uint *)0x1402f6306:
                          goto switchD_1402f62aa_caseD_402f6306;
                        case (uint *)0x1402f69ad:
                          goto switchD_1402f62aa_caseD_402f69ad;
                        case (uint *)0x1402f6b1b:
switchD_1402f62aa_caseD_402f6b1b:
                          *(byte *)((longlong)puVar38 + -0x77) =
                               *(byte *)((longlong)puVar38 + -0x77) + (char)puVar53;
                          *(byte *)puVar38 = (byte)*puVar38 + (char)puVar38;
                          *(byte *)((longlong)puVar38 + -0x75) =
                               *(byte *)((longlong)puVar38 + -0x75) + (char)puVar53;
                          goto switchD_1402f6219_caseD_16;
                        case (uint *)0x1402f6b2a:
                          *(int *)(puVar66 + 0x13) = (int)puVar38;
                          goto switchD_1402f6219_caseD_16;
                        case (uint *)0x1402f6bc5:
                          goto switchD_1402f6219_caseD_18;
                        case (uint *)0x1402f6be4:
                    /* WARNING: Bad instruction - Truncating control flow here */
                          halt_baddata();
                        case (uint *)0x1402f6cad:
                          *(byte *)puVar38 = (byte)*puVar38 + bVar49;
                          goto switchD_1402f6219_caseD_15;
                        case (uint *)0x1402f6f7b:
                          puVar63 = puVar66 + -1;
                          puVar66 = puVar66 + -1;
                          *puVar63 = *(undefined8 *)((longlong)puVar61 + 0x21a2860f);
                          *(byte *)puVar38 = (byte)*puVar38 + bVar49;
                          goto LAB_1402f6f83;
                        case (uint *)0x1402f7033:
                          *(byte *)((longlong)puVar38 + 0x1010401) =
                               *(byte *)((longlong)puVar38 + 0x1010401) + cVar99;
                          goto code_r0x0001402f7039;
                        case (uint *)0x1402f70be:
                          *(byte *)puVar38 = (byte)*puVar38 + bVar49;
                          goto code_r0x0001402f70b3;
                        case (uint *)0x1402f71c0:
                          *(byte *)puVar38 = (byte)*puVar38 + bVar49;
code_r0x0001402f71c2:
                          *(undefined8 *)((longlong)puVar66 + 0xb0) =
                               *(undefined8 *)((longlong)puVar66 + 0x210);
                          puVar57 = (uint *)&DAT_0000000c;
                          goto code_r0x0001402f71d7;
                        case (uint *)0x1402f7299:
                          *(byte *)puVar38 = bVar49;
                          *(byte *)puVar38 = (byte)*puVar38 + bVar49;
                          goto code_r0x0001402f728b;
                        case (uint *)0x1402f734b:
                          *(byte *)puVar38 = (byte)*puVar38 + bVar49;
                          goto code_r0x0001402f7339;
                        case (uint *)0x1402f85dd:
                          puVar57 = (uint *)(lVar72 + -0x37);
                          puVar80 = (uint *)((longlong)puVar79 + 1);
                          *(byte *)_Src = (byte)*puVar79;
                          *puVar38 = *puVar38 + (int)puVar38;
                          *(byte *)((longlong)puVar38 + 0x448b7447) =
                               *(byte *)((longlong)puVar38 + 0x448b7447) + (char)puVar53;
                          goto LAB_1402f85b6;
                        case (uint *)0x1402f86dd:
switchD_1402f6219_caseD_21:
                    /* WARNING: Bad instruction - Truncating control flow here */
                          halt_baddata();
                        case (uint *)0x1402f8705:
                          pcVar78 = (char *)((ulonglong)puVar38 & 0xfffffffffffffff2);
                          *pcVar78 = *pcVar78 + (char)pcVar78;
                          *(byte *)puVar57 = (byte)*puVar57 + (char)pcVar78;
                          goto LAB_1402f86f6;
                        case (uint *)0x1402f8887:
                          goto code_r0x0001402f8886;
                        case (uint *)0x1402f8a03:
                          *(undefined2 *)(puVar38 + (longlong)puVar79 * 2) = in_FS;
switchD_1402f625c_caseD_3bdb3fe8:
                          *(byte *)puVar38 = (byte)*puVar38 + (char)puVar38;
                          *(byte *)((longlong)puVar38 + -0x77) =
                               *(byte *)((longlong)puVar38 + -0x77) + (char)puVar53;
                    /* WARNING: Bad instruction - Truncating control flow here */
                          halt_baddata();
                        case (uint *)0x1402f8a1a:
                          puVar53 = (uint *)((longlong)puVar66 + 0xf5U & 0xffffffff);
                          goto code_r0x0001402f8a21;
                        case (uint *)0x1402f8a2c:
                          *(byte *)_Src = *(byte *)_Src >> 4 | *(byte *)_Src << 4;
                          goto code_r0x0001402f8a33;
                        case (uint *)0x1402f8b18:
                          *(byte *)puVar38 = (byte)*puVar38 + bVar49;
                          *(byte *)((longlong)puVar38 + -0x73) =
                               *(byte *)((longlong)puVar38 + -0x73) + (char)puVar53;
                          puVar45 = (undefined8 *)((ulonglong)puVar38 & 0xffffffff);
                          piVar41 = (int *)((ulonglong)puVar66 & 0xffffff00);
                          *piVar41 = *piVar41 + (int)piVar41;
                          goto LAB_1402f8b13;
                        case (uint *)0x1402f8b93:
switchD_1402f62aa_caseD_402f8b93:
                          *(byte *)(puVar73 + (longlong)((longlong)puVar53 + -0x13)) =
                               (byte)puVar73[(longlong)((longlong)puVar53 + -0x13)] + (char)puVar53;
                          puVar38 = (uint *)((ulonglong)puVar38 & 0xffffffffffffff00);
                          *puVar38 = *puVar38 + (int)puVar38;
                          *(byte *)((longlong)puVar38 + -0x75) =
                               *(byte *)((longlong)puVar38 + -0x75) + (char)puVar53;
                          *(undefined2 *)((longlong)puVar38 + (longlong)puVar79) = in_FS;
switchD_1402f6219_caseD_2f:
                          *(byte *)((longlong)puVar38 * 2) =
                               *(byte *)((longlong)puVar38 * 2) ^ (byte)puVar38;
                          pbVar1 = (byte *)((longlong)puVar61 + (longlong)puVar53 * 4 + 1);
                          *pbVar1 = *pbVar1 + (char)puVar53;
                          goto switchD_1402f62f9_caseD_402f8ba7;
                        case (uint *)0x1402f8bba:
switchD_1402f62aa_caseD_402f8bba:
                          uVar36 = (uint)puVar38 & 0xffffff78;
                          goto code_r0x0001402f8bb5;
                        case (uint *)0x1402f8bc8:
                          *(byte *)(puVar61 + (longlong)((longlong)puVar53 + 0x13)) =
                               (byte)puVar61[(longlong)((longlong)puVar53 + 0x13)] + bVar49;
                          goto switchD_1402f62f9_caseD_402f8bce;
                        case (uint *)0x1402f8bf7:
                    /* WARNING: Bad instruction - Truncating control flow here */
                          halt_baddata();
                        }
switchD_1402f62aa_caseD_402f62e0:
                        puVar57 = (uint *)(ulonglong)*(byte *)((longlong)puVar73 + 3);
                        puVar79 = (uint *)(ulonglong)bVar34;
                        if (*(byte *)((longlong)puVar73 + 3) == 0)
                        goto switchD_1402f62f9_caseD_402f631a;
code_r0x0001402f62eb:
                        puVar53 = &switchD_1402f62f9::switchdataD_1402f99b0;
switchD_1402f625c_caseD_402f62f2:
                        puVar80 = (uint *)((longlong)(int)puVar53[(longlong)puVar79] +
                                          (longlong)puVar53);
                        bVar49 = (byte)puVar38;
                        uVar36 = (uint)puVar38;
                        cVar31 = (char)puVar57;
                        bVar50 = (byte)puVar53;
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                        switch(puVar80) {
                        case (uint *)0x1402f5b78:
                          *(byte *)puVar38 = (byte)*puVar38 + bVar49;
                          goto LAB_1402f5b72;
                        case (uint *)0x1402f61cf:
                          if (cVar31 != '\x03') goto LAB_1402f61e0;
                          break;
                        case (uint *)0x1402f62fb:
                          if (cVar31 == '\x01') break;
LAB_1402f61e0:
                          uVar36 = (uint)puVar61 - 1 & (uint)puVar61;
                          puVar61 = (uint *)(ulonglong)uVar36;
                          if ((short)uVar36 == 0) goto LAB_1402f61ac;
                          goto LAB_1402f61ec;
                        case (uint *)0x1402f6306:
switchD_1402f62aa_caseD_402f6306:
                          if ((char)puVar57 != '\x04') goto LAB_1402f61e0;
                          break;
                        case (uint *)0x1402f6311:
                          if (cVar31 != '\x02') goto LAB_1402f61e0;
                          break;
                        case (uint *)0x1402f69c1:
                          goto switchD_1402f62f9_caseD_402f69c1;
                        case (uint *)0x1402f6b2f:
                          *(byte *)puVar38 = (byte)*puVar38 + bVar49;
                          goto switchD_1402f6219_caseD_16;
                        case (uint *)0x1402f6b3e:
                          goto switchD_1402f62f9_caseD_402f6b3e;
                        case (uint *)0x1402f6bd9:
                          goto switchD_1402f6219_caseD_18;
                        case (uint *)0x1402f6bf8:
                          bVar33 = *(byte *)_Src;
                          *(byte *)puVar38 = (byte)*puVar38 | bVar49;
                          *(byte *)((longlong)puVar38 + -1) =
                               *(byte *)((longlong)puVar38 + -1) + bVar50 + bVar33;
                          puVar45 = puVar66 + -1;
                          puVar66[-1] = puVar73;
                          cVar105 = '\x17';
                          do {
                            puVar73 = puVar73 + -2;
                            puVar45 = puVar45 + -1;
                            *puVar45 = *(undefined8 *)puVar73;
                            cVar105 = cVar105 + -1;
                          } while ('\0' < cVar105);
                          puVar66[-0x19] = puVar66 + -1;
                          LOCK();
                          *(int *)((longlong)puVar38 +
                                  ((ulonglong)
                                   ((int)CONCAT71((int7)((ulonglong)puVar53 >> 8),bVar50 + bVar33) +
                                   *_Src) - 0x72b80000)) = (int)_Src;
                          UNLOCK();
                          uVar37 = (ulonglong)(uVar36 | 0x2dc1);
                          goto code_r0x0001402f6c0c;
                        case (uint *)0x1402f6cc1:
                          *(byte *)puVar38 = (byte)*puVar38 + bVar49;
switchD_1402f6219_caseD_15:
                          puVar66[0x22] = 0x42424df8;
                          puVar66[0x23] = 1;
                          puVar66[0x24] = puVar66 + 0x34;
                          puVar66[0x25] = 1;
                          puVar66[-1] = 0x1402f6cd0;
                          FUN_1423a0360(puVar66 + 0x40,puVar66 + 0x20);
                          puVar66[0x17] = puVar66[0x40];
                          puVar73 = (uint *)puVar66[0x41];
                          puVar66[0x16] = puVar66[0x42];
                          puVar66[-1] = 0x1402f92f8;
                          FUN_1408192a0(puVar66[9],0xc);
                          *(undefined1 *)((longlong)puVar66 + 0x104) =
                               *(undefined1 *)((longlong)puVar66 + 0x3c);
                          *(undefined4 *)(puVar66 + 0x20) = *(undefined4 *)(puVar66 + 7);
                          uVar74 = 0x1010104;
                          goto LAB_1402f93ee;
                        case (uint *)0x1402f6f8f:
                          puVar53 = puVar73;
                          puVar57 = puVar39;
                          goto code_r0x0001402f6f89;
                        case (uint *)0x1402f7047:
                          *(uint *)(puVar66 + 0x17) = uVar36;
                          goto code_r0x0001402f7039;
                        case (uint *)0x1402f70d2:
                          *puVar57 = *puVar57 & (uint)puVar57;
                          goto code_r0x0001402f70d0;
                        case (uint *)0x1402f71d4:
                          *(byte *)puVar38 = (byte)*puVar38 + bVar49;
                          *(byte *)(puVar53 + -0x12) = (byte)puVar53[-0x12] + bVar49;
                          *puVar38 = *puVar38 + uVar36;
                          *(byte *)puVar38 = (byte)*puVar38 + bVar49;
code_r0x0001402f71d7:
                          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f71e7;
                          FUN_1408192a0(*(undefined8 *)((longlong)puVar66 + 0x48),puVar57);
                          *(undefined1 *)((longlong)puVar66 + 0x104) =
                               *(undefined1 *)((longlong)puVar66 + 0x3c);
                          *(undefined4 *)((longlong)puVar66 + 0x100) =
                               *(undefined4 *)((longlong)puVar66 + 0x38);
                          uVar74 = 0x2020104;
LAB_1402f93ee:
                          *(undefined8 *)((longlong)puVar66 + 0xa8) = uVar74;
                          *(undefined8 *)((longlong)puVar66 + 0x88) = 0;
                          *(undefined8 *)((longlong)puVar66 + 0xa0) =
                               *(undefined8 *)((longlong)puVar66 + 0x80);
                          *(undefined8 *)((longlong)puVar66 + 0x98) =
                               *(undefined8 *)((longlong)puVar66 + 0x58);
                          puVar61 = (uint *)0x0;
                          bVar33 = 0;
                          goto LAB_1402f74f5;
                        case (uint *)0x1402f72ad:
                          *(byte *)puVar38 = (byte)*puVar38 + bVar49;
                          goto code_r0x0001402f728b;
                        case (uint *)0x1402f735f:
                          *puVar38 = *puVar38 + uVar36;
                          *(byte *)puVar53 = (byte)*puVar53 + bVar49;
                          *(byte *)puVar38 = (byte)*puVar38 + bVar49;
                          *(byte *)((longlong)puVar38 + -0x73) =
                               *(byte *)((longlong)puVar38 + -0x73) + bVar50;
                          *(undefined2 *)((longlong)puVar38 * 2) = in_FS;
                          uVar37 = CONCAT71((int7)((ulonglong)puVar38 >> 8),bVar49 + (byte)*puVar38)
                          ;
                          pcVar78 = (char *)(uVar37 - 0x73);
                          *pcVar78 = *pcVar78 + bVar50;
                          puVar65 = (undefined1 *)(uVar37 & 0xffffffff);
                          piVar41 = (int *)((ulonglong)puVar66 & 0xffffff00);
                          *piVar41 = *piVar41 + (int)piVar41;
                          cVar31 = (char)((ulonglong)puVar53 >> 8);
                          pcVar78 = (char *)(CONCAT71((int7)((ulonglong)puVar66 >> 8),cVar31) &
                                            0xffffffff);
                          if (puVar53 == (uint *)0x1) {
                            puVar38 = (uint *)(CONCAT71((int7)((ulonglong)puVar66 >> 8),
                                                        (byte)*puVar57) & 0xffffffff);
                            puVar66 = (undefined8 *)puVar65;
                          }
                          else {
                            *pcVar78 = *pcVar78 + cVar31;
                            *(char **)(puVar65 + 0x1a0) = pcVar78;
                            *(undefined1 **)(puVar65 + 0x1a8) = &LAB_140293f90;
                            *(undefined8 *)(puVar65 + 0x100) = 0;
                            puVar38 = (uint *)&UNK_142424de0;
                            puVar66 = (undefined8 *)puVar65;
                          }
code_r0x0001402f7339:
                          *(uint **)((longlong)puVar66 + 0x110) = puVar38;
                          *(undefined8 *)((longlong)puVar66 + 0x118) = 1;
                          *(undefined1 **)((longlong)puVar66 + 0x120) =
                               (undefined1 *)((longlong)puVar66 + 0x1a0);
                          *(undefined8 *)((longlong)puVar66 + 0x128) = 1;
                          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f737e;
                          FUN_1423a0360((undefined1 *)((longlong)puVar66 + 0x200),
                                        (undefined1 *)((longlong)puVar66 + 0x100));
                          *(undefined8 *)((longlong)puVar66 + 0xb8) =
                               *(undefined8 *)((longlong)puVar66 + 0x200);
                          puVar73 = *(uint **)((longlong)puVar66 + 0x208);
                          *(undefined8 *)((longlong)puVar66 + 0xb0) =
                               *(undefined8 *)((longlong)puVar66 + 0x210);
                          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f93d2;
                          FUN_1408192a0(*(undefined8 *)((longlong)puVar66 + 0x48),0xc);
                          *(undefined1 *)((longlong)puVar66 + 0x104) =
                               *(undefined1 *)((longlong)puVar66 + 0x3c);
                          *(undefined4 *)((longlong)puVar66 + 0x100) =
                               *(undefined4 *)((longlong)puVar66 + 0x38);
                          uVar74 = 0x3020104;
                          goto LAB_1402f93ee;
                        case (uint *)0x1402f85f1:
                          if (-1 < (longlong)puVar80) goto code_r0x0001402f865a;
                          *(undefined4 *)(lVar72 + 0x42) = 0x47c60000;
                          goto LAB_1402f8600;
                        case (uint *)0x1402f86f1:
                          goto switchD_1402f625c_caseD_402f86f1;
                        case (uint *)0x1402f8719:
                          goto code_r0x0001402f8718;
                        case (uint *)0x1402f889b:
                          *(byte *)puVar38 = (byte)*puVar38 + bVar49;
                          goto code_r0x0001402f8895;
                        case (uint *)0x1402f8a17:
                          *(byte *)puVar38 = (byte)*puVar38 + bVar49;
                          goto code_r0x0001402f8a19;
                        case (uint *)0x1402f8a2e:
                          goto code_r0x0001402f8a33;
                        case (uint *)0x1402f8a40:
                          goto code_r0x0001402f8a33;
                        case (uint *)0x1402f8b2c:
                          puVar80 = (uint *)*puVar66;
                          *(byte *)((longlong)puVar38 + -0x75) =
                               *(byte *)((longlong)puVar38 + -0x75) - bVar50;
                          *puVar66 = puVar80;
                          pbVar1 = (byte *)((longlong)puVar38 + 0x3b);
                          bVar33 = *pbVar1;
                          *pbVar1 = *pbVar1 - bVar50;
                          puVar68 = puVar66 + -1;
                          puVar66 = puVar66 + -1;
                          *puVar68 = puVar80;
                          *(byte *)((longlong)puVar73 + 0x25) =
                               (*(byte *)((longlong)puVar73 + 0x25) -
                               (char)((ulonglong)puVar57 >> 8)) - (bVar33 < bVar50);
                          goto code_r0x0001402f8b38;
                        case (uint *)0x1402f8ba7:
                          goto switchD_1402f62f9_caseD_402f8ba7;
                        case (uint *)0x1402f8bce:
                          goto switchD_1402f62f9_caseD_402f8bce;
                        case (uint *)0x1402f8bdc:
                          goto switchD_1402f62f9_caseD_402f8bce;
                        case (uint *)0x1402f8c0b:
                          uVar37 = (ulonglong)(uVar36 + (int)puVar53);
                          goto code_r0x0001402f8bff;
                        }
switchD_1402f62f9_caseD_402f631a:
                        if ((puVar66[0x1d] == 4) && (*(int *)puVar66[0x1c] == 0x474e4950))
                        goto LAB_1402f6913;
                        bVar33 = *(byte *)((longlong)puVar66 + 0xf5);
                        if ((bVar33 & 0xfd) == 0) {
                          bVar33 = 1;
                        }
                        *(char *)((longlong)puVar66 + 0x104) =
                             (char)((uint)*(int *)((longlong)puVar66 + 0xf6) >> 0x18);
                        *(uint *)(puVar66 + 0x20) =
                             (uint)bVar33 | *(int *)((longlong)puVar66 + 0xf6) << 8;
                        puVar66[0x32] = puVar73 + 10;
                        puVar66[-1] = 0x1402f6388;
                        uVar74 = FUN_140765640(puVar73 + 10,puVar66 + 0x20);
                        puVar66[0xb] = uVar74;
                        uVar37 = *(ulonglong *)(puVar73 + 2);
                        lVar62 = *(longlong *)(puVar73 + 8);
                        uVar52 = puVar66[0xb];
                        bVar33 = (byte)(uVar52 >> 0x39);
                        auVar90 = ZEXT216(CONCAT11(bVar33,bVar33));
                        auVar90 = pshuflw(auVar90,auVar90,0);
                        uVar89 = auVar90._0_4_;
                        lVar72 = lVar62 + -5;
                        puVar66[9] = 0;
                        puVar66[0x10] = lVar62;
                        goto LAB_1402f63c6;
                      }
LAB_1402f61ac:
                      auVar96[0] = -(auVar91[0] == cVar105);
                      auVar96[1] = -(auVar91[1] == cVar106);
                      auVar96[2] = -(auVar91[2] == cVar107);
                      auVar96[3] = -(auVar91[3] == cVar108);
                      auVar96[4] = -(auVar91[4] == cVar109);
                      auVar96[5] = -(auVar91[5] == cVar110);
                      auVar96[6] = -(auVar91[6] == cVar111);
                      auVar96[7] = -(auVar91[7] == cVar112);
                      auVar96[8] = -(auVar91[8] == cVar113);
                      auVar96[9] = -(auVar91[9] == cVar114);
                      auVar96[10] = -(auVar91[10] == cVar115);
                      auVar96[0xb] = -(auVar91[0xb] == cVar116);
                      auVar96[0xc] = -(auVar91[0xc] == cVar117);
                      auVar96[0xd] = -(auVar91[0xd] == cVar118);
                      auVar96[0xe] = -(auVar91[0xe] == cVar119);
                      auVar96[0xf] = -(auVar91[0xf] == cVar120);
                      if ((((((((((((((((SUB161(auVar96 >> 7,0) & 1) != 0 ||
                                       (SUB161(auVar96 >> 0xf,0) & 1) != 0) ||
                                      (SUB161(auVar96 >> 0x17,0) & 1) != 0) ||
                                     (SUB161(auVar96 >> 0x1f,0) & 1) != 0) ||
                                    (SUB161(auVar96 >> 0x27,0) & 1) != 0) ||
                                   (SUB161(auVar96 >> 0x2f,0) & 1) != 0) ||
                                  (SUB161(auVar96 >> 0x37,0) & 1) != 0) ||
                                 (SUB161(auVar96 >> 0x3f,0) & 1) != 0) ||
                                (SUB161(auVar96 >> 0x47,0) & 1) != 0) ||
                               (SUB161(auVar96 >> 0x4f,0) & 1) != 0) ||
                              (SUB161(auVar96 >> 0x57,0) & 1) != 0) ||
                             (SUB161(auVar96 >> 0x5f,0) & 1) != 0) ||
                            (SUB161(auVar96 >> 0x67,0) & 1) != 0) ||
                           (SUB161(auVar96 >> 0x6f,0) & 1) != 0) ||
                          (SUB161(auVar96 >> 0x77,0) & 1) != 0) || auVar96[0xf] < '\0') break;
code_r0x0001402f61bd:
                      puVar38 = (uint *)((longlong)puVar38 + puVar66[0xb] + 0x10);
                      puVar53 = (uint *)(puVar66[0xb] + 0x10);
                    } while( true );
                  }
                  *(undefined4 *)(puVar66[0x52] + 4) = *(undefined4 *)((longlong)puVar66 + 0x19c);
                  bVar33 = *(byte *)(puVar66 + 0x1e);
                  if ((bVar33 & 0xfd) == 0) {
                    bVar33 = 1;
                  }
                  uVar4 = *(undefined4 *)((longlong)puVar66 + 0xf1);
                  bVar34 = *(byte *)((longlong)puVar66 + 0xf5);
                  if ((bVar34 & 0xfd) == 0) {
                    bVar34 = 1;
                  }
                  puVar66[-1] = 0x1402f6869;
                  FUN_14032dfb0(puVar66 + 0x40,
                                (ulonglong)
                                CONCAT41(*(undefined4 *)((longlong)puVar66 + 0xf6),bVar34));
                  puVar66[0x24] = puVar66[0x44];
                  puVar66[0x25] = puVar66[0x45];
                  puVar66[0x22] = puVar66[0x42];
                  puVar66[0x23] = puVar66[0x43];
                  puVar66[0x20] = puVar66[0x40];
                  puVar66[0x21] = puVar66[0x41];
                  puVar66[-1] = 0x1402f68cb;
                  FUN_14037d450(puVar66 + 0x34,puVar66[0x12] + 0x40,
                                (ulonglong)CONCAT41(uVar4,bVar33),puVar66 + 0x20);
                  if ((puVar66[0x37] != 0) && (lVar72 = puVar66[0x34], lVar72 != 0)) {
                    uVar37 = (lVar72 + 1) * 5 + 0xfU & 0xfffffffffffffff0;
                    lVar72 = lVar72 + uVar37 + 0x11;
                    if (lVar72 != 0) {
                      puVar66[-1] = 0x1402f6913;
                      FUN_1408192a0(puVar66[0x37] - uVar37,lVar72,0x10);
                    }
                  }
                  goto LAB_1402f6913;
                }
                bVar88 = puVar73 == puVar11;
switchD_1402f62aa_caseD_402f5b64:
              } while (!bVar88);
            }
            goto LAB_1402f94f4;
          }
        }
        else {
          *(undefined ***)((longlong)puVar66 + 0x2a0) =
               &PTR_s__home_puzzled_squid_src_tunnet_d_14241fb68;
        }
      }
    }
    *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f97c9;
    FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                  ,0x2b,*(undefined8 *)((longlong)puVar66 + 0x2a0));
  }
  else {
    *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f979c;
    FUN_1423ab620(uVar37,uVar52,&PTR_s__home_puzzled_squid_src_tunnet_d_14241eae0);
  }
LAB_1402f986f:
                    /* WARNING: Does not return */
  pcVar13 = (code *)invalidInstructionException();
  (*pcVar13)();
switchD_1402f62f9_caseD_402f6b3e:
  goto LAB_1402f5cb8;
LAB_1402f63c6:
  uVar52 = uVar52 & uVar37;
  pcVar78 = (char *)(lVar62 + uVar52);
  cVar31 = *pcVar78;
  cVar99 = pcVar78[1];
  cVar100 = pcVar78[2];
  cVar101 = pcVar78[3];
  cVar19 = pcVar78[4];
  cVar20 = pcVar78[5];
  cVar21 = pcVar78[6];
  cVar22 = pcVar78[7];
  cVar23 = pcVar78[8];
  cVar24 = pcVar78[9];
  cVar25 = pcVar78[10];
  cVar26 = pcVar78[0xb];
  cVar27 = pcVar78[0xc];
  cVar28 = pcVar78[0xd];
  cVar29 = pcVar78[0xe];
  cVar30 = pcVar78[0xf];
  cVar32 = auVar90[0];
  auVar91[0] = -(cVar32 == cVar31);
  cVar93 = auVar90[1];
  auVar91[1] = -(cVar93 == cVar99);
  cVar94 = auVar90[2];
  auVar91[2] = -(cVar94 == cVar100);
  cVar95 = auVar90[3];
  auVar91[3] = -(cVar95 == cVar101);
  auVar91[4] = -(cVar32 == cVar19);
  auVar91[5] = -(cVar93 == cVar20);
  auVar91[6] = -(cVar94 == cVar21);
  auVar91[7] = -(cVar95 == cVar22);
  auVar91[8] = -(cVar32 == cVar23);
  auVar91[9] = -(cVar93 == cVar24);
  auVar91[10] = -(cVar94 == cVar25);
  auVar91[0xb] = -(cVar95 == cVar26);
  auVar91[0xc] = -(cVar32 == cVar27);
  auVar91[0xd] = -(cVar93 == cVar28);
  auVar91[0xe] = -(cVar94 == cVar29);
  auVar91[0xf] = -(cVar95 == cVar30);
  uVar59 = (ushort)(SUB161(auVar91 >> 7,0) & 1) | (ushort)(SUB161(auVar91 >> 0xf,0) & 1) << 1 |
           (ushort)(SUB161(auVar91 >> 0x17,0) & 1) << 2 |
           (ushort)(SUB161(auVar91 >> 0x1f,0) & 1) << 3 |
           (ushort)(SUB161(auVar91 >> 0x27,0) & 1) << 4 |
           (ushort)(SUB161(auVar91 >> 0x2f,0) & 1) << 5 |
           (ushort)(SUB161(auVar91 >> 0x37,0) & 1) << 6 |
           (ushort)(SUB161(auVar91 >> 0x3f,0) & 1) << 7 |
           (ushort)(SUB161(auVar91 >> 0x47,0) & 1) << 8 |
           (ushort)(SUB161(auVar91 >> 0x4f,0) & 1) << 9 |
           (ushort)(SUB161(auVar91 >> 0x57,0) & 1) << 10 |
           (ushort)(SUB161(auVar91 >> 0x5f,0) & 1) << 0xb |
           (ushort)(SUB161(auVar91 >> 0x67,0) & 1) << 0xc |
           (ushort)(SUB161(auVar91 >> 0x6f,0) & 1) << 0xd |
           (ushort)(SUB161(auVar91 >> 0x77,0) & 1) << 0xe | (ushort)(auVar91[0xf] >> 7) << 0xf;
  while (uVar102 = uVar89, uVar59 != 0) {
    uVar12 = 0;
    if (uVar59 != 0) {
      for (; (uVar59 >> uVar12 & 1) == 0; uVar12 = uVar12 + 1) {
      }
    }
    puVar66[-1] = 0x1402f6409;
    cVar32 = FUN_1406b6550(puVar66 + 0x20,(uVar12 + uVar52 & uVar37) * -5 + lVar72);
    uVar59 = uVar59 - 1 & uVar59;
    if (cVar32 != '\0') goto LAB_1402f6913;
  }
  auVar103[0] = -(cVar31 == cVar105);
  auVar103[1] = -(cVar99 == cVar106);
  auVar103[2] = -(cVar100 == cVar107);
  auVar103[3] = -(cVar101 == cVar108);
  auVar103[4] = -(cVar19 == cVar109);
  auVar103[5] = -(cVar20 == cVar110);
  auVar103[6] = -(cVar21 == cVar111);
  auVar103[7] = -(cVar22 == cVar112);
  auVar103[8] = -(cVar23 == cVar113);
  auVar103[9] = -(cVar24 == cVar114);
  auVar103[10] = -(cVar25 == cVar115);
  auVar103[0xb] = -(cVar26 == cVar116);
  auVar103[0xc] = -(cVar27 == cVar117);
  auVar103[0xd] = -(cVar28 == cVar118);
  auVar103[0xe] = -(cVar29 == cVar119);
  auVar103[0xf] = -(cVar30 == cVar120);
  if ((((((((((((((((SUB161(auVar103 >> 7,0) & 1) != 0 || (SUB161(auVar103 >> 0xf,0) & 1) != 0) ||
                  (SUB161(auVar103 >> 0x17,0) & 1) != 0) || (SUB161(auVar103 >> 0x1f,0) & 1) != 0)
                || (SUB161(auVar103 >> 0x27,0) & 1) != 0) || (SUB161(auVar103 >> 0x2f,0) & 1) != 0)
              || (SUB161(auVar103 >> 0x37,0) & 1) != 0) || (SUB161(auVar103 >> 0x3f,0) & 1) != 0) ||
            (SUB161(auVar103 >> 0x47,0) & 1) != 0) || (SUB161(auVar103 >> 0x4f,0) & 1) != 0) ||
          (SUB161(auVar103 >> 0x57,0) & 1) != 0) || (SUB161(auVar103 >> 0x5f,0) & 1) != 0) ||
        (SUB161(auVar103 >> 0x67,0) & 1) != 0) || (SUB161(auVar103 >> 0x6f,0) & 1) != 0) ||
      (SUB161(auVar103 >> 0x77,0) & 1) != 0) || auVar103[0xf] < '\0') goto LAB_1402f90f5;
  uVar52 = uVar52 + puVar66[9] + 0x10;
  puVar66[9] = puVar66[9] + 0x10;
  lVar62 = puVar66[0x10];
  goto LAB_1402f63c6;
LAB_1402f90f5:
  puVar66[-1] = 0x1402f9120;
  FUN_140643f00(puVar73 + 2,puVar66[0xb],puVar66[0x20],puVar66[0x32]);
LAB_1402f6913:
  puVar66[-1] = 0x1402f6927;
  puVar39 = (uint *)FUN_14204d800();
  puVar66[0xe] = puVar39;
  puVar61 = (uint *)(ulonglong)*(uint *)(puVar66 + 0x1e);
  puVar80 = (uint *)(ulonglong)*(uint *)((longlong)puVar66 + 0xf4);
  puVar66[0x10] = puVar66[0x18];
  puVar66[0xb] = puVar66[0x19];
  puVar66[-1] = 0x1402f6969;
  pacVar40 = (char (*) [8])thunk_FUN_142351260(0xc,1);
  if (pacVar40 == (char (*) [8])0x0) {
    puVar66[-1] = 0x1402f97f6;
    FUN_14239ef70(0xc,1);
    goto LAB_1402f986f;
  }
code_r0x0001402f6972:
  builtin_strncpy(pacVar40[1],"cket",4);
  puVar66[9] = pacVar40;
  *pacVar40 = (char  [8])0x617020796d6d7544;
  puVar53 = (uint *)puVar66[0xd];
  *(byte *)((longlong)puVar66 + 0x3c) = (byte)puVar53[1];
  puVar38 = (uint *)(ulonglong)*puVar53;
  puVar79 = puVar80;
switchD_1402f625c_caseD_402f6999:
  *(int *)(puVar66 + 7) = (int)puVar38;
  puVar73 = (uint *)((ulonglong)(byte)*puVar53 - 1);
  if (puVar73 < (uint *)0x4) {
switchD_1402f62aa_caseD_402f69ad:
    puVar80 = (uint *)((longlong)puVar79 << 0x20 | (ulonglong)puVar61);
    puVar38 = (uint *)puVar66[0xd];
    puVar53 = (uint *)(ulonglong)*(byte *)((longlong)puVar38 + 1);
    puVar57 = (uint *)(ulonglong)*(byte *)((longlong)puVar38 + 2);
switchD_1402f62f9_caseD_402f69c1:
    bVar33 = *(byte *)((longlong)puVar38 + 3);
    cVar99 = (char)puVar57;
    cVar31 = (char)puVar53;
    switch((longlong)&switchD_1402f69d3::switchdataD_1402f99c4 +
           (longlong)(int)(&switchD_1402f69d3::switchdataD_1402f99c4)[(longlong)puVar73]) {
    case 0x1402f69d5:
      iVar82 = (int)puVar57;
      if (iVar82 == 2) {
        if (bVar33 == 2) {
          *(uint *)(puVar66 + 8) = (int)puVar53 << 8 | 0x3040001;
          *(undefined1 *)((longlong)puVar66 + 0x44) = 0;
          puVar66[-1] = 0x1402f6f16;
          cVar31 = FUN_1406b6550(puVar66 + 0x1e,puVar66 + 8);
          _Src = (uint *)puVar66[0xc];
          puVar66[0x32] = puVar39;
          if (cVar31 != '\0') {
            puVar61 = (uint *)puVar66[0x32];
            puVar39 = puVar61 + 4;
            puVar73 = puVar61 + 0x48;
            puVar38 = *(uint **)(puVar61 + 0x44);
LAB_1402f6f83:
            do {
              puVar53 = puVar73;
              puVar57 = puVar39;
              if (&DAT_0000003f < puVar38) {
code_r0x0001402f6f89:
                *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f6f8e;
                uVar52 = FUN_14204e720();
                puVar73 = puVar53;
                puVar39 = puVar57;
                if ((*(longlong *)(puVar61 + 0x56) < 1) ||
                   ((longlong)(*(longlong *)(puVar61 + 0x58) - uVar52) < 0)) {
switchD_1402f6219_caseD_1e:
                  *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f6f58;
                  FUN_1404628b0(puVar53,puVar57,uVar52);
                }
                else {
                  *(longlong *)(puVar61 + 0x56) = *(longlong *)(puVar61 + 0x56) + -0x100;
                  *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f6fc1;
                  FUN_14204f0e0(puVar53,6,puVar57);
                }
                puVar61[0x44] = 0;
                puVar61[0x45] = 0;
                puVar38 = (uint *)0x0;
              }
LAB_1402f6f65:
              uVar36 = puVar61[(longlong)(puVar38 + 1)];
              puVar38 = (uint *)((longlong)puVar38 + 1);
              *(uint **)(puVar61 + 0x44) = puVar38;
            } while (0xb3ffffff < (uint)((ulonglong)uVar36 * 0x5a));
            *(int *)((longlong)puVar66 + 0x2ac) = (int)((ulonglong)uVar36 * 0x5a >> 0x20) + 10;
            *(undefined1 **)((longlong)puVar66 + 0x1a0) = (undefined1 *)((longlong)puVar66 + 0x2ac);
            *(code **)((longlong)puVar66 + 0x1a8) = FUN_1423bf650;
            *(undefined8 *)((longlong)puVar66 + 0x100) = 0;
            *(undefined ***)((longlong)puVar66 + 0x110) = &PTR_s_I_wanna_buy_crypto_coins_142424e50;
            *(undefined8 *)((longlong)puVar66 + 0x118) = 2;
            *(undefined1 **)((longlong)puVar66 + 0x120) = (undefined1 *)((longlong)puVar66 + 0x1a0);
            *(undefined8 *)((longlong)puVar66 + 0x128) = 1;
            *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f91aa;
            FUN_1423a0360((undefined1 *)((longlong)puVar66 + 0x200),
                          (undefined1 *)((longlong)puVar66 + 0x100));
            *(undefined8 *)((longlong)puVar66 + 0xb8) = *(undefined8 *)((longlong)puVar66 + 0x200);
            puVar73 = *(uint **)((longlong)puVar66 + 0x208);
            *(undefined8 *)((longlong)puVar66 + 0xb0) = *(undefined8 *)((longlong)puVar66 + 0x210);
            *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f91e7;
            FUN_1408192a0(*(undefined8 *)((longlong)puVar66 + 0x48),0xc);
            *(undefined1 *)((longlong)puVar66 + 0x104) = *(undefined1 *)((longlong)puVar66 + 0x3c);
            *(undefined4 *)((longlong)puVar66 + 0x100) = *(undefined4 *)((longlong)puVar66 + 0x38);
            *(undefined8 *)((longlong)puVar66 + 0x88) = 0;
            *(undefined8 *)((longlong)puVar66 + 0xa0) = *(undefined8 *)((longlong)puVar66 + 0x80);
            *(undefined8 *)((longlong)puVar66 + 0x98) = *(undefined8 *)((longlong)puVar66 + 0x58);
            puVar61 = (uint *)0x0;
LAB_1402f9227:
            *(uint **)((longlong)puVar66 + 0xa8) = puVar80;
            bVar33 = 0;
            puVar39 = *(uint **)((longlong)puVar66 + 400);
            goto LAB_1402f74f5;
          }
        }
        goto switchD_1402f6b70_default;
      }
      if (iVar82 != 3) {
        if (iVar82 == 4) {
          if (bVar33 == 2) {
            if (((cVar31 == '\x01') && (puVar66[0x1d] == 0xc)) &&
               ((int)((longlong *)puVar66[0x1c])[1] == 0x676f6c61 &&
                *(longlong *)puVar66[0x1c] == 0x7461632f20544547)) {
              puVar61 = (uint *)&DAT_00000007;
              puVar66[-1] = 0x1402f943b;
              puVar73 = (uint *)thunk_FUN_142351260(7,1);
              _Src = (uint *)puVar66[0xc];
              if (puVar73 == (uint *)0x0) goto LAB_1402f9818;
              pbVar1 = (byte *)((longlong)puVar73 + 3);
              pbVar1[0] = 0x61;
              pbVar1[1] = 0x6c;
              pbVar1[2] = 0x6f;
              pbVar1[3] = 0x67;
              *puVar73 = 0x61746143;
              puVar66[-1] = 0x1402f946e;
              FUN_1408192a0(puVar66[9],0xc);
              *(undefined1 *)((longlong)puVar66 + 0x104) = *(undefined1 *)((longlong)puVar66 + 0x3c)
              ;
              *(undefined4 *)(puVar66 + 0x20) = *(undefined4 *)(puVar66 + 7);
              puVar66[0x17] = 7;
              puVar66[0x11] = 0;
              puVar66[0x14] = puVar66[0x10];
              puVar66[0x13] = puVar66[0xb];
              puVar66[0x15] = puVar80;
              uVar74 = 7;
              break;
            }
          }
          else if (bVar33 == 1) {
            *(uint *)(puVar66 + 8) = (int)puVar53 << 8 | 0x3040001;
            *(undefined1 *)((longlong)puVar66 + 0x44) = 0;
            puVar66[-1] = 0x1402f6a25;
            cVar31 = FUN_1406b6550(puVar66 + 0x1e,puVar66 + 8);
            _Src = (uint *)puVar66[0xc];
            puVar66[0x32] = puVar39;
            if (cVar31 != '\0') {
              puVar66[0x34] = puVar66 + 0x1b;
              puVar66[0x35] = &LAB_140293f90;
              puVar66[0x20] = 0;
              puVar66[0x22] = &PTR_DAT_142424e18;
              puVar66[0x23] = 1;
              puVar66[0x24] = puVar66 + 0x34;
              puVar66[0x25] = 1;
              puVar66[-1] = 0x1402f6ab1;
              FUN_1423a0360(puVar66 + 0x40,puVar66 + 0x20);
              puVar66[0x17] = puVar66[0x40];
              puVar73 = (uint *)puVar66[0x41];
              puVar66[0x16] = puVar66[0x42];
              puVar66[-1] = 0x1402f6aee;
              FUN_1408192a0(puVar66[9],0xc);
              puVar61 = (uint *)0x1;
switchD_1402f6219_caseD_16:
              *(undefined1 *)((longlong)puVar66 + 0x104) = *(undefined1 *)((longlong)puVar66 + 0x3c)
              ;
              *(undefined4 *)(puVar66 + 0x20) = *(undefined4 *)(puVar66 + 7);
              puVar66[0x11] = 0;
              puVar66[0x14] = puVar66[0x10];
              puVar66[0x13] = puVar66[0xb];
              goto LAB_1402f9227;
            }
          }
        }
        goto switchD_1402f6b70_default;
      }
      if (((bVar33 != 1) || (puVar66[0x1d] != 0xc)) ||
         ((int)((longlong *)puVar66[0x1c])[1] != 0x79726575 ||
          *(longlong *)puVar66[0x1c] != 0x7120686372616553)) goto switchD_1402f6b70_default;
      puVar61 = (uint *)&DAT_0000000d;
      puVar66[-1] = 0x1402f6e47;
      puVar73 = (uint *)thunk_FUN_142351260(0xd,1);
      _Src = (uint *)puVar66[0xc];
      if (puVar73 == (uint *)0x0) goto LAB_1402f9818;
      pbVar1 = (byte *)((longlong)puVar73 + 5);
      pbVar1[0] = 0x68;
      pbVar1[1] = 0x20;
      pbVar1[2] = 0x72;
      pbVar1[3] = 0x65;
      pbVar1[4] = 0x73;
      pbVar1[5] = 0x75;
      pbVar1[6] = 0x6c;
      pbVar1[7] = 0x74;
      puVar73[0] = 0x72616553;
      puVar73[1] = 0x72206863;
      puVar66[-1] = 0x1402f6e8b;
      FUN_1408192a0(puVar66[9],0xc);
      *(undefined1 *)((longlong)puVar66 + 0x104) = *(undefined1 *)((longlong)puVar66 + 0x3c);
      *(undefined4 *)(puVar66 + 0x20) = *(undefined4 *)(puVar66 + 7);
      puVar66[0x17] = 0xd;
      puVar66[0x11] = 0;
      puVar66[0x14] = puVar66[0x10];
      puVar66[0x13] = puVar66[0xb];
      puVar66[0x15] = puVar80;
      uVar74 = 0xd;
      break;
    case 0x1402f6b43:
      if ((cVar31 != '\x02') || (cVar99 != '\x03')) goto switchD_1402f6b70_default;
      switch((ulonglong)bVar33) {
      case 1:
        *(undefined1 *)((longlong)puVar66 + 0x3c) = *(undefined1 *)((longlong)puVar66 + 0xf4);
        *(undefined4 *)(puVar66 + 7) = *(undefined4 *)(puVar66 + 0x1e);
        puVar61 = (uint *)&DAT_00000005;
        puVar66[-1] = &UNK_1402f6b9c;
        puVar38 = (uint *)thunk_FUN_142351260(5,1);
        bVar88 = puVar38 == (uint *)0x0;
code_r0x0001402f6b9f:
        _Src = (uint *)puVar66[0xc];
        if (bVar88) {
LAB_1402f9818:
          puVar66[-1] = 0x1402f9825;
          FUN_14239ef70(puVar61,1);
          goto LAB_1402f986f;
        }
        *(byte *)(puVar38 + 1) = 0x6e;
        *puVar38 = 0x656b6f54;
        puVar57 = (uint *)&DAT_0000000c;
        puVar73 = puVar38;
switchD_1402f6219_caseD_18:
        puVar66[-1] = 0x1402f6bcc;
        FUN_1408192a0(puVar66[9],puVar57);
        *(undefined1 *)((longlong)puVar66 + 0x104) = *(undefined1 *)((longlong)puVar66 + 0x3c);
        *(undefined4 *)(puVar66 + 0x20) = *(undefined4 *)(puVar66 + 7);
        puVar38 = (uint *)0x4030203;
        break;
      case 2:
        *(undefined1 *)((longlong)puVar66 + 0x3c) = *(undefined1 *)((longlong)puVar66 + 0xf4);
        *(undefined4 *)(puVar66 + 7) = *(undefined4 *)(puVar66 + 0x1e);
        puVar61 = (uint *)&DAT_00000005;
        puVar66[-1] = 0x1402f7232;
        puVar73 = (uint *)thunk_FUN_142351260(5,1);
        _Src = (uint *)puVar66[0xc];
        if (puVar73 == (uint *)0x0) goto LAB_1402f9818;
        *(byte *)(puVar73 + 1) = 0x6e;
        *puVar73 = 0x656b6f54;
        puVar66[-1] = 0x1402f7262;
        FUN_1408192a0(puVar66[9],0xc);
        *(undefined1 *)((longlong)puVar66 + 0x104) = *(undefined1 *)((longlong)puVar66 + 0x3c);
        *(undefined4 *)(puVar66 + 0x20) = *(undefined4 *)(puVar66 + 7);
code_r0x0001402f7279:
        puVar38 = (uint *)0x3030203;
        break;
      case 3:
        *(undefined1 *)((longlong)puVar66 + 0x3c) = *(undefined1 *)((longlong)puVar66 + 0xf4);
        *(undefined4 *)(puVar66 + 7) = *(undefined4 *)(puVar66 + 0x1e);
        puVar61 = (uint *)&DAT_00000005;
        puVar66[-1] = 0x1402f6fed;
        puVar73 = (uint *)thunk_FUN_142351260(5,1);
        _Src = (uint *)puVar66[0xc];
        if (puVar73 == (uint *)0x0) goto LAB_1402f9818;
        *(byte *)(puVar73 + 1) = 0x6e;
        *puVar73 = 0x656b6f54;
        puVar57 = (uint *)&DAT_0000000c;
code_r0x0001402f700d:
        puVar66[-1] = 0x1402f701d;
        FUN_1408192a0(puVar66[9],puVar57);
        *(undefined1 *)((longlong)puVar66 + 0x104) = *(undefined1 *)((longlong)puVar66 + 0x3c);
        *(undefined4 *)(puVar66 + 0x20) = *(undefined4 *)(puVar66 + 7);
        puVar38 = (uint *)0x1010401;
code_r0x0001402f7039:
        puVar66[0x15] = puVar38;
        puVar66[0x17] = 5;
        puVar66[0x13] = 6;
        puVar66[0x11] = 1;
        puVar66[0x14] = &DAT_1424241fe;
        goto LAB_1402f72bc;
      case 4:
        *(undefined1 *)((longlong)puVar66 + 0x3c) = *(undefined1 *)((longlong)puVar66 + 0xf4);
        *(undefined4 *)(puVar66 + 7) = *(undefined4 *)(puVar66 + 0x1e);
        puVar61 = (uint *)&DAT_00000005;
switchD_1402f6219_caseD_1a:
        puVar66[-1] = 0x1402f70a5;
        puVar38 = (uint *)thunk_FUN_142351260(5,1);
        _Src = (uint *)puVar66[0xc];
        if (puVar38 == (uint *)0x0) goto LAB_1402f9818;
code_r0x0001402f70b3:
        *(byte *)(puVar38 + 1) = 0x6e;
        *puVar38 = 0x656b6f54;
        puVar57 = (uint *)&DAT_0000000c;
        puVar53 = (uint *)puVar66[9];
        puVar73 = puVar38;
code_r0x0001402f70d0:
        puVar66[-1] = 0x1402f70d5;
        FUN_1408192a0(puVar53,puVar57);
        *(undefined1 *)((longlong)puVar66 + 0x104) = *(undefined1 *)((longlong)puVar66 + 0x3c);
        *(undefined4 *)(puVar66 + 0x20) = *(undefined4 *)(puVar66 + 7);
        puVar38 = (uint *)0x2030203;
        break;
      default:
        goto switchD_1402f6b70_default;
      }
LAB_1402f727e:
      puVar66[0x15] = puVar38;
      puVar38 = (uint *)&DAT_00000005;
code_r0x0001402f728b:
      puVar66[0x17] = puVar38;
      puVar66[0x11] = CONCAT71((int7)((ulonglong)puVar38 >> 8),1);
      puVar66[0x14] = puVar66[0x10];
      puVar66[0x13] = puVar66[0xb];
LAB_1402f72bc:
      uVar74 = 5;
      break;
    case 0x1402f6bed:
      if (((cVar31 == '\x01') && (cVar99 == '\x02')) && (uVar37 = (ulonglong)bVar33 - 1, uVar37 < 4)
         ) {
code_r0x0001402f6c0c:
                    /* WARNING: Could not recover jumptable at 0x0001402f6c1a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)((longlong)&UINT_1402f99d4 + (longlong)(int)(&UINT_1402f99d4)[uVar37]))();
        return;
      }
      goto switchD_1402f6b70_default;
    case 0x1402f6cd5:
      if ((cVar99 != '\x02') || (bVar33 != 1)) goto switchD_1402f6b70_default;
      puVar66[0x34] = puVar66 + 0x1b;
      puVar66[0x35] = &LAB_140293f90;
      puVar66[0x20] = 0;
      puVar66[0x22] = &PTR_DAT_142424df8;
      puVar66[0x23] = 1;
      puVar66[0x24] = puVar66 + 0x34;
      puVar66[0x25] = 1;
      puVar66[-1] = 0x1402f6d5d;
      FUN_1423a0360(puVar66 + 0x40,puVar66 + 0x20);
      _Src = (uint *)puVar66[0xc];
      puVar66[0x17] = puVar66[0x40];
      puVar73 = (uint *)puVar66[0x41];
      puVar66[0x16] = puVar66[0x42];
      puVar66[-1] = 0x1402f6d9f;
      FUN_1408192a0(puVar66[9],0xc,1);
      *(undefined1 *)((longlong)puVar66 + 0x104) = *(undefined1 *)((longlong)puVar66 + 0x3c);
      *(undefined4 *)(puVar66 + 0x20) = *(undefined4 *)(puVar66 + 7);
      bVar33 = 1;
      puVar61 = (uint *)&DAT_00000004;
      puVar66[0x11] = 0;
      puVar66[0x14] = puVar66[0x10];
      puVar66[0x13] = puVar66[0xb];
      puVar66[0x15] = puVar80;
      goto LAB_1402f74f5;
    }
    puVar61 = (uint *)0x0;
    puVar66[0x16] = uVar74;
    bVar33 = 0;
  }
  else {
switchD_1402f6b70_default:
    puVar66[-1] = 0x1402f74dd;
    FUN_1408192a0(puVar66[9],0xc,1);
    bVar33 = 2;
    _Src = (uint *)puVar66[0xc];
    puVar73 = (uint *)puVar66[0x5a];
    puVar61 = (uint *)puVar66[0x5b];
  }
LAB_1402f74f5:
  *(longlong *)puVar39 = *(longlong *)puVar39 + -1;
  if (*(longlong *)puVar39 == 0) {
    puVar80 = puVar39 + 2;
    *(longlong *)puVar80 = *(longlong *)puVar80 + -1;
    if (*(longlong *)puVar80 == 0) {
      *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7521;
      FUN_1408192a0(puVar39,0x170,0x10);
    }
  }
  if ((*(byte *)((longlong)_Src + 0x7a) != 2) && (uVar37 = *(ulonglong *)(_Src + 0x16), uVar37 != 0)
     ) {
    uVar74 = *(undefined8 *)(_Src + 0x18);
    *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f754f;
    FUN_1408192a0(uVar74,uVar37,~uVar37 >> 0x3f);
  }
  *(undefined8 *)(_Src + 0x10) = *(undefined8 *)((longlong)puVar66 + 0xa0);
  *(undefined8 *)(_Src + 0x12) = *(undefined8 *)((longlong)puVar66 + 0x98);
  *(uint **)((longlong)puVar66 + 0x2d8) = puVar61;
  *(uint **)(_Src + 0x14) = puVar61;
  *(undefined8 *)(_Src + 0x16) = *(undefined8 *)((longlong)puVar66 + 0xb8);
  *(uint **)(_Src + 0x18) = puVar73;
  *(undefined8 *)(_Src + 0x1a) = *(undefined8 *)((longlong)puVar66 + 0xb0);
  _Src[0x1c] = *(uint *)((longlong)puVar66 + 0x100);
  *(byte *)(_Src + 0x1d) = *(byte *)((longlong)puVar66 + 0x104);
  uVar74 = *(undefined8 *)((longlong)puVar66 + 0xa8);
  *(byte *)((longlong)_Src + 0x79) = (byte)((ulonglong)uVar74 >> 0x20);
  *(int *)((longlong)_Src + 0x75) = (int)uVar74;
  *(byte *)((longlong)_Src + 0x7a) = bVar33;
  *(byte *)((longlong)_Src + 0x7b) = (byte)*(undefined8 *)((longlong)puVar66 + 0x88);
  *(byte *)(_Src + 0x1f) = 0;
  *(byte *)((longlong)_Src + 0x7f) = *(byte *)((longlong)puVar66 + 0x202);
  *(undefined2 *)((longlong)_Src + 0x7d) = *(undefined2 *)((longlong)puVar66 + 0x200);
  if ((*(char *)((longlong)puVar66 + 0xf5) != '\0') &&
     (*(char *)((longlong)puVar66 + 0xf5) != '\x03')) {
    *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7617;
    iVar35 = FUN_1406b6820((undefined1 *)((longlong)puVar66 + 0xc0),
                           *(undefined8 *)((longlong)puVar66 + 0x90));
    puVar45 = *(undefined8 **)((longlong)puVar66 + 0x430);
    uVar74 = *puVar45;
    uVar54 = puVar45[1];
    uVar89 = *(undefined4 *)(puVar45 + 2);
    *(undefined4 *)((longlong)puVar66 + 0x30) = *(undefined4 *)((longlong)puVar45 + 0x14);
    *(undefined4 *)((longlong)puVar66 + 0x28) = uVar89;
    *(undefined4 *)((longlong)puVar66 + 0x20) = *(undefined4 *)((longlong)puVar66 + 0x78);
    *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7650;
    FUN_1400af880((undefined1 *)((longlong)puVar66 + 0x100),uVar54,uVar74,
                  *(undefined4 *)((longlong)puVar66 + 0x7c));
    iVar82 = iVar35;
    if ((*(int *)((longlong)puVar66 + 0x100) == 0) &&
       ((iVar82 = 0, **(char **)((longlong)puVar66 + 0x108) != '\n' &&
        (iVar82 = iVar35 / 2, iVar82 < 2)))) {
      iVar82 = 1;
    }
    if ((*(longlong *)((longlong)puVar66 + 0xe8) == 4) &&
       ((**(int **)((longlong)puVar66 + 0xe0) == 0x474e4950 ||
        (**(int **)((longlong)puVar66 + 0xe0) == 0x474e4f50)))) {
      iVar82 = 0;
    }
    *(undefined ***)((longlong)puVar66 + 0x20) = &PTR_s_src_net_endpoint_rs_142424420;
    *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f76cf;
    FUN_142244e00((undefined1 *)((longlong)puVar66 + 0x100),
                  (undefined1 *)((longlong)puVar66 + 0x1e0),
                  *(undefined4 *)((longlong)puVar66 + 0x7c),
                  *(undefined4 *)((longlong)puVar66 + 0x78));
    uVar89 = *(undefined4 *)((longlong)puVar66 + 0x100);
    uVar102 = *(undefined4 *)((longlong)puVar66 + 0x104);
    plVar75 = (longlong *)**(longlong **)((longlong)puVar66 + 0x108);
    lVar72 = plVar75[2];
    lVar62 = plVar75[5];
    if (lVar62 == plVar75[3]) {
      *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f76fa;
      FUN_14079f6c0(plVar75 + 3);
      lVar62 = plVar75[5];
    }
    lVar2 = plVar75[4];
    *(longlong *)(lVar2 + lVar62 * 0x10) = lVar72;
    *(code **)(lVar2 + 8 + lVar62 * 0x10) = FUN_140694340;
    plVar75[5] = plVar75[5] + 1;
    lVar62 = plVar75[2];
    if ((ulonglong)(*plVar75 - lVar62) < 0x10) {
      *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7738;
      FUN_1407a1510(plVar75,lVar62,0x10);
    }
    lVar62 = plVar75[1];
    puVar43 = (undefined4 *)(lVar62 + lVar72);
    *puVar43 = uVar89;
    puVar43[1] = uVar102;
    *(longlong *)(lVar62 + 8 + lVar72) = (longlong)iVar82;
    plVar75[2] = lVar72 + 0x10;
  }
  puVar86 = (undefined1 *)((longlong)puVar66 + 0x100);
  plVar75 = *(longlong **)((longlong)puVar66 + 0xe0);
  uVar37 = *(ulonglong *)((longlong)puVar66 + 0xe8);
  *(uint **)((longlong)puVar66 + 0x2d0) = puVar73;
  if (uVar37 == 8) {
    if (*plVar75 != 0x3123206b63617254) {
      if (*plVar75 == 0x3223206b63617254) {
        if (*(char *)((longlong)puVar66 + 0x57) != '\0') {
          *(undefined ***)((longlong)puVar66 + 0x20) = &PTR_s_src_net_endpoint_rs_142424468;
          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7a9b;
          FUN_142244e00(puVar86,(undefined1 *)((longlong)puVar66 + 0x1e0),
                        *(undefined4 *)((longlong)puVar66 + 0x7c),
                        *(undefined4 *)((longlong)puVar66 + 0x78));
          uVar89 = *(undefined4 *)((longlong)puVar66 + 0x100);
          uVar102 = *(undefined4 *)((longlong)puVar66 + 0x104);
          plVar75 = (longlong *)**(undefined8 **)((longlong)puVar66 + 0x108);
          lVar62 = plVar75[2];
          lVar72 = plVar75[5];
          if (lVar72 == plVar75[3]) {
            *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7ac6;
            FUN_14079f6c0(plVar75 + 3);
            lVar72 = plVar75[5];
          }
          lVar2 = plVar75[4];
          *(longlong *)(lVar2 + lVar72 * 0x10) = lVar62;
          *(code **)(lVar2 + 8 + lVar72 * 0x10) = FUN_14068b0c0;
          plVar75[5] = plVar75[5] + 1;
          lVar72 = plVar75[2];
          if ((ulonglong)(*plVar75 - lVar72) < 0x20) {
            *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7b04;
            FUN_1407a1510(plVar75,lVar72,0x20);
          }
          lVar72 = plVar75[1];
          *(undefined4 *)(lVar72 + lVar62) = uVar89;
          ((undefined4 *)(lVar72 + lVar62))[1] = uVar102;
          pcVar78 = "cabin";
LAB_1402f7b14:
          *(char **)(lVar72 + 8 + lVar62) = pcVar78;
          *(undefined8 *)(lVar72 + 0x10 + lVar62) = 5;
          goto LAB_1402f7be9;
        }
      }
      else if (*plVar75 == 0x3323206b63617254) {
        if (*(char *)((longlong)puVar66 + 0x57) != '\0') {
          *(undefined ***)((longlong)puVar66 + 0x20) = &PTR_s_src_net_endpoint_rs_142424490;
          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7b62;
          FUN_142244e00(puVar86,(undefined1 *)((longlong)puVar66 + 0x1e0),
                        *(undefined4 *)((longlong)puVar66 + 0x7c),
                        *(undefined4 *)((longlong)puVar66 + 0x78));
          uVar89 = *(undefined4 *)((longlong)puVar66 + 0x100);
          uVar102 = *(undefined4 *)((longlong)puVar66 + 0x104);
          plVar75 = (longlong *)**(undefined8 **)((longlong)puVar66 + 0x108);
          lVar62 = plVar75[2];
          lVar72 = plVar75[5];
          if (lVar72 == plVar75[3]) {
            *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7b8d;
            FUN_14079f6c0(plVar75 + 3);
            lVar72 = plVar75[5];
          }
          lVar2 = plVar75[4];
          *(longlong *)(lVar2 + lVar72 * 0x10) = lVar62;
          *(code **)(lVar2 + 8 + lVar72 * 0x10) = FUN_14068b0c0;
          plVar75[5] = plVar75[5] + 1;
          lVar72 = plVar75[2];
          if ((ulonglong)(*plVar75 - lVar72) < 0x20) {
            *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7bcb;
            FUN_1407a1510(plVar75,lVar72,0x20);
          }
          lVar72 = plVar75[1];
          *(undefined4 *)(lVar72 + lVar62) = uVar89;
          ((undefined4 *)(lVar72 + lVar62))[1] = uVar102;
          *(char **)(lVar72 + 8 + lVar62) = "supermarket";
          *(undefined8 *)(lVar72 + 0x10 + lVar62) = 0xb;
          goto LAB_1402f7be9;
        }
      }
      else if ((*(byte *)((longlong)puVar66 + 0x57) & *plVar75 == 0x3423206b63617254) != 0) {
        *(undefined ***)((longlong)puVar66 + 0x20) = &PTR_s_src_net_endpoint_rs_1424244b0;
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f792f;
        FUN_142244e00(puVar86,(undefined1 *)((longlong)puVar66 + 0x1e0),
                      *(undefined4 *)((longlong)puVar66 + 0x7c),
                      *(undefined4 *)((longlong)puVar66 + 0x78));
        uVar89 = *(undefined4 *)((longlong)puVar66 + 0x100);
        uVar102 = *(undefined4 *)((longlong)puVar66 + 0x104);
        plVar75 = (longlong *)**(longlong **)((longlong)puVar66 + 0x108);
        lVar62 = plVar75[2];
        lVar72 = plVar75[5];
        if (lVar72 == plVar75[3]) {
          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f795a;
          FUN_14079f6c0(plVar75 + 3);
          lVar72 = plVar75[5];
        }
        lVar2 = plVar75[4];
        *(longlong *)(lVar2 + lVar72 * 0x10) = lVar62;
        *(code **)(lVar2 + 8 + lVar72 * 0x10) = FUN_14068b0c0;
        plVar75[5] = plVar75[5] + 1;
        lVar72 = plVar75[2];
        if ((ulonglong)(*plVar75 - lVar72) < 0x20) {
          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7998;
          FUN_1407a1510(plVar75,lVar72,0x20);
        }
        lVar72 = plVar75[1];
        *(undefined4 *)(lVar72 + lVar62) = uVar89;
        ((undefined4 *)(lVar72 + lVar62))[1] = uVar102;
        pcVar78 = "beach";
        goto LAB_1402f7b14;
      }
LAB_1402f7c00:
      uVar37 = *(ulonglong *)((longlong)puVar66 + 0xe8);
      goto LAB_1402f7c08;
    }
    if (*(char *)((longlong)puVar66 + 0x57) != '\0') {
      *(undefined ***)((longlong)puVar66 + 0x20) = &PTR_s_src_net_endpoint_rs_142424440;
      *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f79de;
      FUN_142244e00(puVar86,(undefined1 *)((longlong)puVar66 + 0x1e0),
                    *(undefined4 *)((longlong)puVar66 + 0x7c),
                    *(undefined4 *)((longlong)puVar66 + 0x78));
      uVar89 = *(undefined4 *)((longlong)puVar66 + 0x100);
      uVar102 = *(undefined4 *)((longlong)puVar66 + 0x104);
      plVar75 = (longlong *)**(undefined8 **)((longlong)puVar66 + 0x108);
      lVar62 = plVar75[2];
      lVar72 = plVar75[5];
      if (lVar72 == plVar75[3]) {
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7a09;
        FUN_14079f6c0(plVar75 + 3);
        lVar72 = plVar75[5];
      }
      lVar2 = plVar75[4];
      *(longlong *)(lVar2 + lVar72 * 0x10) = lVar62;
      *(code **)(lVar2 + 8 + lVar72 * 0x10) = FUN_14068b0c0;
      plVar75[5] = plVar75[5] + 1;
      lVar72 = plVar75[2];
      if ((ulonglong)(*plVar75 - lVar72) < 0x20) {
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7a47;
        FUN_1407a1510(plVar75,lVar72,0x20);
      }
      lVar72 = plVar75[1];
      *(undefined4 *)(lVar72 + lVar62) = uVar89;
      ((undefined4 *)(lVar72 + lVar62))[1] = uVar102;
      *(char **)(lVar72 + 8 + lVar62) = "camp";
      *(undefined8 *)(lVar72 + 0x10 + lVar62) = 4;
LAB_1402f7be9:
      *(undefined8 *)(lVar72 + 0x18 + lVar62) = 0x7fffffff000000f0;
      plVar75[2] = lVar62 + 0x20;
      goto LAB_1402f7c00;
    }
    uVar37 = 8;
LAB_1402f7c12:
    piVar41 = *(int **)((longlong)puVar66 + 0xe0);
    if (*(int *)((longlong)piVar41 + 3) == 0x2f205245 && *piVar41 == 0x4544524f) {
      if ((7 < uVar37) && (*(char *)((longlong)piVar41 + 7) < -0x40)) {
        *(undefined ***)((longlong)puVar66 + 0x20) = &PTR_s_src_net_endpoint_rs_1424244d8;
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f9841;
        FUN_1423b47c0(piVar41,uVar37,7,uVar37);
        goto LAB_1402f986f;
      }
      *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7c52;
      uVar37 = FUN_1423babb0((longlong)piVar41 + 7,uVar37 - 7);
      if ((uVar37 & 1) == 0) {
        *(undefined4 *)(*(longlong *)((longlong)puVar66 + 0x290) + 4) =
             *(undefined4 *)((longlong)puVar66 + 0x19c);
        lVar72 = *(longlong *)((longlong)puVar66 + 0x90);
        plVar75 = *(longlong **)((longlong)puVar66 + 0x438);
        *(undefined4 *)(*plVar75 + 4) = *(undefined4 *)((longlong)plVar75 + 0xc);
        lVar62 = plVar75[2];
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7c9c;
        cVar31 = FUN_14079a770(lVar72 + 0x160,lVar62,uVar37 >> 0x20);
        if ((cVar31 != '\0') && (*(longlong *)(*(longlong *)((longlong)puVar66 + 0x90) + 0x18) == 0)
           ) {
          *(undefined2 *)((longlong)puVar66 + 0x1a0) = 400;
          *(undefined4 *)(*(longlong *)((longlong)puVar66 + 0x290) + 4) =
               *(undefined4 *)((longlong)puVar66 + 0x19c);
          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7ce8;
          FUN_1405211a0((undefined1 *)((longlong)puVar66 + 0x200),
                        (undefined1 *)((longlong)puVar66 + 0x1a0));
          *(undefined2 *)((longlong)puVar66 + 0x100) = 400;
          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7d0d;
          memcpy((undefined1 *)((longlong)puVar66 + 0x108),(undefined1 *)((longlong)puVar66 + 0x200)
                 ,0x88);
          puVar8 = *(ulonglong **)((longlong)puVar66 + 0x90);
          uVar37 = *puVar8;
          uVar52 = puVar8[3];
          if (uVar52 == uVar37) {
            *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7d31;
            FUN_140293030(puVar8);
            uVar37 = *puVar8;
            uVar52 = puVar8[3];
          }
          uVar56 = puVar8[2];
          uVar44 = 0;
          if (uVar37 <= uVar52 + uVar56) {
            uVar44 = uVar37;
          }
          uVar37 = puVar8[1];
          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7d65;
          memcpy((void *)(((uVar52 + uVar56) - uVar44) * 0x90 + uVar37),
                 (undefined1 *)((longlong)puVar66 + 0x100),0x90);
          puVar8[3] = puVar8[3] + 1;
        }
      }
    }
  }
  else if (uVar37 == 4) {
    if ((int)*plVar75 == 0x474e4950) {
      *(undefined1 *)((longlong)puVar66 + 0x204) =
           *(undefined1 *)(*(undefined4 **)((longlong)puVar66 + 0x68) + 1);
      *(undefined4 *)((longlong)puVar66 + 0x200) = **(undefined4 **)((longlong)puVar66 + 0x68);
      *(undefined1 *)((longlong)puVar66 + 0x104) = *(undefined1 *)((longlong)puVar66 + 0xf4);
      *(undefined4 *)((longlong)puVar66 + 0x100) = *(undefined4 *)((longlong)puVar66 + 0xf0);
      uVar74 = 4;
      *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f77da;
      puVar43 = (undefined4 *)thunk_FUN_142351260(4,1);
      if (puVar43 == (undefined4 *)0x0) goto LAB_1402f97f8;
      lVar72 = *(longlong *)((longlong)puVar66 + 0x60);
      *puVar43 = 0x474e4f50;
      uVar74 = *(undefined8 *)((longlong)puVar66 + 0xc0);
      uVar54 = *(undefined8 *)((longlong)puVar66 + 200);
      *(undefined4 *)((longlong)puVar66 + 0x1a0) = *(undefined4 *)((longlong)puVar66 + 0x200);
      *(undefined1 *)((longlong)puVar66 + 0x1a4) = *(undefined1 *)((longlong)puVar66 + 0x204);
      *(undefined4 *)((longlong)puVar66 + 0x70) = *(undefined4 *)((longlong)puVar66 + 0x100);
      *(undefined1 *)((longlong)puVar66 + 0x74) = *(undefined1 *)((longlong)puVar66 + 0x104);
      if ((*(char *)(lVar72 + 0x7a) != '\x02') &&
         (uVar37 = *(ulonglong *)(lVar72 + 0x58), uVar37 != 0)) {
        *(undefined8 *)((longlong)puVar66 + 0x48) = uVar54;
        uVar54 = *(undefined8 *)(lVar72 + 0x60);
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7865;
        FUN_1408192a0(uVar54,uVar37,~uVar37 >> 0x3f);
        uVar54 = *(undefined8 *)((longlong)puVar66 + 0x48);
      }
      *(undefined8 *)(lVar72 + 0x40) = uVar74;
      *(undefined8 *)(lVar72 + 0x48) = uVar54;
      *(undefined8 *)(lVar72 + 0x50) = 8;
      *(undefined8 *)(lVar72 + 0x58) = 4;
      *(undefined4 **)(lVar72 + 0x60) = puVar43;
      *(undefined8 *)(lVar72 + 0x68) = 4;
      *(undefined1 *)(lVar72 + 0x74) = *(undefined1 *)((longlong)puVar66 + 0x1a4);
      *(undefined4 *)(lVar72 + 0x70) = *(undefined4 *)((longlong)puVar66 + 0x1a0);
      *(undefined1 *)(lVar72 + 0x79) = *(undefined1 *)((longlong)puVar66 + 0x74);
      *(undefined4 *)(lVar72 + 0x75) = *(undefined4 *)((longlong)puVar66 + 0x70);
      *(undefined2 *)(lVar72 + 0x7a) = 1;
      *(undefined1 *)(lVar72 + 0x7c) = 0;
      goto LAB_1402f7c00;
    }
  }
  else {
LAB_1402f7c08:
    if (6 < uVar37) goto LAB_1402f7c12;
  }
  puVar45 = *(undefined8 **)((longlong)puVar66 + 0x430);
  uVar74 = *puVar45;
  uVar54 = puVar45[1];
  uVar4 = *(undefined4 *)(puVar45 + 2);
  uVar5 = *(undefined4 *)((longlong)puVar45 + 0x14);
  *(undefined4 *)((longlong)puVar66 + 0x30) = uVar5;
  *(undefined4 *)((longlong)puVar66 + 0x28) = uVar4;
  *(undefined4 *)((longlong)puVar66 + 0x20) = *(undefined4 *)((longlong)puVar66 + 0x78);
  *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7da8;
  FUN_1400af880((undefined1 *)((longlong)puVar66 + 0x200),uVar54,uVar74,
                *(undefined4 *)((longlong)puVar66 + 0x7c));
  if (((*(int *)((longlong)puVar66 + 0x200) == 0) &&
      (**(char **)((longlong)puVar66 + 0x208) == '\x05')) &&
     (*(longlong *)((longlong)puVar66 + 0xe8) == 0x19)) {
    pcVar78 = *(char **)((longlong)puVar66 + 0xe0);
    auVar90[0] = -(*pcVar78 == 'L');
    auVar90[1] = -(pcVar78[1] == 'A');
    auVar90[2] = -(pcVar78[2] == 'W');
    auVar90[3] = -(pcVar78[3] == ' ');
    auVar90[4] = -(pcVar78[4] == 'E');
    auVar90[5] = -(pcVar78[5] == 'N');
    auVar90[6] = -(pcVar78[6] == 'F');
    auVar90[7] = -(pcVar78[7] == 'O');
    auVar90[8] = -(pcVar78[8] == 'R');
    auVar90[9] = -(pcVar78[9] == 'C');
    auVar90[10] = -(pcVar78[10] == 'E');
    auVar90[0xb] = -(pcVar78[0xb] == 'M');
    auVar90[0xc] = -(pcVar78[0xc] == 'E');
    auVar90[0xd] = -(pcVar78[0xd] == 'N');
    auVar90[0xe] = -(pcVar78[0xe] == 'T');
    auVar90[0xf] = -(pcVar78[0xf] == ' ');
    auVar97[0] = -(pcVar78[9] == 'C');
    auVar97[1] = -(pcVar78[10] == 'E');
    auVar97[2] = -(pcVar78[0xb] == 'M');
    auVar97[3] = -(pcVar78[0xc] == 'E');
    auVar97[4] = -(pcVar78[0xd] == 'N');
    auVar97[5] = -(pcVar78[0xe] == 'T');
    auVar97[6] = -(pcVar78[0xf] == ' ');
    auVar97[7] = -(pcVar78[0x10] == 'O');
    auVar97[8] = -(pcVar78[0x11] == 'P');
    auVar97[9] = -(pcVar78[0x12] == 'E');
    auVar97[10] = -(pcVar78[0x13] == 'R');
    auVar97[0xb] = -(pcVar78[0x14] == 'A');
    auVar97[0xc] = -(pcVar78[0x15] == 'T');
    auVar97[0xd] = -(pcVar78[0x16] == 'I');
    auVar97[0xe] = -(pcVar78[0x17] == 'O');
    auVar97[0xf] = -(pcVar78[0x18] == 'N');
    auVar97 = auVar97 & auVar90;
    if ((ushort)((ushort)(SUB161(auVar97 >> 7,0) & 1) | (ushort)(SUB161(auVar97 >> 0xf,0) & 1) << 1
                 | (ushort)(SUB161(auVar97 >> 0x17,0) & 1) << 2 |
                 (ushort)(SUB161(auVar97 >> 0x1f,0) & 1) << 3 |
                 (ushort)(SUB161(auVar97 >> 0x27,0) & 1) << 4 |
                 (ushort)(SUB161(auVar97 >> 0x2f,0) & 1) << 5 |
                 (ushort)(SUB161(auVar97 >> 0x37,0) & 1) << 6 |
                 (ushort)(SUB161(auVar97 >> 0x3f,0) & 1) << 7 |
                 (ushort)(SUB161(auVar97 >> 0x47,0) & 1) << 8 |
                 (ushort)(SUB161(auVar97 >> 0x4f,0) & 1) << 9 |
                 (ushort)(SUB161(auVar97 >> 0x57,0) & 1) << 10 |
                 (ushort)(SUB161(auVar97 >> 0x5f,0) & 1) << 0xb |
                 (ushort)(SUB161(auVar97 >> 0x67,0) & 1) << 0xc |
                 (ushort)(SUB161(auVar97 >> 0x6f,0) & 1) << 0xd |
                 (ushort)(SUB161(auVar97 >> 0x77,0) & 1) << 0xe |
                (ushort)(byte)(auVar97[0xf] >> 7) << 0xf) == 0xffff) {
      *(undefined ***)((longlong)puVar66 + 0x20) = &PTR_s_src_net_endpoint_rs_142424510;
      *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f80da;
      FUN_142244e00((undefined1 *)((longlong)puVar66 + 0x100),
                    (undefined1 *)((longlong)puVar66 + 0x1e0),
                    *(undefined4 *)((longlong)puVar66 + 0x7c),
                    *(undefined4 *)((longlong)puVar66 + 0x78));
      *(undefined4 *)((longlong)puVar66 + 0x80) = *(undefined4 *)((longlong)puVar66 + 0x100);
      *(undefined4 *)((longlong)puVar66 + 400) = *(undefined4 *)((longlong)puVar66 + 0x104);
      *(longlong **)((longlong)puVar66 + 0x310) = *(longlong **)((longlong)puVar66 + 0x108);
      plVar75 = (longlong *)**(longlong **)((longlong)puVar66 + 0x108);
      *(longlong *)((longlong)puVar66 + 0x48) = plVar75[2];
      lVar72 = plVar75[5];
      lVar62 = plVar75[3];
      *(longlong **)((longlong)puVar66 + 0x58) = plVar75;
      if (lVar72 == lVar62) {
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f812a;
        FUN_14079f6c0(plVar75 + 3);
        plVar75 = *(longlong **)((longlong)puVar66 + 0x58);
        lVar72 = plVar75[5];
      }
      lVar62 = plVar75[4];
      *(undefined8 *)(lVar62 + lVar72 * 0x10) = *(undefined8 *)((longlong)puVar66 + 0x48);
      *(code **)(lVar62 + 8 + lVar72 * 0x10) = FUN_1406929e0;
      plVar75[5] = plVar75[5] + 1;
      lVar72 = plVar75[2];
      if ((ulonglong)(*plVar75 - lVar72) < 0xc) {
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8174;
        FUN_1407a1510(*(undefined8 *)((longlong)puVar66 + 0x58),lVar72,0xc);
      }
      lVar72 = *(longlong *)((longlong)puVar66 + 0x58);
      lVar62 = *(longlong *)(lVar72 + 8);
      lVar2 = *(longlong *)((longlong)puVar66 + 0x48);
      *(undefined4 *)(lVar62 + lVar2) = *(undefined4 *)((longlong)puVar66 + 0x80);
      *(undefined4 *)(lVar62 + 4 + lVar2) = *(undefined4 *)((longlong)puVar66 + 400);
      *(undefined1 *)(lVar62 + 8 + lVar2) = 10;
      *(longlong *)(lVar72 + 0x10) = lVar2 + 0xc;
      plVar75 = (longlong *)**(longlong **)((longlong)puVar66 + 0x310);
      *(longlong *)((longlong)puVar66 + 0x58) = plVar75[2];
      lVar72 = plVar75[5];
      lVar62 = plVar75[3];
      *(longlong **)((longlong)puVar66 + 0x48) = plVar75;
      if (lVar72 == lVar62) {
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f81d0;
        FUN_14079f6c0(plVar75 + 3);
        plVar75 = *(longlong **)((longlong)puVar66 + 0x48);
        lVar72 = plVar75[5];
      }
      lVar62 = plVar75[4];
      *(undefined8 *)(lVar62 + lVar72 * 0x10) = *(undefined8 *)((longlong)puVar66 + 0x58);
      *(code **)(lVar62 + 8 + lVar72 * 0x10) = FUN_14068ac80;
      plVar75[5] = plVar75[5] + 1;
      lVar72 = plVar75[2];
      if ((ulonglong)(*plVar75 - lVar72) < 0xc) {
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f821a;
        FUN_1407a1510(*(undefined8 *)((longlong)puVar66 + 0x48),lVar72,0xc);
      }
      lVar72 = *(longlong *)((longlong)puVar66 + 0x48);
      lVar62 = *(longlong *)(lVar72 + 8);
      lVar2 = *(longlong *)((longlong)puVar66 + 0x58);
      *(undefined4 *)(lVar62 + lVar2) = *(undefined4 *)((longlong)puVar66 + 0x80);
      *(undefined4 *)(lVar62 + 4 + lVar2) = *(undefined4 *)((longlong)puVar66 + 400);
      *(undefined4 *)(lVar62 + 8 + lVar2) = 0;
      *(longlong *)(lVar72 + 0x10) = lVar2 + 0xc;
    }
  }
  if (*(char *)((longlong)puVar66 + 0xfc) != '\0') {
    *(undefined4 *)((longlong)puVar66 + 0x30) = uVar5;
    *(undefined4 *)((longlong)puVar66 + 0x28) = uVar4;
    *(undefined4 *)((longlong)puVar66 + 0x20) = *(undefined4 *)((longlong)puVar66 + 0x78);
    *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7ded;
    FUN_1400af880((undefined1 *)((longlong)puVar66 + 0x100),uVar54,uVar74,
                  *(undefined4 *)((longlong)puVar66 + 0x7c));
    if (*(int *)((longlong)puVar66 + 0x100) != 0) {
      *(undefined1 *)((longlong)puVar66 + 0x104) = 0;
      *(undefined4 *)((longlong)puVar66 + 0x100) = 0x3020101;
      if ((4 < **(byte **)((longlong)puVar66 + 0x68)) ||
         (**(byte **)((longlong)puVar66 + 0x68) == 1)) {
        lVar72 = *(longlong *)((longlong)puVar66 + 0x68);
        if (*(byte *)(lVar72 + 3) < 2) {
          if (*(char *)(lVar72 + 2) == '\x03') goto LAB_1402f7f51;
        }
        else {
          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8b0e;
          FUN_1406b6550(lVar72,(undefined1 *)((longlong)puVar66 + 0x100));
        }
      }
      *(undefined ***)((longlong)puVar66 + 0x20) = &PTR_s_src_net_endpoint_rs_142424528;
      *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7e53;
      FUN_142244e00((undefined1 *)((longlong)puVar66 + 0x100),
                    (undefined1 *)((longlong)puVar66 + 0x1e0),
                    *(undefined4 *)((longlong)puVar66 + 0x7c),
                    *(undefined4 *)((longlong)puVar66 + 0x78));
      plVar60 = *(longlong **)((longlong)puVar66 + 0x108);
      uVar4 = *(undefined4 *)((longlong)puVar66 + 0x100);
      uVar5 = *(undefined4 *)((longlong)puVar66 + 0x104);
      plVar75 = (longlong *)*plVar60;
      lVar72 = plVar75[2];
      lVar62 = plVar75[5];
      if (lVar62 == plVar75[3]) {
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7e85;
        FUN_14079f6c0(plVar75 + 3);
        lVar62 = plVar75[5];
      }
      lVar2 = plVar75[4];
      *(longlong *)(lVar2 + lVar62 * 0x10) = lVar72;
      *(code **)(lVar2 + 8 + lVar62 * 0x10) = FUN_1406929e0;
      plVar75[5] = plVar75[5] + 1;
      lVar62 = plVar75[2];
      if ((ulonglong)(*plVar75 - lVar62) < 0xc) {
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7ec3;
        FUN_1407a1510(plVar75,lVar62,0xc);
      }
      lVar62 = plVar75[1];
      *(undefined4 *)(lVar62 + lVar72) = uVar4;
      *(undefined4 *)(lVar62 + 4 + lVar72) = uVar5;
      *(undefined1 *)(lVar62 + 8 + lVar72) = 4;
      plVar75[2] = lVar72 + 0xc;
      plVar60 = (longlong *)*plVar60;
      lVar72 = plVar60[2];
      lVar62 = plVar60[5];
      if (lVar62 == plVar60[3]) {
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7ef7;
        FUN_14079f6c0(plVar60 + 3);
        lVar62 = plVar60[5];
      }
      lVar2 = plVar60[4];
      *(longlong *)(lVar2 + lVar62 * 0x10) = lVar72;
      *(code **)(lVar2 + 8 + lVar62 * 0x10) = FUN_14068ac80;
      plVar60[5] = plVar60[5] + 1;
      lVar62 = plVar60[2];
      if ((ulonglong)(*plVar60 - lVar62) < 0xc) {
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7f35;
        FUN_1407a1510(plVar60,lVar62,0xc);
      }
      lVar62 = plVar60[1];
      *(undefined4 *)(lVar62 + lVar72) = uVar4;
      *(undefined4 *)(lVar62 + 4 + lVar72) = uVar5;
      *(undefined4 *)(lVar62 + 8 + lVar72) = 0;
      plVar60[2] = lVar72 + 0xc;
    }
  }
LAB_1402f7f51:
  if (*(char *)(*(longlong *)((longlong)puVar66 + 0x90) + 0x1c4) == '\t') {
    *(undefined1 *)((longlong)puVar66 + 0x204) = 0;
    *(undefined4 *)((longlong)puVar66 + 0x200) = 0x1010101;
    if (*(longlong *)(*(longlong *)((longlong)puVar66 + 0x90) + 0x50) != 0) {
      *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f7f9d;
      uVar52 = FUN_140765640(*(longlong *)((longlong)puVar66 + 0x90) + 0x60,
                             (undefined1 *)((longlong)puVar66 + 0x200));
      uVar37 = *(ulonglong *)(*(longlong *)((longlong)puVar66 + 0x90) + 0x40);
      lVar62 = *(longlong *)(*(longlong *)((longlong)puVar66 + 0x90) + 0x58);
      bVar33 = (byte)(uVar52 >> 0x39);
      auVar90 = ZEXT216(CONCAT11(bVar33,bVar33));
      auVar90 = pshuflw(auVar90,auVar90,0);
      uVar89 = auVar90._0_4_;
      lVar72 = lVar62 + -0x38;
      *(undefined8 *)((longlong)puVar66 + 0x48) = 0;
      *(longlong *)((longlong)puVar66 + 0x58) = lVar62;
      while( true ) {
        uVar52 = uVar52 & uVar37;
        pcVar78 = (char *)(lVar62 + uVar52);
        cVar31 = *pcVar78;
        cVar99 = pcVar78[1];
        cVar100 = pcVar78[2];
        cVar101 = pcVar78[3];
        cVar19 = pcVar78[4];
        cVar20 = pcVar78[5];
        cVar21 = pcVar78[6];
        cVar22 = pcVar78[7];
        cVar23 = pcVar78[8];
        cVar24 = pcVar78[9];
        cVar25 = pcVar78[10];
        cVar26 = pcVar78[0xb];
        cVar27 = pcVar78[0xc];
        cVar28 = pcVar78[0xd];
        cVar29 = pcVar78[0xe];
        cVar30 = pcVar78[0xf];
        cVar32 = auVar90[0];
        auVar92[0] = -(cVar32 == cVar31);
        cVar93 = auVar90[1];
        auVar92[1] = -(cVar93 == cVar99);
        cVar94 = auVar90[2];
        auVar92[2] = -(cVar94 == cVar100);
        cVar95 = auVar90[3];
        auVar92[3] = -(cVar95 == cVar101);
        auVar92[4] = -(cVar32 == cVar19);
        auVar92[5] = -(cVar93 == cVar20);
        auVar92[6] = -(cVar94 == cVar21);
        auVar92[7] = -(cVar95 == cVar22);
        auVar92[8] = -(cVar32 == cVar23);
        auVar92[9] = -(cVar93 == cVar24);
        auVar92[10] = -(cVar94 == cVar25);
        auVar92[0xb] = -(cVar95 == cVar26);
        auVar92[0xc] = -(cVar32 == cVar27);
        auVar92[0xd] = -(cVar93 == cVar28);
        auVar92[0xe] = -(cVar94 == cVar29);
        auVar92[0xf] = -(cVar95 == cVar30);
        uVar59 = (ushort)(SUB161(auVar92 >> 7,0) & 1) | (ushort)(SUB161(auVar92 >> 0xf,0) & 1) << 1
                 | (ushort)(SUB161(auVar92 >> 0x17,0) & 1) << 2 |
                 (ushort)(SUB161(auVar92 >> 0x1f,0) & 1) << 3 |
                 (ushort)(SUB161(auVar92 >> 0x27,0) & 1) << 4 |
                 (ushort)(SUB161(auVar92 >> 0x2f,0) & 1) << 5 |
                 (ushort)(SUB161(auVar92 >> 0x37,0) & 1) << 6 |
                 (ushort)(SUB161(auVar92 >> 0x3f,0) & 1) << 7 |
                 (ushort)(SUB161(auVar92 >> 0x47,0) & 1) << 8 |
                 (ushort)(SUB161(auVar92 >> 0x4f,0) & 1) << 9 |
                 (ushort)(SUB161(auVar92 >> 0x57,0) & 1) << 10 |
                 (ushort)(SUB161(auVar92 >> 0x5f,0) & 1) << 0xb |
                 (ushort)(SUB161(auVar92 >> 0x67,0) & 1) << 0xc |
                 (ushort)(SUB161(auVar92 >> 0x6f,0) & 1) << 0xd |
                 (ushort)(SUB161(auVar92 >> 0x77,0) & 1) << 0xe | (ushort)(auVar92[0xf] >> 7) << 0xf
        ;
        while (uVar102 = uVar89, uVar59 != 0) {
          uVar12 = 0;
          if (uVar59 != 0) {
            for (; (uVar59 >> uVar12 & 1) == 0; uVar12 = uVar12 + 1) {
            }
          }
          lVar62 = (uVar12 + uVar52 & uVar37) * -0x38 + lVar72;
          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f801e;
          cVar32 = FUN_1406b6550((undefined1 *)((longlong)puVar66 + 0x200),lVar62);
          uVar59 = uVar59 - 1 & uVar59;
          if (cVar32 != '\0') {
            if (3 < *(ulonglong *)(lVar62 + 0x18)) {
              plVar75 = *(longlong **)((longlong)puVar66 + 0x468);
              *(undefined4 *)(*plVar75 + 4) = *(undefined4 *)((longlong)plVar75 + 0xc);
              lVar72 = plVar75[2];
              uVar74 = *(undefined8 *)(lVar72 + 0x10);
              if (*(char *)(lVar72 + 0x48) == '\0') {
                plVar75 = (longlong *)(lVar72 + 0x28);
                lVar62 = *(longlong *)(lVar72 + 0x28);
                if (lVar62 == *(longlong *)(lVar72 + 0x18)) {
                  *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f82d1;
                  FUN_14079f6c0(lVar72 + 0x18);
                  lVar62 = *plVar75;
                }
                plVar60 = (longlong *)(lVar72 + 0x20);
              }
              else {
                plVar75 = (longlong *)(lVar72 + 0x40);
                lVar62 = *(longlong *)(lVar72 + 0x40);
                if (lVar62 == *(longlong *)(lVar72 + 0x30)) {
                  *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8293;
                  FUN_14079f6c0(lVar72 + 0x30);
                  lVar62 = *plVar75;
                }
                plVar60 = (longlong *)(lVar72 + 0x38);
              }
              lVar2 = *plVar60;
              *(undefined8 *)(lVar2 + lVar62 * 0x10) = uVar74;
              *(undefined1 *)(lVar2 + 8 + lVar62 * 0x10) = 1;
              *plVar75 = *plVar75 + 1;
              *(longlong *)(lVar72 + 0x10) = *(longlong *)(lVar72 + 0x10) + 1;
              *(undefined4 *)(*(longlong *)((longlong)puVar66 + 0x290) + 4) =
                   *(undefined4 *)((longlong)puVar66 + 0x19c);
              if (*(char *)(*(longlong *)((longlong)puVar66 + 0x90) + 0x1c4) != '\n') {
                *(undefined1 *)(*(longlong *)((longlong)puVar66 + 0x90) + 0x1c4) = 10;
                *(undefined2 *)((longlong)puVar66 + 0x1a0) = 0x14;
                *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8344;
                FUN_1405211a0((undefined1 *)((longlong)puVar66 + 0x108),
                              (undefined1 *)((longlong)puVar66 + 0x1a0));
                *(undefined2 *)((longlong)puVar66 + 0x100) = 0x14;
                puVar8 = *(ulonglong **)((longlong)puVar66 + 0x90);
                uVar37 = *puVar8;
                uVar52 = puVar8[3];
                if (uVar52 == uVar37) {
                  *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8372;
                  FUN_140293030(puVar8);
                  uVar37 = *puVar8;
                  uVar52 = puVar8[3];
                }
                uVar56 = puVar8[2];
                uVar44 = 0;
                if (uVar37 <= uVar52 + uVar56) {
                  uVar44 = uVar37;
                }
                uVar37 = puVar8[1];
                *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f83a6;
                memcpy((void *)(((uVar52 + uVar56) - uVar44) * 0x90 + uVar37),
                       (undefined1 *)((longlong)puVar66 + 0x100),0x90);
                puVar8[3] = puVar8[3] + 1;
              }
            }
            goto LAB_1402f83b0;
          }
        }
        auVar104[0] = -(cVar31 == cVar105);
        auVar104[1] = -(cVar99 == cVar106);
        auVar104[2] = -(cVar100 == cVar107);
        auVar104[3] = -(cVar101 == cVar108);
        auVar104[4] = -(cVar19 == cVar109);
        auVar104[5] = -(cVar20 == cVar110);
        auVar104[6] = -(cVar21 == cVar111);
        auVar104[7] = -(cVar22 == cVar112);
        auVar104[8] = -(cVar23 == cVar113);
        auVar104[9] = -(cVar24 == cVar114);
        auVar104[10] = -(cVar25 == cVar115);
        auVar104[0xb] = -(cVar26 == cVar116);
        auVar104[0xc] = -(cVar27 == cVar117);
        auVar104[0xd] = -(cVar28 == cVar118);
        auVar104[0xe] = -(cVar29 == cVar119);
        auVar104[0xf] = -(cVar30 == cVar120);
        if ((((((((((((((((SUB161(auVar104 >> 7,0) & 1) != 0 || (SUB161(auVar104 >> 0xf,0) & 1) != 0
                         ) || (SUB161(auVar104 >> 0x17,0) & 1) != 0) ||
                       (SUB161(auVar104 >> 0x1f,0) & 1) != 0) ||
                      (SUB161(auVar104 >> 0x27,0) & 1) != 0) ||
                     (SUB161(auVar104 >> 0x2f,0) & 1) != 0) || (SUB161(auVar104 >> 0x37,0) & 1) != 0
                    ) || (SUB161(auVar104 >> 0x3f,0) & 1) != 0) ||
                  (SUB161(auVar104 >> 0x47,0) & 1) != 0) || (SUB161(auVar104 >> 0x4f,0) & 1) != 0)
                || (SUB161(auVar104 >> 0x57,0) & 1) != 0) || (SUB161(auVar104 >> 0x5f,0) & 1) != 0)
              || (SUB161(auVar104 >> 0x67,0) & 1) != 0) || (SUB161(auVar104 >> 0x6f,0) & 1) != 0) ||
            (SUB161(auVar104 >> 0x77,0) & 1) != 0) || auVar104[0xf] < '\0') break;
        uVar52 = uVar52 + *(longlong *)((longlong)puVar66 + 0x48) + 0x10;
        *(longlong *)((longlong)puVar66 + 0x48) = *(longlong *)((longlong)puVar66 + 0x48) + 0x10;
        lVar62 = *(longlong *)((longlong)puVar66 + 0x58);
      }
    }
  }
LAB_1402f83b0:
  puVar73 = (uint *)((longlong)puVar66 + 0x100);
  if (*(char *)((longlong)puVar66 + 0xfc) != '\0') {
    *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f83d8;
    cVar31 = FUN_1406b6550((undefined1 *)((longlong)puVar66 + 0xf5),
                           *(undefined8 *)((longlong)puVar66 + 0x68));
    puVar73 = (uint *)((longlong)puVar66 + 0x100);
    if (((cVar31 == '\0') &&
        ((*(char *)(*(longlong *)((longlong)puVar66 + 0x68) + 2) == '\x03' ||
         (*(char *)(*(longlong *)((longlong)puVar66 + 0x68) + 2) == '\0')))) &&
       ((*(char *)(*(longlong *)((longlong)puVar66 + 0x68) + 3) == '\x03' ||
        (*(char *)(*(longlong *)((longlong)puVar66 + 0x68) + 3) == '\0')))) {
      *(undefined ***)((longlong)puVar66 + 0x20) = &PTR_s_src_net_endpoint_rs_142424540;
      *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f843a;
      FUN_142244e00(puVar73,(undefined1 *)((longlong)puVar66 + 0x1e0),
                    *(undefined4 *)((longlong)puVar66 + 0x7c),
                    *(undefined4 *)((longlong)puVar66 + 0x78));
      uVar74 = *(undefined8 *)(*(longlong *)((longlong)puVar66 + 0x440) + 0x10);
      *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8453;
      iVar82 = FUN_1406b6820((undefined1 *)((longlong)puVar66 + 0xc0),uVar74);
      uVar89 = *(undefined4 *)((longlong)puVar66 + 0x100);
      uVar102 = *(undefined4 *)((longlong)puVar66 + 0x104);
      plVar75 = (longlong *)**(longlong **)((longlong)puVar66 + 0x108);
      lVar72 = plVar75[2];
      lVar62 = plVar75[5];
      if (lVar62 == plVar75[3]) {
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8480;
        FUN_14079f6c0(plVar75 + 3);
        lVar62 = plVar75[5];
      }
      lVar2 = plVar75[4];
      *(longlong *)(lVar2 + lVar62 * 0x10) = lVar72;
      *(code **)(lVar2 + 8 + lVar62 * 0x10) = FUN_140694340;
      plVar75[5] = plVar75[5] + 1;
      lVar62 = plVar75[2];
      if ((ulonglong)(*plVar75 - lVar62) < 0x10) {
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f84be;
        FUN_1407a1510(plVar75,lVar62,0x10);
      }
      lVar62 = plVar75[1];
      puVar43 = (undefined4 *)(lVar62 + lVar72);
      *puVar43 = uVar89;
      puVar43[1] = uVar102;
      *(longlong *)(lVar62 + 8 + lVar72) = (longlong)iVar82;
      plVar75[2] = lVar72 + 0x10;
      *(undefined1 *)((longlong)puVar66 + 0x204) =
           *(undefined1 *)(*(undefined4 **)((longlong)puVar66 + 0x68) + 1);
      *(undefined4 *)((longlong)puVar66 + 0x200) = **(undefined4 **)((longlong)puVar66 + 0x68);
      *(undefined1 *)((longlong)puVar66 + 0x104) = *(undefined1 *)((longlong)puVar66 + 0xf4);
      *(undefined4 *)((longlong)puVar66 + 0x100) = *(undefined4 *)((longlong)puVar66 + 0xf0);
      uVar74 = 0x19;
      *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8520;
      puVar80 = (uint *)thunk_FUN_142351260(0x19,1);
      if (puVar80 == (uint *)0x0) {
LAB_1402f97f8:
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f9805;
        FUN_14239ef70(uVar74,1);
        goto LAB_1402f986f;
      }
      pbVar1 = (byte *)((longlong)puVar80 + 9);
      pbVar1[0] = 'C';
      pbVar1[1] = 'E';
      pbVar1[2] = 'M';
      pbVar1[3] = 'E';
      pbVar1[4] = 'N';
      pbVar1[5] = 'T';
      pbVar1[6] = ' ';
      pbVar1[7] = 'O';
      pbVar1 = (byte *)((longlong)puVar80 + 0x11);
      pbVar1[0] = 'P';
      pbVar1[1] = 'E';
      pbVar1[2] = 'R';
      pbVar1[3] = 'A';
      pbVar1[4] = 'T';
      pbVar1[5] = 'I';
      pbVar1[6] = 'O';
      pbVar1[7] = 'N';
      *(undefined8 *)puVar80 = 0x4f464e452057414c;
      puVar80[2] = 0x4d454352;
      puVar80[3] = 0x20544e45;
      puVar39 = *(uint **)((longlong)puVar66 + 0xc0);
      puVar61 = *(uint **)((longlong)puVar66 + 200);
      *(undefined4 *)((longlong)puVar66 + 0x1a0) = *(undefined4 *)((longlong)puVar66 + 0x200);
      *(undefined1 *)((longlong)puVar66 + 0x1a4) = *(undefined1 *)((longlong)puVar66 + 0x204);
      *(undefined4 *)((longlong)puVar66 + 0x70) = *(undefined4 *)((longlong)puVar66 + 0x100);
      *(undefined1 *)((longlong)puVar66 + 0x74) = *(undefined1 *)((longlong)puVar66 + 0x104);
      puVar57 = *(uint **)((longlong)puVar66 + 0x60);
      puVar73 = (uint *)((longlong)puVar66 + 0x100);
      if ((*(byte *)((longlong)puVar57 + 0x7a) != 2) &&
         (uVar37 = *(ulonglong *)(puVar57 + 0x16), uVar37 != 0)) {
        uVar74 = *(undefined8 *)(puVar57 + 0x18);
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f85b6;
        FUN_1408192a0(uVar74,uVar37,~uVar37 >> 0x3f);
      }
LAB_1402f85b6:
      *(uint **)(puVar57 + 0x10) = puVar39;
      *(uint **)(puVar57 + 0x12) = puVar61;
      puVar57[0x14] = 8;
      puVar57[0x15] = 0;
      puVar57[0x16] = 0x19;
      puVar57[0x17] = 0;
      *(uint **)(puVar57 + 0x18) = puVar80;
      puVar57[0x1a] = 0x19;
      puVar57[0x1b] = 0;
      puVar57[0x1c] = *(uint *)((longlong)puVar66 + 0x1a0);
      *(byte *)(puVar57 + 0x1d) = *(byte *)((longlong)puVar66 + 0x1a4);
      *(undefined4 *)((longlong)puVar57 + 0x75) = *(undefined4 *)((longlong)puVar66 + 0x70);
      *(byte *)((longlong)puVar57 + 0x79) = *(byte *)((longlong)puVar66 + 0x74);
      ((byte *)((longlong)puVar57 + 0x7a))[0] = 0;
      ((byte *)((longlong)puVar57 + 0x7a))[1] = 0;
      *(byte *)(puVar57 + 0x1f) = 0;
    }
  }
LAB_1402f8600:
  *(undefined1 *)((longlong)puVar66 + 0x104) = 0;
  *(undefined4 *)((longlong)puVar66 + 0x100) = 0x3020101;
  switch(**(undefined1 **)((longlong)puVar66 + 0x68)) {
  case 0:
  case 4:
    if (*(byte *)(*(longlong *)((longlong)puVar66 + 0x68) + 2) < 2) {
      puVar38 = (uint *)(ulonglong)
                        *(byte *)(*(longlong *)(*(longlong *)((longlong)puVar66 + 0x440) + 0x10) +
                                 0x1c5);
      puVar80 = puVar38;
code_r0x0001402f865a:
      if (puVar80 == (uint *)0x0) {
LAB_1402f89ee:
        *(undefined1 *)((longlong)puVar66 + 0x104) = 0;
        *(undefined4 *)((longlong)puVar66 + 0x100) = 0x3020104;
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8a11;
        cVar31 = FUN_1406b6550((undefined1 *)((longlong)puVar66 + 0xf0),puVar73);
        if (cVar31 == '\0') break;
code_r0x0001402f8a19:
        puVar53 = (uint *)((longlong)puVar66 + 0xf5);
code_r0x0001402f8a21:
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8a2b;
        cVar31 = FUN_1406b6550(puVar53,*(undefined8 *)((longlong)puVar66 + 0x68));
        if (cVar31 == '\0') break;
code_r0x0001402f8a33:
        plVar75 = *(longlong **)((longlong)puVar66 + 0x458);
        *(undefined4 *)(*plVar75 + 4) = *(undefined4 *)((longlong)plVar75 + 0xc);
        puVar80 = (uint *)plVar75[2];
        _Src = *(uint **)(puVar80 + 4);
        if ((byte)puVar80[0x12] == 0) {
          puVar61 = puVar80 + 10;
          puVar57 = *(uint **)(puVar80 + 10);
          if (puVar57 != *(uint **)(puVar80 + 6)) goto LAB_1402f8b5d;
          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8b5a;
          FUN_14079f290(puVar80 + 6);
          goto LAB_1402f8b5a;
        }
        puVar61 = puVar80 + 0x10;
        puVar57 = *(uint **)(puVar80 + 0x10);
        if (puVar57 != *(uint **)(puVar80 + 0xc)) goto LAB_1402f8ae2;
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8a6d;
        FUN_14079f290(puVar80 + 0xc);
        goto LAB_1402f8adf;
      }
      if ((int)puVar38 != 1) break;
      *(undefined1 *)((longlong)puVar66 + 0x104) = 0;
      *(undefined4 *)((longlong)puVar66 + 0x100) = 0x1020104;
      *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8691;
      cVar31 = FUN_1406b6550((undefined1 *)((longlong)puVar66 + 0xf0),
                             (undefined1 *)((longlong)puVar66 + 0x100));
      if (cVar31 == '\0') break;
      *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f86ab;
      cVar31 = FUN_1406b6550((undefined1 *)((longlong)puVar66 + 0xf5),
                             *(undefined8 *)((longlong)puVar66 + 0x68));
      if (cVar31 == '\0') break;
code_r0x0001402f86b3:
      plVar75 = *(longlong **)((longlong)puVar66 + 0x458);
      *(undefined4 *)(*plVar75 + 4) = *(undefined4 *)((longlong)plVar75 + 0xc);
      puVar80 = (uint *)plVar75[2];
      _Src = *(uint **)(puVar80 + 4);
      if ((byte)puVar80[0x12] == 0) {
        puVar61 = puVar80 + 10;
        puVar57 = *(uint **)(puVar80 + 10);
        if (puVar57 == *(uint **)(puVar80 + 6)) {
code_r0x0001402f8b38:
          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8b41;
          FUN_14079f290(puVar80 + 6);
          goto LAB_1402f8b5a;
        }
        goto LAB_1402f8b5d;
      }
      puVar61 = puVar80 + 0x10;
      puVar57 = *(uint **)(puVar80 + 0x10);
      if (puVar57 == *(uint **)(puVar80 + 0xc)) {
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f86f1;
        FUN_14079f290(puVar80 + 0xc);
switchD_1402f625c_caseD_402f86f1:
        goto LAB_1402f8adf;
      }
      goto LAB_1402f8ae2;
    }
LAB_1402f86f6:
    *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8703;
    bVar33 = FUN_1406b6550((undefined1 *)((longlong)puVar66 + 0xf5));
    if ((bVar33 & *(byte *)((longlong)puVar66 + 0xf2) < 2) != 1) break;
code_r0x0001402f8718:
    switch(*(undefined1 *)(*(longlong *)(*(longlong *)((longlong)puVar66 + 0x440) + 0x10) + 0x1c5))
    {
    case 2:
      if (1 < *(byte *)(*(longlong *)((longlong)puVar66 + 0x68) + 3)) break;
      goto LAB_1402f8aa9;
    case 3:
      bVar33 = *(byte *)(*(longlong *)((longlong)puVar66 + 0x68) + 3) & 5;
      goto joined_r0x0001402f8a91;
    case 4:
      if ((*(char *)(*(longlong *)((longlong)puVar66 + 0x68) + 3) == '\0') ||
         (*(char *)(*(longlong *)((longlong)puVar66 + 0x68) + 3) == '\x03')) goto LAB_1402f8aa9;
      break;
    case 5:
      bVar33 = *(byte *)(*(longlong *)((longlong)puVar66 + 0x68) + 3) & 3;
joined_r0x0001402f8a91:
      if (bVar33 == 0) {
LAB_1402f8aa9:
        plVar75 = *(longlong **)((longlong)puVar66 + 0x458);
        *(undefined4 *)(*plVar75 + 4) = *(undefined4 *)((longlong)plVar75 + 0xc);
        puVar80 = (uint *)plVar75[2];
        _Src = *(uint **)(puVar80 + 4);
        if ((byte)puVar80[0x12] == 0) {
          puVar61 = puVar80 + 10;
          puVar57 = *(uint **)(puVar80 + 10);
switchD_1402f6219_caseD_22:
          if (puVar57 == *(uint **)(puVar80 + 6)) {
            *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8aff;
            FUN_14079f290(puVar80 + 6);
LAB_1402f8b5a:
            puVar57 = *(uint **)puVar61;
          }
LAB_1402f8b5d:
          puVar39 = puVar80 + 8;
        }
        else {
          puVar61 = puVar80 + 0x10;
          puVar57 = *(uint **)(puVar80 + 0x10);
          if (puVar57 == *(uint **)(puVar80 + 0xc)) {
            *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8adf;
            FUN_14079f290(puVar80 + 0xc);
LAB_1402f8adf:
            puVar57 = *(uint **)puVar61;
          }
LAB_1402f8ae2:
          puVar39 = puVar80 + 0xe;
        }
        *(uint **)(*(longlong *)puVar39 + (longlong)puVar57 * 8) = _Src;
        *(longlong *)puVar61 = *(longlong *)puVar61 + 1;
switchD_1402f6219_caseD_29:
        *(longlong *)(puVar80 + 4) = *(longlong *)(puVar80 + 4) + 1;
      }
    }
    break;
  default:
    lVar72 = *(longlong *)((longlong)puVar66 + 0x68);
    if (*(byte *)(lVar72 + 3) < 2) {
      if (2 < *(byte *)(lVar72 + 2)) {
        if (*(byte *)(lVar72 + 2) != 3) goto switchD_1402f8633_caseD_3;
        if ((*(longlong *)((longlong)puVar66 + 0xe8) != 4) ||
           ((**(int **)((longlong)puVar66 + 0xe0) != 0x474e4950 &&
            (**(int **)((longlong)puVar66 + 0xe0) != 0x474e4f50)))) {
          *(undefined ***)((longlong)puVar66 + 0x20) = &PTR_s_src_net_endpoint_rs_142424560;
          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f87d5;
          FUN_142244e00((undefined1 *)((longlong)puVar66 + 0x100),
                        (undefined1 *)((longlong)puVar66 + 0x1e0),
                        *(undefined4 *)((longlong)puVar66 + 0x7c),
                        *(undefined4 *)((longlong)puVar66 + 0x78));
          uVar74 = *(undefined8 *)(*(longlong *)((longlong)puVar66 + 0x440) + 0x10);
          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f87ee;
          iVar82 = FUN_1406b6820((undefined1 *)((longlong)puVar66 + 0xc0),uVar74);
          uVar89 = *(undefined4 *)((longlong)puVar66 + 0x100);
          uVar102 = *(undefined4 *)((longlong)puVar66 + 0x104);
          puVar80 = (uint *)**(undefined8 **)((longlong)puVar66 + 0x108);
          _Src = *(uint **)(puVar80 + 4);
          lVar72 = *(longlong *)(puVar80 + 10);
          if (lVar72 == *(longlong *)(puVar80 + 6)) {
            *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f881b;
            FUN_14079f6c0(puVar80 + 6);
            lVar72 = *(longlong *)(puVar80 + 10);
          }
          lVar62 = *(longlong *)(puVar80 + 8);
          *(uint **)(lVar62 + lVar72 * 0x10) = _Src;
          *(code **)(lVar62 + 8 + lVar72 * 0x10) = FUN_140694340;
          *(longlong *)(puVar80 + 10) = *(longlong *)(puVar80 + 10) + 1;
          lVar72 = *(longlong *)(puVar80 + 4);
          if ((ulonglong)(*(longlong *)puVar80 - lVar72) < 0x10) {
            *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8859;
            FUN_1407a1510(puVar80,lVar72,0x10);
          }
          puVar38 = (uint *)((ulonglong)(longlong)iVar82 >> 1);
switchD_1402f6219_caseD_23:
          lVar72 = *(longlong *)(puVar80 + 2);
          pbVar1 = (byte *)(lVar72 + (longlong)_Src);
          *(undefined4 *)pbVar1 = uVar89;
          *(undefined4 *)(pbVar1 + 4) = uVar102;
          *(uint **)(lVar72 + 8 + (longlong)_Src) = puVar38;
          *(uint **)(puVar80 + 4) = _Src + 4;
        }
      }
    }
    else {
      *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8882;
      cVar31 = FUN_1406b6550(lVar72,puVar73);
      if (cVar31 == '\0') goto switchD_1402f8633_caseD_3;
code_r0x0001402f8886:
      if (*(longlong *)((longlong)puVar66 + 0xe8) == 7) {
code_r0x0001402f8895:
        if (*(int *)((longlong)*(int **)((longlong)puVar66 + 0xe0) + 3) == 0x676f6c61 &&
            **(int **)((longlong)puVar66 + 0xe0) == 0x61746143) {
          plVar75 = *(longlong **)((longlong)puVar66 + 0x440);
          *(undefined4 *)(*plVar75 + 4) = *(undefined4 *)((longlong)plVar75 + 0xc);
          lVar72 = plVar75[2];
          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f88da;
          FUN_14079b300(lVar72 + 0x160);
        }
      }
    }
    break;
  case 2:
    break;
  case 3:
switchD_1402f8633_caseD_3:
    puVar80 = *(uint **)(*(longlong *)((longlong)puVar66 + 0x440) + 0x10);
    if ((byte)puVar80[0x71] == 6) {
      *(undefined1 *)((longlong)puVar66 + 0x104) = 0;
      *(undefined4 *)((longlong)puVar66 + 0x100) = 0x3020101;
      if ((4 < *(byte *)((longlong)puVar66 + 0xf0)) || (*(byte *)((longlong)puVar66 + 0xf0) == 1)) {
        puVar45 = puVar66;
        if (*(byte *)((longlong)puVar66 + 0xf3) < 2) {
          if (*(byte *)((longlong)puVar66 + 0xf2) < 2) {
            lVar72 = **(longlong **)((longlong)puVar66 + 0x440);
            uVar4 = *(undefined4 *)((longlong)*(longlong **)((longlong)puVar66 + 0x440) + 0xc);
            puVar80[0x6c] = 2;
            *(undefined4 *)(lVar72 + 4) = uVar4;
            if ((byte)puVar80[0x71] != 7) {
              *(byte *)(puVar80 + 0x71) = 7;
              *(undefined2 *)((longlong)puVar66 + 0x200) = 0x10;
              *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f898b;
              FUN_1405211a0((undefined1 *)((longlong)puVar66 + 0x108),
                            (undefined1 *)((longlong)puVar66 + 0x200));
              *(undefined2 *)((longlong)puVar66 + 0x100) = 0x10;
              puVar39 = *(uint **)puVar80;
              puVar53 = *(uint **)(puVar80 + 6);
              _Src = (uint *)((longlong)puVar66 + 0x100);
              if (puVar53 == puVar39) {
                *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f89b1;
                FUN_140293030(puVar80);
                puVar39 = *(uint **)puVar80;
                puVar53 = *(uint **)(puVar80 + 6);
              }
              puVar53 = (uint *)((longlong)puVar53 + *(longlong *)(puVar80 + 4));
              puVar38 = (uint *)0x0;
              if (puVar39 <= puVar53) {
                puVar38 = puVar39;
              }
code_r0x0001402f89c8:
              lVar72 = *(longlong *)(puVar80 + 2);
              *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f89e5;
              memcpy((void *)(((longlong)puVar53 - (longlong)puVar38) * 0x90 + lVar72),_Src,0x90);
              *(longlong *)(puVar80 + 6) = *(longlong *)(puVar80 + 6) + 1;
            }
          }
        }
        else {
LAB_1402f8b13:
          *(undefined8 *)((longlong)puVar45 + -8) = 0x1402f8b28;
          FUN_1406b6550((undefined1 *)((longlong)puVar45 + 0xf0),
                        (undefined1 *)((longlong)puVar45 + 0x100));
          puVar66 = puVar45;
        }
      }
    }
  }
switchD_1402f8633_caseD_2:
  uVar37 = *(ulonglong *)((longlong)puVar66 + 0xd8);
  if (uVar37 != 0) {
    *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8b94;
    FUN_1408192a0(*(undefined8 *)((longlong)puVar66 + 0xe0),uVar37,~uVar37 >> 0x3f);
  }
  puVar39 = (uint *)((longlong)puVar66 + 0x100);
LAB_1402f8b9c:
  puVar53 = *(uint **)((longlong)puVar66 + 0x430);
switchD_1402f62f9_caseD_402f8ba7:
  puVar57 = *(uint **)(puVar53 + 2);
  uVar36 = puVar53[4];
  *(uint *)((longlong)puVar66 + 0x30) = puVar53[5];
code_r0x0001402f8bb5:
  *(uint *)((longlong)puVar66 + 0x28) = uVar36;
  *(undefined4 *)((longlong)puVar66 + 0x20) = *(undefined4 *)((longlong)puVar66 + 0x78);
  puVar53 = (uint *)((longlong)puVar66 + 0xc0);
switchD_1402f62f9_caseD_402f8bce:
  *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8bd3;
  FUN_1400af880(puVar53,puVar57);
  puVar61 = *(uint **)((longlong)puVar66 + 0x60);
  if ((*(int *)((longlong)puVar66 + 0xc0) != 0) ||
     (uVar37 = (ulonglong)**(byte **)((longlong)puVar66 + 200) - 4, 6 < uVar37))
  goto switchD_1402f8c0d_caseD_402f5be0;
code_r0x0001402f8bff:
  switch((longlong)&switchD_1402f8c0d::switchdataD_1402f9a18 +
         (longlong)(int)(&switchD_1402f8c0d::switchdataD_1402f9a18)[uVar37]) {
  case 0x1402f5be0:
    goto switchD_1402f8c0d_caseD_402f5be0;
  case 0x1402f8c0f:
    if (*(byte *)((longlong)puVar61 + 0x7a) == 2) goto switchD_1402f8c0d_caseD_402f5be0;
    *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8c27;
    cVar31 = FUN_1406b6550(puVar61 + 0x1c,*(undefined8 *)((longlong)puVar66 + 0x68));
    puVar61 = *(uint **)((longlong)puVar66 + 0x60);
    if (cVar31 == '\0') goto switchD_1402f8c0d_caseD_402f5be0;
    break;
  case 0x1402f8c36:
    if (1 < **(byte **)((longlong)puVar66 + 0x68)) goto switchD_1402f8c0d_caseD_402f5be0;
    break;
  case 0x1402f8c73:
    lVar72 = *(longlong *)((longlong)puVar66 + 0x1f0);
    uVar37 = *(ulonglong *)(lVar72 + 0x110);
    do {
      if (0x3f < uVar37) {
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8ccc;
        lVar62 = FUN_14204e720();
        if ((*(longlong *)(lVar72 + 0x158) < 1) || (*(longlong *)(lVar72 + 0x160) - lVar62 < 0)) {
          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8c9e;
          FUN_1404628b0(lVar72 + 0x120,lVar72 + 0x10);
        }
        else {
          *(longlong *)(lVar72 + 0x158) = *(longlong *)(lVar72 + 0x158) + -0x100;
          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8cff;
          FUN_14204f0e0(lVar72 + 0x120,6);
        }
        *(undefined8 *)(lVar72 + 0x110) = 0;
        uVar37 = 0;
      }
      uVar36 = *(uint *)(lVar72 + 0x10 + uVar37 * 4);
      uVar37 = uVar37 + 1;
      *(ulonglong *)(lVar72 + 0x110) = uVar37;
    } while ((uVar36 & 0x20000000) != 0);
    if ((uVar36 < 0x40000000) && (*(byte *)((longlong)puVar61 + 0x7a) == 2)) {
      *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8d26;
      puVar45 = (undefined8 *)thunk_FUN_142351260(0xe0,8);
      if (puVar45 == (undefined8 *)0x0) {
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f9816;
        FUN_14239ef70(0xe0,8);
        goto LAB_1402f986f;
      }
      *puVar45 = "Totally n0t a v1rus";
      puVar45[1] = 0x13;
      puVar45[2] = "Congrats! U won!";
      puVar45[3] = 0x10;
      puVar45[4] = "1 simple trick to get **RICH**";
      puVar45[5] = 0x1e;
      puVar45[6] = "Free credits! $$$";
      puVar45[7] = 0x11;
      puVar45[8] = "**Perfectly s4fe packet**";
      puVar45[9] = 0x19;
      puVar45[10] = "[URGENT] Open me!";
      puVar45[0xb] = 0x11;
      puVar45[0xc] = "U have been hacked!!!";
      puVar45[0xd] = 0x15;
      puVar45[0xe] = "Susan shared a document with u";
      puVar45[0xf] = 0x1e;
      puVar45[0x10] = "Re:";
      puVar45[0x11] = 3;
      puVar45[0x12] = "Hello :)";
      puVar45[0x13] = 8;
      puVar45[0x14] = "1nvoice due";
      puVar45[0x15] = 0xb;
      puVar45[0x16] = "D1rect d3posit";
      puVar45[0x17] = 0xe;
      puVar45[0x18] = "R3sponse required";
      puVar45[0x19] = 0x11;
      puVar45[0x1a] = "Employee raises!!!";
      puVar45[0x1b] = 0x12;
      uVar74 = **(undefined8 **)((longlong)puVar66 + 0x298);
      *(undefined4 *)((longlong)puVar66 + 0x108) =
           *(undefined4 *)(*(undefined8 **)((longlong)puVar66 + 0x298) + 1);
      *(undefined8 *)((longlong)puVar66 + 0x100) = uVar74;
      plVar75 = *(longlong **)((longlong)puVar66 + 0x450);
      *(undefined4 *)(*plVar75 + 4) = *(undefined4 *)((longlong)plVar75 + 0xc);
      lVar72 = plVar75[2];
      uVar74 = *(undefined8 *)(lVar72 + 0x10);
      if (*(char *)(lVar72 + 0x48) == '\0') {
        plVar75 = (longlong *)(lVar72 + 0x28);
        lVar62 = *(longlong *)(lVar72 + 0x28);
        if (lVar62 == *(longlong *)(lVar72 + 0x18)) {
          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8ed3;
          FUN_14079f430(lVar72 + 0x18);
          lVar62 = *plVar75;
        }
        plVar60 = (longlong *)(lVar72 + 0x20);
      }
      else {
        plVar75 = (longlong *)(lVar72 + 0x40);
        lVar62 = *(longlong *)(lVar72 + 0x40);
        if (lVar62 == *(longlong *)(lVar72 + 0x30)) {
          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8eb3;
          FUN_14079f430(lVar72 + 0x30);
          lVar62 = *plVar75;
        }
        plVar60 = (longlong *)(lVar72 + 0x38);
      }
      lVar2 = *plVar60;
      *(char **)(lVar2 + lVar62 * 0x28) = "beep_infected";
      *(undefined8 *)(lVar2 + 8 + lVar62 * 0x28) = 0xd;
      *(undefined8 *)(lVar2 + 0x10 + lVar62 * 0x28) = *(undefined8 *)((longlong)puVar66 + 0x100);
      *(undefined4 *)(lVar2 + 0x18 + lVar62 * 0x28) = *(undefined4 *)((longlong)puVar66 + 0x108);
      *(undefined8 *)(lVar2 + 0x20 + lVar62 * 0x28) = uVar74;
      *plVar75 = *plVar75 + 1;
      *(longlong *)(lVar72 + 0x10) = *(longlong *)(lVar72 + 0x10) + 1;
      uVar14 = **(undefined2 **)((longlong)puVar66 + 0x68);
      *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8f2b;
      bVar33 = FUN_1406b5fa0();
      *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8f32;
      bVar34 = FUN_1406b5fa0();
      if (1 < (bVar33 | bVar34)) {
        *(undefined1 *)((longlong)puVar66 + 0x1a4) =
             *(undefined1 *)(*(undefined4 **)((longlong)puVar66 + 0x68) + 1);
        *(undefined4 *)((longlong)puVar66 + 0x1a0) = **(undefined4 **)((longlong)puVar66 + 0x68);
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8f6e;
        uVar36 = FUN_140673740((undefined1 *)((longlong)puVar66 + 0x1f0),0,0xe);
        *(byte *)((longlong)puVar66 + 0x48) = bVar34;
        *(byte *)((longlong)puVar66 + 0x90) = bVar33;
        uVar37 = (ulonglong)uVar36;
        if (0xd < uVar36) {
          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f97e2;
          FUN_1423ab620(uVar37,0xe,&PTR_s__home_puzzled_squid__cargo_regis_14248cc28);
          goto LAB_1402f986f;
        }
        *(undefined8 *)((longlong)puVar66 + 0x200) = 0;
        *(undefined8 *)((longlong)puVar66 + 0x208) = 1;
        *(undefined8 *)((longlong)puVar66 + 0x210) = 0;
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8fc8;
        FUN_1423aea40((undefined1 *)((longlong)puVar66 + 0x100),
                      (undefined1 *)((longlong)puVar66 + 0x200),&PTR_LAB_14241f058);
        uVar74 = puVar45[uVar37 * 2];
        uVar54 = puVar45[uVar37 * 2 + 1];
        *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8fde;
        cVar31 = FUN_1423b0fc0(uVar74,uVar54,(undefined1 *)((longlong)puVar66 + 0x100));
        if (cVar31 != '\0') {
          *(undefined ***)((longlong)puVar66 + 0x20) =
               &PTR_s__rustc_11d96b59307b1702fffe871bf_14241f110;
          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f986f;
          FUN_1423ab9f0("a Display implementation returned an error unexpectedly",0x37,
                        (undefined1 *)((longlong)puVar66 + 0x2b0),&PTR_LAB_14241f1b8);
          goto LAB_1402f986f;
        }
        *(undefined4 *)((longlong)puVar66 + 0x2b0) = *(undefined4 *)((longlong)puVar66 + 0x1a0);
        *(undefined1 *)((longlong)puVar66 + 0x2b4) = *(undefined1 *)((longlong)puVar66 + 0x1a4);
        *(undefined8 *)((longlong)puVar66 + 0x100) = *(undefined8 *)((longlong)puVar66 + 0x200);
        *(undefined8 *)((longlong)puVar66 + 0x108) = *(undefined8 *)((longlong)puVar66 + 0x208);
        *(undefined8 *)((longlong)puVar66 + 0x110) = *(undefined8 *)((longlong)puVar66 + 0x210);
        lVar72 = *(longlong *)((longlong)puVar66 + 0x60);
        if ((*(char *)(lVar72 + 0x7a) != '\x02') &&
           (uVar37 = *(ulonglong *)(lVar72 + 0x58), uVar37 != 0)) {
          uVar74 = *(undefined8 *)(lVar72 + 0x60);
          *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f9056;
          FUN_1408192a0(uVar74,uVar37,~uVar37 >> 0x3f);
        }
        *(char **)(lVar72 + 0x40) = "a93b3b";
        *(undefined8 *)(lVar72 + 0x48) = 6;
        *(undefined8 *)(lVar72 + 0x50) = 0;
        uVar74 = *(undefined8 *)((longlong)puVar66 + 0x108);
        *(undefined8 *)(lVar72 + 0x58) = *(undefined8 *)((longlong)puVar66 + 0x100);
        *(undefined8 *)(lVar72 + 0x60) = uVar74;
        *(undefined8 *)(lVar72 + 0x68) = *(undefined8 *)((longlong)puVar66 + 0x110);
        *(undefined4 *)(lVar72 + 0x70) = *(undefined4 *)((longlong)puVar66 + 0x2b0);
        *(undefined1 *)(lVar72 + 0x74) = *(undefined1 *)((longlong)puVar66 + 0x2b4);
        *(undefined2 *)(lVar72 + 0x75) = uVar14;
        *(undefined1 *)(lVar72 + 0x77) = *(undefined1 *)((longlong)puVar66 + 0x90);
        *(undefined1 *)(lVar72 + 0x78) = *(undefined1 *)((longlong)puVar66 + 0x48);
        *(undefined4 *)(lVar72 + 0x79) = 0x1000000;
      }
      *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f90c6;
      FUN_1408192a0(puVar45,0xe0);
      puVar39 = (uint *)((longlong)puVar66 + 0x100);
      puVar61 = *(uint **)((longlong)puVar66 + 0x60);
    }
    goto switchD_1402f8c0d_caseD_402f5be0;
  }
  if ((*(byte *)((longlong)puVar61 + 0x7a) != 2) && (*(longlong *)(puVar61 + 0x16) != 0)) {
    uVar74 = *(undefined8 *)(puVar61 + 0x18);
    *(undefined8 *)((longlong)puVar66 + -8) = 0x1402f8c6e;
    FUN_1408192a0(uVar74);
  }
  *(byte *)((longlong)puVar61 + 0x7a) = 2;
switchD_1402f8c0d_caseD_402f5be0:
  puVar61 = puVar61 + 0x26;
  if (puVar61 == *(uint **)((longlong)puVar66 + 800)) {
    puVar73 = *(uint **)((longlong)puVar66 + 0x318);
    if (puVar73 != puVar11) goto LAB_1402f9657;
    goto LAB_1402f94f4;
  }
  goto LAB_1402f5bf5;
}

