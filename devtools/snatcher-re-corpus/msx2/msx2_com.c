// Ghidra decompilation of msx2_com.bin (z80:LE:16:default)

// ---- entry @ ram:0100

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(undefined2 param_1)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  code *pcVar5;
  byte bVar7;
  short sVar6;
  char *pcVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  char *pcVar11;
  code **ppcVar12;
  code *pcStack_2;
  
  uVar4 = CONCAT11((char)((ushort)param_1 >> 8),9);
  pcStack_2 = (code *)0x108;
  func_0xf37d(uVar4,s_To_play_on_harddisk__this_game_n_ram_0343 + 0x278);
  bVar2 = (byte)((ushort)uVar4 >> 8);
  pcStack_2 = (code *)0x10e;
  cVar1 = func_0xf37d(0);
  if ((cVar1 == '\0') && (1 < bVar2)) {
    s_To_play_on_harddisk__this_game_n_ram_0343[0x2c4] = DAT_ram_f2cf + -2;
  }
  else {
    pcStack_2 = (code *)0x128;
    bVar2 = DAT_ram_f342;
    s_To_play_on_harddisk__this_game_n_ram_0343[0x2c4] = FUN_ram_0c96(0);
  }
  pcVar5 = (code *)CONCAT11(bVar2,0x11);
  pcStack_2 = (code *)0x133;
  cVar1 = func_0xf37d(pcVar5,0x2ec);
  ppcVar12 = (code **)register0x44;
  if (cVar1 == '\0') {
    pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0x17f;
    if (6 < (byte)s_To_play_on_harddisk__this_game_n_ram_0343[0x2c4]) {
      pcStack_2 = FUN_ram_0608 + 6;
      DAT_ram_0ab9 = FUN_ram_0a9e(6,s_To_play_on_harddisk__this_game_n_ram_0343 + 0x17f);
      pcStack_2 = (code *)0x617;
      DAT_ram_0aba = FUN_ram_0a9e(7);
      pcStack_2 = (code *)0x620;
      cVar1 = FUN_ram_0a9e(0x2d);
      enableMaskableInterrupts();
      pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0x23d;
      if (cVar1 != '\0') {
        if (cVar1 == '\x03') {
          pcStack_2 = (code *)0x636;
          FUN_ram_0aa9(0x82,0x180);
        }
        else {
          pcStack_2 = FUN_ram_063b;
          FUN_ram_0a59(s_To_play_on_harddisk__this_game_n_ram_0343 + 0x23d);
        }
        pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343 + 600;
        if (1 < (DAT_ram_fafc & 6) >> 1) {
          pcStack_2 = (code *)0x64c;
          FUN_ram_0967();
          pcStack_2 = (code *)0x64f;
          FUN_ram_0854();
          pcStack_2 = (code *)0x65a;
          FUN_ram_086c(1,0x95c,0);
          pcStack_2 = (code *)0x662;
          FUN_ram_0aa9(0,0x135);
          pcStack_2 = (code *)0x66b;
          FUN_ram_026b(CONCAT11(8,s_To_play_on_harddisk__this_game_n_ram_0343[0x2c4]));
          pcStack_2 = FUN_ram_066e;
          FUN_ram_06f3();
          while( true ) {
            pcStack_2 = FUN_ram_066e + 7;
            cVar1 = FUN_ram_0aa9(0x9f);
            if (((cVar1 == '0') || (cVar1 == ' ')) || (cVar1 == '\r')) break;
            if (cVar1 == '1') {
              pcStack_2 = (code *)0x689;
              FUN_ram_068b();
            }
          }
          pcStack_2 = FUN_ram_0698 + 3;
          FUN_ram_0714();
          while( true ) {
            uVar3 = 0;
            pcStack_2 = (code *)0x6c0;
            FUN_ram_09db(2,0x7d2,200);
            pcStack_2 = (code *)0x6c8;
            func_0xf37d(CONCAT11(uVar3,0x1a),0xc000);
            pcStack_2 = (code *)0x6d4;
            func_0xf37d(0x2f,0x100,0);
            if (((DAT_ram_c003 == '\0') && (DAT_ram_c004 == '\x01')) && (DAT_ram_c005 == '\0'))
            break;
            do {
              pcStack_2 = (code *)0x6a9;
              FUN_ram_09db(2,0x813,200);
              pcStack_2 = (code *)0x6b0;
              cVar1 = FUN_ram_0aa9(0x9f);
            } while (cVar1 == '\0');
          }
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
      }
    }
  }
  else {
    bVar7 = (byte)((ushort)pcVar5 >> 8);
    pcStack_2 = FUN_ram_0144 + 6;
    bVar2 = func_0xf37d(0);
    pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343;
    if ((bVar2 != 0) || (bVar2 = bVar7, bVar7 < 2)) goto RST0;
    pcStack_2 = (code *)0x160;
    FUN_ram_026b(CONCAT11(9,s_To_play_on_harddisk__this_game_n_ram_0343[0x2c4]),
                 s_To_play_on_harddisk__this_game_n_ram_0343);
    pcStack_2 = (code *)0x168;
    cVar1 = func_0xf37d(0xf,0xbf5);
    if (cVar1 != '\0') {
      pcStack_2 = (code *)0x16c;
      FUN_ram_0abc(cVar1);
    }
    disableMaskableInterrupts();
    puVar9 = &DAT_ram_4000;
    puVar10 = (undefined1 *)0x0;
    sVar6 = 0x100;
    do {
      *puVar9 = *puVar10;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
      sVar6 = sVar6 + -1;
    } while (sVar6 != 0);
    enableMaskableInterrupts();
    puVar10 = (undefined1 *)0x4100;
    puVar9 = (undefined1 *)0x4101;
    sVar6 = 0x2b00;
    uRam4100 = 0xc9;
    do {
      *puVar9 = *puVar10;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
      sVar6 = sVar6 + -1;
    } while (sVar6 != 0);
    puVar10 = (undefined1 *)0xd77;
    puVar9 = (undefined1 *)0x6c00;
    sVar6 = 0x181;
    do {
      *puVar9 = *puVar10;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
      sVar6 = sVar6 + -1;
    } while (sVar6 != 0);
    bIo00fd = 2;
    uVar3 = 0x1a;
    pcStack_2 = (code *)0x1a1;
    func_0xf37d(0xc000);
    pcStack_2 = (code *)CONCAT11(3,uVar3);
    do {
      s_SNATCHER000_ram_02ed[10] = (char)((ushort)pcStack_2 >> 8) + '0';
      pcVar5 = (code *)0x310f;
      s_To_play_on_harddisk__this_game_n_ram_0343[0xa1] = s_SNATCHER000_ram_02ed[10];
      s_To_play_on_harddisk__this_game_n_ram_0343[0xd1] = s_SNATCHER000_ram_02ed[10];
      s_To_play_on_harddisk__this_game_n_ram_0343[0x105] = s_SNATCHER000_ram_02ed[10];
      cVar1 = func_0xf37d(0x310f,0x2ec);
      pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0x86;
      ppcVar12 = &pcStack_2;
      if (cVar1 != '\0') goto FUN_ram_0336;
      s_SNATCHER000_ram_02ed[0xd] = '\0';
      s_SNATCHER000_ram_02ed[0xe] = '\x02';
      _DAT_ram_030d = (char *)0x0;
      _DAT_ram_030f = 0;
      pcVar5 = (code *)CONCAT11((char)((ushort)pcVar5 >> 8),0x27);
      cVar1 = func_0xf37d(0,pcVar5,1,0x2ec);
      pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0xb6;
      ppcVar12 = &pcStack_2;
      if (cVar1 != '\0') goto FUN_ram_0336;
      cVar1 = (char)((ushort)pcStack_2 >> 8);
      pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0xea;
      pcVar5 = pcStack_2;
      ppcVar12 = (code **)register0x44;
      if ((char)(DAT_ram_c01d + '\x01') != cVar1) goto FUN_ram_0336;
      cVar1 = cVar1 + -1;
      pcStack_2 = (code *)CONCAT11(cVar1,(char)pcStack_2);
    } while (cVar1 != '\0');
    uVar3 = 0;
    pcStack_2 = (code *)0x1fb;
    func_0xf37d(0x1a,0xbe00);
    s_SNATCHER000_ram_02ed[0xd] = '\0';
    s_SNATCHER000_ram_02ed[0xe] = '\x02';
    _DAT_ram_030d = s_To_play_on_harddisk__this_game_n_ram_0343 + 0xc9;
    _DAT_ram_030f = 0;
    uVar4 = CONCAT11(uVar3,0x27);
    pcStack_2 = (code *)0x218;
    func_0xf37d(uVar4,1,0x2ec);
    uVar4 = CONCAT11((char)((ushort)uVar4 >> 8),0x1a);
    pcStack_2 = (code *)0x220;
    func_0xf37d(uVar4,0x8000);
    s_SNATCHER000_ram_02ed[0xd] = '\0';
    s_SNATCHER000_ram_02ed[0xe] = '\x02';
    _DAT_ram_030d = (char *)0x3f8;
    _DAT_ram_030f = 0;
    pcVar5 = (code *)CONCAT11((char)((ushort)uVar4 >> 8),0x27);
    pcStack_2 = (code *)0x23d;
    cVar1 = func_0xf37d(pcVar5,0x20,0x2ec);
    pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0x119;
    if (cVar1 == '\0') {
      pcStack_2 = (code *)0x24c;
      func_0xf37d(0,0x10,0x2ec);
      pcVar8 = &LAB_ram_8100;
      do {
        while (pcVar11 = pcVar8, *pcVar11 != '!') {
          pcVar8 = pcVar11 + 1;
        }
        pcVar8 = pcVar11 + 1;
      } while ((pcVar11[1] != '4') || (pcVar8 = pcVar11 + 2, pcVar11[2] != -0x40));
      pcVar11[1] = '7';
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
FUN_ram_0336:
  bVar7 = (byte)((ushort)pcVar5 >> 8);
  bIo00fd = DAT_ram_f2c8;
  bVar2 = DAT_ram_f2c8;
  register0x44 = (BADSPACEBASE *)ppcVar12;
RST0:
  *(undefined2 *)((short)register0x44 + -2) = 0x340;
  func_0xf37d(bVar2,CONCAT11(bVar7,9),pcVar8);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ---- FUN_ram_0120 @ ram:0120

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_ram_0120(void)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar6;
  code *pcVar3;
  byte bVar7;
  short sVar4;
  undefined2 uVar5;
  char *pcVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  char *pcVar11;
  code **ppcVar12;
  code *pcStack_2;
  
  pcStack_2 = (code *)0x128;
  uVar6 = DAT_ram_f342;
  s_To_play_on_harddisk__this_game_n_ram_0343[0x2c4] = FUN_ram_0c96(0);
  pcVar3 = (code *)CONCAT11(uVar6,0x11);
  pcStack_2 = (code *)0x133;
  cVar1 = func_0xf37d(pcVar3,0x2ec);
  ppcVar12 = (code **)register0x44;
  if (cVar1 == '\0') {
    pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0x17f;
    if (6 < (byte)s_To_play_on_harddisk__this_game_n_ram_0343[0x2c4]) {
      pcStack_2 = FUN_ram_0608 + 6;
      DAT_ram_0ab9 = FUN_ram_0a9e(6,s_To_play_on_harddisk__this_game_n_ram_0343 + 0x17f);
      pcStack_2 = (code *)0x617;
      DAT_ram_0aba = FUN_ram_0a9e(7);
      pcStack_2 = (code *)0x620;
      cVar1 = FUN_ram_0a9e(0x2d);
      enableMaskableInterrupts();
      pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0x23d;
      if (cVar1 != '\0') {
        if (cVar1 == '\x03') {
          pcStack_2 = (code *)0x636;
          FUN_ram_0aa9(0x82,0x180);
        }
        else {
          pcStack_2 = FUN_ram_063b;
          FUN_ram_0a59(s_To_play_on_harddisk__this_game_n_ram_0343 + 0x23d);
        }
        pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343 + 600;
        if (1 < (DAT_ram_fafc & 6) >> 1) {
          pcStack_2 = (code *)0x64c;
          FUN_ram_0967();
          pcStack_2 = (code *)0x64f;
          FUN_ram_0854();
          pcStack_2 = (code *)0x65a;
          FUN_ram_086c(1,0x95c,0);
          pcStack_2 = (code *)0x662;
          FUN_ram_0aa9(0,0x135);
          pcStack_2 = (code *)0x66b;
          FUN_ram_026b(CONCAT11(8,s_To_play_on_harddisk__this_game_n_ram_0343[0x2c4]));
          pcStack_2 = FUN_ram_066e;
          FUN_ram_06f3();
          while( true ) {
            pcStack_2 = FUN_ram_066e + 7;
            cVar1 = FUN_ram_0aa9(0x9f);
            if (((cVar1 == '0') || (cVar1 == ' ')) || (cVar1 == '\r')) break;
            if (cVar1 == '1') {
              pcStack_2 = (code *)0x689;
              FUN_ram_068b();
            }
          }
          pcStack_2 = FUN_ram_0698 + 3;
          FUN_ram_0714();
          while( true ) {
            uVar6 = 0;
            pcStack_2 = (code *)0x6c0;
            FUN_ram_09db(2,0x7d2,200);
            pcStack_2 = (code *)0x6c8;
            func_0xf37d(CONCAT11(uVar6,0x1a),0xc000);
            pcStack_2 = (code *)0x6d4;
            func_0xf37d(0x2f,0x100,0);
            if (((DAT_ram_c003 == '\0') && (DAT_ram_c004 == '\x01')) && (DAT_ram_c005 == '\0'))
            break;
            do {
              pcStack_2 = (code *)0x6a9;
              FUN_ram_09db(2,0x813,200);
              pcStack_2 = (code *)0x6b0;
              cVar1 = FUN_ram_0aa9(0x9f);
            } while (cVar1 == '\0');
          }
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
      }
    }
  }
  else {
    bVar7 = (byte)((ushort)pcVar3 >> 8);
    pcStack_2 = FUN_ram_0144 + 6;
    bVar2 = func_0xf37d(0);
    pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343;
    if ((bVar2 != 0) || (bVar2 = bVar7, bVar7 < 2)) goto RST0;
    pcStack_2 = (code *)0x160;
    FUN_ram_026b(CONCAT11(9,s_To_play_on_harddisk__this_game_n_ram_0343[0x2c4]),
                 s_To_play_on_harddisk__this_game_n_ram_0343);
    pcStack_2 = (code *)0x168;
    cVar1 = func_0xf37d(0xf,0xbf5);
    if (cVar1 != '\0') {
      pcStack_2 = (code *)0x16c;
      FUN_ram_0abc(cVar1);
    }
    disableMaskableInterrupts();
    puVar9 = &DAT_ram_4000;
    puVar10 = (undefined1 *)0x0;
    sVar4 = 0x100;
    do {
      *puVar9 = *puVar10;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
      sVar4 = sVar4 + -1;
    } while (sVar4 != 0);
    enableMaskableInterrupts();
    puVar10 = (undefined1 *)0x4100;
    puVar9 = (undefined1 *)0x4101;
    sVar4 = 0x2b00;
    uRam4100 = 0xc9;
    do {
      *puVar9 = *puVar10;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
      sVar4 = sVar4 + -1;
    } while (sVar4 != 0);
    puVar10 = (undefined1 *)0xd77;
    puVar9 = (undefined1 *)0x6c00;
    sVar4 = 0x181;
    do {
      *puVar9 = *puVar10;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
      sVar4 = sVar4 + -1;
    } while (sVar4 != 0);
    bIo00fd = 2;
    uVar6 = 0x1a;
    pcStack_2 = (code *)0x1a1;
    func_0xf37d(0xc000);
    pcStack_2 = (code *)CONCAT11(3,uVar6);
    do {
      s_SNATCHER000_ram_02ed[10] = (char)((ushort)pcStack_2 >> 8) + '0';
      pcVar3 = (code *)0x310f;
      s_To_play_on_harddisk__this_game_n_ram_0343[0xa1] = s_SNATCHER000_ram_02ed[10];
      s_To_play_on_harddisk__this_game_n_ram_0343[0xd1] = s_SNATCHER000_ram_02ed[10];
      s_To_play_on_harddisk__this_game_n_ram_0343[0x105] = s_SNATCHER000_ram_02ed[10];
      cVar1 = func_0xf37d(0x310f,0x2ec);
      pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0x86;
      ppcVar12 = &pcStack_2;
      if (cVar1 != '\0') goto FUN_ram_0336;
      s_SNATCHER000_ram_02ed[0xd] = '\0';
      s_SNATCHER000_ram_02ed[0xe] = '\x02';
      _DAT_ram_030d = (char *)0x0;
      _DAT_ram_030f = 0;
      pcVar3 = (code *)CONCAT11((char)((ushort)pcVar3 >> 8),0x27);
      cVar1 = func_0xf37d(0,pcVar3,1,0x2ec);
      pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0xb6;
      ppcVar12 = &pcStack_2;
      if (cVar1 != '\0') goto FUN_ram_0336;
      cVar1 = (char)((ushort)pcStack_2 >> 8);
      pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0xea;
      pcVar3 = pcStack_2;
      ppcVar12 = (code **)register0x44;
      if ((char)(DAT_ram_c01d + '\x01') != cVar1) goto FUN_ram_0336;
      cVar1 = cVar1 + -1;
      pcStack_2 = (code *)CONCAT11(cVar1,(char)pcStack_2);
    } while (cVar1 != '\0');
    uVar6 = 0;
    pcStack_2 = (code *)0x1fb;
    func_0xf37d(0x1a,0xbe00);
    s_SNATCHER000_ram_02ed[0xd] = '\0';
    s_SNATCHER000_ram_02ed[0xe] = '\x02';
    _DAT_ram_030d = s_To_play_on_harddisk__this_game_n_ram_0343 + 0xc9;
    _DAT_ram_030f = 0;
    uVar5 = CONCAT11(uVar6,0x27);
    pcStack_2 = (code *)0x218;
    func_0xf37d(uVar5,1,0x2ec);
    uVar5 = CONCAT11((char)((ushort)uVar5 >> 8),0x1a);
    pcStack_2 = (code *)0x220;
    func_0xf37d(uVar5,0x8000);
    s_SNATCHER000_ram_02ed[0xd] = '\0';
    s_SNATCHER000_ram_02ed[0xe] = '\x02';
    _DAT_ram_030d = (char *)0x3f8;
    _DAT_ram_030f = 0;
    pcVar3 = (code *)CONCAT11((char)((ushort)uVar5 >> 8),0x27);
    pcStack_2 = (code *)0x23d;
    cVar1 = func_0xf37d(pcVar3,0x20,0x2ec);
    pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0x119;
    if (cVar1 == '\0') {
      pcStack_2 = (code *)0x24c;
      func_0xf37d(0,0x10,0x2ec);
      pcVar8 = &LAB_ram_8100;
      do {
        while (pcVar11 = pcVar8, *pcVar11 != '!') {
          pcVar8 = pcVar11 + 1;
        }
        pcVar8 = pcVar11 + 1;
      } while ((pcVar11[1] != '4') || (pcVar8 = pcVar11 + 2, pcVar11[2] != -0x40));
      pcVar11[1] = '7';
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
FUN_ram_0336:
  bVar7 = (byte)((ushort)pcVar3 >> 8);
  bIo00fd = DAT_ram_f2c8;
  bVar2 = DAT_ram_f2c8;
  register0x44 = (BADSPACEBASE *)ppcVar12;
RST0:
  *(undefined2 *)((short)register0x44 + -2) = 0x340;
  func_0xf37d(bVar2,CONCAT11(bVar7,9),pcVar8);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ---- FUN_ram_012b @ ram:012b

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_ram_012b(undefined2 param_1)

{
  char cVar1;
  byte bVar2;
  undefined1 uVar3;
  code *pcVar4;
  byte bVar7;
  short sVar5;
  undefined2 uVar6;
  char *pcVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  char *pcVar11;
  code **ppcVar12;
  code *pcStack_2;
  
  pcVar4 = (code *)CONCAT11((char)((ushort)param_1 >> 8),0x11);
  pcStack_2 = (code *)0x133;
  cVar1 = func_0xf37d(pcVar4,0x2ec);
  ppcVar12 = (code **)register0x44;
  if (cVar1 == '\0') {
    pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0x17f;
    if (6 < (byte)s_To_play_on_harddisk__this_game_n_ram_0343[0x2c4]) {
      pcStack_2 = FUN_ram_0608 + 6;
      DAT_ram_0ab9 = FUN_ram_0a9e(6,s_To_play_on_harddisk__this_game_n_ram_0343 + 0x17f);
      pcStack_2 = (code *)0x617;
      DAT_ram_0aba = FUN_ram_0a9e(7);
      pcStack_2 = (code *)0x620;
      cVar1 = FUN_ram_0a9e(0x2d);
      enableMaskableInterrupts();
      pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0x23d;
      if (cVar1 != '\0') {
        if (cVar1 == '\x03') {
          pcStack_2 = (code *)0x636;
          FUN_ram_0aa9(0x82,0x180);
        }
        else {
          pcStack_2 = FUN_ram_063b;
          FUN_ram_0a59(s_To_play_on_harddisk__this_game_n_ram_0343 + 0x23d);
        }
        pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343 + 600;
        if (1 < (DAT_ram_fafc & 6) >> 1) {
          pcStack_2 = (code *)0x64c;
          FUN_ram_0967();
          pcStack_2 = (code *)0x64f;
          FUN_ram_0854();
          pcStack_2 = (code *)0x65a;
          FUN_ram_086c(1,0x95c,0);
          pcStack_2 = (code *)0x662;
          FUN_ram_0aa9(0,0x135);
          pcStack_2 = (code *)0x66b;
          FUN_ram_026b(CONCAT11(8,s_To_play_on_harddisk__this_game_n_ram_0343[0x2c4]));
          pcStack_2 = FUN_ram_066e;
          FUN_ram_06f3();
          while( true ) {
            pcStack_2 = FUN_ram_066e + 7;
            cVar1 = FUN_ram_0aa9(0x9f);
            if (((cVar1 == '0') || (cVar1 == ' ')) || (cVar1 == '\r')) break;
            if (cVar1 == '1') {
              pcStack_2 = (code *)0x689;
              FUN_ram_068b();
            }
          }
          pcStack_2 = FUN_ram_0698 + 3;
          FUN_ram_0714();
          while( true ) {
            uVar3 = 0;
            pcStack_2 = (code *)0x6c0;
            FUN_ram_09db(2,0x7d2,200);
            pcStack_2 = (code *)0x6c8;
            func_0xf37d(CONCAT11(uVar3,0x1a),0xc000);
            pcStack_2 = (code *)0x6d4;
            func_0xf37d(0x2f,0x100,0);
            if (((DAT_ram_c003 == '\0') && (DAT_ram_c004 == '\x01')) && (DAT_ram_c005 == '\0'))
            break;
            do {
              pcStack_2 = (code *)0x6a9;
              FUN_ram_09db(2,0x813,200);
              pcStack_2 = (code *)0x6b0;
              cVar1 = FUN_ram_0aa9(0x9f);
            } while (cVar1 == '\0');
          }
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
      }
    }
  }
  else {
    bVar7 = (byte)((ushort)pcVar4 >> 8);
    pcStack_2 = FUN_ram_0144 + 6;
    bVar2 = func_0xf37d(0);
    pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343;
    if ((bVar2 != 0) || (bVar2 = bVar7, bVar7 < 2)) goto RST0;
    pcStack_2 = (code *)0x160;
    FUN_ram_026b(CONCAT11(9,s_To_play_on_harddisk__this_game_n_ram_0343[0x2c4]),
                 s_To_play_on_harddisk__this_game_n_ram_0343);
    pcStack_2 = (code *)0x168;
    cVar1 = func_0xf37d(0xf,0xbf5);
    if (cVar1 != '\0') {
      pcStack_2 = (code *)0x16c;
      FUN_ram_0abc(cVar1);
    }
    disableMaskableInterrupts();
    puVar9 = &DAT_ram_4000;
    puVar10 = (undefined1 *)0x0;
    sVar5 = 0x100;
    do {
      *puVar9 = *puVar10;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
      sVar5 = sVar5 + -1;
    } while (sVar5 != 0);
    enableMaskableInterrupts();
    puVar10 = (undefined1 *)0x4100;
    puVar9 = (undefined1 *)0x4101;
    sVar5 = 0x2b00;
    uRam4100 = 0xc9;
    do {
      *puVar9 = *puVar10;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
      sVar5 = sVar5 + -1;
    } while (sVar5 != 0);
    puVar10 = (undefined1 *)0xd77;
    puVar9 = (undefined1 *)0x6c00;
    sVar5 = 0x181;
    do {
      *puVar9 = *puVar10;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
      sVar5 = sVar5 + -1;
    } while (sVar5 != 0);
    bIo00fd = 2;
    uVar3 = 0x1a;
    pcStack_2 = (code *)0x1a1;
    func_0xf37d(0xc000);
    pcStack_2 = (code *)CONCAT11(3,uVar3);
    do {
      s_SNATCHER000_ram_02ed[10] = (char)((ushort)pcStack_2 >> 8) + '0';
      pcVar4 = (code *)0x310f;
      s_To_play_on_harddisk__this_game_n_ram_0343[0xa1] = s_SNATCHER000_ram_02ed[10];
      s_To_play_on_harddisk__this_game_n_ram_0343[0xd1] = s_SNATCHER000_ram_02ed[10];
      s_To_play_on_harddisk__this_game_n_ram_0343[0x105] = s_SNATCHER000_ram_02ed[10];
      cVar1 = func_0xf37d(0x310f,0x2ec);
      pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0x86;
      ppcVar12 = &pcStack_2;
      if (cVar1 != '\0') goto FUN_ram_0336;
      s_SNATCHER000_ram_02ed[0xd] = '\0';
      s_SNATCHER000_ram_02ed[0xe] = '\x02';
      _DAT_ram_030d = (char *)0x0;
      _DAT_ram_030f = 0;
      pcVar4 = (code *)CONCAT11((char)((ushort)pcVar4 >> 8),0x27);
      cVar1 = func_0xf37d(0,pcVar4,1,0x2ec);
      pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0xb6;
      ppcVar12 = &pcStack_2;
      if (cVar1 != '\0') goto FUN_ram_0336;
      cVar1 = (char)((ushort)pcStack_2 >> 8);
      pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0xea;
      pcVar4 = pcStack_2;
      ppcVar12 = (code **)register0x44;
      if ((char)(DAT_ram_c01d + '\x01') != cVar1) goto FUN_ram_0336;
      cVar1 = cVar1 + -1;
      pcStack_2 = (code *)CONCAT11(cVar1,(char)pcStack_2);
    } while (cVar1 != '\0');
    uVar3 = 0;
    pcStack_2 = (code *)0x1fb;
    func_0xf37d(0x1a,0xbe00);
    s_SNATCHER000_ram_02ed[0xd] = '\0';
    s_SNATCHER000_ram_02ed[0xe] = '\x02';
    _DAT_ram_030d = s_To_play_on_harddisk__this_game_n_ram_0343 + 0xc9;
    _DAT_ram_030f = 0;
    uVar6 = CONCAT11(uVar3,0x27);
    pcStack_2 = (code *)0x218;
    func_0xf37d(uVar6,1,0x2ec);
    uVar6 = CONCAT11((char)((ushort)uVar6 >> 8),0x1a);
    pcStack_2 = (code *)0x220;
    func_0xf37d(uVar6,0x8000);
    s_SNATCHER000_ram_02ed[0xd] = '\0';
    s_SNATCHER000_ram_02ed[0xe] = '\x02';
    _DAT_ram_030d = (char *)0x3f8;
    _DAT_ram_030f = 0;
    pcVar4 = (code *)CONCAT11((char)((ushort)uVar6 >> 8),0x27);
    pcStack_2 = (code *)0x23d;
    cVar1 = func_0xf37d(pcVar4,0x20,0x2ec);
    pcVar8 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0x119;
    if (cVar1 == '\0') {
      pcStack_2 = (code *)0x24c;
      func_0xf37d(0,0x10,0x2ec);
      pcVar8 = &LAB_ram_8100;
      do {
        while (pcVar11 = pcVar8, *pcVar11 != '!') {
          pcVar8 = pcVar11 + 1;
        }
        pcVar8 = pcVar11 + 1;
      } while ((pcVar11[1] != '4') || (pcVar8 = pcVar11 + 2, pcVar11[2] != -0x40));
      pcVar11[1] = '7';
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
FUN_ram_0336:
  bVar7 = (byte)((ushort)pcVar4 >> 8);
  bIo00fd = DAT_ram_f2c8;
  bVar2 = DAT_ram_f2c8;
  register0x44 = (BADSPACEBASE *)ppcVar12;
RST0:
  *(undefined2 *)((short)register0x44 + -2) = 0x340;
  func_0xf37d(bVar2,CONCAT11(bVar7,9),pcVar8);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ---- FUN_ram_0144 @ ram:0144

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_ram_0144(undefined2 param_1)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  byte bVar6;
  short sVar4;
  undefined2 uVar5;
  char *pcVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  char *pcVar10;
  undefined2 *puVar11;
  undefined2 uStack_2;
  
  bVar6 = (byte)((ushort)param_1 >> 8);
  uStack_2 = 0x14a;
  bVar1 = func_0xf37d(0);
  pcVar7 = s_To_play_on_harddisk__this_game_n_ram_0343;
  puVar11 = (undefined2 *)register0x44;
  if ((bVar1 == 0) && (bVar1 = bVar6, 1 < bVar6)) {
    uStack_2 = 0x160;
    FUN_ram_026b(CONCAT11(9,s_To_play_on_harddisk__this_game_n_ram_0343[0x2c4]),
                 s_To_play_on_harddisk__this_game_n_ram_0343);
    uStack_2 = 0x168;
    cVar2 = func_0xf37d(0xf,0xbf5);
    if (cVar2 != '\0') {
      uStack_2 = 0x16c;
      FUN_ram_0abc(cVar2);
    }
    disableMaskableInterrupts();
    puVar8 = &DAT_ram_4000;
    puVar9 = (undefined1 *)0x0;
    sVar4 = 0x100;
    do {
      *puVar8 = *puVar9;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
      sVar4 = sVar4 + -1;
    } while (sVar4 != 0);
    enableMaskableInterrupts();
    puVar9 = (undefined1 *)0x4100;
    puVar8 = (undefined1 *)0x4101;
    sVar4 = 0x2b00;
    uRam4100 = 0xc9;
    do {
      *puVar8 = *puVar9;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
      sVar4 = sVar4 + -1;
    } while (sVar4 != 0);
    puVar9 = (undefined1 *)0xd77;
    puVar8 = (undefined1 *)0x6c00;
    sVar4 = 0x181;
    do {
      *puVar8 = *puVar9;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
      sVar4 = sVar4 + -1;
    } while (sVar4 != 0);
    bIo00fd = 2;
    uVar3 = 0x1a;
    uStack_2 = 0x1a1;
    func_0xf37d(0xc000);
    uStack_2 = CONCAT11(3,uVar3);
    do {
      s_SNATCHER000_ram_02ed[10] = (char)((ushort)uStack_2 >> 8) + '0';
      uVar5 = 0x310f;
      s_To_play_on_harddisk__this_game_n_ram_0343[0xa1] = s_SNATCHER000_ram_02ed[10];
      s_To_play_on_harddisk__this_game_n_ram_0343[0xd1] = s_SNATCHER000_ram_02ed[10];
      s_To_play_on_harddisk__this_game_n_ram_0343[0x105] = s_SNATCHER000_ram_02ed[10];
      cVar2 = func_0xf37d(0x310f,0x2ec);
      pcVar7 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0x86;
      puVar11 = &uStack_2;
      if (cVar2 != '\0') goto FUN_ram_0336;
      s_SNATCHER000_ram_02ed[0xd] = '\0';
      s_SNATCHER000_ram_02ed[0xe] = '\x02';
      _DAT_ram_030d = (char *)0x0;
      _DAT_ram_030f = 0;
      uVar5 = CONCAT11((char)((ushort)uVar5 >> 8),0x27);
      cVar2 = func_0xf37d(0,uVar5,1,0x2ec);
      pcVar7 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0xb6;
      puVar11 = &uStack_2;
      if (cVar2 != '\0') goto FUN_ram_0336;
      cVar2 = (char)((ushort)uStack_2 >> 8);
      pcVar7 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0xea;
      uVar5 = uStack_2;
      puVar11 = (undefined2 *)register0x44;
      if ((char)(DAT_ram_c01d + '\x01') != cVar2) goto FUN_ram_0336;
      cVar2 = cVar2 + -1;
      uStack_2 = CONCAT11(cVar2,(char)uStack_2);
    } while (cVar2 != '\0');
    uVar3 = 0;
    uStack_2 = 0x1fb;
    func_0xf37d(0x1a,0xbe00);
    s_SNATCHER000_ram_02ed[0xd] = '\0';
    s_SNATCHER000_ram_02ed[0xe] = '\x02';
    _DAT_ram_030d = s_To_play_on_harddisk__this_game_n_ram_0343 + 0xc9;
    _DAT_ram_030f = 0;
    uVar5 = CONCAT11(uVar3,0x27);
    uStack_2 = 0x218;
    func_0xf37d(uVar5,1,0x2ec);
    uVar5 = CONCAT11((char)((ushort)uVar5 >> 8),0x1a);
    uStack_2 = 0x220;
    func_0xf37d(uVar5,0x8000);
    s_SNATCHER000_ram_02ed[0xd] = '\0';
    s_SNATCHER000_ram_02ed[0xe] = '\x02';
    _DAT_ram_030d = (char *)0x3f8;
    _DAT_ram_030f = 0;
    uVar5 = CONCAT11((char)((ushort)uVar5 >> 8),0x27);
    uStack_2 = 0x23d;
    cVar2 = func_0xf37d(uVar5,0x20,0x2ec);
    pcVar7 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0x119;
    if (cVar2 == '\0') {
      uStack_2 = 0x24c;
      func_0xf37d(0,0x10,0x2ec);
      pcVar7 = &LAB_ram_8100;
      do {
        while (pcVar10 = pcVar7, *pcVar10 != '!') {
          pcVar7 = pcVar10 + 1;
        }
        pcVar7 = pcVar10 + 1;
      } while ((pcVar10[1] != '4') || (pcVar7 = pcVar10 + 2, pcVar10[2] != -0x40));
      pcVar10[1] = '7';
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
FUN_ram_0336:
    bVar6 = (byte)((ushort)uVar5 >> 8);
    bIo00fd = DAT_ram_f2c8;
    bVar1 = DAT_ram_f2c8;
  }
  *(undefined2 *)((short)puVar11 + -2) = 0x340;
  func_0xf37d(bVar1,CONCAT11(bVar6,9),pcVar7);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ---- FUN_ram_01a3 @ ram:01a3

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_ram_01a3(undefined2 param_1)

{
  char cVar1;
  undefined1 uVar2;
  char *pcVar3;
  char *pcVar4;
  undefined2 *puVar5;
  undefined2 uStack_2;
  
  do {
    s_SNATCHER000_ram_02ed[10] = (char)((ushort)param_1 >> 8) + '0';
    s_To_play_on_harddisk__this_game_n_ram_0343[0xa1] = s_SNATCHER000_ram_02ed[10];
    s_To_play_on_harddisk__this_game_n_ram_0343[0xd1] = s_SNATCHER000_ram_02ed[10];
    s_To_play_on_harddisk__this_game_n_ram_0343[0x105] = s_SNATCHER000_ram_02ed[10];
    uStack_2 = param_1;
    cVar1 = func_0xf37d(0x310f,0x2ec);
    pcVar3 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0x86;
    puVar5 = &uStack_2;
    if (cVar1 != '\0') goto RST0;
    s_SNATCHER000_ram_02ed[0xd] = '\0';
    s_SNATCHER000_ram_02ed[0xe] = '\x02';
    _DAT_ram_030d = (char *)0x0;
    _DAT_ram_030f = 0;
    cVar1 = func_0xf37d(0,0x27,1,0x2ec);
    pcVar3 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0xb6;
    puVar5 = &uStack_2;
    if (cVar1 != '\0') goto RST0;
    cVar1 = (char)((ushort)uStack_2 >> 8);
    pcVar3 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0xea;
    puVar5 = (undefined2 *)register0x44;
    if ((char)(DAT_ram_c01d + '\x01') != cVar1) goto RST0;
    cVar1 = cVar1 + -1;
    param_1 = CONCAT11(cVar1,(char)uStack_2);
  } while (cVar1 != '\0');
  uVar2 = 0;
  uStack_2 = 0x1fb;
  func_0xf37d(0x1a,0xbe00);
  s_SNATCHER000_ram_02ed[0xd] = '\0';
  s_SNATCHER000_ram_02ed[0xe] = '\x02';
  _DAT_ram_030d = s_To_play_on_harddisk__this_game_n_ram_0343 + 0xc9;
  _DAT_ram_030f = 0;
  uStack_2 = 0x218;
  func_0xf37d(CONCAT11(uVar2,0x27),1,0x2ec);
  uStack_2 = 0x220;
  func_0xf37d(0x1a,0x8000);
  s_SNATCHER000_ram_02ed[0xd] = '\0';
  s_SNATCHER000_ram_02ed[0xe] = '\x02';
  _DAT_ram_030d = (char *)0x3f8;
  _DAT_ram_030f = 0;
  uStack_2 = 0x23d;
  cVar1 = func_0xf37d(0x27,0x20,0x2ec);
  pcVar3 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0x119;
  if (cVar1 == '\0') {
    uStack_2 = 0x24c;
    func_0xf37d(0,0x10,0x2ec);
    pcVar3 = &LAB_ram_8100;
    do {
      while (pcVar4 = pcVar3, *pcVar4 != '!') {
        pcVar3 = pcVar4 + 1;
      }
      pcVar3 = pcVar4 + 1;
    } while ((pcVar4[1] != '4') || (pcVar3 = pcVar4 + 2, pcVar4[2] != -0x40));
    pcVar4[1] = '7';
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
RST0:
  uIo00fd = DAT_ram_f2c8;
  *(undefined2 *)((short)puVar5 + -2) = 0x340;
  func_0xf37d(9,pcVar3);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ---- FUN_ram_024f @ ram:024f

/* WARNING: Control flow encountered bad instruction data */

void FUN_ram_024f(char *param_1)

{
  char *pcVar1;
  
  do {
    while (pcVar1 = param_1, *pcVar1 != '!') {
      param_1 = pcVar1 + 1;
    }
    param_1 = pcVar1 + 1;
  } while ((pcVar1[1] != '4') || (param_1 = pcVar1 + 2, pcVar1[2] != -0x40));
  pcVar1[1] = '7';
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ---- FUN_ram_0257 @ ram:0257

/* WARNING: Control flow encountered bad instruction data */

void FUN_ram_0257(char *param_1)

{
  char *pcVar1;
  
  while ((pcVar1 = param_1 + 1, *pcVar1 != '4' || (pcVar1 = param_1 + 2, *pcVar1 != -0x40))) {
    for (; param_1 = pcVar1, *pcVar1 != '!'; pcVar1 = pcVar1 + 1) {
    }
  }
  param_1[1] = '7';
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ---- FUN_ram_026b @ ram:026b

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_ram_026b(undefined2 param_1)

{
  char cVar1;
  byte bVar3;
  short sVar2;
  undefined1 *puVar4;
  undefined1 *puVar5;
  
  bVar3 = (byte)((ushort)param_1 >> 8);
  cVar1 = func_0xf37d(CONCAT11(bVar3,0x11),0x2c7);
  if (cVar1 != '\0') {
    return;
  }
  if ((byte)param_1 < bVar3) {
    uIo00fd = DAT_ram_f2c8;
    func_0xf37d(CONCAT11(bVar3,9),s_To_play_on_harddisk__this_game_n_ram_0343 + 0x1bc);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  func_0xf37d(CONCAT11(bVar3,0x1a),0x4000);
  _DAT_ram_02d5 = 0x4000;
  _DAT_ram_02e8 = 0;
  _DAT_ram_02ea = 0;
  func_0xf37d(0xf,0x2c7);
  func_0xf37d(0x27,1,0x2c7);
  func_0xf37d(0x10,0x2c7);
  disableMaskableInterrupts();
  sVar2 = 0x4000;
  puVar4 = (undefined1 *)0x8000;
  puVar5 = &DAT_ram_4000;
  do {
    *puVar4 = *puVar5;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
    sVar2 = sVar2 + -1;
  } while (sVar2 != 0);
  uIo00fe = 1;
  enableMaskableInterrupts();
  return;
}



// ---- FUN_ram_0336 @ ram:0336

/* WARNING: Control flow encountered bad instruction data */

void FUN_ram_0336(void)

{
  uIo00fd = DAT_ram_f2c8;
  func_0xf37d(9);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ---- FUN_ram_033b @ ram:033b

/* WARNING: Control flow encountered bad instruction data */

void FUN_ram_033b(void)

{
  func_0xf37d(9);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ---- FUN_ram_0608 @ ram:0608

/* WARNING: Control flow encountered bad instruction data */

void FUN_ram_0608(undefined2 param_1)

{
  char cVar1;
  undefined1 uVar2;
  char *pcVar3;
  
  uVar2 = (undefined1)((ushort)param_1 >> 8);
  DAT_ram_0ab9 = FUN_ram_0a9e(6);
  DAT_ram_0aba = FUN_ram_0a9e(7);
  cVar1 = FUN_ram_0a9e(0x2d);
  enableMaskableInterrupts();
  pcVar3 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0x23d;
  if (cVar1 != '\0') {
    if (cVar1 == '\x03') {
      FUN_ram_0aa9(0x82,0x180);
    }
    else {
      FUN_ram_0a59(s_To_play_on_harddisk__this_game_n_ram_0343 + 0x23d);
    }
    pcVar3 = s_To_play_on_harddisk__this_game_n_ram_0343 + 600;
    if (1 < (DAT_ram_fafc & 6) >> 1) {
      FUN_ram_0967();
      FUN_ram_0854();
      FUN_ram_086c(1,0x95c,0);
      FUN_ram_0aa9(0,0x135);
      FUN_ram_026b(CONCAT11(8,s_To_play_on_harddisk__this_game_n_ram_0343[0x2c4]));
      FUN_ram_06f3();
      while (((cVar1 = FUN_ram_0aa9(0x9f), cVar1 != '0' && (cVar1 != ' ')) && (cVar1 != '\r'))) {
        if (cVar1 == '1') {
          FUN_ram_068b();
        }
      }
      FUN_ram_0714();
      while( true ) {
        uVar2 = 0;
        FUN_ram_09db(2,0x7d2,200);
        func_0xf37d(CONCAT11(uVar2,0x1a),0xc000);
        func_0xf37d(0x2f,0x100,0);
        if (((DAT_ram_c003 == '\0') && (DAT_ram_c004 == '\x01')) && (DAT_ram_c005 == '\0')) break;
        do {
          FUN_ram_09db(2,0x813,200);
          cVar1 = FUN_ram_0aa9(0x9f);
        } while (cVar1 == '\0');
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  uIo00fd = DAT_ram_f2c8;
  func_0xf37d(CONCAT11(uVar2,9),pcVar3);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ---- FUN_ram_0638 @ ram:0638

/* WARNING: Control flow encountered bad instruction data */

void FUN_ram_0638(undefined2 param_1)

{
  char cVar1;
  undefined1 uVar2;
  
  uVar2 = (undefined1)((ushort)param_1 >> 8);
  FUN_ram_0a59();
  if ((DAT_ram_fafc & 6) >> 1 < 2) {
    uIo00fd = DAT_ram_f2c8;
    func_0xf37d(CONCAT11(uVar2,9),s_To_play_on_harddisk__this_game_n_ram_0343 + 600);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  FUN_ram_0967();
  FUN_ram_0854();
  FUN_ram_086c(1,0x95c,0);
  FUN_ram_0aa9(0,0x135);
  FUN_ram_026b(CONCAT11(8,s_To_play_on_harddisk__this_game_n_ram_0343[0x2c4]));
  FUN_ram_06f3();
  while (((cVar1 = FUN_ram_0aa9(0x9f), cVar1 != '0' && (cVar1 != ' ')) && (cVar1 != '\r'))) {
    if (cVar1 == '1') {
      FUN_ram_068b();
    }
  }
  FUN_ram_0714();
  while( true ) {
    uVar2 = 0;
    FUN_ram_09db(2,0x7d2,200);
    func_0xf37d(CONCAT11(uVar2,0x1a),0xc000);
    func_0xf37d(0x2f,0x100,0);
    if (((DAT_ram_c003 == '\0') && (DAT_ram_c004 == '\x01')) && (DAT_ram_c005 == '\0')) break;
    do {
      FUN_ram_09db(2,0x813,200);
      cVar1 = FUN_ram_0aa9(0x9f);
    } while (cVar1 == '\0');
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ---- FUN_ram_063b @ ram:063b

/* WARNING: Control flow encountered bad instruction data */

void FUN_ram_063b(void)

{
  char cVar1;
  undefined1 uVar2;
  
  if ((DAT_ram_fafc & 6) >> 1 < 2) {
    uIo00fd = DAT_ram_f2c8;
    func_0xf37d(9,s_To_play_on_harddisk__this_game_n_ram_0343 + 600);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  FUN_ram_0967();
  FUN_ram_0854();
  FUN_ram_086c(1,0x95c,0);
  FUN_ram_0aa9(0,0x135);
  FUN_ram_026b(CONCAT11(8,s_To_play_on_harddisk__this_game_n_ram_0343[0x2c4]));
  FUN_ram_06f3();
  while (((cVar1 = FUN_ram_0aa9(0x9f), cVar1 != '0' && (cVar1 != ' ')) && (cVar1 != '\r'))) {
    if (cVar1 == '1') {
      FUN_ram_068b();
    }
  }
  FUN_ram_0714();
  while( true ) {
    uVar2 = 0;
    FUN_ram_09db(2,0x7d2,200);
    func_0xf37d(CONCAT11(uVar2,0x1a),0xc000);
    func_0xf37d(0x2f,0x100,0);
    if (((DAT_ram_c003 == '\0') && (DAT_ram_c004 == '\x01')) && (DAT_ram_c005 == '\0')) break;
    do {
      FUN_ram_09db(2,0x813,200);
      cVar1 = FUN_ram_0aa9(0x9f);
    } while (cVar1 == '\0');
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ---- FUN_ram_066e @ ram:066e

/* WARNING: Control flow encountered bad instruction data */

void FUN_ram_066e(void)

{
  char cVar1;
  undefined1 uVar2;
  
  while (((cVar1 = FUN_ram_0aa9(0x9f), cVar1 != '0' && (cVar1 != ' ')) && (cVar1 != '\r'))) {
    if (cVar1 == '1') {
      FUN_ram_068b();
    }
  }
  FUN_ram_0714();
  while( true ) {
    uVar2 = 0;
    FUN_ram_09db(2,0x7d2,200);
    func_0xf37d(CONCAT11(uVar2,0x1a),0xc000);
    func_0xf37d(0x2f,0x100,0);
    if (((DAT_ram_c003 == '\0') && (DAT_ram_c004 == '\x01')) && (DAT_ram_c005 == '\0')) break;
    do {
      FUN_ram_09db(2,0x813,200);
      cVar1 = FUN_ram_0aa9(0x9f);
    } while (cVar1 == '\0');
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ---- FUN_ram_068b @ ram:068b

void FUN_ram_068b(void)

{
  FUN_ram_09db(2,0x791,200);
  return;
}



// ---- FUN_ram_0698 @ ram:0698

/* WARNING: Control flow encountered bad instruction data */

void FUN_ram_0698(void)

{
  char cVar1;
  undefined1 uVar2;
  
  FUN_ram_0714();
  while( true ) {
    uVar2 = 0;
    FUN_ram_09db(2,0x7d2,200);
    func_0xf37d(CONCAT11(uVar2,0x1a),0xc000);
    func_0xf37d(0x2f,0x100,0);
    if (((DAT_ram_c003 == '\0') && (DAT_ram_c004 == '\x01')) && (DAT_ram_c005 == '\0')) break;
    do {
      FUN_ram_09db(2,0x813,200);
      cVar1 = FUN_ram_0aa9(0x9f);
    } while (cVar1 == '\0');
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ---- FUN_ram_069d @ ram:069d

/* WARNING: Control flow encountered bad instruction data */

void FUN_ram_069d(void)

{
  char cVar1;
  undefined1 uVar2;
  
  do {
    do {
      FUN_ram_09db(2,0x813,200);
      cVar1 = FUN_ram_0aa9(0x9f);
    } while (cVar1 == '\0');
    uVar2 = 0;
    FUN_ram_09db(2,0x7d2,200);
    func_0xf37d(CONCAT11(uVar2,0x1a),0xc000);
    func_0xf37d(0x2f,0x100,0);
  } while (((DAT_ram_c003 != '\0') || (DAT_ram_c004 != '\x01')) || (DAT_ram_c005 != '\0'));
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ---- FUN_ram_06b4 @ ram:06b4

/* WARNING: Control flow encountered bad instruction data */

void FUN_ram_06b4(void)

{
  char cVar1;
  undefined1 uVar2;
  
  while( true ) {
    uVar2 = 0;
    FUN_ram_09db(2,0x7d2,200);
    func_0xf37d(CONCAT11(uVar2,0x1a),0xc000);
    func_0xf37d(0x2f,0x100,0);
    if (((DAT_ram_c003 == '\0') && (DAT_ram_c004 == '\x01')) && (DAT_ram_c005 == '\0')) break;
    do {
      FUN_ram_09db(2,0x813,200);
      cVar1 = FUN_ram_0aa9(0x9f);
    } while (cVar1 == '\0');
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ---- FUN_ram_06f3 @ ram:06f3

void FUN_ram_06f3(void)

{
  short sVar1;
  
  sVar1 = 0x739;
  FUN_ram_09db(2,0x739,0xb6);
  sVar1 = sVar1 + 1;
  FUN_ram_09db(2,sVar1,0xbf);
  FUN_ram_09db(2,sVar1 + 1,200);
  return;
}



// ---- FUN_ram_0714 @ ram:0714

void FUN_ram_0714(void)

{
  FUN_ram_09db(2,0x72d,0xb6);
  FUN_ram_09db(2,0x72d,0xbf);
  return;
}



// ---- FUN_ram_0854 @ ram:0854

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_ram_0854(void)

{
  char cVar1;
  short sVar2;
  undefined1 uVar3;
  short sVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  
  FUN_ram_0aa9(0x41);
  sVar4 = 0;
  puVar6 = (undefined1 *)0x951;
  FUN_ram_086c(0);
  DAT_ram_092b = FUN_ram_0aa9(0x44);
  puVar5 = (undefined1 *)0x92d;
  sVar2 = 0xb;
  _DAT_ram_0929 = sVar4;
  do {
    *puVar5 = *puVar6;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
    sVar2 = sVar2 + -1;
  } while (sVar2 != 0);
  uVar3 = 0;
  func_0xf37d(0x1a,0xc000);
  cVar1 = func_0xf37d(CONCAT11(uVar3,0xf),0x92c);
  if (cVar1 != '\0') {
    return 0;
  }
  _DAT_ram_093a = 0x400;
  _DAT_ram_094d = 0;
  _DAT_ram_094f = 0;
  while (cVar1 = func_0xf37d(0x27,1,0x92c), cVar1 == '\0') {
    _DAT_ram_0929 = _DAT_ram_0929 + 0x400;
    FUN_ram_08dc(0x400,0xc000);
  }
  func_0xf37d(0x10,0x92c);
  return 1;
}



// ---- FUN_ram_086c @ ram:086c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_ram_086c(undefined1 param_1,undefined1 *param_2,short param_3)

{
  char cVar1;
  short sVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  
  puVar4 = (undefined1 *)0x92d;
  sVar2 = 0xb;
  _DAT_ram_0929 = param_3;
  DAT_ram_092b = param_1;
  do {
    *puVar4 = *param_2;
    puVar4 = puVar4 + 1;
    param_2 = param_2 + 1;
    sVar2 = sVar2 + -1;
  } while (sVar2 != 0);
  uVar3 = 0;
  func_0xf37d(0x1a,0xc000);
  cVar1 = func_0xf37d(CONCAT11(uVar3,0xf),0x92c);
  if (cVar1 != '\0') {
    return 0;
  }
  _DAT_ram_093a = 0x400;
  _DAT_ram_094d = 0;
  _DAT_ram_094f = 0;
  while (cVar1 = func_0xf37d(0x27,1,0x92c), cVar1 == '\0') {
    _DAT_ram_0929 = _DAT_ram_0929 + 0x400;
    FUN_ram_08dc(0x400,0xc000);
  }
  func_0xf37d(0x10,0x92c);
  return 1;
}



// ---- FUN_ram_0892 @ ram:0892

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_ram_0892(void)

{
  char cVar1;
  
  _DAT_ram_093a = 0x400;
  _DAT_ram_094d = 0;
  _DAT_ram_094f = 0;
  while (cVar1 = func_0xf37d(0x27,1,0x92c), cVar1 == '\0') {
    _DAT_ram_0929 = _DAT_ram_0929 + 0x400;
    FUN_ram_08dc(0x400,0xc000);
  }
  func_0xf37d(0x10,0x92c);
  return 1;
}



// ---- FUN_ram_08a1 @ ram:08a1

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_ram_08a1(void)

{
  char cVar1;
  
  while (cVar1 = func_0xf37d(0x27,1,0x92c), cVar1 == '\0') {
    _DAT_ram_0929 = _DAT_ram_0929 + 0x400;
    FUN_ram_08dc(0x400,0xc000);
  }
  func_0xf37d(0x10,0x92c);
  return 1;
}



// ---- FUN_ram_08bc @ ram:08bc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_ram_08bc(void)

{
  char cVar1;
  undefined1 uVar2;
  
  do {
    _DAT_ram_0929 = _DAT_ram_0929 + 0x400;
    uVar2 = 4;
    FUN_ram_08dc(0x400,0xc000);
    cVar1 = func_0xf37d(CONCAT11(uVar2,0x27),1,0x92c);
  } while (cVar1 == '\0');
  func_0xf37d(0x10,0x92c);
  return 1;
}



// ---- FUN_ram_08d6 @ ram:08d6

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_ram_08d6(undefined2 param_1,undefined2 param_2)

{
  char cVar1;
  
  while( true ) {
    FUN_ram_08dc(param_1,param_2);
    cVar1 = func_0xf37d(0x27,1,0x92c);
    if (cVar1 != '\0') break;
    _DAT_ram_0929 = _DAT_ram_0929 + 0x400;
    param_2 = 0xc000;
    param_1 = 0x400;
  }
  func_0xf37d(0x10,0x92c);
  return 1;
}



// ---- FUN_ram_08dc @ ram:08dc

undefined1 FUN_ram_08dc(short param_1,undefined1 *param_2,undefined2 param_3)

{
  byte bVar1;
  
  FUN_ram_08f4(param_3);
  bVar1 = FUN_ram_0a9e(7);
  do {
    *(undefined1 *)(ushort)bVar1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + -1;
  } while (param_1 != 0);
  return 0;
}



// ---- FUN_ram_08ea @ ram:08ea

undefined1 FUN_ram_08ea(byte param_1,undefined1 *param_2,short param_3)

{
  do {
    *(undefined1 *)(ushort)param_1 = *param_2;
    param_2 = param_2 + 1;
    param_3 = param_3 + -1;
  } while (param_3 != 0);
  return 0;
}



// ---- FUN_ram_08f4 @ ram:08f4

void FUN_ram_08f4(undefined2 param_1,undefined2 param_2)

{
  byte bVar1;
  byte in_F;
  char cVar2;
  byte bVar3;
  
  uRam0916 = 0;
  if ((in_F & 1) != 0) {
    uRam0916 = 4;
  }
  cVar2 = FUN_ram_0a9e(7,param_1);
  disableMaskableInterrupts();
  bVar1 = cVar2 + 1;
  *(undefined1 *)(ushort)bVar1 = 0;
  *(undefined1 *)(ushort)bVar1 = 0xad;
  bVar3 = (byte)((ushort)param_2 >> 8);
  *(byte *)(ushort)bVar1 = (bVar3 >> 7) << 1 | (bVar3 & 0x7f) >> 6;
  *(undefined1 *)(ushort)bVar1 = 0x8e;
  *(char *)(ushort)bVar1 = (char)param_2;
  *(byte *)(ushort)bVar1 = bVar3 & 0x3f | 0x40;
  enableMaskableInterrupts();
  return;
}



// ---- FUN_ram_08fa @ ram:08fa

void FUN_ram_08fa(undefined1 param_1,undefined2 param_2,undefined2 param_3)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  
  uRam0916 = param_1;
  cVar2 = FUN_ram_0a9e(7,param_2);
  disableMaskableInterrupts();
  bVar1 = cVar2 + 1;
  *(undefined1 *)(ushort)bVar1 = 0;
  *(undefined1 *)(ushort)bVar1 = 0xad;
  bVar3 = (byte)((ushort)param_3 >> 8);
  *(byte *)(ushort)bVar1 = (bVar3 >> 7) << 1 | (bVar3 & 0x7f) >> 6;
  *(undefined1 *)(ushort)bVar1 = 0x8e;
  *(char *)(ushort)bVar1 = (char)param_3;
  *(byte *)(ushort)bVar1 = bVar3 & 0x3f | 0x40;
  enableMaskableInterrupts();
  return;
}



// ---- FUN_ram_0967 @ ram:0967

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_ram_0967(void)

{
  undefined1 *puVar1;
  byte bVar2;
  ushort uVar3;
  char cVar4;
  undefined1 *puVar5;
  
  DAT_ram_f3ea = 0;
  FUN_ram_0aa9(7,0x5f);
  disableMaskableInterrupts();
  bVar2 = (char)_DAT_ram_0aba + 1;
  *(byte *)(ushort)bVar2 = DAT_ram_ffe7 | 0x20;
  *(undefined1 *)(ushort)bVar2 = 0x88;
  *(undefined1 *)(ushort)bVar2 = 0;
  *(undefined1 *)(ushort)bVar2 = 0x90;
  puVar5 = (undefined1 *)0x997;
  uVar3 = CONCAT11(0x20,(char)_DAT_ram_0aba + '\x02');
  do {
    puVar1 = (undefined1 *)(uVar3 & 0xff);
    cVar4 = (char)(uVar3 >> 8) + -1;
    uVar3 = CONCAT11(cVar4,(char)uVar3);
    *puVar1 = *puVar5;
    puVar5 = puVar5 + 1;
  } while (cVar4 != '\0');
  enableMaskableInterrupts();
  return;
}



// ---- FUN_ram_09b7 @ ram:09b7

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_ram_09b7(undefined1 param_1)

{
  byte bVar1;
  
  bVar1 = (char)((uint3)_DAT_ram_0ab9 >> 8) + 1;
  *(undefined1 *)(ushort)bVar1 = param_1;
  *(undefined1 *)(ushort)bVar1 = 0x8f;
  return *(undefined1 *)(ushort)(byte)((char)_DAT_ram_0ab9 + 1);
}



// ---- FUN_ram_09cc @ ram:09cc

void FUN_ram_09cc(void)

{
  byte bVar1;
  
  do {
    bVar1 = FUN_ram_09b7(2);
  } while ((bVar1 & 1) != 0);
  FUN_ram_09b7(0);
  return;
}



// ---- FUN_ram_09db @ ram:09db

void FUN_ram_09db(short param_1,char *param_2,undefined2 param_3)

{
  byte bVar1;
  short sVar2;
  byte extraout_F;
  byte bVar3;
  undefined2 uVar4;
  
  do {
    if (*param_2 == '\0') {
      return;
    }
    bVar3 = FUN_ram_09f2();
    param_1 = param_1 + 8;
    param_2 = param_2 + 1;
  } while ((bool)((extraout_F & 0x40) >> 6));
  disableMaskableInterrupts();
  FUN_ram_09cc();
  *(undefined1 *)(ushort)(byte)(DAT_ram_0aba + 1U) = 0x20;
  *(undefined1 *)(ushort)(byte)(DAT_ram_0aba + 1U) = 0x91;
  bVar1 = DAT_ram_0aba + 3;
  uVar4 = 0x100;
  if (((0x3f < bVar3) && (uVar4 = 0x10a, 0x7f < bVar3)) && (uVar4 = 0x114, 0xbf < bVar3)) {
    uVar4 = 0x11e;
  }
  sVar2 = (ushort)(bVar3 & 0x3f) * 8;
  *(char *)(ushort)bVar1 = (char)sVar2;
  *(char *)(ushort)bVar1 = (char)((ushort)sVar2 >> 8);
  *(char *)(ushort)bVar1 = (char)uVar4;
  *(char *)(ushort)bVar1 = (char)((ushort)uVar4 >> 8);
  *(char *)(ushort)bVar1 = (char)param_1;
  *(char *)(ushort)bVar1 = (char)((ushort)param_1 >> 8);
  *(char *)(ushort)bVar1 = (char)param_3;
  *(char *)(ushort)bVar1 = (char)((ushort)param_3 >> 8);
  *(undefined1 *)(ushort)bVar1 = 8;
  *(undefined1 *)(ushort)bVar1 = 0;
  *(undefined1 *)(ushort)bVar1 = 10;
  *(undefined1 *)(ushort)bVar1 = 0;
  *(undefined1 *)(ushort)bVar1 = 0;
  *(undefined1 *)(ushort)bVar1 = 0;
  *(undefined1 *)(ushort)bVar1 = 0xd0;
  enableMaskableInterrupts();
  return;
}



// ---- FUN_ram_09f2 @ ram:09f2

void FUN_ram_09f2(undefined2 param_1,undefined2 param_2)

{
  byte bVar1;
  short sVar2;
  undefined2 in_AF;
  byte bVar3;
  undefined2 uVar4;
  
  disableMaskableInterrupts();
  FUN_ram_09cc();
  *(undefined1 *)(ushort)(byte)(DAT_ram_0aba + 1U) = 0x20;
  *(undefined1 *)(ushort)(byte)(DAT_ram_0aba + 1U) = 0x91;
  bVar1 = DAT_ram_0aba + 3;
  uVar4 = 0x100;
  bVar3 = (byte)((ushort)in_AF >> 8);
  if (((0x3f < bVar3) && (uVar4 = 0x10a, 0x7f < bVar3)) && (uVar4 = 0x114, 0xbf < bVar3)) {
    uVar4 = 0x11e;
  }
  sVar2 = (ushort)(bVar3 & 0x3f) * 8;
  *(char *)(ushort)bVar1 = (char)sVar2;
  *(char *)(ushort)bVar1 = (char)((ushort)sVar2 >> 8);
  *(char *)(ushort)bVar1 = (char)uVar4;
  *(char *)(ushort)bVar1 = (char)((ushort)uVar4 >> 8);
  *(char *)(ushort)bVar1 = (char)param_1;
  *(char *)(ushort)bVar1 = (char)((ushort)param_1 >> 8);
  *(char *)(ushort)bVar1 = (char)param_2;
  *(char *)(ushort)bVar1 = (char)((ushort)param_2 >> 8);
  *(undefined1 *)(ushort)bVar1 = 8;
  *(undefined1 *)(ushort)bVar1 = 0;
  *(undefined1 *)(ushort)bVar1 = 10;
  *(undefined1 *)(ushort)bVar1 = 0;
  *(undefined1 *)(ushort)bVar1 = 0;
  *(undefined1 *)(ushort)bVar1 = 0;
  *(undefined1 *)(ushort)bVar1 = 0xd0;
  enableMaskableInterrupts();
  return;
}



// ---- FUN_ram_0a24 @ ram:0a24

void FUN_ram_0a24(byte param_1,byte param_2,undefined2 param_3,undefined2 param_4)

{
  short sVar1;
  undefined2 in_stack_00000000;
  
  sVar1 = (ushort)(param_1 & 0x3f) * 8;
  *(char *)(ushort)param_2 = (char)sVar1;
  *(char *)(ushort)param_2 = (char)((ushort)sVar1 >> 8);
  *(char *)(ushort)param_2 = (char)param_3;
  *(char *)(ushort)param_2 = (char)((ushort)param_3 >> 8);
  *(char *)(ushort)param_2 = (char)in_stack_00000000;
  *(char *)(ushort)param_2 = (char)((ushort)in_stack_00000000 >> 8);
  *(char *)(ushort)param_2 = (char)param_4;
  *(char *)(ushort)param_2 = (char)((ushort)param_4 >> 8);
  *(undefined1 *)(ushort)param_2 = 8;
  *(undefined1 *)(ushort)param_2 = 0;
  *(undefined1 *)(ushort)param_2 = 10;
  *(undefined1 *)(ushort)param_2 = 0;
  *(undefined1 *)(ushort)param_2 = 0;
  *(undefined1 *)(ushort)param_2 = 0;
  *(undefined1 *)(ushort)param_2 = 0xd0;
  enableMaskableInterrupts();
  return;
}



// ---- FUN_ram_0a59 @ ram:0a59

undefined1 FUN_ram_0a59(void)

{
  char cVar1;
  short sVar2;
  
  sVar2 = 4999;
  cVar1 = FUN_ram_0a9e(4999);
  if (cVar1 == -0x59) {
    sVar2 = sVar2 + 1;
    cVar1 = FUN_ram_0a9e(sVar2);
    if (cVar1 == -6) {
      sVar2 = sVar2 + 1;
      FUN_ram_0a9e(sVar2);
      cVar1 = FUN_ram_0a9e(sVar2 + 1);
      if (cVar1 == '\x13') {
        sVar2 = 0x1393;
        cVar1 = FUN_ram_0a9e(0x1393);
        if (cVar1 == -0x25) {
          cVar1 = FUN_ram_0a9e(sVar2 + 1);
          if (cVar1 == -0x4a) {
            FUN_ram_0aa9(1,4999);
            return 1;
          }
        }
      }
    }
  }
  return 0;
}



// ---- FUN_ram_0a9c @ ram:0a9c

undefined1 FUN_ram_0a9c(void)

{
  return 0;
}



// ---- FUN_ram_0a9e @ ram:0a9e

void FUN_ram_0a9e(undefined2 param_1,undefined2 param_2)

{
  func_0x000c(DAT_ram_fcc1,param_2,param_1);
  return;
}



// ---- FUN_ram_0aa9 @ ram:0aa9

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_ram_0aa9(undefined2 param_1,undefined2 param_2)

{
  func_0x001c(_DAT_ram_fcc0,param_1,param_2);
  return;
}



// ---- FUN_ram_0abc @ ram:0abc

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_ram_0abc(void)

{
  char cVar1;
  undefined2 uVar2;
  
  cVar1 = func_0xf37d(0xf,0xbd0);
  uVar2 = 0xc1a;
  if (cVar1 == '\0') {
    func_0xf37d(0,0x1a,0xef8);
    s_SNATCHER001_ram_0bd1[0xd] = '\0';
    s_SNATCHER001_ram_0bd1[0xe] = '\x02';
    _DAT_ram_0bf1 = (char *)0x0;
    _DAT_ram_0bf3 = 0;
    cVar1 = func_0xf37d(0x27,2,0xbd0);
    uVar2 = 0xc1a;
    if (cVar1 == '\0') {
      FUN_ram_0b76(0,0xc46);
      _DAT_ram_0bf1 = s_To_play_on_harddisk__this_game_n_ram_0343 + 0x241;
      _DAT_ram_0bf3 = 0;
      cVar1 = func_0xf37d(0x27,7,0xbd0);
      uVar2 = 0xc1a;
      if (cVar1 == '\0') {
        func_0xf37d(0,0x10,0xbd0);
        func_0xf37d(0x16,0xbf5);
        func_0xf37d(0xf,0xbf5);
        func_0xf37d(0x1a,0xef8);
        ram0x0c03 = 0x200;
        uRam0c16 = 0;
        uRam0c18 = 0;
        cVar1 = func_0xf37d(0x26,7,0xbf5);
        uVar2 = 0xc72;
        if (cVar1 == '\0') {
          func_0xf37d(0,0x10,0xbf5);
          return;
        }
      }
    }
  }
  uIo00fd = DAT_ram_f2c8;
  func_0xf37d(9,uVar2);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ---- FUN_ram_0b66 @ ram:0b66

undefined1 FUN_ram_0b66(short param_1,char *param_2,char *param_3)

{
  char cVar1;
  char cVar2;
  
  do {
    cVar2 = *param_3;
    cVar1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + -1;
    param_3 = param_3 + 1;
    if (cVar2 != cVar1) {
      return 1;
    }
  } while (param_1 != 0);
  return 0;
}



// ---- FUN_ram_0b72 @ ram:0b72

undefined1 FUN_ram_0b72(void)

{
  return 1;
}



// ---- FUN_ram_0b76 @ ram:0b76

/* WARNING: Control flow encountered bad instruction data */

void FUN_ram_0b76(undefined2 param_1)

{
  byte in_F;
  undefined1 uVar1;
  
  uVar1 = 0;
  FUN_ram_0b66(0x1e,0xef8,0xb9d);
  if ((in_F >> 6 & 1) != 0) {
    uVar1 = 0;
    FUN_ram_0b66(0x14,0xf34,0xbbb);
    if ((in_F >> 6 & 1) != 0) {
      return;
    }
  }
  uIo00fd = DAT_ram_f2c8;
  func_0xf37d(CONCAT11(uVar1,9),param_1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// ---- FUN_ram_0c96 @ ram:0c96

void FUN_ram_0c96(undefined2 param_1)

{
  byte extraout_F;
  byte extraout_F_00;
  undefined2 in_AF;
  char cVar1;
  short sVar2;
  undefined1 *puVar3;
  char *pcVar4;
  undefined1 *puVar5;
  char *pcVar6;
  
  DAT_ram_0d5c = (char)((ushort)in_AF >> 8);
  s_FudebaabeduF_ram_0d69[0xc] = cIo00a8;
  DAT_ram_0d76 = DAT_ram_ffff;
  func_0x0024((char)((ushort)param_1 >> 8));
  FUN_ram_0d2d(0);
  puVar3 = (undefined1 *)0xd5d;
  puVar5 = (undefined1 *)0x4100;
  sVar2 = 6;
  do {
    *puVar3 = *puVar5;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
    sVar2 = sVar2 + -1;
  } while (sVar2 != 0);
  pcVar6 = s_FudebaabeduF_ram_0d69;
  pcVar4 = (char *)0x4100;
  sVar2 = 6;
  do {
    *pcVar4 = *pcVar6;
    pcVar4 = pcVar4 + 1;
    pcVar6 = pcVar6 + 1;
    sVar2 = sVar2 + -1;
  } while (sVar2 != 0);
  cVar1 = DAT_ram_0d5c;
  if (DAT_ram_0d5c == '\0') {
    cVar1 = '\x03';
  }
  while( true ) {
    cVar1 = FUN_ram_0d2d(cVar1);
    puVar3 = (undefined1 *)0xd63;
    puVar5 = (undefined1 *)0x4105;
    sVar2 = 6;
    do {
      *puVar3 = *puVar5;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
      sVar2 = sVar2 + -1;
    } while (sVar2 != 0);
    pcVar6 = s_FudebaabeduF_ram_0d69 + 6;
    pcVar4 = (char *)0x4105;
    sVar2 = 6;
    do {
      *pcVar4 = *pcVar6;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
      sVar2 = sVar2 + -1;
    } while (sVar2 != 0);
    FUN_ram_0d43(s_FudebaabeduF_ram_0d69 + 6,0x4105);
    if ((extraout_F >> 6 & 1) == 0) break;
    puVar5 = (undefined1 *)0xd63;
    puVar3 = (undefined1 *)0x4105;
    sVar2 = 6;
    do {
      *puVar3 = *puVar5;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
      sVar2 = sVar2 + -1;
    } while (sVar2 != 0);
    FUN_ram_0d43(s_FudebaabeduF_ram_0d69,0x4100);
    if ((bool)(extraout_F_00 >> 6 & 1)) break;
    cVar1 = cVar1 + '\x01';
  }
  puVar5 = (undefined1 *)0xd5d;
  puVar3 = (undefined1 *)0x4100;
  sVar2 = 6;
  do {
    *puVar3 = *puVar5;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
    sVar2 = sVar2 + -1;
  } while (sVar2 != 0);
  FUN_ram_0d2d();
  FUN_ram_0d4b();
  return;
}



// ---- FUN_ram_0ccd @ ram:0ccd

void FUN_ram_0ccd(void)

{
  undefined1 extraout_F;
  byte extraout_F_00;
  byte extraout_F_01;
  undefined1 uVar2;
  ushort uVar1;
  short sVar3;
  undefined1 *puVar4;
  char *pcVar5;
  undefined1 *puVar6;
  char *pcVar7;
  
  do {
    uVar2 = FUN_ram_0d2d();
    puVar4 = (undefined1 *)0xd63;
    puVar6 = (undefined1 *)0x4105;
    sVar3 = 6;
    do {
      *puVar4 = *puVar6;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
      sVar3 = sVar3 + -1;
    } while (sVar3 != 0);
    uVar1 = CONCAT11(uVar2,extraout_F) & 0xffe9;
    pcVar7 = s_FudebaabeduF_ram_0d69 + 6;
    pcVar5 = (char *)0x4105;
    sVar3 = 6;
    do {
      *pcVar5 = *pcVar7;
      pcVar5 = pcVar5 + 1;
      pcVar7 = pcVar7 + 1;
      sVar3 = sVar3 + -1;
    } while (sVar3 != 0);
    FUN_ram_0d43(s_FudebaabeduF_ram_0d69 + 6,0x4105,uVar1);
    if ((extraout_F_00 >> 6 & 1) == 0) break;
    puVar6 = (undefined1 *)0xd63;
    puVar4 = (undefined1 *)0x4105;
    sVar3 = 6;
    do {
      *puVar4 = *puVar6;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
      sVar3 = sVar3 + -1;
    } while (sVar3 != 0);
    FUN_ram_0d43(s_FudebaabeduF_ram_0d69,0x4100,uVar1);
  } while (!(bool)(extraout_F_01 >> 6 & 1));
  puVar6 = (undefined1 *)0xd5d;
  puVar4 = (undefined1 *)0x4100;
  sVar3 = 6;
  do {
    *puVar4 = *puVar6;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
    sVar3 = sVar3 + -1;
  } while (sVar3 != 0);
  FUN_ram_0d2d();
  FUN_ram_0d4b();
  return;
}



// ---- FUN_ram_0d10 @ ram:0d10

void FUN_ram_0d10(void)

{
  short sVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  puVar3 = (undefined1 *)0xd5d;
  puVar2 = (undefined1 *)0x4100;
  sVar1 = 6;
  do {
    *puVar2 = *puVar3;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
    sVar1 = sVar1 + -1;
  } while (sVar1 != 0);
  FUN_ram_0d2d();
  FUN_ram_0d4b();
  return;
}



// ---- FUN_ram_0d23 @ ram:0d23

void FUN_ram_0d23(void)

{
  FUN_ram_0d2d();
  FUN_ram_0d4b();
  return;
}



// ---- FUN_ram_0d2d @ ram:0d2d

undefined1 FUN_ram_0d2d(void)

{
  undefined2 in_AF;
  undefined1 uVar1;
  
  uVar1 = (undefined1)((ushort)in_AF >> 8);
  if (DAT_ram_0d5c == '\0') {
    uIo00fd = uVar1;
    return uVar1;
  }
  uIo008e = uVar1;
  DAT_ram_4000 = uVar1;
  return uVar1;
}



// ---- FUN_ram_0d38 @ ram:0d38

undefined1 FUN_ram_0d38(void)

{
  undefined2 in_stack_00000000;
  
  uIo008e = (undefined1)((ushort)in_stack_00000000 >> 8);
  DAT_ram_4000 = uIo008e;
  return uIo008e;
}



// ---- FUN_ram_0d43 @ ram:0d43

void FUN_ram_0d43(undefined2 param_1,char *param_2,char *param_3)

{
  char cVar1;
  
  cVar1 = (char)((ushort)param_1 >> 8);
  do {
    if (*param_3 != *param_2) {
      return;
    }
    param_2 = param_2 + 1;
    param_3 = param_3 + 1;
    cVar1 = cVar1 + -1;
  } while (cVar1 != '\0');
  return;
}



// ---- FUN_ram_0d4b @ ram:0d4b

undefined1 FUN_ram_0d4b(void)

{
  undefined2 in_AF;
  
  disableMaskableInterrupts();
  cIo00a8 = s_FudebaabeduF_ram_0d69[0xc];
  DAT_ram_ffff = ~DAT_ram_0d76;
  enableMaskableInterrupts();
  return (char)((ushort)in_AF >> 8);
}


