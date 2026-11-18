
void FUN_140665240(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  void *_Dst;
  undefined8 uVar8;
  code *pcVar9;
  undefined4 *puVar10;
  undefined8 uVar11;
  undefined4 uVar12;
  undefined8 uVar13;
  char cVar14;
  byte bVar15;
  longlong lVar16;
  longlong lVar17;
  longlong lVar18;
  undefined8 uVar19;
  longlong lVar20;
  ulonglong *puVar21;
  ulonglong uVar22;
  undefined4 *puVar23;
  ulonglong uVar24;
  longlong *plVar25;
  undefined1 *puVar26;
  char *pcVar27;
  undefined1 *puVar28;
  longlong *plVar29;
  longlong lVar30;
  undefined8 *puVar31;
  ulonglong uVar32;
  ulonglong *puVar33;
  char *pcVar34;
  longlong lVar35;
  ulonglong uVar36;
  ulonglong *puVar37;
  undefined **ppuVar38;
  longlong *plVar39;
  longlong *plVar40;
  undefined1 uVar41;
  bool bVar42;
  undefined8 unaff_XMM6_Qa;
  undefined4 uVar43;
  undefined8 unaff_XMM6_Qb;
  undefined4 unaff_XMM7_Da;
  undefined4 unaff_XMM7_Db;
  undefined4 unaff_XMM7_Dc;
  undefined4 unaff_XMM7_Dd;
  undefined4 unaff_XMM8_Da;
  undefined4 unaff_XMM8_Db;
  undefined4 unaff_XMM8_Dc;
  undefined4 unaff_XMM8_Dd;
  undefined4 unaff_XMM9_Da;
  undefined4 unaff_XMM9_Db;
  undefined4 unaff_XMM9_Dc;
  undefined4 unaff_XMM9_Dd;
  undefined4 unaff_XMM10_Da;
  undefined4 unaff_XMM10_Db;
  undefined4 unaff_XMM10_Dc;
  undefined4 unaff_XMM10_Dd;
  undefined4 unaff_XMM11_Da;
  undefined4 unaff_XMM11_Db;
  undefined4 unaff_XMM11_Dc;
  undefined4 unaff_XMM11_Dd;
  undefined8 unaff_XMM12_Qa;
  undefined8 unaff_XMM12_Qb;
  longlong alStackX_8 [2];
  undefined4 uStackX_1c;
  longlong lStackX_20;
  undefined8 uStack_48;
  
  uStack_48 = 0x140665256;
  lVar16 = FUN_1423d0c90();
  lVar16 = -lVar16;
  *(undefined8 *)(&stack0x00010600 + lVar16) = unaff_XMM12_Qa;
  *(undefined8 *)(&stack0x00010608 + lVar16) = unaff_XMM12_Qb;
  *(undefined4 *)(&stack0x000105f0 + lVar16) = unaff_XMM11_Da;
  *(undefined4 *)(&stack0x000105f4 + lVar16) = unaff_XMM11_Db;
  *(undefined4 *)(&stack0x000105f8 + lVar16) = unaff_XMM11_Dc;
  *(undefined4 *)(&stack0x000105fc + lVar16) = unaff_XMM11_Dd;
  *(undefined4 *)(&stack0x000105e0 + lVar16) = unaff_XMM10_Da;
  *(undefined4 *)(&stack0x000105e4 + lVar16) = unaff_XMM10_Db;
  *(undefined4 *)(&stack0x000105e8 + lVar16) = unaff_XMM10_Dc;
  *(undefined4 *)(&stack0x000105ec + lVar16) = unaff_XMM10_Dd;
  *(undefined4 *)(&stack0x000105d0 + lVar16) = unaff_XMM9_Da;
  *(undefined4 *)(&stack0x000105d4 + lVar16) = unaff_XMM9_Db;
  *(undefined4 *)(&stack0x000105d8 + lVar16) = unaff_XMM9_Dc;
  *(undefined4 *)(&stack0x000105dc + lVar16) = unaff_XMM9_Dd;
  *(undefined4 *)(&stack0x000105c0 + lVar16) = unaff_XMM8_Da;
  *(undefined4 *)(&stack0x000105c4 + lVar16) = unaff_XMM8_Db;
  *(undefined4 *)(&stack0x000105c8 + lVar16) = unaff_XMM8_Dc;
  *(undefined4 *)(&stack0x000105cc + lVar16) = unaff_XMM8_Dd;
  *(undefined4 *)(&stack0x000105b0 + lVar16) = unaff_XMM7_Da;
  *(undefined4 *)(&stack0x000105b4 + lVar16) = unaff_XMM7_Db;
  *(undefined4 *)(&stack0x000105b8 + lVar16) = unaff_XMM7_Dc;
  *(undefined4 *)(&stack0x000105bc + lVar16) = unaff_XMM7_Dd;
  *(undefined8 *)(&stack0x000105a0 + lVar16) = unaff_XMM6_Qa;
  *(undefined8 *)(&stack0x000105a8 + lVar16) = unaff_XMM6_Qb;
  puVar4 = *(undefined8 **)(&stack0x00010690 + lVar16);
  puVar31 = *(undefined8 **)(&stack0x00010688 + lVar16);
  puVar5 = *(undefined8 **)(&stack0x00010680 + lVar16);
  *(undefined8 *)(&stack0x00000048 + lVar16) = *puVar5;
  *(undefined4 *)(&stack0x00000004 + lVar16) = *(undefined4 *)((longlong)puVar5 + 0xc);
  *(undefined8 *)(&stack0xfffffffffffffff8 + lVar16) = puVar5[2];
  puVar33 = (ulonglong *)**(undefined8 **)(&stack0x000106d8 + lVar16);
  puVar21 = (ulonglong *)(*(undefined8 **)(&stack0x000106d8 + lVar16))[1];
  *(undefined8 *)(&stack0x00000060 + lVar16) = param_2;
  *(undefined8 *)(&stack0x00000068 + lVar16) = param_3;
  uVar6 = *puVar33;
  uVar32 = 0;
  uVar24 = uVar6 - *puVar21;
  if (uVar6 < *puVar21) {
    uVar24 = uVar32;
  }
  uVar19 = *puVar31;
  uVar22 = uVar6 - puVar21[1];
  if (uVar6 < puVar21[1]) {
    uVar22 = uVar32;
  }
  plVar39 = (longlong *)(uVar24 * 0x18 + puVar21[4]);
  uVar6 = puVar21[5] - uVar24;
  if (puVar21[5] < uVar24) {
    plVar39 = &DAT_1424629f0;
    uVar6 = uVar32;
  }
  uVar24 = puVar21[8];
  plVar29 = (longlong *)(uVar22 * 0x18 + puVar21[7]);
  *(undefined8 *)(&stack0x00000220 + lVar16) = puVar31[1];
  if (uVar24 < uVar22) {
    plVar29 = &DAT_1424629f0;
  }
  uVar7 = puVar21[2];
  uVar36 = uVar24 - uVar22;
  if (uVar24 < uVar22) {
    uVar36 = uVar32;
  }
  *(undefined4 *)(&stack0x000000e8 + lVar16) = *(undefined4 *)(puVar31 + 2);
  *(undefined4 *)(&stack0x000000e4 + lVar16) = *(undefined4 *)((longlong)puVar31 + 0x14);
  *(undefined8 *)(&stack0x00000130 + lVar16) = *puVar4;
  *(undefined8 *)(&stack0x00000218 + lVar16) = puVar4[1];
  *(undefined4 *)(&stack0x000000e0 + lVar16) = *(undefined4 *)(puVar4 + 2);
  *(undefined4 *)(&stack0x000000dc + lVar16) = *(undefined4 *)((longlong)puVar4 + 0x14);
  puVar4 = *(undefined8 **)(&stack0x00010698 + lVar16);
  *(undefined8 *)(&stack0x00000128 + lVar16) = *puVar4;
  *(undefined8 *)(&stack0x00000210 + lVar16) = puVar4[1];
  *(undefined4 *)(&stack0x000000d8 + lVar16) = *(undefined4 *)(puVar4 + 2);
  *(undefined4 *)(&stack0x000000d4 + lVar16) = *(undefined4 *)((longlong)puVar4 + 0x14);
  puVar4 = *(undefined8 **)(&stack0x000106a0 + lVar16);
  *(undefined8 *)(&stack0x00000118 + lVar16) = *puVar4;
  *(undefined8 *)(&stack0x00000208 + lVar16) = puVar4[1];
  *(undefined4 *)(&stack0x000000d0 + lVar16) = *(undefined4 *)(puVar4 + 2);
  *(undefined4 *)(&stack0x000000cc + lVar16) = *(undefined4 *)((longlong)puVar4 + 0x14);
  puVar4 = *(undefined8 **)(&stack0x000106a8 + lVar16);
  *(undefined8 *)(&stack0x00000110 + lVar16) = *puVar4;
  *(undefined8 *)(&stack0x00000200 + lVar16) = puVar4[1];
  *(undefined4 *)(&stack0x000000c8 + lVar16) = *(undefined4 *)(puVar4 + 2);
  *(undefined4 *)(&stack0x000000c4 + lVar16) = *(undefined4 *)((longlong)puVar4 + 0x14);
  puVar4 = *(undefined8 **)(&stack0x000106b0 + lVar16);
  *(undefined8 *)(&stack0x000000a8 + lVar16) = *puVar4;
  *(undefined8 *)(&stack0x00000100 + lVar16) = puVar4[1];
  *(undefined4 *)(&stack0x000000b8 + lVar16) = *(undefined4 *)(puVar4 + 2);
  *(undefined4 *)(&stack0x00000074 + lVar16) = *(undefined4 *)((longlong)puVar4 + 0x14);
  puVar4 = *(undefined8 **)(&stack0x000106b8 + lVar16);
  *(undefined8 *)(&stack0x000001f0 + lVar16) = *puVar4;
  *(undefined4 *)(&stack0x000000b4 + lVar16) = *(undefined4 *)((longlong)puVar4 + 0xc);
  *(undefined8 *)(&stack0x000001e8 + lVar16) = puVar4[2];
  puVar4 = *(undefined8 **)(&stack0x000106c0 + lVar16);
  *(undefined8 *)(&stack0x00000050 + lVar16) = *puVar4;
  *(undefined4 *)((longlong)&uStackX_1c + lVar16) = *(undefined4 *)((longlong)puVar4 + 0xc);
  *(undefined8 *)(&stack0x00000028 + lVar16) = puVar4[2];
  puVar4 = *(undefined8 **)(&stack0x000106c8 + lVar16);
  *(undefined8 *)(&stack0x00000108 + lVar16) = *puVar4;
  *(undefined8 *)(&stack0x000001f8 + lVar16) = puVar4[1];
  *(undefined4 *)(&stack0x000000c0 + lVar16) = *(undefined4 *)(puVar4 + 2);
  *(undefined4 *)(&stack0x000000bc + lVar16) = *(undefined4 *)((longlong)puVar4 + 0x14);
  *(undefined8 *)(&stack0x00000138 + lVar16) = **(undefined8 **)(&stack0x000106d0 + lVar16);
  puVar4 = *(undefined8 **)(&stack0x000106e0 + lVar16);
  *(undefined8 *)(&stack0x000001e0 + lVar16) = *puVar4;
  *(undefined4 *)(&stack0x000000b0 + lVar16) = *(undefined4 *)((longlong)puVar4 + 0xc);
  *(undefined8 *)(&stack0x000001d8 + lVar16) = puVar4[2];
  puVar4 = *(undefined8 **)(&stack0x000106e8 + lVar16);
  *(undefined8 *)(&stack0x00000228 + lVar16) = *puVar4;
  *(undefined4 *)(&stack0x000000ec + lVar16) = *(undefined4 *)((longlong)puVar4 + 0xc);
  lVar18 = puVar4[2];
  *(ulonglong **)(&stack0x000001c8 + lVar16) = puVar33;
  *puVar33 = (uVar7 - uVar36) - uVar6;
  if ((char)puVar21[9] == '\0') {
    *(longlong **)(&stack0x000000f8 + lVar16) = plVar29 + uVar36 * 3;
    *(longlong **)(&stack0x000000f0 + lVar16) = plVar39 + uVar6 * 3;
    plVar25 = plVar39;
  }
  else {
    *(longlong **)(&stack0x000000f8 + lVar16) = plVar39 + uVar6 * 3;
    *(longlong **)(&stack0x000000f0 + lVar16) = plVar29 + uVar36 * 3;
    plVar25 = plVar29;
    plVar29 = plVar39;
  }
  lVar17 = *(longlong *)(&stack0x00000100 + lVar16);
  *(longlong *)(&stack0x000001c0 + lVar16) = *(longlong *)(&stack0x00000028 + lVar16) + 0x40;
  lVar35 = *(longlong *)(&stack0xfffffffffffffff8 + lVar16);
  *(longlong *)(&stack0x00000058 + lVar16) = lVar35 + 0x30;
  *(longlong *)(&stack0x00000040 + lVar16) = lVar35 + 0x40;
  *(longlong *)((longlong)alStackX_8 + lVar16 + 8) = lVar35 + 0x38;
  *(longlong *)(&stack0x00000030 + lVar16) = lVar35 + 0x28;
  *(longlong *)((longlong)alStackX_8 + lVar16) = lVar35 + 0x20;
  *(undefined8 *)(&stack0x00000120 + lVar16) = uVar19;
  *(longlong *)(&stack0x000001d0 + lVar16) = lVar18;
  *(longlong *)(&stack0x000000a0 + lVar16) = lVar17 + 0x50;
  *(longlong *)(&stack0x00000038 + lVar16) = lVar35 + 0x18;
LAB_140665658:
  if ((plVar29 == (longlong *)0x0) || (plVar29 == *(longlong **)(&stack0x000000f8 + lVar16))) {
    if (plVar25 == (longlong *)0x0) {
      return;
    }
    if (plVar25 == *(longlong **)(&stack0x000000f0 + lVar16)) {
      return;
    }
    plVar40 = plVar25 + 3;
    plVar39 = (longlong *)0x0;
  }
  else {
    plVar39 = plVar29 + 3;
    plVar40 = plVar25;
    plVar25 = plVar29;
  }
  uVar6 = **(ulonglong **)(&stack0x000001c8 + lVar16);
  uVar24 = plVar25[2] + 1U;
  if (plVar25[2] + 1U <= uVar6) {
    uVar24 = uVar6;
  }
  **(ulonglong **)(&stack0x000001c8 + lVar16) = uVar24;
  if (plVar25 == (longlong *)0x0) {
    return;
  }
  *(undefined4 *)(*(longlong *)(&stack0x00000228 + lVar16) + 4) =
       *(undefined4 *)(&stack0x000000ec + lVar16);
  lVar17 = *(longlong *)(lVar18 + 0x10);
  if (lVar17 != 0) {
    *(longlong **)(&stack0x00000240 + lVar16) = plVar39;
    *(longlong **)(&stack0x00000248 + lVar16) = plVar40;
    if (*(char *)(lVar17 + -1 + *(longlong *)(lVar18 + 8)) != '\0') {
      *(undefined2 *)(lVar18 + 0x18) = 0;
    }
    lVar18 = *(longlong *)(&stack0x00000220 + lVar16);
    *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665731;
    lVar17 = FUN_14221bbe0(uVar19,lVar18,*(undefined4 *)(&stack0x000000e8 + lVar16),
                           *(undefined4 *)(&stack0x000000e4 + lVar16));
    puVar21 = *(ulonglong **)(lVar18 + 0x60);
    puVar33 = puVar21 + *(longlong *)(lVar18 + 0x68);
    lVar35 = 0;
    lVar18 = 0;
    do {
      if (lVar35 == lVar18) {
        do {
          if (puVar21 == puVar33) {
            lVar18 = *(longlong *)(&stack0x00000218 + lVar16);
            *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665818;
            lVar17 = FUN_14221bbe0(*(undefined8 *)(&stack0x00000130 + lVar16),lVar18,
                                   *(undefined4 *)(&stack0x000000e0 + lVar16),
                                   *(undefined4 *)(&stack0x000000dc + lVar16));
            puVar21 = *(ulonglong **)(lVar18 + 0x60);
            puVar33 = puVar21 + *(longlong *)(lVar18 + 0x68);
            lVar35 = 0;
            lVar18 = 0;
            goto LAB_140665868;
          }
          puVar26 = (undefined1 *)*puVar21;
          puVar28 = *(undefined1 **)(*(longlong *)(&stack0x00000120 + lVar16) + 0xd8);
          if (puVar28 <= puVar26) goto LAB_14066775e;
          lVar17 = *(longlong *)(*(longlong *)(&stack0x00000120 + lVar16) + 0xd0);
          puVar21 = puVar21 + 1;
          lVar18 = *(longlong *)(lVar17 + 0x58 + (longlong)puVar26 * 0x60);
        } while (lVar18 == 0);
        lVar17 = *(longlong *)(lVar17 + 0x50 + (longlong)puVar26 * 0x60);
        lVar35 = 0;
      }
      uVar2 = *(undefined4 *)(lVar17 + lVar35 * 8);
      uVar43 = *(undefined4 *)(lVar17 + 4 + lVar35 * 8);
      lVar35 = lVar35 + 1;
      *(undefined ***)(&stack0xffffffffffffffe0 + lVar16) = &PTR_s_src_save_rs_14248fb88;
      *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665780;
      FUN_142244e00(&stack0x000005e0 + lVar16,&stack0x00000060 + lVar16,uVar2,uVar43);
      *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665788;
      FUN_141fcee80(&stack0x000005e0 + lVar16);
    } while( true );
  }
  pcVar27 = "called `Option::unwrap()` on a `None` value";
  ppuVar38 = &PTR_s__home_puzzled_squid_src_tunnet_d_14249fad0;
LAB_14066794c:
  *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140667956;
  FUN_1423ab4f0(pcVar27,0x2b,ppuVar38);
                    /* WARNING: Does not return */
  pcVar9 = (code *)invalidInstructionException();
  (*pcVar9)();
LAB_140665868:
  if (lVar35 == lVar18) {
    do {
      if (puVar21 == puVar33) {
        lVar18 = *(longlong *)(&stack0x00000210 + lVar16);
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x1406658f8;
        lVar17 = FUN_14221bbe0(*(undefined8 *)(&stack0x00000128 + lVar16),lVar18,
                               *(undefined4 *)(&stack0x000000d8 + lVar16),
                               *(undefined4 *)(&stack0x000000d4 + lVar16));
        puVar21 = *(ulonglong **)(lVar18 + 0x60);
        puVar33 = puVar21 + *(longlong *)(lVar18 + 0x68);
        lVar18 = 0;
        lVar35 = 0;
        goto LAB_140665948;
      }
      puVar26 = (undefined1 *)*puVar21;
      puVar28 = *(undefined1 **)(*(longlong *)(&stack0x00000130 + lVar16) + 0xd8);
      if (puVar28 <= puVar26) goto LAB_14066775e;
      lVar17 = *(longlong *)(*(longlong *)(&stack0x00000130 + lVar16) + 0xd0);
      puVar21 = puVar21 + 1;
      lVar18 = *(longlong *)(lVar17 + 0x58 + (longlong)puVar26 * 0x60);
    } while (lVar18 == 0);
    lVar17 = *(longlong *)(lVar17 + 0x50 + (longlong)puVar26 * 0x60);
    lVar35 = 0;
  }
  uVar2 = *(undefined4 *)(lVar17 + lVar35 * 8);
  uVar43 = *(undefined4 *)(lVar17 + 4 + lVar35 * 8);
  lVar35 = lVar35 + 1;
  *(undefined ***)(&stack0xffffffffffffffe0 + lVar16) = &PTR_s_src_save_rs_14248fba0;
  *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665860;
  FUN_142244e00(&stack0x000005e0 + lVar16,&stack0x00000060 + lVar16,uVar2,uVar43);
  *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665868;
  FUN_141fcee80(&stack0x000005e0 + lVar16);
  goto LAB_140665868;
LAB_140665948:
  if (lVar35 == lVar18) {
    do {
      if (puVar21 == puVar33) {
        lVar18 = *(longlong *)(&stack0x00000208 + lVar16);
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x1406659d8;
        lVar17 = FUN_14221bbe0(*(undefined8 *)(&stack0x00000118 + lVar16),lVar18,
                               *(undefined4 *)(&stack0x000000d0 + lVar16),
                               *(undefined4 *)(&stack0x000000cc + lVar16));
        puVar21 = *(ulonglong **)(lVar18 + 0x60);
        puVar33 = puVar21 + *(longlong *)(lVar18 + 0x68);
        lVar18 = 0;
        lVar35 = 0;
        goto LAB_140665a28;
      }
      puVar26 = (undefined1 *)*puVar21;
      puVar28 = *(undefined1 **)(*(longlong *)(&stack0x00000128 + lVar16) + 0xd8);
      if (puVar28 <= puVar26) goto LAB_14066775e;
      lVar17 = *(longlong *)(*(longlong *)(&stack0x00000128 + lVar16) + 0xd0);
      puVar21 = puVar21 + 1;
      lVar18 = *(longlong *)(lVar17 + 0x58 + (longlong)puVar26 * 0x60);
    } while (lVar18 == 0);
    lVar17 = *(longlong *)(lVar17 + 0x50 + (longlong)puVar26 * 0x60);
    lVar35 = 0;
  }
  uVar2 = *(undefined4 *)(lVar17 + lVar35 * 8);
  uVar43 = *(undefined4 *)(lVar17 + 4 + lVar35 * 8);
  lVar35 = lVar35 + 1;
  *(undefined ***)(&stack0xffffffffffffffe0 + lVar16) = &PTR_s_src_save_rs_14248fbb8;
  *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665940;
  FUN_142244e00(&stack0x000005e0 + lVar16,&stack0x00000060 + lVar16,uVar2,uVar43);
  *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665948;
  FUN_141fcee80(&stack0x000005e0 + lVar16);
  goto LAB_140665948;
LAB_140665a28:
  if (lVar35 == lVar18) {
    do {
      if (puVar21 == puVar33) {
        lVar18 = *(longlong *)(&stack0x00000200 + lVar16);
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665ab8;
        lVar17 = FUN_14221bbe0(*(undefined8 *)(&stack0x00000110 + lVar16),lVar18,
                               *(undefined4 *)(&stack0x000000c8 + lVar16),
                               *(undefined4 *)(&stack0x000000c4 + lVar16));
        puVar21 = *(ulonglong **)(lVar18 + 0x60);
        puVar33 = puVar21 + *(longlong *)(lVar18 + 0x68);
        lVar18 = 0;
        lVar35 = 0;
        goto LAB_140665b08;
      }
      puVar26 = (undefined1 *)*puVar21;
      puVar28 = *(undefined1 **)(*(longlong *)(&stack0x00000118 + lVar16) + 0xd8);
      if (puVar28 <= puVar26) goto LAB_14066775e;
      lVar17 = *(longlong *)(*(longlong *)(&stack0x00000118 + lVar16) + 0xd0);
      puVar21 = puVar21 + 1;
      lVar18 = *(longlong *)(lVar17 + 0x58 + (longlong)puVar26 * 0x60);
    } while (lVar18 == 0);
    lVar17 = *(longlong *)(lVar17 + 0x50 + (longlong)puVar26 * 0x60);
    lVar35 = 0;
  }
  uVar2 = *(undefined4 *)(lVar17 + lVar35 * 8);
  uVar43 = *(undefined4 *)(lVar17 + 4 + lVar35 * 8);
  lVar35 = lVar35 + 1;
  *(undefined ***)(&stack0xffffffffffffffe0 + lVar16) = &PTR_s_src_save_rs_14248fbd0;
  *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665a20;
  FUN_142244e00(&stack0x000005e0 + lVar16,&stack0x00000060 + lVar16,uVar2,uVar43);
  *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665a28;
  FUN_141fcee80(&stack0x000005e0 + lVar16);
  goto LAB_140665a28;
LAB_140665b08:
  if (lVar35 == lVar18) {
    do {
      if (puVar21 == puVar33) {
        puVar26 = *(undefined1 **)(&stack0x000001f8 + lVar16);
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665b98;
        puVar28 = puVar26;
        lVar18 = FUN_14221bbe0(*(undefined8 *)(&stack0x00000108 + lVar16),puVar26,
                               *(undefined4 *)(&stack0x000000c0 + lVar16),
                               *(undefined4 *)(&stack0x000000bc + lVar16));
        puVar21 = *(ulonglong **)(puVar26 + 0x60);
        puVar33 = puVar21 + *(longlong *)(puVar26 + 0x68);
        lVar17 = 0;
        lVar35 = 0;
        goto LAB_140665bef;
      }
      puVar26 = (undefined1 *)*puVar21;
      puVar28 = *(undefined1 **)(*(longlong *)(&stack0x00000110 + lVar16) + 0xd8);
      if (puVar28 <= puVar26) goto LAB_14066775e;
      lVar17 = *(longlong *)(*(longlong *)(&stack0x00000110 + lVar16) + 0xd0);
      puVar21 = puVar21 + 1;
      lVar18 = *(longlong *)(lVar17 + 0x58 + (longlong)puVar26 * 0x60);
    } while (lVar18 == 0);
    lVar17 = *(longlong *)(lVar17 + 0x50 + (longlong)puVar26 * 0x60);
    lVar35 = 0;
  }
  uVar2 = *(undefined4 *)(lVar17 + lVar35 * 8);
  uVar43 = *(undefined4 *)(lVar17 + 4 + lVar35 * 8);
  lVar35 = lVar35 + 1;
  *(undefined ***)(&stack0xffffffffffffffe0 + lVar16) = &PTR_s_src_save_rs_14248fbe8;
  *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665b00;
  FUN_142244e00(&stack0x000005e0 + lVar16,&stack0x00000060 + lVar16,uVar2,uVar43);
  *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665b08;
  FUN_141fcee80(&stack0x000005e0 + lVar16);
  goto LAB_140665b08;
LAB_140665bef:
  if (lVar35 == lVar17) {
    do {
      if (puVar21 == puVar33) {
        lVar18 = *plVar25;
        if (lVar18 == 2) {
          *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665c4e;
          lVar18 = FUN_1406b8ee0();
          if (lVar18 == 2) {
            pcVar27 = "called `Option::unwrap()` on a `None` value";
            ppuVar38 = &PTR_s_src_save_rs_14248fc18;
            goto LAB_14066794c;
          }
        }
        else {
          puVar28 = (undefined1 *)plVar25[1];
        }
        puVar26 = &stack0x000005e0 + lVar16;
        *(longlong *)(&stack0x00000288 + lVar16) = lVar18;
        *(undefined1 **)(&stack0x00000290 + lVar16) = puVar28;
        puVar28 = &stack0x00000288 + lVar16;
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665c9c;
        FUN_1406b8ab0(puVar26);
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665ca4;
        lVar18 = FUN_1406c86c0(puVar26);
        if (lVar18 != 0) {
          *(undefined1 **)(&stack0x000005e0 + lVar16) = puVar28;
          *(undefined ***)(&stack0xffffffffffffffe0 + lVar16) = &PTR_s_src_save_rs_14248fc48;
          *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x14066789f;
          FUN_1423ab9f0("Cannot open save file",0x15,&stack0x000005e0 + lVar16,&PTR_FUN_14248ca28);
          goto LAB_14066793c;
        }
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665cbf;
        lVar18 = thunk_FUN_142351260(0x2000,1);
        if (lVar18 == 0) {
          *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140667866;
          FUN_14239ef70(0x2000,1);
          goto LAB_14066793c;
        }
        *(undefined1 **)(&stack0x000085c0 + lVar16) = puVar28;
        *(longlong *)(&stack0x000085c8 + lVar16) = lVar18;
        *(undefined8 *)(&stack0x000085d0 + lVar16) = 0x2000;
        *(undefined8 *)(&stack0x000085d8 + lVar16) = 0;
        *(undefined8 *)(&stack0x000085e0 + lVar16) = 0;
        *(undefined8 *)(&stack0x000085e8 + lVar16) = 0;
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665d08;
        FUN_14043e370(puVar26,&stack0x000085c0 + lVar16);
        if ((&stack0x00000768)[lVar16] == '\x02') {
          *(undefined8 *)(&stack0x000085c0 + lVar16) = *(undefined8 *)(&stack0x000005e0 + lVar16);
          *(undefined ***)(&stack0xffffffffffffffe0 + lVar16) = &PTR_s_src_save_rs_14248fc78;
          *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x1406678e0;
          FUN_1423ab9f0("Corrupted save file",0x13,&stack0x000085c0 + lVar16,&PTR_FUN_14248ca68);
          goto LAB_14066793c;
        }
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665d2c;
        memcpy(&stack0x000002a8 + lVar16,puVar26,0x338);
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665d51;
        uVar19 = FUN_14221bbe0(*(undefined8 *)(&stack0x000000a8 + lVar16),
                               *(undefined8 *)(&stack0x000000a0 + lVar16),
                               *(undefined4 *)(&stack0x000000b8 + lVar16),
                               *(undefined4 *)(&stack0x00000074 + lVar16));
        *(undefined8 *)((longlong)&lStackX_20 + lVar16) = uVar19;
        puVar21 = *(ulonglong **)(*(longlong *)(&stack0x00000100 + lVar16) + 0x68);
        puVar33 = puVar21 + *(longlong *)(*(longlong *)(&stack0x00000100 + lVar16) + 0x70);
        lVar18 = *(longlong *)(&stack0x000000a8 + lVar16);
        puVar37 = *(ulonglong **)(&stack0x000000a0 + lVar16);
        goto LAB_140665dc0;
      }
      puVar26 = (undefined1 *)*puVar21;
      puVar28 = *(undefined1 **)(*(longlong *)(&stack0x00000108 + lVar16) + 0xd8);
      if (puVar28 <= puVar26) {
LAB_14066775e:
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x14066776a;
        FUN_1423ab620(puVar26,puVar28,&PTR_s__home_puzzled_squid_src_tunnet_d_14248cf28);
                    /* WARNING: Does not return */
        pcVar9 = (code *)invalidInstructionException();
        (*pcVar9)();
      }
      lVar18 = *(longlong *)(*(longlong *)(&stack0x00000108 + lVar16) + 0xd0);
      puVar21 = puVar21 + 1;
      lVar17 = *(longlong *)(lVar18 + 0x58 + (longlong)puVar26 * 0x60);
    } while (lVar17 == 0);
    lVar18 = *(longlong *)(lVar18 + 0x50 + (longlong)puVar26 * 0x60);
    lVar35 = 0;
  }
  uVar2 = *(undefined4 *)(lVar18 + lVar35 * 8);
  uVar43 = *(undefined4 *)(lVar18 + 4 + lVar35 * 8);
  lVar35 = lVar35 + 1;
  *(undefined ***)(&stack0xffffffffffffffe0 + lVar16) = &PTR_s_src_save_rs_14248fc00;
  puVar28 = &stack0x00000060 + lVar16;
  *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665be7;
  FUN_142244e00(&stack0x000005e0 + lVar16,puVar28,uVar2,uVar43);
  *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665bef;
  FUN_141fcee80(&stack0x000005e0 + lVar16);
  goto LAB_140665bef;
LAB_140665dc0:
  if (puVar21 != puVar33) {
    uVar6 = *puVar21;
    uVar24 = *(ulonglong *)(lVar18 + 0xd8);
    if (uVar24 <= uVar6) {
      *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x1406677c9;
      FUN_1423ab620(uVar6,uVar24,&PTR_s__home_puzzled_squid_src_tunnet_d_14248cf28);
      goto LAB_14066793c;
    }
    lVar17 = *(longlong *)(lVar18 + 0xd0);
    lVar35 = uVar6 * 0x60;
    if (*(ulonglong *)(lVar17 + 0x40 + lVar35) <= *puVar37) {
LAB_1406677ce:
      *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x1406677e6;
      FUN_1423ab4f0("called `Option::unwrap()` on a `None` value",0x2b,
                    &PTR_s__home_puzzled_squid_src_tunnet_d_14248d298);
      goto LAB_14066793c;
    }
    lVar30 = lVar17 + lVar35;
    lVar20 = *puVar37 * 0x10;
    if (*(longlong *)(*(longlong *)(lVar30 + 0x38) + lVar20) == 0) goto LAB_1406677ce;
    puVar21 = puVar21 + 1;
    lVar17 = *(longlong *)(lVar17 + 0x58 + lVar35);
    if (lVar17 != 0) {
      puVar23 = *(undefined4 **)(lVar30 + 0x50);
      lVar18 = *(longlong *)(*(longlong *)(lVar30 + 0x38) + 8 + lVar20) * 0x58;
      lVar20 = *(longlong *)(*(longlong *)(lVar30 + 8) + 0x10 + lVar18);
      lVar35 = *(longlong *)(*(longlong *)(lVar30 + 8) + 0x40 + lVar18);
      *(undefined8 *)(&stack0xfffffffffffffff0 + lVar16) = 1;
      *(undefined4 **)((longlong)&lStackX_20 + lVar16) = puVar23;
      lVar30 = 0;
      puVar10 = puVar23;
      while( true ) {
        uVar2 = *puVar23;
        uVar43 = puVar10[1];
        fVar1 = *(float *)(&stack0x000002b8 + lVar16);
        uVar19 = *(undefined8 *)(&stack0x000002b0 + lVar16);
        *(longlong *)(&stack0xffffffffffffffe8 + lVar16) = lVar20;
        *(undefined4 *)(lVar20 + 4 + lVar30 * 8) = *(undefined4 *)(&stack0x00000074 + lVar16);
        *(ulonglong *)(lVar35 + 0x10 + lVar30 * 0x30) =
             CONCAT44((float)((ulonglong)uVar19 >> 0x20) + 0.5,(float)uVar19 + 0.0);
        *(float *)(lVar35 + 0x18 + lVar30 * 0x30) = fVar1 + 0.0;
        *(undefined ***)(&stack0xffffffffffffffe0 + lVar16) = &PTR_s_src_save_rs_14248fc90;
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665eb6;
        FUN_142244e00(&stack0x000085c0 + lVar16,&stack0x00000060 + lVar16,uVar2,uVar43);
        uVar19 = *(undefined8 *)(&stack0x000085c0 + lVar16);
        plVar39 = (longlong *)**(longlong **)(&stack0x000085c8 + lVar16);
        lVar18 = plVar39[2];
        lVar30 = plVar39[5];
        if (lVar30 == plVar39[3]) {
          *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665ee1;
          FUN_14079f6c0(plVar39 + 3);
          lVar30 = plVar39[5];
        }
        lVar20 = plVar39[4];
        *(longlong *)(lVar20 + lVar30 * 0x10) = lVar18;
        *(code **)(lVar20 + 8 + lVar30 * 0x10) = FUN_14068cb60;
        plVar39[5] = plVar39[5] + 1;
        lVar30 = plVar39[2];
        if ((ulonglong)(*plVar39 - lVar30) < 0xc) {
          *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665f20;
          FUN_1407a1510(plVar39,lVar30,0xc);
        }
        lVar30 = plVar39[1];
        *(undefined8 *)(lVar30 + lVar18) = uVar19;
        *(undefined1 *)(lVar30 + 8 + lVar18) = 0;
        plVar39[2] = lVar18 + 0xc;
        uVar19 = *(undefined8 *)(&stack0x000085c0 + lVar16);
        plVar39 = (longlong *)**(longlong **)(&stack0x000085c8 + lVar16);
        lVar18 = plVar39[2];
        lVar30 = plVar39[5];
        if (lVar30 == plVar39[3]) {
          *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665f61;
          FUN_14079f6c0(plVar39 + 3);
          lVar30 = plVar39[5];
        }
        lVar20 = plVar39[4];
        *(longlong *)(lVar20 + lVar30 * 0x10) = lVar18;
        *(code **)(lVar20 + 8 + lVar30 * 0x10) = FUN_14068f180;
        plVar39[5] = plVar39[5] + 1;
        lVar30 = plVar39[2];
        if ((ulonglong)(*plVar39 - lVar30) < 0x20) {
          *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665fa0;
          FUN_1407a1510(plVar39,lVar30,0x20);
        }
        lVar30 = plVar39[1];
        *(undefined8 *)(lVar30 + lVar18) = uVar19;
        puVar4 = (undefined8 *)(lVar30 + 8 + lVar18);
        *puVar4 = 0;
        puVar4[1] = 0;
        *(undefined8 *)(lVar30 + 0x18 + lVar18) = 0;
        plVar39[2] = lVar18 + 0x20;
        *(undefined8 *)(&stack0x000005e4 + lVar16) = 0x3f0000003ebd70a4;
        *(undefined4 *)(&stack0x000005e0 + lVar16) = 1;
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140665fe5;
        FUN_1401a04d0(&stack0x000085c0 + lVar16,&stack0x000005e0 + lVar16);
        lVar30 = *(longlong *)(&stack0xfffffffffffffff0 + lVar16);
        lVar18 = *(longlong *)(&stack0x000000a8 + lVar16);
        puVar37 = *(ulonglong **)(&stack0x000000a0 + lVar16);
        lVar20 = *(longlong *)(&stack0xffffffffffffffe8 + lVar16);
        if (lVar30 == lVar17) break;
        if (lVar20 == 0) goto LAB_140666010;
        puVar23 = (undefined4 *)(*(longlong *)((longlong)&lStackX_20 + lVar16) + lVar30 * 8);
        *(longlong *)(&stack0xfffffffffffffff0 + lVar16) = lVar30 + 1;
        puVar10 = (undefined4 *)(*(longlong *)((longlong)&lStackX_20 + lVar16) + lVar30 * 8);
      }
    }
    goto LAB_140665dc0;
  }
LAB_140666010:
  uVar19 = *(undefined8 *)(&stack0x000002a8 + lVar16);
  *(undefined4 *)(*(longlong *)(&stack0x000001f0 + lVar16) + 4) =
       *(undefined4 *)(&stack0x000000b4 + lVar16);
  *(undefined8 *)(*(longlong *)(&stack0x000001e8 + lVar16) + 0x20) = uVar19;
  *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140666054;
  memcpy(&stack0x000005e0 + lVar16,&stack0x000003f8 + lVar16,0x1e8);
  *(undefined4 *)(*(longlong *)(&stack0x00000050 + lVar16) + 4) =
       *(undefined4 *)((longlong)&uStackX_1c + lVar16);
  _Dst = *(void **)(&stack0x00000028 + lVar16);
  *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140666070;
  FUN_14066d5b0(_Dst);
  *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140666081;
  memcpy(_Dst,&stack0x000005e0 + lVar16,0x1e8);
  cVar14 = *(char *)((longlong)_Dst + 0x1c4);
  if (cVar14 == '\x14') {
    *(undefined4 *)(*(longlong *)(&stack0x00000050 + lVar16) + 4) =
         *(undefined4 *)((longlong)&uStackX_1c + lVar16);
    *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x1406660aa;
    FUN_140293270(*(undefined8 *)(&stack0x00000028 + lVar16),0);
    *(undefined8 *)(*(longlong *)(&stack0x00000028 + lVar16) + 0x10) = 0;
    *(undefined4 *)(*(longlong *)(&stack0x00000050 + lVar16) + 4) =
         *(undefined4 *)((longlong)&uStackX_1c + lVar16);
    *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x1406660d3;
    FUN_140641b60(*(undefined8 *)(&stack0x000001c0 + lVar16));
    lVar18 = *(longlong *)(&stack0x00000028 + lVar16);
    *(undefined1 *)(lVar18 + 0x1c4) = 9;
    *(undefined4 *)(*(longlong *)(&stack0x00000050 + lVar16) + 4) =
         *(undefined4 *)((longlong)&uStackX_1c + lVar16);
    *(undefined1 *)(lVar18 + 0x1da) = 0;
    cVar14 = *(char *)(lVar18 + 0x1c4);
  }
  puVar33 = *(ulonglong **)(&stack0x00000028 + lVar16);
  if ((byte)(cVar14 - 0x14U) < 0xfe) {
    *(undefined4 *)(*(longlong *)(&stack0x00000050 + lVar16) + 4) =
         *(undefined4 *)((longlong)&uStackX_1c + lVar16);
    *(undefined1 *)((longlong)puVar33 + 0x1da) = 0;
  }
  *(undefined4 *)(*(longlong *)(&stack0x00000050 + lVar16) + 4) =
       *(undefined4 *)((longlong)&uStackX_1c + lVar16);
  uVar6 = puVar33[3];
  if (uVar6 == 0) {
    lVar18 = 0;
    uVar24 = 0;
  }
  else {
    uVar24 = *puVar33;
    uVar32 = 0;
    if (uVar24 <= puVar33[2]) {
      uVar32 = uVar24;
    }
    lVar18 = puVar33[2] - uVar32;
    lVar17 = uVar6 - (uVar24 - lVar18);
    if (uVar24 - lVar18 <= uVar6 && lVar17 != 0) goto LAB_140666176;
    uVar24 = uVar6 + lVar18;
  }
  lVar17 = 0;
LAB_140666176:
  lVar35 = *(longlong *)(*(longlong *)(&stack0x00000028 + lVar16) + 8);
  lVar18 = lVar18 * 0x90 + lVar35;
  lVar30 = uVar24 * 0x90 + lVar35;
  lVar17 = lVar17 * 0x90 + lVar35;
  while ((lVar20 = lVar17, lVar18 != lVar30 ||
         ((lVar35 != lVar17 &&
          (bVar42 = lVar35 != 0, lVar20 = lVar30, lVar18 = lVar35, lVar35 = lVar30, lVar30 = lVar17,
          bVar42))))) {
    *(undefined1 *)(lVar18 + 0x8d) = 0;
    lVar18 = lVar18 + 0x90;
    lVar17 = lVar20;
  }
  *(undefined8 *)(&stack0xfffffffffffffff0 + lVar16) = *(undefined8 *)(&stack0x00000308 + lVar16);
  *(undefined8 *)(&stack0xffffffffffffffe8 + lVar16) = *(undefined8 *)(&stack0x00000310 + lVar16);
  if (*(longlong *)(&stack0x00000318 + lVar16) != 0) {
    puVar33 = *(ulonglong **)(&stack0xffffffffffffffe8 + lVar16);
    puVar21 = puVar33 + *(longlong *)(&stack0x00000318 + lVar16) * 2;
    do {
      if ((byte)puVar33[1] == 2) break;
      uVar6 = *puVar33;
      if (uVar6 < *(ulonglong *)(&stack0x000002d0 + lVar16)) {
        puVar4 = (undefined8 *)(*(longlong *)(&stack0x000002c8 + lVar16) + uVar6 * 0x1c);
        uVar19 = *puVar4;
        uVar13 = puVar4[1];
        puVar23 = (undefined4 *)(*(longlong *)(&stack0x000002c8 + lVar16) + 0x10 + uVar6 * 0x1c);
        uVar2 = *puVar23;
        uVar43 = puVar23[1];
        cVar14 = ((*(byte *)((longlong)puVar33 + 9) & 1) != 0) * '\t' + '\x01';
        if (((byte)puVar33[1] & 1) != 0) {
          cVar14 = '\a';
        }
        *(undefined4 *)(*(longlong *)(&stack0x00000048 + lVar16) + 4) =
             *(undefined4 *)(&stack0x00000004 + lVar16);
        uVar8 = *(undefined8 *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x10);
        if (*(char *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x48) == '\0') {
          plVar39 = *(longlong **)(&stack0x00000030 + lVar16);
          lVar18 = *plVar39;
          if (lVar18 == **(longlong **)(&stack0x00000038 + lVar16)) {
            *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x14066631c;
            FUN_14079fa10();
            plVar29 = *(longlong **)((longlong)alStackX_8 + lVar16);
            goto LAB_140666321;
          }
          plVar29 = *(longlong **)((longlong)alStackX_8 + lVar16);
        }
        else {
          plVar39 = *(longlong **)(&stack0x00000040 + lVar16);
          lVar18 = *plVar39;
          if (lVar18 == **(longlong **)(&stack0x00000058 + lVar16)) {
            *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x1406662fe;
            FUN_14079fa10();
            plVar29 = *(longlong **)((longlong)alStackX_8 + lVar16 + 8);
LAB_140666321:
            lVar18 = *plVar39;
          }
          else {
            plVar29 = *(longlong **)((longlong)alStackX_8 + lVar16 + 8);
          }
        }
        lVar17 = *plVar29;
        lVar18 = lVar18 * 0x58;
        *(char *)(lVar17 + lVar18) = cVar14;
        *(undefined8 *)(lVar17 + 0x20 + lVar18) = 1;
        *(ulonglong *)(lVar17 + 0x28 + lVar18) = uVar6;
        puVar4 = (undefined8 *)(lVar17 + 0x30 + lVar18);
        *puVar4 = uVar19;
        puVar4[1] = uVar13;
        puVar23 = (undefined4 *)(lVar17 + 0x40 + lVar18);
        *puVar23 = uVar2;
        puVar23[1] = uVar43;
        *(undefined4 *)(lVar17 + 0x48 + lVar18) = 0;
        *(undefined1 *)(lVar17 + 0x4d + lVar18) = 2;
        *(undefined8 *)(lVar17 + 0x50 + lVar18) = uVar8;
        *plVar39 = *plVar39 + 1;
        *(longlong *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x10) =
             *(longlong *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x10) + 1;
      }
      puVar33 = puVar33 + 2;
    } while (puVar33 != puVar21);
  }
  if (*(longlong *)(&stack0xfffffffffffffff0 + lVar16) != 0) {
    *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x14066635e;
    FUN_1408192a0(*(undefined8 *)(&stack0xffffffffffffffe8 + lVar16),
                  *(longlong *)(&stack0xfffffffffffffff0 + lVar16) << 4,8);
  }
  *(undefined8 *)(&stack0xffffffffffffffe8 + lVar16) = *(undefined8 *)(&stack0x00000368 + lVar16);
  lVar18 = *(longlong *)(&stack0x00000370 + lVar16);
  lVar17 = *(longlong *)(&stack0x00000378 + lVar16);
  plVar39 = *(longlong **)(&stack0x00000058 + lVar16);
  if (lVar17 != 0) {
    lVar35 = 0;
    do {
      uVar6 = *(ulonglong *)(lVar18 + lVar35);
      if (uVar6 < *(ulonglong *)(&stack0x000002d0 + lVar16)) {
        lVar30 = *(longlong *)(&stack0x000002c8 + lVar16);
        lVar20 = uVar6 * 0x1c;
        uVar13 = *(undefined8 *)(lVar30 + lVar20);
        uVar8 = ((undefined8 *)(lVar30 + lVar20))[1];
        puVar23 = (undefined4 *)(lVar30 + 0x10 + lVar20);
        uVar43 = *puVar23;
        uVar3 = puVar23[1];
        uVar2 = *(undefined4 *)(lVar30 + 0x18 + lVar20);
        *(undefined4 *)(*(longlong *)(&stack0x00000048 + lVar16) + 4) =
             *(undefined4 *)(&stack0x00000004 + lVar16);
        uVar19 = *(undefined8 *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x10);
        if (*(char *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x48) == '\0') {
          plVar29 = *(longlong **)(&stack0x00000030 + lVar16);
          lVar30 = *plVar29;
          if (lVar30 == **(longlong **)(&stack0x00000038 + lVar16)) {
            *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140666482;
            FUN_14079fa10();
            plVar25 = *(longlong **)((longlong)alStackX_8 + lVar16);
            goto LAB_14066648a;
          }
          plVar25 = *(longlong **)((longlong)alStackX_8 + lVar16);
        }
        else {
          plVar29 = *(longlong **)(&stack0x00000040 + lVar16);
          lVar30 = *plVar29;
          if (lVar30 == *plVar39) {
            *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x14066645e;
            FUN_14079fa10(plVar39);
            plVar25 = *(longlong **)((longlong)alStackX_8 + lVar16 + 8);
LAB_14066648a:
            lVar30 = *plVar29;
          }
          else {
            plVar25 = *(longlong **)((longlong)alStackX_8 + lVar16 + 8);
          }
        }
        lVar20 = *plVar25;
        lVar30 = lVar30 * 0x58;
        *(undefined1 *)(lVar20 + lVar30) = 4;
        *(undefined8 *)(lVar20 + 0x20 + lVar30) = 1;
        *(ulonglong *)(lVar20 + 0x28 + lVar30) = uVar6;
        puVar4 = (undefined8 *)(lVar20 + 0x30 + lVar30);
        *puVar4 = uVar13;
        puVar4[1] = uVar8;
        puVar23 = (undefined4 *)(lVar20 + 0x40 + lVar30);
        *puVar23 = uVar43;
        puVar23[1] = uVar3;
        *(undefined4 *)(lVar20 + 0x48 + lVar30) = uVar2;
        *(undefined1 *)(lVar20 + 0x4d + lVar30) = 2;
        *(undefined8 *)(lVar20 + 0x50 + lVar30) = uVar19;
        *plVar29 = *plVar29 + 1;
        *(longlong *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x10) =
             *(longlong *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x10) + 1;
      }
      lVar35 = lVar35 + 8;
    } while (lVar17 << 3 != lVar35);
  }
  if (*(longlong *)(&stack0xffffffffffffffe8 + lVar16) != 0) {
    *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x1406664bc;
    FUN_1408192a0(lVar18,*(longlong *)(&stack0xffffffffffffffe8 + lVar16) << 3,8);
  }
  *(undefined8 *)(&stack0xffffffffffffffe8 + lVar16) = *(undefined8 *)(&stack0x00000380 + lVar16);
  lVar18 = *(longlong *)(&stack0x00000388 + lVar16);
  lVar17 = *(longlong *)(&stack0x00000390 + lVar16);
  if (lVar17 != 0) {
    lVar35 = 0;
    do {
      uVar6 = *(ulonglong *)(lVar18 + lVar35);
      if (uVar6 < *(ulonglong *)(&stack0x000002d0 + lVar16)) {
        lVar30 = *(longlong *)(&stack0x000002c8 + lVar16);
        lVar20 = uVar6 * 0x1c;
        uVar13 = *(undefined8 *)(lVar30 + lVar20);
        uVar8 = ((undefined8 *)(lVar30 + lVar20))[1];
        puVar23 = (undefined4 *)(lVar30 + 0x10 + lVar20);
        uVar43 = *puVar23;
        uVar3 = puVar23[1];
        uVar2 = *(undefined4 *)(lVar30 + 0x18 + lVar20);
        *(undefined4 *)(*(longlong *)(&stack0x00000048 + lVar16) + 4) =
             *(undefined4 *)(&stack0x00000004 + lVar16);
        uVar19 = *(undefined8 *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x10);
        if (*(char *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x48) == '\0') {
          plVar29 = *(longlong **)(&stack0x00000030 + lVar16);
          lVar30 = *plVar29;
          if (lVar30 == **(longlong **)(&stack0x00000038 + lVar16)) {
            *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x1406665d8;
            FUN_14079fa10();
            plVar25 = *(longlong **)((longlong)alStackX_8 + lVar16);
            goto LAB_1406665e0;
          }
          plVar25 = *(longlong **)((longlong)alStackX_8 + lVar16);
        }
        else {
          plVar29 = *(longlong **)(&stack0x00000040 + lVar16);
          lVar30 = *plVar29;
          if (lVar30 == *plVar39) {
            *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x1406665b4;
            FUN_14079fa10(plVar39);
            plVar25 = *(longlong **)((longlong)alStackX_8 + lVar16 + 8);
LAB_1406665e0:
            lVar30 = *plVar29;
          }
          else {
            plVar25 = *(longlong **)((longlong)alStackX_8 + lVar16 + 8);
          }
        }
        lVar20 = *plVar25;
        lVar30 = lVar30 * 0x58;
        *(undefined1 *)(lVar20 + lVar30) = 6;
        *(undefined8 *)(lVar20 + 0x20 + lVar30) = 1;
        *(ulonglong *)(lVar20 + 0x28 + lVar30) = uVar6;
        puVar4 = (undefined8 *)(lVar20 + 0x30 + lVar30);
        *puVar4 = uVar13;
        puVar4[1] = uVar8;
        puVar23 = (undefined4 *)(lVar20 + 0x40 + lVar30);
        *puVar23 = uVar43;
        puVar23[1] = uVar3;
        *(undefined4 *)(lVar20 + 0x48 + lVar30) = uVar2;
        *(undefined1 *)(lVar20 + 0x4d + lVar30) = 2;
        *(undefined8 *)(lVar20 + 0x50 + lVar30) = uVar19;
        *plVar29 = *plVar29 + 1;
        *(longlong *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x10) =
             *(longlong *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x10) + 1;
      }
      lVar35 = lVar35 + 8;
    } while (lVar17 << 3 != lVar35);
  }
  if (*(longlong *)(&stack0xffffffffffffffe8 + lVar16) != 0) {
    *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x14066661c;
    FUN_1408192a0(lVar18,*(longlong *)(&stack0xffffffffffffffe8 + lVar16) << 3,8);
  }
  *(undefined8 *)((longlong)&lStackX_20 + lVar16) = *(undefined8 *)(&stack0x00000350 + lVar16);
  *(undefined8 *)(&stack0xfffffffffffffff0 + lVar16) = *(undefined8 *)(&stack0x00000358 + lVar16);
  if (*(longlong *)(&stack0x00000360 + lVar16) != 0) {
    puVar33 = *(ulonglong **)(&stack0xfffffffffffffff0 + lVar16);
    puVar21 = puVar33 + *(longlong *)(&stack0x00000360 + lVar16) * 2;
    *(ulonglong **)(&stack0xffffffffffffffe8 + lVar16) = puVar21;
    do {
      if ((byte)puVar33[1] == 2) break;
      uVar6 = *puVar33;
      if (uVar6 < *(ulonglong *)(&stack0x000002d0 + lVar16)) {
        bVar15 = *(byte *)((longlong)puVar33 + 9);
        lVar18 = *(longlong *)(&stack0x000002c8 + lVar16);
        lVar17 = uVar6 * 0x1c;
        uVar19 = *(undefined8 *)(lVar18 + lVar17);
        uVar13 = ((undefined8 *)(lVar18 + lVar17))[1];
        puVar23 = (undefined4 *)(lVar18 + 0x10 + lVar17);
        uVar2 = *puVar23;
        uVar43 = puVar23[1];
        uVar41 = 8;
        if (((byte)puVar33[1] & 1) == 0) {
          uVar41 = 2;
        }
        uVar3 = *(undefined4 *)(lVar18 + 0x18 + lVar17);
        *(undefined4 *)(*(longlong *)(&stack0x00000048 + lVar16) + 4) =
             *(undefined4 *)(&stack0x00000004 + lVar16);
        uVar8 = *(undefined8 *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x10);
        if (*(char *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x48) == '\0') {
          plVar39 = *(longlong **)(&stack0x00000030 + lVar16);
          lVar18 = *plVar39;
          if (lVar18 == **(longlong **)(&stack0x00000038 + lVar16)) {
            *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140666771;
            FUN_14079fa10();
            plVar29 = *(longlong **)((longlong)alStackX_8 + lVar16);
            goto LAB_140666776;
          }
          plVar29 = *(longlong **)((longlong)alStackX_8 + lVar16);
        }
        else {
          plVar39 = *(longlong **)(&stack0x00000040 + lVar16);
          lVar18 = *plVar39;
          if (lVar18 == **(longlong **)(&stack0x00000058 + lVar16)) {
            *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140666752;
            FUN_14079fa10();
            plVar29 = *(longlong **)((longlong)alStackX_8 + lVar16 + 8);
LAB_140666776:
            lVar18 = *plVar39;
          }
          else {
            plVar29 = *(longlong **)((longlong)alStackX_8 + lVar16 + 8);
          }
        }
        lVar17 = *plVar29;
        lVar18 = lVar18 * 0x58;
        *(undefined1 *)(lVar17 + lVar18) = uVar41;
        *(byte *)(lVar17 + 1 + lVar18) = bVar15 & 1;
        *(undefined8 *)(lVar17 + 0x20 + lVar18) = 1;
        *(ulonglong *)(lVar17 + 0x28 + lVar18) = uVar6;
        puVar4 = (undefined8 *)(lVar17 + 0x30 + lVar18);
        *puVar4 = uVar19;
        puVar4[1] = uVar13;
        puVar23 = (undefined4 *)(lVar17 + 0x40 + lVar18);
        *puVar23 = uVar2;
        puVar23[1] = uVar43;
        *(undefined4 *)(lVar17 + 0x48 + lVar18) = uVar3;
        *(undefined1 *)(lVar17 + 0x4d + lVar18) = 2;
        *(undefined8 *)(lVar17 + 0x50 + lVar18) = uVar8;
        *plVar39 = *plVar39 + 1;
        *(longlong *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x10) =
             *(longlong *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x10) + 1;
        puVar21 = *(ulonglong **)(&stack0xffffffffffffffe8 + lVar16);
      }
      puVar33 = puVar33 + 2;
    } while (puVar33 != puVar21);
  }
  if (*(longlong *)((longlong)&lStackX_20 + lVar16) != 0) {
    *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x1406667ae;
    FUN_1408192a0(*(undefined8 *)(&stack0xfffffffffffffff0 + lVar16),
                  *(longlong *)((longlong)&lStackX_20 + lVar16) << 4,8);
  }
  *(undefined8 *)(&stack0xfffffffffffffff0 + lVar16) = *(undefined8 *)(&stack0x000002f0 + lVar16);
  *(undefined8 *)(&stack0xffffffffffffffe8 + lVar16) = *(undefined8 *)(&stack0x000002f8 + lVar16);
  if (*(longlong *)(&stack0x00000300 + lVar16) != 0) {
    puVar33 = *(ulonglong **)(&stack0xffffffffffffffe8 + lVar16);
    puVar21 = puVar33 + *(longlong *)(&stack0x00000300 + lVar16) * 2;
    do {
      bVar15 = *(byte *)((longlong)puVar33 + 0xe);
      if (bVar15 == 2) break;
      uVar6 = *puVar33;
      if (uVar6 < *(ulonglong *)(&stack0x000002d0 + lVar16)) {
        uVar24 = puVar33[1];
        lVar18 = *(longlong *)(&stack0x000002c8 + lVar16);
        lVar17 = uVar6 * 0x1c;
        uVar19 = *(undefined8 *)(lVar18 + lVar17);
        uVar13 = ((undefined8 *)(lVar18 + lVar17))[1];
        puVar23 = (undefined4 *)(lVar18 + 0x10 + lVar17);
        uVar43 = *puVar23;
        uVar3 = puVar23[1];
        (&stack0x000005e4)[lVar16] = *(undefined1 *)((longlong)puVar33 + 0xd);
        *(undefined4 *)(&stack0x000005e0 + lVar16) = *(undefined4 *)((longlong)puVar33 + 9);
        uVar2 = *(undefined4 *)(lVar18 + 0x18 + lVar17);
        bVar15 = bVar15 & 1;
        if ((char)uVar24 == '\v') {
          bVar15 = 2;
        }
        *(undefined4 *)(*(longlong *)(&stack0x00000048 + lVar16) + 4) =
             *(undefined4 *)(&stack0x00000004 + lVar16);
        uVar8 = *(undefined8 *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x10);
        if (*(char *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x48) == '\0') {
          plVar39 = *(longlong **)(&stack0x00000030 + lVar16);
          lVar18 = *plVar39;
          if (lVar18 == **(longlong **)(&stack0x00000038 + lVar16)) {
            *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x14066692b;
            FUN_14079fa10();
            plVar29 = *(longlong **)((longlong)alStackX_8 + lVar16);
            goto LAB_140666933;
          }
          plVar29 = *(longlong **)((longlong)alStackX_8 + lVar16);
        }
        else {
          plVar39 = *(longlong **)(&stack0x00000040 + lVar16);
          lVar18 = *plVar39;
          if (lVar18 == **(longlong **)(&stack0x00000058 + lVar16)) {
            *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x14066690a;
            FUN_14079fa10();
            plVar29 = *(longlong **)((longlong)alStackX_8 + lVar16 + 8);
LAB_140666933:
            lVar18 = *plVar39;
          }
          else {
            plVar29 = *(longlong **)((longlong)alStackX_8 + lVar16 + 8);
          }
        }
        lVar17 = *plVar29;
        lVar18 = lVar18 * 0x58;
        *(undefined1 *)(lVar17 + lVar18) = 0;
        *(undefined4 *)(lVar17 + 1 + lVar18) = *(undefined4 *)(&stack0x000005e0 + lVar16);
        *(undefined1 *)(lVar17 + 5 + lVar18) = (&stack0x000005e4)[lVar16];
        *(undefined8 *)(lVar17 + 0x20 + lVar18) = 1;
        *(ulonglong *)(lVar17 + 0x28 + lVar18) = uVar6;
        puVar4 = (undefined8 *)(lVar17 + 0x30 + lVar18);
        *puVar4 = uVar19;
        puVar4[1] = uVar13;
        puVar23 = (undefined4 *)(lVar17 + 0x40 + lVar18);
        *puVar23 = uVar43;
        puVar23[1] = uVar3;
        *(undefined4 *)(lVar17 + 0x48 + lVar18) = uVar2;
        *(char *)(lVar17 + 0x4c + lVar18) = (char)uVar24;
        *(byte *)(lVar17 + 0x4d + lVar18) = bVar15;
        *(undefined8 *)(lVar17 + 0x50 + lVar18) = uVar8;
        *plVar39 = *plVar39 + 1;
        *(longlong *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x10) =
             *(longlong *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x10) + 1;
      }
      puVar33 = puVar33 + 2;
    } while (puVar33 != puVar21);
  }
  if (*(longlong *)(&stack0xfffffffffffffff0 + lVar16) != 0) {
    *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x14066696e;
    FUN_1408192a0(*(undefined8 *)(&stack0xffffffffffffffe8 + lVar16),
                  *(longlong *)(&stack0xfffffffffffffff0 + lVar16) << 4,8);
  }
  *(undefined8 *)(&stack0xfffffffffffffff0 + lVar16) = *(undefined8 *)(&stack0x00000320 + lVar16);
  *(undefined8 *)(&stack0xffffffffffffffe8 + lVar16) = *(undefined8 *)(&stack0x00000328 + lVar16);
  if (*(longlong *)(&stack0x00000330 + lVar16) != 0) {
    puVar33 = *(ulonglong **)(&stack0xffffffffffffffe8 + lVar16);
    puVar21 = puVar33 + *(longlong *)(&stack0x00000330 + lVar16) * 5;
    do {
      cVar14 = *(char *)((longlong)puVar33 + 0x16);
      if (cVar14 == '\x02') break;
      uVar6 = *puVar33;
      if (uVar6 < *(ulonglong *)(&stack0x000002d0 + lVar16)) {
        lVar18 = *(longlong *)(&stack0x000002c8 + lVar16);
        lVar17 = uVar6 * 0x1c;
        uVar19 = *(undefined8 *)(lVar18 + lVar17);
        uVar13 = ((undefined8 *)(lVar18 + lVar17))[1];
        puVar23 = (undefined4 *)(lVar18 + 0x10 + lVar17);
        uVar2 = *puVar23;
        uVar43 = puVar23[1];
        uVar32 = puVar33[4];
        uVar24 = puVar33[1];
        *(undefined8 *)(&stack0x000005ed + lVar16) = *(undefined8 *)((longlong)puVar33 + 0xe);
        *(ulonglong *)(&stack0x000005e7 + lVar16) = uVar24;
        uVar41 = 9;
        if ((uVar32 & 1) == 0) {
          uVar41 = 3;
        }
        uVar3 = *(undefined4 *)(lVar18 + 0x18 + lVar17);
        *(undefined8 *)(&stack0x000085cd + lVar16) = *(undefined8 *)(&stack0x000005ed + lVar16);
        *(undefined8 *)(&stack0x000085c0 + lVar16) = *(undefined8 *)(&stack0x000005e0 + lVar16);
        *(undefined8 *)(&stack0x000085c8 + lVar16) = *(undefined8 *)(&stack0x000005e8 + lVar16);
        (&stack0x00000168)[lVar16] = *(undefined1 *)((longlong)puVar33 + 0x1f);
        *(undefined8 *)(&stack0x00000160 + lVar16) = *(undefined8 *)((longlong)puVar33 + 0x17);
        *(undefined4 *)(*(longlong *)(&stack0x00000048 + lVar16) + 4) =
             *(undefined4 *)(&stack0x00000004 + lVar16);
        uVar8 = *(undefined8 *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x10);
        if (*(char *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x48) == '\0') {
          plVar39 = *(longlong **)(&stack0x00000030 + lVar16);
          lVar18 = *plVar39;
          if (lVar18 == **(longlong **)(&stack0x00000038 + lVar16)) {
            *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140666b42;
            FUN_14079fa10();
            plVar29 = *(longlong **)((longlong)alStackX_8 + lVar16);
            goto LAB_140666b4a;
          }
          plVar29 = *(longlong **)((longlong)alStackX_8 + lVar16);
        }
        else {
          plVar39 = *(longlong **)(&stack0x00000040 + lVar16);
          lVar18 = *plVar39;
          if (lVar18 == **(longlong **)(&stack0x00000058 + lVar16)) {
            *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140666b21;
            FUN_14079fa10();
            plVar29 = *(longlong **)((longlong)alStackX_8 + lVar16 + 8);
LAB_140666b4a:
            lVar18 = *plVar39;
          }
          else {
            plVar29 = *(longlong **)((longlong)alStackX_8 + lVar16 + 8);
          }
        }
        lVar17 = *plVar29;
        lVar18 = lVar18 * 0x58;
        *(undefined1 *)(lVar17 + lVar18) = uVar41;
        uVar11 = *(undefined8 *)(&stack0x000085c8 + lVar16);
        puVar4 = (undefined8 *)(lVar17 + 1 + lVar18);
        *puVar4 = *(undefined8 *)(&stack0x000085c0 + lVar16);
        puVar4[1] = uVar11;
        *(undefined8 *)(lVar17 + 0xe + lVar18) = *(undefined8 *)(&stack0x000085cd + lVar16);
        *(char *)(lVar17 + 0x16 + lVar18) = cVar14;
        *(undefined8 *)(lVar17 + 0x17 + lVar18) = *(undefined8 *)(&stack0x00000160 + lVar16);
        *(undefined1 *)(lVar17 + 0x1f + lVar18) = (&stack0x00000168)[lVar16];
        *(undefined8 *)(lVar17 + 0x20 + lVar18) = 1;
        *(ulonglong *)(lVar17 + 0x28 + lVar18) = uVar6;
        puVar4 = (undefined8 *)(lVar17 + 0x30 + lVar18);
        *puVar4 = uVar19;
        puVar4[1] = uVar13;
        puVar23 = (undefined4 *)(lVar17 + 0x40 + lVar18);
        *puVar23 = uVar2;
        puVar23[1] = uVar43;
        *(undefined4 *)(lVar17 + 0x48 + lVar18) = uVar3;
        *(undefined1 *)(lVar17 + 0x4d + lVar18) = 2;
        *(undefined8 *)(lVar17 + 0x50 + lVar18) = uVar8;
        *plVar39 = *plVar39 + 1;
        *(longlong *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x10) =
             *(longlong *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x10) + 1;
      }
      puVar33 = puVar33 + 5;
    } while (puVar33 != puVar21);
  }
  if (*(longlong *)(&stack0xfffffffffffffff0 + lVar16) != 0) {
    *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140666b82;
    FUN_1408192a0(*(undefined8 *)(&stack0xffffffffffffffe8 + lVar16),
                  *(longlong *)(&stack0xfffffffffffffff0 + lVar16) * 0x28,8);
  }
  *(undefined8 *)(&stack0xfffffffffffffff0 + lVar16) = *(undefined8 *)(&stack0x00000338 + lVar16);
  lVar18 = *(longlong *)(&stack0x00000340 + lVar16);
  if (*(longlong *)(&stack0x00000348 + lVar16) != 0) {
    lVar17 = *(longlong *)(&stack0x00000348 + lVar16) * 0x18;
    lVar35 = 0;
    *(longlong *)(&stack0xffffffffffffffe8 + lVar16) = lVar17;
    do {
      cVar14 = *(char *)(lVar18 + 9 + lVar35);
      if (cVar14 == '\x03') break;
      uVar6 = *(ulonglong *)(lVar18 + 0x10 + lVar35);
      if (uVar6 < *(ulonglong *)(&stack0x000002d0 + lVar16)) {
        lVar17 = *(longlong *)(&stack0x000002c8 + lVar16);
        lVar30 = uVar6 * 0x1c;
        uVar13 = *(undefined8 *)(lVar17 + lVar30);
        uVar8 = ((undefined8 *)(lVar17 + lVar30))[1];
        puVar23 = (undefined4 *)(lVar17 + 0x10 + lVar30);
        uVar43 = *puVar23;
        uVar3 = puVar23[1];
        (&stack0x000005eb)[lVar16] = *(undefined1 *)((undefined8 *)(lVar18 + lVar35) + 1);
        *(undefined8 *)(&stack0x000005e3 + lVar16) = *(undefined8 *)(lVar18 + lVar35);
        uVar2 = *(undefined4 *)(lVar17 + 0x18 + lVar30);
        *(undefined4 *)(&stack0x000085c8 + lVar16) = *(undefined4 *)(&stack0x000005e8 + lVar16);
        *(undefined8 *)(&stack0x000085c0 + lVar16) = *(undefined8 *)(&stack0x000005e0 + lVar16);
        *(undefined2 *)(&stack0x00000164 + lVar16) = *(undefined2 *)(lVar18 + 0xe + lVar35);
        *(undefined4 *)(&stack0x00000160 + lVar16) = *(undefined4 *)(lVar18 + 10 + lVar35);
        *(undefined4 *)(*(longlong *)(&stack0x00000048 + lVar16) + 4) =
             *(undefined4 *)(&stack0x00000004 + lVar16);
        uVar19 = *(undefined8 *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x10);
        if (*(char *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x48) == '\0') {
          plVar39 = *(longlong **)(&stack0x00000030 + lVar16);
          lVar17 = *plVar39;
          if (lVar17 == **(longlong **)(&stack0x00000038 + lVar16)) {
            *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140666d43;
            FUN_14079fa10();
            plVar29 = *(longlong **)((longlong)alStackX_8 + lVar16);
            goto LAB_140666d4b;
          }
          plVar29 = *(longlong **)((longlong)alStackX_8 + lVar16);
        }
        else {
          plVar39 = *(longlong **)(&stack0x00000040 + lVar16);
          lVar17 = *plVar39;
          if (lVar17 == **(longlong **)(&stack0x00000058 + lVar16)) {
            *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140666d22;
            FUN_14079fa10();
            plVar29 = *(longlong **)((longlong)alStackX_8 + lVar16 + 8);
LAB_140666d4b:
            lVar17 = *plVar39;
          }
          else {
            plVar29 = *(longlong **)((longlong)alStackX_8 + lVar16 + 8);
          }
        }
        lVar30 = *plVar29;
        lVar17 = lVar17 * 0x58;
        *(undefined1 *)(lVar30 + lVar17) = 5;
        *(undefined8 *)(lVar30 + 1 + lVar17) = *(undefined8 *)(&stack0x000085c0 + lVar16);
        *(undefined4 *)(lVar30 + 9 + lVar17) = *(undefined4 *)(&stack0x000085c8 + lVar16);
        *(char *)(lVar30 + 0xd + lVar17) = cVar14;
        *(undefined4 *)(lVar30 + 0xe + lVar17) = *(undefined4 *)(&stack0x00000160 + lVar16);
        *(undefined2 *)(lVar30 + 0x12 + lVar17) = *(undefined2 *)(&stack0x00000164 + lVar16);
        *(undefined8 *)(lVar30 + 0x20 + lVar17) = 1;
        *(ulonglong *)(lVar30 + 0x28 + lVar17) = uVar6;
        puVar4 = (undefined8 *)(lVar30 + 0x30 + lVar17);
        *puVar4 = uVar13;
        puVar4[1] = uVar8;
        puVar23 = (undefined4 *)(lVar30 + 0x40 + lVar17);
        *puVar23 = uVar43;
        puVar23[1] = uVar3;
        *(undefined4 *)(lVar30 + 0x48 + lVar17) = uVar2;
        *(undefined1 *)(lVar30 + 0x4d + lVar17) = 2;
        *(undefined8 *)(lVar30 + 0x50 + lVar17) = uVar19;
        *plVar39 = *plVar39 + 1;
        *(longlong *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x10) =
             *(longlong *)(*(longlong *)(&stack0xfffffffffffffff8 + lVar16) + 0x10) + 1;
        lVar17 = *(longlong *)(&stack0xffffffffffffffe8 + lVar16);
      }
      lVar35 = lVar35 + 0x18;
    } while (lVar17 != lVar35);
  }
  if (*(longlong *)(&stack0xfffffffffffffff0 + lVar16) != 0) {
    *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140666d80;
    FUN_1408192a0(lVar18,*(longlong *)(&stack0xfffffffffffffff0 + lVar16) * 0x18,8);
  }
  lVar18 = *(longlong *)(&stack0x000002d8 + lVar16);
  puVar4 = *(undefined8 **)(&stack0x000002e0 + lVar16);
  lVar17 = *(longlong *)(&stack0x000002e8 + lVar16);
  if (lVar17 != 0) {
    puVar31 = puVar4;
    do {
      cVar14 = *(char *)(puVar31 + 4);
      if (cVar14 == '\b') break;
      uVar13 = *puVar31;
      uVar8 = puVar31[1];
      uVar2 = *(undefined4 *)(puVar31 + 2);
      uVar43 = *(undefined4 *)((longlong)puVar31 + 0x14);
      uVar3 = *(undefined4 *)(puVar31 + 3);
      uVar12 = *(undefined4 *)((longlong)puVar31 + 0x1c);
      *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140666e0d;
      FUN_142244ca0(&stack0x000005e0 + lVar16,&stack0x00000060 + lVar16);
      uVar19 = *(undefined8 *)(&stack0x000005e0 + lVar16);
      plVar39 = (longlong *)**(longlong **)(&stack0x000005e8 + lVar16);
      lVar35 = plVar39[2];
      lVar30 = plVar39[5];
      if (lVar30 == plVar39[3]) {
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140666e39;
        FUN_14079f6c0(plVar39 + 3);
        lVar30 = plVar39[5];
      }
      lVar20 = plVar39[4];
      *(longlong *)(lVar20 + lVar30 * 0x10) = lVar35;
      *(code **)(lVar20 + 8 + lVar30 * 0x10) = FUN_140686dc0;
      plVar39[5] = plVar39[5] + 1;
      lVar30 = plVar39[2];
      if ((ulonglong)(*plVar39 - lVar30) < 0x30) {
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140666e7b;
        FUN_1407a1510(plVar39,lVar30,0x30);
      }
      lVar30 = plVar39[1];
      *(undefined8 *)(lVar30 + lVar35) = uVar19;
      puVar5 = (undefined8 *)(lVar30 + 8 + lVar35);
      *puVar5 = uVar13;
      puVar5[1] = uVar8;
      puVar23 = (undefined4 *)(lVar30 + 0x18 + lVar35);
      *puVar23 = uVar2;
      puVar23[1] = uVar43;
      puVar23[2] = uVar3;
      puVar23[3] = uVar12;
      *(char *)(lVar30 + 0x28 + lVar35) = cVar14;
      plVar39[2] = lVar35 + 0x30;
      puVar31 = puVar31 + 5;
    } while (puVar31 != puVar4 + lVar17 * 5);
  }
  if (lVar18 != 0) {
    *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140666ea2;
    FUN_1408192a0(puVar4,lVar18 * 0x28,8);
  }
  *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140666eab;
  plVar39 = (longlong *)FUN_142353b40(0);
  if (plVar39 == (longlong *)0x0) {
    *(undefined ***)(&stack0xffffffffffffffe0 + lVar16) =
         &PTR_s__rustc_11d96b59307b1702fffe871bf_14248c808;
    *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x14066790e;
    FUN_1423ab9f0("cannot access a Thread Local Storage value during or after destruction",0x46,
                  &stack0x000005e0 + lVar16,&PTR_LAB_14248ca08);
    goto LAB_14066793c;
  }
  lVar18 = *plVar39;
  lVar17 = plVar39[1];
  *plVar39 = *plVar39 + 1;
  *(undefined8 *)(&stack0x00000250 + lVar16) = 0;
  *(undefined8 *)(&stack0x00000258 + lVar16) = 0;
  *(undefined8 *)(&stack0x00000260 + lVar16) = 0;
  *(undefined **)(&stack0x00000268 + lVar16) = &DAT_142429eb0;
  *(longlong *)(&stack0x00000270 + lVar16) = lVar18;
  *(longlong *)(&stack0x00000278 + lVar16) = lVar17;
  lVar18 = *(longlong *)(&stack0x00000398 + lVar16);
  lVar17 = *(longlong *)(&stack0x000003a0 + lVar16);
  lVar35 = *(longlong *)(&stack0x000003a8 + lVar16);
  if (lVar35 != 0) {
    lVar30 = 0;
    do {
      cVar14 = *(char *)(lVar17 + 0xc + lVar30);
      if (cVar14 == 'J') break;
      *(undefined4 *)(&stack0x00000168 + lVar16) =
           *(undefined4 *)((undefined8 *)(lVar30 + lVar17) + 1);
      *(undefined8 *)(&stack0x00000160 + lVar16) = *(undefined8 *)(lVar30 + lVar17);
      (&stack0x000005e0)[lVar16] = cVar14;
      (&stack0x000005f1)[lVar16] = *(undefined1 *)(lVar17 + 0x1d + lVar30);
      puVar4 = (undefined8 *)(lVar17 + 0xd + lVar30);
      uVar19 = puVar4[1];
      *(undefined8 *)(&stack0x000005e1 + lVar16) = *puVar4;
      *(undefined8 *)(&stack0x000005e9 + lVar16) = uVar19;
      *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140666f77;
      FUN_14037c920(&stack0x000085c0 + lVar16,&stack0x00000250 + lVar16,&stack0x00000160 + lVar16,
                    &stack0x000005e0 + lVar16);
      lVar30 = lVar30 + 0x20;
    } while (lVar35 << 5 != lVar30);
  }
  if (lVar18 != 0) {
    *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140666f9a;
    FUN_1408192a0(lVar17,lVar18 << 5,4);
  }
  *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140666fa1;
  plVar39 = (longlong *)FUN_142353b40(0);
  if (plVar39 == (longlong *)0x0) {
    *(undefined ***)(&stack0xffffffffffffffe0 + lVar16) =
         &PTR_s__rustc_11d96b59307b1702fffe871bf_14248c808;
    *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x14066793c;
    FUN_1423ab9f0("cannot access a Thread Local Storage value during or after destruction",0x46,
                  &stack0x000005e0 + lVar16,&PTR_LAB_14248ca08);
LAB_14066793c:
                    /* WARNING: Does not return */
    pcVar9 = (code *)invalidInstructionException();
    (*pcVar9)();
  }
  lVar18 = *plVar39;
  lVar17 = plVar39[1];
  *plVar39 = *plVar39 + 1;
  *(undefined8 *)(&stack0x00000160 + lVar16) = 0;
  *(undefined8 *)(&stack0x00000168 + lVar16) = 0;
  *(undefined8 *)(&stack0x00000170 + lVar16) = 0;
  *(undefined **)(&stack0x00000178 + lVar16) = &DAT_142429eb0;
  *(longlong *)(&stack0x00000180 + lVar16) = lVar18;
  *(longlong *)(&stack0x00000188 + lVar16) = lVar17;
  *(undefined8 *)(&stack0x000001b0 + lVar16) = *(undefined8 *)(&stack0x00000270 + lVar16);
  *(undefined8 *)(&stack0x000001b8 + lVar16) = *(undefined8 *)(&stack0x00000278 + lVar16);
  *(undefined8 *)(&stack0x000001a0 + lVar16) = *(undefined8 *)(&stack0x00000260 + lVar16);
  *(undefined8 *)(&stack0x000001a8 + lVar16) = *(undefined8 *)(&stack0x00000268 + lVar16);
  *(undefined8 *)(&stack0x00000190 + lVar16) = *(undefined8 *)(&stack0x00000250 + lVar16);
  *(undefined8 *)(&stack0x00000198 + lVar16) = *(undefined8 *)(&stack0x00000258 + lVar16);
  puVar21 = *(ulonglong **)(&stack0x000003b8 + lVar16);
  *(undefined8 *)(&stack0x00000238 + lVar16) = *(undefined8 *)(&stack0x000003b0 + lVar16);
  *(undefined8 *)(&stack0x00000140 + lVar16) = *(undefined8 *)(&stack0x000003b0 + lVar16);
  *(ulonglong **)(&stack0x00000148 + lVar16) = puVar21;
  *(ulonglong **)((longlong)&lStackX_20 + lVar16) =
       puVar21 + *(longlong *)(&stack0x000003c0 + lVar16) * 5;
  *(ulonglong **)(&stack0x00000150 + lVar16) =
       puVar21 + *(longlong *)(&stack0x000003c0 + lVar16) * 5;
  *(ulonglong **)(&stack0x00000158 + lVar16) = puVar21;
  *(ulonglong **)(&stack0x00000230 + lVar16) = puVar21;
  puVar33 = puVar21;
  if (*(longlong *)(&stack0x000003c0 + lVar16) != 0) {
    do {
      puVar33 = puVar21 + 5;
      plVar39 = (longlong *)puVar21[3];
      if (plVar39 == (longlong *)0x0) goto LAB_1406674be;
      uVar6 = *puVar21;
      *(int *)(&stack0xffffffffffffffe8 + lVar16) = (int)puVar21[1];
      uVar24 = puVar21[2];
      uVar32 = puVar21[4];
      *(undefined8 *)(&stack0x00000088 + lVar16) = 0;
      *(undefined8 *)(&stack0x00000090 + lVar16) = 1;
      *(undefined8 *)(&stack0x00000098 + lVar16) = 0;
      if (uVar32 != 0) {
        lVar18 = 0;
        plVar29 = plVar39;
        do {
          lVar17 = plVar29[1];
          if ((char)lVar17 == '-') break;
          for (lVar35 = *plVar29; lVar35 != 0; lVar35 = lVar35 + -1) {
            if (lVar18 == *(longlong *)(&stack0x00000088 + lVar16)) {
              *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140667132;
              FUN_14079fd50(&stack0x00000088 + lVar16);
              lVar18 = *(longlong *)(&stack0x00000098 + lVar16);
            }
            *(char *)(*(longlong *)(&stack0x00000090 + lVar16) + lVar18) = (char)lVar17;
            lVar18 = *(longlong *)(&stack0x00000098 + lVar16) + 1;
            *(longlong *)(&stack0x00000098 + lVar16) = lVar18;
          }
          plVar29 = plVar29 + 2;
        } while (plVar29 != plVar39 + uVar32 * 2);
      }
      if (uVar24 != 0) {
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x14066715a;
        FUN_1408192a0(plVar39,uVar24 << 4,8);
      }
      *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x14066716f;
      FUN_142244ca0(&stack0x00000298 + lVar16,&stack0x00000060 + lVar16);
      plVar29 = *(longlong **)(&stack0x000002a0 + lVar16);
      uVar24 = *(ulonglong *)(&stack0x00000298 + lVar16);
      plVar39 = (longlong *)*plVar29;
      lVar18 = plVar39[2];
      lVar17 = plVar39[5];
      if (lVar17 == plVar39[3]) {
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x14066719b;
        FUN_14079f6c0(plVar39 + 3);
        lVar17 = plVar39[5];
      }
      lVar35 = plVar39[4];
      *(longlong *)(lVar35 + lVar17 * 0x10) = lVar18;
      *(code **)(lVar35 + 8 + lVar17 * 0x10) = FUN_14068a820;
      plVar39[5] = plVar39[5] + 1;
      lVar17 = plVar39[2];
      if ((ulonglong)(*plVar39 - lVar17) < 0x14) {
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x1406671d9;
        FUN_1407a1510(plVar39,lVar17,0x14);
      }
      lVar17 = plVar39[1];
      puVar21 = (ulonglong *)(lVar17 + lVar18);
      *puVar21 = uVar24;
      puVar21[1] = uVar6;
      *(undefined4 *)(lVar17 + 0x10 + lVar18) = *(undefined4 *)(&stack0xffffffffffffffe8 + lVar16);
      plVar39[2] = lVar18 + 0x14;
      uVar32 = *(ulonglong *)(&stack0x00000088 + lVar16);
      pcVar27 = *(char **)(&stack0x00000090 + lVar16);
      lVar18 = *(longlong *)(&stack0x00000098 + lVar16);
      pcVar34 = pcVar27;
      if (lVar18 != 0x8000) {
LAB_1406677f3:
        *(ulonglong **)(&stack0x00000148 + lVar16) = puVar33;
        *(ulonglong *)(&stack0x000085c0 + lVar16) = uVar32;
        *(char **)(&stack0x000085c8 + lVar16) = pcVar34;
        *(longlong *)(&stack0x000085d0 + lVar16) = lVar18;
        *(undefined ***)(&stack0xffffffffffffffe0 + lVar16) = &PTR_s_src_save_rs_14248fca8;
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x14066783f;
        FUN_1423ab9f0("called `Result::unwrap()` on an `Err` value",0x2b,&stack0x000085c0 + lVar16,
                      &PTR_LAB_14248cad8);
        goto LAB_14066793c;
      }
      cVar14 = *pcVar27;
      *(undefined4 *)(&stack0x00000083 + lVar16) = *(undefined4 *)(pcVar27 + 4);
      *(undefined4 *)(&stack0x00000080 + lVar16) = *(undefined4 *)(pcVar27 + 1);
      *(undefined8 *)(&stack0xfffffffffffffff0 + lVar16) = *(undefined8 *)(pcVar27 + 8);
      pcVar34 = *(char **)(pcVar27 + 0x10);
      lVar18 = *(longlong *)(pcVar27 + 0x18);
      *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140667263;
      memcpy(&stack0x000005e0 + lVar16,pcVar27 + 0x20,0x7fe0);
      if (uVar32 != 0) {
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x14066727d;
        FUN_1408192a0(pcVar27,uVar32,~uVar32 >> 0x3f);
      }
      if (cVar14 == '-') {
        uVar32 = *(ulonglong *)(&stack0xfffffffffffffff0 + lVar16);
        goto LAB_1406677f3;
      }
      *(undefined4 *)(&stack0x0000007b + lVar16) = *(undefined4 *)(&stack0x00000083 + lVar16);
      *(undefined4 *)(&stack0x00000078 + lVar16) = *(undefined4 *)(&stack0x00000080 + lVar16);
      *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x1406672b8;
      memcpy(&stack0x000085c0 + lVar16,&stack0x000005e0 + lVar16,0x7fe0);
      plVar39 = (longlong *)*plVar29;
      lVar17 = plVar39[2];
      lVar35 = plVar39[5];
      if (lVar35 == plVar39[3]) {
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x1406672d3;
        FUN_14079f6c0(plVar39 + 3);
        lVar35 = plVar39[5];
      }
      lVar30 = plVar39[4];
      *(longlong *)(lVar30 + lVar35 * 0x10) = lVar17;
      *(code **)(lVar30 + 8 + lVar35 * 0x10) = FUN_140685f90;
      plVar39[5] = plVar39[5] + 1;
      lVar35 = plVar39[2];
      if ((ulonglong)(*plVar39 - lVar35) < 0x8008) {
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140667313;
        FUN_1407a1510(plVar39,lVar35,0x8008);
      }
      lVar35 = plVar39[1];
      *(char *)(lVar35 + lVar17) = cVar14;
      uVar2 = *(undefined4 *)(&stack0x0000007b + lVar16);
      *(undefined4 *)(lVar35 + 1 + lVar17) = *(undefined4 *)(&stack0x00000078 + lVar16);
      *(undefined4 *)(lVar35 + 4 + lVar17) = uVar2;
      *(undefined8 *)(lVar35 + 8 + lVar17) = *(undefined8 *)(&stack0xfffffffffffffff0 + lVar16);
      *(char **)(lVar35 + 0x10 + lVar17) = pcVar34;
      *(longlong *)(lVar35 + 0x18 + lVar17) = lVar18;
      *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x14066735f;
      memcpy((void *)(lVar35 + lVar17 + 0x20),&stack0x000085c0 + lVar16,0x7fe0);
      uVar2 = (undefined4)uVar24;
      *(undefined4 *)(lVar35 + 0x8000 + lVar17) = uVar2;
      uVar43 = (undefined4)(uVar24 >> 0x20);
      *(undefined4 *)(lVar35 + 0x8004 + lVar17) = uVar43;
      plVar39[2] = lVar17 + 0x8008;
      plVar39 = (longlong *)*plVar29;
      lVar18 = plVar39[2];
      lVar17 = plVar39[5];
      if (lVar17 == plVar39[3]) {
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x14066739c;
        FUN_14079f6c0(plVar39 + 3);
        lVar17 = plVar39[5];
      }
      lVar35 = plVar39[4];
      *(longlong *)(lVar35 + lVar17 * 0x10) = lVar18;
      *(code **)(lVar35 + 8 + lVar17 * 0x10) = FUN_14068a060;
      plVar39[5] = plVar39[5] + 1;
      lVar17 = plVar39[2];
      if ((ulonglong)(*plVar39 - lVar17) < 8) {
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x1406673db;
        FUN_1407a1510(plVar39,lVar17,8);
      }
      lVar17 = plVar39[1];
      *(undefined4 *)(lVar17 + lVar18) = uVar2;
      *(undefined4 *)(lVar17 + 4 + lVar18) = uVar43;
      plVar39[2] = lVar18 + 8;
      plVar29 = (longlong *)*plVar29;
      lVar18 = plVar29[2];
      lVar17 = plVar29[5];
      if (lVar17 == plVar29[3]) {
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140667411;
        FUN_14079f6c0(plVar29 + 3);
        lVar17 = plVar29[5];
      }
      lVar35 = plVar29[4];
      *(longlong *)(lVar35 + lVar17 * 0x10) = lVar18;
      *(code **)(lVar35 + 8 + lVar17 * 0x10) = FUN_140692cc0;
      plVar29[5] = plVar29[5] + 1;
      lVar17 = plVar29[2];
      if ((ulonglong)(*plVar29 - lVar17) < 8) {
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140667450;
        FUN_1407a1510(plVar29,lVar17,8);
      }
      lVar17 = plVar29[1];
      *(undefined4 *)(lVar17 + lVar18) = uVar2;
      *(undefined4 *)(lVar17 + 4 + lVar18) = uVar43;
      plVar29[2] = lVar18 + 8;
      *(int *)(&stack0x000005e0 + lVar16) = (int)uVar6;
      *(int *)(&stack0x000005e4 + lVar16) = (int)(uVar6 >> 0x20);
      *(undefined4 *)(&stack0x000005e8 + lVar16) =
           *(undefined4 *)(&stack0xffffffffffffffe8 + lVar16);
      *(undefined4 *)(&stack0xffffffffffffffe0 + lVar16) = uVar43;
      *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x1406674ab;
      FUN_14037b0c0(&stack0x000085c0 + lVar16,&stack0x00000160 + lVar16,&stack0x000005e0 + lVar16,
                    uVar24 & 0xffffffff);
      puVar21 = puVar33;
    } while (puVar33 != *(ulonglong **)((longlong)&lStackX_20 + lVar16));
    puVar33 = *(ulonglong **)((longlong)&lStackX_20 + lVar16);
LAB_1406674be:
    *(ulonglong **)(&stack0x00000148 + lVar16) = puVar33;
  }
  puVar21 = *(ulonglong **)((longlong)&lStackX_20 + lVar16);
  if (puVar21 != puVar33) {
    lVar18 = 0;
    do {
      lVar17 = *(longlong *)((longlong)puVar33 + lVar18 + 0x10);
      if (lVar17 != 0) {
        uVar19 = *(undefined8 *)((longlong)puVar33 + lVar18 + 0x18);
        *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140667527;
        FUN_1408192a0(uVar19,lVar17 << 4,8);
      }
      lVar18 = lVar18 + 0x28;
    } while (((ulonglong)((longlong)puVar21 - (longlong)puVar33) / 0x28) * 0x28 != lVar18);
  }
  if (*(longlong *)(&stack0x00000238 + lVar16) != 0) {
    *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140667558;
    FUN_1408192a0(*(undefined8 *)(&stack0x00000230 + lVar16),
                  *(longlong *)(&stack0x00000238 + lVar16) * 0x28,8);
  }
  lVar18 = *(longlong *)(&stack0x000003d8 + lVar16);
  plVar25 = *(longlong **)(&stack0x00000248 + lVar16);
  if (lVar18 != 0) {
    lVar17 = *(longlong *)(&stack0x000003d0 + lVar16);
    lVar35 = 0;
    do {
      uVar2 = *(undefined4 *)(lVar17 + 8 + lVar35);
      *(undefined8 *)(&stack0x000005e0 + lVar16) = *(undefined8 *)(lVar17 + lVar35);
      *(undefined4 *)(&stack0x000005e8 + lVar16) = uVar2;
      *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x1406675ba;
      FUN_140717fa0(&stack0x00000060 + lVar16,*(undefined8 *)(&stack0x00000138 + lVar16),
                    &stack0x000005e0 + lVar16);
      lVar35 = lVar35 + 0xc;
    } while (lVar18 * 0xc != lVar35);
  }
  lVar18 = *(longlong *)(&stack0x000003f0 + lVar16);
  if (lVar18 != 0) {
    lVar17 = *(longlong *)(&stack0x000003e8 + lVar16);
    lVar35 = 0;
    do {
      uVar2 = *(undefined4 *)(lVar17 + 8 + lVar35);
      *(undefined8 *)(&stack0x000005e0 + lVar16) = *(undefined8 *)(lVar17 + lVar35);
      *(undefined4 *)(&stack0x000005e8 + lVar16) = uVar2;
      *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x14066762a;
      FUN_140718480(&stack0x00000060 + lVar16,*(undefined8 *)(&stack0x00000138 + lVar16),
                    &stack0x000005e0 + lVar16);
      lVar35 = lVar35 + 0xc;
    } while (lVar18 * 0xc != lVar35);
  }
  *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x14066764b;
  FUN_142244ca0(&stack0x000085c0 + lVar16,&stack0x00000060 + lVar16);
  *(undefined8 *)(&stack0x00000630 + lVar16) = *(undefined8 *)(&stack0x000001b0 + lVar16);
  *(undefined8 *)(&stack0x00000638 + lVar16) = *(undefined8 *)(&stack0x000001b8 + lVar16);
  *(undefined8 *)(&stack0x00000620 + lVar16) = *(undefined8 *)(&stack0x000001a0 + lVar16);
  *(undefined8 *)(&stack0x00000628 + lVar16) = *(undefined8 *)(&stack0x000001a8 + lVar16);
  *(undefined4 *)(&stack0x00000610 + lVar16) = *(undefined4 *)(&stack0x00000190 + lVar16);
  *(undefined4 *)(&stack0x00000614 + lVar16) = *(undefined4 *)(&stack0x00000194 + lVar16);
  *(undefined4 *)(&stack0x00000618 + lVar16) = *(undefined4 *)(&stack0x00000198 + lVar16);
  *(undefined4 *)(&stack0x0000061c + lVar16) = *(undefined4 *)(&stack0x0000019c + lVar16);
  *(undefined4 *)(&stack0x00000600 + lVar16) = *(undefined4 *)(&stack0x00000180 + lVar16);
  *(undefined4 *)(&stack0x00000604 + lVar16) = *(undefined4 *)(&stack0x00000184 + lVar16);
  *(undefined4 *)(&stack0x00000608 + lVar16) = *(undefined4 *)(&stack0x00000188 + lVar16);
  *(undefined4 *)(&stack0x0000060c + lVar16) = *(undefined4 *)(&stack0x0000018c + lVar16);
  *(undefined4 *)(&stack0x000005f0 + lVar16) = *(undefined4 *)(&stack0x00000170 + lVar16);
  *(undefined4 *)(&stack0x000005f4 + lVar16) = *(undefined4 *)(&stack0x00000174 + lVar16);
  *(undefined4 *)(&stack0x000005f8 + lVar16) = *(undefined4 *)(&stack0x00000178 + lVar16);
  *(undefined4 *)(&stack0x000005fc + lVar16) = *(undefined4 *)(&stack0x0000017c + lVar16);
  *(undefined8 *)(&stack0x000005e0 + lVar16) = *(undefined8 *)(&stack0x00000160 + lVar16);
  *(undefined8 *)(&stack0x000005e8 + lVar16) = *(undefined8 *)(&stack0x00000168 + lVar16);
  *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x1406676bd;
  FUN_1401a51e0(&stack0x000085c0 + lVar16);
  *(undefined4 *)(*(longlong *)(&stack0x000001e0 + lVar16) + 4) =
       *(undefined4 *)(&stack0x000000b0 + lVar16);
  **(undefined1 **)(&stack0x000001d8 + lVar16) = 0xb;
  if (*(longlong *)(&stack0x000002c0 + lVar16) != 0) {
    *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140667705;
    FUN_1408192a0(*(undefined8 *)(&stack0x000002c8 + lVar16),
                  *(longlong *)(&stack0x000002c0 + lVar16) * 0x1c,4);
  }
  if (*(longlong *)(&stack0x000003c8 + lVar16) != 0) {
    *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x14066772d;
    FUN_1408192a0(*(undefined8 *)(&stack0x000003d0 + lVar16),
                  *(longlong *)(&stack0x000003c8 + lVar16) * 0xc,4);
  }
  if (*(longlong *)(&stack0x000003e0 + lVar16) != 0) {
    *(undefined8 *)((longlong)&uStack_48 + lVar16) = 0x140667759;
    FUN_1408192a0(*(undefined8 *)(&stack0x000003e8 + lVar16),
                  *(longlong *)(&stack0x000003e0 + lVar16) * 0xc,4);
  }
  uVar19 = *(undefined8 *)(&stack0x00000120 + lVar16);
  lVar18 = *(longlong *)(&stack0x000001d0 + lVar16);
  plVar29 = *(longlong **)(&stack0x00000240 + lVar16);
  goto LAB_140665658;
}

