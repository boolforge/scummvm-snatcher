// Ghidra decompilation of saturn_main.bin (SuperH:BE:32:SH-2)

// ---- entry @ 06004000

void entry(void)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  iVar1 = iRam06004020;
  uVar3 = 0x600400e;
  (*pcRam06004024)();
  pcVar2 = pcRam06004028;
  *(undefined4 *)(iVar1 + -4) = uVar3;
  (*pcVar2)();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



// ---- FUN_0600401a @ 0600401a

void FUN_0600401a(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


