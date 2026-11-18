
longlong * FUN_1404a81c0(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong *plVar3;
  char *pcVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  undefined7 uVar13;
  undefined8 uVar9;
  undefined7 uVar14;
  longlong lVar10;
  undefined8 uVar11;
  longlong lVar12;
  undefined1 uVar15;
  char *pcVar16;
  longlong lVar17;
  longlong lVar18;
  byte bVar19;
  char cVar20;
  undefined1 *puVar21;
  undefined8 uVar22;
  char cVar23;
  undefined7 uVar27;
  undefined8 uVar24;
  longlong *plVar25;
  longlong *plVar26;
  uint7 uVar30;
  byte *pbVar28;
  undefined8 uVar29;
  char cVar31;
  undefined7 uVar33;
  undefined8 uVar32;
  char cVar34;
  undefined7 uVar35;
  uint7 uVar37;
  undefined8 uVar36;
  bool bVar38;
  longlong alStackX_8 [4];
  undefined8 uStack_48;
  
  uStack_48 = 0x1404a81d6;
  lVar7 = FUN_1423d0c90();
  lVar7 = -lVar7;
  *(undefined8 *)(&stack0x000000c0 + lVar7) = param_1;
  pcVar16 = (char *)(param_2 + 0x78);
  plVar25 = (longlong *)(param_2 + 0x18);
  pbVar28 = (byte *)(param_2 + 0x79);
  *(longlong *)(&stack0xfffffffffffffff8 + lVar7) = param_2 + 0x30;
  *(longlong *)(&stack0xfffffffffffffff0 + lVar7) = param_2 + 0x68;
  puVar1 = (undefined8 *)(param_2 + 0x60);
  plVar26 = (longlong *)(param_2 + 0x20);
  *(longlong *)(&stack0x00000050 + lVar7) = param_2;
  plVar2 = (longlong *)(param_2 + 0x28);
  while( true ) {
    if (*pcVar16 == '\0') {
      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a824d;
      FUN_14019d5e0(&stack0x00000420 + lVar7,*(undefined8 *)(&stack0xfffffffffffffff8 + lVar7));
      if ((&stack0x00000420)[lVar7] != '\0') {
        if ((&stack0x00000420)[lVar7] != '\x02') {
          *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9462;
          lVar12 = FUN_1413e9060(*(undefined8 *)(&stack0x00000428 + lVar7));
          goto LAB_1404a978c;
        }
        uVar9 = *puVar1;
        uVar22 = **(undefined8 **)(&stack0xfffffffffffffff0 + lVar7);
        *(undefined8 *)(&stack0x00000420 + lVar7) = 5;
        goto LAB_1404a977f;
      }
      bVar19 = (&stack0x00000421)[lVar7];
      lVar12 = **(longlong **)(&stack0xfffffffffffffff0 + lVar7) + 1;
      if (bVar19 == 10) {
        lVar8 = *(longlong *)(&stack0x00000050 + lVar7);
        plVar3 = (longlong *)(lVar8 + 0x70);
        *plVar3 = *plVar3 + lVar12;
        plVar3 = (longlong *)(lVar8 + 0x60);
        *plVar3 = *plVar3 + 1;
        lVar12 = 0;
      }
      **(longlong **)(&stack0xfffffffffffffff0 + lVar7) = lVar12;
      *pcVar16 = '\x01';
      *pbVar28 = bVar19;
    }
    else {
      bVar19 = *pbVar28;
    }
    if ((0x20 < bVar19) || ((0x100002600U >> ((ulonglong)bVar19 & 0x3f) & 1) == 0)) break;
    *pcVar16 = '\0';
    lVar12 = *plVar26;
    if (lVar12 != 0) {
      lVar8 = *plVar2;
      if (lVar8 == *plVar25) {
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a82d4;
        FUN_14079fd50(plVar25);
        lVar8 = *plVar2;
        lVar12 = *plVar26;
      }
      *(byte *)(lVar12 + lVar8) = bVar19;
      *plVar2 = *plVar2 + 1;
    }
  }
  if (bVar19 != 0x5b) {
    lVar12 = *(longlong *)(&stack0x00000050 + lVar7);
    if (bVar19 == 0x7b) {
      pcVar4 = (char *)(lVar12 + 0x80);
      *pcVar4 = *pcVar4 + -1;
      if (*pcVar4 != '\0') {
        *pcVar16 = '\0';
        lVar8 = *plVar26;
        if (lVar8 != 0) {
          lVar10 = *plVar2;
          if (lVar10 == *plVar25) {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8324;
            FUN_14079fd50(plVar25);
            lVar10 = *plVar2;
            lVar8 = *plVar26;
          }
          *(undefined1 *)(lVar8 + lVar10) = 0x7b;
          *plVar2 = *plVar2 + 1;
        }
        *(undefined8 **)((longlong)alStackX_8 + lVar7 + -8) = puVar1;
        (&stack0x00000930)[lVar7] = 2;
        *(undefined8 *)(&stack0x00000178 + lVar7) = 0;
        *(undefined8 *)(&stack0x00000198 + lVar7) = 0;
        *(undefined8 *)(&stack0x000001b8 + lVar7) = 0;
        *(undefined8 *)(&stack0x000001d8 + lVar7) = 0;
        *(undefined8 *)(&stack0x000001f8 + lVar7) = 0;
        *(undefined8 *)(&stack0x00000218 + lVar7) = 0;
        *(undefined8 *)(&stack0x00000238 + lVar7) = 0;
        *(undefined8 *)(&stack0x00000288 + lVar7) = 0;
        *(undefined8 *)(&stack0x000002a8 + lVar7) = 0;
        *(undefined8 *)(&stack0x00000258 + lVar7) = 0;
        *(undefined8 *)(&stack0x00000138 + lVar7) = 0;
        *(undefined8 *)(&stack0x000003b8 + lVar7) = 0;
        *(undefined8 *)(&stack0x00000270 + lVar7) = 0;
        *(undefined8 *)(&stack0x00000060 + lVar7) = 0;
        *(undefined8 *)(&stack0x000000b0 + lVar7) = 0;
        *(undefined8 *)(&stack0x000000b8 + lVar7) = 0;
        *(undefined8 *)(&stack0x00000078 + lVar7) = 0;
        *(undefined8 *)(&stack0x00000080 + lVar7) = 0;
        *(undefined8 *)(&stack0x00000088 + lVar7) = 0;
        *(undefined8 *)(&stack0x00000090 + lVar7) = 0;
        *(undefined8 *)(&stack0x00000098 + lVar7) = 0;
        *(undefined8 *)(&stack0x000000a0 + lVar7) = 0;
        *(undefined8 *)(&stack0x000000a8 + lVar7) = 0;
        *(undefined8 *)(&stack0x000000e8 + lVar7) = 0;
        *(undefined8 *)(&stack0x00000068 + lVar7) = 0;
        *(undefined8 *)(&stack0x00000070 + lVar7) = 0;
        bVar38 = false;
        *(undefined8 *)((longlong)alStackX_8 + lVar7 + 8) = 0;
LAB_1404a848e:
        uVar30 = (uint7)((ulonglong)pbVar28 >> 8);
        uVar37 = (uint7)((ulonglong)plVar25 >> 8);
        if (*pcVar16 == '\0') {
          *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a84c2;
          FUN_14019d5e0(&stack0x00000420 + lVar7,*(undefined8 *)(&stack0xfffffffffffffff8 + lVar7));
          if ((&stack0x00000420)[lVar7] == '\0') {
            bVar19 = (&stack0x00000421)[lVar7];
            lVar8 = **(longlong **)(&stack0xfffffffffffffff0 + lVar7) + 1;
            if (bVar19 == 10) {
              *(longlong *)(lVar12 + 0x70) = *(longlong *)(lVar12 + 0x70) + lVar8;
              *(longlong *)(lVar12 + 0x60) = *(longlong *)(lVar12 + 0x60) + 1;
              lVar8 = 0;
            }
            **(longlong **)(&stack0xfffffffffffffff0 + lVar7) = lVar8;
            *pcVar16 = '\x01';
            *pbVar28 = bVar19;
            goto joined_r0x0001404a8508;
          }
          if ((&stack0x00000420)[lVar7] == '\x02') {
            uVar9 = **(undefined8 **)((longlong)alStackX_8 + lVar7 + -8);
            uVar22 = **(undefined8 **)(&stack0xfffffffffffffff0 + lVar7);
            *(undefined8 *)(&stack0x00000420 + lVar7) = 3;
            uVar13 = (undefined7)
                     ((ulonglong)*(undefined8 **)(&stack0xfffffffffffffff0 + lVar7) >> 8);
            *(ulonglong *)(&stack0x00000028 + lVar7) = CONCAT71(uVar13,1);
            *(ulonglong *)(&stack0x00000040 + lVar7) = CONCAT71(uVar13,1);
            *(ulonglong *)(&stack0x00000030 + lVar7) = CONCAT71(uVar13,1);
            *(ulonglong *)(&stack0x00000038 + lVar7) = CONCAT71(uVar13,1);
            *(ulonglong *)(&stack0x00000048 + lVar7) = CONCAT71(uVar13,1);
            *(ulonglong *)(&stack0x00000058 + lVar7) = CONCAT71(uVar13,1);
            pbVar28 = (byte *)((ulonglong)uVar30 << 8);
            plVar25 = (longlong *)((ulonglong)uVar37 << 8);
            lVar17 = *(longlong *)(&stack0x00000060 + lVar7);
            lVar10 = *(longlong *)(&stack0x00000068 + lVar7);
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9146;
            lVar8 = FUN_1413e8fd0(&stack0x00000420 + lVar7,uVar9,uVar22);
            *(longlong *)((longlong)alStackX_8 + lVar7) = lVar8;
            goto LAB_1404a914e;
          }
          uVar9 = *(undefined8 *)(&stack0x00000428 + lVar7);
          lVar17 = *(longlong *)(&stack0x00000060 + lVar7);
          lVar10 = *(longlong *)(&stack0x00000068 + lVar7);
LAB_1404a92bd:
          *(undefined8 *)(&stack0x00000028 + lVar7) = 1;
          *(undefined8 *)(&stack0x00000040 + lVar7) = 1;
          *(undefined8 *)(&stack0x00000030 + lVar7) = 1;
          *(undefined8 *)(&stack0x00000038 + lVar7) = 1;
          *(undefined8 *)(&stack0x00000048 + lVar7) = 1;
          *(undefined8 *)(&stack0x00000058 + lVar7) = 1;
          *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9307;
          uVar9 = FUN_1413e9060(uVar9);
          *(undefined8 *)((longlong)alStackX_8 + lVar7) = uVar9;
LAB_1404a930c:
          uVar24 = CONCAT71(uVar30,1);
          lVar18 = CONCAT71(uVar37,1);
          cVar34 = '\x01';
          cVar31 = '\x01';
          cVar20 = '\x01';
          uVar13 = (undefined7)((ulonglong)uVar9 >> 8);
          *(ulonglong *)(&stack0xfffffffffffffff0 + lVar7) = CONCAT71(uVar13,1);
          *(ulonglong *)(&stack0xfffffffffffffff8 + lVar7) = CONCAT71(uVar13,1);
          *(ulonglong *)((longlong)alStackX_8 + lVar7 + -8) = CONCAT71(uVar13,1);
          *(ulonglong *)((longlong)alStackX_8 + lVar7 + 8) = CONCAT71(uVar13,1);
          *(ulonglong *)((longlong)alStackX_8 + lVar7 + 0x10) = CONCAT71(uVar13,1);
          *(ulonglong *)((longlong)alStackX_8 + lVar7 + 0x18) = CONCAT71(uVar13,1);
          cVar23 = '\x01';
          goto LAB_1404aac28;
        }
        bVar19 = *pbVar28;
joined_r0x0001404a8508:
        if (bVar19 < 0x2d) {
          if ((0x100002600U >> ((ulonglong)bVar19 & 0x3f) & 1) == 0) {
            if ((ulonglong)bVar19 != 0x2c) goto LAB_1404a858f;
            lVar10 = *(longlong *)(&stack0x00000068 + lVar7);
            if (bVar38) {
              *pcVar16 = '\0';
              lVar8 = *plVar26;
              if (lVar8 == 0) goto LAB_1404a8ea0;
              lVar17 = *plVar2;
              if (lVar17 == *plVar25) {
                *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a857f;
                FUN_14079fd50(plVar25);
                lVar17 = *plVar2;
                lVar8 = *plVar26;
              }
              *(undefined1 *)(lVar8 + lVar17) = 0x2c;
              do {
                *plVar2 = *plVar2 + 1;
LAB_1404a8ea0:
                do {
                  if (*pcVar16 == '\0') {
                    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8ed2;
                    FUN_14019d5e0(&stack0x00000420 + lVar7,
                                  *(undefined8 *)(&stack0xfffffffffffffff8 + lVar7));
                    if ((&stack0x00000420)[lVar7] != '\0') {
                      if ((&stack0x00000420)[lVar7] != '\x02') {
                        uVar9 = *(undefined8 *)(&stack0x00000428 + lVar7);
                        lVar17 = *(longlong *)(&stack0x00000060 + lVar7);
                        goto LAB_1404a92bd;
                      }
                      uVar9 = **(undefined8 **)((longlong)alStackX_8 + lVar7 + -8);
                      uVar22 = **(undefined8 **)(&stack0xfffffffffffffff0 + lVar7);
                      *(undefined8 *)(&stack0x00000420 + lVar7) = 5;
                      uVar13 = (undefined7)
                               ((ulonglong)*(undefined8 **)(&stack0xfffffffffffffff0 + lVar7) >> 8);
                      *(ulonglong *)(&stack0x00000028 + lVar7) = CONCAT71(uVar13,1);
                      *(ulonglong *)(&stack0x00000040 + lVar7) = CONCAT71(uVar13,1);
                      *(ulonglong *)(&stack0x00000030 + lVar7) = CONCAT71(uVar13,1);
                      *(ulonglong *)(&stack0x00000038 + lVar7) = CONCAT71(uVar13,1);
                      *(ulonglong *)(&stack0x00000048 + lVar7) = CONCAT71(uVar13,1);
                      *(ulonglong *)(&stack0x00000058 + lVar7) = CONCAT71(uVar13,1);
                      pbVar28 = (byte *)((ulonglong)uVar30 << 8);
                      plVar25 = (longlong *)((ulonglong)uVar37 << 8);
                      lVar17 = *(longlong *)(&stack0x00000060 + lVar7);
                      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a975d;
                      lVar8 = FUN_1413e8fd0(&stack0x00000420 + lVar7,uVar9,uVar22);
                      *(longlong *)((longlong)alStackX_8 + lVar7) = lVar8;
                      goto LAB_1404a914e;
                    }
                    bVar19 = (&stack0x00000421)[lVar7];
                    lVar8 = **(longlong **)(&stack0xfffffffffffffff0 + lVar7) + 1;
                    if (bVar19 == 10) {
                      *(longlong *)(lVar12 + 0x70) = *(longlong *)(lVar12 + 0x70) + lVar8;
                      *(longlong *)(lVar12 + 0x60) = *(longlong *)(lVar12 + 0x60) + 1;
                      lVar8 = 0;
                    }
                    **(longlong **)(&stack0xfffffffffffffff0 + lVar7) = lVar8;
                    *pcVar16 = '\x01';
                    *pbVar28 = bVar19;
                  }
                  else {
                    bVar19 = *pbVar28;
                  }
                  if ((0x20 < bVar19) || ((0x100002600U >> ((ulonglong)bVar19 & 0x3f) & 1) == 0))
                  goto LAB_1404a85aa;
                  *pcVar16 = '\0';
                  lVar8 = *plVar26;
                } while (lVar8 == 0);
                lVar17 = *plVar2;
                if (lVar17 == *plVar25) {
                  *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8f53;
                  FUN_14079fd50(plVar25);
                  lVar17 = *plVar2;
                  lVar8 = *plVar26;
                }
                *(byte *)(lVar8 + lVar17) = bVar19;
              } while( true );
            }
LAB_1404a9d11:
            uVar9 = **(undefined8 **)((longlong)alStackX_8 + lVar7 + -8);
            uVar22 = **(undefined8 **)(&stack0xfffffffffffffff0 + lVar7);
            *(undefined8 *)(&stack0x00000420 + lVar7) = 0x11;
            uVar13 = (undefined7)
                     ((ulonglong)*(undefined8 **)(&stack0xfffffffffffffff0 + lVar7) >> 8);
            *(ulonglong *)(&stack0x00000028 + lVar7) = CONCAT71(uVar13,1);
            *(ulonglong *)(&stack0x00000040 + lVar7) = CONCAT71(uVar13,1);
            *(ulonglong *)(&stack0x00000030 + lVar7) = CONCAT71(uVar13,1);
            *(ulonglong *)(&stack0x00000038 + lVar7) = CONCAT71(uVar13,1);
            *(ulonglong *)(&stack0x00000048 + lVar7) = CONCAT71(uVar13,1);
            *(ulonglong *)(&stack0x00000058 + lVar7) = CONCAT71(uVar13,1);
            pbVar28 = (byte *)((ulonglong)uVar30 << 8);
            plVar25 = (longlong *)((ulonglong)uVar37 << 8);
            lVar17 = *(longlong *)(&stack0x00000060 + lVar7);
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9d87;
            lVar8 = FUN_1413e8fd0(&stack0x00000420 + lVar7,uVar9,uVar22);
            *(longlong *)((longlong)alStackX_8 + lVar7) = lVar8;
            goto LAB_1404a914e;
          }
          *pcVar16 = '\0';
          lVar8 = *plVar26;
          if (lVar8 != 0) {
            lVar10 = *plVar2;
            if (lVar10 == *plVar25) {
              *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8542;
              FUN_14079fd50(plVar25);
              lVar10 = *plVar2;
              lVar8 = *plVar26;
            }
            *(byte *)(lVar8 + lVar10) = bVar19;
            *plVar2 = *plVar2 + 1;
          }
          goto LAB_1404a848e;
        }
LAB_1404a858f:
        if (bVar19 == 0x7d) {
          if (*(longlong *)((longlong)alStackX_8 + lVar7 + 8) == 0) {
            *(undefined8 *)(&stack0x00000028 + lVar7) = 1;
            *(undefined8 *)(&stack0x00000040 + lVar7) = 1;
            *(undefined8 *)(&stack0x00000030 + lVar7) = 1;
            *(undefined8 *)(&stack0x00000038 + lVar7) = 1;
            *(undefined8 *)(&stack0x00000048 + lVar7) = 1;
            *(undefined8 *)(&stack0x00000058 + lVar7) = 1;
            lVar17 = *(longlong *)(&stack0x00000060 + lVar7);
            lVar10 = *(longlong *)(&stack0x00000068 + lVar7);
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a97ff;
            uVar9 = FUN_14020dc40("player",6);
            *(undefined8 *)((longlong)alStackX_8 + lVar7) = uVar9;
            goto LAB_1404a930c;
          }
          lVar17 = *(longlong *)(&stack0x00000060 + lVar7);
          lVar10 = *(longlong *)(&stack0x00000068 + lVar7);
          uVar13 = (undefined7)((ulonglong)pcVar16 >> 8);
          uVar27 = (undefined7)((ulonglong)plVar26 >> 8);
          uVar35 = (undefined7)((ulonglong)lVar12 >> 8);
          uVar33 = (undefined7)((ulonglong)plVar2 >> 8);
          if ((&stack0x00000930)[lVar7] == '\x02') {
            *(undefined8 *)(&stack0x00000028 + lVar7) = 1;
            *(undefined8 *)(&stack0x00000040 + lVar7) = 1;
            *(undefined8 *)(&stack0x00000030 + lVar7) = 1;
            *(undefined8 *)(&stack0x00000038 + lVar7) = 1;
            *(undefined8 *)(&stack0x00000048 + lVar7) = 1;
            *(undefined8 *)(&stack0x00000058 + lVar7) = 1;
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a94e7;
            uVar9 = FUN_14020dc40("story",5);
            *(undefined8 *)((longlong)alStackX_8 + lVar7) = uVar9;
            uVar14 = (undefined7)((ulonglong)uVar9 >> 8);
            *(ulonglong *)(&stack0x00000040 + lVar7) = CONCAT71(uVar14,1);
            *(ulonglong *)(&stack0x00000030 + lVar7) = CONCAT71(uVar14,1);
            *(ulonglong *)(&stack0x00000038 + lVar7) = CONCAT71(uVar14,1);
            *(ulonglong *)(&stack0x00000048 + lVar7) = CONCAT71(uVar14,1);
            *(ulonglong *)(&stack0x00000058 + lVar7) = CONCAT71(uVar14,1);
            uVar22 = CONCAT71(uVar13,1);
            uVar24 = CONCAT71(uVar27,1);
            uVar29 = CONCAT71(uVar30,1);
            uVar36 = CONCAT71(uVar37,1);
            uVar9 = CONCAT71(uVar35,1);
            uVar11 = CONCAT71(uVar33,1);
          }
          else {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9860;
            memcpy(&stack0x00000420 + lVar7,&stack0x000008f8 + lVar7,0x1e8);
            if (*(longlong *)(&stack0x00000070 + lVar7) == 0) {
              *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9aad;
              uVar9 = FUN_14020dc40("nodes",5);
              *(undefined8 *)((longlong)alStackX_8 + lVar7) = uVar9;
              uVar13 = (undefined7)((ulonglong)uVar9 >> 8);
              *(ulonglong *)(&stack0x00000028 + lVar7) = CONCAT71(uVar13,1);
              uVar24 = CONCAT71(uVar30,1);
              uVar36 = CONCAT71(uVar37,1);
              uVar22 = CONCAT71(uVar27,1);
              uVar29 = CONCAT71(uVar35,1);
              *(ulonglong *)(&stack0x00000058 + lVar7) = CONCAT71(uVar13,1);
              *(ulonglong *)(&stack0xfffffffffffffff0 + lVar7) = CONCAT71(uVar13,1);
              *(ulonglong *)(&stack0xfffffffffffffff8 + lVar7) = CONCAT71(uVar13,1);
              *(ulonglong *)((longlong)alStackX_8 + lVar7 + -8) = CONCAT71(uVar13,1);
              *(ulonglong *)((longlong)alStackX_8 + lVar7 + 8) = CONCAT71(uVar13,1);
              uVar9 = CONCAT71(uVar13,1);
            }
            else {
              *(undefined8 *)(&stack0x000002d0 + lVar7) = *(undefined8 *)(&stack0x00000180 + lVar7);
              *(undefined4 *)(&stack0x000002c0 + lVar7) = *(undefined4 *)(&stack0x00000170 + lVar7);
              *(undefined4 *)(&stack0x000002c4 + lVar7) = *(undefined4 *)(&stack0x00000174 + lVar7);
              *(undefined4 *)(&stack0x000002c8 + lVar7) = *(undefined4 *)(&stack0x00000178 + lVar7);
              *(undefined4 *)(&stack0x000002cc + lVar7) = *(undefined4 *)(&stack0x0000017c + lVar7);
              if (lVar10 == 0) {
                *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9cbd;
                uVar9 = FUN_14020dc40("edges",5);
                uVar32 = CONCAT71(uVar33,1);
                uVar24 = CONCAT71(uVar30,1);
                uVar36 = CONCAT71(uVar37,1);
                uVar22 = CONCAT71(uVar27,1);
                uVar29 = CONCAT71(uVar35,1);
                uVar13 = (undefined7)((ulonglong)uVar9 >> 8);
                *(ulonglong *)(&stack0x00000058 + lVar7) = CONCAT71(uVar13,1);
                *(ulonglong *)(&stack0xfffffffffffffff0 + lVar7) = CONCAT71(uVar13,1);
                *(ulonglong *)(&stack0xfffffffffffffff8 + lVar7) = CONCAT71(uVar13,1);
                *(ulonglong *)((longlong)alStackX_8 + lVar7 + -8) = CONCAT71(uVar13,1);
                uVar11 = CONCAT71(uVar13,1);
              }
              else {
                *(undefined8 *)(&stack0x000002f0 + lVar7) =
                     *(undefined8 *)(&stack0x000001a0 + lVar7);
                *(undefined4 *)(&stack0x000002e0 + lVar7) =
                     *(undefined4 *)(&stack0x00000190 + lVar7);
                *(undefined4 *)(&stack0x000002e4 + lVar7) =
                     *(undefined4 *)(&stack0x00000194 + lVar7);
                *(undefined4 *)(&stack0x000002e8 + lVar7) =
                     *(undefined4 *)(&stack0x00000198 + lVar7);
                *(undefined4 *)(&stack0x000002ec + lVar7) =
                     *(undefined4 *)(&stack0x0000019c + lVar7);
                if (*(longlong *)(&stack0x000000e8 + lVar7) == 0) {
                  *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9dbe;
                  uVar9 = FUN_14020dc40("endpoints",9);
                  uVar32 = CONCAT71(uVar33,1);
                  uVar24 = CONCAT71(uVar30,1);
                  uVar36 = CONCAT71(uVar37,1);
                  uVar22 = CONCAT71(uVar27,1);
                  uVar29 = CONCAT71(uVar35,1);
                  uVar13 = (undefined7)((ulonglong)uVar9 >> 8);
                  *(ulonglong *)(&stack0x00000058 + lVar7) = CONCAT71(uVar13,1);
                  *(ulonglong *)(&stack0xfffffffffffffff0 + lVar7) = CONCAT71(uVar13,1);
                  *(ulonglong *)(&stack0xfffffffffffffff8 + lVar7) = CONCAT71(uVar13,1);
                  *(ulonglong *)((longlong)alStackX_8 + lVar7 + -8) = CONCAT71(uVar13,1);
                }
                else {
                  *(undefined8 *)(&stack0x00000310 + lVar7) =
                       *(undefined8 *)(&stack0x000001c0 + lVar7);
                  *(undefined4 *)(&stack0x00000300 + lVar7) =
                       *(undefined4 *)(&stack0x000001b0 + lVar7);
                  *(undefined4 *)(&stack0x00000304 + lVar7) =
                       *(undefined4 *)(&stack0x000001b4 + lVar7);
                  *(undefined4 *)(&stack0x00000308 + lVar7) =
                       *(undefined4 *)(&stack0x000001b8 + lVar7);
                  *(undefined4 *)(&stack0x0000030c + lVar7) =
                       *(undefined4 *)(&stack0x000001bc + lVar7);
                  uVar24 = *(undefined8 *)(&stack0x000003d0 + lVar7);
                  uVar27 = (undefined7)((ulonglong)uVar24 >> 8);
                  if (*(longlong *)(&stack0x000000a8 + lVar7) == 0) {
                    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa23f;
                    uVar9 = FUN_14020dc40("relays",6);
                    *(undefined8 *)((longlong)alStackX_8 + lVar7) = uVar9;
                    uVar32 = CONCAT71(uVar33,1);
                    uVar24 = CONCAT71(uVar27,1);
                    uVar36 = CONCAT71(uVar37,1);
                    uVar22 = CONCAT71(uVar13,1);
                    uVar29 = CONCAT71(uVar35,1);
                    uVar13 = (undefined7)((ulonglong)uVar9 >> 8);
                    *(ulonglong *)(&stack0x00000058 + lVar7) = CONCAT71(uVar13,1);
                    *(ulonglong *)(&stack0xfffffffffffffff0 + lVar7) = CONCAT71(uVar13,1);
                    uVar9 = CONCAT71(uVar13,1);
                  }
                  else {
                    *(undefined8 *)(&stack0x00000330 + lVar7) =
                         *(undefined8 *)(&stack0x000001e0 + lVar7);
                    *(undefined4 *)(&stack0x00000320 + lVar7) =
                         *(undefined4 *)(&stack0x000001d0 + lVar7);
                    *(undefined4 *)(&stack0x00000324 + lVar7) =
                         *(undefined4 *)(&stack0x000001d4 + lVar7);
                    *(undefined4 *)(&stack0x00000328 + lVar7) =
                         *(undefined4 *)(&stack0x000001d8 + lVar7);
                    *(undefined4 *)(&stack0x0000032c + lVar7) =
                         *(undefined4 *)(&stack0x000001dc + lVar7);
                    plVar25 = *(longlong **)(&stack0x000000c0 + lVar7);
                    if (*(longlong *)(&stack0x000000a0 + lVar7) == 0) {
                      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa27c;
                      uVar9 = FUN_14020dc40("filters",7);
                      *(undefined8 *)((longlong)alStackX_8 + lVar7) = uVar9;
                      uVar32 = CONCAT71(uVar33,1);
                      uVar24 = CONCAT71(uVar27,1);
                      uVar36 = CONCAT71(uVar37,1);
                      uVar22 = CONCAT71(uVar13,1);
                      uVar29 = CONCAT71(uVar35,1);
                      uVar13 = (undefined7)((ulonglong)uVar9 >> 8);
                      *(ulonglong *)(&stack0x00000058 + lVar7) = CONCAT71(uVar13,1);
                      uVar9 = CONCAT71(uVar13,1);
                    }
                    else {
                      *(undefined8 *)(&stack0x00000350 + lVar7) =
                           *(undefined8 *)(&stack0x00000200 + lVar7);
                      *(undefined4 *)(&stack0x00000340 + lVar7) =
                           *(undefined4 *)(&stack0x000001f0 + lVar7);
                      *(undefined4 *)(&stack0x00000344 + lVar7) =
                           *(undefined4 *)(&stack0x000001f4 + lVar7);
                      *(undefined4 *)(&stack0x00000348 + lVar7) =
                           *(undefined4 *)(&stack0x000001f8 + lVar7);
                      *(undefined4 *)(&stack0x0000034c + lVar7) =
                           *(undefined4 *)(&stack0x000001fc + lVar7);
                      if (*(longlong *)(&stack0x00000098 + lVar7) == 0) {
                        pcVar16 = "testers";
                        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa369;
                        uVar9 = FUN_14020dc40("testers",7);
                        uVar32 = CONCAT71(uVar33,1);
                        uVar24 = CONCAT71(uVar27,1);
                        uVar36 = CONCAT71(uVar37,1);
                        uVar22 = CONCAT71(uVar13,1);
                        uVar29 = CONCAT71(uVar35,1);
                        uVar11 = CONCAT71((int7)((ulonglong)pcVar16 >> 8),1);
                      }
                      else {
                        *(undefined8 *)(&stack0x00000370 + lVar7) =
                             *(undefined8 *)(&stack0x00000220 + lVar7);
                        *(undefined4 *)(&stack0x00000360 + lVar7) =
                             *(undefined4 *)(&stack0x00000210 + lVar7);
                        *(undefined4 *)(&stack0x00000364 + lVar7) =
                             *(undefined4 *)(&stack0x00000214 + lVar7);
                        *(undefined4 *)(&stack0x00000368 + lVar7) =
                             *(undefined4 *)(&stack0x00000218 + lVar7);
                        *(undefined4 *)(&stack0x0000036c + lVar7) =
                             *(undefined4 *)(&stack0x0000021c + lVar7);
                        if (*(longlong *)(&stack0x00000090 + lVar7) == 0) {
                          *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa390;
                          uVar9 = FUN_14020dc40("hubs",4);
                          uVar32 = CONCAT71(uVar33,1);
                          uVar24 = CONCAT71(uVar27,1);
                          uVar36 = CONCAT71(uVar37,1);
                          uVar22 = CONCAT71(uVar13,1);
                          uVar29 = CONCAT71(uVar35,1);
                        }
                        else {
                          *(undefined8 *)(&stack0x00000160 + lVar7) =
                               *(undefined8 *)(&stack0x00000240 + lVar7);
                          *(undefined4 *)(&stack0x00000150 + lVar7) =
                               *(undefined4 *)(&stack0x00000230 + lVar7);
                          *(undefined4 *)(&stack0x00000154 + lVar7) =
                               *(undefined4 *)(&stack0x00000234 + lVar7);
                          *(undefined4 *)(&stack0x00000158 + lVar7) =
                               *(undefined4 *)(&stack0x00000238 + lVar7);
                          *(undefined4 *)(&stack0x0000015c + lVar7) =
                               *(undefined4 *)(&stack0x0000023c + lVar7);
                          if (*(longlong *)(&stack0x00000088 + lVar7) == 0) {
                            *(undefined8 *)(&stack0x000000d0 + lVar7) = 0;
                            *(undefined8 *)(&stack0x000000d8 + lVar7) = 8;
                            *(undefined8 *)(&stack0x000000e0 + lVar7) = 0;
                            uVar22 = CONCAT71(uVar13,1);
                          }
                          else {
                            *(undefined8 *)(&stack0x000000e0 + lVar7) =
                                 *(undefined8 *)(&stack0x00000290 + lVar7);
                            *(undefined4 *)(&stack0x000000d0 + lVar7) =
                                 *(undefined4 *)(&stack0x00000280 + lVar7);
                            *(undefined4 *)(&stack0x000000d4 + lVar7) =
                                 *(undefined4 *)(&stack0x00000284 + lVar7);
                            *(undefined4 *)(&stack0x000000d8 + lVar7) =
                                 *(undefined4 *)(&stack0x00000288 + lVar7);
                            *(undefined4 *)(&stack0x000000dc + lVar7) =
                                 *(undefined4 *)(&stack0x0000028c + lVar7);
                            uVar22 = 0;
                          }
                          if (*(longlong *)(&stack0x00000080 + lVar7) == 0) {
                            *(undefined8 *)(&stack0x00000110 + lVar7) = 0;
                            *(undefined8 *)(&stack0x00000118 + lVar7) = 8;
                            *(undefined8 *)(&stack0x00000120 + lVar7) = 0;
                            uVar36 = CONCAT71(uVar37,1);
                          }
                          else {
                            *(undefined8 *)(&stack0x00000120 + lVar7) =
                                 *(undefined8 *)(&stack0x000002b0 + lVar7);
                            *(undefined4 *)(&stack0x00000110 + lVar7) =
                                 *(undefined4 *)(&stack0x000002a0 + lVar7);
                            *(undefined4 *)(&stack0x00000114 + lVar7) =
                                 *(undefined4 *)(&stack0x000002a4 + lVar7);
                            *(undefined4 *)(&stack0x00000118 + lVar7) =
                                 *(undefined4 *)(&stack0x000002a8 + lVar7);
                            *(undefined4 *)(&stack0x0000011c + lVar7) =
                                 *(undefined4 *)(&stack0x000002ac + lVar7);
                            uVar36 = 0;
                          }
                          if (*(longlong *)(&stack0x00000078 + lVar7) == 0) {
                            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa6db;
                            uVar9 = FUN_14020dc40("chunk_types",0xb);
                            *(undefined8 *)((longlong)alStackX_8 + lVar7) = uVar9;
                            uVar32 = CONCAT71(uVar33,1);
                            uVar24 = CONCAT71(uVar27,1);
                          }
                          else {
                            *(undefined8 *)(&stack0x00000390 + lVar7) =
                                 *(undefined8 *)(&stack0x00000260 + lVar7);
                            *(undefined4 *)(&stack0x00000380 + lVar7) =
                                 *(undefined4 *)(&stack0x00000250 + lVar7);
                            *(undefined4 *)(&stack0x00000384 + lVar7) =
                                 *(undefined4 *)(&stack0x00000254 + lVar7);
                            *(undefined4 *)(&stack0x00000388 + lVar7) =
                                 *(undefined4 *)(&stack0x00000258 + lVar7);
                            *(undefined4 *)(&stack0x0000038c + lVar7) =
                                 *(undefined4 *)(&stack0x0000025c + lVar7);
                            if (*(longlong *)(&stack0x000000b8 + lVar7) == 0) {
                              uVar32 = CONCAT71(uVar33,1);
                              *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa6ff;
                              uVar9 = FUN_14020dc40("chunks",6);
                              *(undefined8 *)((longlong)alStackX_8 + lVar7) = uVar9;
                            }
                            else {
                              *(undefined8 *)(&stack0x00000c60 + lVar7) =
                                   *(undefined8 *)(&stack0x00000140 + lVar7);
                              *(undefined4 *)(&stack0x00000c50 + lVar7) =
                                   *(undefined4 *)(&stack0x00000130 + lVar7);
                              *(undefined4 *)(&stack0x00000c54 + lVar7) =
                                   *(undefined4 *)(&stack0x00000134 + lVar7);
                              *(undefined4 *)(&stack0x00000c58 + lVar7) =
                                   *(undefined4 *)(&stack0x00000138 + lVar7);
                              *(undefined4 *)(&stack0x00000c5c + lVar7) =
                                   *(undefined4 *)(&stack0x0000013c + lVar7);
                              if (*(longlong *)(&stack0x000000b0 + lVar7) != 0) {
                                bVar38 = lVar17 == 0;
                                if (bVar38) {
                                  uVar24 = 0;
                                }
                                lVar18 = 4;
                                if (!bVar38) {
                                  lVar18 = lVar17;
                                }
                                lVar10 = *(longlong *)(&stack0x000003c0 + lVar7);
                                uVar9 = 0;
                                if (!bVar38) {
                                  uVar9 = *(undefined8 *)(&stack0x00000278 + lVar7);
                                }
                                *(undefined8 *)(&stack0x00000c30 + lVar7) =
                                     *(undefined8 *)(&stack0x00000c40 + lVar7);
                                *(undefined8 *)(&stack0x00000c38 + lVar7) =
                                     *(undefined8 *)(&stack0x00000c48 + lVar7);
                                *(undefined8 *)(&stack0x00000760 + lVar7) =
                                     *(undefined8 *)(&stack0x000008f8 + lVar7);
                                *(undefined8 *)(&stack0x00000768 + lVar7) =
                                     *(undefined8 *)(&stack0x00000900 + lVar7);
                                *(undefined8 *)(&stack0x00000770 + lVar7) =
                                     *(undefined8 *)(&stack0x00000908 + lVar7);
                                *(undefined8 *)(&stack0x00000778 + lVar7) =
                                     *(undefined8 *)(&stack0x00000910 + lVar7);
                                *(undefined8 *)(&stack0x00000780 + lVar7) =
                                     *(undefined8 *)(&stack0x00000918 + lVar7);
                                *(undefined8 *)(&stack0x00000788 + lVar7) =
                                     *(undefined8 *)(&stack0x00000920 + lVar7);
                                *(undefined8 *)(&stack0x00000790 + lVar7) =
                                     *(undefined8 *)(&stack0x00000928 + lVar7);
                                uVar15 = (&stack0x00000458)[lVar7];
                                *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa565;
                                memcpy(&stack0x00000e00 + lVar7,&stack0x00000459 + lVar7,0x1af);
                                *(undefined8 *)(&stack0x000007c0 + lVar7) =
                                     *(undefined8 *)(&stack0x00000170 + lVar7);
                                *(undefined8 *)(&stack0x000007c8 + lVar7) =
                                     *(undefined8 *)(&stack0x00000178 + lVar7);
                                *(undefined8 *)(&stack0x000007d0 + lVar7) =
                                     *(undefined8 *)(&stack0x00000180 + lVar7);
                                *(undefined8 *)(&stack0x000000f0 + lVar7) =
                                     *(undefined8 *)(&stack0x00000190 + lVar7);
                                *(undefined8 *)(&stack0x000000f8 + lVar7) =
                                     *(undefined8 *)(&stack0x00000198 + lVar7);
                                *(undefined8 *)(&stack0x00000100 + lVar7) =
                                     *(undefined8 *)(&stack0x000001a0 + lVar7);
                                *(undefined8 *)(&stack0x000007a0 + lVar7) =
                                     *(undefined8 *)(&stack0x000001b0 + lVar7);
                                *(undefined8 *)(&stack0x000007a8 + lVar7) =
                                     *(undefined8 *)(&stack0x000001b8 + lVar7);
                                *(undefined8 *)(&stack0x000007b0 + lVar7) =
                                     *(undefined8 *)(&stack0x000001c0 + lVar7);
                                *(undefined8 *)(&stack0x000008e0 + lVar7) =
                                     *(undefined8 *)(&stack0x000001d0 + lVar7);
                                *(undefined8 *)(&stack0x000008e8 + lVar7) =
                                     *(undefined8 *)(&stack0x000001d8 + lVar7);
                                *(undefined8 *)(&stack0x000008f0 + lVar7) =
                                     *(undefined8 *)(&stack0x000001e0 + lVar7);
                                *(undefined8 *)(&stack0x000008d0 + lVar7) =
                                     *(undefined8 *)(&stack0x00000200 + lVar7);
                                *(undefined8 *)(&stack0x000008c0 + lVar7) =
                                     *(undefined8 *)(&stack0x000001f0 + lVar7);
                                *(undefined8 *)(&stack0x000008c8 + lVar7) =
                                     *(undefined8 *)(&stack0x000001f8 + lVar7);
                                *(undefined8 *)(&stack0x000008b0 + lVar7) =
                                     *(undefined8 *)(&stack0x00000220 + lVar7);
                                *(undefined8 *)(&stack0x000008a0 + lVar7) =
                                     *(undefined8 *)(&stack0x00000210 + lVar7);
                                *(undefined8 *)(&stack0x000008a8 + lVar7) =
                                     *(undefined8 *)(&stack0x00000218 + lVar7);
                                *(undefined8 *)(&stack0x00000880 + lVar7) =
                                     *(undefined8 *)(&stack0x00000230 + lVar7);
                                *(undefined8 *)(&stack0x00000888 + lVar7) =
                                     *(undefined8 *)(&stack0x00000238 + lVar7);
                                *(undefined8 *)(&stack0x00000890 + lVar7) =
                                     *(undefined8 *)(&stack0x00000240 + lVar7);
                                *(undefined8 *)(&stack0x00000860 + lVar7) =
                                     *(undefined8 *)(&stack0x000000d0 + lVar7);
                                *(undefined8 *)(&stack0x00000868 + lVar7) =
                                     *(undefined8 *)(&stack0x000000d8 + lVar7);
                                *(undefined8 *)(&stack0x00000870 + lVar7) =
                                     *(undefined8 *)(&stack0x000000e0 + lVar7);
                                *(undefined8 *)(&stack0x00000840 + lVar7) =
                                     *(undefined8 *)(&stack0x00000110 + lVar7);
                                *(undefined8 *)(&stack0x00000848 + lVar7) =
                                     *(undefined8 *)(&stack0x00000118 + lVar7);
                                *(undefined8 *)(&stack0x00000850 + lVar7) =
                                     *(undefined8 *)(&stack0x00000120 + lVar7);
                                *(undefined8 *)(&stack0x00000830 + lVar7) =
                                     *(undefined8 *)(&stack0x00000260 + lVar7);
                                *(undefined8 *)(&stack0x00000820 + lVar7) =
                                     *(undefined8 *)(&stack0x00000250 + lVar7);
                                *(undefined8 *)(&stack0x00000828 + lVar7) =
                                     *(undefined8 *)(&stack0x00000258 + lVar7);
                                *(undefined8 *)(&stack0x00000810 + lVar7) =
                                     *(undefined8 *)(&stack0x00000140 + lVar7);
                                *(undefined8 *)(&stack0x00000800 + lVar7) =
                                     *(undefined8 *)(&stack0x00000130 + lVar7);
                                *(undefined8 *)(&stack0x00000808 + lVar7) =
                                     *(undefined8 *)(&stack0x00000138 + lVar7);
                                goto LAB_1404aafa0;
                              }
                              *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa9b0;
                              uVar9 = FUN_14020dc40("toolboxes",9);
                              *(undefined8 *)((longlong)alStackX_8 + lVar7) = uVar9;
                              uVar32 = 0;
                              *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa9c5;
                              FUN_140459390();
                            }
                            if (*(longlong *)(&stack0x00000380 + lVar7) != 0) {
                              *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa9e9;
                              FUN_1408192a0(*(undefined8 *)(&stack0x00000388 + lVar7),
                                            *(longlong *)(&stack0x00000380 + lVar7) << 5,4);
                            }
                            uVar24 = 0;
                          }
                          if (*(longlong *)(&stack0x00000110 + lVar7) != 0) {
                            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aaa10;
                            FUN_1408192a0(*(undefined8 *)(&stack0x00000118 + lVar7),
                                          *(longlong *)(&stack0x00000110 + lVar7) << 3,8);
                          }
                          if (*(longlong *)(&stack0x000000d0 + lVar7) != 0) {
                            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aaa34;
                            FUN_1408192a0(*(undefined8 *)(&stack0x000000d8 + lVar7),
                                          *(longlong *)(&stack0x000000d0 + lVar7) << 3,8);
                          }
                          if (*(longlong *)(&stack0x00000150 + lVar7) != 0) {
                            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aaa58;
                            FUN_1408192a0(*(undefined8 *)(&stack0x00000158 + lVar7),
                                          *(longlong *)(&stack0x00000150 + lVar7) << 4,8);
                          }
                          uVar29 = 0;
                          uVar9 = *(undefined8 *)((longlong)alStackX_8 + lVar7);
                        }
                        if (*(longlong *)(&stack0x00000360 + lVar7) != 0) {
                          *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aaa8e;
                          FUN_1408192a0(*(undefined8 *)(&stack0x00000368 + lVar7),
                                        *(longlong *)(&stack0x00000360 + lVar7) * 0x18,8);
                        }
                        uVar11 = 0;
                      }
                      *(undefined8 *)(&stack0x00000058 + lVar7) = uVar11;
                      *(undefined8 *)((longlong)alStackX_8 + lVar7) = uVar9;
                      if (*(longlong *)(&stack0x00000340 + lVar7) != 0) {
                        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aaacb;
                        FUN_1408192a0(*(undefined8 *)(&stack0x00000348 + lVar7),
                                      *(longlong *)(&stack0x00000340 + lVar7) * 0x28,8);
                      }
                      uVar9 = 0;
                    }
                    *(undefined8 *)(&stack0xfffffffffffffff0 + lVar7) = uVar9;
                    if (*(longlong *)(&stack0x00000320 + lVar7) != 0) {
                      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aaaf6;
                      FUN_1408192a0(*(undefined8 *)(&stack0x00000328 + lVar7),
                                    *(longlong *)(&stack0x00000320 + lVar7) << 4,8);
                    }
                    uVar9 = 0;
                  }
                  *(undefined8 *)(&stack0xfffffffffffffff8 + lVar7) = uVar9;
                  if (*(longlong *)(&stack0x00000300 + lVar7) != 0) {
                    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aab24;
                    FUN_1408192a0(*(undefined8 *)(&stack0x00000308 + lVar7),
                                  *(longlong *)(&stack0x00000300 + lVar7) << 4,8);
                  }
                  *(undefined8 *)((longlong)alStackX_8 + lVar7 + -8) = 0;
                  uVar9 = *(undefined8 *)((longlong)alStackX_8 + lVar7);
                }
                if (*(longlong *)(&stack0x000002e0 + lVar7) != 0) {
                  *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aab5e;
                  FUN_1408192a0(*(undefined8 *)(&stack0x000002e8 + lVar7),
                                *(longlong *)(&stack0x000002e0 + lVar7) * 0x28,8);
                }
                uVar11 = 0;
              }
              *(undefined8 *)((longlong)alStackX_8 + lVar7 + 8) = uVar11;
              *(undefined8 *)((longlong)alStackX_8 + lVar7) = uVar9;
              *(undefined8 *)(&stack0x00000028 + lVar7) = uVar32;
              if (*(longlong *)(&stack0x000002c0 + lVar7) != 0) {
                *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aaba0;
                FUN_1408192a0(*(undefined8 *)(&stack0x000002c8 + lVar7),
                              *(longlong *)(&stack0x000002c0 + lVar7) * 0x1c,4);
              }
              uVar9 = 0;
            }
            *(undefined8 *)(&stack0x00000048 + lVar7) = uVar29;
            *(undefined8 *)(&stack0x00000038 + lVar7) = uVar22;
            *(undefined8 *)(&stack0x00000030 + lVar7) = uVar36;
            *(undefined8 *)(&stack0x00000040 + lVar7) = uVar24;
            uVar11 = 0;
            uVar22 = *(undefined8 *)(&stack0xfffffffffffffff0 + lVar7);
            uVar24 = *(undefined8 *)(&stack0xfffffffffffffff8 + lVar7);
            uVar29 = *(undefined8 *)((longlong)alStackX_8 + lVar7 + -8);
            uVar36 = *(undefined8 *)((longlong)alStackX_8 + lVar7 + 8);
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aabe3;
            FUN_14045b020(&stack0x00000420 + lVar7);
          }
          *(undefined8 *)((longlong)alStackX_8 + lVar7 + 0x18) = uVar11;
          *(undefined8 *)((longlong)alStackX_8 + lVar7 + 0x10) = uVar9;
          *(undefined8 *)((longlong)alStackX_8 + lVar7 + 8) = uVar36;
          *(undefined8 *)((longlong)alStackX_8 + lVar7 + -8) = uVar29;
          *(undefined8 *)(&stack0xfffffffffffffff8 + lVar7) = uVar24;
          *(undefined8 *)(&stack0xfffffffffffffff0 + lVar7) = uVar22;
          cVar20 = (char)*(undefined8 *)(&stack0x00000058 + lVar7);
          cVar31 = (char)*(undefined8 *)(&stack0x00000048 + lVar7);
          uVar24 = *(undefined8 *)(&stack0x00000040 + lVar7);
          lVar18 = *(longlong *)(&stack0x00000030 + lVar7);
          cVar34 = (char)*(undefined8 *)(&stack0x00000038 + lVar7);
          cVar23 = (char)*(undefined8 *)(&stack0x00000028 + lVar7);
          goto LAB_1404aac28;
        }
        lVar10 = *(longlong *)(&stack0x00000068 + lVar7);
        if (bVar38) {
          uVar9 = **(undefined8 **)((longlong)alStackX_8 + lVar7 + -8);
          uVar22 = **(undefined8 **)(&stack0xfffffffffffffff0 + lVar7);
          *(undefined8 *)(&stack0x00000420 + lVar7) = 8;
          uVar13 = (undefined7)((ulonglong)*(undefined8 **)(&stack0xfffffffffffffff0 + lVar7) >> 8);
          *(ulonglong *)(&stack0x00000028 + lVar7) = CONCAT71(uVar13,1);
          *(ulonglong *)(&stack0x00000040 + lVar7) = CONCAT71(uVar13,1);
          *(ulonglong *)(&stack0x00000030 + lVar7) = CONCAT71(uVar13,1);
          *(ulonglong *)(&stack0x00000038 + lVar7) = CONCAT71(uVar13,1);
          *(ulonglong *)(&stack0x00000048 + lVar7) = CONCAT71(uVar13,1);
          *(ulonglong *)(&stack0x00000058 + lVar7) = CONCAT71(uVar13,1);
          pbVar28 = (byte *)((ulonglong)uVar30 << 8);
          plVar25 = (longlong *)((ulonglong)uVar37 << 8);
          lVar17 = *(longlong *)(&stack0x00000060 + lVar7);
          *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa1ed;
          lVar8 = FUN_1413e8fd0(&stack0x00000420 + lVar7,uVar9,uVar22);
          *(longlong *)((longlong)alStackX_8 + lVar7) = lVar8;
LAB_1404a914e:
          cVar23 = '\x01';
          uVar24 = CONCAT71((int7)((ulonglong)pbVar28 >> 8),1);
          lVar18 = CONCAT71((int7)((ulonglong)plVar25 >> 8),1);
          cVar34 = '\x01';
          cVar31 = '\x01';
          cVar20 = '\x01';
          uVar13 = (undefined7)((ulonglong)lVar8 >> 8);
          *(ulonglong *)(&stack0xfffffffffffffff0 + lVar7) = CONCAT71(uVar13,1);
          *(ulonglong *)(&stack0xfffffffffffffff8 + lVar7) = CONCAT71(uVar13,1);
          *(ulonglong *)((longlong)alStackX_8 + lVar7 + -8) = CONCAT71(uVar13,1);
          *(ulonglong *)((longlong)alStackX_8 + lVar7 + 8) = CONCAT71(uVar13,1);
          *(ulonglong *)((longlong)alStackX_8 + lVar7 + 0x10) = CONCAT71(uVar13,1);
          *(ulonglong *)((longlong)alStackX_8 + lVar7 + 0x18) = CONCAT71(uVar13,1);
          goto LAB_1404aac28;
        }
LAB_1404a85aa:
        if (bVar19 != 0x22) {
          if (bVar19 != 0x7d) goto LAB_1404a9d11;
          uVar9 = **(undefined8 **)((longlong)alStackX_8 + lVar7 + -8);
          uVar22 = **(undefined8 **)(&stack0xfffffffffffffff0 + lVar7);
          *(undefined8 *)(&stack0x00000420 + lVar7) = 0x15;
          uVar13 = (undefined7)((ulonglong)*(undefined8 **)(&stack0xfffffffffffffff0 + lVar7) >> 8);
          *(ulonglong *)(&stack0x00000028 + lVar7) = CONCAT71(uVar13,1);
          *(ulonglong *)(&stack0x00000040 + lVar7) = CONCAT71(uVar13,1);
          *(ulonglong *)(&stack0x00000030 + lVar7) = CONCAT71(uVar13,1);
          *(ulonglong *)(&stack0x00000038 + lVar7) = CONCAT71(uVar13,1);
          *(ulonglong *)(&stack0x00000048 + lVar7) = CONCAT71(uVar13,1);
          *(ulonglong *)(&stack0x00000058 + lVar7) = CONCAT71(uVar13,1);
          pbVar28 = (byte *)((ulonglong)uVar30 << 8);
          plVar25 = (longlong *)((ulonglong)uVar37 << 8);
          lVar17 = *(longlong *)(&stack0x00000060 + lVar7);
          *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9ca2;
          lVar8 = FUN_1413e8fd0(&stack0x00000420 + lVar7,uVar9,uVar22);
          *(longlong *)((longlong)alStackX_8 + lVar7) = lVar8;
          goto LAB_1404a914e;
        }
        *pcVar16 = '\0';
        lVar8 = *plVar26;
        lVar17 = *(longlong *)(&stack0x00000060 + lVar7);
        if (lVar8 != 0) {
          lVar18 = *plVar2;
          if (lVar18 == *plVar25) {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a85d7;
            FUN_14079fd50(plVar25);
            lVar18 = *plVar2;
            lVar8 = *plVar26;
          }
          *(undefined1 *)(lVar8 + lVar18) = 0x22;
          *plVar2 = *plVar2 + 1;
        }
        *(undefined8 *)(lVar12 + 0x10) = 0;
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8601;
        lVar8 = FUN_14036c700(&stack0x00000420 + lVar7,plVar25,lVar12);
        if (*(int *)(&stack0x00000420 + lVar7) == 2) {
          *(undefined8 *)((longlong)alStackX_8 + lVar7) = *(undefined8 *)(&stack0x00000428 + lVar7);
          goto LAB_1404a914e;
        }
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a862c;
        FUN_1406c0db0(&stack0x00000c50 + lVar7,*(undefined8 *)(&stack0x00000428 + lVar7),
                      *(undefined8 *)(&stack0x00000430 + lVar7));
        if ((&stack0x00000c50)[lVar7] != '\0') {
          lVar8 = *(longlong *)(&stack0x00000c58 + lVar7);
          *(longlong *)((longlong)alStackX_8 + lVar7) = lVar8;
          goto LAB_1404a914e;
        }
        bVar19 = (&stack0x00000c51)[lVar7];
        if (0xe < (ulonglong)bVar19) {
          *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a89e1;
          lVar8 = FUN_140440b80(lVar12);
          if (lVar8 != 0) goto LAB_1404aa949;
          *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a89f2;
          lVar8 = FUN_14043e710(lVar12);
          bVar38 = true;
          if (lVar8 != 0) goto LAB_1404aa8eb;
          goto LAB_1404a848e;
        }
        switch(bVar19) {
        case 0:
          if (*(longlong *)((longlong)alStackX_8 + lVar7 + 8) != 1) {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8670;
            lVar8 = FUN_140440b80(lVar12);
            *(longlong *)((longlong)alStackX_8 + lVar7) = lVar8;
            if (*(longlong *)((longlong)alStackX_8 + lVar7) != 0) goto LAB_1404a914e;
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8691;
            FUN_1404a5930(&stack0x00000420 + lVar7,lVar12);
            lVar8 = *(longlong *)(&stack0x00000428 + lVar7);
            *(longlong *)((longlong)alStackX_8 + lVar7) = lVar8;
            if (*(longlong *)(&stack0x00000420 + lVar7) == 0) {
              *(undefined8 *)(&stack0x00000c40 + lVar7) = *(undefined8 *)(&stack0x00000430 + lVar7);
              *(undefined8 *)(&stack0x00000c48 + lVar7) = *(undefined8 *)(&stack0x00000438 + lVar7);
              *(undefined8 *)((longlong)alStackX_8 + lVar7 + 8) = 1;
              bVar38 = true;
              goto LAB_1404a848e;
            }
            goto LAB_1404a914e;
          }
          uVar9 = 6;
          pcVar16 = "player";
          break;
        case 1:
          if ((&stack0x00000930)[lVar7] == '\x02') {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8b15;
            lVar8 = FUN_140440b80(lVar12);
            if (lVar8 == 0) {
              *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8b2e;
              FUN_1404af0a0(&stack0x00000420 + lVar7,lVar12);
              cVar20 = (&stack0x00000458)[lVar7];
              lVar8 = *(longlong *)(&stack0x00000420 + lVar7);
              if (cVar20 != '\x02') {
                *(longlong *)((longlong)alStackX_8 + lVar7 + 0x10) = lVar8;
                *(undefined8 *)(&stack0x000003a0 + lVar7) =
                     *(undefined8 *)(&stack0x00000448 + lVar7);
                *(undefined8 *)(&stack0x000003a8 + lVar7) =
                     *(undefined8 *)(&stack0x00000450 + lVar7);
                *(undefined8 *)(&stack0x00000390 + lVar7) =
                     *(undefined8 *)(&stack0x00000438 + lVar7);
                *(undefined8 *)(&stack0x00000398 + lVar7) =
                     *(undefined8 *)(&stack0x00000440 + lVar7);
                *(undefined8 *)(&stack0x00000380 + lVar7) =
                     *(undefined8 *)(&stack0x00000428 + lVar7);
                *(undefined8 *)(&stack0x00000388 + lVar7) =
                     *(undefined8 *)(&stack0x00000430 + lVar7);
                *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8b92;
                memcpy(&stack0x00000c50 + lVar7,&stack0x00000459 + lVar7,0x1af);
                if ((&stack0x00000930)[lVar7] != '\x02') {
                  *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8ba9;
                  FUN_14045b020(&stack0x000008f8 + lVar7);
                }
                *(undefined8 *)(&stack0x000008f8 + lVar7) =
                     *(undefined8 *)((longlong)alStackX_8 + lVar7 + 0x10);
                *(undefined8 *)(&stack0x00000920 + lVar7) =
                     *(undefined8 *)(&stack0x000003a0 + lVar7);
                *(undefined8 *)(&stack0x00000928 + lVar7) =
                     *(undefined8 *)(&stack0x000003a8 + lVar7);
                *(undefined8 *)(&stack0x00000910 + lVar7) =
                     *(undefined8 *)(&stack0x00000390 + lVar7);
                *(undefined8 *)(&stack0x00000918 + lVar7) =
                     *(undefined8 *)(&stack0x00000398 + lVar7);
                *(undefined8 *)(&stack0x00000900 + lVar7) =
                     *(undefined8 *)(&stack0x00000380 + lVar7);
                *(undefined8 *)(&stack0x00000908 + lVar7) =
                     *(undefined8 *)(&stack0x00000388 + lVar7);
                (&stack0x00000930)[lVar7] = cVar20;
                *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8c03;
                memcpy(&stack0x00000931 + lVar7,&stack0x00000c50 + lVar7,0x1af);
                bVar38 = true;
                goto LAB_1404a848e;
              }
              lVar17 = *(longlong *)(&stack0x00000060 + lVar7);
            }
LAB_1404aa949:
            *(longlong *)((longlong)alStackX_8 + lVar7) = lVar8;
            goto LAB_1404a914e;
          }
          uVar9 = 5;
          pcVar16 = "story";
          break;
        case 2:
          if (*(longlong *)(&stack0x00000070 + lVar7) == 0) {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a896f;
            lVar8 = FUN_140440b80(lVar12);
            if (lVar8 != 0) goto LAB_1404aa949;
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8988;
            FUN_14049dff0(&stack0x00000420 + lVar7,lVar12);
            lVar8 = *(longlong *)(&stack0x00000420 + lVar7);
            lVar18 = *(longlong *)(&stack0x00000428 + lVar7);
            if (lVar18 != 0) {
              *(longlong *)(&stack0x00000170 + lVar7) = lVar8;
              *(longlong *)(&stack0x00000178 + lVar7) = lVar18;
              *(undefined8 *)(&stack0x00000180 + lVar7) = *(undefined8 *)(&stack0x00000430 + lVar7);
              bVar38 = true;
              *(longlong *)(&stack0x000007f0 + lVar7) = lVar8;
              *(longlong *)(&stack0x00000070 + lVar7) = lVar18;
              goto LAB_1404a848e;
            }
            goto LAB_1404aa949;
          }
          uVar9 = 5;
          pcVar16 = "nodes";
          break;
        case 3:
          if (lVar10 == 0) {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8a14;
            lVar8 = FUN_140440b80(lVar12);
            if (lVar8 != 0) goto LAB_1404aa949;
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8a2d;
            FUN_14049d4e0(&stack0x00000420 + lVar7,lVar12);
            lVar8 = *(longlong *)(&stack0x00000420 + lVar7);
            lVar18 = *(longlong *)(&stack0x00000428 + lVar7);
            if (lVar18 != 0) {
              *(longlong *)(&stack0x00000190 + lVar7) = lVar8;
              *(longlong *)(&stack0x00000198 + lVar7) = lVar18;
              *(undefined8 *)(&stack0x000001a0 + lVar7) = *(undefined8 *)(&stack0x00000430 + lVar7);
              bVar38 = true;
              *(longlong *)(&stack0x000007e8 + lVar7) = lVar8;
              *(longlong *)(&stack0x00000068 + lVar7) = lVar18;
              goto LAB_1404a848e;
            }
            goto LAB_1404aa949;
          }
          uVar9 = 5;
          pcVar16 = "edges";
          break;
        case 4:
          if (*(longlong *)(&stack0x000000e8 + lVar7) == 0) {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a87ec;
            lVar8 = FUN_140440b80(lVar12);
            if (lVar8 != 0) goto LAB_1404aa949;
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8805;
            FUN_14049be40(&stack0x00000420 + lVar7,lVar12);
            lVar8 = *(longlong *)(&stack0x00000420 + lVar7);
            lVar18 = *(longlong *)(&stack0x00000428 + lVar7);
            if (lVar18 != 0) {
              *(longlong *)(&stack0x000001b0 + lVar7) = lVar8;
              *(longlong *)(&stack0x000001b8 + lVar7) = lVar18;
              *(undefined8 *)(&stack0x000001c0 + lVar7) = *(undefined8 *)(&stack0x00000430 + lVar7);
              bVar38 = true;
              *(longlong *)(&stack0x000007e0 + lVar7) = lVar8;
              *(longlong *)(&stack0x000000e8 + lVar7) = lVar18;
              goto LAB_1404a848e;
            }
            goto LAB_1404aa949;
          }
          uVar9 = 9;
          pcVar16 = "endpoints";
          break;
        case 5:
          if (*(longlong *)(&stack0x000000a8 + lVar7) == 0) {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8c22;
            lVar8 = FUN_140440b80(lVar12);
            if (lVar8 != 0) goto LAB_1404aa949;
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8c3b;
            FUN_14049e740(&stack0x00000420 + lVar7,lVar12);
            lVar8 = *(longlong *)(&stack0x00000420 + lVar7);
            lVar18 = *(longlong *)(&stack0x00000428 + lVar7);
            if (lVar18 != 0) {
              *(longlong *)(&stack0x000001d0 + lVar7) = lVar8;
              *(longlong *)(&stack0x000001d8 + lVar7) = lVar18;
              *(undefined8 *)(&stack0x000001e0 + lVar7) = *(undefined8 *)(&stack0x00000430 + lVar7);
              bVar38 = true;
              *(longlong *)(&stack0x00000418 + lVar7) = lVar8;
              *(longlong *)(&stack0x000000a8 + lVar7) = lVar18;
              goto LAB_1404a848e;
            }
            goto LAB_1404aa949;
          }
          uVar9 = 6;
          pcVar16 = "relays";
          break;
        case 6:
          if (*(longlong *)(&stack0x000000a0 + lVar7) == 0) {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8d2c;
            lVar8 = FUN_140440b80(lVar12);
            if (lVar8 != 0) goto LAB_1404aa949;
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8d45;
            FUN_14049e9b0(&stack0x00000420 + lVar7,lVar12);
            lVar8 = *(longlong *)(&stack0x00000420 + lVar7);
            lVar18 = *(longlong *)(&stack0x00000428 + lVar7);
            if (lVar18 != 0) {
              *(longlong *)(&stack0x000001f0 + lVar7) = lVar8;
              *(longlong *)(&stack0x000001f8 + lVar7) = lVar18;
              *(undefined8 *)(&stack0x00000200 + lVar7) = *(undefined8 *)(&stack0x00000430 + lVar7);
              bVar38 = true;
              *(longlong *)(&stack0x00000410 + lVar7) = lVar8;
              *(longlong *)(&stack0x000000a0 + lVar7) = lVar18;
              goto LAB_1404a848e;
            }
            goto LAB_1404aa949;
          }
          uVar9 = 7;
          pcVar16 = "filters";
          break;
        case 7:
          if (*(longlong *)(&stack0x00000098 + lVar7) == 0) {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8a95;
            lVar8 = FUN_140440b80(lVar12);
            if (lVar8 != 0) goto LAB_1404aa949;
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8aae;
            FUN_14049b960(&stack0x00000420 + lVar7,lVar12);
            lVar8 = *(longlong *)(&stack0x00000420 + lVar7);
            lVar18 = *(longlong *)(&stack0x00000428 + lVar7);
            if (lVar18 != 0) {
              *(longlong *)(&stack0x00000210 + lVar7) = lVar8;
              *(longlong *)(&stack0x00000218 + lVar7) = lVar18;
              *(undefined8 *)(&stack0x00000220 + lVar7) = *(undefined8 *)(&stack0x00000430 + lVar7);
              bVar38 = true;
              *(longlong *)(&stack0x00000408 + lVar7) = lVar8;
              *(longlong *)(&stack0x00000098 + lVar7) = lVar18;
              goto LAB_1404a848e;
            }
            goto LAB_1404aa949;
          }
          uVar9 = 7;
          pcVar16 = "testers";
          break;
        case 8:
          if (*(longlong *)(&stack0x00000090 + lVar7) == 0) {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8e2e;
            lVar8 = FUN_140440b80(lVar12);
            if (lVar8 != 0) goto LAB_1404aa949;
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8e47;
            FUN_14049cc10(&stack0x00000420 + lVar7,lVar12);
            lVar8 = *(longlong *)(&stack0x00000420 + lVar7);
            lVar18 = *(longlong *)(&stack0x00000428 + lVar7);
            if (lVar18 != 0) {
              *(longlong *)(&stack0x00000230 + lVar7) = lVar8;
              *(longlong *)(&stack0x00000238 + lVar7) = lVar18;
              *(undefined8 *)(&stack0x00000240 + lVar7) = *(undefined8 *)(&stack0x00000430 + lVar7);
              bVar38 = true;
              *(longlong *)(&stack0x00000400 + lVar7) = lVar8;
              *(longlong *)(&stack0x00000090 + lVar7) = lVar18;
              goto LAB_1404a848e;
            }
            goto LAB_1404aa949;
          }
          uVar9 = 4;
          pcVar16 = "hubs";
          break;
        case 9:
          if (*(longlong *)(&stack0x00000088 + lVar7) == 0) {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a88ee;
            lVar8 = FUN_140440b80(lVar12);
            if (lVar8 != 0) goto LAB_1404aa949;
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8907;
            FUN_14049bbd0(&stack0x00000420 + lVar7,lVar12);
            lVar8 = *(longlong *)(&stack0x00000420 + lVar7);
            lVar18 = *(longlong *)(&stack0x00000428 + lVar7);
            if (lVar18 != 0) {
              *(longlong *)(&stack0x00000280 + lVar7) = lVar8;
              *(longlong *)(&stack0x00000288 + lVar7) = lVar18;
              *(undefined8 *)(&stack0x00000290 + lVar7) = *(undefined8 *)(&stack0x00000430 + lVar7);
              bVar38 = true;
              *(longlong *)(&stack0x000003f8 + lVar7) = lVar8;
              *(longlong *)(&stack0x00000088 + lVar7) = lVar18;
              goto LAB_1404a848e;
            }
            goto LAB_1404aa949;
          }
          uVar9 = 8;
          pcVar16 = "antennasstruct Story with 47 elements";
          break;
        case 10:
          if (*(longlong *)(&stack0x00000080 + lVar7) == 0) {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8dad;
            lVar8 = FUN_140440b80(lVar12);
            if (lVar8 != 0) goto LAB_1404aa949;
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8dc6;
            FUN_14049d270(&stack0x00000420 + lVar7,lVar12);
            lVar8 = *(longlong *)(&stack0x00000420 + lVar7);
            lVar18 = *(longlong *)(&stack0x00000428 + lVar7);
            if (lVar18 != 0) {
              *(longlong *)(&stack0x000002a0 + lVar7) = lVar8;
              *(longlong *)(&stack0x000002a8 + lVar7) = lVar18;
              *(undefined8 *)(&stack0x000002b0 + lVar7) = *(undefined8 *)(&stack0x00000430 + lVar7);
              bVar38 = true;
              *(longlong *)(&stack0x000003f0 + lVar7) = lVar8;
              *(longlong *)(&stack0x00000080 + lVar7) = lVar18;
              goto LAB_1404a848e;
            }
            goto LAB_1404aa949;
          }
          uVar9 = 7;
          pcVar16 = "bridges";
          break;
        case 0xb:
          if (*(longlong *)(&stack0x00000078 + lVar7) == 0) {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a876b;
            lVar8 = FUN_140440b80(lVar12);
            if (lVar8 != 0) goto LAB_1404aa949;
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8784;
            FUN_14049e260(&stack0x00000420 + lVar7,lVar12);
            lVar8 = *(longlong *)(&stack0x00000420 + lVar7);
            lVar18 = *(longlong *)(&stack0x00000428 + lVar7);
            if (lVar18 != 0) {
              *(longlong *)(&stack0x00000250 + lVar7) = lVar8;
              *(longlong *)(&stack0x00000258 + lVar7) = lVar18;
              *(undefined8 *)(&stack0x00000260 + lVar7) = *(undefined8 *)(&stack0x00000430 + lVar7);
              bVar38 = true;
              *(longlong *)(&stack0x000003e8 + lVar7) = lVar8;
              *(longlong *)(&stack0x00000078 + lVar7) = lVar18;
              goto LAB_1404a848e;
            }
            goto LAB_1404aa949;
          }
          uVar9 = 0xb;
          pcVar16 = "chunk_types";
          break;
        case 0xc:
          if (*(longlong *)(&stack0x000000b8 + lVar7) == 0) {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a886d;
            lVar8 = FUN_140440b80(lVar12);
            if (lVar8 != 0) goto LAB_1404aa949;
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8886;
            FUN_14049b370(&stack0x00000420 + lVar7,lVar12);
            lVar8 = *(longlong *)(&stack0x00000420 + lVar7);
            lVar18 = *(longlong *)(&stack0x00000428 + lVar7);
            if (lVar18 != 0) {
              *(longlong *)(&stack0x00000130 + lVar7) = lVar8;
              *(longlong *)(&stack0x00000138 + lVar7) = lVar18;
              *(undefined8 *)(&stack0x00000140 + lVar7) = *(undefined8 *)(&stack0x00000430 + lVar7);
              bVar38 = true;
              *(longlong *)(&stack0x000003d8 + lVar7) = lVar8;
              *(longlong *)(&stack0x000000b8 + lVar7) = lVar18;
              goto LAB_1404a848e;
            }
            goto LAB_1404aa949;
          }
          uVar9 = 6;
          pcVar16 = "chunks";
          break;
        case 0xd:
          if (*(longlong *)(&stack0x000000b0 + lVar7) == 0) {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8ca3;
            lVar8 = FUN_140440b80(lVar12);
            if (lVar8 != 0) goto LAB_1404aa949;
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8cbc;
            FUN_14049e4d0(&stack0x00000420 + lVar7,lVar12);
            lVar8 = *(longlong *)(&stack0x00000420 + lVar7);
            lVar18 = *(longlong *)(&stack0x00000428 + lVar7);
            if (lVar18 != 0) {
              *(longlong *)(&stack0x000003b0 + lVar7) = lVar8;
              *(longlong *)(&stack0x000003b8 + lVar7) = lVar18;
              *(undefined8 *)(&stack0x000003c0 + lVar7) = *(undefined8 *)(&stack0x00000430 + lVar7);
              bVar38 = true;
              *(longlong *)(&stack0x000003e0 + lVar7) = lVar8;
              *(longlong *)(&stack0x000007f8 + lVar7) = lVar8;
              *(longlong *)(&stack0x000000b0 + lVar7) = lVar18;
              goto LAB_1404a848e;
            }
            goto LAB_1404aa949;
          }
          uVar9 = 9;
          pcVar16 = "toolboxes";
          break;
        case 0xe:
          if (lVar17 == 0) {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a86e4;
            lVar8 = FUN_140440b80(lVar12);
            lVar17 = lVar8;
            if (lVar8 == 0) {
              *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8700;
              FUN_14049e4d0(&stack0x00000420 + lVar7,lVar12);
              lVar8 = *(longlong *)(&stack0x00000420 + lVar7);
              lVar17 = *(longlong *)(&stack0x00000428 + lVar7);
              if (lVar17 != 0) {
                *(longlong *)(&stack0x000003d0 + lVar7) = lVar8;
                *(longlong *)(&stack0x00000268 + lVar7) = lVar8;
                *(longlong *)(&stack0x00000060 + lVar7) = lVar17;
                *(longlong *)(&stack0x00000270 + lVar7) = lVar17;
                *(undefined8 *)(&stack0x00000278 + lVar7) =
                     *(undefined8 *)(&stack0x00000430 + lVar7);
                bVar38 = true;
                goto LAB_1404a848e;
              }
              lVar17 = 0;
            }
            uVar13 = (undefined7)((ulonglong)lVar17 >> 8);
            *(ulonglong *)((longlong)alStackX_8 + lVar7 + 0x18) = CONCAT71(uVar13,1);
            *(ulonglong *)((longlong)alStackX_8 + lVar7 + 0x10) = CONCAT71(uVar13,1);
            *(ulonglong *)((longlong)alStackX_8 + lVar7 + 8) = CONCAT71(uVar13,1);
            *(ulonglong *)((longlong)alStackX_8 + lVar7 + -8) = CONCAT71(uVar13,1);
            *(ulonglong *)(&stack0xfffffffffffffff8 + lVar7) = CONCAT71(uVar13,1);
            *(ulonglong *)(&stack0xfffffffffffffff0 + lVar7) = CONCAT71(uVar13,1);
            cVar20 = '\x01';
            cVar31 = '\x01';
            cVar34 = '\x01';
            lVar18 = CONCAT71(uVar37,1);
            uVar24 = CONCAT71(uVar30,1);
            cVar23 = '\x01';
            *(longlong *)((longlong)alStackX_8 + lVar7) = lVar8;
            goto LAB_1404aac50;
          }
          uVar9 = 5;
          pcVar16 = "pages";
        }
        uVar13 = (undefined7)
                 ((ulonglong)
                  ((longlong)&switchD_1404a865a::switchdataD_1404ac664 +
                  (longlong)(int)(&switchD_1404a865a::switchdataD_1404ac664)[bVar19]) >> 8);
        *(ulonglong *)(&stack0x00000028 + lVar7) = CONCAT71(uVar13,1);
        *(ulonglong *)(&stack0x00000040 + lVar7) = CONCAT71(uVar13,1);
        *(ulonglong *)(&stack0x00000030 + lVar7) = CONCAT71(uVar13,1);
        *(ulonglong *)(&stack0x00000038 + lVar7) = CONCAT71(uVar13,1);
        *(ulonglong *)(&stack0x00000048 + lVar7) = CONCAT71(uVar13,1);
        *(ulonglong *)(&stack0x00000058 + lVar7) = CONCAT71(uVar13,1);
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa8e1;
        uVar9 = FUN_14020dd40(pcVar16,uVar9);
        *(undefined8 *)((longlong)alStackX_8 + lVar7) = uVar9;
        goto LAB_1404a930c;
      }
      goto LAB_1404a9767;
    }
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9835;
    lVar10 = FUN_1404403d0(lVar12,&stack0x000000c8 + lVar7,&PTR_LAB_142439170);
    plVar25 = *(longlong **)(&stack0x000000c0 + lVar7);
    goto LAB_1404ab2d1;
  }
  pcVar4 = (char *)(*(longlong *)(&stack0x00000050 + lVar7) + 0x80);
  *pcVar4 = *pcVar4 + -1;
  if (*pcVar4 != '\0') {
    *pcVar16 = '\0';
    lVar12 = *plVar26;
    if (lVar12 != 0) {
      lVar8 = *plVar2;
      if (lVar8 == *plVar25) {
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8f92;
        FUN_14079fd50(plVar25);
        lVar8 = *plVar2;
        lVar12 = *plVar26;
      }
      *(undefined1 *)(lVar12 + lVar8) = 0x5b;
      *plVar2 = *plVar2 + 1;
    }
    *(undefined8 *)(&stack0x000000f0 + lVar7) = *(undefined8 *)(&stack0x00000050 + lVar7);
    puVar21 = &stack0x00000420 + lVar7;
    while( true ) {
      if (*pcVar16 == '\0') {
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a8fed;
        FUN_14019d5e0(puVar21,*(undefined8 *)(&stack0xfffffffffffffff8 + lVar7));
        cVar20 = (&stack0x00000420)[lVar7];
        if (cVar20 != '\0') goto LAB_1404a952f;
        bVar19 = (&stack0x00000421)[lVar7];
        lVar12 = **(longlong **)(&stack0xfffffffffffffff0 + lVar7) + 1;
        if (bVar19 == 10) {
          lVar8 = *(longlong *)(&stack0x00000050 + lVar7);
          plVar3 = (longlong *)(lVar8 + 0x70);
          *plVar3 = *plVar3 + lVar12;
          plVar3 = (longlong *)(lVar8 + 0x60);
          *plVar3 = *plVar3 + 1;
          lVar12 = 0;
        }
        **(longlong **)(&stack0xfffffffffffffff0 + lVar7) = lVar12;
        *pcVar16 = '\x01';
        *pbVar28 = bVar19;
      }
      else {
        bVar19 = *pbVar28;
      }
      if ((0x20 < bVar19) || ((0x100002600U >> ((ulonglong)bVar19 & 0x3f) & 1) == 0)) break;
      *pcVar16 = '\0';
      lVar12 = *plVar26;
      if (lVar12 != 0) {
        lVar8 = *plVar2;
        if (lVar8 == *plVar25) {
          *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9071;
          FUN_14079fd50(plVar25);
          lVar8 = *plVar2;
          lVar12 = *plVar26;
        }
        *(byte *)(lVar12 + lVar8) = bVar19;
        *plVar2 = *plVar2 + 1;
      }
    }
    if (bVar19 == 0x5d) {
      uVar9 = 0;
LAB_1404a9a8f:
      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9a94;
      uVar9 = FUN_14020dcb0(uVar9,&DAT_14243bd80,&PTR_LAB_1424389c8);
    }
    else {
      (&stack0x000000f8)[lVar7] = 0;
      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a90a3;
      FUN_1404a5930(&stack0x00000420 + lVar7,*(undefined8 *)(&stack0x00000050 + lVar7));
      if (*(longlong *)(&stack0x00000420 + lVar7) == 0) {
        *(undefined8 *)(&stack0x000000b8 + lVar7) = *(undefined8 *)(&stack0x00000428 + lVar7);
        *(undefined4 *)(&stack0x000007c0 + lVar7) = *(undefined4 *)(&stack0x00000430 + lVar7);
        *(undefined4 *)(&stack0x000007c4 + lVar7) = *(undefined4 *)(&stack0x00000434 + lVar7);
        *(undefined4 *)(&stack0x000007c8 + lVar7) = *(undefined4 *)(&stack0x00000438 + lVar7);
        *(undefined4 *)(&stack0x000007cc + lVar7) = *(undefined4 *)(&stack0x0000043c + lVar7);
        puVar21 = &stack0x00000420 + lVar7;
        while( true ) {
          if (*pcVar16 == '\0') {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a920d;
            FUN_14019d5e0(puVar21,*(undefined8 *)(&stack0xfffffffffffffff8 + lVar7));
            cVar20 = (&stack0x00000420)[lVar7];
            if (cVar20 != '\0') goto LAB_1404a952f;
            bVar19 = (&stack0x00000421)[lVar7];
            lVar12 = **(longlong **)(&stack0xfffffffffffffff0 + lVar7) + 1;
            if (bVar19 == 10) {
              lVar8 = *(longlong *)(&stack0x00000050 + lVar7);
              plVar3 = (longlong *)(lVar8 + 0x70);
              *plVar3 = *plVar3 + lVar12;
              plVar3 = (longlong *)(lVar8 + 0x60);
              *plVar3 = *plVar3 + 1;
              lVar12 = 0;
            }
            **(longlong **)(&stack0xfffffffffffffff0 + lVar7) = lVar12;
            *pcVar16 = '\x01';
            *pbVar28 = bVar19;
          }
          else {
            bVar19 = *pbVar28;
          }
          if (0x2c < bVar19) goto LAB_1404a9a73;
          if ((0x100002600U >> ((ulonglong)bVar19 & 0x3f) & 1) == 0) break;
          *pcVar16 = '\0';
          lVar12 = *plVar26;
          if (lVar12 != 0) {
            lVar8 = *plVar2;
            if (lVar8 == *plVar25) {
              *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9299;
              FUN_14079fd50(plVar25);
              lVar8 = *plVar2;
              lVar12 = *plVar26;
            }
            *(byte *)(lVar12 + lVar8) = bVar19;
            *plVar2 = *plVar2 + 1;
          }
        }
        if ((ulonglong)bVar19 == 0x2c) {
          *pcVar16 = '\0';
          lVar12 = *plVar26;
          if (lVar12 != 0) {
            lVar8 = *plVar2;
            if (lVar8 == *plVar25) {
              *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9373;
              FUN_14079fd50(plVar25);
              lVar8 = *plVar2;
              lVar12 = *plVar26;
            }
            *(undefined1 *)(lVar12 + lVar8) = 0x2c;
            *plVar2 = *plVar2 + 1;
          }
          puVar21 = &stack0x00000420 + lVar7;
          while( true ) {
            if (*pcVar16 == '\0') {
              *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a93bd;
              FUN_14019d5e0(puVar21,*(undefined8 *)(&stack0xfffffffffffffff8 + lVar7));
              if ((&stack0x00000420)[lVar7] != '\0') {
                if ((&stack0x00000420)[lVar7] != '\x02') goto LAB_1404a9a5e;
                uVar9 = *puVar1;
                uVar22 = **(undefined8 **)(&stack0xfffffffffffffff0 + lVar7);
                *(undefined8 *)(&stack0x00000420 + lVar7) = 5;
                goto LAB_1404a954f;
              }
              bVar19 = (&stack0x00000421)[lVar7];
              lVar12 = **(longlong **)(&stack0xfffffffffffffff0 + lVar7) + 1;
              if (bVar19 == 10) {
                lVar8 = *(longlong *)(&stack0x00000050 + lVar7);
                plVar3 = (longlong *)(lVar8 + 0x70);
                *plVar3 = *plVar3 + lVar12;
                plVar3 = (longlong *)(lVar8 + 0x60);
                *plVar3 = *plVar3 + 1;
                lVar12 = 0;
              }
              **(longlong **)(&stack0xfffffffffffffff0 + lVar7) = lVar12;
              *pcVar16 = '\x01';
              *pbVar28 = bVar19;
            }
            else {
              bVar19 = *pbVar28;
            }
            if ((0x20 < bVar19) || ((0x100002600U >> ((ulonglong)bVar19 & 0x3f) & 1) == 0)) break;
            *pcVar16 = '\0';
            lVar12 = *plVar26;
            if (lVar12 != 0) {
              lVar8 = *plVar2;
              if (lVar8 == *plVar25) {
                *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9449;
                FUN_14079fd50(plVar25);
                lVar8 = *plVar2;
                lVar12 = *plVar26;
              }
              *(byte *)(lVar12 + lVar8) = bVar19;
              *plVar2 = *plVar2 + 1;
            }
          }
          if (bVar19 != 0x5d) {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9582;
            FUN_1404af0a0(&stack0x00000420 + lVar7,*(undefined8 *)(&stack0x00000050 + lVar7));
            bVar19 = (&stack0x00000458)[lVar7];
            puVar21 = (undefined1 *)(ulonglong)bVar19;
            uVar9 = *(undefined8 *)(&stack0x00000420 + lVar7);
            *(undefined8 **)((longlong)alStackX_8 + lVar7 + -8) = puVar1;
            if (bVar19 != 2) {
              *(undefined8 *)(&stack0x00000920 + lVar7) = *(undefined8 *)(&stack0x00000448 + lVar7);
              *(undefined8 *)(&stack0x00000928 + lVar7) = *(undefined8 *)(&stack0x00000450 + lVar7);
              *(undefined8 *)(&stack0x00000910 + lVar7) = *(undefined8 *)(&stack0x00000438 + lVar7);
              *(undefined8 *)(&stack0x00000918 + lVar7) = *(undefined8 *)(&stack0x00000440 + lVar7);
              *(undefined8 *)(&stack0x00000900 + lVar7) = *(undefined8 *)(&stack0x00000428 + lVar7);
              *(undefined8 *)(&stack0x00000908 + lVar7) = *(undefined8 *)(&stack0x00000430 + lVar7);
              *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a95ec;
              memcpy(&stack0x00000931 + lVar7,&stack0x00000459 + lVar7,0x1af);
              *(undefined8 *)(&stack0x000008f8 + lVar7) = uVar9;
              (&stack0x000000b0)[lVar7] = bVar19;
              (&stack0x00000930)[lVar7] = bVar19;
              puVar21 = &stack0x00000420 + lVar7;
              while( true ) {
                if (*pcVar16 == '\0') {
                  *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a964d;
                  FUN_14019d5e0(puVar21,*(undefined8 *)(&stack0xfffffffffffffff8 + lVar7));
                  if ((&stack0x00000420)[lVar7] != '\0') {
                    if ((&stack0x00000420)[lVar7] != '\x02') goto LAB_1404a9e24;
                    uVar9 = **(undefined8 **)((longlong)alStackX_8 + lVar7 + -8);
                    uVar22 = **(undefined8 **)(&stack0xfffffffffffffff0 + lVar7);
                    *(undefined8 *)(&stack0x00000420 + lVar7) = 2;
                    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9a38;
                    uVar9 = FUN_1413e8fd0(&stack0x00000420 + lVar7,uVar9,uVar22);
                    goto LAB_1404a9e34;
                  }
                  bVar19 = (&stack0x00000421)[lVar7];
                  lVar12 = **(longlong **)(&stack0xfffffffffffffff0 + lVar7) + 1;
                  if (bVar19 == 10) {
                    lVar8 = *(longlong *)(&stack0x00000050 + lVar7);
                    plVar3 = (longlong *)(lVar8 + 0x70);
                    *plVar3 = *plVar3 + lVar12;
                    plVar3 = (longlong *)(lVar8 + 0x60);
                    *plVar3 = *plVar3 + 1;
                    lVar12 = 0;
                  }
                  **(longlong **)(&stack0xfffffffffffffff0 + lVar7) = lVar12;
                  *pcVar16 = '\x01';
                  *pbVar28 = bVar19;
                }
                else {
                  bVar19 = *pbVar28;
                }
                if (0x2c < bVar19) goto LAB_1404a9bd0;
                if ((0x100002600U >> ((ulonglong)bVar19 & 0x3f) & 1) == 0) break;
                *pcVar16 = '\0';
                lVar12 = *plVar26;
                if (lVar12 != 0) {
                  lVar8 = *plVar2;
                  if (lVar8 == *plVar25) {
                    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a96d9;
                    FUN_14079fd50(plVar25);
                    lVar8 = *plVar2;
                    lVar12 = *plVar26;
                  }
                  *(byte *)(lVar12 + lVar8) = bVar19;
                  *plVar2 = *plVar2 + 1;
                }
              }
              if ((ulonglong)bVar19 == 0x2c) {
                *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9b04;
                FUN_14036c6b0(plVar25);
                puVar21 = &stack0x00000420 + lVar7;
                do {
                  if (*pcVar16 == '\0') {
                    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9b38;
                    FUN_14019d5e0(puVar21,*(undefined8 *)(&stack0xfffffffffffffff8 + lVar7));
                    if ((&stack0x00000420)[lVar7] != '\0') {
                      if ((&stack0x00000420)[lVar7] == '\x02') {
                        uVar9 = **(undefined8 **)((longlong)alStackX_8 + lVar7 + -8);
                        uVar22 = **(undefined8 **)(&stack0xfffffffffffffff0 + lVar7);
                        *(undefined8 *)(&stack0x00000420 + lVar7) = 5;
                        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9e22;
                        uVar9 = FUN_1413e8fd0(&stack0x00000420 + lVar7,uVar9,uVar22);
                      }
                      else {
LAB_1404a9e24:
                        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9e31;
                        uVar9 = FUN_1413e9060(*(undefined8 *)(&stack0x00000428 + lVar7));
                      }
                      goto LAB_1404a9e34;
                    }
                    bVar19 = (&stack0x00000421)[lVar7];
                    lVar12 = **(longlong **)(&stack0xfffffffffffffff0 + lVar7) + 1;
                    if (bVar19 == 10) {
                      lVar8 = *(longlong *)(&stack0x00000050 + lVar7);
                      plVar3 = (longlong *)(lVar8 + 0x70);
                      *plVar3 = *plVar3 + lVar12;
                      plVar3 = (longlong *)(lVar8 + 0x60);
                      *plVar3 = *plVar3 + 1;
                      lVar12 = 0;
                    }
                    **(longlong **)(&stack0xfffffffffffffff0 + lVar7) = lVar12;
                    *pcVar16 = '\x01';
                    *pbVar28 = bVar19;
                  }
                  else {
                    bVar19 = *pbVar28;
                  }
                  if ((0x20 < bVar19) || ((0x100002600U >> ((ulonglong)bVar19 & 0x3f) & 1) == 0))
                  goto LAB_1404aa1f7;
                  *pcVar16 = '\0';
                  lVar12 = *plVar26;
                  if (lVar12 != 0) {
                    lVar8 = *plVar2;
                    if (lVar8 == *plVar25) {
                      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9bc4;
                      FUN_14079fd50(plVar25);
                      lVar8 = *plVar2;
                      lVar12 = *plVar26;
                    }
                    *(byte *)(lVar12 + lVar8) = bVar19;
                    *plVar2 = *plVar2 + 1;
                  }
                } while( true );
              }
LAB_1404a9bd0:
              if (bVar19 == 0x5d) {
                *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9bed;
                uVar9 = FUN_14020dcb0(2,&DAT_14243bd80,&PTR_LAB_1424389c8);
              }
              else {
                uVar9 = **(undefined8 **)((longlong)alStackX_8 + lVar7 + -8);
                uVar22 = **(undefined8 **)(&stack0xfffffffffffffff0 + lVar7);
                *(undefined8 *)(&stack0x00000420 + lVar7) = 7;
                *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9c1b;
                uVar9 = FUN_1413e8fd0(&stack0x00000420 + lVar7,uVar9,uVar22);
              }
              goto LAB_1404a9e34;
            }
            goto LAB_1404a9e41;
          }
          uVar9 = *puVar1;
          uVar22 = **(undefined8 **)(&stack0xfffffffffffffff0 + lVar7);
          *(undefined8 *)(&stack0x00000420 + lVar7) = 0x15;
        }
        else {
LAB_1404a9a73:
          if (bVar19 == 0x5d) {
            uVar9 = 1;
            goto LAB_1404a9a8f;
          }
          uVar9 = *puVar1;
          uVar22 = **(undefined8 **)(&stack0xfffffffffffffff0 + lVar7);
          *(undefined8 *)(&stack0x00000420 + lVar7) = 7;
        }
LAB_1404a954f:
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a955c;
        uVar9 = FUN_1413e8fd0(&stack0x00000420 + lVar7,uVar9,uVar22);
      }
      else {
        uVar9 = *(undefined8 *)(&stack0x00000428 + lVar7);
      }
    }
    goto LAB_1404a9e41;
  }
LAB_1404a9767:
  uVar9 = *puVar1;
  uVar22 = **(undefined8 **)(&stack0xfffffffffffffff0 + lVar7);
  *(undefined8 *)(&stack0x00000420 + lVar7) = 0x18;
LAB_1404a977f:
  *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a978c;
  lVar12 = FUN_1413e8fd0(&stack0x00000420 + lVar7,uVar9,uVar22);
LAB_1404a978c:
  plVar25 = *(longlong **)(&stack0x000000c0 + lVar7);
  goto LAB_1404ab2dc;
LAB_1404a952f:
  if (cVar20 == '\x02') {
    uVar9 = *puVar1;
    uVar22 = **(undefined8 **)(&stack0xfffffffffffffff0 + lVar7);
    *(undefined8 *)(&stack0x00000420 + lVar7) = 2;
    goto LAB_1404a954f;
  }
LAB_1404a9a5e:
  *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9a6b;
  uVar9 = FUN_1413e9060(*(undefined8 *)(&stack0x00000428 + lVar7));
  goto LAB_1404a9e41;
LAB_1404aa1f7:
  if (bVar19 == 0x5d) {
    uVar9 = **(undefined8 **)((longlong)alStackX_8 + lVar7 + -8);
    uVar22 = **(undefined8 **)(&stack0xfffffffffffffff0 + lVar7);
    *(undefined8 *)(&stack0x00000420 + lVar7) = 0x15;
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa229;
    uVar9 = FUN_1413e8fd0(&stack0x00000420 + lVar7,uVar9,uVar22);
LAB_1404a9e34:
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404a9e41;
    FUN_14045b020(&stack0x000008f8 + lVar7);
LAB_1404a9e41:
    uVar15 = 2;
  }
  else {
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa2b6;
    FUN_14049dff0(&stack0x00000420 + lVar7,*(undefined8 *)(&stack0x00000050 + lVar7));
    plVar26 = *(longlong **)(&stack0x00000428 + lVar7);
    if (plVar26 == (longlong *)0x0) {
      uVar9 = *(undefined8 *)(&stack0x00000420 + lVar7);
      goto LAB_1404a9e34;
    }
    lVar12 = *(longlong *)(&stack0x00000420 + lVar7);
    *(longlong *)(&stack0x00000268 + lVar7) = lVar12;
    *(longlong **)(&stack0x00000270 + lVar7) = plVar26;
    *(undefined8 *)(&stack0x00000278 + lVar7) = *(undefined8 *)(&stack0x00000430 + lVar7);
    while( true ) {
      if (*pcVar16 == '\0') {
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa310;
        FUN_1406c1240(&stack0x00000420 + lVar7,*(undefined8 *)(&stack0xfffffffffffffff8 + lVar7));
        if ((&stack0x00000420)[lVar7] != '\0') {
          if ((&stack0x00000420)[lVar7] == '\x02') {
            uVar9 = **(undefined8 **)((longlong)alStackX_8 + lVar7 + -8);
            uVar22 = **(undefined8 **)(&stack0xfffffffffffffff0 + lVar7);
            *(undefined8 *)(&stack0x00000420 + lVar7) = 2;
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa3e3;
            uVar9 = FUN_1413e8fd0(&stack0x00000420 + lVar7,uVar9,uVar22);
          }
          else {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa7b3;
            uVar9 = FUN_1413e9060(*(undefined8 *)(&stack0x00000428 + lVar7));
          }
          goto LAB_1404ab38e;
        }
        bVar19 = (&stack0x00000421)[lVar7];
        *pcVar16 = '\x01';
        *pbVar28 = bVar19;
      }
      else {
        bVar19 = *pbVar28;
      }
      if (0x2c < bVar19) goto LAB_1404aa780;
      if ((0x100002600U >> ((ulonglong)bVar19 & 0x3f) & 1) == 0) break;
      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa356;
      FUN_14036c6b0(plVar25);
    }
    if ((ulonglong)bVar19 != 0x2c) {
LAB_1404aa780:
      if (bVar19 == 0x5d) {
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa7a1;
        uVar9 = FUN_14020dcb0(3,&DAT_14243bd80,&PTR_LAB_1424389c8);
      }
      else {
        uVar9 = **(undefined8 **)((longlong)alStackX_8 + lVar7 + -8);
        uVar22 = **(undefined8 **)(&stack0xfffffffffffffff0 + lVar7);
        *(undefined8 *)(&stack0x00000420 + lVar7) = 7;
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab326;
        uVar9 = FUN_1413e8fd0(&stack0x00000420 + lVar7,uVar9,uVar22);
      }
LAB_1404ab38e:
      if (lVar12 != 0) {
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab3b7;
        FUN_1408192a0(plVar26,lVar12 * 0x1c,4);
      }
      goto LAB_1404a9e34;
    }
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa717;
    FUN_14036c6b0(plVar25);
    while( true ) {
      if (*pcVar16 == '\0') {
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa738;
        FUN_1406c1240(&stack0x00000420 + lVar7,*(undefined8 *)(&stack0xfffffffffffffff8 + lVar7));
        if ((&stack0x00000420)[lVar7] != '\0') {
          if ((&stack0x00000420)[lVar7] == '\x02') {
            uVar9 = *puVar1;
            uVar22 = **(undefined8 **)(&stack0xfffffffffffffff0 + lVar7);
            *(undefined8 *)(&stack0x00000420 + lVar7) = 5;
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab351;
            uVar9 = FUN_1413e8fd0(&stack0x00000420 + lVar7,uVar9,uVar22);
          }
          else {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab38b;
            uVar9 = FUN_1413e9060(*(undefined8 *)(&stack0x00000428 + lVar7));
          }
          goto LAB_1404ab38e;
        }
        bVar19 = (&stack0x00000421)[lVar7];
        *pcVar16 = '\x01';
        *pbVar28 = bVar19;
      }
      else {
        bVar19 = *pbVar28;
      }
      if ((0x20 < bVar19) || ((0x100002600U >> ((ulonglong)bVar19 & 0x3f) & 1) == 0)) break;
      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa77e;
      FUN_14036c6b0(plVar25);
    }
    if (bVar19 == 0x5d) {
      uVar9 = *puVar1;
      uVar22 = **(undefined8 **)(&stack0xfffffffffffffff0 + lVar7);
      *(undefined8 *)(&stack0x00000420 + lVar7) = 0x15;
      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab37c;
      uVar9 = FUN_1413e8fd0(&stack0x00000420 + lVar7,uVar9,uVar22);
      goto LAB_1404ab38e;
    }
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab3d1;
    FUN_14049d4e0(&stack0x00000420 + lVar7,*(undefined8 *)(&stack0x00000050 + lVar7));
    *(longlong *)(&stack0x000000a8 + lVar7) = *(longlong *)(&stack0x00000428 + lVar7);
    if (*(longlong *)(&stack0x00000428 + lVar7) == 0) {
      uVar9 = *(undefined8 *)(&stack0x00000420 + lVar7);
      goto LAB_1404ab38e;
    }
    lVar8 = *(longlong *)(&stack0x00000420 + lVar7);
    *(longlong *)(&stack0x000002c0 + lVar7) = lVar8;
    *(undefined8 *)(&stack0x000002c8 + lVar7) = *(undefined8 *)(&stack0x000000a8 + lVar7);
    *(undefined8 *)(&stack0x000002d0 + lVar7) = *(undefined8 *)(&stack0x00000430 + lVar7);
    while( true ) {
      if (*pcVar16 == '\0') {
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab43b;
        FUN_1406c1240(&stack0x00000420 + lVar7,*(undefined8 *)(&stack0xfffffffffffffff8 + lVar7));
        if ((&stack0x00000420)[lVar7] != '\0') {
          if ((&stack0x00000420)[lVar7] == '\x02') {
            uVar9 = *puVar1;
            uVar22 = **(undefined8 **)(&stack0xfffffffffffffff0 + lVar7);
            *(undefined8 *)(&stack0x00000420 + lVar7) = 2;
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab4b5;
            uVar9 = FUN_1413e8fd0(&stack0x00000420 + lVar7,uVar9,uVar22);
          }
          else {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab560;
            uVar9 = FUN_1413e9060(*(undefined8 *)(&stack0x00000428 + lVar7));
          }
          goto LAB_1404ab5f1;
        }
        bVar19 = (&stack0x00000421)[lVar7];
        *pcVar16 = '\x01';
        *pbVar28 = bVar19;
      }
      else {
        bVar19 = *pbVar28;
      }
      if (0x2c < bVar19) goto LAB_1404ab531;
      if ((0x100002600U >> ((ulonglong)bVar19 & 0x3f) & 1) == 0) break;
      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab479;
      FUN_14036c6b0(plVar25);
    }
    if ((ulonglong)bVar19 != 0x2c) {
LAB_1404ab531:
      if (bVar19 == 0x5d) {
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab54e;
        uVar9 = FUN_14020dcb0(4,&DAT_14243bd80,&PTR_LAB_1424389c8);
      }
      else {
        uVar9 = *puVar1;
        uVar22 = **(undefined8 **)(&stack0xfffffffffffffff0 + lVar7);
        *(undefined8 *)(&stack0x00000420 + lVar7) = 7;
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab589;
        uVar9 = FUN_1413e8fd0(&stack0x00000420 + lVar7,uVar9,uVar22);
      }
LAB_1404ab5f1:
      puVar21 = (undefined1 *)0x0;
      if (lVar8 != 0) {
        puVar21 = (undefined1 *)(lVar8 * 8);
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab61c;
        FUN_1408192a0(*(undefined8 *)(&stack0x000000a8 + lVar7),lVar8 * 0x28,8);
      }
      goto LAB_1404ab38e;
    }
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab4c8;
    FUN_14036c6b0(plVar25);
    while( true ) {
      if (*pcVar16 == '\0') {
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab4e9;
        FUN_1406c1240(&stack0x00000420 + lVar7,*(undefined8 *)(&stack0xfffffffffffffff8 + lVar7));
        if ((&stack0x00000420)[lVar7] != '\0') {
          if ((&stack0x00000420)[lVar7] == '\x02') {
            uVar9 = *puVar1;
            uVar22 = **(undefined8 **)(&stack0xfffffffffffffff0 + lVar7);
            *(undefined8 *)(&stack0x00000420 + lVar7) = 5;
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab5b4;
            uVar9 = FUN_1413e8fd0(&stack0x00000420 + lVar7,uVar9,uVar22);
          }
          else {
            *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab5ee;
            uVar9 = FUN_1413e9060(*(undefined8 *)(&stack0x00000428 + lVar7));
          }
          goto LAB_1404ab5f1;
        }
        bVar19 = (&stack0x00000421)[lVar7];
        *pcVar16 = '\x01';
        *pbVar28 = bVar19;
      }
      else {
        bVar19 = *pbVar28;
      }
      if ((0x20 < bVar19) || ((0x100002600U >> ((ulonglong)bVar19 & 0x3f) & 1) == 0)) break;
      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab52f;
      FUN_14036c6b0(plVar25);
    }
    if (bVar19 == 0x5d) {
      uVar9 = *puVar1;
      uVar22 = **(undefined8 **)(&stack0xfffffffffffffff0 + lVar7);
      *(undefined8 *)(&stack0x00000420 + lVar7) = 0x15;
      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab5df;
      uVar9 = FUN_1413e8fd0(&stack0x00000420 + lVar7,uVar9,uVar22);
      goto LAB_1404ab5f1;
    }
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab636;
    FUN_14049be40(&stack0x00000420 + lVar7,*(undefined8 *)(&stack0x00000050 + lVar7));
    lVar10 = *(longlong *)(&stack0x00000428 + lVar7);
    if (lVar10 == 0) {
      uVar9 = *(undefined8 *)(&stack0x00000420 + lVar7);
      goto LAB_1404ab5f1;
    }
    lVar17 = *(longlong *)(&stack0x00000420 + lVar7);
    *(longlong *)(&stack0x000002e0 + lVar7) = lVar17;
    *(longlong *)(&stack0x000002e8 + lVar7) = lVar10;
    *(undefined8 *)(&stack0x000002f0 + lVar7) = *(undefined8 *)(&stack0x00000430 + lVar7);
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab680;
    FUN_14046c250(&stack0x00000420 + lVar7,&stack0x000000f0 + lVar7);
    if (*(longlong *)(&stack0x00000420 + lVar7) != 0) {
      uVar9 = *(undefined8 *)(&stack0x00000428 + lVar7);
LAB_1404ab693:
      pcVar16 = (char *)0x0;
      if (lVar17 != 0) {
        pcVar16 = (char *)(lVar17 << 4);
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab6b1;
        FUN_1408192a0(lVar10,pcVar16,8);
      }
      goto LAB_1404ab5f1;
    }
    lVar18 = *(longlong *)(&stack0x00000430 + lVar7);
    if (lVar18 == 0) {
      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab761;
      uVar9 = FUN_14020dcb0(5,&DAT_14243bd80,&PTR_LAB_1424389c8);
      goto LAB_1404ab693;
    }
    lVar5 = *(longlong *)(&stack0x00000428 + lVar7);
    *(longlong *)(&stack0x00000300 + lVar7) = lVar5;
    *(longlong *)(&stack0x00000308 + lVar7) = lVar18;
    *(undefined8 *)(&stack0x00000310 + lVar7) = *(undefined8 *)(&stack0x00000438 + lVar7);
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab713;
    FUN_140469f00(&stack0x00000420 + lVar7,&stack0x000000f0 + lVar7);
    if (*(longlong *)(&stack0x00000420 + lVar7) != 0) {
      uVar9 = *(undefined8 *)(&stack0x00000428 + lVar7);
LAB_1404ab726:
      if (lVar5 != 0) {
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab744;
        FUN_1408192a0(lVar18,lVar5 << 4,8);
      }
      goto LAB_1404ab693;
    }
    *(longlong *)(&stack0xfffffffffffffff0 + lVar7) = *(longlong *)(&stack0x00000430 + lVar7);
    if (*(longlong *)(&stack0x00000430 + lVar7) == 0) {
      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab81f;
      uVar9 = FUN_14020dcb0(6,&DAT_14243bd80,&PTR_LAB_1424389c8);
      goto LAB_1404ab726;
    }
    *(undefined8 *)(&stack0xfffffffffffffff8 + lVar7) = *(undefined8 *)(&stack0x00000428 + lVar7);
    *(undefined8 *)(&stack0x00000320 + lVar7) = *(undefined8 *)(&stack0x00000428 + lVar7);
    *(undefined8 *)(&stack0x00000328 + lVar7) = *(undefined8 *)(&stack0xfffffffffffffff0 + lVar7);
    *(undefined8 *)(&stack0x00000330 + lVar7) = *(undefined8 *)(&stack0x00000438 + lVar7);
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab7c6;
    FUN_14046bcf0(&stack0x00000420 + lVar7,&stack0x000000f0 + lVar7);
    if (*(longlong *)(&stack0x00000420 + lVar7) != 0) {
      uVar9 = *(undefined8 *)(&stack0x00000428 + lVar7);
LAB_1404ab7d9:
      if (*(longlong *)(&stack0xfffffffffffffff8 + lVar7) != 0) {
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab802;
        FUN_1408192a0(*(undefined8 *)(&stack0xfffffffffffffff0 + lVar7),
                      *(longlong *)(&stack0xfffffffffffffff8 + lVar7) * 0x28,8);
      }
      goto LAB_1404ab726;
    }
    *(longlong *)(&stack0x000000a0 + lVar7) = *(longlong *)(&stack0x00000430 + lVar7);
    if (*(longlong *)(&stack0x00000430 + lVar7) == 0) {
      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab8ef;
      uVar9 = FUN_14020dcb0(7,&DAT_14243bd80,&PTR_LAB_1424389c8);
      goto LAB_1404ab7d9;
    }
    *(undefined8 *)(&stack0x00000098 + lVar7) = *(undefined8 *)(&stack0x00000428 + lVar7);
    *(undefined8 *)(&stack0x00000340 + lVar7) = *(undefined8 *)(&stack0x00000428 + lVar7);
    *(undefined8 *)(&stack0x00000348 + lVar7) = *(undefined8 *)(&stack0x000000a0 + lVar7);
    *(undefined8 *)(&stack0x00000350 + lVar7) = *(undefined8 *)(&stack0x00000438 + lVar7);
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab88d;
    FUN_14046c510(&stack0x00000420 + lVar7,&stack0x000000f0 + lVar7);
    if (*(longlong *)(&stack0x00000420 + lVar7) != 0) {
      uVar9 = *(undefined8 *)(&stack0x00000428 + lVar7);
LAB_1404ab8a0:
      if (*(longlong *)(&stack0x00000098 + lVar7) != 0) {
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab8d2;
        FUN_1408192a0(*(undefined8 *)(&stack0x000000a0 + lVar7),
                      *(longlong *)(&stack0x00000098 + lVar7) * 0x18,8);
      }
      goto LAB_1404ab7d9;
    }
    *(longlong *)(&stack0x00000090 + lVar7) = *(longlong *)(&stack0x00000430 + lVar7);
    if (*(longlong *)(&stack0x00000430 + lVar7) == 0) {
      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab989;
      uVar9 = FUN_14020dcb0(8,&DAT_14243bd80,&PTR_LAB_1424389c8);
      goto LAB_1404ab8a0;
    }
    *(undefined8 *)(&stack0x00000088 + lVar7) = *(undefined8 *)(&stack0x00000428 + lVar7);
    *(undefined8 *)(&stack0x00000360 + lVar7) = *(undefined8 *)(&stack0x00000428 + lVar7);
    *(undefined8 *)(&stack0x00000368 + lVar7) = *(undefined8 *)(&stack0x00000090 + lVar7);
    *(undefined8 *)(&stack0x00000370 + lVar7) = *(undefined8 *)(&stack0x00000438 + lVar7);
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab959;
    FUN_14046cff0(&stack0x00000420 + lVar7,&stack0x000000f0 + lVar7);
    if (*(longlong *)(&stack0x00000420 + lVar7) != 0) {
      uVar9 = *(undefined8 *)(&stack0x00000428 + lVar7);
LAB_1404abb58:
      if (*(longlong *)(&stack0x00000088 + lVar7) != 0) {
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404abb86;
        FUN_1408192a0(*(undefined8 *)(&stack0x00000090 + lVar7),
                      *(longlong *)(&stack0x00000088 + lVar7) << 4,8);
      }
      goto LAB_1404ab8a0;
    }
    *(longlong *)(&stack0x00000080 + lVar7) = *(longlong *)(&stack0x00000430 + lVar7);
    if (*(longlong *)(&stack0x00000430 + lVar7) == 0) {
      *(undefined8 *)(&stack0x00000150 + lVar7) = 0;
      *(undefined8 *)(&stack0x00000158 + lVar7) = 8;
      *(undefined8 *)(&stack0x00000160 + lVar7) = 0;
      *(undefined8 *)(&stack0x00000080 + lVar7) = 8;
      *(undefined8 *)(&stack0x00000078 + lVar7) = 0;
    }
    else {
      *(undefined8 *)(&stack0x00000078 + lVar7) = *(undefined8 *)(&stack0x00000428 + lVar7);
      *(undefined8 *)(&stack0x00000150 + lVar7) = *(undefined8 *)(&stack0x00000428 + lVar7);
      *(undefined8 *)(&stack0x00000158 + lVar7) = *(undefined8 *)(&stack0x00000080 + lVar7);
      *(undefined8 *)(&stack0x00000160 + lVar7) = *(undefined8 *)(&stack0x00000438 + lVar7);
    }
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aba33;
    FUN_14046b770(&stack0x00000420 + lVar7,&stack0x000000f0 + lVar7);
    if (*(longlong *)(&stack0x00000420 + lVar7) != 0) {
      uVar9 = *(undefined8 *)(&stack0x00000428 + lVar7);
LAB_1404abb2e:
      if (*(longlong *)(&stack0x00000078 + lVar7) != 0) {
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404abb58;
        FUN_1408192a0(*(undefined8 *)(&stack0x00000080 + lVar7),
                      *(longlong *)(&stack0x00000078 + lVar7) << 3,8);
      }
      goto LAB_1404abb58;
    }
    *(longlong *)(&stack0x00000070 + lVar7) = *(longlong *)(&stack0x00000430 + lVar7);
    if (*(longlong *)(&stack0x00000430 + lVar7) == 0) {
      *(undefined8 *)(&stack0x000000d0 + lVar7) = 0;
      *(undefined8 *)(&stack0x000000d8 + lVar7) = 8;
      *(undefined8 *)(&stack0x000000e0 + lVar7) = 0;
      *(undefined8 *)(&stack0x00000070 + lVar7) = 8;
      *(undefined8 *)(&stack0x00000060 + lVar7) = 0;
    }
    else {
      *(undefined8 *)(&stack0x00000060 + lVar7) = *(undefined8 *)(&stack0x00000428 + lVar7);
      *(undefined8 *)(&stack0x000000d0 + lVar7) = *(undefined8 *)(&stack0x00000428 + lVar7);
      *(undefined8 *)(&stack0x000000d8 + lVar7) = *(undefined8 *)(&stack0x00000070 + lVar7);
      *(undefined8 *)(&stack0x000000e0 + lVar7) = *(undefined8 *)(&stack0x00000438 + lVar7);
    }
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404abaed;
    FUN_14046ba30(&stack0x00000420 + lVar7,&stack0x000000f0 + lVar7);
    if (*(longlong *)(&stack0x00000420 + lVar7) != 0) {
      uVar9 = *(undefined8 *)(&stack0x00000428 + lVar7);
LAB_1404abb04:
      if (*(longlong *)(&stack0x00000060 + lVar7) != 0) {
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404abb2e;
        FUN_1408192a0(*(undefined8 *)(&stack0x00000070 + lVar7),
                      *(longlong *)(&stack0x00000060 + lVar7) << 3,8);
      }
      goto LAB_1404abb2e;
    }
    *(longlong *)(&stack0x00000068 + lVar7) = *(longlong *)(&stack0x00000430 + lVar7);
    if (*(longlong *)(&stack0x00000430 + lVar7) == 0) {
      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404abc1a;
      uVar9 = FUN_14020dcb0(0xb,&DAT_14243bd80,&PTR_LAB_1424389c8);
      goto LAB_1404abb04;
    }
    uVar9 = *(undefined8 *)(&stack0x00000428 + lVar7);
    uVar22 = *(undefined8 *)(&stack0x00000438 + lVar7);
    *(undefined8 *)((longlong)alStackX_8 + lVar7 + -8) = uVar9;
    *(undefined8 *)(&stack0x00000110 + lVar7) = uVar9;
    *(undefined8 *)(&stack0x00000118 + lVar7) = *(undefined8 *)(&stack0x00000068 + lVar7);
    *(undefined8 *)(&stack0x00000120 + lVar7) = uVar22;
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404abbea;
    FUN_14046a1c0(&stack0x00000420 + lVar7,&stack0x000000f0 + lVar7);
    if (*(longlong *)(&stack0x00000420 + lVar7) != 0) {
      uVar9 = *(undefined8 *)(&stack0x00000428 + lVar7);
LAB_1404abca9:
      if (*(longlong *)((longlong)alStackX_8 + lVar7 + -8) != 0) {
        lVar6 = *(longlong *)((longlong)alStackX_8 + lVar7 + -8);
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404abcd1;
        FUN_1408192a0(*(undefined8 *)(&stack0x00000068 + lVar7),lVar6 << 5,4);
      }
      goto LAB_1404abb04;
    }
    if (*(longlong *)(&stack0x00000430 + lVar7) == 0) {
      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404abca6;
      uVar9 = FUN_14020dcb0(0xc,&DAT_14243bd80,&PTR_LAB_1424389c8);
      goto LAB_1404abca9;
    }
    *(undefined8 *)(&stack0x00000380 + lVar7) = *(undefined8 *)(&stack0x00000428 + lVar7);
    *(longlong *)(&stack0x00000388 + lVar7) = *(longlong *)(&stack0x00000430 + lVar7);
    *(undefined8 *)(&stack0x00000390 + lVar7) = *(undefined8 *)(&stack0x00000438 + lVar7);
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404abc6c;
    FUN_14046e070(&stack0x00000420 + lVar7,&stack0x000000f0 + lVar7);
    if (*(longlong *)(&stack0x00000420 + lVar7) != 0) {
      uVar9 = *(undefined8 *)(&stack0x00000428 + lVar7);
LAB_1404abc7f:
      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404abc8c;
      FUN_140459390(&stack0x00000380 + lVar7);
      goto LAB_1404abca9;
    }
    lVar6 = *(longlong *)(&stack0x00000430 + lVar7);
    *(longlong *)((longlong)alStackX_8 + lVar7 + 8) = lVar6;
    if (lVar6 == 0) {
      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404abd8c;
      uVar9 = FUN_14020dcb0(0xd,&DAT_14243bd80,&PTR_LAB_1424389c8);
      goto LAB_1404abc7f;
    }
    *(undefined8 *)((longlong)alStackX_8 + lVar7) = *(undefined8 *)(&stack0x00000428 + lVar7);
    *(undefined8 *)(&stack0x00000760 + lVar7) = *(undefined8 *)(&stack0x00000428 + lVar7);
    *(undefined8 *)(&stack0x00000768 + lVar7) = *(undefined8 *)((longlong)alStackX_8 + lVar7 + 8);
    *(undefined8 *)(&stack0x00000770 + lVar7) = *(undefined8 *)(&stack0x00000438 + lVar7);
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404abd33;
    FUN_14046e070(&stack0x00000420 + lVar7,&stack0x000000f0 + lVar7);
    if (*(longlong *)(&stack0x00000420 + lVar7) != 0) {
      uVar9 = *(undefined8 *)(&stack0x00000428 + lVar7);
      if (*(longlong *)((longlong)alStackX_8 + lVar7) != 0) {
        uVar22 = *(undefined8 *)((longlong)alStackX_8 + lVar7 + 8);
        *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404abd6f;
        FUN_1408192a0(uVar22,*(longlong *)((longlong)alStackX_8 + lVar7) * 0xc,4);
      }
      goto LAB_1404abc7f;
    }
    bVar38 = *(undefined1 **)(&stack0x00000430 + lVar7) == (undefined1 *)0x0;
    pcVar16 = *(char **)(&stack0x00000428 + lVar7);
    if (bVar38) {
      pcVar16 = (char *)0x0;
    }
    plVar26 = *(longlong **)(&stack0x00000438 + lVar7);
    if (bVar38) {
      plVar26 = (longlong *)0x0;
    }
    puVar21 = (undefined1 *)0x4;
    if (!bVar38) {
      puVar21 = *(undefined1 **)(&stack0x00000430 + lVar7);
    }
    *(undefined8 *)(&stack0x000007a0 + lVar7) = *(undefined8 *)(&stack0x000007c0 + lVar7);
    *(undefined8 *)(&stack0x000007a8 + lVar7) = *(undefined8 *)(&stack0x000007c8 + lVar7);
    *(undefined8 *)(&stack0x00000e00 + lVar7) = *(undefined8 *)(&stack0x000008f8 + lVar7);
    *(undefined8 *)(&stack0x00000e08 + lVar7) = *(undefined8 *)(&stack0x00000900 + lVar7);
    *(undefined8 *)(&stack0x00000e10 + lVar7) = *(undefined8 *)(&stack0x00000908 + lVar7);
    *(undefined8 *)(&stack0x00000e18 + lVar7) = *(undefined8 *)(&stack0x00000910 + lVar7);
    *(undefined8 *)(&stack0x00000e20 + lVar7) = *(undefined8 *)(&stack0x00000918 + lVar7);
    *(undefined8 *)(&stack0x00000e28 + lVar7) = *(undefined8 *)(&stack0x00000920 + lVar7);
    *(undefined8 *)(&stack0x00000e30 + lVar7) = *(undefined8 *)(&stack0x00000928 + lVar7);
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404abe2b;
    memcpy(&stack0x00000c50 + lVar7,&stack0x00000931 + lVar7,0x1af);
    *(undefined8 *)(&stack0x000003b0 + lVar7) = *(undefined8 *)(&stack0x00000268 + lVar7);
    *(undefined8 *)(&stack0x000003b8 + lVar7) = *(undefined8 *)(&stack0x00000270 + lVar7);
    *(undefined8 *)(&stack0x000003c0 + lVar7) = *(undefined8 *)(&stack0x00000278 + lVar7);
    *(undefined8 *)(&stack0x00000130 + lVar7) = *(undefined8 *)(&stack0x000002c0 + lVar7);
    *(undefined8 *)(&stack0x00000138 + lVar7) = *(undefined8 *)(&stack0x000002c8 + lVar7);
    *(undefined8 *)(&stack0x00000140 + lVar7) = *(undefined8 *)(&stack0x000002d0 + lVar7);
    *(undefined8 *)(&stack0x00000250 + lVar7) = *(undefined8 *)(&stack0x000002e0 + lVar7);
    *(undefined8 *)(&stack0x00000258 + lVar7) = *(undefined8 *)(&stack0x000002e8 + lVar7);
    *(undefined8 *)(&stack0x00000260 + lVar7) = *(undefined8 *)(&stack0x000002f0 + lVar7);
    *(undefined8 *)(&stack0x000002a0 + lVar7) = *(undefined8 *)(&stack0x00000300 + lVar7);
    *(undefined8 *)(&stack0x000002a8 + lVar7) = *(undefined8 *)(&stack0x00000308 + lVar7);
    *(undefined8 *)(&stack0x000002b0 + lVar7) = *(undefined8 *)(&stack0x00000310 + lVar7);
    *(undefined8 *)(&stack0x00000290 + lVar7) = *(undefined8 *)(&stack0x00000330 + lVar7);
    *(undefined8 *)(&stack0x00000280 + lVar7) = *(undefined8 *)(&stack0x00000320 + lVar7);
    *(undefined8 *)(&stack0x00000288 + lVar7) = *(undefined8 *)(&stack0x00000328 + lVar7);
    *(undefined8 *)(&stack0x00000240 + lVar7) = *(undefined8 *)(&stack0x00000350 + lVar7);
    *(undefined8 *)(&stack0x00000230 + lVar7) = *(undefined8 *)(&stack0x00000340 + lVar7);
    *(undefined8 *)(&stack0x00000238 + lVar7) = *(undefined8 *)(&stack0x00000348 + lVar7);
    *(undefined8 *)(&stack0x00000210 + lVar7) = *(undefined8 *)(&stack0x00000360 + lVar7);
    *(undefined8 *)(&stack0x00000218 + lVar7) = *(undefined8 *)(&stack0x00000368 + lVar7);
    *(undefined8 *)(&stack0x00000220 + lVar7) = *(undefined8 *)(&stack0x00000370 + lVar7);
    *(undefined8 *)(&stack0x000001f0 + lVar7) = *(undefined8 *)(&stack0x00000150 + lVar7);
    *(undefined8 *)(&stack0x000001f8 + lVar7) = *(undefined8 *)(&stack0x00000158 + lVar7);
    *(undefined8 *)(&stack0x00000200 + lVar7) = *(undefined8 *)(&stack0x00000160 + lVar7);
    *(undefined8 *)(&stack0x000001d0 + lVar7) = *(undefined8 *)(&stack0x000000d0 + lVar7);
    *(undefined8 *)(&stack0x000001d8 + lVar7) = *(undefined8 *)(&stack0x000000d8 + lVar7);
    *(undefined8 *)(&stack0x000001e0 + lVar7) = *(undefined8 *)(&stack0x000000e0 + lVar7);
    *(undefined8 *)(&stack0x000001c0 + lVar7) = *(undefined8 *)(&stack0x00000120 + lVar7);
    *(undefined8 *)(&stack0x000001b0 + lVar7) = *(undefined8 *)(&stack0x00000110 + lVar7);
    *(undefined8 *)(&stack0x000001b8 + lVar7) = *(undefined8 *)(&stack0x00000118 + lVar7);
    *(undefined8 *)(&stack0x000001a0 + lVar7) = *(undefined8 *)(&stack0x00000390 + lVar7);
    *(undefined8 *)(&stack0x00000190 + lVar7) = *(undefined8 *)(&stack0x00000380 + lVar7);
    *(undefined8 *)(&stack0x00000198 + lVar7) = *(undefined8 *)(&stack0x00000388 + lVar7);
    *(undefined8 *)(&stack0x00000180 + lVar7) = *(undefined8 *)(&stack0x00000770 + lVar7);
    *(undefined8 *)(&stack0x00000170 + lVar7) = *(undefined8 *)(&stack0x00000760 + lVar7);
    *(undefined8 *)(&stack0x00000178 + lVar7) = *(undefined8 *)(&stack0x00000768 + lVar7);
    uVar9 = *(undefined8 *)(&stack0x000000b8 + lVar7);
    uVar15 = (&stack0x000000b0)[lVar7];
  }
  lVar12 = *(longlong *)(&stack0x00000050 + lVar7);
  pcVar4 = (char *)(lVar12 + 0x80);
  *pcVar4 = *pcVar4 + '\x01';
  *(undefined8 *)(&stack0x000008f8 + lVar7) = uVar9;
  *(undefined8 *)(&stack0x00000900 + lVar7) = *(undefined8 *)(&stack0x000007a0 + lVar7);
  *(undefined8 *)(&stack0x00000908 + lVar7) = *(undefined8 *)(&stack0x000007a8 + lVar7);
  *(undefined8 *)(&stack0x00000910 + lVar7) = *(undefined8 *)(&stack0x000003b0 + lVar7);
  *(undefined8 *)(&stack0x00000918 + lVar7) = *(undefined8 *)(&stack0x000003b8 + lVar7);
  *(undefined8 *)(&stack0x00000920 + lVar7) = *(undefined8 *)(&stack0x000003c0 + lVar7);
  *(undefined8 *)(&stack0x00000928 + lVar7) = *(undefined8 *)(&stack0x00000130 + lVar7);
  *(undefined8 *)(&stack0x00000930 + lVar7) = *(undefined8 *)(&stack0x00000138 + lVar7);
  *(undefined8 *)(&stack0x00000938 + lVar7) = *(undefined8 *)(&stack0x00000140 + lVar7);
  *(undefined8 *)(&stack0x00000940 + lVar7) = *(undefined8 *)(&stack0x00000250 + lVar7);
  *(undefined8 *)(&stack0x00000948 + lVar7) = *(undefined8 *)(&stack0x00000258 + lVar7);
  *(undefined8 *)(&stack0x00000950 + lVar7) = *(undefined8 *)(&stack0x00000260 + lVar7);
  *(undefined8 *)(&stack0x00000958 + lVar7) = *(undefined8 *)(&stack0x000002a0 + lVar7);
  *(undefined8 *)(&stack0x00000960 + lVar7) = *(undefined8 *)(&stack0x000002a8 + lVar7);
  *(undefined8 *)(&stack0x00000968 + lVar7) = *(undefined8 *)(&stack0x000002b0 + lVar7);
  *(undefined8 *)(&stack0x00000980 + lVar7) = *(undefined8 *)(&stack0x00000290 + lVar7);
  *(undefined8 *)(&stack0x00000970 + lVar7) = *(undefined8 *)(&stack0x00000280 + lVar7);
  *(undefined8 *)(&stack0x00000978 + lVar7) = *(undefined8 *)(&stack0x00000288 + lVar7);
  *(undefined8 *)(&stack0x00000998 + lVar7) = *(undefined8 *)(&stack0x00000240 + lVar7);
  *(undefined8 *)(&stack0x00000988 + lVar7) = *(undefined8 *)(&stack0x00000230 + lVar7);
  *(undefined8 *)(&stack0x00000990 + lVar7) = *(undefined8 *)(&stack0x00000238 + lVar7);
  *(undefined8 *)(&stack0x000009b0 + lVar7) = *(undefined8 *)(&stack0x00000220 + lVar7);
  *(undefined8 *)(&stack0x000009a0 + lVar7) = *(undefined8 *)(&stack0x00000210 + lVar7);
  *(undefined8 *)(&stack0x000009a8 + lVar7) = *(undefined8 *)(&stack0x00000218 + lVar7);
  *(undefined8 *)(&stack0x000009c8 + lVar7) = *(undefined8 *)(&stack0x00000200 + lVar7);
  *(undefined8 *)(&stack0x000009b8 + lVar7) = *(undefined8 *)(&stack0x000001f0 + lVar7);
  *(undefined8 *)(&stack0x000009c0 + lVar7) = *(undefined8 *)(&stack0x000001f8 + lVar7);
  *(undefined8 *)(&stack0x000009e0 + lVar7) = *(undefined8 *)(&stack0x000001e0 + lVar7);
  *(undefined8 *)(&stack0x000009d0 + lVar7) = *(undefined8 *)(&stack0x000001d0 + lVar7);
  *(undefined8 *)(&stack0x000009d8 + lVar7) = *(undefined8 *)(&stack0x000001d8 + lVar7);
  *(undefined8 *)(&stack0x000009f8 + lVar7) = *(undefined8 *)(&stack0x000001c0 + lVar7);
  *(undefined8 *)(&stack0x000009e8 + lVar7) = *(undefined8 *)(&stack0x000001b0 + lVar7);
  *(undefined8 *)(&stack0x000009f0 + lVar7) = *(undefined8 *)(&stack0x000001b8 + lVar7);
  *(undefined8 *)(&stack0x00000a10 + lVar7) = *(undefined8 *)(&stack0x000001a0 + lVar7);
  *(undefined8 *)(&stack0x00000a00 + lVar7) = *(undefined8 *)(&stack0x00000190 + lVar7);
  *(undefined8 *)(&stack0x00000a08 + lVar7) = *(undefined8 *)(&stack0x00000198 + lVar7);
  *(undefined8 *)(&stack0x00000a28 + lVar7) = *(undefined8 *)(&stack0x00000180 + lVar7);
  *(undefined8 *)(&stack0x00000a18 + lVar7) = *(undefined8 *)(&stack0x00000170 + lVar7);
  *(undefined8 *)(&stack0x00000a20 + lVar7) = *(undefined8 *)(&stack0x00000178 + lVar7);
  *(char **)(&stack0x00000a30 + lVar7) = pcVar16;
  *(undefined1 **)(&stack0x00000a38 + lVar7) = puVar21;
  *(longlong **)(&stack0x00000a40 + lVar7) = plVar26;
  *(undefined8 *)(&stack0x00000a78 + lVar7) = *(undefined8 *)(&stack0x00000e30 + lVar7);
  *(undefined8 *)(&stack0x00000a68 + lVar7) = *(undefined8 *)(&stack0x00000e20 + lVar7);
  *(undefined8 *)(&stack0x00000a70 + lVar7) = *(undefined8 *)(&stack0x00000e28 + lVar7);
  *(undefined8 *)(&stack0x00000a58 + lVar7) = *(undefined8 *)(&stack0x00000e10 + lVar7);
  *(undefined8 *)(&stack0x00000a60 + lVar7) = *(undefined8 *)(&stack0x00000e18 + lVar7);
  *(undefined8 *)(&stack0x00000a48 + lVar7) = *(undefined8 *)(&stack0x00000e00 + lVar7);
  *(undefined8 *)(&stack0x00000a50 + lVar7) = *(undefined8 *)(&stack0x00000e08 + lVar7);
  (&stack0x00000a80)[lVar7] = uVar15;
  *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa066;
  memcpy(&stack0x00000a81 + lVar7,&stack0x00000c50 + lVar7,0x1af);
  *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa06e;
  lVar8 = FUN_1404414b0(lVar12);
  *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa08c;
  memcpy(&stack0x00000420 + lVar7,&stack0x000008f8 + lVar7,0x338);
  *(longlong *)(&stack0x00000758 + lVar7) = lVar8;
  cVar20 = (&stack0x000005a8)[lVar7];
  plVar25 = *(longlong **)(&stack0x000000c0 + lVar7);
  if (cVar20 == '\x02') {
    lVar10 = *(longlong *)(&stack0x00000420 + lVar7);
    cVar20 = '\x02';
    if (lVar8 == 0) {
      lVar12 = *(longlong *)(&stack0x00000050 + lVar7);
    }
    else {
      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa0c4;
      FUN_14045bac0(lVar8 + 0x10);
      lVar12 = *(longlong *)(&stack0x00000050 + lVar7);
LAB_1404ab21c:
      cVar20 = '\x02';
      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab22f;
      FUN_1408192a0(lVar8,0x28,8);
    }
  }
  else if (lVar8 == 0) {
    lVar10 = *(longlong *)(&stack0x00000420 + lVar7);
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa12d;
    memcpy(&stack0x00000fb8 + lVar7,&stack0x00000428 + lVar7,0x180);
    plVar25 = *(longlong **)(&stack0x000000c0 + lVar7);
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa14b;
    memcpy(&stack0x00001139 + lVar7,&stack0x000005a9 + lVar7,0x1af);
    lVar12 = *(longlong *)(&stack0x00000050 + lVar7);
  }
  else {
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aa0e3;
    FUN_14045ac60(&stack0x00000420 + lVar7);
    cVar20 = '\x02';
    lVar12 = *(longlong *)(&stack0x00000050 + lVar7);
    lVar10 = lVar8;
  }
  goto LAB_1404ab290;
LAB_1404aa8eb:
  *(longlong *)((longlong)alStackX_8 + lVar7) = lVar8;
  uVar24 = CONCAT71(uVar30,1);
  lVar18 = CONCAT71(uVar37,1);
  cVar34 = '\x01';
  cVar31 = '\x01';
  cVar20 = '\x01';
  uVar13 = (undefined7)((ulonglong)lVar8 >> 8);
  *(ulonglong *)(&stack0xfffffffffffffff0 + lVar7) = CONCAT71(uVar13,1);
  *(ulonglong *)(&stack0xfffffffffffffff8 + lVar7) = CONCAT71(uVar13,1);
  *(ulonglong *)((longlong)alStackX_8 + lVar7 + -8) = CONCAT71(uVar13,1);
  *(ulonglong *)((longlong)alStackX_8 + lVar7 + 8) = CONCAT71(uVar13,1);
  *(ulonglong *)((longlong)alStackX_8 + lVar7 + 0x10) = CONCAT71(uVar13,1);
  *(ulonglong *)((longlong)alStackX_8 + lVar7 + 0x18) = CONCAT71(uVar13,1);
  lVar17 = *(longlong *)(&stack0x00000060 + lVar7);
  cVar23 = '\x01';
  lVar10 = *(longlong *)(&stack0x00000068 + lVar7);
LAB_1404aac28:
  if ((lVar17 != 0) && (*(longlong *)(&stack0x000003d0 + lVar7) != 0)) {
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aac50;
    FUN_1408192a0(lVar17,*(longlong *)(&stack0x000003d0 + lVar7) * 0xc,4);
  }
LAB_1404aac50:
  if ((*(longlong *)(&stack0x000000b0 + lVar7) != 0) &&
     (*(longlong *)(&stack0x000003e0 + lVar7) != 0)) {
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aac89;
    FUN_1408192a0(*(undefined8 *)(&stack0x000000b0 + lVar7),
                  *(longlong *)(&stack0x000003e0 + lVar7) * 0xc,4);
  }
  if ((*(longlong *)(&stack0x000000b8 + lVar7) != 0) && (cVar23 != '\0')) {
    lVar12 = *(longlong *)(&stack0x00000140 + lVar7);
    if (lVar12 != 0) {
      lVar8 = 0;
      do {
        lVar17 = *(longlong *)(*(longlong *)(&stack0x000000b8 + lVar7) + 0x10 + lVar8);
        if (lVar17 != 0) {
          uVar9 = *(undefined8 *)(*(longlong *)(&stack0x000000b8 + lVar7) + 0x18 + lVar8);
          *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aacef;
          FUN_1408192a0(uVar9,lVar17 << 4,8);
        }
        lVar8 = lVar8 + 0x28;
      } while (lVar12 * 0x28 != lVar8);
    }
    if (*(longlong *)(&stack0x000003d8 + lVar7) != 0) {
      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aad22;
      FUN_1408192a0(*(undefined8 *)(&stack0x000000b8 + lVar7),
                    *(longlong *)(&stack0x000003d8 + lVar7) * 0x28,8);
    }
  }
  if (((*(longlong *)(&stack0x00000078 + lVar7) != 0) && ((char)uVar24 != '\0')) &&
     (*(longlong *)(&stack0x000003e8 + lVar7) != 0)) {
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aad5c;
    FUN_1408192a0(*(undefined8 *)(&stack0x00000078 + lVar7),
                  *(longlong *)(&stack0x000003e8 + lVar7) << 5,4);
  }
  uVar9 = *(undefined8 *)(&stack0xfffffffffffffff0 + lVar7);
  if (((*(longlong *)(&stack0x00000080 + lVar7) != 0) && ((char)lVar18 != '\0')) &&
     (*(longlong *)(&stack0x000003f0 + lVar7) != 0)) {
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aad9b;
    FUN_1408192a0(*(undefined8 *)(&stack0x00000080 + lVar7),
                  *(longlong *)(&stack0x000003f0 + lVar7) << 3,8);
  }
  if (((*(longlong *)(&stack0x00000088 + lVar7) != 0) && (cVar34 != '\0')) &&
     (*(longlong *)(&stack0x000003f8 + lVar7) != 0)) {
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aadd5;
    FUN_1408192a0(*(undefined8 *)(&stack0x00000088 + lVar7),
                  *(longlong *)(&stack0x000003f8 + lVar7) << 3,8);
  }
  uVar22 = *(undefined8 *)((longlong)alStackX_8 + lVar7 + 0x10);
  if (((*(longlong *)(&stack0x00000090 + lVar7) != 0) && (cVar31 != '\0')) &&
     (*(longlong *)(&stack0x00000400 + lVar7) != 0)) {
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aae14;
    FUN_1408192a0(*(undefined8 *)(&stack0x00000090 + lVar7),
                  *(longlong *)(&stack0x00000400 + lVar7) << 4,8);
  }
  if (((*(longlong *)(&stack0x00000098 + lVar7) != 0) && (cVar20 != '\0')) &&
     (*(longlong *)(&stack0x00000408 + lVar7) != 0)) {
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aae52;
    FUN_1408192a0(*(undefined8 *)(&stack0x00000098 + lVar7),
                  *(longlong *)(&stack0x00000408 + lVar7) * 0x18,8);
  }
  if (((*(longlong *)(&stack0x000000a0 + lVar7) != 0) && ((char)uVar9 != '\0')) &&
     (*(longlong *)(&stack0x00000410 + lVar7) != 0)) {
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aae90;
    FUN_1408192a0(*(undefined8 *)(&stack0x000000a0 + lVar7),
                  *(longlong *)(&stack0x00000410 + lVar7) * 0x28,8);
  }
  uVar9 = *(undefined8 *)((longlong)alStackX_8 + lVar7 + -8);
  if (((*(longlong *)(&stack0x000000a8 + lVar7) != 0) &&
      ((char)*(undefined8 *)(&stack0xfffffffffffffff8 + lVar7) != '\0')) &&
     (*(longlong *)(&stack0x00000418 + lVar7) != 0)) {
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aaed3;
    FUN_1408192a0(*(undefined8 *)(&stack0x000000a8 + lVar7),
                  *(longlong *)(&stack0x00000418 + lVar7) << 4,8);
  }
  uVar29 = *(undefined8 *)((longlong)alStackX_8 + lVar7 + 8);
  if ((((char)uVar9 != '\0') && (*(longlong *)(&stack0x000000e8 + lVar7) != 0)) &&
     (*(longlong *)(&stack0x000007e0 + lVar7) != 0)) {
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aaf06;
    FUN_1408192a0(*(longlong *)(&stack0x000000e8 + lVar7),
                  *(longlong *)(&stack0x000007e0 + lVar7) << 4,8);
  }
  lVar12 = *(longlong *)(&stack0x00000050 + lVar7);
  plVar25 = *(longlong **)(&stack0x000000c0 + lVar7);
  if ((((char)uVar29 != '\0') && (lVar10 != 0)) && (*(longlong *)(&stack0x000007e8 + lVar7) != 0)) {
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aaf43;
    FUN_1408192a0(lVar10,*(longlong *)(&stack0x000007e8 + lVar7) * 0x28,8);
  }
  uVar9 = *(undefined8 *)((longlong)alStackX_8 + lVar7 + 0x18);
  if ((((char)uVar22 != '\0') && (*(longlong *)(&stack0x00000070 + lVar7) != 0)) &&
     (*(longlong *)(&stack0x000007f0 + lVar7) != 0)) {
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aaf82;
    FUN_1408192a0(*(undefined8 *)(&stack0x00000070 + lVar7),
                  *(longlong *)(&stack0x000007f0 + lVar7) * 0x1c,4);
  }
  if (((char)uVar9 != '\0') && ((&stack0x00000930)[lVar7] != '\x02')) {
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404aaf9e;
    FUN_14045b020(&stack0x000008f8 + lVar7);
  }
  uVar15 = 2;
LAB_1404aafa0:
  *(char *)(lVar12 + 0x80) = *(char *)(lVar12 + 0x80) + '\x01';
  *(undefined8 *)(&stack0x000008f8 + lVar7) = *(undefined8 *)((longlong)alStackX_8 + lVar7);
  *(undefined8 *)(&stack0x00000900 + lVar7) = *(undefined8 *)(&stack0x00000c30 + lVar7);
  *(undefined8 *)(&stack0x00000908 + lVar7) = *(undefined8 *)(&stack0x00000c38 + lVar7);
  *(undefined8 *)(&stack0x00000910 + lVar7) = *(undefined8 *)(&stack0x000007c0 + lVar7);
  *(undefined8 *)(&stack0x00000918 + lVar7) = *(undefined8 *)(&stack0x000007c8 + lVar7);
  *(undefined8 *)(&stack0x00000920 + lVar7) = *(undefined8 *)(&stack0x000007d0 + lVar7);
  *(undefined8 *)(&stack0x00000928 + lVar7) = *(undefined8 *)(&stack0x000000f0 + lVar7);
  *(undefined8 *)(&stack0x00000930 + lVar7) = *(undefined8 *)(&stack0x000000f8 + lVar7);
  *(undefined8 *)(&stack0x00000938 + lVar7) = *(undefined8 *)(&stack0x00000100 + lVar7);
  *(undefined8 *)(&stack0x00000940 + lVar7) = *(undefined8 *)(&stack0x000007a0 + lVar7);
  *(undefined8 *)(&stack0x00000948 + lVar7) = *(undefined8 *)(&stack0x000007a8 + lVar7);
  *(undefined8 *)(&stack0x00000950 + lVar7) = *(undefined8 *)(&stack0x000007b0 + lVar7);
  *(undefined8 *)(&stack0x00000958 + lVar7) = *(undefined8 *)(&stack0x000008e0 + lVar7);
  *(undefined8 *)(&stack0x00000960 + lVar7) = *(undefined8 *)(&stack0x000008e8 + lVar7);
  *(undefined8 *)(&stack0x00000968 + lVar7) = *(undefined8 *)(&stack0x000008f0 + lVar7);
  *(undefined8 *)(&stack0x00000980 + lVar7) = *(undefined8 *)(&stack0x000008d0 + lVar7);
  *(undefined8 *)(&stack0x00000970 + lVar7) = *(undefined8 *)(&stack0x000008c0 + lVar7);
  *(undefined8 *)(&stack0x00000978 + lVar7) = *(undefined8 *)(&stack0x000008c8 + lVar7);
  *(undefined8 *)(&stack0x00000998 + lVar7) = *(undefined8 *)(&stack0x000008b0 + lVar7);
  *(undefined8 *)(&stack0x00000988 + lVar7) = *(undefined8 *)(&stack0x000008a0 + lVar7);
  *(undefined8 *)(&stack0x00000990 + lVar7) = *(undefined8 *)(&stack0x000008a8 + lVar7);
  *(undefined8 *)(&stack0x000009b0 + lVar7) = *(undefined8 *)(&stack0x00000890 + lVar7);
  *(undefined8 *)(&stack0x000009a0 + lVar7) = *(undefined8 *)(&stack0x00000880 + lVar7);
  *(undefined8 *)(&stack0x000009a8 + lVar7) = *(undefined8 *)(&stack0x00000888 + lVar7);
  *(undefined8 *)(&stack0x000009c8 + lVar7) = *(undefined8 *)(&stack0x00000870 + lVar7);
  *(undefined8 *)(&stack0x000009b8 + lVar7) = *(undefined8 *)(&stack0x00000860 + lVar7);
  *(undefined8 *)(&stack0x000009c0 + lVar7) = *(undefined8 *)(&stack0x00000868 + lVar7);
  *(undefined8 *)(&stack0x000009e0 + lVar7) = *(undefined8 *)(&stack0x00000850 + lVar7);
  *(undefined8 *)(&stack0x000009d0 + lVar7) = *(undefined8 *)(&stack0x00000840 + lVar7);
  *(undefined8 *)(&stack0x000009d8 + lVar7) = *(undefined8 *)(&stack0x00000848 + lVar7);
  *(undefined8 *)(&stack0x000009f8 + lVar7) = *(undefined8 *)(&stack0x00000830 + lVar7);
  *(undefined8 *)(&stack0x000009e8 + lVar7) = *(undefined8 *)(&stack0x00000820 + lVar7);
  *(undefined8 *)(&stack0x000009f0 + lVar7) = *(undefined8 *)(&stack0x00000828 + lVar7);
  *(undefined8 *)(&stack0x00000a10 + lVar7) = *(undefined8 *)(&stack0x00000810 + lVar7);
  *(undefined8 *)(&stack0x00000a00 + lVar7) = *(undefined8 *)(&stack0x00000800 + lVar7);
  *(undefined8 *)(&stack0x00000a08 + lVar7) = *(undefined8 *)(&stack0x00000808 + lVar7);
  *(undefined8 *)(&stack0x00000a18 + lVar7) = *(undefined8 *)(&stack0x000007f8 + lVar7);
  *(undefined8 *)(&stack0x00000a20 + lVar7) = *(undefined8 *)(&stack0x000000b0 + lVar7);
  *(longlong *)(&stack0x00000a28 + lVar7) = lVar10;
  *(undefined8 *)(&stack0x00000a30 + lVar7) = uVar24;
  *(longlong *)(&stack0x00000a38 + lVar7) = lVar18;
  *(undefined8 *)(&stack0x00000a40 + lVar7) = uVar9;
  *(undefined8 *)(&stack0x00000a78 + lVar7) = *(undefined8 *)(&stack0x00000790 + lVar7);
  *(undefined8 *)(&stack0x00000a68 + lVar7) = *(undefined8 *)(&stack0x00000780 + lVar7);
  *(undefined8 *)(&stack0x00000a70 + lVar7) = *(undefined8 *)(&stack0x00000788 + lVar7);
  *(undefined8 *)(&stack0x00000a58 + lVar7) = *(undefined8 *)(&stack0x00000770 + lVar7);
  *(undefined8 *)(&stack0x00000a60 + lVar7) = *(undefined8 *)(&stack0x00000778 + lVar7);
  *(undefined8 *)(&stack0x00000a48 + lVar7) = *(undefined8 *)(&stack0x00000760 + lVar7);
  *(undefined8 *)(&stack0x00000a50 + lVar7) = *(undefined8 *)(&stack0x00000768 + lVar7);
  (&stack0x00000a80)[lVar7] = uVar15;
  *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab1c6;
  memcpy(&stack0x00000a81 + lVar7,&stack0x00000e00 + lVar7,0x1af);
  *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab1ce;
  lVar8 = FUN_140441340(lVar12);
  *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab1ec;
  memcpy(&stack0x00000420 + lVar7,&stack0x000008f8 + lVar7,0x338);
  *(longlong *)(&stack0x00000758 + lVar7) = lVar8;
  cVar20 = (&stack0x000005a8)[lVar7];
  if (cVar20 == '\x02') {
    lVar10 = *(longlong *)(&stack0x00000420 + lVar7);
    cVar20 = '\x02';
    if (lVar8 != 0) {
      *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab21c;
      FUN_14045bac0(lVar8 + 0x10);
      goto LAB_1404ab21c;
    }
  }
  else if (lVar8 == 0) {
    lVar10 = *(longlong *)(&stack0x00000420 + lVar7);
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab27a;
    memcpy(&stack0x00000fb8 + lVar7,&stack0x00000428 + lVar7,0x180);
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab290;
    memcpy(&stack0x00001139 + lVar7,&stack0x000005a9 + lVar7,0x1af);
  }
  else {
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab246;
    FUN_14045ac60(&stack0x00000420 + lVar7);
    cVar20 = '\x02';
    lVar10 = lVar8;
  }
LAB_1404ab290:
  if (cVar20 == '\x02') {
LAB_1404ab2d1:
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab2dc;
    lVar12 = FUN_1401d6db0(lVar10,lVar12);
LAB_1404ab2dc:
    *plVar25 = lVar12;
    *(undefined1 *)(plVar25 + 0x31) = 2;
  }
  else {
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab2ac;
    memcpy(plVar25 + 1,&stack0x00000fb8 + lVar7,0x180);
    *(undefined8 *)((longlong)&uStack_48 + lVar7) = 0x1404ab2c6;
    memcpy((void *)((longlong)plVar25 + 0x189),&stack0x00001139 + lVar7,0x1af);
    *plVar25 = lVar10;
    *(char *)(plVar25 + 0x31) = cVar20;
  }
  return plVar25;
}

