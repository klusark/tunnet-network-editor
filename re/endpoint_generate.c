
void FUN_1402f9a40(undefined8 *param_1,longlong param_2,char *param_3,ulonglong param_4)

{
  longlong *plVar1;
  char *pcVar2;
  char cVar3;
  byte bVar4;
  char cVar5;
  undefined *puVar6;
  code *pcVar7;
  bool bVar8;
  bool bVar9;
  undefined5 uVar10;
  undefined5 uVar11;
  undefined5 uVar12;
  undefined5 uVar13;
  undefined8 **ppuVar14;
  undefined8 **ppuVar15;
  byte bVar16;
  char cVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  longlong *plVar21;
  undefined4 *puVar22;
  undefined8 *puVar23;
  undefined8 *puVar24;
  char (*pacVar25) [8];
  uint uVar26;
  uint uVar27;
  uint uVar28;
  undefined8 uVar29;
  longlong lVar30;
  uint uVar31;
  ulonglong uVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  undefined4 local_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  char cStack_10b;
  char cStack_10a;
  byte bStack_109;
  byte bStack_108;
  char cStack_107;
  undefined1 uStack_106;
  undefined1 uStack_105;
  undefined1 uStack_104;
  undefined1 uStack_103;
  undefined1 uStack_102;
  undefined1 uStack_101;
  longlong *local_100;
  undefined8 local_f8;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 **local_d8;
  undefined8 local_d0;
  ulonglong local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 **local_a8;
  ulonglong local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  longlong local_80;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined8 local_68;
  ulonglong local_58;
  undefined8 *local_50;
  undefined1 *local_48;
  
  local_c0 = param_4;
  local_80 = param_2;
  plVar21 = (longlong *)FUN_14204d800();
  cVar17 = *param_3;
  bVar16 = param_3[1];
  local_58 = (ulonglong)bVar16;
  cVar3 = param_3[2];
  bVar4 = param_3[3];
  local_a0 = (ulonglong)bVar4;
  local_100 = plVar21;
  local_120 = (char (*) [8])thunk_FUN_142351260(0xc,1);
  if (local_120 == (char (*) [8])0x0) {
    FUN_14239ef70(0xc,1);
    goto LAB_1402fc0b2;
  }
  uVar32 = (ulonglong)
           ((byte)((byte)(0x302010000 >> (bVar4 * '\b' & 0x3f)) |
                   (byte)(0xc08040000 >> (cVar3 * '\b' & 0x3fU)) |
                  (byte)(0x3020100000 >> (bVar16 * '\b' & 0x3f)) |
                  (byte)(0xc080400000 >> (cVar17 * '\b' & 0x3fU))) % 0x16);
  puVar6 = (&PTR_DAT_142424270)[uVar32 * 2];
  uVar29 = *(undefined8 *)(&DAT_142424278 + uVar32 * 0x10);
  builtin_strncpy(local_120[1],"cket",4);
  *local_120 = (char  [8])0x617020796d6d7544;
  uVar33 = *(undefined4 *)param_3;
  cVar5 = param_3[4];
  uVar13 = *(undefined5 *)param_3;
  uVar12 = *(undefined5 *)param_3;
  uVar11 = *(undefined5 *)param_3;
  uVar10 = *(undefined5 *)param_3;
  cStack_107 = '\0';
  cStack_10b = '\x01';
  cStack_10a = '\x01';
  bStack_109 = 1;
  bStack_108 = 1;
  uStack_106 = 0;
  uStack_105 = 0;
  local_130 = 0;
  uStack_128 = (undefined8 **)&DAT_0000000c;
  uStack_104 = 0;
  uVar28 = (uint)local_c0;
  if (cVar17 != '\x04') {
    if (cVar17 != '\x02') {
      if (cVar17 != '\x01') goto switchD_1402fa310_default;
      uVar31 = (uint)local_58;
      iVar20 = (int)local_a0;
      local_140 = SUB84(puVar6,0);
      uStack_13c = (undefined4)((ulonglong)puVar6 >> 0x20);
      uStack_138 = (undefined4)uVar29;
      uStack_134 = (undefined4)((ulonglong)uVar29 >> 0x20);
      switch(local_58) {
      case 1:
        if (cVar3 != '\x01') goto code_r0x0001402fa2fa;
        if ((char)local_a0 != '\x01') goto switchD_1402fa310_default;
        if ((local_c0 & 1) != 0) goto LAB_1402faf50;
        uVar31 = (int)(((uint)(local_c0 >> 0x1f) & 1) + uVar28) >> 1;
        if ((uVar31 & 0xf) == 0) {
          uVar31 = uVar28 + 0x1f;
          if (-1 < (int)uVar28) {
            uVar31 = uVar28;
          }
          bVar16 = (char)((char)((int)uVar31 >> 5) + (char)(((int)uVar31 >> 5) / 3) * -3 + '\x01') %
                   '\x04';
          iVar20 = 0x1010001;
          if (bVar16 < 4) {
            iVar20 = (char)bVar16 * 0x100 + 0x1010101;
          }
          cStack_10b = (char)iVar20;
          cStack_10a = (char)((uint)iVar20 >> 8);
          bStack_109 = (byte)((uint)iVar20 >> 0x10);
          bStack_108 = (byte)((uint)iVar20 >> 0x18);
          cStack_107 = '\0';
          puVar23 = (undefined8 *)FUN_140293650(0x30);
          *puVar23 = "Mainframe update";
          puVar23[1] = 0x10;
          puVar23[2] = "Please forward to your endpoints";
          puVar23[3] = 0x20;
          puVar23[4] = "Status report";
          puVar23[5] = 0xd;
          puVar24 = (undefined8 *)FUN_140673b40(puVar23,3,&local_100);
          if (puVar24 == (undefined8 *)0x0) {
            FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                          ,0x2b,&PTR_s_src_net_endpoint_rs_142424dc0);
            goto LAB_1402fc0b2;
          }
          FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
          FUN_1408192a0(local_120,0xc,1);
          uStack_128._0_4_ = SUB84(local_f8,0);
          uStack_128._4_4_ = (undefined4)((ulonglong)local_f8 >> 0x20);
          uStack_118._0_4_ = SUB84(local_e8,0);
          uStack_118._4_4_ = (undefined4)((ulonglong)local_e8 >> 0x20);
          *(undefined4 *)(param_1 + 6) = uVar33;
          *(uint *)((longlong)param_1 + 0x34) =
               CONCAT13(bStack_109,CONCAT12(cStack_10a,CONCAT11(cStack_10b,cVar5)));
          *(uint *)(param_1 + 7) =
               CONCAT13(uStack_105,CONCAT12(uStack_106,CONCAT11(cStack_107,bStack_108)));
          *(uint *)((longlong)param_1 + 0x3c) =
               CONCAT13(uStack_101,CONCAT12(uStack_102,CONCAT11(uStack_103,uStack_104)));
          *(undefined4 *)(param_1 + 4) = uStack_f0;
          *(undefined4 *)((longlong)param_1 + 0x24) = uStack_ec;
          *(undefined4 *)(param_1 + 5) = (undefined4)uStack_118;
          *(undefined4 *)((longlong)param_1 + 0x2c) = uStack_118._4_4_;
          *(undefined4 *)(param_1 + 2) = 0;
          *(undefined4 *)((longlong)param_1 + 0x14) = 0;
          *(undefined4 *)(param_1 + 3) = (undefined4)uStack_128;
          *(undefined4 *)((longlong)param_1 + 0x1c) = uStack_128._4_4_;
          *(undefined4 *)param_1 = local_140;
          *(undefined4 *)((longlong)param_1 + 4) = uStack_13c;
          *(undefined4 *)(param_1 + 1) = uStack_138;
          *(undefined4 *)((longlong)param_1 + 0xc) = uStack_134;
          uVar29 = 0x30;
          goto LAB_1402fb815;
        }
        puVar23 = (undefined8 *)FUN_140293650(0x40);
        *puVar23 = "Firmware update";
        puVar23[1] = 0xf;
        puVar23[2] = "Test";
        puVar23[3] = 4;
        puVar23[4] = "Contribute to science";
        puVar23[5] = 0x15;
        puVar23[6] = "[PATCH] Fix netcode";
        puVar23[7] = 0x13;
        uVar19 = uVar28 + 7;
        if (-1 < (int)uVar28) {
          uVar19 = uVar28;
        }
        uVar28 = ((int)uVar19 >> 3) % 4;
        uVar19 = uVar28 + 1 & 0xff;
        if (3 < uVar28) {
          uVar19 = 0;
        }
        local_b8 = (undefined8 **)CONCAT71(local_b8._1_7_,(char)uVar19);
        cVar17 = FUN_1406b60c0(&local_b8,&DAT_142423e77);
        uVar31 = (int)uVar31 % 4;
        iVar20 = uVar31 * 0x1000000 + 0x1000000;
        if (3 < uVar31) {
          iVar20 = 0;
        }
        iVar18 = 0x10000;
        if (cVar17 == '\0') {
          iVar18 = uVar19 << 0x10;
        }
        iVar20 = iVar18 + iVar20 + 0x101;
        cStack_10b = (char)iVar20;
        cStack_10a = (char)((uint)iVar20 >> 8);
        bStack_109 = (byte)((uint)iVar20 >> 0x10);
        bStack_108 = (byte)((uint)iVar20 >> 0x18);
        cStack_107 = '\0';
        cVar17 = FUN_1406b6550(&cStack_10b,param_3);
        if (cVar17 == '\0') {
          puVar24 = (undefined8 *)FUN_140673b40(puVar23,4,&local_100);
          if (puVar24 == (undefined8 *)0x0) {
            FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                          ,0x2b,&PTR_s_src_net_endpoint_rs_142424d68);
            goto LAB_1402fc0b2;
          }
          FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
          FUN_1408192a0(local_120,0xc,1);
          uStack_128 = local_f8;
          local_120 = (char (*) [8])CONCAT44(uStack_ec,uStack_f0);
          if ((8 < *(byte *)(local_80 + 0x1c4)) ||
             (((cStack_10b == '\x01' && (cStack_10a == '\x01')) && (bStack_109 == 1)))) {
            uStack_118._0_4_ = SUB84(local_e8,0);
            uStack_118._4_4_ = (undefined4)((ulonglong)local_e8 >> 0x20);
            *(undefined4 *)(param_1 + 6) = uVar33;
            *(uint *)((longlong)param_1 + 0x34) =
                 CONCAT13(bStack_109,CONCAT12(cStack_10a,CONCAT11(cStack_10b,cVar5)));
            *(uint *)(param_1 + 7) =
                 CONCAT13(uStack_105,CONCAT12(uStack_106,CONCAT11(cStack_107,bStack_108)));
            *(uint *)((longlong)param_1 + 0x3c) =
                 CONCAT13(uStack_101,CONCAT12(uStack_102,CONCAT11(uStack_103,uStack_104)));
            *(undefined4 *)(param_1 + 4) = uStack_f0;
            *(undefined4 *)((longlong)param_1 + 0x24) = uStack_ec;
            *(undefined4 *)(param_1 + 5) = (undefined4)uStack_118;
            *(undefined4 *)((longlong)param_1 + 0x2c) = uStack_118._4_4_;
            *(undefined4 *)(param_1 + 2) = 0;
            *(undefined4 *)((longlong)param_1 + 0x14) = 0;
            *(int *)(param_1 + 3) = (int)local_f8;
            *(undefined4 *)((longlong)param_1 + 0x1c) = local_f8._4_4_;
            *(undefined4 *)param_1 = local_140;
            *(undefined4 *)((longlong)param_1 + 4) = uStack_13c;
            *(undefined4 *)(param_1 + 1) = uStack_138;
            *(undefined4 *)((longlong)param_1 + 0xc) = uStack_134;
            uVar29 = 0x40;
            goto LAB_1402fb815;
          }
        }
        *(undefined1 *)((longlong)param_1 + 0x3a) = 2;
        FUN_1408192a0(puVar23,0x40,8);
        break;
      case 2:
        if (cVar3 != '\x01') goto code_r0x0001402fa2fa;
        if (iVar20 == 1) {
          if ((local_c0 & 1) != 0) goto LAB_1402faf50;
          uVar31 = (int)(((uint)(local_c0 >> 0x1f) & 1) + uVar28) >> 1;
          if ((uVar31 & 0xf) == 0) {
            uVar31 = uVar28 + 0x1f;
            if (-1 < (int)uVar28) {
              uVar31 = uVar28;
            }
            uVar28 = ((int)uVar31 >> 5) % 4;
            iVar20 = 0x3030001;
            if (uVar28 < 4) {
              iVar20 = uVar28 * 0x100 + 0x3030101;
            }
            cStack_10b = (char)iVar20;
            cStack_10a = (char)((uint)iVar20 >> 8);
            bStack_109 = (byte)((uint)iVar20 >> 0x10);
            bStack_108 = (byte)((uint)iVar20 >> 0x18);
            cStack_107 = '\0';
            puVar23 = (undefined8 *)FUN_140293650(0x20);
            *puVar23 = "TOP SECRET";
            puVar23[1] = 10;
            puVar23[2] = "CONFIDENTIAL";
            puVar23[3] = 0xc;
            uStack_105 = 1;
            puVar24 = (undefined8 *)FUN_140673b40(puVar23,2,&local_100);
            if (puVar24 == (undefined8 *)0x0) {
              FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                            ,0x2b,&PTR_s_src_net_endpoint_rs_142424920);
              goto LAB_1402fc0b2;
            }
            FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
          }
          else {
            puVar23 = (undefined8 *)FUN_140293650(0x20);
            *puVar23 = "Emergency Announcement";
            puVar23[1] = 0x16;
            uVar19 = uVar28 + 7;
            if (-1 < (int)uVar28) {
              uVar19 = uVar28;
            }
            puVar23[2] = "We Want You!";
            uVar28 = ((int)uVar19 >> 3) % 4;
            iVar20 = 0x201;
            if (uVar28 < 4) {
              iVar20 = uVar28 * 0x10000 + 0x10201;
            }
            uVar31 = (int)uVar31 % 4;
            bStack_108 = 0;
            if (uVar31 < 4) {
              bStack_108 = (byte)(uVar31 * 0x1000000 + 0x1000000 >> 0x18);
            }
            puVar23[3] = 0xc;
            bStack_108 = bStack_108 | (byte)((uint)iVar20 >> 0x18);
            cStack_10b = (char)iVar20;
            cStack_10a = (char)((uint)iVar20 >> 8);
            bStack_109 = (byte)((uint)iVar20 >> 0x10);
            cStack_107 = '\0';
            cVar17 = FUN_1406b6550(&cStack_10b,param_3);
            if (cVar17 != '\0') {
              *(undefined1 *)((longlong)param_1 + 0x3a) = 2;
              FUN_1408192a0(puVar23,0x20,8);
              break;
            }
            uStack_105 = 1;
            puVar24 = (undefined8 *)FUN_140673b40(puVar23,2,&local_100);
            if (puVar24 == (undefined8 *)0x0) {
              FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                            ,0x2b,&PTR_s_src_net_endpoint_rs_1424248f0);
              goto LAB_1402fc0b2;
            }
            FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
          }
          FUN_1408192a0(local_120,0xc,1);
          uStack_128._0_4_ = SUB84(local_f8,0);
          uStack_128._4_4_ = (undefined4)((ulonglong)local_f8 >> 0x20);
          uStack_118._0_4_ = SUB84(local_e8,0);
          uStack_118._4_4_ = (undefined4)((ulonglong)local_e8 >> 0x20);
          *(undefined4 *)(param_1 + 6) = uVar33;
          *(uint *)((longlong)param_1 + 0x34) =
               CONCAT13(bStack_109,CONCAT12(cStack_10a,CONCAT11(cStack_10b,cVar5)));
          *(uint *)(param_1 + 7) =
               CONCAT13(uStack_105,CONCAT12(uStack_106,CONCAT11(cStack_107,bStack_108)));
          *(uint *)((longlong)param_1 + 0x3c) =
               CONCAT13(uStack_101,CONCAT12(uStack_102,CONCAT11(uStack_103,uStack_104)));
          *(undefined4 *)(param_1 + 4) = uStack_f0;
          *(undefined4 *)((longlong)param_1 + 0x24) = uStack_ec;
          *(undefined4 *)(param_1 + 5) = (undefined4)uStack_118;
          *(undefined4 *)((longlong)param_1 + 0x2c) = uStack_118._4_4_;
          *(undefined4 *)(param_1 + 2) = 0;
          *(undefined4 *)((longlong)param_1 + 0x14) = 0;
          *(undefined4 *)(param_1 + 3) = (undefined4)uStack_128;
          *(undefined4 *)((longlong)param_1 + 0x1c) = uStack_128._4_4_;
          *(undefined4 *)param_1 = local_140;
          *(undefined4 *)((longlong)param_1 + 4) = uStack_13c;
          *(undefined4 *)(param_1 + 1) = uStack_138;
          *(undefined4 *)((longlong)param_1 + 0xc) = uStack_134;
          uVar29 = 0x20;
LAB_1402fb815:
          FUN_1408192a0(puVar23,uVar29,8);
          goto LAB_1402faf1d;
        }
        if (iVar20 == 2) goto LAB_1402fa1cb;
switchD_1402fa310_caseD_1:
        if ((char)local_a0 == '\x03') {
          if ((local_c0 & 1) == 0) {
            if ((((uint)(local_c0 >> 0x1f) & 1) + uVar28 >> 1 & 1) != 0) {
              uVar31 = uVar28 + 3;
              if (-1 < (int)uVar28) {
                uVar31 = uVar28;
              }
              uVar28 = ((int)uVar31 >> 2) % 4;
              iVar20 = 0x3010001;
              if (uVar28 < 4) {
                iVar20 = uVar28 * 0x100 + 0x3010101;
              }
              cStack_10b = (char)iVar20;
              cStack_10a = (char)((uint)iVar20 >> 8);
              bStack_109 = (byte)((uint)iVar20 >> 0x10);
              bStack_108 = (byte)((uint)iVar20 >> 0x18);
              cStack_107 = '\0';
              puVar23 = (undefined8 *)FUN_140293650(0x10);
              *puVar23 = &DAT_142424cc0;
              puVar23[1] = 0x18;
              puVar24 = (undefined8 *)FUN_140673b40(puVar23,1,&local_100);
              if (puVar24 == (undefined8 *)0x0) {
                FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                              ,0x2b,&PTR_s_src_net_endpoint_rs_142424cd8);
                goto LAB_1402fc0b2;
              }
              FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
              goto LAB_1402fb31a;
            }
            uVar28 = uVar31 << 8 | 0x1020001;
            cStack_10b = '\x01';
            bStack_109 = (byte)(uVar28 >> 0x10);
            bStack_108 = (byte)(uVar28 >> 0x18);
            cStack_107 = '\0';
            cStack_10a = (char)local_58;
            puVar23 = (undefined8 *)FUN_140293650(0x20);
            *puVar23 = "What\'s 6 * 7?";
            puVar23[1] = 0xd;
            puVar23[2] = "Do my homework";
            puVar23[3] = 0xe;
            puVar24 = (undefined8 *)FUN_140673b40(puVar23,2,&local_100);
            if (puVar24 == (undefined8 *)0x0) {
              FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                            ,0x2b,&PTR_s_src_net_endpoint_rs_142424d10);
LAB_1402fc0b2:
                    /* WARNING: Does not return */
              pcVar7 = (code *)invalidInstructionException();
              (*pcVar7)();
            }
            FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
LAB_1402fb651:
            FUN_1408192a0(local_120,0xc,1);
            local_120 = (char (*) [8])CONCAT44(uStack_ec,uStack_f0);
            uVar29 = 0x20;
            goto LAB_1402fb691;
          }
        }
        else {
          if ((iVar20 != 4) || (1 < local_58 - 3)) goto switchD_1402fa310_default;
          if ((local_c0 & 1) == 0) {
            uVar31 = uVar31 << 8;
            iVar20 = ((int)(((uint)(local_c0 >> 0x1f) & 1) + uVar28) >> 1) % 4;
            if (iVar20 == 0) {
              cStack_10b = '\x01';
              bStack_109 = (byte)((uVar31 | 0x4040001) >> 0x10);
              bStack_108 = (byte)((uVar31 | 0x4040001) >> 0x18);
              cStack_107 = '\0';
              cStack_10a = (char)local_58;
              puVar23 = (undefined8 *)FUN_140293650(0x10);
              *puVar23 = &DAT_142424438;
              puVar23[1] = 8;
              puVar24 = (undefined8 *)FUN_140673b40(puVar23,1,&local_100);
              if (puVar24 == (undefined8 *)0x0) {
                FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                              ,0x2b,&PTR_s_src_net_endpoint_rs_142424ca8);
                goto LAB_1402fc0b2;
              }
              FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
            }
            else if (iVar20 == 1) {
              cStack_10b = '\x01';
              bStack_109 = (byte)((uVar31 | 0x3020001) >> 0x10);
              bStack_108 = (byte)((uVar31 | 0x3020001) >> 0x18);
              cStack_107 = '\0';
              cStack_10a = (char)local_58;
              puVar23 = (undefined8 *)FUN_140293650(0x10);
              *puVar23 = "Track #2";
              puVar23[1] = 8;
              puVar24 = (undefined8 *)FUN_140673b40(puVar23,1,&local_100);
              if (puVar24 == (undefined8 *)0x0) {
                FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                              ,0x2b,&PTR_s_src_net_endpoint_rs_142424c90);
                goto LAB_1402fc0b2;
              }
              FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
            }
            else if (iVar20 == 2) {
              cStack_10b = '\x01';
              bStack_109 = (byte)((uVar31 | 0x2040001) >> 0x10);
              bStack_108 = (byte)((uVar31 | 0x2040001) >> 0x18);
              cStack_107 = '\0';
              cStack_10a = (char)local_58;
              puVar23 = (undefined8 *)FUN_140293650(0x10);
              *puVar23 = "Track #3";
              puVar23[1] = 8;
              puVar24 = (undefined8 *)FUN_140673b40(puVar23,1,&local_100);
              if (puVar24 == (undefined8 *)0x0) {
                FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                              ,0x2b,&PTR_s_src_net_endpoint_rs_142424c78);
                goto LAB_1402fc0b2;
              }
              FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
            }
            else {
              cStack_10b = '\x01';
              bStack_109 = (byte)((uVar31 | 0x4030001) >> 0x10);
              bStack_108 = (byte)((uVar31 | 0x4030001) >> 0x18);
              cStack_107 = '\0';
              cStack_10a = (char)local_58;
              puVar23 = (undefined8 *)FUN_140293650(0x10);
              *puVar23 = &DAT_1424244a8;
              puVar23[1] = 8;
              puVar24 = (undefined8 *)FUN_140673b40(puVar23,1,&local_100);
              if (puVar24 == (undefined8 *)0x0) {
                FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                              ,0x2b,&PTR_s_src_net_endpoint_rs_142424c60);
                goto LAB_1402fc0b2;
              }
              FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
            }
            FUN_1408192a0(local_120,0xc,1);
            uStack_118 = (undefined8 **)local_e8;
            uStack_128 = local_f8;
            local_120 = (char (*) [8])CONCAT44(uStack_ec,uStack_f0);
            FUN_1408192a0(puVar23,0x10,8);
            goto LAB_1402fb6a4;
          }
        }
LAB_1402faf50:
        *(undefined1 *)((longlong)param_1 + 0x3a) = 2;
        break;
      case 3:
        if (cVar3 != '\x01') goto code_r0x0001402fa2fa;
        if (iVar20 == 2) {
LAB_1402fa1cb:
          if ((local_c0 & 1) != 0) goto LAB_1402faf50;
          iVar20 = ((int)(((uint)(local_c0 >> 0x1f) & 1) + uVar28) >> 1) % 4;
          if (iVar20 != 0) {
            uVar31 = uVar31 << 8;
            if (iVar20 == 1) {
              cStack_10b = '\x01';
              bStack_109 = (byte)((uVar31 | 0x1030001) >> 0x10);
              bStack_108 = (byte)((uVar31 | 0x1030001) >> 0x18);
              cStack_107 = '\0';
              cStack_10a = (char)local_58;
              puVar23 = (undefined8 *)FUN_140293650(0x10);
              *puVar23 = "Search query";
              puVar23[1] = 0xc;
              puVar24 = (undefined8 *)FUN_140673b40(puVar23,1,&local_100);
              if (puVar24 == (undefined8 *)0x0) {
                FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                              ,0x2b,&PTR_s_src_net_endpoint_rs_142424888);
                goto LAB_1402fc0b2;
              }
              FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
              goto LAB_1402fb31a;
            }
            if (iVar20 != 2) {
              cStack_10b = '\x01';
              bStack_109 = (byte)((uVar31 | 0x2020001) >> 0x10);
              bStack_108 = (byte)((uVar31 | 0x2020001) >> 0x18);
              cStack_107 = '\0';
              cStack_10a = (char)local_58;
              local_78 = FUN_140673660(&local_100,1,4);
              local_98 = (undefined8 *)&local_78;
              uStack_90 = FUN_1423bf650;
              local_f8 = (undefined8 **)0x0;
              local_e8 = &PTR_s_I_need_kg_of_corn_1424247d8;
              local_e0 = 2;
              local_d8 = (undefined8 **)&local_98;
              local_d0 = 1;
              FUN_1423a0360(&local_b8,&local_f8);
              goto LAB_1402fb401;
            }
            cStack_10b = '\x01';
            bStack_109 = (byte)((uVar31 | 0x1020001) >> 0x10);
            bStack_108 = (byte)((uVar31 | 0x1020001) >> 0x18);
            cStack_107 = '\0';
            cStack_10a = (char)local_58;
            puVar23 = (undefined8 *)FUN_140293650(0x40);
            *puVar23 = "Where are the Architects?";
            puVar23[1] = 0x19;
            puVar23[2] = "Did anyone survive the Apocalypse?";
            puVar23[3] = 0x22;
            puVar23[4] = "Who are the Architects?";
            puVar23[5] = 0x17;
            puVar23[6] = "Where is everyone?";
            puVar23[7] = 0x12;
            puVar24 = (undefined8 *)FUN_140673b40(puVar23,4,&local_100);
            if (puVar24 == (undefined8 *)0x0) {
              FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                            ,0x2b,&PTR_s_src_net_endpoint_rs_142424860);
              goto LAB_1402fc0b2;
            }
            FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
            FUN_1408192a0(local_120,0xc,1);
            local_120 = (char (*) [8])CONCAT44(uStack_ec,uStack_f0);
            uVar29 = 0x40;
            goto LAB_1402fb691;
          }
          cStack_107 = '\0';
          cStack_10b = '\x01';
          cStack_10a = '\x03';
          bStack_109 = 1;
          bStack_108 = 1;
          puVar23 = (undefined8 *)FUN_140293650(0x10);
          *puVar23 = "Search request";
          puVar23[1] = 0xe;
          puVar24 = (undefined8 *)FUN_140673b40(puVar23,1,&local_100);
          if (puVar24 == (undefined8 *)0x0) {
            FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                          ,0x2b,&PTR_s_src_net_endpoint_rs_1424248b0);
            goto LAB_1402fc0b2;
          }
          FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
LAB_1402fb31a:
          FUN_1408192a0(local_120,0xc,1);
          local_120 = (char (*) [8])CONCAT44(uStack_ec,uStack_f0);
          uVar29 = 0x10;
          goto LAB_1402fb691;
        }
        if (iVar20 != 1) goto switchD_1402fa310_caseD_1;
        if ((local_c0 & 1) != 0) goto LAB_1402faf50;
        uVar31 = uVar28 + 3;
        if (-1 < (int)uVar28) {
          uVar31 = uVar28;
        }
        if ((((uint)(local_c0 >> 0x1f) & 1) + uVar28 >> 1 & 1) == 0) {
          uVar27 = uVar28 + 0xf;
          uVar19 = uVar28 + 0x3f;
          if (-1 < (int)uVar28) {
            uVar27 = uVar28;
            uVar19 = uVar28;
          }
          uVar19 = ((int)uVar19 >> 6) % 4;
          uVar31 = ((int)uVar31 >> 2) % 4;
          uVar28 = 1;
          if (uVar19 < 4) {
            uVar28 = uVar19 * 0x100 + 0x101;
          }
          uVar26 = ((int)uVar27 >> 4) % 4;
          uVar27 = uVar26 * 0x10000 + 0x10000;
          if (3 < uVar26) {
            uVar27 = 0;
          }
          uVar26 = uVar31 * 0x1000000 + 0x1000000;
          if (3 < uVar31) {
            uVar26 = 0;
          }
          bStack_108 = (byte)((uVar27 | uVar28) >> 0x18) | (byte)(uVar26 >> 0x18);
          cStack_10b = (char)uVar28;
          cStack_10a = (char)(uVar28 >> 8);
          bStack_109 = (byte)((uVar27 | uVar28) >> 0x10);
          cStack_107 = '\0';
          if (uVar19 != 2) {
            puVar23 = (undefined8 *)FUN_140293650(0x10);
            *puVar23 = &DAT_1424247a0;
            puVar23[1] = 8;
            puVar24 = (undefined8 *)FUN_140673b40(puVar23,1,&local_100);
            if (puVar24 == (undefined8 *)0x0) {
              FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                            ,0x2b,&PTR_s_src_net_endpoint_rs_1424247a8);
              goto LAB_1402fc0b2;
            }
            FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
            goto LAB_1402fa9de;
          }
          goto LAB_1402fa199;
        }
        pacVar25 = (char (*) [8])FUN_140293650(0x20);
        *pacVar25 = (char  [8])"Call To Prayer";
        pacVar25[1] = (char  [8])0xe;
        uVar19 = uVar28 + 0xf;
        if (-1 < (int)uVar28) {
          uVar19 = uVar28;
        }
        pacVar25[2] = (char  [8])"We haven\'t seen you at church today";
        uVar28 = ((int)uVar19 >> 4) % 4;
        iVar20 = 0x301;
        if (uVar28 < 4) {
          iVar20 = uVar28 * 0x10000 + 0x10301;
        }
        uVar28 = ((int)uVar31 >> 2) % 4;
        bStack_108 = 0;
        if (uVar28 < 4) {
          bStack_108 = (byte)(uVar28 * 0x1000000 + 0x1000000 >> 0x18);
        }
        pacVar25[3] = (char  [8])0x23;
        bStack_108 = bStack_108 | (byte)((uint)iVar20 >> 0x18);
        cStack_10b = (char)iVar20;
        cStack_10a = (char)((uint)iVar20 >> 8);
        bStack_109 = (byte)((uint)iVar20 >> 0x10);
        cStack_107 = '\0';
        cVar17 = FUN_1406b6550(&cStack_10b,param_3);
        if (cVar17 != '\0') {
          *(undefined1 *)((longlong)param_1 + 0x3a) = 2;
          FUN_1408192a0(pacVar25,0x20,8);
          break;
        }
        puVar23 = (undefined8 *)FUN_140673b40(pacVar25,2,&local_100);
        if (puVar23 == (undefined8 *)0x0) {
          FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                        ,0x2b,&PTR_s_src_net_endpoint_rs_142424788);
          goto LAB_1402fc0b2;
        }
        FUN_140275e80(&local_f8,*puVar23,puVar23[1]);
        FUN_1408192a0(local_120,0xc,1);
        ppuVar15 = (undefined8 **)local_e8;
        ppuVar14 = local_f8;
        local_120 = (char (*) [8])CONCAT44(uStack_ec,uStack_f0);
        uStack_106 = 1;
        lVar30 = 2;
        if ((ulonglong)bStack_109 - 1 < 4) {
          lVar30 = *(longlong *)(&DAT_1424257d0 + (ulonglong)bStack_109 * 8);
        }
        switch(bStack_108) {
        case 1:
          uVar32 = 3;
          break;
        case 2:
          bVar16 = FUN_1406b60c0(&bStack_109,&DAT_14241f6f0);
          uVar32 = (ulonglong)bVar16 ^ 3;
          break;
        case 3:
          uVar32 = 2;
          break;
        case 4:
          uVar32 = 1;
          break;
        default:
          uVar32 = 0;
        }
        param_1[6] = CONCAT17(bStack_109,CONCAT16(cStack_10a,CONCAT15(cStack_10b,uVar12)));
        param_1[7] = CONCAT17(uStack_101,
                              CONCAT16(uStack_102,
                                       CONCAT15(uStack_103,
                                                CONCAT14(uStack_104,
                                                         CONCAT13(uStack_105,
                                                                  CONCAT12(uStack_106,
                                                                           CONCAT11(cStack_107,
                                                                                    bStack_108))))))
                             );
        param_1[4] = local_120;
        param_1[5] = ppuVar15;
        *(undefined4 *)param_1 = local_140;
        *(undefined4 *)((longlong)param_1 + 4) = uStack_13c;
        *(undefined4 *)(param_1 + 1) = uStack_138;
        *(undefined4 *)((longlong)param_1 + 0xc) = uStack_134;
        param_1[2] = uVar32 + lVar30;
        param_1[3] = ppuVar14;
        uStack_128 = (undefined8 **)&DAT_00000020;
        uVar32 = 8;
        goto LAB_1402faf18;
      case 4:
        if ((cVar3 != '\x01') || ((char)local_a0 != '\x01')) goto code_r0x0001402fa2fa;
        if ((local_c0 & 3) == 0) {
          cStack_107 = '\0';
          cStack_10b = '\x03';
          cStack_10a = '\x02';
          bStack_109 = 3;
          bStack_108 = 1;
          puVar23 = (undefined8 *)FUN_140293650(0x10);
          *puVar23 = &DAT_142424733;
          puVar23[1] = 5;
          uStack_105 = 1;
          puVar24 = (undefined8 *)FUN_140673b40(puVar23,1,&local_100);
          if (puVar24 == (undefined8 *)0x0) {
            FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                          ,0x2b,&PTR_s_src_net_endpoint_rs_142424738);
            goto LAB_1402fc0b2;
          }
          FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
LAB_1402fa9de:
          FUN_1408192a0(local_120,0xc,1);
          uStack_128._0_4_ = SUB84(local_f8,0);
          uStack_128._4_4_ = (undefined4)((ulonglong)local_f8 >> 0x20);
          uStack_118._0_4_ = SUB84(local_e8,0);
          uStack_118._4_4_ = (undefined4)((ulonglong)local_e8 >> 0x20);
          *(undefined4 *)(param_1 + 6) = uVar33;
          *(uint *)((longlong)param_1 + 0x34) =
               CONCAT13(bStack_109,CONCAT12(cStack_10a,CONCAT11(cStack_10b,cVar5)));
          *(uint *)(param_1 + 7) =
               CONCAT13(uStack_105,CONCAT12(uStack_106,CONCAT11(cStack_107,bStack_108)));
          *(uint *)((longlong)param_1 + 0x3c) =
               CONCAT13(uStack_101,CONCAT12(uStack_102,CONCAT11(uStack_103,uStack_104)));
          *(undefined4 *)(param_1 + 4) = uStack_f0;
          *(undefined4 *)((longlong)param_1 + 0x24) = uStack_ec;
          *(undefined4 *)(param_1 + 5) = (undefined4)uStack_118;
          *(undefined4 *)((longlong)param_1 + 0x2c) = uStack_118._4_4_;
          *(undefined4 *)(param_1 + 2) = 0;
          *(undefined4 *)((longlong)param_1 + 0x14) = 0;
          *(undefined4 *)(param_1 + 3) = (undefined4)uStack_128;
          *(undefined4 *)((longlong)param_1 + 0x1c) = uStack_128._4_4_;
          *(undefined4 *)param_1 = local_140;
          *(undefined4 *)((longlong)param_1 + 4) = uStack_13c;
          *(undefined4 *)(param_1 + 1) = uStack_138;
          *(undefined4 *)((longlong)param_1 + 0xc) = uStack_134;
          uVar29 = 0x10;
          goto LAB_1402fb815;
        }
LAB_1402fa199:
        cStack_107 = '\0';
        *(undefined1 *)((longlong)param_1 + 0x3a) = 2;
        break;
      default:
code_r0x0001402fa2fa:
        switch(cVar3) {
        case '\x01':
          goto switchD_1402fa310_caseD_1;
        case '\x02':
          if (((char)local_a0 != '\x03') || (2 < local_58 - 2)) goto switchD_1402fa310_default;
          if ((local_c0 & 1) != 0) goto LAB_1402faf50;
          if ((((uint)(local_c0 >> 0x1f) & 1) + uVar28 >> 1 & 3) == 0) {
            uVar28 = uVar31 << 8 | 0x2040001;
            cStack_10b = '\x01';
            bStack_109 = (byte)(uVar28 >> 0x10);
            bStack_108 = (byte)(uVar28 >> 0x18);
            cStack_107 = '\0';
            cStack_10a = (char)local_58;
            puVar23 = (undefined8 *)FUN_140293650(0x20);
            *puVar23 = "One battery, please";
            puVar23[1] = 0x13;
            puVar23[2] = "One bottle of corn oil, please";
            puVar23[3] = 0x1e;
            puVar24 = (undefined8 *)FUN_140673b40(puVar23,2,&local_100);
            if (puVar24 == (undefined8 *)0x0) {
              FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                            ,0x2b,&PTR_s_src_net_endpoint_rs_142424c48);
              goto LAB_1402fc0b2;
            }
            FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
            goto LAB_1402fb651;
          }
          uVar28 = uVar31 << 8 | 0x1020001;
          cStack_10b = '\x01';
          bStack_109 = (byte)(uVar28 >> 0x10);
          bStack_108 = (byte)(uVar28 >> 0x18);
          cStack_107 = '\0';
          cStack_10a = (char)local_58;
          puVar23 = (undefined8 *)FUN_140293650(0xf0);
          *puVar23 = "hello";
          puVar23[1] = 5;
          puVar23[2] = "how do i use the computer?";
          puVar23[3] = 0x1a;
          puVar23[4] = "family pictures";
          puVar23[5] = 0xf;
          puVar23[6] = "I have lost 6 pounds since June";
          puVar23[7] = 0x1f;
          puVar23[8] = "Good morning";
          puVar23[9] = 0xc;
          puVar23[10] = "Bless you!!!";
          puVar23[0xb] = 0xc;
          puVar23[0xc] = "3615 TUNNET";
          puVar23[0xd] = 0xb;
          puVar23[0xe] = "do you get these messages?";
          puVar23[0xf] = 0x1a;
          puVar23[0x10] = "need corn oil";
          puVar23[0x11] = 0xd;
          puVar23[0x12] = ":)";
          puVar23[0x13] = 2;
          puVar23[0x14] = "how to recharge battery?";
          puVar23[0x15] = 0x18;
          puVar23[0x16] = "happy birthday?";
          puVar23[0x17] = 0xf;
          puVar23[0x18] = "teddy bear pattern";
          puVar23[0x19] = 0x12;
          puVar23[0x1a] = "how do I delete this";
          puVar23[0x1b] = 0x14;
          puVar23[0x1c] = "corn bread recipe";
          puVar23[0x1d] = 0x11;
          puVar24 = (undefined8 *)FUN_140673b40(puVar23,0xf,&local_100);
          if (puVar24 == (undefined8 *)0x0) {
            FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                          ,0x2b,&PTR_s_src_net_endpoint_rs_142424bf8);
            goto LAB_1402fc0b2;
          }
          FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
          FUN_1408192a0(local_120,0xc,1);
          local_120 = (char (*) [8])CONCAT44(uStack_ec,uStack_f0);
          uVar29 = 0xf0;
LAB_1402fb691:
          uStack_118 = (undefined8 **)local_e8;
          uStack_128 = local_f8;
          FUN_1408192a0(puVar23,uVar29,8);
          break;
        case '\x03':
          if (iVar20 == 2) {
            if ((uVar31 & 6) != 2) goto switchD_1402fa310_default;
            if ((local_c0 & 7) == 0) {
              uVar19 = uVar28 + 7;
              if (-1 < (int)uVar28) {
                uVar19 = uVar28;
              }
              if ((uVar19 >> 3 & 0xf) == 0) {
                lVar30 = 0;
                do {
                  if (*(longlong *)(local_80 + 0x30) == lVar30) {
                    uVar28 = uVar31 << 8 | 0x1020001;
                    cStack_10b = '\x01';
                    bStack_109 = (byte)(uVar28 >> 0x10);
                    bStack_108 = (byte)(uVar28 >> 0x18);
                    cStack_107 = '\0';
                    cStack_10a = (char)local_58;
                    FUN_14067a670(&local_f8,"Do you have some spare screws?",0x1e);
                    goto LAB_1402fbc7c;
                  }
                  pcVar2 = (char *)(*(longlong *)(local_80 + 0x28) + lVar30);
                  lVar30 = lVar30 + 1;
                } while (*pcVar2 != '=');
                uVar27 = uVar28 + 0x1ff;
                uVar19 = uVar28 + 0x7f;
                if (-1 < (int)uVar28) {
                  uVar27 = uVar28;
                  uVar19 = uVar28;
                }
                uVar19 = ((int)uVar19 >> 7) % 4;
                uVar28 = uVar19 * 0x10000 + 0x10000;
                if (3 < uVar19) {
                  uVar28 = 0;
                }
                uVar19 = ((int)uVar27 >> 9) % 4;
                uVar27 = uVar19 * 0x1000000 + 0x1000000;
                if (3 < uVar19) {
                  uVar27 = 0;
                }
                iVar20 = (uVar27 | uVar28) + uVar31 * 0x100 + 1;
                cStack_10b = (char)iVar20;
                cStack_10a = (char)((uint)iVar20 >> 8);
                bStack_109 = (byte)((uint)iVar20 >> 0x10);
                bStack_108 = (byte)((uint)iVar20 >> 0x18);
                cStack_107 = '\0';
                FUN_14067a670(&local_f8,"Online CNC Machining Service",0x1c);
LAB_1402fbc7c:
                local_a8 = (undefined8 **)local_e8;
                local_b8 = local_f8;
                uStack_b0._0_4_ = uStack_f0;
                uStack_b0._4_4_ = uStack_ec;
                FUN_1408192a0(local_120,0xc,1);
                uStack_118 = local_a8;
                uVar33 = (undefined4)local_b8;
                uVar34 = local_b8._4_4_;
LAB_1402fbcd3:
                uStack_128 = (undefined8 **)CONCAT44(uVar34,uVar33);
                local_120 = (char (*) [8])CONCAT44(uStack_b0._4_4_,(undefined4)uStack_b0);
                break;
              }
            }
          }
          else {
            if (iVar20 != 3) goto switchD_1402fa310_default;
            if ((local_c0 & 1) == 0) {
              iVar20 = ((int)(((uint)(local_c0 >> 0x1f) & 1) + uVar28) >> 1) % 3;
              if (iVar20 != 0) {
                if (iVar20 == 1) {
                  uVar28 = uVar31 << 8 | 0x2040001;
                  cStack_10b = '\x01';
                  bStack_109 = (byte)(uVar28 >> 0x10);
                  bStack_108 = (byte)(uVar28 >> 0x18);
                  cStack_107 = '\0';
                  cStack_10a = (char)local_58;
                  puVar23 = (undefined8 *)FUN_140293650(0x10);
                  *puVar23 = "We need field rations";
                  puVar23[1] = 0x15;
                  uStack_105 = 1;
                  puVar24 = (undefined8 *)FUN_140673b40(puVar23,1,&local_100);
                  if (puVar24 == (undefined8 *)0x0) {
                    FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                                  ,0x2b,&PTR_s_src_net_endpoint_rs_142424a78);
                    goto LAB_1402fc0b2;
                  }
                  FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
                  goto LAB_1402fb31a;
                }
                cStack_107 = '\0';
                cStack_10b = '\x01';
                cStack_10a = '\x02';
                bStack_109 = 1;
                bStack_108 = 1;
                puVar23 = (undefined8 *)FUN_140293650(0x20);
                *puVar23 = "TOP SECRET";
                puVar23[1] = 10;
                puVar23[2] = "CONFIDENTIAL";
                puVar23[3] = 0xc;
                uStack_105 = 1;
                puVar24 = (undefined8 *)FUN_140673b40(puVar23,2,&local_100);
                if (puVar24 == (undefined8 *)0x0) {
                  FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                                ,0x2b,&PTR_s_src_net_endpoint_rs_142424a48);
                  goto LAB_1402fc0b2;
                }
                FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
                goto LAB_1402fb651;
              }
              uVar28 = uVar31 << 8 | 0x2030001;
              cStack_10b = '\x01';
              bStack_109 = (byte)(uVar28 >> 0x10);
              bStack_108 = (byte)(uVar28 >> 0x18);
              cStack_107 = '\0';
              cStack_10a = (char)local_58;
              puVar23 = (undefined8 *)FUN_140293650(0x10);
              *puVar23 = "We need ammunition";
              puVar23[1] = 0x12;
              puVar24 = (undefined8 *)FUN_140673b40(puVar23,1,&local_100);
              if (puVar24 == (undefined8 *)0x0) {
                FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                              ,0x2b,&PTR_s_src_net_endpoint_rs_142424aa8);
                goto LAB_1402fc0b2;
              }
              FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
              FUN_1408192a0(local_120,0xc,1);
              local_120 = (char (*) [8])CONCAT44(uStack_ec,uStack_f0);
              uStack_105 = 1;
              uVar29 = 0x10;
              goto LAB_1402fb691;
            }
          }
          goto LAB_1402faf50;
        case '\x04':
          if (iVar20 != 4) {
            if (iVar20 == 3) {
              if (2 < local_58 - 2) goto switchD_1402fa310_default;
              if ((local_c0 & 1) == 0) {
                if ((((uint)(local_c0 >> 0x1f) & 1) + uVar28 >> 1 & 3) != 0) {
                  uVar28 = uVar31 << 8 | 0x1040001;
                  cStack_10b = '\x01';
                  bStack_109 = (byte)(uVar28 >> 0x10);
                  bStack_108 = (byte)(uVar28 >> 0x18);
                  cStack_107 = '\0';
                  local_130 = 2;
                  uVar32 = plVar21[0x22];
                  cStack_10a = (char)local_58;
                  if (0x3f < uVar32) {
                    FUN_140441990(plVar21 + 0x24,plVar21 + 2);
                    plVar21[0x22] = 0;
                    uVar32 = 0;
                  }
                  local_78 = *(undefined4 *)((longlong)plVar21 + uVar32 * 4 + 0x10);
                  plVar21[0x22] = uVar32 + 1;
                  local_98 = (undefined8 *)&local_78;
                  uStack_90 = FUN_1423bd7e0;
                  local_f8 = (undefined8 **)0x0;
                  local_e8 = &PTR_DAT_142424990;
                  local_e0 = 1;
                  local_d8 = (undefined8 **)&local_98;
                  local_d0 = 1;
                  FUN_1423a0360(&local_b8,&local_f8);
LAB_1402fb401:
                  local_f8 = local_b8;
                  uStack_f0 = (undefined4)uStack_b0;
                  uStack_ec = uStack_b0._4_4_;
                  local_e8 = (undefined **)local_a8;
                  FUN_1408192a0(local_120,0xc,1);
                  uStack_118 = (undefined8 **)local_e8;
                  uVar33 = (undefined4)local_f8;
                  uVar34 = local_f8._4_4_;
                  uStack_b0._0_4_ = uStack_f0;
                  uStack_b0._4_4_ = uStack_ec;
                  goto LAB_1402fbcd3;
                }
                uVar31 = uVar28 + 7;
                if (-1 < (int)uVar28) {
                  uVar31 = uVar28;
                }
                uVar28 = ((int)uVar31 >> 3) % 4;
                iVar20 = 0x2020001;
                if (uVar28 < 4) {
                  iVar20 = uVar28 * 0x100 + 0x2020101;
                }
                cStack_10b = (char)iVar20;
                cStack_10a = (char)((uint)iVar20 >> 8);
                bStack_109 = (byte)((uint)iVar20 >> 0x10);
                bStack_108 = (byte)((uint)iVar20 >> 0x18);
                cStack_107 = '\0';
                puVar23 = (undefined8 *)FUN_140293650(0x30);
                *puVar23 = "My money is working for me";
                puVar23[1] = 0x1a;
                puVar23[2] = "Economists hate this simple trick";
                puVar23[3] = 0x21;
                puVar23[4] = "INVEST NOW!";
                puVar23[5] = 0xb;
                puVar24 = (undefined8 *)FUN_140673b40(puVar23,3,&local_100);
                if (puVar24 == (undefined8 *)0x0) {
                  FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                                ,0x2b,&PTR_s_src_net_endpoint_rs_1424249e8);
                  goto LAB_1402fc0b2;
                }
                FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
                goto LAB_1402fbbdd;
              }
            }
            else {
              if (((iVar20 != 2) || (4 < local_58)) || ((0x16UL >> (local_58 & 0x3f) & 1) == 0))
              goto switchD_1402fa310_default;
              if ((local_c0 & 7) == 0) {
                uVar19 = uVar28 + 7;
                if (-1 < (int)uVar28) {
                  uVar19 = uVar28;
                }
                iVar20 = ((int)uVar19 >> 3) % 0x10;
                if (iVar20 == 1) {
                  uVar28 = uVar31 << 8 | 0x2020001;
                  cStack_10b = '\x01';
                  bStack_109 = (byte)(uVar28 >> 0x10);
                  bStack_108 = (byte)(uVar28 >> 0x18);
                  cStack_107 = '\0';
                  cStack_10a = (char)local_58;
                  FUN_14067a670(&local_f8,"Purchase Order",0xe);
                  goto LAB_1402fbc7c;
                }
                if (iVar20 != 0) goto LAB_1402fa199;
                uVar27 = uVar28 + 0x7f;
                uVar19 = uVar28 + 0x1ff;
                if (-1 < (int)uVar28) {
                  uVar27 = uVar28;
                  uVar19 = uVar28;
                }
                uVar19 = ((int)uVar19 >> 9) % 4;
                uVar28 = uVar19 * 0x10000 + 0x10000;
                if (3 < uVar19) {
                  uVar28 = 0;
                }
                uVar19 = ((int)uVar27 >> 7) % 4;
                uVar27 = uVar19 * 0x1000000 + 0x1000000;
                if (3 < uVar19) {
                  uVar27 = 0;
                }
                iVar20 = (uVar27 | uVar28) + uVar31 * 0x100 + 1;
                cStack_10b = (char)iVar20;
                cStack_10a = (char)((uint)iVar20 >> 8);
                bStack_109 = (byte)((uint)iVar20 >> 0x10);
                bStack_108 = (byte)((uint)iVar20 >> 0x18);
                cStack_107 = '\0';
                puVar23 = (undefined8 *)FUN_140293650(0x30);
                *puVar23 = "BEST PRICES";
                puVar23[1] = 0xb;
                puVar23[2] = "HUGE DISCOUNT!";
                puVar23[3] = 0xe;
                puVar23[4] = "SALES";
                puVar23[5] = 5;
                puVar24 = (undefined8 *)FUN_140673b40(puVar23,3,&local_100);
                if (puVar24 == (undefined8 *)0x0) {
                  FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                                ,0x2b,&PTR_s_src_net_endpoint_rs_142424a30);
                  goto LAB_1402fc0b2;
                }
                FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
LAB_1402fbbdd:
                FUN_1408192a0(local_120,0xc,1);
                local_120 = (char (*) [8])CONCAT44(uStack_ec,uStack_f0);
                uVar29 = 0x30;
                goto LAB_1402fb691;
              }
            }
            goto LAB_1402faf50;
          }
          if (2 < local_58 - 2) goto switchD_1402fa310_default;
          if ((local_c0 & 1) != 0) goto LAB_1402faf50;
          if ((((uint)(local_c0 >> 0x1f) & 1) + uVar28 >> 1 & 1) == 0) {
            uVar28 = uVar31 << 8 | 0x1010001;
            cStack_10b = '\x01';
            bStack_109 = (byte)(uVar28 >> 0x10);
            bStack_108 = (byte)(uVar28 >> 0x18);
            cStack_107 = '\0';
            cStack_10a = (char)local_58;
            puVar23 = (undefined8 *)FUN_140293650(0x10);
            *puVar23 = "Status Report";
            puVar23[1] = 0xd;
            local_130 = 1;
            puVar24 = (undefined8 *)FUN_140673b40(puVar23,1,&local_100);
            if (puVar24 == (undefined8 *)0x0) {
              FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                            ,0x2b,&PTR_s_src_net_endpoint_rs_142424970);
              goto LAB_1402fc0b2;
            }
            FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
          }
          else {
            uVar31 = uVar28 + 3;
            if (-1 < (int)uVar28) {
              uVar31 = uVar28;
            }
            uVar28 = ((int)uVar31 >> 2) % 4;
            iVar20 = 0x4040001;
            if (uVar28 < 4) {
              iVar20 = uVar28 * 0x100 + 0x4040101;
            }
            cStack_10b = (char)iVar20;
            cStack_10a = (char)((uint)iVar20 >> 8);
            bStack_109 = (byte)((uint)iVar20 >> 0x10);
            bStack_108 = (byte)((uint)iVar20 >> 0x18);
            cStack_107 = '\0';
            puVar23 = (undefined8 *)FUN_140293650(0x10);
            *puVar23 = "Meeting minutes";
            puVar23[1] = 0xf;
            puVar24 = (undefined8 *)FUN_140673b40(puVar23,1,&local_100);
            if (puVar24 == (undefined8 *)0x0) {
              FUN_1423ab4f0("called `Option::unwrap()` on a `None` value/home/puzzled_squid/src/tunnet/deps/bevy/crates/bevy_ecs/src/system/function_system.rs"
                            ,0x2b,&PTR_s_src_net_endpoint_rs_142424948);
              goto LAB_1402fc0b2;
            }
            FUN_140275e80(&local_f8,*puVar24,puVar24[1]);
          }
          FUN_1408192a0(local_120,0xc,1);
          uStack_118 = (undefined8 **)local_e8;
          uStack_128 = local_f8;
          local_120 = (char (*) [8])CONCAT44(uStack_ec,uStack_f0);
          FUN_1408192a0(puVar23,0x10,8);
          break;
        default:
          goto switchD_1402fa310_default;
        }
LAB_1402fb6a4:
        param_1[6] = CONCAT17(bStack_109,CONCAT16(cStack_10a,CONCAT15(cStack_10b,uVar13)));
        param_1[7] = CONCAT17(uStack_101,
                              CONCAT16(uStack_102,
                                       CONCAT15(uStack_103,
                                                CONCAT14(uStack_104,
                                                         CONCAT13(uStack_105,
                                                                  CONCAT12(uStack_106,
                                                                           CONCAT11(cStack_107,
                                                                                    bStack_108))))))
                             );
        param_1[4] = local_120;
        param_1[5] = uStack_118;
        param_1[2] = local_130;
        param_1[3] = uStack_128;
        *(undefined4 *)param_1 = local_140;
        *(undefined4 *)((longlong)param_1 + 4) = uStack_13c;
        *(undefined4 *)(param_1 + 1) = uStack_138;
        *(undefined4 *)((longlong)param_1 + 0xc) = uStack_134;
        goto LAB_1402faf1d;
      }
      goto LAB_1402faf5e;
    }
    if ((((char)local_58 == '\x04') && (cVar3 == '\x02')) && ((char)local_a0 == '\x01')) {
      cStack_107 = param_3[4];
      uVar33 = *(undefined4 *)param_3;
      cStack_10b = (char)uVar33;
      cStack_10a = (char)((uint)uVar33 >> 8);
      bStack_109 = (byte)((uint)uVar33 >> 0x10);
      bStack_108 = (byte)((uint)uVar33 >> 0x18);
      puVar22 = (undefined4 *)thunk_FUN_142351260(0x13,1);
      if (puVar22 == (undefined4 *)0x0) {
        FUN_14239ef70(0x13,1);
        goto LAB_1402fc0b2;
      }
      *puVar22 = 0x203a6552;
      puVar22[1] = 0x203a6552;
      puVar22[2] = 0x203a6552;
      puVar22[3] = 0x203a6552;
      *(undefined4 *)((longlong)puVar22 + 0xf) = 0x2e2e2e20;
      FUN_1408192a0(local_120,0xc,1);
      uStack_106 = 1;
      *param_1 = puVar6;
      param_1[1] = uVar29;
      *(undefined4 *)(param_1 + 2) = 4;
      *(undefined4 *)((longlong)param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 3) = 0x13;
      *(undefined4 *)((longlong)param_1 + 0x1c) = 0;
      param_1[4] = puVar22;
      param_1[5] = 0x13;
      param_1[6] = CONCAT17(bStack_109,CONCAT16(cStack_10a,CONCAT15(cStack_10b,uVar10)));
      *(ushort *)(param_1 + 7) = CONCAT11(cStack_107,bStack_108);
      *(undefined1 *)((longlong)param_1 + 0x3a) = 1;
      *(uint *)((longlong)param_1 + 0x3b) =
           CONCAT13(uStack_102,CONCAT12(uStack_103,CONCAT11(uStack_104,uStack_105)));
      *(undefined1 *)((longlong)param_1 + 0x3f) = uStack_101;
      goto LAB_1402faf1d;
    }
switchD_1402fa310_default:
    *(undefined1 *)((longlong)param_1 + 0x3a) = 2;
    uStack_128 = (undefined8 **)&DAT_0000000c;
    goto LAB_1402faf09;
  }
  if ((((char)local_58 != '\x01') || (cVar3 != '\x01')) || ((char)local_a0 != '\x01'))
  goto switchD_1402fa310_default;
  uVar31 = uVar28 + 3;
  if (-1 < (int)uVar28) {
    uVar31 = uVar28;
  }
  if (uVar28 - (uVar31 & 0xfffffffc) != ((int)uVar31 >> 2) % 4) goto LAB_1402faf50;
  FUN_1423a1210(&local_f8,"ACGT...",4,4);
  ppuVar15 = (undefined8 **)local_e8;
  ppuVar14 = local_f8;
  uVar29 = CONCAT44(uStack_ec,uStack_f0);
  FUN_140673c60(uVar29,local_e8,&local_100);
  FUN_1423b2600(&local_f8,uVar29,ppuVar15);
  if (local_f8 != (undefined8 **)0x0) {
    local_98._0_7_ = (undefined7)((ulonglong)local_e8 >> 8);
    if ((char)local_e8 != '\x02') {
      uStack_f0 = SUB84(local_e8,0);
      uStack_ec = local_e8._4_4_;
      local_e8 = (undefined **)ppuVar14;
      local_d8 = ppuVar15;
      FUN_1423ab9f0("called `Result::unwrap()` on an `Err` value",0x2b,&local_f8,&PTR_LAB_14241f228,
                    &PTR_s_src_net_endpoint_rs_1424246c8);
      goto LAB_1402fc0b2;
    }
  }
  local_b8 = ppuVar14;
  local_a8 = ppuVar15;
  local_50 = &local_b8;
  local_48 = &LAB_140293f90;
  local_f8 = (undefined8 **)0x0;
  local_e8 = &PTR_s__home_puzzled_squid__cargo_regis_1424246a8;
  local_e0 = 2;
  local_d8 = &local_50;
  local_d0 = 1;
  uStack_b0 = (char (*) [8])uVar29;
  FUN_1423a0360(&local_98,&local_f8);
  if (local_b8 != (undefined8 **)0x0) {
    FUN_1408192a0(uStack_b0,local_b8,~(ulonglong)local_b8 >> 0x3f);
  }
  local_78 = (undefined4)local_98;
  uStack_74 = local_98._4_4_;
  uStack_70 = (undefined4)uStack_90;
  uStack_6c = uStack_90._4_4_;
  local_68 = local_88;
  switch(*(undefined1 *)(local_80 + 0x1c5)) {
  case 0:
    bStack_108 = 1;
    goto LAB_1402faadc;
  case 1:
    bStack_108 = 4;
LAB_1402faadc:
    bStack_109 = 2;
    cStack_10a = '\x01';
    cStack_10b = '\x04';
    cStack_107 = '\0';
    FUN_1408192a0(local_120,0xc,1);
    *(undefined4 *)(param_1 + 6) = uVar33;
    *(char *)((longlong)param_1 + 0x34) = cVar5;
    *(uint *)((longlong)param_1 + 0x35) =
         CONCAT13(bStack_108,CONCAT12(bStack_109,CONCAT11(cStack_10a,cStack_10b)));
    *(char *)((longlong)param_1 + 0x39) = cStack_107;
    *(uint *)((longlong)param_1 + 0x3a) =
         CONCAT13(uStack_103,CONCAT12(uStack_104,CONCAT11(uStack_105,uStack_106)));
    *(ushort *)((longlong)param_1 + 0x3e) = CONCAT11(uStack_101,uStack_102);
    param_1[4] = CONCAT44(uStack_6c,uStack_70);
    param_1[5] = local_68;
    param_1[2] = 0;
    param_1[3] = CONCAT44(uStack_74,local_78);
    *(undefined4 *)param_1 = 0x424241fe;
    *(undefined4 *)((longlong)param_1 + 4) = 1;
    *(undefined4 *)(param_1 + 1) = 6;
    *(undefined4 *)((longlong)param_1 + 0xc) = 0;
    goto LAB_1402faf1d;
  case 2:
    cStack_107 = '\0';
    cStack_10b = '\x04';
    cStack_10a = '\x01';
    bStack_109 = 2;
    bStack_108 = 1;
    FUN_14067a670(&local_f8,&DAT_142424710,0x10);
    break;
  case 3:
    cStack_107 = '\0';
    cStack_10b = '\x04';
    cStack_10a = '\x01';
    bStack_109 = 2;
    bStack_108 = 2;
    FUN_14067a670(&local_f8,&DAT_142424700,0x10);
    break;
  case 4:
    cStack_107 = '\0';
    cStack_10b = '\x04';
    cStack_10a = '\x01';
    bStack_109 = 2;
    bStack_108 = 3;
    FUN_14067a670(&local_f8,&DAT_1424246f0,0x10);
    break;
  case 5:
    cStack_107 = '\0';
    cStack_10b = '\x04';
    cStack_10a = '\x01';
    bStack_109 = 2;
    bStack_108 = 4;
    FUN_14067a670(&local_f8,&DAT_1424246e0,0x10);
    break;
  default:
    *(undefined1 *)((longlong)param_1 + 0x3a) = 2;
    bVar9 = false;
    bVar8 = false;
    puVar23 = local_98;
    goto joined_r0x0001402fac5e;
  }
  local_a8 = (undefined8 **)local_e8;
  local_b8 = local_f8;
  uStack_b0 = (char (*) [8])CONCAT44(uStack_ec,uStack_f0);
  FUN_1408192a0(local_120,0xc,1);
  param_1[6] = CONCAT17(bStack_109,CONCAT16(cStack_10a,CONCAT15(cStack_10b,uVar11)));
  param_1[7] = CONCAT17(uStack_101,
                        CONCAT16(uStack_102,
                                 CONCAT15(uStack_103,
                                          CONCAT14(uStack_104,
                                                   CONCAT13(uStack_105,
                                                            CONCAT12(uStack_106,
                                                                     CONCAT11(cStack_107,bStack_108)
                                                                    ))))));
  param_1[4] = uStack_b0;
  param_1[5] = local_a8;
  param_1[2] = 0;
  param_1[3] = local_b8;
  *(undefined4 *)param_1 = 0x424241fe;
  *(undefined4 *)((longlong)param_1 + 4) = 1;
  *(undefined4 *)(param_1 + 1) = 6;
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  bVar9 = true;
  bVar8 = true;
  puVar23 = (undefined8 *)CONCAT44(uStack_74,local_78);
  local_120 = uStack_b0;
  uStack_128 = local_b8;
joined_r0x0001402fac5e:
  if (puVar23 != (undefined8 *)0x0) {
    FUN_1408192a0(CONCAT44(uStack_6c,uStack_70),puVar23,~(ulonglong)puVar23 >> 0x3f);
    bVar8 = bVar9;
  }
  if (!bVar8) {
LAB_1402faf5e:
    if (uStack_128 != (undefined8 **)0x0) {
LAB_1402faf09:
      uVar32 = ~(ulonglong)uStack_128 >> 0x3f;
      pacVar25 = local_120;
LAB_1402faf18:
      FUN_1408192a0(pacVar25,uStack_128,uVar32);
    }
  }
LAB_1402faf1d:
  *plVar21 = *plVar21 + -1;
  if (*plVar21 == 0) {
    plVar1 = plVar21 + 1;
    *plVar1 = *plVar1 + -1;
    if (*plVar1 == 0) {
      FUN_1408192a0(plVar21,0x170,0x10);
    }
  }
  return;
}

