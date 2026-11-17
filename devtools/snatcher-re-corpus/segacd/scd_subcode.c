// Ghidra decompilation of scd_subcode.bin (68000:BE:32:default)

// ---- FUN_0000e322 @ 0000e322

void FUN_0000e322(void)

{
  short sVar1;
  short unaff_D6w;
  short unaff_D7w;
  short *psVar2;
  undefined4 unaff_A5;
  undefined4 unaff_A6;
  
  psVar2 = (short *)&DAT_000b6000;
  sVar1 = 0xf;
  if ((DAT_00ff800f & 8) != 0) {
    sVar1 = 3;
  }
  do {
    if (*psVar2 == 0) {
      *psVar2 = unaff_D6w;
      *(undefined4 *)(psVar2 + 1) = unaff_A5;
      *(undefined4 *)(psVar2 + 3) = unaff_A6;
      psVar2[5] = unaff_D7w;
      return;
    }
    psVar2 = psVar2 + 6;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}



// ---- FUN_0000e41a @ 0000e41a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000e41a(void)

{
  short sVar1;
  byte *in_A1;
  byte *pbVar2;
  char *pcVar3;
  
  sVar1 = 0xb;
  pbVar2 = _DAT_000090c0;
  while( true ) {
    pbVar2 = pbVar2 + 0x10;
    if ((byte *)0x90bf < pbVar2) {
      pbVar2 = &DAT_00009000;
    }
    if (*pbVar2 == 0) break;
    sVar1 = sVar1 + -1;
    if (sVar1 == -1) {
      return;
    }
  }
  *(byte **)(pbVar2 + 8) = in_A1;
  *pbVar2 = *in_A1;
  pbVar2[1] = 0;
  pbVar2[2] = in_A1[2];
  pbVar2[3] = in_A1[3];
  *(byte **)(pbVar2 + 4) = in_A1 + 4;
  pbVar2[0xc] = 0;
  if (0x7f < *pbVar2) {
    pcVar3 = &DAT_00009000;
    sVar1 = 0xb;
    do {
      if (*pcVar3 == '\x06') {
        *pcVar3 = '\0';
      }
      pcVar3 = pcVar3 + 0x10;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
  }
  *pbVar2 = *pbVar2 & 0x7f;
  return;
}



// ---- FUN_0000e4a0 @ 0000e4a0

void FUN_0000e4a0(void)

{
  short sVar1;
  undefined4 *puVar2;
  
  sVar1 = 0x2f;
  puVar2 = (undefined4 *)&DAT_00009000;
  do {
    *puVar2 = 0;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (sVar1 != -1);
  return;
}



// ---- FUN_0000e528 @ 0000e528

void FUN_0000e528(void)

{
  return;
}



// ---- FUN_0000e540 @ 0000e540

undefined4 FUN_0000e540(void)

{
  undefined4 in_D0;
  int in_A1;
  undefined4 in_stack_00000000;
  
  if (*(char *)(in_A1 + 1) != '\0') {
    *(char *)(in_A1 + 1) = *(char *)(in_A1 + 1) + -1;
    return in_stack_00000000;
  }
  *(undefined1 *)(in_A1 + 1) = *(undefined1 *)(*(int *)(in_A1 + 8) + 1);
  if ((*(byte *)(in_A1 + 2) & 0x80) == 0) {
    DAT_000b6404 = DAT_000b6404 | 1;
    return in_D0;
  }
  DAT_000b6404 = DAT_000b6404 | 2;
  return in_D0;
}



// ---- FUN_0000e7a8 @ 0000e7a8

void FUN_0000e7a8(void)

{
  ushort in_D0w;
  ushort in_D1w;
  ushort unaff_D2w;
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort *unaff_A3;
  
  uVar1 = *unaff_A3 & 0xf;
  uVar2 = *unaff_A3 & 0xf0;
  uVar3 = *unaff_A3 & 0xf00;
  if (uVar1 != in_D0w) {
    if ((short)uVar1 < (short)in_D0w) {
      uVar1 = uVar1 + 2;
    }
    else {
      uVar1 = uVar1 - 2;
    }
  }
  if (uVar2 != in_D1w) {
    if ((short)uVar2 < (short)in_D1w) {
      uVar2 = uVar2 + 0x20;
    }
    else {
      uVar2 = uVar2 - 0x20;
    }
  }
  if (uVar3 != unaff_D2w) {
    if ((short)uVar3 < (short)unaff_D2w) {
      uVar3 = uVar3 + 0x200;
    }
    else {
      uVar3 = uVar3 - 0x200;
    }
  }
  *unaff_A3 = uVar3 | uVar2 | uVar1;
  return;
}



// ---- FUN_0000e7fa @ 0000e7fa

void FUN_0000e7fa(void)

{
  int in_A1;
  
  *(char *)(in_A1 + 0xc) = *(char *)(in_A1 + 0xc) + '\x01';
  return;
}



// ---- FUN_0000e81a @ 0000e81a

void FUN_0000e81a(void)

{
  short sVar1;
  char *in_A1;
  char *pcVar2;
  
  sVar1 = 6;
  pcVar2 = &DAT_00008e00;
  do {
    if (*pcVar2 == '\0') {
      *pcVar2 = *in_A1;
      pcVar2[1] = '\0';
      *(char **)(pcVar2 + 2) = in_A1 + 2;
      return;
    }
    pcVar2 = pcVar2 + 8;
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}



// ---- FUN_0000e874 @ 0000e874

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0000e874(void)

{
  byte bVar1;
  uint uVar2;
  char cVar3;
  ushort uVar4;
  uint unaff_D5;
  short sVar5;
  int iVar6;
  byte *pbVar7;
  byte *extraout_A1;
  undefined1 *extraout_A1_00;
  byte *extraout_A1_01;
  undefined1 *extraout_A1_02;
  byte *extraout_A1_03;
  undefined1 *extraout_A1_04;
  undefined1 *extraout_A1_05;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  byte *pbVar11;
  
  do {
    uVar2 = FUN_0000e880();
    pbVar11 = extraout_A1;
    while( true ) {
      pbVar7 = pbVar11;
      pbVar11 = pbVar7 + 8;
      uVar4 = (short)unaff_D5 - 1;
      unaff_D5 = (uint)uVar4;
      if (uVar4 == 0xffff) {
        return uVar2;
      }
      if ((*pbVar11 & 0x40) != 0) break;
      if (*pbVar11 != 0) {
        uVar4 = (*pbVar11 & 0x30) >> 2;
        _DAT_00008e38 = *(undefined4 **)(&DAT_0000e8b6 + (short)uVar4);
        cVar3 = (char)uVar4;
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
        switch(*pbVar11 & 0xf) {
        case 0:
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        case 1:
          uVar2 = (uint)uVar4;
          if ((cVar3 != '\0') || (_DAT_000b6000 == 0)) {
            if ((*pbVar11 & 0x80) == 0) {
              FUN_0000f346(*(undefined4 *)(pbVar7 + 10));
            }
            uVar2 = FUN_0000e8c6();
            *(int *)(extraout_A1_00 + 2) = *(int *)(extraout_A1_00 + 2) + 10;
            if (**(short **)(extraout_A1_00 + 2) == -1) {
              *extraout_A1_00 = 0;
            }
          }
          break;
        case 2:
          uVar2 = (uint)uVar4;
          if ((cVar3 != '\0') || (_DAT_000b6000 == 0)) {
            do {
              puVar10 = *(undefined4 **)(pbVar11 + 2);
              sVar5 = *(short *)(puVar10 + 2) + -1;
              puVar8 = (undefined1 *)*puVar10;
              puVar9 = (undefined1 *)((int)_DAT_00008e38 + (int)*(short *)((int)puVar10 + 6));
              do {
                *puVar9 = *puVar8;
                sVar5 = sVar5 + -1;
                puVar8 = puVar8 + 1;
                puVar9 = puVar9 + 1;
              } while (sVar5 != -1);
              uVar2 = FUN_0000e8c6();
              *(int *)(extraout_A1_01 + 2) = *(int *)(extraout_A1_01 + 2) + 10;
              pbVar11 = extraout_A1_01;
            } while (**(short **)(extraout_A1_01 + 2) != -1);
            *extraout_A1_01 = 0;
          }
          return uVar2;
        case 3:
          uVar2 = (uint)uVar4;
          if ((cVar3 != '\0') || (_DAT_000b6000 == 0)) {
            if ((*pbVar11 & 0x80) == 0) {
              FUN_0000f346(*(undefined4 *)(pbVar7 + 10));
            }
            while( true ) {
              uVar2 = FUN_0000e8c6();
              *(int *)(extraout_A1_02 + 2) = *(int *)(extraout_A1_02 + 2) + 10;
              if (**(short **)(extraout_A1_02 + 2) == -1) break;
              *(int *)(extraout_A1_02 + 2) = *(int *)(extraout_A1_02 + 2) + -4;
            }
            *extraout_A1_02 = 0;
          }
          return uVar2;
        case 4:
          uVar2 = (uint)uVar4;
          if ((cVar3 != '\0') || (_DAT_000b6000 == 0)) {
            iVar6 = *(int *)(pbVar7 + 10);
            if ((*pbVar11 & 0x80) == 0) {
              FUN_0000f346();
              *extraout_A1_03 = *extraout_A1_03 | 0x80;
              pbVar11 = extraout_A1_03;
            }
            sVar5 = ((ushort)(pbVar11[1] & 7) + ((ushort)(pbVar11[1] >> 3) * 5 & 0xff07) & 0xff07) *
                    2;
            pbVar11 = (byte *)((int)_DAT_00008e38 +
                              (int)*(short *)(iVar6 + 6) +
                              (uint)(byte)((&DAT_0000ea78)[sVar5] +
                                          (char)((ushort)(pbVar11[1] & 7) * 4)));
            bVar1 = (&DAT_0000ea79)[sVar5];
            sVar5 = (*(ushort *)(iVar6 + 8) >> 5) - 1;
            do {
              *pbVar11 = bVar1 & *pbVar11;
              pbVar11 = pbVar11 + 0x20;
              sVar5 = sVar5 + -1;
            } while (sVar5 != -1);
            uVar2 = FUN_0000e8c6();
            extraout_A1_04[1] = extraout_A1_04[1] + '\x01';
            if (extraout_A1_04[1] == 'A') {
              *extraout_A1_04 = 0;
            }
          }
          return uVar2;
        case 5:
          uVar2 = (uint)uVar4;
          if ((cVar3 != '\0') || (_DAT_000b6000 == 0)) {
            if (pbVar7[9] == 0) {
              sVar5 = 7;
              puVar10 = _DAT_00008e38;
              do {
                *puVar10 = 0;
                sVar5 = sVar5 + -1;
                puVar10 = puVar10 + 1;
              } while (sVar5 != -1);
            }
            sVar5 = ((ushort)(pbVar7[9] & 7) + ((ushort)(pbVar7[9] >> 3) * 5 & 0xff07) & 0xff07) * 2
            ;
            pbVar11 = (byte *)((uint)(byte)((&DAT_0000ea78)[sVar5] +
                                           (char)((ushort)(pbVar7[9] & 7) * 4)) + (int)_DAT_00008e38
                              );
            bVar1 = (&DAT_0000ea79)[sVar5];
            sVar5 = 0;
            do {
              *pbVar11 = (bVar1 ^ 0xff) & 0x77 | *pbVar11;
              sVar5 = sVar5 + -1;
            } while (sVar5 != -1);
            uVar2 = FUN_0000e322();
            extraout_A1_05[1] = extraout_A1_05[1] + '\x01';
            if (extraout_A1_05[1] == 'A') {
              *extraout_A1_05 = 0;
            }
          }
          return uVar2;
        }
        return uVar2;
      }
    }
  } while( true );
}



// ---- FUN_0000e880 @ 0000e880

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0000e880(void)

{
  byte bVar1;
  uint uVar2;
  ushort uVar3;
  char cVar4;
  short sVar5;
  int iVar6;
  byte *in_A1;
  undefined1 *extraout_A1;
  byte *extraout_A1_00;
  undefined1 *extraout_A1_01;
  byte *extraout_A1_02;
  undefined1 *extraout_A1_03;
  undefined1 *extraout_A1_04;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  
  uVar3 = (*in_A1 & 0x30) >> 2;
  _DAT_00008e38 = *(undefined4 **)(&DAT_0000e8b6 + (short)uVar3);
  cVar4 = (char)uVar3;
                    /* WARNING (jumptable): Sanity check requires truncation of jumptable */
                    /* WARNING: Could not find normalized switch variable to match jumptable */
  switch(*in_A1 & 0xf) {
  case 0:
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  case 1:
    uVar2 = (uint)uVar3;
    if ((cVar4 != '\0') || (_DAT_000b6000 == 0)) {
      if ((*in_A1 & 0x80) == 0) {
        FUN_0000f346(*(undefined4 *)(in_A1 + 2));
      }
      uVar2 = FUN_0000e8c6();
      *(int *)(extraout_A1 + 2) = *(int *)(extraout_A1 + 2) + 10;
      if (**(short **)(extraout_A1 + 2) == -1) {
        *extraout_A1 = 0;
      }
    }
    break;
  case 2:
    uVar2 = (uint)uVar3;
    if ((cVar4 != '\0') || (_DAT_000b6000 == 0)) {
      do {
        puVar9 = *(undefined4 **)(in_A1 + 2);
        sVar5 = *(short *)(puVar9 + 2) + -1;
        puVar7 = (undefined1 *)*puVar9;
        puVar8 = (undefined1 *)((int)_DAT_00008e38 + (int)*(short *)((int)puVar9 + 6));
        do {
          *puVar8 = *puVar7;
          sVar5 = sVar5 + -1;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        } while (sVar5 != -1);
        uVar2 = FUN_0000e8c6();
        *(int *)(extraout_A1_00 + 2) = *(int *)(extraout_A1_00 + 2) + 10;
        in_A1 = extraout_A1_00;
      } while (**(short **)(extraout_A1_00 + 2) != -1);
      *extraout_A1_00 = 0;
    }
    return uVar2;
  case 3:
    uVar2 = (uint)uVar3;
    if ((cVar4 != '\0') || (_DAT_000b6000 == 0)) {
      if ((*in_A1 & 0x80) == 0) {
        FUN_0000f346(*(undefined4 *)(in_A1 + 2));
      }
      while( true ) {
        uVar2 = FUN_0000e8c6();
        *(int *)(extraout_A1_01 + 2) = *(int *)(extraout_A1_01 + 2) + 10;
        if (**(short **)(extraout_A1_01 + 2) == -1) break;
        *(int *)(extraout_A1_01 + 2) = *(int *)(extraout_A1_01 + 2) + -4;
      }
      *extraout_A1_01 = 0;
    }
    return uVar2;
  case 4:
    uVar2 = (uint)uVar3;
    if ((cVar4 != '\0') || (_DAT_000b6000 == 0)) {
      iVar6 = *(int *)(in_A1 + 2);
      if ((*in_A1 & 0x80) == 0) {
        FUN_0000f346();
        *extraout_A1_02 = *extraout_A1_02 | 0x80;
        in_A1 = extraout_A1_02;
      }
      sVar5 = ((ushort)(in_A1[1] & 7) + ((ushort)(in_A1[1] >> 3) * 5 & 0xff07) & 0xff07) * 2;
      pbVar10 = (byte *)((int)_DAT_00008e38 +
                        (int)*(short *)(iVar6 + 6) +
                        (uint)(byte)((&DAT_0000ea78)[sVar5] + (char)((ushort)(in_A1[1] & 7) * 4)));
      bVar1 = (&DAT_0000ea79)[sVar5];
      sVar5 = (*(ushort *)(iVar6 + 8) >> 5) - 1;
      do {
        *pbVar10 = bVar1 & *pbVar10;
        pbVar10 = pbVar10 + 0x20;
        sVar5 = sVar5 + -1;
      } while (sVar5 != -1);
      uVar2 = FUN_0000e8c6();
      extraout_A1_03[1] = extraout_A1_03[1] + '\x01';
      if (extraout_A1_03[1] == 'A') {
        *extraout_A1_03 = 0;
      }
    }
    return uVar2;
  case 5:
    uVar2 = (uint)uVar3;
    if ((cVar4 != '\0') || (_DAT_000b6000 == 0)) {
      if (in_A1[1] == 0) {
        sVar5 = 7;
        puVar9 = _DAT_00008e38;
        do {
          *puVar9 = 0;
          sVar5 = sVar5 + -1;
          puVar9 = puVar9 + 1;
        } while (sVar5 != -1);
      }
      sVar5 = ((ushort)(in_A1[1] & 7) + ((ushort)(in_A1[1] >> 3) * 5 & 0xff07) & 0xff07) * 2;
      pbVar10 = (byte *)((uint)(byte)((&DAT_0000ea78)[sVar5] + (char)((ushort)(in_A1[1] & 7) * 4)) +
                        (int)_DAT_00008e38);
      bVar1 = (&DAT_0000ea79)[sVar5];
      sVar5 = 0;
      do {
        *pbVar10 = (bVar1 ^ 0xff) & 0x77 | *pbVar10;
        sVar5 = sVar5 + -1;
      } while (sVar5 != -1);
      uVar2 = FUN_0000e322();
      extraout_A1_04[1] = extraout_A1_04[1] + '\x01';
      if (extraout_A1_04[1] == 'A') {
        *extraout_A1_04 = 0;
      }
    }
    return uVar2;
  }
  return uVar2;
}



// ---- FUN_0000e8c6 @ 0000e8c6

void FUN_0000e8c6(void)

{
  FUN_0000e322();
  return;
}



// ---- FUN_0000eeb6 @ 0000eeb6

undefined8 FUN_0000eeb6(void)

{
  undefined4 in_D0;
  short sVar1;
  undefined4 in_D1;
  undefined4 *puVar2;
  
  sVar1 = 0x4ff;
  puVar2 = (undefined4 *)&DAT_00007a00;
  do {
    *puVar2 = 0;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (sVar1 != -1);
  return CONCAT44(in_D0,in_D1);
}



// ---- FUN_0000f346 @ 0000f346

void FUN_0000f346(void)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort in_D1w;
  short sVar4;
  short sVar5;
  int unaff_A5;
  byte *pbVar6;
  byte *pbVar7;
  byte *unaff_A6;
  byte *pbVar8;
  
  pbVar6 = (byte *)(unaff_A5 + 2);
  sVar5 = 0;
  do {
    while( true ) {
      while( true ) {
        sVar5 = sVar5 + -1;
        pbVar7 = pbVar6;
        if (sVar5 == -1) {
          sVar5 = 7;
          pbVar7 = pbVar6 + 1;
          in_D1w = CONCAT11((char)(in_D1w >> 8),*pbVar6);
        }
        uVar3 = in_D1w & 1;
        in_D1w = in_D1w >> 1;
        if (uVar3 != 0) break;
        pbVar6 = pbVar7 + 1;
        *unaff_A6 = *pbVar7;
        unaff_A6 = unaff_A6 + 1;
      }
      pbVar6 = pbVar7 + 1;
      bVar1 = *pbVar7;
      uVar3 = (ushort)bVar1;
      if ((char)bVar1 < '\0') break;
      if (bVar1 == 0x1f) {
        return;
      }
      uVar2 = CONCAT11((char)((ushort)(uVar3 << 3) >> 8),*pbVar6);
      sVar4 = (uVar3 & 0x1f) + 2;
      pbVar6 = pbVar7 + 2;
LAB_0000f396:
      pbVar7 = unaff_A6;
      do {
        unaff_A6 = pbVar7 + 1;
        *pbVar7 = pbVar7[(short)-uVar2];
        sVar4 = sVar4 + -1;
        pbVar7 = unaff_A6;
      } while (sVar4 != -1);
    }
    if ((bVar1 & 0x40) == 0) {
      sVar4 = (bVar1 >> 4) - 7;
      uVar2 = uVar3 & 0xf;
      goto LAB_0000f396;
    }
    uVar3 = (ushort)(byte)(bVar1 + 0x47);
    pbVar7 = pbVar6;
    pbVar8 = unaff_A6;
    do {
      pbVar6 = pbVar7 + 1;
      unaff_A6 = pbVar8 + 1;
      *pbVar8 = *pbVar7;
      uVar3 = uVar3 - 1;
      pbVar7 = pbVar6;
      pbVar8 = unaff_A6;
    } while (uVar3 != 0xffff);
  } while( true );
}



// ---- FUN_0000fea0 @ 0000fea0

void FUN_0000fea0(void)

{
  short in_D1w;
  
                    /* WARNING: Could not recover jumptable at 0x0000fea4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&DAT_0000fea8 + *(short *)(&DAT_0000fea8 + in_D1w)))();
  return;
}



// ---- FUN_0000ffae @ 0000ffae

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000ffae(void)

{
  _DAT_00009b40 = _DAT_00009b40 + 6;
  FUN_0000ffc4();
  return;
}



// ---- FUN_0000ffb6 @ 0000ffb6

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000ffb6(void)

{
  _DAT_00009b40 = _DAT_00009b40 + 4;
  FUN_0000ffc4();
  return;
}



// ---- FUN_0000ffc4 @ 0000ffc4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000ffc4(void)

{
                    /* WARNING: Could not recover jumptable at 0x0000ffde. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&DAT_0000ffe2 +
            *(short *)(&DAT_0000ffe2 + (short)(*(short *)(_DAT_00009b40 + 0x9940) * 2))))();
  return;
}



// ---- FUN_0001045e @ 0001045e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001045e(void)

{
  char cVar1;
  ushort uVar2;
  int in_A0;
  bool bVar3;
  
  bVar3 = false;
  func_0x00005f16();
  if (!bVar3) {
    cVar1 = *(char *)(in_A0 + 1);
    DAT_0001059c = cVar1 + '0';
    bVar3 = false;
    func_0x00005f16();
    if (bVar3) {
      _DAT_0000784e = _DAT_0000784e + -1;
      if (_DAT_0000784e != 0) {
        return;
      }
    }
    else {
      bVar3 = false;
      func_0x00005f16();
      if (!bVar3) {
        uVar2 = (ushort)(byte)(cVar1 - 1);
        DAT_000078b6 = DAT_000078b6 | '\x01' << (uVar2 & 7);
        *(undefined2 *)((short)(uVar2 * 2) + 0x79e2) = 1;
        _DAT_000079e0 = 0;
        goto LAB_000104d6;
      }
    }
    DAT_00009c00 = DAT_00009c01;
    _DAT_000079e0 = 0xff;
  }
LAB_000104d6:
  _DAT_00007856 = 0;
  FUN_0000ffb6();
  return;
}



// ---- FUN_000107dc @ 000107dc

void FUN_000107dc(void)

{
  byte in_D0b;
  int in_A0;
  
  if (in_D0b < *(byte *)(in_A0 + 1)) {
    return;
  }
  return;
}



// ---- FUN_00010eae @ 00010eae

undefined4 FUN_00010eae(void)

{
  undefined4 in_D0;
  short sVar1;
  short unaff_D7w;
  char *pcVar2;
  char *pcVar3;
  undefined1 in_ZF;
  
  FUN_000107dc();
  if ((bool)in_ZF) {
    return 0xff;
  }
  sVar1 = 0x20;
  pcVar2 = (char *)(unaff_D7w + 0x1e000);
  pcVar3 = &DAT_000096e9;
  do {
    *pcVar3 = *pcVar2;
    if (*pcVar2 == -1) {
      return in_D0;
    }
    sVar1 = sVar1 + -1;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (sVar1 != -1);
  DAT_0000970f = 0xff;
  return in_D0;
}



// ---- FUN_0001189e @ 0001189e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_0001189e(void)

{
  byte bVar1;
  ushort uVar2;
  ushort in_D0w;
  char cVar3;
  
  cVar3 = (char)in_D0w;
  if (cVar3 == '*') {
    DAT_00007ac5 = 0;
  }
  else if (cVar3 == '#') {
    DAT_00007b15 = 0;
  }
  else {
    *(undefined1 *)((short)((in_D0w & 0x1f) * 0x50) + 0x7a25) = 0;
  }
  bVar1 = DAT_000097f2;
  if (cVar3 == '\b') {
    FUN_00011a94();
    do {
    } while (DAT_00008d85 != '\x03');
    if (_DAT_000079fe == 3) {
      DAT_00008dd5 = 0;
      DAT_00008d67 = DAT_0001170e;
      DAT_00008d6b = DAT_0001170f;
    }
    uVar2 = FUN_00011aa8();
    return uVar2;
  }
  if (cVar3 == '\t') {
    FUN_00011a94();
    bVar1 = 0;
    if (DAT_000097f2 != 0) {
      bVar1 = *(byte *)((short)(ushort)DAT_000097f2 + 0x97d0);
      if (bVar1 == 0) {
        DAT_000097f2 = DAT_000097f2 - 1;
      }
      *(undefined1 *)((short)(ushort)DAT_000097f2 + 0x97d0) = 0;
    }
    return (ushort)bVar1;
  }
  if (DAT_00009719 <= DAT_000097f2) {
    return in_D0w;
  }
  *(char *)((short)(ushort)DAT_000097f2 + 0x97d0) = cVar3;
  if ((byte)(bVar1 + 1) != DAT_00009719) {
    DAT_000097f2 = DAT_000097f2 + 1;
  }
  return in_D0w;
}



// ---- FUN_00011a94 @ 00011a94

undefined4 FUN_00011a94(void)

{
  undefined4 in_D0;
  
  FUN_00013e0a();
  return in_D0;
}



// ---- FUN_00011aa8 @ 00011aa8

void FUN_00011aa8(void)

{
  byte bVar1;
  char cVar2;
  char extraout_D1b;
  short sVar3;
  bool bVar4;
  undefined1 uVar5;
  
  bVar1 = DAT_000097f2;
  if (*(char *)((short)(ushort)DAT_000097f2 + 0x97d0) != '\0') {
    bVar1 = DAT_000097f2 + 1;
  }
  (&DAT_00009759)[(short)(ushort)bVar1] = 0xff;
  for (sVar3 = 0; (&DAT_00009759)[sVar3] != -1; sVar3 = sVar3 + 1) {
    if ((&DAT_00009759)[sVar3] != ' ') goto LAB_00011aec;
  }
  DAT_00009759 = 0x20;
  DAT_0000975a = 0xff;
LAB_00011aec:
  cVar2 = '\0';
  while( true ) {
    bVar4 = cVar2 == '\0';
    uVar5 = 0;
    FUN_000107dc(cVar2);
    if (bVar4) {
      DAT_000079f4 = 1;
      return;
    }
    FUN_00011b26();
    if (!(bool)uVar5) break;
    cVar2 = extraout_D1b + '\x01';
  }
  DAT_000079f4 = extraout_D1b + '\x01';
  return;
}



// ---- FUN_00011b26 @ 00011b26

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00011b26(void)

{
  short sVar1;
  int in_A1;
  
  sVar1 = -1;
  if (_DAT_0000971a == 1) {
    do {
      sVar1 = sVar1 + 1;
      if (*(char *)(in_A1 + sVar1) == -1) {
        return;
      }
    } while (*(char *)(in_A1 + sVar1) != DAT_00009759);
  }
  else {
    do {
      sVar1 = sVar1 + 1;
      if (*(char *)(in_A1 + sVar1) != (&DAT_00009759)[sVar1]) {
        return;
      }
    } while (*(char *)(in_A1 + sVar1) != -1);
  }
  return;
}



// ---- FUN_00012042 @ 00012042

void FUN_00012042(void)

{
  return;
}



// ---- FUN_0001204e @ 0001204e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001204e(void)

{
  if (1 < _DAT_000078e2) {
    _DAT_000078e2 = _DAT_000078e2 - 2;
  }
  return;
}



// ---- FUN_0001205c @ 0001205c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001205c(void)

{
  if (((_DAT_000078e0 == 0) || (_DAT_000078e0 == 0xb)) || (_DAT_00007972 == 0)) {
    if (_DAT_000078e2 < 0x20) {
      _DAT_000078e2 = _DAT_000078e2 + 1;
      return;
    }
  }
  else if (_DAT_000078e2 < 0x30) {
    _DAT_000078e2 = _DAT_000078e2 + 1;
  }
  return;
}



// ---- FUN_00012e66 @ 00012e66

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00012e66(void)

{
  thunk_FUN_00015eb4();
  if (_DAT_00007910 < 6) {
    _DAT_0000892c = _DAT_0000892c + -1;
    DAT_00012eae = *(undefined2 *)(&LAB_00012ebc + (short)(_DAT_0000892c * 2));
    FUN_0000e81a();
    _DAT_00007910 = _DAT_00007910 + 1;
  }
  return;
}



// ---- FUN_00013e0a @ 00013e0a

/* WARNING: Removing unreachable block (ram,0x00013e44) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00013e0a(void)

{
  undefined2 in_D0w;
  
  *(undefined2 *)(_DAT_00009b40 + 0x9940) = 0x1c;
  *(undefined2 *)(_DAT_00009b40 + 0x9942) = in_D0w;
  do {
  } while( true );
}



// ---- thunk_FUN_0001530e @ 000150ee

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_0001530e(void)

{
  byte in_D0b;
  
  if (in_D0b != 0) {
    DAT_0007f80d = 1;
    _DAT_0007f84a = (ushort)in_D0b;
    if (in_D0b < 0xf8) {
      if (in_D0b < DAT_00054000) {
        DAT_0001511e = DAT_0001511e | 8;
        FUN_0001535e();
      }
    }
    else {
      FUN_000162e0();
    }
    DAT_0007f80d = 0;
  }
  return;
}



// ---- thunk_FUN_00015eb4 @ 000150fa

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thunk_FUN_00015eb4(void)

{
  byte in_D0b;
  char in_D1b;
  
  if (in_D0b != 0) {
    if (in_D0b == 0xff) {
      DAT_0007f815 = 1;
    }
    else {
      _DAT_0007f848 = (ushort)in_D0b;
      if ((in_D0b < 0xf1) && (in_D1b != '\0')) {
        DAT_0007f815 = 0;
        DAT_0007f817 = 0xff;
      }
      *(byte *)((short)(ushort)DAT_0007f87f + 0x7f880) = in_D0b;
      DAT_0007f87f = DAT_0007f87f + 1;
      if (DAT_0007f87f == 0x80) {
        DAT_0007f87f = 0;
      }
    }
  }
  return;
}



// ---- FUN_00015130 @ 00015130

undefined8 FUN_00015130(void)

{
  undefined4 in_D0;
  undefined4 in_D1;
  
  FUN_00016364();
  return CONCAT44(in_D0,in_D1);
}



// ---- FUN_0001530e @ 0001530e

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001530e(void)

{
  byte in_D0b;
  
  if (in_D0b != 0) {
    DAT_0007f80d = 1;
    _DAT_0007f84a = (ushort)in_D0b;
    if (in_D0b < 0xf8) {
      if (in_D0b < DAT_00054000) {
        DAT_0001511e = DAT_0001511e | 8;
        FUN_0001535e();
      }
    }
    else {
      FUN_000162e0();
    }
    DAT_0007f80d = 0;
  }
  return;
}



// ---- FUN_0001535e @ 0001535e

undefined8 FUN_0001535e(void)

{
  undefined4 in_D0;
  byte bVar1;
  undefined4 in_D1;
  undefined1 extraout_D1b;
  byte unaff_D2b;
  uint uVar2;
  short sVar3;
  int extraout_A0;
  int extraout_A0_00;
  int iVar4;
  int extraout_A0_01;
  
  uVar2 = (uint)(ushort)(((ushort)in_D0 & 0xff) << 4);
  if ((byte)in_D1 == 0xff) {
    DAT_0007f807 = (&DAT_00054000)[uVar2];
    sVar3 = (ushort)*(byte *)(uVar2 + 0x54001) << 6;
    *(char *)(sVar3 + 0x7f901) = (char)in_D0;
    if (DAT_0007f807 < *(byte *)(sVar3 + 0x7f914)) goto LAB_0001541a;
    FUN_00015e24();
    *(undefined1 *)(extraout_A0_00 + 0x15 + (int)sVar3) = extraout_D1b;
    iVar4 = extraout_A0_00;
  }
  else {
    if (1 < (byte)in_D1) goto LAB_0001541a;
    sVar3 = ((ushort)in_D1 & 0xff) << 6;
    *(char *)(sVar3 + 0x7f901) = (char)in_D0;
    if ((byte)(&DAT_00054000)[uVar2] < *(byte *)(sVar3 + 0x7f914)) goto LAB_0001541a;
    DAT_0007f807 = FUN_00015e24();
    *(undefined1 *)(extraout_A0 + 0x15 + (int)sVar3) = *(undefined1 *)(uVar2 + 0x54001);
    iVar4 = extraout_A0;
  }
  bVar1 = *(byte *)(uVar2 + 0x54002);
  *(byte *)(iVar4 + 0x16 + (int)sVar3) = bVar1;
  if (unaff_D2b != 0) {
    bVar1 = (byte)((uint)bVar1 * (uint)unaff_D2b >> 8);
  }
  *(byte *)(iVar4 + 0x17 + (int)sVar3) = bVar1;
  *(undefined1 *)(iVar4 + 0x18 + (int)sVar3) = *(undefined1 *)(uVar2 + 0x54003);
  *(undefined2 *)(iVar4 + 0x1a + (int)sVar3) = *(undefined2 *)(uVar2 + 0x54004);
  *(int *)(iVar4 + 2 + (int)sVar3) = *(int *)(uVar2 + 0x54006) + 0x10;
  FUN_00015420();
  *(byte *)(extraout_A0_01 + 0x14 + (int)sVar3) = DAT_0007f807;
LAB_0001541a:
  return CONCAT44(in_D0,in_D1);
}



// ---- FUN_00015420 @ 00015420

void FUN_00015420(void)

{
  short extraout_D1w;
  
  FUN_00015458();
  FUN_00015466();
  FUN_00015458();
  FUN_00015466();
  FUN_00015bb8();
  DAT_0007f802 = DAT_0007f802 & ~('\x01' << ((ushort)(extraout_D1w * 2) & 7));
  DAT_0007f802 = DAT_0007f802 & ~('\x01' << ((ushort)(extraout_D1w * 2 + 1) & 7));
  return;
}



// ---- FUN_00015458 @ 00015458

void FUN_00015458(void)

{
  char unaff_D7b;
  int in_A1;
  
  *(char *)(in_A1 + 0xf) = unaff_D7b + -0x40;
  FUN_00016672();
  return;
}



// ---- FUN_00015466 @ 00015466

void FUN_00015466(void)

{
  byte bVar1;
  byte in_D1b;
  short extraout_D1w;
  short unaff_D3w;
  ushort uVar2;
  byte bVar3;
  int in_A0;
  int extraout_A0;
  int extraout_A0_00;
  int extraout_A0_01;
  int in_A1;
  int extraout_A1;
  int extraout_A1_00;
  int extraout_A1_01;
  int extraout_A1_02;
  
  uVar2 = (ushort)*(byte *)(in_A0 + 0x17 + (int)unaff_D3w);
  if (DAT_0001512a != '\0') {
    uVar2 = (ushort)(uVar2 * 0x70) >> 8;
  }
  if ((1 < in_D1b) && (DAT_0007f817 != 0xff)) {
    uVar2 = (ushort)(uVar2 * DAT_0007f817) >> 8;
  }
  *(char *)(in_A1 + 1) = (char)uVar2;
  FUN_00016672();
  bVar1 = *(byte *)(extraout_A0 + 0x18 + (int)unaff_D3w);
  bVar3 = bVar1 << 4 | bVar1 >> 4;
  if (DAT_0007f806 != '\0') {
    bVar3 = ((byte)((bVar1 & 0xf) + (bVar1 >> 4)) >> 1) * '\x11';
  }
  *(byte *)(extraout_A1 + 3) = bVar3;
  FUN_00016672();
  *(undefined1 *)(extraout_A1_00 + 7) = *(undefined1 *)(extraout_A0_00 + 0x1a + (int)unaff_D3w);
  FUN_00016672();
  *(undefined1 *)(extraout_A1_01 + 5) = *(undefined1 *)(extraout_A0_01 + 0x1b + (int)unaff_D3w);
  FUN_00016672();
  *(char *)(extraout_A1_02 + 0xd) = (char)(extraout_D1w << 6);
  FUN_00016672();
  return;
}



// ---- FUN_000154f8 @ 000154f8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_000154f8(void)

{
  ushort uVar1;
  undefined4 in_D0;
  uint uVar2;
  undefined4 in_D1;
  undefined4 unaff_D2;
  
  _DAT_00015120 = (short)in_D0;
  uVar2 = (uint)(ushort)(_DAT_00015120 << 3);
  DAT_0007f807 = *(undefined1 *)(uVar2 + 0x50000);
  DAT_0007f811 = *(char *)(uVar2 + 0x50001);
  DAT_0007f812 = DAT_0007f811;
  _DAT_0007f84c = _DAT_00015120;
  if (DAT_0007f811 == '\x01') {
    DAT_0007f808 = *(undefined1 *)(uVar2 + 0x50002);
    DAT_0007f809 = *(undefined1 *)(uVar2 + 0x50003);
    _DAT_0007f82c = *(ushort *)(uVar2 + 0x50004) + 0x17;
    _DAT_0007f830 = (uint)*(ushort *)(uVar2 + 0x50006);
    if (0x34 < *(ushort *)(uVar2 + 0x50006)) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    DAT_0007f80e = 0;
    _DAT_0007f824 = 0;
    _DAT_0007f828 = 0x65000;
    DAT_0007f80f = 2;
    DAT_0001511e = DAT_0001511e | 4;
  }
  else {
    if (DAT_0007f811 == '\x02') {
      DAT_0007f813 = DAT_0007f813 & 0xfd;
      DAT_0007f813 = DAT_0007f813 | 1;
      DAT_0007f814 = 0;
    }
    else if (DAT_0007f811 != -0x7e) goto LAB_0001566e;
    DAT_0001511e = DAT_0001511e & 0xf7;
    FUN_00015e24();
    FUN_00015e24();
    _DAT_00015120 = -1;
    DAT_0007f808 = *(undefined1 *)(uVar2 + 0x50002);
    DAT_0007f809 = *(undefined1 *)(uVar2 + 0x50003);
    _DAT_0007f82c = *(ushort *)(uVar2 + 0x50004) + 0x17;
    _DAT_0007f820 = *(ushort *)(uVar2 + 0x50004) + 0x37;
    uVar1 = *(ushort *)(uVar2 + 0x50006);
    _DAT_0007f830 = (uint)uVar1;
    if (uVar1 < 0x21) {
      DAT_0007f80e = 0;
      _DAT_0007f824 = 0;
    }
    else {
      _DAT_0007f830 = 0x20;
      _DAT_0007f824 = CONCAT22((short)((uint)unaff_D2 >> 0x10),uVar1 - 0x20);
    }
    _DAT_0007f828 = 0x65000;
    DAT_0007f80f = 1;
    DAT_0001511e = DAT_0001511e | 1;
  }
LAB_0001566e:
  return CONCAT44(in_D0,in_D1);
}



// ---- FUN_00015bb8 @ 00015bb8

void FUN_00015bb8(void)

{
  char unaff_D3b;
  
  if ((unaff_D3b == -0x80) || (unaff_D3b == -0x40)) {
    return;
  }
  if ((DAT_0007f811 == '\x02') || (DAT_0007f811 == -0x7e)) {
    FUN_00015cb8();
    return;
  }
  FUN_00015be2();
  return;
}



// ---- FUN_00015be2 @ 00015be2

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00015be2(void)

{
  byte bVar1;
  short sVar2;
  short unaff_D3w;
  ushort unaff_D5w;
  ushort uVar3;
  short sVar4;
  int in_A0;
  int extraout_A0;
  int extraout_A0_00;
  int extraout_A0_01;
  int iVar5;
  int in_A1;
  int extraout_A1;
  byte *unaff_A2;
  byte *pbVar6;
  ushort *puVar7;
  bool bVar8;
  
  *(ushort *)(in_A0 + 10 + (int)unaff_D3w) = unaff_D5w + 0x2000;
  sVar4 = 1;
  do {
    uVar3 = unaff_D5w;
    *(byte *)(in_A1 + 0xf) = (byte)(uVar3 >> 0xc) + 0x80;
    FUN_00016672();
    sVar2 = 0xfff;
    bVar8 = (uVar3 & 0x3000) == 0x3000;
    if (bVar8) {
      _DAT_00ff3ffe = 0xff;
      sVar2 = 0xffe;
    }
    puVar7 = (ushort *)&DAT_00ff2000;
    do {
      pbVar6 = unaff_A2;
      unaff_A2 = pbVar6 + 1;
      bVar1 = *pbVar6;
      *puVar7 = (ushort)bVar1;
      if (bVar1 == 0xff) {
        uVar3 = ((((ushort)(puVar7 + 1) & 0x1fff) >> 1) - 2) + uVar3;
        *(ushort *)(extraout_A0 + 0x12 + (int)unaff_D3w) = uVar3;
        if ((uVar3 & 0x3fff) < 0x2000) {
          *(byte *)(extraout_A0 + unaff_D3w) = *(byte *)(extraout_A0 + unaff_D3w) | 2;
          iVar5 = extraout_A0;
        }
        else {
          FUN_00015d8a();
          iVar5 = extraout_A0_00;
        }
        *(byte *)(iVar5 + unaff_D3w) = *(byte *)(iVar5 + unaff_D3w) | 1;
        return;
      }
      sVar2 = sVar2 + -1;
      puVar7 = puVar7 + 1;
    } while (sVar2 != -1);
    unaff_D5w = uVar3 + 0x1000;
    sVar4 = sVar4 + -1;
    in_A1 = extraout_A1;
  } while (sVar4 != -1);
  iVar5 = extraout_A0;
  if (bVar8) {
    unaff_D5w = uVar3 + 0xd000;
    unaff_A2 = pbVar6 + 2;
    FUN_00015d8a();
    iVar5 = extraout_A0_01;
  }
  if (unaff_A2 == (byte *)0x75000) {
    unaff_A2 = (byte *)0x65000;
  }
  *(byte **)(iVar5 + 2 + (int)unaff_D3w) = unaff_A2;
  *(ushort *)(iVar5 + 10 + (int)unaff_D3w) = unaff_D5w;
  *(ushort *)(iVar5 + 0x12 + (int)unaff_D3w) = unaff_D5w;
  DAT_0007f847 = DAT_0007f847 + '\x01';
  return;
}



// ---- FUN_00015cb8 @ 00015cb8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00015cb8(void)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  short unaff_D3w;
  short unaff_D5w;
  short sVar4;
  int in_A0;
  int extraout_A0;
  int extraout_A0_00;
  int extraout_A0_01;
  int iVar5;
  int in_A1;
  int extraout_A1;
  byte *unaff_A2;
  byte *pbVar6;
  ushort *puVar7;
  bool bVar8;
  
  *(short *)(in_A0 + 10 + (int)unaff_D3w) = unaff_D5w + 0x2000;
  sVar4 = 1;
  do {
    *(byte *)(in_A1 + 0xf) = (byte)((ushort)unaff_D5w >> 0xc) + 0x80;
    FUN_00016672();
    sVar3 = 0xfff;
    bVar8 = unaff_D5w == 0x7000;
    if (bVar8) {
      _DAT_00ff3ffe = 0xff;
      sVar3 = 0xffe;
    }
    puVar7 = (ushort *)&DAT_00ff2000;
    do {
      pbVar6 = unaff_A2;
      unaff_A2 = pbVar6 + 1;
      bVar1 = *pbVar6;
      *puVar7 = (ushort)bVar1;
      if (bVar1 == 0xff) {
        uVar2 = ((((ushort)(puVar7 + 1) & 0x1fff) >> 1) - 2) + unaff_D5w;
        *(ushort *)(extraout_A0 + 0x12 + (int)unaff_D3w) = uVar2;
        if ((uVar2 & 0x7fff) < 0x2000) {
          *(byte *)(extraout_A0 + unaff_D3w) = *(byte *)(extraout_A0 + unaff_D3w) | 2;
          iVar5 = extraout_A0;
        }
        else {
          FUN_00015d8a();
          iVar5 = extraout_A0_00;
        }
        *(byte *)(iVar5 + unaff_D3w) = *(byte *)(iVar5 + unaff_D3w) | 1;
        return;
      }
      sVar3 = sVar3 + -1;
      puVar7 = puVar7 + 1;
    } while (sVar3 != -1);
    unaff_D5w = unaff_D5w + 0x1000;
    sVar4 = sVar4 + -1;
    in_A1 = extraout_A1;
  } while (sVar4 != -1);
  iVar5 = extraout_A0;
  if (bVar8) {
    unaff_A2 = pbVar6 + 2;
    unaff_D5w = 0;
    FUN_00015d8a();
    iVar5 = extraout_A0_01;
  }
  if (unaff_A2 == (byte *)0x75000) {
    unaff_A2 = (byte *)0x65000;
  }
  *(byte **)(iVar5 + 2 + (int)unaff_D3w) = unaff_A2;
  *(short *)(iVar5 + 10 + (int)unaff_D3w) = unaff_D5w;
  *(short *)(iVar5 + 0x12 + (int)unaff_D3w) = unaff_D5w;
  DAT_0007f847 = DAT_0007f847 + '\x01';
  return;
}



// ---- FUN_00015d8a @ 00015d8a

void FUN_00015d8a(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  char extraout_D1b;
  undefined4 unaff_D6;
  int extraout_A1;
  int extraout_A1_00;
  int extraout_A1_01;
  int extraout_A1_02;
  int extraout_A1_03;
  int extraout_A1_04;
  int extraout_A1_05;
  int extraout_A1_06;
  
  FUN_00015458();
  uVar2 = (undefined1)((uint)unaff_D6 >> 8);
  *(undefined1 *)(extraout_A1 + 0xb) = uVar2;
  FUN_00016672();
  uVar1 = (undefined1)unaff_D6;
  *(undefined1 *)(extraout_A1_00 + 9) = uVar1;
  FUN_00016672();
  FUN_00015458();
  *(undefined1 *)(extraout_A1_01 + 0xb) = uVar2;
  FUN_00016672();
  *(undefined1 *)(extraout_A1_02 + 9) = uVar1;
  FUN_00016672();
  if ((extraout_D1b == '\0') && ((DAT_0007f812 & 3) == 2)) {
    FUN_00015458();
    *(undefined1 *)(extraout_A1_03 + 0xb) = uVar2;
    FUN_00016672();
    *(undefined1 *)(extraout_A1_04 + 9) = uVar1;
    FUN_00016672();
    FUN_00015458();
    *(undefined1 *)(extraout_A1_05 + 0xb) = uVar2;
    FUN_00016672();
    *(undefined1 *)(extraout_A1_06 + 9) = uVar1;
    FUN_00016672();
  }
  return;
}



// ---- FUN_00015e24 @ 00015e24

void FUN_00015e24(void)

{
  short in_D1w;
  short unaff_D3w;
  int in_A0;
  
  *(undefined1 *)(in_A0 + 0x14 + (int)unaff_D3w) = 0;
  *(byte *)(in_A0 + unaff_D3w) = *(byte *)(in_A0 + unaff_D3w) & 0xfe;
  DAT_0007f802 = DAT_0007f802 | '\x01' << ((ushort)(in_D1w * 2) & 7);
  DAT_0007f802 = DAT_0007f802 | '\x01' << ((byte)((char)(in_D1w * 2) + 1) & 7);
  FUN_00015e90();
  return;
}



// ---- FUN_00015e50 @ 00015e50

void FUN_00015e50(void)

{
  short in_D1w;
  short unaff_D3w;
  int in_A0;
  
  *(undefined1 *)(in_A0 + 0x14 + (int)unaff_D3w) = 0;
  *(byte *)(in_A0 + unaff_D3w) = *(byte *)(in_A0 + unaff_D3w) & 0xfe;
  DAT_0007f802 = DAT_0007f802 | '\x01' << ((ushort)(in_D1w * 2) & 7);
  DAT_0007f802 = DAT_0007f802 | '\x01' << ((byte)((char)(in_D1w * 2) + 1) & 7);
  if ((char)in_D1w == '\0') {
    DAT_0007f802 = DAT_0007f802 | 0xc;
  }
  FUN_00015e90();
  return;
}



// ---- FUN_00015e90 @ 00015e90

void FUN_00015e90(void)

{
  if (DAT_0007f802 != DAT_0007f803) {
    DAT_0007f803 = DAT_0007f802;
    DAT_00ff0011 = DAT_0007f802;
    FUN_00016672();
  }
  return;
}



// ---- FUN_00015eb4 @ 00015eb4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00015eb4(void)

{
  byte in_D0b;
  char in_D1b;
  
  if (in_D0b != 0) {
    if (in_D0b == 0xff) {
      DAT_0007f815 = 1;
    }
    else {
      _DAT_0007f848 = (ushort)in_D0b;
      if ((in_D0b < 0xf1) && (in_D1b != '\0')) {
        DAT_0007f815 = 0;
        DAT_0007f817 = 0xff;
      }
      *(byte *)((short)(ushort)DAT_0007f87f + 0x7f880) = in_D0b;
      DAT_0007f87f = DAT_0007f87f + 1;
      if (DAT_0007f87f == 0x80) {
        DAT_0007f87f = 0;
      }
    }
  }
  return;
}



// ---- FUN_00016128 @ 00016128

void FUN_00016128(void)

{
  short sVar1;
  char cVar3;
  ushort uVar2;
  uint uVar4;
  short sVar5;
  int iVar6;
  int extraout_A1;
  byte *pbVar7;
  byte *pbVar8;
  ushort *puVar9;
  
  iVar6 = 0xff0000;
  uVar4 = 0x8000;
  uVar2 = 1;
  while ((((cVar3 = (char)uVar2, cVar3 == '\x06' || (cVar3 == '\b')) || (cVar3 == '\t')) ||
         (cVar3 == '\n'))) {
LAB_000161e4:
    uVar2 = (ushort)(byte)(cVar3 + 1U);
    if ((byte)(cVar3 + 1U) == 0xd) {
      return;
    }
  }
  pbVar7 = (byte *)(*(int *)((ushort)(uVar2 << 4) + 0x54006) + 0x10);
  *(uint *)((short)(uVar2 << 3) + 0x7fa40) = uVar4;
  do {
    *(char *)(iVar6 + 0xf) = (char)(((ushort)(uVar4 >> 8) & 0xff) >> 4) + -0x80;
    FUN_00016672();
    sVar1 = (short)(uVar4 & 0xffff0fff);
    sVar5 = 0xfff - sVar1;
    pbVar8 = pbVar7;
    puVar9 = (ushort *)(&DAT_00ff2000 + CONCAT22((short)((uVar4 & 0xffff0fff) >> 0x10),sVar1 * 2));
    do {
      pbVar7 = pbVar8 + 1;
      iVar6 = extraout_A1;
      if (*pbVar8 == 0xff) {
        *puVar9 = 0x80;
        *(uint *)((short)(uVar2 << 3) + 0x7fa44) = uVar4;
        puVar9[1] = 0xff;
        puVar9[2] = 0xff;
        puVar9[3] = 0xff;
        uVar4 = uVar4 + 4;
        if ((char)uVar4 != '\0') {
          uVar4 = CONCAT22((short)(uVar4 >> 0x10),(short)uVar4 + 0xff) & 0xffffff00;
        }
        goto LAB_000161e4;
      }
      *puVar9 = (ushort)*pbVar8;
      uVar4 = uVar4 + 1;
      sVar5 = sVar5 + -1;
      pbVar8 = pbVar7;
      puVar9 = puVar9 + 1;
    } while (sVar5 != -1);
  } while( true );
}



// ---- FUN_000162e0 @ 000162e0

void FUN_000162e0(void)

{
  undefined2 in_D0w;
  
                    /* WARNING: Could not recover jumptable at 0x000162f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)((int)&PTR_LAB_000162fc +
              (int)(short)(CONCAT11((char)((ushort)in_D0w >> 8),(char)in_D0w + '\b') << 2)))();
  return;
}



// ---- FUN_00016330 @ 00016330

void FUN_00016330(void)

{
  DAT_00ff0011 = 0xff;
  FUN_00016672();
  DAT_0007f802 = 0xff;
  DAT_0007f803 = 0xff;
  DAT_0001511e = DAT_0001511e & 0xf7;
  return;
}



// ---- FUN_00016364 @ 00016364

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00016364(void)

{
  char extraout_var;
  char extraout_var_00;
  char extraout_D1b;
  char extraout_D1b_00;
  short sVar1;
  undefined1 *extraout_A0;
  bool bVar2;
  
  if (DAT_0007f80f != '\0') {
    _DAT_0007fa08 = 0;
    func_0x00005f22();
    DAT_0007f844 = DAT_0007f844 + '\x01';
LAB_00016384:
    DAT_0007f845 = DAT_0007f845 + '\x01';
    _DAT_0007fa08 = _DAT_0007fa08 + 1;
    if (_DAT_0007fa08 != 4) {
      func_0x00005f22();
      sVar1 = 600;
      do {
        func_0x00005f10();
        while( true ) {
          bVar2 = false;
          func_0x00005f22();
          if ((bVar2) && (sVar1 = sVar1 + -1, sVar1 != -1)) break;
          if (bVar2) {
            DAT_0007f840 = DAT_0007f840 + '\x01';
            goto LAB_00016384;
          }
          if (DAT_0007f84f == '\0') {
            DAT_00ff8004 = 5;
            _DAT_00ff800a = (undefined2)(_DAT_0007f828 >> 3);
            bVar2 = false;
            func_0x00005f22();
            if (bVar2) {
              DAT_0007f841 = DAT_0007f841 + '\x01';
              goto LAB_00016384;
            }
            FUN_000165ca();
            if (extraout_D1b_00 != extraout_var_00) goto LAB_00016384;
            sVar1 = 0x600;
            do {
              bVar2 = (DAT_00ff8004 & 0x80) != 0;
              if (bVar2) break;
              sVar1 = sVar1 + -1;
            } while (sVar1 != -1);
            if (!bVar2) {
              DAT_0007f842 = DAT_0007f842 + '\x01';
              goto LAB_00016384;
            }
          }
          else {
            DAT_00ff8004 = 3;
            bVar2 = false;
            func_0x00005f22();
            if (bVar2) {
              DAT_0007f81c = DAT_0007f81c + '\x01';
              goto LAB_00016384;
            }
            FUN_000165ca();
            if (extraout_D1b != extraout_var) goto LAB_00016384;
            bVar2 = false;
            func_0x00005f22();
            if (bVar2) {
              DAT_0007f81d = DAT_0007f81d + '\x01';
              goto LAB_00016384;
            }
          }
          _DAT_0007f828 = _DAT_0007f828 + 0x800;
          if ((DAT_0007f80f == '\x01') && (_DAT_0007f828 == 0x75000)) {
            _DAT_0007f828 = 0x65000;
          }
          func_0x00005f22();
          sVar1 = 6;
          DAT_0007f846 = DAT_0007f846 + '\x01';
          _DAT_0007f82c = _DAT_0007f82c + 1;
          _DAT_0007f830 = _DAT_0007f830 + -1;
          if (_DAT_0007f830 == 0) {
            func_0x00005f22();
            if (_DAT_0007f824 != 0) {
              DAT_0007f80e = 1;
            }
            if (DAT_0007f80f == '\x02') {
              DAT_0001511e = DAT_0001511e & 0xfb;
            }
            DAT_0007f80c = 0;
            DAT_0007f80d = 0;
            DAT_0007f80f = 0;
            return;
          }
        }
      } while( true );
    }
    _DAT_0007f82c = 0x16;
    _DAT_0007f830 = 1;
    func_0x00005f22();
    func_0x00005f22();
    DAT_0007f80d = 1;
    DAT_0007f80c = 1;
    DAT_0007f811 = 0;
    DAT_0007f80f = '\0';
    DAT_0007f81b = 0;
    _DAT_0007f800 = 0;
    FUN_00015e50();
    *extraout_A0 = 0;
    DAT_0001511e = DAT_0001511e & 0xf8;
    DAT_0007f80c = 0;
    DAT_0007f80d = 0;
  }
  return;
}



// ---- FUN_000165ca @ 000165ca

void FUN_000165ca(void)

{
  return;
}



// ---- FUN_0001661a @ 0001661a

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0001661a(void)

{
  undefined4 in_D0;
  short sVar1;
  undefined4 in_D1;
  undefined4 *puVar2;
  
  sVar1 = 0x1ff;
  puVar2 = (undefined4 *)&DAT_0007f800;
  do {
    *puVar2 = 0;
    sVar1 = sVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (sVar1 != -1);
  DAT_0007f802 = 0xff;
  DAT_0007f803 = 0xff;
  DAT_0007f817 = 0xff;
  DAT_0007f819 = 0xff;
  _DAT_0001511e = 0;
  _DAT_00015120 = 0xffff;
  _DAT_0001512a = 0;
  DAT_0007fa07 = 4;
  return CONCAT44(in_D0,in_D1);
}



// ---- FUN_00016672 @ 00016672

void FUN_00016672(void)

{
  short sVar1;
  
  sVar1 = 0x28;
  do {
    sVar1 = sVar1 + -1;
  } while (sVar1 != -1);
  return;
}



// ---- FUN_00016682 @ 00016682

void FUN_00016682(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  undefined2 *puVar4;
  int in_A1;
  int extraout_A1;
  
  sVar1 = 0;
  sVar2 = 0xf;
  do {
    *(byte *)(in_A1 + 0xf) = (byte)((ushort)sVar1 >> 0xc) + 0x80;
    FUN_00016672();
    sVar3 = 0xfff;
    puVar4 = (undefined2 *)&DAT_00ff2000;
    do {
      *puVar4 = 0;
      sVar3 = sVar3 + -1;
      puVar4 = puVar4 + 1;
    } while (sVar3 != -1);
    sVar1 = sVar1 + 0x1000;
    sVar2 = sVar2 + -1;
    in_A1 = extraout_A1;
  } while (sVar2 != -1);
  return;
}


