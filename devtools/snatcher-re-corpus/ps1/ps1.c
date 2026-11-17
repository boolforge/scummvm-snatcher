// Ghidra decompilation of ps1_slps.bin (MIPS:LE:32:default)

// ---- FUN_80029a20 @ 80029a20

void FUN_80029a20(void)

{
  return;
}



// ---- FUN_80029ae4 @ 80029ae4

void FUN_80029ae4(undefined4 param_1)

{
  FUN_80058704();
  FUN_800586a4(param_1,0x3f,0);
  return;
}



// ---- FUN_80029b18 @ 80029b18

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80029b18(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  _DAT_800ac954 = param_1;
  if (param_1 == 0) {
    do {
      (&DAT_800a0910)[iVar2] = 0xff;
      (&DAT_800a08e8)[iVar2] = 0xff;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x22);
    FUN_80058374(&DAT_800a08e8,0x22,&DAT_800a0910,0x22);
    FUN_80061c44();
    FUN_80058524();
    uVar1 = 2;
    DAT_800a00a8 = DAT_800a08e8;
    DAT_800a00b0 = DAT_800a0910;
  }
  else {
    FUN_80058614(s_PadInit__unsupported_mode__d_80028000);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



// ---- FUN_80029bdc @ 80029bdc

undefined4 FUN_80029bdc(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 1;
    if ((DAT_800a00a8 == DAT_800a08e8) && (uVar1 = 0, DAT_800a00b0 != DAT_800a0910)) {
      uVar1 = 1;
    }
  }
  else {
    FUN_80058614(s_PadStatus__unsupported_mode__d_80028020);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



// ---- FUN_80029d44 @ 80029d44

void FUN_80029d44(void)

{
  FUN_80058384();
  return;
}



// ---- FUN_80029d74 @ 80029d74

undefined4 FUN_80029d74(int param_1,char *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = &DAT_800a00b8 + param_1;
  uVar1 = 0xffffffff;
  if (*(char *)*piVar2 == '\0') {
    *param_2 = ((char *)*piVar2)[4];
    param_2[1] = *(char *)(*piVar2 + 5);
    param_2[2] = *(char *)(*piVar2 + 3);
    uVar1 = 0;
    param_2[3] = *(char *)(*piVar2 + 1);
  }
  return uVar1;
}



// ---- FUN_80029dec @ 80029dec

void FUN_80029dec(void)

{
  FUN_80029e5c(&DAT_800a08e8,&DAT_800a0910);
  FUN_80029f7c(4,4);
  FUN_80029f04(0,0x140,0,0xf0);
  FUN_80029f94(0,0,0);
  FUN_80029f94(1,0,0);
  return;
}



// ---- FUN_80029e5c @ 80029e5c

void FUN_80029e5c(undefined4 param_1,undefined4 param_2)

{
  DAT_800a00b8 = param_1;
  DAT_800a00bc = param_2;
  DAT_800a093b = 0;
  DAT_800a093a = 0;
  DAT_800a0939 = 0;
  DAT_800a0938 = 0;
  DAT_800a093f = 0;
  DAT_800a093e = 0;
  DAT_800a093d = 0;
  DAT_800a093c = 0;
  DAT_800a0943 = 0;
  DAT_800a0942 = 0;
  DAT_800a0941 = 0;
  DAT_800a0940 = 0;
  DAT_800a0947 = 0;
  DAT_800a0946 = 0;
  DAT_800a0945 = 0;
  DAT_800a0944 = 0;
  DAT_800a00c2 = 0;
  DAT_800a00c0 = 0;
  return;
}



// ---- FUN_80029f04 @ 80029f04

void FUN_80029f04(int param_1,int param_2,int param_3,int param_4)

{
  DAT_800a00d0 = param_1 * (uint)DAT_800a00f8;
  DAT_800a00d8 = param_2 * (uint)DAT_800a00f8;
  DAT_800a00e8 = param_3 * (uint)DAT_800a0100;
  DAT_800a00f0 = param_4 * (uint)DAT_800a0100;
  return;
}



// ---- FUN_80029f7c @ 80029f7c

void FUN_80029f7c(undefined2 param_1,undefined2 param_2)

{
  DAT_800a00f8 = param_1;
  DAT_800a0100 = param_2;
  return;
}



// ---- FUN_80029f94 @ 80029f94

void FUN_80029f94(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_800a0100;
  *(uint *)(&DAT_800a00c8 + param_1 * 4) = param_2 * (uint)DAT_800a00f8;
  *(uint *)(&DAT_800a00e0 + param_1 * 4) = param_3 * uVar1;
  return;
}



// ---- FUN_80029ff0 @ 80029ff0

void FUN_80029ff0(int param_1,int *param_2)

{
  uint uVar1;
  
  FUN_8002a134();
  uVar1 = (uint)DAT_800a00f8;
  if (uVar1 == 0) {
    trap(0x1c00);
  }
  if ((uVar1 == 0xffffffff) && (*(int *)(&DAT_800a00c8 + param_1 * 4) == -0x80000000)) {
    trap(0x1800);
  }
  *param_2 = *(int *)(&DAT_800a00c8 + param_1 * 4) / (int)uVar1;
  uVar1 = (uint)DAT_800a0100;
  if (uVar1 == 0) {
    trap(0x1c00);
  }
  if ((uVar1 == 0xffffffff) && (*(int *)(&DAT_800a00e0 + param_1 * 4) == -0x80000000)) {
    trap(0x1800);
  }
  param_2[1] = *(int *)(&DAT_800a00e0 + param_1 * 4) / (int)uVar1;
  (&DAT_800a0938)[(uint)(ushort)(&DAT_800a00c0)[param_1] + param_1 * 8] = 0;
  param_2[2] = 0;
  if (*(char *)(&DAT_800a00b8)[param_1] == '\0') {
    param_2[2] = ~(int)((char *)(&DAT_800a00b8)[param_1])[3] & 0xc;
  }
  return;
}



// ---- FUN_8002a134 @ 8002a134

void FUN_8002a134(int param_1)

{
  int iVar1;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  
  pcVar2 = (char *)(&DAT_800a00b8)[param_1];
  if ((pcVar2[1] == '\x12') && (*pcVar2 == '\0')) {
    piVar3 = (int *)(&DAT_800a00c8 + param_1 * 4);
    *piVar3 = (int)pcVar2[4] + *piVar3;
    *(int *)(&DAT_800a00e0 + param_1 * 4) =
         (int)*(char *)((&DAT_800a00b8)[param_1] + 5) + *(int *)(&DAT_800a00e0 + param_1 * 4);
    iVar1 = DAT_800a00d0;
    if ((*piVar3 < DAT_800a00d0) || (iVar1 = DAT_800a00d8, DAT_800a00d8 < *piVar3)) {
      *piVar3 = iVar1;
    }
    iVar4 = *(int *)(&DAT_800a00e0 + param_1 * 4);
    iVar1 = DAT_800a00e8;
    if ((iVar4 < DAT_800a00e8) || (iVar1 = DAT_800a00f0, DAT_800a00f0 < iVar4)) {
      *(int *)(&DAT_800a00e0 + param_1 * 4) = iVar1;
    }
  }
  return;
}



// ---- FUN_8002a23c @ 8002a23c

void FUN_8002a23c(void)

{
  char cVar1;
  
  FUN_80029a20();
  FUN_8002a5a8();
  FUN_8002a5bc();
  do {
    FUN_8002a64c();
    FUN_8002a7e0();
    while (cVar1 = FUN_8002bcbc(0xffffffff), cVar1 == '\0') {
      FUN_8002aa28();
      FUN_8002b4e8();
      cVar1 = FUN_8002bd04(0xffffffff);
      if (cVar1 == '\0') {
        FUN_8002a2e4();
        FUN_8002b248();
      }
      FUN_8002aaac();
    }
    FUN_8002a834();
  } while( true );
}



// ---- FUN_8002a2e4 @ 8002a2e4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002a2e4(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = _DAT_800abf64;
  iVar1 = FUN_8002b210(0);
  if (iVar1 == 0) {
    iVar2 = FUN_8002b144();
    (*(code *)(&PTR_FUN_80070910)[iVar2])();
  }
  else if (iVar1 == 2) {
    (*(code *)**(undefined4 **)(iVar2 + 0x7a74))(iVar2,0);
  }
  return;
}



// ---- FUN_8002a378 @ 8002a378

void FUN_8002a378(void)

{
  FUN_8002b114(2);
  return;
}



// ---- FUN_8002a398 @ 8002a398

void FUN_8002a398(void)

{
  FUN_8002c57c(0,1,9,FUN_8002a558);
  FUN_8002b170(0);
  return;
}



// ---- FUN_8002a3d0 @ 8002a3d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002a3d0(void)

{
  *(undefined4 *)(_DAT_800abf64 + 0x7a74) = 0x800b4000;
  FUN_8002c57c(0,0x800b4000,2,FUN_8002a588);
  FUN_8002b170(0);
  return;
}



// ---- FUN_8002a420 @ 8002a420

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002a420(void)

{
  *(undefined4 *)(_DAT_800abf64 + 0x7a74) = 0x800b4000;
  FUN_8002c57c(1,0x800b4000,2,FUN_8002a588);
  FUN_8002b170(0);
  return;
}



// ---- FUN_8002a470 @ 8002a470

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002a470(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  FUN_800458d4(0);
  *(undefined4 *)(iVar1 + 0x7a74) = 0x800b4000;
  FUN_8002c57c(2,0x800b4000,2,FUN_8002a588);
  FUN_8002b170(0);
  return;
}



// ---- FUN_8002a4d0 @ 8002a4d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002a4d0(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  FUN_80031c9c(0);
  FUN_80055d44();
  *(undefined4 *)(iVar1 + 0x7a74) = 0x800b4000;
  FUN_8002c57c(3,0x800b4000,2,FUN_8002a588);
  FUN_8002b170(0);
  return;
}



// ---- FUN_8002a538 @ 8002a538

void FUN_8002a538(void)

{
  FUN_8002b170(0);
  return;
}



// ---- FUN_8002a558 @ 8002a558

void FUN_8002a558(void)

{
  FUN_8003bb90();
  FUN_80051468();
  FUN_8002b114(0);
  return;
}



// ---- FUN_8002a588 @ 8002a588

void FUN_8002a588(void)

{
  FUN_8002b170(0);
  return;
}



// ---- FUN_8002a5a8 @ 8002a5a8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002a5a8(void)

{
  _DAT_800abf64 = 0x80010000;
  return;
}



// ---- FUN_8002a5bc @ 8002a5bc

void FUN_8002a5bc(void)

{
  FUN_80061c44();
  FUN_80058314();
  FUN_8002a87c();
  FUN_8002b290();
  FUN_8002be40();
  FUN_8003b038();
  FUN_8002d32c();
  FUN_800585a4();
  FUN_80058544(0);
  FUN_8002a624();
  return;
}



// ---- FUN_8002a624 @ 8002a624

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002a624(void)

{
  FUN_800585e4(_DAT_800abf64,4);
  return;
}



// ---- FUN_8002a64c @ 8002a64c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002a64c(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  iVar1 = _DAT_800abf64;
  iVar5 = 0;
  iVar4 = 0x7aac;
  iVar3 = _DAT_800abf64;
  do {
    iVar2 = iVar1 + iVar4;
    iVar4 = iVar4 + 0x40;
    *(undefined4 *)(iVar3 + 0x7a84) = 4;
    *(int *)(iVar3 + 0x7a88) = iVar2;
    iVar5 = iVar5 + 1;
    iVar3 = iVar3 + 0x14;
  } while (iVar5 < 2);
  FUN_80059584(0);
  FUN_8005d138(0x100,0xf0,4,1,0);
  FUN_8005d948(0,0,0,0xf0);
  local_c = 0x100;
  local_10 = 0;
  local_e = 0;
  local_a = 0xf0;
  FUN_8005dc68(&local_10);
  FUN_8005d898();
  FUN_8005df48();
  FUN_8005ddec(0x80,0x78);
  FUN_8005de04(0x400);
  FUN_800598bc(0);
  FUN_8005d908();
  FUN_8002a72c();
  return;
}



// ---- FUN_8002a72c @ 8002a72c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002a72c(void)

{
  FUN_800585e4(_DAT_800abf64 + 4,0x1958);
  FUN_8002abc4();
  FUN_8002b0a8();
  FUN_8002b350();
  FUN_8002d5f0();
  FUN_80030508();
  FUN_8003058c();
  FUN_8002be98();
  FUN_8003b1f4();
  FUN_80031a80();
  FUN_8002c6e8();
  FUN_80031ed0();
  FUN_80032494();
  FUN_80032784();
  FUN_80034988();
  FUN_800363bc();
  FUN_80031c68();
  FUN_80036704();
  return;
}



// ---- FUN_8002a7e0 @ 8002a7e0

void FUN_8002a7e0(void)

{
  FUN_800585d4(DAT_8007092c);
  DAT_8007092c = DAT_8007092c * 0x41c64e6d + 0x3039;
  FUN_8003bb3c();
  return;
}



// ---- FUN_8002a834 @ 8002a834

void FUN_8002a834(void)

{
  FUN_800598bc(0);
  FUN_80059584(0);
  FUN_80058314();
  FUN_80031238();
  FUN_80031b24();
  FUN_800585a4();
  return;
}



// ---- FUN_8002a87c @ 8002a87c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002a87c(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _DAT_800abf64;
  uVar2 = FUN_80058574(0xf2000003,2,0x1000,FUN_8002a960);
  *(undefined4 *)(iVar1 + 4) = uVar2;
  FUN_80058364();
  _DAT_1f801104 = 0x143;
  _DAT_1f801114 = _DAT_1f801114 | 6;
  FUN_800583a4(0xf2000000,0xffff,0x2010);
  FUN_800583a4(0xf2000001,0xffff,0x2010);
  FUN_800583a4(0xf2000003,1,0x1000);
  FUN_80058478(0xf2000000);
  FUN_80058478(0xf2000001);
  FUN_80058478(0xf2000003);
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  return;
}



// ---- FUN_8002a960 @ 8002a960

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002a960(void)

{
  *(int *)(_DAT_800abf64 + 0x14) = *(int *)(_DAT_800abf64 + 0x14) + 1;
  FUN_80031b9c();
  return;
}



// ---- FUN_8002a994 @ 8002a994

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002a994(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  FUN_800584ac(0xf2000000);
  FUN_800584ac(0xf2000001);
  FUN_800584ac(0xf2000002);
  FUN_800584ac(0xf2000003);
  FUN_80058304(*(undefined4 *)(iVar1 + 4));
  return;
}



// ---- FUN_8002a9f4 @ 8002a9f4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8002a9f4(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 4) {
    uVar1 = *(undefined4 *)(param_1 * 4 + _DAT_800abf64 + 8);
  }
  else {
    uVar1 = *(undefined4 *)(_DAT_800abf64 + 0x18);
  }
  return uVar1;
}



// ---- FUN_8002aa28 @ 8002aa28

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002aa28(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _DAT_800abf64;
  iVar2 = FUN_8005daf8();
  _DAT_800ac1b0 = iVar1 + iVar2 * 0x14 + 0x7a84;
  _DAT_800b05cc = iVar2;
  *(int *)(iVar1 + 0x7a78) = iVar2;
  *(int *)(iVar1 + 0x7a7c) = _DAT_800ac1b0;
  _DAT_800aeea0 = iVar1 + iVar2 * 0x40 + 0x7aac;
  *(int *)(iVar1 + 0x7a80) = _DAT_800aeea0;
  FUN_8005da98(0,0,*(undefined4 *)(iVar1 + 0x7a7c));
  return;
}



// ---- FUN_8002aaac @ 8002aaac

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002aaac(void)

{
  int iVar1;
  char cVar2;
  
  iVar1 = _DAT_800abf64;
  FUN_800363d4();
  FUN_80031eec();
  FUN_8002c164();
  FUN_8002e1cc();
  FUN_8002c944();
  FUN_80055e50();
  FUN_80055dcc();
  FUN_80031b70();
  *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
  FUN_8002ab90();
  FUN_8005da28();
  cVar2 = FUN_8002bd04(0xffffffff);
  if (cVar2 == '\0') {
    FUN_80059584(1);
    FUN_8005d698(0,0);
    FUN_8005d758();
    FUN_8005dba8();
    FUN_8005d5a4(0,0,0,_DAT_800ac1b0);
    FUN_8005d9f8(_DAT_800ac1b0);
  }
  return;
}



// ---- FUN_8002ab90 @ 8002ab90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002ab90(void)

{
  *(uint *)(_DAT_800abf64 + 8) = _DAT_1f801110 & 0xffff;
  _DAT_1f801100 = 0;
  _DAT_1f801110 = 0;
  return;
}



// ---- FUN_8002abc4 @ 8002abc4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002abc4(void)

{
  *(undefined4 *)(_DAT_800abf64 + 0x1c) = 0;
  FUN_8002abf8(0x80018000,0x10000);
  return;
}



// ---- FUN_8002abf8 @ 8002abf8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002abf8(undefined4 param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  FUN_800585e4();
  *(undefined4 *)(iVar1 + 0x1c) = param_1;
  *(undefined4 *)param_1 = param_1;
  *(uint *)(*(int *)(iVar1 + 0x1c) + 4) = param_2 >> 3;
  return;
}



// ---- FUN_8002ac50 @ 8002ac50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_8002ac50(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar6 = (undefined4 *)(_DAT_800abf64 + 0x1c);
  puVar5 = *(undefined4 **)(_DAT_800abf64 + 0x1c);
  uVar4 = (param_1 + 7U >> 3) + 1;
  if (param_1 == 0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    FUN_80058314();
    puVar1 = (undefined4 *)*puVar5;
    while (puVar2 = puVar1, uVar3 = puVar2[1], uVar3 < uVar4) {
      if (puVar2 == (undefined4 *)*puVar6) {
        puVar2 = (undefined4 *)0x0;
        FUN_80058614(s_HEAP_ERROR_80028040);
        goto LAB_8002ad10;
      }
      puVar5 = puVar2;
      puVar1 = (undefined4 *)*puVar2;
    }
    if (uVar3 == uVar4) {
      *puVar5 = *puVar2;
    }
    else {
      puVar2[1] = uVar3 - uVar4;
      puVar2 = puVar2 + (uVar3 - uVar4) * 2;
      puVar2[1] = uVar4;
    }
    *puVar6 = puVar5;
    puVar2 = puVar2 + 2;
LAB_8002ad10:
    FUN_800585a4();
  }
  return puVar2;
}



// ---- FUN_8002ad3c @ 8002ad3c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_8002ad3c(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  FUN_80058314();
  if (param_1 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)(_DAT_800abf64 + 0x1c);
    puVar5 = *(undefined4 **)(_DAT_800abf64 + 0x1c);
    uVar4 = (param_2 + 7U >> 3) + 1;
    if (param_2 == 0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      FUN_80058314();
      puVar1 = (undefined4 *)*puVar5;
      while (puVar3 = puVar1, uVar2 = puVar3[1], uVar2 < uVar4) {
        if (puVar3 == (undefined4 *)*puVar6) {
          puVar3 = (undefined4 *)0x0;
          FUN_80058614(s_HEAP_ERROR_80028040);
          goto LAB_8002ae18;
        }
        puVar5 = puVar3;
        puVar1 = (undefined4 *)*puVar3;
      }
      if (uVar2 == uVar4) {
        *puVar5 = *puVar3;
      }
      else {
        puVar3[1] = uVar2 - uVar4;
        puVar3 = puVar3 + (uVar2 - uVar4) * 2;
        puVar3[1] = uVar4;
      }
      *puVar6 = puVar5;
      puVar3 = puVar3 + 2;
LAB_8002ae18:
      FUN_800585a4();
    }
  }
  else {
    if (param_2 != param_1[1]) {
      puVar6 = (undefined4 *)(_DAT_800abf64 + 0x1c);
      puVar5 = *(undefined4 **)(_DAT_800abf64 + 0x1c);
      uVar4 = (param_2 + 7U >> 3) + 1;
      if (param_2 == 0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        FUN_80058314();
        puVar1 = (undefined4 *)*puVar5;
        while (puVar3 = puVar1, uVar2 = puVar3[1], uVar2 < uVar4) {
          if (puVar3 == (undefined4 *)*puVar6) {
            puVar3 = (undefined4 *)0x0;
            FUN_80058614(s_HEAP_ERROR_80028040);
            goto LAB_8002aee4;
          }
          puVar5 = puVar3;
          puVar1 = (undefined4 *)*puVar3;
        }
        if (uVar2 == uVar4) {
          *puVar5 = *puVar3;
        }
        else {
          puVar3[1] = uVar2 - uVar4;
          puVar3 = puVar3 + (uVar2 - uVar4) * 2;
          puVar3[1] = uVar4;
        }
        *puVar6 = puVar5;
        puVar3 = puVar3 + 2;
LAB_8002aee4:
        FUN_800585a4();
      }
      if (puVar3 != (undefined4 *)0x0) {
        FUN_8002af34(param_1);
        goto LAB_8002af04;
      }
    }
    puVar3 = param_1;
  }
LAB_8002af04:
  FUN_800585a4();
  return puVar3;
}



// ---- FUN_8002af34 @ 8002af34

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002af34(int param_1)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  undefined4 *puVar5;
  
  iVar1 = _DAT_800abf64;
  puVar4 = (uint *)(param_1 + -8);
  puVar5 = (undefined4 *)(_DAT_800abf64 + 0x1c);
  if (param_1 != 0) {
    FUN_80058314();
    puVar3 = *(uint **)(iVar1 + 0x1c);
    while ((puVar4 <= puVar3 || ((uint *)*puVar3 <= puVar4))) {
      puVar2 = (uint *)*puVar3;
      if ((puVar2 <= puVar3) && ((puVar3 < puVar4 || (puVar4 < puVar2)))) break;
      puVar3 = puVar2;
    }
    puVar2 = (uint *)*puVar3;
    if (puVar4 + *(int *)(param_1 + -4) * 2 == puVar2) {
      *(uint *)(param_1 + -4) = *(int *)(param_1 + -4) + puVar2[1];
      *puVar4 = *(uint *)*puVar3;
    }
    else {
      *puVar4 = (uint)puVar2;
    }
    if (puVar3 + puVar3[1] * 2 == puVar4) {
      puVar3[1] = puVar3[1] + *(int *)(param_1 + -4);
      *puVar3 = *puVar4;
    }
    else {
      *puVar3 = (uint)puVar4;
    }
    *puVar5 = puVar3;
    FUN_800585a4();
  }
  return;
}



// ---- FUN_8002b054 @ 8002b054

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8002b054(char param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  for (puVar2 = (undefined4 *)**(undefined4 **)(_DAT_800abf64 + 0x1c); iVar3 = iVar3 + puVar2[1],
      puVar2 != *(undefined4 **)(_DAT_800abf64 + 0x1c); puVar2 = (undefined4 *)*puVar2) {
  }
  iVar1 = iVar3 * 8;
  if (param_1 != '\0') {
    iVar1 = iVar3 * -8 + 0x10000;
  }
  return iVar1;
}



// ---- FUN_8002b0a8 @ 8002b0a8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002b0a8(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = _DAT_800abf64;
  iVar3 = 3;
  iVar2 = _DAT_800abf64 + 0x2c;
  *(undefined4 *)(_DAT_800abf64 + 0x20) = 1;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  do {
    *(undefined4 *)(iVar2 + 8) = 0;
    iVar3 = iVar3 + -1;
    iVar2 = iVar2 + -4;
  } while (-1 < iVar3);
  return;
}



// ---- FUN_8002b114 @ 8002b114

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002b114(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = _DAT_800abf64;
  iVar3 = 3;
  iVar2 = _DAT_800abf64 + 0x2c;
  *(undefined4 *)(_DAT_800abf64 + 0x20) = param_1;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  do {
    *(undefined4 *)(iVar2 + 8) = 0;
    iVar3 = iVar3 + -1;
    iVar2 = iVar2 + -4;
  } while (-1 < iVar3);
  return;
}



// ---- FUN_8002b144 @ 8002b144

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8002b144(void)

{
  int iVar1;
  
  iVar1 = *(int *)(_DAT_800abf64 + 0x20);
  if (6 < iVar1) {
    iVar1 = 6;
  }
  return iVar1;
}



// ---- FUN_8002b170 @ 8002b170

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002b170(uint param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = _DAT_800abf64 + 0x20;
  iVar1 = (param_1 & 0xff) * 4 + iVar3;
  uVar2 = (param_1 & 0xff) + 1;
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
  if (uVar2 < 4) {
    iVar3 = uVar2 * 4 + iVar3;
    do {
      *(undefined4 *)(iVar3 + 8) = 0;
      uVar2 = uVar2 + 1;
      iVar3 = iVar3 + 4;
    } while ((int)uVar2 < 4);
  }
  return;
}



// ---- FUN_8002b210 @ 8002b210

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8002b210(uint param_1)

{
  undefined4 uVar1;
  
  if ((param_1 & 0xff) < 4) {
    uVar1 = *(undefined4 *)((param_1 & 0xff) * 4 + _DAT_800abf64 + 0x28);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



// ---- FUN_8002b248 @ 8002b248

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002b248(void)

{
  *(int *)(_DAT_800abf64 + 0x24) = *(int *)(_DAT_800abf64 + 0x24) + 1;
  return;
}



// ---- FUN_8002b290 @ 8002b290

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002b290(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = _DAT_800abf64 + 0x4c;
  iVar1 = _DAT_800abf64 + 0x52;
  FUN_80058374(iVar2,6,iVar1,6);
  FUN_80029e5c(iVar2,iVar1);
  FUN_80029f7c(3,4);
  FUN_80029f04(0xfffffff0,0x110,0xfffffff0,0x100);
  FUN_80029f94(0,0x80,0x50);
  FUN_80029f94(1,0x80,0x50);
  FUN_80058524();
  return;
}



// ---- FUN_8002b330 @ 8002b330

void FUN_8002b330(void)

{
  FUN_80029d44();
  return;
}



// ---- FUN_8002b350 @ 8002b350

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002b350(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = _DAT_800abf64;
  iVar5 = 0;
  iVar4 = _DAT_800abf64 + 0x38;
  *(undefined4 *)(_DAT_800abf64 + 0x38) = 0;
  iVar2 = iVar4;
  do {
    *(undefined2 *)(iVar2 + 4) = 0;
    *(undefined2 *)(iVar2 + 8) = 0;
    *(undefined2 *)(iVar2 + 0xc) = 0;
    *(undefined2 *)(iVar2 + 0x10) = 0;
    iVar5 = iVar5 + 1;
    iVar2 = iVar2 + 2;
  } while (iVar5 < 2);
  FUN_800585e4(iVar4 + iVar5 * 6 + 0x14,6);
  FUN_800585e4(iVar4 + iVar5 * 0x52 + 0x20,0x52);
  iVar5 = 7;
  iVar2 = iVar3 + 0x46;
  *(undefined2 *)(iVar3 + 0xfc) = 0x80;
  *(undefined2 *)(iVar3 + 0xfe) = 0x50;
  *(undefined1 *)(iVar3 + 0x100) = 0;
  *(undefined1 *)(iVar3 + 0x101) = 1;
  *(undefined1 *)(iVar3 + 0x102) = 1;
  *(undefined1 *)(iVar3 + 0x103) = 0;
  *(undefined2 *)(iVar3 + 0x104) = 0;
  *(undefined2 *)(iVar3 + 0x106) = 0;
  *(undefined1 *)(iVar3 + 0x108) = 0;
  *(undefined1 *)(iVar3 + 0x109) = 0;
  *(undefined1 *)(iVar3 + 0x10c) = 1;
  *(undefined1 *)(iVar3 + 0x10d) = 0;
  *(undefined1 *)(iVar3 + 0x10e) = 0;
  *(undefined1 *)(iVar3 + 0x10f) = 0;
  *(undefined1 *)(iVar3 + 0x110) = 0;
  *(undefined1 *)(iVar3 + 0x111) = 1;
  *(undefined1 *)(iVar3 + 0x112) = 0;
  *(undefined1 *)(iVar3 + 0x113) = 0;
  *(undefined1 *)(iVar3 + 0x114) = 0;
  *(undefined1 *)(iVar3 + 0x115) = 1;
  *(undefined1 *)(iVar3 + 0x116) = 0;
  *(undefined1 *)(iVar3 + 0x117) = 0;
  do {
    *(undefined2 *)(iVar2 + 0xe0) = 0;
    iVar5 = iVar5 + -1;
    iVar2 = iVar2 + -2;
  } while (-1 < iVar5);
  iVar2 = 0;
  *(undefined2 *)(iVar3 + 0x118) = DAT_80070948;
  uVar1 = DAT_8007094a;
  *(undefined2 *)(iVar3 + 0x11c) = 8;
  *(undefined2 *)(iVar3 + 0x11e) = 4;
  *(undefined2 *)(iVar3 + 0x11a) = uVar1;
  iVar3 = iVar4;
  do {
    *(undefined1 *)(iVar4 + iVar2 + 0xf0) = 0xff;
    *(undefined1 *)(iVar4 + iVar2 + 0xf2) = 0;
    *(undefined2 *)(iVar3 + 0xf4) = 0;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 2;
  } while (iVar2 < 2);
  FUN_8002bb54(1);
  FUN_8002bc14(1);
  FUN_8002bc98(1);
  FUN_8002bce0(0);
  FUN_8002bc50(1);
  return;
}



// ---- FUN_8002b4e8 @ 8002b4e8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002b4e8(void)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  uint uVar12;
  undefined2 local_28 [2];
  undefined2 local_24;
  uint local_20;
  
  iVar2 = _DAT_800abf64;
  uVar12 = *(uint *)(_DAT_800abf64 + 0x38);
  uVar4 = FUN_8002bd28(0);
  *(undefined4 *)(iVar2 + 0x38) = uVar4;
  puVar11 = (uint *)(iVar2 + 0x38);
  if (*(char *)(iVar2 + 0x100) == '\x01') {
    FUN_8002bd8c(0,local_28);
    if (*(char *)(iVar2 + 0x103) == '\x01') {
      *(undefined1 *)(iVar2 + 0x103) = 0;
    }
    else if (*(char *)(iVar2 + 0x101) == '\x01') {
      if (*(char *)(iVar2 + 0x110) == '\0') {
        *(undefined2 *)(iVar2 + 0xfc) = local_28[0];
        *(undefined2 *)(iVar2 + 0xfe) = local_24;
      }
      if ((*(ushort *)(iVar2 + 0x11c) & local_20) != 0) {
        *(uint *)(iVar2 + 0x38) = (uint)*(ushort *)(iVar2 + 0x118) | *(uint *)(iVar2 + 0x38);
      }
      if ((*(ushort *)(iVar2 + 0x11e) & local_20) != 0) {
        *(uint *)(iVar2 + 0x38) = (uint)*(ushort *)(iVar2 + 0x11a) | *(uint *)(iVar2 + 0x38);
      }
    }
    else {
      *(undefined2 *)(iVar2 + 0xfc) = 0x80;
      *(undefined2 *)(iVar2 + 0xfe) = 0x50;
    }
    FUN_80029f94(0,(int)*(short *)(iVar2 + 0xfc),(int)*(short *)(iVar2 + 0xfe));
  }
  uVar9 = 0;
  puVar6 = puVar11;
  puVar8 = puVar11;
  do {
    if ((*(char *)((int)puVar6 + 0xf2) == '\x01') || (cVar3 = (char)puVar6[0x3c], cVar3 == '\0')) {
      *puVar11 = ~(0xffff << (uVar9 & 0x1f)) & *puVar11;
      cVar3 = (char)puVar6[0x3c];
    }
    if (cVar3 == '\0') {
      uVar5 = (uint)(ushort)puVar8[0x3d] << (uVar9 & 0x1f);
LAB_8002b684:
      *puVar11 = uVar5;
    }
    else if (cVar3 == '\x01') {
      uVar5 = (uint)(ushort)puVar8[0x3d] << (uVar9 & 0x1f) | *puVar11;
      goto LAB_8002b684;
    }
    *(undefined1 *)(puVar6 + 0x3c) = 0xff;
    *(undefined2 *)(puVar8 + 0x3d) = 0;
    puVar8 = (uint *)((int)puVar8 + 2);
    puVar6 = (uint *)((int)puVar6 + 1);
    uVar9 = uVar9 + 0x10;
    if (iVar2 + 0x3c <= (int)puVar8) {
      iVar10 = 0;
      uVar9 = *puVar11;
      puVar6 = puVar11;
      do {
        uVar5 = iVar10 << 4;
        iVar10 = iVar10 + 1;
        uVar7 = *puVar11;
        *(short *)(puVar6 + 2) = (short)(uVar12 >> (uVar5 & 0x1f));
        *(short *)(puVar6 + 3) = (short)((~uVar12 & uVar9) >> (uVar5 & 0x1f));
        *(short *)(puVar6 + 4) = (short)((uVar12 & ~uVar9) >> (uVar5 & 0x1f));
        *(short *)(puVar6 + 1) = (short)(uVar7 >> (uVar5 & 0x1f));
        puVar6 = (uint *)((int)puVar6 + 2);
      } while (iVar10 < 2);
      if ((*(char *)(iVar2 + 0x10c) == '\x01') &&
         ((iVar10 = FUN_8002b8ac(0,0x90c,1,1,0), iVar10 != 0 ||
          (iVar10 = FUN_8002b8ac(1,0x90c,1,1,0), iVar10 != 0)))) {
        bVar1 = *(byte *)(iVar2 + 0x10e);
        *(byte *)(iVar2 + 0x10e) = bVar1 + 1;
        if (0x13 < bVar1) {
          *(undefined1 *)(iVar2 + 0x10c) = 1;
          *(undefined1 *)(iVar2 + 0x10d) = 1;
          *(undefined1 *)(iVar2 + 0x10e) = 0;
          FUN_80031268(0,7);
        }
      }
      else {
        *(undefined1 *)(iVar2 + 0x10d) = 0;
        *(undefined1 *)(iVar2 + 0x10e) = 0;
        if ((*(char *)(iVar2 + 0x10f) == '\x01') &&
           ((iVar10 = FUN_8002b8ac(0,0x800,1,3,0), iVar10 != 0 ||
            (iVar10 = FUN_8002b8ac(1,0x800,1,3,0), iVar10 != 0)))) {
          *(bool *)(iVar2 + 0x110) = *(char *)(iVar2 + 0x110) == '\0';
        }
        if ((*(uint *)(iVar2 + 0x110) & 0xffff00) == 0x100) {
          uVar12 = 0;
          if (*(char *)(iVar2 + 0x113) != '\0') {
            bVar1 = *(byte *)(iVar2 + 0x114);
            *(byte *)(iVar2 + 0x114) = bVar1 + 1;
            if (0x3b < bVar1) {
              *(undefined1 *)(iVar2 + 0x114) = 0;
              *(undefined1 *)(iVar2 + 0x113) = 0;
            }
            uVar12 = (uint)*(byte *)(iVar2 + 0x113);
          }
          if (*(short *)(&DAT_80070930 + uVar12 * 2) == -1) {
            *(undefined1 *)(iVar2 + 0x112) = 1;
            *(undefined1 *)(iVar2 + 0x114) = 0;
            *(undefined1 *)(iVar2 + 0x113) = 0;
          }
          else {
            iVar10 = FUN_8002b8ac(0,*(short *)(&DAT_80070930 + uVar12 * 2),0,3,0);
            if (iVar10 != 0) {
              *(undefined1 *)(iVar2 + 0x114) = 0;
              *(char *)(iVar2 + 0x113) = *(char *)(iVar2 + 0x113) + '\x01';
            }
          }
        }
      }
      return;
    }
  } while( true );
}



// ---- FUN_8002b8ac @ 8002b8ac

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_8002b8ac(byte param_1,ushort param_2,char param_3,undefined1 param_4,char param_5)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  ushort uVar4;
  
  iVar3 = _DAT_800abf64 + 0x38;
  uVar4 = 0xffff;
  if (param_5 != '\x01') {
    uVar4 = param_2;
  }
  if (1 < param_1) {
LAB_8002b9fc:
    return 0xffffffff;
  }
  switch(param_4) {
  case 1:
    uVar2 = *(ushort *)((uint)param_1 * 2 + iVar3 + 4);
    break;
  case 2:
    uVar2 = *(ushort *)((uint)param_1 * 2 + iVar3 + 8);
    break;
  case 3:
    uVar2 = *(ushort *)((uint)param_1 * 2 + iVar3 + 0xc);
    break;
  case 4:
    uVar2 = *(ushort *)((uint)param_1 * 2 + iVar3 + 0x10);
    break;
  case 5:
    if (param_3 == '\0') {
      iVar3 = (uint)param_1 * 2 + iVar3;
      return (uint)((*(ushort *)(iVar3 + 8) & uVar4 & *(ushort *)(iVar3 + 4)) != 0);
    }
    if (param_3 != '\x01') {
      return 0xffffffff;
    }
    iVar3 = (uint)param_1 * 2 + iVar3;
    uVar2 = *(ushort *)(iVar3 + 4);
    param_2 = *(ushort *)(iVar3 + 8);
    goto LAB_8002b9ec;
  default:
    goto LAB_8002b9fc;
  }
  if (param_3 == '\0') {
    uVar1 = (uint)((param_2 & uVar2 & uVar4) != 0);
  }
  else if (param_3 == '\x01') {
LAB_8002b9ec:
    uVar1 = (uint)((uVar4 & uVar2) == param_2);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



// ---- FUN_8002ba04 @ 8002ba04

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_8002ba04(ushort param_1)

{
  undefined2 uVar1;
  
  if (param_1 == 0x41) {
    uVar1 = *(undefined2 *)(_DAT_800abf64 + 0x11a);
  }
  else if (param_1 < 0x42) {
    uVar1 = 0;
    if (param_1 == 0x24) {
      uVar1 = *(undefined2 *)(_DAT_800abf64 + 0x118);
    }
  }
  else {
    uVar1 = 0x2019;
    if (param_1 == 0xf0) {
      uVar1 = 0xf0;
    }
    else if (param_1 != 0x2019) {
      uVar1 = 0;
    }
  }
  return uVar1;
}



// ---- FUN_8002ba74 @ 8002ba74

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002ba74(int param_1,int param_2)

{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = _DAT_800abf64;
  if (param_1 == 0x12) {
    uVar2 = 4;
    if (param_2 == 0) {
      uVar2 = 8;
    }
    *(undefined2 *)(_DAT_800abf64 + 0x11c) = uVar2;
    if (param_2 == 0) {
      uVar2 = 4;
    }
    else {
      uVar2 = 8;
    }
    *(undefined2 *)(iVar1 + 0x11e) = uVar2;
  }
  else if (param_1 == 0x41) {
    *(undefined2 *)(_DAT_800abf64 + 0x118) = (&DAT_80070948)[param_2 * 2];
    *(undefined2 *)(iVar1 + 0x11a) = (&DAT_8007094a)[param_2 * 2];
  }
  return;
}



// ---- FUN_8002bb54 @ 8002bb54

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_8002bb54(uint param_1)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  if (param_1 < 2) {
    *(char *)(_DAT_800abf64 + 0x100) = (char)param_1;
  }
  return *(undefined1 *)(iVar1 + 0x100);
}



// ---- FUN_8002bb78 @ 8002bb78

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_8002bb78(void)

{
  return *(undefined1 *)(_DAT_800abf64 + 0x101);
}



// ---- FUN_8002bb90 @ 8002bb90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002bb90(int param_1,undefined2 *param_2)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  if (param_1 == 0) {
    *(undefined1 *)(_DAT_800abf64 + 0x103) = 1;
    *(undefined2 *)(iVar1 + 0xfc) = *param_2;
    *(undefined2 *)(iVar1 + 0xfe) = param_2[1];
  }
  else if (param_1 == 1) {
    *param_2 = *(undefined2 *)(_DAT_800abf64 + 0xfc);
    param_2[1] = *(undefined2 *)(iVar1 + 0xfe);
  }
  return;
}



// ---- FUN_8002bbf0 @ 8002bbf0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_8002bbf0(uint param_1)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  if (param_1 < 2) {
    *(char *)(_DAT_800abf64 + 0x102) = (char)param_1;
  }
  return *(undefined1 *)(iVar1 + 0x102);
}



// ---- FUN_8002bc14 @ 8002bc14

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_8002bc14(uint param_1)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  if (param_1 < 2) {
    *(char *)(_DAT_800abf64 + 0x108) = (char)param_1;
  }
  return *(undefined1 *)(iVar1 + 0x108);
}



// ---- FUN_8002bc50 @ 8002bc50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_8002bc50(uint param_1)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  if (param_1 < 2) {
    *(char *)(_DAT_800abf64 + 0x111) = (char)param_1;
  }
  return *(undefined1 *)(iVar1 + 0x111);
}



// ---- FUN_8002bc74 @ 8002bc74

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_8002bc74(uint param_1)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  if (param_1 < 2) {
    *(char *)(_DAT_800abf64 + 0x112) = (char)param_1;
  }
  return *(undefined1 *)(iVar1 + 0x112);
}



// ---- FUN_8002bc98 @ 8002bc98

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_8002bc98(uint param_1)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  if (param_1 < 2) {
    *(char *)(_DAT_800abf64 + 0x10c) = (char)param_1;
  }
  return *(undefined1 *)(iVar1 + 0x10c);
}



// ---- FUN_8002bcbc @ 8002bcbc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_8002bcbc(uint param_1)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  if (param_1 < 2) {
    *(char *)(_DAT_800abf64 + 0x10d) = (char)param_1;
  }
  return *(undefined1 *)(iVar1 + 0x10d);
}



// ---- FUN_8002bce0 @ 8002bce0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_8002bce0(uint param_1)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  if (param_1 < 2) {
    *(char *)(_DAT_800abf64 + 0x10f) = (char)param_1;
  }
  return *(undefined1 *)(iVar1 + 0x10f);
}



// ---- FUN_8002bd04 @ 8002bd04

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_8002bd04(uint param_1)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  if (param_1 < 2) {
    *(char *)(_DAT_800abf64 + 0x110) = (char)param_1;
  }
  return *(undefined1 *)(iVar1 + 0x110);
}



// ---- FUN_8002bd28 @ 8002bd28

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_8002bd28(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0xffff;
  uVar1 = 0xffff;
  if (*(short *)(_DAT_800abf64 + 0x4c) == 0x4100) {
    uVar2 = (uint)CONCAT11(*(undefined1 *)(_DAT_800abf64 + 0x4e),
                           *(undefined1 *)(_DAT_800abf64 + 0x4f));
  }
  if ((*(uint *)(_DAT_800abf64 + 0x50) & 0xffff0000) == 0x41000000) {
    uVar1 = (uint)CONCAT11(*(undefined1 *)(_DAT_800abf64 + 0x54),
                           *(undefined1 *)(_DAT_800abf64 + 0x55));
  }
  return ~(uVar2 | uVar1 << 0x10);
}



// ---- FUN_8002bd8c @ 8002bd8c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_8002bd8c(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_18 [8];
  
  iVar2 = _DAT_800abf64 + 0x38;
  iVar1 = iVar2 + param_1 * 6;
  if ((*(char *)(iVar1 + 0x14) == '\0') && (*(char *)(iVar1 + 0x15) == '\x12')) {
    *(undefined1 *)(_DAT_800abf64 + 0x101) = 1;
    FUN_80029ff0(param_1);
    FUN_80029d74(param_1,auStack_18);
  }
  else {
    *(undefined1 *)(_DAT_800abf64 + 0x101) = 0;
    *param_2 = 0x80;
    param_2[1] = 0x50;
    param_2[2] = 0;
  }
  return *(undefined1 *)(iVar2 + param_1 * 6 + 0x14);
}



// ---- FUN_8002be40 @ 8002be40

void FUN_8002be40(void)

{
  FUN_8005fd10();
  return;
}



// ---- FUN_8002be60 @ 8002be60

void FUN_8002be60(void)

{
  int iVar1;
  undefined1 local_10 [8];
  
  local_10[0] = 0x80;
  do {
    iVar1 = FUN_8005e964(0xe,local_10,0);
  } while (iVar1 == 0);
  return;
}



// ---- FUN_8002be98 @ 8002be98

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002be98(void)

{
  int iVar1;
  int iVar2;
  undefined1 local_10 [8];
  
  iVar1 = _DAT_800abf64;
  local_10[0] = 200;
  iVar2 = _DAT_800abf64 + 0x58c;
  *(undefined4 *)(_DAT_800abf64 + 0x57c) = 0;
  *(undefined4 *)(iVar1 + 0x580) = 0;
  *(undefined1 *)(iVar1 + 0x584) = 2;
  *(undefined1 *)(iVar1 + 0x585) = 0;
  *(undefined1 *)(iVar1 + 0x586) = 0;
  *(undefined1 *)(iVar1 + 0x587) = 0;
  *(undefined1 *)(iVar1 + 0x588) = 0;
  FUN_800585e4(iVar2,8);
  do {
    iVar1 = FUN_8005e964(0xe,local_10,0);
  } while (iVar1 == 0);
  return;
}



// ---- FUN_8002bf04 @ 8002bf04

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8002bf04(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar1 = _DAT_800abf64;
  iVar4 = -1;
  puVar5 = (undefined4 *)(_DAT_800abf64 + 0x57c);
  FUN_80058314();
  puVar2 = (undefined4 *)FUN_8002ac50(0x1c);
  if (puVar2 == (undefined4 *)0x0) goto LAB_8002c128;
  *puVar2 = 0;
  puVar2[1] = param_1;
  puVar2[3] = param_3;
  puVar2[4] = param_4;
  puVar2[5] = param_5;
  puVar2[6] = 0;
  if (param_1 == 0xe) {
    *(undefined1 *)(puVar2 + 2) = *(undefined1 *)param_2;
  }
  else if (param_1 < 0xf) {
    if (param_1 < 6) {
      if (param_1 < 4) {
        if (param_1 == 2) goto LAB_8002c094;
        if (2 < param_1) goto LAB_8002c058;
      }
    }
    else if (param_1 < 0xd) {
      if (param_1 < 7) goto LAB_8002c058;
    }
    else {
      puVar2[2] = *param_2;
    }
  }
  else {
    if (param_1 != 0x1b) {
      if (0x1b < param_1) {
        if (param_1 == 0xfd) {
LAB_8002c0cc:
          puVar2[2] = param_2;
        }
        else if (param_1 < 0xfe) {
          if (param_1 == 0xfb) goto LAB_8002c0cc;
          if (param_1 == 0xfc) {
            puVar2[2] = *param_2;
            FUN_8005eb34(param_4,puVar2 + 4);
          }
        }
        else {
          if (param_1 == 0xfe) goto LAB_8002c094;
          if (param_1 == 0xff) goto LAB_8002c0cc;
        }
        goto LAB_8002c0d0;
      }
      if ((((param_1 < 0x10) || (param_1 < 0x12)) || (0x16 < param_1)) || (param_1 < 0x15))
      goto LAB_8002c0d0;
    }
LAB_8002c058:
    if (param_2 != (undefined4 *)0x0) {
LAB_8002c094:
      FUN_8005eb34(param_2,puVar2 + 2);
    }
  }
LAB_8002c0d0:
  piVar3 = (int *)*puVar5;
  if (piVar3 == (int *)0x0) {
    *puVar5 = puVar2;
  }
  else {
    iVar4 = *piVar3;
    while (iVar4 != 0) {
      piVar3 = (int *)*piVar3;
      iVar4 = *piVar3;
    }
    *piVar3 = (int)puVar2;
  }
  iVar4 = *(int *)(iVar1 + 0x580);
  *(int *)(iVar1 + 0x580) = iVar4 + 1;
LAB_8002c128:
  FUN_800585a4();
  return iVar4;
}



// ---- FUN_8002c164 @ 8002c164

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002c164(void)

{
  int iVar1;
  byte bVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined1 local_18 [8];
  
  iVar1 = _DAT_800abf64;
  puVar8 = *(undefined4 **)(_DAT_800abf64 + 0x57c);
  puVar9 = (undefined4 *)(_DAT_800abf64 + 0x57c);
  if (puVar8 == (undefined4 *)0x0) {
    FUN_8005e964(0x10,0,_DAT_800abf64 + 0x58c);
    return;
  }
  FUN_8005e964(1,0,local_18);
  *(undefined1 *)(iVar1 + 0x585) = local_18[0];
  bVar2 = FUN_8005e6c8(1,0);
  *(byte *)(iVar1 + 0x584) = bVar2;
  if (bVar2 != 2) {
    if (bVar2 < 3) {
      if (bVar2 == 0) {
        return;
      }
    }
    else if (bVar2 == 5) {
      puVar8[6] = 0;
      *(undefined1 *)(iVar1 + 0x587) = 1;
      return;
    }
  }
  if (*(char *)(iVar1 + 0x587) == '\x01') {
    *(undefined1 *)(iVar1 + 0x587) = 0;
    do {
      iVar4 = FUN_8005e964(10,0,0);
    } while (iVar4 == 0);
    do {
      iVar4 = FUN_8005e964(0xe,&DAT_80070978,0);
    } while (iVar4 == 0);
  }
  switch(puVar8[1]) {
  case 0xfb:
    *(undefined4 *)(iVar1 + 0x59c) = 0;
    *(undefined4 *)(iVar1 + 0x5a0) = puVar8[4];
    FUN_80031c9c(3);
    FUN_8003b460(puVar8[3],puVar8[2],0xffffffff);
    do {
      if (*(uint *)(iVar1 + 0x5a0) <= *(uint *)(iVar1 + 0x59c)) break;
      FUN_8003b278();
      FUN_8003b388();
      FUN_8002b4e8();
      uVar3 = FUN_8002ba04(0xf0);
      iVar4 = FUN_8002b8ac(0,uVar3,0,3,0);
    } while (iVar4 == 0);
    FUN_8003b590();
    FUN_80031c9c(3);
    FUN_80036704();
    FUN_80055d44();
    goto switchD_8002c398_caseD_4;
  case 0xfc:
    switch(puVar8[6]) {
    case 0:
      uVar5 = FUN_8005e918(0xd,puVar8 + 2,0);
      break;
    case 1:
      uVar5 = FUN_8005e918(2,puVar8 + 4,0);
      break;
    case 2:
      uVar7 = 200;
      goto LAB_8002c4d8;
    case 3:
      uVar5 = *(byte *)(iVar1 + 0x585) & 0x20;
      break;
    default:
      goto switchD_8002c398_caseD_4;
    }
    break;
  case 0xfd:
    iVar4 = puVar8[6];
    if (iVar4 == 1) {
      if ((*(byte *)(iVar1 + 0x585) & 0x20) == 0) {
        return;
      }
      puVar8[6] = 2;
      return;
    }
    if ((1 < iVar4) || (iVar4 != 0)) goto switchD_8002c398_caseD_4;
    uVar7 = puVar8[2];
LAB_8002c4d8:
    uVar5 = FUN_8005eac4(uVar7);
    break;
  case 0xfe:
    iVar4 = puVar8[6];
    if (iVar4 == 1) {
      uVar6 = puVar8[4];
      uVar5 = uVar6;
      if ((int)uVar6 < 0) {
        uVar5 = uVar6 + 0x7ff;
      }
      iVar4 = FUN_8005e9d0(((int)uVar5 >> 0xb) + (uint)((uVar6 & 0x7ff) != 0),puVar8[3],0x80);
      if (iVar4 == 0) {
        return;
      }
      puVar8[6] = puVar8[6] + 1;
      *(byte *)(iVar1 + 0x586) = *(byte *)(iVar1 + 0x586) | 1;
      return;
    }
    if (1 < iVar4) {
      if (iVar4 != 2) goto switchD_8002c398_caseD_4;
      iVar4 = FUN_8005e708(1,0);
      if (iVar4 == -1) {
        puVar8[6] = 0;
        return;
      }
      if (iVar4 != 0) {
        return;
      }
      *(byte *)(iVar1 + 0x586) = *(byte *)(iVar1 + 0x586) & 0xfe;
      goto LAB_8002c4e8;
    }
    if (iVar4 != 0) goto switchD_8002c398_caseD_4;
    uVar5 = FUN_8005e918(2,puVar8 + 2,0);
    break;
  case 0xff:
    FUN_80057420(puVar8[2],puVar8[3],puVar8[4]);
switchD_8002c398_caseD_4:
    if ((code *)puVar8[5] != (code *)0x0) {
      (*(code *)puVar8[5])(iVar1,0);
    }
    iVar4 = *(int *)(iVar1 + 0x580);
    *puVar9 = *puVar8;
    *(int *)(iVar1 + 0x580) = iVar4 + -1;
    FUN_8002af34(puVar8);
    return;
  default:
    if (puVar8[6] != 0) goto switchD_8002c398_caseD_4;
    uVar5 = FUN_8005e918(*(undefined1 *)(puVar8 + 1),puVar8 + 2,0);
  }
  if (uVar5 == 0) {
    return;
  }
LAB_8002c4e8:
  puVar8[6] = puVar8[6] + 1;
  return;
}



// ---- FUN_8002c57c @ 8002c57c

void FUN_8002c57c(int param_1,uint param_2,int param_3,undefined4 param_4)

{
  uint *puVar1;
  undefined **ppuVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  switch(param_3) {
  case 0:
    ppuVar2 = &PTR_DAT_80071e84;
    break;
  case 1:
    ppuVar2 = &PTR_DAT_8007205c;
    break;
  case 2:
    ppuVar2 = &PTR_DAT_800721c4;
    break;
  case 3:
    ppuVar2 = &PTR_DAT_800724c0;
    break;
  case 4:
    ppuVar2 = &PTR_DAT_80073cf4;
    break;
  case 5:
    ppuVar2 = &PTR_DAT_80074680;
    break;
  case 6:
    ppuVar2 = &PTR_DAT_800748e0;
    break;
  case 7:
    ppuVar2 = &PTR_DAT_800749fc;
    break;
  case 8:
    ppuVar2 = &PTR_DAT_80074a40;
    break;
  case 9:
    ppuVar2 = &PTR_DAT_80074a78;
    break;
  default:
    goto switchD_8002c5bc_default;
  }
  puVar1 = (uint *)ppuVar2[param_1];
  uVar6 = *puVar1;
  uVar4 = puVar1[1];
  uVar5 = puVar1[2];
  if (param_3 == 9) {
    FUN_8003b884(param_2 & 0xff);
    uVar3 = 0xfb;
    param_2 = uVar6;
  }
  else {
    uVar3 = 0xfe;
    if (uVar4 == 0) {
      uVar3 = 0xff;
    }
    else {
      uVar6 = uVar4;
    }
    uVar4 = uVar6;
  }
  FUN_8002bf04(uVar3,uVar4,param_2,uVar5,param_4);
switchD_8002c5bc_default:
  return;
}



// ---- FUN_8002c6e8 @ 8002c6e8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002c6e8(void)

{
  *(undefined4 *)(_DAT_800abf64 + 0x17e8) = 0;
  return;
}



// ---- FUN_8002c6f8 @ 8002c6f8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002c6f8(byte param_1,int param_2,undefined4 *param_3,ushort *param_4,char param_5)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined4 *puVar10;
  
  uVar5 = 0;
  uVar6 = 0;
  uVar9 = 0;
  uVar8 = 0;
  puVar10 = (undefined4 *)(_DAT_800abf64 + 0x17e8);
  uVar7 = 0;
  if (param_1 == 1) {
    if (param_4 == (ushort *)0x0) {
      return;
    }
    uVar5 = (uint)*param_4;
    uVar6 = (uint)param_4[1];
  }
  else {
    if (param_1 < 2) {
      if (param_1 != 0) goto LAB_8002c7d4;
    }
    else if (param_1 != 2) {
      if (param_1 == 3) {
        if (param_4 == (ushort *)0x0) {
          return;
        }
        uVar7 = (undefined1)*param_4;
        uVar8 = *(undefined1 *)((int)param_4 + 1);
        uVar9 = (undefined1)param_4[1];
      }
      goto LAB_8002c7d4;
    }
    if (param_2 == 0) {
      return;
    }
  }
LAB_8002c7d4:
  if (param_5 == '\x01') {
    if (param_1 == 1) {
      FUN_800599f4(param_3,uVar5,uVar6);
    }
    else if (param_1 < 2) {
      if (param_1 == 0) {
        FUN_8005997c(param_3,param_2);
      }
    }
    else if (param_1 == 2) {
      FUN_800599b8(param_3,param_2);
    }
    else if (param_1 == 3) {
      FUN_8005992c(param_3,uVar7,uVar8,uVar9);
    }
    FUN_800598fc(0);
  }
  else {
    puVar1 = (undefined4 *)FUN_8002ac50(0x20);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = 0;
      puVar1[1] = (uint)param_1;
      puVar1[2] = param_2;
      uVar4 = param_3[1];
      puVar1[3] = *param_3;
      puVar1[4] = uVar4;
      puVar1[5] = uVar5;
      puVar1[6] = uVar6;
      *(undefined1 *)(puVar1 + 7) = uVar7;
      *(undefined1 *)((int)puVar1 + 0x1d) = uVar8;
      *(undefined1 *)((int)puVar1 + 0x1e) = uVar9;
      piVar2 = (int *)*puVar10;
      if (piVar2 == (int *)0x0) {
        *puVar10 = puVar1;
      }
      else {
        iVar3 = *piVar2;
        while (iVar3 != 0) {
          piVar2 = (int *)*piVar2;
          iVar3 = *piVar2;
        }
        *piVar2 = (int)puVar1;
      }
    }
  }
  return;
}



// ---- FUN_8002c944 @ 8002c944

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002c944(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  piVar3 = *(int **)(_DAT_800abf64 + 0x17e8);
  puVar4 = (undefined4 *)(_DAT_800abf64 + 0x17e8);
  piVar2 = piVar3;
  if (piVar3 != (int *)0x0) {
    do {
      iVar1 = piVar2[1];
      if (iVar1 == 1) {
        FUN_800599f4(piVar2 + 3,piVar2[5],piVar2[6]);
      }
      else if (iVar1 < 2) {
        if (iVar1 == 0) {
          FUN_8005997c(piVar2 + 3,piVar2[2]);
        }
      }
      else if (iVar1 == 2) {
        FUN_800599b8(piVar2 + 3,piVar2[2]);
      }
      else if (iVar1 == 3) {
        FUN_8005992c(piVar2 + 3,(char)piVar2[7],*(undefined1 *)((int)piVar2 + 0x1d),
                     *(undefined1 *)((int)piVar2 + 0x1e));
      }
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)0x0);
    FUN_800598fc(0);
    do {
      piVar2 = (int *)*piVar3;
      FUN_8002af34(piVar3);
      piVar3 = piVar2;
    } while (piVar2 != (int *)0x0);
    *puVar4 = 0;
  }
  return;
}



// ---- FUN_8002ca58 @ 8002ca58

int FUN_8002ca58(undefined4 *param_1,undefined4 *param_2,int *param_3,uint *param_4,int param_5)

{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  puVar2 = (uint *)(param_3 + 1);
  if (*param_3 != 0) {
    if (param_5 == 0) {
      FUN_8003b924(puVar2,param_4);
      puVar2 = param_4;
    }
    else if (param_5 == 1) {
      uVar1 = FUN_8003b924(puVar2,param_4);
      FUN_80058604(puVar2,param_4,uVar1);
      *param_3 = 0;
    }
  }
  uVar3 = *puVar2;
  uVar4 = puVar2[1];
  if (param_1 != (undefined4 *)0x0) {
    if (uVar3 == 0) {
      *param_1 = 0;
      param_1[2] = 0;
    }
    else {
      FUN_8002cb60(param_1,puVar2 + 2);
    }
  }
  if (param_2 != (undefined4 *)0x0) {
    if (uVar4 == 0) {
      *param_2 = 0;
      param_2[2] = 0;
    }
    else {
      FUN_8002ced4(param_2,(int)(puVar2 + 2) + (uVar3 & 0xfffffffc));
    }
  }
  return uVar3 + uVar4;
}



// ---- FUN_8002cb60 @ 8002cb60

int * FUN_8002cb60(int *param_1,int *param_2)

{
  if (param_1 != (int *)0x0) {
    *param_1 = (int)param_2 + *param_2;
    param_1[1] = (uint)param_2 >> 2;
    param_1[2] = *(int *)(*param_1 + 8);
    param_1[3] = *(int *)(*param_1 + 0xc);
    param_1[4] = *(int *)(*param_1 + 0x10);
    param_1[5] = *(int *)(*param_1 + 0x14);
    param_1[6] = *(int *)(*param_1 + 0x18);
  }
  return param_2;
}



// ---- FUN_8002cbc8 @ 8002cbc8

void FUN_8002cbc8(int param_1,undefined1 *param_2,undefined1 *param_3)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  undefined1 *puVar5;
  short local_40;
  short local_3e;
  short local_38;
  short local_36;
  short local_30;
  short local_2e;
  short local_2c;
  short local_2a;
  
  if (((param_1 != 0) && (param_2 != (undefined1 *)0x0)) &&
     (uVar4 = 0, *(int *)(param_1 + 0x14) != 0)) {
    puVar5 = param_3;
    do {
      iVar2 = *(int *)(param_1 + 4) * 4;
      puVar3 = (uint *)(iVar2 + *(int *)(uVar4 * 4 + iVar2 + *(int *)(param_1 + 0xc)));
      FUN_80031e14(*param_2,&local_40);
      param_2 = param_2 + 1;
      if (param_3 != (undefined1 *)0x0) {
        FUN_80031e58(*puVar5,&local_38);
        local_40 = local_40 + local_38;
        local_3e = local_3e + local_36;
      }
      puVar5 = puVar5 + 1;
      uVar1 = *puVar3;
      local_2c = ((short)((uVar1 & 0xff) >> 1) - 1U & 0x3f) + 1;
      local_2a = (((ushort)(uVar1 >> 8) & 0xff) - 1 & 0x7f) + 1;
      local_30 = local_40;
      local_2e = local_3e;
      FUN_8002c6f8(0,puVar3 + 1,&local_30,0,1);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_1 + 0x14));
  }
  return;
}



// ---- FUN_8002cd20 @ 8002cd20

void FUN_8002cd20(int param_1,undefined1 *param_2,undefined1 *param_3,uint param_4,int param_5)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_38;
  undefined2 local_36;
  undefined2 local_34;
  undefined2 local_32;
  
  if (param_1 != 0) {
    if (param_5 < 0) {
      uVar3 = 0;
      if (*(int *)(param_1 + 0x18) != 0) {
        puVar4 = param_3;
        do {
          uVar1 = 0;
          if (param_3 != (undefined1 *)0x0) {
            uVar1 = *puVar4;
          }
          FUN_80031eb4(*param_2,uVar1,&local_40);
          local_38 = local_40;
          local_36 = local_3e;
          if ((param_4 & 0xff) == 0) {
            local_34 = 0x100;
          }
          else {
            local_34 = (undefined2)((param_4 & 0xff) << 4);
          }
          puVar4 = puVar4 + 1;
          local_32 = 1;
          iVar2 = *(int *)(param_1 + 4) * 4;
          param_2 = param_2 + 1;
          FUN_8002c6f8(0,iVar2 + *(int *)(uVar3 * 4 + iVar2 + *(int *)(param_1 + 0x10)),&local_38,0,
                       1);
          uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint *)(param_1 + 0x18));
      }
    }
    else {
      uVar1 = 0;
      if (param_3 != (undefined1 *)0x0) {
        uVar1 = *param_3;
      }
      FUN_80031eb4(*param_2,uVar1,&local_40);
      local_38 = local_40;
      local_36 = local_3e;
      if ((param_4 & 0xff) == 0) {
        local_34 = 0x100;
      }
      else {
        local_34 = (undefined2)((param_4 & 0xff) << 4);
      }
      local_32 = 1;
      iVar2 = *(int *)(param_1 + 4) * 4;
      FUN_8002c6f8(0,iVar2 + *(int *)(param_5 * 4 + iVar2 + *(int *)(param_1 + 0x10)),&local_38,0,1)
      ;
    }
  }
  return;
}



// ---- FUN_8002ced4 @ 8002ced4

int * FUN_8002ced4(int *param_1,int *param_2)

{
  if (param_1 != (int *)0x0) {
    *param_1 = (int)param_2 + *param_2;
    param_1[1] = (uint)param_2 >> 2;
    param_1[2] = *(int *)(*param_1 + 8);
    param_1[3] = *(int *)(*param_1 + 0xc);
    param_1[4] = *(int *)(*param_1 + 0x10);
    param_1[5] = *(int *)(*param_1 + 0x14);
    param_1[6] = *(int *)(*param_1 + 0x18);
    param_1[7] = *(int *)(*param_1 + 0x1c);
    param_1[8] = *(int *)(*param_1 + 0x20);
    param_1[9] = *(int *)(*param_1 + 0x24);
    param_1[10] = *(int *)(*param_1 + 0x28);
  }
  return param_2;
}



// ---- FUN_8002cf6c @ 8002cf6c

void FUN_8002cf6c(int param_1,undefined1 *param_2,undefined1 *param_3)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  undefined1 *puVar5;
  short local_40;
  short local_3e;
  short local_38;
  short local_36;
  short local_30;
  short local_2e;
  short local_2c;
  short local_2a;
  
  if (((param_1 != 0) && (param_2 != (undefined1 *)0x0)) &&
     (uVar4 = 0, *(int *)(param_1 + 0x24) != 0)) {
    puVar5 = param_3;
    do {
      iVar2 = *(int *)(param_1 + 4) * 4;
      puVar3 = (uint *)(iVar2 + *(int *)(uVar4 * 4 + iVar2 + *(int *)(param_1 + 0x14)));
      FUN_80031e14(*param_2,&local_40);
      param_2 = param_2 + 1;
      if (param_3 != (undefined1 *)0x0) {
        FUN_80031e58(*puVar5,&local_38);
        local_40 = local_40 + local_38;
        local_3e = local_3e + local_36;
      }
      puVar5 = puVar5 + 1;
      uVar1 = *puVar3;
      local_2c = ((short)((uVar1 & 0xff) >> 1) - 1U & 0x3f) + 1;
      local_2a = (((ushort)(uVar1 >> 8) & 0xff) - 1 & 0x7f) + 1;
      local_30 = local_40;
      local_2e = local_3e;
      FUN_8002c6f8(0,puVar3 + 1,&local_30,0,1);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_1 + 0x24));
  }
  return;
}



// ---- FUN_8002d0c4 @ 8002d0c4

void FUN_8002d0c4(int param_1,undefined1 param_2,uint param_3)

{
  int iVar1;
  byte *pbVar2;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_10;
  undefined2 local_e;
  short local_c;
  short local_a;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 4) * 4;
    pbVar2 = (byte *)(iVar1 + *(int *)((param_3 & 0xff) * 4 + iVar1 + *(int *)(param_1 + 0x14)));
    FUN_80031e14(param_2,&local_18);
    local_10 = local_18;
    local_e = local_16;
    local_c = ((*pbVar2 >> 1) - 1 & 0x3f) + 1;
    local_a = (pbVar2[1] - 1 & 0x7f) + 1;
    FUN_8002c6f8(0,pbVar2 + 4,&local_10,0,1);
  }
  return;
}



// ---- FUN_8002d178 @ 8002d178

void FUN_8002d178(int param_1,undefined1 *param_2,undefined1 *param_3,uint param_4,int param_5)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_38;
  undefined2 local_36;
  undefined2 local_34;
  undefined2 local_32;
  
  if (param_1 != 0) {
    if (param_5 < 0) {
      uVar3 = 0;
      if (*(int *)(param_1 + 0x28) != 0) {
        puVar4 = param_3;
        do {
          uVar1 = 0;
          if (param_3 != (undefined1 *)0x0) {
            uVar1 = *puVar4;
          }
          FUN_80031eb4(*param_2,uVar1,&local_40);
          local_38 = local_40;
          local_36 = local_3e;
          if ((param_4 & 0xff) == 0) {
            local_34 = 0x100;
          }
          else {
            local_34 = (undefined2)((param_4 & 0xff) << 4);
          }
          puVar4 = puVar4 + 1;
          local_32 = 1;
          iVar2 = *(int *)(param_1 + 4) * 4;
          param_2 = param_2 + 1;
          FUN_8002c6f8(0,iVar2 + *(int *)(uVar3 * 4 + iVar2 + *(int *)(param_1 + 0x18)),&local_38,0,
                       1);
          uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint *)(param_1 + 0x28));
      }
    }
    else {
      uVar1 = 0;
      if (param_3 != (undefined1 *)0x0) {
        uVar1 = *param_3;
      }
      FUN_80031eb4(*param_2,uVar1,&local_40);
      local_38 = local_40;
      local_36 = local_3e;
      if ((param_4 & 0xff) == 0) {
        local_34 = 0x100;
      }
      else {
        local_34 = (undefined2)((param_4 & 0xff) << 4);
      }
      local_32 = 1;
      iVar2 = *(int *)(param_1 + 4) * 4;
      FUN_8002c6f8(0,iVar2 + *(int *)(param_5 * 4 + iVar2 + *(int *)(param_1 + 0x18)),&local_38,0,1)
      ;
    }
  }
  return;
}



// ---- FUN_8002d32c @ 8002d32c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002d32c(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _DAT_800abf64;
  uVar2 = FUN_80058574(0xf4000001,4,0x1000,&LAB_8002d4c8);
  *(undefined4 *)(iVar1 + 0x13c) = uVar2;
  uVar2 = FUN_80058574(0xf4000001,0x8000,0x1000,&LAB_8002d4d8);
  *(undefined4 *)(iVar1 + 0x140) = uVar2;
  uVar2 = FUN_80058574(0xf4000001,0x100,0x1000,&LAB_8002d4ec);
  *(undefined4 *)(iVar1 + 0x144) = uVar2;
  uVar2 = FUN_80058574(0xf4000001,0x2000,0x1000,&LAB_8002d500);
  *(undefined4 *)(iVar1 + 0x148) = uVar2;
  uVar2 = FUN_80058574(0xf0000011,4,0x1000,&LAB_8002d514);
  *(undefined4 *)(iVar1 + 0x14c) = uVar2;
  uVar2 = FUN_80058574(0xf0000011,0x8000,0x1000,&LAB_8002d524);
  *(undefined4 *)(iVar1 + 0x150) = uVar2;
  uVar2 = FUN_80058574(0xf0000011,0x100,0x1000,&LAB_8002d538);
  *(undefined4 *)(iVar1 + 0x154) = uVar2;
  uVar2 = FUN_80058574(0xf0000011,0x2000,0x1000,&LAB_8002d54c);
  *(undefined4 *)(iVar1 + 0x158) = uVar2;
  FUN_80058364(*(undefined4 *)(iVar1 + 0x13c));
  FUN_80058364(*(undefined4 *)(iVar1 + 0x140));
  FUN_80058364(*(undefined4 *)(iVar1 + 0x144));
  FUN_80058364(*(undefined4 *)(iVar1 + 0x148));
  FUN_80058364(*(undefined4 *)(iVar1 + 0x14c));
  FUN_80058364(*(undefined4 *)(iVar1 + 0x150));
  FUN_80058364(*(undefined4 *)(iVar1 + 0x154));
  FUN_80058364(*(undefined4 *)(iVar1 + 0x158));
  FUN_800586b4(1);
  FUN_800586e4();
  FUN_800586f4();
  return;
}



// ---- FUN_8002d560 @ 8002d560

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002d560(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  FUN_80058304(*(undefined4 *)(_DAT_800abf64 + 0x13c));
  FUN_80058304(*(undefined4 *)(iVar1 + 0x140));
  FUN_80058304(*(undefined4 *)(iVar1 + 0x144));
  FUN_80058304(*(undefined4 *)(iVar1 + 0x148));
  FUN_80058304(*(undefined4 *)(iVar1 + 0x14c));
  FUN_80058304(*(undefined4 *)(iVar1 + 0x150));
  FUN_80058304(*(undefined4 *)(iVar1 + 0x154));
  FUN_80058304(*(undefined4 *)(iVar1 + 0x158));
  FUN_800586c4();
  return;
}



// ---- FUN_8002d5f0 @ 8002d5f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002d5f0(void)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = _DAT_800abf64;
  *(undefined4 *)(_DAT_800abf64 + 0x130) = 0;
  puVar1 = PTR_s_bu00_BISLPS_00154SNATCHER_800709b4;
  *(undefined4 *)(iVar2 + 0x138) = 0x801a6800;
  *(undefined1 *)(iVar2 + 0x15c) = 0;
  *(undefined1 *)(iVar2 + 0x15d) = 0;
  *(undefined1 *)(iVar2 + 0x15e) = 0xff;
  *(undefined1 *)(iVar2 + 0x15f) = 0xff;
  *(undefined4 *)(iVar2 + 0x160) = 0;
  *(undefined1 *)(iVar2 + 0x164) = 0xff;
  *(undefined **)(iVar2 + 0x134) = puVar1;
  return;
}



// ---- FUN_8002d634 @ 8002d634

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8002d634(undefined4 param_1,int param_2)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  
  iVar1 = _DAT_800abf64;
  cVar2 = (char)param_2;
  *(char *)(_DAT_800abf64 + 0x15d) = cVar2;
  uVar3 = param_2 << 4;
  switch(param_1) {
  case 1:
    iVar1 = FUN_80058694(uVar3 & 0xf0);
    break;
  case 2:
    iVar1 = FUN_80029ae4(uVar3 & 0xf0);
    break;
  case 3:
    iVar1 = FUN_80058684(uVar3 & 0xf0);
    break;
  case 4:
    iVar1 = FUN_800586d4(param_2);
    break;
  default:
    iVar1 = 0;
    break;
  case 0x10:
    *(undefined1 *)(iVar1 + 0x15c) = 0x10;
    iVar1 = 0x10;
    break;
  case 0x11:
    *(undefined1 *)(iVar1 + 0x15c) = 0x11;
    iVar1 = 0x11;
    break;
  case 0x12:
    *(undefined1 *)(iVar1 + 0x15c) = 0x12;
    iVar1 = 0x12;
    break;
  case 0x13:
    *(undefined1 *)(iVar1 + 0x15c) = 0x13;
    iVar1 = 0x13;
    break;
  case 0x14:
    *(undefined1 *)(iVar1 + 0x15c) = 0x14;
    iVar1 = 0x14;
    break;
  case 0x15:
    *(undefined1 *)(iVar1 + 0x15c) = 0x15;
    iVar1 = 0x15;
    break;
  case 0x20:
    iVar1 = (int)*(char *)(iVar1 + 0x15c);
    break;
  case 0x21:
    *(char *)(iVar1 + 0x164) = cVar2;
    iVar1 = (int)cVar2;
    break;
  case 0x22:
    iVar1 = (int)*(char *)(iVar1 + 0x164);
  }
  return iVar1;
}



// ---- FUN_8002d758 @ 8002d758

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8002d758(int param_1,int param_2)

{
  int iVar1;
  char *in_v1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if (param_1 == 0) {
    local_18 = *(undefined4 *)(_DAT_800abf64 + 0x13c);
    local_14 = *(undefined4 *)(_DAT_800abf64 + 0x140);
    local_10 = *(undefined4 *)(_DAT_800abf64 + 0x144);
    local_c = *(undefined4 *)(_DAT_800abf64 + 0x148);
    in_v1 = (char *)(_DAT_800abf64 + 0x15e);
  }
  else if (param_1 == 1) {
    local_18 = *(undefined4 *)(_DAT_800abf64 + 0x14c);
    local_14 = *(undefined4 *)(_DAT_800abf64 + 0x150);
    local_10 = *(undefined4 *)(_DAT_800abf64 + 0x154);
    local_c = *(undefined4 *)(_DAT_800abf64 + 0x158);
    in_v1 = (char *)(_DAT_800abf64 + 0x15f);
  }
  if (param_2 == 0) {
    iVar1 = (int)*in_v1;
    *(char *)(_DAT_800abf64 + 0x164) = *in_v1;
  }
  else if (param_2 == 1) {
    *(undefined1 *)(_DAT_800abf64 + 0x164) = 0xff;
    *in_v1 = -1;
    FUN_80058594(local_18);
    FUN_80058594(local_14);
    FUN_80058594(local_10);
    FUN_80058594(local_c);
    iVar1 = 1;
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}



// ---- FUN_8002d860 @ 8002d860

int FUN_8002d860(uint param_1,int param_2,char param_3)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  undefined *local_18 [2];
  
  local_18[0] = PTR_s_bu00___80028150;
  local_18[1] = PTR_s_bu10___80028154;
  if (param_3 == '\0') {
    puVar2 = (&PTR_s_bu00_BISLPS_00154SNATCHER_800709b4)[param_1 & 0xff];
  }
  else {
    puVar2 = local_18[param_1 & 0xff];
  }
  iVar1 = FUN_800585c4(puVar2,param_2);
  iVar3 = 1;
  if (iVar1 == 0) {
    iVar3 = 0;
  }
  else {
    while( true ) {
      param_2 = param_2 + 0x28;
      iVar1 = FUN_80058564(param_2);
      if (iVar1 == 0) break;
      iVar3 = iVar3 + 1;
    }
  }
  return iVar3;
}



// ---- FUN_8002d918 @ 8002d918

void FUN_8002d918(undefined2 *param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined **ppuVar9;
  int iVar10;
  int iVar11;
  
  FUN_800585e4(param_1,0x2000);
  uVar1 = DAT_80028158;
  iVar11 = 0;
  *(undefined1 *)(param_1 + 1) = 0x12;
  *(undefined1 *)((int)param_1 + 3) = 1;
  *param_1 = uVar1;
  FUN_80058644(param_1 + 2,&DAT_800709d4);
  uVar3 = DAT_80070b78;
  uVar2 = DAT_80070b74;
  *(undefined4 *)(param_1 + 0x30) = DAT_80070b70;
  *(undefined4 *)(param_1 + 0x32) = uVar2;
  *(undefined4 *)(param_1 + 0x34) = uVar3;
  uVar3 = DAT_80070b84;
  uVar2 = DAT_80070b80;
  *(undefined4 *)(param_1 + 0x36) = DAT_80070b7c;
  *(undefined4 *)(param_1 + 0x38) = uVar2;
  *(undefined4 *)(param_1 + 0x3a) = uVar3;
  uVar2 = DAT_80070b8c;
  *(undefined4 *)(param_1 + 0x3c) = DAT_80070b88;
  *(undefined4 *)(param_1 + 0x3e) = uVar2;
  ppuVar9 = &PTR_DAT_80070b64;
  iVar8 = 0x80;
  do {
    puVar5 = (undefined4 *)*ppuVar9;
    puVar6 = (undefined4 *)((int)param_1 + iVar8);
    puVar7 = puVar5 + 0x20;
    do {
      uVar2 = puVar5[1];
      uVar3 = puVar5[2];
      uVar4 = puVar5[3];
      *puVar6 = *puVar5;
      puVar6[1] = uVar2;
      puVar6[2] = uVar3;
      puVar6[3] = uVar4;
      puVar5 = puVar5 + 4;
      puVar6 = puVar6 + 4;
    } while (puVar5 != puVar7);
    ppuVar9 = ppuVar9 + 1;
    iVar11 = iVar11 + 1;
    iVar8 = iVar8 + 0x80;
  } while (iVar11 < 3);
  iVar8 = 0;
  iVar11 = 0x200;
  do {
    iVar10 = 0;
    puVar5 = (undefined4 *)((int)param_1 + iVar11);
    do {
      *puVar5 = 0;
      uVar2 = FUN_8002dbb4(puVar5);
      puVar5[0xef] = uVar2;
      iVar10 = iVar10 + 1;
      puVar5 = puVar5 + 0xf0;
    } while (iVar10 < 2);
    iVar8 = iVar8 + 1;
    iVar11 = iVar11 + 0x780;
  } while (iVar8 < 4);
  return;
}



// ---- FUN_8002da78 @ 8002da78

void FUN_8002da78(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    *param_1 = 1;
    FUN_8002dbe0(param_1,iVar2);
    uVar1 = FUN_8002dbb4(param_1);
    param_1[0xef] = uVar1;
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 0xf0;
  } while (iVar2 < 2);
  return;
}



// ---- FUN_8002dae0 @ 8002dae0

int FUN_8002dae0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = FUN_8002dbb4(param_1);
    if (*(int *)(param_1 + 0x3bc) == iVar1) {
      return iVar2;
    }
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 0x3c0;
  } while (iVar2 < 2);
  return -2;
}



// ---- FUN_8002db3c @ 8002db3c

void FUN_8002db3c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_88;
  undefined1 local_87;
  
  iVar1 = FUN_80058634(param_1,s_bu00__8002815c);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_80058634(param_1,s_bu10__80028164);
    uVar2 = 0x10;
    if (iVar1 != 0) {
      return;
    }
  }
  local_87 = 0xff;
  local_88 = 0xff;
  FUN_80058704();
  FUN_800586a4(uVar2,0,&local_88);
  return;
}



// ---- FUN_8002dbb4 @ 8002dbb4

byte FUN_8002dbb4(byte *param_1)

{
  uint uVar1;
  byte bVar2;
  
  bVar2 = 0;
  uVar1 = 0;
  do {
    uVar1 = uVar1 + 1;
    bVar2 = bVar2 ^ *param_1;
    param_1 = param_1 + 1;
  } while (uVar1 < 0x3bc);
  return bVar2;
}



// ---- FUN_8002dbe0 @ 8002dbe0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002dbe0(int param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  iVar2 = _DAT_800abf64;
  puVar8 = (undefined4 *)(_DAT_800abf64 + 0x195c);
  if (param_2 == 0) {
    *(uint *)(_DAT_800abf64 + 0x1ac8) =
         *(uint *)(_DAT_800abf64 + 0x1ac8) & 0xfffffc00 |
         ((*(uint *)(_DAT_800abf64 + 0x1ac8) & 0x3ff) + 1 & 0x3ff) % 1000;
  }
  else if (param_2 != 1) {
    return;
  }
  *puVar8 = *(undefined4 *)(iVar2 + 0x1ac4);
  *(undefined4 *)(iVar2 + 0x1960) = *(undefined4 *)(iVar2 + 0x1b30);
  *(undefined4 *)(iVar2 + 0x1964) = *(undefined4 *)(iVar2 + 0x1b34);
  uVar3 = 0xffffffff;
  if ((*(uint *)(iVar2 + 0x1af4) & 2) != 0) {
    uVar3 = *(undefined4 *)(iVar2 + 0x1aec);
  }
  *(undefined4 *)(iVar2 + 0x1968) = uVar3;
  uVar3 = 0xffffffff;
  if ((*(uint *)(iVar2 + 0x1b04) & 1) != 0) {
    uVar3 = *(undefined4 *)(iVar2 + 0x1afc);
  }
  *(undefined4 *)(iVar2 + 0x196c) = uVar3;
  *(undefined4 *)(iVar2 + 0x1970) = *(undefined4 *)(iVar2 + 0x1b10);
  *(uint *)(iVar2 + 0x1974) = (uint)*(ushort *)(iVar2 + 0x57a);
  *(uint *)(iVar2 + 0x1978) = *(uint *)(iVar2 + 0x1acc) >> 4 & 3;
  puVar7 = (undefined4 *)(param_1 + 0x16c);
  *(uint *)(iVar2 + 0x197c) = *(uint *)(iVar2 + 0x1ac8) & 0x3ff;
  puVar6 = (undefined4 *)&DAT_800abff4;
  *(uint *)(iVar2 + 0x1980) = (uint)*(byte *)(iVar2 + 0x1dec);
  *(uint *)(iVar2 + 0x1984) = (uint)*(ushort *)(iVar2 + 0x1de4);
  *(uint *)(iVar2 + 0x1988) = *(uint *)(iVar2 + 0x1d80) >> 1 & 1;
  if (((uint)puVar7 & 3) == 0) {
    do {
      uVar3 = puVar6[1];
      uVar4 = puVar6[2];
      uVar5 = puVar6[3];
      *puVar7 = *puVar6;
      puVar7[1] = uVar3;
      puVar7[2] = uVar4;
      puVar7[3] = uVar5;
      puVar6 = puVar6 + 4;
      puVar7 = puVar7 + 4;
    } while (puVar6 != (undefined4 *)0x800ac1a4);
  }
  else {
    do {
      uVar3 = puVar6[1];
      uVar4 = puVar6[2];
      uVar5 = puVar6[3];
      *puVar7 = *puVar6;
      puVar7[1] = uVar3;
      puVar7[2] = uVar4;
      puVar7[3] = uVar5;
      puVar6 = puVar6 + 4;
      puVar7 = puVar7 + 4;
    } while (puVar6 != (undefined4 *)0x800ac1a4);
    puVar6 = (undefined4 *)0x800ac1a4;
  }
  uVar3 = puVar6[1];
  uVar1 = *(undefined1 *)(puVar6 + 2);
  *puVar7 = *puVar6;
  puVar7[1] = uVar3;
  *(undefined1 *)(puVar7 + 2) = uVar1;
  puVar6 = (undefined4 *)(param_1 + 8);
  do {
    uVar3 = puVar8[1];
    uVar4 = puVar8[2];
    uVar5 = puVar8[3];
    *puVar6 = *puVar8;
    puVar6[1] = uVar3;
    puVar6[2] = uVar4;
    puVar6[3] = uVar5;
    puVar8 = puVar8 + 4;
    puVar6 = puVar6 + 4;
  } while (puVar8 != (undefined4 *)(iVar2 + 0x1abc));
  *puVar6 = *puVar8;
  FUN_800585e4(param_1 + 0x325,0x97);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar2 + 0x1dc8);
  return;
}



// ---- FUN_8002de7c @ 8002de7c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002de7c(int param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  undefined4 *puVar10;
  int *piVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  int local_40 [7];
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  
  iVar2 = _DAT_800abf64;
  piVar11 = local_40;
  puVar13 = (undefined4 *)(_DAT_800abf64 + 0x195c);
  piVar9 = (int *)(_DAT_800abf64 + 0x1a90);
  do {
    iVar3 = piVar9[1];
    iVar5 = piVar9[2];
    iVar7 = piVar9[3];
    *piVar11 = *piVar9;
    piVar11[1] = iVar3;
    piVar11[2] = iVar5;
    piVar11[3] = iVar7;
    piVar9 = piVar9 + 4;
    piVar11 = piVar11 + 4;
  } while (piVar9 != (int *)(_DAT_800abf64 + 0x1ac0));
  puVar10 = (undefined4 *)(param_1 + 0x16c);
  if (param_2 == 0) {
    puVar12 = (undefined4 *)&DAT_800abff4;
    *(undefined4 *)(_DAT_800abf64 + 0x1dc8) = *(undefined4 *)(param_1 + 4);
    _DAT_800afec8 = *(undefined4 *)(param_1 + 4);
    _DAT_800b04ac = 0;
    if (((uint)puVar10 & 3) == 0) {
      do {
        uVar4 = puVar10[1];
        uVar6 = puVar10[2];
        uVar8 = puVar10[3];
        *puVar12 = *puVar10;
        puVar12[1] = uVar4;
        puVar12[2] = uVar6;
        puVar12[3] = uVar8;
        puVar10 = puVar10 + 4;
        puVar12 = puVar12 + 4;
      } while (puVar10 != (undefined4 *)(param_1 + 0x31c));
    }
    else {
      do {
        uVar4 = puVar10[1];
        uVar6 = puVar10[2];
        uVar8 = puVar10[3];
        *puVar12 = *puVar10;
        puVar12[1] = uVar4;
        puVar12[2] = uVar6;
        puVar12[3] = uVar8;
        puVar10 = puVar10 + 4;
        puVar12 = puVar12 + 4;
      } while (puVar10 != (undefined4 *)(param_1 + 0x31c));
    }
    uVar4 = puVar10[1];
    uVar1 = *(undefined1 *)(puVar10 + 2);
    *puVar12 = *puVar10;
    puVar12[1] = uVar4;
    *(undefined1 *)(puVar12 + 2) = uVar1;
    puVar12 = (undefined4 *)(param_1 + 8);
    puVar10 = puVar13;
    do {
      uVar4 = puVar12[1];
      uVar6 = puVar12[2];
      uVar8 = puVar12[3];
      *puVar10 = *puVar12;
      puVar10[1] = uVar4;
      puVar10[2] = uVar6;
      puVar10[3] = uVar8;
      puVar12 = puVar12 + 4;
      puVar10 = puVar10 + 4;
    } while (puVar12 != (undefined4 *)(param_1 + 0x168));
    *puVar10 = *puVar12;
    FUN_800585e4(param_1 + 0x325,0x97);
    uVar4 = *puVar13;
    *(undefined4 *)(iVar2 + 0x1b30) = 0xffffffff;
    *(undefined4 *)(iVar2 + 0x1b34) = 0xffffffff;
    *(undefined4 *)(iVar2 + 0x1aec) = 0xffffffff;
    *(undefined4 *)(iVar2 + 0x1afc) = 0xffffffff;
    *(undefined4 *)(iVar2 + 0x1b08) = 0xffffffff;
    *(undefined4 *)(iVar2 + 0x1ac4) = uVar4;
    *(undefined2 *)(iVar2 + 0x57a) = 7;
    *(uint *)(iVar2 + 0x1acc) =
         *(uint *)(iVar2 + 0x1acc) & 0xffffffcf | (*(uint *)(iVar2 + 0x1978) & 3) << 4;
    *(uint *)(iVar2 + 0x1ac8) =
         *(uint *)(iVar2 + 0x1ac8) & 0xfffffc00 | *(uint *)(iVar2 + 0x197c) & 0x3ff;
    *(undefined1 *)(iVar2 + 0x1dec) = *(undefined1 *)(iVar2 + 0x1980);
    *(undefined2 *)(iVar2 + 0x1de4) = *(undefined2 *)(iVar2 + 0x1984);
    *(uint *)(iVar2 + 0x1d80) =
         *(uint *)(iVar2 + 0x1d80) & 0xfffffffd | (*(uint *)(iVar2 + 0x1988) & 1) << 1;
    if (local_40[0] != -1) {
      *(int *)(iVar2 + 0x1a90) = local_40[0];
    }
    if (local_40[1] != -1) {
      *(int *)(iVar2 + 0x1a94) = local_40[1];
    }
    if (local_40[2] != -1) {
      *(int *)(iVar2 + 0x1a98) = local_40[2];
    }
    if (local_40[3] != -1) {
      *(int *)(iVar2 + 0x1a9c) = local_40[3];
    }
    if (local_40[4] != -1) {
      *(int *)(iVar2 + 0x1aa0) = local_40[4];
    }
    if (local_40[5] != -1) {
      *(int *)(iVar2 + 0x1aa4) = local_40[5];
    }
    if (local_40[6] != -1) {
      *(int *)(iVar2 + 0x1aa8) = local_40[6];
    }
    if (local_24 != -1) {
      *(int *)(iVar2 + 0x1aac) = local_24;
    }
    if (local_20 != -1) {
      *(int *)(iVar2 + 0x1ab0) = local_20;
    }
    if (local_1c != -1) {
      *(int *)(iVar2 + 0x1ab4) = local_1c;
    }
    if (local_18 != -1) {
      *(int *)(iVar2 + 0x1ab8) = local_18;
    }
  }
  return;
}



// ---- FUN_8002e1a4 @ 8002e1a4

int FUN_8002e1a4(undefined2 param_1)

{
  short sVar1;
  
  sVar1 = FUN_80030318(param_1);
  return (int)sVar1;
}



// ---- FUN_8002e1cc @ 8002e1cc

void FUN_8002e1cc(void)

{
  ushort uVar1;
  ushort uVar2;
  
  while( true ) {
    uVar1 = FUN_80030388();
    uVar2 = uVar1 & 0xf00;
    if (uVar1 == 0) break;
    if (uVar2 == 0x300) {
      FUN_8002eefc();
    }
    else if (uVar2 < 0x301) {
      if (uVar2 == 0) {
        FUN_8002e7f8();
      }
      else if (uVar2 == 0x200) {
        FUN_8002f84c();
      }
    }
    else if (uVar2 == 0x600) {
      FUN_800300cc();
    }
    else if (uVar2 < 0x601) {
      if (uVar2 == 0x500) {
        FUN_80030088();
      }
    }
    else if (uVar2 == 0x700) {
      FUN_80030110();
    }
  }
  FUN_8002e4ac();
  FUN_8002e6c4();
  FUN_80030378();
  return;
}



// ---- FUN_8002e2d4 @ 8002e2d4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002e2d4(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  while( true ) {
    uVar2 = 0x1000000 << (uVar1 & 0x1f) & 0xf000000;
    uVar3 = 0x10000000 << (uVar1 & 0x1f) & 0xf0000000;
    if (((_DAT_800ab650 & 0xff000000 & uVar2) != 0) && ((_DAT_800ab650 & 0xf0000000) == 0)) break;
    uVar1 = uVar1 + 1;
    if (3 < uVar1) {
      return;
    }
  }
  _DAT_800ab650 = uVar3 | ~uVar2 & _DAT_800ab650;
  FUN_8002e390((int)(short)uVar1);
  _DAT_800ab650 = ~uVar3 & _DAT_800ab650;
  return;
}



// ---- FUN_8002e390 @ 8002e390

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002e390(short param_1)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = (uint)param_1;
  iVar4 = uVar3 * 4;
  sVar1 = FUN_80066d40(*(undefined4 *)(&DAT_800ab2c0 + iVar4),uVar3,
                       *(undefined4 *)(&DAT_800ab5bc + iVar4));
  if (sVar1 == -1) {
    uVar2 = 0x1010000;
  }
  else {
    _DAT_800ab64c = 0x10000 << (uVar3 & 0x1f) | _DAT_800ab64c;
    sVar1 = FUN_80067328(*(undefined4 *)(&DAT_800ab4fc + iVar4),uVar3);
    uVar2 = 0x1020000;
    if (sVar1 != -1) {
      FUN_8006a53c(1);
      return;
    }
  }
  FUN_800319ec((uVar3 & 0xff) << 8 | uVar2);
  return;
}



// ---- FUN_8002e4ac @ 8002e4ac

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002e4ac(void)

{
  if ((_DAT_800ab64c & 0x400) != 0) {
    FUN_8002e4fc();
  }
  if ((_DAT_800ab650 & 0x200) != 0) {
    FUN_8002e56c();
  }
  return;
}



// ---- FUN_8002e4fc @ 8002e4fc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002e4fc(void)

{
  uint uVar1;
  
  uVar1 = FUN_80031968();
  if (uVar1 < _DAT_800ab658) {
    FUN_80030c28(&DAT_800ac948);
  }
  else if ((_DAT_800ab650 & 0x100) == 0) {
    FUN_8002f51c(0xb4);
  }
  return;
}



// ---- FUN_8002e56c @ 8002e56c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002e56c(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FUN_8003190c();
  if ((uVar1 & 4) != 0) {
    _DAT_800ab650 = _DAT_800ab650 & 0xfffffdff;
    if (_DAT_800ab65c == 0) {
      if ((_DAT_800ab64c & 0x4000) == 0) {
        _DAT_800ab64c = _DAT_800ab64c & 0xffefffff | 0x400;
        _DAT_800ab668 = _DAT_800ab66c;
        _DAT_800ab66a = _DAT_800ab66e;
        FUN_8002eb7c(0x7f,0x7f);
        if ((_DAT_800ab64c & 0x20) == 0) {
          iVar3 = (int)_DAT_800ab668;
          iVar2 = (int)_DAT_800ab66a;
        }
        else {
          iVar2 = (int)_DAT_800ab668;
          iVar3 = (int)_DAT_800ab66a;
          if (iVar3 < iVar2) {
            iVar3 = iVar2;
          }
          else {
            iVar2 = iVar3;
          }
        }
        FUN_8006a388(0,iVar3,iVar2);
        FUN_8006bbac(0,0,1);
      }
    }
    else {
      FUN_8002f2d4(0x74);
      FUN_8002f188();
      if ((_DAT_800ab64c & 0x4000) == 0) {
        FUN_8002f268(_DAT_800ab654);
      }
    }
  }
  return;
}



// ---- FUN_8002e6c4 @ 8002e6c4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002e6c4(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (_DAT_800ab650 != 0) {
    if ((_DAT_800ab650 & 0xff000000) != 0) {
      uVar1 = 0;
      do {
        uVar2 = 0x1000000 << (uVar1 & 0x1f) & 0xf000000;
        uVar3 = 0x10000000 << (uVar1 & 0x1f) & 0xf0000000;
        if (((_DAT_800ab650 & 0xff000000 & uVar2) != 0) && ((_DAT_800ab650 & 0xf0000000) == 0)) {
          _DAT_800ab650 = uVar3 | ~uVar2 & _DAT_800ab650;
          FUN_8002e390((int)(short)uVar1);
          _DAT_800ab650 = ~uVar3 & _DAT_800ab650;
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 4);
    }
    if (DAT_800ab650 != '\0') {
      FUN_8002f5a8();
    }
    if ((_DAT_800ab650 & 0xff00) != 0) {
      FUN_8002ecd0();
    }
    if ((_DAT_800ab650 & 0xff0000) != 0) {
      FUN_8002fde0();
    }
  }
  return;
}



// ---- FUN_8002e7f8 @ 8002e7f8

void FUN_8002e7f8(ushort param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar1 = param_1 & 0xf0;
  if (uVar1 != 0xb0) {
    if (uVar1 < 0xb1) {
      if (uVar1 == 0x20) {
        FUN_8003087c(0x800dc800);
        return;
      }
      if (uVar1 < 0x21) {
        if (uVar1 == 0x10) {
          FUN_8002e9a4(param_1);
          return;
        }
      }
      else if (uVar1 == 0x70) {
        if ((param_1 & 1) != 0) {
          FUN_8002fbec(0x71);
        }
        if ((param_1 & 2) != 0) {
          FUN_800304c8();
        }
        uVar2 = 0x74;
        goto joined_r0x8002e8fc;
      }
LAB_8002e984:
      FUN_8002ea54(param_1 & 0xff);
      return;
    }
    if (uVar1 != 0xd0) {
      if (0xd0 < uVar1) {
        if (uVar1 == 0xe0) {
          if ((param_1 & 1) != 0) {
            FUN_8002fbec(0xe1);
          }
          uVar2 = 0xe4;
        }
        else {
          if (uVar1 != 0xf0) goto LAB_8002e984;
          if ((param_1 & 1) != 0) {
            FUN_8002fbec(0xf1);
          }
          uVar2 = 0xf4;
        }
joined_r0x8002e8fc:
        if ((param_1 & 4) == 0) {
          return;
        }
        FUN_8002f2d4(uVar2);
        FUN_8002f188();
        return;
      }
      if (uVar1 != 0xc0) goto LAB_8002e984;
    }
  }
  if ((param_1 & 1) != 0) {
    FUN_8002fd68(param_1 & 0xfff1);
  }
  if ((param_1 & 4) != 0) {
    FUN_8002f51c(param_1 & 0xfff4);
  }
  return;
}



// ---- FUN_8002e9a4 @ 8002e9a4

void FUN_8002e9a4(byte param_1)

{
  undefined4 uVar1;
  
  FUN_80030688(param_1);
  if (param_1 == 0x12) {
    FUN_80030b20(1);
    uVar1 = 1;
  }
  else if (param_1 < 0x13) {
    if (param_1 != 0x11) {
      return;
    }
    FUN_80030b20(0);
    uVar1 = 0;
  }
  else if (param_1 == 0x14) {
    FUN_80030b20(2);
    uVar1 = 2;
  }
  else {
    if (param_1 != 0x18) {
      return;
    }
    FUN_80030b20(3);
    uVar1 = 3;
  }
  FUN_80030a6c(uVar1);
  return;
}



// ---- FUN_8002ea54 @ 8002ea54

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002ea54(undefined1 param_1)

{
  switch(param_1) {
  case 1:
  case 2:
    FUN_800308e0();
    break;
  case 3:
    FUN_80030428();
    break;
  case 4:
    FUN_800304c8();
    break;
  case 5:
    _DAT_800ab64c = _DAT_800ab64c | 0x100000;
    break;
  case 6:
    _DAT_800ab64c = _DAT_800ab64c | 4;
    FUN_8002eb7c(0xffffffff,0xffffffff);
    break;
  case 7:
    _DAT_800ab64c = _DAT_800ab64c & 0xfffffffb;
    FUN_8002eb7c(0xfffffffe,0xfffffffe);
    break;
  case 8:
    _DAT_800ab64c = _DAT_800ab64c | 8;
    break;
  case 9:
    _DAT_800ab64c = _DAT_800ab64c & 0xfffffff7;
    break;
  case 10:
    FUN_80030378();
  }
  return;
}



// ---- FUN_8002eb7c @ 8002eb7c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002eb7c(ushort param_1,ushort param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  ushort local_10;
  ushort local_e;
  
  uVar2 = (uint)(short)param_1;
  if (uVar2 == 0xffffffff) {
    FUN_800671d4(&local_10);
    local_10 = local_10 >> 3;
    local_e = local_e >> 3;
  }
  else if (uVar2 == 0xfffffffe) {
    FUN_800671d4(&local_10);
  }
  else if ((_DAT_800ab64c & 4) == 0) {
    local_e = param_2;
    local_10 = param_1;
  }
  else {
    if ((int)uVar2 < 0) {
      uVar2 = uVar2 + 7;
    }
    uVar1 = (uint)(short)param_2;
    local_10 = (ushort)(uVar2 >> 3);
    if ((int)uVar1 < 0) {
      uVar1 = uVar1 + 7;
    }
    local_e = (ushort)(uVar1 >> 3);
  }
  if ((_DAT_800ab64c & 0x20) == 0) {
    iVar3 = (int)(short)local_10;
    iVar4 = (int)(short)local_e;
  }
  else {
    iVar3 = (((int)(short)local_10 + (int)(short)local_e) -
            ((int)(short)local_10 + (int)(short)local_e >> 0x1f)) * 0x8000 >> 0x10;
    iVar4 = iVar3;
  }
  FUN_80067284(iVar3,iVar4);
  return;
}



// ---- FUN_8002ec84 @ 8002ec84

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_8002ec84(void)

{
  uint uVar1;
  
  uVar1 = 1;
  if (((_DAT_800ab650 & 0x200) == 0) && (uVar1 = 2, (_DAT_800ab650 & 0x100) == 0)) {
    uVar1 = 3;
    if ((_DAT_800ab64c & 0x4000) == 0) {
      uVar1 = _DAT_800ab64c >> 8 & 4;
    }
  }
  return uVar1;
}



// ---- FUN_8002ecd0 @ 8002ecd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002ecd0(void)

{
  if ((_DAT_800ab650 & 0x100) != 0) {
    FUN_8002ed00();
  }
  return;
}



// ---- FUN_8002ed00 @ 8002ed00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002ed00(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  uVar1 = _DAT_800ab688;
  if ((_DAT_800ab64c & 0x4400) != 0) {
    _DAT_800ab686 = _DAT_800ab686 + 1;
    uVar4 = FUN_8006f2a4((uint)_DAT_800ab688 - (uint)_DAT_800ab686);
    uVar5 = FUN_8006f2a4((int)(short)uVar1);
    if ((short)uVar1 < 0) {
      uVar5 = FUN_8006f3a0((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40f00000);
    }
    uVar5 = FUN_8006f88c((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),(int)uVar5,
                         (int)((ulonglong)uVar5 >> 0x20));
    uVar3 = (undefined4)((ulonglong)uVar5 >> 0x20);
    if (_DAT_800ab668 < 1) {
      _DAT_800ab668 = _DAT_800ab668 & 0xffff0000;
    }
    else {
      uVar4 = FUN_8006f2a4((int)_DAT_800ab66c);
      uVar4 = FUN_8006fb6c((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),(int)uVar5,uVar3);
      uVar2 = FUN_8007076c((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
      _DAT_800ab668 = CONCAT22(_DAT_800ab66a,uVar2);
    }
    if (_DAT_800ab66a < 1) {
      _DAT_800ab668 = _DAT_800ab668 & 0xffff;
    }
    else {
      uVar4 = FUN_8006f2a4((int)_DAT_800ab66e);
      uVar5 = FUN_8006fb6c((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),(int)uVar5,uVar3);
      uVar2 = FUN_8007076c((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
      _DAT_800ab668 = CONCAT22(uVar2,_DAT_800ab668);
    }
    if (_DAT_800ab668 == 0) {
      FUN_8002eea0();
    }
    else {
      FUN_8006a388(0,(int)_DAT_800ab668,(int)_DAT_800ab66a);
    }
  }
  return;
}



// ---- FUN_8002eea0 @ 8002eea0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002eea0(void)

{
  FUN_8002f2d4(0x74);
  if ((_DAT_800ab64c & 0x4000) == 0) {
    FUN_8002f188();
    if (_DAT_800ab654 != 0) {
      FUN_8002f268();
    }
  }
  return;
}



// ---- FUN_8002eefc @ 8002eefc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002eefc(uint param_1)

{
  undefined2 uVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  
  param_1 = param_1 & 0xf000;
  if (param_1 == 0x1000) {
    FUN_8002f2d4(0x74);
    FUN_8002f188();
  }
  else if (param_1 < 0x1001) {
    if (param_1 == 0) {
      puVar2 = (uint *)FUN_800318d4();
      uVar6 = puVar2[1];
      iVar3 = (*puVar2 & 0xff) + 0x1b;
      _DAT_800ab65c = puVar2[2] & 0xffffff;
      DAT_800ab693 = (byte)(puVar2[2] >> 0x18);
      _DAT_800ab660 = puVar2[3] & 0xffffff;
      DAT_800ab695 = (undefined1)(puVar2[3] >> 0x18);
      uVar1 = 0x7f;
      if ((*puVar2 >> 8 & 1) == 0) {
        uVar5 = (uint)(iVar3 * iVar3) >> 0xc;
        iVar3 = uVar5 * 8;
        uVar7 = FUN_8006fb6c(0,0x405fc000,*(undefined4 *)(&DAT_80070c80 + iVar3),
                             *(undefined4 *)(&DAT_80070c84 + iVar3));
        _DAT_800ab670 = FUN_8007076c((int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
        iVar3 = (0xf - uVar5) * 8;
        uVar7 = FUN_8006fb6c(0,0x405fc000,*(undefined4 *)(&DAT_80070c80 + iVar3),
                             *(undefined4 *)(&DAT_80070c84 + iVar3));
        uVar1 = FUN_8007076c((int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
        iVar3 = 0x10;
      }
      else {
        _DAT_800ab670 = 0x7f;
        iVar3 = 8;
      }
      _DAT_800ab65c = iVar3 * _DAT_800ab65c + (uint)DAT_800ab693 + uVar6 + -0x10;
      _DAT_800ab660 = iVar3 * _DAT_800ab660 + (uint)DAT_800ab693 + uVar6 + 0x40;
      _DAT_800ab672 = uVar1;
      if ((_DAT_800ab64c & 0x400) == 0) {
        if (((_DAT_800ab650 & 0x200) == 0) && ((_DAT_800ab64c & 0x4000) == 0)) {
          FUN_8002f188();
          FUN_8002f268(_DAT_800ab654);
        }
      }
      else {
        FUN_8002f51c(0xb4);
      }
    }
  }
  else {
    if (param_1 == 0x2000) {
      uVar4 = 0xe4;
    }
    else {
      uVar4 = 0xf4;
      if (param_1 != 0x4000) {
        return;
      }
    }
    FUN_8002f2d4(uVar4);
  }
  return;
}



// ---- FUN_8002f188 @ 8002f188

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002f188(void)

{
  DAT_800ab694 = DAT_800ab695;
  DAT_800ab692 = DAT_800ab693;
  _DAT_800ab658 = _DAT_800ab660;
  _DAT_800ab654 = _DAT_800ab65c;
  _DAT_800ac948 = 0;
  _DAT_800ac94a = 0;
  _DAT_800ab65c = 0;
  _DAT_800ab660 = 0;
  DAT_800ab693 = 0;
  DAT_800ab695 = 0;
  _DAT_800ab668 = _DAT_800ab670;
  _DAT_800ab66c = _DAT_800ab670;
  _DAT_800ab66a = _DAT_800ab672;
  _DAT_800ab66e = _DAT_800ab672;
  _DAT_800ab664 = _DAT_800ab654;
  _DAT_800ab64c = _DAT_800ab64c & 0xffffbbff;
  _DAT_800ab650 = _DAT_800ab650 & 0xfffffcff;
  return;
}



// ---- FUN_8002f268 @ 8002f268

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002f268(undefined4 param_1)

{
  FUN_80030730();
  _DAT_800ab650 = _DAT_800ab650 | 0x200;
  DAT_800ab68e = DAT_800ab694;
  DAT_800ab68f = DAT_800ab692;
  FUN_800319b0(0xd,param_1);
  return;
}



// ---- FUN_8002f2d4 @ 8002f2d4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002f2d4(byte param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  uVar2 = _DAT_800ab664;
  if (param_1 == 0xe4) {
    uVar1 = 9;
    if ((_DAT_800ab650 & 0x200) == 0) {
      if ((_DAT_800ab64c & 0x400) == 0) {
        return;
      }
      _DAT_800ab664 = FUN_80031968(9);
      if (_DAT_800ab664 <= _DAT_800ab654) {
        _DAT_800ab664 = _DAT_800ab654;
      }
      _DAT_800ab64c = _DAT_800ab64c & 0xfffffbff | 0x4000;
      FUN_8002f51c(0xb4);
      return;
    }
    uVar2 = 0;
    _DAT_800ab64c = _DAT_800ab64c | 0x4000;
    puVar3 = (undefined1 *)0x0;
  }
  else {
    if (param_1 < 0xe5) {
      if (param_1 == 0x74) {
        FUN_8006bbac(0,0,0);
        FUN_800319b0(9,0,0);
        _DAT_800ab64c = _DAT_800ab64c & 0xffffbbff;
        _DAT_800ab650 = _DAT_800ab650 & 0xfffffcff;
        return;
      }
      return;
    }
    if (param_1 != 0xf4) {
      return;
    }
    if ((_DAT_800ab64c & 0x4000) == 0) {
      return;
    }
    _DAT_800ab64c = _DAT_800ab64c & 0xffffbfff;
    if (_DAT_800ab65c != 0) {
      FUN_8002f2d4(0x74);
      if ((_DAT_800ab64c & 0x4000) != 0) {
        return;
      }
      FUN_8002f188();
      if (_DAT_800ab654 == 0) {
        return;
      }
      FUN_8002f268();
      return;
    }
    FUN_80030730();
    uVar1 = 0xd;
    puVar3 = &DAT_800ab68e;
    _DAT_800ab650 = _DAT_800ab650 | 0x200;
    DAT_800ab68e = DAT_800ab694;
    DAT_800ab68f = DAT_800ab692;
  }
  FUN_800319b0(uVar1,uVar2,puVar3);
  return;
}



// ---- FUN_8002f51c @ 8002f51c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002f51c(byte param_1)

{
  if ((_DAT_800ab650 & 0x100) == 0) {
    _DAT_800ab686 = 0;
    _DAT_800ab650 = _DAT_800ab650 | 0x100;
  }
  if ((_DAT_800ab64c & 0x4400) != 0) {
    if (param_1 == 0xc4) {
      _DAT_800ab688 = 0x1e;
    }
    else if (param_1 < 0xc5) {
      _DAT_800ab688 = 10;
      if (param_1 != 0xb4) {
        _DAT_800ab688 = 0x3c;
      }
    }
    else {
      _DAT_800ab688 = 0x5a;
      if (param_1 != 0xd4) {
        _DAT_800ab688 = 0x3c;
      }
    }
  }
  return;
}



// ---- FUN_8002f5a8 @ 8002f5a8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002f5a8(void)

{
  bool bVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  if ((_DAT_800ab650 & 2) != 0) {
    bVar1 = false;
    if (((_DAT_800ab650 & 0x10000000) == 0) && (bVar1 = false, (_DAT_800ab650 & 0x1000000) == 0)) {
      bVar1 = true;
    }
    if (bVar1) {
      FUN_8002fa08();
    }
  }
  uVar2 = _DAT_800ab684;
  if (((_DAT_800ab64c & 0x100) != 0) && ((_DAT_800ab650 & 1) != 0)) {
    _DAT_800ab682 = _DAT_800ab682 + 1;
    uVar5 = FUN_8006f2a4((uint)_DAT_800ab684 - (uint)_DAT_800ab682);
    uVar6 = FUN_8006f2a4((int)(short)uVar2);
    if ((short)uVar2 < 0) {
      uVar6 = FUN_8006f3a0((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,0x40f00000);
    }
    uVar6 = FUN_8006f88c((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),(int)uVar6,
                         (int)((ulonglong)uVar6 >> 0x20));
    if (_DAT_800ab674 < 1) {
      _DAT_800ab674 = 0;
      FUN_8002f7e0();
    }
    else {
      uVar5 = FUN_8006f2a4();
      uVar6 = FUN_8006fb6c((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),(int)uVar6,
                           (int)((ulonglong)uVar6 >> 0x20));
      _DAT_800ab674 = FUN_8007076c((int)uVar6,(int)((ulonglong)uVar6 >> 0x20));
      if ((_DAT_800ab64c & 0x100400) == 0x100000) {
        iVar4 = (int)_DAT_800ab676;
        if (iVar4 == 0) {
          sVar3 = 0;
        }
        else {
          sVar3 = (short)((_DAT_800ab674 * 0x7f) / iVar4);
          if (iVar4 == 0) {
            trap(0x1c00);
          }
          if ((iVar4 == -1) && (_DAT_800ab674 * 0x7f == -0x80000000)) {
            trap(0x5d);
          }
        }
        FUN_8002eb7c((int)sVar3,(int)sVar3);
      }
      else {
        FUN_80062708((int)_DAT_800ab67c,(int)_DAT_800ab674,(int)_DAT_800ab674);
      }
    }
  }
  return;
}



// ---- FUN_8002f7e0 @ 8002f7e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002f7e0(void)

{
  if ((_DAT_800ab64c & 0x100400) == 0x100000) {
    FUN_80066aa4(0);
    FUN_8002eb7c(0,0);
  }
  FUN_8002fbec(0x71);
  if (_DAT_800ab67e != -1) {
    FUN_8002f994();
  }
  return;
}



// ---- FUN_8002f84c @ 8002f84c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002f84c(ushort param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar1 = param_1 & 0xf000;
  if (uVar1 == 0x1000) {
    uVar2 = 0x71;
  }
  else {
    if (uVar1 < 0x1001) {
      if (uVar1 != 0) {
        return;
      }
      if ((_DAT_800ab650 & 1) == 0) {
        if ((_DAT_800ab64c & 0x100) == 0) {
          _DAT_800ab680 = 0xffff;
          _DAT_800ab67e = param_1 & 0xff;
          FUN_8002f994();
          return;
        }
        _DAT_800ab680 = param_1 & 0xff;
        FUN_8002fd68(0xb1);
        return;
      }
      _DAT_800ab680 = param_1 & 0xff;
      if ((_DAT_800ab64c & 0x100400) == 0x100000) {
        FUN_80066aa4(0);
        FUN_8002eb7c(0,0);
      }
      FUN_8002fbec(0x71);
      if (_DAT_800ab67e == -1) {
        return;
      }
      FUN_8002f994();
      return;
    }
    if (uVar1 == 0x2000) {
      uVar2 = 0xe1;
    }
    else {
      uVar2 = 0xf1;
      if (uVar1 != 0x4000) {
        return;
      }
    }
  }
  FUN_8002fbec(uVar2);
  return;
}



// ---- FUN_8002f994 @ 8002f994

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002f994(void)

{
  bool bVar1;
  
  if ((_DAT_800ab650 & 0x10000000) == 0) {
    bVar1 = false;
    if ((_DAT_800ab650 & 0x1000000) == 0) {
      bVar1 = true;
    }
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_8002fa08();
  }
  else {
    _DAT_800ab650 = _DAT_800ab650 | 2;
  }
  return;
}



// ---- FUN_8002fa08 @ 8002fa08

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002fa08(void)

{
  undefined1 auStack_28 [24];
  byte local_10;
  
  FUN_8006311c((int)*(short *)(&DAT_800ab6ec + _DAT_800ab67e * 2),
               (int)*(short *)(&DAT_800ab6ec + _DAT_800ab67e * 2));
  _DAT_800ab67c = FUN_800673f8(*(undefined4 *)(&DAT_800b03e4 + _DAT_800ab67e * 4),0);
  if (_DAT_800ab67c == -1) {
    FUN_800319ec(0x1040000);
    if ((_DAT_800ab64c & 0x100400) == 0x100000) {
      FUN_80066aa4(0);
      FUN_8002eb7c(0,0);
    }
    FUN_8002fbec(0x71);
    if (_DAT_800ab67e != -1) {
      FUN_8002f994();
    }
  }
  else {
    _DAT_800ab674 = _DAT_800ab676;
    _DAT_800ab64c = _DAT_800ab64c & 0xffefefff | 0x100;
    _DAT_800ab650 = _DAT_800ab650 & 0xfffffffc;
    FUN_80063258(0,auStack_28);
    _DAT_800ab674 = (ushort)local_10;
    if ((_DAT_800ab64c & 0x20) != 0) {
      _DAT_800ab674 = local_10 - 0x18;
    }
    _DAT_800ab676 = _DAT_800ab674;
    FUN_8002eb7c(0x7f,0x7f);
    FUN_80062708((int)_DAT_800ab67c,(int)(short)_DAT_800ab674,(int)(short)_DAT_800ab674);
    FUN_8006a15c((int)_DAT_800ab67c,1,1);
  }
  return;
}



// ---- FUN_8002fbec @ 8002fbec

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002fbec(byte param_1)

{
  if (param_1 == 0xe1) {
    if ((_DAT_800ab64c & 0x100) == 0) {
      return;
    }
    FUN_8006ba5c((int)_DAT_800ab67c);
    _DAT_800ab64c = _DAT_800ab64c & 0xfffffeff | 0x1000;
  }
  else {
    if (param_1 < 0xe2) {
      if (param_1 != 0x71) {
        return;
      }
      if ((_DAT_800ab64c & 0x1100) != 0) {
        FUN_80062708((int)_DAT_800ab67c,0,0);
        FUN_8006a5a4((int)_DAT_800ab67c);
        FUN_8006b78c((int)_DAT_800ab67c);
      }
      _DAT_800ab64c = _DAT_800ab64c & 0xffffeeff;
      _DAT_800ab650 = _DAT_800ab650 & 0xfffffffe;
      _DAT_800ab67e = _DAT_800ab680;
      _DAT_800ab680 = 0xffff;
      return;
    }
    if (param_1 != 0xf1) {
      return;
    }
    if ((_DAT_800ab64c & 0x1000) == 0) {
      return;
    }
    FUN_80062f34((int)_DAT_800ab67c);
    _DAT_800ab64c = _DAT_800ab64c & 0xffffefff | 0x100;
  }
  return;
}



// ---- FUN_8002fd68 @ 8002fd68

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002fd68(byte param_1)

{
  undefined2 uVar1;
  uint uVar2;
  
  uVar2 = _DAT_800ab650 | 1;
  if ((_DAT_800ab650 & 1) != 0) {
    return;
  }
  if (param_1 == 0xc1) {
    uVar1 = 0x1e;
  }
  else if (param_1 < 0xc2) {
    uVar1 = 0x14;
    if (param_1 != 0xb1) {
      _DAT_800ab650 = uVar2;
      _DAT_800ab682 = 0;
      return;
    }
  }
  else {
    uVar1 = 0x3c;
    if (param_1 != 0xd1) {
      _DAT_800ab650 = uVar2;
      _DAT_800ab682 = 0;
      return;
    }
  }
  _DAT_800ab684 = uVar1;
  _DAT_800ab682 = 0;
  _DAT_800ab650 = uVar2;
  return;
}



// ---- FUN_8002fde0 @ 8002fde0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002fde0(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = _DAT_800ab50c + 1;
  if (_DAT_800ab50c == -1) {
    return;
  }
  if (DAT_800ab521 == '\x01') {
    iVar1 = (uint)DAT_800ab520 * 0x14;
    if (uVar2 < *(uint *)(&DAT_80070b90 + iVar1)) {
      _DAT_800ab50c = uVar2;
      return;
    }
    _DAT_800ab50c = 0;
    _DAT_800ab514 = _DAT_800ab514 + 1;
    if (_DAT_800ab514 < *(uint *)(&DAT_80070b94 + iVar1)) {
LAB_8002ffa4:
      _DAT_800ab50c = 0;
      FUN_8003027c(_DAT_800ab518,_DAT_800ab51c);
      return;
    }
    _DAT_800ab514 = 0;
    iVar1 = *(int *)(&DAT_80070ba0 + iVar1);
  }
  else {
    iVar1 = (uint)DAT_800ab520 * 0x14;
    if (uVar2 < *(uint *)(&DAT_80070b98 + iVar1)) {
      _DAT_800ab50c = uVar2;
      return;
    }
    _DAT_800ab510 = _DAT_800ab510 + 1;
    if (_DAT_800ab510 < *(uint *)(&DAT_80070b9c + iVar1)) {
      DAT_800ab521 = '\x01';
      goto LAB_8002ffa4;
    }
    _DAT_800ab50c = 0xffffffff;
    _DAT_800ab650 = _DAT_800ab650 & 0xfffeffff;
    iVar1 = *(int *)(&DAT_80070ba0 + iVar1);
  }
  DAT_800ab521 = 2;
  if (iVar1 == 0) {
    FUN_800302f8(_DAT_800ab518,_DAT_800ab51c);
  }
  return;
}



// ---- FUN_8002ffbc @ 8002ffbc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8002ffbc(void)

{
  _DAT_800ab50c = 0xffffffff;
  DAT_800ab521 = 2;
  _DAT_800ab650 = _DAT_800ab650 & 0xfffeffff;
  FUN_800302f8();
  return;
}



// ---- FUN_8003000c @ 8003000c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003000c(undefined4 param_1,undefined4 param_2,uint param_3)

{
  DAT_800ab520 = (char)((param_3 & 0xf0) >> 4) + -1;
  _DAT_800ab50c = 0;
  _DAT_800ab510 = 0;
  _DAT_800ab514 = 0;
  DAT_800ab521 = 1;
  _DAT_800ab650 = _DAT_800ab650 | 0x10000;
  _DAT_800ab518 = param_1;
  _DAT_800ab51c = param_2;
  FUN_8003027c();
  return;
}



// ---- FUN_80030088 @ 80030088

void FUN_80030088(ushort param_1)

{
  if ((param_1 & 0x1000) == 0) {
    FUN_80030154(1,param_1);
  }
  else {
    FUN_800301fc(1,param_1);
  }
  return;
}



// ---- FUN_800300cc @ 800300cc

void FUN_800300cc(ushort param_1)

{
  if ((param_1 & 0x1000) == 0) {
    FUN_80030154(2,param_1);
  }
  else {
    FUN_800301fc(2,param_1);
  }
  return;
}



// ---- FUN_80030110 @ 80030110

void FUN_80030110(ushort param_1)

{
  if ((param_1 & 0x1000) == 0) {
    FUN_80030154(3,param_1);
  }
  else {
    FUN_800301fc(3,param_1);
  }
  return;
}



// ---- FUN_80030154 @ 80030154

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80030154(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (param_1 & 0xff) << 8;
  iVar1 = (param_2 & 0xf) * 0x400 + 0x1800;
  if ((param_2 & 0xf0) != 0) {
    DAT_800ab520 = (char)((param_2 & 0xf0) >> 4) + -1;
    DAT_800ab521 = 1;
    _DAT_800ab50c = 0;
    _DAT_800ab510 = 0;
    _DAT_800ab514 = 0;
    _DAT_800ab650 = _DAT_800ab650 | 0x10000;
    _DAT_800ab518 = iVar2;
    _DAT_800ab51c = iVar1;
  }
  FUN_8003027c(iVar2,iVar1);
  return;
}



// ---- FUN_800301fc @ 800301fc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800301fc(uint param_1,uint param_2)

{
  if ((param_2 & 0xf0) != 0) {
    _DAT_800ab50c = 0xffffffff;
    DAT_800ab521 = 2;
    _DAT_800ab650 = _DAT_800ab650 & 0xfffeffff;
  }
  FUN_800302f8((param_1 & 0xff) << 8,(param_2 & 0xf) * 0x400 + 0x1800);
  return;
}



// ---- FUN_8003027c @ 8003027c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003027c(undefined4 param_1,undefined4 param_2)

{
  _DAT_800ab64c = _DAT_800ab64c & 0xffefffff;
  FUN_8002eb7c(0x7f,0x7f);
  FUN_8006b668(param_1,param_2);
  FUN_800672dc(param_1,param_2,_DAT_800ab678,_DAT_800ab678);
  return;
}



// ---- FUN_800302f8 @ 800302f8

void FUN_800302f8(void)

{
  FUN_8006b668();
  return;
}



// ---- FUN_80030318 @ 80030318

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80030318(undefined2 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0xfffffffe;
  if (((_DAT_800ab64c & 8) == 0) && (uVar1 = 0xffffffff, _DAT_800ab534 < 0x20)) {
    _DAT_800ab534 = _DAT_800ab534 + 1;
    uVar1 = 0;
    *(undefined2 *)(&DAT_800ab534 + (uint)_DAT_800ab534 * 2) = param_1;
  }
  return uVar1;
}



// ---- FUN_80030378 @ 80030378

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80030378(void)

{
  _DAT_800ab534 = 0;
  return;
}



// ---- FUN_80030388 @ 80030388

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_80030388(void)

{
  uint uVar1;
  ushort uVar2;
  undefined2 uVar3;
  
  uVar3 = _DAT_800ab536;
  if (0x20 < _DAT_800ab534) {
    _DAT_800ab534 = 0x20;
  }
  if (_DAT_800ab534 == 0) {
    uVar3 = 0;
  }
  else {
    uVar2 = 1;
    if (1 < _DAT_800ab534) {
      uVar1 = 1;
      do {
        uVar2 = uVar2 + 1;
        *(undefined2 *)(&DAT_800ab534 + uVar1 * 2) = *(undefined2 *)(&DAT_800ab536 + uVar1 * 2);
        uVar1 = (uint)uVar2;
      } while (uVar2 < _DAT_800ab534);
    }
    _DAT_800ab534 = _DAT_800ab534 - 1;
  }
  return uVar3;
}



// ---- FUN_80030428 @ 80030428

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80030428(void)

{
  FUN_8006bbac(0,0,0);
  _DAT_800ab654 = 0;
  _DAT_800ab658 = 0;
  _DAT_800ab65c = 0;
  _DAT_800ab660 = 0;
  _DAT_800ab664 = 0;
  DAT_800ab692 = 0;
  DAT_800ab693 = 0;
  _DAT_800ab64c = _DAT_800ab64c & 0xffffbbff;
  _DAT_800ab650 = _DAT_800ab650 & 0xfffffcff;
  return;
}



// ---- FUN_800304c8 @ 800304c8

void FUN_800304c8(void)

{
  FUN_8006a564();
  FUN_80066aa4(0);
  FUN_8006308c();
  FUN_8006ee60(3);
  FUN_8006306c();
  return;
}



// ---- FUN_80030508 @ 80030508

void FUN_80030508(void)

{
  FUN_80062904();
  FUN_80062ae8(1);
  FUN_80066cc8(0x18);
  FUN_80062944(0x800ab2f8,1,1);
  FUN_80066d00(1);
  FUN_800630ac(3);
  FUN_8006ee60(3);
  FUN_8006306c();
  FUN_8006311c(0x3c,0x3c);
  FUN_8002eb7c(0x7f,0x7f);
  FUN_80062e7c();
  return;
}



// ---- FUN_8003058c @ 8003058c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003058c(void)

{
  FUN_800308e0(2);
  FUN_80030774();
  FUN_800305dc();
  FUN_80030730();
  FUN_80030bec();
  _DAT_800ab534 = 0;
  FUN_800311b0();
  return;
}



// ---- FUN_800305dc @ 800305dc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800305dc(void)

{
  _DAT_800ab2cc = 0x800db800;
  _DAT_800ab5bc = 0x1010;
  _DAT_800ab524 = 0x40000;
  _DAT_800ab2c0 = 0x800d4000;
  _DAT_800ab2c4 = 0x800d9800;
  _DAT_800ab2c8 = 0x800da800;
  _DAT_800ab5c0 = 0x41010;
  _DAT_800ab5c4 = 0x51010;
  _DAT_800ab5c8 = 0x61010;
  _DAT_800ab528 = 0x10000;
  _DAT_800ab52c = 0x10000;
  _DAT_800ab530 = 0x10000;
  return;
}



// ---- FUN_80030688 @ 80030688

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80030688(ushort param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_800318e4();
  if (param_1 == 0x12) {
    _DAT_800ab500 = uVar1;
  }
  else if (param_1 < 0x13) {
    if (param_1 == 0x11) {
      _DAT_800ab4fc = uVar1;
    }
  }
  else if (param_1 == 0x14) {
    _DAT_800ab504 = uVar1;
  }
  else if (param_1 == 0x18) {
    _DAT_800ab508 = uVar1;
  }
  return;
}



// ---- FUN_80030730 @ 80030730

void FUN_80030730(void)

{
  DAT_800ab68a = 200;
  FUN_8006bbac(0,0,0);
  FUN_8006a388(0,0,0);
  return;
}



// ---- FUN_80030774 @ 80030774

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80030774(void)

{
  _DAT_800ab650 = 0;
  _DAT_800ab64c = 0x10;
  _DAT_800ab668 = 0x7f;
  _DAT_800ab66a = 0x7f;
  _DAT_800ab66c = 0x7f;
  _DAT_800ab66e = 0x7f;
  _DAT_800ab670 = 0x7f;
  _DAT_800ab672 = 0x7f;
  _DAT_800ab674 = 4;
  _DAT_800ab676 = 4;
  _DAT_800ab678 = 0x60;
  _DAT_800ab67a = 0x60;
  _DAT_800ab67e = 0xffff;
  _DAT_800ab680 = 0xffff;
  _DAT_800ab654 = 0;
  _DAT_800ab658 = 0;
  _DAT_800ab65c = 0;
  _DAT_800ab660 = 0;
  _DAT_800ab664 = 0;
  _DAT_800ab67c = 0;
  _DAT_800ab682 = 0;
  _DAT_800ab684 = 0xff;
  _DAT_800ab686 = 0;
  _DAT_800ab688 = 0xff;
  DAT_800ab692 = 0;
  DAT_800ab693 = 0;
  DAT_800ab694 = 0;
  DAT_800ab695 = 0;
  return;
}



// ---- FUN_8003087c @ 8003087c

void FUN_8003087c(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  ushort *puVar5;
  
  iVar2 = 0;
  puVar5 = (ushort *)&DAT_800ab6ec;
  piVar4 = (int *)&DAT_800b03e4;
  piVar3 = param_1;
  do {
    iVar1 = *piVar3;
    piVar3 = piVar3 + 1;
    if (iVar1 == 0) {
      iVar1 = *param_1;
    }
    *piVar4 = (int)param_1 + iVar1 + 0x10;
    piVar4 = piVar4 + 1;
    iVar1 = iVar2 + 0x40;
    iVar2 = iVar2 + 1;
    *puVar5 = (ushort)*(byte *)((int)param_1 + iVar1);
    puVar5 = puVar5 + 1;
  } while (iVar2 < 0x10);
  return;
}



// ---- FUN_800308e0 @ 800308e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800308e0(short param_1)

{
  short sVar1;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  
  if (param_1 == 1) {
    sVar1 = 0x18;
    FUN_80063048();
    local_e = 0x4f;
    local_10 = 0x4f;
    local_d = 0x4f;
    local_f = 0x4f;
    _DAT_800ab64c = _DAT_800ab64c & 0xffffffef | 0x20;
  }
  else {
    sVar1 = 0;
    FUN_8006305c();
    local_e = 0x7f;
    local_10 = 0x7f;
    local_d = 0;
    local_f = 0;
    _DAT_800ab64c = _DAT_800ab64c & 0xffffffdf | 0x10;
  }
  FUN_8005eaa4(&local_10);
  _DAT_800ab676 = 4 - sVar1;
  _DAT_800ab674 = 4 - sVar1;
  _DAT_800ab67a = 0x60 - sVar1;
  _DAT_800ab678 = 0x60 - sVar1;
  return;
}



// ---- FUN_800309b8 @ 800309b8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800309b8(void)

{
  int iVar1;
  int iVar2;
  
  if ((_DAT_800ab64c & 0x1100) != 0) {
    FUN_8006a5a4((int)_DAT_800ab67c);
    FUN_8006b78c((int)_DAT_800ab67c);
  }
  FUN_80066aa4(0);
  iVar2 = 3;
  iVar1 = 0x30000;
  do {
    if ((0x10000 << (iVar1 >> 0x10 & 0x1fU) & _DAT_800ab64c) != 0) {
      FUN_8006b6a4();
    }
    iVar2 = iVar2 + -1;
    iVar1 = iVar2 * 0x10000;
  } while (-1 < iVar2 * 0x10000);
  FUN_80062e9c();
  FUN_80062f04();
  return;
}



// ---- FUN_80030a6c @ 80030a6c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80030a6c(uint param_1)

{
  if (((param_1 & 0xffff) == 0) && ((_DAT_800ab64c & 0x100) != 0)) {
    if ((_DAT_800ab64c & 0x100400) == 0x100000) {
      FUN_80066aa4(0);
      FUN_8002eb7c(0,0);
    }
    FUN_8002fbec(0x71);
    if (_DAT_800ab67e != -1) {
      FUN_8002f994();
    }
  }
  _DAT_800ab650 = 0x1000000 << (param_1 & 0x1f) | _DAT_800ab650;
  return;
}



// ---- FUN_80030b20 @ 80030b20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80030b20(short param_1)

{
  if (param_1 == 0) {
    if ((_DAT_800ab64c & 0x100) != 0) {
      FUN_8006a5a4((int)_DAT_800ab67c);
      FUN_8006b78c((int)_DAT_800ab67c);
    }
    _DAT_800ab67e = 0xffff;
    _DAT_800ab680 = 0xffff;
  }
  FUN_8006b6a4((int)param_1);
  return;
}



// ---- FUN_80030bec @ 80030bec

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80030bec(void)

{
  _DAT_800ac94c = 8;
  _DAT_800ac94e = 0x20;
  _DAT_800ac948 = 0;
  _DAT_800ac94a = 0;
  _DAT_800ac950 = 0x212;
  return;
}



// ---- FUN_80030c28 @ 80030c28

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80030c28(ushort *param_1)

{
  short sVar1;
  int iVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  *param_1 = 0;
  param_1[1] = 0;
  if ((_DAT_800ab650 & 0xff000000) != 0) {
    return;
  }
  if ((_DAT_800ab64c & 0x4000) != 0) {
    return;
  }
  iVar2 = FUN_8006f0b4(0);
  if (iVar2 != 1) {
    return;
  }
  sVar1 = FUN_8006a53c(0);
  if (sVar1 != 1) {
    return;
  }
  FUN_8006f1f4(0);
  FUN_8006efa8(0x800aeeb0,0x200);
  FUN_8006f0b4(1);
  FUN_8006f1f4(0x400);
  FUN_8006efa8(0x800af2b0,0x200);
  FUN_8006f0b4(1);
  if ((param_1[4] & 0xf) == 1) {
    FUN_80030f4c(param_1,param_1 + 1,0,param_1[3]);
  }
  else if ((param_1[4] & 0xf) == 2) {
    FUN_8003104c(param_1,param_1 + 1,0,param_1[3]);
  }
  uVar5 = (uint)*param_1;
  uVar6 = (uint)param_1[1];
  uVar3 = param_1[4] & 0xf00;
  if ((param_1[4] & 0xf0) == 0x20) {
    uVar5 = uVar5 * uVar5 >> 0xf;
    uVar6 = uVar6 * uVar6 >> 0xf;
  }
  if (uVar3 == 0x400) {
    if (uVar5 < 0x9999) {
      uVar5 = (uVar5 << 2) / 6;
    }
    else {
      uVar5 = (uVar5 * 6 >> 2) - 0x8001;
    }
    if (uVar6 < 0x9999) {
      uVar6 = (uVar6 << 2) / 6;
      goto LAB_80030f10;
    }
    uVar4 = 0xffff7fff;
    uVar6 = uVar6 * 6 >> 2;
  }
  else if (uVar3 < 0x401) {
    if (uVar3 != 0x100) goto LAB_80030f10;
    if (uVar5 < 0x3333) {
      uVar5 = uVar5 << 2;
    }
    else {
      uVar5 = (uVar5 >> 2) + 0xc000;
    }
    uVar4 = uVar6 >> 2;
    if (uVar6 < 0x3333) {
      uVar6 = uVar6 << 2;
      goto LAB_80030f10;
    }
    uVar6 = 0xc000;
  }
  else {
    if (uVar3 != 0x800) goto LAB_80030f10;
    if (uVar5 < 0xb333) {
      uVar4 = (uVar5 * 2) / 7;
      uVar5 = uVar4 + (uVar5 * 2 - uVar4 >> 1) >> 2;
    }
    else {
      uVar5 = (uVar5 << 3) / 3 - 0x1aaab;
    }
    if (uVar6 < 0xb333) {
      uVar4 = (uVar6 * 2) / 7;
      uVar6 = uVar4 + (uVar6 * 2 - uVar4 >> 1) >> 2;
      goto LAB_80030f10;
    }
    uVar4 = 0xfffe5555;
    uVar6 = (uVar6 << 3) / 3;
  }
  uVar6 = uVar6 + uVar4;
LAB_80030f10:
  *param_1 = (ushort)(uVar5 >> (0x10 - param_1[2] & 0x1f));
  param_1[1] = (ushort)(uVar6 >> (0x10 - param_1[2] & 0x1f));
  return;
}



// ---- FUN_80030f4c @ 80030f4c

/* WARNING: Removing unreachable block (ram,0x80030f78) */

void FUN_80030f4c(ushort *param_1,ushort *param_2,uint param_3,uint param_4)

{
  int iVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  
  param_4 = param_4 & 0xffff;
  if (param_4 == 0) {
    trap(0x1c00);
  }
  uVar4 = 0;
  if (param_4 != 0) {
    do {
      iVar1 = (param_3 & 0xffff) * 2;
      uVar2 = *(ushort *)(iVar1 + -0x7ff51150);
      uVar3 = *(ushort *)(iVar1 + -0x7ff50d50);
      if ((uVar2 & 0x8000) != 0) {
        uVar2 = -uVar2;
      }
      if ((uVar3 & 0x8000) != 0) {
        uVar3 = -uVar3;
      }
      if ((uint)*param_1 < (uint)(int)(short)uVar2) {
        *param_1 = uVar2;
      }
      param_3 = param_3 + 0x100 / param_4;
      if ((uint)*param_2 < (uint)(int)(short)uVar3) {
        *param_2 = uVar3;
      }
      uVar4 = uVar4 + 1;
    } while ((uVar4 & 0xffff) < param_4);
  }
  *param_1 = *param_1 << 1;
  *param_2 = *param_2 << 1;
  return;
}



// ---- FUN_8003104c @ 8003104c

/* WARNING: Removing unreachable block (ram,0x80031078) */

void FUN_8003104c(undefined2 *param_1,undefined2 *param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  uint uVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  
  uVar4 = param_4 & 0xffff;
  if (uVar4 == 0) {
    trap(0x1c00);
  }
  iVar2 = 0;
  uVar6 = 0;
  iVar7 = 0;
  if (uVar4 != 0) {
    do {
      iVar1 = (param_3 & 0xffff) * 2;
      uVar3 = *(ushort *)(iVar1 + -0x7ff51150);
      uVar5 = *(ushort *)(iVar1 + -0x7ff50d50);
      if ((uVar3 & 0x8000) != 0) {
        uVar3 = -uVar3;
      }
      uVar6 = uVar6 + 1;
      if ((uVar5 & 0x8000) != 0) {
        uVar5 = -uVar5;
      }
      iVar2 = iVar2 + (short)uVar3;
      iVar7 = iVar7 + (short)uVar5;
      param_3 = param_3 + 0x100 / uVar4;
    } while ((uVar6 & 0xffff) < uVar4);
  }
  param_4 = param_4 & 0xffff;
  if (param_4 == 0) {
    trap(0x1c00);
  }
  if (param_4 == 0) {
    trap(0x1c00);
  }
  *param_1 = (short)((uint)(iVar2 << 1) / param_4);
  *param_2 = (short)((uint)(iVar7 << 1) / param_4);
  return;
}



// ---- FUN_8003115c @ 8003115c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8003115c(void)

{
  int iVar1;
  
  iVar1 = 0;
  if ((_DAT_800ab64c & 0x400) != 0) {
    if (_DAT_800ac94a < _DAT_800ac948) {
      iVar1 = (int)(short)_DAT_800ac948;
    }
    else {
      iVar1 = (int)(short)_DAT_800ac94a;
    }
  }
  return iVar1;
}



// ---- FUN_800311b0 @ 800311b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800311b0(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  *(undefined2 *)(_DAT_800abf64 + 0x53e) = 0xc;
  *(undefined2 *)(iVar1 + 0x540) = 0x30;
  *(undefined2 *)(iVar1 + 0x542) = 0x7f;
  *(undefined4 *)(iVar1 + 0x54c) = 0x80;
  *(undefined4 *)(iVar1 + 0x550) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x554) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x558) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x55c) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x560) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x564) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x568) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x56c) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x570) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x574) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x528) = 1;
  *(undefined4 *)(iVar1 + 0x52c) = 0;
  *(undefined4 *)(iVar1 + 0x530) = 0;
  *(undefined4 *)(iVar1 + 0x534) = 0;
  *(undefined4 *)(iVar1 + 0x538) = 0;
  *(undefined2 *)(iVar1 + 0x53c) = 0;
  *(undefined4 *)(iVar1 + 0x544) = 1;
  *(undefined4 *)(iVar1 + 0x548) = 0;
  *(undefined2 *)(iVar1 + 0x578) = 0;
  *(undefined2 *)(iVar1 + 0x57a) = 7;
  return;
}



// ---- FUN_80031238 @ 80031238

void FUN_80031238(void)

{
  return;
}



// ---- FUN_80031240 @ 80031240

int FUN_80031240(undefined2 param_1)

{
  short sVar1;
  
  sVar1 = FUN_80030318(param_1);
  return (int)sVar1;
}



// ---- FUN_80031268 @ 80031268

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_80031268(ushort param_1,uint param_2)

{
  short sVar1;
  ushort uVar2;
  undefined *puVar3;
  ushort uVar4;
  int *piVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  
  iVar8 = _DAT_800abf64;
  puVar10 = (undefined4 *)(_DAT_800abf64 + 0x528);
  if (*(short *)(_DAT_800abf64 + 0x578) == 1) {
    return 0xffffffff;
  }
  uVar4 = param_1 & 0xfff;
  if (uVar4 != 0x300) {
    if (uVar4 < 0x301) {
      if (uVar4 == 0) {
        if (param_2 - 6 < 2) {
          if (param_2 == *(ushort *)(_DAT_800abf64 + 0x57a)) {
            return 0xffffffff;
          }
          *(short *)(_DAT_800abf64 + 0x57a) = (short)param_2;
        }
        sVar1 = FUN_80030318(param_2 & 0xffff);
        return (int)sVar1;
      }
      if (uVar4 != 0x200) {
        return 0x200;
      }
      uVar11 = 0;
      if (DAT_8008b180 == 0) {
        return 0xffffffff;
      }
      iVar8 = 0;
      while (*(uint *)((int)&DAT_8008b184 + iVar8) != param_2) {
        uVar11 = uVar11 + 1;
        iVar8 = iVar8 + 0xc;
        if (DAT_8008b180 <= uVar11) {
          return 0xffffffff;
        }
      }
      uVar7 = 0;
      if (*(int *)((int)&DAT_8008b188 + iVar8) == 0) {
        return 0xffffffff;
      }
      while( true ) {
        piVar5 = (int *)(uVar7 * 8 + *(int *)((int)&PTR_DAT_8008b18c + iVar8));
        uVar7 = uVar7 + 1;
        if (*piVar5 == *(int *)(_DAT_800abf64 + 0x550)) break;
        if (*(uint *)((int)&DAT_8008b188 + iVar8) <= uVar7) {
          return 0xffffffff;
        }
      }
      uVar4 = *(ushort *)(piVar5 + 1);
      uVar2 = param_1 & 0xf000 | 0x200;
    }
    else {
      if (uVar4 == 0x301) goto LAB_8003149c;
      if (uVar4 != 0x500) {
        return 0x500;
      }
      uVar11 = 0;
      if (DAT_8008acac == 0) {
        return 0xffffffff;
      }
      iVar8 = 0;
      while (*(uint *)((int)&DAT_8008acb4 + iVar8) != param_2) {
        uVar11 = uVar11 + 1;
        iVar8 = iVar8 + 8;
        if (DAT_8008acac <= uVar11) {
          return 0xffffffff;
        }
      }
      uVar4 = *(ushort *)(iVar8 + -0x7ff7534e);
      uVar2 = (ushort)*(byte *)(iVar8 + -0x7ff75350) |
              param_1 & 0xf000 | (ushort)*(byte *)(iVar8 + -0x7ff7534f) << 8;
    }
    FUN_80030318(uVar4 | uVar2);
    return uVar11;
  }
  *(undefined4 *)(_DAT_800abf64 + 0x54c) = 0x80;
LAB_8003149c:
  uVar11 = 0;
  if (DAT_8008aca8 != 0) {
    iVar9 = 0;
    do {
      if (*(uint *)((int)&DAT_80085f44 + iVar9) == param_2) {
        uVar6 = 1;
        if (*(int *)((int)&DAT_80085f38 + iVar9) != 0) {
          uVar6 = 2;
        }
        *puVar10 = uVar6;
        *(uint *)(iVar8 + 0x52c) =
             *(int *)((int)&DAT_80085f38 + iVar9) << 8 | (uint)*(byte *)(iVar8 + 0x54c);
        if (*(int *)((int)&DAT_80085f38 + iVar9) == 0) {
          puVar3 = PTR_DAT_80074a40;
        }
        else {
          puVar3 = PTR_DAT_80074a44;
        }
        *(undefined4 *)(iVar8 + 0x530) = *(undefined4 *)(puVar3 + 4);
        *(undefined4 *)(iVar8 + 0x534) = *(undefined4 *)((int)&DAT_80085f3c + iVar9);
        *(undefined4 *)(iVar8 + 0x538) = *(undefined4 *)((int)&DAT_80085f40 + iVar9);
        FUN_80030318(0x300);
        FUN_800315cc(0);
        return uVar11;
      }
      uVar11 = uVar11 + 1;
      iVar9 = iVar9 + 0x10;
    } while (uVar11 < DAT_8008aca8);
  }
  return 0xffffffff;
}



// ---- FUN_800315cc @ 800315cc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_800315cc(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  
  switch(param_1) {
  case 0:
    uVar2 = 1;
    *(byte *)(_DAT_800abf64 + 0x586) = *(byte *)(_DAT_800abf64 + 0x586) | 0x10;
    break;
  case 1:
    uVar2 = 1;
    *(byte *)(_DAT_800abf64 + 0x586) = *(byte *)(_DAT_800abf64 + 0x586) & 0xef;
    break;
  case 2:
    iVar1 = 1;
    if (((((_DAT_800ab650 & 0x200) == 0) && (iVar1 = 2, (_DAT_800ab650 & 0x100) == 0)) &&
        (iVar1 = 3, (_DAT_800ab64c & 0x4000) == 0)) && (iVar1 = 0, (_DAT_800ab64c & 0x400) != 0)) {
      iVar1 = 4;
    }
    uVar2 = (uint)(iVar1 != 0);
    break;
  case 3:
    if ((_DAT_800ab650 & 0x200) == 0) {
      if ((_DAT_800ab650 & 0x100) != 0) {
        return 2;
      }
      if ((_DAT_800ab64c & 0x4000) != 0) {
        return 3;
      }
      if ((_DAT_800ab64c & 0x400) != 0) {
        return 4;
      }
      goto switchD_80031600_default;
    }
  case 4:
    uVar2 = 1;
    break;
  case 5:
    uVar2 = *(uint *)(_DAT_800abf64 + 0x544);
    break;
  default:
switchD_80031600_default:
    uVar2 = 0;
  }
  return uVar2;
}



// ---- FUN_800316f0 @ 800316f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800316f0(void)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if ((_DAT_800ab64c & 0x400) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = _DAT_800ac948;
    if (_DAT_800ac948 <= _DAT_800ac94a) {
      uVar1 = _DAT_800ac94a;
    }
  }
  uVar3 = (uint)(short)uVar1;
  if (uVar3 < *(ushort *)(_DAT_800abf64 + 0x53c)) {
    uVar1 = *(ushort *)(_DAT_800abf64 + 0x53e);
    uVar2 = 2;
  }
  else {
    uVar1 = *(ushort *)(_DAT_800abf64 + 0x53e);
    uVar2 = 0;
  }
  if ((uVar1 <= uVar3) && (uVar2 = 1, *(ushort *)(_DAT_800abf64 + 0x540) <= uVar3)) {
    uVar2 = 2;
  }
  return uVar2;
}



// ---- FUN_800317a4 @ 800317a4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800317a4(int param_1)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  *(int *)(_DAT_800abf64 + 0x54c) = param_1;
  if (param_1 < 0) {
    *(undefined4 *)(iVar1 + 0x54c) = 0x80;
  }
  return;
}



// ---- FUN_800317c4 @ 800317c4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800317c4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _DAT_800abf64;
  FUN_80030318(0x21);
  iVar2 = 0;
  *(undefined4 *)(iVar1 + 0x550) = param_1;
  do {
    if (*(int *)((int)&DAT_80070d00 + iVar2) == *(int *)(iVar1 + 0x550)) {
      FUN_80031884(*(undefined4 *)((int)&DAT_80070d04 + iVar2),param_2,param_3);
      return;
    }
    iVar2 = iVar2 + 8;
  } while (iVar2 < 0x58);
  return;
}



// ---- FUN_80031884 @ 80031884

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80031884(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  *(int *)(_DAT_800abf64 + 0x554) = param_3;
  iVar1 = param_3 * 4 + iVar1 + 0x528;
  *(undefined4 *)(iVar1 + 0x30) = param_1;
  *(undefined4 *)(iVar1 + 0x40) = param_2;
  FUN_80030318(*(undefined2 *)(&DAT_80070d58 + param_3 * 4));
  return;
}



// ---- FUN_800318d4 @ 800318d4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_800318d4(void)

{
  return _DAT_800abf64 + 0x52c;
}



// ---- FUN_800318e4 @ 800318e4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800318e4(void)

{
  return *(undefined4 *)(_DAT_800abf64 + *(int *)(_DAT_800abf64 + 0x554) * 4 + 0x568);
}



// ---- FUN_8003190c @ 8003190c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8003190c(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)(_DAT_800abf64 + 0x57c) == 0) {
    uVar1 = 1;
    if ((((*(byte *)(_DAT_800abf64 + 0x585) & 0x80) == 0) &&
        (uVar1 = 2, (*(byte *)(_DAT_800abf64 + 0x585) & 0x40) == 0)) &&
       (uVar1 = 3, (*(byte *)(_DAT_800abf64 + 0x586) & 1) == 0)) {
      uVar1 = 4;
    }
  }
  return uVar1;
}



// ---- FUN_80031968 @ 80031968

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80031968(void)

{
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  
  local_10 = *(undefined1 *)(_DAT_800abf64 + 0x58c);
  local_f = *(undefined1 *)(_DAT_800abf64 + 0x58d);
  local_e = *(undefined1 *)(_DAT_800abf64 + 0x58e);
  FUN_8005ec60(&local_10);
  return;
}



// ---- FUN_800319b0 @ 800319b0

void FUN_800319b0(undefined1 param_1,int param_2,undefined4 param_3)

{
  undefined1 uVar1;
  
  uVar1 = 0xfc;
  if (param_2 == 0) {
    uVar1 = param_1;
  }
  FUN_8002bf04(uVar1,param_3,0,param_2,0);
  return;
}



// ---- FUN_800319ec @ 800319ec

uint FUN_800319ec(int param_1)

{
  uint uVar1;
  
  if (param_1 < 0) {
    uVar1 = *(uint *)(&DAT_80070d6c + (DAT_80070d68 & 0xf) * 4);
  }
  else {
    FUN_80058614(s_sound_error___0x_08x_800281ac,param_1);
    uVar1 = DAT_80070d68 + 1;
    *(int *)(&DAT_80070d6c + (DAT_80070d68 & 0xf) * 4) = param_1;
    DAT_80070d68 = uVar1;
  }
  return uVar1;
}



// ---- FUN_80031a80 @ 80031a80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80031a80(void)

{
  int iVar1;
  int in_zero;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar1 = _DAT_800abf64;
  iVar4 = 1;
  puVar5 = (undefined4 *)(_DAT_800abf64 + 0x5dc);
  iVar3 = *(int *)(in_zero + 0x110);
  do {
    *(undefined4 *)(iVar3 + 0x154) = 0x404;
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + 0xc0;
  } while (iVar4 < 4);
  FUN_80058314();
  uVar2 = FUN_80058354(FUN_80031bac,iVar1 + 0x6e4,0);
  *puVar5 = uVar2;
  uVar2 = FUN_80058354(FUN_80031c18,iVar1 + 0x16e4,0);
  *(undefined4 *)(iVar1 + 0x5e0) = uVar2;
  uVar2 = FUN_80058354(&DAT_80031c60,iVar1 + 0x17e4,0);
  *(undefined4 *)(iVar1 + 0x5e4) = uVar2;
  FUN_800585a4();
  return;
}



// ---- FUN_80031b24 @ 80031b24

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80031b24(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  FUN_80058514(*(undefined4 *)(_DAT_800abf64 + 0x5dc));
  FUN_80058514(*(undefined4 *)(iVar1 + 0x5e0));
  FUN_80058514(*(undefined4 *)(iVar1 + 0x5e4));
  return;
}



// ---- FUN_80031b70 @ 80031b70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80031b70(void)

{
  FUN_80058534(*(undefined4 *)(_DAT_800abf64 + 0x5dc));
  return;
}



// ---- FUN_80031b9c @ 80031b9c

void FUN_80031b9c(void)

{
  int in_zero;
  
  **(undefined4 **)(in_zero + 0x108) = *(undefined4 *)(in_zero + 0x110);
  return;
}



// ---- FUN_80031bac @ 80031bac

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80031bac(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  do {
    if (DAT_8007090c == 0) {
      FUN_800561a8();
      FUN_80056668();
      FUN_80056d0c();
    }
    FUN_80058534(*(undefined4 *)(iVar1 + 0x5e0));
  } while( true );
}



// ---- FUN_80031c18 @ 80031c18

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80031c18(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  do {
    FUN_8003cbbc();
    FUN_80058534(*(undefined4 *)(iVar1 + 0x5e4));
  } while( true );
}



// ---- FUN_80031c68 @ 80031c68

void FUN_80031c68(void)

{
  FUN_80031c9c(0);
  FUN_80031d6c(0,0,0x100,0xf0);
  return;
}



// ---- FUN_80031c9c @ 80031c9c

void FUN_80031c9c(int param_1)

{
  undefined2 uVar1;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  if (param_1 == 1) {
    local_10 = 0x100;
    local_c = 0x300;
    uVar1 = 0x200;
  }
  else if (param_1 < 2) {
    if (param_1 != 0) goto LAB_80031d40;
    local_c = 0x400;
    uVar1 = 0x200;
    local_10 = 0;
  }
  else if (param_1 == 2) {
    local_c = 0x100;
    uVar1 = 0x1e0;
    local_10 = 0;
  }
  else {
    uVar1 = 0x1e0;
    if (param_1 != 3) goto LAB_80031d40;
    local_10 = 0;
    local_c = 0x1e0;
  }
  local_e = 0;
  local_a = uVar1;
LAB_80031d40:
  FUN_8002c6f8(3,0,&local_10,&DAT_80070dac,1);
  return;
}



// ---- FUN_80031d6c @ 80031d6c

void FUN_80031d6c(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  local_10 = param_1;
  local_e = param_2;
  local_c = param_3;
  local_a = param_4;
  FUN_8005dc68(&local_10);
  return;
}



// ---- FUN_80031d9c @ 80031d9c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80031d9c(void)

{
  undefined1 auStack_18 [8];
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  if (_DAT_800b05cc == 0) {
    local_e = 0;
  }
  else {
    local_e = 0xf0;
  }
  local_c = 0x100;
  local_10 = 0;
  local_a = 0xf0;
  FUN_80031e14(0x12,auStack_18);
  FUN_8002c6f8(1,0,&local_10,auStack_18,1);
  return;
}



// ---- FUN_80031e14 @ 80031e14

void FUN_80031e14(uint param_1,short *param_2)

{
  *param_2 = (short)((param_1 & 0xff) >> 5) * 0x100 + ((ushort)param_1 & 3) * 0x40 + 0x100;
  param_2[1] = ((ushort)((param_1 & 0xff) >> 4) & 1) * 0x100 + (short)((param_1 & 0xf) >> 2) * 0x80;
  return;
}



// ---- FUN_80031e58 @ 80031e58

void FUN_80031e58(uint param_1,ushort *param_2)

{
  *param_2 = (ushort)(param_1 >> 2) & 0x3c;
  param_2[1] = (ushort)((param_1 & 0xf) << 3);
  return;
}



// ---- FUN_80031e74 @ 80031e74

void FUN_80031e74(ushort param_1,undefined2 *param_2)

{
  *param_2 = 0;
  param_2[1] = (param_1 & 0xc) << 5;
  return;
}



// ---- FUN_80031e88 @ 80031e88

void FUN_80031e88(uint param_1,undefined2 *param_2,char param_3)

{
  undefined2 uVar1;
  uint uVar2;
  
  uVar2 = (param_1 & 0xff) >> 4;
  uVar1 = (undefined2)(uVar2 << 3);
  if (param_3 == '\0') {
    uVar1 = (undefined2)(uVar2 << 4);
  }
  *param_2 = uVar1;
  param_2[1] = (short)((param_1 & 0xf) << 3);
  return;
}



// ---- FUN_80031eb4 @ 80031eb4

void FUN_80031eb4(ushort param_1,ushort param_2,short *param_3)

{
  *param_3 = (param_2 & 0xff) << 4;
  param_3[1] = (param_1 & 0xff) + 0x1e0;
  return;
}



// ---- FUN_80031ed0 @ 80031ed0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80031ed0(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  *(undefined4 *)(_DAT_800abf64 + 0x17f0) = 0;
  *(undefined2 *)(iVar1 + 0x17f4) = 0;
  *(undefined2 *)(iVar1 + 0x17f6) = 0;
  return;
}



// ---- FUN_80031eec @ 80031eec

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80031eec(void)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(_DAT_800abf64 + 0x17f0);
  piVar2 = (int *)(_DAT_800abf64 + 0x17f0);
  if (piVar1 != (int *)0x0) {
    do {
      if ((piVar1[3] & 0x100U) == 0) {
        FUN_80031f7c(piVar1);
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
    piVar2 = (int *)*piVar2;
    do {
      piVar2 = (int *)*piVar2;
      FUN_80032040();
    } while (piVar2 != (int *)0x0);
  }
  return;
}



// ---- FUN_80031f7c @ 80031f7c

void FUN_80031f7c(int param_1)

{
  uint uVar1;
  
  if (param_1 != 0) {
    if ((*(uint *)(param_1 + 0xc) & 0x80) == 0) {
      uVar1 = *(uint *)(param_1 + 0xc) >> 5 & 3;
      if (uVar1 == 2) {
        FUN_800340f8(param_1);
        FUN_8003415c(param_1);
      }
      else if (uVar1 < 3) {
        if (uVar1 == 1) {
          FUN_80032720(param_1);
        }
      }
      else if (uVar1 == 3) {
        FUN_80035ae8(param_1);
        FUN_80035b4c(param_1);
        FUN_80035dbc(param_1);
      }
    }
    FUN_80031f7c(*(undefined4 *)(param_1 + 4));
  }
  return;
}



// ---- FUN_80032040 @ 80032040

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80032040(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  iVar1 = _DAT_800abf64;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  puVar7 = (undefined4 *)param_1[1];
  iVar4 = param_1[2];
  if ((param_1[3] & 0x80) == 0) goto LAB_800321f8;
  if ((param_1[3] & 0x10) == 0) {
    if (iVar4 != 0) {
      *(undefined4 **)(iVar4 + 4) = puVar7;
    }
    if (puVar7 != (undefined4 *)0x0) {
      puVar7[2] = iVar4;
    }
  }
  else {
    puVar2 = *(undefined4 **)(_DAT_800abf64 + 0x17f0);
    if (puVar2 == param_1) {
      if (puVar7 == (undefined4 *)0x0) {
        *(undefined4 *)(_DAT_800abf64 + 0x17f0) = *param_1;
      }
      else {
        *(undefined4 **)(_DAT_800abf64 + 0x17f0) = puVar7;
LAB_800320f8:
        uVar5 = *param_1;
        puVar7[2] = 0;
        *puVar7 = uVar5;
        puVar7[3] = puVar7[3] | 0x10;
      }
    }
    else {
      puVar3 = (undefined4 *)*puVar2;
      while (puVar3 != param_1) {
        puVar2 = (undefined4 *)*puVar2;
        puVar3 = (undefined4 *)*puVar2;
      }
      if (puVar7 != (undefined4 *)0x0) {
        *puVar2 = puVar7;
        goto LAB_800320f8;
      }
      *puVar2 = *param_1;
    }
  }
  uVar6 = (uint)param_1[3] >> 5 & 3;
  if (uVar6 == 2) {
    FUN_800327d4(param_1);
  }
  else if (uVar6 < 3) {
    if (uVar6 == 1) {
      FUN_800324ec(param_1);
    }
  }
  else if (uVar6 == 3) {
    FUN_80034a80(param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = param_1[3] & 0xffffe100;
  *(short *)(iVar1 + 0x17f4) = *(short *)(iVar1 + 0x17f4) + -1;
LAB_800321f8:
  FUN_80032040(puVar7);
  return;
}



// ---- FUN_8003221c @ 8003221c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003221c(int param_1,uint param_2)

{
  int iVar1;
  ushort uVar2;
  undefined4 uVar3;
  
  iVar1 = _DAT_800abf64;
  if (param_1 == 0) {
    *(undefined2 *)(_DAT_800abf64 + 0x17f6) = 0;
  }
  else if ((*(uint *)(param_1 + 0xc) & 0x60) != 0) {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x80;
    uVar2 = *(short *)(iVar1 + 0x17f6) + 1;
    *(ushort *)(iVar1 + 0x17f6) = uVar2;
    uVar3 = 0;
    if (uVar2 != param_2) {
      uVar3 = *(undefined4 *)(param_1 + 4);
    }
    FUN_8003221c(uVar3);
  }
  return;
}



// ---- FUN_80032288 @ 80032288

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80032288(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  
  iVar1 = _DAT_800abf64;
  if ((param_1 != 0) && (uVar6 = *(uint *)(param_1 + 0xc), (uVar6 & 0xf) == 2)) {
    *(uint *)(param_1 + 0xc) = uVar6 & 0xfffffef0 | 1;
    if (param_2 == 0) {
      *(uint *)(param_1 + 0xc) = uVar6 & 0xfffffef0 | 0x11;
      piVar2 = *(int **)(iVar1 + 0x17f0);
      if (piVar2 == (int *)0x0) {
        *(int *)(iVar1 + 0x17f0) = param_1;
      }
      else {
        iVar3 = *piVar2;
        while (iVar3 != 0) {
          piVar2 = (int *)*piVar2;
          iVar3 = *piVar2;
        }
        *piVar2 = param_1;
      }
    }
    else {
      *(uint *)(param_1 + 0xc) = uVar6 & 0xfffffee0 | 1;
      if (param_3 == 0) {
        iVar4 = *(int *)(param_1 + 4);
        iVar3 = param_1;
        while (iVar4 != 0) {
          iVar3 = *(int *)(iVar3 + 4);
          iVar4 = *(int *)(iVar3 + 4);
        }
        uVar5 = 0;
        if (*(int *)(param_2 + 4) != 0) {
          *(int *)(*(int *)(param_2 + 4) + 8) = iVar3;
          uVar5 = *(undefined4 *)(param_2 + 4);
        }
        *(undefined4 *)(iVar3 + 4) = uVar5;
        *(int *)(param_1 + 8) = param_2;
        *(int *)(param_2 + 4) = param_1;
      }
      else if (param_3 == 1) {
        iVar3 = *(int *)(param_2 + 4);
        while (iVar3 != 0) {
          param_2 = *(int *)(param_2 + 4);
          iVar3 = *(int *)(param_2 + 4);
        }
        *(int *)(param_2 + 4) = param_1;
        *(int *)(param_1 + 8) = param_2;
      }
    }
    *(short *)(iVar1 + 0x17f4) = *(short *)(iVar1 + 0x17f4) + 1;
  }
  return;
}



// ---- FUN_800323d4 @ 800323d4

void FUN_800323d4(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    if (param_2 < 1) {
      uVar1 = *(undefined4 *)(param_1 + 8);
      param_2 = param_2 + 1;
    }
    else {
      uVar1 = *(undefined4 *)(param_1 + 4);
      param_2 = param_2 + -1;
    }
    FUN_800323d4(uVar1,param_2);
  }
  return;
}



// ---- FUN_80032494 @ 80032494

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80032494(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  *(undefined4 *)(_DAT_800abf64 + 0x17f8) = 0xffffffff;
  *(undefined1 *)(iVar1 + 0x7a70) = 0;
  *(undefined4 *)(iVar1 + 0x17fc) = 0;
  *(undefined4 *)(iVar1 + 0x1800) = 0;
  *(undefined4 *)(iVar1 + 0x1804) = 0x800f4800;
  *(undefined ***)(iVar1 + 0x1808) = &PTR_PTR_80070ff4;
  FUN_800585e4(iVar1 + 0x18a8,0x40);
  return;
}



// ---- FUN_800324ec @ 800324ec

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800324ec(int param_1)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  if (param_1 != 0) {
    FUN_8002af34(*(undefined4 *)(param_1 + 0x14));
    if ((*(uint *)(param_1 + 0x18) & 0x40000000) == 0) {
      FUN_8002af34(param_1);
    }
    FUN_800585e4(param_1,0x1c);
    *(char *)(iVar1 + 0x7a70) = *(char *)(iVar1 + 0x7a70) + -1;
  }
  return;
}



// ---- FUN_80032568 @ 80032568

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_80032568(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _DAT_800abf64;
  if (param_1 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)FUN_8002ac50(0x1c);
    if (param_1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    uVar2 = 0;
  }
  else {
    if ((param_1[3] & 0xf) != 0) {
      return (undefined4 *)0x0;
    }
    uVar2 = 0x40000000;
  }
  param_1[6] = uVar2;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[4] = param_2;
  param_1[5] = 0;
  param_1[3] = param_1[3] & 0xffffe100 | 0x122;
  *(char *)(iVar1 + 0x7a70) = *(char *)(iVar1 + 0x7a70) + '\x01';
  return param_1;
}



// ---- FUN_80032654 @ 80032654

void FUN_80032654(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xc0000000;
  return;
}



// ---- FUN_80032684 @ 80032684

undefined4 FUN_80032684(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 == 0) {
    if (param_3 != 0) {
      FUN_8002af34(*(undefined4 *)(param_1 + 0x14));
      uVar1 = FUN_8002ac50(param_3);
      *(undefined4 *)(param_1 + 0x14) = uVar1;
    }
  }
  else if (param_3 != 0) {
    FUN_8002af34(*(undefined4 *)(param_1 + 0x14));
    iVar2 = FUN_8002ac50(param_3);
    *(int *)(param_1 + 0x14) = iVar2;
    if (iVar2 != 0) {
      FUN_80058604(iVar2,param_2,param_3);
    }
  }
  return *(undefined4 *)(param_1 + 0x14);
}



// ---- FUN_80032720 @ 80032720

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80032720(int param_1)

{
  uint uVar1;
  
  if (*(code **)(param_1 + 0x10) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x10))(_DAT_800abf64,param_1,*(undefined4 *)(param_1 + 0x14));
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xc1ffffff | (uVar1 & 0x1f) << 0x19;
  }
  return;
}



// ---- FUN_80032784 @ 80032784

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80032784(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _DAT_800abf64;
  iVar2 = _DAT_800abf64 + 0x22b0;
  *(undefined1 *)(_DAT_800abf64 + 0x7a71) = 0;
  FUN_800585e4(iVar2,0x2400);
  *(undefined1 *)(iVar1 + 0x18e8) = 0x80;
  *(undefined1 *)(iVar1 + 0x18e9) = 0x80;
  *(undefined1 *)(iVar1 + 0x18ea) = 0x80;
  *(undefined1 *)(iVar1 + 0x18eb) = 1;
  return;
}



// ---- FUN_800327d4 @ 800327d4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800327d4(int param_1)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  if (param_1 != 0) {
    FUN_8002af34(*(undefined4 *)(param_1 + 0x20));
    FUN_8002af34(*(undefined4 *)(param_1 + 0x28));
    FUN_8002af34(*(undefined4 *)(param_1 + 0x24));
    FUN_8002af34(*(undefined4 *)(param_1 + 0x2c));
    FUN_8002af34(*(undefined4 *)(param_1 + 0x30));
    FUN_8002af34(*(undefined4 *)(param_1 + 0x34));
    FUN_8002af34(*(undefined4 *)(param_1 + 0x38));
    FUN_8002af34(*(undefined4 *)(param_1 + 0x1c));
    if ((*(uint *)(param_1 + 0x3c) & 1) == 0) {
      FUN_8002af34(param_1);
    }
    FUN_800585e4(param_1,0x40);
    *(char *)(iVar1 + 0x7a71) = *(char *)(iVar1 + 0x7a71) + -1;
  }
  return;
}



// ---- FUN_800328a4 @ 800328a4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_800328a4(undefined4 *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = _DAT_800abf64;
  if (param_1 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)FUN_8002ac50(0x40);
    uVar4 = 0;
    if (param_1 != (undefined4 *)0x0) goto LAB_8003290c;
LAB_800329dc:
    param_1 = (undefined4 *)0x0;
  }
  else {
    if ((param_1[3] & 0xf) != 0) {
      return (undefined4 *)0x0;
    }
    uVar4 = 1;
LAB_8003290c:
    uVar2 = param_2 & 0xff;
    if (uVar2 == 6) {
      iVar3 = FUN_8002ac50(0x78);
      if (iVar3 == 0) goto LAB_800329c8;
      *(undefined1 *)(iVar3 + 0x53) = 9;
      *(undefined1 *)(iVar3 + 0x57) = 0x2c;
    }
    else if (uVar2 < 7) {
      iVar3 = 0;
      if (uVar2 == 4) {
        iVar3 = FUN_8002ac50(0x6c);
        if (iVar3 == 0) goto LAB_800329c8;
        *(undefined1 *)(iVar3 + 0x4b) = 8;
        *(undefined1 *)(iVar3 + 0x4f) = 0x38;
      }
    }
    else if (uVar2 == 0xf) {
      iVar3 = FUN_8002ac50(0x3c);
      if (iVar3 == 0) {
LAB_800329c8:
        if (uVar4 != 0) {
          return (undefined4 *)0x0;
        }
        FUN_8002af34(param_1);
        goto LAB_800329dc;
      }
      *(undefined1 *)(iVar3 + 0x2b) = 4;
      *(undefined1 *)(iVar3 + 0x2f) = 100;
    }
    else {
      iVar3 = 0;
      if (uVar2 == 0x12) {
        iVar3 = FUN_8002ac50(0x30);
        if (iVar3 == 0) goto LAB_800329c8;
        *(undefined1 *)(iVar3 + 0x23) = 3;
        *(undefined1 *)(iVar3 + 0x27) = 0x60;
      }
    }
    param_1[7] = iVar3;
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[8] = 0;
    param_1[9] = 0;
    param_1[10] = 0;
    param_1[0xb] = 0;
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    param_1[0xe] = 0;
    param_1[3] = param_1[3] & 0xffffe100 | 0x142;
    param_1[0xf] = uVar4 | (param_2 & 0x1f) << 4 | 0x10000000;
    param_1[6] = 0x40000000;
    *(char *)(iVar1 + 0x7a71) = *(char *)(iVar1 + 0x7a71) + '\x01';
  }
  return param_1;
}



// ---- FUN_80032b80 @ 80032b80

undefined4 FUN_80032b80(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  
  bVar1 = true;
  if ((param_2 & 1) != 0) {
    iVar2 = FUN_8002ac50(0x18);
    *(int *)(param_1 + 0x20) = iVar2;
    bVar1 = iVar2 != 0;
  }
  if (!bVar1) goto LAB_80032c60;
  if ((param_2 & 2) != 0) {
    iVar2 = FUN_8002ac50(0x18);
    *(int *)(param_1 + 0x28) = iVar2;
    if (iVar2 != 0) {
      iVar2 = FUN_8002ac50(8);
      *(int *)(param_1 + 0x30) = iVar2;
      if (iVar2 != 0) goto LAB_80032bf4;
    }
    bVar1 = false;
  }
LAB_80032bf4:
  if (!bVar1) goto LAB_80032c60;
  if ((param_2 & 4) != 0) {
    iVar2 = FUN_8002ac50(0x18);
    *(int *)(param_1 + 0x24) = iVar2;
    if (iVar2 != 0) {
      iVar2 = FUN_8002ac50(8);
      *(int *)(param_1 + 0x34) = iVar2;
      if (iVar2 != 0) goto LAB_80032c28;
    }
    bVar1 = false;
  }
LAB_80032c28:
  if ((bVar1) && ((param_2 & 8) != 0)) {
    iVar2 = FUN_8002ac50(0x18);
    *(int *)(param_1 + 0x2c) = iVar2;
    if (iVar2 != 0) {
      iVar2 = FUN_8002ac50(4);
      *(int *)(param_1 + 0x38) = iVar2;
      if (iVar2 != 0) goto LAB_80032c60;
    }
    bVar1 = false;
  }
LAB_80032c60:
  if (bVar1) {
    uVar3 = 0;
    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) & 0xffffe1ff | (param_2 & 0xf) << 9;
  }
  else {
    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) & 0xffffe1ff;
    FUN_8002af34(*(undefined4 *)(param_1 + 0x20));
    FUN_8002af34(*(undefined4 *)(param_1 + 0x28));
    FUN_8002af34(*(undefined4 *)(param_1 + 0x24));
    FUN_8002af34(*(undefined4 *)(param_1 + 0x2c));
    FUN_8002af34(*(undefined4 *)(param_1 + 0x30));
    FUN_8002af34(*(undefined4 *)(param_1 + 0x34));
    FUN_8002af34(*(undefined4 *)(param_1 + 0x38));
    FUN_8002af34(*(undefined4 *)(param_1 + 0x1c));
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



// ---- FUN_80032d18 @ 80032d18

uint FUN_80032d18(int param_1,uint param_2)

{
  if (param_2 != 0xffffffff) {
    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) & 0xfffffff9 | (param_2 & 3) << 1;
  }
  return *(uint *)(param_1 + 0x3c) >> 1 & 3;
}



// ---- FUN_80032d54 @ 80032d54

void FUN_80032d54(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) & 0xfffe1fff | (param_2 & 0xf) << 0xd;
  return;
}



// ---- FUN_80032d78 @ 80032d78

void FUN_80032d78(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) & 0xcfffffff | (param_2 & 3) << 0x1c;
  return;
}



// ---- FUN_80032d9c @ 80032d9c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_80032d9c(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = (uint)(param_2 < 2);
  if (uVar1 == 0) {
    if (param_1 == 0) {
      uVar1 = (uint)*(byte *)(_DAT_800abf64 + 0x18eb);
    }
    else {
      uVar1 = *(byte *)(param_1 + 0x3f) & 1;
    }
  }
  else if (param_1 == 0) {
    *(char *)(_DAT_800abf64 + 0x18eb) = (char)param_2;
  }
  else {
    uVar1 = (param_2 & 1) << 0x18;
    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) & 0xfeffffff | uVar1;
  }
  return uVar1;
}



// ---- FUN_80032e0c @ 80032e0c

void FUN_80032e0c(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) & 0xff01ffff | (param_2 & 0x7f) << 0x11;
  return;
}



// ---- FUN_80032e30 @ 80032e30

void FUN_80032e30(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) & 0xbfffffff | (param_2 & 1) << 0x1e;
  return;
}



// ---- FUN_80032e54 @ 80032e54

void FUN_80032e54(int param_1,uint param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  if (param_2 < 2) {
    uVar2 = *(uint *)(param_1 + 0x3c);
    *(uint *)(param_1 + 0x3c) = uVar2 & 0xf1ffffff | (param_2 & 1) << 0x19 | (param_3 & 3) << 0x1a;
    uVar2 = (uVar2 & 0x1f0) >> 4;
    if (uVar2 == 6) {
      iVar3 = *(int *)(param_1 + 0x1c);
      if (param_2 == 0) {
        *(byte *)(iVar3 + 0x57) = *(byte *)(iVar3 + 0x57) & 0xfd;
      }
      else {
        *(byte *)(iVar3 + 0x57) = *(byte *)(iVar3 + 0x57) | 2;
      }
    }
    else if (uVar2 < 7) {
      if (uVar2 == 4) {
        iVar3 = *(int *)(param_1 + 0x1c);
        if (param_2 == 0) {
          *(byte *)(iVar3 + 0x4f) = *(byte *)(iVar3 + 0x4f) & 0xfd;
        }
        else {
          *(byte *)(iVar3 + 0x4f) = *(byte *)(iVar3 + 0x4f) | 2;
        }
      }
    }
    else if (uVar2 == 0xf) {
      iVar3 = *(int *)(param_1 + 0x1c);
      if (param_2 == 0) {
        *(byte *)(iVar3 + 0x2f) = *(byte *)(iVar3 + 0x2f) & 0xfd;
      }
      else {
        *(byte *)(iVar3 + 0x2f) = *(byte *)(iVar3 + 0x2f) | 2;
      }
    }
    else if (uVar2 == 0x12) {
      iVar3 = *(int *)(param_1 + 0x1c);
      if (param_2 == 0) {
        bVar1 = *(byte *)(iVar3 + 0x27) & 0xfd;
      }
      else {
        bVar1 = *(byte *)(iVar3 + 0x27) | 2;
      }
      *(byte *)(iVar3 + 0x27) = bVar1;
    }
  }
  return;
}



// ---- FUN_80032fac @ 80032fac

uint FUN_80032fac(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined2 local_18;
  undefined2 local_16;
  
  FUN_80031eb4(param_2 & 0xff,param_3 & 0xff,&local_18);
  uVar2 = *(uint *)(param_1 + 0x3c) >> 4 & 0x1f;
  if (uVar2 == 0xf) {
    iVar3 = *(int *)(param_1 + 0x1c);
    if (((int)param_2 < 0) || ((int)param_3 < 0)) {
      uVar1 = (uint)*(ushort *)(iVar3 + 0x36);
    }
    else {
      uVar1 = FUN_8005c5a4(local_18,local_16);
      *(short *)(iVar3 + 0x36) = (short)uVar1;
    }
  }
  else {
    uVar1 = 0;
    if ((uVar2 < 0x10) && (uVar1 = 6, uVar2 == 6)) {
      iVar3 = *(int *)(param_1 + 0x1c);
      if (((int)param_2 < 0) || ((int)param_3 < 0)) {
        uVar1 = (uint)*(ushort *)(iVar3 + 0x5e);
      }
      else {
        uVar1 = FUN_8005c5a4(local_18,local_16);
        *(short *)(iVar3 + 0x5e) = (short)uVar1;
      }
    }
  }
  return uVar1;
}



// ---- FUN_80033094 @ 80033094

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80033094(int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = _DAT_800abf64;
  if (param_1 == 0) {
    *(undefined1 *)(_DAT_800abf64 + 0x18e8) = param_2;
    *(undefined1 *)(iVar2 + 0x18e9) = param_3;
    *(undefined1 *)(iVar2 + 0x18ea) = param_4;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x3c) >> 4 & 0x1f;
    if (uVar1 == 6) {
      iVar2 = *(int *)(param_1 + 0x1c);
      *(undefined1 *)(iVar2 + 0x54) = param_2;
      *(undefined1 *)(iVar2 + 0x55) = param_3;
      *(undefined1 *)(iVar2 + 0x56) = param_4;
    }
    else if (uVar1 < 7) {
      if (uVar1 == 4) {
        iVar2 = *(int *)(param_1 + 0x1c);
        if ((param_5 & 1) != 0) {
          *(undefined1 *)(iVar2 + 0x4c) = param_2;
          *(undefined1 *)(iVar2 + 0x4d) = param_3;
          *(undefined1 *)(iVar2 + 0x4e) = param_4;
        }
        if ((param_5 & 2) != 0) {
          *(undefined1 *)(iVar2 + 0x54) = param_2;
          *(undefined1 *)(iVar2 + 0x55) = param_3;
          *(undefined1 *)(iVar2 + 0x56) = param_4;
        }
        if ((param_5 & 4) != 0) {
          *(undefined1 *)(iVar2 + 0x5c) = param_2;
          *(undefined1 *)(iVar2 + 0x5d) = param_3;
          *(undefined1 *)(iVar2 + 0x5e) = param_4;
        }
        if ((param_5 & 8) != 0) {
          *(undefined1 *)(iVar2 + 100) = param_2;
          *(undefined1 *)(iVar2 + 0x65) = param_3;
          *(undefined1 *)(iVar2 + 0x66) = param_4;
        }
      }
    }
    else if (uVar1 == 0xf) {
      iVar2 = *(int *)(param_1 + 0x1c);
      *(undefined1 *)(iVar2 + 0x2c) = param_2;
      *(undefined1 *)(iVar2 + 0x2d) = param_3;
      *(undefined1 *)(iVar2 + 0x2e) = param_4;
    }
    else if (uVar1 == 0x12) {
      iVar2 = *(int *)(param_1 + 0x1c);
      *(undefined1 *)(iVar2 + 0x24) = param_2;
      *(undefined1 *)(iVar2 + 0x25) = param_3;
      *(undefined1 *)(iVar2 + 0x26) = param_4;
    }
  }
  return;
}



// ---- FUN_800331ac @ 800331ac

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800331ac(int param_1,undefined1 *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = _DAT_800abf64;
  if (param_1 == 0) {
    *param_2 = *(undefined1 *)(_DAT_800abf64 + 0x18e8);
    param_2[1] = *(undefined1 *)(iVar2 + 0x18e9);
    param_2[2] = *(undefined1 *)(iVar2 + 0x18ea);
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x3c) >> 4 & 0x1f;
    if (uVar1 == 6) {
      iVar2 = *(int *)(param_1 + 0x1c);
      *param_2 = *(undefined1 *)(iVar2 + 0x54);
      param_2[1] = *(undefined1 *)(iVar2 + 0x55);
      param_2[2] = *(undefined1 *)(iVar2 + 0x56);
    }
    else if (uVar1 < 7) {
      if (uVar1 == 4) {
        iVar2 = *(int *)(param_1 + 0x1c);
        if (param_3 == 2) {
          *param_2 = *(undefined1 *)(iVar2 + 0x54);
          param_2[1] = *(undefined1 *)(iVar2 + 0x55);
          param_2[2] = *(undefined1 *)(iVar2 + 0x56);
        }
        else if (param_3 < 3) {
          if (param_3 == 1) {
            *param_2 = *(undefined1 *)(iVar2 + 0x4c);
            param_2[1] = *(undefined1 *)(iVar2 + 0x4d);
            param_2[2] = *(undefined1 *)(iVar2 + 0x4e);
          }
        }
        else if (param_3 == 4) {
          *param_2 = *(undefined1 *)(iVar2 + 0x5c);
          param_2[1] = *(undefined1 *)(iVar2 + 0x5d);
          param_2[2] = *(undefined1 *)(iVar2 + 0x5e);
        }
        else if (param_3 == 8) {
          *param_2 = *(undefined1 *)(iVar2 + 100);
          param_2[1] = *(undefined1 *)(iVar2 + 0x65);
          param_2[2] = *(undefined1 *)(iVar2 + 0x66);
        }
      }
    }
    else if (uVar1 == 0xf) {
      iVar2 = *(int *)(param_1 + 0x1c);
      *param_2 = *(undefined1 *)(iVar2 + 0x2c);
      param_2[1] = *(undefined1 *)(iVar2 + 0x2d);
      param_2[2] = *(undefined1 *)(iVar2 + 0x2e);
    }
    else if (uVar1 == 0x12) {
      iVar2 = *(int *)(param_1 + 0x1c);
      *param_2 = *(undefined1 *)(iVar2 + 0x24);
      param_2[1] = *(undefined1 *)(iVar2 + 0x25);
      param_2[2] = *(undefined1 *)(iVar2 + 0x26);
    }
  }
  return;
}



// ---- FUN_80033388 @ 80033388

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80033388(int param_1,char param_2,char param_3,char param_4,int param_5)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = _DAT_800abf64;
  if (param_1 == 0) {
    pcVar1 = (char *)(_DAT_800abf64 + 0x18ea);
    *(char *)(_DAT_800abf64 + 0x18e8) = param_2 + *(char *)(_DAT_800abf64 + 0x18e8);
    *(char *)(iVar3 + 0x18ea) = param_4 + *pcVar1;
    *(char *)(iVar3 + 0x18e9) = param_3 + *(char *)(iVar3 + 0x18e9);
    return;
  }
  uVar2 = *(uint *)(param_1 + 0x3c) >> 4 & 0x1f;
  if (uVar2 == 6) {
    iVar3 = *(int *)(param_1 + 0x1c);
  }
  else {
    if (6 < uVar2) {
      if (uVar2 == 0xf) {
        iVar3 = *(int *)(param_1 + 0x1c);
        *(char *)(iVar3 + 0x2c) = param_2 + *(char *)(iVar3 + 0x2c);
        *(char *)(iVar3 + 0x2e) = param_4 + *(char *)(iVar3 + 0x2e);
        *(char *)(iVar3 + 0x2d) = param_3 + *(char *)(iVar3 + 0x2d);
        return;
      }
      if (uVar2 == 0x12) {
        iVar3 = *(int *)(param_1 + 0x1c);
        *(char *)(iVar3 + 0x24) = param_2 + *(char *)(iVar3 + 0x24);
        *(char *)(iVar3 + 0x26) = param_4 + *(char *)(iVar3 + 0x26);
        *(char *)(iVar3 + 0x25) = param_3 + *(char *)(iVar3 + 0x25);
        return;
      }
      return;
    }
    if (uVar2 != 4) {
      return;
    }
    iVar3 = *(int *)(param_1 + 0x1c);
    if (param_5 != 2) {
      if (param_5 < 3) {
        if (param_5 == 1) {
          *(char *)(iVar3 + 0x4c) = param_2 + *(char *)(iVar3 + 0x4c);
          *(char *)(iVar3 + 0x4e) = param_4 + *(char *)(iVar3 + 0x4e);
          *(char *)(iVar3 + 0x4d) = param_3 + *(char *)(iVar3 + 0x4d);
          return;
        }
        return;
      }
      if (param_5 == 4) {
        *(char *)(iVar3 + 0x5c) = param_2 + *(char *)(iVar3 + 0x5c);
        *(char *)(iVar3 + 0x5e) = param_4 + *(char *)(iVar3 + 0x5e);
        *(char *)(iVar3 + 0x5d) = param_3 + *(char *)(iVar3 + 0x5d);
        return;
      }
      if (param_5 == 8) {
        *(char *)(iVar3 + 100) = param_2 + *(char *)(iVar3 + 100);
        *(char *)(iVar3 + 0x66) = param_4 + *(char *)(iVar3 + 0x66);
        *(char *)(iVar3 + 0x65) = param_3 + *(char *)(iVar3 + 0x65);
        return;
      }
      return;
    }
  }
  *(char *)(iVar3 + 0x54) = param_2 + *(char *)(iVar3 + 0x54);
  *(char *)(iVar3 + 0x56) = param_4 + *(char *)(iVar3 + 0x56);
  *(char *)(iVar3 + 0x55) = param_3 + *(char *)(iVar3 + 0x55);
  return;
}



// ---- FUN_80033560 @ 80033560

void FUN_80033560(int param_1,undefined2 param_2,undefined2 param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_1 + 0x3c) >> 4 & 0x1f;
  if (uVar1 == 6) {
    iVar2 = *(int *)(param_1 + 0x1c);
    if ((param_4 & 1) != 0) {
      *(undefined2 *)(iVar2 + 0x58) = param_2;
      *(undefined2 *)(iVar2 + 0x5a) = param_3;
    }
    if ((param_4 & 2) != 0) {
      *(undefined2 *)(iVar2 + 0x60) = param_2;
      *(undefined2 *)(iVar2 + 0x62) = param_3;
    }
    if ((param_4 & 4) != 0) {
      *(undefined2 *)(iVar2 + 0x68) = param_2;
      *(undefined2 *)(iVar2 + 0x6a) = param_3;
    }
    if ((param_4 & 8) != 0) {
      *(undefined2 *)(iVar2 + 0x70) = param_2;
      *(undefined2 *)(iVar2 + 0x72) = param_3;
    }
  }
  else if (uVar1 < 7) {
    if (uVar1 == 4) {
      iVar2 = *(int *)(param_1 + 0x1c);
      if ((param_4 & 1) != 0) {
        *(undefined2 *)(iVar2 + 0x50) = param_2;
        *(undefined2 *)(iVar2 + 0x52) = param_3;
      }
      if ((param_4 & 2) != 0) {
        *(undefined2 *)(iVar2 + 0x58) = param_2;
        *(undefined2 *)(iVar2 + 0x5a) = param_3;
      }
      if ((param_4 & 4) != 0) {
        *(undefined2 *)(iVar2 + 0x60) = param_2;
        *(undefined2 *)(iVar2 + 0x62) = param_3;
      }
      if ((param_4 & 8) != 0) {
        *(undefined2 *)(iVar2 + 0x68) = param_2;
        *(undefined2 *)(iVar2 + 0x6a) = param_3;
      }
    }
  }
  else if (uVar1 == 0xf) {
    iVar2 = *(int *)(param_1 + 0x1c);
    *(undefined2 *)(iVar2 + 0x30) = param_2;
    *(undefined2 *)(iVar2 + 0x32) = param_3;
  }
  else if (uVar1 == 0x12) {
    iVar2 = *(int *)(param_1 + 0x1c);
    *(undefined2 *)(iVar2 + 0x28) = param_2;
    *(undefined2 *)(iVar2 + 0x2a) = param_3;
  }
  return;
}



// ---- FUN_80033848 @ 80033848

void FUN_80033848(int param_1,short param_2,short param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 != 0) {
    uVar1 = *(uint *)(param_1 + 0x3c) >> 4 & 0x1f;
    if (uVar1 == 6) {
      iVar2 = *(int *)(param_1 + 0x1c);
      if ((param_4 & 1) != 0) {
        *(short *)(iVar2 + 0x58) = param_2 + *(short *)(iVar2 + 0x58);
        *(short *)(iVar2 + 0x5a) = param_3 + *(short *)(iVar2 + 0x5a);
      }
      if ((param_4 & 2) != 0) {
        *(short *)(iVar2 + 0x60) = param_2 + *(short *)(iVar2 + 0x60);
        *(short *)(iVar2 + 0x62) = param_3 + *(short *)(iVar2 + 0x62);
      }
      if ((param_4 & 4) != 0) {
        *(short *)(iVar2 + 0x68) = param_2 + *(short *)(iVar2 + 0x68);
        *(short *)(iVar2 + 0x6a) = param_3 + *(short *)(iVar2 + 0x6a);
      }
      if ((param_4 & 8) != 0) {
        *(short *)(iVar2 + 0x70) = param_2 + *(short *)(iVar2 + 0x70);
        *(short *)(iVar2 + 0x72) = param_3 + *(short *)(iVar2 + 0x72);
      }
    }
    else if (uVar1 < 7) {
      if (uVar1 == 4) {
        iVar2 = *(int *)(param_1 + 0x1c);
        if ((param_4 & 1) != 0) {
          *(short *)(iVar2 + 0x50) = param_2 + *(short *)(iVar2 + 0x50);
          *(short *)(iVar2 + 0x52) = param_3 + *(short *)(iVar2 + 0x52);
        }
        if ((param_4 & 2) != 0) {
          *(short *)(iVar2 + 0x58) = param_2 + *(short *)(iVar2 + 0x58);
          *(short *)(iVar2 + 0x5a) = param_3 + *(short *)(iVar2 + 0x5a);
        }
        if ((param_4 & 4) != 0) {
          *(short *)(iVar2 + 0x60) = param_2 + *(short *)(iVar2 + 0x60);
          *(short *)(iVar2 + 0x62) = param_3 + *(short *)(iVar2 + 0x62);
        }
        if ((param_4 & 8) != 0) {
          *(short *)(iVar2 + 0x68) = param_2 + *(short *)(iVar2 + 0x68);
          *(short *)(iVar2 + 0x6a) = param_3 + *(short *)(iVar2 + 0x6a);
        }
      }
    }
    else if (uVar1 == 0xf) {
      iVar2 = *(int *)(param_1 + 0x1c);
      *(short *)(iVar2 + 0x30) = param_2 + *(short *)(iVar2 + 0x30);
      *(short *)(iVar2 + 0x32) = param_3 + *(short *)(iVar2 + 0x32);
    }
    else if (uVar1 == 0x12) {
      iVar2 = *(int *)(param_1 + 0x1c);
      *(short *)(iVar2 + 0x28) = param_2 + *(short *)(iVar2 + 0x28);
      *(short *)(iVar2 + 0x2a) = param_3 + *(short *)(iVar2 + 0x2a);
    }
  }
  return;
}



// ---- FUN_80033a18 @ 80033a18

void FUN_80033a18(int param_1,short param_2,short param_3,int param_4)

{
  short sVar1;
  short sVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  int iVar6;
  char cVar7;
  uint uVar8;
  
  uVar8 = *(uint *)(param_1 + 0x3c) >> 4 & 0x1f;
  if (uVar8 == 6) {
    iVar6 = *(int *)(param_1 + 0x1c);
    sVar1 = *(short *)(iVar6 + 0x58);
    sVar2 = *(short *)(iVar6 + 0x5a);
    if (param_4 == 0x10) {
      cVar3 = (char)sVar1;
      cVar7 = (char)param_2 + cVar3;
      cVar4 = (char)sVar2;
      cVar5 = (char)param_3 + cVar4;
      *(char *)(iVar6 + 0x5c) = cVar3;
      *(char *)(iVar6 + 0x5d) = cVar4;
      *(char *)(iVar6 + 100) = cVar7;
      *(char *)(iVar6 + 0x65) = cVar4;
      *(char *)(iVar6 + 0x6c) = cVar3;
      *(char *)(iVar6 + 0x6d) = cVar5;
      *(char *)(iVar6 + 0x74) = cVar7;
      *(char *)(iVar6 + 0x75) = cVar5;
    }
    else if (param_4 == 0x40) {
      *(short *)(iVar6 + 0x58) = sVar1;
      *(short *)(iVar6 + 0x5a) = sVar2;
      *(short *)(iVar6 + 0x60) = param_2 + sVar1;
      *(short *)(iVar6 + 0x62) = sVar2;
      *(short *)(iVar6 + 0x68) = sVar1;
      *(short *)(iVar6 + 0x6a) = param_3 + sVar2;
      *(short *)(iVar6 + 0x70) = param_2 + sVar1;
      *(short *)(iVar6 + 0x72) = param_3 + sVar2;
    }
  }
  else if (uVar8 < 7) {
    if (uVar8 == 4) {
      iVar6 = *(int *)(param_1 + 0x1c);
      sVar1 = *(short *)(iVar6 + 0x50);
      sVar2 = *(short *)(iVar6 + 0x52);
      *(short *)(iVar6 + 0x50) = sVar1;
      *(short *)(iVar6 + 0x52) = sVar2;
      *(short *)(iVar6 + 0x58) = param_2 + sVar1;
      *(short *)(iVar6 + 0x5a) = sVar2;
      *(short *)(iVar6 + 0x60) = sVar1;
      *(short *)(iVar6 + 0x62) = param_3 + sVar2;
      *(short *)(iVar6 + 0x68) = param_2 + sVar1;
      *(short *)(iVar6 + 0x6a) = param_3 + sVar2;
    }
  }
  else if (uVar8 == 0xf) {
    iVar6 = *(int *)(param_1 + 0x1c);
    *(short *)(iVar6 + 0x38) = param_2;
    *(short *)(iVar6 + 0x3a) = param_3;
  }
  else if (uVar8 == 0x12) {
    iVar6 = *(int *)(param_1 + 0x1c);
    *(short *)(iVar6 + 0x2c) = param_2;
    *(short *)(iVar6 + 0x2e) = param_3;
  }
  return;
}



// ---- FUN_80033bc8 @ 80033bc8

void FUN_80033bc8(int param_1,short param_2,short param_3,int param_4)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined1 uVar3;
  int iVar4;
  char cVar5;
  uint uVar6;
  char cVar7;
  undefined1 uVar8;
  
  uVar6 = *(uint *)(param_1 + 0x3c) >> 4 & 0x1f;
  if (uVar6 == 6) {
    iVar4 = *(int *)(param_1 + 0x1c);
    if (param_4 == 0x10) {
      uVar1 = *(undefined2 *)(iVar4 + 0x58);
      uVar2 = *(undefined2 *)(iVar4 + 0x5a);
      param_2 = *(short *)(iVar4 + 0x60) + param_2;
      param_3 = *(short *)(iVar4 + 0x6a) + param_3;
      *(undefined2 *)(iVar4 + 0x58) = uVar1;
      *(undefined2 *)(iVar4 + 0x5a) = uVar2;
      *(short *)(iVar4 + 0x60) = param_2;
      *(undefined2 *)(iVar4 + 0x62) = uVar2;
      *(undefined2 *)(iVar4 + 0x68) = uVar1;
      *(short *)(iVar4 + 0x6a) = param_3;
      *(short *)(iVar4 + 0x70) = param_2;
      *(short *)(iVar4 + 0x72) = param_3;
    }
    else {
      cVar5 = (char)*(undefined2 *)(iVar4 + 0x60) + (char)param_2;
      cVar7 = (char)*(undefined2 *)(iVar4 + 0x6a) + (char)param_3;
      uVar8 = (undefined1)*(undefined2 *)(iVar4 + 0x58);
      *(undefined1 *)(iVar4 + 0x5c) = uVar8;
      uVar3 = (undefined1)*(undefined2 *)(iVar4 + 0x5a);
      *(undefined1 *)(iVar4 + 0x5d) = uVar3;
      *(char *)(iVar4 + 100) = cVar5;
      *(undefined1 *)(iVar4 + 0x65) = uVar3;
      *(undefined1 *)(iVar4 + 0x6c) = uVar8;
      *(char *)(iVar4 + 0x6d) = cVar7;
      *(char *)(iVar4 + 0x74) = cVar5;
      *(char *)(iVar4 + 0x75) = cVar7;
    }
  }
  else if (uVar6 < 7) {
    if (uVar6 == 4) {
      iVar4 = *(int *)(param_1 + 0x1c);
      uVar1 = *(undefined2 *)(iVar4 + 0x50);
      uVar2 = *(undefined2 *)(iVar4 + 0x52);
      param_2 = *(short *)(iVar4 + 0x58) + param_2;
      *(undefined2 *)(iVar4 + 0x50) = uVar1;
      *(undefined2 *)(iVar4 + 0x52) = uVar2;
      *(short *)(iVar4 + 0x58) = param_2;
      *(undefined2 *)(iVar4 + 0x5a) = uVar2;
      *(undefined2 *)(iVar4 + 0x60) = uVar1;
      *(short *)(iVar4 + 0x68) = param_2;
      param_3 = *(short *)(iVar4 + 0x62) + param_3;
      *(short *)(iVar4 + 0x62) = param_3;
      *(short *)(iVar4 + 0x6a) = param_3;
    }
  }
  else if (uVar6 == 0xf) {
    iVar4 = *(int *)(param_1 + 0x1c);
    *(short *)(iVar4 + 0x38) = param_2 + *(short *)(iVar4 + 0x38);
    *(short *)(iVar4 + 0x3a) = param_3 + *(short *)(iVar4 + 0x3a);
  }
  else if (uVar6 == 0x12) {
    iVar4 = *(int *)(param_1 + 0x1c);
    *(short *)(iVar4 + 0x2c) = param_2 + *(short *)(iVar4 + 0x2c);
    *(short *)(iVar4 + 0x2e) = param_3 + *(short *)(iVar4 + 0x2e);
  }
  return;
}



// ---- FUN_80033d40 @ 80033d40

void FUN_80033d40(int param_1,undefined1 param_2,undefined1 param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_1 + 0x3c) >> 4 & 0x1f;
  if (uVar1 == 0xf) {
    iVar2 = *(int *)(param_1 + 0x1c);
    *(undefined1 *)(iVar2 + 0x34) = param_2;
    *(undefined1 *)(iVar2 + 0x35) = param_3;
  }
  else if ((uVar1 < 0x10) && (uVar1 == 6)) {
    iVar2 = *(int *)(param_1 + 0x1c);
    if ((param_4 & 1) != 0) {
      *(undefined1 *)(iVar2 + 0x5c) = param_2;
      *(undefined1 *)(iVar2 + 0x5d) = param_3;
    }
    if ((param_4 & 2) != 0) {
      *(undefined1 *)(iVar2 + 100) = param_2;
      *(undefined1 *)(iVar2 + 0x65) = param_3;
    }
    if ((param_4 & 4) != 0) {
      *(undefined1 *)(iVar2 + 0x6c) = param_2;
      *(undefined1 *)(iVar2 + 0x6d) = param_3;
    }
    if ((param_4 & 8) != 0) {
      *(undefined1 *)(iVar2 + 0x74) = param_2;
      *(undefined1 *)(iVar2 + 0x75) = param_3;
    }
  }
  return;
}



// ---- FUN_80033dcc @ 80033dcc

void FUN_80033dcc(int param_1,undefined1 param_2,undefined1 param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  undefined1 local_18 [2];
  undefined1 local_16;
  
  FUN_80031e88(param_2,local_18,param_3);
  uVar1 = *(uint *)(param_1 + 0x3c) >> 4 & 0x1f;
  if (uVar1 == 0xf) {
    iVar2 = *(int *)(param_1 + 0x1c);
    *(undefined1 *)(iVar2 + 0x34) = local_18[0];
    *(undefined1 *)(iVar2 + 0x35) = local_16;
  }
  else if ((uVar1 < 0x10) && (uVar1 == 6)) {
    iVar2 = *(int *)(param_1 + 0x1c);
    if ((param_4 & 1) != 0) {
      *(undefined1 *)(iVar2 + 0x5c) = local_18[0];
      *(undefined1 *)(iVar2 + 0x5d) = local_16;
    }
    if ((param_4 & 2) != 0) {
      *(undefined1 *)(iVar2 + 100) = local_18[0];
      *(undefined1 *)(iVar2 + 0x65) = local_16;
    }
    if ((param_4 & 4) != 0) {
      *(undefined1 *)(iVar2 + 0x6c) = local_18[0];
      *(undefined1 *)(iVar2 + 0x6d) = local_16;
    }
    if ((param_4 & 8) != 0) {
      *(undefined1 *)(iVar2 + 0x74) = local_18[0];
      *(undefined1 *)(iVar2 + 0x75) = local_16;
    }
  }
  return;
}



// ---- FUN_80033fe0 @ 80033fe0

void FUN_80033fe0(int param_1,char param_2,char param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_1 + 0x3c) >> 4 & 0x1f;
  if (uVar1 == 0xf) {
    iVar2 = *(int *)(param_1 + 0x1c);
    *(char *)(iVar2 + 0x34) = param_2 + *(char *)(iVar2 + 0x34);
    *(char *)(iVar2 + 0x35) = param_3 + *(char *)(iVar2 + 0x35);
  }
  else if ((uVar1 < 0x10) && (uVar1 == 6)) {
    iVar2 = *(int *)(param_1 + 0x1c);
    if ((param_4 & 1) != 0) {
      *(char *)(iVar2 + 0x5c) = param_2 + *(char *)(iVar2 + 0x5c);
      *(char *)(iVar2 + 0x5d) = param_3 + *(char *)(iVar2 + 0x5d);
    }
    if ((param_4 & 2) != 0) {
      *(char *)(iVar2 + 100) = param_2 + *(char *)(iVar2 + 100);
      *(char *)(iVar2 + 0x65) = param_3 + *(char *)(iVar2 + 0x65);
    }
    if ((param_4 & 4) != 0) {
      *(char *)(iVar2 + 0x6c) = param_2 + *(char *)(iVar2 + 0x6c);
      *(char *)(iVar2 + 0x6d) = param_3 + *(char *)(iVar2 + 0x6d);
    }
    if ((param_4 & 8) != 0) {
      *(char *)(iVar2 + 0x74) = param_2 + *(char *)(iVar2 + 0x74);
      *(char *)(iVar2 + 0x75) = param_3 + *(char *)(iVar2 + 0x75);
    }
  }
  return;
}



// ---- FUN_800340c8 @ 800340c8

void FUN_800340c8(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xc0000000;
  return;
}



// ---- FUN_800340f8 @ 800340f8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800340f8(int param_1)

{
  uint uVar1;
  
  if (*(code **)(param_1 + 0x10) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x10))(_DAT_800abf64,param_1,*(undefined4 *)(param_1 + 0x14));
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xc1ffffff | (uVar1 & 0x1f) << 0x19;
  }
  return;
}



// ---- FUN_8003415c @ 8003415c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003415c(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint *puVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  char *pcVar14;
  int iVar15;
  int unaff_s1;
  int iVar16;
  undefined2 local_18;
  undefined2 local_16;
  
  iVar1 = _DAT_800abf64;
  pcVar14 = (char *)(_DAT_800abf64 + 0x18e8);
  if ((*(uint *)(param_1 + 0x3c) >> 1 & 1) == 0) {
    uVar3 = *(uint *)(param_1 + 0x3c) & 0x1000000;
  }
  else {
    uVar3 = (uint)*(byte *)(_DAT_800abf64 + 0x18eb);
  }
  if (uVar3 == 0) {
    return;
  }
  uVar3 = *(uint *)(param_1 + 0x3c) >> 4 & 0x1f;
  if (uVar3 == 6) {
    iVar15 = *(int *)(param_1 + 0x1c);
    puVar11 = (undefined4 *)(iVar15 + 0x50);
    puVar13 = (undefined4 *)(_DAT_800b05cc * 0x28 + iVar15);
    do {
      puVar12 = puVar13;
      puVar10 = puVar11;
      uVar5 = puVar10[1];
      uVar7 = puVar10[2];
      uVar9 = puVar10[3];
      *puVar12 = *puVar10;
      puVar12[1] = uVar5;
      puVar12[2] = uVar7;
      puVar12[3] = uVar9;
      puVar11 = puVar10 + 4;
      puVar13 = puVar12 + 4;
    } while (puVar11 != (undefined4 *)(iVar15 + 0x70));
    uVar5 = puVar10[5];
    puVar12[4] = *puVar11;
    puVar12[5] = uVar5;
    FUN_80031e14(*(byte *)(param_1 + 0x3e) >> 1,&local_18);
    uVar2 = FUN_8005c510(*(uint *)(param_1 + 0x3c) >> 0x1c & 3,*(uint *)(param_1 + 0x3c) >> 0x1a & 3
                         ,local_18,local_16);
    *(undefined2 *)(_DAT_800b05cc * 0x28 + iVar15 + 0x16) = uVar2;
    FUN_80031e74(*(uint *)(param_1 + 0x3c) >> 0x11 & 0x7f,&local_18,
                 *(uint *)(param_1 + 0x3c) >> 0x1c & 3);
    iVar16 = _DAT_800b05cc * 0x28 + iVar15;
    *(char *)(iVar16 + 0xc) = *(char *)(iVar16 + 0xc) + (char)local_18;
    iVar16 = _DAT_800b05cc * 0x28 + iVar15;
    *(char *)(iVar16 + 0xd) = *(char *)(iVar16 + 0xd) + (char)local_16;
    if ((*(uint *)(param_1 + 0x3c) >> 1 & 2) != 0) {
      if (*pcVar14 != -0x80) {
        *(char *)(_DAT_800b05cc * 0x28 + iVar15 + 4) = *pcVar14;
      }
      if (*(char *)(iVar1 + 0x18e9) != -0x80) {
        *(undefined1 *)(_DAT_800b05cc * 0x28 + iVar15 + 5) = *(undefined1 *)(iVar1 + 0x18e9);
      }
      if (*(char *)(iVar1 + 0x18ea) != -0x80) {
        *(undefined1 *)(_DAT_800b05cc * 0x28 + iVar15 + 6) = *(undefined1 *)(iVar1 + 0x18ea);
      }
    }
    puVar4 = (uint *)(_DAT_800b05cc * 0x28 + iVar15);
    uVar6 = *puVar4;
    uVar3 = *(uint *)(param_1 + 0x3c) >> 0xb & 0x3c;
  }
  else if (uVar3 < 7) {
    if (uVar3 != 4) goto LAB_80034874;
    iVar15 = *(int *)(param_1 + 0x1c);
    puVar13 = (undefined4 *)(_DAT_800b05cc * 0x24 + iVar15);
    puVar11 = (undefined4 *)(iVar15 + 0x48);
    do {
      uVar5 = puVar11[1];
      uVar7 = puVar11[2];
      uVar9 = puVar11[3];
      *puVar13 = *puVar11;
      puVar13[1] = uVar5;
      puVar13[2] = uVar7;
      puVar13[3] = uVar9;
      puVar11 = puVar11 + 4;
      puVar13 = puVar13 + 4;
    } while (puVar11 != (undefined4 *)(iVar15 + 0x68));
    *puVar13 = *puVar11;
    if ((*(uint *)(param_1 + 0x3c) >> 1 & 2) != 0) {
      if (*pcVar14 != -0x80) {
        *(char *)(_DAT_800b05cc * 0x24 + iVar15 + 4) = *pcVar14;
      }
      if (*(char *)(iVar1 + 0x18e9) != -0x80) {
        *(undefined1 *)(_DAT_800b05cc * 0x24 + iVar15 + 5) = *(undefined1 *)(iVar1 + 0x18e9);
      }
      if (*(char *)(iVar1 + 0x18ea) != -0x80) {
        *(undefined1 *)(_DAT_800b05cc * 0x24 + iVar15 + 6) = *(undefined1 *)(iVar1 + 0x18ea);
      }
    }
    puVar4 = (uint *)(_DAT_800b05cc * 0x24 + iVar15);
    uVar6 = *puVar4;
    uVar3 = *(uint *)(param_1 + 0x3c) >> 0xb & 0x3c;
  }
  else if (uVar3 == 0xf) {
    iVar16 = *(int *)(param_1 + 0x1c);
    puVar11 = (undefined4 *)(_DAT_800b05cc * 0x14 + iVar16);
    uVar5 = *(undefined4 *)(iVar16 + 0x2c);
    uVar7 = *(undefined4 *)(iVar16 + 0x30);
    uVar9 = *(undefined4 *)(iVar16 + 0x34);
    *puVar11 = *(undefined4 *)(iVar16 + 0x28);
    puVar11[1] = uVar5;
    puVar11[2] = uVar7;
    puVar11[3] = uVar9;
    puVar11[4] = *(undefined4 *)(iVar16 + 0x38);
    FUN_80031e74(*(uint *)(param_1 + 0x3c) >> 0x11 & 0x7f,&local_18,
                 *(uint *)(param_1 + 0x3c) >> 0x1c & 3);
    iVar15 = _DAT_800b05cc * 0x14 + iVar16;
    *(char *)(iVar15 + 0xc) = *(char *)(iVar15 + 0xc) + (char)local_18;
    iVar15 = _DAT_800b05cc * 0x14 + iVar16;
    *(char *)(iVar15 + 0xd) = *(char *)(iVar15 + 0xd) + (char)local_16;
    if ((*(uint *)(param_1 + 0x3c) >> 1 & 2) != 0) {
      if (*pcVar14 != -0x80) {
        *(char *)(_DAT_800b05cc * 0x14 + iVar16 + 4) = *pcVar14;
      }
      if (*(char *)(iVar1 + 0x18e9) != -0x80) {
        *(undefined1 *)(_DAT_800b05cc * 0x14 + iVar16 + 5) = *(undefined1 *)(iVar1 + 0x18e9);
      }
      if (*(char *)(iVar1 + 0x18ea) != -0x80) {
        *(undefined1 *)(_DAT_800b05cc * 0x14 + iVar16 + 6) = *(undefined1 *)(iVar1 + 0x18ea);
      }
    }
    puVar4 = (uint *)(_DAT_800b05cc * 0x14 + iVar16);
    uVar6 = *puVar4;
    uVar3 = *(uint *)(param_1 + 0x3c) >> 0xb & 0x3c;
  }
  else {
    if (uVar3 != 0x12) goto LAB_80034874;
    iVar15 = *(int *)(param_1 + 0x1c);
    puVar11 = (undefined4 *)(_DAT_800b05cc * 0x10 + iVar15);
    uVar5 = *(undefined4 *)(iVar15 + 0x24);
    uVar7 = *(undefined4 *)(iVar15 + 0x28);
    uVar9 = *(undefined4 *)(iVar15 + 0x2c);
    *puVar11 = *(undefined4 *)(iVar15 + 0x20);
    puVar11[1] = uVar5;
    puVar11[2] = uVar7;
    puVar11[3] = uVar9;
    if ((*(uint *)(param_1 + 0x3c) >> 1 & 2) != 0) {
      if (*pcVar14 != -0x80) {
        *(char *)(_DAT_800b05cc * 0x14 + unaff_s1 + 4) = *pcVar14;
      }
      if (*(char *)(iVar1 + 0x18e9) != -0x80) {
        *(undefined1 *)(_DAT_800b05cc * 0x14 + unaff_s1 + 5) = *(undefined1 *)(iVar1 + 0x18e9);
      }
      if (*(char *)(iVar1 + 0x18ea) != -0x80) {
        *(undefined1 *)(_DAT_800b05cc * 0x14 + unaff_s1 + 6) = *(undefined1 *)(iVar1 + 0x18ea);
      }
    }
    puVar4 = (uint *)(_DAT_800b05cc * 0x10 + iVar15);
    uVar3 = *(uint *)(param_1 + 0x3c) >> 0xb & 0x3c;
    uVar6 = *puVar4;
  }
  iVar1 = _DAT_800aeea0;
  *puVar4 = uVar6 & 0xff000000 | *(uint *)(uVar3 + _DAT_800aeea0) & 0xffffff;
  puVar8 = (uint *)((*(uint *)(param_1 + 0x3c) >> 0xb & 0x3c) + iVar1);
  *puVar8 = *puVar8 & 0xff000000 | (uint)puVar4 & 0xffffff;
LAB_80034874:
  if ((*(uint *)(param_1 + 0x3c) >> 9 & 1) != 0) {
    iVar15 = *(int *)(param_1 + 0x20);
    FUN_80031e14(*(uint *)(param_1 + 0x3c) >> 0x11 & 0x7f,&local_18);
    uVar2 = FUN_8005c510(*(uint *)(param_1 + 0x3c) >> 0x1c & 3,*(uint *)(param_1 + 0x3c) >> 0x1a & 3
                         ,local_18,local_16);
    FUN_8005a1d8(iVar15 + _DAT_800b05cc * 0xc,*(uint *)(param_1 + 0x3c) >> 0x1f,
                 *(uint *)(param_1 + 0x3c) >> 0x1e & 1,uVar2,0);
    iVar1 = _DAT_800aeea0;
    puVar8 = (uint *)(_DAT_800b05cc * 0xc + iVar15);
    *puVar8 = *puVar8 & 0xff000000 |
              *(uint *)((*(uint *)(param_1 + 0x3c) >> 0xb & 0x3c) + _DAT_800aeea0) & 0xffffff;
    puVar4 = (uint *)((*(uint *)(param_1 + 0x3c) >> 0xb & 0x3c) + iVar1);
    *puVar4 = *puVar4 & 0xff000000 | (uint)puVar8 & 0xffffff;
  }
  return;
}



// ---- FUN_80034988 @ 80034988

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80034988(void)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  
  iVar5 = _DAT_800abf64;
  iVar2 = _DAT_800abf64 + 0x46b0;
  puVar4 = (undefined1 *)(_DAT_800abf64 + 0x18ec);
  *(undefined1 *)(_DAT_800abf64 + 0x7a72) = 0;
  FUN_800585e4(iVar2,0x33c0);
  iVar2 = 0;
  puVar3 = puVar4;
  do {
    *puVar4 = 0;
    *(undefined4 *)(puVar3 + 0x10) = 0;
    puVar3 = puVar3 + 4;
    puVar1 = &DAT_80071034 + iVar2;
    iVar2 = iVar2 + 1;
    puVar4[0x50] = *puVar1;
    puVar4 = puVar4 + 1;
  } while (iVar2 < 0x10);
  *(undefined1 *)(iVar5 + 0x194c) = 0x80;
  *(undefined1 *)(iVar5 + 0x194d) = 0x80;
  *(undefined1 *)(iVar5 + 0x194e) = 0x80;
  *(undefined1 *)(iVar5 + 0x194f) = 1;
  *(undefined1 *)(iVar5 + 0x1950) = 1;
  iVar5 = _DAT_800abf64 + 0x1e88;
  FUN_80032568(iVar5,&LAB_80034a48);
  FUN_80032288(iVar5,0,1);
  return;
}



// ---- FUN_80034a80 @ 80034a80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80034a80(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar2 = _DAT_800abf64;
  puVar4 = (undefined1 *)(_DAT_800abf64 + 0x18ec);
  if (param_1 != 0) {
    if (((*(uint *)(param_1 + 0x58) & 0x1a0) == 0x180) &&
       (uVar6 = 0, *(int *)(*(int *)(param_1 + 0x1c) + 0x24) != 0)) {
      do {
        puVar3 = puVar4;
        do {
          if (*(char *)(*(int *)(param_1 + 0x40) + uVar6) == puVar3[0x50]) {
            *puVar3 = 0;
          }
          puVar3 = puVar3 + 1;
        } while ((int)puVar3 < iVar2 + 0x18fc);
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(*(int *)(param_1 + 0x1c) + 0x24));
    }
    FUN_8002af34(*(undefined4 *)(param_1 + 0x40));
    FUN_8002af34(*(undefined4 *)(param_1 + 0x44));
    iVar7 = 0;
    if ((*(uint *)(param_1 + 0x58) & 0x80) != 0) {
      FUN_8002af34(*(undefined4 *)(param_1 + 0x1c));
    }
    iVar5 = param_1;
    do {
      iVar7 = iVar7 + 1;
      FUN_8002af34(*(undefined4 *)(iVar5 + 0x30));
      puVar1 = (undefined4 *)(iVar5 + 0x38);
      iVar5 = iVar5 + 4;
      FUN_8002af34(*puVar1);
    } while (iVar7 < 2);
    if ((*(uint *)(param_1 + 0x58) & 1) == 0) {
      FUN_8002af34(param_1);
    }
    FUN_800585e4(param_1,0x5c);
    *(char *)(iVar2 + 0x7a72) = *(char *)(iVar2 + 0x7a72) + -1;
  }
  return;
}



// ---- FUN_80034bec @ 80034bec

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_80034bec(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = _DAT_800abf64;
  if (param_1 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)FUN_8002ac50(0x5c);
    uVar2 = 0;
    if (param_1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
  }
  else {
    uVar2 = 1;
    if ((param_1[3] & 0xf) != 0) {
      return (undefined4 *)0x0;
    }
  }
  *(undefined1 *)((int)param_1 + 0x49) = 0x80;
  *(undefined1 *)((int)param_1 + 0x4a) = 0x80;
  *(undefined1 *)((int)param_1 + 0x4b) = 0x80;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  *(undefined2 *)((int)param_1 + 0x22) = 0;
  *(undefined2 *)(param_1 + 9) = 0;
  param_1[0xb] = 0;
  *(undefined2 *)((int)param_1 + 0x26) = 0;
  param_1[10] = 0;
  param_1[7] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  *(undefined1 *)(param_1 + 0x12) = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  *(undefined1 *)(param_1 + 0x15) = 0;
  *(undefined1 *)((int)param_1 + 0x55) = 0;
  *(undefined1 *)((int)param_1 + 0x56) = 0;
  param_1[3] = param_1[3] & 0xffffe160 | 0x162;
  param_1[6] = param_1[6] & 0xc0000000;
  param_1[6] = param_1[6] | 0x40000000;
  *(undefined1 *)((int)param_1 + 0x57) = 0;
  param_1[0x16] = uVar2 | param_1[0x16] & 0x80040040 | 0x40040;
  *(char *)(iVar1 + 0x7a72) = *(char *)(iVar1 + 0x7a72) + '\x01';
  return param_1;
}



// ---- FUN_80034e00 @ 80034e00

void FUN_80034e00(int param_1,uint param_2,uint param_3)

{
  *(uint *)(param_1 + 0x58) =
       *(uint *)(param_1 + 0x58) & 0xffffff9f | (param_2 & 1) << 5 | (param_3 & 1) << 6;
  return;
}



// ---- FUN_80034e34 @ 80034e34

uint FUN_80034e34(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  undefined4 uVar9;
  uint *puVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  uint uVar14;
  uint uVar15;
  undefined4 *puVar16;
  int iVar17;
  uint local_448 [270];
  
  if ((param_2 == (undefined4 *)0x0) && (param_3 == 0)) {
    return *(uint *)(param_1 + 0x1c);
  }
  uVar15 = *(uint *)(param_1 + 0x58);
  *(uint *)(param_1 + 0x58) = uVar15 | 0x100;
  if ((uVar15 & 0x40) == 0) {
    if (param_2 == (undefined4 *)0x0) {
LAB_80034ef4:
      *(uint *)(param_1 + 0x58) = uVar15 & 0xffffff7f | 0x100;
      *(int *)(param_1 + 0x1c) = param_3;
    }
    else {
      *(uint *)(param_1 + 0x58) = uVar15 | 0x180;
      puVar1 = (undefined4 *)FUN_8002ad3c(*(undefined4 *)(param_1 + 0x1c),0x2c);
      *(undefined4 **)(param_1 + 0x1c) = puVar1;
      puVar13 = param_2;
      do {
        puVar16 = puVar1;
        puVar12 = puVar13;
        uVar4 = puVar12[1];
        uVar9 = puVar12[2];
        uVar11 = puVar12[3];
        *puVar16 = *puVar12;
        puVar16[1] = uVar4;
        puVar16[2] = uVar9;
        puVar16[3] = uVar11;
        puVar13 = puVar12 + 4;
        puVar1 = puVar16 + 4;
      } while (puVar13 != param_2 + 8);
      uVar4 = puVar12[5];
      uVar9 = puVar12[6];
      puVar16[4] = *puVar13;
      puVar16[5] = uVar4;
      puVar16[6] = uVar9;
    }
  }
  else {
    if (param_2 == (undefined4 *)0x0) goto LAB_80034ef4;
    *(uint *)(param_1 + 0x58) = uVar15 | 0x180;
    iVar2 = FUN_8002ad3c(*(undefined4 *)(param_1 + 0x1c),param_2[2]);
    *(int *)(param_1 + 0x1c) = iVar2;
    iVar17 = param_2[1];
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(iVar2 + 4) = 0;
    *(undefined4 *)(iVar2 + 8) = param_2[2];
    *(undefined4 *)(iVar2 + 0x1c) = param_2[7];
    *(undefined4 *)(iVar2 + 0x20) = param_2[8];
    puVar10 = (uint *)(iVar2 + 0x2c);
    *(undefined4 *)(iVar2 + 0x24) = param_2[9];
    uVar15 = 0;
    *(undefined4 *)(iVar2 + 0x28) = param_2[10];
    if (*(int *)(iVar2 + 0x1c) != 0) {
      puVar7 = local_448;
      do {
        *puVar7 = (uint)puVar10;
        uVar8 = 0;
        puVar5 = (uint *)(iVar17 * 4 + *(int *)(uVar15 * 4 + iVar17 * 4 + param_2[3]));
        uVar14 = *puVar5;
        *puVar10 = uVar14;
        puVar10 = puVar10 + 1;
        if (uVar14 != 0) {
          do {
            puVar5 = puVar5 + 1;
            uVar8 = uVar8 + 1;
            *puVar10 = *puVar5;
            puVar10 = puVar10 + 1;
          } while (uVar8 < uVar14);
        }
        uVar15 = uVar15 + 1;
        puVar7 = puVar7 + 1;
      } while (uVar15 < *(uint *)(iVar2 + 0x1c));
    }
    uVar15 = 0;
    *(uint **)(iVar2 + 0xc) = puVar10;
    if (*(int *)(iVar2 + 0x1c) != 0) {
      puVar7 = local_448;
      do {
        uVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        uVar15 = uVar15 + 1;
        *puVar10 = uVar8;
        puVar10 = puVar10 + 1;
      } while (uVar15 < *(uint *)(iVar2 + 0x1c));
    }
    uVar15 = 0;
    iVar3 = 0;
    if (*(int *)(iVar2 + 0x20) != 0) {
      puVar7 = local_448;
      do {
        *puVar7 = (uint)puVar10;
        uVar8 = 0;
        puVar5 = (uint *)(iVar17 * 4 + *(int *)(uVar15 * 4 + iVar17 * 4 + param_2[4]));
        uVar14 = *puVar5 >> 0x18;
        *puVar10 = *puVar5;
        puVar10 = puVar10 + 1;
        if (uVar14 != 0) {
          do {
            puVar6 = puVar5 + 1;
            puVar5 = puVar5 + 2;
            uVar8 = uVar8 + 1;
            *puVar10 = *puVar6;
            puVar10[1] = *puVar5;
            puVar10 = puVar10 + 2;
          } while (uVar8 < uVar14);
        }
        uVar15 = uVar15 + 1;
        puVar7 = puVar7 + 1;
      } while (uVar15 < *(uint *)(iVar2 + 0x20));
      iVar3 = *(int *)(iVar2 + 0x20);
    }
    uVar15 = 0;
    *(uint **)(iVar2 + 0x10) = puVar10;
    if (iVar3 != 0) {
      puVar7 = local_448;
      do {
        uVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        uVar15 = uVar15 + 1;
        *puVar10 = uVar8;
        puVar10 = puVar10 + 1;
      } while (uVar15 < *(uint *)(iVar2 + 0x20));
    }
    uVar15 = 0;
    *(uint **)(iVar2 + 0x14) = puVar10;
    if (*(int *)(iVar2 + 0x24) != 0) {
      do {
        iVar3 = uVar15 * 4;
        uVar15 = uVar15 + 1;
        *puVar10 = iVar17 * 4 + *(int *)(iVar3 + iVar17 * 4 + param_2[5]);
        puVar10 = puVar10 + 1;
      } while (uVar15 < *(uint *)(iVar2 + 0x24));
    }
  }
  uVar15 = *(uint *)(param_1 + 0x58);
  uVar8 = uVar15 >> 10 & 3;
  if (uVar8 != 1) {
    if (uVar8 < 2 != 0) {
      if (uVar8 != 0) {
        return (uint)(uVar8 < 2);
      }
      uVar15 = uVar15 & 0xfffff3ff;
      goto LAB_80035184;
    }
    if ((uVar8 != 2) && (uVar8 != 3)) {
      return 3;
    }
  }
  uVar15 = uVar15 | 0xc00;
LAB_80035184:
  *(uint *)(param_1 + 0x58) = uVar15;
  return uVar15;
}



// ---- FUN_800351a0 @ 800351a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800351a0(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  
  iVar1 = _DAT_800abf64;
  puVar5 = (undefined1 *)(_DAT_800abf64 + 0x18ec);
  if ((*(uint *)(param_1 + 0x58) & 0x20) == 0) {
    if (param_4 < 1) {
      if ((*(uint *)(param_1 + 0x58) & 0x100) == 0) {
        return;
      }
      param_4 = *(int *)(*(int *)(param_1 + 0x1c) + 0x24);
    }
    if (param_3 != 0) {
      uVar2 = FUN_8002ad3c(*(undefined4 *)(param_1 + 0x44),param_4);
      *(undefined4 *)(param_1 + 0x44) = uVar2;
      FUN_80058604(uVar2,param_3,param_4);
    }
    if (param_2 != 0) {
      uVar2 = FUN_8002ad3c(*(undefined4 *)(param_1 + 0x40),param_4);
      *(undefined4 *)(param_1 + 0x40) = uVar2;
      FUN_80058604(uVar2,param_2,param_4);
      iVar4 = 0;
      if (0 < param_4) {
        do {
          puVar3 = puVar5;
          do {
            if (*(char *)(*(int *)(param_1 + 0x40) + iVar4) == puVar3[0x50]) {
              *puVar3 = 1;
            }
            puVar3 = puVar3 + 1;
          } while ((int)puVar3 < iVar1 + 0x18fc);
          iVar4 = iVar4 + 1;
        } while (iVar4 < param_4);
      }
    }
  }
  return;
}



// ---- FUN_800352cc @ 800352cc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800352cc(int param_1,uint param_2)

{
  int iVar1;
  undefined1 *puVar2;
  uint uVar3;
  undefined1 *puVar4;
  
  iVar1 = _DAT_800abf64;
  puVar4 = (undefined1 *)(_DAT_800abf64 + 0x18ec);
  if (param_1 != 0) {
    if ((param_2 & 1) != 0) {
      if (((*(uint *)(param_1 + 0x58) & 0x1a0) == 0x180) &&
         (uVar3 = 0, *(int *)(*(int *)(param_1 + 0x1c) + 0x24) != 0)) {
        do {
          puVar2 = puVar4;
          do {
            if (*(char *)(*(int *)(param_1 + 0x40) + uVar3) == puVar2[0x50]) {
              *puVar2 = 0;
            }
            puVar2 = puVar2 + 1;
          } while ((int)puVar2 < iVar1 + 0x18fc);
          uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint *)(*(int *)(param_1 + 0x1c) + 0x24));
      }
      FUN_8002af34(*(undefined4 *)(param_1 + 0x40));
      FUN_8002af34(*(undefined4 *)(param_1 + 0x44));
    }
    if (((param_2 & 2) != 0) && ((*(uint *)(param_1 + 0x58) & 0x80) != 0)) {
      FUN_8002af34(*(undefined4 *)(param_1 + 0x1c));
    }
  }
  return;
}



// ---- FUN_800353e0 @ 800353e0

uint FUN_800353e0(int param_1,uint param_2)

{
  if (param_2 != 0xffffffff) {
    *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xffffffe3 | (param_2 & 7) << 2;
  }
  return *(uint *)(param_1 + 0x58) >> 2 & 7;
}



// ---- FUN_8003541c @ 8003541c

void FUN_8003541c(int param_1,uint param_2)

{
  if (param_2 < 0x100) {
    *(char *)(param_1 + 0x48) = (char)param_2;
  }
  return;
}



// ---- FUN_80035434 @ 80035434

void FUN_80035434(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xfffbffff | (param_2 & 1) << 0x12;
  return;
}



// ---- FUN_80035458 @ 80035458

undefined4 FUN_80035458(int param_1,uint param_2,ushort param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  int iVar8;
  
  uVar6 = (param_4 & 1) << 0xc;
  uVar2 = *(uint *)(param_1 + 0x58);
  iVar8 = *(int *)(param_1 + 0x1c);
  *(char *)(param_1 + 0x56) = (char)param_2;
  *(char *)(param_1 + 0x57) = (char)param_3;
  uVar3 = uVar2 & 0xffffefff | uVar6;
  uVar4 = (uVar2 & 0xc00) >> 10;
  *(uint *)(param_1 + 0x58) = uVar3;
  if (uVar4 == 1) {
    uVar3 = uVar2 & 0xffffe3ff | uVar6 | 0x400;
  }
  else if (uVar4 < 2) {
    if (uVar4 != 0) goto LAB_800354fc;
    uVar3 = uVar2 & 0xffffe3ff | uVar6 | 0x400;
  }
  else if (uVar4 == 2) {
    uVar3 = uVar2 & 0xffffe3ff | uVar6 | 0x400;
  }
  else {
    uVar3 = uVar3 | 0xc00;
    if (uVar4 != 3) goto LAB_800354fc;
  }
  *(uint *)(param_1 + 0x58) = uVar3;
LAB_800354fc:
  if ((*(uint *)(param_1 + 0x58) & 0x100) != 0) {
    if ((int)param_2 < 0) {
      param_2 = (uint)*(ushort *)(param_1 + 0x20);
    }
    if (param_2 < *(uint *)(iVar8 + 0x1c)) {
      iVar5 = *(int *)(iVar8 + 4) * 4;
      puVar7 = (ushort *)(iVar5 + *(int *)(param_2 * 4 + iVar5 + *(int *)(iVar8 + 0xc)));
      iVar1 = *(int *)(iVar8 + 0x10);
      if (param_3 < *puVar7) {
        *(ushort *)(param_1 + 0x22) = param_3;
        *(ushort *)(param_1 + 0x20) = (ushort)param_2;
        *(ushort *)(param_1 + 0x24) = puVar7[(uint)*(ushort *)(param_1 + 0x22) * 2 + 3];
        *(ushort *)(param_1 + 0x26) = puVar7[(uint)*(ushort *)(param_1 + 0x22) * 2 + 2];
        *(int *)(param_1 + 0x2c) =
             *(int *)(iVar8 + 4) * 4 +
             *(int *)((uint)*(ushort *)(param_1 + 0x24) * 4 + iVar5 + iVar1);
        *(undefined2 *)(param_1 + 0x2a) = *(undefined2 *)(param_1 + 0x26);
        iVar8 = ((*(uint *)(param_1 + 0x58) >> 0xe & 3) + 1) * *(int *)(param_1 + 0x28);
        *(int *)(param_1 + 0x28) = iVar8;
        iVar1 = (*(ushort *)(param_1 + 0x5a) & 3) + 1;
        if (iVar1 == 0) {
          trap(0x1c00);
        }
        if ((iVar1 == -1) && (iVar8 == -0x80000000)) {
          trap(0x5d);
        }
        *(int *)(param_1 + 0x28) = iVar8 / iVar1;
        *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xfffff3ff | 0x800;
        return 1;
      }
    }
  }
  return 0;
}



// ---- FUN_80035654 @ 80035654

uint FUN_80035654(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_2 != (undefined4 *)0x0) {
    uVar1 = *(undefined4 *)(param_1 + 0x24);
    uVar2 = *(undefined4 *)(param_1 + 0x28);
    uVar3 = *(undefined4 *)(param_1 + 0x2c);
    *param_2 = *(undefined4 *)(param_1 + 0x20);
    param_2[1] = uVar1;
    param_2[2] = uVar2;
    param_2[3] = uVar3;
  }
  return *(uint *)(param_1 + 0x58) >> 0xc & 1;
}



// ---- FUN_80035694 @ 80035694

uint FUN_80035694(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  if (((int)param_2 < 0) && ((int)param_3 < 0)) {
    uVar1 = (*(uint *)(param_1 + 0x58) >> 0x18 & 0xf) << 0x10 |
            *(uint *)(param_1 + 0x58) >> 0x13 & 0x1f;
  }
  else {
    if (param_2 < 0x20) {
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xff07ffff | (param_2 & 0x1f) << 0x13;
    }
    uVar1 = 0xf0ff0000;
    if (param_3 < 0x10) {
      uVar1 = (param_3 & 0xf) << 0x18;
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xf0ffffff | uVar1;
    }
  }
  return uVar1;
}



// ---- FUN_8003571c @ 8003571c

void FUN_8003571c(int param_1,undefined2 param_2,undefined2 param_3)

{
  *(undefined2 *)(param_1 + 0x4e) = param_2;
  *(undefined2 *)(param_1 + 0x52) = param_3;
  return;
}



// ---- FUN_80035740 @ 80035740

void FUN_80035740(int param_1,short param_2,short param_3)

{
  *(short *)(param_1 + 0x4e) = *(short *)(param_1 + 0x4e) + param_2;
  *(short *)(param_1 + 0x52) = *(short *)(param_1 + 0x52) + param_3;
  return;
}



// ---- FUN_8003579c @ 8003579c

void FUN_8003579c(int param_1,uint param_2,uint param_3)

{
  if (param_2 < 2) {
    *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xefffffff | (param_2 & 1) << 0x1c;
  }
  if (param_3 < 4) {
    *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0x9fffffff | (param_3 & 3) << 0x1d;
  }
  return;
}



// ---- FUN_800358f0 @ 800358f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800358f0(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  if (param_1 == 0) {
    if (param_2 < 2) {
      *(char *)(_DAT_800abf64 + 0x194f) = (char)param_2;
    }
    if (param_3 < 2) {
      *(char *)(iVar1 + 0x1950) = (char)param_3;
    }
  }
  else {
    if (param_2 < 2) {
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xfffffdff | (param_2 & 1) << 9;
    }
    if (param_3 < 2) {
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xffffefff | (param_3 & 1) << 0xc;
    }
    if (param_4 < 2) {
      *(uint *)(param_1 + 0x58) = *(uint *)(param_1 + 0x58) & 0xffffdfff | (param_4 & 1) << 0xd;
    }
  }
  return;
}



// ---- FUN_80035998 @ 80035998

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80035998(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  if (param_1 == 0) {
    if (param_2 < 0x100) {
      *(char *)(_DAT_800abf64 + 0x194c) = (char)param_2;
    }
    if (param_3 < 0x100) {
      *(char *)(iVar1 + 0x194d) = (char)param_3;
    }
    if (param_4 < 0x100) {
      *(char *)(iVar1 + 0x194e) = (char)param_4;
    }
  }
  else {
    if (param_2 < 0x100) {
      *(char *)(param_1 + 0x49) = (char)param_2;
    }
    if (param_3 < 0x100) {
      *(char *)(param_1 + 0x4a) = (char)param_3;
    }
    if (param_4 < 0x100) {
      *(char *)(param_1 + 0x4b) = (char)param_4;
    }
  }
  return;
}



// ---- FUN_80035ab8 @ 80035ab8

void FUN_80035ab8(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xc0000000;
  return;
}



// ---- FUN_80035ae8 @ 80035ae8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80035ae8(int param_1)

{
  uint uVar1;
  
  if (*(code **)(param_1 + 0x10) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 0x10))(_DAT_800abf64,param_1,*(undefined4 *)(param_1 + 0x14));
    *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xc1ffffff | (uVar1 & 0x1f) << 0x19;
  }
  return;
}



// ---- FUN_80035b4c @ 80035b4c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80035b4c(int param_1)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  short *psVar7;
  uint uVar8;
  int iVar9;
  
  iVar5 = _DAT_800abf64;
  uVar8 = *(uint *)(param_1 + 0x58);
  iVar9 = *(int *)(param_1 + 0x1c);
  if ((uVar8 & 0x100) == 0) {
    return;
  }
  uVar4 = uVar8 >> 10 & 3;
  if (uVar4 == 1) {
    uVar4 = FUN_80035458(param_1,*(undefined1 *)(param_1 + 0x56),*(undefined1 *)(param_1 + 0x57),1);
  }
  else if (1 < uVar4) {
    if ((uVar4 == 2) || (uVar4 != 3)) goto LAB_80035c10;
    uVar4 = FUN_80035458(param_1,*(undefined1 *)(param_1 + 0x56),*(undefined1 *)(param_1 + 0x57),
                         uVar8 >> 0xc & 1);
  }
  if (uVar4 == 0) {
    return;
  }
LAB_80035c10:
  uVar8 = *(uint *)(param_1 + 0x58) & 0x1000;
  if ((*(uint *)(param_1 + 0x58) >> 2 & 4) != 0) {
    uVar8 = (uint)*(byte *)(iVar5 + 0x1950);
  }
  if ((uVar8 != 0) &&
     (uVar2 = *(short *)(param_1 + 0x2a) - 1, *(ushort *)(param_1 + 0x2a) = uVar2,
     (int)((uint)uVar2 << 0x10) < 1)) {
    iVar6 = *(int *)(iVar9 + 4) * 4;
    sVar3 = *(short *)(param_1 + 0x22) + 1;
    psVar7 = (short *)(iVar6 + *(int *)((uint)*(ushort *)(param_1 + 0x20) * 4 +
                                       iVar6 + *(int *)(iVar9 + 0xc)));
    iVar5 = *(int *)(iVar9 + 0x10);
    sVar1 = *psVar7;
    *(short *)(param_1 + 0x22) = sVar3;
    if (sVar3 == sVar1) {
      sVar3 = 0;
      if ((*(uint *)(param_1 + 0x58) & 0x2000) == 0) {
        sVar3 = sVar1 + -1;
      }
      *(short *)(param_1 + 0x22) = sVar3;
      *(uint *)(param_1 + 0x58) =
           *(uint *)(param_1 + 0x58) & 0xffffefff | *(uint *)(param_1 + 0x58) >> 1 & 0x1000;
    }
    *(short *)(param_1 + 0x24) = psVar7[(uint)*(ushort *)(param_1 + 0x22) * 2 + 3];
    *(short *)(param_1 + 0x26) = psVar7[(uint)*(ushort *)(param_1 + 0x22) * 2 + 2];
    *(int *)(param_1 + 0x2c) =
         *(int *)(iVar9 + 4) * 4 + *(int *)((uint)*(ushort *)(param_1 + 0x24) * 4 + iVar6 + iVar5);
    *(short *)(param_1 + 0x2a) = *(short *)(param_1 + 0x2a) + *(short *)(param_1 + 0x26);
    iVar5 = ((*(uint *)(param_1 + 0x58) >> 0xe & 3) + 1) * *(int *)(param_1 + 0x28);
    *(int *)(param_1 + 0x28) = iVar5;
    iVar9 = (*(ushort *)(param_1 + 0x5a) & 3) + 1;
    if (iVar9 == 0) {
      trap(0x1c00);
    }
    if ((iVar9 == -1) && (iVar5 == -0x80000000)) {
      trap(0x5d);
    }
    *(int *)(param_1 + 0x28) = iVar5 / iVar9;
  }
  return;
}



// ---- FUN_80035dbc @ 80035dbc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80035dbc(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  short sVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  char *pcVar8;
  char cVar9;
  char *pcVar10;
  short *psVar11;
  uint *puVar12;
  uint *puVar13;
  int iVar14;
  uint uVar15;
  char *pcVar16;
  short local_a0;
  short local_9e;
  undefined4 local_98;
  int local_90;
  int local_88;
  byte local_80;
  short local_78;
  short local_70;
  byte local_68;
  byte local_60;
  byte local_58;
  undefined1 local_50;
  undefined1 local_48;
  undefined1 local_40;
  
  iVar1 = _DAT_800abf64;
  local_90 = *(int *)(param_1 + 0x1c);
  local_98 = DAT_800281c4;
  pcVar16 = (char *)(_DAT_800abf64 + 0x18ec);
  if ((*(uint *)(param_1 + 0x58) & 0x100) != 0) {
    uVar5 = *(uint *)(param_1 + 0x58) >> 10 & 3;
    if (uVar5 != 1) {
      if (uVar5 < 2) {
        if (uVar5 == 0) {
          return;
        }
      }
      else if ((uVar5 != 2) && (uVar5 == 3)) {
        return;
      }
      uVar5 = *(uint *)(param_1 + 0x58) & 0x200;
      if ((*(uint *)(param_1 + 0x58) >> 2 & 1) != 0) {
        uVar5 = (uint)*(byte *)(_DAT_800abf64 + 0x194f);
      }
      if (uVar5 != 0) {
        if ((*(uint *)(param_1 + 0x58) >> 2 & 2) == 0) {
          local_50 = *(undefined1 *)(param_1 + 0x49);
        }
        else {
          local_50 = *(undefined1 *)(_DAT_800abf64 + 0x194c);
        }
        if ((*(uint *)(param_1 + 0x58) >> 2 & 2) == 0) {
          local_48 = *(undefined1 *)(param_1 + 0x4a);
        }
        else {
          local_48 = *(undefined1 *)(_DAT_800abf64 + 0x194d);
        }
        if ((*(uint *)(param_1 + 0x58) >> 2 & 2) == 0) {
          local_40 = *(undefined1 *)(param_1 + 0x4b);
        }
        else {
          local_40 = *(undefined1 *)(_DAT_800abf64 + 0x194e);
        }
        puVar7 = *(uint **)(param_1 + 0x2c);
        local_88 = *(int *)(local_90 + 4) * 4 + *(int *)(local_90 + 0x14);
        local_80 = *(byte *)((int)puVar7 + 3);
        uVar5 = (uint)local_80;
        iVar14 = 0;
        if (*(byte *)(param_1 + _DAT_800b05cc + 0x54) != uVar5) {
          *(byte *)(param_1 + _DAT_800b05cc + 0x54) = local_80;
          uVar4 = FUN_8002ad3c(*(undefined4 *)(_DAT_800b05cc * 4 + param_1 + 0x30),uVar5 * 0x14);
          iVar6 = _DAT_800b05cc * 4 + param_1;
          *(undefined4 *)(iVar6 + 0x30) = uVar4;
          uVar4 = FUN_8002ad3c(*(undefined4 *)(iVar6 + 0x38),uVar5 * 0xc);
          *(undefined4 *)(_DAT_800b05cc * 4 + param_1 + 0x38) = uVar4;
        }
        iVar6 = _DAT_800b05cc * 4 + param_1;
        puVar13 = *(uint **)(iVar6 + 0x30);
        puVar12 = *(uint **)(iVar6 + 0x38);
        if (uVar5 != 0) {
          psVar11 = (short *)((int)puVar13 + 10);
          do {
            local_78 = *(short *)((int)puVar7 + 6);
            local_70 = (short)puVar7[1];
            puVar7 = puVar7 + 2;
            uVar5 = *puVar7;
            local_60 = (byte)*puVar7;
            uVar15 = uVar5 >> 0x18;
            local_58 = (byte)(uVar5 >> 0x10);
            local_68 = (byte)(uVar5 >> 8);
            if ((*(uint *)(param_1 + 0x58) & 0x20) == 0) {
              cVar9 = *(char *)(uVar15 + *(int *)(param_1 + 0x40));
            }
            else {
              iVar6 = 0;
              pcVar8 = pcVar16;
              do {
                if (*(int *)(pcVar8 + 0x10) ==
                    *(int *)(local_90 + 4) * 4 + *(int *)(uVar15 * 4 + local_88)) {
                  cVar9 = pcVar16[iVar6 + 0x50];
                  goto LAB_80036134;
                }
                iVar6 = iVar6 + 1;
                pcVar8 = pcVar8 + 4;
              } while (iVar6 < 0x10);
              iVar6 = 0;
              pcVar8 = pcVar16;
              pcVar10 = pcVar16;
              do {
                iVar6 = iVar6 + 1;
                if ((*pcVar10 == '\0') && (*(int *)(pcVar8 + 0x10) == 0)) {
                  *(int *)(pcVar8 + 0x10) =
                       *(int *)(local_90 + 4) * 4 + *(int *)(uVar15 * 4 + local_88);
                  cVar9 = pcVar10[0x50];
                  FUN_8002d0c4(local_90,pcVar10[0x50]);
                  goto LAB_80036134;
                }
                pcVar8 = pcVar8 + 4;
                pcVar10 = pcVar10 + 1;
              } while (iVar6 < 0x10);
              cVar9 = *(char *)(iVar1 + 0x193c);
            }
LAB_80036134:
            *(undefined1 *)((int)psVar11 + -7) = 4;
            *(undefined1 *)((int)psVar11 + -3) = 100;
            if ((*(uint *)(param_1 + 0x58) & 0x10000000) != 0) {
              *(undefined1 *)((int)psVar11 + -3) = 0x66;
            }
            *(undefined1 *)(psVar11 + -3) = local_50;
            *(undefined1 *)((int)psVar11 + -5) = local_48;
            *(undefined1 *)(psVar11 + -2) = local_40;
            FUN_80031e14(cVar9,&local_a0);
            uVar2 = FUN_8005c510(*(uint *)(param_1 + 0x58) >> 0x12 & 1,
                                 *(uint *)(param_1 + 0x58) >> 0x1d & 3,local_a0,local_9e);
            FUN_8005a1d8(puVar12,1,0,uVar2,0);
            FUN_80031eb4(*(uint *)(param_1 + 0x58) >> 0x13 & 0x1f,
                         *(uint *)(param_1 + 0x58) >> 0x18 & 0xf,&local_a0);
            sVar3 = FUN_8005c5a4(local_a0,local_9e);
            psVar11[2] = sVar3;
            FUN_80031e74(cVar9,&local_a0,*(uint *)(param_1 + 0x58) >> 0x12 & 1);
            puVar13 = puVar13 + 5;
            if (*(int *)(param_1 + 0x44) != 0) {
              FUN_80031e88(*(undefined1 *)(uVar15 + *(int *)(param_1 + 0x44)),&local_98,
                           *(uint *)(param_1 + 0x58) >> 0x12 & 1);
            }
            local_a0 = local_a0 + (local_58 & 0xf) * 8 + (short)local_98;
            local_9e = local_9e + (ushort)(local_58 >> 4) * 8 + local_98._2_2_;
            *(undefined1 *)(psVar11 + 1) = (undefined1)local_a0;
            psVar11[3] = (ushort)local_68;
            psVar11[4] = (ushort)local_60;
            *(undefined1 *)((int)psVar11 + 3) = (undefined1)local_9e;
            puVar12 = puVar12 + 3;
            psVar11[-1] = local_78 + *(short *)(param_1 + 0x4e);
            iVar14 = iVar14 + 1;
            *psVar11 = local_70 + *(short *)(param_1 + 0x52);
            psVar11 = psVar11 + 10;
          } while (iVar14 < (int)(uint)local_80);
        }
        iVar1 = _DAT_800aeea0;
        iVar14 = 0;
        if (local_80 != 0) {
          do {
            puVar13 = puVar13 + -5;
            *puVar13 = *puVar13 & 0xff000000 |
                       *(uint *)((uint)*(byte *)(param_1 + 0x48) * 4 + iVar1) & 0xffffff;
            puVar12 = puVar12 + -3;
            puVar7 = (uint *)((uint)*(byte *)(param_1 + 0x48) * 4 + iVar1);
            *puVar7 = *puVar7 & 0xff000000 | (uint)puVar13 & 0xffffff;
            *puVar12 = *puVar12 & 0xff000000 |
                       *(uint *)((uint)*(byte *)(param_1 + 0x48) * 4 + iVar1) & 0xffffff;
            iVar14 = iVar14 + 1;
            puVar7 = (uint *)((uint)*(byte *)(param_1 + 0x48) * 4 + iVar1);
            *puVar7 = *puVar7 & 0xff000000 | (uint)puVar12 & 0xffffff;
          } while (iVar14 < (int)(uint)local_80);
        }
      }
    }
  }
  return;
}



// ---- FUN_800363bc @ 800363bc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800363bc(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  *(undefined4 *)(_DAT_800abf64 + 0x1954) = 0;
  *(undefined4 *)(iVar1 + 0x1958) = 0;
  return;
}



// ---- FUN_800363d4 @ 800363d4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800363d4(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  iVar1 = _DAT_800abf64;
  piVar4 = *(int **)(_DAT_800abf64 + 0x1954);
  piVar5 = (int *)(_DAT_800abf64 + 0x1954);
  if (piVar4 != (int *)0x0) {
    do {
      (*(code *)(&PTR_FUN_80071044)[piVar4[1]])(iVar1,piVar4,0);
      piVar2 = (int *)*piVar5;
      if (piVar2 == piVar4) {
        *piVar5 = *piVar4;
      }
      else {
        piVar3 = (int *)*piVar2;
        while (piVar3 != piVar4) {
          piVar2 = (int *)*piVar2;
          piVar3 = (int *)*piVar2;
        }
        *piVar2 = *piVar4;
      }
      FUN_8002af34(piVar4);
      *(int *)(iVar1 + 0x1958) = *(int *)(iVar1 + 0x1958) + -1;
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)0x0);
  }
  return;
}



// ---- FUN_800364d8 @ 800364d8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_800364d8(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  
  iVar1 = _DAT_800abf64;
  iVar9 = -1;
  puVar10 = (undefined4 *)(_DAT_800abf64 + 0x1954);
  FUN_80058314();
  puVar2 = (undefined4 *)FUN_8002ac50(0x118);
  if (puVar2 != (undefined4 *)0x0) {
    switch(param_1) {
    case 0:
    case 3:
    case 4:
    case 5:
      uVar4 = param_2[1];
      uVar5 = param_2[2];
      puVar2[2] = *param_2;
      puVar2[3] = uVar4;
      puVar2[4] = uVar5;
      *puVar2 = 0;
      break;
    case 1:
    case 10:
      uVar4 = param_2[1];
      uVar5 = param_2[2];
      uVar6 = param_2[3];
      puVar2[2] = *param_2;
      puVar2[3] = uVar4;
      puVar2[4] = uVar5;
      puVar2[5] = uVar6;
      *puVar2 = 0;
      break;
    case 2:
      uVar4 = param_2[1];
      uVar5 = param_2[2];
      uVar6 = param_2[3];
      puVar2[2] = *param_2;
      puVar2[3] = uVar4;
      puVar2[4] = uVar5;
      puVar2[5] = uVar6;
      uVar4 = param_2[5];
      puVar2[6] = param_2[4];
      puVar2[7] = uVar4;
      *puVar2 = 0;
      break;
    case 6:
      uVar4 = param_2[1];
      uVar5 = param_2[2];
      uVar6 = param_2[3];
      puVar2[2] = *param_2;
      puVar2[3] = uVar4;
      puVar2[4] = uVar5;
      puVar2[5] = uVar6;
      uVar4 = param_2[5];
      uVar5 = param_2[6];
      puVar2[6] = param_2[4];
      puVar2[7] = uVar4;
      puVar2[8] = uVar5;
      *puVar2 = 0;
      break;
    case 7:
      puVar2[2] = *param_2;
      *puVar2 = 0;
      break;
    case 8:
      puVar7 = puVar2 + 2;
      puVar8 = param_2 + 0x44;
      do {
        uVar4 = param_2[1];
        uVar5 = param_2[2];
        uVar6 = param_2[3];
        *puVar7 = *param_2;
        puVar7[1] = uVar4;
        puVar7[2] = uVar5;
        puVar7[3] = uVar6;
        param_2 = param_2 + 4;
        puVar7 = puVar7 + 4;
      } while (param_2 != puVar8);
      *puVar2 = 0;
      break;
    case 9:
      uVar4 = param_2[1];
      puVar2[2] = *param_2;
      puVar2[3] = uVar4;
      *puVar2 = 0;
      break;
    default:
      FUN_8002af34(puVar2);
      goto LAB_800366d8;
    }
    puVar2[1] = param_1;
    piVar3 = (int *)*puVar10;
    if (piVar3 == (int *)0x0) {
      *puVar10 = puVar2;
    }
    else {
      iVar9 = *piVar3;
      while (iVar9 != 0) {
        piVar3 = (int *)*piVar3;
        iVar9 = *piVar3;
      }
      *piVar3 = (int)puVar2;
    }
    iVar9 = *(int *)(iVar1 + 0x1958);
    *(int *)(iVar1 + 0x1958) = iVar9 + 1;
  }
LAB_800366d8:
  FUN_800585a4();
  return iVar9;
}



// ---- FUN_80036704 @ 80036704

void FUN_80036704(void)

{
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  undefined2 local_16;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  
  local_10 = DAT_800281f4;
  local_f = DAT_800281f5;
  local_e = DAT_800281f6;
  FUN_80031eb4(0x1b,0xf,&local_18);
  local_24 = 0x10;
  local_22 = 1;
  local_28 = local_18;
  local_26 = local_16;
  FUN_8002c6f8(0,&DAT_80074a88,&local_28,0,0);
  FUN_80031e14(0x16,&local_18);
  local_1c = 0x80;
  local_1a = 0x80;
  local_20 = local_18;
  local_1e = local_16;
  FUN_8002c6f8(3,0,&local_20,&local_10,1);
  return;
}



// ---- FUN_800367d8 @ 800367d8
// decompile failed: Exception while decompiling 800367d8: process: timeout


// ---- FUN_8003b038 @ 8003b038

void FUN_8003b038(void)

{
  FUN_80058714(0);
  FUN_800619d8(FUN_8003b068);
  return;
}



// ---- FUN_8003b068 @ 8003b068

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003b068(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  int iVar5;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar1 = _DAT_800abf64;
  local_10 = *(undefined4 *)(_DAT_800abf64 + 0x5cc);
  local_c = *(undefined4 *)(_DAT_800abf64 + 0x5d0);
  iVar5 = _DAT_800abf64 + 0x57c;
  if (*(int *)(_DAT_800abf64 + 0x5a4) == 0) {
    local_10._2_2_ = (short)((uint)local_10 >> 0x10);
    local_10 = CONCAT22(local_10._2_2_ + *(short *)(_DAT_800abf64 + 0x5da),
                        (short)local_10 + *(short *)(_DAT_800abf64 + 0x5d8));
  }
  else if ((*(int *)(_DAT_800abf64 + 0x5a4) == 1) && (_DAT_800ab698 == 1)) {
    FUN_80060294();
    _DAT_800ab698 = 0;
  }
  FUN_8005997c(&local_10,*(undefined4 *)(iVar1 + 0x5b4));
  FUN_800598fc(0);
  sVar4 = *(short *)(iVar1 + 0x5cc) + *(short *)(iVar1 + 0x5d0);
  *(short *)(iVar1 + 0x5cc) = sVar4;
  iVar2 = iVar5 + *(int *)(iVar1 + 0x5c8) * 8;
  if ((int)sVar4 < (int)*(short *)(iVar2 + 0x3c) + (int)*(short *)(iVar2 + 0x40)) {
    FUN_80058814(*(undefined4 *)(iVar1 + 0x5b4),
                 ((int)*(short *)(iVar1 + 0x5d0) * (int)*(short *)(iVar1 + 0x5d2)) / 2);
  }
  else {
    *(undefined4 *)(iVar1 + 0x5d4) = 1;
    uVar3 = (uint)(*(int *)(iVar1 + 0x5c8) == 0);
    *(uint *)(iVar1 + 0x5c8) = uVar3;
    *(undefined2 *)(iVar1 + 0x5cc) = *(undefined2 *)(iVar5 + uVar3 * 8 + 0x3c);
    *(undefined2 *)(iVar1 + 0x5ce) = *(undefined2 *)(iVar5 + *(int *)(iVar1 + 0x5c8) * 8 + 0x3e);
  }
  return;
}



// ---- FUN_8003b1f4 @ 8003b1f4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003b1f4(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  *(undefined4 *)(_DAT_800abf64 + 0x594) = 0x80166800;
  *(undefined4 *)(iVar1 + 0x598) = 0;
  *(undefined4 *)(iVar1 + 0x59c) = 0;
  *(undefined4 *)(iVar1 + 0x5a0) = 0;
  *(undefined4 *)(iVar1 + 0x5a4) = 0;
  *(undefined4 *)(iVar1 + 0x5b0) = 0;
  *(undefined4 *)(iVar1 + 0x5c8) = 0;
  *(undefined4 *)(iVar1 + 0x5d4) = 0;
  *(undefined2 *)(iVar1 + 0x5d8) = 0;
  *(undefined2 *)(iVar1 + 0x5da) = 0;
  *(int *)(iVar1 + 0x5ac) = *(int *)(iVar1 + 0x594) + 0x28000;
  *(int *)(iVar1 + 0x5b4) = *(int *)(iVar1 + 0x594) + 0x50000;
  *(undefined4 *)(iVar1 + 0x5a8) = *(undefined4 *)(iVar1 + 0x594);
  FUN_8003b884(0);
  return;
}



// ---- FUN_8003b278 @ 8003b278

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003b278(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_18;
  
  iVar1 = _DAT_800abf64;
  local_18 = 0x800000;
  iVar4 = _DAT_800abf64 + 0x57c;
  FUN_80058798(*(undefined4 *)(*(int *)(_DAT_800abf64 + 0x5b0) * 4 + iVar4 + 0x2c),
               *(int *)(_DAT_800abf64 + 0x5a4) + 2);
  FUN_80058814(*(undefined4 *)(iVar1 + 0x5b4),
               ((int)*(short *)(iVar1 + 0x5d0) * (int)*(short *)(iVar1 + 0x5d2)) / 2);
  FUN_8003b640();
  iVar2 = *(int *)(iVar1 + 0x5d4);
  while (iVar2 == 0) {
    local_18 = local_18 + -1;
    if (local_18 == 0) {
      *(undefined4 *)(iVar1 + 0x5d4) = 1;
      uVar3 = (uint)(*(int *)(iVar1 + 0x5c8) == 0);
      *(uint *)(iVar1 + 0x5c8) = uVar3;
      *(undefined2 *)(iVar1 + 0x5cc) = *(undefined2 *)(iVar4 + uVar3 * 8 + 0x3c);
      *(undefined2 *)(iVar1 + 0x5ce) = *(undefined2 *)(iVar4 + *(int *)(iVar1 + 0x5c8) * 8 + 0x3e);
    }
    iVar2 = *(int *)(iVar1 + 0x5d4);
  }
  *(undefined4 *)(iVar1 + 0x5d4) = 0;
  FUN_80062390(0);
  return;
}



// ---- FUN_8003b388 @ 8003b388

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003b388(void)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_88 [4];
  short local_84;
  undefined1 local_77;
  undefined1 auStack_70 [96];
  
  iVar1 = _DAT_800abf64;
  iVar2 = _DAT_800abf64 + 0x57c + (uint)(*(int *)(_DAT_800abf64 + 0x5c8) == 0) * 8;
  FUN_8005cdb0(auStack_88,(int)*(short *)(iVar2 + 0x3c),(int)*(short *)(iVar2 + 0x3e),
               (int)*(short *)(iVar2 + 0x40),(int)*(short *)(iVar2 + 0x42));
  FUN_8005cd24(auStack_70,(int)*(short *)(iVar2 + 0x3c),(int)*(short *)(iVar2 + 0x3e),
               (int)*(short *)(iVar2 + 0x40),(int)*(short *)(iVar2 + 0x42));
  if (*(int *)(iVar1 + 0x5a4) == 1) {
    local_84 = (short)(((int)local_84 << 1) / 3);
    local_77 = 1;
  }
  FUN_80059ce8(auStack_88);
  FUN_80059bc8(auStack_70);
  FUN_800598bc(1);
  return;
}



// ---- FUN_8003b460 @ 8003b460

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003b460(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_38 [2];
  undefined4 local_30 [6];
  
  iVar2 = _DAT_800abf64;
  FUN_800598bc(0);
  if (param_2 == 0) {
    do {
      iVar1 = FUN_80060f80(local_30,param_1);
    } while (iVar1 == 0);
    local_38[0] = local_30[0];
  }
  else {
    FUN_8005eb34(param_2,local_38);
  }
  FUN_8006bbac(0,0,1);
  FUN_8006a388(0,0x7f,0x7f);
  FUN_8005fe9c(*(int *)(iVar2 + 0x594) + 0x52d00,0x20);
  FUN_8005ffe4(*(undefined4 *)(iVar2 + 0x5a4),1,param_3,0,0);
  do {
    iVar2 = FUN_8005e964(9,0,0);
  } while (iVar2 == 0);
  do {
    iVar2 = FUN_8005e918(0x15,local_38,0);
  } while (iVar2 == 0);
  do {
    iVar2 = FUN_8005eac4(0x1c0);
  } while (iVar2 == 0);
  FUN_8003b640();
  return;
}



// ---- FUN_8003b590 @ 8003b590

void FUN_8003b590(void)

{
  int iVar1;
  undefined1 local_10 [8];
  
  local_10[0] = 0x80;
  FUN_800598bc(0);
  FUN_8006a388(0,0,0);
  FUN_80060274(1,0,0xffffffff);
  FUN_8005fef4();
  FUN_8005ff44();
  FUN_800619fc(0);
  FUN_8005e7c8(0);
  do {
    iVar1 = FUN_8005e964(0xe,local_10,0);
  } while (iVar1 == 0);
  do {
    iVar1 = FUN_8005e964(9,0,0);
  } while (iVar1 == 0);
  do {
    iVar1 = FUN_8005e964(10,0,0);
  } while (iVar1 == 0);
  return;
}



// ---- FUN_8003b640 @ 8003b640

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003b640(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = _DAT_800abf64;
  iVar4 = 0;
  do {
    iVar2 = FUN_8003b6e0(iVar1 + 0x5a8);
    iVar4 = iVar4 + 1;
    if (iVar2 != 0) {
      uVar3 = (uint)(*(int *)(iVar1 + 0x5b0) == 0);
      *(uint *)(iVar1 + 0x5b0) = uVar3;
      FUN_80058758(iVar2,*(undefined4 *)(uVar3 * 4 + iVar1 + 0x5a8));
      FUN_800600b8(iVar2);
      return;
    }
  } while (iVar4 != 0x800001);
  return;
}



// ---- FUN_8003b6e0 @ 8003b6e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8003b6e0(int param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_28;
  int local_24;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  
  iVar4 = _DAT_800abf64;
  iVar5 = 0;
  do {
    iVar3 = FUN_800601c0(&local_28,&local_24);
    iVar5 = iVar5 + 1;
    if (iVar3 == 0) {
      *(undefined4 *)(iVar4 + 0x59c) = *(undefined4 *)(local_24 + 8);
      if ((_DAT_80071070 != *(ushort *)(local_24 + 0x10)) ||
         (_DAT_80071074 != *(ushort *)(local_24 + 0x12))) {
        local_1c = 0x140;
        local_20 = 0;
        local_1e = 0;
        local_1a = 0x1e0;
        FUN_8005992c(&local_20,0,0,0);
        _DAT_80071070 = (uint)*(ushort *)(local_24 + 0x10);
        _DAT_80071074 = (uint)*(ushort *)(local_24 + 0x12);
      }
      iVar4 = *(int *)(iVar4 + 0x5a4);
      uVar1 = DAT_80071074;
      if (iVar4 == 0) {
        uVar2 = DAT_80071070;
        *(undefined2 *)(param_1 + 0x1c) = DAT_80071070;
        *(undefined2 *)(param_1 + 0x14) = uVar2;
        *(undefined2 *)(param_1 + 0x1e) = uVar1;
        *(undefined2 *)(param_1 + 0x16) = uVar1;
        *(undefined2 *)(param_1 + 0x2a) = uVar1;
      }
      else if (iVar4 == 1) {
        uVar2 = (undefined2)(_DAT_80071070 * 3 - ((int)(_DAT_80071070 * 3) >> 0x1f) >> 1);
        *(undefined2 *)(param_1 + 0x1c) = uVar2;
        *(undefined2 *)(param_1 + 0x14) = uVar2;
        *(undefined2 *)(param_1 + 0x1e) = uVar1;
        *(undefined2 *)(param_1 + 0x16) = uVar1;
        *(undefined2 *)(param_1 + 0x2a) = uVar1;
      }
      return local_28;
    }
  } while (iVar5 != 0x800001);
  return 0;
}



// ---- FUN_8003b884 @ 8003b884

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_8003b884(uint param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = _DAT_800abf64;
  param_1 = param_1 & 0xff;
  *(uint *)(_DAT_800abf64 + 0x5a4) = param_1;
  if (param_1 == 0) {
    *(undefined2 *)(iVar1 + 0x5bc) = 0x140;
    *(undefined2 *)(iVar1 + 0x5c4) = 0x140;
    uVar2 = 0x10;
  }
  else {
    if (param_1 != 1) goto LAB_8003b900;
    *(undefined2 *)(iVar1 + 0x5bc) = 0x1e0;
    *(undefined2 *)(iVar1 + 0x5c4) = 0x1e0;
    uVar2 = 0x18;
  }
  *(undefined2 *)(iVar1 + 0x5b8) = 0;
  *(undefined2 *)(iVar1 + 0x5ba) = 0;
  *(undefined2 *)(iVar1 + 0x5be) = 0xf0;
  *(undefined2 *)(iVar1 + 0x5c0) = 0;
  *(undefined2 *)(iVar1 + 0x5c2) = 0xf0;
  *(undefined2 *)(iVar1 + 0x5c6) = 0xf0;
  *(undefined2 *)(iVar1 + 0x5cc) = 0;
  *(undefined2 *)(iVar1 + 0x5ce) = 0;
  *(undefined2 *)(iVar1 + 0x5d0) = uVar2;
  *(undefined2 *)(iVar1 + 0x5d2) = 0xf0;
LAB_8003b900:
  return *(undefined1 *)(iVar1 + 0x5a4);
}



// ---- FUN_8003b924 @ 8003b924

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8003b924(undefined4 param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = 0;
  uVar5 = 1;
  DAT_80071078 = 0x80;
  DAT_80071079 = 0;
  _DAT_800a1d48 = param_1;
  while( true ) {
    while (iVar2 = FUN_8003ba3c(), iVar2 != 0) {
      uVar1 = FUN_8003bab4(8);
      *param_2 = uVar1;
      param_2 = param_2 + 1;
      *(undefined1 *)(uVar5 + 0x800a0d48) = uVar1;
      uVar5 = uVar5 + 1 & 0xfff;
      iVar6 = iVar6 + 1;
    }
    iVar2 = FUN_8003bab4(0xc);
    if (iVar2 == 0) break;
    iVar3 = FUN_8003bab4(4);
    iVar4 = 0;
    if (-1 < iVar3 + 1) {
      do {
        iVar6 = iVar6 + 1;
        uVar1 = *(undefined1 *)((iVar2 + iVar4 & 0xfffU) + 0x800a0d48);
        iVar4 = iVar4 + 1;
        *param_2 = uVar1;
        *(undefined1 *)(uVar5 + 0x800a0d48) = uVar1;
        uVar5 = uVar5 + 1 & 0xfff;
        param_2 = param_2 + 1;
      } while (iVar4 <= iVar3 + 1);
    }
  }
  return iVar6;
}



// ---- FUN_8003ba3c @ 8003ba3c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte FUN_8003ba3c(void)

{
  byte bVar1;
  byte bVar2;
  
  if (DAT_80071078 == 0x80) {
    DAT_80071079 = *_DAT_800a1d48;
    _DAT_800a1d48 = _DAT_800a1d48 + 1;
  }
  bVar1 = DAT_80071078 >> 1;
  bVar2 = DAT_80071079 & DAT_80071078;
  DAT_80071078 = bVar1;
  if (bVar1 == 0) {
    DAT_80071078 = 0x80;
  }
  return bVar2;
}



// ---- FUN_8003bab4 @ 8003bab4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_8003bab4(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 1 << (param_1 - 1U & 0x1f);
  uVar2 = (uint)DAT_80071078;
  uVar4 = 0;
  while (uVar3 != 0) {
    if (uVar2 == 0x80) {
      DAT_80071079 = *_DAT_800a1d48;
      _DAT_800a1d48 = _DAT_800a1d48 + 1;
    }
    uVar1 = DAT_80071079 & uVar2;
    uVar2 = uVar2 >> 1;
    if (uVar1 != 0) {
      uVar4 = uVar4 | uVar3;
    }
    uVar3 = uVar3 >> 1;
    if (uVar2 == 0) {
      uVar2 = 0x80;
    }
  }
  DAT_80071078 = (char)uVar2;
  return uVar4;
}



// ---- FUN_8003bb3c @ 8003bb3c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003bb3c(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  FUN_800585e4(_DAT_800abf64 + 0x195c,0x6118);
  *(undefined1 *)(iVar1 + 0x7a70) = 0;
  *(undefined1 *)(iVar1 + 0x7a71) = 0;
  *(undefined1 *)(iVar1 + 0x7a72) = 0;
  FUN_8003cc50();
  FUN_80055d44();
  FUN_80057418();
  return;
}



// ---- FUN_8003bb90 @ 8003bb90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003bb90(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _DAT_800abf64;
  iVar2 = _DAT_800abf64 + 0x1990;
  *(undefined4 *)(_DAT_800abf64 + 0x195c) = 0;
  *(undefined4 *)(iVar1 + 0x1960) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1964) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1968) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x196c) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1970) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1974) = 0;
  *(undefined4 *)(iVar1 + 0x1978) = 0;
  *(undefined4 *)(iVar1 + 0x197c) = 0;
  *(undefined4 *)(iVar1 + 0x1980) = 0;
  *(undefined4 *)(iVar1 + 0x1984) = 0;
  *(undefined4 *)(iVar1 + 0x1988) = 0;
  *(undefined4 *)(iVar1 + 0x198c) = 0;
  FUN_800585e4(iVar2,0x100);
  iVar2 = _DAT_800abf64;
  *(undefined4 *)(iVar1 + 0x1a90) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1a94) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1a98) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1a9c) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1aa0) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1aa4) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1aa8) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1aac) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1ab0) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1ab4) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1ab8) = 0xffffffff;
  iVar2 = iVar2 + 0x1e50;
  FUN_80032568(iVar2,0);
  FUN_80032288(iVar2,0,1);
  FUN_80032654(iVar2,&LAB_8003bc70);
  return;
}



// ---- FUN_8003bc78 @ 8003bc78

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003bc78(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  if (param_1 == 2) {
    FUN_80032d9c(_DAT_800abf64 + 0x2430,param_2);
    FUN_80032d9c(iVar1 + 0x2470,param_2);
    FUN_80032d9c(iVar1 + 0x24b0,param_2);
    iVar1 = iVar1 + 0x24f0;
  }
  else if (param_1 < 3) {
    if (param_1 != 1) {
      return;
    }
    FUN_80032d9c(_DAT_800abf64 + 0x22f0,param_2);
    FUN_80032d9c(iVar1 + 0x2330,param_2);
    FUN_80032d9c(iVar1 + 0x2370,param_2);
    FUN_80032d9c(iVar1 + 0x23b0,param_2);
    iVar1 = iVar1 + 0x23f0;
  }
  else {
    if (param_1 != 4) {
      return;
    }
    FUN_80032d9c(_DAT_800abf64 + 0x22f0,param_2);
    FUN_80032d9c(iVar1 + 0x2330,param_2);
    FUN_80032d9c(iVar1 + 0x2370,param_2);
    FUN_80032d9c(iVar1 + 0x23b0,param_2);
    iVar1 = iVar1 + 0x23f0;
    param_2 = 0;
  }
  FUN_80032d9c(iVar1,param_2);
  return;
}



// ---- FUN_8003bd88 @ 8003bd88

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003bd88(int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  if (param_1 == 2) {
    FUN_80033094(_DAT_800abf64 + 0x2430,param_2,param_3,param_4,1);
    FUN_80033094(iVar1 + 0x2470,param_2,param_3,param_4,1);
    FUN_80033094(iVar1 + 0x24b0,param_2,param_3,param_4,1);
    iVar1 = iVar1 + 0x24f0;
  }
  else {
    if (param_1 < 3) {
      if (param_1 != 1) {
        return;
      }
    }
    else if (param_1 != 4) {
      return;
    }
    FUN_80033094(_DAT_800abf64 + 0x22f0,param_2,param_3,param_4,1);
    FUN_80033094(iVar1 + 0x2330,param_2,param_3,param_4,1);
    FUN_80033094(iVar1 + 0x2370,param_2,param_3,param_4,1);
    FUN_80033094(iVar1 + 0x23b0,param_2,param_3,param_4,1);
    iVar1 = iVar1 + 0x23f0;
  }
  FUN_80033094(iVar1,param_2,param_3,param_4,1);
  return;
}



// ---- FUN_8003bf00 @ 8003bf00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003bf00(ushort *param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  
  iVar14 = _DAT_800abf64;
  uVar1 = *param_1;
  uVar13 = (uint)uVar1;
  uVar2 = param_1[2];
  uVar3 = param_1[1];
  uVar16 = (uint)uVar3;
  uVar4 = param_1[3];
  sVar5 = (short)(uVar13 + uVar2);
  iVar6 = _DAT_800abf64 + 0x22f0;
  uVar18 = uVar16 + uVar4;
  FUN_80033560(iVar6,0,0,1);
  iVar7 = iVar14 + 0x2330;
  iVar17 = (int)(short)uVar3;
  FUN_80033560(iVar7,0,iVar17,1);
  iVar8 = iVar14 + 0x2370;
  FUN_80033560(iVar8,(int)sVar5,iVar17,1);
  iVar15 = iVar14 + 0x23b0;
  iVar11 = (int)(uVar18 * 0x10000) >> 0x10;
  FUN_80033560(iVar15,0,iVar11,1);
  iVar12 = iVar14 + 0x23f0;
  FUN_80033560(iVar12,(int)(short)uVar1,iVar17,1);
  FUN_80033d40(iVar6,0,0,1);
  uVar9 = uVar16 & 0xff;
  FUN_80033d40(iVar7,0,uVar9,1);
  uVar10 = uVar13 + uVar2 & 0xff;
  FUN_80033d40(iVar8,uVar10,uVar9,1);
  FUN_80033d40(iVar15,0,uVar18 & 0xff,1);
  FUN_80033d40(iVar12,uVar13 & 0xff,uVar9,1);
  FUN_80033a18(iVar6,0x100,uVar16,0x40);
  FUN_80033a18(iVar7,uVar13,uVar4,0x40);
  FUN_80033a18(iVar8,0x100 - sVar5,uVar4,0x40);
  FUN_80033a18(iVar15,0x100,0xf0 - (short)uVar18,0x40);
  FUN_80033a18(iVar12,uVar2,uVar4,0x40);
  FUN_80033560(iVar14 + 0x22b0,(int)(short)uVar1,iVar17,1);
  FUN_80033a18(iVar14 + 0x22b0,uVar2,uVar4,0x40);
  iVar12 = iVar14 + 0x2430;
  iVar6 = (int)((uVar13 + 0xfffe) * 0x10000) >> 0x10;
  FUN_80033560(iVar12,iVar6,(int)((uVar16 + 0xfffe) * 0x10000) >> 0x10,1);
  iVar8 = iVar14 + 0x2470;
  FUN_80033560(iVar8,iVar6,iVar17,1);
  iVar7 = iVar14 + 0x24b0;
  FUN_80033560(iVar7,(int)sVar5,iVar17,1);
  iVar14 = iVar14 + 0x24f0;
  FUN_80033560(iVar14,iVar6,iVar11,1);
  uVar13 = uVar13 + 0xfffe & 0xff;
  FUN_80033d40(iVar12,uVar13,uVar16 + 0xfffe & 0xff,1);
  FUN_80033d40(iVar8,uVar13,uVar9,1);
  FUN_80033d40(iVar7,uVar10,uVar9,1);
  FUN_80033d40(iVar14,uVar13,uVar18 & 0xff,1);
  FUN_80033a18(iVar12,uVar2 + 4,2,0x40);
  FUN_80033a18(iVar8,2,uVar4,0x40);
  FUN_80033a18(iVar7,2,uVar4,0x40);
  FUN_80033a18(iVar14,uVar2 + 4,2,0x40);
  return;
}



// ---- FUN_8003c2a8 @ 8003c2a8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003c2a8(ushort *param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  
  iVar11 = _DAT_800abf64;
  iVar5 = _DAT_800abf64 + 0x22f0;
  uVar1 = *param_1;
  uVar2 = param_1[1];
  uVar3 = param_1[2];
  uVar4 = param_1[3];
  FUN_80033848(iVar5,0,0,1);
  iVar15 = iVar11 + 0x2330;
  iVar9 = (int)(short)uVar2;
  FUN_80033848(iVar15,0,iVar9,1);
  iVar6 = iVar11 + 0x2370;
  iVar7 = (int)(short)uVar3;
  FUN_80033848(iVar6,iVar7,iVar9,1);
  iVar14 = iVar11 + 0x23b0;
  iVar8 = (int)(short)uVar4;
  FUN_80033848(iVar14,0,iVar8,1);
  iVar13 = iVar11 + 0x23f0;
  iVar10 = (int)(short)uVar1;
  FUN_80033848(iVar13,iVar10,iVar9,1);
  FUN_80033fe0(iVar5,0,0,1);
  FUN_80033fe0(iVar15,0,iVar9,1);
  FUN_80033fe0(iVar6,iVar7,iVar9,1);
  FUN_80033fe0(iVar14,0,iVar8,1);
  FUN_80033fe0(iVar13,iVar10,iVar9,1);
  FUN_80033bc8(iVar5,0,iVar9,0x40);
  iVar12 = (int)(((uint)uVar4 - (uint)uVar2) * 0x10000) >> 0x10;
  FUN_80033bc8(iVar15,iVar10,iVar12,0x40);
  FUN_80033bc8(iVar6,(int)((uint)uVar3 * -0x10000) >> 0x10,iVar12,0x40);
  FUN_80033bc8(iVar14,0,(int)((uint)uVar4 * -0x10000) >> 0x10,0x40);
  iVar6 = (int)(((uint)uVar3 - (uint)uVar1) * 0x10000) >> 0x10;
  FUN_80033bc8(iVar13,iVar6,iVar12,0x40);
  FUN_80033848(iVar11 + 0x22b0,iVar10,iVar9,1);
  FUN_80033bc8(iVar11 + 0x22b0,iVar6,iVar12,0x40);
  iVar14 = iVar11 + 0x2430;
  FUN_80033848(iVar14,iVar10,iVar9,1);
  iVar13 = iVar11 + 0x2470;
  FUN_80033848(iVar13,iVar10,iVar9,1);
  iVar5 = iVar11 + 0x24b0;
  FUN_80033848(iVar5,iVar7,iVar9,1);
  iVar11 = iVar11 + 0x24f0;
  FUN_80033848(iVar11,iVar10,iVar8,1);
  FUN_80033fe0(iVar14,iVar10,iVar9,1);
  FUN_80033fe0(iVar13,iVar10,iVar9,1);
  FUN_80033fe0(iVar5,iVar7,iVar9,1);
  FUN_80033fe0(iVar11,iVar10,iVar8,1);
  FUN_80033bc8(iVar14,iVar6,0,0x40);
  FUN_80033bc8(iVar13,0,iVar12,0x40);
  FUN_80033bc8(iVar5,0,iVar12,0x40);
  FUN_80033bc8(iVar11,iVar6,0,0x40);
  return;
}



// ---- FUN_8003c5f8 @ 8003c5f8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_8003c5f8(undefined4 param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar1 = _DAT_800abf64;
  iVar6 = _DAT_800abf64 + 0x22b0;
  uVar2 = 0;
  switch(param_1) {
  case 0:
    *(uint *)(_DAT_800abf64 + 0x1ac8) =
         *(uint *)(_DAT_800abf64 + 0x1ac8) & 0xcfffdfff | (uint)(param_2 != 2) << 0x1c;
    FUN_80032d9c(iVar6,0);
    FUN_80032e54(iVar6,1,param_2);
    uVar3 = 0;
    uVar4 = 0;
    uVar5 = 0;
    goto LAB_8003c714;
  case 1:
    uVar2 = *(uint *)(_DAT_800abf64 + 0x1ac8);
    *(uint *)(_DAT_800abf64 + 0x1ac8) =
         uVar2 & 0xefffdfff | (uint)(param_2 != 2) << 0x1c | 0x20000000;
    FUN_80032d9c(iVar6,(uVar2 & 0x4000) >> 0xe);
    FUN_80032e54(iVar6,1,param_2);
    uVar3 = 0xff;
    uVar4 = 0xff;
    uVar5 = 0xff;
LAB_8003c714:
    FUN_80033094(iVar6,uVar3,uVar4,uVar5,0xf);
    uVar2 = FUN_800340c8(iVar6,0);
    break;
  case 2:
    uVar2 = *(uint *)(_DAT_800abf64 + 0x1ac8);
    if ((uVar2 & 0x4000) != 0) {
      *(uint *)(_DAT_800abf64 + 0x1ac8) =
           uVar2 & 0xefffffff | 0x2000 | (uint)(param_2 != 2) << 0x1c | 0x20000000;
      FUN_80032d9c(iVar6,1);
      FUN_80032e54(iVar6,1,param_2);
      FUN_80033094(iVar6,0xff,0xff,0xff,0xf);
      uVar2 = FUN_800340c8(iVar6,FUN_8003c9f4);
      return uVar2;
    }
    goto LAB_8003c868;
  case 3:
    uVar2 = *(uint *)(_DAT_800abf64 + 0x1ac8);
    if ((uVar2 & 0x4000) != 0) {
      *(uint *)(_DAT_800abf64 + 0x1ac8) = uVar2 & 0xcfffffff | 0x2000 | (uint)(param_2 != 2) << 0x1c
      ;
      FUN_80032d9c(iVar6,1);
      FUN_80032e54(iVar6,1,param_2);
      FUN_80033094(iVar6,0,0,0,0xf);
      uVar2 = FUN_800340c8(iVar6,FUN_8003cad8);
      return uVar2;
    }
LAB_8003c868:
    uVar2 = uVar2 | 0x40000000;
    *(uint *)(_DAT_800abf64 + 0x1ac8) = uVar2;
    break;
  case 4:
    uVar2 = *(uint *)(_DAT_800abf64 + 0x1ac8) >> 0xd;
    goto LAB_8003c740;
  case 5:
    uVar2 = *(uint *)(_DAT_800abf64 + 0x1ac8) >> 0x1d;
    if ((*(uint *)(_DAT_800abf64 + 0x1ac8) & 0x2000) != 0) {
      return 1;
    }
LAB_8003c740:
    uVar2 = (uVar2 ^ 1) & 1;
    break;
  case 6:
    if (param_2 == 1) {
      FUN_80033560(iVar6,0,0,1);
      uVar3 = 0x100;
      uVar4 = 0xf0;
    }
    else if ((int)param_2 < 2 == 0) {
      if (param_2 != 2) {
        return 2;
      }
      FUN_80033560(iVar6,0,0x20,1);
      uVar3 = 0x100;
      uVar4 = 0xb0;
    }
    else {
      if (param_2 != 0) {
        return (uint)((int)param_2 < 2);
      }
      FUN_80033560(iVar6,0x20,0x10,1);
      uVar3 = 0xc0;
      uVar4 = 0x80;
    }
    uVar2 = FUN_80033a18(iVar6,uVar3,uVar4,0x40);
    break;
  case 7:
    uVar2 = (param_2 & 7) << 0x19;
    *(uint *)(_DAT_800abf64 + 0x1ac8) = *(uint *)(_DAT_800abf64 + 0x1ac8) & 0xf1ffffff | uVar2;
    break;
  case 8:
    if (param_2 < 2) {
      *(uint *)(_DAT_800abf64 + 0x1ac8) =
           *(uint *)(_DAT_800abf64 + 0x1ac8) & 0xffffbfff | (param_2 & 1) << 0xe;
      FUN_80032d9c(iVar6);
    }
    uVar2 = *(uint *)(iVar1 + 0x1ac8) >> 0xe & 1;
    break;
  case 9:
    if (param_2 < 2) {
      *(uint *)(_DAT_800abf64 + 0x1ac8) =
           *(uint *)(_DAT_800abf64 + 0x1ac8) & 0xbfffffff | (param_2 & 1) << 0x1e;
    }
    uVar2 = *(uint *)(iVar1 + 0x1ac8) >> 0x1e & 1;
  }
  return uVar2;
}



// ---- FUN_8003c9f4 @ 8003c9f4

void FUN_8003c9f4(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = *(uint *)(param_1 + 0x1ac8);
  iVar4 = param_1 + 0x22b0;
  uVar2 = uVar1 & 0xfe007fff | (((int)(uVar1 << 7) >> 0x16) - (uVar1 >> 0x19 & 7) & 0x3ff) << 0xf;
  uVar3 = (int)(uVar2 << 7) >> 0x16;
  *(uint *)(param_1 + 0x1ac8) = uVar2;
  if ((int)uVar3 < 1) {
    *(uint *)(param_1 + 0x1ac8) = uVar1 & 0x9e005fff | 0x400000;
    FUN_80033094(iVar4,0,0,0,0xf);
    FUN_800340c8(iVar4,0);
  }
  else {
    uVar3 = uVar3 & 0xff;
    FUN_80033094(iVar4,uVar3,uVar3,uVar3,0xf);
  }
  return;
}



// ---- FUN_8003cad8 @ 8003cad8

void FUN_8003cad8(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = *(uint *)(param_1 + 0x1ac8);
  iVar4 = param_1 + 0x22b0;
  uVar2 = uVar1 & 0xfe007fff | (((int)(uVar1 << 7) >> 0x16) + (uVar1 >> 0x19 & 7) & 0x3ff) << 0xf;
  uVar3 = (int)(uVar2 << 7) >> 0x16;
  *(uint *)(param_1 + 0x1ac8) = uVar2;
  if ((int)uVar3 < 0xff) {
    uVar3 = uVar3 & 0xff;
    FUN_80033094(iVar4,uVar3,uVar3,uVar3,0xf);
  }
  else {
    *(uint *)(param_1 + 0x1ac8) = uVar1 & 0xbe005fff | 0x20400000;
    FUN_80033094(iVar4,0xff,0xff,0xff,0xf);
    FUN_800340c8(iVar4,0);
  }
  return;
}



// ---- FUN_8003cbbc @ 8003cbbc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003cbbc(void)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = _DAT_800abf64;
  bVar1 = *(byte *)(_DAT_800abf64 + 0x1ac0);
  while ((bVar1 & 1) == 0) {
    bVar1 = *(byte *)(_DAT_800abf64 + 0x1ac0);
  }
  FUN_8003e90c();
  FUN_8003d198(*(undefined4 *)(PTR_DAT_80071e84 + 8));
  FUN_8003d500(*(uint *)(iVar2 + 0x1acc) & 1);
  FUN_8003d33c();
  do {
    FUN_8003e9ac();
  } while( true );
}



// ---- FUN_8003cc50 @ 8003cc50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003cc50(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar1 = _DAT_800abf64;
  *(byte *)(_DAT_800abf64 + 0x1ac0) = *(byte *)(_DAT_800abf64 + 0x1ac0) & 0xfe;
  *(byte *)(iVar1 + 0x1ac0) = *(byte *)(iVar1 + 0x1ac0) & 0xfd;
  *(byte *)(iVar1 + 0x1ac0) = *(byte *)(iVar1 + 0x1ac0) & 0xfb;
  *(byte *)(iVar1 + 0x1ac0) = *(byte *)(iVar1 + 0x1ac0) & 0xf7;
  *(byte *)(iVar1 + 0x1ac0) = *(byte *)(iVar1 + 0x1ac0) & 0xef;
  *(byte *)(iVar1 + 0x1ac0) = *(byte *)(iVar1 + 0x1ac0) & 0xdf;
  *(byte *)(iVar1 + 0x1ac0) = *(byte *)(iVar1 + 0x1ac0) & 0xbf;
  iVar7 = 7;
  *(byte *)(iVar1 + 0x1ac0) = *(byte *)(iVar1 + 0x1ac0) & 0x7f;
  *(undefined4 *)(iVar1 + 0x1ac4) = 0;
  *(byte *)(iVar1 + 0x1ac1) = *(byte *)(iVar1 + 0x1ac1) & 0xfe;
  *(byte *)(iVar1 + 0x1ac1) = *(byte *)(iVar1 + 0x1ac1) & 0xfd;
  *(byte *)(iVar1 + 0x1ac1) = *(byte *)(iVar1 + 0x1ac1) & 0xfb;
  *(undefined4 *)(iVar1 + 0x1ac8) = 0x88404000;
  *(byte *)(iVar1 + 0x1ac1) = *(byte *)(iVar1 + 0x1ac1) & 0xf7;
  *(byte *)(iVar1 + 0x1ac1) = *(byte *)(iVar1 + 0x1ac1) & 0xef;
  *(byte *)(iVar1 + 0x1ac1) = *(byte *)(iVar1 + 0x1ac1) & 0xdf;
  *(uint *)(iVar1 + 0x1acc) = *(uint *)(iVar1 + 0x1acc) & 0xffffffc1 | 1;
  iVar9 = iVar1 + 0x1ac0;
  *(byte *)(iVar1 + 0x1acc) = *(byte *)(iVar1 + 0x1acc) & 0xbf;
  iVar4 = iVar1 + 0x1ac7;
  *(byte *)(iVar1 + 0x1acc) = *(byte *)(iVar1 + 0x1acc) & 0x7f;
  *(uint *)(iVar1 + 0x1acc) = *(uint *)(iVar1 + 0x1acc) & 0xff | 0x8000;
  do {
    *(undefined1 *)(iVar4 + 0x10) = 0;
    iVar7 = iVar7 + -1;
    iVar4 = iVar4 + -1;
  } while (-1 < iVar7);
  iVar7 = 3;
  iVar4 = iVar1 + 0x1ac3;
  *(undefined4 *)(iVar1 + 0x1adc) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1aec) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1ad8) = 0;
  *(undefined4 *)(iVar1 + 0x1ae4) = 0;
  *(undefined4 *)(iVar1 + 0x1ae8) = 0;
  *(undefined2 *)(iVar1 + 0x1af2) = 0;
  *(undefined2 *)(iVar1 + 0x1af0) = 0;
  *(uint *)(iVar1 + 0x1ae0) = *(uint *)(iVar1 + 0x1ae0) & 0xfffffff8;
  *(uint *)(iVar1 + 0x1af4) = *(uint *)(iVar1 + 0x1af4) & 0xe3f001f8 | 0x3f001f8;
  do {
    *(undefined1 *)(iVar4 + 0x38) = 0xff;
    iVar7 = iVar7 + -1;
    iVar4 = iVar4 + -1;
  } while (-1 < iVar7);
  iVar7 = 0;
  *(undefined4 *)(iVar1 + 0x1afc) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1b08) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1b10) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1b30) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1b34) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1b38) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1b3c) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0x1b40) = 0xffffffff;
  *(undefined2 *)(iVar1 + 0x1b00) = 0;
  *(undefined2 *)(iVar1 + 0x1b02) = 0;
  *(undefined2 *)(iVar1 + 0x1b0c) = 0;
  *(undefined2 *)(iVar1 + 0x1b0e) = 0;
  *(undefined4 *)(iVar1 + 0x1b14) = 0;
  *(undefined4 *)(iVar1 + 0x1b18) = 0;
  *(undefined4 *)(iVar1 + 0x1b1c) = 0;
  *(undefined4 *)(iVar1 + 0x1b20) = 0;
  *(undefined4 *)(iVar1 + 0x1b24) = 0;
  *(undefined4 *)(iVar1 + 0x1b2c) = 0;
  *(undefined4 *)(iVar1 + 0x1b44) = 0;
  *(undefined4 *)(iVar1 + 0x1b48) = 0;
  *(undefined4 *)(iVar1 + 0x1b4c) = 0;
  *(undefined4 *)(iVar1 + 0x1b54) = 0;
  *(uint *)(iVar1 + 0x1b28) = *(uint *)(iVar1 + 0x1b28) & 0xfffffe00 | 0xb0;
  *(uint *)(iVar1 + 0x1b04) = *(uint *)(iVar1 + 0x1b04) & 0xfffffffe;
  *(uint *)(iVar1 + 0x1b50) = *(uint *)(iVar1 + 0x1b50) & 0xffffff80;
  iVar4 = iVar9;
  do {
    *(undefined4 *)(iVar4 + 0x98) = 0;
    *(undefined4 *)(iVar4 + 0x118) = 0;
    iVar7 = iVar7 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar7 < 0x20);
  iVar8 = 0;
  iVar4 = iVar9;
  iVar7 = iVar9;
  do {
    *(undefined1 *)(iVar9 + iVar8 + 0x2b8) = 0;
    iVar6 = 0;
    puVar5 = (undefined1 *)(iVar7 + 0x298);
    puVar3 = (undefined4 *)(iVar4 + 0x218);
    puVar2 = (undefined4 *)(iVar4 + 0x198);
    do {
      *puVar2 = 0;
      *puVar3 = 0;
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
      puVar3 = puVar3 + 1;
      iVar6 = iVar6 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar6 < 8);
    iVar7 = iVar7 + 8;
    iVar8 = iVar8 + 1;
    iVar4 = iVar4 + 0x20;
  } while (iVar8 < 4);
  *(undefined4 *)(iVar1 + 0x1d7c) = 0;
  *(uint *)(iVar1 + 0x1d80) = *(uint *)(iVar1 + 0x1d80) & 0xfffffff8 | 0xf8;
  *(undefined1 *)(iVar1 + 0x1d81) = 0x60;
  *(undefined1 *)(iVar1 + 0x1d82) = 0x40;
  FUN_800585e4(iVar1 + 0x1d84,0x17);
  *(undefined1 *)(iVar1 + 0x1d9b) = 0;
  *(undefined1 *)(iVar1 + 0x1d9e) = 0xff;
  *(undefined1 *)(iVar1 + 0x1d9c) = 0;
  *(undefined1 *)(iVar1 + 0x1d9d) = 0xb;
  *(undefined4 *)(iVar1 + 0x1da0) = 0;
  FUN_800585e4(iVar1 + 0x1da4,10);
  iVar7 = 0;
  *(undefined1 *)(iVar1 + 0x1db1) = 9;
  *(undefined1 *)(iVar1 + 0x1dae) = 0xff;
  *(undefined1 *)(iVar1 + 0x1daf) = 0;
  *(undefined1 *)(iVar1 + 0x1db2) = 0;
  *(undefined1 *)(iVar1 + 0x1db3) = 0;
  *(undefined4 *)(iVar1 + 0x1db8) = 0;
  *(undefined4 *)(iVar1 + 0x1dbc) = 0;
  *(undefined4 *)(iVar1 + 0x1dc0) = 0;
  *(undefined4 *)(iVar1 + 0x1dc8) = 0;
  *(uint *)(iVar1 + 0x1dc4) = *(uint *)(iVar1 + 0x1dc4) & 0xffffff00;
  iVar4 = iVar9;
  do {
    iVar7 = iVar7 + 1;
    *(undefined1 *)(iVar4 + 0x30c) = 0;
    *(undefined1 *)(iVar4 + 0x310) = 0xff;
    iVar4 = iVar9 + iVar7;
  } while (iVar7 < 4);
  *(undefined4 *)(iVar1 + 0x1dd4) = 0x80105000;
  *(undefined4 *)(iVar1 + 0x1dd8) = 0;
  *(undefined4 *)(iVar1 + 0x1de0) = 0xffffffff;
  *(undefined2 *)(iVar1 + 0x1de4) = 0;
  *(undefined1 *)(iVar1 + 0x1de6) = 0;
  *(undefined1 *)(iVar1 + 0x1de7) = 0;
  *(undefined1 *)(iVar1 + 0x1de8) = 0;
  *(undefined1 *)(iVar1 + 0x1de9) = 0;
  *(undefined1 *)(iVar1 + 0x1dea) = 0;
  *(undefined1 *)(iVar1 + 0x1deb) = 0;
  *(undefined1 *)(iVar1 + 0x1dec) = 0;
  *(undefined1 *)(iVar1 + 0x1ded) = 0;
  *(undefined1 *)(iVar1 + 0x1dee) = 0;
  *(undefined1 *)(iVar1 + 0x1def) = 0;
  return;
}



// ---- FUN_8003d198 @ 8003d198

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003d198(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  undefined4 local_130;
  undefined4 local_12c;
  undefined1 auStack_128 [264];
  
  iVar7 = _DAT_800abf64;
  iVar6 = 0;
  pbVar5 = &DAT_8010d000;
  *(byte *)(_DAT_800abf64 + 0x1ac1) = *(byte *)(_DAT_800abf64 + 0x1ac1) & 0xfb;
  local_130 = 0;
  local_12c = 0;
  FUN_800364d8(9,&local_130);
  bVar1 = *(byte *)(iVar7 + 0x1ac1);
  while ((bVar1 & 4) == 0) {
    bVar1 = *(byte *)(iVar7 + 0x1ac1);
  }
  uRam800ac1b4 = DAT_80028244;
  uRam800ac1b8 = DAT_80028248;
  uRam800ac1bc = DAT_8002824c;
  iVar7 = 1;
  if (0 < param_1) {
    do {
      uVar4 = (uint)*pbVar5;
      FUN_800585e4(auStack_128,0x101);
      FUN_80058604(auStack_128,pbVar5 + 1,uVar4);
      uVar2 = FUN_8004582c(auStack_128);
      iVar3 = iVar7 * 0x20;
      iVar7 = iVar7 + 1;
      FUN_80058644(iVar3 + -0x7ff53e4c,uVar2);
      FUN_8002af34(uVar2);
      iVar6 = iVar6 + 1 + uVar4;
      pbVar5 = pbVar5 + 1 + uVar4;
    } while (iVar6 < param_1);
  }
  _DAT_800ac934 = iVar7;
  return;
}



// ---- FUN_8003d33c @ 8003d33c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003d33c(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _DAT_800abf64;
  if (*(int *)(_DAT_800abf64 + 0x1a90) == -1) {
    *(undefined4 *)(_DAT_800abf64 + 0x1a90) = 1;
  }
  if (*(int *)(iVar1 + 0x1a94) == -1) {
    *(undefined4 *)(iVar1 + 0x1a94) = 0;
  }
  if (*(int *)(iVar1 + 0x1a98) == -1) {
    *(undefined4 *)(iVar1 + 0x1a98) = 0;
  }
  if (*(int *)(iVar1 + 0x1a9c) == -1) {
    *(undefined4 *)(iVar1 + 0x1a9c) = 1;
  }
  if (*(int *)(iVar1 + 0x1aa0) == -1) {
    *(undefined4 *)(iVar1 + 0x1aa0) = 0;
  }
  if (*(int *)(iVar1 + 0x1aa4) == -1) {
    *(undefined4 *)(iVar1 + 0x1aa4) = 1;
  }
  if (*(int *)(iVar1 + 0x1aa8) == -1) {
    *(undefined4 *)(iVar1 + 0x1aa8) = 2;
  }
  if (*(int *)(iVar1 + 0x1aac) == -1) {
    *(undefined4 *)(iVar1 + 0x1aac) = 0x7f;
  }
  if (*(int *)(iVar1 + 0x1ab0) == -1) {
    *(undefined4 *)(iVar1 + 0x1ab0) = 0;
  }
  if (*(int *)(iVar1 + 0x1ab4) == -1) {
    *(undefined4 *)(iVar1 + 0x1ab4) = 0x7f;
  }
  if (*(int *)(iVar1 + 0x1ab8) == -1) {
    *(undefined4 *)(iVar1 + 0x1ab8) = 0;
  }
  *(uint *)(iVar1 + 0x1acc) =
       *(uint *)(iVar1 + 0x1acc) & 0xfffe7fff | (*(uint *)(iVar1 + 0x1a90) & 3) << 0xf;
  FUN_8002ba74(0x41,*(undefined4 *)(iVar1 + 0x1a94));
  FUN_8002ba74(0x12,*(undefined4 *)(iVar1 + 0x1a98));
  FUN_80033094(_DAT_800abf64 + 0x2770,*(undefined1 *)(iVar1 + 0x1aac),
               *(undefined1 *)(iVar1 + 0x1ab0),*(undefined1 *)(iVar1 + 0x1ab4),1);
  iVar2 = _DAT_800abf64 + 0x4c70;
  *(undefined1 *)(iVar1 + 0x1ded) = *(undefined1 *)(iVar1 + 0x1ab8);
  FUN_80035458(iVar2,*(undefined1 *)(iVar1 + 0x1ab8),0,1);
  FUN_80035694(iVar2,0x1c,(&DAT_80071108)[*(byte *)(iVar1 + 0x1ded)]);
  return;
}



// ---- FUN_8003d500 @ 8003d500

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003d500(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_68;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [2];
  
  iVar2 = _DAT_800abf64;
  iVar8 = _DAT_800abf64 + 0x195c;
  pbVar6 = (byte *)(_DAT_800abf64 + 0x1ac0);
  if (param_1 == 1) {
    return;
  }
  FUN_8002de7c(_DAT_800abf64 + 0x168,0);
  if (*(int *)(iVar2 + 0x1dc8) == DAT_80071100) {
    *(undefined4 *)(iVar2 + 0x1960) = 0x1f;
    uVar3 = 0x530;
  }
  else {
    if (*(int *)(iVar2 + 0x1dc8) != DAT_80071104) {
      *(byte *)(iVar2 + 0x1ac0) = *(byte *)(iVar2 + 0x1ac0) & 0xbf;
      bVar1 = *(byte *)(iVar2 + 0x1ac0);
      *(uint *)(iVar2 + 0x1acc) = *(uint *)(iVar2 + 0x1acc) | 2;
      while ((bVar1 & 0x40) == 0) {
        bVar1 = *pbVar6;
      }
      goto LAB_8003d5f0;
    }
    *(undefined4 *)(iVar2 + 0x1960) = 0x1f;
    uVar3 = 0x531;
  }
  *(undefined4 *)(iVar2 + 0x1964) = uVar3;
  *(uint *)(iVar2 + 0x1acc) =
       *(uint *)(iVar2 + 0x1acc) & 0xffffffcf | ((*(uint *)(iVar2 + 0x1acc) >> 4 & 3) + 1 & 3) << 4;
LAB_8003d5f0:
  *(undefined4 *)(iVar2 + 0x544) = 0;
  *(undefined2 *)(iVar2 + 0x578) = 1;
  *pbVar6 = *pbVar6 & 0x7f;
  local_78 = *(undefined4 *)(iVar2 + 0x1960);
  local_74 = *(undefined4 *)(iVar2 + 0x1964);
  local_70 = 1;
  FUN_800364d8(5,&local_78);
  do {
  } while ((*pbVar6 & 0x80) == 0);
  if (*(uint *)(iVar2 + 0x198c) < 0x80) {
    iVar4 = 0;
  }
  else {
    iVar4 = (*(uint *)(iVar2 + 0x198c) & 0x7f) + 1;
  }
  uVar7 = *(uint *)(iVar2 + 0x198c);
  if (0x80 < uVar7) {
    uVar7 = 0x80;
  }
  for (; iVar4 < (int)uVar7; iVar4 = iVar4 + 1) {
    *pbVar6 = *pbVar6 & 0xfb;
    local_68 = 0;
    iVar5 = iVar4;
    if (iVar4 < 0) {
      iVar5 = iVar4 + 0x7f;
    }
    iVar5 = (iVar4 + (iVar5 >> 7) * -0x80) * 2 + iVar8;
    local_64 = (int)((uint)*(ushort *)(iVar5 + 0x34) << 0x10) >> 0x11;
    local_60 = 0x17b;
    if ((*(ushort *)(iVar5 + 0x34) & 1) != 0) {
      local_60 = 0x17d;
    }
    local_5c = 0;
    FUN_800364d8(1,&local_68);
    do {
    } while ((*pbVar6 & 4) == 0);
  }
  *(undefined4 *)(iVar2 + 0x544) = 1;
  *(undefined2 *)(iVar2 + 0x578) = 0;
  FUN_80031268(0,*(undefined4 *)(iVar2 + 0x1974));
  if (0 < *(int *)(iVar2 + 0x1970)) {
    *pbVar6 = *pbVar6 & 0xdf;
    local_58 = 0;
    local_54 = *(undefined4 *)(iVar2 + 0x1970);
    local_50 = 0;
    FUN_800364d8(4,&local_58);
    do {
    } while ((*pbVar6 & 0x20) == 0);
    *pbVar6 = *pbVar6 & 0xdf;
    local_58 = 0;
    local_54 = 0x9b9;
    local_50 = 0;
    FUN_800364d8(4,&local_58);
    do {
    } while ((*pbVar6 & 0x20) == 0);
  }
  if (0 < *(int *)(iVar2 + 0x1968)) {
    bVar1 = *pbVar6;
    *(uint *)(iVar2 + 0x1af4) = *(uint *)(iVar2 + 0x1af4) & 0xe7ffffff | 0x8000000;
    *pbVar6 = bVar1 & 0xf7;
    local_38 = 0;
    local_34 = *(undefined4 *)(iVar2 + 0x1968);
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    FUN_800364d8(2,&local_38);
    do {
    } while ((*pbVar6 & 8) == 0);
  }
  if (0 < *(int *)(iVar2 + 0x196c)) {
    *pbVar6 = *pbVar6 & 0xef;
    local_48 = 0;
    local_44 = *(undefined4 *)(iVar2 + 0x196c);
    local_40 = 0;
    FUN_800364d8(3,&local_48);
    do {
    } while ((*pbVar6 & 0x10) == 0);
  }
  *(byte *)(iVar2 + 0x1ac1) = *(byte *)(iVar2 + 0x1ac1) & 0xfe;
  local_20[0] = 0xb4;
  FUN_800364d8(7,local_20);
  do {
  } while ((*(byte *)(iVar2 + 0x1ac1) & 1) == 0);
  if ((*(int *)(iVar2 + 0x1dc8) != DAT_80071100) && (*(int *)(iVar2 + 0x1dc8) != DAT_80071104)) {
    *pbVar6 = *pbVar6 & 0xbf;
    bVar1 = *pbVar6;
    *(uint *)(iVar2 + 0x1acc) = *(uint *)(iVar2 + 0x1acc) | 2;
    while ((bVar1 & 0x40) == 0) {
      bVar1 = *pbVar6;
    }
  }
  return;
}



// ---- FUN_8003d924 @ 8003d924

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8003d924(void)

{
  undefined4 uVar1;
  
  if (_DAT_800aee9c == 0) {
    uVar1 = FUN_8003d95c();
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



// ---- FUN_8003d95c @ 8003d95c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8003d95c(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 local_138;
  int local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128 [32];
  undefined4 local_a8 [36];
  
  iVar1 = _DAT_800abf64;
  iVar4 = 0;
  if (0 < _DAT_800abf60) {
    puVar5 = &local_138;
    iVar7 = -0x7ff51990;
    iVar6 = 0;
    do {
      uVar3 = FUN_8004582c(iVar7);
      iVar7 = iVar7 + 0x40;
      puVar5[4] = uVar3;
      puVar2 = (undefined4 *)(iVar6 + -0x7ff51990);
      iVar6 = iVar6 + 0x40;
      iVar4 = iVar4 + 1;
      puVar5[0x24] = *puVar2;
      puVar5 = puVar5 + 1;
    } while (iVar4 < _DAT_800abf60);
  }
  local_138 = *(undefined4 *)(&DAT_800afec8 + _DAT_800ab5cc * 4);
  local_12c = _DAT_800ab6a0;
  local_130 = _DAT_800b03c8;
  local_134 = _DAT_800abf60;
  FUN_800364d8(8,&local_138);
  *(byte *)(iVar1 + 0x1ac1) = *(byte *)(iVar1 + 0x1ac1) & 0xfd;
  do {
  } while ((*(byte *)(iVar1 + 0x1ac1) & 2) == 0);
  iVar4 = 0;
  if (0 < _DAT_800abf60) {
    puVar5 = &local_138;
    do {
      puVar2 = puVar5 + 4;
      puVar5 = puVar5 + 1;
      FUN_8002af34(*puVar2);
      iVar4 = iVar4 + 1;
    } while (iVar4 < _DAT_800abf60);
  }
  return (*(int *)(iVar1 + 0x1d7c) << 0x17) >> 0x19;
}



// ---- FUN_8003dacc @ 8003dacc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003dacc(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  undefined4 local_18;
  int local_14;
  
  iVar2 = _DAT_800abf64;
  if (param_1 == 5) {
    puVar4 = &DAT_80118000;
    *(uint *)(_DAT_800abf64 + 0x1db4) = *(uint *)(_DAT_800abf64 + 0x1db4) | 1;
  }
  else {
    uVar3 = *(uint *)(_DAT_800abf64 + 0x1db4);
    if ((uVar3 & 1) == 0) {
      *(uint *)(_DAT_800abf64 + 0x1db4) = uVar3 & 0xfffffffe;
      local_18 = 1;
      local_14 = param_1;
      FUN_800364d8(9,&local_18);
      *(byte *)(iVar2 + 0x1ac1) = *(byte *)(iVar2 + 0x1ac1) & 0xfb;
      puVar4 = &DAT_8010d000;
      bVar1 = *(byte *)(iVar2 + 0x1ac1);
      while ((bVar1 & 4) == 0) {
        bVar1 = *(byte *)(iVar2 + 0x1ac1);
      }
    }
    else {
      puVar4 = &DAT_8010d000;
      *(uint *)(_DAT_800abf64 + 0x1db4) = uVar3 & 0xfffffffe;
    }
  }
  _DAT_800abff0 = puVar4 + 4;
  _DAT_800ab5a4 = _DAT_800abff0 + CONCAT11(*puVar4,puVar4[1]);
  pbVar5 = _DAT_800abff0 + CONCAT11(*puVar4,puVar4[1]) + CONCAT11(puVar4[2],puVar4[3]);
  _DAT_800aee98 =
       (uint)pbVar5[3] << 0x18 | (uint)pbVar5[2] << 0x10 | (uint)pbVar5[1] << 8 | (uint)*pbVar5;
  return;
}



// ---- FUN_8003dc1c @ 8003dc1c

void FUN_8003dc1c(void)

{
  return;
}



// ---- FUN_8003dc2c @ 8003dc2c

uint FUN_8003dc2c(void)

{
  DAT_8007110c = DAT_8007110c * 0x41c64e6d + 0x3039;
  return DAT_8007110c >> 0x10 & 0xff;
}



// ---- FUN_8003dc5c @ 8003dc5c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8003dc5c(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  undefined4 local_38;
  uint local_34;
  uint local_30;
  undefined4 local_18;
  uint local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar2 = _DAT_800abf64;
  pbVar4 = (byte *)(_DAT_800abf64 + 0x1ac0);
  if ((((param_1 != 0x82d) && (param_1 < 0x82e)) && (param_1 == 0x676)) &&
     ((param_2 != 0x9c8 && (param_2 < 0x9c9)))) {
    if (param_2 < 0x346) {
      if ((0x342 < param_2) || ((param_2 < 0x252 && (0x24d < param_2)))) {
LAB_8003dd04:
        *(byte *)(_DAT_800abf64 + 0x1ac1) = *(byte *)(_DAT_800abf64 + 0x1ac1) & 0xf7;
        local_18 = 0;
        local_10 = _DAT_800ab5cc;
        local_c = _DAT_800ab6a0;
        local_14 = param_2;
        FUN_800364d8(10,&local_18);
        do {
        } while ((*(byte *)(iVar2 + 0x1ac1) & 8) == 0);
        goto LAB_8003de5c;
      }
    }
    else if (param_2 != 0x50a) {
      if (param_2 < 0x50b) {
        if (param_2 < 0x349) {
          if ((*(uint *)(_DAT_800abf64 + 0x1dc4) & 0x80) == 0) {
            if (*(int *)(_DAT_800abf64 + 0x1b3c) != -1) {
              *(uint *)(_DAT_800abf64 + 0x1af4) = *(uint *)(_DAT_800abf64 + 0x1af4) | 2;
            }
            iVar1 = _DAT_800ab5b8;
            *(uint *)(iVar2 + 0x1af4) = *(uint *)(iVar2 + 0x1af4) & 0xe7ffffff | 0x8000000;
            *(undefined4 *)(iVar2 + 0x1dc8) = *(undefined4 *)(&DAT_800afec8 + iVar1 * 4);
          }
          else {
            *(undefined4 *)(_DAT_800abf64 + 0x1978) = 0;
            uVar3 = *(uint *)(iVar2 + 0x1acc) >> 4 & 3;
            if (uVar3 == 0) {
              *(undefined4 *)(iVar2 + 0x1dc8) = DAT_80071100;
            }
            else if (uVar3 == 1) {
              *(undefined4 *)(iVar2 + 0x1dc8) = DAT_80071104;
            }
            else {
              *(undefined4 *)(iVar2 + 0x1dc8) = 0;
            }
          }
          return 0;
        }
      }
      else if (param_2 == 0x999) goto LAB_8003dd04;
    }
  }
  *pbVar4 = *pbVar4 & 0xbf;
  local_38 = 5;
  local_34 = param_1;
  local_30 = param_2;
  FUN_800364d8(6,&local_38);
  do {
  } while ((*pbVar4 & 0x40) == 0);
LAB_8003de5c:
  return *(undefined4 *)(iVar2 + 0x1b18);
}



// ---- FUN_8003de74 @ 8003de74

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003de74(undefined4 param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = *(undefined4 *)(_DAT_800abf64 + 0x1b30);
  local_10 = 0;
  local_14 = param_1;
  FUN_800364d8(5,&local_18);
  return;
}



// ---- FUN_8003deb0 @ 8003deb0

void FUN_8003deb0(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = 0;
  local_c = 0;
  local_14 = param_1;
  local_10 = param_2;
  FUN_800364d8(1,&local_18);
  return;
}



// ---- FUN_8003dee4 @ 8003dee4

void FUN_8003dee4(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_18;
  undefined4 local_14;
  
  if (param_2 == 0) {
    local_28 = 1;
  }
  else {
    local_28 = 3;
  }
  local_24 = 0x5f0;
  local_20 = param_1;
  local_18 = param_2;
  local_14 = param_3;
  FUN_800364d8(6,&local_28);
  return;
}



// ---- FUN_8003df30 @ 8003df30

void FUN_8003df30(undefined4 param_1)

{
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  local_1c = param_1;
  FUN_800364d8(2,&local_20);
  return;
}



// ---- FUN_8003df5c @ 8003df5c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003df5c(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_20;
  uint local_1c;
  undefined4 local_18;
  
  iVar2 = _DAT_800abf64;
  uVar3 = FUN_8004582c(param_1 + _DAT_800ab5a4);
  *(byte *)(iVar2 + 0x1ac0) = *(byte *)(iVar2 + 0x1ac0) & 0xfd;
  local_20 = 0;
  local_1c = *(uint *)(iVar2 + 0x1acc) >> 9 & 0x3f;
  local_18 = uVar3;
  FUN_800364d8(0,&local_20);
  bVar1 = *(byte *)(iVar2 + 0x1ac0);
  while ((bVar1 & 2) == 0) {
    bVar1 = *(byte *)(iVar2 + 0x1ac0);
  }
  FUN_8002af34(uVar3);
  return;
}



// ---- FUN_8003e000 @ 8003e000

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003e000(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int local_20;
  int local_1c;
  undefined4 local_18;
  
  iVar2 = _DAT_800abf64;
  uVar3 = FUN_8004582c(param_2 + _DAT_800ab5a4);
  *(byte *)(iVar2 + 0x1ac0) = *(byte *)(iVar2 + 0x1ac0) & 0xfd;
  local_20 = param_1 * 0x20 + -0x7ff53e4c;
  local_1c = param_1;
  local_18 = uVar3;
  FUN_800364d8(0,&local_20);
  bVar1 = *(byte *)(iVar2 + 0x1ac0);
  while ((bVar1 & 2) == 0) {
    bVar1 = *(byte *)(iVar2 + 0x1ac0);
  }
  FUN_8002af34(uVar3);
  return;
}



// ---- FUN_8003e0ac @ 8003e0ac

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003e0ac(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar2 = _DAT_800abf64;
  *(byte *)(_DAT_800abf64 + 0x1ac0) = *(byte *)(_DAT_800abf64 + 0x1ac0) & 0xfb;
  local_18 = 0;
  local_c = 1;
  local_14 = param_1;
  local_10 = param_2;
  FUN_800364d8(1,&local_18);
  bVar1 = *(byte *)(iVar2 + 0x1ac0);
  while ((bVar1 & 4) == 0) {
    bVar1 = *(byte *)(iVar2 + 0x1ac0);
  }
  return;
}



// ---- FUN_8003e12c @ 8003e12c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003e12c(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar2 = _DAT_800abf64;
  *(byte *)(_DAT_800abf64 + 0x1ac0) = *(byte *)(_DAT_800abf64 + 0x1ac0) & 0xfb;
  local_18 = 1;
  local_10 = 0;
  local_c = 0;
  local_14 = param_1;
  FUN_800364d8(1,&local_18);
  bVar1 = *(byte *)(iVar2 + 0x1ac0);
  while ((bVar1 & 4) == 0) {
    bVar1 = *(byte *)(iVar2 + 0x1ac0);
  }
  return;
}



// ---- FUN_8003e1a8 @ 8003e1a8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003e1a8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  
  iVar2 = _DAT_800abf64;
  *(byte *)(_DAT_800abf64 + 0x1ac0) = *(byte *)(_DAT_800abf64 + 0x1ac0) & 0xf7;
  local_20 = 0;
  local_18 = 0;
  local_c = (uint)((*(uint *)(iVar2 + 0x1af4) & 0x18000000) != 0x18000000);
  local_1c = param_1;
  local_14 = param_2;
  local_10 = param_3;
  FUN_800364d8(2,&local_20);
  bVar1 = *(byte *)(iVar2 + 0x1ac0);
  while ((bVar1 & 8) == 0) {
    bVar1 = *(byte *)(iVar2 + 0x1ac0);
  }
  return;
}



// ---- FUN_8003e23c @ 8003e23c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003e23c(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar2 = _DAT_800abf64;
  *(byte *)(_DAT_800abf64 + 0x1ac0) = *(byte *)(_DAT_800abf64 + 0x1ac0) & 0xf7;
  local_20 = 1;
  local_1c = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_18 = param_1;
  FUN_800364d8(2,&local_20);
  bVar1 = *(byte *)(iVar2 + 0x1ac0);
  while ((bVar1 & 8) == 0) {
    bVar1 = *(byte *)(iVar2 + 0x1ac0);
  }
  return;
}



// ---- FUN_8003e2c0 @ 8003e2c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003e2c0(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar2 = _DAT_800abf64;
  *(byte *)(_DAT_800abf64 + 0x1ac0) = *(byte *)(_DAT_800abf64 + 0x1ac0) & 0xef;
  local_18 = 0;
  local_10 = 0;
  local_14 = param_1;
  FUN_800364d8(3,&local_18);
  bVar1 = *(byte *)(iVar2 + 0x1ac0);
  while ((bVar1 & 0x10) == 0) {
    bVar1 = *(byte *)(iVar2 + 0x1ac0);
  }
  return;
}



// ---- FUN_8003e334 @ 8003e334

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003e334(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar2 = _DAT_800abf64;
  *(byte *)(_DAT_800abf64 + 0x1ac0) = *(byte *)(_DAT_800abf64 + 0x1ac0) & 0xef;
  local_18 = 1;
  local_14 = 0;
  local_10 = param_1;
  FUN_800364d8(3,&local_18);
  bVar1 = *(byte *)(iVar2 + 0x1ac0);
  while ((bVar1 & 0x10) == 0) {
    bVar1 = *(byte *)(iVar2 + 0x1ac0);
  }
  return;
}



// ---- FUN_8003e3ac @ 8003e3ac

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003e3ac(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar2 = _DAT_800abf64;
  *(byte *)(_DAT_800abf64 + 0x1ac0) = *(byte *)(_DAT_800abf64 + 0x1ac0) & 0xdf;
  local_18 = 0;
  local_10 = 0;
  local_14 = param_1;
  FUN_800364d8(4,&local_18);
  bVar1 = *(byte *)(iVar2 + 0x1ac0);
  while ((bVar1 & 0x20) == 0) {
    bVar1 = *(byte *)(iVar2 + 0x1ac0);
  }
  return;
}



// ---- FUN_8003e420 @ 8003e420

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003e420(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar2 = _DAT_800abf64;
  *(byte *)(_DAT_800abf64 + 0x1ac0) = *(byte *)(_DAT_800abf64 + 0x1ac0) & 0xdf;
  local_18 = 1;
  local_14 = 0;
  local_10 = param_1;
  FUN_800364d8(4,&local_18);
  bVar1 = *(byte *)(iVar2 + 0x1ac0);
  while ((bVar1 & 0x20) == 0) {
    bVar1 = *(byte *)(iVar2 + 0x1ac0);
  }
  return;
}



// ---- FUN_8003e498 @ 8003e498

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003e498(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  
  iVar2 = _DAT_800abf64;
  *(byte *)(_DAT_800abf64 + 0x1ac0) = *(byte *)(_DAT_800abf64 + 0x1ac0) & 0xbf;
  local_28 = 0;
  local_24 = param_1;
  FUN_800364d8(6,&local_28);
  bVar1 = *(byte *)(iVar2 + 0x1ac0);
  while ((bVar1 & 0x40) == 0) {
    bVar1 = *(byte *)(iVar2 + 0x1ac0);
  }
  return;
}



// ---- FUN_8003e508 @ 8003e508

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003e508(int param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 local_30;
  int local_2c;
  undefined4 local_20;
  
  iVar2 = _DAT_800abf64;
  pbVar3 = (byte *)(_DAT_800abf64 + 0x1ac0);
  if (param_1 != 0x24d) {
    *(byte *)(_DAT_800abf64 + 0x1ac0) = *(byte *)(_DAT_800abf64 + 0x1ac0) & 0xbf;
    local_30 = 1;
    local_2c = param_1;
    local_20 = param_2;
    FUN_800364d8(6,&local_30);
    bVar1 = *(byte *)(iVar2 + 0x1ac0);
    while ((bVar1 & 0x40) == 0) {
      bVar1 = *pbVar3;
    }
    do {
    } while (param_1 == 0x5ee);
  }
  return;
}



// ---- FUN_8003e5a8 @ 8003e5a8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003e5a8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar2 = _DAT_800abf64;
  *(byte *)(_DAT_800abf64 + 0x1ac0) = *(byte *)(_DAT_800abf64 + 0x1ac0) & 0xbf;
  local_28 = 2;
  local_24 = param_1;
  local_18 = param_2;
  local_14 = param_3;
  FUN_800364d8(6,&local_28);
  bVar1 = *(byte *)(iVar2 + 0x1ac0);
  while ((bVar1 & 0x40) == 0) {
    bVar1 = *(byte *)(iVar2 + 0x1ac0);
  }
  return;
}



// ---- FUN_8003e628 @ 8003e628

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003e628(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar2 = _DAT_800abf64;
  *(byte *)(_DAT_800abf64 + 0x1ac0) = *(byte *)(_DAT_800abf64 + 0x1ac0) & 0xbf;
  local_28 = 3;
  local_24 = param_1;
  local_20 = param_3;
  local_18 = param_2;
  local_14 = param_4;
  FUN_800364d8(6,&local_28);
  bVar1 = *(byte *)(iVar2 + 0x1ac0);
  while ((bVar1 & 0x40) == 0) {
    bVar1 = *(byte *)(iVar2 + 0x1ac0);
  }
  return;
}



// ---- FUN_8003e6ac @ 8003e6ac

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003e6ac(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 local_28 [4];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar2 = _DAT_800abf64;
  *(byte *)(_DAT_800abf64 + 0x1ac0) = *(byte *)(_DAT_800abf64 + 0x1ac0) & 0xbf;
  local_28[0] = 4;
  local_18 = param_2;
  local_14 = param_3;
  local_10 = param_4;
  FUN_800364d8(6,local_28);
  bVar1 = *(byte *)(iVar2 + 0x1ac0);
  while ((bVar1 & 0x40) == 0) {
    bVar1 = *(byte *)(iVar2 + 0x1ac0);
  }
  return;
}



// ---- FUN_8003e728 @ 8003e728

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003e728(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_18;
  
  iVar2 = _DAT_800abf64;
  *(byte *)(_DAT_800abf64 + 0x1ac0) = *(byte *)(_DAT_800abf64 + 0x1ac0) & 0xbf;
  local_28 = 6;
  local_24 = param_1;
  local_20 = param_2;
  local_18 = param_3;
  FUN_800364d8(6,&local_28);
  bVar1 = *(byte *)(iVar2 + 0x1ac0);
  while ((bVar1 & 0x40) == 0) {
    bVar1 = *(byte *)(iVar2 + 0x1ac0);
  }
  return;
}



// ---- FUN_8003e7a8 @ 8003e7a8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003e7a8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar2 = _DAT_800abf64;
  *(byte *)(_DAT_800abf64 + 0x1ac0) = *(byte *)(_DAT_800abf64 + 0x1ac0) & 0xbf;
  local_28 = 7;
  local_24 = param_1;
  local_20 = param_2;
  local_1c = param_3;
  FUN_800364d8(6,&local_28);
  bVar1 = *(byte *)(iVar2 + 0x1ac0);
  while ((bVar1 & 0x40) == 0) {
    bVar1 = *(byte *)(iVar2 + 0x1ac0);
  }
  return;
}



// ---- FUN_8003e828 @ 8003e828

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003e828(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar2 = _DAT_800abf64;
  local_18 = *(undefined4 *)(_DAT_800abf64 + 0x1b30);
  *(byte *)(_DAT_800abf64 + 0x1ac0) = *(byte *)(_DAT_800abf64 + 0x1ac0) & 0x7f;
  local_10 = 0;
  local_14 = param_1;
  FUN_800364d8(5,&local_18);
  bVar1 = *(byte *)(iVar2 + 0x1ac0);
  while ((bVar1 & 0x80) == 0) {
    bVar1 = *(byte *)(iVar2 + 0x1ac0);
  }
  return;
}



// ---- FUN_8003e8a0 @ 8003e8a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003e8a0(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 local_10 [2];
  
  iVar2 = _DAT_800abf64;
  *(byte *)(_DAT_800abf64 + 0x1ac1) = *(byte *)(_DAT_800abf64 + 0x1ac1) & 0xfe;
  local_10[0] = param_1;
  FUN_800364d8(7,local_10);
  bVar1 = *(byte *)(iVar2 + 0x1ac1);
  while ((bVar1 & 1) == 0) {
    bVar1 = *(byte *)(iVar2 + 0x1ac1);
  }
  return;
}



// ---- FUN_8003e90c @ 8003e90c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003e90c(void)

{
  uint uVar1;
  undefined4 *puVar2;
  
  _DAT_800abf68 = &DAT_800abff4;
  FUN_800585e4(&DAT_800abff4,0x1b9);
  uVar1 = 0;
  puVar2 = (undefined4 *)&DAT_800afec8;
  _DAT_800ab5cc = 0;
  do {
    *puVar2 = 0xffffffff;
    uVar1 = uVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (uVar1 < 0x40);
  uVar1 = 0;
  puVar2 = (undefined4 *)&DAT_800b04ac;
  _DAT_800ab6a0 = 0;
  *(undefined4 *)(&DAT_800afec8 + _DAT_800ab5cc * 4) = 0;
  do {
    *puVar2 = 0;
    uVar1 = uVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (uVar1 < 0x10);
  return;
}



// ---- FUN_8003e9ac @ 8003e9ac

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003e9ac(void)

{
  undefined4 uVar1;
  
  _DAT_800b0620 = 0;
  _DAT_800ab578 = 0xffffffff;
  uVar1 = *(undefined4 *)(&DAT_800afec8 + _DAT_800ab5cc * 4);
  do {
    uVar1 = FUN_8003ea04(uVar1);
  } while( true );
}



// ---- FUN_8003ea04 @ 8003ea04

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_8003ea04(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = _DAT_800ab5cc + 1;
  iVar1 = _DAT_800ab5cc * 4;
  _DAT_800ab5cc = uVar2;
  *(uint *)(&DAT_800afec8 + iVar1) = param_1;
  if (0x3f < uVar2) {
    _DAT_800ab5cc = 0;
  }
  if (_DAT_800ab5cc == 0) {
    _DAT_800ab5b8 = 0x3e;
  }
  else {
    _DAT_800ab5b8 = 0x3f;
    if (_DAT_800ab5cc != 1) {
      _DAT_800ab5b8 = _DAT_800ab5cc - 2;
    }
  }
  FUN_8003f2dc((int)param_1 >> 0xf);
  _DAT_800ab5d8 = param_1 & 0x7fff;
  FUN_8003ec28(param_1);
  uVar2 = _DAT_800ab5d8;
  uVar3 = 0;
  iVar1 = 0;
  do {
    *(undefined1 *)(iVar1 + -0x7ff5365b) = 0;
    uVar3 = uVar3 + 1;
    iVar1 = iVar1 + 0x144;
  } while (uVar3 < 0x10);
  if (*(char *)(_DAT_800abff0 + _DAT_800ab5d8) == '\t') {
    uVar2 = _DAT_800ab5d8 + 1;
    do {
      _DAT_800ab5d8 = uVar2;
      uVar3 = FUN_8003f870(0);
    } while ((int)uVar3 < 0);
  }
  else if (*(char *)(_DAT_800abff0 + _DAT_800ab5d8) == '\n') {
    uVar3 = 0xffffffff;
  }
  else {
    _DAT_800b03c8 = 0xffffffff;
    do {
      _DAT_800ab5d8 = uVar2;
      uVar3 = FUN_8004195c();
    } while ((int)uVar3 < 0);
  }
  FUN_8003ec5c();
  if (0xffffff < (int)uVar3) {
    if ((int)uVar3 < 0x2000000) {
      iVar1 = _DAT_800ab6a0 * 4;
      _DAT_800ab6a0 = _DAT_800ab6a0 + 1;
      *(uint *)(&DAT_800b04ac + iVar1) = param_1;
      return uVar3 & 0x7fffff;
    }
    _DAT_800ab6a0 = _DAT_800ab6a0 + -1;
    uVar3 = *(uint *)(&DAT_800b04ac + _DAT_800ab6a0 * 4);
  }
  return uVar3;
}



// ---- FUN_8003ec28 @ 8003ec28

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003ec28(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _DAT_800b0620 * 4;
  _DAT_800b0620 = _DAT_800b0620 + 1;
  *(undefined4 *)(&DAT_800affc8 + iVar1) = param_1;
  return;
}



// ---- FUN_8003ec5c @ 8003ec5c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003ec5c(void)

{
  _DAT_800b0620 = _DAT_800b0620 + -1;
  return;
}



// ---- FUN_8003ec7c @ 8003ec7c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_8003ec7c(int param_1)

{
  byte bVar1;
  byte *pbVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  if (param_1 == 0) {
    iVar4 = _DAT_800ab5d8 + 1;
    pbVar2 = (byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
    _DAT_800abfec = (uint)*pbVar2;
    uVar3 = CONCAT11(*pbVar2,*(undefined1 *)(_DAT_800abff0 + iVar4));
  }
  else {
    iVar4 = _DAT_800ab5d8 + 1;
    pbVar2 = (byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    iVar6 = _DAT_800ab5d8 + 2;
    _DAT_800ab5d8 = _DAT_800ab5d8 + 3;
    bVar1 = *(byte *)(_DAT_800abff0 + iVar4);
    _DAT_800abfec = (uint)bVar1;
    uVar3 = CONCAT11(bVar1,*(undefined1 *)(_DAT_800abff0 + iVar6));
    uVar5 = (uint)uVar3;
    uVar7 = (uint)*pbVar2;
    if (*pbVar2 != 0xff) goto LAB_8003ed5c;
  }
  uVar5 = (short)uVar3 + -2 + _DAT_800ab5d8;
  uVar7 = _DAT_800ab578;
LAB_8003ed5c:
  return uVar7 << 0xf | uVar5;
}



// ---- FUN_8003ed68 @ 8003ed68

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_8003ed68(void)

{
  ushort uVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = _DAT_800ab5d8 + 1;
  puVar2 = (undefined1 *)(_DAT_800abff0 + _DAT_800ab5d8);
  iVar4 = _DAT_800ab5d8 + 2;
  _DAT_800ab5d8 = _DAT_800ab5d8 + 3;
  uVar1 = CONCAT11(*puVar2,*(undefined1 *)(_DAT_800abff0 + iVar3));
  _DAT_800abfec = (uint)uVar1;
  return CONCAT21(uVar1,*(undefined1 *)(_DAT_800abff0 + iVar4)) & 0x1fffff;
}



// ---- FUN_8003ede4 @ 8003ede4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8003ede4(void)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = _DAT_800ab5d8 + 1;
  pbVar1 = (byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
  _DAT_800abfec = (uint)*pbVar1;
  iVar2 = (uint)CONCAT11(*pbVar1,*(undefined1 *)(_DAT_800abff0 + iVar2)) * 2;
  if (*(char *)(iVar2 + _DAT_800ab5a4 + -1) != '\0') {
    iVar2 = iVar2 + -1;
  }
  return iVar2;
}



// ---- FUN_8003ee58 @ 8003ee58

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003ee58(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = _DAT_800ab5d8 + 1;
  uVar1 = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  _DAT_800abfec = uVar1;
  _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
  if (uVar1 < 0xc0) {
    _DAT_800ab5d8 = iVar2;
  }
  else {
    uVar1 = (uVar1 - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + iVar2);
  }
  _DAT_800ab5d8 = uVar1 + _DAT_800ab5d8;
  return;
}



// ---- FUN_8003eed8 @ 8003eed8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_8003eed8(uint param_1)

{
  int iVar1;
  int iVar2;
  
  param_1 = param_1 & 0xffff;
  if (param_1 < 0xe000) {
    if (param_1 < 0xa000) {
      return param_1;
    }
    iVar1 = FUN_8003ef5c(_DAT_800aee98);
    iVar2 = -0xa000;
  }
  else {
    iVar1 = FUN_8003ef5c(_DAT_800aeeac);
    iVar2 = -0xe000;
  }
  return param_1 + iVar1 + iVar2;
}



// ---- FUN_8003ef5c @ 8003ef5c

void FUN_8003ef5c(void)

{
  return;
}



// ---- FUN_8003ef90 @ 8003ef90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003ef90(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_1 & 0xffff;
  if (uVar3 < 0xe000) {
    if (uVar3 < 0xa000) goto LAB_8003f00c;
    iVar1 = FUN_8003ef5c(_DAT_800aee98);
    iVar2 = -0xa000;
  }
  else {
    iVar1 = FUN_8003ef5c(_DAT_800aeeac);
    iVar2 = -0xe000;
  }
  uVar3 = uVar3 + iVar1 + iVar2;
LAB_8003f00c:
  FUN_8003f034(uVar3,((int)param_1 >> 0x10 & 0x1fU) + 1);
  return;
}



// ---- FUN_8003f034 @ 8003f034

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_8003f034(uint param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  
  iVar5 = (int)param_1 >> 3;
  param_1 = param_1 & 7;
  if ((int)(param_1 + param_2) < 9) {
    uVar2 = (int)(uint)*(byte *)(_DAT_800abf68 + iVar5) >> ((8 - param_2) - param_1 & 0x1f) &
            (1 << (param_2 & 0x1f)) - 1U;
  }
  else {
    uVar3 = (param_2 - 8) + param_1;
    uVar2 = (uint)*(byte *)(_DAT_800abf68 + iVar5) & 0xff >> param_1;
    iVar5 = iVar5 + 1;
    if (7 < (int)uVar3) {
      pbVar4 = (byte *)(iVar5 + _DAT_800abf68);
      do {
        bVar1 = *pbVar4;
        pbVar4 = pbVar4 + 1;
        uVar3 = uVar3 - 8;
        uVar2 = uVar2 << 8 | (uint)bVar1;
        iVar5 = iVar5 + 1;
      } while (7 < (int)uVar3);
    }
    if (uVar3 != 0) {
      uVar2 = uVar2 << (uVar3 & 0x1f) |
              (int)(uint)*(byte *)(_DAT_800abf68 + iVar5) >> (8 - uVar3 & 0x1f);
    }
  }
  return uVar2;
}



// ---- FUN_8003f10c @ 8003f10c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003f10c(uint param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_1 & 0xffff;
  if (uVar3 < 0xe000) {
    if (uVar3 < 0xa000) goto LAB_8003f18c;
    iVar1 = FUN_8003ef5c(_DAT_800aee98);
    iVar2 = -0xa000;
  }
  else {
    iVar1 = FUN_8003ef5c(_DAT_800aeeac);
    iVar2 = -0xe000;
  }
  uVar3 = uVar3 + iVar1 + iVar2;
LAB_8003f18c:
  FUN_8003f1bc(uVar3,((int)param_1 >> 0x10 & 0x1fU) + 1,param_2);
  return;
}



// ---- FUN_8003f1bc @ 8003f1bc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003f1bc(int param_1,uint param_2,uint param_3)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  int iVar6;
  
  uVar2 = param_1 + -1 + param_2;
  iVar6 = (int)uVar2 >> 3;
  uVar2 = uVar2 & 7;
  if (((int)param_2 < 0x20) && (param_3 >> (param_2 & 0x1f) != 0)) {
    param_3 = (1 << (param_2 & 0x1f)) - 1;
  }
  if ((int)(uVar2 + 1) < (int)param_2) {
    uVar4 = param_3 >> uVar2 + 1;
    uVar3 = (param_2 - 1) - uVar2;
    *(byte *)(_DAT_800abf68 + iVar6) =
         *(byte *)(_DAT_800abf68 + iVar6) & ~(byte)((2 << uVar2) + -1 << (7 - uVar2 & 0x1f)) |
         (byte)(param_3 << (7 - uVar2 & 0x1f));
    while( true ) {
      iVar6 = iVar6 + -1;
      if ((int)uVar3 < 8) break;
      uVar3 = uVar3 - 8;
      *(byte *)(_DAT_800abf68 + iVar6) = (byte)uVar4;
      uVar4 = uVar4 >> 8;
    }
    if (uVar3 == 0) {
      return;
    }
    pbVar1 = (byte *)(_DAT_800abf68 + iVar6);
    bVar5 = *pbVar1 & (byte)(-1 << (uVar3 & 0x1f)) | (byte)uVar4;
  }
  else {
    pbVar1 = (byte *)(_DAT_800abf68 + iVar6);
    bVar5 = *pbVar1 & ~(byte)((1 << (param_2 & 0x1f)) + -1 << (7 - uVar2 & 0x1f)) |
            (byte)(param_3 << (7 - uVar2 & 0x1f));
  }
  *pbVar1 = bVar5;
  return;
}



// ---- FUN_8003f2dc @ 8003f2dc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8003f2dc(int param_1)

{
  if (_DAT_800ab578 != param_1) {
    FUN_8003dacc();
    _DAT_800ab578 = param_1;
  }
  return;
}



// ---- FUN_8003f31c @ 8003f31c

undefined4 FUN_8003f31c(int param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_48 [4];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  iVar3 = 0;
  if (0 < *(short *)(&DAT_8007111a + param_1 * 8)) {
    puVar4 = local_48;
    do {
      iVar3 = iVar3 + 1;
      uVar1 = FUN_800429b0();
      *puVar4 = uVar1;
      puVar4 = puVar4 + 1;
    } while (iVar3 < *(short *)(&DAT_8007111a + param_1 * 8));
  }
  iVar3 = param_1 * 8;
  pcVar2 = (code *)(&PTR_FUN_80071114)[param_1 * 2];
  if (*(short *)(&DAT_80071118 + iVar3) != 0) {
    switch(*(undefined2 *)(&DAT_8007111a + iVar3)) {
    case 0:
      uVar1 = (*pcVar2)();
      return uVar1;
    case 1:
      uVar1 = (*pcVar2)(local_48[0]);
      return uVar1;
    case 2:
      uVar1 = (*pcVar2)(local_48[0],local_48[1]);
      return uVar1;
    case 3:
      uVar1 = (*pcVar2)(local_48[0],local_48[1],local_48[2]);
      return uVar1;
    case 4:
      uVar1 = (*pcVar2)(local_48[0],local_48[1],local_48[2],local_48[3]);
      return uVar1;
    case 5:
      break;
    case 6:
      break;
    case 7:
      goto LAB_8003f714;
    case 8:
LAB_8003f714:
      uVar1 = (*pcVar2)(local_48[0],local_48[1],local_48[2],local_48[3],local_38,local_34,local_30);
      return uVar1;
    case 9:
      goto LAB_8003f7b8;
    case 10:
LAB_8003f7b8:
      uVar1 = (*pcVar2)(local_48[0],local_48[1],local_48[2],local_48[3],local_38,local_34,local_30,
                        local_2c,local_28);
      return uVar1;
    default:
      goto switchD_8003f3ec_default;
    }
    uVar1 = (*pcVar2)(local_48[0],local_48[1],local_48[2],local_48[3],local_38);
    return uVar1;
  }
  switch(*(undefined2 *)(&DAT_8007111a + iVar3)) {
  case 0:
    (*pcVar2)();
    break;
  case 1:
    (*pcVar2)(local_48[0]);
    break;
  case 2:
    (*pcVar2)(local_48[0],local_48[1]);
    break;
  case 3:
    (*pcVar2)(local_48[0],local_48[1],local_48[2]);
    break;
  case 4:
    (*pcVar2)(local_48[0],local_48[1],local_48[2],local_48[3]);
    break;
  case 5:
    goto LAB_8003f490;
  case 6:
LAB_8003f490:
    (*pcVar2)(local_48[0],local_48[1],local_48[2],local_48[3],local_38);
    break;
  case 7:
    goto LAB_8003f504;
  case 8:
LAB_8003f504:
    (*pcVar2)(local_48[0],local_48[1],local_48[2],local_48[3],local_38,local_34,local_30);
    break;
  case 9:
    goto LAB_8003f5a8;
  case 10:
LAB_8003f5a8:
    (*pcVar2)(local_48[0],local_48[1],local_48[2],local_48[3],local_38,local_34,local_30,local_2c,
              local_28);
    break;
  default:
switchD_8003f3ec_default:
  }
  return 0;
}



// ---- FUN_8003f7fc @ 8003f7fc

void FUN_8003f7fc(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(short *)(&DAT_8007111a + param_1 * 8)) {
    do {
      iVar1 = iVar1 + 1;
      FUN_800433b0();
    } while (iVar1 < *(short *)(&DAT_8007111a + param_1 * 8));
  }
  return;
}



// ---- FUN_8003f870 @ 8003f870

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8003f870(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  uVar2 = _DAT_800abfec;
  iVar3 = _DAT_800ab5d8 + 1;
  if (0xbf < _DAT_800abfec) {
    uVar2 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
    iVar3 = _DAT_800ab5d8 + 2;
  }
  _DAT_800ab5d8 = iVar3;
  iVar3 = uVar2 + _DAT_800ab5d8;
  do {
    if (iVar3 <= _DAT_800ab5d8) {
      return -1;
    }
    iVar1 = FUN_8003fc20(param_1);
  } while (iVar1 < 0);
  return iVar1;
}



// ---- FUN_8003f93c @ 8003f93c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8003f93c(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar2 = _DAT_800ab5d8;
  uVar1 = _DAT_800ab578;
  FUN_8003f2dc((int)param_1 >> 0xf);
  param_1 = param_1 & 0x7fff;
  _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + param_1);
  _DAT_800ab5d8 = param_1 + 2;
  if (_DAT_800abfec < 0xc0) {
    uVar4 = _DAT_800abfec;
    _DAT_800ab5d8 = param_1 + 1;
  }
  else {
    uVar4 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + param_1 + 1);
  }
  iVar5 = uVar4 + _DAT_800ab5d8;
  do {
    if (iVar5 <= _DAT_800ab5d8) {
      iVar3 = -1;
      break;
    }
    iVar3 = FUN_8003fc20(param_2);
  } while (iVar3 < 0);
  FUN_8003f2dc(uVar1);
  _DAT_800ab5d8 = uVar2;
  return iVar3;
}



// ---- FUN_8003fb14 @ 8003fb14

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8003fb14(uint param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar2 = _DAT_800ab5d8;
  uVar1 = _DAT_800ab578;
  FUN_8003f2dc((int)param_1 >> 0xf);
  param_1 = param_1 & 0x7fff;
  _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + param_1);
  _DAT_800ab5d8 = param_1 + 2;
  if (_DAT_800abfec < 0xc0) {
    uVar4 = _DAT_800abfec;
    _DAT_800ab5d8 = param_1 + 1;
  }
  else {
    uVar4 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + param_1 + 1);
  }
  iVar5 = uVar4 + _DAT_800ab5d8;
  do {
    if (iVar5 <= _DAT_800ab5d8) {
      iVar3 = -1;
      break;
    }
    iVar3 = FUN_8003fe88();
  } while (iVar3 < 0);
  FUN_8003f2dc(uVar1);
  _DAT_800ab5d8 = uVar2;
  return iVar3;
}



// ---- FUN_8003fc20 @ 8003fc20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8003fc20(undefined4 param_1)

{
  byte bVar1;
  undefined4 uVar2;
  byte bVar3;
  int iVar4;
  
  iVar4 = _DAT_800ab5d8 + 1;
  bVar1 = *(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  bVar3 = bVar1 & 0xe0;
  _DAT_800ab5d8 = iVar4;
  if (bVar3 == 0x40) {
    uVar2 = FUN_800401f0(bVar1 & 0x1f,param_1);
    return uVar2;
  }
  if (bVar3 < 0x41) {
    if ((bVar1 & 0xe0) == 0) {
      uVar2 = FUN_80040118(bVar1 & 0x1f);
      return uVar2;
    }
    if (bVar3 == 0x20) {
      uVar2 = FUN_80040170(bVar1 & 0x1f);
      return uVar2;
    }
  }
  else {
    if (bVar3 == 0x60) {
      uVar2 = FUN_80040248(bVar1 & 0x1f);
      return uVar2;
    }
    if (bVar3 == 0x80) {
      uVar2 = FUN_800405cc(bVar1 & 0x1f);
      return uVar2;
    }
  }
  bVar3 = bVar1 & 0xf0;
  if (bVar3 == 0xb0) {
    uVar2 = FUN_80040cc0(bVar1 & 0xf);
    return uVar2;
  }
  if (bVar3 < 0xb1) {
    if (bVar3 == 0xa0) {
      uVar2 = FUN_80040998(bVar1 & 0xf);
      return uVar2;
    }
  }
  else {
    if (bVar3 == 0xc0) {
      uVar2 = FUN_80040fbc(bVar1 & 0xf);
      return uVar2;
    }
    if (bVar3 == 0xd0) {
      uVar2 = FUN_80041008(bVar1 & 0xf);
      return uVar2;
    }
  }
  switch(bVar1) {
  case 0xe0:
  case 0xe1:
  case 0xe2:
  case 0xe3:
    uVar2 = FUN_800410e0(bVar1 & 3);
    break;
  case 0xe4:
  case 0xe5:
  case 0xe6:
  case 0xe7:
    uVar2 = FUN_8004145c(bVar1 & 3);
    break;
  case 0xe8:
    uVar2 = FUN_800414a0(0);
    break;
  case 0xe9:
    uVar2 = FUN_800414a0(1);
    break;
  case 0xea:
    uVar2 = FUN_800415b8();
    break;
  case 0xeb:
    uVar2 = FUN_80041630();
    break;
  case 0xec:
    uVar2 = FUN_800416f0();
    break;
  case 0xed:
    uVar2 = FUN_800416f8();
    break;
  case 0xee:
    uVar2 = FUN_80041008(0xffffffff);
    break;
  default:
    uVar2 = 0xffffffff;
    break;
  case 0xfb:
    uVar2 = FUN_80040248(0xfffffffe);
    break;
  case 0xfc:
    uVar2 = FUN_80040248(0xffffffff);
    break;
  case 0xfd:
    uVar2 = FUN_800405cc(0xffffffff);
    break;
  case 0xfe:
    uVar2 = FUN_80040998(0xffffffff);
    break;
  case 0xff:
    uVar2 = FUN_80040cc0(0xffffffff);
  }
  return uVar2;
}



// ---- FUN_8003fe88 @ 8003fe88

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8003fe88(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar2 = _DAT_800ab5d8 + 1;
  uVar3 = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  uVar4 = uVar3 & 0xe0;
  if (uVar4 == 0x40) {
LAB_8003ff00:
    _DAT_800ab5d8 = ((uVar3 & 0x1f) + 1) * 3 + iVar2;
    return 0xffffffff;
  }
  if (uVar4 < 0x41) {
    if (((*(byte *)(_DAT_800abff0 + _DAT_800ab5d8) & 0xe0) == 0) || (uVar4 == 0x20))
    goto LAB_8003ff00;
  }
  else {
    if (uVar4 == 0x60) {
      _DAT_800ab5d8 = iVar2;
      FUN_80041724(uVar3 & 0x1f);
      return 0xffffffff;
    }
    if (uVar4 == 0x80) {
      _DAT_800ab5d8 = iVar2;
      FUN_8004177c(uVar3 & 0x1f);
      return 0xffffffff;
    }
  }
  uVar4 = uVar3 & 0xf0;
  if (uVar4 == 0xb0) {
    _DAT_800ab5d8 = iVar2;
    FUN_80041844(uVar3 & 0xf);
    return 0xffffffff;
  }
  if (uVar4 < 0xb1) {
    if (uVar4 == 0xa0) {
      _DAT_800ab5d8 = iVar2;
      FUN_800417d0(uVar3 & 0xf);
      return 0xffffffff;
    }
  }
  else {
    if (uVar4 == 0xc0) {
      _DAT_800ab5d8 = iVar2;
      FUN_800418a4(uVar3 & 0xf);
      return 0xffffffff;
    }
    if (uVar4 == 0xd0) {
      _DAT_800ab5d8 = iVar2;
      FUN_800418ec(uVar3 & 0xf);
      return 0xffffffff;
    }
  }
  switch(uVar3) {
  case 0xe0:
  case 0xe1:
  case 0xe2:
  case 0xe3:
    _DAT_800ab5d8 = iVar2;
    uVar1 = FUN_800412a4(uVar3 & 3);
    return uVar1;
  case 0xe4:
    iVar2 = _DAT_800ab5d8 + 3;
    break;
  case 0xe5:
    iVar2 = _DAT_800ab5d8 + 4;
    break;
  case 0xe6:
    iVar2 = _DAT_800ab5d8 + 3;
    break;
  case 0xe7:
    iVar2 = _DAT_800ab5d8 + 4;
    break;
  default:
    goto switchD_8003ffec_caseD_e8;
  case 0xeb:
    _DAT_800ab5d8 = iVar2;
    uVar1 = FUN_80041630();
    return uVar1;
  case 0xed:
    iVar2 = _DAT_800ab5d8 + 3;
    break;
  case 0xee:
    _DAT_800ab5d8 = iVar2;
    FUN_800418ec(0xffffffff);
    return 0xffffffff;
  case 0xfb:
    _DAT_800ab5d8 = iVar2;
    FUN_800433b0();
    iVar2 = _DAT_800ab5d8;
  case 0xe9:
    _DAT_800ab5d8 = iVar2;
    FUN_8003ee58();
    return 0xffffffff;
  case 0xfc:
  case 0xfd:
  case 0xfe:
  case 0xff:
    iVar5 = _DAT_800ab5d8 + 2;
    _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + iVar2);
    _DAT_800ab5d8 = _DAT_800ab5d8 + 3;
    if (_DAT_800abfec < 0xc0) {
      uVar3 = _DAT_800abfec;
      _DAT_800ab5d8 = iVar5;
    }
    else {
      uVar3 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + iVar5);
    }
    iVar2 = uVar3 + _DAT_800ab5d8;
  }
switchD_8003ffec_caseD_e8:
  _DAT_800ab5d8 = iVar2;
  return 0xffffffff;
}



// ---- FUN_80040118 @ 80040118

undefined4 FUN_80040118(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_1 + 1) {
    do {
      iVar2 = iVar2 + 1;
      uVar1 = FUN_8003ed68();
      FUN_8003f10c(uVar1,1);
    } while (iVar2 < param_1 + 1);
  }
  return 0xffffffff;
}



// ---- FUN_80040170 @ 80040170

undefined4 FUN_80040170(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_1 + 1) {
    do {
      uVar1 = FUN_8003ed68();
      iVar2 = FUN_8003ef90(uVar1);
      iVar3 = iVar3 + 1;
      if (iVar2 != -1) {
        FUN_8003f10c(uVar1,iVar2 + 1);
      }
    } while (iVar3 < param_1 + 1);
  }
  return 0xffffffff;
}



// ---- FUN_800401f0 @ 800401f0

undefined4 FUN_800401f0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_1 + 1) {
    do {
      iVar2 = iVar2 + 1;
      uVar1 = FUN_8003ed68();
      FUN_8003f10c(uVar1,0);
    } while (iVar2 < param_1 + 1);
  }
  return 0xffffffff;
}



// ---- FUN_80040248 @ 80040248

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80040248(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 < 0) {
    if (param_1 == -1) {
      _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
      uVar4 = _DAT_800abfec;
      iVar3 = _DAT_800ab5d8 + 1;
      if (0xbf < _DAT_800abfec) {
        uVar4 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
        iVar3 = _DAT_800ab5d8 + 2;
      }
      _DAT_800ab5d8 = iVar3;
      iVar3 = uVar4 + _DAT_800ab5d8;
      while( true ) {
        if (iVar3 <= _DAT_800ab5d8) {
          return -1;
        }
        iVar1 = FUN_800429b0();
        if (iVar1 != 0) break;
        FUN_8003ee58();
      }
      _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
      uVar4 = _DAT_800abfec;
      iVar1 = _DAT_800ab5d8 + 1;
      if (0xbf < _DAT_800abfec) {
        uVar4 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
        iVar1 = _DAT_800ab5d8 + 2;
      }
      _DAT_800ab5d8 = iVar1;
      iVar1 = uVar4 + _DAT_800ab5d8;
      do {
        if (iVar1 <= _DAT_800ab5d8) {
          _DAT_800ab5d8 = iVar3;
          return -1;
        }
        iVar2 = FUN_8003fc20(param_2);
      } while (iVar2 < 0);
      _DAT_800ab5d8 = iVar3;
      return iVar2;
    }
    iVar3 = FUN_800429b0();
    if (iVar3 != 0) {
      _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
      uVar4 = _DAT_800abfec;
      iVar3 = _DAT_800ab5d8 + 1;
      if (0xbf < _DAT_800abfec) {
        uVar4 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
        iVar3 = _DAT_800ab5d8 + 2;
      }
      _DAT_800ab5d8 = iVar3;
      iVar3 = uVar4 + _DAT_800ab5d8;
      do {
        if (iVar3 <= _DAT_800ab5d8) {
          return -1;
        }
        iVar1 = FUN_8003fc20(param_2);
      } while (iVar1 < 0);
      return iVar1;
    }
  }
  else {
    param_1 = param_1 + 1;
    iVar3 = 0;
    if (0 < param_1) {
      do {
        iVar1 = FUN_800429b0();
        if (iVar1 != 0) break;
        iVar3 = iVar3 + 1;
        FUN_8003ee58();
      } while (iVar3 < param_1);
    }
    _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    uVar4 = _DAT_800abfec;
    iVar1 = _DAT_800ab5d8 + 1;
    if (0xbf < _DAT_800abfec) {
      uVar4 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
      iVar1 = _DAT_800ab5d8 + 2;
    }
    _DAT_800ab5d8 = iVar1;
    iVar1 = uVar4 + _DAT_800ab5d8;
    do {
      iVar2 = -1;
      if (iVar1 <= _DAT_800ab5d8) break;
      iVar2 = FUN_8003fc20(param_2);
    } while (iVar2 < 0);
    if (-1 < iVar2) {
      return iVar2;
    }
    if (param_1 <= iVar3) {
      return -1;
    }
    while (iVar3 = iVar3 + 1, iVar3 < param_1) {
      FUN_800433b0();
      FUN_8003ee58();
    }
  }
  FUN_8003ee58();
  return -1;
}



// ---- FUN_800405cc @ 800405cc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_800405cc(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 < 0) {
    iVar2 = _DAT_800ab5d8 + 1;
    _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
    if (_DAT_800abfec < 0xc0) {
      uVar4 = _DAT_800abfec;
      _DAT_800ab5d8 = iVar2;
    }
    else {
      uVar4 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + iVar2);
    }
    iVar2 = -1;
    iVar3 = uVar4 + _DAT_800ab5d8;
    uVar1 = FUN_800429b0();
    do {
      if (iVar3 <= _DAT_800ab5d8) break;
      iVar2 = FUN_80040758(param_2,uVar1);
    } while (iVar2 == -99);
    _DAT_800ab5d8 = iVar3;
  }
  else {
    param_1 = param_1 + 1;
    uVar1 = FUN_800429b0();
    iVar3 = 0;
    iVar2 = iVar3;
    if (param_1 < 1) goto LAB_80040650;
    do {
      iVar3 = iVar2;
      iVar2 = FUN_80040758(param_2,uVar1);
      if (-1 < iVar2) {
        return iVar2;
      }
      if (iVar2 == -1) goto LAB_80040650;
      iVar2 = iVar3 + 1;
    } while (iVar3 + 1 < param_1);
    for (iVar3 = iVar3 + 2; iVar2 = -1, iVar3 < param_1; iVar3 = iVar3 + 1) {
      FUN_8003ee58();
      FUN_8003ee58();
LAB_80040650:
    }
  }
  return iVar2;
}



// ---- FUN_80040758 @ 80040758

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80040758(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  uVar2 = _DAT_800abfec;
  iVar1 = _DAT_800ab5d8 + 1;
  if (0xbf < _DAT_800abfec) {
    uVar2 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
    iVar1 = _DAT_800ab5d8 + 2;
  }
  _DAT_800ab5d8 = iVar1;
  if (uVar2 == 0) {
    _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    uVar2 = _DAT_800abfec;
    iVar1 = _DAT_800ab5d8 + 1;
    if (0xbf < _DAT_800abfec) {
      uVar2 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
      iVar1 = _DAT_800ab5d8 + 2;
    }
    _DAT_800ab5d8 = iVar1;
    iVar3 = uVar2 + _DAT_800ab5d8;
    do {
      if (iVar3 <= _DAT_800ab5d8) {
        return -1;
      }
      iVar1 = FUN_8003fc20(param_1);
    } while (iVar1 < 0);
  }
  else {
    iVar1 = uVar2 + _DAT_800ab5d8;
    if (_DAT_800ab5d8 < iVar1) {
      do {
        iVar3 = FUN_800429b0();
        if (iVar3 == param_2) {
          _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + iVar1);
          _DAT_800ab5d8 = iVar1 + 2;
          if (_DAT_800abfec < 0xc0) {
            uVar2 = _DAT_800abfec;
            _DAT_800ab5d8 = iVar1 + 1;
          }
          else {
            uVar2 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + iVar1 + 1);
          }
          iVar1 = uVar2 + _DAT_800ab5d8;
          do {
            if (iVar1 <= _DAT_800ab5d8) {
              return -1;
            }
            iVar3 = FUN_8003fc20(param_1);
          } while (iVar3 < 0);
          return iVar3;
        }
      } while (_DAT_800ab5d8 < iVar1);
    }
    FUN_8003ee58();
    iVar1 = -99;
  }
  return iVar1;
}



// ---- FUN_80040998 @ 80040998

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80040998(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 < 0) {
    iVar5 = _DAT_800ab5d8 + 1;
    _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
    if (_DAT_800abfec < 0xc0) {
      uVar2 = _DAT_800abfec;
      _DAT_800ab5d8 = iVar5;
    }
    else {
      uVar2 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + iVar5);
    }
    iVar5 = uVar2 + _DAT_800ab5d8;
    uVar1 = FUN_8003ed68();
    uVar2 = FUN_8003ef90(uVar1);
    FUN_8003f10c(uVar1,uVar2 + 1);
    while( true ) {
      if (iVar5 <= _DAT_800ab5d8) {
        return -1;
      }
      if (uVar2 <= *(byte *)(_DAT_800abff0 + _DAT_800ab5d8)) break;
      _DAT_800ab5d8 = _DAT_800ab5d8 + 1;
      FUN_8003ee58();
    }
    _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
    uVar2 = _DAT_800abfec;
    iVar4 = _DAT_800ab5d8 + 2;
    if (0xbf < _DAT_800abfec) {
      uVar2 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 2);
      iVar4 = _DAT_800ab5d8 + 3;
    }
    _DAT_800ab5d8 = iVar4;
    iVar4 = uVar2 + _DAT_800ab5d8;
    do {
      if (iVar4 <= _DAT_800ab5d8) {
        _DAT_800ab5d8 = iVar5;
        return -1;
      }
      iVar3 = FUN_8003fc20(param_2);
    } while (iVar3 < 0);
    _DAT_800ab5d8 = iVar5;
    return iVar3;
  }
  iVar5 = -1;
  param_1 = param_1 + 2;
  uVar1 = FUN_8003ed68();
  uVar2 = FUN_8003ef90(uVar1);
  FUN_8003f10c(uVar1,uVar2 + 1);
  iVar4 = 0;
  if (0 < param_1) {
    do {
      if (uVar2 <= *(byte *)(_DAT_800abff0 + _DAT_800ab5d8)) {
        _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
        uVar2 = _DAT_800abfec;
        iVar5 = _DAT_800ab5d8 + 2;
        if (0xbf < _DAT_800abfec) {
          uVar2 = (_DAT_800abfec - 0xc0) * 0x100 |
                  (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 2);
          iVar5 = _DAT_800ab5d8 + 3;
        }
        _DAT_800ab5d8 = iVar5;
        iVar3 = uVar2 + _DAT_800ab5d8;
        goto joined_r0x80040a84;
      }
      iVar4 = iVar4 + 1;
      _DAT_800ab5d8 = _DAT_800ab5d8 + 1;
      FUN_8003ee58();
    } while (iVar4 < param_1);
  }
  goto LAB_80040ad0;
  while (iVar5 = FUN_8003fc20(param_2), iVar5 < 0) {
joined_r0x80040a84:
    iVar5 = -1;
    if (iVar3 <= _DAT_800ab5d8) break;
  }
LAB_80040ad0:
  if (iVar5 < 0) {
    while( true ) {
      iVar4 = iVar4 + 1;
      iVar5 = -1;
      if (param_1 <= iVar4) break;
      _DAT_800ab5d8 = _DAT_800ab5d8 + 1;
      FUN_8003ee58();
    }
  }
  return iVar5;
}



// ---- FUN_80040cc0 @ 80040cc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80040cc0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = FUN_8003dc2c();
  if (param_1 < 0) {
    _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    uVar3 = _DAT_800abfec;
    iVar4 = _DAT_800ab5d8 + 1;
    if (0xbf < _DAT_800abfec) {
      uVar3 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
      iVar4 = _DAT_800ab5d8 + 2;
    }
    _DAT_800ab5d8 = iVar4;
    iVar2 = uVar3 + _DAT_800ab5d8;
    iVar4 = _DAT_800ab5d8;
    while( true ) {
      if (iVar2 <= iVar4) {
        _DAT_800ab5d8 = iVar4;
        return -1;
      }
      _DAT_800ab5d8 = iVar4 + 1;
      if (iVar1 <= (int)(uint)*(byte *)(_DAT_800abff0 + iVar4)) break;
      FUN_8003ee58();
      iVar4 = _DAT_800ab5d8;
    }
    _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    uVar3 = _DAT_800abfec;
    _DAT_800ab5d8 = iVar4 + 2;
    if (0xbf < _DAT_800abfec) {
      _DAT_800ab5d8 = iVar4 + 3;
      uVar3 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + iVar4 + 2);
    }
    iVar1 = uVar3 + _DAT_800ab5d8;
    do {
      if (iVar1 <= _DAT_800ab5d8) {
        _DAT_800ab5d8 = iVar2;
        return -1;
      }
      iVar4 = FUN_8003fc20(param_2);
    } while (iVar4 < 0);
    _DAT_800ab5d8 = iVar2;
    return iVar4;
  }
  iVar2 = -1;
  param_1 = param_1 + 2;
  iVar4 = 0;
  if (0 < param_1) {
    do {
      if (iVar1 <= (int)(uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8)) {
        _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
        uVar3 = _DAT_800abfec;
        iVar1 = _DAT_800ab5d8 + 2;
        if (0xbf < _DAT_800abfec) {
          uVar3 = (_DAT_800abfec - 0xc0) * 0x100 |
                  (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 2);
          iVar1 = _DAT_800ab5d8 + 3;
        }
        _DAT_800ab5d8 = iVar1;
        iVar1 = uVar3 + _DAT_800ab5d8;
        goto joined_r0x80040d90;
      }
      iVar4 = iVar4 + 1;
      _DAT_800ab5d8 = _DAT_800ab5d8 + 1;
      FUN_8003ee58();
    } while (iVar4 < param_1);
  }
  goto LAB_80040ddc;
  while (iVar2 = FUN_8003fc20(param_2), iVar2 < 0) {
joined_r0x80040d90:
    if (iVar1 <= _DAT_800ab5d8) {
      iVar2 = -1;
      break;
    }
  }
LAB_80040ddc:
  if (iVar2 < 0) {
    while( true ) {
      iVar4 = iVar4 + 1;
      iVar2 = -1;
      if (param_1 <= iVar4) break;
      _DAT_800ab5d8 = _DAT_800ab5d8 + 1;
      FUN_8003ee58();
    }
  }
  return iVar2;
}



// ---- FUN_80040fbc @ 80040fbc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80040fbc(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  _DAT_800ab5d8 = _DAT_800ab5d8 + 1;
  FUN_8003f31c(param_1 << 8 | (uint)*pbVar1);
  return 0xffffffff;
}



// ---- FUN_80041008 @ 80041008

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80041008(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  
  if (param_1 < 0) {
    uVar6 = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    _DAT_800ab5d8 = _DAT_800ab5d8 + 1;
  }
  else {
    uVar6 = param_1 + 1;
  }
  iVar1 = _DAT_800ab5d8;
  _DAT_800ab5d8 = uVar6 * 3 + _DAT_800ab5d8;
  iVar5 = 0;
  uVar3 = FUN_800429b0();
  iVar2 = _DAT_800ab5d8;
  _DAT_800ab5d8 = iVar1;
  if (0 < (int)uVar6) {
    do {
      iVar5 = iVar5 + 1;
      uVar4 = FUN_8003ed68();
      FUN_8003f10c(uVar4,uVar3);
    } while (iVar5 < (int)uVar6);
  }
  _DAT_800ab5d8 = iVar2;
  return 0xffffffff;
}



// ---- FUN_800410e0 @ 800410e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_800410e0(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  
  uVar2 = FUN_8003ec7c(param_1 & 1);
  uVar1 = _DAT_800aeeac;
  uVar8 = 0;
  if ((param_1 & 2) != 0) {
    iVar5 = _DAT_800ab5d8 + 1;
    pbVar3 = (byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
    _DAT_800abfec = (uint)*pbVar3;
    _DAT_800aeeac = FUN_8003eed8(CONCAT11(*pbVar3,*(undefined1 *)(_DAT_800abff0 + iVar5)));
    uVar8 = uVar1;
  }
  FUN_8003ec28(uVar2);
  iVar5 = _DAT_800ab5d8;
  uVar1 = _DAT_800ab578;
  FUN_8003f2dc((int)uVar2 >> 0xf);
  uVar2 = uVar2 & 0x7fff;
  _DAT_800ab5d8 = uVar2 + 1;
  _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + uVar2);
  uVar6 = _DAT_800abfec;
  if (0xbf < _DAT_800abfec) {
    uVar6 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    _DAT_800ab5d8 = uVar2 + 2;
  }
  iVar7 = uVar6 + _DAT_800ab5d8;
  do {
    if (iVar7 <= _DAT_800ab5d8) {
      iVar4 = -1;
      break;
    }
    iVar4 = FUN_8003fc20(param_2);
  } while (iVar4 < 0);
  FUN_8003f2dc(uVar1);
  _DAT_800ab5d8 = iVar5;
  FUN_8003ec5c();
  if ((param_1 & 2) != 0) {
    _DAT_800aeeac = uVar8;
  }
  return iVar4;
}



// ---- FUN_800412a4 @ 800412a4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_800412a4(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  
  uVar2 = FUN_8003ec7c(param_1 & 1);
  uVar1 = _DAT_800aeeac;
  uVar8 = 0;
  if ((param_1 & 2) != 0) {
    iVar5 = _DAT_800ab5d8 + 1;
    pbVar3 = (byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
    _DAT_800abfec = (uint)*pbVar3;
    _DAT_800aeeac = FUN_8003eed8(CONCAT11(*pbVar3,*(undefined1 *)(_DAT_800abff0 + iVar5)));
    uVar8 = uVar1;
  }
  FUN_8003ec28(uVar2);
  iVar5 = _DAT_800ab5d8;
  uVar1 = _DAT_800ab578;
  FUN_8003f2dc((int)uVar2 >> 0xf);
  uVar2 = uVar2 & 0x7fff;
  _DAT_800ab5d8 = uVar2 + 1;
  _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + uVar2);
  uVar6 = _DAT_800abfec;
  if (0xbf < _DAT_800abfec) {
    uVar6 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    _DAT_800ab5d8 = uVar2 + 2;
  }
  iVar7 = uVar6 + _DAT_800ab5d8;
  do {
    if (iVar7 <= _DAT_800ab5d8) {
      iVar4 = -1;
      break;
    }
    iVar4 = FUN_8003fe88();
  } while (iVar4 < 0);
  FUN_8003f2dc(uVar1);
  _DAT_800ab5d8 = iVar5;
  FUN_8003ec5c();
  if ((param_1 & 2) != 0) {
    _DAT_800aeeac = uVar8;
  }
  return iVar4;
}



// ---- FUN_8004145c @ 8004145c

uint FUN_8004145c(uint param_1)

{
  uint uVar1;
  
  uVar1 = FUN_8003ec7c(param_1 & 1);
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 0x1000000;
  }
  return uVar1;
}



// ---- FUN_800414a0 @ 800414a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_800414a0(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (param_2 == 0) {
    iVar1 = -1;
    if (param_1 != 0) {
      FUN_8003ee58();
      iVar1 = -1;
    }
  }
  else {
    *(undefined1 *)(_DAT_800b03c8 * 0x144 + -0x7ff5365b) = 1;
    iVar1 = -1;
    if (param_1 != 0) {
      _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
      uVar2 = _DAT_800abfec;
      iVar1 = _DAT_800ab5d8 + 1;
      if (0xbf < _DAT_800abfec) {
        uVar2 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
        iVar1 = _DAT_800ab5d8 + 2;
      }
      _DAT_800ab5d8 = iVar1;
      iVar3 = uVar2 + _DAT_800ab5d8;
      do {
        if (iVar3 <= _DAT_800ab5d8) {
          return -1;
        }
        iVar1 = FUN_8003fc20(0);
      } while (iVar1 < 0);
    }
  }
  return iVar1;
}



// ---- FUN_800415b8 @ 800415b8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800415b8(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _DAT_800b03c8 * 4;
  iVar2 = _DAT_800b03c8;
  if (-1 < _DAT_800b03c8) {
    iVar1 = _DAT_800b03c8 * 0x144;
    do {
      if (*(char *)(iVar1 + -0x7ff5365b) != '\0') break;
      iVar2 = iVar2 + -1;
      iVar1 = iVar1 + -0x144;
    } while (-1 < iVar2);
    iVar1 = iVar2 << 2;
  }
  *(undefined1 *)(iVar1 * 0x40 + iVar2 * 0x44 + -0x7ff5365b) = 0;
  return 0xffffffff;
}



// ---- FUN_80041630 @ 80041630

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80041630(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  uVar2 = _DAT_800abfec;
  iVar3 = _DAT_800ab5d8 + 1;
  if (0xbf < _DAT_800abfec) {
    uVar2 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
    iVar3 = _DAT_800ab5d8 + 2;
  }
  _DAT_800ab5d8 = iVar3;
  iVar3 = uVar2 + _DAT_800ab5d8;
  do {
    if (iVar3 <= _DAT_800ab5d8) {
      return -1;
    }
    iVar1 = FUN_8003fc20(0);
  } while (iVar1 < 0);
  return iVar1;
}



// ---- FUN_800416f0 @ 800416f0

undefined4 FUN_800416f0(void)

{
  return 0x2000000;
}



// ---- FUN_800416f8 @ 800416f8

undefined4 FUN_800416f8(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_8003ede4();
  FUN_8003dc1c(uVar1);
  return 0xffffffff;
}



// ---- FUN_80041724 @ 80041724

void FUN_80041724(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < param_1 + 1) {
    do {
      iVar1 = iVar1 + 1;
      FUN_800433b0();
      FUN_8003ee58();
    } while (iVar1 < param_1 + 1);
  }
  FUN_8003ee58();
  return;
}



// ---- FUN_8004177c @ 8004177c

void FUN_8004177c(int param_1)

{
  int iVar1;
  
  FUN_800433b0();
  iVar1 = 0;
  if (0 < param_1 + 1) {
    do {
      iVar1 = iVar1 + 1;
      FUN_8003ee58();
      FUN_8003ee58();
    } while (iVar1 < param_1 + 1);
  }
  return;
}



// ---- FUN_800417d0 @ 800417d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800417d0(int param_1)

{
  int iVar1;
  
  _DAT_800ab5d8 = _DAT_800ab5d8 + 3;
  iVar1 = 0;
  if (0 < param_1 + 2) {
    do {
      _DAT_800ab5d8 = _DAT_800ab5d8 + 1;
      iVar1 = iVar1 + 1;
      FUN_8003ee58();
    } while (iVar1 < param_1 + 2);
  }
  return;
}



// ---- FUN_80041844 @ 80041844

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80041844(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < param_1 + 2) {
    do {
      _DAT_800ab5d8 = _DAT_800ab5d8 + 1;
      iVar1 = iVar1 + 1;
      FUN_8003ee58();
    } while (iVar1 < param_1 + 2);
  }
  return;
}



// ---- FUN_800418a4 @ 800418a4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800418a4(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  _DAT_800ab5d8 = _DAT_800ab5d8 + 1;
  FUN_8003f7fc(param_1 << 8 | (uint)*pbVar1);
  return;
}



// ---- FUN_800418ec @ 800418ec

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800418ec(int param_1)

{
  uint uVar1;
  
  if (param_1 < 0) {
    uVar1 = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    _DAT_800ab5d8 = _DAT_800ab5d8 + 1;
  }
  else {
    uVar1 = param_1 + 1;
  }
  _DAT_800ab5d8 = uVar1 * 3 + _DAT_800ab5d8;
  FUN_800433b0();
  return;
}



// ---- FUN_8004195c @ 8004195c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8004195c(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  _DAT_800b03c8 = _DAT_800b03c8 + 1;
  iVar3 = _DAT_800b03c8 * 0x144;
  *(undefined1 *)(iVar3 + -0x7ff5365c) = DAT_800b0620;
  uVar2 = _DAT_800ab5d8;
  *(undefined1 *)(iVar3 + -0x7ff53659) = 0;
  *(undefined1 *)(iVar3 + -0x7ff5365a) = 0;
  iVar4 = FUN_80041da4();
  cVar1 = *(char *)(iVar3 + -0x7ff5365b);
  while (((cVar1 != '\0' && (iVar4 < 0)) && (iVar4 = FUN_80041a4c(), iVar4 < 0))) {
    *(undefined1 *)(iVar3 + -0x7ff53659) = 0;
    *(undefined1 *)(iVar3 + -0x7ff5365a) = 0;
    _DAT_800ab5d8 = uVar2;
    *(undefined1 *)(iVar3 + -0x7ff5365b) = 2;
    iVar4 = FUN_80041da4();
    cVar1 = *(char *)(iVar3 + -0x7ff5365b);
  }
  _DAT_800b03c8 = _DAT_800b03c8 + -1;
  return;
}



// ---- FUN_80041a4c @ 80041a4c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80041a4c(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  if (_DAT_800b03c8 != 0) {
    iVar8 = _DAT_800b03c8 + -1;
    if (-1 < iVar8) {
      iVar9 = iVar8 * 0x144;
      do {
        iVar7 = *(byte *)(iVar9 + -0x7ff53659) - 1;
        if (-1 < iVar7) {
          iVar4 = iVar7 * 8 + iVar9 + -0x7ff5369c;
          do {
            _DAT_800b0620 = (uint)*(byte *)(iVar9 + -0x7ff5365c) + *(int *)(iVar4 + 200);
            iVar1 = FUN_8003fb14(*(undefined4 *)(iVar4 + 0xc4));
            iVar7 = iVar7 + -1;
            if (-1 < iVar1) {
              return iVar1;
            }
            iVar4 = iVar4 + -8;
          } while (-1 < iVar7);
        }
        iVar8 = iVar8 + -1;
        iVar9 = iVar9 + -0x144;
      } while (-1 < iVar8);
    }
    _DAT_800b0620 = 1;
    iVar8 = 0;
    if (0 < _DAT_800b03c8) {
      iVar9 = 0;
      do {
        puVar6 = (undefined4 *)(iVar9 + -0x7ff5369c);
        iVar7 = 0;
        if (*(char *)(iVar9 + -0x7ff5365a) != '\0') {
          puVar5 = puVar6;
          do {
            iVar4 = 0;
            if (0 < (int)puVar5[0x12]) {
              puVar3 = puVar6;
              do {
                *(undefined4 *)(&DAT_800affc8 + ((uint)*(byte *)(iVar9 + -0x7ff5365c) + iVar4) * 4)
                     = *puVar3;
                iVar4 = iVar4 + 1;
                puVar3 = puVar3 + 1;
              } while (iVar4 < (int)puVar5[0x12]);
            }
            _DAT_800b0620 = (uint)*(byte *)(iVar9 + -0x7ff5365c) + puVar5[0x12];
            iVar4 = FUN_8003fb14(puVar5[0x11]);
            iVar7 = iVar7 + 1;
            if (-1 < iVar4) {
              return iVar4;
            }
            puVar5 = puVar5 + 2;
          } while (iVar7 < (int)(uint)*(byte *)(iVar9 + -0x7ff5365a));
        }
        uVar2 = (uint)*(byte *)(iVar9 + -0x7ff5365c);
        iVar7 = 0;
        if (0 < (int)(*(byte *)(iVar9 + -0x7ff53518) - uVar2)) {
          do {
            *(undefined4 *)(&DAT_800affc8 + (uVar2 + iVar7) * 4) = *puVar6;
            uVar2 = (uint)*(byte *)(iVar9 + -0x7ff5365c);
            iVar7 = iVar7 + 1;
            puVar6 = puVar6 + 1;
          } while (iVar7 < (int)(*(byte *)(iVar9 + -0x7ff53518) - uVar2));
        }
        iVar8 = iVar8 + 1;
        _DAT_800b0620 = (uint)*(byte *)(iVar9 + -0x7ff53518);
        iVar9 = iVar9 + 0x144;
      } while (iVar8 < _DAT_800b03c8);
    }
  }
  return -1;
}



// ---- FUN_80041c5c @ 80041c5c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80041c5c(uint param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar3 = _DAT_800ab5d8;
  uVar2 = _DAT_800ab578;
  FUN_8003f2dc((int)param_1 >> 0xf);
  _DAT_800ab5d8 = param_1 & 0x7fff;
  _DAT_800b03c8 = _DAT_800b03c8 + 1;
  iVar5 = _DAT_800b03c8 * 0x144;
  *(undefined1 *)(iVar5 + -0x7ff5365c) = DAT_800b0620;
  uVar4 = _DAT_800ab5d8;
  *(undefined1 *)(iVar5 + -0x7ff53659) = 0;
  *(undefined1 *)(iVar5 + -0x7ff5365a) = 0;
  iVar6 = FUN_80041da4();
  cVar1 = *(char *)(iVar5 + -0x7ff5365b);
  while (((cVar1 != '\0' && (iVar6 < 0)) && (iVar6 = FUN_80041a4c(), iVar6 < 0))) {
    *(undefined1 *)(iVar5 + -0x7ff53659) = 0;
    *(undefined1 *)(iVar5 + -0x7ff5365a) = 0;
    _DAT_800ab5d8 = uVar4;
    *(undefined1 *)(iVar5 + -0x7ff5365b) = 2;
    iVar6 = FUN_80041da4();
    cVar1 = *(char *)(iVar5 + -0x7ff5365b);
  }
  _DAT_800b03c8 = _DAT_800b03c8 + -1;
  FUN_8003f2dc(uVar2);
  _DAT_800ab5d8 = uVar3;
  return iVar6;
}



// ---- FUN_80041da4 @ 80041da4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80041da4(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = _DAT_800ab5d8 + 1;
  bVar1 = *(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  _DAT_800ab5d8 = uVar3;
  if (bVar1 == 10) {
LAB_80041fdc:
    iVar2 = -1;
  }
  else {
    if (bVar1 != 9) {
      if ((bVar1 & 0x20) != 0) {
        iVar2 = _DAT_800b03c8 * 0x144;
        *(uint *)(iVar2 + -0x7ff5369c + (uint)*(byte *)(iVar2 + -0x7ff5365a) * 8 + 0x44) =
             _DAT_800ab578 << 0xf | uVar3;
        *(uint *)(iVar2 + -0x7ff5369c + (uint)*(byte *)(iVar2 + -0x7ff5365a) * 8 + 0x48) =
             _DAT_800b0620 - (uint)*(byte *)(iVar2 + -0x7ff5365c);
        *(char *)(iVar2 + -0x7ff5365a) = *(char *)(iVar2 + -0x7ff5365a) + '\x01';
        iVar2 = FUN_8003f870(*(char *)(iVar2 + -0x7ff5365b) != '\x02');
        if (-1 < iVar2) {
          return iVar2;
        }
      }
      uVar3 = _DAT_800ab5d8;
      if ((bVar1 & 0x10) != 0) {
        iVar2 = _DAT_800b03c8 * 0x144;
        FUN_80042124(bVar1);
        *(uint *)(iVar2 + -0x7ff5369c + (uint)*(byte *)(iVar2 + -0x7ff53659) * 8 + 0xc4) =
             _DAT_800ab578 << 0xf | _DAT_800ab5d8;
        *(uint *)(iVar2 + -0x7ff5369c + (uint)*(byte *)(iVar2 + -0x7ff53659) * 8 + 200) =
             _DAT_800b0620 - (uint)*(byte *)(iVar2 + -0x7ff5365c);
        *(char *)(iVar2 + -0x7ff53659) = *(char *)(iVar2 + -0x7ff53659) + '\x01';
      }
      _DAT_800ab5d8 = uVar3;
      switch(bVar1 & 0xf) {
      case 0:
      case 1:
      case 2:
      case 3:
        iVar2 = FUN_800421f0(bVar1 & 3);
        break;
      default:
        iVar2 = -1;
        break;
      case 8:
        iVar2 = FUN_80043564();
        break;
      case 0xc:
        iVar2 = FUN_80042308();
        break;
      case 0xd:
        iVar2 = FUN_800425d0();
        break;
      case 0xe:
        iVar2 = FUN_800426e0();
        break;
      case 0xf:
        iVar2 = FUN_80042850();
      }
      if (iVar2 == -2) {
        if ((bVar1 & 0x10) == 0) {
          return -2;
        }
        FUN_8003ee58();
        return -2;
      }
      if (iVar2 != -1) {
        return iVar2;
      }
      if ((bVar1 & 0x10) == 0) goto LAB_80041fdc;
    }
    iVar2 = FUN_8003f870(0);
  }
  return iVar2;
}



// ---- FUN_80042028 @ 80042028

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80042028(uint param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = _DAT_800ab5d8;
  uVar1 = _DAT_800ab578;
  FUN_8003f2dc((int)param_1 >> 0xf);
  _DAT_800ab5d8 = param_1 & 0x7fff;
  uVar3 = FUN_80041da4();
  FUN_8003f2dc(uVar1);
  _DAT_800ab5d8 = uVar2;
  return uVar3;
}



// ---- FUN_800420a0 @ 800420a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800420a0(void)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = _DAT_800ab5d8 + 1;
  bVar1 = *(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  _DAT_800ab5d8 = iVar2;
  if (bVar1 != 10) {
    if (bVar1 != 9) {
      if ((bVar1 & 0x20) != 0) {
        FUN_8003ee58();
      }
      FUN_80042124(bVar1);
      if ((bVar1 & 0x10) == 0) {
        return;
      }
    }
    FUN_8003ee58();
  }
  return;
}



// ---- FUN_80042124 @ 80042124

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80042124(uint param_1)

{
  switch(param_1 & 0xf) {
  case 0:
    _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
    break;
  case 1:
    _DAT_800ab5d8 = _DAT_800ab5d8 + 3;
    break;
  case 2:
    _DAT_800ab5d8 = _DAT_800ab5d8 + 4;
    break;
  case 3:
    _DAT_800ab5d8 = _DAT_800ab5d8 + 5;
    break;
  case 8:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    FUN_8003ee58();
  }
  return;
}



// ---- FUN_800421f0 @ 800421f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800421f0(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  byte *pbVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  
  uVar2 = FUN_8003ec7c(param_1 & 1);
  uVar1 = _DAT_800aeeac;
  uVar6 = 0;
  if ((param_1 & 2) != 0) {
    iVar5 = _DAT_800ab5d8 + 1;
    pbVar3 = (byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
    _DAT_800abfec = (uint)*pbVar3;
    _DAT_800aeeac = FUN_8003eed8(CONCAT11(*pbVar3,*(undefined1 *)(_DAT_800abff0 + iVar5)));
    uVar6 = uVar1;
  }
  FUN_8003ec28(uVar2);
  iVar5 = _DAT_800ab5d8;
  uVar1 = _DAT_800ab578;
  FUN_8003f2dc((int)uVar2 >> 0xf);
  _DAT_800ab5d8 = uVar2 & 0x7fff;
  uVar4 = FUN_80041da4();
  FUN_8003f2dc(uVar1);
  _DAT_800ab5d8 = iVar5;
  FUN_8003ec5c();
  if ((param_1 & 2) != 0) {
    _DAT_800aeeac = uVar6;
  }
  return uVar4;
}



// ---- FUN_80042308 @ 80042308

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80042308(void)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  uVar4 = _DAT_800abfec;
  iVar5 = _DAT_800ab5d8 + 1;
  if (0xbf < _DAT_800abfec) {
    uVar4 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
    iVar5 = _DAT_800ab5d8 + 2;
  }
  _DAT_800ab5d8 = iVar5;
  iVar5 = uVar4 + _DAT_800ab5d8;
joined_r0x8004238c:
  do {
    if ((iVar5 <= _DAT_800ab5d8) || (iVar2 = FUN_800429b0(), iVar2 != 0)) {
      uVar3 = 0xffffffff;
      if (_DAT_800ab5d8 != iVar5) {
        uVar3 = FUN_80041da4();
        _DAT_800ab5d8 = iVar5;
      }
      return uVar3;
    }
    iVar2 = _DAT_800ab5d8 + 1;
    bVar1 = *(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    _DAT_800ab5d8 = iVar2;
  } while (bVar1 == 10);
  if (bVar1 != 9) goto code_r0x800423e0;
  goto LAB_80042404;
code_r0x800423e0:
  if ((bVar1 & 0x20) != 0) {
    FUN_8003ee58();
  }
  FUN_80042124(bVar1);
  if ((bVar1 & 0x10) != 0) {
LAB_80042404:
    FUN_8003ee58();
  }
  goto joined_r0x8004238c;
}



// ---- FUN_80042464 @ 80042464

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80042464(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  uVar4 = _DAT_800abfec;
  iVar5 = _DAT_800ab5d8 + 1;
  if (0xbf < _DAT_800abfec) {
    uVar4 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
    iVar5 = _DAT_800ab5d8 + 2;
  }
  _DAT_800ab5d8 = iVar5;
  if (uVar4 == 0) {
    uVar2 = FUN_80041da4();
  }
  else {
    iVar5 = uVar4 + _DAT_800ab5d8;
    do {
      if (iVar5 <= _DAT_800ab5d8) {
        iVar5 = _DAT_800ab5d8 + 1;
        bVar1 = *(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
        _DAT_800ab5d8 = iVar5;
        if (bVar1 != 10) {
          if (bVar1 != 9) {
            if ((bVar1 & 0x20) != 0) {
              FUN_8003ee58();
            }
            FUN_80042124(bVar1);
            if ((bVar1 & 0x10) == 0) {
              return 0xffffff9d;
            }
          }
          FUN_8003ee58();
        }
        return 0xffffff9d;
      }
      iVar3 = FUN_800429b0();
    } while (iVar3 != param_1);
    _DAT_800ab5d8 = iVar5;
    uVar2 = FUN_80041da4();
  }
  return uVar2;
}



// ---- FUN_800425d0 @ 800425d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_800425d0(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = _DAT_800ab5d8 + 1;
  _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  iVar4 = -1;
  if (_DAT_800abfec < 0xc0) {
    uVar3 = _DAT_800abfec;
    _DAT_800ab5d8 = iVar2;
  }
  else {
    _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
    uVar3 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + iVar2);
  }
  iVar2 = uVar3 + _DAT_800ab5d8;
  uVar1 = FUN_800429b0();
  do {
    if (iVar2 <= _DAT_800ab5d8) break;
    iVar4 = FUN_80042464(uVar1);
  } while (iVar4 == -99);
  _DAT_800ab5d8 = iVar2;
  iVar2 = -1;
  if (iVar4 != -99) {
    iVar2 = iVar4;
  }
  return iVar2;
}



// ---- FUN_800426e0 @ 800426e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800426e0(void)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = _DAT_800ab5d8 + 1;
  _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
  if (_DAT_800abfec < 0xc0) {
    uVar3 = _DAT_800abfec;
    _DAT_800ab5d8 = iVar6;
  }
  else {
    uVar3 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + iVar6);
  }
  iVar6 = uVar3 + _DAT_800ab5d8;
  uVar2 = FUN_8003ed68();
  uVar3 = FUN_8003ef90(uVar2);
  FUN_8003f10c(uVar2,uVar3 + 1);
LAB_80042818:
  do {
    iVar5 = _DAT_800ab5d8 + 1;
    if (iVar6 <= _DAT_800ab5d8) {
      return 0xffffffff;
    }
    pbVar4 = (byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
    if (uVar3 <= *pbVar4) {
      _DAT_800ab5d8 = iVar5;
      uVar2 = FUN_80041da4();
      _DAT_800ab5d8 = iVar6;
      return uVar2;
    }
    bVar1 = *(byte *)(_DAT_800abff0 + iVar5);
  } while (bVar1 == 10);
  if (bVar1 != 9) goto code_r0x800427ec;
  goto LAB_80042810;
code_r0x800427ec:
  if ((bVar1 & 0x20) != 0) {
    FUN_8003ee58();
  }
  FUN_80042124(bVar1);
  if ((bVar1 & 0x10) != 0) {
LAB_80042810:
    FUN_8003ee58();
  }
  goto LAB_80042818;
}



// ---- FUN_80042850 @ 80042850

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80042850(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar3 = FUN_8003dc2c();
  _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  uVar6 = _DAT_800abfec;
  iVar2 = _DAT_800ab5d8 + 1;
  if (0xbf < _DAT_800abfec) {
    uVar6 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
    iVar2 = _DAT_800ab5d8 + 2;
  }
  _DAT_800ab5d8 = iVar2;
  iVar7 = uVar6 + _DAT_800ab5d8;
  iVar2 = _DAT_800ab5d8;
joined_r0x800428f8:
  do {
    if (iVar7 <= iVar2) {
      _DAT_800ab5d8 = iVar2;
      return 0xffffffff;
    }
    _DAT_800ab5d8 = iVar2 + 1;
    iVar5 = iVar2 + 2;
    if (iVar3 <= (int)(uint)*(byte *)(_DAT_800abff0 + iVar2)) {
      uVar4 = FUN_80041da4();
      _DAT_800ab5d8 = iVar7;
      return uVar4;
    }
    bVar1 = *(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    iVar2 = iVar5;
  } while (bVar1 == 10);
  _DAT_800ab5d8 = iVar5;
  if (bVar1 != 9) goto code_r0x80042950;
  goto LAB_80042974;
code_r0x80042950:
  if ((bVar1 & 0x20) != 0) {
    FUN_8003ee58();
  }
  FUN_80042124(bVar1);
  iVar2 = _DAT_800ab5d8;
  if ((bVar1 & 0x10) != 0) {
LAB_80042974:
    FUN_8003ee58();
    iVar2 = _DAT_800ab5d8;
  }
  goto joined_r0x800428f8;
}



// ---- FUN_800429b0 @ 800429b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_800429b0(void)

{
  byte bVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar8 = _DAT_800ab5d8 + 1;
  uVar6 = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  if ((*(byte *)(_DAT_800abff0 + _DAT_800ab5d8) & 0x80) == 0) {
    uVar6 = FUN_8003ede4();
    return uVar6;
  }
  uVar5 = uVar6 & 0xf0;
  if ((uVar6 & 0xe0) == 0x80) {
    uVar3 = FUN_8003ed68();
    uVar6 = FUN_8003ef90(uVar3);
    return uVar6;
  }
  if (uVar5 == 0xb0) {
LAB_80042a78:
    _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
    bVar1 = *(byte *)(_DAT_800abff0 + iVar8);
    uVar6 = uVar6 & 0xf;
LAB_80042c3c:
    uVar5 = (uint)bVar1;
    uVar6 = uVar6 << 8;
    goto LAB_80042c40;
  }
  if (uVar5 < 0xb1) {
    if (uVar5 == 0xa0) goto LAB_80042a78;
  }
  else {
    if (uVar5 == 0xc0) {
      _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
      uVar6 = FUN_8003f31c((uVar6 & 0xf) << 8 | (uint)*(byte *)(_DAT_800abff0 + iVar8));
      return uVar6;
    }
    if (uVar5 == 0xd0) {
      _DAT_800ab5d8 = iVar8;
      return uVar6 & 0xf;
    }
  }
  switch(uVar6) {
  case 0xe0:
    _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
    uVar6 = (uint)*(byte *)(_DAT_800abff0 + iVar8);
    break;
  case 0xe1:
    iVar4 = _DAT_800ab5d8 + 2;
    _DAT_800ab5d8 = _DAT_800ab5d8 + 3;
    _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + iVar8);
    uVar5 = (uint)*(byte *)(_DAT_800abff0 + iVar4);
    uVar6 = _DAT_800abfec << 8;
    goto LAB_80042c40;
  case 0xe2:
  case 0xe4:
    iVar4 = _DAT_800ab5d8 + 2;
    iVar7 = _DAT_800ab5d8 + 3;
    iVar9 = _DAT_800ab5d8 + 4;
    _DAT_800ab5d8 = _DAT_800ab5d8 + 5;
    uVar6 = (uint)CONCAT21(CONCAT11(*(undefined1 *)(_DAT_800abff0 + iVar8),
                                    *(undefined1 *)(_DAT_800abff0 + iVar4)),
                           *(undefined1 *)(_DAT_800abff0 + iVar7));
    bVar1 = *(byte *)(_DAT_800abff0 + iVar9);
    _DAT_800abfec = uVar6;
    goto LAB_80042c3c;
  case 0xe3:
    iVar4 = _DAT_800ab5d8 + 2;
    _DAT_800ab5d8 = _DAT_800ab5d8 + 3;
    _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + iVar8);
    uVar5 = (uint)*(byte *)(_DAT_800abff0 + iVar4);
    uVar6 = _DAT_800abfec << 8;
LAB_80042c40:
    uVar6 = uVar6 | uVar5;
    break;
  case 0xe5:
    _DAT_800ab5d8 = iVar8;
    uVar6 = FUN_80043178(0xffffffff);
    break;
  case 0xe6:
    _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
    uVar6 = FUN_80043178(*(undefined1 *)(_DAT_800abff0 + iVar8));
    break;
  case 0xe7:
    _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
    uVar6 = FUN_80043234(*(undefined1 *)(_DAT_800abff0 + iVar8),0xffffffff);
    break;
  case 0xe8:
  case 0xe9:
    _DAT_800ab5d8 = iVar8;
    uVar6 = FUN_8003ec7c(uVar6 & 1);
    break;
  case 0xea:
  case 0xeb:
    _DAT_800ab5d8 = iVar8;
    uVar6 = FUN_8003ec7c(uVar6 & 1);
    uVar6 = FUN_80043178(uVar6 | 0x1000000);
    break;
  case 0xec:
  case 0xed:
    _DAT_800ab5d8 = iVar8;
    uVar3 = FUN_8003ec7c(uVar6 & 1);
    uVar6 = FUN_80043234(0xffffffff,uVar3);
    break;
  case 0xee:
  case 0xef:
    _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
    uVar2 = *(undefined1 *)(_DAT_800abff0 + iVar8);
    uVar3 = FUN_8003ec7c(uVar6 & 1);
    uVar6 = FUN_80043234(uVar2,uVar3);
    break;
  case 0xf0:
    _DAT_800ab5d8 = iVar8;
    uVar6 = FUN_8003ed68();
    break;
  case 0xf1:
    _DAT_800ab5d8 = iVar8;
    iVar8 = FUN_800429b0();
    uVar6 = (uint)(iVar8 == 0);
    break;
  case 0xf2:
    _DAT_800ab5d8 = iVar8;
    iVar8 = FUN_800429b0();
    iVar4 = FUN_800429b0();
    uVar6 = iVar8 * iVar4;
    break;
  case 0xf3:
    _DAT_800ab5d8 = iVar8;
    uVar6 = FUN_800429b0();
    uVar5 = FUN_800429b0();
    uVar6 = uVar6 / uVar5;
    if (uVar5 == 0) {
      trap(0x1c00);
    }
    break;
  case 0xf4:
    _DAT_800ab5d8 = iVar8;
    uVar6 = FUN_800429b0();
    uVar5 = FUN_800429b0();
    uVar6 = uVar6 % uVar5;
    if (uVar5 == 0) {
      trap(0x1c00);
    }
    break;
  case 0xf5:
    _DAT_800ab5d8 = iVar8;
    iVar8 = FUN_800429b0();
    iVar4 = FUN_800429b0();
    uVar6 = iVar8 + iVar4;
    break;
  case 0xf6:
    _DAT_800ab5d8 = iVar8;
    iVar8 = FUN_800429b0();
    iVar4 = FUN_800429b0();
    uVar6 = iVar8 - iVar4;
    break;
  case 0xf7:
    _DAT_800ab5d8 = iVar8;
    uVar6 = FUN_80042efc();
    break;
  case 0xf8:
    _DAT_800ab5d8 = iVar8;
    uVar6 = FUN_800429b0();
    uVar5 = FUN_800429b0();
    uVar6 = (uint)(uVar6 < uVar5);
    break;
  case 0xf9:
    _DAT_800ab5d8 = iVar8;
    uVar6 = FUN_800429b0();
    uVar5 = FUN_800429b0();
    uVar6 = (uint)(uVar5 < uVar6);
    break;
  case 0xfa:
    _DAT_800ab5d8 = iVar8;
    uVar6 = FUN_800429b0();
    uVar5 = FUN_800429b0();
    uVar6 = uVar5 < uVar6 ^ 1;
    break;
  case 0xfb:
    _DAT_800ab5d8 = iVar8;
    uVar6 = FUN_800429b0();
    uVar5 = FUN_800429b0();
    uVar6 = uVar6 < uVar5 ^ 1;
    break;
  case 0xfc:
    _DAT_800ab5d8 = iVar8;
    iVar8 = FUN_800429b0();
    iVar4 = FUN_800429b0();
    uVar6 = (uint)(iVar8 == iVar4);
    break;
  case 0xfd:
    _DAT_800ab5d8 = iVar8;
    iVar8 = FUN_800429b0();
    iVar4 = FUN_800429b0();
    uVar6 = (uint)(iVar8 != iVar4);
    break;
  case 0xfe:
    _DAT_800ab5d8 = iVar8;
    uVar6 = FUN_80042fc8();
    break;
  case 0xff:
    _DAT_800ab5d8 = iVar8;
    uVar6 = FUN_800430a0();
    break;
  default:
    uVar6 = 0;
    _DAT_800ab5d8 = iVar8;
  }
  return uVar6;
}



// ---- FUN_80042efc @ 80042efc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80042efc(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = _DAT_800ab5d8 + 1;
  _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  if (_DAT_800abfec < 0xc0) {
    uVar3 = _DAT_800abfec;
    _DAT_800ab5d8 = iVar2;
  }
  else {
    _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
    uVar3 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + iVar2);
  }
  iVar4 = uVar3 + _DAT_800ab5d8;
  iVar1 = 0;
  iVar2 = 0;
  if (_DAT_800ab5d8 < iVar4) {
    do {
      iVar1 = FUN_800429b0();
      iVar1 = iVar2 + iVar1;
      iVar2 = iVar1;
    } while (_DAT_800ab5d8 < iVar4);
  }
  return iVar1;
}



// ---- FUN_80042fc8 @ 80042fc8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80042fc8(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  uVar2 = _DAT_800abfec;
  iVar3 = _DAT_800ab5d8 + 1;
  if (0xbf < _DAT_800abfec) {
    uVar2 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
    iVar3 = _DAT_800ab5d8 + 2;
  }
  _DAT_800ab5d8 = iVar3;
  iVar3 = uVar2 + _DAT_800ab5d8;
  do {
    if (iVar3 <= _DAT_800ab5d8) {
      return 1;
    }
    iVar1 = FUN_800429b0();
  } while (iVar1 != 0);
  _DAT_800ab5d8 = iVar3;
  return 0;
}



// ---- FUN_800430a0 @ 800430a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800430a0(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  uVar2 = _DAT_800abfec;
  iVar3 = _DAT_800ab5d8 + 1;
  if (0xbf < _DAT_800abfec) {
    uVar2 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
    iVar3 = _DAT_800ab5d8 + 2;
  }
  _DAT_800ab5d8 = iVar3;
  iVar3 = uVar2 + _DAT_800ab5d8;
  do {
    if (iVar3 <= _DAT_800ab5d8) {
      return 0;
    }
    iVar1 = FUN_800429b0();
  } while (iVar1 == 0);
  _DAT_800ab5d8 = iVar3;
  return 1;
}



// ---- FUN_80043178 @ 80043178

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_80043178(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  
  if (-1 < (int)param_1) {
    if (0xffffff < (int)param_1) {
      uVar2 = _DAT_800b0620 - 1;
      if (-1 < (int)uVar2) {
        puVar1 = (uint *)(&DAT_800affc8 + uVar2 * 4);
        do {
          if (*puVar1 == (param_1 & 0x7fffff)) break;
          uVar2 = uVar2 - 1;
          puVar1 = puVar1 + -1;
        } while (-1 < (int)uVar2);
      }
      return ~uVar2 >> 0x1f;
    }
    if ((int)param_1 <= _DAT_800b0620 + -1) {
      return *(uint *)(&DAT_800affc8 + (_DAT_800b0620 - (param_1 + 1)) * 4);
    }
  }
  return _DAT_800affc8;
}



// ---- FUN_80043234 @ 80043234

void FUN_80043234(void)

{
  FUN_80043254();
  return;
}



// ---- FUN_80043254 @ 80043254

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_80043254(uint param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if ((int)param_1 < 0) {
    if (-1 < param_2) {
      iVar3 = _DAT_800ab5cc + -2;
      uVar4 = 1;
      if (iVar3 < 0) {
        iVar3 = _DAT_800ab5cc + 0x3e;
      }
      piVar1 = (int *)(&DAT_800afec8 + iVar3 * 4);
      while( true ) {
        if (*piVar1 < 0) {
          return 0;
        }
        iVar5 = iVar3 + -1;
        if (*piVar1 == param_2) break;
        piVar2 = piVar1 + -1;
        if (iVar5 < 0) {
          piVar2 = piVar1 + 0x3f;
          iVar5 = iVar3 + 0x3f;
        }
        uVar4 = uVar4 + 1;
        piVar1 = piVar2;
        iVar3 = iVar5;
        if (0x3f < uVar4) {
          return 0;
        }
      }
      return uVar4;
    }
  }
  else if (param_2 < 0) {
    if (0x3f < param_1) {
      return 0;
    }
    iVar3 = _DAT_800ab5cc - (param_1 + 1);
    if (iVar3 < 0) {
      iVar3 = iVar3 + 0x40;
    }
    if ((int)*(uint *)(&DAT_800afec8 + iVar3 * 4) < 0) {
      return 0;
    }
    return *(uint *)(&DAT_800afec8 + iVar3 * 4);
  }
  if (0x3f < param_1) {
    param_1 = 0x3f;
  }
  iVar3 = _DAT_800ab5cc + -2;
  if (iVar3 < 0) {
    iVar3 = _DAT_800ab5cc + 0x3e;
  }
  if (0 < (int)param_1) {
    piVar1 = (int *)(&DAT_800afec8 + iVar3 * 4);
    do {
      if (*piVar1 < 0) {
        return 0;
      }
      iVar3 = iVar3 + -1;
      if (*piVar1 == param_2) {
        return 1;
      }
      piVar1 = piVar1 + -1;
      if (iVar3 < 0) {
        piVar1 = (int *)&DAT_800affc4;
        iVar3 = 0x3f;
      }
      param_1 = param_1 - 1;
    } while (0 < (int)param_1);
  }
  return 0;
}



// ---- FUN_800433b0 @ 800433b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800433b0(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = _DAT_800ab5d8 + 1;
  uVar2 = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  if ((*(byte *)(_DAT_800abff0 + _DAT_800ab5d8) & 0x80) == 0) {
    _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
    return;
  }
  uVar1 = uVar2 & 0xf0;
  if ((uVar2 & 0xe0) == 0x80) {
    _DAT_800ab5d8 = _DAT_800ab5d8 + 3;
    return;
  }
  if (uVar1 == 0xb0) {
switchD_800434ac_caseD_e0:
    iVar3 = _DAT_800ab5d8 + 2;
  }
  else {
    if (uVar1 < 0xb1) {
      if (uVar1 == 0xa0) goto switchD_800434ac_caseD_e0;
    }
    else {
      if (uVar1 == 0xc0) {
        _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
        FUN_8003f7fc((uVar2 & 0xf) << 8 | (uint)*(byte *)(_DAT_800abff0 + iVar3));
        return;
      }
      if (uVar1 == 0xd0) {
        _DAT_800ab5d8 = iVar3;
        return;
      }
    }
    switch(uVar2) {
    case 0xe0:
    case 0xe6:
    case 0xe7:
      goto switchD_800434ac_caseD_e0;
    case 0xe1:
    case 0xe3:
    case 0xe8:
    case 0xea:
    case 0xec:
      iVar3 = _DAT_800ab5d8 + 3;
      break;
    case 0xe2:
    case 0xe4:
    case 0xef:
      iVar3 = _DAT_800ab5d8 + 5;
      break;
    case 0xe9:
    case 0xeb:
    case 0xed:
    case 0xee:
    case 0xf0:
      iVar3 = _DAT_800ab5d8 + 4;
      break;
    case 0xf2:
    case 0xf3:
    case 0xf4:
    case 0xf5:
    case 0xf6:
    case 0xf8:
    case 0xf9:
    case 0xfa:
    case 0xfb:
    case 0xfc:
    case 0xfd:
      _DAT_800ab5d8 = iVar3;
      FUN_800433b0();
      iVar3 = _DAT_800ab5d8;
    case 0xf1:
      _DAT_800ab5d8 = iVar3;
      FUN_800433b0();
      iVar3 = _DAT_800ab5d8;
      break;
    case 0xf7:
    case 0xfe:
    case 0xff:
      _DAT_800ab5d8 = iVar3;
      FUN_8003ee58();
      iVar3 = _DAT_800ab5d8;
    }
  }
  _DAT_800ab5d8 = iVar3;
  return;
}



// ---- FUN_80043564 @ 80043564

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80043564(void)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  
  uVar2 = _DAT_800ab5d8;
  do {
    _DAT_800abf60 = 0;
    _DAT_800abf5c = 0;
    _DAT_800adda4 = _DAT_800b0620;
    _DAT_800ab5d8 = uVar2;
    FUN_80043a58();
    if (_DAT_800abf60 == 0) {
      return -1;
    }
    if (*(char *)(_DAT_800b03c8 * 0x144 + -0x7ff5365b) == '\0') {
      iVar3 = FUN_8003d924();
      if (iVar3 < 0) {
        return -2;
      }
    }
    else {
      do {
        iVar3 = FUN_8003d924();
      } while (iVar3 < 0);
    }
    iVar4 = _DAT_800b03c8 * 0x144;
    iVar9 = _DAT_800adda4 - (uint)*(byte *)(iVar4 + -0x7ff5365c);
    uVar7 = 0;
    if (0 < iVar9) {
      puVar6 = (undefined4 *)(iVar4 + -0x7ff5369c);
      do {
        iVar5 = *(byte *)(iVar4 + -0x7ff5365c) + uVar7;
        uVar7 = uVar7 + 1;
        *puVar6 = *(undefined4 *)(&DAT_800affc8 + iVar5 * 4);
        puVar6 = puVar6 + 1;
      } while ((int)uVar7 < iVar9);
    }
    if (uVar7 < 0x10) {
      piVar8 = (undefined4 *)(iVar4 + -0x7ff5369c) + uVar7;
      do {
        iVar5 = *(int *)((uVar7 - iVar9) * 4 + iVar3 * 0x40 + -0x7ff52240);
        bVar1 = *(byte *)(iVar4 + -0x7ff5365c);
        *piVar8 = iVar5;
        *(int *)(&DAT_800affc8 + (bVar1 + uVar7) * 4) = iVar5;
        if (*piVar8 < 0) break;
        uVar7 = uVar7 + 1;
        piVar8 = piVar8 + 1;
      } while (uVar7 < 0x10);
    }
    iVar9 = _DAT_800adda4;
    _DAT_800b0620 = *(byte *)(iVar4 + -0x7ff5365c) + uVar7;
    iVar3 = FUN_80041c5c(*(undefined4 *)(iVar3 * 4 + -0x7ff51a10));
    _DAT_800b0620 = iVar9;
    if (iVar3 != -2) {
      return iVar3;
    }
  } while( true );
}



// ---- FUN_80043790 @ 80043790

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80043790(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  
  FUN_80058624(param_1 + _DAT_800ab5a4);
  iVar2 = _DAT_800abf60 * 0x40;
  param_1 = param_1 + _DAT_800ab5a4;
  *(int *)(iVar2 + -0x7ff51990) = param_1;
  FUN_80058644(iVar2 + -0x7ff51990,param_1);
  iVar1 = _DAT_800adda4;
  iVar2 = _DAT_800abf60;
  uVar4 = _DAT_800b0620 - _DAT_800adda4;
  *(uint *)(_DAT_800abf60 * 4 + -0x7ff51a10) = _DAT_800ab578 << 0xf | _DAT_800ab5d8;
  iVar5 = 0;
  if (0 < (int)uVar4) {
    puVar3 = (undefined4 *)(iVar2 * 0x40 + -0x7ff52240);
    do {
      iVar2 = iVar5 + iVar1;
      iVar5 = iVar5 + 1;
      *puVar3 = *(undefined4 *)(&DAT_800affc8 + iVar2 * 4);
      puVar3 = puVar3 + 1;
    } while (iVar5 < (int)uVar4);
  }
  if (uVar4 < 0x10) {
    *(undefined4 *)(uVar4 * 4 + _DAT_800abf60 * 0x40 + -0x7ff52240) = 0xffffffff;
  }
  _DAT_800aee9c = 0;
  _DAT_800abf60 = _DAT_800abf60 + 1;
  return;
}



// ---- FUN_800438e0 @ 800438e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800438e0(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  uint uVar7;
  int iVar8;
  
  iVar8 = _DAT_800abf5c;
  uVar7 = 0;
  puVar6 = (undefined2 *)&DAT_800b04ec;
  puVar4 = (undefined2 *)(_DAT_800abf60 * 0x40 + -0x7ff51990);
  do {
    if (iVar8 <= (int)uVar7) break;
    uVar1 = *puVar6;
    puVar6 = puVar6 + 1;
    uVar7 = uVar7 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
  } while (uVar7 < 0x20);
  iVar8 = 0;
  if (uVar7 < 0x20) {
    *(undefined2 *)(uVar7 * 2 + _DAT_800abf60 * 0x40 + -0x7ff51990) = 0xffff;
  }
  iVar2 = _DAT_800adda4;
  iVar3 = _DAT_800abf60;
  uVar7 = _DAT_800b0620 - _DAT_800adda4;
  *(uint *)(_DAT_800abf60 * 4 + -0x7ff51a10) = _DAT_800ab578 << 0xf | _DAT_800ab5d8;
  if (0 < (int)uVar7) {
    puVar5 = (undefined4 *)(iVar3 * 0x40 + -0x7ff52240);
    do {
      iVar3 = iVar8 + iVar2;
      iVar8 = iVar8 + 1;
      *puVar5 = *(undefined4 *)(&DAT_800affc8 + iVar3 * 4);
      puVar5 = puVar5 + 1;
    } while (iVar8 < (int)uVar7);
  }
  if (uVar7 < 0x10) {
    *(undefined4 *)(uVar7 * 4 + _DAT_800abf60 * 0x40 + -0x7ff52240) = 0xffffffff;
  }
  _DAT_800aee9c = 1;
  _DAT_800abf60 = _DAT_800abf60 + 1;
  return;
}



// ---- FUN_80043a58 @ 80043a58

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80043a58(void)

{
  uint uVar1;
  int iVar2;
  
  _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  uVar1 = _DAT_800abfec;
  iVar2 = _DAT_800ab5d8 + 1;
  if (0xbf < _DAT_800abfec) {
    uVar1 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
    iVar2 = _DAT_800ab5d8 + 2;
  }
  _DAT_800ab5d8 = iVar2;
  iVar2 = uVar1 + _DAT_800ab5d8;
  while (_DAT_800ab5d8 < iVar2) {
    FUN_80043b10();
  }
  return;
}



// ---- FUN_80043b10 @ 80043b10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80043b10(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  if ((*(byte *)(_DAT_800abff0 + _DAT_800ab5d8) & 0x80) == 0) {
    uVar1 = FUN_8003ede4();
    FUN_80043790(uVar1);
    FUN_800420a0();
    return;
  }
  iVar2 = _DAT_800ab5d8 + 1;
  if ((uVar3 & 0xc0) == 0x80) {
    FUN_80043cd8(1);
    return;
  }
  switch(uVar3 & 0xf8) {
  case 0xc0:
  case 200:
    _DAT_800ab5d8 = iVar2;
    FUN_80043e68(uVar3 & 0xf);
    iVar2 = _DAT_800ab5d8;
    break;
  case 0xd0:
  case 0xd8:
    _DAT_800ab5d8 = iVar2;
    FUN_800443dc(uVar3 & 0xf);
    iVar2 = _DAT_800ab5d8;
    break;
  case 0xe0:
    _DAT_800ab5d8 = iVar2;
    FUN_80044544(uVar3 & 7);
    iVar2 = _DAT_800ab5d8;
    break;
  case 0xe8:
    uVar3 = uVar3 & 7;
LAB_80043cc0:
    _DAT_800ab5d8 = iVar2;
    FUN_80044838(uVar3);
    iVar2 = _DAT_800ab5d8;
    break;
  default:
    if ((uVar3 & 0xfc) == 0xf0) {
      _DAT_800ab5d8 = iVar2;
      FUN_80043cd8((uVar3 & 3) + 2);
      return;
    }
    switch(uVar3) {
    case 0xf4:
    case 0xf5:
    case 0xf6:
    case 0xf7:
      _DAT_800ab5d8 = iVar2;
      FUN_80043d98(uVar3 & 3);
      iVar2 = _DAT_800ab5d8;
      break;
    case 0xf8:
      _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
      FUN_80043cd8(*(undefined1 *)(_DAT_800abff0 + iVar2));
      iVar2 = _DAT_800ab5d8;
      break;
    case 0xfb:
      _DAT_800ab5d8 = iVar2;
      FUN_80043e68(0xfffffffe);
      iVar2 = _DAT_800ab5d8;
      break;
    case 0xfc:
      _DAT_800ab5d8 = iVar2;
      FUN_80043e68(0xffffffff);
      iVar2 = _DAT_800ab5d8;
      break;
    case 0xfd:
      _DAT_800ab5d8 = iVar2;
      FUN_800443dc(0xffffffff);
      iVar2 = _DAT_800ab5d8;
      break;
    case 0xfe:
      _DAT_800ab5d8 = iVar2;
      FUN_80044544(0xffffffff);
      iVar2 = _DAT_800ab5d8;
      break;
    case 0xff:
      uVar3 = 0xffffffff;
      goto LAB_80043cc0;
    }
  }
  _DAT_800ab5d8 = iVar2;
  return;
}



// ---- FUN_80043cd8 @ 80043cd8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80043cd8(int param_1)

{
  bool bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  
  if (0 < param_1) {
    iVar4 = 1;
    do {
      iVar3 = _DAT_800ab5d8 + 1;
      pbVar2 = (byte *)(_DAT_800abff0 + _DAT_800ab5d8);
      _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
      _DAT_800abfec = (uint)*pbVar2;
      FUN_80044cd0(CONCAT11(*pbVar2,*(undefined1 *)(_DAT_800abff0 + iVar3)) & 0x3fff);
      bVar1 = iVar4 < param_1;
      iVar4 = iVar4 + 1;
    } while (bVar1);
  }
  iVar4 = 0;
  FUN_800438e0();
  if (0 < param_1) {
    do {
      iVar4 = iVar4 + 1;
      FUN_80044d04();
    } while (iVar4 < param_1);
  }
  FUN_800420a0();
  return;
}



// ---- FUN_80043d98 @ 80043d98

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80043d98(uint param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar2 = FUN_8003ec7c(param_1 & 1);
  uVar1 = _DAT_800aeeac;
  uVar5 = 0;
  if ((param_1 & 2) != 0) {
    iVar4 = _DAT_800ab5d8 + 1;
    pbVar3 = (byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
    _DAT_800abfec = (uint)*pbVar3;
    _DAT_800aeeac = FUN_8003eed8(CONCAT11(*pbVar3,*(undefined1 *)(_DAT_800abff0 + iVar4)));
    uVar5 = uVar1;
  }
  FUN_8003ec28(uVar2);
  FUN_80044af4(uVar2);
  FUN_8003ec5c();
  if ((param_1 & 2) != 0) {
    _DAT_800aeeac = uVar5;
  }
  return;
}



// ---- FUN_80043e68 @ 80043e68

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80043e68(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 < 0) {
    if (param_1 == -1) {
      _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
      uVar3 = _DAT_800abfec;
      iVar2 = _DAT_800ab5d8 + 1;
      if (0xbf < _DAT_800abfec) {
        uVar3 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
        iVar2 = _DAT_800ab5d8 + 2;
      }
      _DAT_800ab5d8 = iVar2;
      iVar2 = uVar3 + _DAT_800ab5d8;
      while( true ) {
        if (iVar2 <= _DAT_800ab5d8) {
          return;
        }
        iVar1 = FUN_800429b0();
        if (iVar1 != 0) break;
        FUN_8003ee58();
      }
      _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
      uVar3 = _DAT_800abfec;
      iVar1 = _DAT_800ab5d8 + 1;
      if (0xbf < _DAT_800abfec) {
        uVar3 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
        iVar1 = _DAT_800ab5d8 + 2;
      }
      _DAT_800ab5d8 = iVar1;
      iVar1 = uVar3 + _DAT_800ab5d8;
      while (_DAT_800ab5d8 < iVar1) {
        FUN_80043b10();
      }
      _DAT_800ab5d8 = iVar2;
      return;
    }
    iVar2 = FUN_800429b0();
    if (iVar2 != 0) {
      _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
      uVar3 = _DAT_800abfec;
      iVar2 = _DAT_800ab5d8 + 1;
      if (0xbf < _DAT_800abfec) {
        uVar3 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
        iVar2 = _DAT_800ab5d8 + 2;
      }
      _DAT_800ab5d8 = iVar2;
      iVar2 = uVar3 + _DAT_800ab5d8;
      while (_DAT_800ab5d8 < iVar2) {
        FUN_80043b10();
      }
      return;
    }
  }
  else {
    param_1 = param_1 + 1;
    iVar2 = 0;
    if (0 < param_1) {
      do {
        iVar1 = FUN_800429b0();
        if (iVar1 != 0) break;
        iVar2 = iVar2 + 1;
        FUN_8003ee58();
      } while (iVar2 < param_1);
    }
    _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    uVar3 = _DAT_800abfec;
    iVar1 = _DAT_800ab5d8 + 1;
    if (0xbf < _DAT_800abfec) {
      uVar3 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
      iVar1 = _DAT_800ab5d8 + 2;
    }
    _DAT_800ab5d8 = iVar1;
    iVar1 = uVar3 + _DAT_800ab5d8;
    while (_DAT_800ab5d8 < iVar1) {
      FUN_80043b10();
    }
    if (param_1 <= iVar2) {
      return;
    }
    while (iVar2 = iVar2 + 1, iVar2 < param_1) {
      FUN_800433b0();
      FUN_8003ee58();
    }
  }
  FUN_8003ee58();
  return;
}



// ---- FUN_800441b8 @ 800441b8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800441b8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
  uVar3 = _DAT_800abfec;
  iVar4 = _DAT_800ab5d8 + 1;
  if (0xbf < _DAT_800abfec) {
    uVar3 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
    iVar4 = _DAT_800ab5d8 + 2;
  }
  _DAT_800ab5d8 = iVar4;
  if (uVar3 == 0) {
    _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    uVar3 = _DAT_800abfec;
    iVar4 = _DAT_800ab5d8 + 1;
    if (0xbf < _DAT_800abfec) {
      uVar3 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
      iVar4 = _DAT_800ab5d8 + 2;
    }
    _DAT_800ab5d8 = iVar4;
    iVar4 = uVar3 + _DAT_800ab5d8;
    while (uVar2 = 0xffffffff, _DAT_800ab5d8 < iVar4) {
      FUN_80043b10();
    }
  }
  else {
    iVar4 = uVar3 + _DAT_800ab5d8;
    if (_DAT_800ab5d8 < iVar4) {
      do {
        iVar1 = FUN_800429b0();
        if (iVar1 == param_1) {
          _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + iVar4);
          _DAT_800ab5d8 = iVar4 + 2;
          if (_DAT_800abfec < 0xc0) {
            uVar3 = _DAT_800abfec;
            _DAT_800ab5d8 = iVar4 + 1;
          }
          else {
            uVar3 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + iVar4 + 1);
          }
          iVar4 = uVar3 + _DAT_800ab5d8;
          while (_DAT_800ab5d8 < iVar4) {
            FUN_80043b10();
          }
          return 0xffffffff;
        }
      } while (_DAT_800ab5d8 < iVar4);
    }
    FUN_8003ee58();
    uVar2 = 0xffffff9d;
  }
  return uVar2;
}



// ---- FUN_800443dc @ 800443dc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800443dc(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 < 0) {
    iVar3 = _DAT_800ab5d8 + 1;
    _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
    if (_DAT_800abfec < 0xc0) {
      uVar4 = _DAT_800abfec;
      _DAT_800ab5d8 = iVar3;
    }
    else {
      uVar4 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + iVar3);
    }
    iVar3 = uVar4 + _DAT_800ab5d8;
    uVar1 = FUN_800429b0();
    do {
      if (iVar3 <= _DAT_800ab5d8) break;
      iVar2 = FUN_800441b8(uVar1);
    } while (iVar2 != -1);
    _DAT_800ab5d8 = iVar3;
  }
  else {
    param_1 = param_1 + 1;
    uVar1 = FUN_800429b0();
    iVar3 = 0;
    if (0 < param_1) {
      do {
        iVar2 = FUN_800441b8(uVar1);
        if (iVar2 == -1) break;
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_1);
    }
    while (iVar3 = iVar3 + 1, iVar3 < param_1) {
      FUN_8003ee58();
      FUN_8003ee58();
    }
  }
  return;
}



// ---- FUN_80044544 @ 80044544

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80044544(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 < 0) {
    iVar4 = _DAT_800ab5d8 + 1;
    _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    _DAT_800ab5d8 = _DAT_800ab5d8 + 2;
    if (_DAT_800abfec < 0xc0) {
      uVar2 = _DAT_800abfec;
      _DAT_800ab5d8 = iVar4;
    }
    else {
      uVar2 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + iVar4);
    }
    iVar4 = uVar2 + _DAT_800ab5d8;
    uVar1 = FUN_8003ed68();
    uVar2 = FUN_8003ef90(uVar1);
    FUN_8003f10c(uVar1,uVar2 + 1);
    while (_DAT_800ab5d8 < iVar4) {
      if (uVar2 <= *(byte *)(_DAT_800abff0 + _DAT_800ab5d8)) {
        _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
        uVar2 = _DAT_800abfec;
        iVar3 = _DAT_800ab5d8 + 2;
        if (0xbf < _DAT_800abfec) {
          uVar2 = (_DAT_800abfec - 0xc0) * 0x100 |
                  (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 2);
          iVar3 = _DAT_800ab5d8 + 3;
        }
        _DAT_800ab5d8 = iVar3;
        iVar3 = uVar2 + _DAT_800ab5d8;
        while (_DAT_800ab5d8 < iVar3) {
          FUN_80043b10();
        }
        _DAT_800ab5d8 = iVar4;
        return;
      }
      _DAT_800ab5d8 = _DAT_800ab5d8 + 1;
      FUN_8003ee58();
    }
  }
  else {
    param_1 = param_1 + 2;
    uVar1 = FUN_8003ed68();
    uVar2 = FUN_8003ef90(uVar1);
    FUN_8003f10c(uVar1,uVar2 + 1);
    iVar4 = 0;
    if (0 < param_1) {
LAB_80044590:
      if (*(byte *)(_DAT_800abff0 + _DAT_800ab5d8) < uVar2) goto LAB_80044650;
      _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
      uVar2 = _DAT_800abfec;
      iVar3 = _DAT_800ab5d8 + 2;
      if (0xbf < _DAT_800abfec) {
        uVar2 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 2);
        iVar3 = _DAT_800ab5d8 + 3;
      }
      _DAT_800ab5d8 = iVar3;
      iVar3 = uVar2 + _DAT_800ab5d8;
      while (_DAT_800ab5d8 < iVar3) {
        FUN_80043b10();
      }
    }
joined_r0x8004466c:
    while (iVar4 = iVar4 + 1, iVar4 < param_1) {
      _DAT_800ab5d8 = _DAT_800ab5d8 + 1;
      FUN_8003ee58();
    }
  }
  return;
LAB_80044650:
  iVar4 = iVar4 + 1;
  _DAT_800ab5d8 = _DAT_800ab5d8 + 1;
  FUN_8003ee58();
  if (param_1 <= iVar4) goto joined_r0x8004466c;
  goto LAB_80044590;
}



// ---- FUN_80044838 @ 80044838

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80044838(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = FUN_8003dc2c();
  if (param_1 < 0) {
    _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    uVar2 = _DAT_800abfec;
    iVar3 = _DAT_800ab5d8 + 1;
    if (0xbf < _DAT_800abfec) {
      uVar2 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
      iVar3 = _DAT_800ab5d8 + 2;
    }
    _DAT_800ab5d8 = iVar3;
    iVar4 = uVar2 + _DAT_800ab5d8;
    iVar3 = _DAT_800ab5d8;
    while (_DAT_800ab5d8 = iVar3, iVar3 < iVar4) {
      _DAT_800ab5d8 = iVar3 + 1;
      if (iVar1 <= (int)(uint)*(byte *)(_DAT_800abff0 + iVar3)) {
        _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
        uVar2 = _DAT_800abfec;
        _DAT_800ab5d8 = iVar3 + 2;
        if (0xbf < _DAT_800abfec) {
          _DAT_800ab5d8 = iVar3 + 3;
          uVar2 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + iVar3 + 2);
        }
        iVar1 = uVar2 + _DAT_800ab5d8;
        while (_DAT_800ab5d8 < iVar1) {
          FUN_80043b10();
        }
        _DAT_800ab5d8 = iVar4;
        return;
      }
      FUN_8003ee58();
      iVar3 = _DAT_800ab5d8;
    }
  }
  else {
    param_1 = param_1 + 2;
    iVar3 = 0;
    if (0 < param_1) {
LAB_80044868:
      if ((int)(uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8) < iVar1) goto LAB_80044928;
      _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
      uVar2 = _DAT_800abfec;
      iVar1 = _DAT_800ab5d8 + 2;
      if (0xbf < _DAT_800abfec) {
        uVar2 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 2);
        iVar1 = _DAT_800ab5d8 + 3;
      }
      _DAT_800ab5d8 = iVar1;
      iVar1 = uVar2 + _DAT_800ab5d8;
      while (_DAT_800ab5d8 < iVar1) {
        FUN_80043b10();
      }
    }
joined_r0x80044944:
    while (iVar3 = iVar3 + 1, iVar3 < param_1) {
      _DAT_800ab5d8 = _DAT_800ab5d8 + 1;
      FUN_8003ee58();
    }
  }
  return;
LAB_80044928:
  iVar3 = iVar3 + 1;
  _DAT_800ab5d8 = _DAT_800ab5d8 + 1;
  FUN_8003ee58();
  if (param_1 <= iVar3) goto joined_r0x80044944;
  goto LAB_80044868;
}



// ---- FUN_80044af4 @ 80044af4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80044af4(uint param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = _DAT_800ab5d8;
  uVar1 = _DAT_800ab578;
  FUN_8003f2dc((int)param_1 >> 0xf);
  param_1 = param_1 & 0x7fff;
  _DAT_800ab5d8 = param_1 + 2;
  if (*(char *)(_DAT_800abff0 + param_1) == '\0') {
    _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + param_1 + 1);
    _DAT_800ab5d8 = param_1 + 3;
    if (_DAT_800abfec < 0xc0) {
      uVar3 = _DAT_800abfec;
      _DAT_800ab5d8 = param_1 + 2;
    }
    else {
      uVar3 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + param_1 + 2);
    }
    iVar4 = uVar3 + _DAT_800ab5d8;
    while (_DAT_800ab5d8 < iVar4) {
      FUN_80043b10();
    }
  }
  else {
    FUN_80044cd0(CONCAT11(*(char *)(_DAT_800abff0 + param_1),
                          *(undefined1 *)(_DAT_800abff0 + param_1 + 1)) & 0x3fff);
    _DAT_800abfec = (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8);
    uVar3 = _DAT_800abfec;
    iVar4 = _DAT_800ab5d8 + 1;
    if (0xbf < _DAT_800abfec) {
      uVar3 = (_DAT_800abfec - 0xc0) * 0x100 | (uint)*(byte *)(_DAT_800abff0 + _DAT_800ab5d8 + 1);
      iVar4 = _DAT_800ab5d8 + 2;
    }
    _DAT_800ab5d8 = iVar4;
    iVar4 = uVar3 + _DAT_800ab5d8;
    while (_DAT_800ab5d8 < iVar4) {
      FUN_80043b10();
    }
    FUN_80044d04();
  }
  FUN_8003f2dc(uVar1);
  _DAT_800ab5d8 = uVar2;
  return;
}



// ---- FUN_80044cd0 @ 80044cd0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80044cd0(undefined2 param_1)

{
  int iVar1;
  
  iVar1 = _DAT_800abf5c * 2;
  _DAT_800abf5c = _DAT_800abf5c + 1;
  *(undefined2 *)(&DAT_800b04ec + iVar1) = param_1;
  return;
}



// ---- FUN_80044d04 @ 80044d04

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80044d04(void)

{
  _DAT_800abf5c = _DAT_800abf5c + -1;
  return;
}



// ---- FUN_80044d24 @ 80044d24

void FUN_80044d24(void)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_8002ac50(0x44);
  *puVar1 = 0;
  puVar1[1] = 0x10;
  return;
}



// ---- FUN_80044d50 @ 80044d50

void FUN_80044d50(int param_1)

{
  undefined2 *puVar1;
  int iVar2;
  
  if (param_1 < 0x10) {
    iVar2 = 0x10;
  }
  else {
    iVar2 = 0x20;
    if (param_1 < 0x1000) {
      if (0x20 < param_1) {
        do {
          iVar2 = iVar2 << 1;
        } while (iVar2 < param_1);
      }
    }
    else {
      iVar2 = param_1 + 0xfff;
      if (iVar2 < 0) {
        iVar2 = param_1 + 0x1ffe;
      }
      iVar2 = (iVar2 >> 0xc) << 0xc;
      if (0xffff < iVar2) {
        iVar2 = 0xffff;
      }
    }
  }
  puVar1 = (undefined2 *)FUN_8002ac50(iVar2 * 4 + 4);
  *puVar1 = 0;
  puVar1[1] = (short)iVar2;
  return;
}



// ---- FUN_80044dfc @ 80044dfc

ushort * FUN_80044dfc(ushort *param_1,int param_2)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 != (ushort *)0x0) {
    param_2 = param_2 + (uint)*param_1 * 2;
    if (param_2 <= (int)(uint)param_1[1]) {
      return param_1;
    }
    iVar3 = 0x10;
    if (0xf < param_2) {
      iVar2 = 0x20;
      if (param_2 < 0x1000) {
        iVar3 = 0x20;
        if (0x20 < param_2) {
          do {
            iVar2 = iVar2 << 1;
          } while (iVar2 < param_2);
          param_1[1] = (ushort)iVar2;
          goto LAB_80044f24;
        }
      }
      else {
        iVar3 = param_2 + 0xfff;
        if (iVar3 < 0) {
          iVar3 = param_2 + 0x1ffe;
        }
        iVar3 = (iVar3 >> 0xc) << 0xc;
        if (0xffff < iVar3) {
          iVar3 = 0xffff;
        }
      }
    }
    param_1[1] = (ushort)iVar3;
LAB_80044f24:
    puVar1 = (ushort *)FUN_8002ad3c(param_1,(uint)param_1[1] * 4 + 4);
    return puVar1;
  }
  if (param_2 < 0x10) {
    iVar3 = 0x10;
  }
  else {
    iVar3 = 0x20;
    if (param_2 < 0x1000) {
      iVar2 = 0x80;
      iVar4 = iVar3;
      if (0x20 < param_2) {
        do {
          iVar3 = iVar4 << 1;
          iVar2 = iVar4 << 3;
          iVar4 = iVar3;
        } while (iVar3 < param_2);
      }
      goto LAB_80044e80;
    }
    iVar2 = param_2 + 0xfff;
    if (iVar2 < 0) {
      iVar2 = param_2 + 0x1ffe;
    }
    iVar3 = (iVar2 >> 0xc) << 0xc;
    iVar2 = (iVar2 >> 0xc) << 0xe;
    if (iVar3 < 0x10000) goto LAB_80044e80;
    iVar3 = 0xffff;
  }
  iVar2 = iVar3 << 2;
LAB_80044e80:
  puVar1 = (ushort *)FUN_8002ac50(iVar2 + 4);
  *puVar1 = 0;
  puVar1[1] = (ushort)iVar3;
  return puVar1;
}



// ---- FUN_80044f4c @ 80044f4c

void FUN_80044f4c(ushort *param_1,undefined4 param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  if (param_1 == (ushort *)0x0) {
    param_1 = (ushort *)FUN_8002ac50(0x44);
    *param_1 = 0;
    param_1[1] = 0x10;
  }
  uVar1 = *param_1;
  if (uVar1 == param_1[1]) {
    uVar2 = uVar1 << 1;
    if ((0xfff < uVar1) && (uVar2 = 0xffff, uVar1 < 0xefff)) {
      uVar2 = uVar1 + 0x1000;
    }
    param_1[1] = uVar2;
    param_1 = (ushort *)FUN_8002ad3c(param_1,(uint)param_1[1] * 4 + 4);
  }
  uVar1 = *param_1;
  *param_1 = uVar1 + 1;
  *(undefined4 *)(param_1 + (uint)uVar1 * 2 + 2) = param_2;
  return;
}



// ---- FUN_80044ff4 @ 80044ff4

undefined4 FUN_80044ff4(ushort *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (ushort *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_8002ac50((uint)param_1[1] * 4 + 4);
    FUN_80058604(uVar1,param_1,(uint)*param_1 * 4 + 4);
  }
  return uVar1;
}



// ---- FUN_80045060 @ 80045060

ushort * FUN_80045060(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  
  if (param_2 != (ushort *)0x0) {
    if (param_1 == (ushort *)0x0) {
      puVar2 = (ushort *)FUN_8002ac50((uint)param_2[1] * 4 + 4);
      FUN_80058604(puVar2,param_2,(uint)*param_2 * 4 + 4);
      return puVar2;
    }
    param_1 = (ushort *)FUN_80044dfc(param_1,*param_2);
    iVar3 = 0;
    if (*param_2 != 0) {
      puVar2 = param_2;
      do {
        uVar1 = *param_1;
        iVar3 = iVar3 + 1;
        *param_1 = uVar1 + 1;
        *(undefined4 *)(param_1 + (uint)uVar1 * 2 + 2) = *(undefined4 *)(puVar2 + 2);
        puVar2 = puVar2 + 2;
      } while (iVar3 < (int)(uint)*param_2);
    }
  }
  return param_1;
}



// ---- FUN_8004512c @ 8004512c

void FUN_8004512c(void)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_8002ac50(0x24);
  *puVar1 = 0;
  puVar1[1] = 0x10;
  return;
}



// ---- FUN_80045158 @ 80045158

void FUN_80045158(int param_1)

{
  undefined2 *puVar1;
  int iVar2;
  
  if (param_1 < 0x10) {
    iVar2 = 0x10;
  }
  else {
    iVar2 = 0x20;
    if (param_1 < 0x1000) {
      if (0x20 < param_1) {
        do {
          iVar2 = iVar2 << 1;
        } while (iVar2 < param_1);
      }
    }
    else {
      iVar2 = param_1 + 0xfff;
      if (iVar2 < 0) {
        iVar2 = param_1 + 0x1ffe;
      }
      iVar2 = (iVar2 >> 0xc) << 0xc;
      if (0xffff < iVar2) {
        iVar2 = 0xffff;
      }
    }
  }
  puVar1 = (undefined2 *)FUN_8002ac50(iVar2 * 2 + 4);
  *puVar1 = 0;
  puVar1[1] = (short)iVar2;
  return;
}



// ---- FUN_80045204 @ 80045204

ushort * FUN_80045204(ushort *param_1,int param_2)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 != (ushort *)0x0) {
    param_2 = param_2 + (uint)*param_1 * 2;
    if (param_2 <= (int)(uint)param_1[1]) {
      return param_1;
    }
    iVar3 = 0x10;
    if (0xf < param_2) {
      iVar2 = 0x20;
      if (param_2 < 0x1000) {
        iVar3 = 0x20;
        if (0x20 < param_2) {
          do {
            iVar2 = iVar2 << 1;
          } while (iVar2 < param_2);
          param_1[1] = (ushort)iVar2;
          goto LAB_8004532c;
        }
      }
      else {
        iVar3 = param_2 + 0xfff;
        if (iVar3 < 0) {
          iVar3 = param_2 + 0x1ffe;
        }
        iVar3 = (iVar3 >> 0xc) << 0xc;
        if (0xffff < iVar3) {
          iVar3 = 0xffff;
        }
      }
    }
    param_1[1] = (ushort)iVar3;
LAB_8004532c:
    puVar1 = (ushort *)FUN_8002ad3c(param_1,(uint)param_1[1] * 2 + 4);
    return puVar1;
  }
  if (param_2 < 0x10) {
    iVar3 = 0x10;
  }
  else {
    iVar3 = 0x20;
    if (param_2 < 0x1000) {
      iVar2 = 0x40;
      iVar4 = iVar3;
      if (0x20 < param_2) {
        do {
          iVar3 = iVar4 << 1;
          iVar2 = iVar4 << 2;
          iVar4 = iVar3;
        } while (iVar3 < param_2);
      }
      goto LAB_80045288;
    }
    iVar2 = param_2 + 0xfff;
    if (iVar2 < 0) {
      iVar2 = param_2 + 0x1ffe;
    }
    iVar3 = (iVar2 >> 0xc) << 0xc;
    iVar2 = (iVar2 >> 0xc) << 0xd;
    if (iVar3 < 0x10000) goto LAB_80045288;
    iVar3 = 0xffff;
  }
  iVar2 = iVar3 << 1;
LAB_80045288:
  puVar1 = (ushort *)FUN_8002ac50(iVar2 + 4);
  *puVar1 = 0;
  puVar1[1] = (ushort)iVar3;
  return puVar1;
}



// ---- FUN_80045354 @ 80045354

void FUN_80045354(ushort *param_1,ushort param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  if (param_1 == (ushort *)0x0) {
    param_1 = (ushort *)FUN_8002ac50(0x24);
    *param_1 = 0;
    param_1[1] = 0x10;
  }
  uVar1 = *param_1;
  if (uVar1 == param_1[1]) {
    uVar2 = uVar1 << 1;
    if ((0xfff < uVar1) && (uVar2 = 0xffff, uVar1 < 0xefff)) {
      uVar2 = uVar1 + 0x1000;
    }
    param_1[1] = uVar2;
    param_1 = (ushort *)FUN_8002ad3c(param_1,(uint)param_1[1] * 2 + 4);
  }
  uVar1 = *param_1;
  *param_1 = uVar1 + 1;
  param_1[uVar1 + 2] = param_2;
  return;
}



// ---- FUN_800453fc @ 800453fc

void FUN_800453fc(void)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_8002ac50(0x14);
  *puVar1 = 0;
  puVar1[1] = 0x10;
  return;
}



// ---- FUN_80045428 @ 80045428

void FUN_80045428(int param_1)

{
  undefined2 *puVar1;
  int iVar2;
  
  if (param_1 < 0x10) {
    iVar2 = 0x10;
  }
  else {
    iVar2 = 0x20;
    if (param_1 < 0x1000) {
      if (0x20 < param_1) {
        do {
          iVar2 = iVar2 << 1;
        } while (iVar2 < param_1);
      }
    }
    else {
      iVar2 = param_1 + 0xfff;
      if (iVar2 < 0) {
        iVar2 = param_1 + 0x1ffe;
      }
      iVar2 = (iVar2 >> 0xc) << 0xc;
      if (0xffff < iVar2) {
        iVar2 = 0xffff;
      }
    }
  }
  puVar1 = (undefined2 *)FUN_8002ac50(iVar2 << 1);
  *puVar1 = 0;
  puVar1[1] = (short)iVar2;
  return;
}



// ---- FUN_800454d0 @ 800454d0

void FUN_800454d0(ushort *param_1,undefined1 param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  if (param_1 == (ushort *)0x0) {
    param_1 = (ushort *)FUN_8002ac50(0x14);
    *param_1 = 0;
    param_1[1] = 0x10;
  }
  uVar1 = *param_1;
  if (uVar1 == param_1[1]) {
    uVar2 = uVar1 << 1;
    if ((0xfff < uVar1) && (uVar2 = 0xffff, uVar1 < 0xefff)) {
      uVar2 = uVar1 + 0x1000;
    }
    param_1[1] = uVar2;
    param_1 = (ushort *)FUN_8002ad3c(param_1,param_1[1] + 4);
  }
  uVar1 = *param_1;
  *param_1 = uVar1 + 1;
  *(undefined1 *)((int)param_1 + uVar1 + 4) = param_2;
  return;
}



// ---- FUN_8004556c @ 8004556c

void FUN_8004556c(ushort *param_1,undefined4 param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  if (param_1 == (ushort *)0x0) {
    param_1 = (ushort *)FUN_8002ac50(0x14);
    *param_1 = 0;
    param_1[1] = 0x10;
  }
  uVar1 = *param_1;
  if (uVar1 == param_1[1]) {
    uVar2 = uVar1 << 1;
    if ((0xfff < uVar1) && (uVar2 = 0xffff, uVar1 < 0xefff)) {
      uVar2 = uVar1 + 0x1000;
    }
    param_1[1] = uVar2;
    param_1 = (ushort *)FUN_8002ad3c(param_1,param_1[1] + 4);
  }
  uVar1 = *param_1;
  *param_1 = uVar1 + 1;
  *(char *)((int)param_1 + uVar1 + 4) = (char)((uint)param_2 >> 8);
  if (param_1 == (ushort *)0x0) {
    param_1 = (ushort *)FUN_8002ac50(0x14);
    *param_1 = 0;
    param_1[1] = 0x10;
  }
  uVar1 = *param_1;
  if (uVar1 == param_1[1]) {
    uVar2 = uVar1 << 1;
    if ((0xfff < uVar1) && (uVar2 = 0xffff, uVar1 < 0xefff)) {
      uVar2 = uVar1 + 0x1000;
    }
    param_1[1] = uVar2;
    param_1 = (ushort *)FUN_8002ad3c(param_1,param_1[1] + 4);
  }
  uVar1 = *param_1;
  *param_1 = uVar1 + 1;
  *(char *)((int)param_1 + uVar1 + 4) = (char)param_2;
  return;
}



// ---- FUN_8004568c @ 8004568c

void FUN_8004568c(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_8004556c(param_1,param_2 >> 0x10);
  FUN_8004556c(uVar1,param_2 & 0xffff);
  return;
}



// ---- FUN_800456c4 @ 800456c4

void FUN_800456c4(ushort *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = FUN_80058624(param_2);
  if (param_1 == (ushort *)0x0) {
    param_1 = (ushort *)FUN_8002ac50(0x14);
    *param_1 = 0;
    param_1[1] = 0x10;
  }
  iVar3 = (uint)*param_1 + iVar1 + 1;
  if (iVar3 <= (int)(uint)param_1[1]) goto LAB_800457a0;
  iVar2 = 0x10;
  if (iVar3 < 0x10) {
LAB_80045788:
    param_1[1] = (ushort)iVar2;
  }
  else {
    iVar4 = 0x20;
    if (0xfff < iVar3) {
      iVar2 = iVar3 + 0xfff;
      if (iVar2 < 0) {
        iVar2 = iVar3 + 0x1ffe;
      }
      iVar2 = (iVar2 >> 0xc) << 0xc;
      if (0xffff < iVar2) {
        iVar2 = 0xffff;
      }
      goto LAB_80045788;
    }
    iVar2 = 0x20;
    if (iVar3 < 0x21) goto LAB_80045788;
    do {
      iVar4 = iVar4 << 1;
    } while (iVar4 < iVar3);
    param_1[1] = (ushort)iVar4;
  }
  param_1 = (ushort *)FUN_8002ad3c(param_1,param_1[1] + 4);
LAB_800457a0:
  FUN_80058644((int)param_1 + *param_1 + 4,param_2);
  *param_1 = *param_1 + (short)(iVar1 + 1);
  return;
}



// ---- FUN_800457e0 @ 800457e0

undefined4 FUN_800457e0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_80058624();
  uVar2 = FUN_8002ac50(iVar1 + 1);
  FUN_80058644(uVar2,param_1);
  return uVar2;
}



// ---- FUN_8004582c @ 8004582c

char * FUN_8004582c(char *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  if (param_1 == (char *)0x0) {
    iVar2 = FUN_80058624(s__NULL__80028604);
    pcVar3 = (char *)FUN_8002ac50(iVar2 + 1);
    FUN_80058644(pcVar3,s__NULL__80028604);
  }
  else {
    iVar2 = FUN_80058624(param_1);
    pcVar3 = (char *)FUN_8002ac50(iVar2 + 1);
    cVar1 = *param_1;
    pcVar4 = pcVar3;
    while (cVar1 != '\0') {
      cVar1 = *param_1;
      param_1 = param_1 + 1;
      *pcVar4 = -cVar1;
      pcVar4 = pcVar4 + 1;
      cVar1 = *param_1;
    }
    *pcVar4 = '\0';
  }
  return pcVar3;
}



// ---- FUN_800458d4 @ 800458d4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte FUN_800458d4(int param_1)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64;
  if (param_1 == 0) {
    FUN_80045978();
    FUN_80047500();
    FUN_800483dc();
    FUN_80048630();
    FUN_8004a1c4();
    FUN_8004a444();
    FUN_8004a70c();
    FUN_8004b904();
    FUN_8004d460();
    FUN_8004d548();
    FUN_80051050();
    FUN_80055d44();
    FUN_80036704();
  }
  return *(byte *)(iVar1 + 0x1ac1) >> 5 & 1;
}



// ---- FUN_80045978 @ 80045978

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80045978(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64 + 0x1ea4;
  FUN_80032568(iVar1,FUN_800459e8);
  FUN_80032288(iVar1,0,1);
  return;
}



// ---- FUN_800459e8 @ 800459e8

void FUN_800459e8(int param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  
  iVar7 = param_1 + 0x22b0;
  FUN_800328a4(iVar7,0x12);
  FUN_80032288(iVar7,param_2,1);
  FUN_80032b80(iVar7,1);
  FUN_80032d54(iVar7,2);
  FUN_80032d9c(iVar7,0);
  FUN_80033560(iVar7,0x20,0x10,1);
  FUN_80033a18(iVar7,0xc0,0x80,0x40);
  iVar2 = param_1 + 0x46b0;
  iVar3 = param_1 + 0x4768;
  FUN_80034bec(iVar2);
  FUN_80032288(iVar2,param_2,1);
  FUN_80035ab8(iVar2,FUN_800474cc);
  FUN_8003541c(iVar2,2);
  FUN_80034e00(iVar2,0,1);
  FUN_80035434(iVar2,1);
  FUN_800358f0(iVar2,0,1,1);
  FUN_80035694(iVar2,0x1a,0);
  FUN_80035458(iVar2,0,0,1);
  FUN_8003571c(iVar2,0,0);
  FUN_8003579c(iVar2,1,1);
  FUN_80034bec(iVar3);
  FUN_80032288(iVar3,param_2,1);
  FUN_80035ab8(iVar3,FUN_8004736c);
  FUN_8003541c(iVar3,0);
  FUN_80034e00(iVar3,0,1);
  FUN_80035434(iVar3,0);
  FUN_800358f0(iVar3,0,1,1);
  FUN_80035694(iVar3,0x1b,0xd);
  FUN_80035458(iVar3,0,0,1);
  FUN_8003571c(iVar3,0x80,0x78);
  iVar2 = param_1 + 0x47c4;
  FUN_80034bec(iVar2);
  FUN_80032288(iVar2,param_2,1);
  FUN_80035ab8(iVar2,0);
  FUN_8003541c(iVar2,0);
  FUN_80034e00(iVar2,0,1);
  FUN_80035434(iVar2,0);
  FUN_800358f0(iVar2,0,1,1);
  FUN_80035694(iVar2,0x1b,0xd);
  FUN_80035458(iVar2,0,0,1);
  FUN_8003571c(iVar2,0x80,0x78);
  FUN_8003579c(iVar2,1,0);
  FUN_80035998(iVar2,0,0,0);
  iVar2 = param_1 + 0x470c;
  FUN_80034bec(iVar2);
  FUN_80032288(iVar2,param_2,1);
  FUN_80034e00(iVar2,0,1);
  FUN_80035434(iVar2,0);
  FUN_800358f0(iVar2,0,1,1);
  FUN_80035694(iVar2,0x1b,0xc);
  FUN_80035458(iVar2,0,0,1);
  FUN_8003571c(iVar2,0xe8,0xcc);
  iVar2 = param_1 + 0x27f0;
  FUN_800328a4(iVar2,4);
  FUN_80032288(iVar2,param_2,1);
  FUN_80032b80(iVar2,1);
  FUN_80032d54(iVar2,4);
  FUN_80032d9c(iVar2,0);
  FUN_80032e54(iVar2,1,0);
  FUN_80032e30(iVar2,1);
  FUN_80033560(iVar2,8,0x114,1);
  FUN_80033a18(iVar2,0xf0,0x40,0x40);
  FUN_80033094(iVar2,0,0,0,1);
  FUN_80033094(iVar2,0,0,0,2);
  FUN_80033094(iVar2,0,0,0,4);
  FUN_80033094(iVar2,0,0,0,8);
  iVar2 = param_1 + 0x27b0;
  FUN_800328a4(iVar2,0xf);
  FUN_80032288(iVar2,param_2,1);
  FUN_80032b80(iVar2,1);
  FUN_80032d78(iVar2,1);
  FUN_80032d54(iVar2,4);
  FUN_80032d9c(iVar2,0);
  FUN_80032e0c(iVar2,2);
  FUN_80032fac(iVar2,0x1d,0);
  FUN_80033560(iVar2,4,0x110,1);
  FUN_80033a18(iVar2,0xf8,0x4c,0x40);
  FUN_80033d40(iVar2,0,0,1);
  FUN_80033094(iVar2,0x80,0x80,0x80,1);
  iVar2 = param_1 + 0x2530;
  FUN_800328a4(iVar2,0xf);
  FUN_80032288(iVar2,param_2,1);
  FUN_80032b80(iVar2,1);
  FUN_80032d78(iVar2,0);
  FUN_80032d54(iVar2,2);
  FUN_80032d9c(iVar2,0);
  FUN_80032e0c(iVar2,0x16);
  FUN_80032fac(iVar2,0x1b,0xf);
  FUN_80033560(iVar2,10,0x9f,1);
  FUN_80033a18(iVar2,0,0x10,0x40);
  FUN_80033dcc(iVar2,0,0,1);
  FUN_80033094(iVar2,0x80,0x80,0x80,1);
  iVar3 = 0;
  iVar2 = 0;
  do {
    iVar2 = iVar7 + iVar2 + 0x2c0;
    FUN_800328a4(iVar2,0xf);
    FUN_80032288(iVar2,param_2,1);
    FUN_80032b80(iVar2,1);
    FUN_80032d78(iVar2,0);
    FUN_80032d54(iVar2,2);
    FUN_80032d9c(iVar2,0);
    FUN_80032e0c(iVar2,0x16);
    FUN_80032fac(iVar2,0x1b,0xf);
    FUN_80033560(iVar2,0xe,((iVar3 % 3) * 0x10 + 0xad) * 0x10000 >> 0x10,1);
    FUN_80033a18(iVar2,0,0x10,0x40);
    puVar1 = &DAT_800711b4 + iVar3;
    iVar3 = iVar3 + 1;
    FUN_80033dcc(iVar2,*puVar1,0,1);
    FUN_80033094(iVar2,0x80,0x80,0x80,1);
    iVar2 = iVar3 * 0x40;
  } while (iVar3 < 6);
  iVar2 = param_1 + 0x26f0;
  FUN_800328a4(iVar2,0x12);
  FUN_80032288(iVar2,param_2,0);
  FUN_80032b80(iVar2,1);
  FUN_80032d54(iVar2,2);
  FUN_80032d9c(iVar2,0);
  FUN_80032e54(iVar2,1,0);
  FUN_80033560(iVar2,0x24,0x48,1);
  FUN_80033a18(iVar2,0xc,0xc,0x40);
  FUN_80033094(iVar2,0,0x80,0,1);
  iVar2 = param_1 + 0x2730;
  FUN_800328a4(iVar2,0xf);
  FUN_80032288(iVar2,param_2,1);
  FUN_80032b80(iVar2,1);
  FUN_80032d78(iVar2,0);
  FUN_80032d54(iVar2,2);
  FUN_80032d9c(iVar2,0);
  FUN_80032e0c(iVar2,0x17);
  FUN_80032fac(iVar2,0x1b,0xf);
  FUN_80033560(iVar2,0x14,0x116,1);
  FUN_80033a18(iVar2,0xd8,0x40,0x40);
  FUN_80033dcc(iVar2,0,0,1);
  FUN_80033094(iVar2,0x80,0x80,0x80,1);
  iVar2 = param_1 + 0x2770;
  FUN_800328a4(iVar2,0x12);
  FUN_80032288(iVar2,param_2,1);
  FUN_80032b80(iVar2,1);
  FUN_80032d54(iVar2,3);
  FUN_80032d9c(iVar2,0);
  FUN_80032e54(iVar2,1,0);
  FUN_80033560(iVar2,8,0x9e,1);
  FUN_80033a18(iVar2,0x78,0xc,0x40);
  FUN_80033094(iVar2,0x7f,0,0x7f,1);
  iVar2 = param_1 + 0x2830;
  FUN_800328a4(iVar2,0xf);
  FUN_80032288(iVar2,param_2,1);
  FUN_80032b80(iVar2,1);
  FUN_80032d78(iVar2,1);
  FUN_80032d54(iVar2,4);
  FUN_80032d9c(iVar2,0);
  FUN_80032e0c(iVar2,6);
  FUN_80032fac(iVar2,0x1d,0);
  FUN_80033560(iVar2,0,0x10c,1);
  FUN_80033a18(iVar2,0x100,0x50,0x40);
  FUN_80033d40(iVar2,0,0,1);
  FUN_80033094(iVar2,0x80,0x80,0x80,1);
  iVar2 = param_1 + 0x2870;
  FUN_800328a4(iVar2,4);
  FUN_80032288(iVar2,param_2,1);
  FUN_80032b80(iVar2,1);
  FUN_80032d54(iVar2,4);
  FUN_80032d9c(iVar2,0);
  FUN_80032e54(iVar2,1,0);
  FUN_80032e30(iVar2,1);
  FUN_80033560(iVar2,0,0x113,1);
  FUN_80033a18(iVar2,0x100,0x42,0x40);
  FUN_80033094(iVar2,0,0,0,1);
  FUN_80033094(iVar2,0,0,0,2);
  FUN_80033094(iVar2,0,0,0,4);
  FUN_80033094(iVar2,0,0,0,8);
  iVar2 = param_1 + 0x29b0;
  FUN_800328a4(iVar2,0xf);
  FUN_80032288(iVar2,param_2,1);
  FUN_80032b80(iVar2,1);
  FUN_80032d78(iVar2,1);
  FUN_80032d54(iVar2,4);
  FUN_80032d9c(iVar2,0);
  FUN_80032e0c(iVar2,6);
  FUN_80032fac(iVar2,0x1e,0);
  FUN_80033560(iVar2,4,0x110,1);
  FUN_80033a18(iVar2,0xf8,0x4c,0x40);
  FUN_80033d40(iVar2,0,0,1);
  FUN_80033094(iVar2,0x80,0x80,0x80,1);
  FUN_80032e54(iVar2,1,0);
  iVar2 = param_1 + 0x48d8;
  FUN_80034bec(iVar2);
  FUN_80032288(iVar2,param_2,1);
  FUN_80034e00(iVar2,0,1);
  FUN_80035434(iVar2,1);
  FUN_8003541c(iVar2,3);
  FUN_800358f0(iVar2,0,0,0);
  FUN_80035694(iVar2,0x1e,0xe);
  FUN_8003571c(iVar2,4,0x98);
  FUN_80035458(iVar2,0,0,1);
  iVar2 = param_1 + 0x29f0;
  FUN_800328a4(iVar2,0x12);
  FUN_80032288(iVar2,param_2,1);
  FUN_80032b80(iVar2,1);
  FUN_80032d9c(iVar2,0);
  FUN_80032d54(iVar2,3);
  FUN_80032e54(iVar2,1,0);
  FUN_80033560(iVar2,0x1c,0x74,1);
  FUN_80033a18(iVar2,0xb8,0,0x40);
  FUN_80033094(iVar2,0,0x70,0x38,1);
  iVar2 = 0;
  cVar6 = '\0';
  iVar5 = 0x220000;
  iVar3 = 0x200000;
  do {
    iVar4 = iVar7 + iVar2 * 0x40 + 0x780;
    FUN_800328a4(iVar4,0x12);
    FUN_80032288(iVar4,param_2,1);
    FUN_80032b80(iVar4,1);
    FUN_80032d54(iVar4,3);
    FUN_80032d9c(iVar4,0);
    FUN_80032e54(iVar4,1,0);
    FUN_80033560(iVar4,iVar3 >> 0x10,0x74,1);
    FUN_80033a18(iVar4,0xe,0,0x40);
    FUN_80033094(iVar4,0,0x70,0x38,1);
    iVar4 = iVar7 + iVar2 * 0x40 + 0xa40;
    FUN_800328a4(iVar4,0xf);
    FUN_80032288(iVar4,param_2,1);
    FUN_80032b80(iVar4,1);
    FUN_80032d78(iVar4,0);
    FUN_80032d54(iVar4,2);
    FUN_80032d9c(iVar4,0);
    FUN_80032e0c(iVar4,0x17);
    FUN_80032fac(iVar4,0x1b,0xf);
    FUN_80033560(iVar4,iVar5 >> 0x10,0x6e,1);
    FUN_80033a18(iVar4,0xc,0x10,0x40);
    FUN_80033d40(iVar4,cVar6,0,1);
    FUN_80033094(iVar4,0x80,0x80,0x80,1);
    iVar5 = iVar5 + 0x100000;
    iVar3 = iVar3 + 0x100000;
    iVar2 = iVar2 + 1;
    cVar6 = cVar6 + '\f';
  } while (iVar2 < 0xb);
  iVar2 = param_1 + 0x28f0;
  FUN_800328a4(iVar2,4);
  FUN_80032288(iVar2,param_2,1);
  FUN_80032b80(iVar2,1);
  FUN_80032d54(iVar2,4);
  FUN_80032d9c(iVar2,0);
  FUN_80032e54(iVar2,1,0);
  FUN_80032e30(iVar2,1);
  FUN_80033560(iVar2,8,0x114,1);
  FUN_80033a18(iVar2,0x88,0x40,0x40);
  FUN_80033094(iVar2,0,0,0,1);
  FUN_80033094(iVar2,0,0,0,2);
  FUN_80033094(iVar2,0,0,0,4);
  FUN_80033094(iVar2,0,0,0,8);
  iVar2 = param_1 + 0x28b0;
  FUN_800328a4(iVar2,0xf);
  FUN_80032288(iVar2,param_2,1);
  FUN_80032b80(iVar2,1);
  FUN_80032d78(iVar2,1);
  FUN_80032d54(iVar2,4);
  FUN_80032d9c(iVar2,0);
  FUN_80032e0c(iVar2,2);
  FUN_80032fac(iVar2,0x1e,0);
  FUN_80033560(iVar2,4,0x110,1);
  FUN_80033a18(iVar2,0xf8,0x4c,0x40);
  FUN_80033d40(iVar2,0,0,1);
  FUN_80033094(iVar2,0x80,0x80,0x80,1);
  FUN_80032e54(iVar2,1,0);
  iVar2 = param_1 + 0x4820;
  FUN_80034bec(iVar2);
  FUN_80032288(iVar2,param_2,1);
  FUN_80034e00(iVar2,0,1);
  FUN_80035434(iVar2,1);
  FUN_8003541c(iVar2,3);
  FUN_800358f0(iVar2,0,0,0);
  FUN_80035694(iVar2,0x1e,0xe);
  FUN_8003571c(iVar2,4,0x110);
  FUN_80035458(iVar2,0,0,1);
  iVar2 = param_1 + 0x487c;
  FUN_80034bec(iVar2);
  FUN_80032288(iVar2,param_2,1);
  FUN_80034e00(iVar2,0,1);
  FUN_80035434(iVar2,1);
  FUN_8003541c(iVar2,3);
  FUN_800358f0(iVar2,0,0,0);
  FUN_80035694(iVar2,0x1e,0xe);
  FUN_8003571c(iVar2,4,0x110);
  FUN_80035458(iVar2,0xc,0,1);
  iVar2 = param_1 + 0x2930;
  FUN_800328a4(iVar2,0xf);
  FUN_80032288(iVar2,param_2,1);
  FUN_80032b80(iVar2,1);
  FUN_80032d78(iVar2,0);
  FUN_80032d54(iVar2,2);
  FUN_80032d9c(iVar2,0);
  FUN_80032e0c(iVar2,0x17);
  FUN_80032fac(iVar2,0x1b,0xf);
  FUN_80033560(iVar2,0xc,0x128,1);
  FUN_80033a18(iVar2,0x78,0x10,0x40);
  FUN_80033d40(iVar2,0,0,1);
  FUN_80033094(iVar2,0x80,0x80,0x80,1);
  iVar2 = param_1 + 0x2970;
  FUN_800328a4(iVar2,0x12);
  FUN_80032288(iVar2,param_2,0);
  FUN_80032b80(iVar2,1);
  FUN_80032d9c(iVar2,0);
  FUN_80032d54(iVar2,3);
  FUN_80032e54(iVar2,1,0);
  FUN_80033560(iVar2,0xb,0xae,1);
  FUN_80033a18(iVar2,0xc,0x10,0x40);
  FUN_80033094(iVar2,0,0x70,0x38,1);
  iVar2 = param_1 + 0x31f0;
  FUN_800328a4(iVar2,0xf);
  FUN_80032288(iVar2,param_2,1);
  FUN_80032b80(iVar2,1);
  FUN_80032d78(iVar2,1);
  FUN_80032d54(iVar2,7);
  FUN_80032d9c(iVar2,0);
  FUN_80032e0c(iVar2,0x12);
  FUN_80032fac(iVar2,0x16,0);
  FUN_80033560(iVar2,0x20,0x10,1);
  FUN_80033a18(iVar2,0xc0,0x80,0x40);
  FUN_80033d40(iVar2,0,0,1);
  FUN_80033094(iVar2,0x80,0x80,0x80,1);
  param_1 = param_1 + 0x3230;
  FUN_800328a4(param_1,0x12);
  FUN_80032288(param_1,param_2,1);
  FUN_80032b80(param_1,1);
  FUN_80032d54(param_1,0xe);
  FUN_80032d9c(param_1,0);
  FUN_80033560(param_1,0x20,0x10,1);
  FUN_80033a18(param_1,0xc0,0x80,0x40);
  FUN_8002c57c(0xcf,0x80119000,4,FUN_80046d94);
  FUN_80032654(param_2,0);
  return;
}



// ---- FUN_80046d94 @ 80046d94

void FUN_80046d94(int param_1)

{
  undefined1 auStack_40 [48];
  
  FUN_8002ca58(0,auStack_40,0x80119000,0x801a6800,0);
  FUN_8002cf6c(auStack_40,&DAT_80071518,0);
  FUN_8002d178(auStack_40,&DAT_8007154c,0,0,0xffffffff);
  FUN_80034e34(param_1 + 0x46b0,auStack_40,0);
  FUN_800351a0(param_1 + 0x46b0,&DAT_80071518,0,0xffffffff);
  *(uint *)(param_1 + 0x1ac8) = *(uint *)(param_1 + 0x1ac8) | 0x800;
  FUN_8002c57c(5,&DAT_80118000,1,0);
  FUN_8002c57c(0xcd,0x8011a000,4,0);
  FUN_8002c57c(0xbe,0x8011a800,4,0);
  FUN_8002c57c(0xbf,0x8011c000,4,0);
  FUN_8002c57c(0xc6,0x8011d800,4,0);
  FUN_8002c57c(0xc5,0x80120000,4,0);
  FUN_8002c57c(0xc1,0x80122800,4,FUN_80046efc);
  return;
}



// ---- FUN_80046efc @ 80046efc

void FUN_80046efc(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_70 [32];
  undefined1 auStack_50 [48];
  
  FUN_8002ca58(0,auStack_50,0x8011a000,0x801a6800,0);
  FUN_8002cf6c(auStack_50,&DAT_80071500,&DAT_80071520);
  FUN_8002d178(auStack_50,&DAT_80071534,&DAT_8007155c,1,0xffffffff);
  iVar2 = param_1 + 0x4768;
  FUN_80034e34(iVar2,auStack_50,0);
  FUN_800351a0(iVar2,&DAT_80071500,&DAT_80071520,0xffffffff);
  uVar1 = FUN_80034e34(iVar2,0,0);
  FUN_80034e34(param_1 + 0x47c4,0,uVar1);
  FUN_800351a0(param_1 + 0x47c4,&DAT_80071500,&DAT_80071520,0xffffffff);
  FUN_8002ca58(auStack_70,auStack_50,0x8011a800,0x801a6800,0);
  FUN_8002cbc8(auStack_70,&DAT_800714f4,0);
  FUN_8002cd20(auStack_70,&DAT_80071528,&DAT_80071550,8,0xffffffff);
  FUN_8002cf6c(auStack_50,&DAT_800714f8,&DAT_8007151c);
  FUN_8002d178(auStack_50,&DAT_8007152c,&DAT_80071554,1,0xffffffff);
  FUN_80034e34(param_1 + 0x470c,auStack_50,0);
  FUN_800351a0(param_1 + 0x470c,&DAT_800714f8,&DAT_8007151c,0xffffffff);
  FUN_8002ca58(auStack_70,0,0x8011c000,0x801a6800,0);
  FUN_8002cbc8(auStack_70,&DAT_800714fc,0);
  FUN_8002cd20(auStack_70,&DAT_80071530,&DAT_80071558,8,0xffffffff);
  FUN_8002ca58(0,auStack_50,0x8011d800,0x801a6800,0);
  FUN_80034e34(param_1 + 0x4820,auStack_50,0);
  FUN_800351a0(param_1 + 0x4820,&DAT_8007150c,&DAT_80071524,0xffffffff);
  FUN_80034e34(param_1 + 0x487c,auStack_50,0);
  FUN_800351a0(param_1 + 0x487c,&DAT_8007150c,&DAT_80071524,0xffffffff);
  FUN_8002ca58(0,auStack_50,0x80120000,0x801a6800,0);
  FUN_80034e34(param_1 + 0x48d8,auStack_50,0);
  FUN_800351a0(param_1 + 0x48d8,&DAT_80071514,0,0xffffffff);
  FUN_80055d44();
  FUN_8002c57c(0x24,0x800d9800,5,0);
  FUN_8002c57c(0x24,0x80166800,6,FUN_80047224);
  return;
}



// ---- FUN_80047224 @ 80047224

void FUN_80047224(int param_1)

{
  FUN_80031884(0x24,0x80166800,1);
  FUN_80032654(param_1 + 0x1ea4,FUN_8004726c);
  return;
}



// ---- FUN_8004726c @ 8004726c

void FUN_8004726c(undefined4 param_1,undefined4 param_2)

{
  FUN_800528ac();
  FUN_80032654(param_2,FUN_800472a4);
  return;
}



// ---- FUN_800472a4 @ 800472a4

void FUN_800472a4(int param_1,undefined4 param_2)

{
  if ((*(byte *)(param_1 + 0x1ac1) & 0x10) != 0) {
    *(byte *)(param_1 + 0x1ac1) = *(byte *)(param_1 + 0x1ac1) | 0x20;
    *(uint *)(param_1 + 0x1ac8) = *(uint *)(param_1 + 0x1ac8) & 0xfffff7ff;
    FUN_80032654(param_2,FUN_80047304);
  }
  return;
}



// ---- FUN_80047304 @ 80047304

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80047304(int param_1,undefined4 param_2)

{
  *(byte *)(_DAT_800abf64 + 0x1ac0) = *(byte *)(_DAT_800abf64 + 0x1ac0) | 1;
  if ((*(byte *)(param_1 + 0x1ac0) & 1) != 0) {
    FUN_80032654(param_2,&LAB_80047358);
  }
  return;
}



// ---- FUN_8004736c @ 8004736c

void FUN_8004736c(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  int iVar5;
  ushort local_20;
  ushort local_1e;
  
  FUN_8002bb90(1,&local_20);
  bVar4 = false;
  iVar2 = FUN_8002bbf0(0xffffffff);
  iVar5 = param_1 + 0x4768;
  if (iVar2 != 0) {
    cVar1 = FUN_8002bb78();
    bVar4 = cVar1 != '\0';
  }
  FUN_8003571c(iVar5,(int)(short)local_20,(int)(short)local_1e);
  iVar2 = param_1 + 0x47c4;
  FUN_8003571c(iVar2,(int)((local_20 + 4) * 0x10000) >> 0x10,(int)((local_1e + 4) * 0x10000) >> 0x10
              );
  FUN_800358f0(iVar5,bVar4,1,1);
  FUN_800358f0(iVar2,bVar4,1,1);
  if (*(char *)(param_1 + 0x588) == '\x01') {
    if (DAT_800711ba != 0) {
      return;
    }
    uVar3 = 2;
    DAT_800711ba = 2;
  }
  else {
    if (DAT_800711ba != 2) {
      return;
    }
    uVar3 = 0;
    DAT_800711ba = 0;
  }
  FUN_80035458(iVar5,uVar3,0,1);
  FUN_80035458(iVar2,DAT_800711ba,0,1);
  return;
}



// ---- FUN_800474cc @ 800474cc

void FUN_800474cc(int param_1,undefined4 param_2)

{
  FUN_800358f0(param_2,*(uint *)(param_1 + 0x1ac8) >> 0xb & 1,1,1);
  return;
}



// ---- FUN_80047500 @ 80047500

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80047500(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64 + 0x1ec0;
  FUN_80032568(iVar1,0);
  FUN_80032288(iVar1,0,1);
  return;
}



// ---- FUN_80047548 @ 80047548

void FUN_80047548(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined *puVar3;
  char cVar4;
  undefined4 uVar5;
  int iVar6;
  code *pcVar7;
  byte local_30 [8];
  
  iVar6 = 0;
  uVar5 = 0xe;
  pcVar7 = FUN_80047ec4;
  puVar3 = &DAT_8002860c;
  cVar4 = '\x05';
  *(uint *)(param_1 + 0x1acc) =
       *(uint *)(param_1 + 0x1acc) & 0xffff81ff | (*(uint *)(param_2 + 0xc) & 0x3f) << 9;
  if ((*(uint *)(param_2 + 0xc) & 0x3f) != 7) {
    pcVar7 = FUN_80047788;
    uVar5 = 0x12;
    if (*(int *)(param_2 + 8) != 0) {
      iVar6 = 1;
      iVar1 = FUN_80058634(*(int *)(param_2 + 8),&DAT_80028618);
      if (iVar1 != 0) {
        puVar3 = *(undefined **)(param_2 + 8);
        cVar4 = (&DAT_800711bc)[*(int *)(param_2 + 0xc)];
      }
      FUN_800367d8(puVar3,0x16,0,(int)cVar4,0x12,local_30);
      FUN_80033a18(param_1 + 0x2530,(uint)local_30[0] * 0xc,0x10,1);
    }
  }
  FUN_800367d8(*(undefined4 *)(param_2 + 0x10),0x16,2,0xffffffff,uVar5,param_1 + 0x1ad0);
  uVar2 = FUN_80058624(*(undefined4 *)(param_2 + 0x10));
  iVar1 = FUN_80058654(((uVar2 & 0xff) - 4) + *(int *)(param_2 + 0x10),&DAT_80028624,4);
  uVar2 = 0;
  *(uint *)(param_1 + 0x1acc) =
       *(uint *)(param_1 + 0x1acc) & 0x7001feff | (uint)(iVar1 == 0) << 0x1f | iVar6 << 8 | 0xc0000;
  iVar6 = param_1 + 0x1ac0;
  do {
    if (*(char *)(iVar6 + 0x10) == '\0') {
      *(uint *)(param_1 + 0x1acc) = *(uint *)(param_1 + 0x1acc) & 0xfff1ffff | (uVar2 & 7) << 0x11;
      break;
    }
    uVar2 = uVar2 + 1;
    iVar6 = param_1 + 0x1ac0 + uVar2;
  } while ((int)uVar2 < 6);
  FUN_80032654(param_1 + 0x1ec0,pcVar7);
  return;
}



// ---- FUN_80047788 @ 80047788

void FUN_80047788(int param_1,undefined4 param_2)

{
  code *pcVar1;
  
  FUN_80032d9c(param_1 + 0x27b0,1);
  FUN_80032d9c(param_1 + 0x27f0,1);
  if ((*(uint *)(param_1 + 0x1af4) & 0x4000000) == 0) {
    if ((*(uint *)(param_1 + 0x1acc) & 0x20000000) == 0) {
      pcVar1 = FUN_800478d0;
      if ((*(uint *)(param_1 + 0x1acc) & 0x10000000) != 0) {
        pcVar1 = FUN_80047978;
      }
    }
    else {
      pcVar1 = FUN_800479d8;
    }
  }
  else {
    pcVar1 = FUN_8004783c;
  }
  FUN_80032654(param_2,pcVar1);
  return;
}



// ---- FUN_8004783c @ 8004783c

void FUN_8004783c(int param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  
  *(uint *)(param_2 + 0x18) =
       *(uint *)(param_2 + 0x18) & 0xfff00000 | (*(uint *)(param_2 + 0x18) & 0xfffff) + 1 & 0xfffff;
  iVar1 = FUN_8004a0a0();
  if (iVar1 == 1) {
    pcVar2 = FUN_800478d0;
    if ((*(uint *)(param_1 + 0x1acc) & 0x10000000) != 0) {
      pcVar2 = FUN_80047978;
    }
    FUN_80032654(param_2,pcVar2);
  }
  return;
}



// ---- FUN_800478d0 @ 800478d0

void FUN_800478d0(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar1 + 1 & 0xfffff;
  if (uVar1 < 0xf) {
    FUN_80033848(param_1 + 0x27b0,0,0xfffffff8,1);
    FUN_80033848(param_1 + 0x27f0,0,0xfffffff8,0xf);
  }
  else {
    *(uint *)(param_1 + 0x1acc) = *(uint *)(param_1 + 0x1acc) | 0x10000000;
    FUN_80032654(param_2,FUN_80047978);
  }
  return;
}



// ---- FUN_80047978 @ 80047978

void FUN_80047978(int param_1,undefined4 param_2)

{
  FUN_80032d9c(param_1 + 0x2530,*(uint *)(param_1 + 0x1acc) >> 8 & 1);
  FUN_80032d9c(param_1 + 0x2570,1);
  FUN_80032654(param_2,FUN_800479d8);
  return;
}



// ---- FUN_800479d8 @ 800479d8

void FUN_800479d8(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar2 + 1 & 0xfffff;
  uVar3 = *(uint *)(param_1 + 0x1acc);
  uVar1 = (uint)(byte)(&DAT_800711f8)[uVar3 >> 0xf & 3];
  if (uVar1 == 0) {
    trap(0x1c00);
  }
  if ((uVar1 == 0xffffffff) && (uVar2 == 0x80000000)) {
    trap(0x5d);
  }
  uVar4 = 1;
  if (uVar2 % uVar1 == 0) {
    if ((uVar3 & 0x18000) == 0x10000) {
      uVar4 = *(byte *)(param_1 + 0x1ac0 + (uVar3 >> 0x14 & 7) + 0x10) & 0x1f;
      *(uint *)(param_1 + 0x1acc) = uVar3 & 0xf07fffff | uVar4 << 0x17;
    }
    FUN_80033bc8(param_1 + 0x22b0 + (*(uint *)(param_1 + 0x1acc) >> 0xe & 0x1c0) + 0x2c0,uVar4 * 0xc
                 ,0,1);
    FUN_80032d9c(param_1 + 0x22b0 + (*(uint *)(param_1 + 0x1acc) >> 0xe & 0x1c0) + 0x2c0,
                 (*(uint *)(param_1 + 0x1acc) >> 0x1d ^ 1) & 1);
    uVar1 = *(uint *)(param_1 + 0x1acc);
    uVar2 = (uVar1 >> 0x17 & 0x1f) + 1 & 0x1f;
    *(uint *)(param_1 + 0x1acc) = uVar1 & 0xf07fffff | uVar2 << 0x17;
    if (*(byte *)(param_1 + 0x1ac0 + ((uVar1 & 0x700000) >> 0x14) + 0x10) < uVar2) {
      uVar2 = ((uVar1 & 0xf07fffff) >> 0x14 & 7) + 1 & 7;
      *(uint *)(param_1 + 0x1acc) = uVar1 & 0xf00fffff | uVar2 << 0x14;
      if ((uVar2 == (int)((ulonglong)(longlong)(int)uVar2 / 3) * 3) ||
         (uVar2 == (uVar1 & 0xe0000) >> 0x11)) {
        FUN_800358f0(param_1 + 0x470c,(uVar1 & 0xa0000000) == 0,1,1);
        FUN_80032654(param_2,FUN_80047c30);
      }
    }
  }
  else {
    FUN_800358f0(param_1 + 0x470c,0,1,1);
  }
  return;
}



// ---- FUN_80047c30 @ 80047c30

void FUN_80047c30(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar5 + 1 & 0xfffff;
  if (-1 < *(int *)(param_1 + 0x1acc)) {
    uVar1 = FUN_8002ba04(0x24);
    iVar2 = FUN_8002b8ac(0,uVar1,0,3,0);
    if (iVar2 != 0) goto LAB_80047cdc;
    if ((*(uint *)(param_1 + 0x1acc) & 0x80000000) == 0) {
      return;
    }
  }
  if (uVar5 < 0x1f) {
    return;
  }
LAB_80047cdc:
  FUN_80032d9c(param_1 + 0x2530,0);
  FUN_800358f0(param_1 + 0x470c,0,1,1);
  iVar6 = 0;
  iVar2 = 0x2c0;
  do {
    iVar4 = param_1 + 0x22b0 + iVar2;
    FUN_80032d9c(iVar4,0);
    FUN_80033a18(iVar4,0,0x10,1);
    iVar6 = iVar6 + 1;
    iVar2 = iVar2 + 0x40;
  } while (iVar6 < 6);
  FUN_80031268(0x500,0xffffffed);
  uVar5 = *(uint *)(param_1 + 0x1acc);
  if ((uVar5 >> 0x14 & 7) < (uVar5 >> 0x11 & 7)) {
    pcVar3 = FUN_800479d8;
  }
  else {
    pcVar3 = FUN_80047dc4;
    if ((uVar5 & 0x20000000) != 0) {
      pcVar3 = FUN_80047e90;
    }
  }
  FUN_80032654(param_2,pcVar3);
  return;
}



// ---- FUN_80047dc4 @ 80047dc4

void FUN_80047dc4(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar1 + 1 & 0xfffff;
  if (uVar1 < 0xf) {
    FUN_80033848(param_1 + 0x27b0,0,8,1);
    FUN_80033848(param_1 + 0x27f0,0,8,0xf);
  }
  else {
    *(uint *)(param_1 + 0x1acc) = *(uint *)(param_1 + 0x1acc) & 0xefffffff;
    FUN_80032d9c(param_1 + 0x27b0,0);
    FUN_80032d9c(param_1 + 0x27f0,0);
    FUN_80032654(param_2,FUN_80047e90);
  }
  return;
}



// ---- FUN_80047e90 @ 80047e90

void FUN_80047e90(int param_1,undefined4 param_2)

{
  *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 2;
  FUN_80032654(param_2,0);
  return;
}



// ---- FUN_80047ec4 @ 80047ec4

void FUN_80047ec4(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_80032d9c(param_1 + 0x26f0,1);
  FUN_800358f0(param_1 + 0x470c,0,1,1);
  iVar2 = 0;
  iVar3 = 0x2c0;
  do {
    iVar1 = iVar2;
    if (iVar2 < 0) {
      iVar1 = iVar2 + 3;
    }
    FUN_80033560(param_1 + 0x22b0 + iVar3,0x24,
                 ((iVar2 + (iVar1 >> 2) * -4) * 0x10 + 0x48) * 0x10000 >> 0x10,1);
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x40;
  } while (iVar2 < 6);
  FUN_80032654(param_2,FUN_80047f88);
  return;
}



// ---- FUN_80047f88 @ 80047f88

/* WARNING: Removing unreachable block (ram,0x800480c8) */

void FUN_80047f88(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  FUN_80033bc8(param_1 + 0x22b0 + (*(uint *)(param_1 + 0x1acc) >> 0xe & 0x1c0) + 0x2c0,0xc,0,1);
  FUN_80032d9c(param_1 + 0x22b0 + (*(uint *)(param_1 + 0x1acc) >> 0xe & 0x1c0) + 0x2c0,1);
  FUN_80033848(param_1 + 0x26f0,0xc,0,1);
  if (((*(uint *)(param_1 + 0x1acc) & 0xf800000) == 0) &&
     ((*(uint *)(param_1 + 0x1acc) >> 0x14 & 3) == 0)) {
    FUN_80031268(0x500,0xfffffffc);
  }
  uVar1 = *(uint *)(param_1 + 0x1acc);
  uVar2 = (uVar1 >> 0x17 & 0x1f) + 1 & 0x1f;
  *(uint *)(param_1 + 0x1acc) = uVar1 & 0xf07fffff | uVar2 << 0x17;
  if (*(byte *)(param_1 + ((uVar1 & 0x700000) >> 0x14) + 0x1ad0) < uVar2) {
    uVar2 = ((uVar1 & 0xf07fffff) >> 0x14 & 7) + 1;
    uVar3 = uVar2 & 7;
    *(uint *)(param_1 + 0x1acc) = uVar1 & 0xf00fffff | uVar3 << 0x14;
    if (3 >= uVar3) {
      FUN_80033560(param_1 + 0x26f0,0x24,
                   (int)(((uVar3 - (uVar2 & 4)) * 0x10 + 0x48) * 0x10000) >> 0x10,1);
    }
    uVar1 = *(uint *)(param_1 + 0x1acc) >> 0x14;
    if (((uVar1 & 3) == 0) || ((uVar1 & 7) == (*(uint *)(param_1 + 0x1acc) >> 0x11 & 7))) {
      if (3 < uVar3) {
        FUN_80033848(param_1 + 0x26f0,0xfffffff4,0,1);
      }
      FUN_800340c8(param_1 + 0x26f0,FUN_80048370);
      FUN_80032654(param_2,FUN_80048180);
    }
  }
  return;
}



// ---- FUN_80048180 @ 80048180

void FUN_80048180(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = FUN_8002ba04(0x24);
  iVar2 = FUN_8002b8ac(0,uVar1,0,3,0);
  iVar4 = param_1 + 0x26f0;
  if (iVar2 != 0) {
    FUN_80032d9c(iVar4,0);
    FUN_800340c8(iVar4,0);
    FUN_80033560(iVar4,0x24,0x48,1);
    iVar4 = 0;
    iVar2 = 0x2c0;
    do {
      iVar5 = param_1 + 0x22b0 + iVar2;
      FUN_80032d9c(iVar5,0);
      FUN_80033a18(iVar5,0,0x10,1);
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 0x40;
    } while (iVar4 < 6);
    pcVar3 = FUN_800482a0;
    if ((*(uint *)(param_1 + 0x1acc) >> 0x14 & 7) < (*(uint *)(param_1 + 0x1acc) >> 0x11 & 7)) {
      pcVar3 = FUN_80047f88;
    }
    FUN_80032654(param_2,pcVar3);
  }
  return;
}



// ---- FUN_800482a0 @ 800482a0

void FUN_800482a0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar3 = 0x2c0;
  iVar4 = 0;
  do {
    iVar1 = param_1 + 0x22b0 + iVar3;
    iVar3 = iVar3 + 0x40;
    FUN_80033560(iVar1,0xe,
                 ((iVar2 + (iVar4 - (iVar2 >> 0x1f)) * -3) * 0x10 + 0xad) * 0x10000 >> 0x10,1);
    iVar2 = iVar2 + 1;
    iVar4 = iVar2 / 3 + (iVar2 >> 0x1f);
  } while (iVar2 < 6);
  FUN_80032654(param_2,0);
  *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 2;
  return;
}



// ---- FUN_80048370 @ 80048370

void FUN_80048370(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_2 + 0x18);
  *(uint *)(param_2 + 0x18) = uVar2 & 0xfff00000 | (uVar2 & 0xfffff) + 1 & 0xfffff;
  if ((uVar2 & 3) == 0) {
    iVar1 = FUN_80032d9c(param_2,0xffffffff);
    FUN_80032d9c(param_2,iVar1 == 0);
  }
  return;
}



// ---- FUN_800483dc @ 800483dc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800483dc(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64 + 0x1edc;
  FUN_80032568(iVar1,0);
  FUN_80032288(iVar1,0,1);
  return;
}



// ---- FUN_80048424 @ 80048424

void FUN_80048424(int param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (*(int *)(param_2 + 8) != 0) {
    if (*(int *)(param_2 + 8) == 1) {
      FUN_80032654(param_1 + 0x1edc,FUN_800485b8);
      return;
    }
    return;
  }
  *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 4;
  uVar1 = *(uint *)(param_1 + 0x1ae0);
  uVar3 = *(undefined4 *)(param_2 + 0xc);
  *(uint *)(param_1 + 0x1ae0) = uVar1 & 0xfffffffb;
  *(undefined4 *)(param_1 + 0x1adc) = uVar3;
  iVar4 = *(int *)(param_2 + 0x10);
  if (iVar4 == 0x17c) {
LAB_800484d8:
    uVar1 = uVar1 & 0xfffffff8 | 1;
  }
  else {
    if (0x17c < iVar4) {
      if (iVar4 != 0x17d) goto LAB_800484e8;
      goto LAB_800484d8;
    }
    if (iVar4 != 0x17b) goto LAB_800484e8;
    uVar1 = uVar1 & 0xfffffff8;
  }
  *(uint *)(param_1 + 0x1ae0) = uVar1;
LAB_800484e8:
  (**(code **)(param_1 + 0x1ad8))
            (param_1,*(undefined4 *)(param_1 + 0x1adc),*(uint *)(param_1 + 0x1ae0) & 3);
  if ((*(int *)(param_2 + 0x14) == 1) && (piVar2 = &DAT_800711fc, DAT_800711fc != 0)) {
    do {
      iVar4 = *piVar2;
      piVar2 = piVar2 + 1;
      if (iVar4 == *(int *)(param_1 + 0x1adc)) {
        uVar1 = *(uint *)(param_1 + 0x198c);
        *(uint *)(param_1 + 0x198c) = uVar1 + 1;
        *(ushort *)((uVar1 & 0x7f) * 2 + param_1 + 0x1990) =
             *(byte *)(param_1 + 0x1ae0) & 3 | *(short *)(param_1 + 0x1adc) << 1;
        return;
      }
    } while (*piVar2 != 0);
  }
  return;
}



// ---- FUN_800485b8 @ 800485b8

void FUN_800485b8(int param_1,undefined4 param_2)

{
  if ((*(uint *)(param_1 + 0x1ae0) & 4) != 0) {
    *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 4;
    FUN_80032654(param_2,0);
  }
  return;
}



// ---- FUN_80048600 @ 80048600

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80048600(undefined4 param_1)

{
  *(undefined4 *)(_DAT_800abf64 + 0x1ad8) = param_1;
  return;
}



// ---- FUN_80048630 @ 80048630

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80048630(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64 + 0x1ef8;
  FUN_80032568(iVar1,0);
  FUN_80032288(iVar1,0,1);
  iVar1 = _DAT_800abf64 + 0x202c;
  FUN_80032568(iVar1,0);
  FUN_80032288(iVar1,0,1);
  iVar1 = _DAT_800abf64 + 0x2048;
  FUN_80032568(iVar1,0);
  FUN_80032288(iVar1,0,1);
  return;
}



// ---- FUN_800486c8 @ 800486c8

void FUN_800486c8(int param_1,int param_2)

{
  int *piVar1;
  undefined **ppuVar2;
  int iVar3;
  code *pcVar4;
  uint uVar5;
  
  if (*(int *)(param_2 + 8) == 0) {
    if (*(int *)(param_2 + 0xc) == 0x24c) {
      *(undefined4 *)(param_1 + 0x1aec) = 0xffffffff;
      uVar5 = *(uint *)(param_2 + 0x1c);
      *(undefined2 *)(param_1 + 0x1af2) = 0;
      *(undefined4 *)(param_1 + 0x1ae8) = 0;
      *(undefined4 *)(param_1 + 0x1b20) = 0;
      *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) & 0xfffffdff | (uVar5 & 1) << 9;
      *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) & 0xfff7fffe;
      *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) & 0xfff803fd | 0x1f8;
      FUN_80032654(param_1 + 0x1ef8,FUN_80048fd4);
      FUN_80032654(param_1 + 0x202c,0);
      iVar3 = param_1 + 0x2048;
      pcVar4 = (code *)0x0;
    }
    else {
      *(int *)(param_1 + 0x1aec) = *(int *)(param_2 + 0xc);
      uVar5 = *(uint *)(param_2 + 0x1c);
      *(undefined2 *)(param_1 + 0x1af2) = 0;
      *(undefined4 *)(param_1 + 0x1ae8) = 0;
      *(undefined4 *)(param_1 + 0x1b20) = 0;
      *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) & 0xfffffdff | (uVar5 & 1) << 9;
      *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) & 0xfff7fffe;
      *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) & 0xfff803fd | 0x1f8;
      (**(code **)(param_1 + 0x1ae4))(param_1,*(undefined4 *)(param_2 + 0xc));
      if ((*(uint *)(param_1 + 0x1af4) & 0x80000) == 0) {
        *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) | 1;
        FUN_80032654(param_1 + 0x1ef8,FUN_80048db0);
        FUN_80032654(param_1 + 0x202c,FUN_800490b4);
        uVar5 = 0;
        if (DAT_800712d8 != 0) {
          piVar1 = &DAT_800712dc;
          do {
            uVar5 = uVar5 + 1;
            if (*(int *)(param_1 + 0x1aec) == *piVar1) {
              *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) | 2;
              return;
            }
            piVar1 = piVar1 + 1;
          } while (uVar5 < DAT_800712d8);
        }
        ppuVar2 = &PTR_DAT_8008c020;
        uVar5 = 0;
        if (PTR_DAT_8008c020 == (undefined *)0x0) {
          return;
        }
        piVar1 = (int *)PTR_DAT_8008c020;
        while (ppuVar2 = ppuVar2 + 1, *piVar1 != *(int *)(param_1 + 0x1aec)) {
          piVar1 = (int *)*ppuVar2;
          uVar5 = uVar5 + 1;
          if (piVar1 == (int *)0x0) {
            return;
          }
        }
        iVar3 = param_1 + 0x2048;
        pcVar4 = FUN_80049144;
        *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) & 0xfffffe07 | (uVar5 & 0x3f) << 3
        ;
      }
      else {
        pcVar4 = FUN_80048ac8;
        iVar3 = param_1 + 0x1ef8;
        if ((*(uint *)(param_1 + 0x1acc) & 0x10000000) != 0) {
          pcVar4 = FUN_800489d8;
        }
      }
    }
  }
  else {
    if (*(int *)(param_2 + 8) != 1) {
      return;
    }
    iVar3 = param_1 + 0x1ef8;
    if ((*(uint *)(param_1 + 0x1af4) & 2) != 0) {
      *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 8;
      return;
    }
    pcVar4 = FUN_80048e18;
    *(undefined2 *)(param_1 + 0x1af0) = *(undefined2 *)(param_2 + 0x10);
    if ((*(uint *)(param_1 + 0x1af4) & 1) != 0) {
      pcVar4 = FUN_80048f60;
    }
  }
  FUN_80032654(iVar3,pcVar4);
  return;
}



// ---- FUN_800489d8 @ 800489d8

void FUN_800489d8(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar1 + 1 & 0xfffff;
  if (uVar1 < 0xf) {
    FUN_80033848(param_1 + 0x27b0,0,8,1);
    FUN_80033848(param_1 + 0x27f0,0,8,0xf);
    FUN_80035740(param_1 + 0x470c,0,8);
  }
  else {
    FUN_80032d9c(param_1 + 0x27b0,0);
    FUN_80032d9c(param_1 + 0x27f0,0);
    FUN_800358f0(param_1 + 0x470c,0,1,1);
    *(uint *)(param_1 + 0x1acc) = *(uint *)(param_1 + 0x1acc) & 0xefffffff;
    FUN_80032654(param_2,FUN_80048ac8);
  }
  return;
}



// ---- FUN_80048ac8 @ 80048ac8

void FUN_80048ac8(int param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  
  if ((*(uint *)(param_1 + 0x1af4) & 0x4000000) == 0) {
    if ((*(uint *)(param_1 + 0x1af4) & 0x3800000) == 0) {
      pcVar1 = FUN_80048cdc;
    }
    else {
      FUN_80032d9c(param_1 + 0x2830,1);
      iVar2 = param_1 + 0x2870;
      FUN_80032d9c(iVar2,1);
      FUN_80033560(param_1 + 0x2830,0,0x10c,1);
      FUN_80033560(iVar2,0,0x113,1);
      FUN_80033a18(iVar2,0x100,0x42,0x40);
      pcVar1 = FUN_80048bac;
    }
  }
  else {
    pcVar1 = FUN_80048c54;
  }
  FUN_80032654(param_2,pcVar1);
  return;
}



// ---- FUN_80048bac @ 80048bac

void FUN_80048bac(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar1 + 1 & 0xfffff;
  if (uVar1 < 0xf) {
    FUN_80033848(param_1 + 0x2830,0,0xfffffff8,1);
    FUN_80033848(param_1 + 0x2870,0,0xfffffff8,0xf);
  }
  else {
    *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) | 0x4000000;
    FUN_80032654(param_2,FUN_80048c54);
  }
  return;
}



// ---- FUN_80048c54 @ 80048c54

void FUN_80048c54(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  param_1 = param_1 + 0x4934;
  iVar3 = 0;
  do {
    iVar1 = 0;
    iVar2 = param_1;
    do {
      param_1 = iVar2 + 0x5c;
      FUN_8003541c(iVar2,3);
      iVar1 = iVar1 + 1;
      iVar2 = param_1;
    } while (iVar1 < 3);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  FUN_80032654(param_2,FUN_80048cdc);
  return;
}



// ---- FUN_80048cdc @ 80048cdc

void FUN_80048cdc(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (*(int *)(param_1 + 0x1af4) << 9) >> 0x1d;
  if (iVar1 < 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = iVar1 % 3;
  }
  FUN_800317a4(*(undefined4 *)(&DAT_80071328 + iVar1 * 4));
  *(undefined4 *)(param_1 + 0x544) = 0;
  if ((*(uint *)(param_1 + 0x1af4) & 0x200) != 0) {
    FUN_80031268(0x301,*(undefined4 *)(param_1 + 0x1aec));
  }
  *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 8;
  FUN_80032654(param_2,0);
  return;
}



// ---- FUN_80048db0 @ 80048db0

void FUN_80048db0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x544) = 0;
  if ((*(uint *)(param_1 + 0x1af4) & 0x200) != 0) {
    FUN_80031268(0x300,*(undefined4 *)(param_1 + 0x1aec));
  }
  *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 8;
  FUN_80032654(param_2,0);
  return;
}



// ---- FUN_80048e18 @ 80048e18

void FUN_80048e18(int param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  
  if (((*(code **)(param_1 + 0x1ae8) == (code *)0x0) ||
      (iVar1 = (**(code **)(param_1 + 0x1ae8))(param_1,0), iVar1 != 0)) &&
     (iVar1 = FUN_800315cc(3), iVar1 == 0)) {
    FUN_8004976c();
    pcVar2 = FUN_80048f18;
    if ((*(uint *)(param_1 + 0x1af4) & 0x3800000) == 0x800000) {
      pcVar2 = FUN_80048eac;
    }
    FUN_80032654(param_2,pcVar2);
  }
  return;
}



// ---- FUN_80048eac @ 80048eac

void FUN_80048eac(undefined4 param_1,int param_2)

{
  int iVar1;
  
  *(uint *)(param_2 + 0x18) =
       *(uint *)(param_2 + 0x18) & 0xfff00000 | (*(uint *)(param_2 + 0x18) & 0xfffff) + 1 & 0xfffff;
  iVar1 = FUN_8004a0a0();
  if (iVar1 == 1) {
    FUN_80032654(param_2,FUN_80048f18);
  }
  return;
}



// ---- FUN_80048f18 @ 80048f18

void FUN_80048f18(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x544) = 1;
  *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) | 0x3800000;
  *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 8;
  FUN_80032654(param_2,0);
  return;
}



// ---- FUN_80048f60 @ 80048f60

void FUN_80048f60(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_800315cc(3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x544) = 1;
    *(undefined4 *)(param_1 + 0x1aec) = 0xffffffff;
    FUN_80032654(param_1 + 0x202c,0);
    *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 8;
    FUN_80032654(param_2,0);
  }
  return;
}



// ---- FUN_80048fd4 @ 80048fd4

void FUN_80048fd4(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_800315cc(3);
  switch(uVar1) {
  case 0:
    *(undefined4 *)(param_1 + 0x544) = 1;
    *(undefined4 *)(param_1 + 0x1aec) = 0xffffffff;
    *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 8;
    *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) & 0xfffffffb;
    FUN_80032654(param_2,0);
    break;
  case 4:
    if ((*(uint *)(param_1 + 0x1af4) & 4) == 0) {
      FUN_80031268(0,0xd4);
      *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) | 4;
    }
  }
  return;
}



// ---- FUN_800490b4 @ 800490b4

void FUN_800490b4(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_800315cc(3);
  switch(uVar1) {
  case 0:
    if ((*(uint *)(param_1 + 0x1af4) & 0x202) == 0x202) {
      FUN_80031268(0x300,*(undefined4 *)(param_1 + 0x1aec));
    }
    break;
  case 4:
    *(int *)(param_1 + 0x1b20) = *(int *)(param_1 + 0x1b20) + 1;
  }
  return;
}



// ---- FUN_80049144 @ 80049144

void FUN_80049144(int param_1,int param_2)

{
  uint uVar1;
  code *pcVar2;
  undefined4 *puVar3;
  
  uVar1 = *(uint *)(param_1 + 0x1af4) >> 0xb & 0xff;
  if (uVar1 == *(uint *)((&PTR_DAT_8008c020)[(int)(*(uint *)(param_1 + 0x1af4) << 0x17) >> 0x1a] + 8
                        )) {
    pcVar2 = (code *)0x0;
  }
  else {
    puVar3 = (undefined4 *)
             (uVar1 * 8 +
             *(int *)((&PTR_DAT_8008c020)[(int)(*(uint *)(param_1 + 0x1af4) << 0x17) >> 0x1a] + 4));
    if (*(uint *)(param_1 + 0x1b20) < (uint)*(ushort *)(puVar3 + 1)) {
      return;
    }
    (**(code **)(param_1 + 0x1ae4))(param_1,*puVar3);
    pcVar2 = FUN_800492fc;
    param_2 = param_1 + 0x2048;
    if ((*(uint *)(param_1 + 0x1acc) & 0x10000000) != 0) {
      pcVar2 = FUN_8004920c;
    }
  }
  FUN_80032654(param_2,pcVar2);
  return;
}



// ---- FUN_8004920c @ 8004920c

void FUN_8004920c(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar1 + 1 & 0xfffff;
  if (uVar1 < 0xf) {
    FUN_80033848(param_1 + 0x27b0,0,8,1);
    FUN_80033848(param_1 + 0x27f0,0,8,0xf);
    FUN_80035740(param_1 + 0x470c,0,8);
  }
  else {
    FUN_80032d9c(param_1 + 0x27b0,0);
    FUN_80032d9c(param_1 + 0x27f0,0);
    FUN_800358f0(param_1 + 0x470c,0,1,1);
    *(uint *)(param_1 + 0x1acc) = *(uint *)(param_1 + 0x1acc) & 0xefffffff;
    FUN_80032654(param_2,FUN_800492fc);
  }
  return;
}



// ---- FUN_800492fc @ 800492fc

void FUN_800492fc(int param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  
  if ((*(uint *)(param_1 + 0x1af4) & 0x4000000) == 0) {
    if ((*(uint *)(param_1 + 0x1af4) & 0x3800000) == 0) {
      pcVar1 = FUN_80049510;
    }
    else {
      FUN_80032d9c(param_1 + 0x2830,1);
      iVar2 = param_1 + 0x2870;
      FUN_80032d9c(iVar2,1);
      FUN_80033560(param_1 + 0x2830,0,0x10c,1);
      FUN_80033560(iVar2,0,0x113,1);
      FUN_80033a18(iVar2,0x100,0x42,0x40);
      pcVar1 = FUN_800493e0;
    }
  }
  else {
    pcVar1 = FUN_80049488;
  }
  FUN_80032654(param_2,pcVar1);
  return;
}



// ---- FUN_800493e0 @ 800493e0

void FUN_800493e0(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar1 + 1 & 0xfffff;
  if (uVar1 < 0xf) {
    FUN_80033848(param_1 + 0x2830,0,0xfffffff8,1);
    FUN_80033848(param_1 + 0x2870,0,0xfffffff8,0xf);
  }
  else {
    *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) | 0x4000000;
    FUN_80032654(param_2,FUN_80049488);
  }
  return;
}



// ---- FUN_80049488 @ 80049488

void FUN_80049488(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  param_1 = param_1 + 0x4934;
  iVar3 = 0;
  do {
    iVar1 = 0;
    iVar2 = param_1;
    do {
      param_1 = iVar2 + 0x5c;
      FUN_8003541c(iVar2,3);
      iVar1 = iVar1 + 1;
      iVar2 = param_1;
    } while (iVar1 < 3);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  FUN_80032654(param_2,FUN_80049510);
  return;
}



// ---- FUN_80049510 @ 80049510

void FUN_80049510(int param_1)

{
  uint uVar1;
  code *pcVar2;
  undefined *puVar3;
  
  puVar3 = (&PTR_DAT_8008c020)[(*(int *)(param_1 + 0x1af4) << 0x17) >> 0x1a];
  if (*(code **)(param_1 + 0x1ae8) != (code *)0x0) {
    (**(code **)(param_1 + 0x1ae8))(param_1,0);
  }
  uVar1 = *(uint *)(param_1 + 0x1af4) >> 0xb & 0xff;
  if ((uint)*(ushort *)(uVar1 * 8 + *(int *)(puVar3 + 4) + 6) <= *(uint *)(param_1 + 0x1b20)) {
    *(uint *)(param_1 + 0x1af4) =
         *(uint *)(param_1 + 0x1af4) & 0xfff807ff | (uVar1 + 1 & 0xff) << 0xb;
    FUN_8004976c();
    pcVar2 = FUN_8004965c;
    if ((*(uint *)(param_1 + 0x1af4) & 0x3800000) == 0x800000) {
      pcVar2 = FUN_800495f0;
    }
    FUN_80032654(param_1 + 0x2048,pcVar2);
  }
  return;
}



// ---- FUN_800495f0 @ 800495f0

void FUN_800495f0(undefined4 param_1,int param_2)

{
  int iVar1;
  
  *(uint *)(param_2 + 0x18) =
       *(uint *)(param_2 + 0x18) & 0xfff00000 | (*(uint *)(param_2 + 0x18) & 0xfffff) + 1 & 0xfffff;
  iVar1 = FUN_8004a0a0();
  if (iVar1 == 1) {
    FUN_80032654(param_2,FUN_8004965c);
  }
  return;
}



// ---- FUN_8004965c @ 8004965c

void FUN_8004965c(int param_1,undefined4 param_2)

{
  *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) | 0x3800000;
  FUN_80032654(param_2,FUN_80049144);
  return;
}



// ---- FUN_80049698 @ 80049698

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80049698(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = _DAT_800abf64 + 0x2010;
  FUN_80032568(iVar4,0);
  FUN_80032288(iVar4,0,1);
  iVar3 = 0;
  iVar1 = _DAT_800abf64 + 0x4934;
  iVar2 = 0;
  do {
    do {
      FUN_80034bec(iVar1);
      FUN_80032288(iVar1,iVar4,1);
      FUN_80034e00(iVar1,0,0);
      FUN_8003541c(iVar1,0xf);
      FUN_80035434(iVar1,1);
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x5c;
    } while (iVar2 < 3);
    iVar3 = iVar3 + 1;
    iVar2 = 0;
  } while (iVar3 < 3);
  return;
}



// ---- FUN_8004976c @ 8004976c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8004976c(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = _DAT_800abf64;
  uVar1 = *(uint *)(_DAT_800abf64 + 0x1af4);
  *(undefined4 *)(_DAT_800abf64 + 0x1aec) = 0xffffffff;
  uVar2 = uVar1 & 0x700000;
  *(undefined4 *)(iVar4 + 0x1ae8) = 0;
  if ((uVar2 != 0x700000) && (uVar2 != 0x600000)) {
    iVar3 = ((int)(uVar1 << 9) >> 0x1d) * 0x114 + 0x4934 + iVar4;
    FUN_80035458(iVar3,0xffffffff,0,0);
    FUN_80035ab8(iVar3,0);
  }
  if (*(char *)(iVar4 + 0x1afb) != -1) {
    iVar3 = *(char *)(iVar4 + 0x1afb) * 0x5c + 0x6370 + _DAT_800abf64;
    FUN_80035458(iVar3,0xffffffff,0,0);
    FUN_80035ab8(iVar3,0);
  }
  if ((*(uint *)(iVar4 + 0x1af4) & 0x3800000) == 0x1000000) {
    iVar4 = ((int)(*(uint *)(iVar4 + 0x1af4) << 9) >> 0x1d) * 0x114 + 0x4934 + _DAT_800abf64;
    FUN_800358f0(iVar4,0,0,0);
    FUN_800358f0(iVar4 + 0x5c,0,0,0);
    FUN_800358f0(iVar4 + 0xb8,0,0,0);
  }
  return;
}



// ---- FUN_800498d4 @ 800498d4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800498d4(undefined4 param_1)

{
  *(undefined4 *)(_DAT_800abf64 + 0x1ae4) = param_1;
  return;
}



// ---- FUN_80049904 @ 80049904

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80049904(int param_1,int param_2,undefined4 param_3,uint param_4,uint param_5,uint param_6)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 auStack_68 [48];
  undefined1 local_38;
  undefined1 local_37;
  undefined1 auStack_36 [2];
  int local_34;
  undefined4 local_30;
  
  iVar5 = _DAT_800abf64;
  iVar7 = _DAT_800abf64 + 0x1ac0;
  if (param_1 == -2) {
    *(undefined1 *)(_DAT_800abf64 + 0x1afb) = 0xff;
  }
  else {
    uVar4 = (undefined1)param_1;
    local_38 = uVar4;
    local_30 = param_3;
    if (param_1 == -1) {
      *(char *)(_DAT_800abf64 + 0x1afb) = (char)param_2;
      local_37 = 0;
      FUN_800585e4(auStack_36,2);
      local_34 = 0;
      iVar5 = param_2 * 0x5c + 0x6370 + _DAT_800abf64;
      FUN_80032684(iVar5,&local_38,8);
      FUN_80035458(iVar5,param_6,0,0);
      FUN_800358f0(iVar5,1,0,0);
      FUN_80035ab8(iVar5,FUN_80049fac);
    }
    else {
      iVar6 = param_1 * 0x114 + 0x4934 + _DAT_800abf64;
      if (param_2 < 0) {
        *(undefined1 *)(iVar7 + param_1 + 0x38) = 0xff;
        iVar5 = 0;
        do {
          FUN_8003541c(iVar6,0xf);
          FUN_8003571c(iVar6,(param_1 * 0x48 + 0x18) * 0x10000 >> 0x10,0x9c);
          FUN_800358f0(iVar6,0,0,0);
          FUN_80035ab8(iVar6,0);
          iVar5 = iVar5 + 1;
          iVar6 = iVar6 + 0x5c;
        } while (iVar5 < 3);
      }
      else {
        FUN_8002ca58(0,auStack_68,param_2 * 0x4800 + -0x7fecb000,0,0xffffffff);
        iVar7 = iVar7 + param_1;
        if (*(char *)(iVar7 + 0x38) != param_2) {
          *(char *)(iVar7 + 0x38) = (char)param_2;
          FUN_8002cf6c(auStack_68,param_1 + -0x7ff8eccc,0);
          iVar3 = 0;
          iVar7 = iVar6;
          do {
            FUN_80034e34(iVar7,auStack_68,0);
            FUN_800351a0(iVar7,param_1 + -0x7ff8eccc,0,0xffffffff);
            iVar3 = iVar3 + 1;
            iVar7 = iVar7 + 0x5c;
          } while (iVar3 < 3);
        }
        FUN_8002d178(auStack_68,&DAT_80071338 + param_1,&DAT_8007133c + param_1,4,local_30);
        iVar3 = 0;
        iVar7 = iVar6;
        do {
          uVar1 = 0xf;
          if ((*(uint *)(iVar5 + 0x1af4) & 0x4000000) != 0) {
            uVar1 = 3;
          }
          FUN_8003541c(iVar7,uVar1);
          FUN_8003571c(iVar7,(param_1 * 0x48 + 0x18) * 0x10000 >> 0x10,0x9c);
          iVar3 = iVar3 + 1;
          FUN_80035694(iVar7,(&DAT_80071338)[param_1],(&DAT_8007133c)[param_1]);
          iVar7 = iVar7 + 0x5c;
        } while (iVar3 < 3);
        if (param_6 == 0xfffffffd) {
          FUN_80035458(iVar6,0xffffffff,0,1);
          FUN_80035458(iVar6 + 0x5c,param_5,0,1);
          FUN_80035458(iVar6 + 0xb8,param_4,0,1);
          FUN_800358f0(iVar6,0,0,0);
          uVar1 = 0;
        }
        else {
          if (param_6 != 0xfffffffe) {
            FUN_80035458(iVar6,param_6,0,1);
            iVar7 = iVar6 + 0x5c;
            FUN_80035458(iVar7,param_5,0,1);
            iVar5 = iVar6 + 0xb8;
            FUN_80035458(iVar5,param_4,0,1);
            FUN_800358f0(iVar6,~param_6 >> 0x1f,0,0);
            FUN_800358f0(iVar7,~param_5 >> 0x1f,0,0);
            FUN_800358f0(iVar5,~param_4 >> 0x1f,0,0);
            pcVar2 = (code *)0x0;
            if (-1 < (int)param_6) {
              pcVar2 = FUN_80049fac;
            }
            FUN_80035ab8(iVar6,pcVar2);
            pcVar2 = (code *)0x0;
            if (-1 < (int)param_5) {
              pcVar2 = FUN_80049e8c;
            }
            FUN_80035ab8(iVar7,pcVar2);
            FUN_80035ab8(iVar5,0);
            local_37 = 0;
            FUN_800585e4(auStack_36,2);
            iVar3 = FUN_80058674();
            iVar5 = iVar3;
            if (iVar3 < 0) {
              iVar5 = iVar3 + 7;
            }
            local_34 = (iVar3 + (iVar5 >> 3) * -8) * 8 + -0x7ff8ecc0;
            FUN_80032684(iVar7,&local_38,8);
            local_37 = 0;
            local_38 = uVar4;
            FUN_800585e4(auStack_36,2);
            local_34 = 0;
            FUN_80032684(iVar6,&local_38,8);
            return;
          }
          FUN_80035458(iVar6,0xffffffff,0,1);
          FUN_80035458(iVar6 + 0x5c,param_5,0,1);
          FUN_80035458(iVar6 + 0xb8,param_4,0,1);
          FUN_800358f0(iVar6,0,0,0);
          uVar1 = 1;
        }
        FUN_800358f0(iVar6 + 0x5c,1,1,uVar1);
        FUN_800358f0(iVar6 + 0xb8,1,1,0);
        FUN_80035ab8(iVar6,0);
        FUN_80035ab8(iVar6 + 0x5c,0);
        FUN_80035ab8(iVar6 + 0xb8,0);
      }
    }
  }
  return;
}



// ---- FUN_80049e8c @ 80049e8c

void FUN_80049e8c(undefined4 param_1,int param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar2 + 1 & 0xfffff;
  if (*(ushort *)((uint)*(byte *)(param_3 + 1) * 2 + *(int *)(param_3 + 4)) < uVar2) {
    if (*(byte *)(param_3 + 1) == 3) {
      cVar1 = '\0';
    }
    else {
      cVar1 = *(char *)(param_3 + 1) + '\x01';
    }
    *(char *)(param_3 + 1) = cVar1;
    FUN_80035458(param_2,0xffffffff,0,1);
    FUN_800358f0(param_2,1,1,0);
    FUN_80035ab8(param_2,FUN_80049f54);
  }
  return;
}



// ---- FUN_80049f54 @ 80049f54

void FUN_80049f54(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_80035654(param_2,0);
  if (iVar1 == 0) {
    FUN_800358f0(param_2,0,1,0);
    FUN_80035ab8(param_2,FUN_80049e8c);
  }
  return;
}



// ---- FUN_80049fac @ 80049fac

void FUN_80049fac(int param_1,undefined4 param_2,char *param_3)

{
  undefined2 uVar1;
  
  if ((*(int *)(param_1 + 0x1af4) << 9) >> 0x1d == (int)*param_3) {
    uVar1 = FUN_800316f0();
    FUN_80035458(param_2,0xffffffff,uVar1,0);
  }
  return;
}



// ---- FUN_8004a0a0 @ 8004a0a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8004a0a0(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = _DAT_800abf64;
  iVar3 = _DAT_800abf64 + 0x4934;
  if (param_1 < 0xf) {
    FUN_80033848(_DAT_800abf64 + 0x2830,0,8,1);
    FUN_80033848(iVar2 + 0x2870,0,8,0xf);
    iVar5 = 0;
    iVar2 = 0;
    do {
      do {
        iVar4 = iVar3 + 0x5c;
        FUN_80035740(iVar3,0,8);
        iVar2 = iVar2 + 1;
        iVar3 = iVar4;
      } while (iVar2 < 3);
      iVar5 = iVar5 + 1;
      iVar2 = 0;
    } while (iVar5 < 3);
    uVar1 = 0;
  }
  else {
    iVar5 = _DAT_800abf64 + 0x2830;
    iVar4 = 0;
    *(uint *)(_DAT_800abf64 + 0x1af4) = *(uint *)(_DAT_800abf64 + 0x1af4) & 0xfbffffff;
    FUN_80032d9c(iVar5,0);
    FUN_80032d9c(iVar2 + 0x2870,0);
    do {
      iVar2 = 0;
      do {
        FUN_80035ab8(iVar3,0);
        FUN_800358f0(iVar3,0,0,0);
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x5c;
      } while (iVar2 < 3);
      iVar4 = iVar4 + 1;
      uVar1 = 1;
    } while (iVar4 < 3);
  }
  return uVar1;
}



// ---- FUN_8004a1c4 @ 8004a1c4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8004a1c4(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64 + 0x1f14;
  FUN_80032568(iVar1,0);
  FUN_80032288(iVar1,0,1);
  return;
}



// ---- FUN_8004a20c @ 8004a20c

void FUN_8004a20c(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  if (*(int *)(param_2 + 8) == 0) {
    *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x10;
    iVar3 = *(int *)(param_2 + 0xc);
    if (*(int *)(param_1 + 0x1afc) != iVar3) {
      if ((iVar3 == 0x24c) || (iVar3 - 0x9baU < 2)) {
        if (*(int *)(param_1 + 0x1afc) != -1) {
          FUN_80031268(0,0xd1);
        }
        *(undefined4 *)(param_1 + 0x1afc) = 0xffffffff;
        *(undefined2 *)(param_1 + 0x1b00) = 0;
        *(uint *)(param_1 + 0x1b04) = *(uint *)(param_1 + 0x1b04) & 0xfffffffe;
      }
      else {
        *(int *)(param_1 + 0x1afc) = iVar3;
        *(undefined2 *)(param_1 + 0x1b00) = 0;
        *(uint *)(param_1 + 0x1b04) = *(uint *)(param_1 + 0x1b04) & 0xfffffffe;
        FUN_80031268(0x200,*(undefined4 *)(param_1 + 0x1afc));
        uVar1 = DAT_80071380;
        uVar2 = 0;
        if (DAT_80071380 != 0) {
          piVar4 = &DAT_80071384;
          do {
            iVar3 = *piVar4;
            piVar4 = piVar4 + 1;
            if (*(int *)(param_1 + 0x1afc) == iVar3) {
              *(uint *)(param_1 + 0x1b04) = *(uint *)(param_1 + 0x1b04) | 1;
            }
            uVar2 = uVar2 + 1;
          } while (uVar2 < uVar1);
        }
      }
    }
  }
  else if (*(int *)(param_2 + 8) == 1) {
    *(undefined2 *)(param_1 + 0x1b02) = *(undefined2 *)(param_2 + 0x10);
    if (*(short *)(param_1 + 0x1b02) == 0) {
      *(undefined4 *)(param_1 + 0x1afc) = 0xffffffff;
      *(undefined2 *)(param_1 + 0x1b00) = 0;
      *(uint *)(param_1 + 0x1b04) = *(uint *)(param_1 + 0x1b04) & 0xfffffffe;
      *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x10;
    }
    else {
      FUN_80032654(param_1 + 0x1f14,FUN_8004a39c);
    }
  }
  return;
}



// ---- FUN_8004a39c @ 8004a39c

void FUN_8004a39c(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar1 + 1 & 0xfffff;
  if (*(ushort *)(param_1 + 0x1b02) < uVar1) {
    FUN_80031268(0,0xd1);
    *(undefined4 *)(param_1 + 0x1afc) = 0xffffffff;
    *(undefined2 *)(param_1 + 0x1b00) = 0;
    *(uint *)(param_1 + 0x1b04) = *(uint *)(param_1 + 0x1b04) & 0xfffffffe;
    *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x10;
    FUN_80032654(param_2,0);
  }
  return;
}



// ---- FUN_8004a444 @ 8004a444

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8004a444(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64 + 0x1f30;
  FUN_80032568(iVar1,0);
  FUN_80032288(iVar1,0,1);
  return;
}



// ---- FUN_8004a48c @ 8004a48c

void FUN_8004a48c(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  if (*(int *)(param_2 + 8) == 0) {
    *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x20;
    iVar3 = *(int *)(param_2 + 0xc);
    if (iVar3 == 0x9b9) {
      *(undefined4 *)(param_1 + 0x1b10) = *(undefined4 *)(param_1 + 0x1b08);
    }
    else {
      if (iVar3 < 0x9ba) {
        if (iVar3 == 0x24c) {
          FUN_80031268(0,0xd2);
          return;
        }
        if (iVar3 == 0x9b8) {
          *(undefined4 *)(param_1 + 0x1b10) = 0xffffffff;
          return;
        }
      }
      else {
        if (iVar3 == 0x9ba) {
          FUN_80031268(0x1500,*(undefined4 *)(param_1 + 0x1b08));
          uVar1 = DAT_800713f4;
          uVar2 = 0;
          if (DAT_800713f4 != 0) {
            piVar4 = &DAT_800713f8;
            do {
              iVar3 = *piVar4;
              piVar4 = piVar4 + 1;
              if (*(int *)(param_1 + 0x1b08) == iVar3) {
                *(undefined4 *)(param_1 + 0x1b10) = 0xffffffff;
              }
              uVar2 = uVar2 + 1;
            } while (uVar2 < uVar1);
          }
          *(undefined2 *)(param_1 + 0x1b0c) = 0;
          return;
        }
        if (iVar3 == 0x9bb) {
          FUN_80031268(0,0x72);
          *(undefined4 *)(param_1 + 0x1b08) = 0xffffffff;
          *(undefined2 *)(param_1 + 0x1b0c) = 0;
          return;
        }
      }
      if ((*(int *)(param_1 + 0x1b10) == -1) ||
         (*(int *)(param_1 + 0x1b10) != *(int *)(param_2 + 0xc))) {
        *(undefined4 *)(param_1 + 0x1b08) = *(undefined4 *)(param_2 + 0xc);
        *(undefined2 *)(param_1 + 0x1b0c) = 0;
        FUN_80031268(0x500,*(undefined4 *)(param_1 + 0x1b08));
      }
    }
  }
  else if (*(int *)(param_2 + 8) == 1) {
    *(undefined2 *)(param_1 + 0x1b0e) = *(undefined2 *)(param_2 + 0x10);
    if (*(short *)(param_1 + 0x1b0e) == 0) {
      *(undefined4 *)(param_1 + 0x1b08) = 0xffffffff;
      *(undefined2 *)(param_1 + 0x1b0c) = 0;
      *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x20;
    }
    else {
      FUN_80032654(param_1 + 0x1f30,FUN_8004a66c);
    }
  }
  return;
}



// ---- FUN_8004a66c @ 8004a66c

void FUN_8004a66c(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar1 + 1 & 0xfffff;
  if (*(ushort *)(param_1 + 0x1b0e) < uVar1) {
    FUN_80031268(0x1500,*(undefined4 *)(param_1 + 0x1b08));
    *(undefined4 *)(param_1 + 0x1b08) = 0xffffffff;
    *(undefined2 *)(param_1 + 0x1b0c) = 0;
    *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x20;
    FUN_80032654(param_2,0);
  }
  return;
}



// ---- FUN_8004a70c @ 8004a70c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8004a70c(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64 + 0x1f68;
  FUN_80032568(iVar1,0);
  FUN_80032288(iVar1,0,1);
  return;
}



// ---- FUN_8004a754 @ 8004a754

void FUN_8004a754(int param_1,int param_2)

{
  code *pcVar1;
  
  FUN_80032684(param_1 + 0x1f68,param_2 + 8,0x1c);
  switch(*(undefined4 *)(param_2 + 8)) {
  case 0:
    pcVar1 = FUN_8004a84c;
    break;
  case 1:
    pcVar1 = FUN_8004a8bc;
    break;
  case 2:
    pcVar1 = FUN_8004a9a4;
    break;
  case 3:
    pcVar1 = FUN_8004a9d8;
    break;
  case 4:
    pcVar1 = FUN_8004aa7c;
    break;
  case 5:
    pcVar1 = FUN_8004ab2c;
    break;
  case 6:
    pcVar1 = FUN_8004af30;
    break;
  case 7:
    pcVar1 = FUN_8004b1d4;
    break;
  default:
    goto switchD_8004a7a8_default;
  }
  FUN_80032654(param_1 + 0x1f68,pcVar1);
switchD_8004a7a8_default:
  return;
}



// ---- FUN_8004a84c @ 8004a84c

void FUN_8004a84c(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_3 + 4);
  if (iVar1 == 0x95b) {
    *(uint *)(param_1 + 0x1acc) = *(uint *)(param_1 + 0x1acc) | 0x40000000;
  }
  else if ((0x95b < iVar1) && (iVar1 == 0x9c7)) {
    *(undefined1 *)(param_1 + 0x1dee) = 1;
  }
  *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x40;
  FUN_80032654(param_2,0);
  return;
}



// ---- FUN_8004a8bc @ 8004a8bc

void FUN_8004a8bc(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_3 + 4);
  if (iVar2 == 0x5ee) {
    *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) & 0xbf;
    if (*(int *)(param_3 + 0x10) == 1) {
      bVar1 = *(byte *)(param_1 + 0x1acc) | 0x40;
    }
    else {
      if (*(int *)(param_3 + 0x10) != 2) goto LAB_8004a988;
      bVar1 = *(byte *)(param_1 + 0x1acc) | 0x80;
    }
    *(byte *)(param_1 + 0x1acc) = bVar1;
  }
  else if ((iVar2 < 0x5ef) && (iVar2 == 0x155)) {
    *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x40;
  }
  else {
    *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x40;
    (**(code **)(param_1 + 0x1b14))(param_1,*(undefined4 *)(param_1 + 0x1b1c),0,0,0);
  }
LAB_8004a988:
  FUN_80032654(param_2,0);
  return;
}



// ---- FUN_8004a9a4 @ 8004a9a4

void FUN_8004a9a4(int param_1,undefined4 param_2)

{
  *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x40;
  FUN_80032654(param_2,0);
  return;
}



// ---- FUN_8004a9d8 @ 8004a9d8

void FUN_8004a9d8(int param_1,undefined4 param_2,int param_3)

{
  short sVar1;
  short sVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_3 + 0x14) * 4;
  sVar1 = *(short *)(&DAT_8007140c + iVar3);
  sVar2 = *(short *)(&DAT_8007140e + iVar3);
  *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x40;
  *(undefined4 *)(param_1 + 0x1b1c) = *(undefined4 *)(param_3 + 8);
  if (*(int *)(param_1 + 0x1b14) != 0) {
    (**(code **)(param_1 + 0x1b14))
              (param_1,*(undefined4 *)(param_1 + 0x1b1c),1,sVar1 + -0x20,sVar2 + -0x10);
  }
  FUN_80032654(param_2,0);
  return;
}



// ---- FUN_8004aa7c @ 8004aa7c

void FUN_8004aa7c(int param_1,undefined4 param_2,int param_3)

{
  *(int *)(param_1 + 0x1b24) =
       *(int *)(param_3 + 0x10) * 0xe10 + *(int *)(param_3 + 0x14) * 0x3c + *(int *)(param_3 + 0x18)
  ;
  FUN_80032654(param_2,FUN_8004aae0);
  return;
}



// ---- FUN_8004aae0 @ 8004aae0

void FUN_8004aae0(int param_1,undefined4 param_2)

{
  if (*(uint *)(param_1 + 0x1b24) <= *(uint *)(param_1 + 0x1b20)) {
    *(undefined4 *)(param_1 + 0x1b24) = 0;
    *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x40;
    FUN_80032654(param_2,0);
  }
  return;
}



// ---- FUN_8004ab2c @ 8004ab2c

void FUN_8004ab2c(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  byte *pbVar5;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  iVar2 = *(int *)(param_3 + 4);
  pbVar5 = (byte *)(param_1 + 0x1ac0);
  if (iVar2 == 0x82d) {
    if (*(int *)(param_3 + 8) == 0x9b4) {
      *(uint *)(param_1 + 0x1d80) = *(uint *)(param_1 + 0x1d80) | 2;
      *(undefined1 *)(param_1 + 0x1d81) = 0x60;
      *(undefined1 *)(param_1 + 0x1d82) = 0x40;
    }
    else {
      *(uint *)(param_1 + 0x1d80) = *(uint *)(param_1 + 0x1d80) & 0xfffffffd;
    }
    *(undefined4 *)(param_1 + 0x1b18) = 1;
    *(uint *)(param_1 + 0x1d80) = *(uint *)(param_1 + 0x1d80) & 0xfffffffb | 0xf8;
    *pbVar5 = *pbVar5 | 0x40;
    pcVar4 = (code *)0x0;
    goto LAB_8004ae84;
  }
  if (0x82d < iVar2) {
    if (iVar2 == 0x99c) {
      iVar2 = *(int *)(param_3 + 8);
      if (iVar2 == 0x675) {
        pcVar4 = (code *)0x0;
        *(undefined4 *)(param_1 + 0x1b18) = 1;
        *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x40;
        *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) | 0x18000000;
      }
      else if (iVar2 < 0x676) {
        if (iVar2 != 0x674) {
          return;
        }
        pcVar4 = (code *)0x0;
        *(undefined4 *)(param_1 + 0x1b18) = 1;
        *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x40;
      }
      else if (iVar2 == 0x9a7) {
        *(uint *)(param_1 + 0x1b50) = *(uint *)(param_1 + 0x1b50) | 4;
        *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) & 0x7f;
        local_20 = 0xffffffff;
        local_1c = *(undefined4 *)(param_1 + 0x1b38);
        local_18 = 0;
        FUN_800364d8(5,&local_20);
        pcVar4 = FUN_8004aea4;
      }
      else {
        uVar3 = 0xffffffff;
        if (iVar2 != 0x9a8) {
          return;
        }
        *(uint *)(param_1 + 0x1b50) = *(uint *)(param_1 + 0x1b50) | 2;
        *(undefined4 *)(param_1 + 0x1b38) = *(undefined4 *)(param_1 + 0x1b34);
        if ((*(uint *)(param_1 + 0x1b04) & 1) != 0) {
          uVar3 = *(undefined4 *)(param_1 + 0x1afc);
        }
        *(undefined4 *)(param_1 + 0x1b40) = uVar3;
        FUN_8004b264();
        pcVar4 = (code *)0x0;
        *(undefined4 *)(param_1 + 0x1b18) = 1;
        *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x40;
      }
    }
    else {
      if (iVar2 != 0x9c4) {
        return;
      }
      *(undefined1 *)(param_1 + 0x1def) = 1;
      *(undefined4 *)(param_1 + 0x1de0) = *(undefined4 *)(param_3 + 8);
      FUN_80052fcc();
      pcVar4 = (code *)0x0;
    }
    goto LAB_8004ae84;
  }
  if (iVar2 != 0x676) {
    return;
  }
  iVar2 = *(int *)(param_3 + 8);
  if (iVar2 == 0x9cb) {
    *(uint *)(param_1 + 0x1b18) = (uint)*(byte *)(param_1 + 0x1dec);
  }
  else if (iVar2 < 0x9cc) {
    if (iVar2 == 0x9c8) {
      *(uint *)(param_1 + 0x1b18) = (uint)*(byte *)(param_1 + 0x1deb);
    }
    else if (iVar2 < 0x9c9) {
      if (iVar2 == 0x50a) {
        FUN_8002bc50(1);
        FUN_8002bc74(0);
        pcVar4 = FUN_8004aef0;
        goto LAB_8004ae84;
      }
    }
    else if (iVar2 == 0x9c9) {
      *(uint *)(param_1 + 0x1b18) = (uint)*(byte *)(param_1 + 0x1de6);
    }
    else if (iVar2 == 0x9ca) {
      *(uint *)(param_1 + 0x1b18) = (uint)*(byte *)(param_1 + 0x1de8);
    }
  }
  else if (iVar2 == 0x9ce) {
    *(uint *)(param_1 + 0x1b18) = (uint)*(byte *)(param_1 + 0x1dea);
  }
  else if (iVar2 < 0x9cf) {
    if (iVar2 == 0x9cc) {
      *(uint *)(param_1 + 0x1b18) = (uint)*(byte *)(param_1 + 0x1de9);
    }
    else if (iVar2 == 0x9cd) {
      uVar1 = (uint)*(ushort *)(param_1 + 0x1de4);
code_r0x8004ae6c:
      *(uint *)(param_1 + 0x1b18) = uVar1;
    }
  }
  else if (iVar2 == 0x9cf) {
    *(uint *)(param_1 + 0x1b18) = (uint)*(byte *)(param_1 + 0x1de7);
  }
  else if (iVar2 == 0x9d7) {
    uVar1 = (*(int *)(param_1 + 0x1d80) << 0x18) >> 0x1b;
    goto code_r0x8004ae6c;
  }
  pcVar4 = (code *)0x0;
  *pbVar5 = *pbVar5 | 0x40;
LAB_8004ae84:
  FUN_80032654(param_2,pcVar4);
  return;
}



// ---- FUN_8004aea4 @ 8004aea4

void FUN_8004aea4(int param_1,undefined4 param_2)

{
  if ((*(byte *)(param_1 + 0x1ac0) & 0x80) != 0) {
    *(undefined4 *)(param_1 + 0x1b18) = 1;
    *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x40;
    FUN_80032654(param_2,0);
  }
  return;
}



// ---- FUN_8004aef0 @ 8004aef0

void FUN_8004aef0(int param_1,undefined4 param_2)

{
  *(uint *)(param_1 + 0x1b18) = (uint)(DAT_8007090c == 0);
  *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x40;
  FUN_80032654(param_2,0);
  return;
}



// ---- FUN_8004af30 @ 8004af30

void FUN_8004af30(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  
  iVar2 = *(int *)(param_3 + 8);
  if (iVar2 == 0x9cb) {
    *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x40;
    *(undefined1 *)(param_1 + 0x1dec) = *(undefined1 *)(param_3 + 0x10);
    goto LAB_8004b1b8;
  }
  if (0x9cb < iVar2) {
    if (iVar2 == 0xa33) {
      *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x40;
      *(uint *)(param_1 + 0x1acc) =
           *(uint *)(param_1 + 0x1acc) & 0xdfffffff |
           ((*(uint *)(param_1 + 0x1acc) >> 0x1d ^ 1) & 1) << 0x1d;
    }
    else if (iVar2 < 0xa34) {
      if (iVar2 != 0x9cd) {
        return;
      }
      *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x40;
      *(short *)(param_1 + 0x1de4) = *(short *)(param_1 + 0x1de4) + 1;
    }
    else {
      if (iVar2 != 0xa39) {
        return;
      }
      *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x40;
      uVar6 = 7;
      if (*(int *)(param_3 + 0x10) != 0) {
        uVar6 = 6;
      }
      FUN_80031268(0,uVar6);
    }
    goto LAB_8004b1b8;
  }
  if (iVar2 == 0x755) {
    *(uint *)(param_1 + 0x1b28) = *(uint *)(param_1 + 0x1b28) | 0x101;
    *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x40;
    goto LAB_8004b1b8;
  }
  if (iVar2 < 0x756) {
    if (iVar2 != 0xdf) {
      return;
    }
    if (*(int *)(param_3 + 0x10) == 0) {
      *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x40;
      *(uint *)(param_1 + 0x1dc4) = *(uint *)(param_1 + 0x1dc4) | 0x80;
    }
    else {
      *(uint *)(param_1 + 0x1acc) =
           *(uint *)(param_1 + 0x1acc) & 0xffffffcf | (*(int *)(param_3 + 0x10) - 1U & 3) << 4 | 2;
      *(uint *)(param_1 + 0x1dc4) = *(uint *)(param_1 + 0x1dc4) & 0xffffff7f;
    }
    goto LAB_8004b1b8;
  }
  if (iVar2 != 0x756) {
    return;
  }
  uVar3 = *(uint *)(param_1 + 0x1b28);
  uVar1 = (*(uint *)(param_3 + 0x10) & 0xf) << 4;
  uVar4 = uVar3 & 0xffffff0f | uVar1;
  *(uint *)(param_1 + 0x1b28) = uVar4;
  uVar5 = *(uint *)(param_3 + 0x10) & 0xf;
  if (uVar5 == 3) {
    uVar4 = uVar4 | 8;
LAB_8004b0d4:
    *(uint *)(param_1 + 0x1b28) = uVar4;
  }
  else if (uVar5 < 4) {
    uVar4 = uVar4 | 8;
    if (uVar5 == 2) goto LAB_8004b0d4;
  }
  else if ((uVar5 == 4) || (uVar5 == 5)) {
    uVar4 = uVar3 & 0xffffff07 | uVar1;
    goto LAB_8004b0d4;
  }
  *(uint *)(param_1 + 0x1b28) = *(uint *)(param_1 + 0x1b28) & 0xfffffeff | 1;
  *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x40;
LAB_8004b1b8:
  FUN_80032654(param_2,0);
  return;
}



// ---- FUN_8004b1d4 @ 8004b1d4

void FUN_8004b1d4(int param_1,undefined4 param_2)

{
  *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) | 0x40;
  *(uint *)(param_1 + 0x1b28) = *(uint *)(param_1 + 0x1b28) | 8;
  FUN_80032654(param_2,0);
  return;
}



// ---- FUN_8004b210 @ 8004b210

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8004b210(undefined4 param_1)

{
  *(undefined4 *)(_DAT_800abf64 + 0x1b14) = param_1;
  return;
}



// ---- FUN_8004b220 @ 8004b220

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8004b220(void)

{
  *(byte *)(_DAT_800abf64 + 0x1ac0) = *(byte *)(_DAT_800abf64 + 0x1ac0) | 0x40;
  FUN_80032654(_DAT_800abf64 + 0x1f68,0);
  return;
}



// ---- FUN_8004b264 @ 8004b264

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8004b264(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = _DAT_800abf64;
  iVar4 = 0;
  iVar5 = 0;
  *(uint *)(_DAT_800abf64 + 0x1b50) = *(uint *)(_DAT_800abf64 + 0x1b50) & 0xfffffffb | 2;
  uVar2 = FUN_8002ac50(0x1c0);
  *(undefined4 *)(iVar1 + 0x1b44) = uVar2;
  uVar2 = FUN_8002ac50(0x1000);
  *(undefined4 *)(iVar1 + 0x1b48) = uVar2;
  uVar2 = FUN_8002ac50(0x1700);
  iVar6 = _DAT_800abf64;
  *(undefined4 *)(iVar1 + 0x1b4c) = uVar2;
  iVar3 = iVar6 + 0x20f0;
  do {
    iVar4 = iVar4 + 1;
    FUN_8004b4d0(iVar3,iVar5 + *(int *)(iVar1 + 0x1b44),0);
    iVar5 = iVar5 + 0x1c;
    iVar3 = iVar3 + 0x1c;
  } while (iVar4 < 0x10);
  iVar4 = 0;
  iVar3 = iVar6 + 14000;
  do {
    iVar5 = iVar4 * 0x40;
    iVar4 = iVar4 + 1;
    FUN_8004b540(iVar3,iVar5 + *(int *)(iVar1 + 0x1b48),0);
    iVar3 = iVar3 + 0x40;
  } while (iVar4 < 0x40);
  iVar4 = 0;
  iVar3 = 0;
  iVar6 = iVar6 + 0x6370;
  do {
    iVar4 = iVar4 + 1;
    FUN_8004b6a4(iVar6,iVar3 + *(int *)(iVar1 + 0x1b4c),0);
    iVar3 = iVar3 + 0x5c;
    iVar6 = iVar6 + 0x5c;
  } while (iVar4 < 0x40);
  return;
}



// ---- FUN_8004b39c @ 8004b39c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8004b39c(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = _DAT_800abf64;
  iVar2 = 0;
  iVar4 = 0;
  iVar5 = _DAT_800abf64 + 14000;
  iVar6 = _DAT_800abf64 + 0x6370;
  iVar3 = _DAT_800abf64 + 0x20f0;
  *(uint *)(_DAT_800abf64 + 0x1b50) = *(uint *)(_DAT_800abf64 + 0x1b50) & 0xfffffff9;
  do {
    iVar2 = iVar2 + 1;
    FUN_8004b4d0(iVar4 + *(int *)(iVar1 + 0x1b44),iVar3,1);
    iVar4 = iVar4 + 0x1c;
    iVar3 = iVar3 + 0x1c;
  } while (iVar2 < 0x10);
  iVar3 = 0;
  do {
    iVar2 = iVar3 * 0x40;
    iVar3 = iVar3 + 1;
    FUN_8004b540(iVar2 + *(int *)(iVar1 + 0x1b48),iVar5,1);
    iVar5 = iVar5 + 0x40;
  } while (iVar3 < 0x40);
  iVar5 = 0;
  iVar3 = 0;
  do {
    iVar5 = iVar5 + 1;
    FUN_8004b6a4(iVar3 + *(int *)(iVar1 + 0x1b4c),iVar6,1);
    iVar3 = iVar3 + 0x5c;
    iVar6 = iVar6 + 0x5c;
  } while (iVar5 < 0x40);
  FUN_8002af34(*(undefined4 *)(iVar1 + 0x1b44));
  FUN_8002af34(*(undefined4 *)(iVar1 + 0x1b48));
  FUN_8002af34(*(undefined4 *)(iVar1 + 0x1b4c));
  return;
}



// ---- FUN_8004b4d0 @ 8004b4d0

void FUN_8004b4d0(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_2 + 0x18);
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
  uVar1 = *(uint *)(param_1 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = uVar3 & 0xfff00000 | uVar1;
  uVar2 = *(uint *)(param_1 + 0x18) & 0x1f00000;
  *(uint *)(param_2 + 0x18) = uVar3 & 0xfe000000 | uVar1 | uVar2;
  *(uint *)(param_2 + 0x18) =
       uVar3 & 0x7e000000 | uVar1 | uVar2 | *(uint *)(param_1 + 0x18) & 0x80000000;
  return;
}



// ---- FUN_8004b540 @ 8004b540

void FUN_8004b540(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar5 = *(uint *)(param_2 + 0x18);
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
  uVar1 = *(uint *)(param_1 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = uVar5 & 0xfff00000 | uVar1;
  uVar2 = *(uint *)(param_1 + 0x18) & 0x1f00000;
  *(uint *)(param_2 + 0x18) = uVar5 & 0xfe000000 | uVar1 | uVar2;
  *(uint *)(param_2 + 0x18) =
       uVar5 & 0x7e000000 | uVar1 | uVar2 | *(uint *)(param_1 + 0x18) & 0x80000000;
  uVar1 = *(uint *)(param_2 + 0x3c);
  uVar6 = *(uint *)(param_1 + 0x3c) & 8;
  *(uint *)(param_2 + 0x3c) = uVar1 & 0xfffffff7 | uVar6;
  uVar7 = *(uint *)(param_1 + 0x3c) & 0x1e000;
  *(uint *)(param_2 + 0x3c) = uVar1 & 0xfffe1ff7 | uVar6 | uVar7;
  uVar2 = *(uint *)(param_1 + 0x3c) & 0xfe0000;
  *(uint *)(param_2 + 0x3c) = uVar1 & 0xff001ff7 | uVar6 | uVar7 | uVar2;
  uVar5 = (*(byte *)(param_1 + 0x3f) & 1) << 0x18;
  *(uint *)(param_2 + 0x3c) = uVar1 & 0xfe001ff7 | uVar6 | uVar7 | uVar2 | uVar5;
  uVar3 = *(uint *)(param_1 + 0x3c) & 0x2000000;
  *(uint *)(param_2 + 0x3c) = uVar1 & 0xfc001ff7 | uVar6 | uVar7 | uVar2 | uVar5 | uVar3;
  uVar4 = *(uint *)(param_1 + 0x3c) & 0xc000000;
  *(uint *)(param_2 + 0x3c) = uVar1 & 0xf0001ff7 | uVar6 | uVar7 | uVar2 | uVar5 | uVar3 | uVar4;
  *(uint *)(param_2 + 0x3c) =
       uVar1 & 0xc0001ff7 | uVar6 | uVar7 | uVar2 | uVar5 | uVar3 | uVar4 |
       *(uint *)(param_1 + 0x3c) & 0x30000000;
  return;
}



// ---- FUN_8004b6a4 @ 8004b6a4

void FUN_8004b6a4(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar4 = *(uint *)(param_2 + 0x18);
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0x10);
  uVar1 = *(uint *)(param_1 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = uVar4 & 0xfff00000 | uVar1;
  uVar2 = *(uint *)(param_1 + 0x18) & 0x1f00000;
  *(uint *)(param_2 + 0x18) = uVar4 & 0xfe000000 | uVar1 | uVar2;
  *(uint *)(param_2 + 0x18) =
       uVar4 & 0x7e000000 | uVar1 | uVar2 | *(uint *)(param_1 + 0x18) & 0x80000000;
  *(undefined1 *)(param_2 + 0x48) = *(undefined1 *)(param_1 + 0x48);
  *(undefined1 *)(param_2 + 0x49) = *(undefined1 *)(param_1 + 0x49);
  *(undefined1 *)(param_2 + 0x4a) = *(undefined1 *)(param_1 + 0x4a);
  *(undefined1 *)(param_2 + 0x4b) = *(undefined1 *)(param_1 + 0x4b);
  *(undefined4 *)(param_2 + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(param_2 + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(uint *)(param_2 + 0x58) =
       *(uint *)(param_2 + 0x58) & 0xfffbffff | *(uint *)(param_1 + 0x58) & 0x40000;
  *(undefined1 *)(param_2 + 0x56) = *(undefined1 *)(param_1 + 0x56);
  *(undefined1 *)(param_2 + 0x57) = *(undefined1 *)(param_1 + 0x57);
  uVar1 = *(uint *)(param_2 + 0x58);
  uVar5 = *(uint *)(param_1 + 0x58) & 0x200;
  *(uint *)(param_2 + 0x58) = uVar1 & 0xfffffdff | uVar5;
  uVar6 = *(uint *)(param_1 + 0x58) & 0xc00;
  *(uint *)(param_2 + 0x58) = uVar1 & 0xfffff1ff | uVar5 | uVar6;
  uVar7 = *(uint *)(param_1 + 0x58) & 0x1000;
  *(uint *)(param_2 + 0x58) = uVar1 & 0xffffe1ff | uVar5 | uVar6 | uVar7;
  uVar8 = *(uint *)(param_1 + 0x58) & 0x2000;
  *(uint *)(param_2 + 0x58) = uVar1 & 0xffffc1ff | uVar5 | uVar6 | uVar7 | uVar8;
  uVar2 = *(uint *)(param_1 + 0x58) & 0xf80000;
  *(uint *)(param_2 + 0x58) = uVar1 & 0xff07c1ff | uVar5 | uVar6 | uVar7 | uVar8 | uVar2;
  uVar4 = (*(byte *)(param_1 + 0x5b) & 0xf) << 0x18;
  *(uint *)(param_2 + 0x58) = uVar1 & 0xf007c1ff | uVar5 | uVar6 | uVar7 | uVar8 | uVar2 | uVar4;
  uVar3 = *(uint *)(param_1 + 0x58) & 0x10000000;
  *(uint *)(param_2 + 0x58) =
       uVar1 & 0xe007c1ff | uVar5 | uVar6 | uVar7 | uVar8 | uVar2 | uVar4 | uVar3;
  *(uint *)(param_2 + 0x58) =
       uVar1 & 0x8007c1ff | uVar5 | uVar6 | uVar7 | uVar8 | uVar2 | uVar4 | uVar3 |
       *(uint *)(param_1 + 0x58) & 0x60000000;
  *(undefined2 *)(param_2 + 0x20) = *(undefined2 *)(param_1 + 0x20);
  *(undefined2 *)(param_2 + 0x22) = *(undefined2 *)(param_1 + 0x22);
  *(undefined2 *)(param_2 + 0x24) = *(undefined2 *)(param_1 + 0x24);
  *(undefined2 *)(param_2 + 0x26) = *(undefined2 *)(param_1 + 0x26);
  *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(param_1 + 0x28);
  if (param_3 == 1) {
    FUN_80035458(param_2,*(undefined2 *)(param_1 + 0x20),*(undefined2 *)(param_1 + 0x22),0);
    uVar1 = *(uint *)(param_1 + 0x58);
    FUN_800358f0(param_2,uVar1 >> 9 & 1,uVar1 >> 0xc & 1,uVar1 >> 0xd & 1);
  }
  return;
}



// ---- FUN_8004b904 @ 8004b904

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8004b904(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64 + 0x1f4c;
  FUN_80032568(iVar1,0);
  FUN_80032288(iVar1,0,1);
  return;
}



// ---- FUN_8004b94c @ 8004b94c

void FUN_8004b94c(int param_1,int param_2)

{
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined **ppuVar7;
  int iVar8;
  
  ppuVar7 = &PTR_DAT_80085e4c;
  iVar8 = param_1 + 0x1f4c;
  if (*(int *)(param_2 + 0x10) == 1) {
    *(undefined4 *)(param_1 + 0x1b30) = *(undefined4 *)(param_2 + 8);
    uVar6 = *(undefined4 *)(param_2 + 0xc);
    *(uint *)(param_1 + 0x1b50) = *(uint *)(param_1 + 0x1b50) & 0xfffffffe;
    *(undefined4 *)(param_1 + 0x1b34) = uVar6;
    FUN_80032654(iVar8,FUN_8004bed0);
  }
  else if (*(int *)(param_1 + 0x1b34) == *(int *)(param_2 + 0xc)) {
    FUN_8004d120();
  }
  else {
    if (*(int *)(param_2 + 8) != -1) {
      if ((*(uint *)(param_1 + 0x1b50) & 6) == 0) {
        *(undefined4 *)(param_1 + 0x198c) = 0;
        FUN_800585e4(param_1 + 0x1990,0x100);
      }
      uVar2 = (uint)(byte)(&PTR_DAT_80085e4c)[*(int *)(param_2 + 8)][0x20];
      iVar4 = 0;
      if (uVar2 != 0) {
        piVar3 = *(int **)((&PTR_DAT_80085e4c)[*(int *)(param_2 + 8)] + 4);
        do {
          iVar4 = iVar4 + 1;
          if (*piVar3 == *(int *)(param_2 + 0xc)) {
            *(undefined4 *)(param_1 + 0x1b30) = *(undefined4 *)(param_2 + 8);
            *(undefined4 *)(param_1 + 0x1b34) = *(undefined4 *)(param_2 + 0xc);
            FUN_80032654(iVar8,FUN_8004bb4c);
            return;
          }
          piVar3 = piVar3 + 1;
        } while (iVar4 < (int)uVar2);
      }
    }
    iVar4 = 0;
    while( true ) {
      puVar1 = *ppuVar7;
      ppuVar7 = ppuVar7 + 1;
      if (puVar1 == (undefined *)0x0) break;
      iVar5 = 0;
      if ((byte)puVar1[0x20] != 0) {
        piVar3 = *(int **)(puVar1 + 4);
        do {
          iVar5 = iVar5 + 1;
          if (*piVar3 == *(int *)(param_2 + 0xc)) {
            *(int *)(param_1 + 0x1b30) = iVar4;
            *(undefined4 *)(param_1 + 0x1b34) = *(undefined4 *)(param_2 + 0xc);
            *(uint *)(param_1 + 0x1b50) = *(uint *)(param_1 + 0x1b50) & 0xfffffffe;
            FUN_80032654(iVar8,FUN_8004bc84);
            return;
          }
          piVar3 = piVar3 + 1;
        } while (iVar5 < (int)(uint)(byte)puVar1[0x20]);
      }
      iVar4 = iVar4 + 1;
    }
  }
  return;
}



// ---- FUN_8004bb4c @ 8004bb4c

void FUN_8004bb4c(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  FUN_80032654(param_1 + 0x20f0,0);
  FUN_80032654(param_1 + 0x210c,0);
  FUN_80032654(param_1 + 0x2128,0);
  FUN_80032654(param_1 + 0x2144,0);
  iVar3 = 0;
  iVar2 = param_1 + 14000;
  do {
    uVar1 = FUN_80032d18(iVar2,0xffffffff);
    iVar3 = iVar3 + 1;
    if ((uVar1 & 1) == 0) {
      FUN_80032d9c(iVar2,0);
      FUN_800340c8(iVar2,0);
    }
    iVar2 = iVar2 + 0x40;
  } while (iVar3 < 0x40);
  iVar3 = 0;
  iVar2 = param_1 + 0x6370;
  do {
    uVar1 = FUN_800353e0(iVar2,0xffffffff);
    iVar3 = iVar3 + 1;
    if ((uVar1 & 1) == 0) {
      FUN_800358f0(iVar2,0,0,0);
      FUN_80035ab8(iVar2,0);
    }
    iVar2 = iVar2 + 0x5c;
  } while (iVar3 < 0x40);
  (**(code **)(param_1 + 0x1b2c))(param_1,*(undefined4 *)(param_1 + 0x1b34));
  FUN_80032654(param_2,0);
  return;
}



// ---- FUN_8004bc84 @ 8004bc84

void FUN_8004bc84(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((*(uint *)(param_1 + 0x1b50) & 2) == 0) {
    iVar1 = FUN_8003c5f8(5,0);
    if (iVar1 != 0) {
      FUN_8003c5f8(3,2);
    }
  }
  else {
    FUN_8003bc78(1,1);
    FUN_8003bc78(2,0);
  }
  FUN_80032654(param_2,FUN_8004bd04);
  return;
}



// ---- FUN_8004bd04 @ 8004bd04

void FUN_8004bd04(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_8003c5f8(4,0);
  if (iVar1 == 1) {
    FUN_80032654(param_2,FUN_8004bd50);
  }
  return;
}



// ---- FUN_8004bd50 @ 8004bd50

void FUN_8004bd50(int param_1,undefined4 param_2)

{
  FUN_8003221c(param_1 + 0x2010,0);
  FUN_8003221c(param_1 + 0x20f0,0);
  FUN_8003221c(param_1 + 0x210c,0);
  FUN_8003221c(param_1 + 0x2128,0);
  FUN_8003221c(param_1 + 0x2144,0);
  FUN_80032654(param_2,FUN_8004bdcc);
  return;
}



// ---- FUN_8004bdcc @ 8004bdcc

void FUN_8004bdcc(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1aec) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x544) = 0;
  *(undefined2 *)(param_1 + 0x1af2) = 0;
  *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) & 0xfffffffd;
  FUN_80032654(param_2,FUN_8004be18);
  return;
}



// ---- FUN_8004be18 @ 8004be18

void FUN_8004be18(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_800315cc(3);
  switch(uVar1) {
  case 0:
    *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) & 0xfffffffb;
    FUN_80032654(param_2,FUN_8004bed0);
    break;
  case 4:
    if ((*(uint *)(param_1 + 0x1af4) & 4) == 0) {
      FUN_80031268(0,0xd4);
      *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) | 4;
    }
  }
  return;
}



// ---- FUN_8004bed0 @ 8004bed0

void FUN_8004bed0(int param_1,undefined4 param_2)

{
  FUN_80032568(param_1 + 0x20f0,0);
  FUN_80032568(param_1 + 0x210c,0);
  FUN_80032568(param_1 + 0x2128,0);
  FUN_80032568(param_1 + 0x2144,0);
  FUN_80032288(param_1 + 0x20f0,0,1);
  FUN_80032288(param_1 + 0x210c,0,1);
  FUN_80032288(param_1 + 0x2128,0,1);
  FUN_80032288(param_1 + 0x2144,0,1);
  *(undefined1 *)(param_1 + 0x1af8) = 0xff;
  *(undefined1 *)(param_1 + 0x1af9) = 0xff;
  *(undefined1 *)(param_1 + 0x1afa) = 0xff;
  *(undefined1 *)(param_1 + 0x1afb) = 0xff;
  *(undefined1 *)(param_1 + 0x588) = 1;
  *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) & 0xff8fffff | 0x600000;
  FUN_8002c57c(*(undefined4 *)(&PTR_DAT_80085e4c)[*(int *)(param_1 + 0x1b30)],0x800f4800,3,
               FUN_8004c4a0);
  FUN_80032654(param_2,FUN_8004c020);
  return;
}



// ---- FUN_8004c020 @ 8004c020

void FUN_8004c020(int param_1,undefined4 param_2)

{
  if ((*(uint *)(param_1 + 0x1b50) & 1) != 0) {
    *(uint *)(param_1 + 0x1b50) = *(uint *)(param_1 + 0x1b50) & 0xfffffff7;
    FUN_80032654(param_2,FUN_8004c06c);
  }
  return;
}



// ---- FUN_8004c06c @ 8004c06c

void FUN_8004c06c(int param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  
  puVar5 = (&PTR_DAT_80085e4c)[*(int *)(param_1 + 0x1b30)];
  if (DAT_80071454 < (int)(uint)(byte)puVar5[0x24]) {
    iVar3 = DAT_80071454 * 4 + param_1 + 0x528;
    iVar2 = DAT_80071454;
    do {
      iVar4 = iVar2 * 4;
      if ((*(int *)(iVar4 + *(int *)(puVar5 + 0x14)) != -1) &&
         (*(int *)(iVar4 + *(int *)(puVar5 + 0x14)) != *(int *)(iVar3 + 0x30))) {
        if (iVar2 == 0) {
          *(undefined4 *)(param_1 + 0x1afc) = 0xffffffff;
          *(undefined2 *)(param_1 + 0x1b00) = 0;
          *(uint *)(param_1 + 0x1b04) = *(uint *)(param_1 + 0x1b04) & 0xfffffffe;
          FUN_8002c57c(**(undefined4 **)(puVar5 + 0x1c),0x800dc800,7,0);
        }
        FUN_8002c57c(*(undefined4 *)(iVar4 + *(int *)(puVar5 + 0x14)),
                     *(undefined4 *)(&DAT_8007145c + iVar4),5,0);
        FUN_8002c57c(*(undefined4 *)(iVar4 + *(int *)(puVar5 + 0x18)),0x80166800,6,FUN_8004d07c);
        pcVar1 = FUN_8004c21c;
        DAT_80071458 = *(undefined4 *)(&DAT_8007145c + iVar4);
        *(uint *)(param_1 + 0x1b50) = *(uint *)(param_1 + 0x1b50) | 8;
        goto LAB_8004c1f0;
      }
      DAT_80071454 = DAT_80071454 + 1;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar2 < (int)(uint)(byte)puVar5[0x24]);
  }
  *(undefined4 *)(param_1 + 0x544) = 1;
  pcVar1 = FUN_8004c258;
LAB_8004c1f0:
  FUN_80032654(param_2,pcVar1);
  return;
}



// ---- FUN_8004c21c @ 8004c21c

void FUN_8004c21c(int param_1,undefined4 param_2)

{
  if ((*(uint *)(param_1 + 0x1b50) & 8) == 0) {
    FUN_80032654(param_2,FUN_8004c06c);
  }
  return;
}



// ---- FUN_8004c258 @ 8004c258

void FUN_8004c258(int param_1,undefined4 param_2)

{
  code *pcVar1;
  
  *(undefined1 *)(param_1 + 0x588) = 0;
  FUN_80049698();
  (**(code **)(param_1 + 0x1874))(param_1,0);
  if ((*(uint *)(param_1 + 0x1b50) & 4) == 0) {
    (**(code **)(param_1 + 0x1b2c))(param_1,*(undefined4 *)(param_1 + 0x1b34));
    pcVar1 = (code *)0x0;
  }
  else {
    pcVar1 = FUN_8004c2e8;
  }
  FUN_80032654(param_2,pcVar1);
  return;
}



// ---- FUN_8004c2e8 @ 8004c2e8

void FUN_8004c2e8(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x1b3c) != -1) {
    *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) & 0xe7ffffff | 0x10000000;
  }
  FUN_80032654(param_2,FUN_8004c33c);
  return;
}



// ---- FUN_8004c33c @ 8004c33c

void FUN_8004c33c(int param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if (*(int *)(param_1 + 0x1b40) < 0) {
    pcVar1 = FUN_8004c3f8;
  }
  else {
    *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) & 0xef;
    local_18 = 0;
    local_14 = *(undefined4 *)(param_1 + 0x1b40);
    local_10 = 0;
    FUN_800364d8(3,&local_18);
    pcVar1 = FUN_8004c3bc;
  }
  FUN_80032654(param_2,pcVar1);
  return;
}



// ---- FUN_8004c3bc @ 8004c3bc

void FUN_8004c3bc(int param_1,undefined4 param_2)

{
  if ((*(byte *)(param_1 + 0x1ac0) & 0x10) != 0) {
    FUN_80032654(param_2,FUN_8004c3f8);
  }
  return;
}



// ---- FUN_8004c3f8 @ 8004c3f8

void FUN_8004c3f8(undefined4 param_1,undefined4 param_2)

{
  FUN_8003c5f8(0,2);
  FUN_8004d144(0,0xffffffff,0xffffffff);
  FUN_8004b39c();
  FUN_80032654(param_2,FUN_8004c450);
  return;
}



// ---- FUN_8004c450 @ 8004c450

void FUN_8004c450(undefined4 param_1,undefined4 param_2)

{
  FUN_8003bc78(4,1);
  FUN_8003bc78(2,1);
  FUN_8004d120();
  FUN_80032654(param_2,0);
  return;
}



// ---- FUN_8004c4a0 @ 8004c4a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8004c4a0(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  DAT_80071454 = 0;
  FUN_800585e4((undefined4 *)(param_1 + 0x180c),0x9c);
  puVar7 = _DAT_800f4804 + 0x24;
  puVar6 = _DAT_800f4804;
  puVar1 = (undefined4 *)(param_1 + 0x180c);
  do {
    puVar8 = puVar1;
    puVar5 = puVar6;
    uVar2 = puVar5[1];
    uVar3 = puVar5[2];
    uVar4 = puVar5[3];
    *puVar8 = *puVar5;
    puVar8[1] = uVar2;
    puVar8[2] = uVar3;
    puVar8[3] = uVar4;
    puVar6 = puVar5 + 4;
    puVar1 = puVar8 + 4;
  } while (puVar6 != puVar7);
  uVar2 = puVar5[5];
  uVar3 = puVar5[6];
  puVar8[4] = *puVar6;
  puVar8[5] = uVar2;
  puVar8[6] = uVar3;
  if (*(int *)(param_1 + 0x180c) == 0) {
    *(undefined4 *)(param_1 + 0x180c) =
         *(undefined4 *)((&PTR_DAT_80085e4c)[*(int *)(param_1 + 0x1b30)] + 8);
  }
  if (*(int *)(param_1 + 0x1810) == 0) {
    *(undefined4 *)(param_1 + 0x1810) =
         *(undefined4 *)((&PTR_DAT_80085e4c)[*(int *)(param_1 + 0x1b30)] + 0xc);
  }
  if (*(int *)(param_1 + 0x1814) == 0) {
    *(undefined4 *)(param_1 + 0x1814) =
         *(undefined4 *)((&PTR_DAT_80085e4c)[*(int *)(param_1 + 0x1b30)] + 0x10);
  }
  if (*(int *)(param_1 + 0x1818) == 0) {
    *(uint *)(param_1 + 0x1818) = (uint)(byte)(&PTR_DAT_80085e4c)[*(int *)(param_1 + 0x1b30)][0x21];
  }
  if (*(int *)(param_1 + 0x1820) == 0) {
    *(uint *)(param_1 + 0x1820) = (uint)(byte)(&PTR_DAT_80085e4c)[*(int *)(param_1 + 0x1b30)][0x22];
  }
  if (*(int *)(param_1 + 0x1828) == 0) {
    *(uint *)(param_1 + 0x1828) = (uint)(byte)(&PTR_DAT_80085e4c)[*(int *)(param_1 + 0x1b30)][0x23];
  }
  if (*(int *)(param_1 + 0x1840) == 0) {
    *(undefined **)(param_1 + 0x1840) = &DAT_80071474;
  }
  if (*(int *)(param_1 + 0x184c) == 0) {
    *(undefined **)(param_1 + 0x184c) = &DAT_80071498;
  }
  if (*(int *)(param_1 + 0x1858) == 0) {
    *(undefined **)(param_1 + 0x1858) = &DAT_800714bc;
  }
  if (*(int *)(param_1 + 0x1864) == 0) {
    *(undefined **)(param_1 + 0x1864) = &DAT_800714d8;
  }
  FUN_8004d110(*(undefined4 *)(param_1 + 0x1878));
  FUN_80048600(*(undefined4 *)(param_1 + 0x187c));
  FUN_8004b210(*(undefined4 *)(param_1 + 0x1880));
  FUN_800498d4(*(undefined4 *)(param_1 + 0x1884));
  FUN_8002c57c(*(undefined4 *)(*(int *)(param_1 + 0x181c) * 4 + *(int *)(param_1 + 0x180c)),
               0x80135000,4,FUN_8004c77c);
  return;
}



// ---- FUN_8004c77c @ 8004c77c

void FUN_8004c77c(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  int local_90 [5];
  int local_7c;
  int local_78;
  int local_70 [9];
  int local_4c;
  int local_48;
  int local_40;
  
  FUN_8002ca58(local_90,local_70,0x80135000,0x801a6800,0);
  local_40 = param_1 + 0x1ac0;
  if (local_90[0] != 0) {
    iVar9 = 0;
    puVar11 = (undefined1 *)(*(int *)(param_1 + 0x1840) + *(int *)(param_1 + 0x1848));
    puVar10 = (undefined1 *)(*(int *)(param_1 + 0x1858) + *(int *)(param_1 + 0x1860));
    if (*(int *)(param_1 + 0x1844) != 0) {
      iVar9 = *(int *)(param_1 + 0x1844) + *(int *)(param_1 + 0x1848);
    }
    puVar6 = (undefined1 *)0x0;
    if (*(int *)(param_1 + 0x185c) != 0) {
      puVar6 = (undefined1 *)(*(int *)(param_1 + 0x185c) + *(int *)(param_1 + 0x1860));
    }
    FUN_8002cbc8(local_90,puVar11,iVar9);
    FUN_8002cd20(local_90,puVar10,puVar6,0,0xffffffff);
    iVar5 = 0;
    *(int *)(param_1 + 0x1848) = *(int *)(param_1 + 0x1848) + local_7c;
    *(int *)(param_1 + 0x1860) = *(int *)(param_1 + 0x1860) + local_78;
    iVar9 = param_1 + *(int *)(param_1 + 0x1834) * 0x40 + 14000;
    if (*(char *)(*(int *)(param_1 + 0x1830) + *(int *)(param_1 + 0x181c)) != '\0') {
      do {
        FUN_800328a4(iVar9,0xf);
        FUN_80032288(iVar9,param_1 + 0x20f0,1);
        FUN_80032b80(iVar9,1);
        FUN_80032d78(iVar9,1);
        FUN_80032d54(iVar9,0xb);
        FUN_80033094(iVar9,0x80,0x80,0x80,1);
        FUN_80033560(iVar9,0x20,0x10,1);
        FUN_80033a18(iVar9,0xc0,0x80,0x40);
        FUN_80033d40(iVar9,0,0,1);
        FUN_80032e0c(iVar9,*puVar11);
        uVar3 = 0;
        if (puVar6 != (undefined1 *)0x0) {
          uVar3 = *puVar6;
        }
        FUN_80032fac(iVar9,*puVar10,uVar3);
        *(int *)(param_1 + 0x1834) = *(int *)(param_1 + 0x1834) + 1;
        iVar5 = iVar5 + 1;
        iVar9 = iVar9 + 0x40;
      } while (iVar5 < (int)(uint)*(byte *)(*(int *)(param_1 + 0x1830) + *(int *)(param_1 + 0x181c))
              );
    }
  }
  if (local_70[0] != 0) {
    iVar9 = 0;
    iVar5 = *(int *)(param_1 + 0x184c) + *(int *)(param_1 + 0x1854);
    puVar10 = (undefined1 *)(*(int *)(param_1 + 0x1864) + *(int *)(param_1 + 0x186c));
    if (*(int *)(param_1 + 0x1850) != 0) {
      iVar9 = *(int *)(param_1 + 0x1850) + *(int *)(param_1 + 0x1854);
    }
    iVar7 = 0;
    if (*(int *)(param_1 + 0x1868) != 0) {
      iVar7 = *(int *)(param_1 + 0x1868) + *(int *)(param_1 + 0x186c);
    }
    FUN_8002cf6c(local_70,iVar5,iVar9);
    FUN_8002d178(local_70,puVar10,iVar7,0,0xffffffff);
    iVar7 = 0;
    *(int *)(param_1 + 0x1854) = *(int *)(param_1 + 0x1854) + local_4c;
    *(int *)(param_1 + 0x186c) = *(int *)(param_1 + 0x186c) + local_48;
    iVar8 = param_1 + *(int *)(param_1 + 0x183c) * 0x5c + 0x6370;
    if (*(char *)(*(int *)(param_1 + 0x1838) + *(int *)(param_1 + 0x181c)) != '\0') {
      iVar4 = iVar8;
      do {
        FUN_80034bec(iVar4);
        FUN_80032288(iVar4,param_1 + 0x210c,1);
        FUN_80034e00(iVar4,0,1);
        FUN_8003541c(iVar4,8);
        FUN_80035434(iVar4,1);
        FUN_8003571c(iVar4,0x20,0x10);
        FUN_800358f0(iVar4,0,0,0);
        if (iVar7 == 0) {
          uVar1 = 0;
        }
        else {
          uVar1 = FUN_80034e34(iVar8,0,0);
        }
        piVar2 = (int *)0x0;
        if (iVar7 == 0) {
          piVar2 = local_70;
        }
        FUN_80034e34(iVar4,piVar2,uVar1);
        FUN_800351a0(iVar4,iVar5,iVar9,0xffffffff);
        FUN_80035694(iVar4,*puVar10,0);
        *(int *)(param_1 + 0x183c) = *(int *)(param_1 + 0x183c) + 1;
        iVar7 = iVar7 + 1;
        iVar4 = iVar4 + 0x5c;
      } while (iVar7 < (int)(uint)*(byte *)(*(int *)(param_1 + 0x1838) + *(int *)(param_1 + 0x181c))
              );
    }
  }
  iVar9 = *(int *)(param_1 + 0x181c) + 1;
  *(int *)(param_1 + 0x181c) = iVar9;
  if (iVar9 < *(int *)(param_1 + 0x1818)) {
    FUN_8002c57c(*(undefined4 *)(iVar9 * 4 + *(int *)(param_1 + 0x180c)),0x80135000,4,FUN_8004c77c);
  }
  else if (*(int *)(param_1 + 0x1820) == 0) {
    if (*(int *)(param_1 + 0x1828) == 0) {
      *(uint *)(local_40 + 0x90) = *(uint *)(local_40 + 0x90) | 1;
    }
    else {
      FUN_8002c57c(*(undefined4 *)(*(int *)(param_1 + 0x182c) * 4 + *(int *)(param_1 + 0x1814)),
                   0x80135000,4,FUN_8004cfb8);
    }
  }
  else {
    FUN_8002c57c(*(undefined4 *)(*(int *)(param_1 + 0x1824) * 4 + *(int *)(param_1 + 0x1810)),
                 0x80135000,4,FUN_8004cc6c);
  }
  return;
}



// ---- FUN_8004cc6c @ 8004cc6c

void FUN_8004cc6c(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  undefined1 auStack_68 [36];
  int local_44;
  uint local_40;
  
  iVar9 = 0;
  iVar10 = *(int *)(param_1 + 0x184c) + *(int *)(param_1 + 0x1854);
  puVar8 = (undefined1 *)(*(int *)(param_1 + 0x1864) + *(int *)(param_1 + 0x186c));
  if (*(int *)(param_1 + 0x1850) != 0) {
    iVar9 = *(int *)(param_1 + 0x1850) + *(int *)(param_1 + 0x1854);
  }
  FUN_8002ca58(0,auStack_68,0x80135000,0x801a6800,0);
  FUN_8002cf6c(auStack_68,iVar10,iVar9);
  *(int *)(param_1 + 0x1854) = *(int *)(param_1 + 0x1854) + local_44;
  uVar5 = 0;
  if (local_40 != 0) {
    do {
      uVar1 = uVar5;
      if ((int)uVar5 < 0) {
        uVar1 = uVar5 + 7;
      }
      FUN_8002d178(auStack_68,puVar8 + ((int)uVar1 >> 3),
                   &DAT_8007146c + uVar5 + ((int)uVar1 >> 3) * -8,2,uVar5);
      uVar1 = *(int *)(param_1 + 0x1870) + 1;
      *(uint *)(param_1 + 0x1870) = uVar1;
      uVar5 = uVar5 + 1;
      if ((uVar1 & 7) == 0) {
        *(int *)(param_1 + 0x186c) = *(int *)(param_1 + 0x186c) + 1;
      }
    } while (uVar5 < local_40);
  }
  iVar6 = 0;
  iVar7 = param_1 + *(int *)(param_1 + 0x183c) * 0x5c + 0x6370;
  if (*(char *)(*(int *)(param_1 + 0x1838) + *(int *)(param_1 + 0x181c) + *(int *)(param_1 + 0x1824)
               ) != '\0') {
    iVar4 = iVar7;
    do {
      FUN_80034bec(iVar4);
      FUN_80032288(iVar4,param_1 + 0x210c,1);
      FUN_80034e00(iVar4,0,1);
      FUN_8003541c(iVar4,8);
      FUN_80035434(iVar4,1);
      FUN_8003571c(iVar4,0x20,0x10);
      FUN_800358f0(iVar4,0,0,0);
      if (iVar6 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = FUN_80034e34(iVar7,0,0);
      }
      puVar3 = (undefined1 *)0x0;
      if (iVar6 == 0) {
        puVar3 = auStack_68;
      }
      FUN_80034e34(iVar4,puVar3,uVar2);
      FUN_800351a0(iVar4,iVar10,iVar9,0xffffffff);
      FUN_80035694(iVar4,*puVar8,0);
      FUN_8003541c(iVar4,3);
      iVar6 = iVar6 + 1;
      *(int *)(param_1 + 0x183c) = *(int *)(param_1 + 0x183c) + 1;
      iVar4 = iVar4 + 0x5c;
    } while (iVar6 < (int)(uint)*(byte *)(*(int *)(param_1 + 0x1838) +
                                         *(int *)(param_1 + 0x181c) + *(int *)(param_1 + 0x1824)));
  }
  iVar9 = *(int *)(param_1 + 0x1824) + 1;
  *(int *)(param_1 + 0x1824) = iVar9;
  if (iVar9 < *(int *)(param_1 + 0x1820)) {
    FUN_8002c57c(*(undefined4 *)(iVar9 * 4 + *(int *)(param_1 + 0x1810)),0x80135000,4,FUN_8004cc6c);
  }
  else if (*(int *)(param_1 + 0x1828) == 0) {
    *(uint *)(param_1 + 0x1b50) = *(uint *)(param_1 + 0x1b50) | 1;
  }
  else {
    FUN_8002c57c(*(undefined4 *)(*(int *)(param_1 + 0x182c) * 4 + *(int *)(param_1 + 0x1814)),
                 0x80135000,4,FUN_8004cfb8);
  }
  return;
}



// ---- FUN_8004cfb8 @ 8004cfb8

void FUN_8004cfb8(int param_1)

{
  int iVar1;
  
  FUN_8002ca58(0,0,*(int *)(param_1 + 0x182c) * 0x4800 + -0x7fecb000,0x801a6800,1);
  iVar1 = *(int *)(param_1 + 0x182c) + 1;
  *(int *)(param_1 + 0x182c) = iVar1;
  if (iVar1 < *(int *)(param_1 + 0x1828)) {
    FUN_8002c57c(*(undefined4 *)(iVar1 * 4 + *(int *)(param_1 + 0x1814)),
                 iVar1 * 0x4800 + -0x7fecb000,4,FUN_8004cfb8);
  }
  else {
    *(uint *)(param_1 + 0x1b50) = *(uint *)(param_1 + 0x1b50) | 1;
  }
  return;
}



// ---- FUN_8004d07c @ 8004d07c

void FUN_8004d07c(int param_1)

{
  if (DAT_80071454 == 0) {
    FUN_800317c4(**(undefined4 **)((&PTR_DAT_80085e4c)[*(int *)(param_1 + 0x1b30)] + 0x1c),
                 0x80166800,0);
  }
  else {
    FUN_80031884(*(undefined4 *)
                  (DAT_80071454 * 4 +
                  *(int *)((&PTR_DAT_80085e4c)[*(int *)(param_1 + 0x1b30)] + 0x14)),0x80166800);
  }
  *(uint *)(param_1 + 0x1b50) = *(uint *)(param_1 + 0x1b50) & 0xfffffff7;
  return;
}



// ---- FUN_8004d110 @ 8004d110

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8004d110(undefined4 param_1)

{
  *(undefined4 *)(_DAT_800abf64 + 0x1b2c) = param_1;
  return;
}



// ---- FUN_8004d120 @ 8004d120

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8004d120(void)

{
  *(byte *)(_DAT_800abf64 + 0x1ac0) = *(byte *)(_DAT_800abf64 + 0x1ac0) | 0x80;
  return;
}



// ---- FUN_8004d144 @ 8004d144

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8004d144(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 auStack_68 [32];
  undefined1 auStack_48 [48];
  
  iVar1 = _DAT_800abf64;
  if (param_1 == 0) {
    if ((*(uint *)(_DAT_800abf64 + 0x1b50) & 0x10) == 0) goto LAB_8004d220;
    uVar3 = 0x80125000;
    uVar2 = *(uint *)(_DAT_800abf64 + 0x1b50) & 0xffffffef;
  }
  else {
    if ((param_1 != 1) || ((*(uint *)(_DAT_800abf64 + 0x1b50) & 0x10) != 0)) goto LAB_8004d220;
    uVar3 = 0x80122800;
    uVar2 = *(uint *)(_DAT_800abf64 + 0x1b50) | 0x10;
  }
  *(uint *)(_DAT_800abf64 + 0x1b50) = uVar2;
  FUN_8002ca58(auStack_68,0,uVar3,0x801a6800,0);
  FUN_8002cbc8(auStack_68,&DAT_80071504,0);
  FUN_8002cd20(auStack_68,&DAT_80071538,0,0,0xffffffff);
LAB_8004d220:
  if (param_2 == 0) {
    if ((*(uint *)(iVar1 + 0x1b50) & 0x20) != 0) {
      *(uint *)(iVar1 + 0x1b50) = *(uint *)(iVar1 + 0x1b50) & 0xffffffdf;
      FUN_8002ca58(auStack_68,auStack_48,0x8011a800,0x801a6800,0);
      FUN_8002cbc8(auStack_68,&DAT_800714f4,0);
    }
  }
  else if (param_2 == 1) {
    if ((*(uint *)(iVar1 + 0x1b50) & 0x20) == 0) {
      *(uint *)(iVar1 + 0x1b50) = *(uint *)(iVar1 + 0x1b50) | 0x20;
      FUN_8002ca58(auStack_68,auStack_48,0x8011d800,0x801a6800,0);
      FUN_8002cbc8(auStack_68,&DAT_80071508,0);
      FUN_8002cd20(auStack_68,&DAT_8007153c,0,0,0xffffffff);
      FUN_8002cf6c(auStack_48,&DAT_8007150c,&DAT_80071524);
      FUN_8002d178(auStack_48,&DAT_80071540,&DAT_80071560,0,0xffffffff);
    }
  }
  if (param_3 == 0) {
    if ((*(uint *)(iVar1 + 0x1b50) & 0x40) != 0) {
      *(uint *)(iVar1 + 0x1b50) = *(uint *)(iVar1 + 0x1b50) & 0xffffffbf;
      FUN_8002ca58(auStack_68,auStack_48,0x8011c000,0x801a6800,0);
      FUN_8002cbc8(auStack_68,&DAT_800714fc,0);
    }
  }
  else if (param_3 == 1) {
    if ((*(uint *)(iVar1 + 0x1b50) & 0x40) == 0) {
      *(uint *)(iVar1 + 0x1b50) = *(uint *)(iVar1 + 0x1b50) | 0x40;
      FUN_8002ca58(auStack_68,auStack_48,0x80120000,0x801a6800,0);
      FUN_8002cbc8(auStack_68,&DAT_80071510,0);
      FUN_8002cd20(auStack_68,&DAT_80071544,0,0,0xffffffff);
      FUN_8002cf6c(auStack_48,&DAT_80071514,0);
      FUN_8002d178(auStack_48,&DAT_80071548,&DAT_80071564,0,0xffffffff);
    }
  }
  FUN_80055d44();
  return;
}



// ---- FUN_8004d460 @ 8004d460

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8004d460(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64 + 0x1f84;
  FUN_80032568(iVar1,0);
  FUN_80032288(iVar1,0,1);
  return;
}



// ---- FUN_8004d4a8 @ 8004d4a8

void FUN_8004d4a8(int param_1,int param_2)

{
  *(undefined4 *)(param_1 + 0x1b54) = *(undefined4 *)(param_2 + 8);
  FUN_80032654(param_1 + 0x1f84,FUN_8004d4d8);
  return;
}



// ---- FUN_8004d4d8 @ 8004d4d8

void FUN_8004d4d8(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar1 + 1 & 0xfffff;
  if (uVar1 == *(uint *)(param_1 + 0x1b54)) {
    *(byte *)(param_1 + 0x1ac1) = *(byte *)(param_1 + 0x1ac1) | 1;
    FUN_80032654(param_2,0);
  }
  return;
}



// ---- FUN_8004d548 @ 8004d548

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8004d548(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64 + 0x1fa0;
  FUN_80032568(iVar1,0);
  FUN_80032288(iVar1,0,1);
  return;
}



// ---- FUN_8004d590 @ 8004d590

void FUN_8004d590(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined1 auStack_c8 [144];
  undefined1 local_38;
  
  uVar2 = *(uint *)(param_1 + 0x1d7c);
  iVar12 = param_1 + 0x1ac0;
  *(uint *)(param_1 + 0x1d7c) = uVar2 & 0xfffff1ff;
  iVar8 = (int)*(char *)(iVar12 + (uVar2 & 3) + 0x2b8);
  iVar4 = *(int *)(param_2 + 0x10);
  puVar13 = (undefined4 *)(param_2 + 8);
  if ((iVar4 < iVar8) || ((iVar8 == iVar4 && ((uVar2 & 0x1fc) != 0x1fc)))) {
    uVar9 = (uint)*(char *)(*(int *)(param_2 + 0x14) * 8 + iVar12 + iVar4 + 0x298);
    iVar4 = *(int *)(*(int *)(param_2 + 0x14) * 0x20 + iVar12 + iVar4 * 4 + 0x218);
    if (iVar4 == puVar13[uVar9 + 0x24]) {
      *(uint *)(param_1 + 0x1d7c) =
           uVar2 & 0xfffff1ff | (uVar9 & -(uint)((int)uVar9 < *(int *)(param_2 + 0xc)) & 7) << 9;
    }
    else {
      uVar2 = 0;
      if (0 < *(int *)(param_2 + 0xc)) {
        puVar3 = puVar13;
        do {
          if (iVar4 == puVar3[0x24]) {
            *(uint *)(param_1 + 0x1d7c) =
                 *(uint *)(param_1 + 0x1d7c) & 0xfffff1ff | (uVar2 & 7) << 9;
            break;
          }
          uVar2 = uVar2 + 1;
          puVar3 = puVar3 + 1;
        } while ((int)uVar2 < *(int *)(param_2 + 0xc));
      }
    }
  }
  if (*(char *)(param_1 + 0x1db3) == '\x01') {
    *(undefined1 *)(param_1 + 0x1db3) = 0;
    *(uint *)(param_1 + 0x1d7c) = *(uint *)(param_1 + 0x1d7c) & 0xfffff1ff | 0x800;
  }
  iVar4 = 0;
  if ((1 < *(int *)(param_2 + 0xc)) &&
     (iVar8 = FUN_80058654(*(undefined4 *)(param_2 + 0x1c),&DAT_8002868c,0xc), iVar8 == 0)) {
    *(uint *)(param_1 + 0x1d7c) = *(uint *)(param_1 + 0x1d7c) & 0xfffff1ff;
  }
  *(undefined1 *)(iVar12 + *(int *)(param_2 + 0x14) + 0x2b8) = *(undefined1 *)(param_2 + 0x10);
  uVar2 = *(uint *)(param_1 + 0x1d7c);
  uVar9 = *(uint *)(param_2 + 0x14) & 3;
  *(uint *)(param_1 + 0x1d7c) = uVar2 & 0xfffffffc | uVar9;
  *(uint *)(param_1 + 0x1d7c) =
       uVar2 & 0x80000e00 | uVar9 | (*(uint *)(param_2 + 0xc) & 0x3f) << 0xc | 0x1f8;
  *(undefined4 *)(*(int *)(param_2 + 0x10) * 4 + *(int *)(param_2 + 0x14) * 0x20 + iVar12 + 0x198) =
       *puVar13;
  if (0 < *(int *)(param_2 + 0xc)) {
    iVar8 = iVar12;
    puVar3 = puVar13;
    do {
      iVar4 = iVar4 + 1;
      *(undefined4 *)(iVar8 + 0x98) = puVar3[4];
      puVar5 = puVar3 + 0x24;
      puVar3 = puVar3 + 1;
      *(undefined4 *)(iVar8 + 0x118) = *puVar5;
      iVar8 = iVar8 + 4;
    } while (iVar4 < *(int *)(param_2 + 0xc));
  }
  iVar4 = *(int *)(param_2 + 0xc);
  if (iVar4 < 8) {
    iVar8 = iVar4 * 4 + iVar12;
    do {
      *(undefined4 *)(iVar8 + 0x98) = 0;
      *(undefined4 *)(iVar8 + 0x118) = 0;
      iVar4 = iVar4 + 1;
      iVar8 = iVar8 + 4;
    } while (iVar4 < 8);
  }
  iVar4 = *(int *)(param_2 + 0x14) + 1;
  if (iVar4 < 4) {
    iVar11 = iVar4 * 8 + iVar12;
    iVar8 = iVar4 * 0x20 + iVar12;
    do {
      *(undefined1 *)(iVar12 + iVar4 + 0x2b8) = 0;
      iVar10 = 0;
      puVar6 = (undefined1 *)(iVar11 + 0x298);
      puVar5 = (undefined4 *)(iVar8 + 0x218);
      puVar3 = (undefined4 *)(iVar8 + 0x198);
      do {
        *puVar3 = 0;
        *puVar5 = 0;
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
        puVar5 = puVar5 + 1;
        iVar10 = iVar10 + 1;
        puVar3 = puVar3 + 1;
      } while (iVar10 < 8);
      iVar11 = iVar11 + 8;
      iVar4 = iVar4 + 1;
      iVar8 = iVar8 + 0x20;
    } while (iVar4 < 4);
  }
  uVar2 = *(uint *)(param_1 + 0x1b28);
  if ((uVar2 & 1) == 0) {
    FUN_800585f4(auStack_c8,0x20,0x90);
    local_38 = 0;
    iVar4 = 0;
    if (0 < *(int *)(param_2 + 0xc)) {
      do {
        uVar1 = FUN_80058624(puVar13[4]);
        iVar8 = iVar4;
        if (iVar4 < 0) {
          iVar8 = iVar4 + 3;
        }
        puVar3 = puVar13 + 4;
        puVar13 = puVar13 + 1;
        FUN_80058664(auStack_c8 + iVar4 * 0x24 + (iVar8 >> 2) * -0x7c,*puVar3,uVar1);
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(param_2 + 0xc));
    }
    FUN_800367d8(auStack_c8,0x17,0,0xffffffff,0x12,0);
    pcVar7 = FUN_8004da74;
    if ((*(uint *)(param_1 + 0x1af4) & 0x4000000) != 0) {
      pcVar7 = FUN_8004da08;
    }
  }
  else {
    uVar9 = uVar2 >> 3 & 1;
    if (uVar9 == 0) {
      pcVar7 = FUN_8004f47c;
      if ((uVar2 & 6) == 0) {
        pcVar7 = FUN_8004e73c;
      }
    }
    else {
      if (uVar9 != 1) {
        return;
      }
      pcVar7 = FUN_8004ff00;
      if ((uVar2 & 6) == 0) {
        pcVar7 = FUN_8004fbc4;
      }
    }
  }
  FUN_80032654(param_1 + 0x1fa0,pcVar7);
  return;
}



// ---- FUN_8004da08 @ 8004da08

void FUN_8004da08(undefined4 param_1,int param_2)

{
  int iVar1;
  
  *(uint *)(param_2 + 0x18) =
       *(uint *)(param_2 + 0x18) & 0xfff00000 | (*(uint *)(param_2 + 0x18) & 0xfffff) + 1 & 0xfffff;
  iVar1 = FUN_8004a0a0();
  if (iVar1 == 1) {
    FUN_80032654(param_2,FUN_8004da74);
  }
  return;
}



// ---- FUN_8004da74 @ 8004da74

void FUN_8004da74(int param_1,undefined4 param_2)

{
  FUN_80032d9c(param_1 + 0x27b0,1);
  FUN_80032d9c(param_1 + 0x27f0,1);
  FUN_80032d9c(param_1 + 0x2730,1);
  FUN_80032654(param_2,FUN_8004dad8);
  return;
}



// ---- FUN_8004dad8 @ 8004dad8

void FUN_8004dad8(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar1 + 1 & 0xfffff;
  if (uVar1 < 0xf) {
    FUN_80033848(param_1 + 0x27b0,0,0xfffffff8,1);
    FUN_80033848(param_1 + 0x27f0,0,0xfffffff8,0xf);
    FUN_80033848(param_1 + 0x2730,0,0xfffffff8,1);
  }
  else {
    *(uint *)(param_1 + 0x1acc) = *(uint *)(param_1 + 0x1acc) | 0x10000000;
    FUN_80032654(param_2,FUN_8004db94);
  }
  return;
}



// ---- FUN_8004db94 @ 8004db94

void FUN_8004db94(int param_1,int param_2)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  short sVar10;
  ushort local_20;
  ushort local_1e;
  
  sVar10 = 0;
  uVar9 = 5;
  iVar8 = param_1 + 0x1ac0;
  iVar5 = param_1;
  if (((*(uint *)(param_1 + 0x1d80) & 2) != 0) &&
     (*(char *)(iVar8 + (*(uint *)(param_1 + 0x1d7c) & 3) + 0x2b8) == '\0')) {
    uVar2 = FUN_8002ba04(0x41);
    iVar3 = FUN_8002b8ac(0,uVar2,0,3,0);
    iVar5 = param_2;
    if (iVar3 != 0) {
      *(uint *)(param_1 + 0x1d80) = *(uint *)(param_1 + 0x1d80) | 4;
      goto LAB_8004e384;
    }
  }
  *(uint *)(param_1 + 0x1d80) = *(uint *)(param_1 + 0x1d80) & 0xfffffffb;
  cVar1 = FUN_8002bb78(iVar5);
  if (cVar1 == '\0') {
    iVar5 = FUN_8002b8ac(0,0x1000,0,3,0);
    if (iVar5 == 0) {
      iVar5 = FUN_8002b8ac(0,0x1000,1,1,0);
      if (iVar5 == 0) {
        iVar5 = FUN_8002b8ac(0,0x4000,0,3,0);
        if (iVar5 != 0) {
          uVar6 = *(uint *)(param_1 + 0x1d7c);
          uVar9 = 2;
          goto LAB_8004df64;
        }
        iVar5 = FUN_8002b8ac(0,0x4000,1,1,0);
        if (iVar5 == 0) {
          iVar5 = FUN_8002b8ac(0,0x8000,0,3,0);
          if (iVar5 != 0) {
            uVar6 = *(uint *)(param_1 + 0x1d7c);
            uVar9 = 3;
            goto LAB_8004df64;
          }
          iVar5 = FUN_8002b8ac(0,0x8000,1,1,0);
          if (iVar5 == 0) {
            iVar5 = FUN_8002b8ac(0,0x2000,0,3,0);
            if (iVar5 != 0) {
              uVar6 = *(uint *)(param_1 + 0x1d7c);
              uVar9 = 4;
              goto LAB_8004df64;
            }
            iVar5 = FUN_8002b8ac(0,0x2000,1,1,0);
            if ((iVar5 != 0) &&
               (uVar6 = ((*(uint *)(param_1 + 0x1d7c) >> 0x12 & 0x1fff) + 1 & 0x1fff) << 0x12,
               *(uint *)(param_1 + 0x1d7c) = *(uint *)(param_1 + 0x1d7c) & 0x8003ffff | uVar6,
               (uVar6 & 0x3c0000) == 0)) {
              uVar9 = 4;
            }
          }
          else {
            uVar6 = ((*(uint *)(param_1 + 0x1d7c) >> 0x12 & 0x1fff) + 1 & 0x1fff) << 0x12;
            *(uint *)(param_1 + 0x1d7c) = *(uint *)(param_1 + 0x1d7c) & 0x8003ffff | uVar6;
            if ((uVar6 & 0x3c0000) == 0) {
              uVar9 = 3;
            }
          }
        }
        else {
          uVar6 = ((*(uint *)(param_1 + 0x1d7c) >> 0x12 & 0x1fff) + 1 & 0x1fff) << 0x12;
          *(uint *)(param_1 + 0x1d7c) = *(uint *)(param_1 + 0x1d7c) & 0x8003ffff | uVar6;
          if ((uVar6 & 0x3c0000) == 0) {
            uVar9 = 2;
          }
        }
      }
      else {
        uVar6 = ((*(uint *)(param_1 + 0x1d7c) >> 0x12 & 0x1fff) + 1 & 0x1fff) << 0x12;
        *(uint *)(param_1 + 0x1d7c) = *(uint *)(param_1 + 0x1d7c) & 0x8003ffff | uVar6;
        if ((uVar6 & 0x3c0000) == 0) {
          uVar9 = 1;
        }
      }
    }
    else {
      uVar6 = *(uint *)(param_1 + 0x1d7c);
      uVar9 = 1;
LAB_8004df64:
      *(uint *)(param_1 + 0x1d7c) = uVar6 & 0x8003ffff;
    }
    if (uVar9 == 2) {
      uVar7 = *(uint *)(param_1 + 0x1d7c);
      uVar6 = uVar7 >> 9 & 7;
      uVar9 = 0;
      if (uVar6 != (uVar7 >> 0xc & 0x3f) - 1) {
        uVar9 = uVar6 + 1;
      }
      uVar7 = uVar7 & 0xfffff1ff;
      uVar9 = uVar9 & 7;
LAB_8004e19c:
      *(uint *)(param_1 + 0x1d7c) = uVar7 | uVar9 << 9;
    }
    else if (uVar9 < 3) {
      if (uVar9 == 1) {
        uVar9 = *(uint *)(param_1 + 0x1d7c);
        if ((uVar9 & 0xe00) == 0) {
          uVar9 = uVar9 >> 0xc & 0x3f;
        }
        else {
          uVar9 = uVar9 >> 9 & 7;
        }
        *(uint *)(param_1 + 0x1d7c) =
             *(uint *)(param_1 + 0x1d7c) & 0xfffff1ff | (uVar9 - 1 & 7) << 9;
      }
    }
    else if (uVar9 == 3) {
      uVar7 = *(uint *)(param_1 + 0x1d7c);
      if ((uVar7 & 0x3fe00) != 0x8000) {
        uVar6 = uVar7 >> 9 & 7;
        if (uVar6 < 4) {
          uVar9 = uVar7 >> 0xc & 0x3f;
          if (uVar9 < uVar6 + 4) {
            if ((uVar7 & 0xe00) == 0) {
              uVar7 = uVar7 & 0xfffff1ff;
              uVar6 = uVar9 - 1;
            }
            else {
              uVar7 = uVar7 & 0xfffff1ff;
              uVar6 = uVar6 - 1;
            }
          }
          else {
            uVar7 = uVar7 & 0xfffff1ff;
            uVar6 = uVar6 + 3;
          }
        }
        else {
          uVar7 = uVar7 & 0xfffff1ff;
          uVar6 = uVar6 - 4;
        }
        goto LAB_8004e198;
      }
      *(uint *)(param_1 + 0x1d7c) = uVar7 | 0xe00;
    }
    else if (uVar9 == 4) {
      uVar7 = *(uint *)(param_1 + 0x1d7c);
      if ((uVar7 & 0xe00) != 0xe00) {
        uVar6 = uVar7 >> 9 & 7;
        if (uVar6 < 4) {
          uVar4 = uVar7 >> 0xc & 0x3f;
          uVar9 = uVar6 + 4 & 7;
          if (uVar6 + 4 < uVar4) {
            uVar7 = uVar7 & 0xfffff1ff;
            goto LAB_8004e19c;
          }
          if ((uVar6 == uVar4 - 1) || ((uVar7 & 0xe00) == 0x600)) goto LAB_8004e180;
          uVar7 = uVar7 & 0xfffff1ff;
          uVar6 = uVar6 + 1;
        }
        else {
          uVar7 = uVar7 & 0xfffff1ff;
          uVar6 = uVar6 - 3;
        }
LAB_8004e198:
        uVar9 = uVar6 & 7;
        goto LAB_8004e19c;
      }
LAB_8004e180:
      *(uint *)(param_1 + 0x1d7c) = uVar7 & 0xfffff1ff;
    }
    FUN_80032d9c(param_1 + 0x2770,1);
    iVar5 = (*(uint *)(param_1 + 0x1d7c) >> 0xb & 1) * 0x78 + 8;
    local_20 = (ushort)iVar5;
    iVar3 = (*(uint *)(param_1 + 0x1d7c) >> 5 & 0x30) + 0x9e;
    local_1e = (ushort)iVar3;
    FUN_80033560(param_1 + 0x2770,iVar5 * 0x10000 >> 0x10,iVar3,1);
  }
  else {
    uVar9 = 0xffffffff;
    FUN_8002bb90(1,&local_20);
    local_20 = local_20 - 8;
    local_1e = local_1e - 0x9e;
    if ((local_20 < 0xd9) && (local_1e < 0x3d)) {
      iVar5 = (int)(short)local_20;
      iVar3 = (int)(short)local_1e;
      local_20 = (ushort)(iVar5 / 0x78);
      if (iVar3 < 0) {
        iVar3 = iVar3 + 0xf;
      }
      local_1e = (ushort)(iVar3 >> 4);
      uVar9 = (iVar5 / 0x78) * 4 + (iVar3 >> 4);
    }
    sVar10 = (short)uVar9;
    uVar6 = (int)(uVar9 << 0x10) >> 0x10;
    if (((int)uVar6 < 0) || ((int)(*(uint *)(param_1 + 0x1d7c) >> 0xc & 0x3f) <= (int)uVar6)) {
      FUN_80032d9c(param_1 + 0x2770,0);
    }
    else {
      iVar5 = ((int)(uVar9 << 0x10) >> 0x12) * 0x78 + 8;
      iVar3 = (uVar9 & 3) * 0x10 + 0x9e;
      *(uint *)(param_1 + 0x1d7c) = *(uint *)(param_1 + 0x1d7c) & 0xfffff1ff | (uVar6 & 7) << 9;
      local_20 = (ushort)iVar5;
      local_1e = (ushort)iVar3;
      FUN_80033560(param_1 + 0x2770,iVar5 * 0x10000 >> 0x10,iVar3,1);
      FUN_80032d9c(param_1 + 0x2770,1);
    }
  }
  uVar2 = FUN_8002ba04(0x24);
  iVar5 = FUN_8002b8ac(0,uVar2,0,3,0);
  if (((iVar5 != 0) && (-1 < sVar10)) &&
     ((int)sVar10 < (int)(*(uint *)(param_1 + 0x1d7c) >> 0xc & 0x3f))) {
    FUN_80031268(0x500,0xffffffed);
    uVar9 = *(uint *)(param_1 + 0x1d7c) & 3;
    *(undefined4 *)(*(char *)(iVar8 + uVar9 + 0x2b8) * 4 + uVar9 * 0x20 + iVar8 + 0x218) =
         *(undefined4 *)((*(uint *)(param_1 + 0x1d7c) >> 7 & 0x1c) + iVar8 + 0x118);
    uVar9 = *(uint *)(param_1 + 0x1d7c) & 3;
    *(byte *)(uVar9 * 8 + iVar8 + 0x298 + (int)*(char *)(iVar8 + uVar9 + 0x2b8)) =
         (byte)(*(uint *)(param_1 + 0x1d7c) >> 9) & 7;
    *(uint *)(param_1 + 0x1d7c) =
         *(uint *)(param_1 + 0x1d7c) & 0xfffffe03 | *(uint *)(param_1 + 0x1d7c) >> 7 & 0x1c;
    FUN_80032654(param_2,FUN_8004e3b0);
  }
  uVar2 = FUN_8002ba04(0x41);
  iVar5 = FUN_8002b8ac(0,uVar2,0,3,0);
  if (iVar5 == 0) {
    return;
  }
  FUN_80031268(0x500,0xffffffed);
  uVar9 = *(uint *)(param_1 + 0x1d7c) & 3;
  *(undefined4 *)(*(char *)(iVar8 + uVar9 + 0x2b8) * 4 + uVar9 * 0x20 + iVar8 + 0x218) = 0;
  uVar9 = *(uint *)(param_1 + 0x1d7c) & 3;
  *(undefined1 *)(uVar9 * 8 + iVar8 + 0x298 + (int)*(char *)(iVar8 + uVar9 + 0x2b8)) = 0xff;
  *(uint *)(param_1 + 0x1d7c) = *(uint *)(param_1 + 0x1d7c) | 0x1fc;
LAB_8004e384:
  FUN_80032654(param_2,FUN_8004e3b0);
  return;
}



// ---- FUN_8004e3b0 @ 8004e3b0

void FUN_8004e3b0(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar1 + 1 & 0xfffff;
  if (uVar1 < 0xf) {
    FUN_80033848(param_1 + 0x27b0,0,8,1);
    FUN_80033848(param_1 + 0x27f0,0,8,0xf);
    FUN_80033848(param_1 + 0x2730,0,8,1);
    FUN_80033848(param_1 + 0x2770,0,8,1);
  }
  else {
    FUN_80032d9c(param_1 + 0x27b0,0);
    FUN_80032d9c(param_1 + 0x27f0,0);
    FUN_80032d9c(param_1 + 0x2730,0);
    FUN_80032d9c(param_1 + 0x2770,0);
    *(uint *)(param_1 + 0x1acc) = *(uint *)(param_1 + 0x1acc) & 0xefffffff;
    if ((*(uint *)(param_1 + 0x1d80) & 4) == 0) {
      FUN_80032654(param_2,0);
      *(byte *)(param_1 + 0x1ac1) = *(byte *)(param_1 + 0x1ac1) | 2;
    }
    else {
      FUN_80032654(param_2,FUN_8004e4ec);
    }
  }
  return;
}



// ---- FUN_8004e4ec @ 8004e4ec

void FUN_8004e4ec(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  ushort local_20;
  ushort local_1e;
  
  cVar1 = FUN_8002bb78();
  if (cVar1 == '\0') {
    iVar3 = FUN_8002b8ac(0,0x1000,1,1,0);
    if (iVar3 != 0) {
      if (*(char *)(param_1 + 0x1d82) == '\0') {
        cVar1 = '\0';
      }
      else {
        cVar1 = *(char *)(param_1 + 0x1d82) + -1;
      }
      *(char *)(param_1 + 0x1d82) = cVar1;
    }
    iVar3 = FUN_8002b8ac(0,0x8000,1,1,0);
    if (iVar3 != 0) {
      if (*(char *)(param_1 + 0x1d81) == '\0') {
        cVar1 = '\0';
      }
      else {
        cVar1 = *(char *)(param_1 + 0x1d81) + -1;
      }
      *(char *)(param_1 + 0x1d81) = cVar1;
    }
    iVar3 = FUN_8002b8ac(0,0x4000,1,1,0);
    if (iVar3 != 0) {
      if (*(char *)(param_1 + 0x1d82) == -0x80) {
        cVar1 = -0x80;
      }
      else {
        cVar1 = *(char *)(param_1 + 0x1d82) + '\x01';
      }
      *(char *)(param_1 + 0x1d82) = cVar1;
    }
    iVar3 = FUN_8002b8ac(0,0x2000,1,1,0);
    if (iVar3 != 0) {
      if (*(char *)(param_1 + 0x1d81) == -0x40) {
        cVar1 = -0x40;
      }
      else {
        cVar1 = *(char *)(param_1 + 0x1d81) + '\x01';
      }
      *(char *)(param_1 + 0x1d81) = cVar1;
    }
  }
  else {
    FUN_8002bb90(1,&local_20);
    local_20 = local_20 - 0x20;
    local_1e = local_1e - 0x10;
    if (local_20 < 0xc1) {
      *(undefined1 *)(param_1 + 0x1d81) = (undefined1)local_20;
    }
    if (local_1e < 0x81) {
      *(undefined1 *)(param_1 + 0x1d82) = (undefined1)local_1e;
    }
  }
  *(uint *)(param_1 + 0x1d80) =
       *(uint *)(param_1 + 0x1d80) & 0xffffff07 |
       ((byte)(&DAT_800716d8)
              [(uint)(*(byte *)(param_1 + 0x1d82) >> 2) * 0x30 +
               (uint)(*(byte *)(param_1 + 0x1d81) >> 2)] & 0x1f) << 3;
  uVar2 = FUN_8002ba04(0x41);
  iVar3 = FUN_8002b8ac(0,uVar2,0,1,0);
  if (iVar3 == 0) {
    *(uint *)(param_1 + 0x1d7c) = *(uint *)(param_1 + 0x1d7c) & 0xfffff1ff | 0x200;
    FUN_80032654(param_2,FUN_8004da74);
  }
  return;
}



// ---- FUN_8004e73c @ 8004e73c

void FUN_8004e73c(int param_1,undefined4 param_2)

{
  code *pcVar1;
  
  *(undefined1 *)(param_1 + 0x1d9b) = 0;
  *(undefined1 *)(param_1 + 0x1d9e) = 0;
  *(undefined1 *)(param_1 + 0x1d9c) = 0;
  *(undefined4 *)(param_1 + 0x1da0) = 0;
  *(byte *)(param_1 + 0x1d9d) = (byte)(*(uint *)(param_1 + 0x1b28) >> 4) & 0xf;
  FUN_800585e4(param_1 + 0x1d84,0x17);
  FUN_800367d8(s__80071568,0x17,0,0xffffffff,0xe,0);
  FUN_8004d144(0xffffffff,0xffffffff,1);
  pcVar1 = FUN_8004e864;
  if ((*(uint *)(param_1 + 0x1af4) & 0x4000000) != 0) {
    pcVar1 = FUN_8004e7f8;
  }
  FUN_80032654(param_2,pcVar1);
  return;
}



// ---- FUN_8004e7f8 @ 8004e7f8

void FUN_8004e7f8(undefined4 param_1,int param_2)

{
  int iVar1;
  
  *(uint *)(param_2 + 0x18) =
       *(uint *)(param_2 + 0x18) & 0xfff00000 | (*(uint *)(param_2 + 0x18) & 0xfffff) + 1 & 0xfffff;
  iVar1 = FUN_8004a0a0();
  if (iVar1 == 1) {
    FUN_80032654(param_2,FUN_8004e864);
  }
  return;
}



// ---- FUN_8004e864 @ 8004e864

void FUN_8004e864(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = *(uint *)(param_1 + 0x1b28) >> 4 & 0xf;
  if (uVar1 != 3) {
    if (uVar1 < 4) {
      iVar3 = 0x34;
      if (uVar1 != 2) {
        iVar3 = 0;
      }
      goto LAB_8004e8ec;
    }
    if (uVar1 != 4) {
      iVar3 = 0x38;
      if (uVar1 != 5) {
        iVar3 = 0;
      }
      goto LAB_8004e8ec;
    }
  }
  iVar3 = 0x34;
LAB_8004e8ec:
  FUN_80032d9c(param_1 + 0x29b0,1);
  FUN_80033560(param_1 + 0x29f0,iVar3 + 0x1c,0x74,1);
  iVar2 = 0;
  if (*(char *)(param_1 + 0x1d9d) != '\0') {
    iVar5 = 0xa40;
    iVar4 = 0x780;
    do {
      FUN_80033560(param_1 + 0x22b0 + iVar4,(iVar2 * 0x10 + iVar3 + 0x20) * 0x10000 >> 0x10,0x74,1);
      FUN_80033560(param_1 + 0x22b0 + iVar5,(iVar2 * 0x10 + iVar3 + 0x22) * 0x10000 >> 0x10,0x6e,1);
      iVar5 = iVar5 + 0x40;
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 0x40;
    } while (iVar2 < (int)(uint)*(byte *)(param_1 + 0x1d9d));
  }
  FUN_80032654(param_2,FUN_8004e9c4);
  return;
}



// ---- FUN_8004e9c4 @ 8004e9c4

void FUN_8004e9c4(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar1 + 1 & 0xfffff;
  if (uVar1 < 0xf) {
    FUN_80033848(param_1 + 0x29b0,0,0xfffffff8,1);
  }
  else {
    FUN_80032d9c(param_1 + 0x29f0,1);
    FUN_80033a18(param_1 + 0x29f0,(uint)*(byte *)(param_1 + 0x1d9d) << 4 | 8,0,1);
    iVar2 = 0;
    if (*(char *)(param_1 + 0x1d9d) != '\0') {
      iVar3 = 0x780;
      do {
        FUN_80032d9c(param_1 + 0x22b0 + iVar3,1);
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x40;
      } while (iVar2 < (int)(uint)*(byte *)(param_1 + 0x1d9d));
    }
    *(uint *)(param_1 + 0x1d7c) = *(uint *)(param_1 + 0x1d7c) | 0x80000000;
    FUN_80032654(param_2,FUN_8004eae0);
  }
  return;
}



// ---- FUN_8004eae0 @ 8004eae0

void FUN_8004eae0(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar1 + 1 & 0xfffff;
  if (uVar1 < 10) {
    FUN_80033848(param_1 + 0x29f0,0,0xffffffff,1);
    FUN_80033bc8(param_1 + 0x29f0,0,2,0x40);
    iVar3 = 0;
    if (*(char *)(param_1 + 0x1d9d) != '\0') {
      iVar4 = 0x780;
      do {
        iVar2 = param_1 + 0x22b0 + iVar4;
        FUN_80033848(iVar2,0,0xffffffff,1);
        FUN_80033bc8(iVar2,0,2,0x40);
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x40;
      } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x1d9d));
    }
  }
  else {
    FUN_800358f0(param_1 + 0x48d8,1,0,0);
    iVar3 = 0;
    if (*(char *)(param_1 + 0x1d9d) != '\0') {
      iVar4 = 0xa40;
      do {
        FUN_80032d9c(param_1 + 0x22b0 + iVar4,1);
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x40;
      } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x1d9d));
    }
    FUN_80032654(param_2,FUN_8004ec40);
  }
  return;
}



// ---- FUN_8004ec40 @ 8004ec40

void FUN_8004ec40(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  ushort local_48;
  ushort local_46;
  
  iVar9 = 0;
  cVar1 = FUN_8002bb78();
  if (cVar1 != '\0') {
    FUN_8002bb90(1,&local_48);
    uVar3 = (uint)local_48;
    iVar6 = (uVar3 + 0xffdc) * 0x10000;
    iVar4 = iVar6 >> 0x10;
    if (iVar4 < 0) {
LAB_8004ed74:
      iVar6 = -1;
    }
    else if (iVar4 < 0x3c) {
      iVar6 = iVar6 >> 0x1f;
      iVar6 = (iVar4 / 6 + iVar6 >> 1) - iVar6;
    }
    else if ((iVar4 < 0x40) || (0x7b < iVar4)) {
      iVar6 = (int)((uVar3 + 0xffdc) * 0x10000) >> 0x10;
      if ((iVar6 < 0x80) || (0xbb < iVar6)) goto LAB_8004ed74;
      iVar4 = (uVar3 + 0xff5c) * 0x10000;
      iVar6 = iVar4 >> 0x1f;
      iVar6 = (((iVar4 >> 0x10) / 6 + iVar6 >> 1) - iVar6) + 10;
    }
    else {
      iVar4 = (uVar3 + 0xff9c) * 0x10000;
      iVar6 = iVar4 >> 0x1f;
      iVar6 = (((iVar4 >> 0x10) / 6 + iVar6 >> 1) - iVar6) + 5;
    }
    iVar4 = (int)((local_46 - 0xa0) * 0x10000) >> 0x10;
    if ((iVar4 < 0) || (0x37 < (local_46 - 0xa0 & 0xffff))) {
      sVar7 = -1;
    }
    else {
      sVar7 = (short)(iVar4 / 0xe);
    }
    if ((iVar6 << 0x10 < 0) || (sVar7 < 0)) {
      *(undefined1 *)(param_1 + 0x1d9e) = 0xff;
    }
    else {
      *(char *)(param_1 + 0x1d9e) = (char)iVar6 + (char)sVar7 * '\x0f';
    }
    goto LAB_8004efc8;
  }
  if (*(char *)(param_1 + 0x1d9e) < '\0') {
    *(undefined1 *)(param_1 + 0x1d9e) = 0;
  }
  iVar6 = FUN_8002b8ac(0,0xf000,0,5,0);
  if (iVar6 == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = *(int *)(param_1 + 0x1da0) + 1;
  }
  *(int *)(param_1 + 0x1da0) = iVar6;
  iVar6 = FUN_8002b8ac(0,0x8000,0,3,0);
  uVar5 = 0x8000;
  if (iVar6 == 0) {
    if (8 < *(uint *)(param_1 + 0x1da0)) {
      iVar6 = FUN_8002b8ac(0,0x8000,1,1,0);
      if ((iVar6 != 0) && (uVar5 = 0x8000, (*(uint *)(param_1 + 0x1da0) & 1) == 0))
      goto LAB_8004efc0;
    }
    iVar6 = FUN_8002b8ac(0,0x2000,0,3,0);
    uVar5 = 0x2000;
    if (iVar6 == 0) {
      if (8 < *(uint *)(param_1 + 0x1da0)) {
        iVar6 = FUN_8002b8ac(0,0x2000,1,1,0);
        if ((iVar6 != 0) && (uVar5 = 0x2000, (*(uint *)(param_1 + 0x1da0) & 1) == 0))
        goto LAB_8004efc0;
      }
      iVar6 = FUN_8002b8ac(0,0x1000,0,3,0);
      uVar5 = 0x1000;
      if (iVar6 == 0) {
        if (8 < *(uint *)(param_1 + 0x1da0)) {
          iVar6 = FUN_8002b8ac(0,0x1000,1,1,0);
          if ((iVar6 != 0) && (uVar5 = 0x1000, (*(uint *)(param_1 + 0x1da0) & 1) == 0))
          goto LAB_8004efc0;
        }
        iVar6 = FUN_8002b8ac(0,0x4000,0,3,0);
        uVar5 = 0x4000;
        if (iVar6 == 0) {
          if (*(uint *)(param_1 + 0x1da0) < 9) goto LAB_8004efc8;
          iVar6 = FUN_8002b8ac(0,0x4000,1,1,0);
          if ((iVar6 == 0) || (uVar5 = 0x4000, (*(uint *)(param_1 + 0x1da0) & 1) != 0))
          goto LAB_8004efc8;
        }
      }
    }
  }
LAB_8004efc0:
  FUN_8004f530(uVar5);
LAB_8004efc8:
  uVar2 = FUN_8002ba04(0x24);
  iVar6 = FUN_8002b8ac(0,uVar2,0,3,0);
  if ((iVar6 != 0) && (-1 < *(char *)(param_1 + 0x1d9e))) {
    iVar9 = FUN_8004f838(0);
    if (iVar9 == 0) {
      uVar5 = 0xffffffec;
    }
    else {
      uVar5 = 0xffffffed;
    }
    FUN_80031268(0x500,uVar5);
  }
  iVar6 = FUN_8002b8ac(0,0x800,0,3,0);
  if (iVar6 != 0) {
    FUN_80031268(0x500,0xffffffed);
    iVar9 = 1;
  }
  uVar2 = FUN_8002ba04(0x41);
  iVar6 = FUN_8002b8ac(0,uVar2,0,3,0);
  iVar4 = 0;
  if (iVar6 != 0) {
    FUN_80031268(0x500,0xffffffed);
    iVar9 = FUN_8004f838(1);
  }
  iVar6 = param_1 + 0x22b0;
  if (*(char *)(param_1 + 0x1d9d) != '\0') {
    iVar8 = 0x780;
    do {
      FUN_80033094(iVar6 + iVar8,0,0x70,0x38,1);
      iVar4 = iVar4 + 1;
      iVar8 = iVar8 + 0x40;
    } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x1d9d));
  }
  if ((uint)*(byte *)(param_1 + 0x1d9b) < (uint)*(byte *)(param_1 + 0x1d9d)) {
    FUN_80033094(iVar6 + (uint)*(byte *)(param_1 + 0x1d9b) * 0x40 + 0x780,0xff,0,0,1);
  }
  if (*(char *)(param_1 + 0x1d9e) < '\0') {
    FUN_800358f0(param_1 + 0x48d8,0,0,0);
  }
  else {
    FUN_800358f0(param_1 + 0x48d8,1,0,0);
    FUN_80035458(param_1 + 0x48d8,(&DAT_8007157c)[*(char *)(param_1 + 0x1d9e)],0,1);
  }
  if (iVar9 == 1) {
    FUN_80035458(param_1 + 0x48d8,DAT_8007157c,0,1);
    FUN_800358f0(param_1 + 0x48d8,0,0,0);
    iVar9 = 0;
    cVar1 = '\0';
    if (*(char *)(param_1 + 0x1d9d) != '\0') {
      iVar4 = 0xa40;
      do {
        FUN_80032d9c(iVar6 + iVar4,0);
        iVar9 = iVar9 + 1;
        iVar4 = iVar4 + 0x40;
      } while (iVar9 < (int)(uint)*(byte *)(param_1 + 0x1d9d));
      cVar1 = *(char *)(param_1 + 0x1d9d);
    }
    iVar9 = 0;
    if (cVar1 != '\0') {
      iVar4 = 0x780;
      do {
        FUN_80033094(iVar6 + iVar4,0,0x70,0x38,1);
        iVar9 = iVar9 + 1;
        iVar4 = iVar4 + 0x40;
      } while (iVar9 < (int)(uint)*(byte *)(param_1 + 0x1d9d));
    }
    FUN_80032654(param_2,FUN_8004f268);
  }
  return;
}



// ---- FUN_8004f268 @ 8004f268

void FUN_8004f268(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar2 + 1 & 0xfffff;
  if (uVar2 < 0xf) {
    FUN_80033848(param_1 + 0x29b0,0,8,1);
    if (uVar2 < 10) {
      FUN_80033848(param_1 + 0x29f0,0,1,1);
      FUN_80033bc8(param_1 + 0x29f0,0,0xfffffffe,0x40);
      iVar4 = 0;
      if (*(char *)(param_1 + 0x1d9d) != '\0') {
        iVar5 = 0x780;
        do {
          iVar3 = param_1 + 0x22b0 + iVar5;
          FUN_80033848(iVar3,0,1,1);
          FUN_80033bc8(iVar3,0,0xfffffffe,0x40);
          iVar4 = iVar4 + 1;
          iVar5 = iVar5 + 0x40;
        } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x1d9d));
      }
    }
  }
  else {
    FUN_80032d9c(param_1 + 0x29b0,0);
    if ((*(uint *)(param_1 + 0x1b28) & 0x100) == 0) {
      FUN_8004d144(0xffffffff,0xffffffff,0);
      uVar1 = 2;
      *(uint *)(param_1 + 0x1b28) = *(uint *)(param_1 + 0x1b28) & 0xffffff00 | 0xb0;
    }
    else {
      uVar1 = 0;
      *(uint *)(param_1 + 0x1d7c) = *(uint *)(param_1 + 0x1d7c) & 0x7fffffff;
      *(uint *)(param_1 + 0x1b28) =
           *(uint *)(param_1 + 0x1b28) & 0xfffffff9 |
           ((*(uint *)(param_1 + 0x1b28) >> 1 & 3) + 1 & 3) << 1;
    }
    uVar2 = FUN_80050d8c(param_1 + 0x1d84,param_1 + 7000,uVar1);
    *(uint *)(param_1 + 0x1d7c) = *(uint *)(param_1 + 0x1d7c) & 0xfffffe03 | (uVar2 & 0x7f) << 2;
    *(byte *)(param_1 + 0x1ac1) = *(byte *)(param_1 + 0x1ac1) | 2;
    FUN_80032654(param_2,0);
  }
  return;
}



// ---- FUN_8004f47c @ 8004f47c

void FUN_8004f47c(int param_1,undefined4 param_2)

{
  uint uVar1;
  
  FUN_8004d144(0xffffffff,0xffffffff,0);
  *(uint *)(param_1 + 0x1b28) = *(uint *)(param_1 + 0x1b28) & 0xffffff00 | 0xb0;
  uVar1 = FUN_80050d8c(param_1 + 0x1d84,param_1 + 7000,1);
  *(uint *)(param_1 + 0x1d7c) = *(uint *)(param_1 + 0x1d7c) & 0xfffffe03 | (uVar1 & 0x7f) << 2;
  FUN_80032654(param_2,0);
  *(byte *)(param_1 + 0x1ac1) = *(byte *)(param_1 + 0x1ac1) | 2;
  return;
}



// ---- FUN_8004f530 @ 8004f530

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8004f530(ushort param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  iVar1 = _DAT_800abf64;
  if (param_1 == 0) {
    return;
  }
  if ((param_1 & 0x1000) == 0) goto LAB_8004f5d0;
  iVar3 = FUN_8004f734(0x1000);
  if (iVar3 == 1) {
    cVar2 = *(char *)(iVar1 + 0x1d9e) + '-';
LAB_8004f5c8:
    *(char *)(iVar1 + 0x1d9e) = cVar2;
  }
  else if (iVar3 < 2) {
    if (iVar3 == 0) {
LAB_8004f5bc:
      cVar2 = *(char *)(iVar1 + 0x1d9e) + -0xf;
      goto LAB_8004f5c8;
    }
  }
  else if (iVar3 == 5) goto LAB_8004f5bc;
LAB_8004f5d0:
  if ((param_1 & 0x4000) == 0) goto LAB_8004f63c;
  iVar3 = FUN_8004f734(0x4000);
  if (iVar3 == 2) {
LAB_8004f628:
    cVar2 = *(char *)(iVar1 + 0x1d9e) + -0x2d;
LAB_8004f634:
    *(char *)(iVar1 + 0x1d9e) = cVar2;
  }
  else if (iVar3 < 3) {
    if (iVar3 == 0) {
      cVar2 = *(char *)(iVar1 + 0x1d9e) + '\x0f';
      goto LAB_8004f634;
    }
  }
  else if (iVar3 == 5) goto LAB_8004f628;
LAB_8004f63c:
  if ((param_1 & 0x8000) == 0) goto LAB_8004f6ac;
  iVar3 = FUN_8004f734(0x8000);
  if (iVar3 == 3) {
    cVar2 = *(char *)(iVar1 + 0x1d9e) + '\x0e';
  }
  else if (iVar3 < 4) {
    if (iVar3 != 0) goto LAB_8004f6ac;
    cVar2 = *(char *)(iVar1 + 0x1d9e) + -1;
  }
  else {
    cVar2 = '7';
    if (iVar3 != 5) goto LAB_8004f6ac;
  }
  *(char *)(iVar1 + 0x1d9e) = cVar2;
LAB_8004f6ac:
  if ((param_1 & 0x2000) == 0) {
    return;
  }
  iVar3 = FUN_8004f734(0x2000);
  if (iVar3 == 4) {
    cVar2 = *(char *)(iVar1 + 0x1d9e) + -0xe;
  }
  else if (iVar3 < 5) {
    if (iVar3 != 0) {
      return;
    }
    cVar2 = *(char *)(iVar1 + 0x1d9e) + '\x01';
  }
  else {
    cVar2 = '-';
    if (iVar3 != 5) {
      return;
    }
  }
  *(char *)(iVar1 + 0x1d9e) = cVar2;
  return;
}



// ---- FUN_8004f734 @ 8004f734

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_8004f734(ushort param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(char *)(_DAT_800abf64 + 0x1d9e);
  if ((int)uVar2 < 0x38) {
    if (param_1 == 0x2000) {
      uVar1 = (uint)((int)(uVar2 + 1) % 0xf == 0) << 2;
    }
    else {
      uVar1 = 0x1000;
      if (param_1 < 0x2001) {
        if (param_1 == 0x1000) {
          uVar1 = (uint)(uVar2 < 0xf);
        }
      }
      else if (param_1 == 0x4000) {
        uVar1 = (uint)(uVar2 - 0x2d < 0xc) << 1;
      }
      else {
        uVar1 = 0x8000;
        if (param_1 == 0x8000) {
          uVar1 = -(uint)((int)uVar2 % 0xf == 0) & 3;
        }
      }
    }
  }
  else {
    uVar1 = 5;
  }
  return uVar1;
}



// ---- FUN_8004f838 @ 8004f838

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8004f838(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined *puVar4;
  undefined1 uVar5;
  uint uVar6;
  int iVar7;
  undefined1 uVar8;
  
  iVar1 = _DAT_800abf64;
  uVar8 = DAT_8002869c;
  iVar7 = _DAT_800abf64 + 0x1ac0;
  uVar6 = (uint)*(byte *)(_DAT_800abf64 + 0x1d9b);
  if (param_1 == 0) {
    uVar3 = (int)((*(byte *)(_DAT_800abf64 + 0x1d9e) - 0x29) * 0x1000000) >> 0x18;
    if (uVar3 < 0x13) {
                    /* WARNING: Jumptable with 0 entries at 0x8004f918 */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*(code *)(&PTR_LAB_80028734)[uVar3])();
      return uVar2;
    }
    if (*(byte *)(_DAT_800abf64 + 0x1d9d) <= uVar6) {
      return 0;
    }
    if (*(char *)(_DAT_800abf64 + 0x1d9e) == '7') {
      puVar4 = &DAT_8002872c;
    }
    else {
      puVar4 = (&PTR_DAT_8007167c)[((int)*(char *)(_DAT_800abf64 + 0x1d9e) / 5) * 0x1000000 >> 0x18]
               + (((int)*(char *)(_DAT_800abf64 + 0x1d9e) % 5) * 0x1000000 >> 0x18) * 2;
    }
    FUN_80058664(iVar7 + uVar6 * 2 + 0x2c4,puVar4,2);
    uVar5 = (undefined1)(uVar6 + 1);
    *(undefined1 *)(iVar1 + 0x1d9b) = uVar5;
    if ((uint)*(byte *)(iVar1 + 0x1d9c) < uVar6 + 1) {
      *(undefined1 *)(iVar1 + 0x1d9c) = uVar5;
    }
  }
  else if (param_1 == 1) {
    if (uVar6 == 0) {
      return 0;
    }
    *(char *)(_DAT_800abf64 + 0x1d9b) = *(char *)(_DAT_800abf64 + 0x1d9b) + -1;
    if (uVar6 == 1) {
      FUN_80058664(iVar1 + 0x1d84,&DAT_8002872c,2);
    }
    else {
      iVar7 = (uVar6 - 1) * 2 + iVar7;
      *(undefined1 *)(iVar7 + 0x2c4) = 0;
      *(undefined1 *)(iVar7 + 0x2c5) = 0;
    }
  }
  FUN_800367d8(iVar1 + 0x1d84,0x17,0,0xffffffff,0xe,0,uVar8);
  return 0;
}



// ---- FUN_8004fbc4 @ 8004fbc4

void FUN_8004fbc4(int param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  
  local_28 = DAT_80028780;
  local_24 = DAT_80028784;
  local_20 = DAT_80028788;
  local_1c = DAT_8002878c;
  local_18 = DAT_80028790;
  local_14 = DAT_80028794;
  local_13 = DAT_80028795;
  local_12 = DAT_80028796;
  *(undefined1 *)(param_1 + 0x1dae) = 10;
  *(undefined1 *)(param_1 + 0x1daf) = 0;
  *(byte *)(param_1 + 0x1db1) = (byte)(*(uint *)(param_1 + 0x1b28) >> 4) & 0xf;
  FUN_800585e4(param_1 + 0x1da4,10);
  FUN_800367d8(&local_28,0x17,0,0xffffffff,0xe,0);
  pcVar1 = FUN_8004fd44;
  if ((*(uint *)(param_1 + 0x1af4) & 0x4000000) != 0) {
    pcVar1 = FUN_8004fcd8;
  }
  FUN_80032654(param_2,pcVar1);
  return;
}



// ---- FUN_8004fcd8 @ 8004fcd8

void FUN_8004fcd8(undefined4 param_1,int param_2)

{
  int iVar1;
  
  *(uint *)(param_2 + 0x18) =
       *(uint *)(param_2 + 0x18) & 0xfff00000 | (*(uint *)(param_2 + 0x18) & 0xfffff) + 1 & 0xfffff;
  iVar1 = FUN_8004a0a0();
  if (iVar1 == 1) {
    FUN_80032654(param_2,FUN_8004fd44);
  }
  return;
}



// ---- FUN_8004fd44 @ 8004fd44

void FUN_8004fd44(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  FUN_80032d9c(param_1 + 0x28b0,1);
  FUN_80032d9c(param_1 + 0x28f0,1);
  uVar1 = *(uint *)(param_1 + 0x1b28) >> 8 & 1;
  if (uVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 1;
    if (uVar1 != 1) goto LAB_8004fdac;
  }
  FUN_8004d144(uVar2,1,0xffffffff);
LAB_8004fdac:
  FUN_80032654(param_2,FUN_8004fdd4);
  return;
}



// ---- FUN_8004fdd4 @ 8004fdd4

void FUN_8004fdd4(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar1 + 1 & 0xfffff;
  if (uVar1 < 0xf) {
    FUN_80033848(param_1 + 0x28b0,0,0xfffffff8,1);
    FUN_80033848(param_1 + 0x28f0,0,0xfffffff8,0xf);
    FUN_80033848(param_1 + 0x2930,0,0xfffffff8,1);
    FUN_80035740(param_1 + 0x4820,0,0xfffffff8);
    FUN_80035740(param_1 + 0x487c,0,0xfffffff8);
  }
  else {
    FUN_80032d9c(param_1 + 0x2930,1);
    FUN_80032d9c(param_1 + 0x2970,1);
    FUN_800358f0(param_1 + 0x4820,1,0,0);
    FUN_800358f0(param_1 + 0x487c,(*(uint *)(param_1 + 0x1b28) >> 8 ^ 1) & 1,0,0);
    *(uint *)(param_1 + 0x1d80) = *(uint *)(param_1 + 0x1d80) | 1;
    FUN_80032654(param_2,FUN_8004ff00);
  }
  return;
}



// ---- FUN_8004ff00 @ 8004ff00

void FUN_8004ff00(int param_1,undefined4 param_2)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  undefined2 uVar5;
  uint uVar6;
  int iVar7;
  short sVar8;
  int iVar9;
  code *pcVar10;
  undefined4 uVar11;
  undefined2 *puVar12;
  int iVar13;
  int iVar14;
  undefined2 local_68;
  undefined1 local_66;
  ushort local_50;
  ushort local_4e;
  ushort local_48;
  ushort local_46;
  
  bVar2 = false;
  bVar3 = false;
  uVar6 = *(uint *)(param_1 + 0x1b28) >> 8 & 1;
  iVar14 = param_1 + 0x1ac0;
  if (uVar6 == 0) {
    cVar4 = FUN_8002bb78();
    if (cVar4 == '\0') {
      cVar4 = '\0';
      iVar7 = 10;
      if (-1 < *(char *)(param_1 + 0x1dae)) {
        iVar7 = (int)*(char *)(param_1 + 0x1dae);
      }
      iVar9 = FUN_8002b8ac(0,0x1000,0,3,0);
      if ((iVar9 != 0) && (cVar4 = -3, iVar7 < 3)) {
        cVar4 = '\t';
      }
      iVar9 = FUN_8002b8ac(0,0x4000,0,3,0);
      if ((iVar9 != 0) && (cVar4 = '\x03', 8 < iVar7)) {
        cVar4 = -9;
      }
      iVar9 = FUN_8002b8ac(0,0x8000,0,3,0);
      if (iVar9 != 0) {
        if (iVar7 == 0xb) {
          cVar4 = -2;
        }
        else {
          cVar4 = '\x02';
          if (iVar7 != (iVar7 / 3) * 3) {
            cVar4 = -1;
          }
        }
      }
      iVar9 = FUN_8002b8ac(0,0x2000,0,3,0);
      if (iVar9 != 0) {
        if (iVar7 == 10) {
          cVar4 = -1;
        }
        else {
          cVar4 = -2;
          if (iVar7 + 1 != ((iVar7 + 1) / 3) * 3) {
            cVar4 = '\x01';
          }
        }
      }
      cVar4 = *(char *)(param_1 + 0x1dae) + cVar4;
    }
    else {
      FUN_8002bb90(1,&local_50);
      iVar7 = (local_50 + 0xff4f) * 0x10000;
      if ((iVar7 < 0) || (iVar7 = iVar7 >> 0x14, 0x2f < (local_50 + 0xff4f & 0xffff))) {
        iVar7 = -1;
      }
      iVar9 = (int)((local_4e + 0xff60) * 0x10000) >> 0x10;
      if ((iVar9 < 0) || (0x37 < (local_4e + 0xff60 & 0xffff))) {
        sVar8 = -1;
      }
      else {
        sVar8 = (short)(iVar9 / 0xe);
      }
      if ((iVar7 << 0x10 < 0) || (sVar8 < 0)) {
        cVar4 = -1;
      }
      else {
        cVar4 = (char)iVar7 + (char)sVar8 * '\x03';
      }
    }
    *(char *)(param_1 + 0x1dae) = cVar4;
    uVar5 = FUN_8002ba04(0x41);
    iVar7 = FUN_8002b8ac(0,uVar5,0,3,0);
    if (iVar7 != 0) {
      FUN_80031268(0x500,0xffffffed);
      bVar3 = true;
      if (*(char *)(param_1 + 0x1daf) != '\0') {
        bVar2 = true;
        *(char *)(param_1 + 0x1daf) = *(char *)(param_1 + 0x1daf) + -1;
      }
    }
    uVar5 = FUN_8002ba04(0x24);
    iVar7 = FUN_8002b8ac(0,uVar5,0,3,0);
    if ((iVar7 != 0) && (-1 < *(char *)(param_1 + 0x1dae))) {
      if ((*(byte *)(param_1 + 0x1daf) < *(byte *)(param_1 + 0x1db1)) &&
         (*(char *)(param_1 + 0x1dae) < '\n')) {
        FUN_80031268(0x500,0xffffffec);
        bVar1 = *(byte *)(param_1 + 0x1daf);
        *(byte *)(param_1 + 0x1daf) = bVar1 + 1;
        *(undefined1 *)((uint)bVar1 + iVar14 + 0x2e4) = *(undefined1 *)(param_1 + 0x1dae);
      }
      else {
        FUN_80031268(0x500,0xffffffed);
      }
      bVar2 = true;
    }
    if (*(char *)(param_1 + 0x1dae) < '\0') {
      FUN_800358f0(param_1 + 0x4820,0,0,0);
    }
    else {
      FUN_800358f0(param_1 + 0x4820,1,0,0);
      FUN_80035458(param_1 + 0x4820,*(undefined1 *)(*(char *)(param_1 + 0x1dae) + -0x7ff8e958),0,1);
    }
    FUN_80033a18(param_1 + 0x2930,(uint)*(byte *)(param_1 + 0x1daf) * 0xc,0x10,1);
    FUN_80033560(param_1 + 0x2970,(uint)*(byte *)(param_1 + 0x1daf) * 0xc + 0xb,0xae,1);
    FUN_80032d9c(param_1 + 0x2970,*(byte *)(param_1 + 0x1daf) < *(byte *)(param_1 + 0x1db1));
    if ((bVar2) && (*(char *)(param_1 + 0x1dae) < '\n')) {
      FUN_800585e4(&local_68,0x17);
      iVar7 = 0;
      if (*(char *)(param_1 + 0x1daf) != '\0') {
        puVar12 = &local_68;
        do {
          FUN_80058664(puVar12,(uint)*(byte *)(iVar14 + iVar7 + 0x2e4) * 2 + -0x7ffd7868,2);
          iVar7 = iVar7 + 1;
          puVar12 = puVar12 + 1;
        } while (iVar7 < (int)(uint)*(byte *)(param_1 + 0x1daf));
      }
      FUN_800367d8(&local_68,0x17,0,0xffffffff,0xe,0);
    }
    if (bVar3) {
      return;
    }
    if ((!bVar2) || (*(char *)(param_1 + 0x1dae) < '\n')) {
      iVar7 = FUN_8002b8ac(0,0x800,0,3,0);
      if (iVar7 == 0) {
        return;
      }
      FUN_80031268(0x500,0xffffffed);
    }
    *(undefined1 *)(param_1 + 0x1db3) = 1;
    FUN_800585e4(&local_68,0x17);
    local_68 = DAT_800287b4;
    local_66 = DAT_800287b6;
    if (*(char *)(param_1 + 0x1daf) != '\0') {
      iVar7 = 1;
      iVar9 = 0;
      do {
        iVar13 = iVar7;
        FUN_80058664(&local_68 + iVar13,(uint)*(byte *)(iVar14 + iVar9 + 0x2e4) * 2 + -0x7ffd7868,2)
        ;
        iVar7 = iVar13 + 1;
        iVar9 = iVar13;
      } while (iVar13 < (int)(uint)*(byte *)(param_1 + 0x1daf));
    }
    uVar11 = 4;
    if ((*(uint *)(param_1 + 0x1b28) & 0xf0) == 0x20) {
      uVar11 = 3;
    }
    uVar6 = FUN_80050d8c(&local_68,param_1 + 7000,uVar11);
    pcVar10 = FUN_80050b10;
    *(uint *)(param_1 + 0x1d7c) = *(uint *)(param_1 + 0x1d7c) & 0xfffffe03 | (uVar6 & 0x7f) << 2;
  }
  else {
    if (uVar6 != 1) {
      return;
    }
    cVar4 = FUN_8002bb78();
    if (cVar4 == '\0') {
      cVar4 = '\0';
      iVar7 = 10;
      if (-1 < *(char *)(param_1 + 0x1dae)) {
        iVar7 = (int)*(char *)(param_1 + 0x1dae);
      }
      iVar9 = FUN_8002b8ac(0,0x1000,0,3,0);
      if ((iVar9 != 0) && (cVar4 = -3, iVar7 < 3)) {
        cVar4 = '\t';
      }
      iVar9 = FUN_8002b8ac(0,0x4000,0,3,0);
      if ((iVar9 != 0) && (cVar4 = '\x03', 8 < iVar7)) {
        cVar4 = -9;
      }
      iVar9 = FUN_8002b8ac(0,0x8000,0,3,0);
      if ((iVar9 != 0) && (cVar4 = '\x02', iVar7 != (iVar7 / 3) * 3)) {
        cVar4 = -1;
      }
      iVar9 = FUN_8002b8ac(0,0x2000,0,3,0);
      if ((iVar9 != 0) && (cVar4 = -2, iVar7 + 1 != ((iVar7 + 1) / 3) * 3)) {
        cVar4 = '\x01';
      }
      cVar4 = *(char *)(param_1 + 0x1dae) + cVar4;
    }
    else {
      FUN_8002bb90(1,&local_48);
      iVar7 = (local_48 + 0xff4f) * 0x10000;
      if ((iVar7 < 0) || (iVar7 = iVar7 >> 0x14, 0x2f < (local_48 + 0xff4f & 0xffff))) {
        iVar7 = -1;
      }
      iVar9 = (int)((local_46 + 0xff60) * 0x10000) >> 0x10;
      if ((iVar9 < 0) || (0x37 < (local_46 + 0xff60 & 0xffff))) {
        sVar8 = -1;
      }
      else {
        sVar8 = (short)(iVar9 / 0xe);
      }
      if ((iVar7 << 0x10 < 0) || (sVar8 < 0)) {
        cVar4 = -1;
      }
      else {
        cVar4 = (char)iVar7 + (char)sVar8 * '\x03';
      }
    }
    *(char *)(param_1 + 0x1dae) = cVar4;
    uVar5 = FUN_8002ba04(0x24);
    iVar7 = FUN_8002b8ac(0,uVar5,0,3,0);
    if ((iVar7 == 0) || (*(char *)(param_1 + 0x1dae) < 0)) {
      uVar5 = FUN_8002ba04(0x41);
      iVar7 = FUN_8002b8ac(0,uVar5,0,3,0);
      if (iVar7 != 0) {
        FUN_80031268(0x500,0xffffffed);
        if (*(char *)(param_1 + 0x1daf) == '\x01') {
          *(uint *)(param_1 + 0x1b28) = *(uint *)(param_1 + 0x1b28) & 0xfffffff9 | 4;
          *(byte *)(param_1 + 0x1ac1) = *(byte *)(param_1 + 0x1ac1) | 2;
          *(uint *)(param_1 + 0x1d7c) = *(uint *)(param_1 + 0x1d7c) | 0x1fc;
          FUN_80032654(param_2,0);
        }
        if (*(char *)(param_1 + 0x1daf) != '\0') {
          *(char *)(param_1 + 0x1daf) = *(char *)(param_1 + 0x1daf) + -1;
        }
      }
    }
    else {
      FUN_80031268(0x500,*(undefined4 *)
                          ((((int)*(char *)(param_1 + 0x1dae) % 3) * 0x1000000 >> 0x16) +
                          -0x7ff8e934));
      bVar2 = true;
      if (*(byte *)(param_1 + 0x1daf) < *(byte *)(param_1 + 0x1db1)) {
        bVar1 = *(byte *)(param_1 + 0x1daf);
        *(byte *)(param_1 + 0x1daf) = bVar1 + 1;
        *(undefined1 *)((uint)bVar1 + iVar14 + 0x2e4) = *(undefined1 *)(param_1 + 0x1dae);
      }
    }
    if (*(char *)(param_1 + 0x1dae) < '\0') {
      FUN_800358f0(param_1 + 0x4820,0,0,0);
    }
    else {
      FUN_800358f0(param_1 + 0x4820,1,0,0);
      FUN_80035458(param_1 + 0x4820,*(undefined1 *)(*(char *)(param_1 + 0x1dae) + -0x7ff8e94c),0,1);
    }
    FUN_80033a18(param_1 + 0x2930,(uint)*(byte *)(param_1 + 0x1daf) * 0xc,0x10,1);
    FUN_80033560(param_1 + 0x2970,(uint)*(byte *)(param_1 + 0x1daf) * 0xc + 0xb,0xae,1);
    FUN_80032d9c(param_1 + 0x2970,*(byte *)(param_1 + 0x1daf) < *(byte *)(param_1 + 0x1db1));
    if (!bVar2) {
      return;
    }
    FUN_800585e4(&local_68,0x17);
    iVar7 = 0;
    if (*(char *)(param_1 + 0x1daf) != '\0') {
      puVar12 = &local_68;
      do {
        FUN_80058664(puVar12,(uint)*(byte *)(iVar14 + iVar7 + 0x2e4) * 2 + -0x7ffd7848,2);
        iVar7 = iVar7 + 1;
        puVar12 = puVar12 + 1;
      } while (iVar7 < (int)(uint)*(byte *)(param_1 + 0x1daf));
    }
    FUN_800367d8(&local_68,0x17,0,0xffffffff,0xe,0);
    uVar6 = *(uint *)(param_1 + 0x1b28) >> 1 & 3;
    if (uVar6 == 1) {
      if ((*(char *)(param_1 + 0x1da4) == '\t') || (*(char *)(param_1 + 0x1da4) == '\v')) {
        *(uint *)(param_1 + 0x1d7c) = *(uint *)(param_1 + 0x1d7c) & 0xfffffe03;
      }
      else {
        FUN_800585e4(&local_68,0x17);
        local_68 = DAT_800287b4;
        local_66 = DAT_800287b6;
        if (*(char *)(param_1 + 0x1daf) != '\0') {
          iVar7 = 1;
          iVar9 = 0;
          do {
            iVar13 = iVar7;
            FUN_80058664(&local_68 + iVar13,
                         (uint)*(byte *)(iVar14 + iVar9 + 0x2e4) * 2 + -0x7ffd7848,2);
            iVar7 = iVar13 + 1;
            iVar9 = iVar13;
          } while (iVar13 < (int)(uint)*(byte *)(param_1 + 0x1daf));
        }
        uVar6 = FUN_80050d8c(&local_68,param_1 + 7000,1);
        *(uint *)(param_1 + 0x1d7c) = *(uint *)(param_1 + 0x1d7c) & 0xfffffe03 | (uVar6 & 0x7f) << 2
        ;
      }
      if (((*(uint *)(param_1 + 0x1d7c) & 0x1fc) == 0) &&
         (*(char *)(param_1 + 0x1daf) != *(char *)(param_1 + 0x1db1))) {
        return;
      }
      pcVar10 = FUN_80050b10;
    }
    else {
      if (uVar6 < 2) {
        if (uVar6 != 0) {
          return;
        }
      }
      else if (uVar6 != 2) {
        return;
      }
      uVar6 = (uint)*(byte *)(param_1 + 0x1da4);
      if ((uVar6 == 9) || (uVar6 == 0xb)) {
        *(uint *)(param_1 + 0x1d7c) = *(uint *)(param_1 + 0x1d7c) & 0xfffffe03;
      }
      else {
        *(uint *)(param_1 + 0x1d7c) =
             *(uint *)(param_1 + 0x1d7c) & 0xfffffe03 | ((byte)(&DAT_800716c0)[uVar6] & 0x7f) << 2;
      }
      *(uint *)(param_1 + 0x1b28) = *(uint *)(param_1 + 0x1b28) & 0xfffffff9 | 2;
      *(byte *)(param_1 + 0x1ac1) = *(byte *)(param_1 + 0x1ac1) | 2;
      pcVar10 = (code *)0x0;
    }
  }
  FUN_80032654(param_2,pcVar10);
  return;
}



// ---- FUN_80050b10 @ 80050b10

void FUN_80050b10(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar1 + 1 & 0xfffff;
  if (uVar1 == 0x1e) {
    FUN_80032654(param_2,FUN_80050b6c);
  }
  return;
}



// ---- FUN_80050b6c @ 80050b6c

void FUN_80050b6c(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar1 + 1 & 0xfffff;
  if (uVar1 < 0xf) {
    FUN_80033848(param_1 + 0x28b0,0,8,1);
    FUN_80033848(param_1 + 0x28f0,0,8,0xf);
    FUN_80033848(param_1 + 0x2970,0,8,1);
    FUN_80033848(param_1 + 0x2930,0,8,1);
    FUN_80035740(param_1 + 0x4820,0,8);
    FUN_80035740(param_1 + 0x487c,0,8);
  }
  else {
    FUN_80032d9c(param_1 + 0x28b0,0);
    FUN_80032d9c(param_1 + 0x28f0,0);
    FUN_80032d9c(param_1 + 0x2970,0);
    FUN_80032d9c(param_1 + 0x2930,0);
    FUN_800358f0(param_1 + 0x4820,0,0,0);
    FUN_80033a18(param_1 + 0x2930,0,0x78,1);
    FUN_80035458(param_1 + 0x4820,0,0,1);
    FUN_80035458(param_1 + 0x487c,0xc,0,1);
    FUN_8004d144(0xffffffff,0,0xffffffff);
    *(undefined1 *)(param_1 + 0x1dae) = 0xff;
    *(uint *)(param_1 + 0x1b28) = *(uint *)(param_1 + 0x1b28) & 0xffffff00 | 0xa0;
    *(uint *)(param_1 + 0x1d80) = *(uint *)(param_1 + 0x1d80) & 0xfffffffe;
    *(byte *)(param_1 + 0x1ac1) = *(byte *)(param_1 + 0x1ac1) | 2;
    FUN_80032654(param_2,0);
  }
  return;
}



// ---- FUN_80050d8c @ 80050d8c

int FUN_80050d8c(char *param_1,int *param_2,int param_3)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  
  iVar5 = 0;
  local_30 = DAT_8002869c;
  local_2f = DAT_8002869d;
  local_2e = DAT_8002869e;
  if (param_3 == 0) {
    if ((*param_1 != '\0') && (FUN_80058664(&local_30,param_1,2), *param_2 != 0)) {
      do {
        uVar4 = 0;
        uVar1 = FUN_80058624(*param_2);
        if (uVar1 >> 1 != 0) {
          do {
            iVar3 = FUN_80058654(uVar4 * 2 + *param_2,&local_30,2);
            uVar4 = uVar4 + 1;
            if (iVar3 == 0) {
              return iVar5;
            }
          } while (uVar4 < uVar1 >> 1);
        }
        param_2 = param_2 + 1;
        iVar5 = iVar5 + 1;
      } while (*param_2 != 0);
      return 0;
    }
  }
  else {
    if (param_3 < 0) {
      return (int)DAT_8002869c;
    }
    if (4 < param_3) {
      return 0;
    }
    uVar1 = FUN_80058624(param_1);
    uVar4 = 0;
    if (uVar1 != 0) {
      pcVar2 = param_1;
      do {
        if (*pcVar2 == ' ') {
          *pcVar2 = '\0';
          uVar1 = uVar4;
        }
        uVar4 = uVar4 + 1;
        pcVar2 = pcVar2 + 1;
      } while (uVar4 < uVar1);
    }
    if ((param_3 == 1) && (uVar1 == 0)) {
      return 0;
    }
    if ((param_3 == 2) && (uVar1 == 0)) {
      return 1;
    }
    if ((param_3 == 3) && (uVar1 == 2)) {
      return 1;
    }
    if (param_3 == 4) {
      if (uVar1 == 2) {
        return 1;
      }
      if (uVar1 == 4) {
        return 3;
      }
      if (uVar1 == 8) {
        iVar5 = FUN_80058654(param_1,&DAT_800287d4,4);
        iVar3 = 0xc;
        if (iVar5 == 0) {
          iVar3 = 2;
        }
        return iVar3;
      }
    }
    if (*param_2 != 0) {
      do {
        iVar3 = FUN_80058634(param_1,*param_2);
        param_2 = param_2 + 1;
        if (iVar3 == 0) {
          return iVar5;
        }
        iVar5 = iVar5 + 1;
      } while (*param_2 != 0);
    }
    if (((param_3 != 1) && (param_3 != 2)) && (param_3 != 3)) {
      if (param_3 != 4) {
        return 4;
      }
      iVar5 = FUN_80058654(param_1,&DAT_800287dc,4);
      if (iVar5 != 0) {
        iVar5 = FUN_80058654(param_1,&DAT_800287e4,4);
        if (iVar5 == 0) {
          return 9;
        }
        iVar5 = FUN_80058654(param_1,&DAT_800287ec,4);
        if (iVar5 == 0) {
          return 10;
        }
        return 0xb;
      }
    }
  }
  return 0;
}



// ---- FUN_80051050 @ 80051050

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80051050(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64 + 0x1fbc;
  FUN_80032568(iVar1,0);
  FUN_80032288(iVar1,0,1);
  return;
}



// ---- FUN_80051098 @ 80051098

void FUN_80051098(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_2 + 8) == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    if (*(int *)(param_2 + 8) != 1) goto LAB_800510d4;
    uVar1 = *(undefined4 *)(param_2 + 0xc);
  }
  *(undefined4 *)(param_1 + 0x1db8) = uVar1;
LAB_800510d4:
  FUN_80032654(param_1 + 0x1fbc,FUN_800510f4);
  return;
}



// ---- FUN_800510f4 @ 800510f4

void FUN_800510f4(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = *(uint *)(param_1 + 0x1af4) >> 0x1b & 3;
  if ((uVar1 != 2) && ((uVar1 < 3 || (uVar1 == 3)))) {
    uVar2 = 0xffffffff;
    if ((*(uint *)(param_1 + 0x1af4) & 2) != 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x1aec);
    }
    *(undefined4 *)(param_1 + 0x1b3c) = uVar2;
  }
  *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) & 0xfffffffd;
  *(undefined4 *)(param_1 + 0x544) = 0;
  FUN_80032654(param_2,FUN_8005119c);
  return;
}



// ---- FUN_8005119c @ 8005119c

void FUN_8005119c(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_800315cc(3);
  switch(uVar1) {
  case 0:
    *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) & 0xfffffffb;
    FUN_80032654(param_2,FUN_80051250);
    break;
  case 4:
    if ((*(uint *)(param_1 + 0x1af4) & 4) == 0) {
      *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) | 4;
      FUN_80031268(0,0xd4);
    }
  }
  return;
}



// ---- FUN_80051250 @ 80051250

void FUN_80051250(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x1db8);
  bVar1 = -1 < iVar2;
  if (!bVar1) {
    iVar2 = 0;
  }
  FUN_8002c57c(iVar2,&DAT_8010d000,bVar1,FUN_800512bc);
  FUN_80032654(param_2,0);
  return;
}



// ---- FUN_800512bc @ 800512bc

void FUN_800512bc(int param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  uVar2 = *(uint *)(param_1 + 0x1af4) >> 0x1b & 3;
  if (uVar2 == 1) {
    bVar1 = *(byte *)(param_1 + 0x1ac1);
    *(undefined4 *)(param_1 + 0x544) = 1;
    *(uint *)(param_1 + 0x1af4) =
         *(uint *)(param_1 + 0x1af4) & 0xfffffffd | (uint)(*(int *)(param_1 + 0x1b3c) != -1) << 1;
    uVar2 = *(uint *)(param_1 + 0x1af4) | 0x200;
  }
  else {
    if (uVar2 < 2) {
      if (uVar2 == 0) {
        *(byte *)(param_1 + 0x1ac1) = *(byte *)(param_1 + 0x1ac1) | 4;
        *(undefined4 *)(param_1 + 0x544) = 1;
        *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) & 0xfffffdff;
      }
      goto LAB_800513e8;
    }
    if (uVar2 == 2) {
      *(byte *)(param_1 + 0x1ac0) = *(byte *)(param_1 + 0x1ac0) & 0xf7;
      local_28 = 0;
      local_24 = *(undefined4 *)(param_1 + 0x1b3c);
      local_20 = 0;
      local_1c = 0;
      local_18 = 0;
      FUN_800364d8(2,&local_28);
      FUN_80032654(param_1 + 0x1fbc,FUN_80051410);
      goto LAB_800513e8;
    }
    if (uVar2 != 3) goto LAB_800513e8;
    bVar1 = *(byte *)(param_1 + 0x1ac1);
    *(undefined4 *)(param_1 + 0x544) = 1;
    uVar2 = *(uint *)(param_1 + 0x1af4) | 0x202;
  }
  *(byte *)(param_1 + 0x1ac1) = bVar1 | 4;
  *(uint *)(param_1 + 0x1af4) = uVar2;
LAB_800513e8:
  *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) & 0xe7ffffff;
  return;
}



// ---- FUN_80051410 @ 80051410

void FUN_80051410(int param_1,undefined4 param_2)

{
  if ((*(byte *)(param_1 + 0x1ac0) & 8) != 0) {
    *(undefined4 *)(param_1 + 0x544) = 1;
    *(byte *)(param_1 + 0x1ac1) = *(byte *)(param_1 + 0x1ac1) | 4;
    *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) | 0x200;
    FUN_80032654(param_2,0);
  }
  return;
}



// ---- FUN_80051468 @ 80051468

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80051468(void)

{
  int iVar1;
  
  iVar1 = _DAT_800abf64 + 0x1fd8;
  FUN_80032568(iVar1,0);
  FUN_80032288(iVar1,0,1);
  return;
}



// ---- FUN_800514b0 @ 800514b0

void FUN_800514b0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_2 + 8);
  *(int *)(param_1 + 0x1dbc) = iVar1;
  if (iVar1 == 0) {
    uVar3 = *(uint *)(param_2 + 0xc);
    *(uint *)(param_1 + 0x1dc0) = uVar3;
    if (uVar3 == 0x251) {
      FUN_8002d634(0x14,0);
      *(uint *)(param_1 + 0x1dc4) = *(uint *)(param_1 + 0x1dc4) | 3;
    }
    else {
      if (0x251 < uVar3) {
        if (uVar3 == 0x344) {
          uVar2 = 0x12;
        }
        else if (uVar3 < 0x345) {
          uVar2 = 0x10;
          if (uVar3 != 0x343) {
            *(undefined4 *)(param_1 + 0x160) = 0;
            goto LAB_80051604;
          }
        }
        else if (uVar3 == 0x345) {
          uVar2 = 0x11;
        }
        else {
          uVar2 = 0x15;
          if (uVar3 != 0x999) {
            *(undefined4 *)(param_1 + 0x160) = 0;
            goto LAB_80051604;
          }
        }
        goto LAB_800515f8;
      }
      if (uVar3 == 0x24f) {
        FUN_8002d634(0x14,0);
        *(uint *)(param_1 + 0x1dc4) = *(uint *)(param_1 + 0x1dc4) & 0xfffffffc | 1;
      }
      else if (uVar3 < 0x250) {
        if (uVar3 != 0x24e) {
          *(undefined4 *)(param_1 + 0x160) = 0;
          goto LAB_80051604;
        }
        FUN_8002d634(0x14,0);
        *(uint *)(param_1 + 0x1dc4) = *(uint *)(param_1 + 0x1dc4) & 0xfffffffc;
      }
      else {
        FUN_8002d634(0x14,0);
        *(uint *)(param_1 + 0x1dc4) = *(uint *)(param_1 + 0x1dc4) & 0xfffffffc | 2;
      }
    }
  }
  else {
    uVar2 = 0x14;
    if (iVar1 != 1) {
      *(undefined4 *)(param_1 + 0x160) = 0;
      goto LAB_80051604;
    }
LAB_800515f8:
    FUN_8002d634(uVar2,0);
  }
  *(undefined4 *)(param_1 + 0x160) = 0;
LAB_80051604:
  FUN_80032654(param_1 + 0x1fd8,FUN_8005162c);
  return;
}



// ---- FUN_8005162c @ 8005162c

void FUN_8005162c(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  
  FUN_8002d758(0,1);
  FUN_8002d758(1,1);
  iVar1 = FUN_8002d634(1,0);
  if (iVar1 == 1) {
    uVar2 = *(uint *)(param_1 + 0x160);
    *(uint *)(param_1 + 0x160) = uVar2 + 1;
    if (uVar2 < 0x3d) {
      pcVar3 = FUN_800516d4;
    }
    else {
      FUN_8002d634(0x21,2);
      pcVar3 = FUN_8005267c;
    }
    FUN_80032654(param_2,pcVar3);
  }
  return;
}



// ---- FUN_800516d4 @ 800516d4

void FUN_800516d4(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = FUN_8002d758(0,0);
  if (iVar1 == 1) {
    pcVar2 = FUN_8005162c;
  }
  else if (iVar1 < 2) {
    if (iVar1 != 0) {
      return;
    }
    pcVar2 = FUN_80051884;
  }
  else if (iVar1 == 2) {
    pcVar2 = FUN_8005162c;
  }
  else {
    if (iVar1 != 3) {
      return;
    }
    pcVar2 = FUN_80051788;
  }
  FUN_80032654(param_2,pcVar2);
  return;
}



// ---- FUN_80051788 @ 80051788

void FUN_80051788(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  FUN_8002d758(0,1);
  FUN_8002d758(1,1);
  iVar1 = FUN_8002d634(2,0);
  if (iVar1 == 1) {
    FUN_80032654(param_2,FUN_800517ec);
  }
  return;
}



// ---- FUN_800517ec @ 800517ec

void FUN_800517ec(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = FUN_8002d758(1,0);
  if (iVar1 != 1) {
    if (iVar1 < 2) {
      if (iVar1 != 0) {
        return;
      }
      pcVar2 = FUN_80051884;
      goto LAB_80051868;
    }
    if ((iVar1 != 2) && (iVar1 != 3)) {
      return;
    }
  }
  pcVar2 = FUN_8005162c;
LAB_80051868:
  FUN_80032654(param_2,pcVar2);
  return;
}



// ---- FUN_80051884 @ 80051884

void FUN_80051884(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  
  uVar1 = FUN_8002d634(0x20,0);
  switch(uVar1) {
  case 0x10:
    FUN_8002d758(0,1);
    FUN_8002d758(1,1);
    iVar2 = FUN_8002d634(3,0);
    if (iVar2 != 1) {
      return;
    }
    pcVar3 = FUN_80051990;
    break;
  case 0x11:
    pcVar3 = FUN_80051a44;
    break;
  case 0x12:
    pcVar3 = FUN_80051ac0;
    break;
  case 0x13:
    pcVar3 = FUN_80051be8;
    break;
  case 0x14:
    pcVar3 = FUN_80051cb4;
    break;
  case 0x15:
    pcVar3 = FUN_8005217c;
    break;
  default:
    FUN_8002d634(0x21,0xffffffff);
    pcVar3 = FUN_8005267c;
  }
  FUN_80032654(param_2,pcVar3);
  return;
}



// ---- FUN_80051990 @ 80051990

void FUN_80051990(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = FUN_8002d758(0,0);
  if (iVar1 == 1) {
    pcVar2 = FUN_8005162c;
  }
  else if (iVar1 < 2) {
    if (iVar1 != 0) {
      return;
    }
    pcVar2 = FUN_80051be8;
  }
  else if (iVar1 == 2) {
    pcVar2 = FUN_8005162c;
  }
  else {
    if (iVar1 != 3) {
      return;
    }
    pcVar2 = FUN_8005267c;
  }
  FUN_80032654(param_2,pcVar2);
  return;
}



// ---- FUN_80051a44 @ 80051a44

void FUN_80051a44(int param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = FUN_80058394((&PTR_s_bu00__80071d98)[*(byte *)(param_1 + 0x15d)]);
  if (iVar1 == 1) {
    pcVar2 = FUN_80052598;
  }
  else {
    FUN_8002d634(0x21,0xfffffffd);
    pcVar2 = FUN_8005267c;
  }
  FUN_80032654(param_2,pcVar2);
  return;
}



// ---- FUN_80051ac0 @ 80051ac0

void FUN_80051ac0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  code *pcVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 auStack_270 [600];
  
  iVar6 = 0;
  iVar1 = FUN_8002d860(0,auStack_270,0);
  if (iVar1 == 0) {
    iVar1 = FUN_8002d860(0,auStack_270,1);
    iVar3 = 0;
    if (0 < iVar1) {
      puVar2 = auStack_270;
      do {
        iVar3 = iVar3 + 1;
        iVar6 = iVar6 + *(int *)(puVar2 + 0x18);
        puVar2 = puVar2 + 0x28;
      } while (iVar3 < iVar1);
    }
    if (iVar6 < 0x1c001) {
      iVar1 = FUN_800585b4(*(undefined4 *)(param_1 + 0x134),0x10200);
      *(int *)(param_1 + 0x130) = iVar1;
      if (iVar1 != -1) {
        FUN_80058334();
        pcVar4 = FUN_800521f8;
        goto LAB_80051bbc;
      }
      uVar5 = 4;
    }
    else {
      uVar5 = 0xfffffffb;
    }
    FUN_8002d634(0x21,uVar5);
    pcVar4 = FUN_8005267c;
  }
  else {
    pcVar4 = FUN_80052598;
  }
LAB_80051bbc:
  FUN_80032654(param_2,pcVar4);
  return;
}



// ---- FUN_80051be8 @ 80051be8

void FUN_80051be8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  undefined1 auStack_268 [600];
  
  iVar5 = 0;
  iVar1 = FUN_8002d860(0,auStack_268,0);
  if (iVar1 == 0) {
    iVar1 = FUN_8002d860(0,auStack_268,1);
    iVar3 = 0;
    if (0 < iVar1) {
      puVar2 = auStack_268;
      do {
        iVar3 = iVar3 + 1;
        iVar5 = iVar5 + *(int *)(puVar2 + 0x18);
        puVar2 = puVar2 + 0x28;
      } while (iVar3 < iVar1);
    }
    FUN_8002d634(0x21,-(uint)(0x1c000 < iVar5) & 0xfffffffb);
    pcVar4 = FUN_8005267c;
  }
  else {
    pcVar4 = FUN_80052598;
  }
  FUN_80032654(param_2,pcVar4);
  return;
}



// ---- FUN_80051cb4 @ 80051cb4

void FUN_80051cb4(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = FUN_8002d758(0,0);
  if (iVar1 == 0) {
    pcVar2 = FUN_80051d30;
  }
  else if (iVar1 == 3) {
    pcVar2 = FUN_8005267c;
  }
  else {
    pcVar2 = FUN_8005162c;
  }
  FUN_80032654(param_2,pcVar2);
  return;
}



// ---- FUN_80051d30 @ 80051d30

void FUN_80051d30(int param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int unaff_s3;
  undefined4 unaff_s4;
  
  iVar1 = FUN_800585b4(*(undefined4 *)(param_1 + 0x134),0x8001);
  puVar3 = (undefined4 *)(param_1 + 0x130);
  *(int *)(param_1 + 0x130) = iVar1;
  if (iVar1 == -1) {
    FUN_8002d634(0x21,4);
    pcVar2 = FUN_8005267c;
  }
  else {
    if (*(int *)(param_1 + 0x1dbc) == 0) {
      unaff_s4 = 0x780;
      unaff_s3 = (*(uint *)(param_1 + 0x1dc4) & 3) * 0x780 + 0x200;
    }
    else if (*(int *)(param_1 + 0x1dbc) == 1) {
      unaff_s3 = 0x200;
      unaff_s4 = 0x1e00;
    }
    iVar1 = FUN_80058324(*puVar3,unaff_s3,0);
    if (iVar1 == -1) {
      FUN_80058334(*puVar3);
      pcVar2 = FUN_80052058;
    }
    else {
      FUN_8002d758(0,1);
      FUN_8002d758(1,1);
      iVar1 = FUN_80058584(*puVar3,*(undefined4 *)(param_1 + 0x138),unaff_s4);
      if (iVar1 == 0) {
        pcVar2 = FUN_80051e90;
      }
      else {
        FUN_80058334(*puVar3);
        pcVar2 = FUN_80052058;
      }
    }
  }
  FUN_80032654(param_2,pcVar2);
  return;
}



// ---- FUN_80051e90 @ 80051e90

void FUN_80051e90(int param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = FUN_8002d758(0,0);
  if (iVar1 < 0) {
    return;
  }
  iVar1 = FUN_8002d758(0,0);
  if (iVar1 == 1) {
    pcVar2 = FUN_80052058;
  }
  else if (iVar1 < 2) {
    if (iVar1 != 0) goto LAB_80051f3c;
    pcVar2 = FUN_80051f60;
  }
  else {
    if ((iVar1 != 2) && (iVar1 != 3)) goto LAB_80051f3c;
    pcVar2 = FUN_8005267c;
  }
  FUN_80032654(param_2,pcVar2);
LAB_80051f3c:
  FUN_80058334(*(undefined4 *)(param_1 + 0x130));
  return;
}



// ---- FUN_80051f60 @ 80051f60

void FUN_80051f60(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x138);
  if (*(int *)(param_1 + 0x1dbc) == 0) {
    iVar3 = FUN_8002dae0(iVar4);
    if (iVar3 < 0) {
      FUN_8002d634(0x21,iVar3);
      pcVar2 = FUN_8005267c;
    }
    else {
      pcVar2 = FUN_80052598;
      *(undefined1 *)(param_1 + 0x1ac0 + (*(uint *)(param_1 + 0x1dc4) & 3) + 0x30c) =
           *(undefined1 *)(iVar4 + iVar3 * 0x3c0);
    }
  }
  else {
    iVar3 = 0;
    if (*(int *)(param_1 + 0x1dbc) != 1) {
      return;
    }
    do {
      uVar1 = FUN_8002dae0(iVar4);
      *(undefined1 *)(param_1 + 0x1ac0 + iVar3 + 0x310) = uVar1;
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x780;
    } while (iVar3 < 4);
    pcVar2 = FUN_80052598;
  }
  FUN_80032654(param_2,pcVar2);
  return;
}



// ---- FUN_80052058 @ 80052058

void FUN_80052058(int param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  int *piVar3;
  int unaff_s1;
  int unaff_s2;
  
  piVar3 = (int *)(param_1 + 0x130);
  if (*(int *)(param_1 + 0x1dbc) == 0) {
    unaff_s2 = 0x780;
    unaff_s1 = (*(uint *)(param_1 + 0x1dc4) & 3) * 0x780 + 0x200;
  }
  else if (*(int *)(param_1 + 0x1dbc) == 1) {
    unaff_s1 = 0x200;
    unaff_s2 = 0x1e00;
  }
  do {
    iVar1 = FUN_800585b4(*(undefined4 *)(param_1 + 0x134),1);
    *piVar3 = iVar1;
  } while (iVar1 == -1);
  do {
    iVar1 = FUN_80058324(*piVar3,unaff_s1,0);
  } while (iVar1 == -1);
  iVar1 = FUN_80058584(*piVar3,*(undefined4 *)(param_1 + 0x138),unaff_s2);
  if (iVar1 == unaff_s2) {
    FUN_80058334(*piVar3);
    pcVar2 = FUN_80051f60;
  }
  else {
    FUN_80058334(*piVar3);
    FUN_8002d634(0x21,0xfffffffc);
    pcVar2 = FUN_8005267c;
  }
  FUN_80032654(param_2,pcVar2);
  return;
}



// ---- FUN_8005217c @ 8005217c

void FUN_8005217c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = FUN_8002d758(0,0);
  if (iVar1 == 0) {
    pcVar2 = FUN_800521f8;
  }
  else if (iVar1 == 3) {
    pcVar2 = FUN_8005267c;
  }
  else {
    pcVar2 = FUN_8005162c;
  }
  FUN_80032654(param_2,pcVar2);
  return;
}



// ---- FUN_800521f8 @ 800521f8

void FUN_800521f8(int param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int unaff_s3;
  undefined4 unaff_s4;
  
  iVar1 = FUN_800585b4(*(undefined4 *)(param_1 + 0x134),0x8002);
  puVar3 = (undefined4 *)(param_1 + 0x130);
  *(int *)(param_1 + 0x130) = iVar1;
  if (iVar1 == -1) {
    FUN_8002d634(0x21,4);
    pcVar2 = FUN_8005267c;
  }
  else {
    iVar1 = FUN_8002d634(0x20,0);
    if (iVar1 == 0x12) {
      unaff_s3 = 0;
      unaff_s4 = 0x2000;
      FUN_8002d918(*(undefined4 *)(param_1 + 0x138));
    }
    else if (iVar1 == 0x15) {
      unaff_s4 = 0x780;
      unaff_s3 = (*(uint *)(param_1 + 0x1dc4) & 3) * 0x780 + 0x200;
      FUN_8002da78(*(undefined4 *)(param_1 + 0x138));
    }
    iVar1 = FUN_80058324(*puVar3,unaff_s3,0);
    if (iVar1 == -1) {
      FUN_80058334(*puVar3);
      pcVar2 = FUN_80052448;
    }
    else {
      FUN_8002d758(0,1);
      FUN_8002d758(1,1);
      iVar1 = FUN_80058344(*puVar3,*(undefined4 *)(param_1 + 0x138),unaff_s4);
      if (iVar1 == 0) {
        pcVar2 = FUN_80052378;
      }
      else {
        FUN_80058334(*puVar3);
        pcVar2 = FUN_80052448;
      }
    }
  }
  FUN_80032654(param_2,pcVar2);
  return;
}



// ---- FUN_80052378 @ 80052378

void FUN_80052378(int param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = FUN_8002d758(0,0);
  if (iVar1 < 0) {
    return;
  }
  iVar1 = FUN_8002d758(0,0);
  if (iVar1 == 1) {
    pcVar2 = FUN_80052448;
  }
  else if (iVar1 < 2) {
    if (iVar1 != 0) goto LAB_80052424;
    pcVar2 = FUN_80052598;
  }
  else {
    if ((iVar1 != 2) && (iVar1 != 3)) goto LAB_80052424;
    pcVar2 = FUN_8005267c;
  }
  FUN_80032654(param_2,pcVar2);
LAB_80052424:
  FUN_80058334(*(undefined4 *)(param_1 + 0x130));
  return;
}



// ---- FUN_80052448 @ 80052448

void FUN_80052448(int param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  int *piVar3;
  int unaff_s1;
  int unaff_s3;
  
  piVar3 = (int *)(param_1 + 0x130);
  do {
    iVar1 = FUN_800585b4(*(undefined4 *)(param_1 + 0x134),0x8002);
    *piVar3 = iVar1;
  } while (iVar1 == -1);
  iVar1 = FUN_8002d634(0x20,0);
  if (iVar1 == 0x12) {
    unaff_s1 = 0;
    unaff_s3 = 0x2000;
    FUN_8002d918(*(undefined4 *)(param_1 + 0x138));
  }
  else if (iVar1 == 0x15) {
    unaff_s3 = 0x780;
    unaff_s1 = (*(uint *)(param_1 + 0x1dc4) & 3) * 0x780 + 0x200;
    FUN_8002da78(*(undefined4 *)(param_1 + 0x138));
  }
  do {
    iVar1 = FUN_80058324(*piVar3,unaff_s1,0);
  } while (iVar1 == -1);
  iVar1 = FUN_80058344(*piVar3,*(undefined4 *)(param_1 + 0x138),unaff_s3);
  if (iVar1 == unaff_s3) {
    FUN_80058334(*piVar3);
    pcVar2 = FUN_80052598;
  }
  else {
    FUN_80058334(*piVar3);
    FUN_8002d634(0x21,0xfffffffc);
    pcVar2 = FUN_8005267c;
  }
  FUN_80032654(param_2,pcVar2);
  return;
}



// ---- FUN_80052598 @ 80052598

void FUN_80052598(int param_1,undefined4 param_2)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x1dbc) == 0) {
    uVar1 = *(uint *)(param_1 + 0x1dc0);
    if (uVar1 == 0x251) {
      *(uint *)(param_1 + 0x1b18) = (uint)*(byte *)(param_1 + 0x1dcf);
    }
    else if (uVar1 < 0x252) {
      if (uVar1 == 0x24f) {
        *(uint *)(param_1 + 0x1b18) = (uint)*(byte *)(param_1 + 0x1dcd);
      }
      else if (uVar1 < 0x250) {
        if (uVar1 == 0x24e) {
          *(uint *)(param_1 + 0x1b18) = (uint)*(byte *)(param_1 + 0x1dcc);
        }
      }
      else {
        *(uint *)(param_1 + 0x1b18) = (uint)*(byte *)(param_1 + 0x1dce);
      }
    }
    else {
      if (uVar1 != 0x344) {
        if (uVar1 < 0x345) {
          if (uVar1 != 0x343) goto LAB_8005265c;
        }
        else if ((uVar1 != 0x345) && (uVar1 != 0x999)) goto LAB_8005265c;
      }
      *(undefined4 *)(param_1 + 0x1b18) = 0;
    }
  }
LAB_8005265c:
  FUN_80032654(param_2,FUN_80052878);
  return;
}



// ---- FUN_8005267c @ 8005267c

/* WARNING: Switch with 1 destination removed at 0x8005281c : 10 cases all go to same destination */

void FUN_8005267c(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_8002d634(0x22,0);
  if (*(int *)(param_1 + 0x1dbc) != 0) {
    if (*(int *)(param_1 + 0x1dbc) == 1) {
      *(uint *)(param_1 + 0x1dc4) = *(uint *)(param_1 + 0x1dc4) & 0xffffff83 | (uVar1 & 0x1f) << 2;
    }
    goto LAB_8005284c;
  }
  uVar2 = *(uint *)(param_1 + 0x1dc0);
  if (uVar2 == 0x343) {
    switch(uVar1) {
    case 2:
      goto switchD_800527dc_caseD_fffffffc;
    case 3:
switchD_800527a8_caseD_fffffffb:
      *(undefined4 *)(param_1 + 0x1b18) = 2;
      goto LAB_8005284c;
    case 0xfffffffb:
    case 0:
      *(undefined4 *)(param_1 + 0x1b18) = 3;
      goto LAB_8005284c;
    case 0xfffffffc:
    case 0xfffffffd:
    case 0xfffffffe:
    case 0xffffffff:
    case 1:
    case 4:
      goto switchD_800527dc_caseD_fffffffb;
    default:
      goto switchD_800527dc_default;
    }
  }
  if (uVar2 < 0x344) {
    if ((0x251 < uVar2) || (uVar2 < 0x24e)) goto LAB_8005284c;
switchD_800527dc_caseD_fffffffb:
    *(undefined4 *)(param_1 + 0x1b18) = 0xffffffff;
LAB_8005284c:
    FUN_80032654(param_2,FUN_80052878);
    return;
  }
  if (uVar2 != 0x345) {
    if (0x344 < uVar2) {
      if (uVar2 != 0x999) goto LAB_8005284c;
      switch(uVar1) {
      case 0xfffffffb:
      case 0xfffffffd:
      case 0xfffffffe:
      case 0xffffffff:
      case 0:
      case 2:
      case 3:
        goto switchD_800527dc_caseD_fffffffb;
      case 0xfffffffc:
      case 1:
      case 4:
        goto switchD_800527dc_caseD_fffffffc;
      default:
        goto switchD_800527dc_default;
      }
    }
    switch(uVar1) {
    case 0xfffffffb:
      goto switchD_800527a8_caseD_fffffffb;
    case 0xfffffffc:
    case 1:
    case 4:
      goto switchD_800527dc_caseD_fffffffc;
    case 0xfffffffd:
    case 0xfffffffe:
    case 0xffffffff:
    case 0:
    case 2:
    case 3:
      goto switchD_800527dc_caseD_fffffffb;
    default:
      goto switchD_800527dc_default;
    }
  }
  switch(uVar1) {
  case 0xfffffffb:
  case 0xfffffffc:
  case 0xfffffffe:
  case 0xffffffff:
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
    goto switchD_800527dc_caseD_fffffffb;
  case 0xfffffffd:
switchD_800527dc_caseD_fffffffc:
    *(undefined4 *)(param_1 + 0x1b18) = 1;
    goto LAB_8005284c;
  default:
switchD_800527dc_default:
    *(undefined4 *)(param_1 + 0x1b18) = 0xffffffff;
    goto LAB_8005284c;
  }
}



// ---- FUN_80052878 @ 80052878

void FUN_80052878(int param_1,undefined4 param_2)

{
  *(byte *)(param_1 + 0x1ac1) = *(byte *)(param_1 + 0x1ac1) | 8;
  FUN_80032654(param_2,0);
  return;
}



// ---- FUN_800528ac @ 800528ac

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800528ac(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _DAT_800abf64;
  iVar2 = _DAT_800abf64 + 0x2160;
  _DAT_800a1d4c = _DAT_800abf64 + 0x1df0;
  _DAT_800a1d50 = _DAT_800abf64 + 0x1e10;
  FUN_80032568(iVar2,0);
  FUN_80032288(iVar2,0,1);
  FUN_80032568(iVar1 + 0x217c,0);
  FUN_80032288(iVar1 + 0x217c,iVar2,1);
  FUN_80032568(iVar1 + 0x2198,0);
  FUN_80032288(iVar1 + 0x2198,iVar2,1);
  FUN_80032568(iVar1 + 0x21b4,0);
  FUN_80032288(iVar1 + 0x21b4,iVar2,1);
  FUN_80032568(iVar1 + 0x21d0,0);
  FUN_80032288(iVar1 + 0x21d0,iVar2,1);
  FUN_8002c57c(0xc0,0x80136800,4,0);
  FUN_8002c57c(199,0x80135000,4,0);
  FUN_8002c57c(0xce,0x80136000,4,FUN_800529e8);
  return;
}



// ---- FUN_800529e8 @ 800529e8

void FUN_800529e8(int param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  undefined1 auStack_78 [32];
  undefined1 auStack_58 [48];
  
  FUN_8002ca58(auStack_78,0,0x80136800,0x801a6800,0);
  FUN_8002cbc8(auStack_78,&DAT_80071e38,&DAT_80071e3c);
  FUN_8002cd20(auStack_78,&DAT_80071e40,0,0,0xffffffff);
  iVar3 = param_1 + 0x2ff0;
  FUN_800328a4(iVar3,0xf);
  FUN_80032288(iVar3,param_1 + 0x2160,1);
  FUN_80032b80(iVar3,1);
  FUN_80032d78(iVar3,1);
  FUN_80032d54(iVar3,4);
  FUN_80032e54(iVar3,0,0);
  bVar5 = 0;
  FUN_80032e0c(iVar3,DAT_80071e38);
  FUN_80033dcc(iVar3,10,1,1);
  FUN_80032d9c(iVar3,0);
  uVar2 = 0;
  do {
    iVar3 = param_1 + 0x22b0 + uVar2 * 0x40 + 0xd80;
    FUN_800328a4(iVar3,4);
    FUN_80032288(iVar3,param_1 + 0x2160,1);
    pcVar1 = (code *)0x0;
    if (uVar2 == 0) {
      pcVar1 = FUN_80054ef4;
    }
    FUN_800340c8(iVar3,pcVar1);
    FUN_80032b80(iVar3,1);
    FUN_80032d78(iVar3,1);
    FUN_80032d54(iVar3,4);
    FUN_80032e54(iVar3,0,0);
    FUN_80032d9c(iVar3,0);
    iVar3 = param_1 + 0x22b0 + uVar2 * 0x40 + 0xe00;
    FUN_800328a4(iVar3,4);
    FUN_80032288(iVar3,param_1 + 0x2160,1);
    FUN_800340c8(iVar3,0);
    FUN_80032b80(iVar3,1);
    FUN_80032d78(iVar3,1);
    FUN_80032d54(iVar3,4);
    FUN_80032e54(iVar3,0,0);
    FUN_80032d9c(iVar3,0);
    bVar5 = bVar5 + 1;
    uVar2 = (uint)bVar5;
  } while (bVar5 < 2);
  FUN_8002ca58(auStack_78,auStack_58,0x80135000,0x801a6800,0);
  FUN_8002cbc8(auStack_78,&DAT_80071e28,&DAT_80071e2c);
  FUN_8002cd20(auStack_78,&DAT_80071e30,&DAT_80071e34,1,0xffffffff);
  FUN_8002cf6c(auStack_58,&DAT_80071e50,&DAT_80071e54);
  FUN_8002d178(auStack_58,&DAT_80071e58,&DAT_80071e5c,1,0xffffffff);
  iVar3 = param_1 + 0x2fb0;
  FUN_800328a4(iVar3,0xf);
  iVar4 = param_1 + 0x2160;
  FUN_80032288(iVar3,iVar4,1);
  FUN_800340c8(iVar3,0);
  FUN_80032b80(iVar3,1);
  FUN_80032d78(iVar3,0);
  FUN_80032e54(iVar3,1,1);
  FUN_80032e0c(iVar3,DAT_80071e28);
  FUN_80033094(iVar3,0x80,0x80,0x80,1);
  FUN_80033560(iVar3,0x20,0x10,1);
  FUN_80033a18(iVar3,0xc0,0x80,0);
  FUN_80033d40(iVar3,0,0,1);
  FUN_80032fac(iVar3,0x1b,0xe);
  FUN_80032d9c(iVar3,0);
  iVar3 = param_1 + 0x4ccc;
  FUN_80034bec(iVar3);
  FUN_80032288(iVar3,iVar4,1);
  FUN_80035ab8(iVar3,0);
  FUN_80034e00(iVar3,0,1);
  FUN_80034e34(iVar3,auStack_58,0);
  FUN_800351a0(iVar3,&DAT_80071e50,&DAT_80071e54,0xffffffff);
  FUN_80035434(iVar3,0);
  FUN_800358f0(iVar3,0,0,0);
  FUN_80035458(iVar3,0,0,1);
  FUN_8003571c(iVar3,0x20,0x10);
  FUN_80035694(iVar3,0x1c,0xc);
  *(undefined1 *)(param_1 + 0x1ded) = 0;
  FUN_8002ca58(0,auStack_58,0x80136000,0x801a6800,0);
  FUN_8002cf6c(auStack_58,&DAT_80071e28,&DAT_80071e44);
  FUN_8002d178(auStack_58,&DAT_80071e48,&DAT_80071e4c,1,0xffffffff);
  iVar3 = param_1 + 0x4c70;
  FUN_80034bec(iVar3);
  FUN_80032288(iVar3,iVar4,1);
  FUN_80034e00(iVar3,0,1);
  FUN_80034e34(iVar3,auStack_58,0);
  FUN_800351a0(iVar3,&DAT_80071e28,&DAT_80071e44,0xffffffff);
  FUN_80035434(iVar3,0);
  FUN_80035458(iVar3,*(undefined1 *)(param_1 + 0x1ded),0,1);
  FUN_80035694(iVar3,0x1c,(&DAT_80071e4c)[*(byte *)(param_1 + 0x1ded)]);
  iVar3 = param_1 + 0x3130;
  FUN_800328a4(iVar3,0x12);
  FUN_80032288(iVar3,iVar4,1);
  FUN_800340c8(iVar3,0);
  FUN_80032b80(iVar3,1);
  FUN_80032d54(iVar3,4);
  FUN_80032e54(iVar3,0,0);
  FUN_80032d9c(iVar3,0);
  *(byte *)(param_1 + 0x1ac1) = *(byte *)(param_1 + 0x1ac1) | 0x10;
  return;
}



// ---- FUN_80052fcc @ 80052fcc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80052fcc(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = _DAT_800abf64;
  *_DAT_800a1d4c = 4;
  _DAT_800a1d4c[1] = (*_DAT_800a1d4c % 3) * '?' + 0x20;
  _DAT_800a1d4c[2] = (*_DAT_800a1d4c / 3) * '*' + 0x10;
  _DAT_800a1d4c[3] = 0;
  _DAT_800a1d4c[4] = 0;
  _DAT_800a1d4c[5] = 0;
  _DAT_800a1d4c[6] = 0;
  _DAT_800a1d4c[0x10] = 0;
  _DAT_800a1d4c[0x11] = 0;
  _DAT_800a1d4c[0x12] = 0;
  _DAT_800a1d4c[0x13] = 0;
  _DAT_800a1d4c[0x15] = 0;
  pbVar1 = _DAT_800a1d4c;
  _DAT_800a1d4c[0x18] = 0;
  pbVar2 = _DAT_800a1d4c;
  pbVar1[0x1c] = 0;
  pbVar1[0x1d] = 0;
  pbVar1[0x1e] = 0;
  pbVar1[0x1f] = 0;
  pbVar2[0x14] = 0;
  iVar5 = 0;
  _DAT_800a1d4c[0x17] = 0;
  do {
    _DAT_800a1d4c[iVar5 + 7] = 0;
    *(undefined1 *)(_DAT_800a1d50 + iVar5) = 0;
    *(undefined1 *)(_DAT_800a1d50 + iVar5 + 9) = 0;
    *(undefined1 *)(_DAT_800a1d50 + iVar5 + 0x16) = 0;
    iVar4 = _DAT_800a1d50 + iVar5;
    iVar5 = iVar5 + 1;
    *(undefined1 *)(iVar4 + 0x1f) = 0;
  } while (iVar5 < 9);
  *(undefined1 *)(_DAT_800a1d50 + 0x12) = 0;
  *(undefined1 *)(_DAT_800a1d50 + 0x13) = 0;
  *(undefined1 *)(_DAT_800a1d50 + 0x15) = 0;
  *(undefined1 *)(_DAT_800a1d50 + 0x28) = 0;
  *(undefined1 *)(_DAT_800a1d50 + 0x29) = 0;
  *(undefined1 *)(iVar3 + 0x1de6) = 0;
  *(undefined1 *)(iVar3 + 0x1deb) = 0;
  *(undefined1 *)(iVar3 + 0x1de9) = 0;
  *(undefined1 *)(iVar3 + 0x1de7) = 0;
  *(undefined1 *)(iVar3 + 0x1dea) = 0;
  *(undefined1 *)(iVar3 + 0x1de8) = 0;
  DAT_80071e20 = 1;
  FUN_80032654(_DAT_800abf64 + 0x2160,FUN_8005323c);
  return;
}



// ---- FUN_8005323c @ 8005323c

void FUN_8005323c(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1aec) = 0xffffffff;
  *(undefined2 *)(param_1 + 0x1af2) = 0;
  *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) & 0xfffffffd;
  FUN_80031268(0,0xd1);
  *(undefined4 *)(param_1 + 0x1afc) = 0xffffffff;
  *(undefined2 *)(param_1 + 0x1b00) = 0;
  FUN_80031268(0,*(uint *)(param_1 + 0x1b08) | 0x1000);
  *(undefined4 *)(param_1 + 0x1b08) = 0xffffffff;
  *(undefined2 *)(param_1 + 0x1b0c) = 0;
  FUN_80032654(param_2,FUN_800532cc);
  return;
}



// ---- FUN_800532cc @ 800532cc

void FUN_800532cc(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_800315cc(3);
  switch(uVar1) {
  case 0:
    *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) & 0xfffffffb;
    FUN_80032654(param_2,FUN_80053384);
    break;
  case 4:
    if ((*(uint *)(param_1 + 0x1af4) & 4) == 0) {
      FUN_80031268(0,0xd4);
      *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) | 4;
    }
  }
  return;
}



// ---- FUN_80053384 @ 80053384

void FUN_80053384(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  if (*(char *)(param_1 + 0x1def) == '\0') {
    return;
  }
  switch(*(undefined4 *)(param_1 + 0x1de0)) {
  case 0x99d:
    uVar2 = 0xd;
    uVar1 = 0xb;
    break;
  case 0x99e:
    uVar2 = 0xe;
    uVar1 = 0xc;
    break;
  case 0x99f:
    uVar2 = 8;
    uVar1 = 5;
    break;
  case 0x9a0:
    uVar2 = 6;
    uVar1 = 3;
    break;
  case 0x9a1:
    uVar2 = 4;
    *(undefined4 *)(param_1 + 0x1de0) = 0;
    goto LAB_80053494;
  case 0x9a2:
    uVar2 = 5;
    uVar1 = 1;
    break;
  case 0x9a3:
    uVar2 = 5;
    uVar1 = 2;
    break;
  case 0x9a4:
    uVar2 = 0xf;
    uVar1 = 0xd;
    break;
  case 0x9a5:
    uVar2 = 0x10;
    uVar1 = 0xe;
    break;
  case 0x9a6:
    uVar2 = 7;
    uVar1 = 4;
    break;
  default:
    goto switchD_800533d8_caseD_9a7;
  case 0x9a9:
    uVar2 = 9;
    uVar1 = 6;
    break;
  case 0x9aa:
    uVar2 = 10;
    uVar1 = 7;
    break;
  case 0x9ab:
    uVar2 = 0xc;
    uVar1 = 10;
    break;
  case 0x9ac:
    uVar2 = 0xb;
    uVar1 = 8;
    break;
  case 0x9ad:
    uVar2 = 0xb;
    uVar1 = 9;
  }
  *(undefined4 *)(param_1 + 0x1de0) = uVar1;
LAB_80053494:
  FUN_8002c57c(uVar2,0x80105000,2,FUN_800537b8);
  if (*(int *)(param_1 + 0x1de0) == 0xb) {
    pcVar3 = FUN_800534f4;
  }
  else {
    pcVar3 = FUN_800536a8;
  }
  FUN_80032654(param_2,pcVar3);
switchD_800533d8_caseD_9a7:
  return;
}



// ---- FUN_800534f4 @ 800534f4

void FUN_800534f4(undefined4 param_1,undefined4 param_2)

{
  FUN_8002c57c(0x1d,0x800da800,5,0);
  FUN_8002c57c(0x1d,0x80166800,6,FUN_80053558);
  FUN_80032654(param_2,0);
  return;
}



// ---- FUN_80053558 @ 80053558

void FUN_80053558(int param_1)

{
  FUN_80031884(0x1d,0x80166800,2);
  FUN_80032654(param_1 + 0x2160,FUN_800535a0);
  return;
}



// ---- FUN_800535a0 @ 800535a0

void FUN_800535a0(undefined4 param_1,undefined4 param_2)

{
  FUN_8002c57c(0x1f,0x800db800,5,0);
  FUN_8002c57c(0x1f,0x80166800,6,FUN_80053604);
  FUN_80032654(param_2,0);
  return;
}



// ---- FUN_80053604 @ 80053604

void FUN_80053604(int param_1)

{
  FUN_80031884(0x1f,0x80166800,3);
  FUN_80032654(param_1 + 0x2160,FUN_8005364c);
  return;
}



// ---- FUN_8005364c @ 8005364c

void FUN_8005364c(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar1 + 1 & 0xfffff;
  if (uVar1 == 10) {
    FUN_80032654(param_2,FUN_800536a8);
  }
  return;
}



// ---- FUN_800536a8 @ 800536a8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800536a8(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  iVar1 = FUN_800315cc(2);
  if (iVar1 == 0) {
    switch(*(undefined4 *)(param_1 + 0x1de0)) {
    case 0:
      if (*(char *)(_DAT_800a1d4c + 0x18) == '\0') goto switchD_80053700_default;
      uVar2 = 0xdb;
      break;
    case 1:
    case 2:
    case 8:
    case 9:
    case 0xd:
      uVar2 = 0xdd;
      break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 10:
    case 0xb:
    case 0xc:
    case 0xe:
      uVar2 = 0xde;
      break;
    default:
      goto switchD_80053700_default;
    }
    FUN_80031268(0x300,uVar2);
  }
switchD_80053700_default:
  *(undefined1 *)(_DAT_800a1d4c + 0x14) = 1;
  if (*(char *)(_DAT_800a1d4c + 0x15) != '\0') {
    if (*(int *)(param_1 + 0x1de0) == 0) {
      pcVar3 = (code *)0x0;
    }
    else {
      pcVar3 = FUN_80054004;
    }
    FUN_80032654(param_2,pcVar3);
  }
  return;
}



// ---- FUN_800537b8 @ 800537b8

void FUN_800537b8(int param_1)

{
  FUN_80032654(param_1 + 0x217c,FUN_80053804);
  (*(code *)**(undefined4 **)(param_1 + 0x1dd4))(param_1,0);
  return;
}



// ---- FUN_80053804 @ 80053804

void FUN_80053804(int param_1,undefined4 param_2)

{
  code *pcVar1;
  
  if (*(int *)(param_1 + 0x1de0) == 0) {
    pcVar1 = FUN_8005384c;
  }
  else {
    pcVar1 = FUN_8005388c;
  }
  FUN_80032654(param_2,pcVar1);
  return;
}



// ---- FUN_8005384c @ 8005384c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8005384c(undefined4 param_1,undefined4 param_2)

{
  if (*(char *)(_DAT_800a1d4c + 6) != '\0') {
    FUN_80032654(param_2,FUN_80053cb4);
  }
  return;
}



// ---- FUN_8005388c @ 8005388c

void FUN_8005388c(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar5 = param_1 + 0x2ff0;
  FUN_800340c8(iVar5,0);
  FUN_80033094(iVar5,0x80,0x80,0x80,1);
  FUN_80033560(iVar5,8,0x98,1);
  FUN_80033a18(iVar5,0xf0,0x20,0);
  FUN_80032fac(iVar5,0x1c,0);
  FUN_80033dcc(iVar5,10,1,1);
  FUN_80032e54(iVar5,0,0);
  FUN_80032d9c(iVar5,1);
  iVar5 = 0;
  do {
    iVar1 = iVar5 * 9;
    iVar6 = param_1 + 0x22b0 + iVar5 * 0x40 + 0xd80;
    FUN_80033094(iVar6,(&DAT_80071dac)[iVar1],(&DAT_80071dad)[iVar1],(&DAT_80071dae)[iVar1],1);
    iVar8 = iVar5 + 1;
    iVar2 = iVar8 * 3;
    FUN_80033094(iVar6,(&DAT_80071dac)[iVar2],(&DAT_80071dad)[iVar2],(&DAT_80071dae)[iVar2],2);
    iVar3 = (2 - iVar5) * 3;
    FUN_80033094(iVar6,(&DAT_80071dac)[iVar3],(&DAT_80071dad)[iVar3],(&DAT_80071dae)[iVar3],4);
    iVar4 = (iVar5 * -3 + 3) * 3;
    FUN_80033094(iVar6,(&DAT_80071dac)[iVar4],(&DAT_80071dad)[iVar4],(&DAT_80071dae)[iVar4],8);
    iVar7 = (iVar5 * 8 + 0xa0) * 0x10000 >> 0x10;
    FUN_80033560(iVar6,0x33,iVar7,1);
    FUN_80033a18(iVar6,DAT_80071e00,DAT_80071e01,0);
    FUN_80032e54(iVar6,0,0);
    FUN_80032d9c(iVar6,1);
    iVar5 = param_1 + 0x22b0 + iVar5 * 0x40 + 0xe00;
    FUN_80033094(iVar5,(&DAT_80071da0)[iVar1],(&DAT_80071da1)[iVar1],(&DAT_80071da2)[iVar1],1);
    FUN_80033094(iVar5,(&DAT_80071da0)[iVar2],(&DAT_80071da1)[iVar2],(&DAT_80071da2)[iVar2],2);
    FUN_80033094(iVar5,(&DAT_80071da0)[iVar3],(&DAT_80071da1)[iVar3],(&DAT_80071da2)[iVar3],4);
    FUN_80033094(iVar5,(&DAT_80071da0)[iVar4],(&DAT_80071da1)[iVar4],(&DAT_80071da2)[iVar4],8);
    FUN_80033560(iVar5,0x33,iVar7,1);
    FUN_80033a18(iVar5,DAT_80071e00,DAT_80071e01,0);
    FUN_80032e54(iVar5,0,0);
    FUN_80032d9c(iVar5,1);
    iVar5 = iVar8;
  } while (iVar8 < 2);
  FUN_80032654(param_2,FUN_80053cb4);
  return;
}



// ---- FUN_80053cb4 @ 80053cb4

void FUN_80053cb4(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 4;
  if (*(int *)(param_1 + 0x1de0) == 0) {
    uVar1 = 2;
  }
  iVar2 = param_1 + 0x4c70;
  FUN_80032d54(param_1 + 0x2fb0,uVar1);
  FUN_80035ab8(iVar2,FUN_800555ac);
  uVar1 = 4;
  if (*(int *)(param_1 + 0x1de0) == 0) {
    uVar1 = 2;
  }
  FUN_8003541c(iVar2,uVar1);
  FUN_8003571c(iVar2,0x20,0x10);
  FUN_800353e0(iVar2,0);
  FUN_8003579c(iVar2,1,1);
  FUN_800358f0(iVar2,0,0,0);
  FUN_80032654(param_2,FUN_80053f6c);
  FUN_80032654(param_1 + 0x2198,FUN_80053d98);
  return;
}



// ---- FUN_80053d98 @ 80053d98

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80053d98(int param_1)

{
  char cVar1;
  int iVar2;
  
  if ((*(char *)(_DAT_800a1d4c + 0x15) != '\0') || (*(char *)(_DAT_800a1d4c + 0x14) == '\0'))
  goto LAB_80053eec;
  cVar1 = FUN_8002bb78();
  if (cVar1 == '\0') {
    iVar2 = FUN_8002b8ac(0,0x100,0,3,0);
    if (iVar2 == 0) goto LAB_80053eec;
    *(undefined1 *)(param_1 + 0x1dea) = 1;
    if (*(char *)(_DAT_800a1d4c + 3) == '\0') goto LAB_80053e7c;
    if (*(char *)(_DAT_800a1d4c + 3) != '\x01') goto LAB_80053eec;
  }
  else {
    iVar2 = FUN_8002b8ac(0,0x40,0,3,0);
    if (iVar2 == 0) goto LAB_80053eec;
    *(undefined1 *)(param_1 + 0x1dea) = 1;
    if (*(char *)(_DAT_800a1d4c + 3) == '\0') {
LAB_80053e7c:
      FUN_80031268(0x500,0x282);
      FUN_80032d9c(param_1 + 0x2fb0,1);
      FUN_800358f0(param_1 + 0x4c70,1,0,0);
      *(undefined1 *)(_DAT_800a1d4c + 3) = 1;
      goto LAB_80053eec;
    }
    if (*(char *)(_DAT_800a1d4c + 3) != '\x01') goto LAB_80053eec;
    FUN_8002bbf0(1);
  }
  FUN_80032d9c(param_1 + 0x2fb0,0);
  FUN_800358f0(param_1 + 0x4c70,0,0,0);
  *(undefined1 *)(_DAT_800a1d4c + 3) = 0;
LAB_80053eec:
  if ((*(char *)(_DAT_800a1d4c + 0x12) == '\x01') && (DAT_80071e24 == '\0')) {
    if (*(char *)(_DAT_800a1d4c + 3) == '\x01') {
      DAT_80071e24 = '\x01';
      FUN_800340c8(param_1 + 0x2fb0,FUN_80055498);
    }
    else {
      *(undefined1 *)(_DAT_800a1d4c + 0x12) = 0;
    }
  }
  return;
}



// ---- FUN_80053f6c @ 80053f6c

void FUN_80053f6c(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = param_1 + 0x4ccc;
  FUN_80035ab8(iVar2,FUN_80055b74);
  uVar1 = 5;
  if (*(int *)(param_1 + 0x1de0) == 0) {
    uVar1 = 3;
  }
  FUN_8003541c(iVar2,uVar1);
  FUN_8003571c(iVar2,0x20,0x10);
  FUN_800358f0(iVar2,0,0,0);
  FUN_80032654(param_2,0);
  return;
}



// ---- FUN_80054004 @ 80054004

void FUN_80054004(int param_1,undefined4 param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  byte abStack_68 [6];
  byte abStack_62 [82];
  
  FUN_80032d9c(param_1 + 0x2fb0,0);
  FUN_800358f0(param_1 + 0x4c70,0,0,0);
  FUN_800358f0(param_1 + 0x4ccc,0,0,0);
  iVar3 = 0;
  do {
    iVar1 = (uint)*(byte *)(param_1 + 0x1deb) * 0xc;
    bVar2 = (&DAT_80071dac)[iVar3 + iVar1];
    if (0x80 < (byte)(&DAT_80071dac)[iVar3 + iVar1]) {
      bVar2 = bVar2 + 0x80;
    }
    abStack_68[iVar3 + iVar1] = bVar2;
    iVar1 = (uint)*(byte *)(param_1 + 0x1deb) * 0xc;
    bVar2 = (&DAT_80071db2)[iVar3 + iVar1];
    if (0x80 < (byte)(&DAT_80071db2)[iVar3 + iVar1]) {
      bVar2 = bVar2 + 0x80;
    }
    abStack_62[iVar3 + iVar1] = bVar2;
    (&DAT_800a1d64)[iVar3] =
         (abStack_68[iVar3 + (uint)*(byte *)(param_1 + 0x1deb) * 0xc] / 0x30) * '0';
    (&DAT_800a1d6a)[iVar3] =
         (abStack_62[iVar3 + (uint)*(byte *)(param_1 + 0x1deb) * 0xc] / 0x30) * '0';
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  DAT_800a1d5c = DAT_800a1d64 / 0x30;
  DAT_800a1d5d = DAT_800a1d65 / 0x30;
  DAT_800a1d5e = DAT_800a1d66 / 0x30;
  DAT_800a1d60 = DAT_800a1d6a / 0x30;
  DAT_800a1d61 = DAT_800a1d6b / 0x30;
  DAT_800a1d62 = DAT_800a1d6c / 0x30;
  FUN_80032654(param_2,FUN_80054290);
  return;
}



// ---- FUN_80054290 @ 80054290

void FUN_80054290(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar9 = param_1 + 0x22b0;
  uVar5 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar5 + 1 & 0xfffff;
  if (uVar5 == 0x40) {
    FUN_80054d00(0x1c,0x1c,1);
    param_1 = param_1 + 0x2ff0;
    FUN_80032fac(param_1,0x1c,0);
    FUN_80033094(param_1,0x60,0x60,0x60,1);
    FUN_80032e54(param_1,1,1);
    iVar4 = 0;
    iVar8 = 0;
    do {
      if (iVar8 == 0) {
        uVar1 = DAT_800a1d66;
        uVar2 = DAT_800a1d65;
        uVar3 = DAT_800a1d64;
      }
      else {
        uVar1 = DAT_800a1d6c;
        uVar2 = DAT_800a1d6b;
        uVar3 = DAT_800a1d6a;
      }
      FUN_80033094(iVar9 + iVar4 + 0xd80,uVar3,uVar2,uVar1,1);
      if (iVar8 == 0) {
        uVar1 = DAT_800a1d66;
        uVar2 = DAT_800a1d65;
        uVar3 = DAT_800a1d64;
      }
      else {
        uVar1 = DAT_800a1d6c;
        uVar2 = DAT_800a1d6b;
        uVar3 = DAT_800a1d6a;
      }
      FUN_80033094(iVar9 + iVar8 * 0x40 + 0xd80,uVar3,uVar2,uVar1,2);
      if (iVar8 == 0) {
        uVar1 = DAT_800a1d6c;
        uVar2 = DAT_800a1d6b;
        uVar3 = DAT_800a1d6a;
      }
      else {
        uVar1 = DAT_800a1d66;
        uVar2 = DAT_800a1d65;
        uVar3 = DAT_800a1d64;
      }
      FUN_80033094(iVar9 + iVar8 * 0x40 + 0xd80,uVar3,uVar2,uVar1,4);
      if (iVar8 == 0) {
        uVar1 = DAT_800a1d6c;
        uVar2 = DAT_800a1d6b;
        uVar3 = DAT_800a1d6a;
      }
      else {
        uVar1 = DAT_800a1d66;
        uVar2 = DAT_800a1d65;
        uVar3 = DAT_800a1d64;
      }
      FUN_80033094(iVar9 + iVar8 * 0x40 + 0xd80,uVar3,uVar2,uVar1,8);
      iVar6 = iVar9 + iVar8 * 0x40 + 0xe00;
      iVar4 = iVar8 * 9;
      FUN_80033094(iVar6,(&DAT_80071da0)[iVar4],(&DAT_80071da1)[iVar4],(&DAT_80071da2)[iVar4],1);
      iVar7 = iVar8 + 1;
      iVar4 = iVar7 * 3;
      FUN_80033094(iVar6,(&DAT_80071da0)[iVar4],(&DAT_80071da1)[iVar4],(&DAT_80071da2)[iVar4],2);
      iVar4 = (2 - iVar8) * 3;
      FUN_80033094(iVar6,(&DAT_80071da0)[iVar4],(&DAT_80071da1)[iVar4],(&DAT_80071da2)[iVar4],4);
      iVar4 = (iVar8 * -3 + 3) * 3;
      FUN_80033094(iVar6,(&DAT_80071da0)[iVar4],(&DAT_80071da1)[iVar4],(&DAT_80071da2)[iVar4],8);
      FUN_80032e54(iVar9 + iVar8 * 0x40 + 0xd80,1,1);
      FUN_80032e54(iVar6,1,1);
      iVar4 = iVar7 * 0x40;
      iVar8 = iVar7;
    } while (iVar7 < 2);
    FUN_80032654(param_2,FUN_800546c8);
  }
  return;
}



// ---- FUN_800546c8 @ 800546c8

void FUN_800546c8(int param_1,int param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char local_60 [8];
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [8];
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [8];
  undefined2 local_38;
  undefined2 local_36;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined2 local_2a;
  
  iVar5 = param_1 + 0x2ff0;
  *(uint *)(param_2 + 0x18) =
       *(uint *)(param_2 + 0x18) & 0xfff00000 | (*(uint *)(param_2 + 0x18) & 0xfffff) + 1 & 0xfffff;
  FUN_800331ac(iVar5,local_60,0);
  iVar7 = param_1 + 0x22b0;
  if (local_60[0] == '\0') {
    FUN_80032d9c(iVar5,0);
    FUN_80032d9c(param_1 + 0x3030,0);
    FUN_80032d9c(param_1 + 0x3070,0);
    FUN_80032d9c(param_1 + 0x30b0,0);
    FUN_80032d9c(param_1 + 0x30f0,0);
    FUN_80031eb4(0x1c,0,&local_38);
    local_2c = 0x100;
    local_2a = 1;
    local_30 = local_38;
    local_2e = local_36;
    FUN_8005997c(&local_30,0x800a1d70);
    FUN_800598fc(0);
    FUN_80032654(param_2,FUN_80054b78);
  }
  else {
    FUN_80033388(iVar5,0xfffffffe,0xfffffffe,0xfffffffe,0);
    iVar5 = 0;
    iVar9 = 0;
    iVar8 = 0xd80;
    do {
      FUN_800331ac(param_1 + 0x3030,auStack_58,1);
      FUN_800331ac(param_1 + 0x3030,auStack_50,4);
      FUN_800331ac(param_1 + 0x30b0,auStack_48,1);
      FUN_800331ac(param_1 + 0x30b0,auStack_40,4);
      if (iVar5 == 0) {
        cVar1 = DAT_800a1d5c;
      }
      else {
        cVar1 = DAT_800a1d60;
      }
      if (iVar5 == 0) {
        cVar2 = DAT_800a1d5d;
      }
      else {
        cVar2 = DAT_800a1d61;
      }
      if (iVar5 == 0) {
        cVar3 = DAT_800a1d5e;
      }
      else {
        cVar3 = DAT_800a1d62;
      }
      FUN_80033388(iVar7 + iVar8,(int)-cVar1,(int)-cVar2,(int)-cVar3,1);
      if (iVar5 == 0) {
        cVar1 = DAT_800a1d5c;
      }
      else {
        cVar1 = DAT_800a1d60;
      }
      if (iVar5 == 0) {
        cVar2 = DAT_800a1d5d;
      }
      else {
        cVar2 = DAT_800a1d61;
      }
      if (iVar5 == 0) {
        cVar3 = DAT_800a1d5e;
      }
      else {
        cVar3 = DAT_800a1d62;
      }
      FUN_80033388(iVar7 + iVar8,(int)-cVar1,(int)-cVar2,(int)-cVar3,2);
      if (iVar5 == 0) {
        cVar1 = DAT_800a1d60;
      }
      else {
        cVar1 = DAT_800a1d5c;
      }
      if (iVar5 == 0) {
        cVar2 = DAT_800a1d61;
      }
      else {
        cVar2 = DAT_800a1d5d;
      }
      if (iVar5 == 0) {
        cVar3 = DAT_800a1d62;
      }
      else {
        cVar3 = DAT_800a1d5e;
      }
      FUN_80033388(iVar7 + iVar8,(int)-cVar1,(int)-cVar2,(int)-cVar3,4);
      if (iVar5 == 0) {
        cVar1 = DAT_800a1d60;
      }
      else {
        cVar1 = DAT_800a1d5c;
      }
      if (iVar5 == 0) {
        cVar2 = DAT_800a1d61;
      }
      else {
        cVar2 = DAT_800a1d5d;
      }
      if (iVar5 == 0) {
        cVar3 = DAT_800a1d62;
      }
      else {
        cVar3 = DAT_800a1d5e;
      }
      FUN_80033388(iVar7 + iVar8,(int)-cVar1,(int)-cVar2,(int)-cVar3,8);
      iVar6 = iVar7 + iVar9 + 0xe00;
      uVar4 = -(uint)(iVar5 != 0);
      FUN_80033388(iVar6,uVar4,uVar4,uVar4 & 0xfffffffe,1);
      FUN_80033388(iVar6,uVar4,uVar4,uVar4 & 0xfffffffe,2);
      uVar4 = -(uint)(iVar5 == 0);
      FUN_80033388(iVar6,uVar4,uVar4,uVar4 & 0xfffffffe,4);
      FUN_80033388(iVar6,uVar4,uVar4,uVar4 & 0xfffffffe,8);
      iVar9 = iVar9 + 0x40;
      iVar5 = iVar5 + 1;
      iVar8 = iVar8 + 0x40;
    } while (iVar5 < 2);
  }
  return;
}



// ---- FUN_80054b78 @ 80054b78

void FUN_80054b78(int param_1,undefined4 param_2)

{
  FUN_80032654(param_1 + 0x2160,0);
  FUN_80032654(param_2,FUN_80054bb8);
  return;
}



// ---- FUN_80054bb8 @ 80054bb8

void FUN_80054bb8(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_800315cc(3);
  switch(uVar1) {
  case 0:
    *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) & 0xfffffffb;
    FUN_80032654(param_2,FUN_80054c84);
    break;
  case 1:
    FUN_80031268(0,0x74);
    break;
  case 4:
    if ((*(uint *)(param_1 + 0x1af4) & 4) == 0) {
      FUN_80031268(0,0xd4);
      *(uint *)(param_1 + 0x1af4) = *(uint *)(param_1 + 0x1af4) | 4;
    }
  }
  return;
}



// ---- FUN_80054c84 @ 80054c84

void FUN_80054c84(int param_1)

{
  FUN_80032d9c(param_1 + 0x3130,0);
  FUN_8002bbf0(1);
  FUN_80032654(param_1 + 0x2160,0);
  FUN_80032654(param_1 + 0x217c,0);
  FUN_80032654(param_1 + 0x2198,0);
  FUN_80032654(param_1 + 0x21b4,0);
  FUN_80032654(param_1 + 0x21d0,0);
  FUN_8004b220();
  return;
}



// ---- FUN_80054d00 @ 80054d00

void FUN_80054d00(undefined1 param_1,undefined1 param_2,char param_3)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ushort *puVar5;
  ushort local_220 [256];
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  
  FUN_80031eb4(param_1,0,&local_20);
  local_14 = 0x100;
  local_12 = 1;
  local_18 = local_20;
  local_16 = local_1e;
  FUN_800599b8(&local_18,0x800a1d70);
  FUN_800599b8(&local_18,local_220);
  FUN_800598fc(0);
  puVar5 = local_220;
  do {
    uVar1 = *puVar5;
    uVar3 = *puVar5 >> 10 & 0x1f;
    uVar2 = *puVar5 >> 5 & 0x1f;
    uVar4 = uVar1 & 0x1f;
    if (param_3 == '\0') {
      if ((uVar3 + uVar2 + uVar4 < 5) && (uVar3 * uVar2 * uVar4 == 0)) {
        uVar1 = uVar1 & 0x8000 | (ushort)(uVar3 << 10) | (ushort)(uVar2 << 5) | (ushort)uVar4;
LAB_80054e80:
        *puVar5 = uVar1;
      }
      else {
        uVar2 = (uVar3 * 299 + uVar2 * 0x24b + uVar4 * 0x72) / 1000 & 0x1f;
        *puVar5 = *puVar5 & 0x8000 | (ushort)(uVar2 << 10) | (ushort)(uVar2 << 5) | (ushort)uVar2;
      }
    }
    else {
      uVar1 = uVar1 | 0x8000;
      if (param_3 == '\x01') goto LAB_80054e80;
    }
    puVar5 = puVar5 + 1;
    if ((int)&local_20 <= (int)puVar5) {
      FUN_80031eb4(param_2,0,&local_20);
      local_14 = 0x100;
      local_12 = 1;
      local_18 = local_20;
      local_16 = local_1e;
      FUN_8005997c(&local_18,local_220);
      FUN_800598fc(0);
      return;
    }
  } while( true );
}



// ---- FUN_80054ef4 @ 80054ef4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80054ef4(int param_1,int param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  
  if (*(char *)(_DAT_800a1d4c + 0x13) == '\0') {
    *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000;
  }
  else {
    FUN_80031268(0x500,0xfffffff8);
    iVar11 = DAT_80071e20;
    uVar12 = *(uint *)(param_2 + 0x18) & 0xfffff;
    *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar12 + 1 & 0xfffff;
    uVar10 = (uint)(byte)((&DAT_80071e00)[(iVar11 + -1) * 2] - (&DAT_80071e00)[iVar11 * 2]);
    if (((&DAT_80071e00)[(iVar11 + -1) * 2] - (&DAT_80071e00)[iVar11 * 2] & 1) != 0) {
      uVar10 = uVar10 + 1;
    }
    uVar10 = uVar10 >> 1;
    iVar13 = DAT_80071e20 * 0xc;
    iVar11 = (DAT_80071e20 + -1) * 0xc;
    if (uVar10 == 0) {
      trap(0x1c00);
    }
    if ((uVar10 == 0xffffffff) &&
       ((uint)(byte)(&DAT_80071dac)[iVar13] - (uint)(byte)(&DAT_80071dac)[iVar11] == -0x80000000)) {
      trap(0x5d);
    }
    cVar4 = (char)((int)((uint)(byte)(&DAT_80071dac)[iVar13] - (uint)(byte)(&DAT_80071dac)[iVar11])
                  / (int)uVar10);
    if (uVar10 == 0) {
      trap(0x1c00);
    }
    if ((uVar10 == 0xffffffff) &&
       ((uint)(byte)(&DAT_80071db2)[iVar13] - (uint)(byte)(&DAT_80071db2)[iVar11] == -0x80000000)) {
      trap(0x5d);
    }
    cVar5 = (char)((int)((uint)(byte)(&DAT_80071db2)[iVar13] - (uint)(byte)(&DAT_80071db2)[iVar11])
                  / (int)uVar10);
    if (uVar10 == 0) {
      trap(0x1c00);
    }
    if ((uVar10 == 0xffffffff) &&
       ((uint)(byte)(&DAT_80071dad)[iVar13] - (uint)(byte)(&DAT_80071dad)[iVar11] == -0x80000000)) {
      trap(0x5d);
    }
    cVar6 = (char)((int)((uint)(byte)(&DAT_80071dad)[iVar13] - (uint)(byte)(&DAT_80071dad)[iVar11])
                  / (int)uVar10);
    if (uVar10 == 0) {
      trap(0x1c00);
    }
    if ((uVar10 == 0xffffffff) &&
       ((uint)(byte)(&DAT_80071db3)[iVar13] - (uint)(byte)(&DAT_80071db3)[iVar11] == -0x80000000)) {
      trap(0x5d);
    }
    cVar7 = (char)((int)((uint)(byte)(&DAT_80071db3)[iVar13] - (uint)(byte)(&DAT_80071db3)[iVar11])
                  / (int)uVar10);
    if (uVar10 == 0) {
      trap(0x1c00);
    }
    if ((uVar10 == 0xffffffff) &&
       ((uint)(byte)(&DAT_80071dae)[iVar13] - (uint)(byte)(&DAT_80071dae)[iVar11] == -0x80000000)) {
      trap(0x5d);
    }
    cVar8 = (char)((int)((uint)(byte)(&DAT_80071dae)[iVar13] - (uint)(byte)(&DAT_80071dae)[iVar11])
                  / (int)uVar10);
    if (uVar10 == 0) {
      trap(0x1c00);
    }
    if ((uVar10 == 0xffffffff) &&
       ((uint)(byte)(&DAT_80071db4)[iVar13] - (uint)(byte)(&DAT_80071db4)[iVar11] == -0x80000000)) {
      trap(0x5d);
    }
    cVar9 = (char)((int)((uint)(byte)(&DAT_80071db4)[iVar13] - (uint)(byte)(&DAT_80071db4)[iVar11])
                  / (int)uVar10);
    if (uVar12 == uVar10) {
      DAT_80071e20 = DAT_80071e20 + 1;
      *(undefined1 *)(_DAT_800a1d4c + 0x13) = 0;
    }
    else {
      param_1 = param_1 + 0x22b0;
      if (uVar12 < uVar10) {
        iVar11 = 0xd80;
        do {
          if (iVar11 == 0xd80) {
            cVar1 = cVar4;
          }
          else {
            cVar1 = cVar5;
          }
          if (iVar11 == 0xd80) {
            cVar2 = cVar6;
          }
          else {
            cVar2 = cVar7;
          }
          if (iVar11 == 0xd80) {
            cVar3 = cVar8;
          }
          else {
            cVar3 = cVar9;
          }
          FUN_80033388(param_1 + iVar11,(int)cVar1,(int)cVar2,(int)cVar3,1);
          if (iVar11 == 0xd80) {
            cVar1 = cVar4;
          }
          else {
            cVar1 = cVar5;
          }
          if (iVar11 == 0xd80) {
            cVar2 = cVar6;
          }
          else {
            cVar2 = cVar7;
          }
          if (iVar11 == 0xd80) {
            cVar3 = cVar8;
          }
          else {
            cVar3 = cVar9;
          }
          FUN_80033388(param_1 + iVar11,(int)cVar1,(int)cVar2,(int)cVar3,2);
          if (iVar11 == 0xd80) {
            cVar1 = cVar5;
          }
          else {
            cVar1 = cVar4;
          }
          if (iVar11 == 0xd80) {
            cVar2 = cVar7;
          }
          else {
            cVar2 = cVar6;
          }
          if (iVar11 == 0xd80) {
            cVar3 = cVar9;
          }
          else {
            cVar3 = cVar8;
          }
          FUN_80033388(param_1 + iVar11,(int)cVar1,(int)cVar2,(int)cVar3,4);
          if (iVar11 == 0xd80) {
            cVar1 = cVar5;
          }
          else {
            cVar1 = cVar4;
          }
          if (iVar11 == 0xd80) {
            cVar2 = cVar7;
          }
          else {
            cVar2 = cVar6;
          }
          if (iVar11 == 0xd80) {
            cVar3 = cVar9;
          }
          else {
            cVar3 = cVar8;
          }
          FUN_80033388(param_1 + iVar11,(int)cVar1,(int)cVar2,(int)cVar3,8);
          FUN_80033bc8(param_1 + iVar11,0xfffffffe,0,0);
          iVar11 = iVar11 + 0x40;
        } while (iVar11 < 0xe00);
      }
    }
  }
  if (6 < DAT_80071e20) {
    *(undefined1 *)(_DAT_800a1d4c + 0x17) = 1;
  }
  return;
}



// ---- FUN_80055498 @ 80055498

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80055498(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar3 + 1 & 0xfffff;
  if (uVar3 < 0xf) {
    iVar1 = FUN_80058674();
    iVar2 = FUN_80058674();
    FUN_80033560(param_2,(iVar1 % 6 + 0x1d) * 0x10000 >> 0x10,(iVar2 % 6 + 0xd) * 0x10000 >> 0x10,1)
    ;
  }
  else if (uVar3 == 0xf) {
    FUN_80033560(param_2,0x20,0x10,1);
    DAT_80071e24 = 0;
    *(undefined1 *)(_DAT_800a1d4c + 0x12) = 0;
  }
  return;
}



// ---- FUN_800555ac @ 800555ac

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800555ac(int param_1)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  ushort local_18;
  ushort local_16;
  
  cVar1 = FUN_8002bb78();
  if (cVar1 == '\0') {
    iVar3 = FUN_8002b8ac(0,0x9000,1,1,0);
    if (iVar3 == 0) {
      iVar3 = FUN_8002b8ac(0,0x3000,1,1,0);
      if (iVar3 != 0) {
        *_DAT_800a1d4c = 2;
        goto LAB_800558ec;
      }
      iVar3 = FUN_8002b8ac(0,0xc000,1,1,0);
      if (iVar3 != 0) {
        *_DAT_800a1d4c = 6;
        goto LAB_800558ec;
      }
      iVar3 = FUN_8002b8ac(0,0x6000,1,1,0);
      if (iVar3 != 0) {
        *_DAT_800a1d4c = 8;
        goto LAB_800558ec;
      }
      iVar3 = FUN_8002b8ac(0,0x1000,1,1,0);
      if (iVar3 != 0) {
        *_DAT_800a1d4c = 1;
        goto LAB_800558ec;
      }
      iVar3 = FUN_8002b8ac(0,0x4000,1,1,0);
      if (iVar3 != 0) {
        *_DAT_800a1d4c = 7;
        goto LAB_800558ec;
      }
      iVar3 = FUN_8002b8ac(0,0x2000,1,1,0);
      if (iVar3 != 0) {
        *_DAT_800a1d4c = 5;
        goto LAB_800558ec;
      }
      iVar3 = FUN_8002b8ac(0,0x8000,1,1,0);
      if (iVar3 != 0) {
        *_DAT_800a1d4c = 3;
        goto LAB_800558ec;
      }
      goto LAB_800558dc;
    }
  }
  else {
    FUN_8002bb90(1,&local_18);
    uVar2 = 0x20;
    if (((short)local_18 < 0x20) || (uVar2 = 0xe0, 0xe0 < (short)local_18)) {
      local_18 = uVar2;
    }
    uVar2 = 0x10;
    if (((short)local_16 < 0x10) || (uVar2 = 0x90, 0xa0 < (short)local_16)) {
      local_16 = uVar2;
    }
    uVar4 = (uint)local_18;
    if (0x3f < uVar4 - 0x20) {
      if (0x3f < uVar4 - 0x60) {
        if (uVar4 - 0xa0 < 0x41) {
          uVar4 = (uint)local_16;
          if (uVar4 - 0x10 < 0x2b) {
            *_DAT_800a1d4c = 2;
          }
          else if (uVar4 - 0x3b < 0x2b) {
            *_DAT_800a1d4c = 5;
          }
          else if (uVar4 - 0x66 < 0x2b) {
            *_DAT_800a1d4c = 8;
          }
        }
        goto LAB_800558ec;
      }
      uVar4 = (uint)local_16;
      if (uVar4 - 0x10 < 0x2b) {
        *_DAT_800a1d4c = 1;
        goto LAB_800558ec;
      }
      if (0x2a < uVar4 - 0x3b) {
        if (uVar4 - 0x66 < 0x2b) {
          *_DAT_800a1d4c = 7;
        }
        goto LAB_800558ec;
      }
LAB_800558dc:
      *_DAT_800a1d4c = 4;
      goto LAB_800558ec;
    }
    uVar4 = (uint)local_16;
    if (0x2a < uVar4 - 0x10) {
      if (uVar4 - 0x3b < 0x2b) {
        *_DAT_800a1d4c = 3;
      }
      else if (uVar4 - 0x66 < 0x2b) {
        *_DAT_800a1d4c = 6;
      }
      goto LAB_800558ec;
    }
  }
  *_DAT_800a1d4c = 0;
LAB_800558ec:
  _DAT_800a1d4c[1] = (*_DAT_800a1d4c % 3) * '?' + 0x20;
  _DAT_800a1d4c[2] = (*_DAT_800a1d4c / 3) * '*' + 0x10;
  if ((_DAT_800a1d4c[3] != 0) && (_DAT_800a1d4c[0x15] == 0)) {
    cVar1 = FUN_8002bb78();
    if (cVar1 != '\0') {
      FUN_8002bbf0(0);
    }
    FUN_800358f0(param_1 + 0x4c70,1,1,1);
    FUN_8003571c(param_1 + 0x4c70,_DAT_800a1d4c[1],_DAT_800a1d4c[2]);
  }
  if (_DAT_800a1d4c[0x12] == 1) {
    if (_DAT_800a1d4c[3] == 1) {
      FUN_80035ab8(param_1 + 0x4c70,FUN_80055a44);
    }
    else {
      _DAT_800a1d4c[0x12] = 0;
    }
  }
  return;
}



// ---- FUN_80055a44 @ 80055a44

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80055a44(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_2 + 0x18) & 0xfffff;
  *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfff00000 | uVar3 + 1 & 0xfffff;
  iVar1 = FUN_80058674();
  iVar2 = FUN_80058674();
  param_1 = param_1 + 0x4c70;
  FUN_8003571c(param_1,(int)(((uint)*(byte *)(_DAT_800a1d4c + 1) + iVar1 % 0x28 + -0x14) * 0x10000)
                       >> 0x10,
               (int)(((uint)*(byte *)(_DAT_800a1d4c + 2) + iVar2 % 0x28 + -0x14) * 0x10000) >> 0x10)
  ;
  if (uVar3 == 0xf) {
    FUN_8003571c(param_1,0x3f,0x2a);
    *(undefined1 *)(_DAT_800a1d4c + 0x12) = 0;
    FUN_80035ab8(param_1,FUN_800555ac);
  }
  return;
}



// ---- FUN_80055b74 @ 80055b74

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80055b74(int param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  
  if ((_DAT_800a1d4c[3] != 0) && (_DAT_800a1d4c[0x15] == 0)) {
    if (_DAT_800a1d4c[0x16] == 0) {
      uVar3 = FUN_8002ba04(0x24);
      iVar4 = FUN_8002b8ac(0,uVar3,0,3,0);
      iVar5 = param_1 + 0x4ccc;
      if (iVar4 == 0) {
        return;
      }
      pbVar1 = _DAT_800a1d4c + 1;
      pbVar2 = _DAT_800a1d4c + 2;
      *(int *)(_DAT_800a1d4c + 0x1c) = *(int *)(_DAT_800a1d4c + 0x1c) + 1;
      FUN_8003571c(iVar5,*pbVar1 + 0xd,*pbVar2 + 2);
      FUN_800358f0(iVar5,1,1,0);
      FUN_80035458(iVar5,0,0,1);
    }
    else {
      uVar3 = FUN_8002ba04(0x24);
      iVar4 = FUN_8002b8ac(0,uVar3,0,1,0);
      if (iVar4 == 0) {
        FUN_800358f0(param_1 + 0x4ccc,0,0,0);
        return;
      }
      pbVar1 = _DAT_800a1d4c + 1;
      pbVar2 = _DAT_800a1d4c + 2;
      *(int *)(_DAT_800a1d4c + 0x1c) = *(int *)(_DAT_800a1d4c + 0x1c) + 1;
      FUN_8003571c(param_1 + 0x4ccc,*pbVar1 + 0xd,*pbVar2 + 2);
      FUN_800358f0(param_1 + 0x4ccc,1,1,1);
    }
    FUN_80031268(0x500,0x9c5);
    if (*(int *)(param_1 + 0x1de0) == 0xc) {
      FUN_80031268(0x500,0xffffffe8);
    }
    if (*(char *)(_DAT_800a1d50 + (uint)*_DAT_800a1d4c) == '\x01') {
      *(byte *)(_DAT_800a1d50 + 0x14) = *_DAT_800a1d4c;
      _DAT_800a1d4c[0x10] = 1;
    }
  }
  return;
}



// ---- FUN_80055d44 @ 80055d44

void FUN_80055d44(void)

{
  undefined4 uVar1;
  
  if (DAT_8007090c != 1) {
    FUN_8005bb64(0x180,0);
    uVar1 = FUN_8005bbfc(0x10,0x10,0xf0,0xf0,0,0x1e0);
    FUN_8005bb24(uVar1);
    uVar1 = FUN_8005bbfc(0x10,0x10,0xf0,0xf0,0,0x1e0);
    FUN_8005bb24(uVar1);
  }
  return;
}



// ---- FUN_80055dcc @ 80055dcc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80055dcc(void)

{
  int iVar1;
  
  if (DAT_8007090c != 1) {
    iVar1 = FUN_8002b8ac(1,8,0,3,0);
    if (iVar1 != 0) {
      DAT_80071e60 = (uint)(DAT_80071e60 == 0);
    }
    if (DAT_80071e60 != 0) {
      FUN_8005bec4(_DAT_800b05cc);
    }
  }
  return;
}



// ---- FUN_80055e50 @ 80055e50

void FUN_80055e50(void)

{
  bool bVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined1 auStack_118 [92];
  undefined1 auStack_bc [92];
  undefined1 auStack_60 [20];
  undefined1 auStack_4c [20];
  uint local_38;
  undefined1 *local_30;
  
  uVar8 = 0x100;
  iVar9 = 0xf0;
  iVar7 = 0;
  iVar6 = 0;
  local_38 = 0;
  if (DAT_8007090c != 1) {
    iVar2 = FUN_8002b8ac(1,0x80,0,3,0);
    local_30 = auStack_60;
    if (iVar2 != 0) {
      do {
        FUN_8002b4e8();
        iVar2 = FUN_8002b8ac(0,0x8000,1,1,0);
        if (iVar2 != 0) {
          iVar2 = 0;
          if (0xf < iVar7) {
            iVar2 = iVar7 + -0x10;
          }
          iVar7 = iVar2;
        }
        iVar2 = FUN_8002b8ac(0,0x2000,1,1,0);
        if (iVar2 != 0) {
          iVar7 = iVar7 + 0x10;
        }
        iVar2 = FUN_8002b8ac(0,0x1000,1,1,0);
        if (iVar2 != 0) {
          iVar2 = 0;
          if (0xf < iVar6) {
            iVar2 = iVar6 + -0x10;
          }
          iVar6 = iVar2;
        }
        iVar2 = FUN_8002b8ac(0,0x4000,1,1,0);
        if (iVar2 != 0) {
          iVar6 = iVar6 + 0x10;
        }
        iVar2 = FUN_8002b8ac(0,0x20,0,3,0);
        if (iVar2 != 0) {
          uVar8 = 0x100;
        }
        iVar2 = FUN_8002b8ac(0,0x40,0,3,0);
        if (iVar2 != 0) {
          uVar8 = 0x140;
        }
        iVar2 = FUN_8002b8ac(0,0x10,0,3,0);
        if (iVar2 != 0) {
          uVar8 = 0x200;
        }
        iVar2 = FUN_8002b8ac(0,0x80,0,3,0);
        if (iVar2 != 0) {
          uVar8 = 0x280;
        }
        iVar2 = FUN_8002b8ac(0,4,0,3,0);
        if ((iVar2 != 0) && (bVar1 = iVar9 == 0xf0, iVar9 = 0xf0, bVar1)) {
          iVar9 = 0x1e0;
        }
        iVar2 = FUN_8002b8ac(0,1,0,3,0);
        iVar4 = 0;
        if (iVar2 != 0) {
          local_38 = local_38 ^ 1;
        }
        iVar5 = 0;
        iVar2 = FUN_8005daf8();
        puVar3 = local_30;
        do {
          FUN_8005cd24(auStack_118 + iVar4,iVar7,iVar6,uVar8,iVar9);
          FUN_8005cdb0(puVar3,iVar7,iVar6,uVar8,iVar9);
          iVar4 = iVar4 + 0x5c;
          iVar5 = iVar5 + 1;
          puVar3[0x10] = (undefined1)local_38;
          puVar3 = puVar3 + 0x14;
        } while (iVar5 < 2);
        FUN_80059bc8(auStack_118 + iVar2 * 0x5c);
        FUN_80059ce8(local_30 + iVar2 * 0x14);
        FUN_80062390(0);
        iVar2 = FUN_8002b8ac(1,0x80,0,3,0);
      } while (iVar2 == 0);
      FUN_8005cd24(auStack_118,0,0,0x100,0xf0);
      FUN_8005cdb0(local_30,0,0xf0,0x100,0xf0);
      FUN_8005cd24(auStack_bc,0,0xf0,0x100,0xf0);
      FUN_8005cdb0(auStack_4c,0,0,0x100,0xf0);
    }
  }
  return;
}



// ---- FUN_800561a8 @ 800561a8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800561a8(void)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  uVar2 = FUN_8002a9f4(0xffffffff);
  if (DAT_80071e68 == 0) {
    DAT_80071e68 = 1;
    iVar11 = 0;
    iVar10 = -0x7ff5e060;
    iVar9 = -0x7ff5e090;
    iVar12 = 0;
    iVar8 = -0x7ff5e010;
    do {
      iVar6 = 0;
      *(undefined1 *)(iVar8 + 3) = 3;
      *(undefined1 *)(iVar8 + 7) = 0x40;
      *(undefined1 *)(iVar8 + 4) = 0xff;
      *(undefined1 *)(iVar8 + 5) = 0;
      *(undefined1 *)(iVar8 + 6) = 0;
      *(undefined2 *)(iVar8 + 8) = 0xd0;
      *(undefined2 *)(iVar8 + 10) = 0x30;
      *(undefined2 *)(iVar8 + 0xc) = 0xf0;
      *(undefined2 *)(iVar8 + 0xe) = 0x30;
      iVar5 = iVar12;
      do {
        iVar6 = iVar6 + 1;
        *(undefined1 *)(iVar5 + -0x7ff5e08d) = 3;
        *(undefined1 *)(iVar5 + -0x7ff5e089) = 0x40;
        *(undefined1 *)(iVar5 + -0x7ff5e08c) = 0xff;
        *(undefined1 *)(iVar5 + -0x7ff5e08b) = 0xff;
        *(undefined1 *)(iVar5 + -0x7ff5e08a) = 0xff;
        iVar5 = iVar5 + 0x10;
      } while (iVar6 < 4);
      iVar5 = 0;
      iVar6 = iVar11 << 9;
      *(undefined2 *)(iVar9 + 8) = 0xd0;
      *(undefined2 *)(iVar9 + 10) = 0x10;
      *(undefined2 *)(iVar9 + 0xc) = 0xf0;
      *(undefined2 *)(iVar9 + 0xe) = 0x10;
      *(undefined2 *)(iVar12 + -0x7ff5e078) = 0xf0;
      *(undefined2 *)(iVar12 + -0x7ff5e076) = 0x10;
      *(undefined2 *)(iVar12 + -0x7ff5e074) = 0xf0;
      *(undefined2 *)(iVar12 + -0x7ff5e072) = 0x50;
      *(undefined2 *)(iVar12 + -0x7ff5e068) = 0xf0;
      *(undefined2 *)(iVar12 + -0x7ff5e066) = 0x50;
      *(undefined2 *)(iVar12 + -0x7ff5e064) = 0xd0;
      *(undefined2 *)(iVar12 + -0x7ff5e062) = 0x50;
      *(undefined2 *)(iVar10 + 8) = 0xd0;
      *(undefined2 *)(iVar10 + 10) = 0x50;
      *(undefined2 *)(iVar10 + 0xc) = 0xd0;
      *(undefined2 *)(iVar10 + 0xe) = 0x10;
      do {
        sVar4 = 0xef - (short)iVar5;
        iVar5 = iVar5 + 1;
        *(undefined1 *)(iVar6 + -0x7ff5dfed) = 3;
        *(undefined1 *)(iVar6 + -0x7ff5dfe9) = 0x40;
        *(undefined1 *)(iVar6 + -0x7ff5dfec) = 0;
        *(undefined1 *)(iVar6 + -0x7ff5dfeb) = 0xff;
        *(undefined1 *)(iVar6 + -0x7ff5dfea) = 0;
        *(short *)(iVar6 + -0x7ff5dfe8) = sVar4;
        *(undefined2 *)(iVar6 + -0x7ff5dfe6) = 0x50;
        *(short *)(iVar6 + -0x7ff5dfe4) = sVar4;
        *(undefined2 *)(iVar6 + -0x7ff5dfe2) = 0;
        iVar6 = iVar6 + 0x10;
      } while (iVar5 < 0x1f);
      iVar10 = iVar10 + 0x40;
      iVar9 = iVar9 + 0x40;
      iVar12 = iVar12 + 0x40;
      iVar11 = iVar11 + 1;
      iVar8 = iVar8 + 0x10;
    } while (iVar11 < 2);
  }
  uVar3 = FUN_8005d728();
  *(undefined4 *)((uVar2 & 0xff) * 4 + -0x7ff5d2f8) = uVar3;
  iVar8 = 0;
  if (DAT_80071e64 == 1) {
    iVar9 = 0;
    do {
      iVar10 = *(int *)((uVar2 - iVar8 & 0xff) * 4 + -0x7ff5d2f8);
      if (iVar10 < 0x100) {
        sVar4 = 0;
        if (0 < iVar10) {
          sVar4 = (short)(iVar10 >> 3);
        }
        *(undefined1 *)(_DAT_800b05cc * 0x200 + iVar9 + -0x7ff5dfec) = 0;
        *(undefined1 *)(_DAT_800b05cc * 0x200 + iVar9 + -0x7ff5dfeb) = 0xff;
      }
      else if (iVar10 < 0x200) {
        if (iVar10 < 0) {
          iVar10 = iVar10 + 7;
        }
        *(undefined1 *)(_DAT_800b05cc * 0x200 + iVar9 + -0x7ff5dfec) = 0xff;
        *(undefined1 *)(_DAT_800b05cc * 0x200 + iVar9 + -0x7ff5dfeb) = 0xff;
        sVar4 = (short)(iVar10 >> 3);
      }
      else {
        *(undefined1 *)(_DAT_800b05cc * 0x200 + iVar9 + -0x7ff5dfec) = 0xff;
        *(undefined1 *)(_DAT_800b05cc * 0x200 + iVar9 + -0x7ff5dfeb) = 0;
        sVar4 = 0x40;
      }
      *(undefined1 *)(_DAT_800b05cc * 0x200 + iVar9 + -0x7ff5dfea) = 0;
      iVar8 = iVar8 + 1;
      *(short *)(iVar9 + _DAT_800b05cc * 0x200 + -0x7ff5dfe2) = 0x50 - sVar4;
      iVar9 = iVar9 + 0x10;
    } while (iVar8 < 0x1f);
    FUN_80058314();
    puVar1 = _DAT_800aeea0;
    iVar10 = 0;
    iVar11 = -0x7ff5e090;
    puVar7 = (uint *)(_DAT_800b05cc * 0x10 + -0x7ff5e010);
    iVar9 = _DAT_800b05cc * 0x40;
    *puVar7 = *puVar7 & 0xff000000 | *_DAT_800aeea0 & 0xffffff;
    *puVar1 = *puVar1 & 0xff000000 | (uint)puVar7 & 0xffffff;
    iVar8 = iVar9;
    do {
      uVar2 = iVar9 + iVar11;
      iVar11 = iVar11 + 0x10;
      iVar10 = iVar10 + 1;
      *(uint *)(iVar8 + -0x7ff5e090) =
           *(uint *)(iVar8 + -0x7ff5e090) & 0xff000000 | *puVar1 & 0xffffff;
      *puVar1 = *puVar1 & 0xff000000 | uVar2 & 0xffffff;
      puVar7 = _DAT_800aeea0;
      iVar8 = iVar8 + 0x10;
    } while (iVar10 < 4);
    iVar10 = 0;
    iVar9 = -0x7ff5dff0;
    iVar11 = _DAT_800b05cc * 0x200;
    iVar8 = iVar11;
    do {
      uVar2 = iVar11 + iVar9;
      iVar9 = iVar9 + 0x10;
      iVar10 = iVar10 + 1;
      *(uint *)(iVar8 + -0x7ff5dff0) =
           *(uint *)(iVar8 + -0x7ff5dff0) & 0xff000000 | *puVar7 & 0xffffff;
      *puVar7 = *puVar7 & 0xff000000 | uVar2 & 0xffffff;
      iVar8 = iVar8 + 0x10;
    } while (iVar10 < 0x1f);
    FUN_800585a4();
  }
  return;
}



// ---- FUN_80056668 @ 80056668

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80056668(void)

{
  ushort uVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 uVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  ushort local_28 [4];
  
  iVar8 = _DAT_800abf64;
  uVar4 = FUN_8002a9f4(0xffffffff);
  uVar5 = FUN_8003115c();
  if (DAT_80071e6c == 0) {
    DAT_80071e6c = 1;
    iVar10 = 0;
    iVar12 = -0x7ff5dbc0;
    iVar11 = -0x7ff5dbf0;
    iVar13 = 0;
    do {
      iVar9 = 0;
      iVar7 = iVar10 << 5;
      do {
        iVar9 = iVar9 + 1;
        *(undefined1 *)(iVar7 + -0x7ff5db6d) = 3;
        *(undefined1 *)(iVar7 + -0x7ff5db69) = 0x40;
        *(undefined1 *)(iVar7 + -0x7ff5db6c) = 0xff;
        *(undefined1 *)(iVar7 + -0x7ff5db6b) = 0;
        *(undefined1 *)(iVar7 + -0x7ff5db6a) = 0;
        iVar7 = iVar7 + 0x10;
      } while (iVar9 < 2);
      iVar9 = 0;
      iVar7 = iVar13;
      do {
        iVar9 = iVar9 + 1;
        *(undefined1 *)(iVar7 + -0x7ff5dbed) = 3;
        *(undefined1 *)(iVar7 + -0x7ff5dbe9) = 0x40;
        *(undefined1 *)(iVar7 + -0x7ff5dbec) = 0xff;
        *(undefined1 *)(iVar7 + -0x7ff5dbeb) = 0xff;
        *(undefined1 *)(iVar7 + -0x7ff5dbea) = 0xff;
        iVar7 = iVar7 + 0x10;
      } while (iVar9 < 4);
      iVar7 = 0;
      iVar9 = iVar10 << 9;
      *(undefined2 *)(iVar11 + 8) = 0xa8;
      *(undefined2 *)(iVar11 + 10) = 0x10;
      *(undefined2 *)(iVar11 + 0xc) = 200;
      *(undefined2 *)(iVar11 + 0xe) = 0x10;
      *(undefined2 *)(iVar13 + -0x7ff5dbd8) = 200;
      *(undefined2 *)(iVar13 + -0x7ff5dbd6) = 0x10;
      *(undefined2 *)(iVar13 + -0x7ff5dbd4) = 200;
      *(undefined2 *)(iVar13 + -0x7ff5dbd2) = 0x50;
      *(undefined2 *)(iVar13 + -0x7ff5dbc8) = 200;
      *(undefined2 *)(iVar13 + -0x7ff5dbc6) = 0x50;
      *(undefined2 *)(iVar13 + -0x7ff5dbc4) = 0xa8;
      *(undefined2 *)(iVar13 + -0x7ff5dbc2) = 0x50;
      *(undefined2 *)(iVar12 + 8) = 0xa8;
      *(undefined2 *)(iVar12 + 10) = 0x50;
      *(undefined2 *)(iVar12 + 0xc) = 0xa8;
      *(undefined2 *)(iVar12 + 0xe) = 0x10;
      do {
        sVar6 = 199 - (short)iVar7;
        iVar7 = iVar7 + 1;
        *(undefined1 *)(iVar9 + -0x7ff5db2d) = 3;
        *(undefined1 *)(iVar9 + -0x7ff5db29) = 0x40;
        *(undefined1 *)(iVar9 + -0x7ff5db2c) = 0;
        *(undefined1 *)(iVar9 + -0x7ff5db2b) = 0xff;
        *(undefined1 *)(iVar9 + -0x7ff5db2a) = 0;
        *(short *)(iVar9 + -0x7ff5db28) = sVar6;
        *(undefined2 *)(iVar9 + -0x7ff5db26) = 0x50;
        *(short *)(iVar9 + -0x7ff5db24) = sVar6;
        *(undefined2 *)(iVar9 + -0x7ff5db22) = 0;
        iVar9 = iVar9 + 0x10;
      } while (iVar7 < 0x1f);
      iVar12 = iVar12 + 0x40;
      iVar11 = iVar11 + 0x40;
      iVar10 = iVar10 + 1;
      iVar13 = iVar13 + 0x40;
    } while (iVar10 < 2);
  }
  iVar10 = 0;
  local_28[0] = *(ushort *)(iVar8 + 0x53e);
  local_28[1] = *(ushort *)(iVar8 + 0x540);
  iVar8 = 0;
  do {
    iVar11 = iVar10 * 0x10;
    uVar1 = *(ushort *)((int)local_28 + iVar8);
    *(undefined1 *)(_DAT_800b05cc * 0x20 + iVar11 + -0x7ff5db6d) = 3;
    *(undefined1 *)(_DAT_800b05cc * 0x20 + iVar11 + -0x7ff5db69) = 0x40;
    iVar8 = _DAT_800b05cc * 0x20 + iVar11;
    *(byte *)(iVar8 + -0x7ff5db69) = *(byte *)(iVar8 + -0x7ff5db69) & 0xfd;
    *(undefined1 *)(_DAT_800b05cc * 0x20 + iVar11 + -0x7ff5db6c) = 0xff;
    *(undefined1 *)(_DAT_800b05cc * 0x20 + iVar11 + -0x7ff5db6b) = 0;
    *(undefined1 *)(_DAT_800b05cc * 0x20 + iVar11 + -0x7ff5db6a) = 0;
    iVar10 = iVar10 + 1;
    iVar11 = _DAT_800b05cc * 0x20 + iVar11;
    *(undefined2 *)(iVar11 + -0x7ff5db68) = 0xa8;
    *(undefined2 *)(iVar11 + -0x7ff5db64) = 200;
    sVar6 = (short)((int)((0x7f - (uint)uVar1) * 0x40) / 0x7f) + 0x10;
    *(short *)(iVar11 + -0x7ff5db66) = sVar6;
    *(short *)(iVar11 + -0x7ff5db62) = sVar6;
    iVar8 = iVar10 * 2;
  } while (iVar10 < 2);
  *(undefined4 *)((uVar4 & 0xff) * 4 + -0x7ff5d730) = uVar5;
  iVar10 = 0;
  iVar8 = 0;
  do {
    iVar11 = *(int *)((uVar4 - iVar10 & 0xff) * 4 + -0x7ff5d730);
    if (iVar11 < (int)(uint)local_28[0]) {
      iVar12 = (int)((ulonglong)((longlong)(iVar11 << 6) * -0x7efdfbf7) >> 0x20);
      *(undefined1 *)(_DAT_800b05cc * 0x200 + iVar8 + -0x7ff5db2c) = 0;
      *(undefined1 *)(_DAT_800b05cc * 0x200 + iVar8 + -0x7ff5db2b) = 0;
      *(undefined1 *)(_DAT_800b05cc * 0x200 + iVar8 + -0x7ff5db2a) = 0xff;
LAB_80056aa8:
      sVar6 = (short)(iVar12 + iVar11 * 0x40 >> 6) - (short)(iVar11 * 0x40 >> 0x1f);
    }
    else {
      iVar12 = (int)((ulonglong)((longlong)(iVar11 << 6) * -0x7efdfbf7) >> 0x20);
      if (iVar11 < (int)(uint)local_28[1]) {
        *(undefined1 *)(_DAT_800b05cc * 0x200 + iVar8 + -0x7ff5db2c) = 0;
LAB_80056a70:
        *(undefined1 *)(_DAT_800b05cc * 0x200 + iVar8 + -0x7ff5db2b) = 0xff;
        *(undefined1 *)(_DAT_800b05cc * 0x200 + iVar8 + -0x7ff5db2a) = 0;
        goto LAB_80056aa8;
      }
      if (iVar11 < 0x7f) {
        iVar12 = (int)((ulonglong)((longlong)(iVar11 << 6) * -0x7efdfbf7) >> 0x20);
        *(undefined1 *)(_DAT_800b05cc * 0x200 + iVar8 + -0x7ff5db2c) = 0xff;
        goto LAB_80056a70;
      }
      *(undefined1 *)(_DAT_800b05cc * 0x200 + iVar8 + -0x7ff5db2c) = 0xff;
      *(undefined1 *)(_DAT_800b05cc * 0x200 + iVar8 + -0x7ff5db2b) = 0;
      sVar6 = 0x40;
      *(undefined1 *)(_DAT_800b05cc * 0x200 + iVar8 + -0x7ff5db2a) = 0;
    }
    iVar10 = iVar10 + 1;
    *(short *)(iVar8 + _DAT_800b05cc * 0x200 + -0x7ff5db22) = 0x50 - sVar6;
    iVar8 = iVar8 + 0x10;
    if (0x1e < iVar10) {
      if (DAT_80071e64 == 1) {
        FUN_80058314();
        puVar2 = _DAT_800aeea0;
        iVar11 = 0;
        iVar10 = -0x7ff5db70;
        iVar12 = _DAT_800b05cc * 0x20;
        iVar8 = iVar12;
        do {
          uVar4 = iVar12 + iVar10;
          iVar10 = iVar10 + 0x10;
          iVar11 = iVar11 + 1;
          *(uint *)(iVar8 + -0x7ff5db70) =
               *(uint *)(iVar8 + -0x7ff5db70) & 0xff000000 | *puVar2 & 0xffffff;
          *puVar2 = *puVar2 & 0xff000000 | uVar4 & 0xffffff;
          puVar3 = _DAT_800aeea0;
          iVar8 = iVar8 + 0x10;
        } while (iVar11 < 2);
        iVar11 = 0;
        iVar10 = -0x7ff5dbf0;
        iVar12 = _DAT_800b05cc * 0x40;
        iVar8 = iVar12;
        do {
          uVar4 = iVar12 + iVar10;
          iVar10 = iVar10 + 0x10;
          iVar11 = iVar11 + 1;
          *(uint *)(iVar8 + -0x7ff5dbf0) =
               *(uint *)(iVar8 + -0x7ff5dbf0) & 0xff000000 | *puVar3 & 0xffffff;
          *puVar3 = *puVar3 & 0xff000000 | uVar4 & 0xffffff;
          puVar2 = _DAT_800aeea0;
          iVar8 = iVar8 + 0x10;
        } while (iVar11 < 4);
        iVar11 = 0;
        iVar10 = -0x7ff5db30;
        iVar12 = _DAT_800b05cc * 0x200;
        iVar8 = iVar12;
        do {
          uVar4 = iVar12 + iVar10;
          iVar10 = iVar10 + 0x10;
          iVar11 = iVar11 + 1;
          *(uint *)(iVar8 + -0x7ff5db30) =
               *(uint *)(iVar8 + -0x7ff5db30) & 0xff000000 | *puVar2 & 0xffffff;
          *puVar2 = *puVar2 & 0xff000000 | uVar4 & 0xffffff;
          iVar8 = iVar8 + 0x10;
        } while (iVar11 < 0x1f);
        FUN_800585a4();
      }
      return;
    }
  } while( true );
}



// ---- FUN_80056d0c @ 80056d0c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80056d0c(void)

{
  byte bVar1;
  int iVar2;
  uint *puVar3;
  char cVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint *puVar9;
  char *pcVar10;
  uint *puVar11;
  undefined *puVar12;
  undefined *puVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  byte *pbVar17;
  int *piVar18;
  undefined4 *puVar19;
  
  iVar2 = _DAT_800abf64;
  piVar18 = (int *)(_DAT_800abf64 + 0x57c);
  pbVar17 = (byte *)(_DAT_800abf64 + 0x1ac0);
  puVar19 = (undefined4 *)(_DAT_800abf64 + 0x130);
  if (DAT_80071e74 == 0) {
    DAT_80071e74 = 1;
    iVar16 = 0;
    iVar15 = 0;
    iVar14 = -0x7ff5d330;
    do {
      iVar16 = iVar16 + 1;
      *(undefined1 *)(iVar14 + 3) = 3;
      *(undefined1 *)(iVar14 + 7) = 0x60;
      *(undefined2 *)(iVar14 + 8) = 8;
      *(undefined2 *)(iVar14 + 10) = 8;
      *(undefined1 *)(iVar14 + 4) = 0xff;
      *(undefined1 *)(iVar14 + 5) = 0;
      *(undefined1 *)(iVar14 + 6) = 0xff;
      *(undefined2 *)(iVar14 + 0xc) = 0x98;
      *(undefined2 *)(iVar14 + 0xe) = 0x98;
      *(byte *)(iVar14 + 7) = *(byte *)(iVar14 + 7) | 2;
      uVar5 = FUN_8005c510(0,2,0,0);
      FUN_8005a1d8(iVar15 + -0x7ff5d310,0,0,uVar5,0);
      iVar15 = iVar15 + 0xc;
      iVar14 = iVar14 + 0x10;
    } while (iVar16 < 2);
  }
  FUN_80058314();
  iVar14 = FUN_8002b8ac(0,8,0,3,0);
  if (iVar14 != 0) {
    DAT_80071e64 = (uint)(DAT_80071e64 == 0);
  }
  if (DAT_80071e64 != 1) goto LAB_800573dc;
  FUN_8005c12c(_DAT_800b05cc,s_VER___200_800289ac);
  uVar6 = FUN_8002b054(1);
  FUN_8005c12c(_DAT_800b05cc,s_heap____05x_800289b8,uVar6);
  uVar6 = FUN_8005e708(1,0);
  if (*piVar18 == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = *(undefined4 *)(*piVar18 + 4);
  }
  FUN_8005c12c(_DAT_800b05cc,s_Read___3d__02d__02x_800289c8,uVar6,*(undefined4 *)(iVar2 + 0x580),
               uVar7);
  if (*(char *)(iVar2 + 0x588) == '\0') {
    puVar12 = &DAT_800289fc;
    if ((*(uint *)(iVar2 + 0x1ac8) & 0x800) != 0) {
      puVar12 = &DAT_800289f8;
    }
  }
  else {
    puVar12 = &DAT_80028a00;
  }
  FUN_8005c12c(_DAT_800b05cc,s_sect_s___02x__02x__02x_800289e0,puVar12,
               *(undefined1 *)(iVar2 + 0x58c),*(undefined1 *)(iVar2 + 0x58d),
               *(undefined1 *)(iVar2 + 0x58e));
  bVar1 = *(byte *)(iVar2 + 0x584);
  if (bVar1 == 2) {
    pcVar10 = s_Cdl____Complete_80028a04;
  }
  else if (bVar1 < 3) {
    if (bVar1 == 0) {
      pcVar10 = s_Cdl____NoIntr_80028a18;
    }
    else {
LAB_80056fc4:
      pcVar10 = s_Cdl____StatError_80028a3c;
    }
  }
  else {
    if (bVar1 != 5) goto LAB_80056fc4;
    pcVar10 = s_Cdl____DiskError_80028a28;
  }
  FUN_8005c12c(_DAT_800b05cc,pcVar10);
  cVar4 = FUN_8003190c();
  puVar12 = &DAT_800289fc;
  if (cVar4 == '\x04') {
    puVar12 = &DAT_800289f8;
  }
  uVar8 = (uint)*(byte *)(iVar2 + 0x586);
  FUN_8005c12c(_DAT_800b05cc,s_stat_s___02x__02x__02x_80028a50,puVar12,
               *(undefined1 *)(iVar2 + 0x584),*(undefined1 *)(iVar2 + 0x585),uVar8);
  uVar5 = FUN_8002ec84();
  switch(uVar5) {
  case 0:
    pcVar10 = s_phase__OFF_80028a68;
    break;
  case 1:
    pcVar10 = s_phase__SEEK_80028a74;
    break;
  case 2:
    pcVar10 = s_phase__FADE_80028a84;
    break;
  case 3:
    pcVar10 = s_phase__PAUSE_80028a94;
    break;
  case 4:
    pcVar10 = s_phase__PLAY_80028aa4;
    break;
  default:
    goto switchD_8005705c_default;
  }
  FUN_8005c12c(_DAT_800b05cc,pcVar10);
switchD_8005705c_default:
  FUN_8005c12c(_DAT_800b05cc,s_card___02d__02d__02d_80028ab4,(int)*(char *)(iVar2 + 0x15c),
               (int)*(char *)(iVar2 + 0x164),*puVar19,uVar8);
  uVar8 = *(uint *)(iVar2 + 0x1ac4);
  FUN_8005c12c(_DAT_800b05cc,s_time___02d__02d__02d_80028acc,(uVar8 / 0xe10) % 0x3c,
               uVar8 / 0x3c + (uVar8 / 0xe10) * -0x3c,uVar8 % 0x3c);
  FUN_8005c12c(_DAT_800b05cc,s_play___03d__02d_80028ae4,*(uint *)(iVar2 + 0x1ac8) & 0x3ff,
               *(uint *)(iVar2 + 0x1acc) >> 4 & 3);
  FUN_8005c12c(_DAT_800b05cc,&DAT_80028af8);
  puVar12 = &DAT_800289fc;
  if ((*pbVar17 & 0x80) != 0) {
    puVar12 = &DAT_800289f8;
  }
  FUN_8005c12c(_DAT_800b05cc,s_SCN_s___04d__04d_80028afc,puVar12,*(undefined4 *)(iVar2 + 0x1b34),
               *(undefined4 *)(iVar2 + 0x1b30));
  puVar12 = &DAT_800289fc;
  if ((*(uint *)(iVar2 + 0x1ae0) & 4) != 0) {
    puVar12 = &DAT_800289f8;
  }
  FUN_8005c12c(_DAT_800b05cc,s_ACT_s___04d__04d_80028b10,puVar12,*(undefined4 *)(iVar2 + 0x1adc),
               *(undefined4 *)(iVar2 + 0x198c));
  puVar12 = &DAT_800289fc;
  if ((*(uint *)(iVar2 + 0x1b04) & 1) != 0) {
    puVar12 = &DAT_80028a00;
  }
  FUN_8005c12c(_DAT_800b05cc,s_SEQ_s___04d__04d_80028b24,puVar12,*(undefined4 *)(iVar2 + 0x1afc),
               *(undefined4 *)(iVar2 + 0x1b40));
  puVar12 = &DAT_800289fc;
  if (*(short *)(iVar2 + 0x57a) == 6) {
    puVar12 = &DAT_80028a00;
  }
  FUN_8005c12c(_DAT_800b05cc,s_VAG_s___04d__04d_80028b38,puVar12,*(undefined4 *)(iVar2 + 0x1b08),
               *(undefined4 *)(iVar2 + 0x1b10));
  puVar12 = &DAT_800289fc;
  if ((*(uint *)(iVar2 + 0x1af4) & 2) != 0) {
    puVar12 = &DAT_80028a00;
  }
  puVar13 = &DAT_800289fc;
  if ((*(uint *)(iVar2 + 0x1af4) & 0x200) != 0) {
    puVar13 = &DAT_80028a00;
  }
  FUN_8005c12c(_DAT_800b05cc,s_XAS_s_s__04d__04d_80028b4c,puVar12,puVar13,
               *(undefined4 *)(iVar2 + 0x1aec),*(undefined4 *)(iVar2 + 0x1b3c));
  iVar2 = _DAT_800b05cc;
  puVar3 = _DAT_800aeea0;
  puVar11 = (uint *)(_DAT_800b05cc * 0x10 + -0x7ff5d330);
  *puVar11 = *puVar11 & 0xff000000 | *_DAT_800aeea0 & 0xffffff;
  puVar9 = (uint *)(iVar2 * 0xc + 0x800a2cf0);
  *puVar3 = *puVar3 & 0xff000000 | (uint)puVar11 & 0xffffff;
  *puVar9 = *puVar9 & 0xff000000 | (uint)puVar11 & 0xffffff;
  *puVar3 = *puVar3 & 0xff000000 | (uint)puVar9 & 0xffffff;
LAB_800573dc:
  FUN_800585a4();
  return;
}



// ---- FUN_80057418 @ 80057418

void FUN_80057418(void)

{
  return;
}



// ---- FUN_80057420 @ 80057420

undefined4 FUN_80057420(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_800625c0(param_1,0,0);
  uVar2 = FUN_80062600(uVar1,0,2);
  FUN_80062600(uVar1,0,0);
  FUN_8006251c(uVar1,param_2,uVar2);
  FUN_80062624(uVar1);
  return uVar1;
}



// ---- FUN_800574a4 @ 800574a4

undefined4 FUN_800574a4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_800625e0(param_1,1);
  FUN_80062634(uVar1,param_2,param_3);
  FUN_80062624(uVar1);
  return uVar1;
}



// ---- FUN_80057504 @ 80057504

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80057504(undefined4 param_1,undefined4 *param_2)

{
  undefined *puVar1;
  uint uVar2;
  char *pcVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  
  puVar6 = (undefined4 *)param_2[7];
  switch(param_1) {
  case 0:
    FUN_8005c12c(_DAT_800b05cc,s_CLASS__0x_08x_80028b78,param_2);
    puVar4 = &DAT_80028ba4;
    if ((param_2[0x16] & 0x100) != 0) {
      puVar4 = &DAT_80028ba0;
    }
    FUN_8005c12c(_DAT_800b05cc,s_opd___0x_08x___s___80028b88,puVar6,puVar4);
    pcVar3 = s_SOLID_80028bbc;
    if ((param_2[0x16] & 0x20) != 0) {
      pcVar3 = s_LIQUID_80028bb4;
    }
    FUN_8005c12c(_DAT_800b05cc,s_load____s_80028ba8,pcVar3);
    puVar4 = &DAT_80028bd8;
    if ((param_2[0x16] & 0x40) != 0) {
      puVar4 = &DAT_80028bd0;
    }
    FUN_8005c12c(_DAT_800b05cc,s_area____s_80028bc4,puVar4);
    pcVar3 = s__>DEPEND_80028bf8;
    if ((param_2[0x16] & 0x80) != 0) {
      pcVar3 = s_INDEPEND_80028bec;
    }
    FUN_8005c12c(_DAT_800b05cc,s_heap____s_80028be0,pcVar3);
    FUN_8005c12c(_DAT_800b05cc,s_prim____d_80028c04,
                 *(undefined1 *)((int)param_2 + _DAT_800b05cc + 0x54));
    FUN_8005c12c(_DAT_800b05cc,s_pos____d__d_80028c10,(int)*(short *)((int)param_2 + 0x4e),
                 (int)*(short *)((int)param_2 + 0x52));
    puVar4 = &DAT_80028c30;
    if ((param_2[0x16] & 0x40000) != 0) {
      puVar4 = &DAT_80028c2c;
    }
    FUN_8005c12c(_DAT_800b05cc,s_mod____s_80028c20,puVar4);
    FUN_8005c12c(_DAT_800b05cc,s_plt___0x_02x_0x_02x_80028c34,(uint)param_2[0x16] >> 0x13 & 0x1f,
                 (uint)param_2[0x16] >> 0x18 & 0xf);
    FUN_8005c12c(_DAT_800b05cc,s_prio____d_80028c4c,*(undefined1 *)(param_2 + 0x12));
    puVar4 = &DAT_80028ba4;
    uVar2 = param_2[0x16];
    if ((uVar2 & 0x200) != 0) {
      puVar4 = &DAT_80028ba0;
    }
    puVar5 = &DAT_80028ba4;
    if ((uVar2 & 0x1000) != 0) {
      puVar5 = &DAT_80028ba0;
    }
    if ((uVar2 & 0x2000) == 0) {
      puVar1 = &DAT_80028ba4;
    }
    else {
      puVar1 = &DAT_80028ba0;
    }
    FUN_8005c12c(_DAT_800b05cc,s_flg___d__s__a__s__l__s_80028c58,puVar4,puVar5,puVar1);
    FUN_8005c12c(_DAT_800b05cc,s_anime__0x_04x_80028c74,*(undefined1 *)((int)param_2 + 0x56));
    FUN_8005c12c(_DAT_800b05cc,s_frame__0x_04x_80028c84,*(undefined1 *)((int)param_2 + 0x57));
    puVar4 = &DAT_80028ba4;
    if ((param_2[0x16] & 0x10000000) != 0) {
      puVar4 = &DAT_80028ba0;
    }
    FUN_8005c12c(_DAT_800b05cc,s_str____s___d___80028c94,puVar4,(uint)param_2[0x16] >> 0x1d & 3,
                 puVar1);
    FUN_8005c12c(_DAT_800b05cc,s_spd____d__d_80028ca8,((uint)param_2[0x16] >> 0xe & 3) + 1,
                 ((uint)param_2[0x16] >> 0x10 & 3) + 1);
    goto switchD_80057544_default;
  case 1:
    FUN_8005c12c(_DAT_800b05cc,s_CLASS__0x_08x_80028b78,param_2);
    FUN_8005c12c(_DAT_800b05cc,s_opd___0x_08x_80028cb8,puVar6);
    FUN_8005c12c(_DAT_800b05cc,s_adrs___0x_08x_80028cc8,*puVar6);
    FUN_8005c12c(_DAT_800b05cc,s_ofst___0x_08x_80028cd8,puVar6[1]);
    FUN_8005c12c(_DAT_800b05cc,s_size___0x_08x_80028ce8,puVar6[2]);
    FUN_8005c12c(_DAT_800b05cc,s_anmt___0x_08x_80028cf8,puVar6[3]);
    FUN_8005c12c(_DAT_800b05cc,s_ptnt___0x_08x_80028d08,puVar6[4]);
    FUN_8005c12c(_DAT_800b05cc,s_romt___0x_08x_80028d18,puVar6[5]);
    FUN_8005c12c(_DAT_800b05cc,s_pltt___0x_08x_80028d28,puVar6[6]);
    FUN_8005c12c(_DAT_800b05cc,s_anmn___0x_08x_80028d38,puVar6[7]);
    FUN_8005c12c(_DAT_800b05cc,s_ptnn___0x_08x_80028d48,puVar6[8]);
    FUN_8005c12c(_DAT_800b05cc,s_romn___0x_08x_80028d58,puVar6[9]);
    puVar4 = (undefined *)puVar6[10];
    pcVar3 = s_pltn___0x_08x_80028d68;
    break;
  case 2:
    FUN_8005c12c(_DAT_800b05cc,s_CLASS__0x_08x_80028b78,param_2);
    puVar4 = &DAT_80028d90;
    if ((param_2[0x16] & 0xc00) != 0) {
      puVar4 = &DAT_80028d8c;
    }
    FUN_8005c12c(_DAT_800b05cc,s_anm___0x_04x_s_80028d78,*(undefined2 *)(param_2 + 8),puVar4);
    FUN_8005c12c(_DAT_800b05cc,s_frm___0x_04x_80028d94,*(undefined2 *)((int)param_2 + 0x22));
    FUN_8005c12c(_DAT_800b05cc,s_ptn___0x_04x_80028da4,*(undefined2 *)(param_2 + 9));
    FUN_8005c12c(_DAT_800b05cc,s_tim___0x_04x_80028db4,*(undefined2 *)((int)param_2 + 0x26));
    FUN_8005c12c(_DAT_800b05cc,s_cntl___0x_08x_80028dc4,param_2[10]);
    FUN_8005c12c(_DAT_800b05cc,s_cnt1___0x_04x_80028dd4,(int)*(short *)((int)param_2 + 0x2a));
    puVar4 = (undefined *)(int)*(short *)(param_2 + 10);
    pcVar3 = s_cnt0___0x_04x_80028de4;
    break;
  case 3:
    FUN_8005c12c(_DAT_800b05cc,s_CLASS__0x_08x_80028b78,param_2);
    FUN_8005c12c(_DAT_800b05cc,s_func___0x_08x_80028df4,param_2[4]);
    FUN_8005c12c(_DAT_800b05cc,s_list___0x_08x_80028e04,param_2[5]);
    FUN_8005c12c(_DAT_800b05cc,s_step___0x_08x_80028e14,(int)(param_2[6] << 7) >> 0x1b);
    pcVar3 = s_time___0x_08x_80028e24;
    puVar4 = (undefined *)(param_2[6] & 0xfffff);
    break;
  case 4:
    FUN_8005c12c(_DAT_800b05cc,s_CLASS__0x_08x_80028b78,param_2);
    FUN_8005c12c(_DAT_800b05cc,s_Next___0x_08x_80028e34,*param_2);
    FUN_8005c12c(_DAT_800b05cc,s_next___0x_08x_80028e44,param_2[1]);
    FUN_8005c12c(_DAT_800b05cc,s_last___0x_08x_80028e54,param_2[2]);
    FUN_8005c12c(_DAT_800b05cc,s_link___0x_02x_80028e64,param_2[3] & 0xf);
    puVar4 = &DAT_80028ba4;
    if ((param_2[3] & 0x10) != 0) {
      puVar4 = &DAT_80028ba0;
    }
    FUN_8005c12c(_DAT_800b05cc,s_root____s_80028e74,puVar4);
    puVar4 = &DAT_80028ba4;
    if ((param_2[3] & 0x80) != 0) {
      puVar4 = &DAT_80028ba0;
    }
    pcVar3 = s_free____s_80028e80;
    break;
  default:
    goto switchD_80057544_default;
  }
  FUN_8005c12c(_DAT_800b05cc,pcVar3,puVar4);
switchD_80057544_default:
  FUN_8005c12c(_DAT_800b05cc,&DAT_80028e8c);
  return;
}



// ---- FUN_80057c48 @ 80057c48

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80057c48(int param_1,undefined4 *param_2)

{
  char *pcVar1;
  undefined *puVar2;
  
  if (param_1 == 1) {
    FUN_8005c12c(_DAT_800b05cc,s_PRIM___0x_08x_80028ea4,param_2);
    FUN_8005c12c(_DAT_800b05cc,s_func___0x_08x_80028df4,param_2[4]);
    FUN_8005c12c(_DAT_800b05cc,s_list___0x_08x_80028e04,param_2[5]);
    FUN_8005c12c(_DAT_800b05cc,s_step___0x_08x_80028e14,(int)(param_2[6] << 7) >> 0x1b);
    pcVar1 = s_time___0x_08x_80028e24;
    puVar2 = (undefined *)(param_2[6] & 0xfffff);
  }
  else if (param_1 < 2) {
    if (param_1 != 0) goto LAB_800580f8;
    FUN_8005c12c(_DAT_800b05cc,s_PRIM___0x_08x_80028ea4,param_2);
    FUN_8005c12c(_DAT_800b05cc,s_prim___0x_08x_80028eb4,param_2[7]);
    FUN_8005c12c(_DAT_800b05cc,s_dmode__0x_08x_80028ec4,param_2[8]);
    FUN_8005c12c(_DAT_800b05cc,s_darea__0x_08x_80028ed4,param_2[9]);
    FUN_8005c12c(_DAT_800b05cc,s_dtwin__0x_08x_80028ee4,param_2[10]);
    FUN_8005c12c(_DAT_800b05cc,s_dofst__0x_08x_80028ef4,param_2[0xb]);
    puVar2 = &DAT_80028ba4;
    if ((param_2[0xf] & 1) != 0) {
      puVar2 = &DAT_80028ba0;
    }
    FUN_8005c12c(_DAT_800b05cc,s_work____s_80028f04,puVar2);
    puVar2 = &DAT_80028ba4;
    if ((param_2[0xf] & 8) != 0) {
      puVar2 = &DAT_80028ba0;
    }
    FUN_8005c12c(_DAT_800b05cc,s_stop____s_80028f10,puVar2);
    FUN_8005c12c(_DAT_800b05cc,s_cntl___0x_02x_80028f1c,(uint)param_2[0xf] >> 1 & 3);
    FUN_8005c12c(_DAT_800b05cc,s_pcode__0x_02x_80028f2c,(uint)param_2[0xf] >> 4 & 0x1f);
    FUN_8005c12c(_DAT_800b05cc,s_dcode__0x_02x_80028f3c,(uint)param_2[0xf] >> 9 & 0xf);
    FUN_8005c12c(_DAT_800b05cc,s_prio___0x_02x_80028f4c,(uint)param_2[0xf] >> 0xd & 0xf);
    FUN_8005c12c(_DAT_800b05cc,s_tpage__0x_02x_80028f5c,(uint)param_2[0xf] >> 0x11 & 0x7f);
    puVar2 = &DAT_80028ba4;
    if ((param_2[0xf] & 0x1000000) != 0) {
      puVar2 = &DAT_80028ba0;
    }
    FUN_8005c12c(_DAT_800b05cc,s_disp____s_80028f6c,puVar2);
    puVar2 = &DAT_80028ba4;
    if ((param_2[0xf] & 0x2000000) != 0) {
      puVar2 = &DAT_80028ba0;
    }
    FUN_8005c12c(_DAT_800b05cc,s_str____s___d___80028c94,puVar2,(uint)param_2[0xf] >> 0x1a & 3);
    puVar2 = &DAT_80028c30;
    if ((param_2[0xf] & 0x30000000) == 0x10000000) {
      puVar2 = &DAT_80028c2c;
    }
    FUN_8005c12c(_DAT_800b05cc,s_mode____s_80028f78,puVar2);
    puVar2 = &DAT_80028ba4;
    if ((param_2[0xf] & 0x40000000) != 0) {
      puVar2 = &DAT_80028ba0;
    }
    FUN_8005c12c(_DAT_800b05cc,s_dtd____s_80028f84,puVar2);
    puVar2 = &DAT_80028ba4;
    if ((int)param_2[0xf] < 0) {
      puVar2 = &DAT_80028ba0;
    }
    pcVar1 = s_dfe____s_80028f90;
  }
  else {
    if (param_1 != 2) goto LAB_800580f8;
    FUN_8005c12c(_DAT_800b05cc,s_PRIM___0x_08x_80028ea4,param_2);
    FUN_8005c12c(_DAT_800b05cc,s_Next___0x_08x_80028e34,*param_2);
    FUN_8005c12c(_DAT_800b05cc,s_next___0x_08x_80028e44,param_2[1]);
    FUN_8005c12c(_DAT_800b05cc,s_last___0x_08x_80028e54,param_2[2]);
    FUN_8005c12c(_DAT_800b05cc,s_link___0x_02x_80028e64,param_2[3] & 0xf);
    puVar2 = &DAT_80028ba4;
    if ((param_2[3] & 0x10) != 0) {
      puVar2 = &DAT_80028ba0;
    }
    FUN_8005c12c(_DAT_800b05cc,s_root____s_80028e74,puVar2);
    puVar2 = &DAT_80028ba4;
    if ((param_2[3] & 0x80) != 0) {
      puVar2 = &DAT_80028ba0;
    }
    pcVar1 = s_free____s_80028e80;
  }
  FUN_8005c12c(_DAT_800b05cc,pcVar1,puVar2);
LAB_800580f8:
  FUN_8005c12c(_DAT_800b05cc,&DAT_80028e8c);
  return;
}



// ---- FUN_80058124 @ 80058124

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80058124(int param_1,undefined4 *param_2)

{
  char *pcVar1;
  undefined *puVar2;
  
  if (param_1 == 0) {
    FUN_8005c12c(_DAT_800b05cc,s_FUNC___0x_08x_80028f9c,param_2);
    FUN_8005c12c(_DAT_800b05cc,s_func___0x_08x_80028df4,param_2[4]);
    FUN_8005c12c(_DAT_800b05cc,s_list___0x_08x_80028e04,param_2[5]);
    FUN_8005c12c(_DAT_800b05cc,s_step___0x_08x_80028e14,(int)(param_2[6] << 7) >> 0x1b);
    pcVar1 = s_time___0x_08x_80028e24;
    puVar2 = (undefined *)(param_2[6] & 0xfffff);
  }
  else {
    if (param_1 != 1) goto LAB_800582d8;
    FUN_8005c12c(_DAT_800b05cc,s_FUNC___0x_08x_80028f9c,param_2);
    FUN_8005c12c(_DAT_800b05cc,s_Next___0x_08x_80028e34,*param_2);
    FUN_8005c12c(_DAT_800b05cc,s_next___0x_08x_80028e44,param_2[1]);
    FUN_8005c12c(_DAT_800b05cc,s_last___0x_08x_80028e54,param_2[2]);
    FUN_8005c12c(_DAT_800b05cc,s_link___0x_02x_80028e64,param_2[3] & 0xf);
    puVar2 = &DAT_80028ba4;
    if ((param_2[3] & 0x10) != 0) {
      puVar2 = &DAT_80028ba0;
    }
    FUN_8005c12c(_DAT_800b05cc,s_root____s_80028e74,puVar2);
    puVar2 = &DAT_80028ba4;
    if ((param_2[3] & 0x80) != 0) {
      puVar2 = &DAT_80028ba0;
    }
    pcVar1 = s_free____s_80028e80;
  }
  FUN_8005c12c(_DAT_800b05cc,pcVar1,puVar2);
LAB_800582d8:
  FUN_8005c12c(_DAT_800b05cc,&DAT_80028e8c);
  return;
}



// ---- FUN_80058304 @ 80058304

void FUN_80058304(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_80058314 @ 80058314

void FUN_80058314(void)

{
  syscall(0);
  return;
}



// ---- FUN_80058324 @ 80058324

void FUN_80058324(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_80058334 @ 80058334

void FUN_80058334(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_80058344 @ 80058344

void FUN_80058344(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_80058354 @ 80058354

void FUN_80058354(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_80058364 @ 80058364

void FUN_80058364(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_80058374 @ 80058374

void FUN_80058374(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_80058384 @ 80058384

void FUN_80058384(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_80058394 @ 80058394

void FUN_80058394(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_800583a4 @ 800583a4

undefined4 FUN_800583a4(uint param_1,undefined2 param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  ushort uVar3;
  
  param_1 = param_1 & 0xffff;
  uVar3 = 0x48;
  if (param_1 < 3) {
    iVar2 = param_1 * 0x10 + DAT_8008c06c;
    *(undefined2 *)(iVar2 + 4) = 0;
    *(undefined2 *)(iVar2 + 8) = param_2;
    if (param_1 < 2) {
      if ((param_3 & 0x10) != 0) {
        uVar3 = 0x49;
      }
      if ((param_3 & 1) == 0) {
        uVar3 = uVar3 | 0x100;
      }
    }
    else if ((param_1 == 2) && ((param_3 & 1) == 0)) {
      uVar3 = 0x248;
    }
    if ((param_3 & 0x1000) != 0) {
      uVar3 = uVar3 | 0x10;
    }
    uVar1 = 1;
    *(ushort *)(param_1 * 0x10 + DAT_8008c06c + 4) = uVar3;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



// ---- FUN_80058440 @ 80058440

undefined2 FUN_80058440(uint param_1)

{
  undefined2 uVar1;
  
  if ((param_1 & 0xffff) < 3) {
    uVar1 = *(undefined2 *)((param_1 & 0xffff) * 0x10 + DAT_8008c06c);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



// ---- FUN_80058478 @ 80058478

bool FUN_80058478(uint param_1)

{
  *(uint *)(DAT_8008c068 + 4) =
       *(uint *)(DAT_8008c068 + 4) | *(uint *)(&DAT_8008c070 + (param_1 & 0xffff) * 4);
  return (param_1 & 0xffff) < 3;
}



// ---- FUN_800584ac @ 800584ac

undefined4 FUN_800584ac(uint param_1)

{
  *(uint *)(DAT_8008c068 + 4) =
       ~*(uint *)(&DAT_8008c070 + (param_1 & 0xffff) * 4) & *(uint *)(DAT_8008c068 + 4);
  return 1;
}



// ---- FUN_800584e0 @ 800584e0

bool FUN_800584e0(uint param_1)

{
  param_1 = param_1 & 0xffff;
  if (param_1 < 3) {
    *(undefined2 *)(param_1 * 0x10 + DAT_8008c06c) = 0;
  }
  return param_1 < 3;
}



// ---- FUN_80058514 @ 80058514

void FUN_80058514(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_80058524 @ 80058524

void FUN_80058524(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_80058534 @ 80058534

void FUN_80058534(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_80058544 @ 80058544

void FUN_80058544(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_80058564 @ 80058564

void FUN_80058564(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_80058574 @ 80058574

void FUN_80058574(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_80058584 @ 80058584

void FUN_80058584(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_80058594 @ 80058594

void FUN_80058594(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_800585a4 @ 800585a4

void FUN_800585a4(void)

{
  syscall(0);
  return;
}



// ---- FUN_800585b4 @ 800585b4

void FUN_800585b4(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_800585c4 @ 800585c4

void FUN_800585c4(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_800585d4 @ 800585d4

void FUN_800585d4(void)

{
  (*(code *)&LAB_000000a0)();
  return;
}



// ---- FUN_800585e4 @ 800585e4

void FUN_800585e4(void)

{
  (*(code *)&LAB_000000a0)();
  return;
}



// ---- FUN_800585f4 @ 800585f4

void FUN_800585f4(void)

{
  (*(code *)&LAB_000000a0)();
  return;
}



// ---- FUN_80058604 @ 80058604

void FUN_80058604(void)

{
  (*(code *)&LAB_000000a0)();
  return;
}



// ---- FUN_80058614 @ 80058614

void FUN_80058614(void)

{
  (*(code *)&LAB_000000a0)();
  return;
}



// ---- FUN_80058624 @ 80058624

void FUN_80058624(void)

{
  (*(code *)&LAB_000000a0)();
  return;
}



// ---- FUN_80058634 @ 80058634

void FUN_80058634(void)

{
  (*(code *)&LAB_000000a0)();
  return;
}



// ---- FUN_80058644 @ 80058644

void FUN_80058644(void)

{
  (*(code *)&LAB_000000a0)();
  return;
}



// ---- FUN_80058654 @ 80058654

void FUN_80058654(void)

{
  (*(code *)&LAB_000000a0)();
  return;
}



// ---- FUN_80058664 @ 80058664

void FUN_80058664(void)

{
  (*(code *)&LAB_000000a0)();
  return;
}



// ---- FUN_80058674 @ 80058674

void FUN_80058674(void)

{
  (*(code *)&LAB_000000a0)();
  return;
}



// ---- FUN_80058684 @ 80058684

void FUN_80058684(void)

{
  (*(code *)&LAB_000000a0)();
  return;
}



// ---- FUN_80058694 @ 80058694

void FUN_80058694(void)

{
  (*(code *)&LAB_000000a0)();
  return;
}



// ---- FUN_800586a4 @ 800586a4

void FUN_800586a4(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_800586b4 @ 800586b4

void FUN_800586b4(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_800586c4 @ 800586c4

void FUN_800586c4(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_800586d4 @ 800586d4

void FUN_800586d4(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_800586e4 @ 800586e4

void FUN_800586e4(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_800586f4 @ 800586f4

void FUN_800586f4(void)

{
  (*(code *)&LAB_000000a0)();
  return;
}



// ---- FUN_80058704 @ 80058704

void FUN_80058704(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_80058714 @ 80058714

void FUN_80058714(int param_1)

{
  if (param_1 == 0) {
    FUN_80061c44();
  }
  FUN_80058874(param_1);
  return;
}



// ---- FUN_80058758 @ 80058758

void FUN_80058758(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_80058d14();
  if (iVar1 == 0) {
    FUN_80058f64(param_1,param_2);
  }
  return;
}



// ---- FUN_80058798 @ 80058798

void FUN_80058798(uint *param_1,uint param_2)

{
  uint uVar1;
  
  if ((param_2 & 1) == 0) {
    uVar1 = *param_1 | 0x8000000;
  }
  else {
    uVar1 = *param_1 & 0xf7ffffff;
  }
  *param_1 = uVar1;
  if ((param_2 & 2) == 0) {
    uVar1 = *param_1 & 0xfdffffff;
  }
  else {
    uVar1 = *param_1 | 0x2000000;
  }
  *param_1 = uVar1;
  FUN_80058980(param_1,(short)*param_1);
  return;
}



// ---- FUN_80058814 @ 80058814

void FUN_80058814(void)

{
  FUN_80058a1c();
  return;
}



// ---- FUN_80058834 @ 80058834

void FUN_80058834(void)

{
  FUN_80058ab0();
  return;
}



// ---- FUN_80058854 @ 80058854

void FUN_80058854(void)

{
  FUN_80058b48();
  return;
}



// ---- FUN_80058874 @ 80058874

void FUN_80058874(int param_1)

{
  if (param_1 == 0) {
    *DAT_8009fddc = 0x80000000;
    *DAT_8009fdb0 = 0;
    *DAT_8009fdbc = 0;
    *DAT_8009fddc = 0x60000000;
    FUN_80058980(&DAT_8008c088,0x20);
    FUN_80058980(&DAT_8008c10c,0x20);
  }
  else if (param_1 == 1) {
    *DAT_8009fddc = 0x80000000;
    *DAT_8009fdb0 = 0;
    *DAT_8009fdbc = 0;
    *DAT_8009fddc = 0x60000000;
  }
  else {
    FUN_80058614(s_MDEC_rest_bad_option__d__80028fac);
    FUN_80058d04();
  }
  return;
}



// ---- FUN_80058980 @ 80058980

void FUN_80058980(undefined4 *param_1,uint param_2)

{
  FUN_80058ab0();
  *DAT_8009fde0 = *DAT_8009fde0 | 0x88;
  *DAT_8009fda8 = (int)(param_1 + 1);
  *DAT_8009fdac = (param_2 >> 5) << 0x10 | 0x20;
  *DAT_8009fdd8 = *param_1;
  *DAT_8009fdb0 = 0x1000201;
  return;
}



// ---- FUN_80058a1c @ 80058a1c

void FUN_80058a1c(undefined4 param_1,uint param_2)

{
  FUN_80058b48();
  *DAT_8009fde0 = *DAT_8009fde0 | 0x88;
  *DAT_8009fdbc = 0;
  *DAT_8009fdb4 = param_1;
  *DAT_8009fdb8 = (param_2 >> 5) << 0x10 | 0x20;
  *DAT_8009fdbc = 0x1000200;
  return;
}



// ---- FUN_80058ab0 @ 80058ab0

undefined4 FUN_80058ab0(void)

{
  uint uVar1;
  int local_10;
  
  local_10 = 0x100000;
  uVar1 = *DAT_8009fdb0;
  while( true ) {
    if ((uVar1 & 0x1000000) == 0) {
      return 0;
    }
    local_10 = local_10 + -1;
    if (local_10 == -1) break;
    uVar1 = *DAT_8009fdb0;
  }
  FUN_80058cc8(s_MDEC_in_sync_80028fc8);
  return 0xffffffff;
}



// ---- FUN_80058b48 @ 80058b48

undefined4 FUN_80058b48(void)

{
  uint uVar1;
  int local_10;
  
  local_10 = 0x100000;
  uVar1 = *DAT_8009fdbc;
  while( true ) {
    if ((uVar1 & 0x1000000) == 0) {
      return 0;
    }
    local_10 = local_10 + -1;
    if (local_10 == -1) break;
    uVar1 = *DAT_8009fdbc;
  }
  FUN_80058cc8(s_MDEC_out_sync_80028fd8);
  return 0xffffffff;
}



// ---- FUN_80058bf8 @ 80058bf8

undefined4 FUN_80058bf8(void)

{
  uint uVar1;
  
  uVar1 = *DAT_8009fddc;
  FUN_80058614(s_DMA___d__d___ADDR__0x_08x_>0x_08_80028fe8,*DAT_8009fdb0 >> 0x18 & 1,
               *DAT_8009fdbc >> 0x18 & 1,*DAT_8009fda8,*DAT_8009fdb4);
  FUN_80058614(s_FIFO___d__d__BUSY__d_DREQ___d__d_80029010,~uVar1 >> 0x1f,uVar1 >> 0x1e & 1,
               uVar1 >> 0x1d & 1,uVar1 >> 0x1c & 1,uVar1 >> 0x1b & 1,uVar1 >> 0x19 & 1,
               uVar1 >> 0x17 & 1);
  return 0;
}



// ---- FUN_80058cc8 @ 80058cc8

undefined4 FUN_80058cc8(undefined4 param_1)

{
  FUN_80058614(s__s_timeout__80029048,param_1);
  FUN_80058bf8();
  FUN_80058874(1);
  return 0;
}



// ---- FUN_80058d04 @ 80058d04

void FUN_80058d04(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_80058d14 @ 80058d14

/* WARNING: Removing unreachable block (ram,0x80058d94) */

int FUN_80058d14(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  uint uVar8;
  ushort *puVar9;
  ushort *puVar10;
  
  uVar1 = *param_1;
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  uVar2 = param_1[2];
  puVar7 = param_2 + 2;
  if ((param_1[3] != 1) && (param_1[3] != 2)) {
    return 0;
  }
  puVar10 = param_1 + 6;
  uVar8 = 10;
  param_2 = param_2 + 3;
  uVar4 = (uint)(param_1[4] >> 6);
  uVar6 = CONCAT22(param_1[4],param_1[5]) << 10;
LAB_80058d8c:
  uVar4 = (uint)uVar2 << 10 | uVar4;
LAB_80058d9c:
  *puVar7 = (ushort)uVar4;
LAB_80058da0:
  uVar4 = uVar6 >> 0x13;
LAB_80058da4:
  puVar7 = param_2;
  puVar9 = (ushort *)(&DAT_8008d190 + uVar4 * 8);
  if (*(short *)(&DAT_8008d192 + uVar4 * 8) == 0) {
    puVar9 = (ushort *)(&DAT_8009d190 + (uVar6 >> 0xf) * 8);
    uVar8 = uVar8 + 8;
    uVar6 = uVar6 << 8;
    if ((uVar8 & 0x10) != 0) {
      uVar3 = *puVar10;
      uVar8 = uVar8 & 0xf;
      puVar10 = puVar10 + 1;
      uVar6 = uVar6 | (uint)uVar3 << uVar8;
    }
  }
  uVar6 = uVar6 << (*puVar9 & 0x1f);
  uVar8 = uVar8 + *puVar9;
  if ((uVar8 & 0x10) != 0) {
    uVar3 = *puVar10;
    uVar8 = uVar8 & 0xf;
    puVar10 = puVar10 + 1;
    uVar6 = uVar6 | (uint)uVar3 << uVar8;
  }
  uVar3 = puVar9[1];
  *puVar7 = uVar3;
  param_2 = puVar7;
  if (uVar3 == 0x7c1f) goto LAB_80058f1c;
  if (uVar3 != 0xfe00) {
    uVar3 = puVar9[2];
    param_2 = puVar7 + 1;
    *param_2 = uVar3;
    if (uVar3 == 0x7c1f) goto LAB_80058f1c;
    if (uVar3 < 0x7c20) goto code_r0x80058eb8;
    if (uVar3 != 0xfe00) goto LAB_80058ed4;
  }
  goto LAB_80058e4c;
code_r0x80058eb8:
  uVar4 = uVar6 >> 0x13;
  if (uVar3 == 0) goto LAB_80058da4;
LAB_80058ed4:
  uVar3 = puVar9[3];
  param_2 = puVar7 + 2;
  *param_2 = uVar3;
  if (uVar3 == 0x7c1f) {
LAB_80058f1c:
    *param_2 = (ushort)(uVar6 >> 0x10);
    uVar3 = *puVar10;
    puVar10 = puVar10 + 1;
    param_2 = param_2 + 1;
    uVar6 = uVar6 << 0x10 | (uint)uVar3 << (uVar8 & 0x1f);
    goto LAB_80058da0;
  }
  if (uVar3 < 0x7c20) {
    uVar4 = uVar6 >> 0x13;
    if (uVar3 != 0) {
      param_2 = puVar7 + 3;
    }
    goto LAB_80058da4;
  }
  if (uVar3 == 0xfe00) goto LAB_80058e4c;
  param_2 = puVar7 + 3;
  goto LAB_80058da0;
LAB_80058e4c:
  uVar4 = uVar6 >> 0x16;
  puVar7 = param_2 + 1;
  if (uVar4 == 0x1ff) {
    iVar5 = 0x3f;
    do {
      *puVar7 = 0xfe00;
      iVar5 = iVar5 + -1;
      puVar7 = puVar7 + 1;
    } while (-1 < iVar5);
    return uVar1 + 1;
  }
  uVar8 = uVar8 + 10;
  uVar6 = uVar6 << 10;
  if ((uVar8 & 0x10) != 0) {
    uVar3 = *puVar10;
    uVar8 = uVar8 & 0xf;
    puVar10 = puVar10 + 1;
    uVar6 = uVar6 | (uint)uVar3 << uVar8;
  }
  param_2 = param_2 + 2;
  if (-1 < (int)uVar4) goto LAB_80058d8c;
  uVar4 = (uint)uVar2 << 10 | uVar4 + 0x400;
  goto LAB_80058d9c;
}



// ---- FUN_80058f64 @ 80058f64

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80058f64(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  ushort *puVar6;
  ushort *puVar7;
  
  _DAT_800b03d4 = 0;
  _DAT_800ab2b8 = 0;
  _DAT_800b05d8 = 0;
  _DAT_800abfbc = 0;
  uVar1 = *param_1;
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  uVar2 = param_1[2];
  puVar6 = param_2 + 2;
  if (param_1[3] != 3) {
    FUN_80058614(s_MDEC_vlec__invalid_VLC_ID_80029058);
    return 0;
  }
  _DAT_800addb0 = 0;
  _DAT_800ab5d0 = param_1 + 6;
  _DAT_800abfdc = CONCAT22(param_1[4],param_1[5]);
  uVar4 = FUN_8005934c();
  param_2 = param_2 + 3;
  if ((int)uVar4 < 0) goto LAB_80059048;
LAB_8005903c:
  uVar4 = (uint)uVar2 << 10 | uVar4;
  do {
    *puVar6 = (ushort)uVar4;
LAB_80059050:
    puVar7 = param_2;
    iVar5 = (_DAT_800abfdc >> 0x13) * 8;
    puVar6 = (ushort *)(&DAT_8008d190 + iVar5);
    if (*(short *)(&DAT_8008d192 + iVar5) == 0) {
      puVar6 = (ushort *)(&DAT_8009d190 + (_DAT_800abfdc >> 0xf) * 8);
      _DAT_800abfdc = _DAT_800abfdc << 8;
      _DAT_800addb0 = _DAT_800addb0 + 8;
      if ((_DAT_800addb0 & 0x10) != 0) {
        _DAT_800addb0 = _DAT_800addb0 & 0xf;
        _DAT_800abfdc = (uint)*_DAT_800ab5d0 << _DAT_800addb0 | _DAT_800abfdc;
        _DAT_800ab5d0 = _DAT_800ab5d0 + 1;
      }
      _DAT_800abfdc = _DAT_800abfdc << (*puVar6 & 0x1f);
      _DAT_800addb0 = *puVar6 + _DAT_800addb0;
      if ((_DAT_800addb0 & 0x10) != 0) {
        _DAT_800addb0 = _DAT_800addb0 & 0xf;
        _DAT_800abfdc = (uint)*_DAT_800ab5d0 << _DAT_800addb0 | _DAT_800abfdc;
        goto LAB_800591c4;
      }
    }
    else {
      _DAT_800abfdc = _DAT_800abfdc << (*puVar6 & 0x1f);
      _DAT_800addb0 = *puVar6 + _DAT_800addb0;
      if ((_DAT_800addb0 & 0x10) != 0) {
        _DAT_800addb0 = _DAT_800addb0 & 0xf;
        _DAT_800abfdc = (uint)*_DAT_800ab5d0 << _DAT_800addb0 | _DAT_800abfdc;
LAB_800591c4:
        _DAT_800ab5d0 = _DAT_800ab5d0 + 1;
      }
    }
    uVar3 = puVar6[1];
    *puVar7 = uVar3;
    param_2 = puVar7;
    if (uVar3 == 0x7c1f) goto LAB_800592b8;
    if (uVar3 != 0xfe00) {
      uVar3 = puVar6[2];
      param_2 = puVar7 + 1;
      *param_2 = uVar3;
      if (uVar3 == 0x7c1f) goto LAB_800592b8;
      if (uVar3 < 0x7c20) break;
      if (uVar3 != 0xfe00) goto LAB_80059270;
    }
LAB_800591f0:
    puVar6 = param_2 + 1;
    if (_DAT_800abfdc >> 0x16 == 0x3ff) {
      iVar5 = 0x3f;
      do {
        *puVar6 = 0xfe00;
        iVar5 = iVar5 + -1;
        puVar6 = puVar6 + 1;
      } while (-1 < iVar5);
      return uVar1 + 1;
    }
    uVar4 = FUN_8005934c();
    param_2 = param_2 + 2;
    if (-1 < (int)uVar4) goto LAB_8005903c;
LAB_80059048:
    uVar4 = (uint)uVar2 << 10 | uVar4 + 0x400;
  } while( true );
  if (uVar3 != 0) {
LAB_80059270:
    uVar3 = puVar6[3];
    param_2 = puVar7 + 2;
    *param_2 = uVar3;
    if (uVar3 == 0x7c1f) {
LAB_800592b8:
      *param_2 = _DAT_800abfde;
      _DAT_800abfdc = (uint)*_DAT_800ab5d0 << (_DAT_800addb0 & 0x1f) | _DAT_800abfdc << 0x10;
      param_2 = param_2 + 1;
      _DAT_800ab5d0 = _DAT_800ab5d0 + 1;
    }
    else if (uVar3 < 0x7c20) {
      if (uVar3 != 0) {
        param_2 = puVar7 + 3;
      }
    }
    else {
      if (uVar3 == 0xfe00) goto LAB_800591f0;
      param_2 = puVar7 + 3;
    }
  }
  goto LAB_80059050;
}



// ---- FUN_8005934c @ 8005934c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8005934c(void)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  ushort *puVar5;
  
  uVar4 = 0;
  if (_DAT_800abfbc < 2) {
    puVar1 = &DAT_8008c990;
  }
  else {
    puVar1 = &DAT_8008c190;
  }
  puVar5 = (ushort *)(puVar1 + (_DAT_800abfdc >> 0x18) * 8);
  _DAT_800abfdc = _DAT_800abfdc << (*puVar5 & 0x1f);
  _DAT_800addb0 = *puVar5 + _DAT_800addb0;
  if ((_DAT_800addb0 & 0x10) != 0) {
    _DAT_800addb0 = _DAT_800addb0 & 0xf;
    _DAT_800abfdc = (uint)*_DAT_800ab5d0 << _DAT_800addb0 | _DAT_800abfdc;
    _DAT_800ab5d0 = _DAT_800ab5d0 + 1;
  }
  uVar2 = (uint)puVar5[1];
  if (uVar2 != 0) {
    uVar4 = _DAT_800abfdc >> (0x20 - uVar2 & 0x1f);
    iVar3 = 1 << (uVar2 - 1 & 0x1f);
    if ((int)uVar4 < iVar3) {
      uVar4 = uVar4 + 1 + iVar3 * -2;
    }
    _DAT_800abfdc = _DAT_800abfdc << (uVar2 & 0x1f);
    _DAT_800addb0 = uVar2 + _DAT_800addb0;
    if ((_DAT_800addb0 & 0x10) != 0) {
      _DAT_800addb0 = _DAT_800addb0 & 0xf;
      _DAT_800abfdc = (uint)*_DAT_800ab5d0 << _DAT_800addb0 | _DAT_800abfdc;
      _DAT_800ab5d0 = _DAT_800ab5d0 + 1;
    }
  }
  if (_DAT_800abfbc == 0) {
    iVar3 = uVar4 + _DAT_800ab2b8;
    _DAT_800ab2b8 = iVar3;
  }
  else if (_DAT_800abfbc == 1) {
    iVar3 = uVar4 + _DAT_800b05d8;
    _DAT_800b05d8 = iVar3;
  }
  else {
    iVar3 = uVar4 + _DAT_800b03d4;
    _DAT_800b03d4 = iVar3;
  }
  _DAT_800abfbc = _DAT_800abfbc + 1;
  if (_DAT_800abfbc == 6) {
    _DAT_800abfbc = 0;
  }
  return iVar3 << 2;
}



// ---- FUN_8005955c @ 8005955c

void FUN_8005955c(uint param_1)

{
  FUN_8005bb14(param_1 & 0xffffff);
  return;
}



// ---- FUN_80059584 @ 80059584

/* WARNING: Removing unreachable block (ram,0x800595b4) */

undefined4 FUN_80059584(uint param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = param_1 & 3;
  if (uVar2 < 3) {
    if (uVar2 == 0) {
      FUN_80061c44();
      FUN_80061ca4(2,*(undefined4 *)(PTR_PTR_8009fde4 + 0x24));
      FUN_8005955c(PTR_PTR_8009fde4);
      DAT_8009fdf0 = (**(code **)(PTR_PTR_8009fde4 + 0x34))(0);
    }
    else {
      DAT_8009fdf0 = (**(code **)(PTR_PTR_8009fde4 + 0x34))(1);
    }
  }
  else {
    if (uVar2 != 3) {
      return 0xffffffff;
    }
    DAT_8009fdf0 = (**(code **)(PTR_PTR_8009fde4 + 0x34))(1);
    FUN_80061ca4(2,*(undefined4 *)(PTR_PTR_8009fde4 + 0x24));
  }
  uVar2 = (**(code **)(PTR_PTR_8009fde4 + 0x28))(8);
  if (DAT_8009fdf4 == 0) {
    uVar1 = 0x8000000;
  }
  else {
    uVar1 = 0x8000080;
  }
  (**(code **)(PTR_PTR_8009fde4 + 0x10))(uVar2 | uVar1);
  uVar3 = 0;
  if ((param_1 & 8) != 0) {
    DAT_8009fdf0 = 2;
    uVar3 = 0x20000504;
    if (DAT_8009fdf4 != 0) {
      uVar3 = 0x20000501;
    }
    uVar3 = (**(code **)(PTR_PTR_8009fde4 + 0x10))(uVar3);
  }
  return uVar3;
}



// ---- FUN_80059750 @ 80059750

undefined4 FUN_80059750(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar1 = DAT_8009fdf4;
  DAT_8009fdf4 = param_1;
  uVar2 = (**(code **)(PTR_PTR_8009fde4 + 0x28))(8);
  if (DAT_8009fdf4 == 0) {
    uVar3 = 0x8000000;
  }
  else {
    uVar3 = 0x8000080;
  }
  (**(code **)(PTR_PTR_8009fde4 + 0x10))(uVar2 | uVar3);
  if (DAT_8009fdf0 == 2) {
    uVar4 = 0x20000504;
    if (DAT_8009fdf4 != 0) {
      uVar4 = 0x20000501;
    }
    (**(code **)(PTR_PTR_8009fde4 + 0x10))(uVar4);
  }
  return uVar1;
}



// ---- FUN_80059820 @ 80059820

undefined4 FUN_80059820(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = DAT_8009fdec;
  DAT_8009fdec = param_1;
  if (param_1 != 0) {
    (*(code *)PTR_FUN_8009fde8)
              (s_SetGraphDebug_level__d_type__d_r_80029074,param_1,DAT_8009fdf0,DAT_8009fdf4);
  }
  return uVar1;
}



// ---- FUN_80059884 @ 80059884

undefined4 FUN_80059884(void)

{
  return DAT_8009fdf0;
}



// ---- FUN_800598bc @ 800598bc

void FUN_800598bc(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x3000001;
  if (param_1 != 0) {
    uVar1 = 0x3000000;
  }
  (**(code **)(PTR_PTR_8009fde4 + 0x10))(uVar1);
  return;
}



// ---- FUN_800598fc @ 800598fc

void FUN_800598fc(void)

{
  (**(code **)(PTR_PTR_8009fde4 + 0x3c))();
  return;
}



// ---- FUN_8005992c @ 8005992c

void FUN_8005992c(undefined4 param_1,uint param_2,uint param_3,uint param_4)

{
  (**(code **)(PTR_PTR_8009fde4 + 8))
            (*(undefined4 *)(PTR_PTR_8009fde4 + 0xc),param_1,8,
             (param_4 & 0xff) << 0x10 | (param_3 & 0xff) << 8 | param_2 & 0xff);
  return;
}



// ---- FUN_8005997c @ 8005997c

void FUN_8005997c(undefined4 param_1,undefined4 param_2)

{
  (**(code **)(PTR_PTR_8009fde4 + 8))(*(undefined4 *)(PTR_PTR_8009fde4 + 0x20),param_1,8,param_2);
  return;
}



// ---- FUN_800599b8 @ 800599b8

void FUN_800599b8(undefined4 param_1,undefined4 param_2)

{
  (**(code **)(PTR_PTR_8009fde4 + 8))(*(undefined4 *)(PTR_PTR_8009fde4 + 0x1c),param_1,8,param_2);
  return;
}



// ---- FUN_800599f4 @ 800599f4

void FUN_800599f4(undefined4 *param_1,uint param_2,int param_3)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  undefined4 local_10;
  
  local_20 = 0x4ffffff;
  local_1c = 0x80000000;
  local_18 = *param_1;
  local_14 = param_3 << 0x10 | param_2 & 0xffff;
  local_10 = param_1[1];
  (**(code **)(PTR_PTR_8009fde4 + 8))(*(undefined4 *)(PTR_PTR_8009fde4 + 0x18),&local_20,0x14,0);
  return;
}



// ---- FUN_80059ab4 @ 80059ab4

undefined4 FUN_80059ab4(undefined4 param_1)

{
  (**(code **)(PTR_PTR_8009fde4 + 0x2c))();
  return param_1;
}



// ---- FUN_80059aec @ 80059aec

void FUN_80059aec(int param_1)

{
  undefined1 uVar1;
  
  uVar1 = *(undefined1 *)(param_1 + 3);
  if (DAT_8009fdec != 0) {
    FUN_8005d0a4(s_DrawPrim_800290a0,param_1);
  }
  (**(code **)(PTR_PTR_8009fde4 + 0x3c))(0);
  (**(code **)(PTR_PTR_8009fde4 + 0x14))(param_1 + 4,uVar1);
  return;
}



// ---- FUN_80059b70 @ 80059b70

void FUN_80059b70(undefined4 param_1)

{
  if (DAT_8009fdec == 0) {
    (**(code **)(PTR_PTR_8009fde4 + 4))(*(undefined4 *)(PTR_PTR_8009fde4 + 0x18),param_1,0);
  }
  else {
    FUN_8005ceb4();
  }
  return;
}



// ---- FUN_80059bc8 @ 80059bc8

undefined4 * FUN_80059bc8(undefined4 *param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  FUN_8005a22c(param_1 + 7,param_1);
  puVar1 = PTR_PTR_8009fde4;
  param_1[7] = param_1[7] | 0xffffff;
  (**(code **)(puVar1 + 4))(*(undefined4 *)(puVar1 + 0x18),param_1 + 7,0);
  puVar7 = param_1;
  puVar2 = (undefined4 *)&DAT_800a3148;
  do {
    puVar8 = puVar2;
    puVar6 = puVar7;
    uVar3 = puVar6[1];
    uVar4 = puVar6[2];
    uVar5 = puVar6[3];
    *puVar8 = *puVar6;
    puVar8[1] = uVar3;
    puVar8[2] = uVar4;
    puVar8[3] = uVar5;
    puVar7 = puVar6 + 4;
    puVar2 = puVar8 + 4;
  } while (puVar7 != param_1 + 0x14);
  uVar3 = puVar6[5];
  uVar4 = puVar6[6];
  puVar8[4] = *puVar7;
  puVar8[5] = uVar3;
  puVar8[6] = uVar4;
  return param_1;
}



// ---- FUN_80059ce8 @ 80059ce8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort * FUN_80059ce8(ushort *param_1)

{
  ushort uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar7 = 0x8000000;
  if (DAT_8009fdf0 == 0) {
    uVar3 = (param_1[1] & 0x1ff) << 10 | *param_1 & 0x3ff;
  }
  else {
    uVar3 = FUN_8005a780();
    uVar3 = (param_1[1] & 0xfff) << 0xc | uVar3 & 0xfff;
  }
  (**(code **)(PTR_PTR_8009fde4 + 0x10))(uVar3 | 0x5000000);
  uVar6 = (short)param_1[4] * 10 + 0x260;
  uVar3 = (int)(short)param_1[5] + 0x10;
  if ((short)param_1[6] == 0) {
    uVar5 = (short)param_1[4] * 10 + 0xc60;
  }
  else {
    uVar5 = uVar6 + (short)param_1[6] * 10;
  }
  uVar8 = uVar3 + (int)(short)param_1[7];
  if ((short)param_1[7] == 0) {
    uVar8 = (int)(short)param_1[5] + 0x100;
  }
  uVar4 = 500;
  if ((499 < (int)uVar6) && (uVar4 = uVar6, 0xcda < (int)uVar6)) {
    uVar4 = 0xcda;
  }
  uVar6 = uVar4 + 0x50;
  if (((int)(uVar4 + 0x50) <= (int)uVar5) && (uVar6 = uVar5, 0xcda < (int)uVar5)) {
    uVar6 = 0xcda;
  }
  if ((int)uVar3 < 0) {
    uVar3 = 0;
  }
  else if ((char)param_1[9] == '\0') {
    if (0xfe < (int)uVar3) goto LAB_80059e40;
  }
  else if (0x136 < (int)uVar3) {
LAB_80059e40:
    uVar3 = 0xfe;
    if ((char)param_1[9] != '\0') {
      uVar3 = 0x136;
    }
  }
  uVar5 = uVar3 + 1;
  if ((int)(uVar3 + 1) <= (int)uVar8) {
    uVar5 = uVar8;
    if ((char)param_1[9] == '\0') {
      if ((int)uVar8 < 0x100) goto LAB_80059ec0;
    }
    else if ((int)uVar8 < 0x138) goto LAB_80059ec0;
    uVar5 = 0xff;
    if ((char)param_1[9] != '\0') {
      uVar5 = 0x137;
    }
  }
LAB_80059ec0:
  (**(code **)(PTR_PTR_8009fde4 + 0x10))((uVar6 & 0xfff) << 0xc | uVar4 & 0xfff | 0x6000000);
  (**(code **)(PTR_PTR_8009fde4 + 0x10))((uVar5 & 0x3ff) << 10 | uVar3 & 0x3ff | 0x7000000);
  if ((char)param_1[9] == '\x01') {
    uVar7 = 0x8000008;
  }
  if (*(char *)((int)param_1 + 0x11) != '\0') {
    uVar7 = uVar7 | 0x10;
  }
  if ((char)param_1[8] != '\0') {
    uVar7 = uVar7 | 0x20;
  }
  if (DAT_8009fdf4 != 0) {
    uVar7 = uVar7 | 0x80;
  }
  uVar1 = param_1[2];
  if (0x118 < (short)uVar1) {
    if ((short)uVar1 < 0x161) {
      uVar7 = uVar7 | 1;
    }
    else if ((short)uVar1 < 0x191) {
      uVar7 = uVar7 | 0x40;
    }
    else if ((short)uVar1 < 0x231) {
      uVar7 = uVar7 | 2;
    }
    else {
      uVar7 = uVar7 | 3;
    }
  }
  bVar2 = (short)param_1[3] < 0x121;
  if ((char)param_1[9] == '\0') {
    bVar2 = (short)param_1[3] < 0x101;
  }
  if (!bVar2) {
    uVar7 = uVar7 | 0x24;
  }
  (**(code **)(PTR_PTR_8009fde4 + 0x10))(uVar7);
  _DAT_800a31a8 = *(undefined4 *)param_1;
  _DAT_800a31ac = *(undefined4 *)(param_1 + 2);
  _DAT_800a31b0 = *(undefined4 *)(param_1 + 4);
  _DAT_800a31b4 = *(undefined4 *)(param_1 + 6);
  _DAT_800a31b8 = *(undefined4 *)(param_1 + 8);
  return param_1;
}



// ---- FUN_8005a0c8 @ 8005a0c8

void FUN_8005a0c8(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  *(undefined1 *)(param_1 + 3) = 2;
  uVar1 = FUN_8005a6fc(param_2);
  *(undefined4 *)(param_1 + 4) = uVar1;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// ---- FUN_8005a100 @ 8005a100

void FUN_8005a100(int param_1,short *param_2)

{
  undefined4 uVar1;
  
  *(undefined1 *)(param_1 + 3) = 2;
  uVar1 = FUN_8005a520((int)*param_2,(int)param_2[1]);
  *(undefined4 *)(param_1 + 4) = uVar1;
  uVar1 = FUN_8005a5f0((int)*param_2 + (int)param_2[2] + -1,(int)param_2[1] + (int)param_2[3] + -1);
  *(undefined4 *)(param_1 + 8) = uVar1;
  return;
}



// ---- FUN_8005a170 @ 8005a170

void FUN_8005a170(int param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  
  *(undefined1 *)(param_1 + 3) = 2;
  uVar1 = FUN_8005a6c0(*param_2,param_2[1]);
  *(undefined4 *)(param_1 + 4) = uVar1;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



// ---- FUN_8005a1d8 @ 8005a1d8

void FUN_8005a1d8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  
  *(undefined1 *)(param_1 + 3) = 2;
  uVar1 = FUN_8005a4d0(param_2,param_3,param_4);
  *(undefined4 *)(param_1 + 4) = uVar1;
  uVar1 = FUN_8005a6fc(param_5);
  *(undefined4 *)(param_1 + 8) = uVar1;
  return;
}



// ---- FUN_8005a22c @ 8005a22c

void FUN_8005a22c(int param_1,uint *param_2)

{
  uint uVar1;
  ushort uVar2;
  undefined4 uVar3;
  short sVar4;
  char cVar5;
  undefined4 local_18;
  undefined4 local_14;
  
  uVar3 = FUN_8005a520((int)(short)*param_2,(int)*(short *)((int)param_2 + 2));
  *(undefined4 *)(param_1 + 4) = uVar3;
  uVar3 = FUN_8005a5f0((int)(short)param_2[1] + (int)(short)*param_2 + -1,
                       (int)*(short *)((int)param_2 + 2) + (int)*(short *)((int)param_2 + 6) + -1);
  *(undefined4 *)(param_1 + 8) = uVar3;
  uVar3 = FUN_8005a6c0((int)(short)param_2[2],(int)*(short *)((int)param_2 + 10));
  *(undefined4 *)(param_1 + 0xc) = uVar3;
  uVar3 = FUN_8005a4d0(*(undefined1 *)((int)param_2 + 0x17),*(undefined1 *)((int)param_2 + 0x16),
                       (short)param_2[5]);
  *(undefined4 *)(param_1 + 0x10) = uVar3;
  uVar3 = FUN_8005a6fc(param_2 + 3);
  *(undefined4 *)(param_1 + 0x14) = uVar3;
  *(undefined4 *)(param_1 + 0x18) = 0xe6000000;
  cVar5 = '\a';
  if ((char)param_2[6] == '\0') goto LAB_8005a4b4;
  uVar1 = *param_2;
  uVar2 = (ushort)param_2[1];
  sVar4 = *(short *)((int)param_2 + 6);
  if ((short)uVar2 < 0) {
    uVar2 = 0;
  }
  else if (0x3ff < (short)uVar2) {
    uVar2 = 0x3ff;
  }
  if (sVar4 < 0) {
    sVar4 = 0;
  }
  else if (DAT_8009fdf0 == 0) {
    if (0x1ff < sVar4) goto LAB_8005a368;
  }
  else if (0x3ff < sVar4) {
LAB_8005a368:
    sVar4 = 0x1ff;
    if (DAT_8009fdf0 != 0) {
      sVar4 = 0x3ff;
    }
  }
  local_18._0_2_ = (short)uVar1;
  local_14 = CONCAT22(sVar4,uVar2);
  if (((uVar1 & 0x3f) == 0) && ((uVar2 & 0x3f) == 0)) {
    cVar5 = '\n';
    *(uint *)(param_1 + 0x1c) =
         (uint)*(byte *)((int)param_2 + 0x1b) << 0x10 |
         (uint)*(byte *)((int)param_2 + 0x1a) << 8 | 0x2000000 |
         (uint)*(byte *)((int)param_2 + 0x19);
    *(uint *)(param_1 + 0x20) = uVar1;
    *(undefined4 *)(param_1 + 0x24) = local_14;
  }
  else {
    local_18._2_2_ = (short)(uVar1 >> 0x10);
    local_18 = CONCAT22(local_18._2_2_ - *(short *)((int)param_2 + 10),
                        (short)local_18 - (short)param_2[2]);
    *(uint *)(param_1 + 0x1c) =
         (uint)*(byte *)((int)param_2 + 0x1b) << 0x10 |
         (uint)*(byte *)((int)param_2 + 0x1a) << 8 | 0x60000000 |
         (uint)*(byte *)((int)param_2 + 0x19);
    *(undefined4 *)(param_1 + 0x20) = local_18;
    *(undefined4 *)(param_1 + 0x24) = local_14;
    cVar5 = '\n';
  }
LAB_8005a4b4:
  *(char *)(param_1 + 3) = cVar5 + -1;
  return;
}



// ---- FUN_8005a4d0 @ 8005a4d0

uint FUN_8005a4d0(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  if (DAT_8009fdf0 == 0) {
    uVar1 = 0xe1000000;
    if (param_2 != 0) {
      uVar1 = 0xe1000200;
    }
    param_3 = param_3 & 0x1ff;
    if (param_1 != 0) {
      param_3 = param_3 | 0x400;
    }
  }
  else {
    uVar1 = 0xe1000000;
    if (param_2 != 0) {
      uVar1 = 0xe1000800;
    }
    param_3 = param_3 & 0x27ff;
    if (param_1 != 0) {
      param_3 = param_3 | 0x1000;
    }
  }
  return uVar1 | param_3;
}



// ---- FUN_8005a520 @ 8005a520

uint FUN_8005a520(short param_1,uint param_2)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (uint)param_1;
  if ((int)uVar2 < 0) {
    uVar2 = 0;
  }
  else if (0x3ff < (int)uVar2) {
    uVar2 = 0x3ff;
  }
  sVar1 = (short)param_2;
  if (sVar1 < 0) {
    param_2 = 0;
  }
  else {
    if (DAT_8009fdf0 == 0) {
      if (sVar1 < 0x200) goto code_r0x8005a5bc;
    }
    else if (sVar1 < 0x400) goto code_r0x8005a5bc;
    param_2 = 0x1ff;
    if (DAT_8009fdf0 != 0) {
      param_2 = 0x3ff;
    }
  }
code_r0x8005a5bc:
  if (DAT_8009fdf0 == 0) {
    uVar3 = (param_2 & 0x3ff) << 10;
    uVar2 = uVar2 & 0x3ff;
  }
  else {
    uVar3 = (param_2 & 0xfff) << 0xc;
    uVar2 = uVar2 & 0xfff;
  }
  return uVar3 | uVar2 | 0xe3000000;
}



// ---- FUN_8005a5f0 @ 8005a5f0

uint FUN_8005a5f0(short param_1,uint param_2)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (uint)param_1;
  if ((int)uVar2 < 0) {
    uVar2 = 0;
  }
  else if (0x3ff < (int)uVar2) {
    uVar2 = 0x3ff;
  }
  sVar1 = (short)param_2;
  if (sVar1 < 0) {
    param_2 = 0;
  }
  else {
    if (DAT_8009fdf0 == 0) {
      if (sVar1 < 0x200) goto code_r0x8005a68c;
    }
    else if (sVar1 < 0x400) goto code_r0x8005a68c;
    param_2 = 0x1ff;
    if (DAT_8009fdf0 != 0) {
      param_2 = 0x3ff;
    }
  }
code_r0x8005a68c:
  if (DAT_8009fdf0 == 0) {
    uVar3 = (param_2 & 0x1ff) << 10;
    uVar2 = uVar2 & 0x3ff;
  }
  else {
    uVar3 = (param_2 & 0xfff) << 0xc;
    uVar2 = uVar2 & 0xfff;
  }
  return uVar3 | uVar2 | 0xe4000000;
}



// ---- FUN_8005a6c0 @ 8005a6c0

uint FUN_8005a6c0(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 & 0xfff;
  if (DAT_8009fdf0 == 0) {
    uVar1 = (param_2 & 0x7ff) << 0xb;
    uVar2 = param_1 & 0x7ff;
  }
  else {
    uVar1 = (param_2 & 0xfff) << 0xc;
  }
  return uVar1 | uVar2 | 0xe5000000;
}



// ---- FUN_8005a6fc @ 8005a6fc

uint FUN_8005a6fc(byte *param_1)

{
  uint uVar1;
  
  if (param_1 == (byte *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (uint)(param_1[2] >> 3) << 0xf | (uint)(*param_1 >> 3) << 10 | 0xe2000000 |
            ((int)(-(int)*(short *)(param_1 + 6) & 0xffU) >> 3) << 5 |
            (int)(-(int)*(short *)(param_1 + 4) & 0xffU) >> 3;
  }
  return uVar1;
}



// ---- FUN_8005a780 @ 8005a780

uint FUN_8005a780(short *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)(DAT_8009fdf0 < 2);
  if (DAT_8009fdf0 == 1) {
    if (DAT_8009fdf4 == 0) {
      uVar1 = (uint)*param_1;
    }
    else {
      uVar1 = (0x400 - param_1[2]) - (int)*param_1;
    }
  }
  else if (uVar1 == 0) {
    uVar1 = 2;
    if (DAT_8009fdf0 == 2) {
      if (DAT_8009fdf4 == 0) {
        uVar1 = (int)*param_1 / 2;
      }
      else {
        uVar1 = (0x400 - (int)param_1[2] / 2) - (int)*param_1;
      }
    }
  }
  else if (DAT_8009fdf0 == 0) {
    uVar1 = (uint)*param_1;
  }
  return uVar1;
}



// ---- FUN_8005a870 @ 8005a870

int FUN_8005a870(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  *DAT_8009fe1c = *DAT_8009fe1c | 0x8000000;
  *DAT_8009fe18 = 0;
  *DAT_8009fe10 = param_1 + param_2 * 4 + -4;
  *DAT_8009fe14 = param_2;
  *DAT_8009fe18 = 0x11000002;
  FUN_8005ba00();
  uVar1 = *DAT_8009fe18;
  while( true ) {
    if ((uVar1 & 0x1000000) == 0) {
      return param_2;
    }
    iVar2 = FUN_8005ba20();
    if (iVar2 != 0) break;
    uVar1 = *DAT_8009fe18;
  }
  return -1;
}



// ---- FUN_8005a958 @ 8005a958

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8005a958(uint *param_1,uint param_2)

{
  uint uVar1;
  ushort uVar2;
  short sVar3;
  undefined4 local_14;
  
  uVar1 = *param_1;
  uVar2 = (ushort)param_1[1];
  sVar3 = *(short *)((int)param_1 + 6);
  if ((short)uVar2 < 0) {
    uVar2 = 0;
  }
  else if (0x3ff < (short)uVar2) {
    uVar2 = 0x3ff;
  }
  if (sVar3 < 0) {
    sVar3 = 0;
  }
  else {
    if (DAT_8009fdf0 == 0) {
      if (sVar3 < 0x200) goto LAB_8005aa2c;
    }
    else if (sVar3 < 0x400) goto LAB_8005aa2c;
    sVar3 = 0x1ff;
    if (DAT_8009fdf0 != 0) {
      sVar3 = 0x3ff;
    }
  }
LAB_8005aa2c:
  local_14 = CONCAT22(sVar3,uVar2);
  if (((uVar1 & 0x3f) == 0) && ((uVar2 & 0x3f) == 0)) {
    _DAT_800a3108 = 0x4ffffff;
    _DAT_800a310c = 0xe6000000;
    _DAT_800a3110 = param_2 & 0xffffff | 0x2000000;
    _DAT_800a3118 = local_14;
    _DAT_800a3114 = uVar1;
  }
  else {
    _DAT_800a3108 = 0x70a3128;
    _DAT_800a310c = 0xe3000000;
    _DAT_800a3110 = 0xe4ffffff;
    _DAT_800a3114 = 0xe5000000;
    _DAT_800a3118 = 0xe6000000;
    _DAT_800a311c = param_2 & 0xffffff | 0x60000000;
    _DAT_800a3128 = 0x3ffffff;
    _DAT_800a3124 = local_14;
    _DAT_800a3120 = uVar1;
    _DAT_800a312c = FUN_8005b210(3);
    _DAT_800a312c = _DAT_800a312c | 0xe3000000;
    _DAT_800a3130 = FUN_8005b210(4);
    _DAT_800a3130 = _DAT_800a3130 | 0xe4000000;
    _DAT_800a3134 = FUN_8005b210(5);
    _DAT_800a3134 = _DAT_800a3134 | 0xe5000000;
  }
  FUN_8005b1c0(&DAT_800a3108);
  return 0;
}



// ---- FUN_8005aba0 @ 8005aba0

undefined4 FUN_8005aba0(undefined4 *param_1,undefined4 *param_2)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  short sVar7;
  uint uVar8;
  undefined4 local_20;
  undefined4 local_1c;
  
  FUN_8005ba00();
  local_20 = *param_1;
  sVar1 = *(short *)(param_1 + 1);
  sVar7 = *(short *)((int)param_1 + 6);
  if (sVar1 < 0) {
    sVar1 = 0;
  }
  else if (0x3ff < sVar1) {
    sVar1 = 0x3ff;
  }
  if (sVar7 < 0) {
    sVar7 = 0;
  }
  else {
    if (DAT_8009fdf0 == 0) {
      if (sVar7 < 0x200) goto LAB_8005ac8c;
    }
    else if (sVar7 < 0x400) goto LAB_8005ac8c;
    sVar7 = 0x1ff;
    if (DAT_8009fdf0 != 0) {
      sVar7 = 0x3ff;
    }
  }
LAB_8005ac8c:
  iVar5 = (int)(short)local_20;
  local_1c = CONCAT22(sVar7,sVar1);
  if (0x3ff < iVar5) {
    uVar8 = (uint)local_20 >> 0x10;
    local_20 = CONCAT22((short)uVar8,(short)((iVar5 + -0x400) / 2));
  }
  uVar6 = ((int)sVar1 * (int)sVar7 + 1) / 2;
  uVar8 = uVar6 & 0xf;
  if ((int)uVar6 < 1) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar3 = *DAT_8009fe00;
    while ((uVar3 & 0x4000000) == 0) {
      iVar4 = FUN_8005ba20();
      if (iVar4 != 0) {
        return 0xffffffff;
      }
      uVar3 = *DAT_8009fe00;
    }
    *DAT_8009fe00 = 0x4000000;
    *DAT_8009fdfc = 0x1000000;
    uVar2 = 0xa0000000;
    if (0x3ff < iVar5) {
      uVar2 = 0xb0000000;
    }
    *DAT_8009fdfc = uVar2;
    *DAT_8009fdfc = local_20;
    *DAT_8009fdfc = local_1c;
    while (uVar8 = uVar8 - 1, uVar8 != 0xffffffff) {
      uVar2 = *param_2;
      param_2 = param_2 + 1;
      *DAT_8009fdfc = uVar2;
    }
    if ((int)uVar6 >> 4 != 0) {
      *DAT_8009fe00 = 0x4000002;
      *DAT_8009fe04 = (int)param_2;
      *DAT_8009fe08 = ((int)uVar6 >> 4) << 0x10 | 0x10;
      *DAT_8009fe0c = 0x1000201;
    }
    uVar2 = 0;
  }
  return uVar2;
}



// ---- FUN_8005ae50 @ 8005ae50

undefined4 FUN_8005ae50(undefined4 *param_1,undefined4 *param_2)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  short sVar6;
  uint uVar7;
  undefined4 local_1c;
  
  FUN_8005ba00();
  uVar2 = *param_1;
  sVar1 = *(short *)(param_1 + 1);
  sVar6 = *(short *)((int)param_1 + 6);
  if (sVar1 < 0) {
    sVar1 = 0;
  }
  else if (0x3ff < sVar1) {
    sVar1 = 0x3ff;
  }
  if (sVar6 < 0) {
    sVar6 = 0;
  }
  else {
    if (DAT_8009fdf0 == 0) {
      if (sVar6 < 0x200) goto LAB_8005af38;
    }
    else if (sVar6 < 0x400) goto LAB_8005af38;
    sVar6 = 0x1ff;
    if (DAT_8009fdf0 != 0) {
      sVar6 = 0x3ff;
    }
  }
LAB_8005af38:
  uVar5 = ((int)sVar1 * (int)sVar6 + 1) / 2;
  local_1c = CONCAT22(sVar6,sVar1);
  if ((int)uVar5 < 1) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar7 = uVar5 & 0xf;
    uVar3 = *DAT_8009fe00;
    while ((uVar3 & 0x4000000) == 0) {
      iVar4 = FUN_8005ba20();
      if (iVar4 != 0) {
        return 0xffffffff;
      }
      uVar3 = *DAT_8009fe00;
    }
    *DAT_8009fe00 = 0x4000000;
    *DAT_8009fdfc = 0x1000000;
    *DAT_8009fdfc = 0xc0000000;
    *DAT_8009fdfc = uVar2;
    *DAT_8009fdfc = local_1c;
    uVar3 = *DAT_8009fe00;
    while ((uVar3 & 0x8000000) == 0) {
      iVar4 = FUN_8005ba20();
      if (iVar4 != 0) {
        return 0xffffffff;
      }
      uVar3 = *DAT_8009fe00;
    }
    while (uVar7 = uVar7 - 1, uVar7 != 0xffffffff) {
      *param_2 = *DAT_8009fdfc;
      param_2 = param_2 + 1;
    }
    if ((int)uVar5 >> 4 != 0) {
      *DAT_8009fe00 = 0x4000003;
      *DAT_8009fe04 = (int)param_2;
      *DAT_8009fe08 = ((int)uVar5 >> 4) << 0x10 | 0x10;
      *DAT_8009fe0c = 0x1000200;
    }
    uVar2 = 0;
  }
  return uVar2;
}



// ---- FUN_8005b11c @ 8005b11c

void FUN_8005b11c(uint param_1)

{
  *DAT_8009fe00 = param_1;
  *(uint *)((param_1 >> 0x18) * 4 + -0x7ff5ce40) = param_1 & 0xffffff;
  return;
}



// ---- FUN_8005b154 @ 8005b154

uint FUN_8005b154(int param_1)

{
  return param_1 << 0x18 | *(uint *)(param_1 * 4 + -0x7ff5ce40);
}



// ---- FUN_8005b174 @ 8005b174

undefined4 FUN_8005b174(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  *DAT_8009fe00 = 0x4000000;
  while (param_2 = param_2 + -1, param_2 != -1) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    *DAT_8009fdfc = uVar1;
  }
  return 0;
}



// ---- FUN_8005b1c0 @ 8005b1c0

void FUN_8005b1c0(undefined4 param_1)

{
  *DAT_8009fe00 = 0x4000002;
  *DAT_8009fe04 = param_1;
  *DAT_8009fe08 = 0;
  *DAT_8009fe0c = 0x1000401;
  return;
}



// ---- FUN_8005b210 @ 8005b210

uint FUN_8005b210(uint param_1)

{
  *DAT_8009fe00 = param_1 | 0x10000000;
  return *DAT_8009fdfc & 0xffffff;
}



// ---- FUN_8005b244 @ 8005b244

void FUN_8005b244(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_8005b268(param_1,param_2,0,param_3);
  return;
}



// ---- FUN_8005b268 @ 8005b268

uint FUN_8005b268(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  FUN_8005ba00();
  uVar2 = DAT_8009fe20 + 1 & 0x3f;
  iVar1 = DAT_8009fe20;
  while( true ) {
    if ((uVar2 != DAT_8009fe24) || (*(int *)(DAT_8009fe24 * 0x4c + -0x7ff5cdb8) == 0)) {
      iVar3 = iVar1 * 0x4c;
      *(undefined4 *)(iVar3 + -0x7ff5cdb8) = 0;
      DAT_8009fe20 = uVar2;
      if (param_3 == 0) {
        *(undefined4 *)(iVar3 + -0x7ff5cdb4) = param_2;
      }
      else {
        FUN_8005babc(iVar3 + -0x7ff5cdac,param_2,param_3);
        *(int *)(iVar3 + -0x7ff5cdb4) = iVar3 + -0x7ff5cdac;
      }
      *(undefined4 *)(iVar1 * 0x4c + -0x7ff5cdb0) = param_4;
      *(undefined4 *)(iVar1 * 0x4c + -0x7ff5cdb8) = param_1;
      FUN_8005b454();
      return DAT_8009fe20 - DAT_8009fe24 & 0x3f;
    }
    DAT_8009fe20 = iVar1;
    if ((DAT_8009fe28 != 0) && (iVar1 = FUN_80061d34(), iVar1 != 0)) break;
    iVar1 = FUN_8005ba20();
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    FUN_8005b454();
    iVar1 = DAT_8009fe20;
  }
  return 0xffffffff;
}



// ---- FUN_8005b454 @ 8005b454

undefined4 FUN_8005b454(void)

{
  uint uVar1;
  int iVar2;
  
  FUN_8005ba00();
  while( true ) {
    if (DAT_8009fe20 == DAT_8009fe24) {
      if (DAT_8009fdf8 != (code *)0x0) {
        (*DAT_8009fdf8)();
      }
      return 0;
    }
    if (DAT_8009fe28 != 0) {
      return 1;
    }
    if ((*DAT_8009fe0c & 0x1000000) != 0) {
      return 2;
    }
    uVar1 = *DAT_8009fe00;
    DAT_8009fe28 = 1;
    while ((uVar1 & 0x10000000) == 0) {
      iVar2 = FUN_8005ba20();
      if (iVar2 != 0) {
        return 0xffffffff;
      }
      uVar1 = *DAT_8009fe00;
    }
    if (*(int *)(DAT_8009fe24 * 0x4c + -0x7ff5cdb8) == 0) break;
    (**(code **)(DAT_8009fe24 * 0x4c + -0x7ff5cdb8))
              (*(undefined4 *)(DAT_8009fe24 * 0x4c + -0x7ff5cdb4),
               *(undefined4 *)(DAT_8009fe24 * 0x4c + -0x7ff5cdb0));
    *(undefined4 *)(DAT_8009fe24 * 0x4c + -0x7ff5cdb8) = 0;
    DAT_8009fe24 = DAT_8009fe24 + 1 & 0x3f;
    if (0 < DAT_8009fe28) {
      DAT_8009fe28 = DAT_8009fe28 + -1;
    }
  }
  if (DAT_8009fe28 < 1) {
    return 3;
  }
  DAT_8009fe28 = DAT_8009fe28 + -1;
  return 3;
}



// ---- FUN_8005b72c @ 8005b72c

uint FUN_8005b72c(int param_1)

{
  int iVar1;
  
  DAT_8009fe24 = 0;
  iVar1 = 0;
  DAT_8009fe20 = 0;
  do {
    *(undefined4 *)(iVar1 + -0x7ff5cdb8) = 0;
    iVar1 = iVar1 + 0x4c;
  } while (iVar1 < 0x1300);
  if (param_1 == 0) {
    *DAT_8009fe0c = 0x401;
    *DAT_8009fe1c = *DAT_8009fe1c | 0x800;
    *DAT_8009fe00 = 0;
  }
  else if (param_1 == 1) {
    *DAT_8009fe0c = 0x401;
    *DAT_8009fe1c = *DAT_8009fe1c | 0x800;
    *DAT_8009fe00 = 0x2000000;
    *DAT_8009fe00 = 0x1000000;
  }
  *DAT_8009fdfc = *DAT_8009fe00 & 0x3fff | 0xe1001000;
  DAT_8009fe28 = 0;
  return *DAT_8009fe00 >> 0xc & 1;
}



// ---- FUN_8005b87c @ 8005b87c

uint FUN_8005b87c(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    FUN_8005ba00();
    do {
      if (DAT_8009fe20 == DAT_8009fe24) {
        uVar1 = *DAT_8009fe0c;
        while ((uVar1 & 0x1000000) != 0) {
          iVar2 = FUN_8005ba20();
          if (iVar2 != 0) {
            return 0xffffffff;
          }
          uVar1 = *DAT_8009fe0c;
        }
        uVar1 = *DAT_8009fe00;
        while( true ) {
          if ((uVar1 & 0x4000000) != 0) {
            return uVar1 & 0x4000000;
          }
          iVar2 = FUN_8005ba20();
          if (iVar2 != 0) break;
          uVar1 = *DAT_8009fe00;
        }
        return 0xffffffff;
      }
      FUN_8005b454();
      iVar2 = FUN_8005ba20();
    } while (iVar2 == 0);
    return 0xffffffff;
  }
  if (DAT_8009fe20 != DAT_8009fe24) {
    return DAT_8009fe20 - DAT_8009fe24 & 0x3f;
  }
  if ((*DAT_8009fe00 & 0x10000000) == 0) {
    return 1;
  }
  if ((*DAT_8009fe00 & 0x4000000) == 0) {
    return 0;
  }
  return 1;
}



// ---- FUN_8005ba00 @ 8005ba00

void FUN_8005ba00(void)

{
  DAT_800a0108 = DAT_8009ffd8 + 0xf0;
  return;
}



// ---- FUN_8005ba20 @ 8005ba20

undefined4 FUN_8005ba20(void)

{
  undefined4 uVar1;
  
  if (DAT_800a0108 < DAT_8009ffd8) {
    FUN_80058614(s_GPU_timeout_QUE___2d__2d__CODE___800290ac,DAT_8009fe20,DAT_8009fe24,
                 *DAT_8009fe00 >> 0x1a & 1,*DAT_8009fe0c >> 0x18 & 1,*DAT_8009fe04);
    FUN_8005b72c(1);
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



// ---- FUN_8005babc @ 8005babc

void FUN_8005babc(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = param_3 + -1;
  if (param_3 != 0) {
    do {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      iVar2 = iVar2 + -1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    } while (iVar2 != -1);
  }
  return;
}



// ---- FUN_8005baec @ 8005baec

void FUN_8005baec(undefined1 *param_1,undefined1 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_3 + -1;
  if (param_3 != 0) {
    do {
      *param_1 = param_2;
      iVar1 = iVar1 + -1;
      param_1 = param_1 + 1;
    } while (iVar1 != -1);
  }
  return;
}



// ---- FUN_8005bb14 @ 8005bb14

void FUN_8005bb14(void)

{
  (*(code *)&LAB_000000a0)();
  return;
}



// ---- FUN_8005bb24 @ 8005bb24

void FUN_8005bb24(int param_1)

{
  if ((-1 < param_1) && (param_1 <= DAT_8009fe2c)) {
    PTR_FUN_8009fde8 = FUN_8005c12c;
    DAT_8009fe30 = param_1;
  }
  return;
}



// ---- FUN_8005bb64 @ 8005bb64

void FUN_8005bb64(undefined4 param_1,int param_2)

{
  DAT_800a0118 = FUN_8005ccc0(&DAT_8009e32c,param_1,param_2 + 0x80);
  DAT_800a0110 = FUN_8005cbd8(&DAT_8009e52c,0,0,param_1,param_2,0x80,0x20);
  DAT_8009fe2c = 0;
  FUN_800585f4(&DAT_8009e204,0,0xb0);
  return;
}



// ---- FUN_8005bbfc @ 8005bbfc

int FUN_8005bbfc(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
                int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  
  if (DAT_8009fe2c < 4) {
    if (DAT_8009fe2c == 0) {
      DAT_8009fe34 = 0;
    }
    if (0x400 < param_6 + DAT_8009fe34) {
      param_6 = 0x400 - DAT_8009fe34;
    }
    FUN_8005a1d8(DAT_8009fe2c * 0x2c + -0x7ff61dec,0,0,DAT_800a0110,0);
    if (param_5 != 0) {
      FUN_8005c8e0(&DAT_8009e204 + DAT_8009fe2c * 0x2c);
      (&DAT_8009e208)[DAT_8009fe2c * 0x2c] = 0;
      (&DAT_8009e209)[DAT_8009fe2c * 0x2c] = 0;
      (&DAT_8009e20a)[DAT_8009fe2c * 0x2c] = 0;
    }
    iVar2 = DAT_8009fe34;
    iVar1 = DAT_8009fe2c * 0x2c;
    *(undefined2 *)(&DAT_8009e20c + iVar1) = param_1;
    *(undefined2 *)(&DAT_8009e20e + iVar1) = param_2;
    *(undefined2 *)(&DAT_8009e210 + iVar1) = param_3;
    *(undefined2 *)(&DAT_8009e212 + iVar1) = param_4;
    *(int *)(&DAT_8009e220 + iVar1) = param_6;
    *(int *)(&DAT_8009e228 + iVar1) = iVar2 + -0x7ff5bab8;
    *(int *)(&DAT_8009e224 + iVar1) = iVar2 * 0x10 + -0x7ff5b6b8;
    *(undefined4 *)(&DAT_8009e22c + iVar1) = 0;
    **(undefined1 **)(&DAT_8009e228 + iVar1) = 0;
    iVar2 = *(int *)(&DAT_8009e224 + DAT_8009fe2c * 0x2c);
    iVar1 = 0;
    if (0 < param_6) {
      do {
        FUN_8005c868(iVar2);
        FUN_8005c7a0(iVar2,1);
        iVar1 = iVar1 + 1;
        *(undefined2 *)(iVar2 + 0xe) = DAT_800a0118;
        iVar2 = iVar2 + 0x10;
      } while (iVar1 < param_6);
    }
    DAT_8009fe34 = param_6 + DAT_8009fe34;
    iVar2 = DAT_8009fe2c;
    DAT_8009fe2c = DAT_8009fe2c + 1;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}



// ---- FUN_8005bec4 @ 8005bec4

int FUN_8005bec4(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined2 *puVar8;
  byte *pbVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  
  if (((param_1 < 0) || (DAT_8009fe2c <= param_1)) &&
     (param_1 = DAT_8009fe30, *(int *)(&DAT_8009e228 + DAT_8009fe30 * 0x2c) == 0)) {
    iVar2 = 0;
  }
  else {
    param_1 = param_1 * 0x2c;
    iVar2 = param_1 + -0x7ff61dec;
    pbVar9 = *(byte **)(&DAT_8009e228 + param_1);
    iVar12 = *(int *)(&DAT_8009e224 + param_1);
    iVar7 = (int)*(short *)(&DAT_8009e20c + param_1);
    iVar10 = (int)*(short *)(&DAT_8009e20e + param_1);
    iVar11 = *(int *)(&DAT_8009e220 + param_1);
    iVar13 = iVar7 + *(short *)(&DAT_8009e210 + param_1);
    iVar5 = iVar10 + *(short *)(&DAT_8009e212 + param_1);
    FUN_8005c760(iVar2);
    bVar4 = *pbVar9;
    if ((bVar4 != 0) && (iVar11 != 0)) {
      puVar8 = (undefined2 *)(iVar12 + 10);
      do {
        bVar1 = false;
        if (bVar4 == 0x20) {
LAB_8005c070:
          iVar7 = iVar7 + 8;
LAB_8005c074:
          if (iVar13 <= iVar7) {
            bVar1 = true;
          }
        }
        else {
          if (0x20 < bVar4) {
LAB_8005bff4:
            if (*pbVar9 - 0x61 < 0x1a) {
              iVar6 = *pbVar9 - 0x40;
            }
            else {
              iVar6 = *pbVar9 - 0x20;
            }
            iVar3 = iVar6;
            if (iVar6 < 0) {
              iVar3 = iVar6 + 0xf;
            }
            *(char *)(puVar8 + 1) = ((char)iVar6 + (char)(iVar3 >> 4) * -0x10) * '\b';
            if (iVar6 < 0) {
              iVar6 = iVar6 + 0xf;
            }
            *(char *)((int)puVar8 + 3) = (char)((iVar6 >> 4) << 3);
            puVar8[-1] = (short)iVar7;
            *puVar8 = (short)iVar10;
            FUN_8005c6c4(iVar2,iVar12);
            goto LAB_8005c070;
          }
          if (bVar4 == 9) {
            iVar7 = iVar7 + 0x20;
            goto LAB_8005c074;
          }
          if (bVar4 != 10) goto LAB_8005bff4;
          bVar1 = true;
        }
        if (bVar1) {
          iVar7 = (int)*(short *)(&DAT_8009e20c + param_1);
          iVar10 = iVar10 + 8;
          if (iVar5 <= iVar10) break;
        }
        puVar8 = puVar8 + 8;
        pbVar9 = pbVar9 + 1;
        bVar4 = *pbVar9;
        iVar12 = iVar12 + 0x10;
        iVar11 = iVar11 + -1;
        if ((bVar4 == 0) || (iVar11 == 0)) break;
      } while( true );
    }
    if ((&DAT_8009e20b)[param_1] != '\0') {
      FUN_8005c6c4(iVar2,&DAT_8009e204 + param_1);
    }
    FUN_80059b70(iVar2);
    *(undefined4 *)(&DAT_8009e22c + param_1) = 0;
    **(undefined1 **)(&DAT_8009e228 + param_1) = 0;
  }
  return iVar2;
}



// ---- FUN_8005c12c @ 8005c12c

/* WARNING: Removing unreachable block (ram,0x8005c334) */

undefined4 FUN_8005c12c(byte *param_1,byte *param_2,byte *param_3,undefined4 param_4)

{
  bool bVar1;
  bool bVar2;
  byte **ppbVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  byte *pbVar9;
  byte ***pppbVar10;
  byte ***pppbVar11;
  int iVar12;
  byte *pbVar13;
  byte *pbVar14;
  byte *local_res0;
  byte *local_res4;
  byte *local_res8;
  undefined4 local_resc;
  undefined1 local_2a;
  undefined1 local_29;
  byte **local_28 [2];
  
  local_28[0] = &local_res4;
  if (((int)param_1 < 0) || (DAT_8009fe2c <= (int)param_1)) {
    local_res0 = DAT_8009fe30;
    pbVar13 = param_1;
    if (*(int *)(&DAT_8009e228 + (int)DAT_8009fe30 * 0x2c) == 0) {
      return 0xffffffff;
    }
  }
  else {
    local_28[0] = &local_res8;
    pbVar13 = param_2;
    local_res0 = param_1;
  }
  iVar4 = (int)local_res0 * 0x2c;
  if (*(int *)(&DAT_8009e220 + iVar4) < *(int *)(&DAT_8009e22c + iVar4)) {
    return 0xffffffff;
  }
  bVar7 = *pbVar13;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  ppbVar3 = local_28[0];
  do {
    if (bVar7 == 0) {
      *(undefined1 *)(*(int *)(&DAT_8009e228 + iVar4) + *(int *)(&DAT_8009e22c + iVar4)) = 0;
      return *(undefined4 *)(&DAT_8009e22c + iVar4);
    }
    local_28[0] = ppbVar3;
    if (bVar7 == 0x25) {
      pbVar13 = pbVar13 + 1;
      bVar7 = *pbVar13;
      uVar8 = (uint)bVar7;
      iVar12 = 0;
      if (uVar8 == 0x25) goto LAB_8005c244;
      bVar2 = uVar8 != 0x30;
      while (uVar8 - 0x30 < 10) {
        iVar12 = iVar12 * 10 + -0x30 + uVar8;
        pbVar13 = pbVar13 + 1;
        uVar8 = (uint)*pbVar13;
      }
      pppbVar11 = local_28;
      if (iVar12 < 1) {
        iVar12 = 1;
      }
      bVar1 = (int)param_3 < iVar12;
      switch(uVar8) {
      case 0x58:
      case 0x78:
        param_3 = (byte *)0x0;
        local_28[0] = ppbVar3 + 1;
        pbVar5 = *ppbVar3;
        do {
          do {
            pppbVar11 = (byte ***)((int)pppbVar11 + -1);
            uVar8 = (uint)pbVar5 & 0xf;
            pbVar5 = (byte *)((uint)pbVar5 >> 4);
            param_3 = param_3 + 1;
            *(undefined *)pppbVar11 = PTR_s_0123456789ABCDEF_8009fe38[uVar8];
          } while (param_3 == (byte *)0x0);
        } while (pbVar5 != (byte *)0x0);
        if (bVar2) goto switchD_8005c2f0_caseD_59;
        if ((int)param_3 < iVar12) {
          do {
            pppbVar11 = (byte ***)((int)pppbVar11 + -1);
            param_3 = param_3 + 1;
            *(byte *)pppbVar11 = 0x30;
          } while ((int)param_3 < iVar12);
          bVar1 = false;
          goto switchD_8005c2f0_default;
        }
        break;
      case 0x59:
      case 0x5a:
      case 0x5b:
      case 0x5c:
      case 0x5d:
      case 0x5e:
      case 0x5f:
      case 0x60:
      case 0x61:
      case 0x62:
      case 0x65:
      case 0x66:
      case 0x67:
      case 0x68:
      case 0x69:
      case 0x6a:
      case 0x6b:
      case 0x6c:
      case 0x6d:
      case 0x6e:
      case 0x6f:
      case 0x70:
      case 0x71:
      case 0x72:
      case 0x74:
      case 0x75:
      case 0x76:
      case 0x77:
        goto switchD_8005c2f0_caseD_59;
      case 99:
        local_28[0] = ppbVar3 + 1;
        local_29 = *(undefined1 *)ppbVar3;
        pppbVar11 = (byte ***)&local_29;
        param_3 = (byte *)0x1;
        goto switchD_8005c2f0_caseD_59;
      case 100:
        local_28[0] = ppbVar3 + 1;
        pbVar5 = *ppbVar3;
        bVar7 = 0;
        if ((int)pbVar5 < 0) {
          pbVar5 = (byte *)-(int)pbVar5;
          bVar7 = 0x2d;
        }
        param_3 = (byte *)0x0;
        do {
          do {
            pppbVar10 = pppbVar11;
            pbVar9 = param_3;
            pbVar14 = (byte *)((uint)pbVar5 / 10);
            pppbVar11 = (byte ***)((int)pppbVar10 + -1);
            param_3 = pbVar9 + 1;
            *(byte *)pppbVar11 = (char)((uint)pbVar5 % 10) + 0x30;
            pbVar5 = pbVar14;
          } while (param_3 == (byte *)0x0);
        } while (pbVar14 != (byte *)0x0);
        bVar1 = (int)param_3 < iVar12;
        if (bVar7 != 0) {
          pppbVar11 = (byte ***)((int)pppbVar10 + -2);
          *(byte *)pppbVar11 = bVar7;
          param_3 = pbVar9 + 2;
          goto switchD_8005c2f0_caseD_59;
        }
      default:
switchD_8005c2f0_default:
        while (bVar1) {
          iVar6 = *(int *)(&DAT_8009e22c + iVar4);
          *(int *)(&DAT_8009e22c + iVar4) = iVar6 + 1;
          *(undefined1 *)(*(int *)(&DAT_8009e228 + iVar4) + iVar6) = 0x20;
          iVar12 = iVar12 + -1;
          if (*(int *)(&DAT_8009e220 + iVar4) < *(int *)(&DAT_8009e22c + iVar4)) {
            return 0xffffffff;
          }
switchD_8005c2f0_caseD_59:
          bVar1 = (int)param_3 < iVar12;
        }
        break;
      case 0x73:
        local_28[0] = ppbVar3 + 1;
        pppbVar11 = (byte ***)*ppbVar3;
        param_3 = (byte *)FUN_80058624(pppbVar11);
        goto switchD_8005c2f0_caseD_59;
      }
      while (param_3 = param_3 + -1, param_3 != (byte *)0xffffffff) {
        iVar12 = *(int *)(&DAT_8009e22c + iVar4);
        *(int *)(&DAT_8009e22c + iVar4) = iVar12 + 1;
        *(byte *)(*(int *)(&DAT_8009e228 + iVar4) + iVar12) = *(byte *)pppbVar11;
        pppbVar11 = (byte ***)((int)pppbVar11 + 1);
        if (*(int *)(&DAT_8009e220 + iVar4) < *(int *)(&DAT_8009e22c + iVar4)) {
          return 0xffffffff;
        }
      }
    }
    else {
LAB_8005c244:
      iVar12 = *(int *)(&DAT_8009e22c + iVar4);
      *(int *)(&DAT_8009e22c + iVar4) = iVar12 + 1;
      *(byte *)(*(int *)(&DAT_8009e228 + iVar4) + iVar12) = bVar7;
      if (*(int *)(&DAT_8009e220 + iVar4) < *(int *)(&DAT_8009e22c + iVar4)) {
        return 0xffffffff;
      }
    }
    pbVar13 = pbVar13 + 1;
    bVar7 = *pbVar13;
    ppbVar3 = local_28[0];
  } while( true );
}



// ---- FUN_8005c510 @ 8005c510

uint FUN_8005c510(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = FUN_80059884();
  if (iVar1 == 0) {
    uVar3 = (param_1 & 3) << 7 | (param_2 & 3) << 5;
    uVar2 = (int)(param_4 & 0x100) >> 4;
  }
  else {
    uVar3 = (param_1 & 3) << 9 | (param_2 & 3) << 7;
    uVar2 = (int)(param_4 & 0x300) >> 3;
  }
  return uVar3 | uVar2 | (int)(param_3 & 0x3ff) >> 6;
}



// ---- FUN_8005c5a4 @ 8005c5a4

uint FUN_8005c5a4(int param_1,uint param_2)

{
  return (param_2 & 0x3ff) << 6 | param_1 >> 4 & 0x3fU;
}



// ---- FUN_8005c5bc @ 8005c5bc

void FUN_8005c5bc(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = FUN_80059884();
  if (iVar1 == 0) {
    iVar1 = (param_1 & 0x10) << 4;
    uVar2 = (param_1 & 0xffff) >> 7;
    uVar3 = (param_1 & 0xffff) >> 5;
  }
  else {
    iVar1 = (param_1 & 0x60) << 3;
    uVar2 = (param_1 & 0xffff) >> 9;
    uVar3 = (param_1 & 0xffff) >> 7;
  }
  (*(code *)PTR_FUN_8009fde8)
            (s_tpage____d__d__d__d__80029178,uVar2 & 3,uVar3 & 3,(param_1 & 0x1f) << 6,iVar1);
  return;
}



// ---- FUN_8005c64c @ 8005c64c

void FUN_8005c64c(uint param_1)

{
  (*(code *)PTR_FUN_8009fde8)
            (s_clut____d__d__80029190,(param_1 & 0x3f) << 4,(param_1 & 0xffff) >> 6);
  return;
}



// ---- FUN_8005c6c4 @ 8005c6c4

void FUN_8005c6c4(uint *param_1,uint *param_2)

{
  *param_2 = *param_2 & 0xff000000 | *param_1 & 0xffffff;
  *param_1 = *param_1 & 0xff000000 | (uint)param_2 & 0xffffff;
  return;
}



// ---- FUN_8005c73c @ 8005c73c

void FUN_8005c73c(uint *param_1,uint param_2)

{
  *param_1 = *param_1 & 0xff000000 | param_2 & 0xffffff;
  return;
}



// ---- FUN_8005c760 @ 8005c760

void FUN_8005c760(uint *param_1)

{
  *param_1 = *param_1 | 0xffffff;
  return;
}



// ---- FUN_8005c7a0 @ 8005c7a0

void FUN_8005c7a0(int param_1,int param_2)

{
  byte bVar1;
  
  if (param_2 == 0) {
    bVar1 = *(byte *)(param_1 + 7) & 0xfe;
  }
  else {
    bVar1 = *(byte *)(param_1 + 7) | 1;
  }
  *(byte *)(param_1 + 7) = bVar1;
  return;
}



// ---- FUN_8005c868 @ 8005c868

void FUN_8005c868(int param_1)

{
  *(undefined1 *)(param_1 + 3) = 3;
  *(undefined1 *)(param_1 + 7) = 0x74;
  return;
}



// ---- FUN_8005c8e0 @ 8005c8e0

void FUN_8005c8e0(int param_1)

{
  *(undefined1 *)(param_1 + 3) = 3;
  *(undefined1 *)(param_1 + 7) = 0x60;
  return;
}



// ---- FUN_8005c8f4 @ 8005c8f4

void FUN_8005c8f4(int param_1)

{
  *(undefined1 *)(param_1 + 3) = 3;
  *(undefined1 *)(param_1 + 7) = 2;
  return;
}



// ---- FUN_8005c9e4 @ 8005c9e4

void FUN_8005c9e4(short *param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  
  (*(code *)PTR_FUN_8009fde8)
            (s_clip___3d__3d____d__d__800291a0,(int)*param_1,(int)param_1[1],(int)param_1[2],
             (int)param_1[3]);
  (*(code *)PTR_FUN_8009fde8)(s_ofs___3d__3d__800291b8,(int)param_1[4],(int)param_1[5]);
  (*(code *)PTR_FUN_8009fde8)
            (s_tw___d__d____d__d__800291c8,(int)param_1[6],(int)param_1[7],(int)param_1[8],
             (int)param_1[9]);
  (*(code *)PTR_FUN_8009fde8)(s_dtd__d_800291e0,(char)param_1[0xb]);
  (*(code *)PTR_FUN_8009fde8)(s_dfe__d_800291ec,*(undefined1 *)((int)param_1 + 0x17));
  iVar3 = FUN_80059884();
  if (iVar3 == 0) {
    uVar1 = param_1[10];
    uVar4 = (uint)uVar1;
    iVar3 = (uVar4 & 0x10) << 4;
    uVar2 = uVar1 >> 7;
    uVar1 = uVar1 >> 5;
  }
  else {
    uVar1 = param_1[10];
    uVar4 = (uint)uVar1;
    iVar3 = (uVar4 & 0x60) << 3;
    uVar2 = uVar1 >> 9;
    uVar1 = uVar1 >> 7;
  }
  (*(code *)PTR_FUN_8009fde8)
            (s_tpage____d__d__d__d__80029178,uVar2 & 3,uVar1 & 3,(uVar4 & 0x1f) << 6,iVar3);
  return;
}



// ---- FUN_8005cb28 @ 8005cb28

void FUN_8005cb28(short *param_1)

{
  (*(code *)PTR_FUN_8009fde8)
            (s_disp___3d__3d____d__d__800291f8,(int)*param_1,(int)param_1[1],(int)param_1[2],
             (int)param_1[3]);
  (*(code *)PTR_FUN_8009fde8)
            (s_screen___3d__3d____d__d__80029214,(int)param_1[4],(int)param_1[5],(int)param_1[6],
             (int)param_1[7]);
  (*(code *)PTR_FUN_8009fde8)(s_isinter__d_80029230,(char)param_1[8]);
  (*(code *)PTR_FUN_8009fde8)(s_isrgb24__d_8002923c,*(undefined1 *)((int)param_1 + 0x11));
  return;
}



// ---- FUN_8005cbd8 @ 8005cbd8

undefined2
FUN_8005cbd8(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,int param_6,undefined2 param_7)

{
  undefined2 uVar1;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  
  local_20 = (undefined2)param_4;
  local_1e = (undefined2)param_5;
  local_1a = param_7;
  if (param_2 == 1) {
    local_1c = (undefined2)(param_6 / 2);
  }
  else if (param_2 < 2) {
    if (param_2 == 0) {
      if (param_6 < 0) {
        param_6 = param_6 + 3;
      }
      local_1c = (undefined2)(param_6 >> 2);
    }
  }
  else if (param_2 == 2) {
    local_1c = (undefined2)param_6;
  }
  FUN_8005997c(&local_20,param_1);
  uVar1 = FUN_8005c510(param_2,param_3,param_4,param_5);
  return uVar1;
}



// ---- FUN_8005ccc0 @ 8005ccc0

undefined2 FUN_8005ccc0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  
  local_18 = (undefined2)param_2;
  local_16 = (undefined2)param_3;
  local_14 = 0x100;
  local_12 = 1;
  FUN_8005997c(&local_18,param_1);
  uVar1 = FUN_8005c5a4(param_2,param_3);
  return uVar1;
}



// ---- FUN_8005cd24 @ 8005cd24

undefined2 *
FUN_8005cd24(undefined2 *param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
            int param_5)

{
  undefined2 uVar1;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  *(undefined1 *)((int)param_1 + 0x19) = 0;
  *(undefined1 *)(param_1 + 0xd) = 0;
  *(undefined1 *)((int)param_1 + 0x1b) = 0;
  *(undefined1 *)(param_1 + 0xb) = 1;
  param_1[4] = param_2;
  param_1[5] = param_3;
  param_1[3] = (short)param_5;
  *(bool *)((int)param_1 + 0x17) = param_5 != 0x1e0;
  uVar1 = FUN_8005c510(0,0,0x280,0);
  param_1[10] = uVar1;
  *(undefined1 *)(param_1 + 0xc) = 0;
  return param_1;
}



// ---- FUN_8005cdb0 @ 8005cdb0

void FUN_8005cdb0(undefined2 *param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
                 undefined2 param_5)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  *(undefined1 *)((int)param_1 + 0x11) = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  *(undefined1 *)((int)param_1 + 0x13) = 0;
  *(undefined1 *)(param_1 + 9) = 0;
  param_1[3] = param_5;
  return;
}



// ---- FUN_8005cdec @ 8005cdec

undefined * FUN_8005cdec(byte param_1)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)param_1;
  if (uVar3 == 2) {
    puVar1 = &DAT_8009fe84;
  }
  else {
    iVar2 = uVar3 - 0x20;
    if ((byte)(param_1 - 0x20) < 0x60) {
      if (iVar2 < 0) {
        iVar2 = uVar3 - 0x1d;
      }
      puVar1 = (&PTR_DAT_8009e2b4)[iVar2 >> 2];
    }
    else {
      puVar1 = &DAT_8009fe88;
    }
  }
  return puVar1;
}



// ---- FUN_8005ce58 @ 8005ce58

undefined1 FUN_8005ce58(byte param_1)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)param_1;
  if (uVar3 == 2) {
    uVar1 = 3;
  }
  else {
    iVar2 = uVar3 - 0x20;
    if ((byte)(param_1 - 0x20) < 0x60) {
      if (iVar2 < 0) {
        iVar2 = uVar3 - 0x1d;
      }
      uVar1 = (&DAT_8009e314)[iVar2 >> 2];
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



// ---- FUN_8005ceb4 @ 8005ceb4

void FUN_8005ceb4(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  while ((uVar1 & 0xffffff) != 0xffffff) {
    if (*(char *)((int)param_1 + 3) != '\0') {
      FUN_80059aec(param_1);
    }
    param_1 = (uint *)(*param_1 & 0xffffff | 0x80000000);
    uVar1 = *param_1;
  }
  if (*(char *)((int)param_1 + 3) != '\0') {
    FUN_80059aec(param_1);
  }
  return;
}



// ---- FUN_8005cf5c @ 8005cf5c

void FUN_8005cf5c(uint *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 1;
  (*(code *)PTR_FUN_8009fde8)(s_OTag__prim__5d__80029248,0);
  uVar2 = *param_1;
  while ((uVar2 & 0xffffff) != 0xffffff) {
    if (*(char *)((int)param_1 + 3) == '\0') {
      if (*(char *)((uVar2 & 0xffffff | 0x80000000) + 3) != '\0') {
        (*(code *)PTR_FUN_8009fde8)(s__5d__8009fe8c,iVar3);
      }
      iVar3 = iVar3 + 1;
    }
    else {
      FUN_8005d0a4(s_DumpOTage_80029258,param_1);
      uVar1 = FUN_8005cdec(*(undefined1 *)((int)param_1 + 7));
      (*(code *)PTR_FUN_8009fde8)(&DAT_8009fe94,uVar1);
    }
    param_1 = (uint *)(*param_1 & 0xffffff | 0x80000000);
    uVar2 = *param_1;
  }
  FUN_8005d0a4(s_DumpOTage_80029258,param_1);
  uVar1 = FUN_8005cdec(*(undefined1 *)((int)param_1 + 7));
  (*(code *)PTR_FUN_8009fde8)(&DAT_8009fe98,uVar1);
  return;
}



// ---- FUN_8005d0a4 @ 8005d0a4

undefined4 FUN_8005d0a4(undefined4 param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = FUN_8005ce58(*(undefined1 *)(param_2 + 7));
  uVar2 = 0;
  if (cVar1 != '\0') {
    if (cVar1 == *(char *)(param_2 + 3)) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_8005cdec(*(undefined1 *)(param_2 + 7));
      (*(code *)PTR_FUN_8009fde8)
                (s__s__bad_prim_addr__08X_type__s_l_80029264,param_1,param_2,uVar2,
                 *(undefined1 *)(param_2 + 3));
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}



// ---- FUN_8005d138 @ 8005d138

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8005d138(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
                 undefined2 param_5)

{
  FUN_8005d1ac(param_1,param_2,param_3,param_4,param_5);
  FUN_8005da58();
  _DAT_800a08d8 = 0;
  FUN_8005d348(param_1,param_2);
  FUN_8005d758();
  FUN_8005db08();
  return;
}



// ---- FUN_8005d1ac @ 8005d1ac

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8005d1ac(undefined2 param_1,undefined2 param_2,ushort param_3,undefined1 param_4,
                 undefined1 param_5)

{
  FUN_80059584(0);
  DAT_800a07ba = 0;
  DAT_800a07b8 = 0;
  DAT_800a07c2 = 0;
  DAT_800a07c0 = 0;
  DAT_800a07be = 0;
  DAT_800a07bc = 0;
  DAT_800a07c4 = 0;
  DAT_800a07c7 = 0;
  DAT_800a07c8 = 0;
  DAT_800a07c6 = param_4;
  FUN_80059bc8(&DAT_800a07b0);
  _DAT_800a0810 = 0;
  _DAT_800a0812 = 0;
  _DAT_800a0818 = 0;
  _DAT_800a081a = 0;
  _DAT_800a081c = 0;
  _DAT_800a081e = 0;
  DAT_800a0820 = (byte)param_3 & 1;
  _DAT_800a08e0 = param_3 & 4;
  DAT_800a0821 = param_5;
  _DAT_800a0814 = param_1;
  _DAT_800a0816 = param_2;
  FUN_80059ce8();
  return;
}



// ---- FUN_8005d2d0 @ 8005d2d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8005d2d0(undefined2 param_1,undefined2 param_2,ushort param_3,undefined1 param_4,
                 undefined1 param_5)

{
  DAT_800a07c4 = 0;
  DAT_800a07c7 = 0;
  DAT_800a07c8 = 0;
  DAT_800a0820 = (byte)param_3 & 1;
  _DAT_800a08e0 = param_3 & 4;
  DAT_800a0821 = param_5;
  DAT_800a07c6 = param_4;
  _DAT_800a0814 = param_1;
  _DAT_800a0816 = param_2;
  FUN_8005d348(param_1,param_2);
  return;
}



// ---- FUN_8005d348 @ 8005d348

/* WARNING: Removing unreachable block (ram,0x8005d39c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8005d348(ushort param_1,ushort param_2)

{
  _DAT_800a0848 = (uint)param_1;
  _DAT_800a0850 = (uint)param_2;
  if (_DAT_800a0848 == 0) {
    trap(0x1c00);
  }
  _DAT_800a085c = 0;
  _DAT_800a0864 = 0;
  _DAT_800a0874 = 0;
  _DAT_800a0870 = 0;
  _DAT_800a086c = 0;
  _DAT_800a0858 = 0x1000;
  _DAT_800a0860 = 0x1000;
  _DAT_800a0868 = CONCAT22(DAT_800a0868_2,0x1000);
  _DAT_800a08a0 = 0x1000;
  _DAT_800a08a4 = 0;
  _DAT_800a08ac = 0;
  _DAT_800a08b4 = 0;
  _DAT_800a08b0 = _DAT_800a0868;
  _DAT_800a08bc = 0;
  _DAT_800a08b8 = 0;
  DAT_800a0794 = 0;
  DAT_800a07a4 = 0;
  DAT_800a079c = 0;
  DAT_800a07ac = 0;
  DAT_800a07a8 = 0;
  DAT_800a07a0 = (uint)DAT_800a0868_2 << 0x10;
  DAT_800a0798 = 0;
  DAT_800a0790 = 0;
  _DAT_800a0828 = 0;
  _DAT_800a082c = 0;
  _DAT_800a0830 = 0;
  _DAT_800a083c = 0;
  _DAT_800a0838 = DAT_800a07a0;
  _DAT_800a0834 = 0;
  _DAT_800a0844 = 0;
  _DAT_800a0840 = 0;
  DAT_800a0278 = 0;
  DAT_800a027a = 0;
  DAT_800a0280 = 0;
  DAT_800a0282 = 0;
  DAT_800a078a = 0;
  DAT_800a0788 = 0;
  _DAT_800a08c2 = 0;
  _DAT_800a08a8 = ((_DAT_800a0850 << 0xe) / _DAT_800a0848) / 3 & 0xffff;
  _DAT_800a08c0 = 0;
  _DAT_800a08c4 = param_1;
  _DAT_800a08c6 = param_2;
  FUN_8005c8f4(&DAT_800a0120);
  FUN_8005c8f4(&DAT_800a0130);
  return;
}



// ---- FUN_8005d5a4 @ 8005d5a4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8005d5a4(undefined1 param_1,undefined1 param_2,undefined1 param_3,int param_4)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar4 = (uint)_DAT_800a08d8;
  (&DAT_800a0124)[(uint)_DAT_800a08d8 * 0x10] = param_1;
  uVar5 = (uint)_DAT_800a08d8;
  (&DAT_800a0125)[uVar4 * 0x10] = param_2;
  (&DAT_800a0126)[uVar5 * 0x10] = param_3;
  uVar3 = _DAT_800a0850;
  uVar4 = (uint)_DAT_800a08d8;
  iVar6 = uVar4 * 0x10;
  *(undefined2 *)(&DAT_800a0128 + iVar6) = (&DAT_800a0268)[uVar4];
  uVar2 = _DAT_800a0848;
  uVar1 = (&DAT_800a0270)[uVar4];
  *(undefined2 *)(&DAT_800a012e + iVar6) = uVar3;
  *(undefined2 *)(&DAT_800a012c + iVar6) = uVar2;
  *(undefined2 *)(&DAT_800a012a + iVar6) = uVar1;
  FUN_8005c6c4(*(undefined4 *)(param_4 + 0x10),&DAT_800a0120 + iVar6);
  return;
}



// ---- FUN_8005d698 @ 8005d698

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8005d698(short param_1,short param_2)

{
  if (_DAT_800a08e0 == 0) {
    FUN_8005ddec();
  }
  else {
    DAT_800a07b8 = param_1 + (&DAT_800a0268)[_DAT_800a08d8 == 0];
    DAT_800a07ba = param_2 + (&DAT_800a0270)[_DAT_800a08d8 == 0];
  }
  return;
}



// ---- FUN_8005d728 @ 8005d728

void FUN_8005d728(void)

{
  FUN_80058440(0xf2000001);
  return;
}



// ---- FUN_8005d758 @ 8005d758

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8005d758(void)

{
  DAT_800a07b2 = _DAT_800a08c2 + (&DAT_800a0270)[_DAT_800a08d8];
  DAT_800a07b0 = _DAT_800a08c0 + (&DAT_800a0268)[_DAT_800a08d8];
  DAT_800a07b6 = _DAT_800a08c6 + -1;
  DAT_800a07b4 = _DAT_800a08c4 + -1;
  FUN_80059bc8();
  return;
}



// ---- FUN_8005d898 @ 8005d898

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8005d898(void)

{
  DAT_800a0788 = (undefined2)(_DAT_800a0848 >> 1);
  DAT_800a078a = (undefined2)(_DAT_800a0850 >> 1);
  FUN_8005db08();
  _DAT_800a08c8 = 0;
  _DAT_800a08d0 = 10;
  _DAT_800a0898 = 0x3fff;
  return;
}



// ---- FUN_8005d908 @ 8005d908

void FUN_8005d908(void)

{
  FUN_800583a4(0xf2000001,0xffffffff,0x2000);
  FUN_80058478(0xf2000001);
  return;
}



// ---- FUN_8005d948 @ 8005d948

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8005d948(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  if (_DAT_800a08e0 == 0) {
    DAT_800a0278 = param_1;
    DAT_800a027a = param_3;
    DAT_800a0280 = param_2;
    DAT_800a0282 = param_4;
  }
  else {
    DAT_800a0278 = 0;
    DAT_800a027a = 0;
    DAT_800a0280 = 0;
    DAT_800a0282 = 0;
  }
  DAT_800a0268 = param_1;
  DAT_800a026a = param_3;
  DAT_800a0270 = param_2;
  DAT_800a0272 = param_4;
  FUN_8005d758();
  FUN_8005db08();
  return;
}



// ---- FUN_8005d9f8 @ 8005d9f8

void FUN_8005d9f8(int param_1)

{
  FUN_80059b70(*(undefined4 *)(param_1 + 0x10));
  return;
}



// ---- FUN_8005da28 @ 8005da28

void FUN_8005da28(void)

{
  FUN_800584e0(0xf2000001);
  return;
}



// ---- FUN_8005da58 @ 8005da58

void FUN_8005da58(void)

{
  FUN_8005df48();
  FUN_8005dd58(0,0,0);
  FUN_8005ddec(0,0);
  return;
}



// ---- FUN_8005da98 @ 8005da98

void FUN_8005da98(uint param_1,uint param_2,uint *param_3)

{
  param_3[2] = param_1 & 0xffff;
  param_3[3] = param_2 & 0xffff;
  param_3[4] = ((4 << (*param_3 & 0x1f)) + param_3[1]) - 4;
  FUN_80059ab4(param_3[1],1 << (*param_3 & 0x1f));
  return;
}



// ---- FUN_8005daf8 @ 8005daf8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 FUN_8005daf8(void)

{
  return _DAT_800a08d8;
}



// ---- FUN_8005db08 @ 8005db08

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8005db08(void)

{
  if (_DAT_800a08e0 == 0) {
    FUN_8005ddec((int)DAT_800a0788 + (uint)(ushort)(&DAT_800a0268)[_DAT_800a08d8 == 0],
                 (int)DAT_800a078a + (uint)(ushort)(&DAT_800a0270)[_DAT_800a08d8 == 0]);
  }
  else {
    DAT_800a07b8 = (undefined2)
                   ((int)DAT_800a0788 + (uint)(ushort)(&DAT_800a0268)[_DAT_800a08d8 == 0]);
    DAT_800a07ba = (undefined2)
                   ((int)DAT_800a078a + (uint)(ushort)(&DAT_800a0270)[_DAT_800a08d8 == 0]);
  }
  return;
}



// ---- FUN_8005dba8 @ 8005dba8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8005dba8(void)

{
  int iVar1;
  
  _DAT_800a0810 = (&DAT_800a0268)[_DAT_800a08d8];
  _DAT_800a0812 = (&DAT_800a0270)[_DAT_800a08d8];
  FUN_80059ce8();
  FUN_800598bc(1);
  _DAT_800a08d8 = (ushort)(_DAT_800a08d8 == 0);
  FUN_8005d758();
  FUN_8005db08();
  iVar1 = 0;
  do {
    *(undefined2 *)((int)&DAT_800a0288 + iVar1) = 0;
    iVar1 = iVar1 + 0x28;
  } while (iVar1 < 0x500);
  return;
}



// ---- FUN_8005dc68 @ 8005dc68

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8005dc68(undefined2 *param_1)

{
  _DAT_800a08c0 = *param_1;
  _DAT_800a08c2 = param_1[1];
  _DAT_800a08c4 = param_1[2];
  _DAT_800a08c6 = param_1[3];
  return;
}



// ---- FUN_8005dd58 @ 8005dd58

void FUN_8005dd58(int param_1,int param_2,int param_3)

{
  setCopControlWord(2,0xa800,param_1 << 4);
  setCopControlWord(2,0xb000,param_2 << 4);
  setCopControlWord(2,0xb800,param_3 << 4);
  return;
}



// ---- FUN_8005ddec @ 8005ddec

void FUN_8005ddec(int param_1,int param_2)

{
  setCopControlWord(2,0xc000,param_1 << 0x10);
  setCopControlWord(2,0xc800,param_2 << 0x10);
  return;
}



// ---- FUN_8005de04 @ 8005de04

void FUN_8005de04(undefined4 param_1)

{
  setCopControlWord(2,0xd000,param_1);
  return;
}



// ---- FUN_8005df48 @ 8005df48

uint FUN_8005df48(void)

{
  setCopReg(0,Status,Status | 0x40000000);
  setCopControlWord(2,0xe800,0x155);
  setCopControlWord(2,0xf000,0x100);
  setCopControlWord(2,0xd000,1000);
  setCopControlWord(2,0xd800,0xffffef9e);
  setCopControlWord(2,0xe000,0x1400000);
  setCopControlWord(2,0xc000,0);
  setCopControlWord(2,0xc800,0);
  return Status | 0x40000000;
}



// ---- FUN_8005e6a8 @ 8005e6a8

void FUN_8005e6a8(void)

{
  FUN_8005f7d0();
  return;
}



// ---- FUN_8005e6c8 @ 8005e6c8

void FUN_8005e6c8(void)

{
  FUN_8005f358();
  return;
}



// ---- FUN_8005e6e8 @ 8005e6e8

void FUN_8005e6e8(void)

{
  FUN_8005f408();
  return;
}



// ---- FUN_8005e708 @ 8005e708

void FUN_8005e708(void)

{
  FUN_8005f9f4();
  return;
}



// ---- FUN_8005e7b0 @ 8005e7b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8005e7b0(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = _DAT_800aee90;
  _DAT_800aee90 = param_1;
  return uVar1;
}



// ---- FUN_8005e7c8 @ 8005e7c8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8005e7c8(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = _DAT_800b04a4;
  _DAT_800b04a4 = param_1;
  return uVar1;
}



// ---- FUN_8005e7e0 @ 8005e7e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8005e7e0(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = _DAT_800addb8;
  _DAT_800addb8 = param_1;
  return uVar1;
}



// ---- FUN_8005e7f8 @ 8005e7f8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8005e7f8(byte param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = _DAT_800aee90;
  iVar3 = 3;
  do {
    _DAT_800aee90 = 0;
    if (DAT_8009feac == 0) {
      if ((((param_2 == 0) || (*(int *)(&DAT_8009f04c + (uint)param_1 * 4) == 0)) ||
          (iVar2 = FUN_8005f494(2,param_2,param_3,0), iVar2 == 0)) &&
         (_DAT_800aee90 = uVar1, iVar2 = FUN_8005f494(param_1,param_2,param_3,param_4), iVar2 == 0))
      {
        return 0;
      }
    }
    else {
      FUN_8005f494(1,0,0,0);
    }
    iVar3 = iVar3 + -1;
    if (iVar3 == -1) {
      _DAT_800aee90 = uVar1;
      return 0xffffffff;
    }
  } while( true );
}



// ---- FUN_8005e918 @ 8005e918

bool FUN_8005e918(undefined1 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_8005e7f8(param_1,param_2,param_3,0);
  return iVar1 == 0;
}



// ---- FUN_8005e93c @ 8005e93c

bool FUN_8005e93c(undefined1 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_8005e7f8(param_1,param_2,0,1);
  return iVar1 == 0;
}



// ---- FUN_8005e964 @ 8005e964

bool FUN_8005e964(undefined1 param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_8005e7f8(param_1,param_2,param_3,0);
  if (iVar2 == 0) {
    iVar2 = FUN_8005f358(0,param_3);
    bVar1 = iVar2 == 2;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}



// ---- FUN_8005e9b0 @ 8005e9b0

bool FUN_8005e9b0(void)

{
  int iVar1;
  
  iVar1 = FUN_8005fbcc();
  return iVar1 == 0;
}



// ---- FUN_8005e9d0 @ 8005e9d0

undefined4 FUN_8005e9d0(undefined4 param_1,undefined4 param_2,byte param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  byte local_20 [8];
  
  iVar2 = 4;
  local_20[0] = param_3;
  if ((param_3 & 0x30) == 0) {
    uVar3 = 0x200;
  }
  else {
    uVar3 = 0x249;
    if ((param_3 & 0x30) != 0x20) {
      uVar3 = 0x246;
    }
  }
  do {
    while( true ) {
      iVar2 = iVar2 + -1;
      if (iVar2 == -1) {
        return 0;
      }
      if (DAT_8009feac == 0) break;
      FUN_8005f494(1,0,0,0);
    }
    iVar1 = FUN_8005f494(0xe,local_20,0,0);
  } while ((iVar1 != 0) || (iVar1 = FUN_8005f8d0(param_2,param_1,uVar3), iVar1 != 0));
  return 1;
}



// ---- FUN_8005eaa4 @ 8005eaa4

undefined4 FUN_8005eaa4(void)

{
  FUN_8005f720();
  return 1;
}



// ---- FUN_8005eac4 @ 8005eac4

void FUN_8005eac4(uint param_1)

{
  undefined4 uVar1;
  undefined1 local_10 [8];
  
  local_10[0] = (undefined1)param_1;
  FUN_8005e918(0xe,local_10,0);
  uVar1 = 6;
  if ((param_1 & 0x100) != 0) {
    FUN_800619fc(FUN_8005ff7c);
    FUN_8005e7c8(FUN_80060294);
    uVar1 = 0x1b;
  }
  FUN_8005e918(uVar1,0,0);
  return;
}



// ---- FUN_8005eb34 @ 8005eb34

/* WARNING: Removing unreachable block (ram,0x8005ec14) */
/* WARNING: Removing unreachable block (ram,0x8005ebe4) */
/* WARNING: Removing unreachable block (ram,0x8005ebb4) */
/* WARNING: Removing unreachable block (ram,0x8005eb80) */
/* WARNING: Removing unreachable block (ram,0x8005eb4c) */
/* WARNING: Removing unreachable block (ram,0x8005eb5c) */
/* WARNING: Removing unreachable block (ram,0x8005eb64) */
/* WARNING: Removing unreachable block (ram,0x8005eb90) */
/* WARNING: Removing unreachable block (ram,0x8005eb98) */
/* WARNING: Removing unreachable block (ram,0x8005ebc4) */
/* WARNING: Removing unreachable block (ram,0x8005ebcc) */
/* WARNING: Removing unreachable block (ram,0x8005ebf4) */
/* WARNING: Removing unreachable block (ram,0x8005ebfc) */
/* WARNING: Removing unreachable block (ram,0x8005ec24) */
/* WARNING: Removing unreachable block (ram,0x8005ec2c) */

void FUN_8005eb34(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = (param_1 + 0x96) / 0x4b;
  iVar3 = (param_1 + 0x96) % 0x4b;
  iVar2 = iVar1 / 0x3c;
  iVar1 = iVar1 % 0x3c;
  param_2[2] = (char)(iVar3 / 10) * '\x10' + (char)(iVar3 % 10);
  param_2[1] = (char)(iVar1 / 10) * '\x10' + (char)(iVar1 % 10);
  *param_2 = (char)(iVar2 / 10) * '\x10' + (char)(iVar2 % 10);
  return;
}



// ---- FUN_8005ec60 @ 8005ec60

/* WARNING: Removing unreachable block (ram,0x8005eca4) */
/* WARNING: Removing unreachable block (ram,0x8005ec70) */
/* WARNING: Removing unreachable block (ram,0x8005ece0) */

int FUN_8005ec60(byte *param_1)

{
  return ((((int)(uint)*param_1 >> 4) * 10 + (*param_1 & 0xf)) * 0x3c +
         ((int)(uint)param_1[1] >> 4) * 10 + (param_1[1] & 0xf)) * 0x4b +
         ((int)(uint)param_1[2] >> 4) * 10 + (param_1[2] & 0xf) + -0x96;
}



// ---- FUN_8005ed08 @ 8005ed08

void FUN_8005ed08(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  int iVar2;
  
  if (param_1 != (undefined1 *)0x0) {
    iVar2 = 7;
    do {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      iVar2 = iVar2 + -1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    } while (iVar2 != -1);
  }
  return;
}



// ---- FUN_8005ed38 @ 8005ed38

void FUN_8005ed38(void)

{
  DAT_800a0178 = DAT_8009ffd8 + 0x1e0;
  return;
}



// ---- FUN_8005ed58 @ 8005ed58

undefined4 FUN_8005ed58(void)

{
  undefined4 uVar1;
  
  if (DAT_800a0178 < DAT_8009ffd8) {
    FUN_80058614(s__s__timeout_Sync__s__Ready__s_800293bc,(&PTR_s_CdlSync_8009f0cc)[DAT_8009ff1c],
                 (&PTR_s_NoIntr_8009f140)[DAT_8009ff20],(&PTR_s_NoIntr_8009f140)[DAT_8009ff24]);
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



// ---- FUN_8005edf0 @ 8005edf0

void FUN_8005edf0(void)

{
  int iVar1;
  
  iVar1 = FUN_80061d34();
  if (iVar1 != 0) {
    FUN_8005ef94();
  }
  if ((DAT_8009ff20 == 5) && (0 < DAT_8009fea8)) {
    FUN_80058614(s__s__DiskError__02x__800293dc,(&PTR_s_CdlSync_8009f0cc)[DAT_8009ff1c],DAT_800a0168
                );
  }
  if ((DAT_8009ff24 == 5) && (0 < DAT_8009fea8)) {
    FUN_80058614(s_Ready_DiskError__02x__800293f4,DAT_800a0170);
  }
  return;
}



// ---- FUN_8005eec4 @ 8005eec4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8005eec4(void)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = *DAT_8009ff08;
  while( true ) {
    uVar2 = FUN_8005ef94();
    if (uVar2 == 0) break;
    if (((uVar2 & 4) != 0) && (_DAT_800b04a4 != (code *)0x0)) {
      (*_DAT_800b04a4)(DAT_8009ff24,&DAT_800a0170);
    }
    if (((uVar2 & 2) != 0) && (_DAT_800aee90 != (code *)0x0)) {
      (*_DAT_800aee90)(DAT_8009ff20,&DAT_800a0168);
    }
  }
  *DAT_8009ff08 = bVar1 & 3;
  return;
}



// ---- FUN_8005ef94 @ 8005ef94

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8005ef94(void)

{
  byte bVar1;
  
  *DAT_8009ff08 = 1;
  _DAT_800a0150 = *DAT_8009ff14 & 7;
  if ((*DAT_8009ff14 & 7) == 0) {
    return 0;
  }
  DAT_800a0158 = 0;
  bVar1 = *DAT_8009ff08;
  while ((bVar1 & 0x20) != 0) {
    (&DAT_800a0140)[DAT_800a0158] = *DAT_8009ff0c;
    DAT_800a0158 = DAT_800a0158 + 1;
    if (7 < DAT_800a0158) goto LAB_8005f0b0;
    bVar1 = *DAT_8009ff08;
  }
  for (; DAT_800a0158 < 8; DAT_800a0158 = DAT_800a0158 + 1) {
    (&DAT_800a0140)[DAT_800a0158] = 0;
  }
LAB_8005f0b0:
  *DAT_8009ff08 = 1;
  *DAT_8009ff14 = 7;
  *DAT_8009ff10 = 7;
  DAT_800a0160 = 0;
  if (*(int *)(&DAT_8009f260 + (uint)DAT_8009ff1c * 4) != 0) {
    DAT_800a0160 = (uint)((DAT_800a0140 & 0x1c) != 0);
  }
  DAT_8009feac = 0;
  if (*(int *)(&DAT_8009f260 + (uint)DAT_8009ff1c * 4) != 0) {
    DAT_8009feac = (uint)((DAT_800a0140 & 0x10) != 0);
  }
  DAT_800a0148 = DAT_800a0150;
  switch(_DAT_800a0150 & 0xff) {
  case 1:
    DAT_8009ff24 = 1;
    break;
  case 2:
    DAT_8009ff20 = 2;
    if (DAT_800a0160 != 0) {
      DAT_8009ff20 = 5;
    }
    goto LAB_8005f268;
  case 3:
    if (DAT_800a0160 == 0) {
      if ((DAT_8009ff20 == 0) && (*(int *)(&DAT_8009f160 + (uint)DAT_8009ff1c * 4) != 0)) {
        DAT_8009ff20 = 3;
        FUN_8005ed08(&DAT_800a0168,&DAT_800a0140);
        return 1;
      }
      DAT_8009ff20 = 2;
    }
    else {
      DAT_8009ff20 = 5;
    }
LAB_8005f268:
    FUN_8005ed08(&DAT_800a0168,&DAT_800a0140);
    return 2;
  case 4:
    DAT_8009ff24 = 4;
    break;
  case 5:
    DAT_8009ff24 = 5;
    DAT_8009ff20 = 5;
    FUN_8005ed08(&DAT_800a0168,&DAT_800a0140);
    FUN_8005ed08(&DAT_800a0170,&DAT_800a0140);
    return 6;
  default:
    FUN_80058614(s_CDROM__unknown_intr__d__8002940c,_DAT_800a0150);
    return 0xffffffff;
  }
  if (DAT_800a0160 != 0) {
    DAT_8009ff24 = 5;
  }
  FUN_8005ed08(&DAT_800a0170,&DAT_800a0140);
  return 4;
}



// ---- FUN_8005f358 @ 8005f358

int FUN_8005f358(int param_1,undefined4 param_2)

{
  int iVar1;
  
  FUN_8005ed38();
  while( true ) {
    iVar1 = FUN_8005ed58();
    if (iVar1 != 0) {
      return -1;
    }
    FUN_8005edf0();
    if ((DAT_8009ff20 == 2) || (DAT_8009ff20 == 5)) break;
    if (param_1 != 0) {
      return 0;
    }
  }
  FUN_8005ed08(param_2,&DAT_800a0168);
  return DAT_8009ff20;
}



// ---- FUN_8005f408 @ 8005f408

int FUN_8005f408(int param_1,undefined4 param_2)

{
  int iVar1;
  
  FUN_8005ed38();
  while( true ) {
    iVar1 = FUN_8005ed58();
    if (iVar1 != 0) {
      return -1;
    }
    FUN_8005edf0();
    iVar1 = DAT_8009ff24;
    if (DAT_8009ff24 != 0) break;
    if (param_1 != 0) {
      return 0;
    }
  }
  DAT_8009ff24 = 0;
  FUN_8005ed08(param_2,&DAT_800a0170);
  return iVar1;
}



// ---- FUN_8005f494 @ 8005f494

int FUN_8005f494(byte param_1,undefined1 *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  FUN_8005ed38();
  while ((DAT_8009ff20 != 2 && (DAT_8009ff20 != 5))) {
    iVar1 = FUN_8005ed58();
    if (iVar1 != 0) {
      return -1;
    }
    FUN_8005edf0();
  }
  if (1 < DAT_8009fea8) {
    FUN_80058614(s__s____8009ff28,(&PTR_s_CdlSync_8009f0cc)[param_1]);
  }
  if ((*(int *)(&DAT_8009f2e0 + (uint)param_1 * 4) == 0) || (param_2 != (undefined1 *)0x0)) {
    DAT_8009ff20 = 0;
    if (*(int *)(&DAT_8009f1e0 + (uint)param_1 * 4) != 0) {
      DAT_8009ff24 = 0;
    }
    *DAT_8009ff08 = 0;
    iVar1 = 0;
    if (0 < *(int *)(&DAT_8009f2e0 + (uint)param_1 * 4)) {
      do {
        *DAT_8009ff10 = *param_2;
        iVar1 = iVar1 + 1;
        param_2 = param_2 + 1;
      } while (iVar1 < *(int *)(&DAT_8009f2e0 + (uint)param_1 * 4));
    }
    DAT_8009ff1c = param_1;
    *DAT_8009ff0c = param_1;
    iVar1 = 0;
    if (param_4 == 0) {
      FUN_8005ed38();
      while (DAT_8009ff20 == 0) {
        iVar1 = FUN_8005ed58();
        if (iVar1 != 0) {
          return -1;
        }
        FUN_8005edf0();
      }
      FUN_8005ed08(param_3,&DAT_800a0168);
      iVar1 = -(uint)(DAT_8009ff20 == 5);
    }
  }
  else {
    iVar1 = 2;
    if (0 < DAT_8009fea8) {
      FUN_80058614(s__s__no_param_80029440,(&PTR_s_CdlSync_8009f0cc)[param_1]);
      iVar1 = 2;
    }
  }
  return iVar1;
}



// ---- FUN_8005f720 @ 8005f720

undefined4 FUN_8005f720(undefined1 *param_1)

{
  FUN_8005f358(0,0);
  *DAT_8009ff08 = 2;
  *DAT_8009ff10 = *param_1;
  *DAT_8009ff14 = param_1[1];
  *DAT_8009ff08 = 3;
  *DAT_8009ff0c = param_1[2];
  *DAT_8009ff10 = param_1[3];
  *DAT_8009ff14 = 0x20;
  return 0;
}



// ---- FUN_8005f7d0 @ 8005f7d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8005f7d0(void)

{
  int iVar1;
  int iVar2;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  
  DAT_8009ff20 = 2;
  DAT_8009ff24 = 0;
  _DAT_800b04a4 = 0;
  _DAT_800aee90 = 0;
  FUN_80061c44();
  FUN_80061c74(2,FUN_8005eec4);
  iVar2 = DAT_8009ff18;
  if ((*(short *)(DAT_8009ff18 + 0x1b8) == 0) && (*(short *)(DAT_8009ff18 + 0x1ba) == 0)) {
    *(undefined2 *)(DAT_8009ff18 + 0x180) = 0x3fff;
    *(undefined2 *)(iVar2 + 0x182) = 0x3fff;
  }
  iVar2 = DAT_8009ff18;
  *(undefined2 *)(DAT_8009ff18 + 0x1b0) = 0x3fff;
  *(undefined2 *)(iVar2 + 0x1b2) = 0x3fff;
  *(undefined2 *)(iVar2 + 0x1aa) = 0xc001;
  local_e = 0x80;
  local_10 = 0x80;
  local_d = 0;
  local_f = 0;
  iVar1 = FUN_8005f720(&local_10);
  iVar2 = -1;
  if (iVar1 == 0) {
    iVar1 = FUN_8005f494(10,0,0,0);
    iVar2 = -1;
    if (iVar1 == 0) {
      iVar2 = FUN_8005f358(0,0);
      iVar2 = -(uint)(iVar2 != 2);
    }
  }
  return iVar2;
}



// ---- FUN_8005f8d0 @ 8005f8d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8005f8d0(undefined4 param_1,int param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_10 [8];
  
  _DAT_800a8948 = param_1;
  _DAT_800a894c = param_3;
  _DAT_800a8950 = param_2;
  FUN_8005ed38();
  do {
    iVar2 = FUN_8005f408(1,auStack_10);
    pcVar1 = _DAT_800b04a4;
    if (iVar2 == 0) {
      _DAT_800b04a4 = FUN_8005fab0;
      _DAT_800a8958 = pcVar1;
      iVar2 = FUN_8005f494(6,0,auStack_10,0);
      if (iVar2 == 0) {
        _DAT_800a8954 = param_2 + 0x1e0 + DAT_8009ffd8;
        return 0;
      }
      break;
    }
    iVar2 = FUN_8005ed58();
  } while (iVar2 == 0);
  if (_DAT_800addb8 != (code *)0x0) {
    (*_DAT_800addb8)(5,auStack_10);
  }
  _DAT_800a8950 = 0xffffffff;
  _DAT_800b04a4 = _DAT_800a8958;
  FUN_8005f494(8,0,0,0);
  return 0xffffffff;
}



// ---- FUN_8005f9f4 @ 8005f9f4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8005f9f4(int param_1,undefined4 param_2)

{
  do {
    FUN_8005ed08(param_2,&DAT_800a0170);
    if (((_DAT_800a8954 < DAT_8009ffd8) || (DAT_8009ff24 == 5)) || (DAT_8009ff24 == 4)) {
      _DAT_800a8950 = -1;
    }
  } while ((param_1 == 0) && (0 < _DAT_800a8950));
  return _DAT_800a8950;
}



// ---- FUN_8005fab0 @ 8005fab0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8005fab0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 1) {
    if (0 < _DAT_800a8950) {
      FUN_8005fbcc(_DAT_800a8948,_DAT_800a894c);
      _DAT_800a8948 = _DAT_800a894c * 4 + _DAT_800a8948;
      _DAT_800a8950 = _DAT_800a8950 + -1;
    }
  }
  else {
    _DAT_800a8950 = -1;
  }
  if (_DAT_800a8950 < 1) {
    if (_DAT_800addb8 != (code *)0x0) {
      (*_DAT_800addb8)(5,param_2);
    }
    uVar1 = 8;
    if (_DAT_800a8950 == 0) {
      uVar1 = 9;
    }
    FUN_8005f494(uVar1,0,0,0);
    _DAT_800b04a4 = _DAT_800a8958;
  }
  return;
}



// ---- FUN_8005fbcc @ 8005fbcc

undefined4 FUN_8005fbcc(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  FUN_8005ed38();
  uVar1 = *DAT_8009ff44;
  while( true ) {
    if ((uVar1 & 0x1000000) == 0) {
      *DAT_8009ff08 = 0;
      *DAT_8009ff14 = 0x80;
      *DAT_8009ff30 = 0x20943;
      *DAT_8009ff34 = 0x132c;
      *DAT_8009ff38 = *DAT_8009ff38 | 0x8000;
      *DAT_8009ff44 = 0;
      *DAT_8009ff3c = param_1;
      *DAT_8009ff40 = param_2 | 0x10000;
      *DAT_8009ff44 = 0x11000000;
      return 0;
    }
    iVar2 = FUN_8005ed58();
    if (iVar2 != 0) break;
    uVar1 = *DAT_8009ff44;
  }
  return 0xffffffff;
}



// ---- FUN_8005fd10 @ 8005fd10

void FUN_8005fd10(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 4;
  do {
    iVar1 = FUN_8005f7d0();
    iVar2 = iVar2 + -1;
    if (iVar1 == 0) {
      FUN_8005e7b0(FUN_8005fe14);
      FUN_8005e7c8(FUN_8005fe3c);
      FUN_8005e7e0(FUN_8005fe64);
      return;
    }
  } while (iVar2 != -1);
  FUN_80058614(s_CdInit__Init_failed_80029450);
  return;
}



// ---- FUN_8005fd9c @ 8005fd9c

void FUN_8005fd9c(void)

{
  FUN_80060e30();
  FUN_80062390(0);
  FUN_8005f7d0();
  FUN_80062390(0);
  FUN_8005e7b0(FUN_8005fe14);
  FUN_80062390(0);
  FUN_8005e7c8(FUN_8005fe3c);
  FUN_80062390(0);
  FUN_8005e7e0(FUN_8005fe64);
  return;
}



// ---- FUN_8005fe14 @ 8005fe14

void FUN_8005fe14(void)

{
  FUN_8005fe8c(0xf0000003,0x20);
  return;
}



// ---- FUN_8005fe3c @ 8005fe3c

void FUN_8005fe3c(void)

{
  FUN_8005fe8c(0xf0000003,0x40);
  return;
}



// ---- FUN_8005fe64 @ 8005fe64

void FUN_8005fe64(void)

{
  FUN_8005fe8c(0xf0000003,0x40);
  return;
}



// ---- FUN_8005fe8c @ 8005fe8c

void FUN_8005fe8c(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_8005fe9c @ 8005fe9c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8005fe9c(undefined4 param_1,undefined4 param_2)

{
  DAT_800a01c0 = 0;
  DAT_800a01b8 = 0;
  DAT_800a01b0 = 0;
  _DAT_800ab5b0 = 0;
  DAT_800a01a8 = param_2;
  _DAT_800ac940 = param_1;
  FUN_80060184(0);
  _DAT_800ab698 = 0;
  return;
}



// ---- FUN_8005fef4 @ 8005fef4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8005fef4(void)

{
  DAT_800a01c0 = 0;
  DAT_800a01b8 = 0;
  DAT_800a01b0 = 0;
  _DAT_800ab5b0 = 0;
  FUN_80060184(0,DAT_800a01a8);
  _DAT_800ab698 = 0;
  return;
}



// ---- FUN_8005ff44 @ 8005ff44

void FUN_8005ff44(void)

{
  FUN_80058314();
  FUN_800619fc(0);
  FUN_8005e7c8(0);
  FUN_800585a4();
  return;
}



// ---- FUN_8005ff7c @ 8005ff7c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8005ff7c(void)

{
  *(undefined2 *)(DAT_800a01b8 * 0x20 + _DAT_800ac940) = 2;
  _DAT_800ab5b0 = 0;
  DAT_800a01b8 = DAT_800a01b0;
  if (DAT_800a01e0 != (code *)0x0) {
    (*DAT_800a01e0)();
  }
  return;
}



// ---- FUN_8005ffe4 @ 8005ffe4

void FUN_8005ffe4(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_80060274(1);
  DAT_800a0190 = 0;
  DAT_800a01e0 = param_4;
  DAT_800a0188 = param_1 & 1;
  DAT_800a01e8 = param_5;
  return;
}



// ---- FUN_80060048 @ 80060048

void FUN_80060048(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_80060274(1,param_3,param_4);
  DAT_800a0190 = param_1;
  DAT_800a0198 = 0;
  DAT_800a0188 = 0;
  DAT_800a01e0 = param_5;
  DAT_800a01e8 = param_6;
  return;
}



// ---- FUN_800600b8 @ 800600b8

/* WARNING: Removing unreachable block (ram,0x800600e8) */
/* WARNING: Removing unreachable block (ram,0x800600f8) */
/* WARNING: Removing unreachable block (ram,0x80060100) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800600b8(int param_1)

{
  short *psVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = (param_1 - (DAT_800a01a8 * 0x20 + _DAT_800ac940) >> 2) / 0x1f8;
  psVar1 = (short *)(iVar6 * 0x20 + _DAT_800ac940);
  if (*psVar1 == 4) {
    iVar3 = (int)psVar1[3];
    iVar5 = 0;
    if (0 < iVar3) {
      iVar4 = iVar6;
      do {
        iVar5 = iVar5 + 1;
        *(undefined2 *)(iVar4 * 0x20 + _DAT_800ac940) = 0;
        iVar4 = iVar5 + iVar6;
      } while (iVar5 < iVar3);
    }
    DAT_800a01c0 = iVar5 + iVar6;
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



// ---- FUN_80060184 @ 80060184

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80060184(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      iVar1 = uVar2 + param_1;
      uVar2 = uVar2 + 1;
      *(undefined4 *)(iVar1 * 0x20 + _DAT_800ac940) = 0;
    } while (uVar2 < param_2);
  }
  return;
}



// ---- FUN_800601c0 @ 800601c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_800601c0(int *param_1,undefined4 *param_2)

{
  short sVar1;
  short *psVar2;
  
  psVar2 = (short *)(DAT_800a01c0 * 0x20 + _DAT_800ac940);
  if (*psVar2 == 1) {
    DAT_800a01c0 = 0;
    *psVar2 = 0;
    psVar2 = (short *)(DAT_800a01c0 * 0x20 + _DAT_800ac940);
  }
  sVar1 = *psVar2;
  if (sVar1 == 2) {
    *psVar2 = 4;
    *param_1 = DAT_800a01a8 * 0x20 + _DAT_800ac940 + DAT_800a01c0 * 0x7e0;
    *param_2 = psVar2;
  }
  return sVar1 != 2;
}



// ---- FUN_80060274 @ 80060274

void FUN_80060274(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  DAT_800a01c8 = param_1;
  DAT_800a01d0 = param_2;
  DAT_800a01d8 = param_3;
  return;
}



// ---- FUN_80060294 @ 80060294

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80060294(void)

{
  undefined4 uVar1;
  short *psVar2;
  uint uVar3;
  byte local_10 [8];
  
  if ((DAT_800a0188 == 0) || ((*DAT_8009ff68 & 0x1000000) == 0)) {
    *DAT_8009ff48 = 0;
    *DAT_8009ff54 = 0;
    FUN_8005e6e8(1,local_10);
    if ((local_10[0] & 4) == 0) {
      if (_DAT_800ab5b0 == 1) {
        if (DAT_800a0190 != 0) {
          DAT_800a0198 = DAT_800a0198 + 1;
        }
        DAT_8009ffa8 = 0xb;
        FUN_80058614(s_Final_Sector_is_on__08x__08x__08_80029468,*DAT_8009ff78,*DAT_8009ff60,
                     *DAT_8009ff64,*DAT_8009ff8c,*DAT_8009ff90);
      }
      else {
        DAT_800a0180 = _DAT_800ac940 + DAT_800a01b0 * 0x10;
        if (*DAT_800a0180 == 0) {
          *DAT_8009ff48 = 0;
          *DAT_8009ff54 = 0x80;
          *DAT_8009ff58 = 0x20943;
          *DAT_8009ff5c = 0x1323;
          if (DAT_800a0190 == 0) {
            FUN_80060c48(3,DAT_800a0180,0,8,0x11000000,0,0);
          }
          else {
            FUN_80060dd4(DAT_800a0180,DAT_800a0198 * 0x800 + DAT_800a0190,8,0);
          }
          do {
          } while ((*DAT_8009ff78 & 0x1000000) != 0);
          *DAT_8009ff58 = 0x20843;
          *DAT_8009ff5c = 0x1325;
          if ((DAT_800a01c8 == 1) && (DAT_800a01d0 != 0)) {
            if (DAT_800a01d0 != (ushort)DAT_800a0180[4]) {
              *DAT_800a0180 = 0;
              if (DAT_800a0190 == 0) {
                return;
              }
              DAT_800a0198 = DAT_800a0198 + 1;
              return;
            }
            DAT_800a01c8 = 0;
          }
          if ((*DAT_800a0180 == 0x160) && (((ushort)DAT_800a0180[1] >> 10 & 0x1f) == DAT_8009ffa4))
          {
            if (((int)DAT_8009ffac == (uint)(ushort)DAT_800a0180[2]) &&
               ((DAT_8009ff9c == 0 || (DAT_8009ff9c == (ushort)DAT_800a0180[4])))) {
              if (DAT_800a0180[2] == 0) {
                DAT_8009ff9c = (uint)(ushort)DAT_800a0180[4];
                DAT_8009ffac = 0;
                if ((DAT_800a01d8 != 0) && (DAT_800a01d8 <= DAT_8009ff9c)) {
                  DAT_8009ff9c = 0;
                  DAT_8009ffac = 0;
                  FUN_80060184(DAT_800a01b8,DAT_800a01b0 - DAT_800a01b8);
                  DAT_800a01b0 = DAT_800a01b8;
                  *DAT_800a0180 = 0;
                  DAT_800a01c8 = 1;
                  if (DAT_800a01e8 != (code *)0x0) {
                    (*DAT_800a01e8)();
                  }
                  if (DAT_800a0190 != 0) {
                    DAT_800a0198 = DAT_800a0198 + 1;
                  }
                  DAT_8009ffa8 = 7;
                  return;
                }
                if ((DAT_800a01a8 - DAT_800a01b0) - 1U < (uint)(ushort)DAT_800a0180[3]) {
                  if (DAT_800a01d8 == 0) {
                    *DAT_800a0180 = 1;
                    DAT_800a01c8 = 1;
                    if (DAT_800a01e8 != (code *)0x0) {
                      (*DAT_800a01e8)();
                    }
                    if (DAT_800a0190 != 0) {
                      DAT_800a0198 = DAT_800a0198 + 1;
                    }
                    DAT_8009ffa8 = 8;
                    return;
                  }
                  if (*_DAT_800ac940 != 0) {
                    *DAT_800a0180 = 0;
                    if (DAT_800a0190 != 0) {
                      DAT_800a0198 = DAT_800a0198 + 1;
                    }
                    DAT_8009ffa8 = 9;
                    return;
                  }
                  *DAT_800a0180 = 1;
                  DAT_800a01b0 = 0;
                  uVar3 = 0;
                  psVar2 = _DAT_800ac940;
                  do {
                    uVar1 = *(undefined4 *)DAT_800a0180;
                    DAT_800a0180 = DAT_800a0180 + 2;
                    uVar3 = uVar3 + 1;
                    *(undefined4 *)psVar2 = uVar1;
                    psVar2 = psVar2 + 2;
                  } while (uVar3 < 8);
                  DAT_800a0180 = _DAT_800ac940;
                }
                DAT_800a01b8 = DAT_800a01b0;
              }
              DAT_8009ffa8 = 10;
              DAT_8009ffac = DAT_8009ffac + 1;
              _DAT_800ac938 = _DAT_800ac940 + DAT_800a01a8 * 0x10 + DAT_800a01b0 * 0x3f0;
              if (DAT_800a0188 == 0) {
                uVar1 = 0x11400100;
                *DAT_8009ff58 = 0x21020843;
              }
              else {
                *DAT_8009ff58 = 0x20943;
                uVar1 = 0x11000000;
                *DAT_8009ff5c = 0x1323;
              }
              if ((ushort)DAT_800a0180[3] - 1 == (uint)(ushort)DAT_800a0180[2]) {
                if (DAT_800a0190 == 0) {
                  FUN_80060c48(3,_DAT_800ac938,0,0x1f8,uVar1,1,0);
                }
                else {
                  FUN_80060dd4(_DAT_800ac938,DAT_800a0198 * 0x800 + DAT_800a0190 + 0x20,0x1f8,1);
                  DAT_800a0198 = DAT_800a0198 + 1;
                }
                *DAT_8009ff5c = 0x1325;
                DAT_8009ffac = 0;
                DAT_8009ff9c = 0;
                _DAT_800ab5b0 = 1;
                DAT_8009ffa4 = DAT_8009ffa0;
              }
              else if (DAT_800a0190 == 0) {
                FUN_80060c48(3,_DAT_800ac938,0,0x1f8,uVar1,0,0);
              }
              else {
                FUN_80060dd4(_DAT_800ac938,DAT_800a0198 * 0x800 + DAT_800a0190 + 0x20,0x1f8,0);
                DAT_800a0198 = DAT_800a0198 + 1;
              }
              *DAT_800a0180 = 3;
              DAT_800a01b0 = DAT_800a01b0 + 1;
              if ((DAT_800a0190 != 0) && (_DAT_800ab5b0 != 0)) {
                FUN_8005ff7c();
              }
            }
            else {
              DAT_8009ff9c = 0;
              DAT_8009ffac = 0;
              FUN_80060184(DAT_800a01b8,DAT_800a01b0 - DAT_800a01b8);
              DAT_800a01b0 = DAT_800a01b8;
              *DAT_800a0180 = 0;
              if (DAT_800a0190 != 0) {
                DAT_800a0198 = DAT_800a0198 + 1;
              }
              DAT_8009ffa8 = 6;
            }
          }
          else {
            if (DAT_800a0190 != 0) {
              DAT_800a0198 = 0;
            }
            DAT_8009ffa8 = 5;
            *DAT_800a0180 = 0;
          }
        }
        else {
          if (DAT_800a0190 != 0) {
            DAT_800a0198 = DAT_800a0198 + 1;
          }
          DAT_8009ffa8 = 4;
        }
      }
    }
    else {
      DAT_8009ffa8 = 3;
    }
  }
  else {
    _DAT_800ab698 = 1;
    if (DAT_800a0190 != 0) {
      DAT_800a0198 = DAT_800a0198 + 1;
    }
    DAT_8009ffa8 = 1;
  }
  return;
}



// ---- FUN_80060c48 @ 80060c48

void FUN_80060c48(uint param_1,undefined4 param_2,int param_3,uint param_4,undefined4 param_5,
                 int param_6,int param_7)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  
  puVar3 = (uint *)((uint)(&DAT_1f801080 + param_1 * 0x10) | 8);
  uVar1 = *puVar3;
  iVar2 = 0;
  do {
    if ((uVar1 & 0x1000000) == 0) {
LAB_80060cd4:
      if (param_6 == 1) {
        uVar1 = *DAT_8009ff64 & 0xffffff | 0x10000 << (param_1 & 0x1f) | param_7 << (param_1 & 0x1f)
        ;
      }
      else {
        uVar1 = *DAT_8009ff64 & 0xffffff & ~(1 << (param_1 + 0x10 & 0x1f));
      }
      *DAT_8009ff64 = uVar1;
      iVar2 = param_1 * 0x10;
      *DAT_8009ff60 = *DAT_8009ff60 | 1 << (param_1 * 4 + 3 & 0x1f);
      *(undefined4 *)(&DAT_1f801080 + iVar2) = param_2;
      *(uint *)(&DAT_1f801084 + iVar2) = param_3 << 0x10 | param_4;
      *(undefined4 *)(&DAT_1f801088 + iVar2) = param_5;
      return;
    }
    if (iVar2 == 0x10000) {
      FUN_80058614(s_DMA_STATUS_ERROR__x_80029498,*puVar3);
      goto LAB_80060cd4;
    }
    uVar1 = *puVar3;
    iVar2 = iVar2 + 1;
  } while( true );
}



// ---- FUN_80060dd4 @ 80060dd4

void FUN_80060dd4(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_3 != 0) {
    do {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      uVar2 = uVar2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    } while (uVar2 < param_3);
  }
  return;
}



// ---- FUN_80060e30 @ 80060e30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80060e30(void)

{
  FUN_80060f70();
  _DAT_a00003e0 = FUN_80060eb0;
  _DAT_a00003f0 = FUN_80060f00;
  _DAT_a00003f8 = FUN_80060f3c;
  _DAT_a0000414 = FUN_80060ed8;
  _DAT_a0000454 = &LAB_80060e28;
  _DAT_a0000488 = &LAB_80060e28;
  _DAT_a000048c = &LAB_80060e28;
  return;
}



// ---- FUN_80060eb0 @ 80060eb0

void FUN_80060eb0(undefined4 param_1)

{
  FUN_8005e964(0x15,param_1,0);
  return;
}



// ---- FUN_80060ed8 @ 80060ed8

void FUN_80060ed8(void)

{
  FUN_8005e964(8,0,0);
  return;
}



// ---- FUN_80060f00 @ 80060f00

void FUN_80060f00(undefined1 *param_1)

{
  undefined1 local_10 [8];
  
  FUN_8005e964(1,0,local_10);
  *param_1 = local_10[0];
  return;
}



// ---- FUN_80060f3c @ 80060f3c

bool FUN_80060f3c(void)

{
  int iVar1;
  
  FUN_8005e9d0();
  do {
    iVar1 = FUN_8005e708(1,0);
  } while (0 < iVar1);
  return iVar1 == 0;
}



// ---- FUN_80060f70 @ 80060f70

void FUN_80060f70(void)

{
  (*(code *)&LAB_000000a0)();
  return;
}



// ---- FUN_80060f80 @ 80060f80

undefined4 * FUN_80060f80(undefined4 *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined1 *puVar10;
  int iVar11;
  char local_38 [32];
  
  if (DAT_8009ffb4 != 0) {
    iVar2 = FUN_80061284();
    if (iVar2 == 0) {
      return (undefined4 *)0x0;
    }
    DAT_8009ffb4 = 0;
  }
  iVar2 = 1;
  if (*param_2 == '\\') {
    local_38[0] = '\0';
    iVar11 = 0;
    pcVar7 = param_2;
    do {
      pcVar9 = local_38;
      if (*pcVar7 != '\\') {
        if (*pcVar7 == '\0') break;
        do {
          cVar1 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          *pcVar9 = cVar1;
          cVar1 = *pcVar7;
          pcVar9 = pcVar9 + 1;
          if (cVar1 == '\\') goto code_r0x80061038;
        } while (cVar1 != '\0');
      }
      cVar1 = *pcVar7;
code_r0x80061038:
      if (cVar1 == '\0') break;
      pcVar7 = pcVar7 + 1;
      *pcVar9 = '\0';
      iVar2 = FUN_8006158c(iVar2,local_38);
      if (iVar2 == -1) {
        local_38[0] = '\0';
        break;
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < 8);
    if (iVar11 < 8) {
      if (local_38[0] == '\0') {
        if (0 < DAT_8009fea8) {
          FUN_80058614(s__s__dir_was_not_found_800294cc,param_2);
        }
      }
      else {
        *pcVar9 = '\0';
        iVar2 = FUN_80061644();
        if (iVar2 == 0) {
          if (0 < DAT_8009fea8) {
            FUN_80058614(s_CdSearchFile__disc_error_800294e4);
          }
        }
        else {
          iVar2 = 0;
          if (1 < DAT_8009fea8) {
            FUN_80058614(s_CdSearchFile__searching__s____80029500,local_38);
          }
          if (DAT_800a8968 != '\0') {
            puVar8 = (undefined4 *)&DAT_800a8960;
            puVar10 = &DAT_800a8968;
            iVar11 = 0;
            do {
              iVar3 = FUN_80061264(puVar10,local_38);
              if (iVar3 != 0) {
                if (1 < DAT_8009fea8) {
                  FUN_80058614(s__s__found_80029520,local_38);
                }
                uVar4 = puVar8[1];
                uVar5 = puVar8[2];
                uVar6 = puVar8[3];
                *param_1 = *puVar8;
                param_1[1] = uVar4;
                param_1[2] = uVar5;
                param_1[3] = uVar6;
                uVar4 = puVar8[5];
                param_1[4] = puVar8[4];
                param_1[5] = uVar4;
                return puVar8;
              }
              puVar8 = puVar8 + 6;
              iVar2 = iVar2 + 1;
              puVar10 = puVar10 + 0x18;
            } while ((iVar2 < 0x28) &&
                    (pcVar7 = &DAT_800a8980 + iVar11, iVar11 = iVar11 + 0x18, *pcVar7 != '\0'));
          }
          if (0 < DAT_8009fea8) {
            FUN_80058614(s__s__not_found_8002952c,local_38);
          }
        }
      }
    }
    else if (0 < DAT_8009fea8) {
      FUN_80058614(s__s__path_level___d__error_800294b0,param_2,iVar11);
    }
  }
  return (undefined4 *)0x0;
}



// ---- FUN_80061264 @ 80061264

bool FUN_80061264(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_80058654(param_1,param_2,0xc);
  return iVar1 == 0;
}



// ---- FUN_80061284 @ 80061284

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80061284(void)

{
  byte bVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  
  iVar4 = FUN_80061944(1,0x10,&DAT_800a94e0);
  if (iVar4 == 1) {
    iVar4 = FUN_80058654(0x800a94e1,s_CD001_8009ffb8,5);
    uVar3 = _DAT_800a956c;
    if (iVar4 == 0) {
      iVar4 = FUN_80061944(1,_DAT_800a956c,&DAT_800a94e0);
      if (iVar4 == 1) {
        pbVar7 = &DAT_800a94e0;
        if (1 < DAT_8009fea8) {
          FUN_80058614(s_CD_newmedia__sarching_dir___800295bc);
        }
        iVar4 = 0;
        bVar2 = true;
        if (DAT_800a94e0 != '\0') {
          iVar6 = 0;
          do {
            iVar6 = (iVar6 * 4 + iVar4 * 3) * 4;
            *(undefined4 *)(iVar6 + -0x7ff572d8) = *(undefined4 *)(pbVar7 + 2);
            bVar1 = pbVar7[6];
            iVar4 = iVar4 + 1;
            *(int *)(iVar6 + -0x7ff572e0) = iVar4;
            iVar8 = iVar6 + -0x7ff572d4;
            *(uint *)(&DAT_800a8d24 + iVar6) = (uint)bVar1;
            FUN_80061914(iVar8,pbVar7 + 8,*pbVar7);
            *(undefined1 *)(iVar8 + (uint)*pbVar7) = 0;
            pbVar7 = pbVar7 + (uint)*pbVar7 + (*pbVar7 & 1) + 8;
            if (1 < DAT_8009fea8) {
              FUN_80058614(s__08x__04x__04x__s_800295dc,*(undefined4 *)(iVar6 + -0x7ff572d8),
                           *(undefined4 *)(iVar6 + -0x7ff572e0),
                           *(undefined4 *)(&DAT_800a8d24 + iVar6),iVar8);
            }
            if (0x2c < iVar4) goto LAB_80061538;
            bVar2 = iVar4 < 0x2d;
            if ((byte *)0x800a9cdf < pbVar7) goto LAB_80061510;
            iVar6 = iVar4 * 2;
          } while (*pbVar7 != 0);
          bVar2 = iVar4 < 0x2d;
        }
LAB_80061510:
        if (bVar2) {
          *(undefined4 *)(&DAT_800a8d24 + iVar4 * 0x2c) = 0;
        }
LAB_80061538:
        DAT_800a01f8 = 0;
        uVar5 = 1;
        if (1 < DAT_8009fea8) {
          FUN_80058614(s_CD_newmedia___d_dir_entries_foun_800295f0,iVar4);
          uVar5 = 1;
        }
      }
      else {
        uVar5 = 0;
        if (0 < DAT_8009fea8) {
          FUN_80058614(s_CD_newmedia__Read_error__PT__08x_80029598,uVar3);
          uVar5 = 0;
        }
      }
    }
    else {
      uVar5 = 0;
      if (0 < DAT_8009fea8) {
        FUN_80058614(s_CD_newmedia__Disc_format_error_i_80029568);
        uVar5 = 0;
      }
    }
  }
  else {
    uVar5 = 0;
    if (0 < DAT_8009fea8) {
      FUN_80058614(s_CD_newmedia__Read_error_in_cd_re_8002953c);
      uVar5 = 0;
    }
  }
  return uVar5;
}



// ---- FUN_8006158c @ 8006158c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8006158c(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (_DAT_800a8d24 != 0) {
    piVar2 = (int *)&DAT_800a8d24;
    iVar4 = 0;
    do {
      if ((*piVar2 == param_1) && (iVar1 = FUN_80058634(param_2,iVar4 + -0x7ff572d4), iVar1 == 0)) {
        return iVar3 + 1;
      }
      piVar2 = piVar2 + 0xb;
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x2c;
    } while ((iVar3 < 0x2d) && (*piVar2 != 0));
  }
  return -1;
}



// ---- FUN_80061644 @ 80061644

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80061644(int param_1)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  
  if (param_1 != DAT_800a01f8) {
    iVar1 = FUN_80061944(1,*(undefined4 *)(param_1 * 0x2c + -0x7ff57304),&DAT_800a94e0);
    if (iVar1 != 1) {
      if (DAT_8009fea8 < 1) {
        return 0xffffffff;
      }
      FUN_80058614(s_CD_cachefile__dir_not_found_80029614);
      return 0xffffffff;
    }
    iVar1 = 0;
    if (1 < DAT_8009fea8) {
      FUN_80058614(s_CD_cachefile__searching____80029634);
    }
    pbVar2 = &DAT_800a94e0;
    if (DAT_800a94e0 != '\0') {
      puVar4 = &DAT_800a8968;
      iVar3 = 0;
      puVar5 = &DAT_800a8960;
      do {
        FUN_8005eb34(*(undefined4 *)(pbVar2 + 2),puVar5);
        *(undefined4 *)(&DAT_800a8964 + iVar3) = *(undefined4 *)(pbVar2 + 10);
        if (iVar1 == 0) {
          _DAT_800a8968 = DAT_8009ffc0;
        }
        else if (iVar1 == 1) {
          _DAT_800a8980 = DAT_8009ffc4;
          DAT_800a8982 = DAT_8009ffc6;
        }
        else {
          FUN_80061914(puVar4,pbVar2 + 0x21,pbVar2[0x20]);
          puVar4[pbVar2[0x20]] = 0;
        }
        puVar5 = puVar5 + 0x18;
        if (1 < DAT_8009fea8) {
          FUN_80058614(s___02x__02x__02x___8d__s_80029650,(&DAT_800a8960)[iVar3],
                       *(undefined1 *)(iVar3 + -0x7ff5769f),*(undefined1 *)(iVar3 + -0x7ff5769e),
                       *(undefined4 *)(&DAT_800a8964 + iVar3),puVar4);
        }
        puVar4 = puVar4 + 0x18;
        iVar1 = iVar1 + 1;
        pbVar2 = pbVar2 + *pbVar2;
        iVar3 = iVar3 + 0x18;
      } while (((iVar1 < 0x28) && (pbVar2 < (byte *)0x800a9ce0)) && (*pbVar2 != 0));
    }
    DAT_800a01f8 = param_1;
    if (iVar1 < 0x28) {
      (&DAT_800a8968)[iVar1 * 0x18] = 0;
    }
    if (DAT_8009fea8 < 2) {
      return 1;
    }
    FUN_80058614(s_CD_cachefile___d_files_found_8002966c,iVar1);
  }
  return 1;
}



// ---- FUN_80061914 @ 80061914

void FUN_80061914(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = param_3 + -1;
  if (param_3 != 0) {
    do {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      iVar2 = iVar2 + -1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    } while (iVar2 != -1);
  }
  return;
}



// ---- FUN_80061944 @ 80061944

bool FUN_80061944(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_18 [8];
  
  uVar1 = FUN_8005eb34(param_2,auStack_18);
  FUN_8005e918(2,uVar1,0);
  FUN_8005e9d0(param_1,param_3,0x80);
  do {
    iVar2 = FUN_8005e708(1,0);
  } while (0 < iVar2);
  return iVar2 == 0;
}



// ---- FUN_800619b4 @ 800619b4

void FUN_800619b4(undefined4 param_1)

{
  FUN_80061ca4(0,param_1);
  return;
}



// ---- FUN_800619d8 @ 800619d8

void FUN_800619d8(undefined4 param_1)

{
  FUN_80061ca4(1,param_1);
  return;
}



// ---- FUN_800619fc @ 800619fc

void FUN_800619fc(undefined4 param_1)

{
  FUN_80061ca4(3,param_1);
  return;
}



// ---- FUN_80061a20 @ 80061a20

void FUN_80061a20(undefined4 param_1)

{
  FUN_80061ca4(4,param_1);
  return;
}



// ---- FUN_80061a44 @ 80061a44

void FUN_80061a44(undefined4 param_1)

{
  FUN_80061ca4(5,param_1);
  return;
}



// ---- FUN_80061a68 @ 80061a68

void FUN_80061a68(undefined4 param_1)

{
  FUN_80061c74(2,param_1);
  return;
}



// ---- FUN_80061a8c @ 80061a8c

void FUN_80061a8c(undefined4 param_1)

{
  FUN_80061c74(9,param_1);
  return;
}



// ---- FUN_80061ab0 @ 80061ab0

void FUN_80061ab0(undefined4 param_1)

{
  FUN_80061c74(10,param_1);
  return;
}



// ---- FUN_80061ad4 @ 80061ad4

code * FUN_80061ad4(void)

{
  *DAT_8009ffd0 = 0xffffffff;
  *DAT_8009ffcc = 0x148;
  FUN_80058544(0);
  FUN_80061c34(3,0);
  DAT_800a0200 = 0;
  FUN_80061c74(0,&LAB_80061b84);
  DAT_8009ffd4 = 1;
  return FUN_80061bd4;
}



// ---- FUN_80061b50 @ 80061b50

void FUN_80061b50(void)

{
  DAT_8009ffd4 = 0;
  FUN_80061c74(0,0);
  DAT_800a0200 = 0;
  return;
}



// ---- FUN_80061bd4 @ 80061bd4

int FUN_80061bd4(int param_1)

{
  int unaff_s1;
  
  FUN_80061ad4();
  if (DAT_8009ffd4 != 0) {
    if (param_1 == DAT_800a0200) {
      return DAT_800a0200;
    }
    unaff_s1 = DAT_800a0200;
    DAT_800a0200 = param_1;
  }
  return unaff_s1;
}



// ---- FUN_80061c34 @ 80061c34

void FUN_80061c34(void)

{
  (*(code *)&LAB_000000c0)();
  return;
}



// ---- FUN_80061c44 @ 80061c44

void FUN_80061c44(void)

{
  (**(code **)(PTR_PTR_8009ffdc + 0xc))();
  return;
}



// ---- FUN_80061c74 @ 80061c74

void FUN_80061c74(void)

{
  (**(code **)(PTR_PTR_8009ffdc + 8))();
  return;
}



// ---- FUN_80061ca4 @ 80061ca4

void FUN_80061ca4(void)

{
  (**(code **)(PTR_PTR_8009ffdc + 4))();
  return;
}



// ---- FUN_80061cd4 @ 80061cd4

void FUN_80061cd4(void)

{
  (**(code **)(PTR_PTR_8009ffdc + 0x14))();
  return;
}



// ---- FUN_80061d04 @ 80061d04

void FUN_80061d04(void)

{
  (**(code **)(PTR_PTR_8009ffdc + 0x10))();
  return;
}



// ---- FUN_80061d34 @ 80061d34

undefined4 FUN_80061d34(void)

{
  return DAT_8009ffe4;
}



// ---- FUN_80061d44 @ 80061d44

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80061d44(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if (DAT_8009ffe0 == 0) {
    FUN_80058314();
    DAT_8009fff0 = 0;
    iVar3 = 10;
    puVar1 = &DAT_8009f3a0;
    do {
      *puVar1 = 0;
      iVar3 = iVar3 + -1;
      puVar1 = puVar1 + -1;
    } while (-1 < iVar3);
    iVar3 = FUN_800620dc(0x800a9ce0);
    if (iVar3 != 0) {
      DAT_8009ffe4 = 1;
      if (((uint)*DAT_8009ffec & *DAT_8009ffe8 & DAT_8009fff0) != 0) {
        iVar3 = 0xff;
        do {
          uVar5 = 1;
          if (iVar3 == -1) {
            FUN_80058614(s_Too_many_interrupts_800296c0);
            break;
          }
          iVar4 = 0;
          puVar1 = &DAT_8009f378;
          do {
            if (((uint)*DAT_8009ffec & (uint)*DAT_8009ffe8 & uVar5 & DAT_8009fff0) != 0) {
              *DAT_8009ffe8 = ~(ushort)uVar5;
              if ((code *)*puVar1 != (code *)0x0) {
                (*(code *)*puVar1)();
              }
            }
            puVar1 = puVar1 + 1;
            iVar4 = iVar4 + 1;
            uVar5 = uVar5 << 1;
          } while (iVar4 < 0xb);
          iVar3 = iVar3 + -1;
        } while (((uint)*DAT_8009ffec & *DAT_8009ffe8 & DAT_8009fff0) != 0);
      }
      DAT_8009ffe4 = 0;
      FUN_800620cc();
    }
    DAT_8009ffe0 = 1;
    uVar2 = FUN_80061ad4();
    *(undefined4 *)(PTR_PTR_8009ffdc + 0x14) = uVar2;
    uVar2 = FUN_800620ec();
    *(undefined4 *)(PTR_PTR_8009ffdc + 4) = uVar2;
    FUN_80060f70();
    _DAT_800a9ce4 = 0x800aacc0;
    FUN_800620bc(0x800a9ce0);
    FUN_800585a4();
  }
  return;
}



// ---- FUN_80061f64 @ 80061f64

int FUN_80061f64(uint param_1,int param_2,undefined4 param_3,int param_4)

{
  ushort *puVar1;
  int *piVar2;
  uint uVar3;
  
  if (DAT_8009ffe0 != 0) {
    piVar2 = &DAT_8009f378 + param_1;
    param_4 = *piVar2;
    if (param_2 != param_4) {
      *piVar2 = 0;
      puVar1 = DAT_8009ffec;
      if (param_2 == 0) {
        uVar3 = ~(1 << (param_1 & 0x1f));
        *DAT_8009ffec = *DAT_8009ffec & (ushort)uVar3;
        DAT_8009fff0 = uVar3 & DAT_8009fff0;
      }
      else {
        *piVar2 = param_2;
        uVar3 = 1 << (param_1 & 0x1f);
        *puVar1 = *puVar1 | (ushort)uVar3;
        DAT_8009fff0 = uVar3 | DAT_8009fff0;
      }
    }
  }
  return param_4;
}



// ---- FUN_80062010 @ 80062010

void FUN_80062010(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int local_10;
  
  local_10 = 0x80000;
  FUN_80058314();
  puVar2 = DAT_8009ffec;
  puVar1 = DAT_8009ffe8;
  DAT_8009ffe0 = 0;
  DAT_8009fff0 = 0;
  *DAT_8009ffe8 = 0;
  iVar4 = 10;
  puVar3 = &DAT_8009f3a0;
  *puVar2 = *puVar1;
  do {
    *puVar3 = 0;
    iVar4 = iVar4 + -1;
    puVar3 = puVar3 + -1;
  } while (-1 < iVar4);
  FUN_80062150();
  FUN_80061b50();
  do {
    local_10 = local_10 + -1;
  } while (local_10 != -1);
  FUN_800585a4();
  return;
}



// ---- FUN_800620bc @ 800620bc

void FUN_800620bc(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_800620cc @ 800620cc

void FUN_800620cc(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_800620dc @ 800620dc

void FUN_800620dc(void)

{
  (*(code *)&LAB_000000a0)();
  return;
}



// ---- FUN_800620ec @ 800620ec

undefined1 * FUN_800620ec(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 6;
  puVar1 = &DAT_8009f3bc;
  *DAT_8009fff4 = 0;
  do {
    *puVar1 = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + -1;
  } while (-1 < iVar2);
  FUN_80061c74(3,FUN_800621a8);
  DAT_8009fff8 = 1;
  return &LAB_800622f8;
}



// ---- FUN_80062150 @ 80062150

void FUN_80062150(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  DAT_8009fff8 = 0;
  *DAT_8009fff4 = 0;
  FUN_80061c74(3,0);
  iVar2 = 6;
  puVar1 = &DAT_8009f3bc;
  do {
    *puVar1 = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + -1;
  } while (-1 < iVar2);
  return;
}



// ---- FUN_800621a8 @ 800621a8

void FUN_800621a8(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  uVar1 = *DAT_8009fff4;
  while ((uVar1 & 0x7f000000) != 0) {
    iVar3 = 0;
    uVar1 = 0x1000000;
    puVar2 = &DAT_8009f3a4;
    do {
      if ((uVar1 & *DAT_8009fff4) != 0) {
        *DAT_8009fff4 = (uVar1 | 0xffffff) & *DAT_8009fff4;
        if ((code *)*puVar2 != (code *)0x0) {
          (*(code *)*puVar2)();
        }
      }
      puVar2 = puVar2 + 1;
      iVar3 = iVar3 + 1;
      uVar1 = uVar1 << 1;
    } while (iVar3 < 7);
    uVar1 = *DAT_8009fff4;
  }
  if (((*DAT_8009fff4 & 0xff000000) == 0x80000000) || ((*DAT_8009fff4 & 0x8000) != 0)) {
    FUN_80058614(s_DMA_bus_error__code__08x_800296d8,*DAT_8009fff4);
  }
  return;
}



// ---- FUN_80062390 @ 80062390

uint FUN_80062390(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *DAT_800a0000 - DAT_800a0004 & 0xffff;
  if (param_1 < 0) {
    uVar2 = DAT_8009ffd8;
  }
  else if (param_1 != 1) {
    FUN_80062494(param_1 + DAT_800a0008 + -1);
    uVar1 = *DAT_8009fffc;
    FUN_80062494(DAT_8009ffd8 + 1);
    if ((uVar1 & 0x80000) != 0) {
      do {
      } while (((uVar1 ^ *DAT_8009fffc) & 0x80000000) == 0);
    }
    DAT_800a0008 = DAT_8009ffd8;
    DAT_800a0004 = *DAT_800a0000;
  }
  return uVar2;
}



// ---- FUN_80062494 @ 80062494

void FUN_80062494(int param_1)

{
  int local_10;
  
  local_10 = 0x8000;
  do {
    if (param_1 <= DAT_8009ffd8) {
      return;
    }
    local_10 = local_10 + -1;
  } while (local_10 != -1);
  FUN_80058614(s_VSync__timeout_800296f4);
  return;
}



// ---- FUN_8006251c @ 8006251c

int FUN_8006251c(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    if (param_3 == 0) {
      return iVar3;
    }
    uVar2 = param_3;
    if (0x8000 < param_3) {
      uVar2 = 0x8000;
    }
    iVar1 = FUN_800626d8(0,param_1,uVar2,param_2);
    iVar3 = iVar3 + iVar1;
    if (iVar1 == -1) break;
    param_2 = param_2 + iVar1;
    param_3 = param_3 - iVar1;
    if (iVar1 < (int)uVar2) {
      return iVar3;
    }
  }
  return -1;
}



// ---- FUN_800625c0 @ 800625c0

void FUN_800625c0(void)

{
  trap(0x103);
  return;
}



// ---- FUN_800625e0 @ 800625e0

void FUN_800625e0(void)

{
  trap(0x102);
  return;
}



// ---- FUN_80062600 @ 80062600

void FUN_80062600(void)

{
  trap(0x107);
  return;
}



// ---- FUN_80062624 @ 80062624

void FUN_80062624(void)

{
  trap(0x104);
  return;
}



// ---- FUN_80062634 @ 80062634

int FUN_80062634(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    if (param_3 == 0) {
      return iVar3;
    }
    uVar2 = param_3;
    if (0x8000 < param_3) {
      uVar2 = 0x8000;
    }
    iVar1 = FUN_800626f0(0,param_1,uVar2,param_2);
    iVar3 = iVar3 + iVar1;
    if (iVar1 == -1) break;
    param_2 = param_2 + iVar1;
    param_3 = param_3 - iVar1;
    if (iVar1 < (int)uVar2) {
      return iVar3;
    }
  }
  return -1;
}



// ---- FUN_800626d8 @ 800626d8

void FUN_800626d8(void)

{
  trap(0x105);
  return;
}



// ---- FUN_800626f0 @ 800626f0

void FUN_800626f0(void)

{
  trap(0x106);
  return;
}



// ---- FUN_80062708 @ 80062708

void FUN_80062708(short param_1,short param_2,short param_3)

{
  FUN_8006277c((int)param_1,0,(int)param_2,(int)param_3);
  return;
}



// ---- FUN_80062740 @ 80062740

void FUN_80062740(short param_1,short param_2,short param_3,short param_4)

{
  FUN_8006277c((int)param_1,(int)param_2,(int)param_3,(int)param_4);
  return;
}



// ---- FUN_8006277c @ 8006277c

void FUN_8006277c(short param_1,short param_2,short param_3,short param_4)

{
  int iVar1;
  
  iVar1 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + param_1 * 4);
  *(short *)(iVar1 + 0x72) = param_3;
  *(short *)(iVar1 + 0x74) = param_4;
  FUN_80065738((int)param_1,(int)param_3,(int)param_4,0);
  return;
}



// ---- FUN_800627f0 @ 800627f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800627f0(int param_1)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  
  FUN_80061c44();
  if (param_1 == 0) {
    FUN_8006bd2c();
  }
  else {
    FUN_8006bd4c();
  }
  puVar7 = (undefined2 *)&DAT_1f801c00;
  iVar4 = 0;
  do {
    iVar6 = 0;
    puVar3 = &DAT_8009f400;
    do {
      uVar1 = *puVar3;
      puVar3 = puVar3 + 1;
      iVar6 = iVar6 + 1;
      *puVar7 = uVar1;
      puVar7 = puVar7 + 1;
    } while (iVar6 < 8);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x18);
  puVar3 = (undefined2 *)&DAT_1f801d80;
  iVar4 = 0;
  puVar7 = &DAT_8009f410;
  do {
    uVar1 = *puVar7;
    puVar7 = puVar7 + 1;
    iVar4 = iVar4 + 1;
    *puVar3 = uVar1;
    puVar3 = puVar3 + 1;
  } while (iVar4 < 0x10);
  FUN_80064698(0x18);
  iVar6 = 0;
  iVar4 = -0x7ff548a4;
  do {
    iVar5 = 0xf;
    puVar2 = (undefined4 *)(iVar4 + 0x3c);
    do {
      *puVar2 = 0;
      iVar5 = iVar5 + -1;
      puVar2 = puVar2 + -1;
    } while (-1 < iVar5);
    iVar6 = iVar6 + 1;
    iVar4 = iVar4 + 0x40;
  } while (iVar6 < 0x20);
  _DAT_800b03dc = 0x3c;
  _DAT_800ae5c8 = 0;
  _DAT_800abfa4 = 0;
  return;
}



// ---- FUN_80062904 @ 80062904

void FUN_80062904(void)

{
  FUN_800627f0(0);
  return;
}



// ---- FUN_80062924 @ 80062924

void FUN_80062924(void)

{
  FUN_800627f0(1);
  return;
}



// ---- FUN_80062944 @ 80062944

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80062944(int param_1,short param_2,short param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = 0;
  _DAT_800b052c = param_2;
  _DAT_800b0534 = param_3;
  if (0 < param_2) {
    piVar4 = (int *)&DAT_800b0424;
    iVar1 = 0;
    do {
      *piVar4 = param_1 + iVar1 * 0xa8;
      piVar4 = piVar4 + 1;
      iVar5 = iVar5 + 1;
      iVar1 = iVar1 + param_3;
    } while (iVar5 < param_2);
  }
  iVar5 = 0;
  if (0 < _DAT_800b052c) {
    piVar4 = (int *)&DAT_800b0424;
    do {
      iVar1 = 0;
      if (0 < _DAT_800b0534) {
        iVar3 = 0;
        do {
          *(undefined4 *)(iVar3 + *piVar4 + 0x90) = 0;
          *(undefined1 *)(iVar3 + *piVar4) = 0xff;
          *(undefined2 *)(iVar3 + *piVar4 + 0x3c) = 0;
          *(undefined2 *)(iVar3 + *piVar4 + 0x3e) = 0;
          *(undefined4 *)(iVar3 + *piVar4 + 0x94) = 0;
          *(undefined4 *)(iVar3 + *piVar4 + 0x98) = 0;
          *(undefined2 *)(iVar3 + *piVar4 + 0x40) = 0;
          *(undefined4 *)(iVar3 + *piVar4 + 0xa4) = 0;
          *(undefined4 *)(iVar3 + *piVar4 + 0xa0) = 0;
          *(undefined4 *)(iVar3 + *piVar4 + 0x9c) = 0;
          *(undefined2 *)(iVar3 + *piVar4 + 0x42) = 0;
          iVar2 = (int)_DAT_800b0534;
          *(undefined2 *)(iVar3 + *piVar4 + 0x72) = 0x7f;
          iVar1 = iVar1 + 1;
          *(undefined2 *)(iVar3 + *piVar4 + 0x74) = 0x7f;
          iVar3 = iVar3 + 0xa8;
        } while (iVar1 < iVar2);
      }
      iVar5 = iVar5 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar5 < _DAT_800b052c);
  }
  return;
}



// ---- FUN_80062ae8 @ 80062ae8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80062ae8(uint param_1)

{
  bool bVar1;
  
  bVar1 = (param_1 & 0x1000) == 0;
  if (bVar1) {
    _DAT_800aee88 = param_1;
  }
  else {
    _DAT_800aee88 = param_1 & 0xfff;
  }
  _DAT_800ab754 = (uint)!bVar1;
  if (3 < (int)_DAT_800aee88) {
    _DAT_800b03dc = _DAT_800aee88;
    return;
  }
  if ((_DAT_800aee88 != 1) && (1 < (int)_DAT_800aee88)) {
    if (_DAT_800aee88 == 2) {
      _DAT_800b03dc = 0xf0;
      return;
    }
    if (_DAT_800aee88 == 3) {
      _DAT_800b03dc = 0x78;
      return;
    }
  }
  _DAT_800b03dc = 0x3c;
  return;
}



// ---- FUN_80062ba8 @ 80062ba8

void FUN_80062ba8(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 3;
  do {
    bVar1 = iVar2 < 6000;
    iVar2 = iVar2 + 3;
  } while (bVar1);
  return;
}



// ---- FUN_80062bc4 @ 80062bc4

/* WARNING: Removing unreachable block (ram,0x80062d90) */
/* WARNING: Removing unreachable block (ram,0x80062dd0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80062bc4(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar2 = 3;
  do {
    bVar1 = iVar2 < 3000;
    iVar2 = iVar2 + 3;
  } while (bVar1);
  if (_DAT_800aee88 == 1) {
    if (param_1 == 0) {
      FUN_80061cd4(FUN_8006a7fc);
      return;
    }
    FUN_80058314();
    FUN_800584e0(0xf2000003);
    FUN_800583a4(0xf2000003,1,0x1000);
    FUN_80062ba8();
    FUN_80062ba8();
    FUN_80058478(0xf2000003);
    uVar3 = 0xf2000003;
    goto LAB_80062e1c;
  }
  if (_DAT_800aee88 < 2) {
    if (_DAT_800aee88 == 0) {
      return;
    }
  }
  else {
    if (_DAT_800aee88 == 2) {
      FUN_80058314();
      FUN_800584e0(0xf2000002);
      FUN_800583a4(0xf2000002,0x44e8,0x1000);
      FUN_80062ba8();
      FUN_80062ba8();
      FUN_80058478(0xf2000002);
      uVar3 = 0xf2000002;
      goto LAB_80062e1c;
    }
    if (_DAT_800aee88 == 3) {
      FUN_80058314();
      FUN_800584e0(0xf2000002);
      FUN_800583a4(0xf2000002,0x89d0,0x1000);
      FUN_80062ba8();
      FUN_80062ba8();
      FUN_80058478(0xf2000002);
      uVar3 = 0xf2000002;
      goto LAB_80062e1c;
    }
  }
  if (_DAT_800ab754 != 0) {
    return;
  }
  if (_DAT_800aee88 < 0x46) {
    uVar4 = 0x3d86 / _DAT_800aee88;
    if (_DAT_800aee88 == 0) {
      trap(0x1c00);
    }
    uVar3 = 0xf2000001;
  }
  else {
    uVar4 = 0x409980 / _DAT_800aee88;
    if (_DAT_800aee88 == 0) {
      trap(0x1c00);
    }
    uVar3 = 0xf2000002;
  }
  FUN_80058314();
  FUN_800584e0(uVar3);
  FUN_800583a4(uVar3,uVar4 & 0xffff,0x1000);
  FUN_80062ba8();
  FUN_80062ba8();
  FUN_80058478(uVar3);
LAB_80062e1c:
  DAT_800a0208 = FUN_80058574(uVar3,2,0x1000,FUN_8006a7fc);
  FUN_80058364(DAT_800a0208);
  FUN_800585a4();
  return;
}



// ---- FUN_80062e5c @ 80062e5c

void FUN_80062e5c(void)

{
  FUN_80062bc4(1);
  return;
}



// ---- FUN_80062e7c @ 80062e7c

void FUN_80062e7c(void)

{
  FUN_80062bc4(0);
  return;
}



// ---- FUN_80062e9c @ 80062e9c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80062e9c(void)

{
  if ((_DAT_800ab754 == 0) || (_DAT_800aee88 != 0)) {
    FUN_80058314();
    FUN_80062f24(DAT_800a0208);
    FUN_80058304(DAT_800a0208);
    FUN_800585a4();
  }
  return;
}



// ---- FUN_80062f04 @ 80062f04

void FUN_80062f04(void)

{
  FUN_8006bde8();
  return;
}



// ---- FUN_80062f24 @ 80062f24

void FUN_80062f24(void)

{
  (*(code *)&LAB_000000b0)();
  return;
}



// ---- FUN_80062f34 @ 80062f34

void FUN_80062f34(int param_1)

{
  uint uVar1;
  int *piVar2;
  
  piVar2 = (int *)(&DAT_800b0424 + ((param_1 << 0x10) >> 0xe));
  uVar1 = *(uint *)(*piVar2 + 0x90);
  if (((uVar1 & 0x204) == 0) && ((uVar1 & 0x100) == 0)) {
    *(uint *)(*piVar2 + 0x90) = uVar1 & 0xfffffffd;
    *(uint *)(*piVar2 + 0x90) = *(uint *)(*piVar2 + 0x90) | 8;
    *(uint *)(*piVar2 + 0x90) = *(uint *)(*piVar2 + 0x90) | 1;
  }
  return;
}



// ---- FUN_80063048 @ 80063048

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80063048(void)

{
  _DAT_800abf9c = 1;
  return;
}



// ---- FUN_8006305c @ 8006305c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8006305c(void)

{
  _DAT_800abf9c = 0;
  return;
}



// ---- FUN_8006306c @ 8006306c

void FUN_8006306c(void)

{
  FUN_8006f008(1);
  return;
}



// ---- FUN_8006308c @ 8006308c

void FUN_8006308c(void)

{
  FUN_8006f008(0);
  return;
}



// ---- FUN_800630ac @ 800630ac

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_800630ac(ushort param_1)

{
  int iVar1;
  
  if (param_1 < 10) {
    _DAT_800ab58c = 1;
    iVar1 = (int)(short)param_1;
    _DAT_800ab590 = iVar1;
    FUN_8006db7c();
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}



// ---- FUN_8006311c @ 8006311c

/* WARNING: Removing unreachable block (ram,0x80063178) */
/* WARNING: Removing unreachable block (ram,0x8006313c) */
/* WARNING: Removing unreachable block (ram,0x8006314c) */
/* WARNING: Removing unreachable block (ram,0x80063154) */
/* WARNING: Removing unreachable block (ram,0x80063188) */
/* WARNING: Removing unreachable block (ram,0x80063190) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8006311c(short param_1,short param_2)

{
  _DAT_800ab58c = 6;
  _DAT_800ab594 = (undefined2)((param_1 * 0x7fff) / 0x7f);
  _DAT_800ab596 = (undefined2)((param_2 * 0x7fff) / 0x7f);
  FUN_8006db7c();
  return;
}



// ---- FUN_800631d8 @ 800631d8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800631d8(short param_1)

{
  _DAT_800ab58c = 0x10;
  _DAT_800ab59c = (int)param_1;
  FUN_8006db7c(&DAT_800ab58c);
  return;
}



// ---- FUN_80063218 @ 80063218

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80063218(short param_1)

{
  _DAT_800ab58c = 8;
  _DAT_800ab598 = (int)param_1;
  FUN_8006db7c(&DAT_800ab58c);
  return;
}



// ---- FUN_80063258 @ 80063258

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80063258(short param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = 0xffffffff;
  if (*(char *)(param_1 + -0x7ff51188) == '\x01') {
    puVar2 = *(undefined4 **)(param_1 * 4 + -0x7ff5495c);
    *param_2 = *puVar2;
    param_2[2] = puVar2[2];
    param_2[1] = puVar2[1];
    *(undefined2 *)((int)param_2 + 0x12) = *(undefined2 *)((int)puVar2 + 0x12);
    *(undefined2 *)(param_2 + 5) = *(undefined2 *)(puVar2 + 5);
    _DAT_800abfd4 = puVar2;
    *(undefined2 *)((int)param_2 + 0x16) = *(undefined2 *)((int)puVar2 + 0x16);
    *(undefined1 *)(param_2 + 6) = *(undefined1 *)(puVar2 + 6);
    *(undefined1 *)((int)param_2 + 0x19) = *(undefined1 *)((int)_DAT_800abfd4 + 0x19);
    *(undefined1 *)((int)param_2 + 0x1a) = *(undefined1 *)((int)_DAT_800abfd4 + 0x1a);
    uVar1 = 0;
    *(undefined1 *)((int)param_2 + 0x1b) = *(undefined1 *)((int)_DAT_800abfd4 + 0x1b);
  }
  return uVar1;
}



// ---- FUN_8006333c @ 8006333c

uint FUN_8006333c(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  ushort uVar7;
  ushort uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar10 = 0xffff;
  uVar9 = 0xffff;
  uVar8 = 0xffff;
  uVar7 = 0xffff;
  bVar5 = 99;
  bVar6 = 99;
  bVar4 = 0;
  if (DAT_800adda8 != 0) {
    do {
      uVar3 = (uint)bVar4;
      iVar2 = uVar3 * 0x18;
      bVar4 = bVar4 + 1;
      if ((*(char *)(iVar2 + -0x7ff55141) == '\0') && (*(short *)(&DAT_800aaeae + iVar2) == 0)) {
        return uVar3;
      }
    } while (bVar4 < DAT_800adda8);
    bVar4 = 0;
    if (DAT_800adda8 != 0) {
      uVar3 = 0;
      do {
        bVar1 = DAT_800adda8;
        iVar2 = uVar3 * 0x18;
        if (*(char *)(iVar2 + -0x7ff55141) == '\0') {
          uVar3 = (uint)*(short *)(iVar2 + -0x7ff55144);
          if ((int)uVar3 < (int)(uVar10 & 0xffff)) {
            uVar8 = *(ushort *)(&DAT_800aaeae + iVar2);
            uVar10 = uVar3;
            bVar5 = bVar4;
          }
          else if ((uVar3 == (uVar10 & 0xffff)) && (*(ushort *)(&DAT_800aaeae + iVar2) < uVar8)) {
            uVar8 = *(ushort *)(&DAT_800aaeae + iVar2);
            bVar5 = bVar4;
          }
        }
        else if ((bVar5 == 99) &&
                (uVar3 = (uint)*(short *)(iVar2 + -0x7ff55144),
                (int)uVar3 <= (int)(uint)DAT_800ae5df)) {
          if ((int)uVar3 < (int)(uVar9 & 0xffff)) {
            uVar7 = *(ushort *)(&DAT_800aaeae + iVar2);
            uVar9 = uVar3;
          }
          else {
            if ((uVar3 != (uVar9 & 0xffff)) || (uVar7 <= *(ushort *)(&DAT_800aaeae + iVar2)))
            goto LAB_8006351c;
            uVar7 = *(ushort *)(&DAT_800aaeae + iVar2);
          }
          bVar6 = bVar4;
        }
LAB_8006351c:
        uVar3 = (uint)bVar4;
        bVar4 = bVar4 + 1;
        *(short *)(uVar3 * 0x18 + -0x7ff55156) = *(short *)(uVar3 * 0x18 + -0x7ff55156) + 1;
        uVar3 = (uint)bVar4;
      } while (bVar4 < bVar1);
    }
  }
  uVar9 = (uint)bVar5;
  if ((uVar9 == 99) && (uVar9 = (uint)bVar6, uVar9 == 99)) {
    uVar9 = (uint)DAT_800adda8;
  }
  return uVar9;
}



// ---- FUN_80063594 @ 80063594

/* WARNING: Removing unreachable block (ram,0x800637dc) */
/* WARNING: Removing unreachable block (ram,0x8006367c) */
/* WARNING: Removing unreachable block (ram,0x800635e0) */
/* WARNING: Removing unreachable block (ram,0x800635e8) */
/* WARNING: Removing unreachable block (ram,0x800635d0) */
/* WARNING: Removing unreachable block (ram,0x80063634) */
/* WARNING: Removing unreachable block (ram,0x800636b4) */
/* WARNING: Removing unreachable block (ram,0x80063800) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80063594(undefined4 param_1,undefined2 param_2)

{
  uint uVar1;
  int iVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = ((((uint)DAT_800ae5d4 * (uint)*(byte *)(_DAT_800abfd4 + 0x18) * 0x3fff) / 0x3f01) *
           (uint)DAT_800ae5da * (uint)DAT_800ae5dd) / 0x3f01;
  uVar6 = (uVar5 * *(ushort *)(_DAT_800ae5e6 * 8 + -0x7ff54f16)) / 0x7f;
  uVar5 = (uVar5 * *(ushort *)(_DAT_800ae5e6 * 8 + -0x7ff54f14)) / 0x7f;
  uVar1 = (uint)DAT_800ae5de;
  if (uVar1 < 0x40) {
    uVar5 = uVar5 * uVar1 >> 6;
  }
  else {
    uVar6 = uVar6 * (0x7f - uVar1) >> 6;
  }
  uVar1 = (uint)DAT_800ae5db;
  if (uVar1 < 0x40) {
    uVar5 = uVar5 * uVar1 >> 6;
  }
  else {
    uVar6 = uVar6 * (0x7f - uVar1) >> 6;
  }
  uVar1 = (uint)DAT_800ae5d5;
  if (uVar1 < 0x40) {
    uVar5 = uVar5 * uVar1 >> 6;
  }
  else {
    uVar6 = uVar6 * (0x7f - uVar1) >> 6;
  }
  uVar1 = uVar6 * uVar6;
  if (_DAT_800abf9c == 1) {
    if (uVar6 < uVar5) {
      uVar6 = uVar5;
    }
    uVar1 = uVar6 * uVar6;
    uVar5 = uVar6;
  }
  iVar2 = ((int)_DAT_800ae5ea & 0x1fffU) * 0x10;
  *(undefined2 *)(iVar2 + -0x7ff552ec) = param_2;
  *(short *)(&DAT_800aad10 + iVar2) = (short)(uVar1 / 0x3fff);
  *(short *)(&DAT_800aad12 + iVar2) = (short)((uVar5 * uVar5) / 0x3fff);
  (&DAT_800aae90)[_DAT_800ae5ea] = (&DAT_800aae90)[_DAT_800ae5ea] | 7;
  *(undefined2 *)(_DAT_800ae5ea * 0x18 + -0x7ff55154) = param_2;
  *(undefined1 *)(_DAT_800ae5ea * 0x18 + -0x7ff55141) = 1;
  uVar6 = (uint)_DAT_800ae5ea;
  if ((int)uVar6 < 0x10) {
    uVar4 = (ushort)(1 << (uVar6 & 0x1f));
    uVar3 = 0;
  }
  else {
    uVar4 = 0;
    uVar3 = (ushort)(1 << (uVar6 - 0x10 & 0x1f));
  }
  if ((DAT_800ae5e4 & 4) == 0) {
    _DAT_800ab2e8 = _DAT_800ab2e8 & ~uVar4;
    _DAT_800ab2f0 = _DAT_800ab2f0 & ~uVar3;
  }
  else {
    _DAT_800ab2e8 = uVar4 | _DAT_800ab2e8;
    _DAT_800ab2f0 = uVar3 | _DAT_800ab2f0;
  }
  _DAT_800ab2d0 = uVar4 | _DAT_800ab2d0;
  _DAT_800ab2d8 = uVar3 | _DAT_800ab2d8;
  _DAT_800b062c = _DAT_800b062c & ~_DAT_800ab2d0;
  _DAT_800b0634 = _DAT_800b0634 & ~_DAT_800ab2d8;
  return;
}



// ---- FUN_800639c4 @ 800639c4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800639c4(void)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  ushort uVar4;
  
  uVar3 = (uint)_DAT_800ae5ea;
  if (uVar3 < 0x10) {
    uVar4 = (ushort)(1 << (uVar3 & 0x1f));
    uVar2 = 0;
  }
  else {
    uVar4 = 0;
    uVar2 = (ushort)(1 << (uVar3 - 0x10 & 0x1f));
  }
  iVar1 = uVar3 * 0x18;
  *(undefined1 *)(iVar1 + -0x7ff55141) = 0;
  *(undefined2 *)(iVar1 + -0x7ff55154) = 0;
  *(undefined2 *)(iVar1 + -0x7ff55158) = 0;
  _DAT_800b062c = uVar4 | _DAT_800b062c;
  _DAT_800b0634 = uVar2 | _DAT_800b0634;
  _DAT_800ab2d0 = _DAT_800ab2d0 & ~_DAT_800b062c;
  _DAT_800ab2d8 = _DAT_800ab2d8 & ~_DAT_800b0634;
  return;
}



// ---- FUN_80063a94 @ 80063a94

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte FUN_80063a94(int param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  
  bVar4 = 0;
  bVar2 = 0;
  bVar3 = bVar4;
  if (DAT_800ae5d0 != 0) {
    do {
      iVar1 = ((uint)DAT_800ae5d7 * 0x10 + (uint)bVar2) * 0x20 + _DAT_800abfe4;
      bVar4 = bVar3;
      if ((*(byte *)(iVar1 + 6) <= DAT_800ae5d2) && (DAT_800ae5d2 <= *(byte *)(iVar1 + 7))) {
        bVar4 = bVar3 + 1;
        *(undefined1 *)(param_2 + (uint)bVar3) = *(undefined1 *)(iVar1 + 0x16);
        *(byte *)(param_1 + (uint)bVar3) = bVar2;
      }
      bVar2 = bVar2 + 1;
      bVar3 = bVar4;
    } while (bVar2 < DAT_800ae5d0);
  }
  return bVar4;
}



// ---- FUN_80063b44 @ 80063b44

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80063b44(void)

{
  undefined2 uVar1;
  uint *puVar2;
  int iVar3;
  
  iVar3 = 0;
  puVar2 = (uint *)&DAT_800ab1f0;
  _DAT_800ae5ec = (short)((int)_DAT_800ae5ea << 3);
  _DAT_800ae5ee = (ushort)DAT_800ae5dc + (ushort)DAT_800ae5d7 * 0x10;
  *(undefined2 *)(&DAT_800aaeae + _DAT_800ae5ea * 0x18) = 0x7fff;
  do {
    iVar3 = iVar3 + 1;
    *puVar2 = ~(1 << ((int)_DAT_800ae5ea & 0x1fU)) & *puVar2;
    puVar2 = puVar2 + 1;
  } while (iVar3 < 0x10);
  if ((_DAT_800ae5e8 & 1) == 0) {
    uVar1 = *(undefined2 *)((((short)_DAT_800ae5e8 + -1) / 2) * 0x10 + _DAT_800abfc4 + 0xe);
  }
  else {
    uVar1 = *(undefined2 *)((((short)_DAT_800ae5e8 + -1) / 2) * 0x10 + _DAT_800abfc4 + 0xc);
  }
  *(undefined2 *)(_DAT_800ae5ec * 2 + -0x7ff552ea) = uVar1;
  (&DAT_800aae90)[_DAT_800ae5ea] = (&DAT_800aae90)[_DAT_800ae5ea] | 8;
  iVar3 = _DAT_800abfe4;
  *(undefined2 *)(&DAT_800aad18 + _DAT_800ae5ec * 2) =
       *(undefined2 *)
        (((uint)DAT_800ae5d7 * 0x10 + (uint)DAT_800ae5dc) * 0x20 + _DAT_800abfe4 + 0x10);
  *(short *)(&DAT_800aad1a + _DAT_800ae5ec * 2) =
       *(short *)(((uint)DAT_800ae5d7 * 0x10 + (uint)DAT_800ae5dc) * 0x20 + iVar3 + 0x12) +
       _DAT_800ab6e4;
  (&DAT_800aae90)[_DAT_800ae5ea] = (&DAT_800aae90)[_DAT_800ae5ea] | 0x30;
  return;
}



// ---- FUN_80063d74 @ 80063d74

/* WARNING: Removing unreachable block (ram,0x80063e30) */
/* WARNING: Removing unreachable block (ram,0x80063dc0) */
/* WARNING: Removing unreachable block (ram,0x80063e00) */
/* WARNING: Removing unreachable block (ram,0x80063e54) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80063d74(uint param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = ((((uint)*(ushort *)(_DAT_800ae5e6 * 8 + -0x7ff54f16) * 0x81 * (uint)DAT_800ae5da) / 0x7f)
          * (uint)DAT_800ae5dd) / 0x7f;
  uVar7 = ((((uint)*(ushort *)(_DAT_800ae5e6 * 8 + -0x7ff54f14) * 0x81 * (uint)DAT_800ae5da) / 0x7f)
          * (uint)DAT_800ae5dd) / 0x7f;
  uVar2 = (uint)DAT_800ae5de;
  if (uVar2 < 0x40) {
    uVar7 = uVar7 * uVar2 >> 6;
  }
  else {
    uVar6 = uVar6 * (0x7f - uVar2) >> 6;
  }
  uVar2 = (uint)DAT_800ae5db;
  if (uVar2 < 0x40) {
    uVar7 = uVar7 * uVar2 >> 6;
  }
  else {
    uVar6 = uVar6 * uVar2 >> 6;
  }
  uVar2 = (uint)DAT_800ae5d5;
  if (uVar2 < 0x40) {
    uVar7 = uVar2 * uVar7 >> 6;
  }
  else {
    uVar6 = uVar6 * (0x7f - uVar2) >> 6;
  }
  if (_DAT_800abf9c == 1) {
    if (uVar6 < uVar7) {
      uVar6 = uVar7;
    }
    else {
      uVar7 = uVar6;
    }
  }
  *(ushort *)(DAT_800a000c + 0x1aa) =
       *(ushort *)(DAT_800a000c + 0x1aa) & 0xc0ff |
       ((ushort)DAT_800ae5d2 - (ushort)DAT_800ae5e0 & 0x3f) << 8;
  uVar2 = param_1 & 0xff;
  *(short *)(&DAT_800aad12 + uVar2 * 0x10) = (short)uVar7;
  bVar1 = (&DAT_800aae90)[uVar2];
  *(short *)(&DAT_800aad10 + uVar2 * 0x10) = (short)uVar6;
  (&DAT_800aae90)[uVar2] = bVar1 | 3;
  if (uVar2 < 0x10) {
    uVar5 = (ushort)(1 << (param_1 & 0x1f));
    uVar4 = 0;
  }
  else {
    uVar5 = 0;
    uVar4 = (ushort)(1 << (uVar2 - 0x10 & 0x1f));
  }
  iVar3 = (param_1 & 0xff) * 0x18;
  *(undefined1 *)(iVar3 + -0x7ff55141) = 1;
  *(undefined2 *)(iVar3 + -0x7ff55154) = 10;
  iVar3 = DAT_800a000c;
  _DAT_800ab2d0 = uVar5 | _DAT_800ab2d0;
  _DAT_800ab2d8 = uVar4 | _DAT_800ab2d8;
  _DAT_800b062c = _DAT_800b062c & ~_DAT_800ab2d0;
  _DAT_800b0634 = _DAT_800b0634 & ~_DAT_800ab2d8;
  if ((DAT_800ae5e4 & 4) == 0) {
    _DAT_800ab2e8 = _DAT_800ab2e8 & ~uVar5;
    _DAT_800ab2f0 = _DAT_800ab2f0 & ~uVar4;
  }
  else {
    _DAT_800ab2e8 = uVar5 | _DAT_800ab2e8;
    _DAT_800ab2f0 = uVar4 | _DAT_800ab2f0;
  }
  *(ushort *)(DAT_800a000c + 0x194) = uVar5;
  *(ushort *)(iVar3 + 0x196) = uVar4;
  return;
}



// ---- FUN_80064110 @ 80064110

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80064110(uint param_1,undefined2 param_2,undefined2 param_3)

{
  byte bVar1;
  int iVar2;
  ushort uVar3;
  uint uVar4;
  ushort uVar5;
  
  uVar4 = param_1 & 0xff;
  *(undefined2 *)(&DAT_800aad12 + uVar4 * 0x10) = param_3;
  bVar1 = (&DAT_800aae90)[uVar4];
  *(undefined2 *)(&DAT_800aad10 + uVar4 * 0x10) = param_2;
  (&DAT_800aae90)[uVar4] = bVar1 | 3;
  if (uVar4 < 0x10) {
    uVar5 = (ushort)(1 << (param_1 & 0x1f));
    uVar3 = 0;
  }
  else {
    uVar5 = 0;
    uVar3 = (ushort)(1 << (uVar4 - 0x10 & 0x1f));
  }
  iVar2 = (param_1 & 0xff) * 0x18;
  *(undefined1 *)(iVar2 + -0x7ff55141) = 1;
  *(undefined2 *)(iVar2 + -0x7ff55154) = 10;
  *(undefined2 *)(iVar2 + -0x7ff55156) = 0;
  iVar2 = DAT_800a000c;
  _DAT_800ab2d0 = uVar5 | _DAT_800ab2d0;
  _DAT_800ab2d8 = uVar3 | _DAT_800ab2d8;
  _DAT_800b062c = _DAT_800b062c & ~_DAT_800ab2d0;
  _DAT_800b0634 = _DAT_800b0634 & ~_DAT_800ab2d8;
  *(ushort *)(DAT_800a000c + 0x194) = uVar5;
  *(ushort *)(iVar2 + 0x196) = uVar3;
  return;
}



// ---- FUN_80064240 @ 80064240

void FUN_80064240(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (param_1 & 0xff) * 0x18;
  *(undefined1 *)(iVar2 + -0x7ff55141) = 0;
  iVar1 = DAT_800a000c;
  *(undefined2 *)(iVar2 + -0x7ff55154) = 0;
  *(undefined2 *)(iVar1 + 0x194) = 0;
  *(undefined2 *)(iVar1 + 0x196) = 0;
  return;
}



// ---- FUN_80064284 @ 80064284

/* WARNING: Removing unreachable block (ram,0x800642bc) */
/* WARNING: Removing unreachable block (ram,0x800642cc) */
/* WARNING: Removing unreachable block (ram,0x800642d4) */
/* WARNING: Removing unreachable block (ram,0x800642a8) */

uint FUN_80064284(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = (DAT_800ae5d2 + 0x3c) - (uint)DAT_800ae5e0;
  uVar2 = (uint)(DAT_800ae5e1 >> 3);
  if (0xf < uVar2) {
    uVar2 = 0xf;
  }
  uVar3 = (uint)*(ushort *)(&DAT_8009f430 + ((iVar1 % 0xc) * 0x10 + uVar2) * 2);
  uVar2 = iVar1 / 0xc - 5;
  if ((int)uVar2 < 1) {
    if ((int)uVar2 < 0) {
      uVar3 = (int)uVar3 >> (-uVar2 & 0x1f);
    }
  }
  else {
    uVar3 = uVar3 << (uVar2 & 0x1f);
  }
  return uVar3 & 0xffff;
}



// ---- FUN_80064340 @ 80064340

/* WARNING: Removing unreachable block (ram,0x800643c4) */
/* WARNING: Removing unreachable block (ram,0x800643d4) */
/* WARNING: Removing unreachable block (ram,0x800643dc) */
/* WARNING: Removing unreachable block (ram,0x80064380) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_80064340(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  short sVar3;
  uint uVar4;
  
  iVar1 = ((uint)DAT_800ae5dc + (uint)DAT_800ae5d7 * 0x10) * 0x20 + _DAT_800abfe4;
  uVar4 = (int)((param_2 & 0xffff) + (uint)*(byte *)(iVar1 + 5)) >> 3;
  sVar3 = (short)uVar4;
  if (0xf < uVar4) {
    sVar3 = sVar3 + -0x10;
  }
  iVar1 = (int)(((uint)(0xf < uVar4) + ((param_1 + 0x3c) - (uint)*(byte *)(iVar1 + 4))) * 0x10000)
          >> 0x10;
  uVar2 = (uint)*(ushort *)(&DAT_8009f430 + ((iVar1 % 0xc) * 0x10 + (int)sVar3) * 2);
  uVar4 = (iVar1 / 0xc + -5) * 0x10000 >> 0x10;
  if ((int)uVar4 < 1) {
    if ((int)uVar4 < 0) {
      uVar2 = (int)uVar2 >> (-uVar4 & 0x1f);
    }
  }
  else {
    uVar2 = uVar2 << (uVar4 & 0x1f);
  }
  return uVar2 & 0xffff;
}



// ---- FUN_80064444 @ 80064444

/* WARNING: Removing unreachable block (ram,0x80064584) */
/* WARNING: Removing unreachable block (ram,0x8006450c) */
/* WARNING: Removing unreachable block (ram,0x8006451c) */
/* WARNING: Removing unreachable block (ram,0x80064524) */
/* WARNING: Removing unreachable block (ram,0x80064594) */
/* WARNING: Removing unreachable block (ram,0x8006459c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80064444(uint param_1,short param_2)

{
  short sVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short sVar7;
  
  uVar3 = param_1 & 0xff;
  if (uVar3 < 0x18) {
    iVar6 = uVar3 * 0x18;
    DAT_800ae5d7 = *(byte *)(iVar6 + -0x7ff5514c);
    DAT_800ae5dc = *(byte *)(iVar6 + -0x7ff55148);
    _DAT_800ae5ea = (ushort)param_1 & 0xff;
    iVar5 = (int)param_2;
    iVar4 = (uint)DAT_800ae5dc + (uint)DAT_800ae5d7 * 0x10;
    if (iVar5 < 1) {
      sVar7 = (short)((int)((uint)*(byte *)(iVar4 * 0x20 + _DAT_800abfe4 + 0xc) * iVar5) / 0x7f);
      sVar1 = *(short *)(iVar6 + -0x7ff55150) + sVar7 + -1;
    }
    else {
      iVar5 = (uint)*(byte *)(iVar4 * 0x20 + _DAT_800abfe4 + 0xd) * iVar5;
      sVar7 = (short)(iVar5 % 0x7f);
      sVar1 = *(short *)(iVar6 + -0x7ff55150) + (short)(iVar5 / 0x7f);
    }
    uVar2 = FUN_80064340((int)sVar1,(int)sVar7);
    *(undefined2 *)(uVar3 * 0x10 + -0x7ff552ec) = uVar2;
    (&DAT_800aae90)[param_1 & 0xff] = (&DAT_800aae90)[param_1 & 0xff] | 4;
  }
  return;
}



// ---- FUN_80064628 @ 80064628

void FUN_80064628(void)

{
  return;
}



// ---- FUN_80064630 @ 80064630

void FUN_80064630(void)

{
  return;
}



// ---- FUN_80064640 @ 80064640

void FUN_80064640(short param_1,short param_2,short param_3)

{
  FUN_80064628((int)param_1,(int)param_2,(int)param_3);
  return;
}



// ---- FUN_80064674 @ 80064674

void FUN_80064674(short param_1)

{
  FUN_80064630((int)param_1);
  return;
}



// ---- FUN_80064698 @ 80064698

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80064698(byte param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 *puVar3;
  ushort uVar4;
  
  FUN_8006f164(0);
  _DAT_800ae5c0 = 0;
  _DAT_800ab6e4 = 0;
  FUN_8006e368(0x20,0x800ab230);
  uVar4 = 0;
  uVar1 = 0;
  do {
    *(undefined2 *)(&DAT_800aad10 + uVar1 * 2) = 0;
    uVar4 = uVar4 + 1;
    uVar1 = (uint)uVar4;
  } while (uVar4 < 0xc0);
  uVar4 = 0;
  uVar1 = 0;
  do {
    (&DAT_800aae90)[uVar1] = 0;
    uVar4 = uVar4 + 1;
    uVar1 = (uint)uVar4;
  } while (uVar4 < 0x18);
  _DAT_800b057c = 0;
  uVar4 = 0;
  uVar1 = 0;
  do {
    *(undefined1 *)(uVar1 + 0x800aee78) = 0;
    uVar4 = uVar4 + 1;
    uVar1 = (uint)uVar4;
  } while (uVar4 < 0x10);
  if (param_1 < 0x18) {
    DAT_800adda8 = param_1;
  }
  else {
    DAT_800adda8 = 0x18;
  }
  uVar4 = 0;
  if (DAT_800adda8 != 0) {
    uVar1 = 0;
    do {
      iVar2 = uVar1 * 0x18;
      *(undefined2 *)(iVar2 + -0x7ff55156) = 0x18;
      *(undefined2 *)(iVar2 + -0x7ff55158) = 0xff;
      *(undefined1 *)(iVar2 + -0x7ff55141) = 0;
      *(undefined2 *)(iVar2 + -0x7ff55154) = 0;
      *(undefined2 *)(&DAT_800aaeae + iVar2) = 0;
      *(undefined2 *)(iVar2 + -0x7ff5514e) = 0xffff;
      *(undefined2 *)(iVar2 + -0x7ff5514c) = 0;
      *(undefined2 *)(iVar2 + -0x7ff5514a) = 0;
      *(undefined2 *)(iVar2 + -0x7ff55148) = 0xff;
      puVar3 = (undefined2 *)((uVar1 & 0x1fff) * 0x10 + DAT_800a000c);
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[3] = 0x200;
      puVar3[2] = 0x1000;
      puVar3[4] = 0x80ff;
      puVar3[5] = 0x4000;
      _DAT_800ae5ea = uVar4;
      FUN_800639c4(1);
      uVar4 = uVar4 + 1;
      uVar1 = (uint)uVar4;
    } while (uVar4 < DAT_800adda8);
  }
  uVar4 = 0;
  uVar1 = 0;
  do {
    iVar2 = uVar1 * 8;
    *(undefined2 *)(iVar2 + -0x7ff54f18) = 0x7f;
    *(undefined2 *)(iVar2 + -0x7ff54f16) = 0x7f;
    *(undefined2 *)(iVar2 + -0x7ff54f14) = 0x7f;
    *(undefined2 *)(iVar2 + -0x7ff54f12) = 0x40;
    uVar4 = uVar4 + 1;
    uVar1 = (uint)uVar4;
  } while (uVar4 < 0x21);
  _DAT_800ab2d0 = 0;
  _DAT_800ab2d8 = 0;
  _DAT_800b062c = 0;
  _DAT_800ab2e8 = 0;
  _DAT_800ab2f0 = 0;
  _DAT_800ab58c = 0;
  _DAT_800ab594 = 0x3fff;
  _DAT_800ab596 = 0x3fff;
  _DAT_800ab590 = 0;
  DAT_800aeea4 = 0;
  _DAT_800abf9c = 0;
  _DAT_800abfb4 = 0x80;
  FUN_80064db4();
  return;
}



// ---- FUN_800649a4 @ 800649a4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800649a4(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  DAT_800ae5df = 0x7f;
  _DAT_800ae5ea = FUN_8006333c(0xff);
  _DAT_800ae5ea = _DAT_800ae5ea & 0xff;
  if (_DAT_800ae5ea < DAT_800adda8) {
    FUN_80064110(_DAT_800ae5ea,param_1,param_2,param_3,param_4);
  }
  return;
}



// ---- FUN_80064ac8 @ 80064ac8

void FUN_80064ac8(undefined2 param_1,undefined2 param_2)

{
  FUN_800649a4(param_1,param_2,0x80ff,0x5fc8);
  return;
}



// ---- FUN_80064af4 @ 80064af4

/* WARNING: Removing unreachable block (ram,0x80064c54) */
/* WARNING: Removing unreachable block (ram,0x80064c64) */
/* WARNING: Removing unreachable block (ram,0x80064c6c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80064af4(ushort param_1,short param_2,short param_3,int param_4)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  
  iVar9 = 0;
  FUN_80066bf4((int)param_2,(int)param_3);
  _DAT_800ae5e6 = param_1 & 0xff;
  bVar7 = 0;
  if (DAT_800adda8 != 0) {
    iVar8 = (param_4 + 0xffc0) * 0x10000 >> 0x10;
    uVar3 = 0;
    do {
      iVar4 = uVar3 * 0x18;
      if (((*(ushort *)(iVar4 + -0x7ff5514e) == param_1) &&
          (*(short *)(iVar4 + -0x7ff55146) == param_2)) &&
         (*(short *)(iVar4 + -0x7ff5514a) == param_3)) {
        uVar3 = (uint)*(ushort *)(iVar4 + -0x7ff55150);
        uVar5 = (uint)*(ushort *)(iVar4 + -0x7ff55148) + (uint)DAT_800ae5d7 * 0x10;
        if (iVar8 < 1) {
          if (iVar8 < 0) {
            iVar4 = iVar8 * (uint)*(byte *)((uVar5 & 0xffff) * 0x20 + _DAT_800abfe4 + 0xc);
            iVar2 = iVar4;
            if (iVar4 < 0) {
              iVar2 = iVar4 + 0x3f;
            }
            uVar3 = (uVar3 + (iVar2 >> 6)) - 1;
            iVar2 = iVar4;
            if (iVar4 < 0) {
              iVar2 = iVar4 + 0x3f;
            }
            uVar5 = (iVar4 + (iVar2 >> 6) * -0x40) * 2 + 0x7f;
          }
          else {
            uVar5 = 0;
          }
        }
        else {
          iVar4 = iVar8 * (uint)*(byte *)((uVar5 & 0xffff) * 0x20 + _DAT_800abfe4 + 0xd);
          uVar3 = uVar3 + iVar4 / 0x3f;
          uVar5 = iVar4 % 0x3f << 1;
        }
        uVar6 = (uint)bVar7;
        DAT_800ae5dc = *(undefined1 *)(uVar6 * 0x18 + -0x7ff55148);
        _DAT_800ae5ea = (ushort)bVar7;
        uVar1 = FUN_80064340(uVar3 & 0xffff,uVar5 & 0xffff);
        *(undefined2 *)(uVar6 * 0x10 + -0x7ff552ec) = uVar1;
        iVar9 = iVar9 + 1;
        (&DAT_800aae90)[uVar6] = (&DAT_800aae90)[uVar6] | 4;
      }
      bVar7 = bVar7 + 1;
      uVar3 = (uint)bVar7;
    } while (bVar7 < DAT_800adda8);
  }
  return iVar9;
}



// ---- FUN_80064db4 @ 80064db4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80064db4(void)

{
  short sVar1;
  uint uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  ushort uVar7;
  ushort uVar8;
  uint *puVar9;
  undefined2 *puVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  short *psVar14;
  int iVar15;
  byte *pbVar16;
  undefined2 *puVar17;
  undefined2 *puVar18;
  undefined2 *puVar19;
  undefined2 *puVar20;
  
  uVar12 = 0;
  uVar13 = (uint)DAT_800adda8;
  DAT_800a0210 = DAT_800a0210 + 1 & 0xf;
  puVar9 = (uint *)(&DAT_800ab1f0 + DAT_800a0210 * 4);
  *puVar9 = 0;
  if (uVar13 != 0) {
    psVar14 = (short *)&DAT_800aaeae;
    iVar15 = DAT_800a000c;
    do {
      *psVar14 = *(short *)(iVar15 + 0xc);
      sVar1 = *psVar14;
      psVar14 = psVar14 + 0xc;
      if (sVar1 == 0) {
        *puVar9 = 1 << (uVar12 & 0x1f) | *puVar9;
      }
      uVar12 = uVar12 + 1;
      iVar15 = iVar15 + 0x10;
    } while ((int)uVar12 < (int)uVar13);
  }
  uVar12 = 0xffffffff;
  if (DAT_800aeea4 == '\0') {
    iVar15 = 0;
    puVar9 = (uint *)&DAT_800ab1f0;
    do {
      iVar15 = iVar15 + 1;
      uVar12 = uVar12 & *puVar9;
      puVar9 = puVar9 + 1;
    } while (iVar15 < 0xf);
    uVar13 = 0;
    if (DAT_800adda8 != 0) {
      iVar15 = 0;
      do {
        uVar2 = uVar13 & 0x1f;
        uVar13 = uVar13 + 1;
        if ((uVar12 & 1 << uVar2) != 0) {
          *(undefined1 *)(iVar15 + -0x7ff55141) = 0;
        }
        iVar15 = iVar15 + 0x18;
      } while ((int)uVar13 < (int)(uint)DAT_800adda8);
    }
  }
  pbVar16 = &DAT_800aae90;
  puVar20 = (undefined2 *)&DAT_800aad1a;
  puVar19 = (undefined2 *)&DAT_800aad18;
  iVar15 = 0;
  puVar18 = (undefined2 *)&DAT_800aad12;
  puVar17 = (undefined2 *)&DAT_800aad10;
  _DAT_800ab2d0 = _DAT_800ab2d0 & ~_DAT_800b062c;
  _DAT_800ab2d8 = _DAT_800ab2d8 & ~_DAT_800b0634;
  do {
    if ((*pbVar16 & 1) != 0) {
      puVar10 = (undefined2 *)(iVar15 + DAT_800a000c);
      *puVar10 = *puVar17;
      puVar10[1] = *puVar18;
    }
    if ((*pbVar16 & 4) != 0) {
      *(undefined2 *)(iVar15 + DAT_800a000c + 4) = *(undefined2 *)(iVar15 + -0x7ff552ec);
    }
    if ((*pbVar16 & 8) != 0) {
      *(undefined2 *)(iVar15 + DAT_800a000c + 6) = *(undefined2 *)(iVar15 + -0x7ff552ea);
    }
    puVar18 = puVar18 + 8;
    if ((*pbVar16 & 0x10) != 0) {
      iVar11 = iVar15 + DAT_800a000c;
      *(undefined2 *)(iVar11 + 8) = *puVar19;
      *(undefined2 *)(iVar11 + 10) = *puVar20;
    }
    *pbVar16 = 0;
    uVar8 = _DAT_800b0634;
    uVar7 = _DAT_800b062c;
    uVar6 = _DAT_800ab2f0;
    uVar5 = _DAT_800ab2e8;
    uVar4 = _DAT_800ab2d8;
    uVar3 = _DAT_800ab2d0;
    iVar11 = DAT_800a000c;
    pbVar16 = pbVar16 + 1;
    puVar20 = puVar20 + 8;
    puVar19 = puVar19 + 8;
    iVar15 = iVar15 + 0x10;
    puVar17 = puVar17 + 8;
  } while ((int)pbVar16 < -0x7ff55158);
  _DAT_800b062c = 0;
  _DAT_800b0634 = 0;
  _DAT_800ab2d0 = 0;
  _DAT_800ab2d8 = 0;
  *(ushort *)(DAT_800a000c + 0x18c) = uVar7;
  *(ushort *)(iVar11 + 0x18e) = uVar8;
  *(ushort *)(iVar11 + 0x188) = uVar3;
  *(ushort *)(iVar11 + 0x18a) = uVar4;
  *(undefined2 *)(iVar11 + 0x198) = uVar5;
  *(undefined2 *)(iVar11 + 0x19a) = uVar6;
  return;
}



// ---- FUN_800650b0 @ 800650b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_800650b0(ushort param_1,short param_2,short param_3,undefined2 param_4,short param_5,
                 undefined1 param_6)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  uint uVar6;
  byte *pbVar7;
  int iVar8;
  byte bVar9;
  byte local_130 [128];
  byte local_b0 [128];
  ushort local_30;
  
  iVar8 = (int)param_3;
  local_30 = param_1;
  iVar3 = FUN_80066bf4((int)param_2,iVar8);
  uVar4 = 0xffffffff;
  if (iVar3 == 0) {
    _DAT_800ae5e6 = param_1 & 0xff;
    DAT_800ae5d2 = (undefined1)param_4;
    DAT_800ae5d3 = 0;
    DAT_800ae5d4 = (undefined1)param_5;
    DAT_800ae5d5 = param_6;
    puVar5 = (undefined1 *)(iVar8 * 0x10 + _DAT_800abfc4);
    DAT_800ae5da = puVar5[1];
    DAT_800ae5db = puVar5[4];
    DAT_800ae5d0 = *puVar5;
    uVar4 = 0;
    if ((ushort)DAT_800ae5d7 < *(ushort *)(_DAT_800abfd4 + 0x12)) {
      if (param_5 == 0) {
        FUN_800654b8((int)(short)param_1,(int)param_2,iVar8,param_4);
        uVar4 = 0;
      }
      else {
        bVar1 = FUN_80063a94(local_b0,local_130);
        bVar9 = 0;
        if (bVar1 != 0) {
          uVar6 = 0;
          do {
            _DAT_800ae5e8 = (ushort)local_130[uVar6];
            DAT_800ae5dc = local_b0[uVar6];
            pbVar7 = (byte *)(((uint)DAT_800ae5dc + (uint)DAT_800ae5d7 * 0x10) * 0x20 +
                             _DAT_800abfe4);
            DAT_800ae5df = *pbVar7;
            DAT_800ae5dd = pbVar7[2];
            DAT_800ae5de = pbVar7[3];
            DAT_800ae5e0 = pbVar7[4];
            DAT_800ae5e1 = pbVar7[5];
            DAT_800ae5e4 = pbVar7[1];
            DAT_800ae5e2 = pbVar7[6];
            DAT_800ae5e3 = pbVar7[7];
            uVar6 = FUN_8006333c(0);
            uVar6 = uVar6 & 0xff;
            _DAT_800ae5ea = (short)uVar6;
            if (uVar6 < DAT_800adda8) {
              *(undefined1 *)(uVar6 * 0x18 + -0x7ff55141) = 1;
              *(undefined2 *)(_DAT_800ae5ea * 0x18 + -0x7ff55156) = 0;
              *(ushort *)(_DAT_800ae5ea * 0x18 + -0x7ff5514e) = local_30;
              *(ushort *)(_DAT_800ae5ea * 0x18 + -0x7ff55146) = (ushort)DAT_800ae5d1;
              *(ushort *)(_DAT_800ae5ea * 0x18 + -0x7ff5514c) = (ushort)DAT_800ae5d7;
              *(short *)(_DAT_800ae5ea * 0x18 + -0x7ff5514a) = param_3;
              *(ushort *)(_DAT_800ae5ea * 0x18 + -0x7ff55148) = (ushort)DAT_800ae5dc;
              *(undefined2 *)(_DAT_800ae5ea * 0x18 + -0x7ff55150) = param_4;
              *(ushort *)(_DAT_800ae5ea * 0x18 + -0x7ff55144) = (ushort)DAT_800ae5df;
              *(ushort *)(_DAT_800ae5ea * 0x18 + -0x7ff55158) = _DAT_800ae5e8;
              FUN_80063b44();
              if (_DAT_800ae5e8 == 0xff) {
                FUN_80063d74((int)_DAT_800ae5ea);
              }
              else {
                uVar2 = FUN_80064284();
                FUN_80063594(bVar1,uVar2);
              }
              uVar4 = uVar4 << 4 | (int)_DAT_800ae5ea;
            }
            bVar9 = bVar9 + 1;
            uVar6 = (uint)bVar9;
          } while (bVar9 < bVar1);
        }
      }
    }
    else {
      uVar4 = 0xffffffff;
    }
  }
  return uVar4;
}



// ---- FUN_800654b8 @ 800654b8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_800654b8(short param_1,short param_2,short param_3,uint param_4)

{
  int iVar1;
  byte bVar2;
  char cVar3;
  
  cVar3 = '\0';
  bVar2 = 0;
  if (DAT_800adda8 != 0) {
    do {
      iVar1 = (uint)bVar2 * 0x18;
      if (((((int)*(short *)(iVar1 + -0x7ff55150) == (param_4 & 0xffff)) &&
           (*(short *)(iVar1 + -0x7ff5514a) == param_3)) &&
          (*(short *)(iVar1 + -0x7ff5514e) == param_1)) &&
         (*(short *)(iVar1 + -0x7ff55146) == param_2)) {
        if (*(short *)(iVar1 + -0x7ff55158) == 0xff) {
          cVar3 = cVar3 + '\x01';
          FUN_80064240();
        }
        else {
          _DAT_800ae5ea = (ushort)bVar2;
          FUN_800639c4(0);
          cVar3 = cVar3 + '\x01';
        }
      }
      bVar2 = bVar2 + 1;
    } while (bVar2 < DAT_800adda8);
  }
  return cVar3;
}



// ---- FUN_8006560c @ 8006560c

void FUN_8006560c(short param_1,short param_2,undefined2 param_3,undefined4 param_4,ushort param_5,
                 ushort param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (uint)param_5;
  uVar3 = (uint)param_6;
  if (uVar2 == uVar3) {
    uVar1 = 0x40;
    uVar3 = uVar2;
  }
  else if (uVar3 < uVar2) {
    uVar1 = (uVar3 << 6) / uVar2;
    if (uVar2 == 0) {
      trap(0x1c00);
    }
    if ((uVar2 == 0xffffffff) && (uVar3 == 0x2000000)) {
      trap(0x1800);
    }
    uVar3 = uVar2;
  }
  else {
    if (uVar3 == 0) {
      trap(0x1c00);
    }
    if ((uVar3 == 0xffffffff) && (uVar2 == 0x2000000)) {
      trap(0x1800);
    }
    uVar1 = 0x7f - (uVar2 << 6) / uVar3;
  }
  FUN_800650b0(0x20,(int)param_1,(int)param_2,param_3,uVar3,uVar1 & 0xffff);
  return;
}



// ---- FUN_800656fc @ 800656fc

void FUN_800656fc(short param_1,short param_2,undefined2 param_3)

{
  FUN_800654b8(0x20,(int)param_1,(int)param_2,param_3);
  return;
}



// ---- FUN_80065738 @ 80065738

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_80065738(uint param_1,short param_2,short param_3,short param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = param_1 & 0xff;
  _DAT_800ae5e6 = (short)uVar1;
  if (uVar1 < 0x22) {
    *(short *)(uVar1 * 8 + -0x7ff54f16) = param_2;
    *(short *)(_DAT_800ae5e6 * 8 + -0x7ff54f14) = param_3;
    if (0x7f < *(ushort *)(_DAT_800ae5e6 * 8 + -0x7ff54f16)) {
      *(undefined2 *)(_DAT_800ae5e6 * 8 + -0x7ff54f16) = 0x7f;
    }
    if (0x7f < *(ushort *)(_DAT_800ae5e6 * 8 + -0x7ff54f14)) {
      *(undefined2 *)(_DAT_800ae5e6 * 8 + -0x7ff54f14) = 0x7f;
    }
    uVar2 = param_1 & 0xff;
    if (param_4 == 1) {
      iVar5 = 0;
      if (DAT_800adda8 != 0) {
        iVar3 = 0;
        do {
          iVar3 = iVar3 >> 0x10;
          if (*(byte *)(iVar3 * 0x18 + -0x7ff5514e) == uVar1) {
            iVar4 = (iVar3 << 0x13) >> 0xf;
            *(short *)(&DAT_800aad10 + iVar4) = param_2 * 0x81;
            *(short *)(&DAT_800aad12 + iVar4) = param_3 * 0x81;
            (&DAT_800aae90)[iVar3] = (&DAT_800aae90)[iVar3] | 3;
          }
          iVar5 = iVar5 + 1;
          iVar3 = iVar5 * 0x10000;
        } while (iVar5 * 0x10000 >> 0x10 < (int)(uint)DAT_800adda8);
      }
      uVar2 = param_1 & 0xff;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



// ---- FUN_800658f4 @ 800658f4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_800658f4(uint param_1,undefined2 *param_2,undefined2 *param_3)

{
  int iVar1;
  
  param_1 = param_1 & 0xff;
  _DAT_800ae5e6 = (short)param_1;
  if (param_1 < 0x22) {
    *param_2 = *(undefined2 *)(param_1 * 8 + -0x7ff54f16);
    *param_3 = *(undefined2 *)(_DAT_800ae5e6 * 8 + -0x7ff54f14);
    iVar1 = (int)_DAT_800ae5e6;
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}



// ---- FUN_80065a18 @ 80065a18

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80065a18(short param_1)

{
  uint uVar1;
  byte bVar2;
  
  bVar2 = 0;
  if (DAT_800adda8 != 0) {
    uVar1 = 0;
    do {
      if (*(short *)(uVar1 * 0x18 + -0x7ff5514e) == param_1) {
        _DAT_800ae5ea = (ushort)bVar2;
        FUN_800639c4(0);
      }
      bVar2 = bVar2 + 1;
      uVar1 = (uint)bVar2;
    } while (bVar2 < DAT_800adda8);
  }
  return;
}



// ---- FUN_80065aac @ 80065aac

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_80065aac(short param_1,short param_2,undefined1 param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_80066bf4((int)param_1,(int)param_2);
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    iVar1 = param_2 * 0x10;
    *(undefined1 *)(iVar1 + _DAT_800abfc4 + 1) = param_3;
    uVar2 = (uint)*(byte *)(iVar1 + _DAT_800abfc4 + 1);
  }
  return uVar2;
}



// ---- FUN_80065b1c @ 80065b1c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_80065b1c(short param_1,short param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_80066bf4((int)param_1,(int)param_2);
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    uVar2 = (uint)*(byte *)(param_2 * 0x10 + _DAT_800abfc4 + 1);
  }
  return uVar2;
}



// ---- FUN_80065b6c @ 80065b6c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_80065b6c(short param_1,short param_2,undefined1 param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_80066bf4((int)param_1,(int)param_2);
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    iVar1 = param_2 * 0x10;
    *(undefined1 *)(iVar1 + _DAT_800abfc4 + 4) = param_3;
    uVar2 = (uint)*(byte *)(iVar1 + _DAT_800abfc4 + 4);
  }
  return uVar2;
}



// ---- FUN_80065bdc @ 80065bdc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_80065bdc(short param_1,short param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_80066bf4((int)param_1,(int)param_2);
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    uVar2 = (uint)*(byte *)(param_2 * 0x10 + _DAT_800abfc4 + 4);
  }
  return uVar2;
}



// ---- FUN_80065c2c @ 80065c2c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_80065c2c(short param_1,ushort param_2,byte param_3,short param_4,short param_5,
                 short param_6,short param_7)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  
  if (_DAT_800abfa4 != 1) {
    _DAT_800abfa4 = 1;
    iVar3 = FUN_80066bf4((int)param_1,(int)(short)param_2);
    if (iVar3 == 0) {
      _DAT_800ae5e6 = 0x20;
      DAT_800ae5d2 = (undefined1)param_4;
      DAT_800ae5d3 = (undefined1)param_5;
      iVar6 = (int)param_6;
      iVar3 = (int)param_7;
      DAT_800ae5d4 = (undefined1)param_6;
      if (iVar6 == iVar3) {
        DAT_800ae5d5 = '@';
      }
      else if (iVar3 < iVar6) {
        if (iVar6 == 0) {
          trap(0x1c00);
        }
        if ((iVar6 == -1) && (iVar3 << 6 == -0x80000000)) {
          trap(0x1800);
        }
        DAT_800ae5d5 = (char)((iVar3 << 6) / iVar6);
      }
      else {
        if (iVar3 == 0) {
          trap(0x1c00);
        }
        if ((iVar3 == -1) && (iVar6 << 6 == -0x80000000)) {
          trap(0x1800);
        }
        DAT_800ae5d4 = (undefined1)param_7;
        DAT_800ae5d5 = '\x7f' - (char)((iVar6 << 6) / iVar3);
      }
      puVar4 = (undefined1 *)(((int)((uint)param_2 << 0x10) >> 0xc) + _DAT_800abfc4);
      DAT_800ae5da = puVar4[1];
      DAT_800ae5db = puVar4[4];
      DAT_800ae5d0 = *puVar4;
      iVar3 = (uint)param_3 + (uint)DAT_800ae5d7 * 0x10;
      puVar4 = (undefined1 *)(iVar3 * 0x20 + _DAT_800abfe4);
      DAT_800ae5df = *puVar4;
      _DAT_800ae5e8 = *(short *)(puVar4 + 0x16);
      DAT_800ae5dd = puVar4[2];
      DAT_800ae5de = puVar4[3];
      DAT_800ae5e0 = puVar4[4];
      DAT_800ae5e1 = puVar4[5];
      DAT_800ae5e4 = puVar4[1];
      DAT_800ae5e2 = puVar4[6];
      DAT_800ae5e3 = puVar4[7];
      DAT_800ae5dc = param_3;
      if (_DAT_800ae5e8 != 0) {
        uVar5 = FUN_8006333c();
        uVar5 = uVar5 & 0xff;
        if (uVar5 != DAT_800adda8) {
          _DAT_800ae5ea = (undefined2)uVar5;
          iVar6 = uVar5 * 0x18;
          *(undefined2 *)(iVar6 + -0x7ff5514e) = 0x20;
          *(short *)(iVar6 + -0x7ff55146) = param_1;
          bVar1 = DAT_800ae5d7;
          *(ushort *)(iVar6 + -0x7ff5514a) = param_2;
          *(ushort *)(iVar6 + -0x7ff5514c) = (ushort)bVar1;
          *(short *)(iVar6 + -0x7ff55158) = _DAT_800ae5e8;
          bVar1 = DAT_800ae5dc;
          *(short *)(iVar6 + -0x7ff55150) = param_4;
          *(undefined1 *)(iVar6 + -0x7ff55141) = 1;
          *(undefined2 *)(iVar6 + -0x7ff55156) = 0;
          *(ushort *)(iVar6 + -0x7ff55148) = (ushort)bVar1;
          FUN_80063b44();
          if (_DAT_800ae5e8 == 0xff) {
            FUN_80063d74(uVar5);
          }
          else {
            uVar2 = FUN_80064340((int)param_4,(int)param_5);
            FUN_80063594(1,uVar2);
          }
          if ((DAT_800ae5e4 & 1) != 0) {
            iVar3 = iVar3 * 0x20 + _DAT_800abfe4;
            FUN_80064640(uVar5,*(undefined1 *)(iVar3 + 8),*(undefined1 *)(iVar3 + 9));
          }
          _DAT_800abfa4 = 0;
          return uVar5;
        }
      }
    }
    _DAT_800abfa4 = 0;
  }
  return 0xffffffff;
}



// ---- FUN_80066054 @ 80066054

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80066054(ushort param_1,short param_2,short param_3,short param_4,short param_5)

{
  int iVar1;
  
  if (_DAT_800abfa4 != 1) {
    _DAT_800abfa4 = 1;
    if ((((param_1 < 0x18) &&
         (iVar1 = (short)param_1 * 0x18, *(short *)(iVar1 + -0x7ff55146) == param_2)) &&
        (*(short *)(iVar1 + -0x7ff5514a) == param_3)) &&
       ((*(short *)(iVar1 + -0x7ff55148) == param_4 && (*(short *)(iVar1 + -0x7ff55150) == param_5))
       )) {
      if (*(short *)(iVar1 + -0x7ff55158) == 0xff) {
        FUN_80064240();
      }
      else {
        _DAT_800ae5ea = param_1;
        FUN_800639c4(0);
      }
      _DAT_800abfa4 = 0;
      return 0;
    }
    _DAT_800abfa4 = 0;
  }
  return 0xffffffff;
}



// ---- FUN_80066178 @ 80066178

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80066178(ushort param_1,short param_2,ushort param_3,byte param_4,short param_5,
                short param_6,short param_7,short param_8)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  
  if (_DAT_800abfa4 != 1) {
    _DAT_800abfa4 = 1;
    if ((param_1 < 0x18) && (iVar3 = FUN_80066bf4((int)param_2,(int)(short)param_3), iVar3 == 0)) {
      _DAT_800ae5e6 = 0x20;
      DAT_800ae5d2 = (undefined1)param_5;
      DAT_800ae5d3 = (undefined1)param_6;
      iVar5 = (int)param_7;
      iVar3 = (int)param_8;
      DAT_800ae5d4 = (undefined1)param_7;
      if (iVar5 == iVar3) {
        DAT_800ae5d5 = '@';
      }
      else if (iVar3 < iVar5) {
        if (iVar5 == 0) {
          trap(0x1c00);
        }
        if ((iVar5 == -1) && (iVar3 << 6 == -0x80000000)) {
          trap(0x1800);
        }
        DAT_800ae5d5 = (char)((iVar3 << 6) / iVar5);
      }
      else {
        if (iVar3 == 0) {
          trap(0x1c00);
        }
        if ((iVar3 == -1) && (iVar5 << 6 == -0x80000000)) {
          trap(0x1800);
        }
        DAT_800ae5d4 = (undefined1)param_8;
        DAT_800ae5d5 = '\x7f' - (char)((iVar5 << 6) / iVar3);
      }
      puVar4 = (undefined1 *)(((int)((uint)param_3 << 0x10) >> 0xc) + _DAT_800abfc4);
      DAT_800ae5da = puVar4[1];
      DAT_800ae5db = puVar4[4];
      DAT_800ae5d0 = *puVar4;
      puVar4 = (undefined1 *)(((uint)param_4 + (uint)DAT_800ae5d7 * 0x10) * 0x20 + _DAT_800abfe4);
      DAT_800ae5df = *puVar4;
      _DAT_800ae5e8 = *(short *)(puVar4 + 0x16);
      DAT_800ae5dd = puVar4[2];
      DAT_800ae5de = puVar4[3];
      DAT_800ae5e0 = puVar4[4];
      DAT_800ae5e1 = puVar4[5];
      DAT_800ae5e4 = puVar4[1];
      DAT_800ae5e2 = puVar4[6];
      DAT_800ae5e3 = puVar4[7];
      DAT_800ae5dc = param_4;
      if (_DAT_800ae5e8 != 0) {
        iVar3 = (short)param_1 * 0x18;
        _DAT_800ae5ea = param_1;
        *(undefined2 *)(iVar3 + -0x7ff5514e) = 0x20;
        *(short *)(iVar3 + -0x7ff55146) = param_2;
        bVar1 = DAT_800ae5d7;
        *(ushort *)(iVar3 + -0x7ff5514a) = param_3;
        *(ushort *)(iVar3 + -0x7ff5514c) = (ushort)bVar1;
        *(short *)(iVar3 + -0x7ff55158) = _DAT_800ae5e8;
        bVar1 = DAT_800ae5dc;
        *(short *)(iVar3 + -0x7ff55150) = param_5;
        *(undefined1 *)(iVar3 + -0x7ff55141) = 1;
        *(undefined2 *)(iVar3 + -0x7ff55156) = 0;
        *(ushort *)(iVar3 + -0x7ff55148) = (ushort)bVar1;
        FUN_80063b44();
        if (_DAT_800ae5e8 == 0xff) {
          FUN_80063d74((int)(short)param_1);
        }
        else {
          uVar2 = FUN_80064340((int)param_5,(int)param_6);
          FUN_80063594(1,uVar2);
        }
        _DAT_800abfa4 = 0;
        return (int)(short)param_1;
      }
    }
    _DAT_800abfa4 = 0;
  }
  return -1;
}



// ---- FUN_80066568 @ 80066568

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80066568(ushort param_1)

{
  undefined4 uVar1;
  
  if (_DAT_800abfa4 == 1) {
    uVar1 = 0xffffffff;
  }
  else {
    _DAT_800abfa4 = 1;
    uVar1 = 0xffffffff;
    if (param_1 < 0x18) {
      _DAT_800ae5ea = param_1;
      FUN_800639c4(0);
      _DAT_800abfa4 = 0;
      uVar1 = 0;
    }
    else {
      _DAT_800abfa4 = 0;
    }
  }
  return uVar1;
}



// ---- FUN_800665dc @ 800665dc

int FUN_800665dc(undefined4 param_1,short param_2,short param_3,undefined4 param_4,short param_5)

{
  short sVar1;
  
  sVar1 = FUN_80064af4(0x20,(int)param_2,(int)param_3,(int)param_5);
  return -(uint)(sVar1 == 0);
}



// ---- FUN_80066618 @ 80066618

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_80066618(ushort param_1,short param_2,short param_3,short param_4,undefined4 param_5,
            short param_6,short param_7)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 < 0x18) {
    iVar3 = (int)(short)param_1;
    iVar2 = iVar3 * 0x18;
    if (*(short *)(iVar2 + -0x7ff55146) != param_2) {
      return 0xffffffff;
    }
    if (*(short *)(iVar2 + -0x7ff5514a) != param_3) {
      return 0xffffffff;
    }
    if (*(short *)(iVar2 + -0x7ff55150) == param_4) {
      FUN_80066bf4();
      _DAT_800ae5e6 = 0x20;
      DAT_800ae5dc = *(undefined1 *)(iVar2 + -0x7ff55148);
      _DAT_800ae5ea = param_1;
      uVar1 = FUN_80064340((int)param_6,(int)param_7);
      *(undefined2 *)(iVar3 * 0x10 + -0x7ff552ec) = uVar1;
      (&DAT_800aae90)[iVar3] = (&DAT_800aae90)[iVar3] | 4;
      return 0;
    }
  }
  return 0xffffffff;
}



// ---- FUN_80066770 @ 80066770

undefined4
FUN_80066770(ushort param_1,short param_2,short param_3,short param_4,undefined2 param_5,
            undefined2 param_6)

{
  int iVar1;
  int iVar2;
  
  if (param_1 < 0x18) {
    iVar2 = (int)(short)param_1;
    iVar1 = iVar2 * 0x18;
    if (*(short *)(iVar1 + -0x7ff55146) != param_2) {
      return 0xffffffff;
    }
    if (*(short *)(iVar1 + -0x7ff5514a) != param_3) {
      return 0xffffffff;
    }
    if (*(short *)(iVar1 + -0x7ff55150) == param_4) {
      *(undefined2 *)(&DAT_800aad18 + iVar2 * 0x10) = param_5;
      *(undefined2 *)(&DAT_800aad1a + iVar2 * 0x10) = param_6;
      (&DAT_800aae90)[iVar2] = (&DAT_800aae90)[iVar2] | 0x30;
      return 0;
    }
  }
  return 0xffffffff;
}



// ---- FUN_800669d4 @ 800669d4

undefined4 FUN_800669d4(ushort param_1,short param_2,short param_3)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 < 0x18) {
    iVar3 = (int)(short)param_1;
    *(short *)(&DAT_800aad12 + iVar3 * 0x10) = param_3 * 0x81;
    bVar1 = (&DAT_800aae90)[iVar3];
    *(short *)(&DAT_800aad10 + iVar3 * 0x10) = param_2 * 0x81;
    uVar2 = 0;
    (&DAT_800aae90)[iVar3] = bVar1 | 3;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



// ---- FUN_80066aa4 @ 80066aa4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80066aa4(void)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  ushort uVar4;
  
  uVar4 = 0;
  if (DAT_800adda8 != 0) {
    iVar2 = 0;
    do {
      iVar1 = (iVar2 >> 0x10) * 0x18;
      *(undefined2 *)(iVar1 + -0x7ff55156) = 0x18;
      *(undefined2 *)(iVar1 + -0x7ff55158) = 0xff;
      *(undefined1 *)(iVar1 + -0x7ff55141) = 0;
      *(undefined2 *)(iVar1 + -0x7ff55154) = 0;
      *(undefined2 *)(&DAT_800aaeae + iVar1) = 0;
      *(undefined2 *)(iVar1 + -0x7ff5514e) = 0xff;
      *(undefined2 *)(iVar1 + -0x7ff5514c) = 0;
      *(undefined2 *)(iVar1 + -0x7ff5514a) = 0;
      *(undefined2 *)(iVar1 + -0x7ff55148) = 0xff;
      puVar3 = (undefined2 *)((((iVar2 >> 0x10) << 0x13) >> 0xf) + DAT_800a000c);
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[3] = 0x200;
      puVar3[2] = 0x1000;
      puVar3[4] = 0x80ff;
      puVar3[5] = 0x4000;
      _DAT_800ae5ea = uVar4;
      FUN_800639c4(1);
      uVar4 = uVar4 + 1;
      iVar2 = (uint)uVar4 << 0x10;
    } while ((short)uVar4 < (short)(ushort)DAT_800adda8);
  }
  return;
}



// ---- FUN_80066bf4 @ 80066bf4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80066bf4(ushort param_1,short param_2)

{
  int iVar1;
  
  if (param_1 < 0x10) {
    if (*(char *)((short)param_1 + -0x7ff51188) != '\x01') {
      return 0xffffffff;
    }
    iVar1 = (short)param_1 * 4;
    if ((int)param_2 < (int)_DAT_800abfb4) {
      _DAT_800abfc4 = *(int *)(iVar1 + -0x7ff549f4);
      _DAT_800abfd4 = *(undefined4 *)(iVar1 + -0x7ff5495c);
      _DAT_800abfe4 = *(undefined4 *)(iVar1 + -0x7ff548f4);
      DAT_800ae5d1 = (char)param_1;
      DAT_800ae5d6 = (char)param_2;
      DAT_800ae5d7 = *(undefined1 *)(param_2 * 0x10 + *(int *)(iVar1 + -0x7ff549f4) + 8);
      return 0;
    }
  }
  return 0xffffffff;
}



// ---- FUN_80066cc8 @ 80066cc8

byte FUN_80066cc8(byte param_1)

{
  if ((param_1 < 0x19) && (param_1 != 0)) {
    DAT_800adda8 = param_1;
  }
  else {
    param_1 = 0xff;
  }
  return param_1;
}



// ---- FUN_80066d00 @ 80066d00

void FUN_80066d00(undefined1 param_1)

{
  DAT_800aeea4 = param_1;
  return;
}



// ---- FUN_80066d10 @ 80066d10

int FUN_80066d10(undefined4 param_1,short param_2)

{
  short sVar1;
  
  sVar1 = FUN_80066da0(param_1,(int)param_2,0,0);
  return (int)sVar1;
}



// ---- FUN_80066d40 @ 80066d40

int FUN_80066d40(undefined4 param_1,short param_2,undefined4 param_3)

{
  short sVar1;
  
  sVar1 = FUN_80066da0(param_1,(int)param_2,1,param_3);
  return (int)sVar1;
}



// ---- FUN_80066d70 @ 80066d70

int FUN_80066d70(undefined4 param_1,short param_2,undefined4 param_3)

{
  short sVar1;
  
  sVar1 = FUN_80066da0(param_1,(int)param_2,1,param_3);
  return (int)sVar1;
}



// ---- FUN_80066da0 @ 80066da0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_80066da0(uint *param_1,int param_2,short param_3,int param_4)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  uint *puVar8;
  int *piVar9;
  uint uVar10;
  int unaff_s2;
  int local_428 [256];
  undefined1 auStack_28 [8];
  
  iVar3 = FUN_8006f190();
  if (iVar3 != 1) {
    FUN_8006f164(1);
    sVar2 = (short)param_2;
    iVar3 = (int)sVar2;
    if (iVar3 < 0x10) {
      iVar6 = 0;
      if (iVar3 == -1) {
        do {
          if (*(char *)(iVar6 + -0x7ff51188) == '\0') {
            *(undefined1 *)(iVar6 + -0x7ff51188) = 1;
            param_2 = iVar6;
            goto LAB_80066eac;
          }
          iVar6 = iVar6 + 1;
          iVar4 = unaff_s2 << 0x10;
        } while (iVar6 < 0x10);
      }
      else {
        iVar4 = unaff_s2 << 0x10;
        if (*(char *)(iVar3 + -0x7ff51188) == '\0') {
          *(undefined1 *)(iVar3 + -0x7ff51188) = 1;
LAB_80066eac:
          _DAT_800b057c = _DAT_800b057c + 1;
          iVar4 = param_2 << 0x10;
          unaff_s2 = param_2;
        }
      }
      if (iVar4 >> 0x10 < 0x10) {
        *(uint **)((iVar4 >> 0x10) * 4 + -0x7ff5495c) = param_1;
        puVar8 = param_1 + 8;
        _DAT_800abfd4 = param_1;
        if (*param_1 >> 8 == 0x564142) {
          _DAT_800abfb4 = 0x40;
          if (((*param_1 & 0xff) == 0x70) && (_DAT_800abfb4 = 0x40, 4 < (int)param_1[1])) {
            _DAT_800abfb4 = 0x80;
          }
          uVar5 = (uint)_DAT_800abfb4;
          if (*(ushort *)((int)param_1 + 0x12) <= uVar5) {
            *(uint **)(((unaff_s2 << 0x10) >> 0xe) + -0x7ff549f4) = puVar8;
            _DAT_800abfe4 = puVar8 + uVar5 * 4;
            iVar3 = 0;
            uVar10 = 0;
            _DAT_800abfc4 = puVar8;
            if (uVar5 != 0) {
              do {
                puVar8[2] = uVar10;
                if ((char)*puVar8 != '\0') {
                  uVar10 = uVar10 + 1;
                }
                iVar3 = iVar3 + 1;
                puVar8 = puVar8 + 4;
              } while (iVar3 < (int)uVar5);
            }
            *(uint **)(((unaff_s2 << 0x10) >> 0xe) + -0x7ff548f4) = _DAT_800abfe4;
            iVar3 = 0;
            piVar7 = local_428;
            bVar1 = *(byte *)((int)_DAT_800abfd4 + 0x16);
            puVar8 = _DAT_800abfe4 + (uint)*(ushort *)((int)_DAT_800abfd4 + 0x12) * 0x80;
            piVar9 = piVar7 + bVar1;
            do {
              if ((int)piVar7 <= (int)piVar9) {
                iVar6 = (uint)(ushort)*puVar8 << 2;
                if (4 < (int)_DAT_800abfd4[1]) {
                  iVar6 = (uint)(ushort)*puVar8 << 3;
                }
                *piVar7 = iVar6;
                iVar3 = iVar3 + *piVar7;
              }
              piVar7 = piVar7 + 1;
              puVar8 = (uint *)((int)puVar8 + 2);
            } while ((int)piVar7 < (int)auStack_28);
            *(uint **)(((unaff_s2 << 0x10) >> 0xe) + -0x7ff4fa20) = puVar8;
            if (((param_3 != 0) || (param_4 = FUN_8006e3d8(iVar3), param_4 != -1)) &&
               (iVar6 = 0, (uint)(param_4 + iVar3) < 0x80001)) {
              *(int *)(((unaff_s2 << 0x10) >> 0xe) + -0x7ff4fa74) = param_4;
              puVar8 = _DAT_800abfc4;
              uVar5 = 0;
              piVar7 = local_428;
              do {
                iVar6 = iVar6 + *piVar7;
                if ((uVar5 & 1) == 0) {
                  *(short *)(puVar8 + ((int)uVar5 / 2) * 4 + 3) =
                       (short)((uint)(param_4 + iVar6) >> 3);
                }
                else {
                  *(short *)((int)puVar8 + ((int)uVar5 / 2) * 0x10 + 0xe) =
                       (short)((uint)(param_4 + iVar6) >> 3);
                }
                uVar5 = uVar5 + 1;
                piVar7 = piVar7 + 1;
              } while ((int)uVar5 <= (int)(uint)bVar1);
              iVar3 = (int)(short)unaff_s2;
              *(int *)(iVar3 * 4 + -0x7ff4fac4) = iVar6;
              *(undefined1 *)(iVar3 + -0x7ff51188) = 2;
              return iVar3;
            }
          }
        }
      }
      *(undefined1 *)(sVar2 + -0x7ff51188) = 0;
      FUN_8006f164(0);
      _DAT_800b057c = _DAT_800b057c + -1;
    }
    else {
      FUN_8006f164(0);
    }
  }
  return -1;
}



// ---- FUN_800671d4 @ 800671d4

/* WARNING: Removing unreachable block (ram,0x8006724c) */
/* WARNING: Removing unreachable block (ram,0x80067210) */
/* WARNING: Removing unreachable block (ram,0x80067220) */
/* WARNING: Removing unreachable block (ram,0x80067228) */
/* WARNING: Removing unreachable block (ram,0x8006725c) */
/* WARNING: Removing unreachable block (ram,0x80067264) */

void FUN_800671d4(ushort *param_1)

{
  undefined4 local_40;
  ushort local_3c;
  ushort local_3a;
  
  local_40 = 3;
  FUN_8006c7e8(0,0x101,&local_40);
  *param_1 = local_3c / 0x81;
  param_1[1] = local_3a / 0x81;
  return;
}



// ---- FUN_80067284 @ 80067284

void FUN_80067284(short param_1,short param_2)

{
  undefined4 local_40;
  short local_3c;
  short local_3a;
  
  local_40 = 3;
  local_3c = param_1 * 0x81;
  local_3a = param_2 * 0x81;
  FUN_8006c7e8(0,0x100,&local_40);
  return;
}



// ---- FUN_800672dc @ 800672dc

void FUN_800672dc(uint param_1,uint param_2,undefined2 param_3,undefined2 param_4)

{
  FUN_8006560c((int)(param_1 << 8) >> 0x10,param_1 & 0xff,(int)(param_2 << 8) >> 0x10,param_2 & 0xff
               ,param_3,param_4);
  return;
}



// ---- FUN_80067328 @ 80067328

int FUN_80067328(undefined4 param_1,ushort param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_2 < 0x11) {
    iVar4 = (int)(short)param_2;
    if (*(char *)(iVar4 + -0x7ff51188) != '\x02') {
      return -1;
    }
    uVar3 = *(undefined4 *)(iVar4 * 4 + -0x7ff4fa74);
    FUN_8006f1a0(0);
    FUN_8006f1f4(uVar3);
    piVar2 = (int *)(iVar4 * 4 + -0x7ff4fac4);
    iVar1 = FUN_8006f244(param_1,*piVar2);
    if (iVar1 == *piVar2) {
      *(undefined1 *)(iVar4 + -0x7ff51188) = 1;
      return iVar4;
    }
  }
  return -1;
}



// ---- FUN_800673f8 @ 800673f8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_800673f8(undefined4 param_1,short param_2)

{
  bool bVar1;
  uint uVar2;
  uint unaff_s0;
  
  if (_DAT_800ae5c8 == 0xffffffff) {
    FUN_80058614(s_Can_t_Open_Sequence_data_any_mor_80029704);
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
    bVar1 = false;
    do {
      if ((1 << (uVar2 & 0x1f) & _DAT_800ae5c8) == 0) {
        bVar1 = true;
        unaff_s0 = uVar2;
      }
      uVar2 = uVar2 + 1;
    } while (!bVar1);
    uVar2 = (uint)(short)unaff_s0;
    _DAT_800ae5c8 = 1 << (uVar2 & 0x1f) | _DAT_800ae5c8;
    FUN_80067958(uVar2,(int)param_2,param_1);
  }
  return uVar2;
}



// ---- FUN_800674a8 @ 800674a8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_800674a8(int param_1,short param_2,short param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint unaff_s2;
  
  if (_DAT_800ae5c8 == 0xffffffff) {
    FUN_80058614(s_Can_t_Open_Sequence_data_any_mor_80029704);
    iVar2 = -1;
  }
  else {
    uVar4 = 0;
    bVar1 = false;
    do {
      if ((1 << (uVar4 & 0x1f) & _DAT_800ae5c8) == 0) {
        bVar1 = true;
        unaff_s2 = uVar4;
      }
      uVar4 = uVar4 + 1;
    } while (!bVar1);
    iVar2 = 0;
    _DAT_800ae5c8 = 1 << (unaff_s2 & 0x1f) | _DAT_800ae5c8;
    if (0 < param_3) {
      do {
        iVar3 = FUN_800675c8((int)(short)unaff_s2,(int)(short)iVar2,(int)param_2,param_1);
        param_1 = param_1 + iVar3;
        iVar2 = iVar2 + 1;
      } while (iVar2 * 0x10000 >> 0x10 < (int)param_3);
    }
    iVar2 = (int)(short)unaff_s2;
  }
  return iVar2;
}



// ---- FUN_800675c8 @ 800675c8

/* WARNING: Removing unreachable block (ram,0x80067770) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_800675c8(ushort param_1,short param_2,undefined2 param_3,int param_4)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined2 uVar8;
  int iVar9;
  undefined1 *puVar10;
  short sVar11;
  int iVar12;
  byte *pbVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  
  iVar14 = 0;
  iVar16 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + ((int)((uint)param_1 << 0x10) >> 0xe));
  *(undefined2 *)(iVar16 + 0x48) = 0;
  *(undefined1 *)(iVar16 + 0x13) = 0;
  *(undefined1 *)(iVar16 + 0x14) = 0;
  *(undefined1 *)(iVar16 + 0x29) = 0;
  *(undefined1 *)(iVar16 + 0x15) = 0;
  *(undefined1 *)(iVar16 + 0x16) = 0;
  *(undefined1 *)(iVar16 + 0x2a) = 0;
  *(undefined1 *)(iVar16 + 0x12) = 0;
  *(undefined4 *)(iVar16 + 0x7c) = 0;
  *(undefined4 *)(iVar16 + 0x80) = 0;
  *(undefined4 *)(iVar16 + 0x84) = 0;
  *(undefined2 *)(iVar16 + 0x70) = 0;
  *(undefined2 *)(iVar16 + 0x46) = 0;
  *(undefined1 *)(iVar16 + 0x2b) = 0;
  *(undefined4 *)(iVar16 + 0x88) = 0;
  *(undefined1 *)(iVar16 + 0x27) = 0;
  *(undefined1 *)(iVar16 + 0x28) = 0;
  *(undefined1 *)(iVar16 + 0x10) = 0;
  *(undefined1 *)(iVar16 + 0x11) = 0;
  *(undefined2 *)(iVar16 + 0x4a) = param_3;
  iVar9 = iVar16;
  iVar12 = iVar16;
  do {
    *(char *)(iVar9 + 0x2c) = (char)iVar14;
    *(undefined1 *)(iVar9 + 0x17) = 0x40;
    *(undefined2 *)(iVar12 + 0x4c) = 0x7f;
    iVar12 = iVar12 + 2;
    iVar14 = iVar14 + 1;
    iVar9 = iVar9 + 1;
  } while (iVar14 < 0x10);
  *(undefined2 *)(iVar16 + 0x6c) = 1;
  *(undefined2 *)(iVar16 + 0x76) = 0x7f;
  *(undefined2 *)(iVar16 + 0x78) = 0x7f;
  *(int *)(iVar16 + 4) = param_4;
  if (param_2 == 0) {
    *(int *)(iVar16 + 4) = param_4 + 8;
    iVar9 = 8;
  }
  else {
    *(int *)(iVar16 + 4) = param_4 + 2;
    iVar9 = 2;
  }
  puVar10 = *(undefined1 **)(iVar16 + 4);
  *(undefined1 **)(iVar16 + 4) = puVar10 + 1;
  uVar1 = *puVar10;
  *(undefined1 **)(iVar16 + 4) = puVar10 + 2;
  pbVar13 = *(byte **)(iVar16 + 4);
  *(ushort *)(iVar16 + 0x48) = CONCAT11(uVar1,puVar10[1]);
  *(byte **)(iVar16 + 4) = pbVar13 + 1;
  bVar2 = *pbVar13;
  *(byte **)(iVar16 + 4) = pbVar13 + 2;
  bVar3 = pbVar13[1];
  *(byte **)(iVar16 + 4) = pbVar13 + 3;
  uVar6 = (uint)bVar2 << 0x10 | (uint)bVar3 << 8 | (uint)pbVar13[2];
  if (uVar6 == 0) {
    trap(0x1c00);
  }
  *(uint *)(iVar16 + 0x84) = uVar6;
  if (uVar6 >> 1 < 60000000U % uVar6) {
    *(uint *)(iVar16 + 0x84) = 60000000 / uVar6 + 1;
  }
  else {
    *(uint *)(iVar16 + 0x84) = 60000000 / uVar6;
  }
  iVar12 = *(int *)(iVar16 + 4);
  *(undefined4 *)(iVar16 + 0x8c) = *(undefined4 *)(iVar16 + 0x84);
  *(int *)(iVar16 + 4) = iVar12 + 3;
  bVar2 = *(byte *)(iVar12 + 2);
  *(int *)(iVar16 + 4) = iVar12 + 4;
  bVar3 = *(byte *)(iVar12 + 3);
  *(int *)(iVar16 + 4) = iVar12 + 5;
  bVar4 = *(byte *)(iVar12 + 4);
  *(int *)(iVar16 + 4) = iVar12 + 6;
  bVar5 = *(byte *)(iVar12 + 5);
  uVar7 = FUN_80069960((int)(short)param_1,(int)param_2);
  iVar12 = _DAT_800b03dc;
  uVar6 = (int)*(short *)(iVar16 + 0x48) * *(int *)(iVar16 + 0x84);
  *(undefined4 *)(iVar16 + 0x7c) = uVar7;
  *(undefined4 *)(iVar16 + 0x88) = uVar7;
  *(undefined4 *)(iVar16 + 0xc) = *(undefined4 *)(iVar16 + 4);
  uVar15 = iVar12 * 0x3c;
  *(undefined4 *)(iVar16 + 8) = *(undefined4 *)(iVar16 + 4);
  if (uVar6 * 10 < uVar15) {
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    uVar8 = (undefined2)((uint)(iVar12 * 600) / uVar6);
    *(undefined2 *)(iVar16 + 0x6c) = uVar8;
    *(undefined2 *)(iVar16 + 0x6e) = uVar8;
  }
  else {
    if (uVar15 == 0) {
      trap(0x1c00);
    }
    if (uVar15 == 0) {
      trap(0x1c00);
    }
    *(undefined2 *)(iVar16 + 0x6c) = 0xffff;
    sVar11 = (short)((uint)((int)*(short *)(iVar16 + 0x48) * *(int *)(iVar16 + 0x84) * 10) / uVar15)
    ;
    *(short *)(iVar16 + 0x6e) = sVar11;
    if ((uint)(iVar12 * 0x1e) <
        (uint)((int)*(short *)(iVar16 + 0x48) * *(int *)(iVar16 + 0x84) * 10) % uVar15) {
      *(short *)(iVar16 + 0x6e) = sVar11 + 1;
    }
  }
  *(undefined2 *)(iVar16 + 0x70) = *(undefined2 *)(iVar16 + 0x6e);
  return iVar9 + 0xb +
         (uint)bVar2 * 0x1000000 + (uint)bVar3 * 0x10000 + (uint)bVar4 * 0x100 + (uint)bVar5;
}



// ---- FUN_80067958 @ 80067958

/* WARNING: Removing unreachable block (ram,0x80067b08) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80067958(ushort param_1,undefined2 param_2,char *param_3)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined2 uVar6;
  int iVar7;
  undefined1 *puVar8;
  short sVar9;
  int iVar10;
  byte *pbVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  
  iVar13 = 0;
  iVar14 = *(int *)(&DAT_800b0424 + ((int)((uint)param_1 << 0x10) >> 0xe));
  *(undefined2 *)(iVar14 + 0x48) = 0;
  *(undefined1 *)(iVar14 + 0x13) = 0;
  *(undefined1 *)(iVar14 + 0x14) = 0;
  *(undefined1 *)(iVar14 + 0x29) = 0;
  *(undefined1 *)(iVar14 + 0x15) = 0;
  *(undefined1 *)(iVar14 + 0x16) = 0;
  *(undefined1 *)(iVar14 + 0x2a) = 0;
  *(undefined1 *)(iVar14 + 0x12) = 0;
  *(undefined4 *)(iVar14 + 0x7c) = 0;
  *(undefined4 *)(iVar14 + 0x80) = 0;
  *(undefined4 *)(iVar14 + 0x84) = 0;
  *(undefined2 *)(iVar14 + 0x70) = 0;
  *(undefined2 *)(iVar14 + 0x46) = 0;
  *(undefined1 *)(iVar14 + 0x2b) = 0;
  *(undefined4 *)(iVar14 + 0x88) = 0;
  *(undefined1 *)(iVar14 + 0x27) = 0;
  *(undefined1 *)(iVar14 + 0x28) = 0;
  *(undefined1 *)(iVar14 + 0x10) = 0;
  *(undefined1 *)(iVar14 + 0x11) = 0;
  *(undefined2 *)(iVar14 + 0x4a) = param_2;
  iVar7 = iVar14;
  iVar10 = iVar14;
  do {
    *(char *)(iVar7 + 0x2c) = (char)iVar13;
    *(undefined1 *)(iVar7 + 0x17) = 0x40;
    *(undefined2 *)(iVar10 + 0x4c) = 0x7f;
    iVar10 = iVar10 + 2;
    iVar13 = iVar13 + 1;
    iVar7 = iVar7 + 1;
  } while (iVar13 < 0x10);
  *(undefined2 *)(iVar14 + 0x6c) = 1;
  *(undefined2 *)(iVar14 + 0x76) = 0x7f;
  *(undefined2 *)(iVar14 + 0x78) = 0x7f;
  *(char **)(iVar14 + 4) = param_3;
  if ((*param_3 == 'S') || (*param_3 == 'p')) {
    *(char **)(iVar14 + 4) = param_3 + 8;
    if (param_3[7] != '\x01') {
      FUN_80058614(s_This_is_not_SEQ_Data__80029728);
      return;
    }
  }
  else {
    FUN_80058614(s_This_is_an_old_SEQ_Data_Format__80029740);
  }
  puVar8 = *(undefined1 **)(iVar14 + 4);
  *(undefined1 **)(iVar14 + 4) = puVar8 + 1;
  uVar1 = *puVar8;
  *(undefined1 **)(iVar14 + 4) = puVar8 + 2;
  pbVar11 = *(byte **)(iVar14 + 4);
  *(ushort *)(iVar14 + 0x48) = CONCAT11(uVar1,puVar8[1]);
  *(byte **)(iVar14 + 4) = pbVar11 + 1;
  bVar2 = *pbVar11;
  *(byte **)(iVar14 + 4) = pbVar11 + 2;
  bVar3 = pbVar11[1];
  *(byte **)(iVar14 + 4) = pbVar11 + 3;
  uVar4 = (uint)bVar2 << 0x10 | (uint)bVar3 << 8 | (uint)pbVar11[2];
  if (uVar4 == 0) {
    trap(0x1c00);
  }
  *(uint *)(iVar14 + 0x84) = uVar4;
  if (uVar4 >> 1 < 60000000U % uVar4) {
    *(uint *)(iVar14 + 0x84) = 60000000 / uVar4 + 1;
  }
  else {
    *(uint *)(iVar14 + 0x84) = 60000000 / uVar4;
  }
  *(undefined4 *)(iVar14 + 0x8c) = *(undefined4 *)(iVar14 + 0x84);
  *(int *)(iVar14 + 4) = *(int *)(iVar14 + 4) + 2;
  uVar5 = FUN_80069960((int)(short)param_1,0);
  iVar7 = _DAT_800b03dc;
  uVar4 = (int)*(short *)(iVar14 + 0x48) * *(int *)(iVar14 + 0x84);
  *(undefined4 *)(iVar14 + 0x7c) = uVar5;
  *(undefined4 *)(iVar14 + 0x88) = uVar5;
  *(undefined4 *)(iVar14 + 0xc) = *(undefined4 *)(iVar14 + 4);
  uVar12 = iVar7 * 0x3c;
  *(undefined4 *)(iVar14 + 8) = *(undefined4 *)(iVar14 + 4);
  if (uVar4 * 10 < uVar12) {
    if (uVar4 == 0) {
      trap(0x1c00);
    }
    uVar6 = (undefined2)((uint)(iVar7 * 600) / uVar4);
    *(undefined2 *)(iVar14 + 0x6c) = uVar6;
    *(undefined2 *)(iVar14 + 0x6e) = uVar6;
  }
  else {
    if (uVar12 == 0) {
      trap(0x1c00);
    }
    if (uVar12 == 0) {
      trap(0x1c00);
    }
    *(undefined2 *)(iVar14 + 0x6c) = 0xffff;
    sVar9 = (short)((uint)((int)*(short *)(iVar14 + 0x48) * *(int *)(iVar14 + 0x84) * 10) / uVar12);
    *(short *)(iVar14 + 0x6e) = sVar9;
    if ((uint)(iVar7 * 0x1e) <
        (uint)((int)*(short *)(iVar14 + 0x48) * *(int *)(iVar14 + 0x84) * 10) % uVar12) {
      *(short *)(iVar14 + 0x6e) = sVar9 + 1;
    }
  }
  *(undefined2 *)(iVar14 + 0x70) = *(undefined2 *)(iVar14 + 0x6e);
  return;
}



// ---- FUN_80067ca0 @ 80067ca0

void FUN_80067ca0(int param_1,short param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + ((param_1 << 0x10) >> 0xe));
  sVar1 = *(short *)(iVar5 + 0x6e);
  iVar3 = *(int *)(iVar5 + 0x88);
  iVar4 = iVar3 - sVar1;
  if (iVar4 < 1) {
    if (sVar1 < iVar3) {
      return;
    }
    do {
      do {
        FUN_80067da8((param_1 << 0x10) >> 0x10,(int)param_2);
      } while (*(int *)(iVar5 + 0x88) == 0);
      iVar3 = iVar3 + *(int *)(iVar5 + 0x88);
      iVar4 = iVar3 - *(short *)(iVar5 + 0x6e);
    } while (iVar3 < *(short *)(iVar5 + 0x6e));
  }
  else {
    sVar2 = *(short *)(iVar5 + 0x6c);
    if (0 < sVar2) {
      *(short *)(iVar5 + 0x6c) = sVar2 + -1;
      return;
    }
    if (sVar2 != 0) {
      *(int *)(iVar5 + 0x88) = iVar4;
      return;
    }
    *(short *)(iVar5 + 0x6c) = sVar1;
    iVar4 = *(int *)(iVar5 + 0x88) + -1;
  }
  *(int *)(iVar5 + 0x88) = iVar4;
  return;
}



// ---- FUN_80067da8 @ 80067da8

void FUN_80067da8(short param_1,short param_2)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  byte bVar3;
  byte *pbVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar7 = (int)param_2;
  iVar8 = (int)param_1;
  iVar6 = iVar7 * 0xa8 + *(int *)(&DAT_800b0424 + iVar8 * 4);
  pbVar4 = *(byte **)(iVar6 + 4);
  *(byte **)(iVar6 + 4) = pbVar4 + 1;
  bVar5 = *pbVar4;
  if ((bVar5 & 0x80) == 0) {
    bVar3 = *(byte *)(iVar6 + 0x11);
    if (bVar3 == 0xc0) {
      FUN_80068140(iVar8,iVar7,bVar5);
      return;
    }
    if (0xc0 < bVar3) {
      if (bVar3 == 0xe0) {
        FUN_80069564(iVar8,iVar7,bVar5);
        return;
      }
      if (bVar3 == 0xff) {
        FUN_80069608(iVar8,iVar7,bVar5);
        return;
      }
      return;
    }
    if (bVar3 != 0x90) {
      if (bVar3 == 0xb0) {
        FUN_800681b0(iVar8,iVar7,bVar5);
        return;
      }
      return;
    }
    *(byte **)(iVar6 + 4) = pbVar4 + 2;
    bVar3 = pbVar4[1];
  }
  else {
    bVar3 = bVar5 & 0xf0;
    *(byte *)(iVar6 + 0x12) = bVar5 & 0xf;
    if (bVar3 == 0xc0) {
      puVar1 = *(undefined1 **)(iVar6 + 4);
      *(undefined1 *)(iVar6 + 0x11) = 0xc0;
      *(undefined1 **)(iVar6 + 4) = puVar1 + 1;
      FUN_80068140(iVar8,iVar7,*puVar1);
      return;
    }
    if (0xc0 < bVar3) {
      if (bVar3 == 0xe0) {
        puVar1 = *(undefined1 **)(iVar6 + 4);
        *(undefined1 *)(iVar6 + 0x11) = 0xe0;
        *(undefined1 **)(iVar6 + 4) = puVar1 + 1;
        FUN_80069564(iVar8,iVar7,*puVar1);
        return;
      }
      if (bVar3 == 0xf0) {
        puVar1 = *(undefined1 **)(iVar6 + 4);
        *(undefined1 *)(iVar6 + 0x11) = 0xff;
        *(byte *)(iVar6 + 0x12) = bVar5 & 0xf;
        *(undefined1 **)(iVar6 + 4) = puVar1 + 1;
        FUN_80069608(iVar8,iVar7,*puVar1);
        return;
      }
      return;
    }
    if (bVar3 != 0x90) {
      if (bVar3 == 0xb0) {
        puVar1 = *(undefined1 **)(iVar6 + 4);
        *(undefined1 *)(iVar6 + 0x11) = 0xb0;
        *(undefined1 **)(iVar6 + 4) = puVar1 + 1;
        FUN_800681b0(iVar8,iVar7,*puVar1);
        return;
      }
      return;
    }
    pbVar4 = *(byte **)(iVar6 + 4);
    *(undefined1 *)(iVar6 + 0x11) = 0x90;
    *(byte **)(iVar6 + 4) = pbVar4 + 1;
    bVar5 = *pbVar4;
    *(byte **)(iVar6 + 4) = pbVar4 + 2;
    bVar3 = pbVar4[1];
  }
  uVar2 = FUN_80069960(iVar8,iVar7);
  *(undefined4 *)(iVar6 + 0x88) = uVar2;
  FUN_80068040(iVar8,iVar7,bVar5,bVar3);
  return;
}



// ---- FUN_80068040 @ 80068040

/* WARNING: Removing unreachable block (ram,0x800680b8) */
/* WARNING: Removing unreachable block (ram,0x800680c8) */
/* WARNING: Removing unreachable block (ram,0x800680d0) */

void FUN_80068040(short param_1,short param_2,undefined1 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = (int)param_2;
  uVar4 = (uint)param_1;
  iVar2 = iVar3 * 0xa8 + *(int *)(&DAT_800b0424 + uVar4 * 4);
  iVar1 = iVar2 + (uint)*(byte *)(iVar2 + 0x12);
  if ((param_4 & 0xff) == 0) {
    FUN_800654b8(iVar3 << 8 | uVar4,(int)*(short *)(iVar2 + 0x4a),*(undefined1 *)(iVar1 + 0x2c),
                 param_3);
  }
  else {
    FUN_800650b0(iVar3 << 8 | uVar4,(int)*(short *)(iVar2 + 0x4a),*(undefined1 *)(iVar1 + 0x2c),
                 param_3,(int)(short)((int)((param_4 & 0xff) *
                                           (int)*(short *)((uint)*(byte *)(iVar2 + 0x12) * 2 + iVar2
                                                          + 0x4c)) / 0x7f),
                 *(undefined1 *)(iVar1 + 0x17));
  }
  return;
}



// ---- FUN_80068140 @ 80068140

void FUN_80068140(short param_1,short param_2,undefined1 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + param_1 * 4);
  *(undefined1 *)(iVar2 + (uint)*(byte *)(iVar2 + 0x12) + 0x2c) = param_3;
  uVar1 = FUN_80069960();
  *(undefined4 *)(iVar2 + 0x88) = uVar1;
  return;
}



// ---- FUN_800681b0 @ 800681b0

/* WARNING: Removing unreachable block (ram,0x8006830c) */
/* WARNING: Removing unreachable block (ram,0x8006831c) */
/* WARNING: Removing unreachable block (ram,0x80068324) */

void FUN_800681b0(ushort param_1,short param_2,byte param_3)

{
  byte bVar1;
  short sVar2;
  undefined4 uVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + ((int)((uint)param_1 << 0x10) >> 0xe));
  pbVar4 = *(byte **)(iVar7 + 4);
  uVar5 = (uint)*(byte *)(iVar7 + 0x12);
  *(byte **)(iVar7 + 4) = pbVar4 + 1;
  bVar1 = *pbVar4;
  uVar6 = (uint)bVar1;
  if (0x79 < param_3) goto switchD_80068248_caseD_2;
  switch(param_3) {
  case 0:
    *(ushort *)(iVar7 + 0x4a) = (ushort)bVar1;
    goto switchD_80068248_caseD_2;
  case 1:
    FUN_80068488((int)(short)param_1,(int)param_2,uVar6);
    break;
  default:
    goto switchD_80068248_caseD_2;
  case 5:
    FUN_800685a8((int)(short)param_1,(int)param_2,uVar6);
    break;
  case 6:
    FUN_80068c4c((int)(short)param_1,(int)param_2,uVar6);
    break;
  case 7:
    *(ushort *)(uVar5 * 2 + iVar7 + 0x4c) = (ushort)bVar1;
    goto switchD_80068248_caseD_2;
  case 10:
    *(byte *)(uVar5 + iVar7 + 0x17) = bVar1;
switchD_80068248_caseD_2:
LAB_80068454:
    uVar3 = FUN_80069960((int)(short)param_1,(int)param_2);
    *(undefined4 *)(iVar7 + 0x88) = uVar3;
    break;
  case 0xb:
    sVar2 = FUN_80065b1c((int)*(short *)(iVar7 + 0x4a),*(undefined1 *)(iVar7 + uVar5 + 0x2c));
    *(short *)(uVar5 * 2 + iVar7 + 0x4c) = (short)((int)(uVar6 * (int)sVar2) / 0x7f);
    uVar3 = FUN_80069960((int)(short)param_1,(int)param_2);
    *(undefined4 *)(iVar7 + 0x88) = uVar3;
    break;
  case 0x40:
    if (uVar6 < 0x40) {
      FUN_8006a14c();
    }
    else {
      FUN_8006a030();
    }
    goto LAB_80068454;
  case 0x41:
    FUN_800686c8((int)(short)param_1,(int)param_2,uVar6);
    break;
  case 0x5b:
    FUN_8006311c(uVar6,uVar6);
    goto LAB_80068454;
  case 0x62:
    FUN_80068920((int)(short)param_1,(int)param_2,uVar6);
    break;
  case 99:
    FUN_80068a44((int)(short)param_1,(int)param_2,uVar6);
    break;
  case 100:
    FUN_80068b6c((int)(short)param_1,(int)param_2,uVar6);
    break;
  case 0x65:
    FUN_80068bdc((int)(short)param_1,(int)param_2,uVar6);
    break;
  case 0x79:
    FUN_80068868((int)(short)param_1,(int)param_2,uVar6);
  }
  return;
}



// ---- FUN_80068488 @ 80068488

void FUN_80068488(ushort param_1,short param_2,undefined1 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte local_58 [16];
  undefined1 auStack_48 [8];
  undefined1 local_40;
  
  iVar3 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + ((int)((uint)param_1 << 0x10) >> 0xe));
  iVar4 = iVar3 + (uint)*(byte *)(iVar3 + 0x12);
  FUN_8006a044((int)*(short *)(iVar3 + 0x4a),*(undefined1 *)(iVar4 + 0x2c),local_58);
  iVar2 = 0;
  if (local_58[0] != 0) {
    do {
      FUN_80069c2c((int)*(short *)(iVar3 + 0x4a),*(undefined1 *)(iVar4 + 0x2c),iVar2,auStack_48);
      local_40 = param_3;
      FUN_80069e68((int)*(short *)(iVar3 + 0x4a),*(undefined1 *)(iVar4 + 0x2c),iVar2,auStack_48);
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(uint)local_58[0]);
  }
  uVar1 = FUN_80069960((int)(short)param_1,(int)param_2);
  *(undefined4 *)(iVar3 + 0x88) = uVar1;
  return;
}



// ---- FUN_800685a8 @ 800685a8

void FUN_800685a8(ushort param_1,short param_2,undefined1 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte local_58 [16];
  undefined1 auStack_48 [11];
  undefined1 local_3d;
  
  iVar3 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + ((int)((uint)param_1 << 0x10) >> 0xe));
  iVar4 = iVar3 + (uint)*(byte *)(iVar3 + 0x12);
  FUN_8006a044((int)*(short *)(iVar3 + 0x4a),*(undefined1 *)(iVar4 + 0x2c),local_58);
  iVar2 = 0;
  if (local_58[0] != 0) {
    do {
      FUN_80069c2c((int)*(short *)(iVar3 + 0x4a),*(undefined1 *)(iVar4 + 0x2c),iVar2,auStack_48);
      local_3d = param_3;
      FUN_80069e68((int)*(short *)(iVar3 + 0x4a),*(undefined1 *)(iVar4 + 0x2c),iVar2,auStack_48);
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(uint)local_58[0]);
  }
  uVar1 = FUN_80069960((int)(short)param_1,(int)param_2);
  *(undefined4 *)(iVar3 + 0x88) = uVar1;
  return;
}



// ---- FUN_800686c8 @ 800686c8

void FUN_800686c8(ushort param_1,short param_2,byte param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte local_60 [16];
  undefined1 uStack_50;
  undefined1 local_4f;
  
  iVar3 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + ((int)((uint)param_1 << 0x10) >> 0xe));
  iVar4 = iVar3 + (uint)*(byte *)(iVar3 + 0x12);
  FUN_8006a044((int)*(short *)(iVar3 + 0x4a),*(undefined1 *)(iVar4 + 0x2c),local_60);
  if (param_3 < 0x40) {
    iVar2 = 0;
    if (local_60[0] != 0) {
      do {
        FUN_80069c2c((int)*(short *)(iVar3 + 0x4a),*(undefined1 *)(iVar4 + 0x2c),iVar2,&uStack_50);
        local_4f = 2;
        FUN_80069e68((int)*(short *)(iVar3 + 0x4a),*(undefined1 *)(iVar4 + 0x2c),iVar2,&uStack_50);
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)(uint)local_60[0]);
    }
  }
  else if (((byte)(param_3 - 0x40) < 0x40) && (iVar2 = 0, local_60[0] != 0)) {
    do {
      FUN_80069c2c((int)*(short *)(iVar3 + 0x4a),*(undefined1 *)(iVar4 + 0x2c),iVar2,&uStack_50);
      local_4f = 0;
      FUN_80069e68((int)*(short *)(iVar3 + 0x4a),*(undefined1 *)(iVar4 + 0x2c),iVar2,&uStack_50);
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(uint)local_60[0]);
  }
  uVar1 = FUN_80069960((int)(short)param_1,(int)param_2);
  *(undefined4 *)(iVar3 + 0x88) = uVar1;
  return;
}



// ---- FUN_80068868 @ 80068868

void FUN_80068868(short param_1,short param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + param_1 * 4);
  FUN_8006308c();
  *(undefined1 *)(iVar2 + (uint)*(byte *)(iVar2 + 0x12) + 0x2c) = *(undefined1 *)(iVar2 + 0x12);
  *(undefined1 *)(iVar2 + 0x13) = 0;
  *(undefined1 *)(iVar2 + 0x14) = 0;
  *(undefined2 *)((uint)*(byte *)(iVar2 + 0x12) * 2 + iVar2 + 0x4c) = 0x7f;
  *(undefined1 *)(iVar2 + (uint)*(byte *)(iVar2 + 0x12) + 0x17) = 0x40;
  uVar1 = FUN_80069960((int)param_1,(int)param_2);
  *(undefined4 *)(iVar2 + 0x88) = uVar1;
  return;
}



// ---- FUN_80068920 @ 80068920

void FUN_80068920(ushort param_1,short param_2,undefined1 param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  
  iVar4 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + ((int)((uint)param_1 << 0x10) >> 0xe));
  if ((*(char *)(iVar4 + 0x27) == '\x01') && (*(char *)(iVar4 + 0x10) == '\0')) {
    *(undefined1 *)(iVar4 + 0x28) = param_3;
    *(undefined1 *)(iVar4 + 0x10) = 1;
  }
  else {
    cVar3 = *(char *)(iVar4 + 0x16);
    if ((cVar3 == '\x1e') || (cVar3 == '\x14')) goto LAB_800689cc;
    *(undefined1 *)(iVar4 + 0x15) = param_3;
    *(char *)(iVar4 + 0x2a) = *(char *)(iVar4 + 0x2a) + '\x01';
  }
  cVar3 = *(char *)(iVar4 + 0x16);
LAB_800689cc:
  if (cVar3 == '(') {
    pcVar1 = *(code **)(param_2 * 4 + (short)param_1 * 0x40 + -0x7ff548a4);
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)((int)(short)param_1,(int)param_2,param_3);
    }
  }
  uVar2 = FUN_80069960((int)(short)param_1,(int)param_2);
  *(undefined4 *)(iVar4 + 0x88) = uVar2;
  return;
}



// ---- FUN_80068a44 @ 80068a44

void FUN_80068a44(short param_1,short param_2,char param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = (int)param_2;
  iVar2 = (int)param_1;
  iVar4 = iVar3 * 0xa8 + *(int *)(&DAT_800b0424 + iVar2 * 4);
  if (param_3 == '\x14') {
    *(undefined1 *)(iVar4 + 0x16) = 0x14;
    *(undefined1 *)(iVar4 + 0x27) = 1;
    uVar1 = FUN_80069960(iVar2,iVar3);
    *(undefined4 *)(iVar4 + 0x88) = uVar1;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar4 + 4);
  }
  else if (param_3 == '\x1e') {
    *(undefined1 *)(iVar4 + 0x16) = 0x1e;
    if (*(byte *)(iVar4 + 0x28) < 0x7f) {
      *(char *)(iVar4 + 0x28) = *(char *)(iVar4 + 0x28) + -1;
      uVar1 = FUN_80069960(iVar2,iVar3);
      *(undefined4 *)(iVar4 + 0x88) = uVar1;
      if (*(char *)(iVar4 + 0x28) == '\0') {
        *(undefined1 *)(iVar4 + 0x10) = 0;
      }
      else {
        *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar4 + 0xc);
      }
    }
    else {
      FUN_80069960(iVar2,iVar3);
      *(undefined4 *)(iVar4 + 0x88) = 0;
      *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar4 + 0xc);
    }
  }
  else {
    *(char *)(iVar4 + 0x16) = param_3;
    *(char *)(iVar4 + 0x2a) = *(char *)(iVar4 + 0x2a) + '\x01';
    uVar1 = FUN_80069960((int)param_1,(int)param_2);
    *(undefined4 *)(iVar4 + 0x88) = uVar1;
  }
  return;
}



// ---- FUN_80068b6c @ 80068b6c

void FUN_80068b6c(short param_1,short param_2,undefined1 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + param_1 * 4);
  *(undefined1 *)(iVar2 + 0x13) = param_3;
  *(char *)(iVar2 + 0x29) = *(char *)(iVar2 + 0x29) + '\x01';
  uVar1 = FUN_80069960();
  *(undefined4 *)(iVar2 + 0x88) = uVar1;
  return;
}



// ---- FUN_80068bdc @ 80068bdc

void FUN_80068bdc(short param_1,short param_2,undefined1 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + param_1 * 4);
  *(undefined1 *)(iVar2 + 0x14) = param_3;
  *(char *)(iVar2 + 0x29) = *(char *)(iVar2 + 0x29) + '\x01';
  uVar1 = FUN_80069960();
  *(undefined4 *)(iVar2 + 0x88) = uVar1;
  return;
}



// ---- FUN_80068c4c @ 80068c4c

/* WARNING: Removing unreachable block (ram,0x80068e40) */

void FUN_80068c4c(short param_1,short param_2,undefined1 param_3)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  byte local_b0 [16];
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined2 local_70;
  
  iVar4 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + param_1 * 4);
  uVar5 = (uint)*(byte *)(iVar4 + 0x12);
  FUN_8006a044((int)*(short *)(iVar4 + 0x4a),*(undefined1 *)(uVar5 + iVar4 + 0x2c),local_b0);
  if ((*(char *)(iVar4 + 0x27) == '\x01') && (*(char *)(iVar4 + 0x10) == '\0')) {
    *(undefined1 *)(iVar4 + 0x28) = param_3;
    *(undefined1 *)(iVar4 + 0x10) = 1;
    uVar1 = FUN_80069960((int)param_1,(int)param_2);
    *(undefined4 *)(iVar4 + 0x88) = uVar1;
  }
  else if ((*(char *)(iVar4 + 0x16) == '\x1e') || (*(char *)(iVar4 + 0x16) == '\x14')) {
    if (*(char *)(iVar4 + 0x29) == '\x02') {
      if (((*(char *)(iVar4 + 0x13) == '\0') && (*(char *)(iVar4 + 0x14) == '\0')) &&
         (iVar3 = 0, local_b0[0] != 0)) {
        do {
          FUN_80069c2c((int)*(short *)(iVar4 + 0x4a),*(undefined1 *)(uVar5 + iVar4 + 0x2c),iVar3,
                       &local_a0);
          local_94 = CONCAT31(CONCAT21(local_94._2_2_,param_3),param_3) & 0xffff7f7f;
          FUN_80069e68((int)*(short *)(iVar4 + 0x4a),*(undefined1 *)(uVar5 + iVar4 + 0x2c),iVar3,
                       &local_a0);
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)(uint)local_b0[0]);
      }
      cVar2 = *(char *)(iVar4 + 0x13);
      if ((cVar2 == '\x01') && (*(char *)(iVar4 + 0x14) == '\0')) {
        iVar3 = 0;
        if (local_b0[0] != 0) {
          do {
            FUN_80069c2c((int)*(short *)(iVar4 + 0x4a),*(undefined1 *)(uVar5 + iVar4 + 0x2c),iVar3,
                         &local_a0);
            FUN_80069e68((int)*(short *)(iVar4 + 0x4a),*(undefined1 *)(uVar5 + iVar4 + 0x2c),iVar3,
                         &local_a0);
            iVar3 = iVar3 + 1;
          } while (iVar3 < (int)(uint)local_b0[0]);
        }
        cVar2 = *(char *)(iVar4 + 0x13);
      }
      if (((cVar2 == '\x02') && (*(char *)(iVar4 + 0x14) == '\0')) && (iVar3 = 0, local_b0[0] != 0))
      {
        do {
          FUN_80069c2c((int)*(short *)(iVar4 + 0x4a),*(undefined1 *)(uVar5 + iVar4 + 0x2c),iVar3,
                       &local_a0);
          FUN_80069e68((int)*(short *)(iVar4 + 0x4a),*(undefined1 *)(uVar5 + iVar4 + 0x2c),iVar3,
                       &local_a0);
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)(uint)local_b0[0]);
      }
      uVar1 = FUN_80069960((int)param_1,(int)param_2);
      *(undefined4 *)(iVar4 + 0x88) = uVar1;
      *(undefined1 *)(iVar4 + 0x29) = 0;
    }
    else if (*(char *)(iVar4 + 0x2a) == '\x02') {
      if (*(char *)(iVar4 + 0x16) == '\x10') {
        iVar3 = 0;
        if (local_b0[0] != 0) {
          do {
            FUN_8006920c((int)*(short *)(iVar4 + 0x4a),*(undefined1 *)(uVar5 + iVar4 + 0x2c),iVar3,
                         local_a0,local_9c,local_98,local_94,local_90,local_8c,local_88,local_84,
                         local_80,local_7c,local_78,local_74,local_70,*(undefined1 *)(iVar4 + 0x15),
                         param_3);
            iVar3 = iVar3 + 1;
          } while (iVar3 < (int)(uint)local_b0[0]);
        }
      }
      else {
        FUN_8006920c((int)*(short *)(iVar4 + 0x4a),*(undefined1 *)(uVar5 + iVar4 + 0x2c),
                     *(char *)(iVar4 + 0x16),local_a0,local_9c,local_98,local_94,local_90,local_8c,
                     local_88,local_84,local_80,local_7c,local_78,local_74,local_70,
                     *(undefined1 *)(iVar4 + 0x15),param_3);
      }
      uVar1 = FUN_80069960((int)param_1,(int)param_2);
      *(undefined4 *)(iVar4 + 0x88) = uVar1;
      *(undefined1 *)(iVar4 + 0x2a) = 0;
    }
    else {
      uVar1 = FUN_80069960((int)param_1,(int)param_2);
      *(undefined4 *)(iVar4 + 0x88) = uVar1;
    }
  }
  else {
    *(undefined1 *)(iVar4 + 0x15) = param_3;
    *(char *)(iVar4 + 0x2a) = *(char *)(iVar4 + 0x2a) + '\x01';
    uVar1 = FUN_80069960((int)param_1,(int)param_2);
    *(undefined4 *)(iVar4 + 0x88) = uVar1;
  }
  return;
}



// ---- FUN_8006920c @ 8006920c

void FUN_8006920c(short param_1,short param_2,short param_3,undefined4 param_4)

{
  undefined4 uVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  undefined4 local_resc;
  undefined4 uStack0000001c;
  undefined4 uStack0000002c;
  ushort uStack00000030;
  ushort uStack00000032;
  ushort uStack00000034;
  undefined2 uStack00000036;
  undefined2 uStack00000038;
  undefined2 uStack0000003a;
  undefined2 in_stack_0000003c;
  undefined4 in_stack_00000040;
  byte in_stack_00000044;
  
  bVar2 = in_stack_00000044;
  uVar1 = in_stack_00000040;
  uVar4 = (uint)in_stack_00000044;
  local_resc = param_4;
  FUN_80069c2c((int)param_1,(int)param_2,(int)param_3,&local_resc);
  if (0x16 < (ushort)uVar1) {
    return;
  }
  uVar3 = (ushort)bVar2;
  switch((ushort)uVar1) {
  case 0:
    local_resc = CONCAT31(local_resc._1_3_,bVar2);
    goto LAB_80069324;
  case 1:
    local_resc._0_2_ = CONCAT11(bVar2,(undefined1)local_resc);
    FUN_80069e68((int)param_1,(int)param_2,(int)param_3,&local_resc);
    if (uVar4 == 0) {
      FUN_8006308c();
      return;
    }
    if (uVar4 == 1) {
      return;
    }
    if (uVar4 == 2) {
      return;
    }
    if (uVar4 == 3) {
      return;
    }
    if (uVar4 == 4) {
      FUN_8006306c();
      return;
    }
    return;
  case 2:
    goto LAB_80069324;
  case 3:
LAB_80069324:
    FUN_80069e68((int)param_1,(int)param_2,(int)param_3,&local_resc);
    return;
  case 4:
    FUN_80069b44((undefined2)uStack0000001c,uStack0000001c._2_2_,&uStack0000002c);
    uStack00000036 = 0;
    uStack0000002c._0_2_ = uVar3;
    break;
  case 5:
    FUN_80069b44((undefined2)uStack0000001c,uStack0000001c._2_2_,&uStack0000002c);
    uStack00000036 = 1;
    uStack0000002c._0_2_ = uVar3;
    break;
  case 6:
    FUN_80069b44((undefined2)uStack0000001c,uStack0000001c._2_2_,&uStack0000002c);
    uStack0000002c._2_2_ = uVar3;
    break;
  case 7:
    FUN_80069b44((undefined2)uStack0000001c,uStack0000001c._2_2_,&uStack0000002c);
    uStack00000030 = uVar3;
    break;
  case 8:
    FUN_80069b44((undefined2)uStack0000001c,uStack0000001c._2_2_,&uStack0000002c);
    uStack00000038 = 0;
    uStack00000032 = uVar3;
    break;
  case 9:
    FUN_80069b44((undefined2)uStack0000001c,uStack0000001c._2_2_,&uStack0000002c);
    uStack00000038 = 1;
    uStack00000032 = uVar3;
    break;
  case 10:
    FUN_80069b44((undefined2)uStack0000001c,uStack0000001c._2_2_,&uStack0000002c);
    uStack0000003a = 0;
    uStack00000034 = uVar3;
    break;
  case 0xb:
    FUN_80069b44((undefined2)uStack0000001c,uStack0000001c._2_2_,&uStack0000002c);
    uStack0000003a = 1;
    uStack00000034 = uVar3;
    break;
  case 0xc:
    FUN_80069b44((undefined2)uStack0000001c,uStack0000001c._2_2_,&uStack0000002c);
    if ((uVar4 == 0) || (0x3f < uVar4)) {
      if (uVar4 - 0x40 < 0x40) {
        in_stack_0000003c = 1;
      }
    }
    else {
      in_stack_0000003c = 0;
    }
    break;
  case 0xd:
    FUN_80069b44((undefined2)uStack0000001c,uStack0000001c._2_2_,&uStack0000002c);
    break;
  case 0xe:
    FUN_80069b44((undefined2)uStack0000001c,uStack0000001c._2_2_,&uStack0000002c);
    break;
  case 0xf:
    FUN_800630ac(uVar4);
    return;
  case 0x10:
    FUN_8006311c(uVar4,uVar4);
    return;
  case 0x11:
    FUN_800631d8(uVar4);
    return;
  case 0x12:
  case 0x13:
    FUN_80063218(uVar4);
  default:
    goto switchD_80069298_caseD_14;
  }
  FUN_80069ba0(&uStack0000002c,&uStack0000001c,(int)&uStack0000001c + 2);
  FUN_80069e68((int)param_1,(int)param_2,(int)param_3,&local_resc);
switchD_80069298_caseD_14:
  return;
}



// ---- FUN_80069564 @ 80069564

void FUN_80069564(short param_1,short param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = (int)param_2;
  uVar5 = (uint)param_1;
  iVar3 = iVar4 * 0xa8 + *(int *)(&DAT_800b0424 + uVar5 * 4);
  puVar2 = *(undefined1 **)(iVar3 + 4);
  *(undefined1 **)(iVar3 + 4) = puVar2 + 1;
  FUN_80064af4(iVar4 << 8 | uVar5,(int)*(short *)(iVar3 + 0x4a),
               *(undefined1 *)((uint)*(byte *)(iVar3 + 0x12) + iVar3 + 0x2c),*puVar2);
  uVar1 = FUN_80069960(uVar5,iVar4);
  *(undefined4 *)(iVar3 + 0x88) = uVar1;
  return;
}



// ---- FUN_80069608 @ 80069608

/* WARNING: Removing unreachable block (ram,0x800696dc) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80069608(short param_1,short param_2,char param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined2 uVar5;
  byte *pbVar6;
  uint uVar7;
  short sVar8;
  int iVar9;
  int *piVar10;
  char *pcVar11;
  int iVar12;
  uint uVar13;
  
  iVar12 = (int)param_2;
  piVar10 = (int *)(&DAT_800b0424 + param_1 * 4);
  iVar9 = iVar12 * 0xa8;
  pcVar11 = (char *)(iVar9 + *piVar10);
  if (param_3 == '/') {
    sVar8 = *(short *)(pcVar11 + 0x46);
    *(short *)(pcVar11 + 0x46) = sVar8 + 1;
    if (*(short *)(pcVar11 + 0x44) == 0) {
      pcVar11[0x80] = '\0';
      pcVar11[0x81] = '\0';
      pcVar11[0x82] = '\0';
      pcVar11[0x83] = '\0';
      pcVar11[0x27] = '\0';
      pcVar11[0x88] = '\0';
      pcVar11[0x89] = '\0';
      pcVar11[0x8a] = '\0';
      pcVar11[0x8b] = '\0';
      *(undefined4 *)(pcVar11 + 4) = *(undefined4 *)(pcVar11 + 8);
    }
    else if ((short)(sVar8 + 1) < *(short *)(pcVar11 + 0x44)) {
      pcVar11[0x80] = '\0';
      pcVar11[0x81] = '\0';
      pcVar11[0x82] = '\0';
      pcVar11[0x83] = '\0';
      pcVar11[0x27] = '\0';
      pcVar11[0x88] = '\0';
      pcVar11[0x89] = '\0';
      pcVar11[0x8a] = '\0';
      pcVar11[0x8b] = '\0';
      *(undefined4 *)(pcVar11 + 4) = *(undefined4 *)(pcVar11 + 8);
      *(undefined4 *)(pcVar11 + 0xc) = *(undefined4 *)(pcVar11 + 8);
    }
    else {
      *(uint *)(iVar9 + *piVar10 + 0x90) = *(uint *)(iVar9 + *piVar10 + 0x90) & 0xfffffffe;
      *(uint *)(iVar9 + *piVar10 + 0x90) = *(uint *)(iVar9 + *piVar10 + 0x90) & 0xfffffff7;
      *(uint *)(iVar9 + *piVar10 + 0x90) = *(uint *)(iVar9 + *piVar10 + 0x90) & 0xfffffffd;
      *(uint *)(iVar9 + *piVar10 + 0x90) = *(uint *)(iVar9 + *piVar10 + 0x90) | 0x200;
      *(uint *)(iVar9 + *piVar10 + 0x90) = *(uint *)(iVar9 + *piVar10 + 0x90) | 4;
      pcVar11[0x2b] = '\0';
      *(undefined4 *)(pcVar11 + 0xc) = *(undefined4 *)(pcVar11 + 8);
      if (*pcVar11 != -1) {
        pcVar11[0x2b] = '\0';
        FUN_80069a14(*pcVar11,iVar12);
      }
      FUN_80065a18(iVar12 << 8 | (int)param_1,iVar12);
      *(int *)(pcVar11 + 0x88) = (int)*(short *)(pcVar11 + 0x6e);
    }
  }
  else if (param_3 == 'Q') {
    pbVar6 = *(byte **)(pcVar11 + 4);
    *(byte **)(pcVar11 + 4) = pbVar6 + 1;
    bVar1 = *pbVar6;
    *(byte **)(pcVar11 + 4) = pbVar6 + 2;
    bVar2 = pbVar6[1];
    *(byte **)(pcVar11 + 4) = pbVar6 + 3;
    iVar9 = _DAT_800b03dc;
    uVar3 = (uint)bVar1 << 0x10 | (uint)bVar2 << 8 | (uint)pbVar6[2];
    uVar13 = 60000000 / uVar3;
    if (uVar3 == 0) {
      trap(0x1c00);
    }
    uVar3 = (int)*(short *)(pcVar11 + 0x48) * uVar13;
    uVar7 = _DAT_800b03dc * 0x3c;
    *(uint *)(pcVar11 + 0x8c) = uVar13;
    if (uVar3 * 10 < uVar7) {
      if (uVar3 == 0) {
        trap(0x1c00);
      }
      uVar5 = (undefined2)((uint)(iVar9 * 600) / uVar3);
      *(undefined2 *)(pcVar11 + 0x6c) = uVar5;
      *(undefined2 *)(pcVar11 + 0x6e) = uVar5;
    }
    else {
      if (uVar7 == 0) {
        trap(0x1c00);
      }
      if (uVar7 == 0) {
        trap(0x1c00);
      }
      pcVar11[0x6c] = -1;
      pcVar11[0x6d] = -1;
      sVar8 = (short)((uint)((int)*(short *)(pcVar11 + 0x48) * *(int *)(pcVar11 + 0x8c) * 10) /
                     uVar7);
      *(short *)(pcVar11 + 0x6e) = sVar8;
      if ((uint)(iVar9 * 0x1e) <
          (uint)((int)*(short *)(pcVar11 + 0x48) * *(int *)(pcVar11 + 0x8c) * 10) % uVar7) {
        *(short *)(pcVar11 + 0x6e) = sVar8 + 1;
      }
    }
    uVar4 = FUN_80069960((int)param_1,(int)param_2);
    *(undefined4 *)(pcVar11 + 0x88) = uVar4;
  }
  return;
}



// ---- FUN_80069960 @ 80069960

int FUN_80069960(int param_1,short param_2)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + ((param_1 << 0x10) >> 0xe));
  pbVar3 = *(byte **)(iVar5 + 4);
  *(byte **)(iVar5 + 4) = pbVar3 + 1;
  bVar1 = *pbVar3;
  uVar4 = (uint)bVar1;
  if (uVar4 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = uVar4 << 2;
    if ((bVar1 & 0x80) != 0) {
      uVar4 = uVar4 & 0x7f;
      do {
        pbVar3 = *(byte **)(iVar5 + 4);
        *(byte **)(iVar5 + 4) = pbVar3 + 1;
        bVar1 = *pbVar3;
        uVar4 = uVar4 * 0x80 + (bVar1 & 0x7f);
      } while ((bVar1 & 0x80) != 0);
      iVar2 = uVar4 * 4;
    }
    iVar2 = (iVar2 + uVar4) * 2;
    *(int *)(iVar5 + 0x80) = iVar2 + *(int *)(iVar5 + 0x80);
  }
  return iVar2;
}



// ---- FUN_80069a14 @ 80069a14

void FUN_80069a14(short param_1,short param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)(&DAT_800b0424 + param_1 * 4);
  iVar1 = param_2 * 0xa8;
  iVar3 = iVar1 + *piVar2;
  *(undefined2 *)(iVar3 + 0x44) = 1;
  *(undefined2 *)(iVar3 + 0x46) = 0;
  FUN_80065738((int)param_1,0x7f,0x7f);
  *(uint *)(iVar1 + *piVar2 + 0x90) = *(uint *)(iVar1 + *piVar2 + 0x90) & 0xfffffeff;
  *(uint *)(iVar1 + *piVar2 + 0x90) = *(uint *)(iVar1 + *piVar2 + 0x90) & 0xfffffff7;
  *(uint *)(iVar1 + *piVar2 + 0x90) = *(uint *)(iVar1 + *piVar2 + 0x90) & 0xfffffffd;
  *(uint *)(iVar1 + *piVar2 + 0x90) = *(uint *)(iVar1 + *piVar2 + 0x90) & 0xfffffffb;
  *(uint *)(iVar1 + *piVar2 + 0x90) = *(uint *)(iVar1 + *piVar2 + 0x90) & 0xfffffdff;
  *(undefined1 *)(iVar3 + 0x2b) = 1;
  *(uint *)(iVar1 + *piVar2 + 0x90) = *(uint *)(iVar1 + *piVar2 + 0x90) | 1;
  return;
}



// ---- FUN_80069b44 @ 80069b44

void FUN_80069b44(uint param_1,uint param_2,ushort *param_3)

{
  ushort uVar1;
  
  param_3[5] = (ushort)param_1 & 0x8000;
  uVar1 = (ushort)param_2;
  param_3[6] = uVar1 & 0x8000;
  param_3[8] = uVar1 & 0x4000;
  param_3[7] = uVar1 & 0x20;
  *param_3 = (ushort)((param_1 & 0xffff) >> 8) & 0x7f;
  param_3[1] = (ushort)((param_1 & 0xffff) >> 4) & 0xf;
  param_3[2] = (ushort)param_1 & 0xf;
  param_3[3] = (ushort)(param_2 >> 6) & 0x7f;
  param_3[4] = uVar1 & 0x1f;
  return;
}



// ---- FUN_80069ba0 @ 80069ba0

void FUN_80069ba0(ushort *param_1,ushort *param_2,ushort *param_3)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar3 = -(ushort)(param_1[6] != 0) & 0x8000;
  if (param_1[8] != 0) {
    uVar3 = uVar3 | 0x4000;
  }
  uVar1 = param_1[3];
  uVar2 = param_1[4];
  *param_2 = -(ushort)(param_1[5] != 0) & 0x8000 | (*param_1 & 0x7f) << 8 | (param_1[1] & 0xf) << 4
             | param_1[2] & 0xf;
  *param_3 = uVar3 | (uVar1 & 0x7f) << 6 | uVar2 & 0x1f;
  return;
}



// ---- FUN_80069c2c @ 80069c2c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80069c2c(short param_1,short param_2,int param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + -0x7ff51188) == '\x01') {
    FUN_80066bf4((int)param_1,(int)param_2);
    iVar2 = (int)((param_3 + (uint)DAT_800ae5d7 * 0x10) * 0x10000) >> 0xb;
    *param_4 = *(undefined1 *)(iVar2 + _DAT_800abfe4);
    param_4[1] = *(undefined1 *)(iVar2 + _DAT_800abfe4 + 1);
    param_4[2] = *(undefined1 *)(iVar2 + _DAT_800abfe4 + 2);
    param_4[3] = *(undefined1 *)(iVar2 + _DAT_800abfe4 + 3);
    param_4[4] = *(undefined1 *)(iVar2 + _DAT_800abfe4 + 4);
    param_4[5] = *(undefined1 *)(iVar2 + _DAT_800abfe4 + 5);
    param_4[7] = *(undefined1 *)(iVar2 + _DAT_800abfe4 + 7);
    param_4[6] = *(undefined1 *)(iVar2 + _DAT_800abfe4 + 6);
    param_4[8] = *(undefined1 *)(iVar2 + _DAT_800abfe4 + 8);
    param_4[9] = *(undefined1 *)(iVar2 + _DAT_800abfe4 + 9);
    param_4[10] = *(undefined1 *)(iVar2 + _DAT_800abfe4 + 10);
    param_4[0xb] = *(undefined1 *)(iVar2 + _DAT_800abfe4 + 0xb);
    param_4[0xc] = *(undefined1 *)(iVar2 + _DAT_800abfe4 + 0xc);
    param_4[0xd] = *(undefined1 *)(iVar2 + _DAT_800abfe4 + 0xd);
    iVar2 = iVar2 + _DAT_800abfe4;
    *(undefined2 *)(param_4 + 0x10) = *(undefined2 *)(iVar2 + 0x10);
    *(undefined2 *)(param_4 + 0x12) = *(undefined2 *)(iVar2 + 0x12);
    *(undefined2 *)(param_4 + 0x14) = *(undefined2 *)(iVar2 + 0x14);
    uVar1 = 0;
    *(undefined2 *)(param_4 + 0x16) = *(undefined2 *)(iVar2 + 0x16);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



// ---- FUN_80069e68 @ 80069e68

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_80069e68(short param_1,short param_2,int param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + -0x7ff51188) == '\x01') {
    FUN_80066bf4((int)param_1,(int)param_2);
    iVar2 = (int)((param_3 + (uint)DAT_800ae5d7 * 0x10) * 0x10000) >> 0xb;
    *(undefined1 *)(iVar2 + _DAT_800abfe4) = *param_4;
    *(undefined1 *)(iVar2 + _DAT_800abfe4 + 1) = param_4[1];
    *(undefined1 *)(iVar2 + _DAT_800abfe4 + 2) = param_4[2];
    *(undefined1 *)(iVar2 + _DAT_800abfe4 + 3) = param_4[3];
    *(undefined1 *)(iVar2 + _DAT_800abfe4 + 4) = param_4[4];
    *(undefined1 *)(iVar2 + _DAT_800abfe4 + 5) = param_4[5];
    *(undefined1 *)(iVar2 + _DAT_800abfe4 + 7) = param_4[7];
    *(undefined1 *)(iVar2 + _DAT_800abfe4 + 6) = param_4[6];
    *(undefined1 *)(iVar2 + _DAT_800abfe4 + 8) = param_4[8];
    *(undefined1 *)(iVar2 + _DAT_800abfe4 + 9) = param_4[9];
    *(undefined1 *)(iVar2 + _DAT_800abfe4 + 10) = param_4[10];
    *(undefined1 *)(iVar2 + _DAT_800abfe4 + 0xb) = param_4[0xb];
    *(undefined1 *)(iVar2 + _DAT_800abfe4 + 0xc) = param_4[0xc];
    *(undefined1 *)(iVar2 + _DAT_800abfe4 + 0xd) = param_4[0xd];
    iVar2 = iVar2 + _DAT_800abfe4;
    *(undefined2 *)(iVar2 + 0x10) = *(undefined2 *)(param_4 + 0x10);
    *(undefined2 *)(iVar2 + 0x12) = *(undefined2 *)(param_4 + 0x12);
    *(undefined2 *)(iVar2 + 0x14) = *(undefined2 *)(param_4 + 0x14);
    uVar1 = 0;
    *(undefined2 *)(iVar2 + 0x16) = *(undefined2 *)(param_4 + 0x16);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



// ---- FUN_8006a030 @ 8006a030

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8006a030(void)

{
  _DAT_800ab6e4 = 2;
  return;
}



// ---- FUN_8006a044 @ 8006a044

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8006a044(short param_1,short param_2,undefined1 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + -0x7ff51188) == '\x01') {
    FUN_80066bf4((int)param_1,(int)param_2);
    iVar2 = param_2 * 0x10;
    *param_3 = *(undefined1 *)(iVar2 + _DAT_800abfc4);
    param_3[1] = *(undefined1 *)(iVar2 + _DAT_800abfc4 + 1);
    param_3[2] = *(undefined1 *)(iVar2 + _DAT_800abfc4 + 2);
    param_3[3] = *(undefined1 *)(iVar2 + _DAT_800abfc4 + 3);
    param_3[4] = *(undefined1 *)(iVar2 + _DAT_800abfc4 + 4);
    uVar1 = 0;
    *(undefined2 *)(param_3 + 6) = *(undefined2 *)(iVar2 + _DAT_800abfc4 + 6);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



// ---- FUN_8006a14c @ 8006a14c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8006a14c(void)

{
  _DAT_800ab6e4 = 0;
  return;
}



// ---- FUN_8006a15c @ 8006a15c

void FUN_8006a15c(short param_1,undefined1 param_2,short param_3)

{
  FUN_8006a290((int)param_1,0,param_2,(int)param_3);
  return;
}



// ---- FUN_8006a194 @ 8006a194

void FUN_8006a194(short param_1,short param_2,undefined1 param_3,short param_4)

{
  FUN_8006a290((int)param_1,(int)param_2,param_3,(int)param_4);
  return;
}



// ---- FUN_8006a1cc @ 8006a1cc

void FUN_8006a1cc(short param_1,short param_2,undefined2 param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(&DAT_800b0424 + param_1 * 4);
  iVar1 = param_2 * 0xa8;
  iVar2 = iVar1 + *piVar3;
  *(uint *)(iVar2 + 0x90) = *(uint *)(iVar2 + 0x90) & 0xfffffdff;
  *(uint *)(iVar1 + *piVar3 + 0x90) = *(uint *)(iVar1 + *piVar3 + 0x90) & 0xfffffffb;
  *(uint *)(iVar1 + *piVar3 + 0x90) = *(uint *)(iVar1 + *piVar3 + 0x90) | 1;
  *(undefined2 *)(iVar2 + 0x44) = param_3;
  *(undefined2 *)(iVar2 + 0x46) = 0;
  *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar2 + 8);
  FUN_80065738((int)param_2 << 8 | (int)param_1,*(undefined2 *)(iVar2 + 0x72),
               *(undefined2 *)(iVar2 + 0x74),0);
  return;
}



// ---- FUN_8006a290 @ 8006a290

void FUN_8006a290(short param_1,short param_2,char param_3,undefined2 param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(&DAT_800b0424 + param_1 * 4);
  iVar1 = param_2 * 0xa8;
  iVar2 = iVar1 + *piVar3;
  *(uint *)(iVar2 + 0x90) = *(uint *)(iVar2 + 0x90) & 0xfffffdff;
  *(uint *)(iVar1 + *piVar3 + 0x90) = *(uint *)(iVar1 + *piVar3 + 0x90) & 0xfffffffb;
  *(undefined2 *)(iVar2 + 0x44) = param_4;
  if (param_3 == '\x01') {
    *(uint *)(iVar1 + *piVar3 + 0x90) = *(uint *)(iVar1 + *piVar3 + 0x90) | 1;
    *(undefined2 *)(iVar2 + 0x46) = 0;
    *(undefined1 *)(iVar2 + 0x2b) = 1;
    FUN_80065738((int)param_2 << 8 | (int)param_1,*(undefined2 *)(iVar2 + 0x72),
                 *(undefined2 *)(iVar2 + 0x74),0);
  }
  else if (param_3 == '\0') {
    *(uint *)(iVar1 + *piVar3 + 0x90) = *(uint *)(iVar1 + *piVar3 + 0x90) | 2;
  }
  return;
}



// ---- FUN_8006a388 @ 8006a388

/* WARNING: Removing unreachable block (ram,0x8006a4f4) */
/* WARNING: Removing unreachable block (ram,0x8006a4b8) */
/* WARNING: Removing unreachable block (ram,0x8006a430) */
/* WARNING: Removing unreachable block (ram,0x8006a3f4) */
/* WARNING: Removing unreachable block (ram,0x8006a404) */
/* WARNING: Removing unreachable block (ram,0x8006a40c) */
/* WARNING: Removing unreachable block (ram,0x8006a440) */
/* WARNING: Removing unreachable block (ram,0x8006a448) */
/* WARNING: Removing unreachable block (ram,0x8006a4c8) */
/* WARNING: Removing unreachable block (ram,0x8006a4d0) */
/* WARNING: Removing unreachable block (ram,0x8006a504) */
/* WARNING: Removing unreachable block (ram,0x8006a50c) */

void FUN_8006a388(char param_1,short param_2,short param_3)

{
  undefined4 local_40 [3];
  undefined2 local_34;
  undefined2 local_32;
  undefined2 local_28;
  undefined2 local_26;
  
  if (param_1 == '\0') {
    local_40[0] = 0x30;
    if (0x7f < param_2) {
      param_2 = 0x7f;
    }
    if (0x7f < param_3) {
      param_3 = 0x7f;
    }
    local_34 = (undefined2)((param_2 * 0x7fff) / 0x7f);
    local_32 = (undefined2)((param_3 * 0x7fff) / 0x7f);
  }
  if (param_1 == '\x01') {
    local_40[0] = 0xc0;
    if (0x7f < param_2) {
      param_2 = 0x7f;
    }
    if (0x7f < param_3) {
      param_3 = 0x7f;
    }
    local_28 = (undefined2)((param_2 * 0x7fff) / 0x7f);
    local_26 = (undefined2)((param_3 * 0x7fff) / 0x7f);
  }
  FUN_8006c7e8(0,0x100,local_40);
  return;
}



// ---- FUN_8006a53c @ 8006a53c

int FUN_8006a53c(short param_1)

{
  short sVar1;
  
  sVar1 = FUN_8006f0b4((int)param_1);
  return (int)sVar1;
}



// ---- FUN_8006a564 @ 8006a564

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8006a564(void)

{
  if (_DAT_800abfa4 != 1) {
    _DAT_800abfa4 = 1;
    FUN_80064db4();
    _DAT_800abfa4 = 0;
  }
  return;
}



// ---- FUN_8006a5a4 @ 8006a5a4

void FUN_8006a5a4(short param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(&DAT_800b0424 + param_1 * 4);
  *(uint *)(*piVar1 + 0x90) = *(uint *)(*piVar1 + 0x90) & 0xfffffffe;
  *(uint *)(*piVar1 + 0x90) = *(uint *)(*piVar1 + 0x90) & 0xfffffffd;
  *(uint *)(*piVar1 + 0x90) = *(uint *)(*piVar1 + 0x90) & 0xfffffff7;
  *(uint *)(*piVar1 + 0x90) = *(uint *)(*piVar1 + 0x90) | 4;
  FUN_8006a6f4((int)param_1,0);
  return;
}



// ---- FUN_8006a638 @ 8006a638

void FUN_8006a638(short param_1,short param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(&DAT_800b0424 + param_1 * 4);
  iVar1 = param_2 * 0xa8;
  *(uint *)(iVar1 + *piVar2 + 0x90) = *(uint *)(iVar1 + *piVar2 + 0x90) & 0xfffffffe;
  *(uint *)(iVar1 + *piVar2 + 0x90) = *(uint *)(iVar1 + *piVar2 + 0x90) & 0xfffffffd;
  *(uint *)(iVar1 + *piVar2 + 0x90) = *(uint *)(iVar1 + *piVar2 + 0x90) & 0xfffffff7;
  *(uint *)(iVar1 + *piVar2 + 0x90) = *(uint *)(iVar1 + *piVar2 + 0x90) | 4;
  FUN_8006a6f4();
  return;
}



// ---- FUN_8006a6f4 @ 8006a6f4

void FUN_8006a6f4(short param_1,short param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + param_1 * 4);
  FUN_80065a18((int)param_2 << 8 | (int)param_1);
  *(undefined1 *)(iVar4 + 0x2b) = 0;
  *(undefined4 *)(iVar4 + 0x80) = 0;
  *(undefined1 *)(iVar4 + 0x27) = 0;
  *(undefined1 *)(iVar4 + 0x13) = 0;
  *(undefined1 *)(iVar4 + 0x14) = 0;
  *(undefined1 *)(iVar4 + 0x29) = 0;
  *(undefined1 *)(iVar4 + 0x15) = 0;
  *(undefined1 *)(iVar4 + 0x16) = 0;
  *(undefined1 *)(iVar4 + 0x2a) = 0;
  *(undefined1 *)(iVar4 + 0x12) = 0;
  *(undefined2 *)(iVar4 + 0x46) = 0;
  *(undefined1 *)(iVar4 + 0x27) = 0;
  *(undefined1 *)(iVar4 + 0x28) = 0;
  *(undefined1 *)(iVar4 + 0x10) = 0;
  *(undefined1 *)(iVar4 + 0x11) = 0;
  iVar2 = 0;
  *(undefined4 *)(iVar4 + 0x88) = *(undefined4 *)(iVar4 + 0x7c);
  *(undefined4 *)(iVar4 + 0x8c) = *(undefined4 *)(iVar4 + 0x84);
  *(undefined2 *)(iVar4 + 0x6e) = *(undefined2 *)(iVar4 + 0x70);
  *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar4 + 8);
  *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar4 + 8);
  iVar1 = iVar4;
  iVar3 = iVar4;
  do {
    *(char *)(iVar1 + 0x2c) = (char)iVar2;
    *(undefined1 *)(iVar1 + 0x17) = 0x40;
    *(undefined2 *)(iVar3 + 0x4c) = 0x7f;
    iVar3 = iVar3 + 2;
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 1;
  } while (iVar2 < 0x10);
  *(undefined2 *)(iVar4 + 0x76) = 0x7f;
  *(undefined2 *)(iVar4 + 0x78) = 0x7f;
  return;
}



// ---- FUN_8006a7fc @ 8006a7fc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8006a7fc(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  
  if (_DAT_800abfa4 != 1) {
    _DAT_800abfa4 = 1;
    uVar3 = 0;
    FUN_80064db4();
    if (0 < _DAT_800b052c) {
      piVar4 = (int *)&DAT_800b0424;
      do {
        if (((1 << (uVar3 & 0x1f) & _DAT_800ae5c8) != 0) && (iVar1 = 0, 0 < _DAT_800b0534)) {
          iVar2 = 0;
          do {
            if ((*(uint *)(iVar2 + *piVar4 + 0x90) & 1) != 0) {
              FUN_8006af08(uVar3,iVar1);
              if ((*(uint *)(iVar2 + *piVar4 + 0x90) & 0x10) != 0) {
                FUN_8006af34(uVar3,iVar1);
              }
              if ((*(uint *)(iVar2 + *piVar4 + 0x90) & 0x20) != 0) {
                FUN_8006aa34(uVar3,iVar1);
              }
              if ((*(uint *)(iVar2 + *piVar4 + 0x90) & 0x40) != 0) {
                FUN_8006b490(uVar3,iVar1);
              }
              if ((*(uint *)(iVar2 + *piVar4 + 0x90) & 0x80) != 0) {
                FUN_8006b490(uVar3,iVar1);
              }
            }
            if ((*(uint *)(iVar2 + *piVar4 + 0x90) & 2) != 0) {
              FUN_8006b3a8(uVar3,iVar1);
            }
            if ((*(uint *)(iVar2 + *piVar4 + 0x90) & 8) != 0) {
              FUN_8006aea8(uVar3,iVar1);
            }
            if ((*(uint *)(iVar2 + *piVar4 + 0x90) & 4) != 0) {
              FUN_8006a6f4(uVar3,iVar1);
              *(undefined4 *)(iVar2 + *piVar4 + 0x90) = 0;
            }
            iVar1 = iVar1 + 1;
            iVar2 = iVar2 + 0xa8;
          } while (iVar1 < _DAT_800b0534);
        }
        uVar3 = uVar3 + 1;
        piVar4 = piVar4 + 1;
      } while ((int)uVar3 < (int)_DAT_800b052c);
    }
    _DAT_800abfa4 = 0;
  }
  return;
}



// ---- FUN_8006aa34 @ 8006aa34

void FUN_8006aa34(ushort param_1,short param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  ushort local_30;
  ushort local_2e [7];
  
  iVar7 = (int)(short)param_1;
  iVar8 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + iVar7 * 4);
  uVar5 = (uint)*(short *)(iVar8 + 0x40);
  uVar2 = *(int *)(iVar8 + 0x98) - 1;
  *(uint *)(iVar8 + 0x98) = uVar2;
  if ((int)uVar5 < 1) {
    if (*(short *)(iVar8 + 0x3c) < 1) {
      if (*(short *)(iVar8 + 0x3c) < 0) {
        iVar3 = *(ushort *)(iVar8 + 0x3e) - uVar5;
        *(short *)(iVar8 + 0x3e) = (short)iVar3;
        if (0 < iVar3 * 0x10000) {
LAB_8006ade0:
          uVar4 = 0x7f;
          uVar6 = 0x7f;
          goto LAB_8006ade8;
        }
        FUN_800658f4(iVar7,&local_30,local_2e);
        uVar2 = (uint)local_30 - (int)*(short *)(iVar8 + 0x40);
        if ((0x7f < (int)uVar2) ||
           (uVar5 = (uint)local_2e[0] - (int)*(short *)(iVar8 + 0x40), 0x7f < (int)uVar5)) {
          FUN_80065738((int)(short)param_1,0x7f,0x7f,0);
          iVar7 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + (short)param_1 * 4);
          goto LAB_8006adfc;
        }
        goto LAB_8006ad7c;
      }
    }
    else {
      iVar3 = *(ushort *)(iVar8 + 0x3e) + uVar5;
      *(short *)(iVar8 + 0x3e) = (short)iVar3;
      if (iVar3 * 0x10000 < 0) {
        uVar4 = 0;
        uVar6 = 0;
LAB_8006ade8:
        FUN_80065738(iVar7,uVar4,uVar6,0);
        iVar7 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + iVar7 * 4);
      }
      else {
        FUN_800658f4(iVar7,&local_30,local_2e);
        iVar3 = (int)*(short *)(iVar8 + 0x40);
        if ((-iVar3 <= (int)(uint)local_30) && (-iVar3 <= (int)(uint)local_2e[0])) {
          uVar2 = (uint)local_30 + iVar3;
          uVar5 = (uint)local_2e[0] + iVar3;
          goto LAB_8006ad7c;
        }
        FUN_80065738((int)(short)param_1,0,0,0);
        iVar7 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + (short)param_1 * 4);
      }
LAB_8006adfc:
      *(uint *)(iVar7 + 0x90) = *(uint *)(iVar7 + 0x90) & 0xffffffdf;
    }
  }
  else {
    if (uVar5 == 0) {
      trap(0x1c00);
    }
    if (uVar2 % uVar5 != 0) goto LAB_8006ae70;
    if (*(short *)(iVar8 + 0x3c) < 1) {
      if (-1 < *(short *)(iVar8 + 0x3c)) goto LAB_8006ae0c;
      uVar1 = *(short *)(iVar8 + 0x3e) + 1;
      *(ushort *)(iVar8 + 0x3e) = uVar1;
      if (0 < (int)((uint)uVar1 << 0x10)) goto LAB_8006ade0;
      FUN_800658f4(iVar7,&local_30,local_2e);
      uVar2 = local_30 + 1;
      if ((0x7f < uVar2) || (uVar5 = local_2e[0] + 1, 0x7f < uVar5)) {
        FUN_80065738((int)(short)param_1,0x7f,0x7f,0);
        iVar7 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + (short)param_1 * 4);
        goto LAB_8006adfc;
      }
    }
    else {
      uVar1 = *(short *)(iVar8 + 0x3e) - 1;
      *(ushort *)(iVar8 + 0x3e) = uVar1;
      if ((int)((uint)uVar1 << 0x10) < 0) {
        uVar4 = 0;
        uVar6 = 0;
        goto LAB_8006ade8;
      }
      FUN_800658f4(iVar7,&local_30,local_2e);
      if ((local_30 == 0) || (local_2e[0] == 0)) {
        FUN_80065738((int)(short)param_1,0,0,0);
        iVar7 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + (short)param_1 * 4);
        goto LAB_8006adfc;
      }
      uVar2 = local_30 - 1;
      uVar5 = local_2e[0] - 1;
    }
LAB_8006ad7c:
    FUN_80065738(iVar7,uVar2,uVar5,0);
  }
LAB_8006ae0c:
  if ((*(int *)(iVar8 + 0x98) == 0) || (*(short *)(iVar8 + 0x3e) == 0)) {
    iVar7 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + ((int)((uint)param_1 << 0x10) >> 0xe));
    *(uint *)(iVar7 + 0x90) = *(uint *)(iVar7 + 0x90) & 0xffffffdf;
  }
LAB_8006ae70:
  FUN_800658f4((int)(short)param_1,iVar8 + 0x76,iVar8 + 0x78);
  return;
}



// ---- FUN_8006aea8 @ 8006aea8

void FUN_8006aea8(int param_1,short param_2)

{
  int iVar1;
  
  *(undefined1 *)(param_2 * 0xa8 + *(int *)(&DAT_800b0424 + ((param_1 << 0x10) >> 0xe)) + 0x2b) = 1;
  iVar1 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + ((param_1 << 0x10) >> 0xe));
  *(uint *)(iVar1 + 0x90) = *(uint *)(iVar1 + 0x90) & 0xfffffff7;
  return;
}



// ---- FUN_8006af08 @ 8006af08

void FUN_8006af08(short param_1,short param_2)

{
  FUN_80067ca0((int)param_1,(int)param_2);
  return;
}



// ---- FUN_8006af34 @ 8006af34

void FUN_8006af34(ushort param_1,short param_2)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  ushort local_30;
  ushort local_2e [7];
  
  iVar8 = (int)(short)param_1;
  iVar9 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + iVar8 * 4);
  sVar1 = *(short *)(iVar9 + 0x40);
  uVar6 = (uint)sVar1;
  uVar3 = *(int *)(iVar9 + 0x98) - 1;
  *(uint *)(iVar9 + 0x98) = uVar3;
  if ((int)uVar6 < 1) {
    if (0 < *(short *)(iVar9 + 0x3c)) {
      *(short *)(iVar9 + 0x3e) = *(short *)(iVar9 + 0x3e) + sVar1;
      FUN_800658f4(iVar8,&local_30,local_2e);
      if (*(short *)(iVar9 + 0x3e) < 0) {
        uVar5 = 0x7f;
        uVar7 = 0x7f;
LAB_8006b2e8:
        FUN_80065738(iVar8,uVar5,uVar7,0);
        iVar8 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + iVar8 * 4);
      }
      else {
        uVar3 = (uint)local_30 - (int)*(short *)(iVar9 + 0x40);
        if (((int)uVar3 < 0x80) &&
           (uVar6 = (uint)local_2e[0] - (int)*(short *)(iVar9 + 0x40), (int)uVar6 < 0x80)) {
LAB_8006b27c:
          FUN_80065738(iVar8,uVar3,uVar6,0);
          goto LAB_8006b30c;
        }
        FUN_80065738((int)(short)param_1,0x7f,0x7f,0);
        iVar8 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + (short)param_1 * 4);
      }
      goto LAB_8006b2fc;
    }
    if (*(short *)(iVar9 + 0x3c) < 0) {
      *(short *)(iVar9 + 0x3e) = *(short *)(iVar9 + 0x3e) - sVar1;
      FUN_800658f4(iVar8,&local_30,local_2e);
      if (0 < *(short *)(iVar9 + 0x3e)) {
LAB_8006b2e0:
        uVar5 = 0;
        uVar7 = 0;
        goto LAB_8006b2e8;
      }
      iVar4 = (int)*(short *)(iVar9 + 0x40);
      if ((-iVar4 <= (int)(uint)local_30) && (-iVar4 <= (int)(uint)local_2e[0])) {
        uVar3 = (uint)local_30 + iVar4;
        uVar6 = (uint)local_2e[0] + iVar4;
        goto LAB_8006b27c;
      }
      FUN_80065738((int)(short)param_1,0,0,0);
      iVar8 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + (short)param_1 * 4);
      goto LAB_8006b2fc;
    }
  }
  else {
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    if (uVar3 % uVar6 != 0) goto LAB_8006b370;
    if (*(short *)(iVar9 + 0x3c) < 1) {
      if (-1 < *(short *)(iVar9 + 0x3c)) goto LAB_8006b30c;
      uVar2 = *(short *)(iVar9 + 0x3e) + 1;
      *(ushort *)(iVar9 + 0x3e) = uVar2;
      if (0 < (int)((uint)uVar2 << 0x10)) goto LAB_8006b2e0;
      FUN_800658f4(iVar8,&local_30,local_2e);
      uVar3 = local_30 - 1;
      if ((-1 < (int)uVar3) && (uVar6 = local_2e[0] - 1, -1 < (int)uVar6)) goto LAB_8006b27c;
      FUN_80065738((int)(short)param_1,0,0,0);
      iVar8 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + (short)param_1 * 4);
    }
    else {
      uVar2 = *(short *)(iVar9 + 0x3e) - 1;
      *(ushort *)(iVar9 + 0x3e) = uVar2;
      if ((int)((uint)uVar2 << 0x10) < 0) {
        uVar5 = 0x7f;
        uVar7 = 0x7f;
        goto LAB_8006b2e8;
      }
      FUN_800658f4(iVar8,&local_30,local_2e);
      uVar3 = local_30 + 1;
      if ((uVar3 < 0x80) && (uVar6 = local_2e[0] + 1, uVar6 < 0x80)) goto LAB_8006b27c;
      FUN_80065738((int)(short)param_1,0x7f,0x7f,0);
      iVar8 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + (short)param_1 * 4);
    }
LAB_8006b2fc:
    *(uint *)(iVar8 + 0x90) = *(uint *)(iVar8 + 0x90) & 0xffffffef;
  }
LAB_8006b30c:
  if ((*(int *)(iVar9 + 0x98) == 0) || (*(short *)(iVar9 + 0x3e) == 0)) {
    iVar8 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + ((int)((uint)param_1 << 0x10) >> 0xe));
    *(uint *)(iVar8 + 0x90) = *(uint *)(iVar8 + 0x90) & 0xffffffef;
  }
LAB_8006b370:
  FUN_800658f4((int)(short)param_1,iVar9 + 0x76,iVar9 + 0x78);
  return;
}



// ---- FUN_8006b3a8 @ 8006b3a8

void FUN_8006b3a8(short param_1,short param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(&DAT_800b0424 + param_1 * 4);
  FUN_80065a18();
  *(undefined1 *)(param_2 * 0xa8 + iVar1 + 0x2b) = 0;
  iVar1 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + param_1 * 4);
  *(uint *)(iVar1 + 0x90) = *(uint *)(iVar1 + 0x90) & 0xfffffffd;
  return;
}



// ---- FUN_8006b490 @ 8006b490

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8006b490(int param_1,short param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + ((param_1 << 0x10) >> 0xe));
  uVar6 = (uint)*(short *)(iVar5 + 0x42);
  uVar2 = *(int *)(iVar5 + 0xa0) - 1;
  *(uint *)(iVar5 + 0xa0) = uVar2;
  if ((int)uVar6 < 1) {
    uVar2 = *(uint *)(iVar5 + 0x8c);
    uVar4 = *(uint *)(iVar5 + 0xa4);
    if (uVar4 < uVar2) {
      *(uint *)(iVar5 + 0x8c) = uVar6 + uVar2;
      bVar1 = uVar6 + uVar2 < uVar4;
    }
    else {
      if (uVar4 <= uVar2) goto LAB_8006b574;
      uVar4 = *(uint *)(iVar5 + 0xa4);
      *(uint *)(iVar5 + 0x8c) = uVar2 - uVar6;
      bVar1 = uVar4 < uVar2 - uVar6;
    }
    if (bVar1) {
      *(uint *)(iVar5 + 0x8c) = uVar4;
    }
  }
  else {
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    if (uVar2 % uVar6 != 0) {
      return;
    }
    uVar2 = *(uint *)(iVar5 + 0x8c);
    iVar3 = uVar2 - 1;
    if ((*(uint *)(iVar5 + 0xa4) < uVar2) || (iVar3 = uVar2 + 1, uVar2 < *(uint *)(iVar5 + 0xa4))) {
      *(int *)(iVar5 + 0x8c) = iVar3;
    }
  }
LAB_8006b574:
  uVar2 = (uint)((int)*(short *)(iVar5 + 0x48) * *(int *)(iVar5 + 0x8c) * 10) /
          (uint)(_DAT_800b03dc * 0x3c);
  if (_DAT_800b03dc * 0x3c == 0) {
    trap(0x1c00);
  }
  *(short *)(iVar5 + 0x6e) = (short)uVar2;
  if ((int)(uVar2 << 0x10) < 1) {
    *(undefined2 *)(iVar5 + 0x6e) = 1;
  }
  if ((*(int *)(iVar5 + 0xa0) == 0) || (*(int *)(iVar5 + 0x8c) == *(int *)(iVar5 + 0xa4))) {
    iVar5 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + ((param_1 << 0x10) >> 0xe));
    *(uint *)(iVar5 + 0x90) = *(uint *)(iVar5 + 0x90) & 0xffffffbf;
    iVar5 = param_2 * 0xa8 + *(int *)(&DAT_800b0424 + ((param_1 << 0x10) >> 0xe));
    *(uint *)(iVar5 + 0x90) = *(uint *)(iVar5 + 0x90) & 0xffffff7f;
  }
  return;
}



// ---- FUN_8006b668 @ 8006b668

void FUN_8006b668(uint param_1,uint param_2)

{
  FUN_800656fc((int)(param_1 << 8) >> 0x10,param_1 & 0xff,(int)(param_2 << 8) >> 0x10,param_2 & 0xff
              );
  return;
}



// ---- FUN_8006b6a4 @ 8006b6a4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8006b6a4(ushort param_1)

{
  int iVar1;
  
  if (param_1 < 0x10) {
    iVar1 = (int)(short)param_1;
    if (*(char *)(iVar1 + -0x7ff51188) == '\x01') {
      FUN_8006ed34(*(undefined4 *)(iVar1 * 4 + -0x7ff4fa74));
      *(undefined1 *)(iVar1 + -0x7ff51188) = 0;
      _DAT_800b057c = _DAT_800b057c + -1;
    }
  }
  return;
}



// ---- FUN_8006b730 @ 8006b730

int FUN_8006b730(undefined4 param_1)

{
  short sVar1;
  
  sVar1 = FUN_80066d10(param_1,0xffffffff);
  if (sVar1 != -1) {
    sVar1 = FUN_80067328(*(undefined4 *)(sVar1 * 4 + -0x7ff4fa20));
  }
  return (int)sVar1;
}



// ---- FUN_8006b78c @ 8006b78c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8006b78c(short param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = (uint)param_1;
  FUN_80065738(uVar5,0,0,1);
  FUN_80065a18(uVar5);
  _DAT_800ae5c8 = ~(1 << (uVar5 & 0x1f)) & _DAT_800ae5c8;
  iVar4 = 0;
  if (0 < _DAT_800b0534) {
    piVar3 = (int *)(&DAT_800b0424 + uVar5 * 4);
    iVar2 = 0;
    do {
      *(undefined4 *)(iVar2 + *piVar3 + 0x90) = 0;
      *(undefined1 *)(iVar2 + *piVar3) = 0xff;
      *(undefined2 *)(iVar2 + *piVar3 + 0x3c) = 0;
      *(undefined2 *)(iVar2 + *piVar3 + 0x3e) = 0;
      *(undefined4 *)(iVar2 + *piVar3 + 0x94) = 0;
      *(undefined4 *)(iVar2 + *piVar3 + 0x98) = 0;
      *(undefined2 *)(iVar2 + *piVar3 + 0x40) = 0;
      *(undefined4 *)(iVar2 + *piVar3 + 0xa4) = 0;
      *(undefined4 *)(iVar2 + *piVar3 + 0xa0) = 0;
      *(undefined4 *)(iVar2 + *piVar3 + 0x9c) = 0;
      *(undefined2 *)(iVar2 + *piVar3 + 0x42) = 0;
      iVar1 = (int)_DAT_800b0534;
      *(undefined2 *)(iVar2 + *piVar3 + 0x72) = 0x7f;
      iVar4 = iVar4 + 1;
      *(undefined2 *)(iVar2 + *piVar3 + 0x74) = 0x7f;
      iVar2 = iVar2 + 0xa8;
    } while (iVar4 < iVar1);
  }
  return;
}



// ---- FUN_8006b8f4 @ 8006b8f4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8006b8f4(short param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = (uint)param_1;
  FUN_80065738(uVar5,0,0,1);
  FUN_80065a18(uVar5);
  _DAT_800ae5c8 = ~(1 << (uVar5 & 0x1f)) & _DAT_800ae5c8;
  iVar4 = 0;
  if (0 < _DAT_800b0534) {
    piVar3 = (int *)(&DAT_800b0424 + uVar5 * 4);
    iVar2 = 0;
    do {
      *(undefined4 *)(iVar2 + *piVar3 + 0x90) = 0;
      *(undefined1 *)(iVar2 + *piVar3) = 0xff;
      *(undefined2 *)(iVar2 + *piVar3 + 0x3c) = 0;
      *(undefined2 *)(iVar2 + *piVar3 + 0x3e) = 0;
      *(undefined4 *)(iVar2 + *piVar3 + 0x94) = 0;
      *(undefined4 *)(iVar2 + *piVar3 + 0x98) = 0;
      *(undefined2 *)(iVar2 + *piVar3 + 0x40) = 0;
      *(undefined4 *)(iVar2 + *piVar3 + 0xa4) = 0;
      *(undefined4 *)(iVar2 + *piVar3 + 0xa0) = 0;
      *(undefined4 *)(iVar2 + *piVar3 + 0x9c) = 0;
      *(undefined2 *)(iVar2 + *piVar3 + 0x42) = 0;
      iVar1 = (int)_DAT_800b0534;
      *(undefined2 *)(iVar2 + *piVar3 + 0x72) = 0x7f;
      iVar4 = iVar4 + 1;
      *(undefined2 *)(iVar2 + *piVar3 + 0x74) = 0x7f;
      iVar2 = iVar2 + 0xa8;
    } while (iVar4 < iVar1);
  }
  return;
}



// ---- FUN_8006ba5c @ 8006ba5c

void FUN_8006ba5c(short param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(&DAT_800b0424 + param_1 * 4);
  FUN_800658f4((int)param_1,*piVar1 + 0x76,*piVar1 + 0x78);
  *(uint *)(*piVar1 + 0x90) = *(uint *)(*piVar1 + 0x90) & 0xfffffffe;
  *(uint *)(*piVar1 + 0x90) = *(uint *)(*piVar1 + 0x90) & 0xfffffff7;
  *(uint *)(*piVar1 + 0x90) = *(uint *)(*piVar1 + 0x90) | 2;
  return;
}



// ---- FUN_8006baec @ 8006baec

void FUN_8006baec(short param_1,short param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(&DAT_800b0424 + param_1 * 4);
  iVar1 = param_2 * 0xa8;
  FUN_800658f4((int)param_1,iVar1 + *piVar2 + 0x76,iVar1 + *piVar2 + 0x78);
  *(uint *)(iVar1 + *piVar2 + 0x90) = *(uint *)(iVar1 + *piVar2 + 0x90) & 0xfffffffe;
  *(uint *)(iVar1 + *piVar2 + 0x90) = *(uint *)(iVar1 + *piVar2 + 0x90) & 0xfffffff7;
  *(uint *)(iVar1 + *piVar2 + 0x90) = *(uint *)(iVar1 + *piVar2 + 0x90) | 2;
  return;
}



// ---- FUN_8006bbac @ 8006bbac

void FUN_8006bbac(char param_1,char param_2,uint param_3)

{
  undefined4 local_40 [4];
  uint local_30;
  uint local_2c;
  uint local_24;
  uint local_20;
  
  if (param_1 == '\0') {
    if (param_2 == '\0') {
      local_40[0] = 0x400;
      local_2c = param_3 & 0xff;
    }
    if (param_2 == '\x01') {
      local_40[0] = 0x100;
      local_30 = param_3 & 0xff;
    }
  }
  if (param_1 == '\x01') {
    if (param_2 == '\0') {
      local_40[0] = 0x800;
      local_20 = param_3 & 0xff;
    }
    if (param_2 == '\x01') {
      local_40[0] = 0x200;
      local_24 = param_3 & 0xff;
    }
  }
  FUN_8006c7e8(0,0x100,local_40);
  return;
}



// ---- FUN_8006bc4c @ 8006bc4c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8006bc4c(undefined4 param_1)

{
  FUN_80061c44();
  FUN_8006beb8(param_1);
  FUN_8006bd6c();
  _DAT_800afeb4 = 0;
  _DAT_800aee70 = 0;
  _DAT_800ab2e0 = 0;
  _DAT_800afeb8 = 0;
  _DAT_800afeba = 0;
  _DAT_800afebc = 0;
  _DAT_800afec0 = 0;
  _DAT_800b0624 = DAT_8009fa38;
  FUN_8006c7e8(_DAT_800abfac,0x61,&DAT_800b0624);
  _DAT_800ab5a8 = 0;
  FUN_8006c7e8(_DAT_800abfac,0x21,&DAT_800ab5a8);
  _DAT_800ac95c = 0;
  _DAT_800b0584 = 0;
  _DAT_800ab584 = 0;
  return;
}



// ---- FUN_8006bd2c @ 8006bd2c

void FUN_8006bd2c(void)

{
  FUN_8006bc4c(0);
  return;
}



// ---- FUN_8006bd4c @ 8006bd4c

void FUN_8006bd4c(void)

{
  FUN_8006bc4c(1);
  return;
}



// ---- FUN_8006bd6c @ 8006bd6c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8006bd6c(void)

{
  if (DAT_800a0010 == 0) {
    DAT_800a0010 = 1;
    FUN_80058314();
    _DAT_800abfac = FUN_8006c140(0,3);
    _DAT_800b05d0 = FUN_80058574(0xf0000009,0x20,0x2000,0);
    FUN_80058364(_DAT_800b05d0);
    FUN_800585a4();
  }
  return;
}



// ---- FUN_8006bde8 @ 8006bde8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8006bde8(void)

{
  if (DAT_800a0010 == 1) {
    DAT_800a0010 = 0;
    FUN_80058314();
    FUN_8006c118(_DAT_800abfac);
    FUN_80058304(_DAT_800b05d0);
    FUN_80062f24(_DAT_800b05d0);
    FUN_800585a4();
  }
  return;
}



// ---- FUN_8006be58 @ 8006be58

void FUN_8006be58(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 0xf0; local_8 = local_8 + 1) {
  }
  return;
}



// ---- FUN_8006beb8 @ 8006beb8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8006beb8(int param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 local_30;
  undefined4 local_2c;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_20;
  undefined4 local_1c;
  undefined4 local_14;
  
  DAT_800a0228 = 1;
  DAT_800a0230 = 0;
  DAT_800a0220 = 0;
  *DAT_800a0024 = *DAT_800a0024 | 0xb0000;
  *(undefined2 *)(DAT_800a0014 + 0x1aa) = 0x8000;
  FUN_8006be58();
  uVar1 = *(ushort *)(DAT_800a0014 + 0x1ae);
  DAT_800a0218 = 0;
  do {
    if ((uVar1 & 0x7ff) == 0) {
LAB_8006bfa0:
      iVar2 = DAT_800a0014;
      *(undefined2 *)(DAT_800a0014 + 0x1ac) = 4;
      *(undefined2 *)(iVar2 + 0x180) = 0;
      *(undefined2 *)(iVar2 + 0x182) = 0;
      *(undefined2 *)(iVar2 + 0x184) = 0;
      *(undefined2 *)(iVar2 + 0x186) = 0;
      *(undefined2 *)(iVar2 + 0x18c) = 0xffff;
      *(undefined2 *)(iVar2 + 0x18e) = 0xffff;
      *(undefined2 *)(iVar2 + 0x198) = 0;
      *(undefined2 *)(iVar2 + 0x19a) = 0;
      if (param_1 == 0) {
        *(undefined2 *)(iVar2 + 400) = 0;
        *(undefined2 *)(iVar2 + 0x192) = 0;
        *(undefined2 *)(iVar2 + 0x194) = 0;
        *(undefined2 *)(iVar2 + 0x196) = 0;
        *(undefined2 *)(iVar2 + 0x1b0) = 0;
        *(undefined2 *)(iVar2 + 0x1b2) = 0;
        *(undefined2 *)(iVar2 + 0x1b4) = 0;
        *(undefined2 *)(iVar2 + 0x1b6) = 0;
        DAT_800a0220 = 0x200;
        FUN_8006c230(&DAT_8009fa28,0x10);
        local_30 = 0xffffffff;
        local_2c = 0x1f;
        local_28 = 0;
        local_26 = 0;
        local_20 = 0x3fff;
        local_1c = 0x200;
        local_14 = 0;
        DAT_800a0230 = 0;
        FUN_8006cffc(&local_30);
        iVar2 = DAT_800a0014;
        *(undefined2 *)(DAT_800a0014 + 0x188) = 0xffff;
        *(ushort *)(iVar2 + 0x18a) = *(ushort *)(iVar2 + 0x18a) | 0xff;
        FUN_8006be58();
        FUN_8006be58();
        FUN_8006be58();
        FUN_8006be58();
        iVar2 = DAT_800a0014;
        *(undefined2 *)(DAT_800a0014 + 0x18c) = 0xffff;
        *(ushort *)(iVar2 + 0x18e) = *(ushort *)(iVar2 + 0x18e) | 0xff;
        FUN_8006be58();
        FUN_8006be58();
        FUN_8006be58();
        FUN_8006be58();
      }
      _DAT_800ab57c = 1;
      *(undefined2 *)(DAT_800a0014 + 0x1aa) = 0xc000;
      _DAT_800ab74c = 0;
      return 0;
    }
    DAT_800a0218 = DAT_800a0218 + 1;
    if (5000 < DAT_800a0218) {
      FUN_80058614(s_SPU_T_O___s__800299a8,s_wait__reset__800299b8);
      goto LAB_8006bfa0;
    }
    uVar1 = *(ushort *)(DAT_800a0014 + 0x1ae);
  } while( true );
}



// ---- FUN_8006c118 @ 8006c118

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8006c118(void)

{
  _DAT_800ab74c = 0;
  FUN_80061a20(0);
  return 1;
}



// ---- FUN_8006c140 @ 8006c140

undefined4 FUN_8006c140(void)

{
  FUN_80061a20(FUN_8006c458);
  return 3;
}



// ---- FUN_8006c168 @ 8006c168

void FUN_8006c168(void)

{
  *DAT_800a002c = *DAT_800a002c & 0xf0ffffff | 0x22000000;
  return;
}



// ---- FUN_8006c198 @ 8006c198

void FUN_8006c198(void)

{
  *DAT_800a002c = *DAT_800a002c & 0xf0ffffff | 0x20000000;
  return;
}



// ---- FUN_8006c1c8 @ 8006c1c8

undefined4 FUN_8006c1c8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = DAT_800a0228;
  *(ushort *)(DAT_800a0014 + 0x1aa) = *(ushort *)(DAT_800a0014 + 0x1aa) & 0xffcf;
  if (iVar1 == 1) {
    FUN_8006c4e4();
  }
  else {
    FUN_8006c230(param_1,param_2);
  }
  return param_2;
}



// ---- FUN_8006c230 @ 8006c230

void FUN_8006c230(undefined2 *param_1,uint param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar1 = *(ushort *)(DAT_800a0014 + 0x1ae);
  *(undefined2 *)(DAT_800a0014 + 0x1a6) = DAT_800a0220;
  FUN_8006be58();
  iVar4 = DAT_800a0014;
  do {
    DAT_800a0014 = iVar4;
    if (param_2 == 0) {
      *(ushort *)(iVar4 + 0x1aa) = *(ushort *)(iVar4 + 0x1aa) & 0xffcf;
      uVar3 = *(ushort *)(iVar4 + 0x1ae);
      DAT_800a0218 = 0;
      while( true ) {
        if ((uVar3 & 0x7ff) == (uVar1 & 0x7ff)) {
          return;
        }
        DAT_800a0218 = DAT_800a0218 + 1;
        if (5000 < DAT_800a0218) break;
        uVar3 = *(ushort *)(DAT_800a0014 + 0x1ae);
      }
      FUN_80058614(s_SPU_T_O___s__800299a8,s_wait__dmaf_clear_W__800299dc);
      return;
    }
    uVar6 = param_2;
    if (0x40 < param_2) {
      uVar6 = 0x40;
    }
    iVar5 = 0;
    if (0 < (int)uVar6) {
      do {
        uVar2 = *param_1;
        param_1 = param_1 + 1;
        iVar5 = iVar5 + 2;
        *(undefined2 *)(iVar4 + 0x1a8) = uVar2;
      } while (iVar5 < (int)uVar6);
    }
    *(ushort *)(DAT_800a0014 + 0x1aa) = *(ushort *)(DAT_800a0014 + 0x1aa) & 0xffcf | 0x10;
    FUN_8006be58();
    uVar3 = *(ushort *)(DAT_800a0014 + 0x1ae);
    DAT_800a0218 = 0;
    while ((uVar3 & 0x400) != 0) {
      DAT_800a0218 = DAT_800a0218 + 1;
      if (5000 < DAT_800a0218) {
        FUN_80058614(s_SPU_T_O___s__800299a8,s_wait__wrdy_H__>_L__800299c8);
        break;
      }
      uVar3 = *(ushort *)(DAT_800a0014 + 0x1ae);
    }
    param_2 = param_2 - uVar6;
    FUN_8006be58();
    FUN_8006be58();
    iVar4 = DAT_800a0014;
  } while( true );
}



// ---- FUN_8006c430 @ 8006c430

undefined4 FUN_8006c430(undefined4 param_1,undefined4 param_2)

{
  FUN_8006c618();
  return param_2;
}



// ---- FUN_8006c458 @ 8006c458

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8006c458(void)

{
  if (DAT_800a0238 == 0) {
    FUN_8006be58();
    FUN_8006be58();
  }
  *(ushort *)(DAT_800a0014 + 0x1aa) = *(ushort *)(DAT_800a0014 + 0x1aa) & 0xffcf;
  if (_DAT_800ab74c == (code *)0x0) {
    FUN_8005fe8c(0xf0000009,0x20);
  }
  else {
    (*_DAT_800ab74c)();
  }
  return;
}



// ---- FUN_8006c4e4 @ 8006c4e4

void FUN_8006c4e4(undefined4 param_1,uint param_2)

{
  *(undefined2 *)(DAT_800a0014 + 0x1a6) = DAT_800a0220;
  FUN_8006be58();
  FUN_8006be58();
  *(ushort *)(DAT_800a0014 + 0x1aa) = *(ushort *)(DAT_800a0014 + 0x1aa) & 0xffcf | 0x20;
  FUN_8006be58();
  FUN_8006be58();
  FUN_8006c198();
  DAT_800a0250 = (param_2 >> 6) + (uint)((param_2 & 0x3f) != 0);
  DAT_800a0240 = param_1;
  DAT_800a0248 = param_2;
  *DAT_800a0028 = *DAT_800a0028 | 0x900000;
  *DAT_800a0024 = *DAT_800a0024 | 0x80000;
  *DAT_800a0018 = DAT_800a0240;
  *DAT_800a001c = DAT_800a0250 << 0x10 | 0x10;
  DAT_800a0238 = 0;
  *DAT_800a0020 = 0x1000201;
  return;
}



// ---- FUN_8006c618 @ 8006c618

void FUN_8006c618(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = DAT_800a0220;
  iVar1 = DAT_800a0014;
  *(ushort *)(DAT_800a0014 + 0x1aa) = *(ushort *)(DAT_800a0014 + 0x1aa) & 0xffcf;
  *(undefined2 *)(iVar1 + 0x1a6) = uVar2;
  *(ushort *)(iVar1 + 0x1aa) = *(ushort *)(iVar1 + 0x1aa) | 0x30;
  FUN_8006c168();
  DAT_800a0250 = (param_2 >> 6) + (uint)((param_2 & 0x3f) != 0);
  DAT_800a0240 = param_1;
  DAT_800a0248 = param_2;
  *DAT_800a0028 = *DAT_800a0028 | 0x900000;
  *DAT_800a0024 = *DAT_800a0024 | 0x80000;
  *DAT_800a0018 = DAT_800a0240;
  *DAT_800a001c = DAT_800a0250 << 0x10 | 0x10;
  DAT_800a0238 = 1;
  *DAT_800a0020 = 0x1000200;
  return;
}



// ---- FUN_8006c728 @ 8006c728

void FUN_8006c728(undefined4 param_1,undefined2 param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = DAT_800a0014;
  *(undefined2 *)(DAT_800a0014 + 0x1a6) = param_2;
  puVar2 = DAT_800a002c;
  *(ushort *)(iVar1 + 0x1aa) = *(ushort *)(iVar1 + 0x1aa) | 0x30;
  *puVar2 = *puVar2 & 0xf0ffffff | 0x22000000;
  *DAT_800a0028 = *DAT_800a0028 | 0x900000;
  *DAT_800a0024 = *DAT_800a0024 | 0x80000;
  *DAT_800a0018 = param_1;
  *DAT_800a001c = param_3 << 0x10 | 0x10;
  DAT_800a0238 = 1;
  *DAT_800a0020 = 0x1000200;
  return;
}



// ---- FUN_8006c7e8 @ 8006c7e8

bool FUN_8006c7e8(undefined4 param_1,uint param_2,uint *param_3)

{
  int iVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  iVar1 = DAT_800a0014;
  uVar6 = (*(ushort *)(DAT_800a0014 + 0x1ac) & 0xe) >> 1;
  if (param_2 == 0x52) {
    *(ushort *)(DAT_800a0014 + 0x194) = *(ushort *)(DAT_800a0014 + 0x194) | (ushort)*param_3;
    *(ushort *)(iVar1 + 0x196) = *(ushort *)(iVar1 + 0x196) | (ushort)*(byte *)((int)param_3 + 2);
    return false;
  }
  if (param_2 < 0x53) {
    if (param_2 == 0x2b) {
      uVar4 = *param_3;
      if (uVar6 != 0) {
        if (uVar6 == 0) {
          trap(0x1c00);
        }
        if ((uVar6 == 0xffffffff) && (uVar4 == 0x80000000)) {
          trap(0x1800);
        }
        if ((int)uVar4 % (int)uVar6 != 0) {
          uVar4 = uVar4 + uVar6;
        }
      }
      DAT_800a0220 = (short)((int)uVar4 >> uVar6 + 1);
      return false;
    }
    if (0x2b < param_2) {
      if (param_2 == 0x40) {
        *(ushort *)(DAT_800a0014 + 400) = *(ushort *)(DAT_800a0014 + 400) | (ushort)*param_3;
        *(ushort *)(iVar1 + 0x192) =
             *(ushort *)(iVar1 + 0x192) | (ushort)*(byte *)((int)param_3 + 2);
        return false;
      }
      if (param_2 < 0x41) {
        if (param_2 != 0x2e) {
          if (0x2e < param_2) {
            if (param_2 == 0x2f) {
              *param_3 = DAT_800a0228;
              return false;
            }
            return false;
          }
          if (param_2 == 0x2d) {
            *param_3 = (uint)DAT_800a0220 << uVar6 + 1;
            return false;
          }
          return false;
        }
LAB_8006cc7c:
        DAT_800a0228 = *param_3;
        return false;
      }
      if (param_2 == 0x42) {
        *(ushort *)(DAT_800a0014 + 400) = *(ushort *)(DAT_800a0014 + 400) & ~(ushort)*param_3;
        *(ushort *)(iVar1 + 0x192) =
             *(ushort *)(iVar1 + 0x192) & ~(ushort)*(byte *)((int)param_3 + 2);
        return false;
      }
      if (0x41 < param_2) {
        if (param_2 != 0x50) {
          if (param_2 == 0x51) {
            *(ushort *)param_3 = *(ushort *)(DAT_800a0014 + 0x1aa) >> 8 & 0x3f;
            return false;
          }
          return false;
        }
        uVar3 = *(ushort *)(DAT_800a0014 + 0x1aa) & 0xc0ff;
        uVar2 = ((ushort)*param_3 & 0x3f) << 8;
LAB_8006cdd8:
        *(ushort *)(DAT_800a0014 + 0x1aa) = uVar3 | uVar2;
        return false;
      }
      uVar4 = (uint)*(ushort *)(DAT_800a0014 + 400);
      uVar6 = *(ushort *)(DAT_800a0014 + 0x192) & 0xff;
LAB_8006cee0:
      *param_3 = uVar4 | uVar6 << 0x10;
      return false;
    }
    if (param_2 == 0x13) {
      uVar4 = *param_3;
      if (uVar6 != 0) {
        if (uVar6 == 0) {
          trap(0x1c00);
        }
        if ((uVar6 == 0xffffffff) && (uVar4 == 0x80000000)) {
          trap(0x1800);
        }
        if ((int)uVar4 % (int)uVar6 != 0) {
          uVar4 = uVar4 + uVar6;
        }
      }
      *(short *)(DAT_800a0014 + 0x1a4) = (short)((int)uVar4 >> uVar6 + 1);
      return false;
    }
    if (param_2 < 0x14) {
      if (param_2 != 2) {
        if (2 < param_2) {
          if (param_2 != 0x10) {
            return false;
          }
          if (param_3 == (uint *)0x0) {
            *(ushort *)(DAT_800a0014 + 0x1aa) = *(ushort *)(DAT_800a0014 + 0x1aa) & 0xffbf;
            DAT_800a0218 = 0;
            if ((*(ushort *)(iVar1 + 0x1aa) & 0x40) == 0) {
              DAT_800a0218 = 0;
              return false;
            }
            while (DAT_800a0218 = DAT_800a0218 + 1, DAT_800a0218 < 0x1389) {
              if ((*(ushort *)(iVar1 + 0x1aa) & 0x40) == 0) {
                return false;
              }
            }
          }
          else {
            *(ushort *)(DAT_800a0014 + 0x1aa) = *(ushort *)(DAT_800a0014 + 0x1aa) | 0x40;
            uVar2 = *(ushort *)(iVar1 + 0x1aa);
            DAT_800a0218 = 0;
            while( true ) {
              if ((uVar2 & 0x40) != 0) {
                return false;
              }
              DAT_800a0218 = DAT_800a0218 + 1;
              if (5000 < DAT_800a0218) break;
              uVar2 = *(ushort *)(iVar1 + 0x1aa);
            }
          }
          FUN_80058614(s_SPU_T_O___s__800299a8,s_wait__ioctl_IRQ__800299f0);
          return false;
        }
        if (param_2 != 1) {
          return false;
        }
        if (param_3 == (uint *)0x0) {
          *(ushort *)(DAT_800a0014 + 0x1aa) = *(ushort *)(DAT_800a0014 + 0x1aa) | 0x4000;
          return false;
        }
        *(ushort *)(DAT_800a0014 + 0x1aa) = *(ushort *)(DAT_800a0014 + 0x1aa) & 0xbfff;
        return false;
      }
      if ((*(ushort *)(DAT_800a0014 + 0x1aa) & 0x4000) != 0) {
LAB_8006ca80:
        *param_3 = 0;
        return false;
      }
    }
    else {
      if (param_2 == 0x15) {
        FUN_80061a8c();
        return false;
      }
      if (param_2 < 0x15) {
        uVar2 = *(ushort *)(DAT_800a0014 + 0x1a4);
        goto LAB_8006ce84;
      }
      if (param_2 != 0x16) {
        if (param_2 != 0x21) {
          return false;
        }
        goto LAB_8006cc7c;
      }
      if ((*(ushort *)(DAT_800a0014 + 0x1aa) & 0x40) == 0) {
        *param_3 = 0;
        return false;
      }
    }
  }
  else {
    if (param_2 == 0x68) {
      uVar4 = *param_3;
      if (uVar6 != 0) {
        if (uVar6 == 0) {
          trap(0x1c00);
        }
        if ((uVar6 == 0xffffffff) && (uVar4 == 0x80000000)) {
          trap(0x1800);
        }
        if ((int)uVar4 % (int)uVar6 != 0) {
          uVar4 = uVar4 + uVar6;
        }
      }
      *(short *)(DAT_800a0014 + 0x1a2) = (short)((int)uVar4 >> uVar6 + 1);
      return false;
    }
    if (param_2 < 0x69) {
      if (param_2 == 0x61) {
        *(ushort *)(DAT_800a0014 + 0x1a2) = (ushort)*param_3;
        return false;
      }
      if (param_2 < 0x62) {
        if (param_2 == 0x54) {
          *(ushort *)(DAT_800a0014 + 0x194) = *(ushort *)(DAT_800a0014 + 0x194) & ~(ushort)*param_3;
          *(ushort *)(iVar1 + 0x196) =
               *(ushort *)(iVar1 + 0x196) & ~(ushort)*(byte *)((int)param_3 + 2);
          return false;
        }
        if (0x53 < param_2) {
          if (param_2 != 0x60) {
            return false;
          }
          uVar3 = *(ushort *)(DAT_800a0014 + 0x1aa) & 0xff7f;
          uVar2 = ((ushort)*param_3 & 1) << 7;
          goto LAB_8006cdd8;
        }
        uVar4 = (uint)*(ushort *)(DAT_800a0014 + 0x194);
        uVar6 = *(ushort *)(DAT_800a0014 + 0x196) & 0xff;
      }
      else {
        if (param_2 == 0x65) {
          *(ushort *)(DAT_800a0014 + 0x198) = *(ushort *)(DAT_800a0014 + 0x198) | (ushort)*param_3;
          *(ushort *)(iVar1 + 0x19a) =
               *(ushort *)(iVar1 + 0x19a) | (ushort)*(byte *)((int)param_3 + 2);
          return false;
        }
        if (param_2 < 0x66) {
          if (param_2 == 99) {
            FUN_8006d180();
            return false;
          }
          return false;
        }
        if (param_2 != 0x66) {
          if (param_2 == 0x67) {
            *(ushort *)(DAT_800a0014 + 0x198) =
                 *(ushort *)(DAT_800a0014 + 0x198) & ~(ushort)*param_3;
            *(ushort *)(iVar1 + 0x19a) =
                 *(ushort *)(iVar1 + 0x19a) & ~(ushort)*(byte *)((int)param_3 + 2);
            return false;
          }
          return false;
        }
        uVar4 = (uint)*(ushort *)(DAT_800a0014 + 0x198);
        uVar6 = *(ushort *)(DAT_800a0014 + 0x19a) & 0xff;
      }
      goto LAB_8006cee0;
    }
    if (param_2 == 0x203) {
      *(ushort *)(DAT_800a0014 + 0x18c) = (ushort)*param_3;
      *(ushort *)(iVar1 + 0x18e) = (ushort)*(byte *)((int)param_3 + 2);
      return false;
    }
    if (0x203 < param_2) {
      if (param_2 == 0x210) {
        FUN_8006c728(param_3,0,0x40);
      }
      else {
        if (param_2 < 0x211) {
          if (param_2 == 0x204) {
            *(ushort *)(DAT_800a0014 + 0x188) = (ushort)*param_3;
            *(ushort *)(iVar1 + 0x18a) = (ushort)*(byte *)((int)param_3 + 2);
            return false;
          }
          return false;
        }
        if (param_2 == 0x212) {
          uVar5 = 0;
        }
        else {
          param_3 = param_3 + 0x200;
          if (param_2 != 0x213) {
            return false;
          }
          uVar5 = 0x100;
        }
        FUN_8006c728(param_3,uVar5,0x20);
      }
      return (*(ushort *)(DAT_800a0014 + 0x1ae) & 0x800) != 0;
    }
    if (param_2 != 0x6a) {
      if (0x69 < param_2) {
        if (param_2 == 0x100) {
          FUN_8006d650();
          return false;
        }
        if (param_2 == 0x101) {
          FUN_8006d9e8();
          return false;
        }
        return false;
      }
      uVar2 = *(ushort *)(DAT_800a0014 + 0x1a2);
LAB_8006ce84:
      *param_3 = (uint)uVar2 << uVar6 + 1;
      return false;
    }
    if ((*(ushort *)(DAT_800a0014 + 0x1aa) & 0x80) == 0) goto LAB_8006ca80;
  }
  *param_3 = 1;
  return false;
}



// ---- FUN_8006cffc @ 8006cffc

void FUN_8006cffc(uint *param_1)

{
  bool bVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined2 *puVar8;
  
  puVar2 = DAT_800a0014;
  uVar5 = param_1[1];
  uVar7 = 0;
  bVar1 = uVar5 == 0;
  uVar6 = ((ushort)DAT_800a0014[0xd6] & 0xe) >> 1;
  puVar8 = DAT_800a0014;
  do {
    if ((1 << (uVar7 & 0x1f) & *param_1) != 0) {
      if ((bVar1) || ((uVar5 & 1) != 0)) {
        *puVar8 = (short)param_1[2];
      }
      if ((bVar1) || ((uVar5 & 2) != 0)) {
        puVar2[uVar7 * 8 + 1] = *(undefined2 *)((int)param_1 + 10);
      }
      if ((bVar1) || ((uVar5 & 4) != 0)) {
        puVar2[uVar7 * 8 + 2] = (short)param_1[4];
      }
      if ((bVar1) || ((uVar5 & 8) != 0)) {
        if (DAT_800a0230 == 0) {
          uVar3 = (undefined2)param_1[5];
        }
        else {
          uVar4 = param_1[5];
          if (uVar6 != 0) {
            if (uVar6 == 0) {
              trap(0x1c00);
            }
            if (uVar4 % uVar6 != 0) {
              uVar4 = uVar4 + uVar6;
            }
          }
          uVar3 = (undefined2)(uVar4 >> uVar6 + 1);
        }
        puVar2[uVar7 * 8 + 3] = uVar3;
      }
      if ((bVar1) || ((uVar5 & 0x10) != 0)) {
        puVar2[uVar7 * 8 + 4] = *(undefined2 *)((int)param_1 + 0x1e);
      }
      if ((bVar1) || ((uVar5 & 0x10) != 0)) {
        puVar2[uVar7 * 8 + 5] = (short)param_1[7];
      }
      if ((bVar1) || ((uVar5 & 0x100) != 0)) {
        puVar2[uVar7 * 8 + 7] = (short)param_1[6];
      }
    }
    uVar7 = uVar7 + 1;
    puVar8 = puVar8 + 8;
  } while ((int)uVar7 < 0x18);
  return;
}



// ---- FUN_8006d180 @ 8006d180

undefined4 FUN_8006d180(uint *param_1)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  bVar1 = uVar2 == 0;
  if ((bVar1) || ((uVar2 & 1) != 0)) {
    *(short *)(DAT_800a0014 + 0x1c0) = (short)param_1[1];
  }
  if ((bVar1) || ((uVar2 & 2) != 0)) {
    *(undefined2 *)(DAT_800a0014 + 0x1c2) = *(undefined2 *)((int)param_1 + 6);
  }
  if ((bVar1) || ((uVar2 & 4) != 0)) {
    *(short *)(DAT_800a0014 + 0x1c4) = (short)param_1[2];
  }
  if ((bVar1) || ((uVar2 & 8) != 0)) {
    *(undefined2 *)(DAT_800a0014 + 0x1c6) = *(undefined2 *)((int)param_1 + 10);
  }
  if ((bVar1) || ((uVar2 & 0x10) != 0)) {
    *(short *)(DAT_800a0014 + 0x1c8) = (short)param_1[3];
  }
  if ((bVar1) || ((uVar2 & 0x20) != 0)) {
    *(undefined2 *)(DAT_800a0014 + 0x1ca) = *(undefined2 *)((int)param_1 + 0xe);
  }
  if ((bVar1) || ((uVar2 & 0x40) != 0)) {
    *(short *)(DAT_800a0014 + 0x1cc) = (short)param_1[4];
  }
  if ((bVar1) || ((uVar2 & 0x80) != 0)) {
    *(undefined2 *)(DAT_800a0014 + 0x1ce) = *(undefined2 *)((int)param_1 + 0x12);
  }
  if ((bVar1) || ((uVar2 & 0x100) != 0)) {
    *(short *)(DAT_800a0014 + 0x1d0) = (short)param_1[5];
  }
  if ((bVar1) || ((uVar2 & 0x200) != 0)) {
    *(undefined2 *)(DAT_800a0014 + 0x1d2) = *(undefined2 *)((int)param_1 + 0x16);
  }
  if ((bVar1) || ((uVar2 & 0x400) != 0)) {
    *(short *)(DAT_800a0014 + 0x1d4) = (short)param_1[6];
  }
  if ((bVar1) || ((uVar2 & 0x800) != 0)) {
    *(undefined2 *)(DAT_800a0014 + 0x1d6) = *(undefined2 *)((int)param_1 + 0x1a);
  }
  if ((bVar1) || ((uVar2 & 0x1000) != 0)) {
    *(short *)(DAT_800a0014 + 0x1d8) = (short)param_1[7];
  }
  if ((bVar1) || ((uVar2 & 0x2000) != 0)) {
    *(undefined2 *)(DAT_800a0014 + 0x1da) = *(undefined2 *)((int)param_1 + 0x1e);
  }
  if ((bVar1) || ((uVar2 & 0x4000) != 0)) {
    *(short *)(DAT_800a0014 + 0x1dc) = (short)param_1[8];
  }
  if ((bVar1) || ((uVar2 & 0x8000) != 0)) {
    *(undefined2 *)(DAT_800a0014 + 0x1de) = *(undefined2 *)((int)param_1 + 0x22);
  }
  if ((bVar1) || ((uVar2 & 0x10000) != 0)) {
    *(short *)(DAT_800a0014 + 0x1e0) = (short)param_1[9];
  }
  if ((bVar1) || ((uVar2 & 0x20000) != 0)) {
    *(undefined2 *)(DAT_800a0014 + 0x1e2) = *(undefined2 *)((int)param_1 + 0x26);
  }
  if ((bVar1) || ((uVar2 & 0x40000) != 0)) {
    *(short *)(DAT_800a0014 + 0x1e4) = (short)param_1[10];
  }
  if ((bVar1) || ((uVar2 & 0x80000) != 0)) {
    *(undefined2 *)(DAT_800a0014 + 0x1e6) = *(undefined2 *)((int)param_1 + 0x2a);
  }
  if ((bVar1) || ((uVar2 & 0x100000) != 0)) {
    *(short *)(DAT_800a0014 + 0x1e8) = (short)param_1[0xb];
  }
  if ((bVar1) || ((uVar2 & 0x200000) != 0)) {
    *(undefined2 *)(DAT_800a0014 + 0x1ea) = *(undefined2 *)((int)param_1 + 0x2e);
  }
  if ((bVar1) || ((uVar2 & 0x400000) != 0)) {
    *(short *)(DAT_800a0014 + 0x1ec) = (short)param_1[0xc];
  }
  if ((bVar1) || ((uVar2 & 0x800000) != 0)) {
    *(undefined2 *)(DAT_800a0014 + 0x1ee) = *(undefined2 *)((int)param_1 + 0x32);
  }
  if ((bVar1) || ((uVar2 & 0x1000000) != 0)) {
    *(short *)(DAT_800a0014 + 0x1f0) = (short)param_1[0xd];
  }
  if ((bVar1) || ((uVar2 & 0x2000000) != 0)) {
    *(undefined2 *)(DAT_800a0014 + 0x1f2) = *(undefined2 *)((int)param_1 + 0x36);
  }
  if ((bVar1) || ((uVar2 & 0x4000000) != 0)) {
    *(short *)(DAT_800a0014 + 500) = (short)param_1[0xe];
  }
  if ((bVar1) || ((uVar2 & 0x8000000) != 0)) {
    *(undefined2 *)(DAT_800a0014 + 0x1f6) = *(undefined2 *)((int)param_1 + 0x3a);
  }
  if ((bVar1) || ((uVar2 & 0x10000000) != 0)) {
    *(short *)(DAT_800a0014 + 0x1f8) = (short)param_1[0xf];
  }
  if ((bVar1) || ((uVar2 & 0x20000000) != 0)) {
    *(undefined2 *)(DAT_800a0014 + 0x1fa) = *(undefined2 *)((int)param_1 + 0x3e);
  }
  if ((bVar1) || ((uVar2 & 0x40000000) != 0)) {
    *(short *)(DAT_800a0014 + 0x1fc) = (short)param_1[0x10];
  }
  if ((bVar1) || ((int)uVar2 < 0)) {
    *(undefined2 *)(DAT_800a0014 + 0x1fe) = *(undefined2 *)((int)param_1 + 0x42);
  }
  return 0;
}



// ---- FUN_8006d650 @ 8006d650

undefined4 FUN_8006d650(uint *param_1)

{
  bool bVar1;
  int iVar2;
  ushort uVar3;
  uint uVar4;
  
  uVar4 = *param_1;
  bVar1 = uVar4 == 0;
  if ((bVar1) || ((uVar4 & 1) != 0)) {
    *(short *)(DAT_800a0014 + 0x180) = (short)param_1[1];
  }
  if ((bVar1) || ((uVar4 & 2) != 0)) {
    *(undefined2 *)(DAT_800a0014 + 0x182) = *(undefined2 *)((int)param_1 + 6);
  }
  if ((bVar1) || ((uVar4 & 4) != 0)) {
    *(short *)(DAT_800a0014 + 0x184) = (short)param_1[2];
  }
  if ((bVar1) || ((uVar4 & 8) != 0)) {
    *(undefined2 *)(DAT_800a0014 + 0x186) = *(undefined2 *)((int)param_1 + 10);
  }
  if ((bVar1) || ((uVar4 & 0x10) != 0)) {
    *(short *)(DAT_800a0014 + 0x1b0) = (short)param_1[3];
  }
  if ((bVar1) || ((uVar4 & 0x20) != 0)) {
    *(undefined2 *)(DAT_800a0014 + 0x1b2) = *(undefined2 *)((int)param_1 + 0xe);
  }
  if ((bVar1) || ((uVar4 & 0x100) != 0)) {
    if (param_1[4] == 0) {
      uVar3 = *(ushort *)(DAT_800a0014 + 0x1aa) & 0xfffb;
    }
    else {
      uVar3 = *(ushort *)(DAT_800a0014 + 0x1aa) | 4;
    }
    *(ushort *)(DAT_800a0014 + 0x1aa) = uVar3;
  }
  if ((bVar1) || ((uVar4 & 0x400) != 0)) {
    if (param_1[5] == 0) {
      uVar3 = *(ushort *)(DAT_800a0014 + 0x1aa) & 0xfffe;
    }
    else {
      uVar3 = *(ushort *)(DAT_800a0014 + 0x1aa) | 1;
    }
    *(ushort *)(DAT_800a0014 + 0x1aa) = uVar3;
  }
  if ((bVar1) || ((uVar4 & 0x40) != 0)) {
    *(short *)(DAT_800a0014 + 0x1b4) = (short)param_1[6];
  }
  if ((bVar1) || ((uVar4 & 0x80) != 0)) {
    *(undefined2 *)(DAT_800a0014 + 0x1b6) = *(undefined2 *)((int)param_1 + 0x1a);
  }
  if ((bVar1) || ((uVar4 & 0x200) != 0)) {
    if (param_1[7] == 0) {
      uVar3 = *(ushort *)(DAT_800a0014 + 0x1aa) & 0xfff7;
    }
    else {
      uVar3 = *(ushort *)(DAT_800a0014 + 0x1aa) | 8;
    }
    *(ushort *)(DAT_800a0014 + 0x1aa) = uVar3;
  }
  if ((bVar1) || ((uVar4 & 0x800) != 0)) {
    if (param_1[8] == 0) {
      uVar3 = *(ushort *)(DAT_800a0014 + 0x1aa) & 0xfffd;
    }
    else {
      uVar3 = *(ushort *)(DAT_800a0014 + 0x1aa) | 2;
    }
    *(ushort *)(DAT_800a0014 + 0x1aa) = uVar3;
  }
  iVar2 = DAT_800a0014;
  if ((bVar1) || ((uVar4 & 0x1000) != 0)) {
    *(ushort *)(DAT_800a0014 + 0x1aa) = *(ushort *)(DAT_800a0014 + 0x1aa) & 0xc0ff;
    *(ushort *)(iVar2 + 0x1aa) = *(ushort *)(iVar2 + 0x1aa) | ((ushort)param_1[9] & 0x3f) << 8;
  }
  iVar2 = DAT_800a0014;
  if ((bVar1) || ((uVar4 & 0x2000) != 0)) {
    *(ushort *)(DAT_800a0014 + 0x1aa) = *(ushort *)(DAT_800a0014 + 0x1aa) & 0xff7f;
    *(ushort *)(iVar2 + 0x1aa) =
         *(ushort *)(iVar2 + 0x1aa) | (*(ushort *)((int)param_1 + 0x26) & 1) << 7;
  }
  iVar2 = DAT_800a0014;
  if ((bVar1) || ((uVar4 & 0x4000) != 0)) {
    *(ushort *)(DAT_800a0014 + 0x1ac) = *(ushort *)(DAT_800a0014 + 0x1ac) & 0xfff1;
    *(ushort *)(iVar2 + 0x1ac) = *(ushort *)(iVar2 + 0x1ac) | ((ushort)param_1[10] & 7) << 1;
  }
  iVar2 = DAT_800a0014;
  if ((bVar1) || ((uVar4 & 0x8000) != 0)) {
    *(ushort *)(DAT_800a0014 + 0x1ac) = *(ushort *)(DAT_800a0014 + 0x1ac) & 0xfffe;
    *(ushort *)(iVar2 + 0x1ac) = *(ushort *)(iVar2 + 0x1ac) | *(ushort *)((int)param_1 + 0x2a) & 1;
  }
  return 0;
}



// ---- FUN_8006d9e8 @ 8006d9e8

undefined4 FUN_8006d9e8(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_800a0014;
  *(undefined2 *)(param_1 + 4) = *(undefined2 *)(DAT_800a0014 + 0x180);
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)(iVar1 + 0x182);
  *(undefined2 *)(param_1 + 8) = *(undefined2 *)(iVar1 + 0x184);
  *(undefined2 *)(param_1 + 10) = *(undefined2 *)(iVar1 + 0x186);
  *(undefined2 *)(param_1 + 0xc) = *(undefined2 *)(iVar1 + 0x1b0);
  *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(iVar1 + 0x1b2);
  *(uint *)(param_1 + 0x10) = *(ushort *)(iVar1 + 0x1aa) >> 2 & 1;
  *(uint *)(param_1 + 0x14) = *(ushort *)(iVar1 + 0x1aa) & 1;
  *(undefined2 *)(param_1 + 0x18) = *(undefined2 *)(iVar1 + 0x1b4);
  *(undefined2 *)(param_1 + 0x1a) = *(undefined2 *)(iVar1 + 0x1b6);
  *(uint *)(param_1 + 0x1c) = *(ushort *)(iVar1 + 0x1aa) >> 3 & 1;
  *(uint *)(param_1 + 0x20) = *(ushort *)(iVar1 + 0x1aa) >> 1 & 1;
  *(ushort *)(param_1 + 0x24) = *(ushort *)(iVar1 + 0x1aa) >> 8 & 0x3f;
  *(ushort *)(param_1 + 0x26) = *(ushort *)(iVar1 + 0x1aa) >> 7 & 1;
  *(short *)(param_1 + 0x28) = (short)((*(ushort *)(iVar1 + 0x1ac) & 0xe) >> 1);
  *(ushort *)(param_1 + 0x2a) = *(ushort *)(iVar1 + 0x1ac) & 1;
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(iVar1 + 0x19c);
  *(undefined2 *)(param_1 + 0x30) = *(undefined2 *)(iVar1 + 0x1ae);
  return 0;
}



// ---- FUN_8006db4c @ 8006db4c

void FUN_8006db4c(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = param_3 + -1;
  if (param_3 != 0) {
    do {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      iVar2 = iVar2 + -1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    } while (iVar2 != -1);
  }
  return;
}



// ---- FUN_8006db7c @ 8006db7c

/* WARNING: Removing unreachable block (ram,0x8006dec0) */
/* WARNING: Removing unreachable block (ram,0x8006ddac) */
/* WARNING: Removing unreachable block (ram,0x8006dd7c) */
/* WARNING: Removing unreachable block (ram,0x8006dd8c) */
/* WARNING: Removing unreachable block (ram,0x8006dd94) */
/* WARNING: Removing unreachable block (ram,0x8006ddbc) */
/* WARNING: Removing unreachable block (ram,0x8006ddc4) */
/* WARNING: Removing unreachable block (ram,0x8006ded0) */
/* WARNING: Removing unreachable block (ram,0x8006ded8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8006db7c(uint *param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint local_80;
  short local_7c;
  short local_7a;
  undefined2 local_6e;
  short local_68;
  short local_66;
  short local_64;
  short local_62;
  short local_5c;
  short local_5a;
  short local_48;
  short local_46;
  short local_44;
  short local_42;
  int local_38 [4];
  
  bVar3 = false;
  uVar8 = *param_1;
  bVar4 = false;
  bVar5 = false;
  bVar2 = uVar8 == 0;
  local_80 = 0;
  if ((bVar2) || ((uVar8 & 1) != 0)) {
    uVar7 = param_1[1];
    bVar1 = (uVar7 & 0x100) != 0;
    if (bVar1) {
      uVar7 = uVar7 & 0xfffffeff;
    }
    if ((9 < uVar7) || (iVar6 = FUN_8006ed0c((&DAT_8009fa38)[uVar7]), iVar6 != 0)) {
      return 0xffffffff;
    }
    _DAT_800b0624 = (&DAT_8009fa38)[uVar7];
    bVar3 = true;
    _DAT_800afeb4 = uVar7;
    if (bVar1) {
      FUN_8006ee60(uVar7);
    }
    FUN_8006db4c(&local_80,_DAT_800afeb4 * 0x44 + -0x7ff60578,0x44);
    if (_DAT_800afeb4 == 7) {
      _DAT_800afec0 = 0xff;
      _DAT_800afebc = 0xff;
    }
    else if (_DAT_800afeb4 == 8) {
      _DAT_800afec0 = 0;
      _DAT_800afebc = 0xff;
    }
    else {
      _DAT_800afec0 = 0;
      _DAT_800afebc = 0;
    }
  }
  if ((bVar2) || ((uVar8 & 8) != 0)) {
    if (((int)_DAT_800afeb4 < 9) && (6 < (int)_DAT_800afeb4)) {
      bVar4 = true;
      if (!bVar3) {
        FUN_8006db4c(&local_80,_DAT_800afeb4 * 0x44 + -0x7ff60578,0x44);
        local_80 = 0xc011c00;
      }
      _DAT_800afebc = param_1[3];
      local_68 = (short)((int)(_DAT_800afebc << 0xd) / 0x7f) - local_7c;
      local_46 = (short)((int)(_DAT_800afebc << 0xc) / 0x7f);
      local_66 = local_46 - local_7a;
      local_64 = local_46 + local_62;
      local_5c = local_46 + local_5a;
      local_48 = local_46 + local_44;
      local_46 = local_46 + local_42;
    }
    else {
      _DAT_800afebc = 0;
    }
  }
  if ((bVar2) || ((uVar8 & 0x10) != 0)) {
    if (((int)_DAT_800afeb4 < 9) && (6 < (int)_DAT_800afeb4)) {
      bVar5 = true;
      if (!bVar3) {
        if (bVar4) {
          local_80 = local_80 | 0x80;
        }
        else {
          FUN_8006db4c(&local_80,_DAT_800afeb4 * 0x44 + -0x7ff60578,0x44);
          local_80 = 0x80;
        }
      }
      _DAT_800afec0 = param_1[4];
      local_6e = (undefined2)((int)(_DAT_800afec0 * 0x8100) / 0x7f);
    }
    else {
      _DAT_800afec0 = 0;
    }
  }
  if (bVar3) {
    FUN_8006c7e8(_DAT_800abfac,0x6a,local_38);
    if (local_38[0] != 0) {
      local_38[1] = 0;
      FUN_8006c7e8(_DAT_800abfac,0x60,local_38 + 1);
    }
    iVar6 = DAT_800a0030;
    *(undefined2 *)(DAT_800a0030 + 0x184) = 0;
    *(undefined2 *)(iVar6 + 0x186) = 0;
    _DAT_800afeb8 = 0;
    _DAT_800afeba = 0;
  }
  else {
    if ((bVar2) || ((uVar8 & 2) != 0)) {
      *(short *)(DAT_800a0030 + 0x184) = (short)param_1[2];
      _DAT_800afeb8 = (undefined2)param_1[2];
    }
    if ((bVar2) || ((uVar8 & 4) != 0)) {
      *(undefined2 *)(DAT_800a0030 + 0x186) = *(undefined2 *)((int)param_1 + 10);
      _DAT_800afeba = *(undefined2 *)((int)param_1 + 10);
    }
  }
  if (((bVar3) || (bVar4)) || (bVar5)) {
    FUN_8006c7e8(_DAT_800abfac,99,&local_80);
  }
  if ((bVar3) && (FUN_8006c7e8(_DAT_800abfac,0x61,&DAT_800b0624), local_38[0] != 0)) {
    FUN_8006c7e8(_DAT_800abfac,0x60,local_38);
  }
  return 0;
}



// ---- FUN_8006e06c @ 8006e06c

void FUN_8006e06c(void)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  puVar3 = DAT_800a0260;
  iVar8 = 0;
  if (-1 < DAT_800a003c) {
    puVar4 = DAT_800a0260;
    do {
      iVar5 = iVar8 + 1;
      if ((*puVar4 & 0x80000000) == 0) {
LAB_8006e124:
        puVar4 = puVar4 + 2;
        iVar8 = iVar8 + 1;
      }
      else {
        puVar2 = puVar3 + iVar5 * 2;
        while (uVar1 = *puVar2, puVar2 = puVar2 + 2, uVar1 == 0x2fffffff) {
          iVar5 = iVar5 + 1;
        }
        puVar2 = puVar3 + iVar5 * 2;
        if (((*puVar2 & 0x80000000) == 0) ||
           ((*puVar2 & 0xfffffff) != (*puVar4 & 0xfffffff) + puVar4[1])) goto LAB_8006e124;
        *puVar2 = 0x2fffffff;
        puVar4[1] = puVar4[1] + puVar2[1];
      }
    } while (iVar8 <= DAT_800a003c);
  }
  iVar8 = DAT_800a003c;
  iVar5 = 0;
  if (-1 < DAT_800a003c) {
    puVar3 = DAT_800a0260;
    do {
      iVar5 = iVar5 + 1;
      if (puVar3[1] == 0) {
        *puVar3 = 0x2fffffff;
      }
      puVar3 = puVar3 + 2;
    } while (iVar5 <= iVar8);
  }
  puVar3 = DAT_800a0260;
  iVar8 = 0;
  if (-1 < DAT_800a003c) {
    puVar4 = DAT_800a0260;
    do {
      iVar5 = DAT_800a003c;
      if ((*puVar4 & 0x40000000) != 0) break;
      iVar6 = iVar8 + 1;
      if (iVar6 <= DAT_800a003c) {
        puVar2 = puVar3 + iVar6 * 2;
        do {
          uVar1 = *puVar2;
          if ((uVar1 & 0x40000000) != 0) break;
          uVar7 = *puVar4;
          iVar6 = iVar6 + 1;
          if ((uVar1 & 0xfffffff) < (uVar7 & 0xfffffff)) {
            *puVar4 = uVar1;
            uVar1 = puVar4[1];
            puVar4[1] = puVar2[1];
            *puVar2 = uVar7;
            puVar2[1] = uVar1;
          }
          puVar2 = puVar2 + 2;
        } while (iVar6 <= iVar5);
      }
      iVar8 = iVar8 + 1;
      puVar4 = puVar4 + 2;
    } while (iVar8 <= DAT_800a003c);
  }
  iVar8 = 0;
  if (-1 < DAT_800a003c) {
    puVar3 = DAT_800a0260;
    do {
      if ((*puVar3 & 0x40000000) != 0) break;
      if (*puVar3 == 0x2fffffff) {
        puVar4 = DAT_800a0260 + DAT_800a003c * 2;
        *puVar3 = *puVar4;
        DAT_800a003c = iVar8;
        puVar3[1] = puVar4[1];
        break;
      }
      iVar8 = iVar8 + 1;
      puVar3 = puVar3 + 2;
    } while (iVar8 <= DAT_800a003c);
  }
  puVar3 = DAT_800a0260;
  iVar8 = DAT_800a003c + -1;
  if (-1 < iVar8) {
    puVar4 = DAT_800a0260 + iVar8 * 2;
    do {
      if ((*puVar4 & 0x80000000) == 0) {
        return;
      }
      *puVar4 = *puVar4 & 0xfffffff | 0x40000000;
      iVar5 = DAT_800a003c * 2;
      iVar6 = iVar8 + -1;
      DAT_800a003c = iVar8;
      puVar4[1] = puVar4[1] + puVar3[iVar5 + 1];
      puVar4 = puVar4 + -2;
      iVar8 = iVar6;
    } while (-1 < iVar6);
  }
  return;
}



// ---- FUN_8006e368 @ 8006e368

int FUN_8006e368(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = DAT_800a0034;
  if (param_1 < 1) {
    param_1 = 0;
  }
  else {
    *param_2 = 0x40001000;
    DAT_800a003c = 0;
    DAT_800a0258 = ((*(ushort *)(iVar1 + 0x1ac) & 0xe) >> 1) + 1;
    DAT_800a0038 = param_1;
    DAT_800a0260 = param_2;
    param_2[1] = (0x10000 << DAT_800a0258) + -0x1000;
  }
  return param_1;
}



// ---- FUN_8006e3d8 @ 8006e3d8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_8006e3d8(uint param_1)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar7 = 0;
  iVar8 = -1;
  if (_DAT_800ab2e0 == 0) {
    iVar9 = 0;
  }
  else {
    iVar9 = 0x10000 - _DAT_800b0624 << (DAT_800a0258 & 0x1f);
  }
  uVar3 = (1 << (DAT_800a0258 & 0x1f)) - 1;
  if ((param_1 & ~uVar3) != 0) {
    param_1 = param_1 + uVar3;
  }
  uVar3 = ((int)param_1 >> (DAT_800a0258 & 0x1f)) << (DAT_800a0258 & 0x1f);
  if ((*DAT_800a0260 & 0x40000000) == 0) {
    FUN_8006e06c();
    if (0 < DAT_800a0038) {
      puVar4 = DAT_800a0260;
      do {
        if (((*puVar4 & 0x40000000) != 0) || (((*puVar4 & 0x80000000) != 0 && (uVar3 <= puVar4[1])))
           ) {
          iVar8 = iVar7;
          break;
        }
        iVar7 = iVar7 + 1;
        puVar4 = puVar4 + 2;
      } while (iVar7 < DAT_800a0038);
    }
  }
  else {
    iVar8 = 0;
  }
  uVar1 = 0xffffffff;
  if (iVar8 != -1) {
    puVar4 = DAT_800a0260 + iVar8 * 2;
    if ((*puVar4 & 0x40000000) == 0) {
      uVar1 = puVar4[1];
      if (uVar3 < uVar1) {
        if (DAT_800a003c < DAT_800a0038) {
          puVar2 = DAT_800a0260 + DAT_800a003c * 2;
          uVar5 = *puVar2;
          uVar6 = puVar2[1];
          *puVar2 = uVar3 + *puVar4 | 0x80000000;
          puVar2[1] = uVar1 - uVar3;
          DAT_800a003c = DAT_800a003c + 1;
          puVar2[2] = uVar5;
          puVar2[3] = uVar6;
        }
      }
      puVar4 = DAT_800a0260 + iVar8 * 2;
      puVar4[1] = uVar3;
      *puVar4 = *puVar4 & 0xfffffff;
      FUN_8006e06c();
      uVar1 = DAT_800a0260[iVar8 * 2];
    }
    else {
      uVar1 = 0xffffffff;
      if ((iVar8 < DAT_800a0038) && (uVar1 = 0xffffffff, uVar3 <= puVar4[1] - iVar9)) {
        DAT_800a003c = iVar8 + 1;
        puVar2 = DAT_800a0260 + DAT_800a003c * 2;
        *puVar2 = (*puVar4 & 0xfffffff) + uVar3 | 0x40000000;
        puVar2[1] = puVar4[1] - uVar3;
        puVar4[1] = uVar3;
        *puVar4 = *puVar4 & 0xfffffff;
        FUN_8006e06c();
        uVar1 = DAT_800a0260[iVar8 * 2];
      }
    }
  }
  return uVar1;
}



// ---- FUN_8006e698 @ 8006e698

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8006e698(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  iVar1 = DAT_800a0260;
  iVar3 = DAT_800a003c;
  puVar2 = (uint *)(param_1 * 8 + DAT_800a0260);
  uVar11 = *puVar2;
  uVar12 = puVar2[1];
  uVar10 = param_2 - (uVar11 & 0xfffffff);
  if (_DAT_800ab2e0 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = 0x10000 - _DAT_800b0624 << (DAT_800a0258 & 0x1f);
  }
  if ((uVar11 & 0x40000000) == 0) {
    uVar9 = uVar12 - uVar10;
  }
  else {
    uVar9 = (uVar12 - uVar10) - iVar5;
  }
  if ((int)uVar9 < (int)param_3) {
    return -1;
  }
  if ((uVar11 & 0x40000000) == 0) {
    if ((int)uVar10 < 1) {
      if (((int)param_3 < (int)uVar9) && (DAT_800a0038 + -1 < DAT_800a003c)) {
        return -1;
      }
      puVar2 = (uint *)(param_1 * 8 + DAT_800a0260);
      puVar2[1] = param_3;
      *puVar2 = *puVar2 & 0xfffffff;
      if ((int)param_3 < (int)uVar9) {
        puVar2 = (uint *)(DAT_800a003c * 8 + iVar1);
        uVar10 = *puVar2;
        uVar12 = puVar2[1];
        *puVar2 = (uVar11 & 0xfffffff) + param_3 | 0x80000000;
        puVar2[1] = uVar9 - param_3;
        DAT_800a003c = DAT_800a003c + 1;
        puVar2[2] = uVar10;
        puVar2[3] = uVar12;
      }
    }
    else {
      if (uVar9 == param_3) {
        iVar5 = DAT_800a0038 + -2;
      }
      else {
        iVar5 = DAT_800a0038 + -1;
      }
      if (iVar5 < DAT_800a003c) {
        return -1;
      }
      *(uint *)(param_1 * 8 + DAT_800a0260 + 4) = uVar10;
      piVar4 = (int *)(DAT_800a003c * 8 + iVar1);
      iVar5 = *piVar4;
      iVar6 = piVar4[1];
      *piVar4 = param_2;
      piVar4[1] = param_3;
      iVar7 = DAT_800a003c + 1;
      DAT_800a003c = iVar7;
      piVar4[2] = iVar5;
      piVar4[3] = iVar6;
      if ((int)param_3 <= (int)uVar9) {
        puVar2 = (uint *)(iVar7 * 8 + iVar1);
        uVar12 = *puVar2;
        uVar8 = puVar2[1];
        *puVar2 = (uVar11 & 0xfffffff) + uVar10 + param_3 | 0x80000000;
        puVar2[1] = uVar9 - param_3;
        DAT_800a003c = iVar3 + 2;
        puVar2[2] = uVar12;
        puVar2[3] = uVar8;
      }
    }
  }
  else {
    if ((int)uVar10 < 1) {
      if (DAT_800a0038 + -1 < DAT_800a003c) {
        return -1;
      }
      puVar2 = (uint *)(DAT_800a003c * 8 + DAT_800a0260);
      puVar2[1] = param_3;
      *puVar2 = *puVar2 & 0xfffffff;
    }
    else {
      if (DAT_800a0038 + -2 < DAT_800a003c) {
        return -1;
      }
      puVar2 = (uint *)(DAT_800a003c * 8 + DAT_800a0260);
      DAT_800a003c = DAT_800a003c + 1;
      iVar3 = DAT_800a003c * 8;
      puVar2[1] = uVar10;
      piVar4 = (int *)(iVar3 + iVar1);
      *puVar2 = *puVar2 & 0xfffffff | 0x80000000;
      *piVar4 = param_2;
      piVar4[1] = param_3;
    }
    DAT_800a003c = DAT_800a003c + 1;
    puVar2 = (uint *)(DAT_800a003c * 8 + DAT_800a0260);
    *puVar2 = (uVar11 & 0xfffffff) + uVar10 + param_3 | 0x40000000;
    puVar2[1] = (uVar12 - uVar10) - param_3;
  }
  FUN_8006e06c();
  return param_2;
}



// ---- FUN_8006e9f4 @ 8006e9f4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_8006e9f4(uint param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  puVar1 = DAT_800a0260;
  if (_DAT_800ab2e0 == 0) {
    iVar7 = 0;
  }
  else {
    iVar7 = 0x10000 - _DAT_800b0624 << (DAT_800a0258 & 0x1f);
  }
  uVar3 = (1 << (DAT_800a0258 & 0x1f)) - 1;
  if ((param_2 & ~uVar3) != 0) {
    param_2 = param_2 + uVar3;
  }
  uVar6 = ((int)param_2 >> (DAT_800a0258 & 0x1f)) << (DAT_800a0258 & 0x1f);
  if ((param_1 & ~uVar3) != 0) {
    param_1 = param_1 + uVar3;
  }
  uVar5 = ((int)param_1 >> (DAT_800a0258 & 0x1f)) << (DAT_800a0258 & 0x1f);
  uVar3 = 0xffffffff;
  if (0xfff < (int)uVar5) {
    uVar4 = uVar5 + uVar6;
    uVar3 = 0xffffffff;
    if ((int)uVar4 <= (0x10000 << (DAT_800a0258 & 0x1f)) - iVar7) {
      if ((*DAT_800a0260 & 0x40000000) == 0) {
        FUN_8006e06c();
        iVar2 = 0;
LAB_8006eb94:
        puVar1 = DAT_800a0260 + iVar2 * 2;
        uVar3 = *puVar1;
        if ((int)uVar3 < 0) {
          uVar3 = uVar3 & 0xfffffff;
          if (uVar5 < uVar3) {
            if ((int)uVar6 <= (int)puVar1[1]) goto LAB_8006ec6c;
            iVar2 = iVar2 + 1;
            goto LAB_8006eb94;
          }
          if (((uVar5 < uVar3 + puVar1[1]) || ((puVar1[2] & 0x40000000) != 0)) &&
             (uVar3 = uVar5,
             (int)uVar6 <=
             (int)((DAT_800a0260 + iVar2 * 2)[1] - (uVar5 - (DAT_800a0260[iVar2 * 2] & 0xfffffff))))
             ) goto LAB_8006ec6c;
LAB_8006ec4c:
          iVar2 = iVar2 + 1;
          goto LAB_8006eb94;
        }
        if ((uVar3 & 0x40000000) == 0) goto LAB_8006ec4c;
        uVar3 = uVar3 & 0xfffffff;
        if ((int)(puVar1[1] - iVar7) < (int)uVar6) {
          return 0xffffffff;
        }
LAB_8006ec6c:
        uVar3 = FUN_8006e698(iVar2,uVar3,uVar6);
      }
      else {
        uVar3 = ((DAT_800a0260[1] + 0x1000) - uVar5) - uVar6;
        if ((int)(uVar5 - 0x1000) < 1) {
          if (DAT_800a0038 + -1 < DAT_800a003c) {
            return 0xffffffff;
          }
          *DAT_800a0260 = uVar5;
          puVar1[1] = uVar6;
          puVar1[2] = uVar4 | 0x40000000;
          puVar1[3] = uVar3;
          DAT_800a003c = 1;
        }
        else {
          if (DAT_800a0038 + -2 < DAT_800a003c) {
            return 0xffffffff;
          }
          *DAT_800a0260 = 0x80001000;
          puVar1[1] = uVar5 - 0x1000;
          puVar1[2] = uVar5;
          puVar1[3] = uVar6;
          puVar1[4] = uVar4 | 0x40000000;
          puVar1[5] = uVar3;
          DAT_800a003c = 2;
        }
        uVar3 = uVar5;
      }
      FUN_8006e06c();
    }
  }
  return uVar3;
}



// ---- FUN_8006ec9c @ 8006ec9c

undefined4 FUN_8006ec9c(uint param_1)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = DAT_800a0260;
  do {
    uVar1 = *puVar2;
    if ((uVar1 & 0x80000000) == 0) {
      if ((uVar1 & 0x40000000) != 0) {
        return 0;
      }
      if (param_1 <= (uVar1 & 0xfffffff)) {
        return 1;
      }
      if (param_1 < (uVar1 & 0xfffffff) + puVar2[1]) {
        return 1;
      }
    }
    puVar2 = puVar2 + 2;
  } while( true );
}



// ---- FUN_8006ed0c @ 8006ed0c

void FUN_8006ed0c(int param_1)

{
  FUN_8006ec9c(param_1 << (DAT_800a0258 & 0x1f));
  return;
}



// ---- FUN_8006ed34 @ 8006ed34

void FUN_8006ed34(uint param_1)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < DAT_800a0038) {
    puVar1 = DAT_800a0260;
    do {
      if ((*puVar1 & 0x40000000) != 0) break;
      iVar2 = iVar2 + 1;
      if (*puVar1 == param_1) {
        *puVar1 = param_1 | 0x80000000;
        break;
      }
      puVar1 = puVar1 + 2;
    } while (iVar2 < DAT_800a0038);
  }
  FUN_8006e06c();
  return;
}



// ---- FUN_8006edb0 @ 8006edb0

void FUN_8006edb0(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (-1 < DAT_800a0038) {
    do {
      iVar2 = iVar3 * 8;
      puVar1 = (undefined4 *)(iVar2 + DAT_800a0260);
      FUN_80058614(s___d___08x____08x___08d__80029a04,iVar3,*puVar1,puVar1[1],puVar1[1]);
      iVar3 = iVar3 + 1;
      if ((*(uint *)(iVar2 + DAT_800a0260) & 0x40000000) != 0) {
        return;
      }
    } while (iVar3 <= DAT_800a0038);
  }
  return;
}



// ---- FUN_8006ee60 @ 8006ee60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8006ee60(uint param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int local_28 [2];
  
  bVar1 = true;
  bVar2 = false;
  iVar4 = ((*(ushort *)(DAT_800a0040 + 0x1ac) & 0xe) >> 1) + 1;
  if (param_1 < 10) {
    iVar3 = FUN_8006ed0c((&DAT_8009fa38)[param_1]);
    if (iVar3 == 0) {
      iVar3 = (&DAT_8009fa38)[param_1];
      uVar6 = 0x10000 - iVar3 << iVar4;
      iVar3 = iVar3 << iVar4;
      FUN_8006c7e8(_DAT_800abfac,0x2f,local_28);
      if (local_28[0] == 0) {
        local_28[1] = 1;
        bVar2 = true;
        FUN_8006c7e8(_DAT_800abfac,0x2e,local_28 + 1);
      }
      do {
        if (uVar6 < 0x401) {
          bVar1 = false;
          uVar5 = uVar6;
        }
        else {
          uVar5 = 0x400;
        }
        FUN_8006f1f4(iVar3);
        FUN_8006f244(&DAT_8009f628,uVar5);
        FUN_8006f0b4(1);
        uVar6 = uVar6 - 0x400;
        iVar3 = iVar3 + 0x400;
      } while (bVar1);
      if (bVar2) {
        FUN_8006c7e8(_DAT_800abfac,0x2e,local_28);
      }
      return 0;
    }
  }
  return 0xffffffff;
}



// ---- FUN_8006efa8 @ 8006efa8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_8006efa8(undefined4 param_1,uint param_2)

{
  if (0x7f000 < param_2) {
    param_2 = 0x7f000;
  }
  FUN_8006c430(param_1,param_2);
  if (_DAT_800ab74c == 0) {
    _DAT_800ab57c = 0;
  }
  return param_2;
}



// ---- FUN_8006f008 @ 8006f008

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8006f008(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    _DAT_800aee70 = 0;
  }
  else {
    if (param_1 != 1) {
      return _DAT_800aee70;
    }
    if ((_DAT_800ab2e0 == 1) || (iVar1 = FUN_8006ed0c(_DAT_800b0624), iVar1 == 0)) {
      _DAT_800aee70 = 1;
    }
    else {
      _DAT_800aee70 = 0;
    }
  }
  FUN_8006c7e8(_DAT_800abfac,0x60,&DAT_800aee70);
  return _DAT_800aee70;
}



// ---- FUN_8006f0b4 @ 8006f0b4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_8006f0b4(int param_1)

{
  int iVar1;
  
  if ((_DAT_800ab5a8 == 1) || (_DAT_800ab57c == 1)) {
    iVar1 = 1;
  }
  else {
    iVar1 = FUN_80058594(_DAT_800b05d0);
    if (param_1 == 1) {
      while (iVar1 == 0) {
        iVar1 = FUN_80058594(_DAT_800b05d0);
      }
      _DAT_800ab57c = 1;
    }
    else if (iVar1 == 1) {
      _DAT_800ab57c = 1;
    }
  }
  return iVar1;
}



// ---- FUN_8006f164 @ 8006f164

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8006f164(int param_1)

{
  _DAT_800ab57c = (uint)(param_1 != 1);
  return;
}



// ---- FUN_8006f190 @ 8006f190

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_8006f190(void)

{
  return _DAT_800ab57c == 0;
}



// ---- FUN_8006f1a0 @ 8006f1a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8006f1a0(int param_1)

{
  undefined4 local_10 [2];
  
  if ((param_1 == 0) || (param_1 != 1)) {
    local_10[0] = 1;
  }
  else {
    local_10[0] = 0;
  }
  _DAT_800ab5a8 = param_1;
  FUN_8006c7e8(_DAT_800abfac,0x21,local_10);
  return;
}



// ---- FUN_8006f1f4 @ 8006f1f4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_8006f1f4(uint param_1)

{
  uint local_res0 [4];
  
  if (param_1 < 0x7f001) {
    local_res0[0] = param_1;
    FUN_8006c7e8(_DAT_800abfac,0x2b,local_res0);
  }
  else {
    local_res0[0] = 0;
  }
  return local_res0[0];
}



// ---- FUN_8006f244 @ 8006f244

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_8006f244(undefined4 param_1,uint param_2)

{
  if (0x7f000 < param_2) {
    param_2 = 0x7f000;
  }
  FUN_8006c1c8(param_1,param_2);
  if (_DAT_800ab74c == 0) {
    _DAT_800ab57c = 0;
  }
  return param_2;
}



// ---- FUN_8006f2a4 @ 8006f2a4

undefined8 FUN_8006f2a4(uint param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 local_20;
  uint local_1c;
  
  uVar2 = 0;
  iVar1 = 0x41d;
  if (param_1 == 0) {
    local_20 = 0;
    uVar2 = 0;
  }
  else {
    if ((int)param_1 < 0) {
      uVar2 = 0x80000000;
      param_1 = -param_1;
    }
    for (; (int)param_1 < 0x1000000; param_1 = param_1 << 4) {
      iVar1 = iVar1 + -4;
    }
    for (local_1c = param_1; (int)local_1c < 0x40000000; local_1c = local_1c << 1) {
      iVar1 = iVar1 + -1;
    }
    local_20 = 0;
    FUN_800706a8(&local_20,1,0,local_1c,10);
    uVar2 = uVar2 | local_1c & 0xffefffff | iVar1 << 0x14;
  }
  return CONCAT44(uVar2,local_20);
}



// ---- FUN_8006f3a0 @ 8006f3a0

undefined8 FUN_8006f3a0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  uint local_34;
  
  local_38 = 0;
  local_34 = 0;
  uVar3 = 0;
  if (((param_2 & 0x7fffffff) == 0) && (param_1 == 0)) goto LAB_8006f6f0;
  if ((param_4 & 0x7fffffff) == 0) {
    if (param_3 != 0) goto LAB_8006f424;
  }
  else {
LAB_8006f424:
    uVar1 = (int)param_2 >> 0x14 & 0x7ff;
    uVar2 = (int)param_4 >> 0x14 & 0x7ff;
    if (uVar1 <= uVar2 + 0x36) {
      if (uVar1 + 0x36 < uVar2) goto LAB_8006f6f0;
      local_4c = param_2 & 0xfffff | 0x100000;
      local_44 = param_4 & 0xfffff | 0x100000;
      local_50 = param_1;
      local_48 = param_3;
      if ((int)param_2 < 0) {
        FUN_80070638(&local_50,param_1);
      }
      if ((param_4 & 0x80000000) != 0) {
        FUN_80070638(&local_48,local_48,local_44);
      }
      FUN_8006f71c(&local_50,0,local_50,local_4c,9);
      FUN_8006f71c(&local_48,0,local_48,local_44,9);
      if (uVar2 < uVar1) {
        FUN_8006f71c(&local_48,1,local_48,local_44,uVar1 - uVar2);
        uVar2 = uVar1;
      }
      else {
        FUN_8006f71c(&local_50,1,local_50,local_4c,uVar2 - uVar1);
      }
      FUN_8006f7e0(&local_50,local_50,local_4c,local_48,local_44);
      if ((int)local_4c < 0) {
        uVar3 = 0x80000000;
        FUN_80070638(&local_50,local_50);
      }
      else if ((local_4c == 0) && (local_50 == 0)) {
        param_3 = local_38;
        param_4 = local_34;
        goto LAB_8006f6f0;
      }
      while ((local_4c & 0xe0000000) == 0) {
        FUN_8006f71c(&local_50,0,local_50,local_4c,1);
        uVar2 = uVar2 - 1;
      }
      if ((local_4c & 0x40000000) != 0) {
        uVar2 = uVar2 + 1;
        FUN_8006f71c(&local_50,1,local_50,local_4c,1);
      }
      local_3c = 0;
      local_40 = 0xff;
      if ((local_50 & 0x200) != 0) {
        local_40 = 0x100;
      }
      FUN_8006f7e0(&local_50,local_50,local_4c,local_40,0);
      if ((local_4c & 0x40000000) != 0) {
        uVar2 = uVar2 + 1;
        FUN_8006f71c(&local_50,1,local_50,local_4c,1);
      }
      FUN_8006f71c(&local_50,1,local_50,local_4c,9);
      local_4c = local_4c & 0xffefffff;
      if ((int)uVar2 < 0x7ff) {
        param_1 = local_50;
        param_2 = uVar3 | uVar2 << 0x14 | local_4c;
      }
      else {
        FUN_8007086c(0x22,0xb);
        param_2 = 0x7ff00000;
        if (uVar3 != 0) {
          param_2 = 0xfff00000;
        }
        param_1 = 0;
      }
    }
  }
  param_4 = param_2;
  param_3 = param_1;
LAB_8006f6f0:
  return CONCAT44(param_4,param_3);
}



// ---- FUN_8006f71c @ 8006f71c

uint * FUN_8006f71c(uint *param_1,int param_2,uint param_3,uint param_4,int param_5)

{
  int iVar1;
  uint local_res8;
  uint local_resc;
  
  local_res8 = param_3;
  local_resc = param_4;
  if (param_2 == 0) {
    iVar1 = 0;
    if (0 < param_5) {
      do {
        local_resc = local_resc << 1;
        if ((local_res8 & 0x80000000) != 0) {
          local_resc = local_resc | 1;
        }
        local_res8 = local_res8 << 1;
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_5);
    }
  }
  else {
    iVar1 = 0;
    if (0 < param_5) {
      do {
        local_res8 = local_res8 >> 1;
        if ((local_resc & 1) != 0) {
          local_res8 = local_res8 | 0x80000000;
        }
        local_resc = (int)local_resc >> 1;
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_5);
    }
  }
  *param_1 = local_res8;
  param_1[1] = local_resc;
  return param_1;
}



// ---- FUN_8006f7e0 @ 8006f7e0

uint * FUN_8006f7e0(uint *param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  uint uVar1;
  int local_res8;
  uint local_14;
  
  local_14 = param_2 >> 0x10;
  uVar1 = (param_2 & 0xffff) + (param_4 & 0xffff);
  if ((uVar1 & 0x10000) != 0) {
    local_14 = local_14 + 1;
  }
  local_14 = local_14 + (param_4 >> 0x10);
  local_res8 = param_3;
  if ((local_14 & 0x10000) != 0) {
    local_res8 = param_3 + 1;
  }
  *param_1 = local_14 * 0x10000 | uVar1 & 0xffff;
  param_1[1] = local_res8 + param_5;
  return param_1;
}



// ---- FUN_8006f88c @ 8006f88c

undefined8 FUN_8006f88c(int param_1,uint param_2,int param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  uint local_34;
  int local_30;
  uint local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  iVar3 = ((int)param_2 >> 0x14 & 0x7ffU) - ((int)param_4 >> 0x14 & 0x7ffU);
  iVar4 = iVar3 + 0x3fe;
  uVar5 = (param_4 ^ param_2) & 0x80000000;
  if (((param_4 & 0x7fffffff) == 0) && (param_3 == 0)) {
    if (uVar5 == 0) {
      uVar5 = 0x7fffffff;
    }
    else {
      uVar5 = 0xffffffff;
    }
    local_50 = 0xffffffff;
  }
  else if (((param_2 & 0x7fffffff) == 0) && (param_1 == 0)) {
    local_50 = 0;
  }
  else {
    local_34 = param_2 & 0xfffff | 0x100000;
    local_2c = param_4 & 0xfffff | 0x100000;
    local_38 = param_1;
    local_30 = param_3;
    iVar2 = FUN_8006fb28(param_1,local_34,param_3);
    if (iVar2 < 0) {
      iVar4 = iVar3 + 0x3fd;
      FUN_8006f71c(&local_38,0,local_38,local_34,1);
    }
    local_44 = 0x200000;
    local_48 = 0;
    local_50 = 0;
    local_4c = 0;
    do {
      iVar3 = FUN_8006fb28(local_38,local_34,local_30,local_2c);
      if (-1 < iVar3) {
        local_4c = local_4c | local_44;
        local_50 = local_50 | local_48;
        FUN_80070638(&local_28,local_30,local_2c);
        FUN_8006f7e0(&local_38,local_38,local_34,local_28,local_24);
      }
      FUN_8006f71c(&local_38,0,local_38,local_34,1);
      FUN_800706a8(&local_48,1,local_48,local_44,1);
    } while ((local_44 != 0) || (local_48 != 0));
    local_3c = 0;
    local_40 = 1;
    FUN_8006f7e0(&local_50,local_50,local_4c,1,0);
    FUN_800706a8(&local_50,1,local_50,local_4c,1);
    local_4c = local_4c & 0xffefffff;
    if (iVar4 + 1 < 0x7ff) {
      uVar5 = uVar5 | (iVar4 + 1) * 0x100000 | local_4c;
    }
    else {
      FUN_8007086c(0x22,0xf);
      bVar1 = uVar5 != 0;
      uVar5 = 0x7ff00000;
      if (bVar1) {
        uVar5 = 0xfff00000;
      }
      local_50 = 0;
    }
  }
  return CONCAT44(uVar5,local_50);
}



// ---- FUN_8006fb28 @ 8006fb28

int FUN_8006fb28(uint param_1,uint param_2,uint param_3,uint param_4)

{
  if (param_2 <= param_4) {
    if (param_2 < param_4) {
      return -1;
    }
    if (param_1 <= param_3) {
      return -(uint)(param_1 < param_3);
    }
  }
  return 1;
}



// ---- FUN_8006fb6c @ 8006fb6c

undefined8 FUN_8006fb6c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 local_68;
  uint local_64;
  undefined4 local_60;
  undefined4 local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_34;
  
  uVar6 = (param_4 ^ param_2) & 0x80000000;
  if ((((param_2 & 0x7fffffff) == 0) && (param_1 == 0)) ||
     (((param_4 & 0x7fffffff) == 0 && (param_3 == 0)))) {
    local_38 = 0;
    local_34 = uVar6;
    goto LAB_8006fe34;
  }
  local_54 = param_2 & 0xfffff | 0x100000;
  local_4c = param_4 & 0xfffff | 0x100000;
  iVar7 = ((int)param_2 >> 0x14 & 0x7ffU) + ((int)param_4 >> 0x14 & 0x7ffU);
  local_58 = param_1;
  local_50 = param_3;
  FUN_800706a8(&local_48,1,param_1,local_54,0x15);
  uVar1 = local_48;
  FUN_800706a8(&local_48,1,local_50,local_4c,0x15);
  uVar2 = local_48;
  uVar3 = local_58 & 0x1fffff;
  uVar5 = local_50 & 0x1fffff;
  FUN_8006fe6c(&local_68,uVar1,local_48);
  FUN_8006fe6c(&local_40,uVar3,uVar2);
  FUN_800706a8(&local_48,1,local_40,local_3c,0x15);
  FUN_8006f7e0(&local_68,local_68,local_64,local_48,local_44);
  FUN_8006fe6c(&local_40,uVar5,uVar1);
  FUN_800706a8(&local_48,1,local_40,local_3c,0x15);
  FUN_8006f7e0(&local_68,local_68,local_64,local_48,local_44);
  iVar4 = iVar7 + -0x3fe;
  if ((int)local_64 < 0) {
    local_5c = 0;
    local_60 = 0x400;
    FUN_8006f7e0(&local_68,local_68,local_64,0x400,0);
LAB_8006fd98:
    FUN_800706a8(&local_68,1,local_68,local_64,0xb);
  }
  else {
    local_5c = 0;
    local_60 = 0x200;
    FUN_8006f7e0(&local_68,local_68,local_64,0x200,0);
    if ((local_64 & 0x80000000) != 0) goto LAB_8006fd98;
    iVar4 = iVar7 + -0x3ff;
    FUN_800706a8(&local_68,1,local_68,local_64,10);
  }
  local_64 = local_64 & 0xffefffff;
  if (iVar4 < 0x7ff) {
    local_34 = uVar6 | iVar4 << 0x14 | local_64;
    local_38 = local_68;
  }
  else {
    FUN_8007086c(0x22,0xd);
    local_34 = 0x7ff00000;
    if (uVar6 != 0) {
      local_34 = 0xfff00000;
    }
    local_38 = 0;
  }
LAB_8006fe34:
  return CONCAT44(local_34,local_38);
}



// ---- FUN_8006fe6c @ 8006fe6c

int * FUN_8006fe6c(int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int local_28;
  int local_24;
  int local_20;
  uint local_1c;
  
  local_28 = (param_2 & 0xffff) * (param_3 & 0xffff);
  uVar1 = (param_2 >> 0x10) * (param_3 & 0xffff);
  local_24 = 0;
  local_1c = uVar1 >> 0x10;
  local_20 = uVar1 * 0x10000;
  FUN_8006f7e0(&local_28,local_28,0,local_20,local_1c);
  uVar1 = (param_2 & 0xffff) * (param_3 >> 0x10);
  local_1c = uVar1 >> 0x10;
  local_20 = uVar1 * 0x10000;
  FUN_8006f7e0(&local_28,local_28,local_24,local_20,local_1c);
  *param_1 = local_28;
  param_1[1] = (param_2 >> 0x10) * (param_3 >> 0x10) + local_24;
  return param_1;
}



// ---- FUN_8006ff6c @ 8006ff6c

void FUN_8006ff6c(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  uVar4 = FUN_8006f88c(param_1,param_2,DAT_800a0044,DAT_800a0048);
  uVar2 = (undefined4)((ulonglong)uVar4 >> 0x20);
  iVar1 = FUN_80070370(param_1,param_2,0,0);
  if (iVar1 < 0) {
    uVar4 = FUN_8006f3a0((int)uVar4,uVar2,DAT_800a0054,DAT_800a0058);
  }
  else {
    uVar4 = FUN_8006f3a0((int)uVar4,uVar2,DAT_800a004c,DAT_800a0050);
  }
  uVar2 = FUN_8007076c((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
  *param_3 = uVar2;
  uVar4 = 0;
  iVar1 = 0x13;
  uVar5 = FUN_8006f2a4(*param_3);
  uVar2 = (undefined4)((ulonglong)uVar5 >> 0x20);
  uVar6 = FUN_8006fb6c((int)uVar5,uVar2,DAT_800a005c,DAT_800a0060);
  uVar6 = FUN_800705b4(param_1,param_2,(int)uVar6,(int)((ulonglong)uVar6 >> 0x20));
  uVar5 = FUN_8006fb6c((int)uVar5,uVar2,DAT_800a0064,DAT_800a0068);
  uVar5 = FUN_8006f3a0((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar5,
                       (int)((ulonglong)uVar5 >> 0x20));
  uVar3 = (undefined4)((ulonglong)uVar5 >> 0x20);
  uVar2 = (undefined4)uVar5;
  uVar5 = FUN_8006fb6c(uVar2,uVar3,uVar2,uVar3);
  do {
    uVar6 = FUN_8006f2a4(iVar1);
    uVar4 = FUN_800705b4((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar4,
                         (int)((ulonglong)uVar4 >> 0x20));
    uVar4 = FUN_8006f88c((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),(int)uVar4,
                         (int)((ulonglong)uVar4 >> 0x20));
    iVar1 = iVar1 + -2;
  } while (2 < iVar1);
  uVar4 = FUN_800705b4(DAT_800a006c,DAT_800a0070,(int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
  FUN_8006f88c(uVar2,uVar3,(int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
  return;
}



// ---- FUN_8007017c @ 8007017c

undefined4 FUN_8007017c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  uint local_18 [2];
  
  uVar4 = FUN_8006ff6c(param_1,param_2,local_18);
  uVar3 = (undefined4)((ulonglong)uVar4 >> 0x20);
  uVar2 = (undefined4)uVar4;
  if ((local_18[0] & 1) != 0) {
    iVar1 = FUN_8007044c(uVar2,uVar3,0,0);
    if (iVar1 == 0) {
      uVar2 = DAT_800a007c;
    }
    else {
      uVar2 = FUN_8006f88c(DAT_800a0074,DAT_800a0078,uVar2,uVar3);
    }
  }
  return uVar2;
}



// ---- FUN_80070208 @ 80070208

undefined4 FUN_80070208(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint local_18 [2];
  
  uVar3 = FUN_8006f88c(param_1,param_2,DAT_800a0084,DAT_800a0088);
  uVar3 = FUN_8006ff6c((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),local_18);
  uVar2 = (undefined4)((ulonglong)uVar3 >> 0x20);
  uVar1 = (undefined4)uVar3;
  uVar3 = FUN_8006f3a0(uVar1,uVar2,uVar1,uVar2);
  uVar4 = FUN_8006fb6c(uVar1,uVar2,uVar1,uVar2);
  uVar4 = FUN_8006f3a0((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),DAT_800a008c,DAT_800a0090);
  uVar3 = FUN_8006f88c((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),(int)uVar4,
                       (int)((ulonglong)uVar4 >> 0x20));
  uVar1 = (undefined4)uVar3;
  if ((local_18[0] & 1) != 0) {
    uVar1 = FUN_8007057c(uVar1,(int)((ulonglong)uVar3 >> 0x20));
  }
  return uVar1;
}



// ---- FUN_800702e8 @ 800702e8

void FUN_800702e8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_8007049c(param_1,param_2,0,0);
  if (iVar1 < 0) {
    uVar2 = FUN_8006f3a0(param_1,param_2,DAT_800a0094,DAT_800a0098);
  }
  else {
    uVar2 = FUN_800705b4(DAT_800a0094,DAT_800a0098,param_1,param_2);
  }
  FUN_80070208((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  return;
}



// ---- FUN_80070370 @ 80070370

int FUN_80070370(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_2 == param_4) && (param_1 == param_3)) {
    return 0;
  }
  if (((((param_2 & 0x7fffffff) == 0) && (param_1 == 0)) && ((param_4 & 0x7fffffff) == 0)) &&
     (param_3 == 0)) {
    return 0;
  }
  uVar1 = (uint)((param_2 & 0x80000000) != 0);
  if ((param_2 & 0x80000000) != (param_4 & 0x80000000)) goto LAB_80070440;
  uVar2 = (int)param_2 >> 0x14 & 0x7ff;
  uVar1 = (int)param_4 >> 0x14 & 0x7ff;
  if (uVar1 < uVar2) {
LAB_80070430:
    uVar1 = (uint)((int)param_2 < 0);
  }
  else {
    if (uVar2 == uVar1) {
      uVar1 = param_2 & 0xfffff | 0x100000;
      uVar2 = param_4 & 0xfffff | 0x100000;
      if ((uVar2 < uVar1) || ((uVar1 == uVar2 && (param_3 <= param_1)))) goto LAB_80070430;
    }
    uVar1 = (uint)((param_2 & 0x80000000) == 0);
  }
LAB_80070440:
  return -uVar1;
}



// ---- FUN_8007044c @ 8007044c

undefined4 FUN_8007044c(int param_1,uint param_2,int param_3,uint param_4)

{
  if ((param_2 == param_4) && (param_1 == param_3)) {
    return 0;
  }
  if ((param_2 & 0x7fffffff) == 0) {
    if (param_1 != 0) {
      return 1;
    }
    if ((param_4 & 0x7fffffff) == 0) {
      if (param_3 == 0) {
        return 0;
      }
      return 1;
    }
  }
  return 1;
}



// ---- FUN_8007049c @ 8007049c

int FUN_8007049c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_2 == param_4) && (param_1 == param_3)) {
    return 0;
  }
  if (((((param_2 & 0x7fffffff) == 0) && (param_1 == 0)) && ((param_4 & 0x7fffffff) == 0)) &&
     (param_3 == 0)) {
    return 0;
  }
  uVar1 = (uint)((param_2 & 0x80000000) != 0);
  if ((param_2 & 0x80000000) != (param_4 & 0x80000000)) goto LAB_80070570;
  uVar3 = (int)param_2 >> 0x14 & 0x7ff;
  uVar2 = (int)param_4 >> 0x14 & 0x7ff;
  if (uVar2 <= uVar3) {
    uVar1 = (uint)((int)param_2 < 0);
    if (uVar3 != uVar2) goto LAB_80070570;
    uVar2 = param_2 & 0xfffff | 0x100000;
    uVar3 = param_4 & 0xfffff | 0x100000;
    if (uVar3 <= uVar2) {
      uVar1 = (uint)((int)param_2 < 0);
      if (uVar2 != uVar3) goto LAB_80070570;
      if (param_3 <= param_1) {
        uVar1 = (uint)((int)param_2 < 0);
        goto LAB_80070570;
      }
    }
  }
  uVar1 = (uint)((param_2 & 0x80000000) == 0);
LAB_80070570:
  return -uVar1;
}



// ---- FUN_8007057c @ 8007057c

undefined8 FUN_8007057c(int param_1,uint param_2)

{
  uint uVar1;
  
  if ((param_2 != 0) || (uVar1 = 0, param_1 != 0)) {
    uVar1 = param_2 ^ 0x80000000;
  }
  return CONCAT44(uVar1,param_1);
}



// ---- FUN_800705b4 @ 800705b4

int FUN_800705b4(int param_1,uint param_2,int param_3,uint param_4)

{
  if (((param_4 & 0x7fffffff) != 0) || (param_3 != 0)) {
    if (((param_2 & 0x7fffffff) == 0) && (param_1 == 0)) {
      param_1 = FUN_8007057c(param_3,param_4);
    }
    else {
      param_1 = FUN_8006f3a0();
    }
  }
  return param_1;
}



// ---- FUN_80070638 @ 80070638

uint * FUN_80070638(uint *param_1,uint param_2,uint param_3)

{
  uint local_res4;
  uint local_res8;
  
  local_res8 = ~param_3;
  local_res4 = ~param_2;
  FUN_8006f7e0(&local_res4,local_res4,local_res8,1,0);
  *param_1 = local_res4;
  param_1[1] = local_res8;
  return param_1;
}



// ---- FUN_800706a8 @ 800706a8

uint * FUN_800706a8(uint *param_1,int param_2,uint param_3,uint param_4,int param_5)

{
  int iVar1;
  uint local_res8;
  uint local_resc;
  
  local_res8 = param_3;
  local_resc = param_4;
  if (param_2 == 0) {
    iVar1 = 0;
    if (0 < param_5) {
      do {
        local_resc = local_resc << 1;
        if ((local_res8 & 0x80000000) != 0) {
          local_resc = local_resc | 1;
        }
        local_res8 = local_res8 << 1;
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_5);
    }
  }
  else {
    iVar1 = 0;
    if (0 < param_5) {
      do {
        local_res8 = local_res8 >> 1;
        if ((local_resc & 1) != 0) {
          local_res8 = local_res8 | 0x80000000;
        }
        local_resc = local_resc >> 1;
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_5);
    }
  }
  *param_1 = local_res8;
  param_1[1] = local_resc;
  return param_1;
}



// ---- FUN_8007076c @ 8007076c

uint FUN_8007076c(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int local_20;
  uint local_1c;
  
  if (((param_2 & 0x7fffffff) == 0) && (param_1 == 0)) {
    local_1c = param_2 & 0x80000000;
  }
  else {
    uVar1 = (int)param_2 >> 0x14 & 0x7ff;
    iVar2 = uVar1 - 0x41d;
    if (iVar2 < 1) {
      local_1c = param_2 & 0xfffff | 0x100000;
      local_20 = param_1;
      FUN_8006f71c(&local_20,0,param_1,local_1c,10);
      if ((uVar1 - 0x3fe < 0x20) && (local_1c != 0)) {
        local_1c = (int)local_1c >> (-iVar2 & 0x1fU);
        if ((int)param_2 < 0) {
          local_1c = -local_1c;
        }
      }
      else {
        local_1c = 0;
      }
    }
    else {
      FUN_8007086c(0x22,0x11);
      local_1c = 0x80000000;
      if (-1 < (int)param_2) {
        local_1c = 0x7fffffff;
      }
    }
  }
  return local_1c;
}



// ---- FUN_8007086c @ 8007086c

undefined4 FUN_8007086c(int param_1,undefined4 param_2)

{
  DAT_800a009c = param_1;
  DAT_800a00a0 = param_2;
  if (param_1 == 0x21) {
    FUN_8005fe8c(0xf4000002,0x301);
  }
  else if (param_1 == 0x22) {
    FUN_8005fe8c(0xf4000002,0x302);
  }
  return 0;
}


