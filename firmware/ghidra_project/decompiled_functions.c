// Decompiled ESP32 SV241 Firmware
// Processor: Xtensa (ESP32)

// Function at 0x400d1724

void FUN_400d1724(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_400d0028;
  iVar1 = DAT_400d0024;
  if ((param_1 == 1) && (param_2 == DAT_400d0020)) {
    memw();
    *(undefined4 *)(DAT_400d0024 + 0x24) = DAT_400d0028;
    memw();
    *(undefined4 *)(iVar1 + 0x28) = uVar2;
    memw();
    *(undefined4 *)(iVar1 + 0x2c) = uVar2;
    memw();
    *(undefined4 *)(iVar1 + 0x30) = uVar2;
    memw();
    *(undefined4 *)(iVar1 + 0x34) = DAT_400d002c;
    memw();
    *(undefined4 *)(iVar1 + 0x38) = uVar2;
    memw();
    *(undefined4 *)(iVar1 + 0x6c) = uVar2;
    memw();
    *(undefined4 *)(iVar1 + 0x70) = uVar2;
    memw();
    *(undefined4 *)(iVar1 + 0x74) = DAT_400d0030;
    uVar2 = DAT_400d0034;
    FUN_400d36fc(DAT_400d0034,0x17);
    FUN_400d35b0(DAT_400d0038,uVar2);
    FUN_400f78e8(DAT_400d003c);
    FUN_400d46d0(DAT_400d0040,0x40);
  }
  if ((param_1 == 0) && (param_2 == DAT_400d0020)) {
    FUN_400d46e4(DAT_400d0040);
    FUN_400d3d10(DAT_400d003c);
  }
  return;
}



// Function at 0x400d17ac

void FUN_400d17ac(void)

{
  undefined4 uVar1;
  
  uVar1 = DAT_400d0038;
  FUN_400d33cc(DAT_400d0038);
  uVar1 = FUN_400d3530(uVar1,0);
  memw();
  *DAT_400d0024 = uVar1;
  return;
}



// Function at 0x400d17cc

void FUN_400d17cc(void)

{
  int iVar1;
  undefined1 auStack_68 [20];
  undefined4 uStack_54;
  undefined1 auStack_44 [20];
  float fStack_30;
  
  FUN_400d3e44(DAT_400d003c,auStack_68,auStack_44);
  iVar1 = DAT_400d0024;
  memw();
  *(float *)(DAT_400d0024 + 4) = fStack_30 - DAT_400d0044;
  memw();
  *(undefined4 *)(iVar1 + 8) = uStack_54;
  return;
}



// Function at 0x400d17fc

void FUN_400d17fc(void)

{
  int iVar1;
  int iVar2;
  float fVar3;
  
  iVar2 = DAT_400d0024;
  memw();
  fVar3 = *(float *)(DAT_400d0024 + 0xc);
  if (NAN(fVar3 * 1.0)) {
    iVar1 = -0x80000000;
    if (0.0 <= fVar3) {
      iVar1 = 0x7fffffff;
    }
  }
  else {
    iVar1 = (int)(fVar3 * 1.4013e-45);
  }
  FUN_400d5d58(1,iVar1,10);
  FUN_400d5e10(0x19,1);
  memw();
  fVar3 = *(float *)(iVar2 + 0x10);
  if (NAN(fVar3 * 1.0)) {
    iVar1 = -0x80000000;
    if (0.0 <= fVar3) {
      iVar1 = 0x7fffffff;
    }
  }
  else {
    iVar1 = (int)(fVar3 * 1.4013e-45);
  }
  FUN_400d5dbc(1,iVar1);
  memw();
  fVar3 = *(float *)(iVar2 + 0x14);
  if (NAN(fVar3 * 1.0)) {
    iVar1 = -0x80000000;
    if (0.0 <= fVar3) {
      iVar1 = 0x7fffffff;
    }
  }
  else {
    iVar1 = (int)(fVar3 * 1.4013e-45);
  }
  FUN_400d5d58(2,iVar1,10);
  FUN_400d5e10(0x21,2);
  memw();
  fVar3 = *(float *)(iVar2 + 0x18);
  if (NAN(fVar3 * 1.0)) {
    iVar1 = -0x80000000;
    if (0.0 <= fVar3) {
      iVar1 = 0x7fffffff;
    }
  }
  else {
    iVar1 = (int)(fVar3 * 1.4013e-45);
  }
  FUN_400d5dbc(2,iVar1);
  memw();
  fVar3 = *(float *)(iVar2 + 0x1c);
  if (NAN(fVar3 * 1.0)) {
    iVar1 = -0x80000000;
    if (0.0 <= fVar3) {
      iVar1 = 0x7fffffff;
    }
  }
  else {
    iVar1 = (int)(fVar3 * 1.4013e-45);
  }
  FUN_400d5d58(3,iVar1,10);
  FUN_400d5e10(0x20,3);
  memw();
  fVar3 = *(float *)(iVar2 + 0x20);
  if (NAN(fVar3 * 1.0)) {
    iVar2 = -0x80000000;
    if (0.0 <= fVar3) {
      iVar2 = 0x7fffffff;
    }
  }
  else {
    iVar2 = (int)(fVar3 * 1.4013e-45);
  }
  FUN_400d5dbc(3,iVar2);
  return;
}



// Function at 0x400d1874

undefined8 FUN_400d1874(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  iVar1 = (*DAT_400d0060)(param_3,param_4,DAT_400d0028,DAT_400d0028);
  uVar3 = CONCAT44(DAT_400d0048,DAT_400d0028);
  if (0 < iVar1) {
    uVar3 = (*DAT_400d0064)(param_1,param_2,DAT_400d004c,DAT_400d0050);
    uVar4 = (*DAT_400d0068)(param_1,param_2,DAT_400d0054,DAT_400d0058);
    uVar3 = (*DAT_400d006c)((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),(int)uVar4,
                            (int)((ulonglong)uVar4 >> 0x20));
    (*DAT_400d006c)(param_3,param_4,DAT_400d0028,DAT_400d005c);
    uVar4 = FUN_400e9ce8();
    uVar3 = (*DAT_400d0068)((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),(int)uVar4,
                            (int)((ulonglong)uVar4 >> 0x20));
    uVar2 = (undefined4)((ulonglong)uVar3 >> 0x20);
    uVar4 = (*DAT_400d0064)((int)uVar3,uVar2,DAT_400d0054,DAT_400d0058);
    uVar3 = (*DAT_400d0070)(DAT_400d004c,DAT_400d0050,(int)uVar3,uVar2);
    uVar3 = (*DAT_400d006c)((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),(int)uVar3,
                            (int)((ulonglong)uVar3 >> 0x20));
  }
  return uVar3;
}



// Function at 0x400d1928

void FUN_400d1928(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  float fVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  uVar5 = CONCAT44(DAT_400d0074,DAT_400d0028);
  memw();
  fVar4 = (float)DAT_400d0024[1];
  memw();
  memw();
  uVar2 = *DAT_400d0024;
  if (DAT_400d0078 < fVar4) {
    uVar5 = (*DAT_400d008c)(DAT_400d0024[2]);
    uVar6 = (*DAT_400d008c)(fVar4);
    uVar5 = FUN_400d1874((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar5,
                         (int)((ulonglong)uVar5 >> 0x20));
    uVar5 = (*DAT_400d0068)((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),DAT_400d0028,DAT_400d007c);
  }
  else if ((fVar4 < DAT_400d0080) || (DAT_400d0078 < fVar4)) {
    if (DAT_400d0028 <= fVar4) {
      uVar5 = (*DAT_400d008c)();
      uVar6 = (*DAT_400d008c)(fVar4);
      uVar5 = FUN_400d1874((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar5,
                           (int)((ulonglong)uVar5 >> 0x20));
      uVar5 = (*DAT_400d0068)((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),DAT_400d0028,DAT_400d0084);
    }
  }
  else {
    uVar5 = (*DAT_400d008c)();
    uVar6 = (*DAT_400d008c)(fVar4);
    uVar5 = FUN_400d1874((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar5,
                         (int)((ulonglong)uVar5 >> 0x20));
    uVar5 = (*DAT_400d0068)((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),DAT_400d0028,DAT_400d0084);
  }
  uVar6 = (*DAT_400d008c)(uVar2);
  iVar3 = (*DAT_400d0090)((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar5,
                          (int)((ulonglong)uVar5 >> 0x20));
  puVar1 = DAT_400d0024;
  if (iVar3 < 1) {
    memw();
    fVar4 = (float)DAT_400d0024[0xc];
    if (NAN(fVar4 * 1.0)) {
      iVar3 = -0x80000000;
      if (0.0 <= fVar4) {
        iVar3 = 0x7fffffff;
      }
    }
    else {
      iVar3 = (int)(fVar4 * 1.4013e-45);
    }
    if (iVar3 == 2) {
      memw();
      memw();
      fVar4 = (float)DAT_400d0024[0xe];
      memw();
      DAT_400d0024[6] = DAT_400d0024[0xd];
      memw();
      puVar1[0xc] = fVar4;
      puVar1 = DAT_400d0024;
      if (fVar4 != DAT_400d0080) {
        fVar4 = DAT_400d0028;
      }
      memw();
      DAT_400d0024[10] = fVar4;
      memw();
      fVar4 = (float)puVar1[6];
      if (NAN(fVar4 * 1.0)) {
        iVar3 = -0x80000000;
        if (0.0 <= fVar4) {
          iVar3 = 0x7fffffff;
        }
      }
      else {
        iVar3 = (int)(fVar4 * 1.4013e-45);
      }
      FUN_400d5dbc(2,iVar3);
    }
  }
  else {
    memw();
    fVar4 = (float)DAT_400d0024[0xc];
    if (NAN(fVar4 * 1.0)) {
      iVar3 = -0x80000000;
      if (0.0 <= fVar4) {
        iVar3 = 0x7fffffff;
      }
    }
    else {
      iVar3 = (int)(fVar4 * 1.4013e-45);
    }
    if (iVar3 != 2) {
      memw();
      memw();
      DAT_400d0024[0xd] = DAT_400d0024[6];
      memw();
      memw();
      puVar1[0xe] = puVar1[0xc];
      memw();
      puVar1[6] = DAT_400d0028;
      memw();
      puVar1[0xc] = DAT_400d0088;
      memw();
      puVar1[10] = DAT_400d0080;
      FUN_400d5dbc(2,0);
    }
  }
  return;
}



// Function at 0x400d1acc

void FUN_400d1acc(void)

{
  int iVar1;
  float fVar2;
  
  memw();
  fVar2 = *(float *)(DAT_400d0024 + 0x10);
  if (NAN(fVar2 * 1.0)) {
    iVar1 = -0x80000000;
    if (0.0 <= fVar2) {
      iVar1 = 0x7fffffff;
    }
  }
  else {
    iVar1 = (int)(fVar2 * 1.4013e-45);
  }
  FUN_400d5dbc(1,iVar1);
  return;
}



// Function at 0x400d1ae4

void FUN_400d1ae4(void)

{
  int iVar1;
  float fVar2;
  
  memw();
  fVar2 = *(float *)(DAT_400d0024 + 0x30);
  if (NAN(fVar2 * 1.0)) {
    iVar1 = -0x80000000;
    if (0.0 <= fVar2) {
      iVar1 = 0x7fffffff;
    }
  }
  else {
    iVar1 = (int)(fVar2 * 1.4013e-45);
  }
  if (iVar1 == 2) {
    FUN_400d5dbc(2,0);
  }
  else {
    memw();
    fVar2 = *(float *)(DAT_400d0024 + 0x18);
    if (NAN(fVar2 * 1.0)) {
      iVar1 = -0x80000000;
      if (0.0 <= fVar2) {
        iVar1 = 0x7fffffff;
      }
    }
    else {
      iVar1 = (int)(fVar2 * 1.4013e-45);
    }
    FUN_400d5dbc(2,iVar1);
  }
  return;
}



// Function at 0x400d1b14

void FUN_400d1b14(void)

{
  int iVar1;
  float fVar2;
  
  memw();
  fVar2 = *(float *)(DAT_400d0024 + 0x20);
  if (NAN(fVar2 * 1.0)) {
    iVar1 = -0x80000000;
    if (0.0 <= fVar2) {
      iVar1 = 0x7fffffff;
    }
  }
  else {
    iVar1 = (int)(fVar2 * 1.4013e-45);
  }
  FUN_400d5dbc(3,iVar1);
  return;
}



// Function at 0x400d1b2c

void FUN_400d1b2c(void)

{
  int iVar1;
  uint uVar2;
  float fVar3;
  
  iVar1 = DAT_400d0024;
  memw();
  fVar3 = *(float *)(DAT_400d0024 + 0x44);
  if (NAN(fVar3 * 1.0)) {
    uVar2 = 0;
    if (0.0 <= fVar3) {
      uVar2 = 0x7fffffff;
    }
  }
  else {
    uVar2 = (uint)(fVar3 * 1.4013e-45);
  }
  FUN_400d5714(0xd,uVar2 & 0xff);
  memw();
  fVar3 = *(float *)(iVar1 + 0x48);
  if (NAN(fVar3 * 1.0)) {
    uVar2 = 0;
    if (0.0 <= fVar3) {
      uVar2 = 0x7fffffff;
    }
  }
  else {
    uVar2 = (uint)(fVar3 * 1.4013e-45);
  }
  FUN_400d5714(0xc,uVar2 & 0xff);
  memw();
  fVar3 = *(float *)(iVar1 + 0x4c);
  if (NAN(fVar3 * 1.0)) {
    uVar2 = 0;
    if (0.0 <= fVar3) {
      uVar2 = 0x7fffffff;
    }
  }
  else {
    uVar2 = (uint)(fVar3 * 1.4013e-45);
  }
  FUN_400d5714(0xe,uVar2 & 0xff);
  memw();
  fVar3 = *(float *)(iVar1 + 0x50);
  if (NAN(fVar3 * 1.0)) {
    uVar2 = 0;
    if (0.0 <= fVar3) {
      uVar2 = 0x7fffffff;
    }
  }
  else {
    uVar2 = (uint)(fVar3 * 1.4013e-45);
  }
  FUN_400d5714(0x1b,uVar2 & 0xff);
  memw();
  fVar3 = *(float *)(iVar1 + 0x54);
  if (NAN(fVar3 * 1.0)) {
    uVar2 = 0;
    if (0.0 <= fVar3) {
      uVar2 = 0x7fffffff;
    }
  }
  else {
    uVar2 = (uint)(fVar3 * 1.4013e-45);
  }
  FUN_400d5714(0x1a,uVar2 & 0xff);
  memw();
  fVar3 = *(float *)(iVar1 + 0x58);
  if (NAN(fVar3 * 1.0)) {
    uVar2 = 0;
    if (0.0 <= fVar3) {
      uVar2 = 0x7fffffff;
    }
  }
  else {
    uVar2 = (uint)(fVar3 * 1.4013e-45);
  }
  FUN_400d5714(0x13,uVar2 & 0xff);
  memw();
  fVar3 = *(float *)(iVar1 + 0x5c);
  if (NAN(fVar3 * 1.0)) {
    uVar2 = 0;
    if (0.0 <= fVar3) {
      uVar2 = 0x7fffffff;
    }
  }
  else {
    uVar2 = (uint)(fVar3 * 1.4013e-45);
  }
  FUN_400d5714(0x12,uVar2 & 0xff);
  return;
}



// Function at 0x400d1bac

void FUN_400d1bac(void)

{
  int iVar1;
  uint uVar2;
  float fVar3;
  
  FUN_400d5678(0xd,3);
  FUN_400d5678(0xc,3);
  FUN_400d5678(0xe,3);
  FUN_400d5678(0x1b,3);
  FUN_400d5678(0x1a,3);
  FUN_400d5678(0x13,3);
  FUN_400d5678(0x12,3);
  iVar1 = DAT_400d0024;
  memw();
  fVar3 = *(float *)(DAT_400d0024 + 0x44);
  if (NAN(fVar3 * 1.0)) {
    uVar2 = 0;
    if (0.0 <= fVar3) {
      uVar2 = 0x7fffffff;
    }
  }
  else {
    uVar2 = (uint)(fVar3 * 1.4013e-45);
  }
  FUN_400d5714(0xd,uVar2 & 0xff);
  memw();
  fVar3 = *(float *)(iVar1 + 0x48);
  if (NAN(fVar3 * 1.0)) {
    uVar2 = 0;
    if (0.0 <= fVar3) {
      uVar2 = 0x7fffffff;
    }
  }
  else {
    uVar2 = (uint)(fVar3 * 1.4013e-45);
  }
  FUN_400d5714(0xc,uVar2 & 0xff);
  memw();
  fVar3 = *(float *)(iVar1 + 0x4c);
  if (NAN(fVar3 * 1.0)) {
    uVar2 = 0;
    if (0.0 <= fVar3) {
      uVar2 = 0x7fffffff;
    }
  }
  else {
    uVar2 = (uint)(fVar3 * 1.4013e-45);
  }
  FUN_400d5714(0xe,uVar2 & 0xff);
  memw();
  fVar3 = *(float *)(iVar1 + 0x50);
  if (NAN(fVar3 * 1.0)) {
    uVar2 = 0;
    if (0.0 <= fVar3) {
      uVar2 = 0x7fffffff;
    }
  }
  else {
    uVar2 = (uint)(fVar3 * 1.4013e-45);
  }
  FUN_400d5714(0x1b,uVar2 & 0xff);
  memw();
  fVar3 = *(float *)(iVar1 + 0x54);
  if (NAN(fVar3 * 1.0)) {
    uVar2 = 0;
    if (0.0 <= fVar3) {
      uVar2 = 0x7fffffff;
    }
  }
  else {
    uVar2 = (uint)(fVar3 * 1.4013e-45);
  }
  FUN_400d5714(0x1a,uVar2 & 0xff);
  memw();
  fVar3 = *(float *)(iVar1 + 0x58);
  if (NAN(fVar3 * 1.0)) {
    uVar2 = 0;
    if (0.0 <= fVar3) {
      uVar2 = 0x7fffffff;
    }
  }
  else {
    uVar2 = (uint)(fVar3 * 1.4013e-45);
  }
  FUN_400d5714(0x13,uVar2 & 0xff);
  memw();
  fVar3 = *(float *)(iVar1 + 0x5c);
  if (NAN(fVar3 * 1.0)) {
    uVar2 = 0;
    if (0.0 <= fVar3) {
      uVar2 = 0x7fffffff;
    }
  }
  else {
    uVar2 = (uint)(fVar3 * 1.4013e-45);
  }
  FUN_400d5714(0x12,uVar2 & 0xff);
  return;
}



// Function at 0x400d1c60

void FUN_400d1c60(void)

{
  int iVar1;
  undefined4 uVar2;
  float fVar3;
  undefined4 uVar4;
  float fVar5;
  
  uVar2 = DAT_400d0094;
  uVar4 = DAT_400d0040;
  iVar1 = DAT_400d0024;
  memw();
  if (*(float *)(DAT_400d0024 + 0x78) == DAT_400d0028) {
    memw();
    *(undefined4 *)(DAT_400d0024 + 0x80) = DAT_400d0094;
    memw();
    *(undefined4 *)(iVar1 + 0x84) = uVar2;
    memw();
    *(undefined4 *)(iVar1 + 0x8c) = uVar2;
    memw();
    *(undefined4 *)(iVar1 + 0x88) = uVar2;
    memw();
    *(undefined4 *)(iVar1 + 0x90) = uVar2;
  }
  else {
    uVar2 = FUN_400d47e8(DAT_400d0040);
    iVar1 = DAT_400d0024;
    memw();
    *(undefined4 *)(DAT_400d0024 + 0x80) = uVar2;
    uVar2 = FUN_400d47c4(uVar4);
    memw();
    *(undefined4 *)(iVar1 + 0x84) = uVar2;
    uVar2 = FUN_400d480c(uVar4);
    memw();
    *(undefined4 *)(iVar1 + 0x8c) = uVar2;
    memw();
    fVar5 = *(float *)(iVar1 + 0x80);
    memw();
    fVar3 = (float)FUN_400f83dc(*(undefined4 *)(iVar1 + 0x84),DAT_400d002c);
    memw();
    *(float *)(iVar1 + 0x88) = fVar5 + fVar3;
    uVar4 = FUN_400d482c(uVar4);
    memw();
    *(undefined4 *)(iVar1 + 0x90) = uVar4;
  }
  return;
}



// Function at 0x400d1cfc

undefined4 FUN_400d1cfc(void)

{
  FUN_400d17ac();
  FUN_400d17cc();
  FUN_400d1928();
  FUN_400d1acc();
  FUN_400d1ae4();
  FUN_400d1b14();
  FUN_400d1b2c();
  FUN_400d1c60();
  return 1;
}



// Function at 0x400d1d1c

void FUN_400d1d1c(int param_1,undefined1 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte local_64 [64];
  int iStack_24;
  
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  func_0x40086818(local_64 + 2,0,0x3e);
  local_64[0] = 0x24;
  local_64[1] = (char)param_1 + '\x04';
  local_64[2] = param_2;
  iVar2 = 0;
  for (iVar1 = 3; iVar1 < param_1 + 3; iVar1 = iVar1 + 1) {
    local_64[iVar1] = *(byte *)(param_3 + iVar2);
    iVar2 = iVar2 + 1;
  }
  iVar3 = 0;
  for (iVar2 = 0; iVar2 < iVar1; iVar2 = iVar2 + 1) {
    iVar3 = iVar3 + (uint)local_64[iVar2];
  }
  local_64[iVar1] =
       (char)iVar3 +
       ((char)(iVar3 + (int)((ulonglong)((longlong)iVar3 * (longlong)DAT_400d009c) >> 0x20) >> 7) -
       (char)(iVar3 >> 0x1f));
  (**(code **)(*DAT_400d00a0 + 0xc))(DAT_400d00a0,local_64);
  memw();
  memw();
  if (iStack_24 == *DAT_400d0098) {
    return;
  }
  func_0x400831d4();
  return;
}



// Function at 0x400d2618

void FUN_400d2618(void)

{
  longlong lVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  char cStack_24;
  char cStack_23;
  char cStack_22;
  char cStack_21;
  
  memw();
  fVar7 = *(float *)(DAT_400d0024 + 0x88) * DAT_400d00e8;
  fVar3 = (float)FUN_400f83dc(fVar7,DAT_400d00ec);
  iVar2 = DAT_400d009c;
  if (NAN(fVar3 * 1.0)) {
    iVar4 = -0x80000000;
    if (0.0 <= fVar3) {
      iVar4 = 0x7fffffff;
    }
  }
  else {
    iVar4 = (int)(fVar3 * 1.4013e-45);
  }
  lVar1 = (longlong)DAT_400d009c;
  fVar3 = (float)FUN_400f83dc(fVar7,DAT_400d00f0);
  if (NAN(fVar3 * 1.0)) {
    iVar5 = -0x80000000;
    if (0.0 <= fVar3) {
      iVar5 = 0x7fffffff;
    }
  }
  else {
    iVar5 = (int)(fVar3 * 1.4013e-45);
  }
  fVar3 = (float)FUN_400f83dc(fVar7,DAT_400d00f4);
  if (NAN(fVar3 * 1.0)) {
    iVar6 = -0x80000000;
    if (0.0 <= fVar3) {
      iVar6 = 0x7fffffff;
    }
  }
  else {
    iVar6 = (int)(fVar3 * 1.4013e-45);
  }
  cStack_22 = (char)iVar6 +
              ((char)(iVar6 + (int)((ulonglong)((longlong)iVar6 * (longlong)iVar2) >> 0x20) >> 7) -
              (char)(iVar6 >> 0x1f));
  if (NAN(fVar7 * 1.0)) {
    iVar6 = -0x80000000;
    if (0.0 <= fVar7) {
      iVar6 = 0x7fffffff;
    }
  }
  else {
    iVar6 = (int)(fVar7 * 1.4013e-45);
  }
  cStack_21 = (char)iVar6 +
              ((char)(iVar6 + (int)((ulonglong)((longlong)iVar6 * (longlong)iVar2) >> 0x20) >> 7) -
              (char)(iVar6 >> 0x1f));
  cStack_24 = (char)iVar4 +
              ((char)(iVar4 + (int)((ulonglong)(iVar4 * lVar1) >> 0x20) >> 7) -
              (char)(iVar4 >> 0x1f));
  cStack_23 = (char)iVar5 +
              ((char)(iVar5 + (int)((ulonglong)((longlong)iVar5 * (longlong)iVar2) >> 0x20) >> 7) -
              (char)(iVar5 >> 0x1f));
  FUN_400d1d1c(4,3,&cStack_24);
  return;
}



// Function at 0x400d26e0

void FUN_400d26e0(void)

{
  longlong lVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  char cStack_24;
  char cStack_23;
  char cStack_22;
  char cStack_21;
  
  memw();
  fVar7 = *(float *)(DAT_400d0024 + 0x8c) * DAT_400d00e8;
  fVar3 = (float)FUN_400f83dc(fVar7,DAT_400d00ec);
  iVar2 = DAT_400d009c;
  if (NAN(fVar3 * 1.0)) {
    iVar4 = -0x80000000;
    if (0.0 <= fVar3) {
      iVar4 = 0x7fffffff;
    }
  }
  else {
    iVar4 = (int)(fVar3 * 1.4013e-45);
  }
  lVar1 = (longlong)DAT_400d009c;
  fVar3 = (float)FUN_400f83dc(fVar7,DAT_400d00f0);
  if (NAN(fVar3 * 1.0)) {
    iVar5 = -0x80000000;
    if (0.0 <= fVar3) {
      iVar5 = 0x7fffffff;
    }
  }
  else {
    iVar5 = (int)(fVar3 * 1.4013e-45);
  }
  fVar3 = (float)FUN_400f83dc(fVar7,DAT_400d00f4);
  if (NAN(fVar3 * 1.0)) {
    iVar6 = -0x80000000;
    if (0.0 <= fVar3) {
      iVar6 = 0x7fffffff;
    }
  }
  else {
    iVar6 = (int)(fVar3 * 1.4013e-45);
  }
  cStack_22 = (char)iVar6 +
              ((char)(iVar6 + (int)((ulonglong)((longlong)iVar6 * (longlong)iVar2) >> 0x20) >> 7) -
              (char)(iVar6 >> 0x1f));
  if (NAN(fVar7 * 1.0)) {
    iVar6 = -0x80000000;
    if (0.0 <= fVar7) {
      iVar6 = 0x7fffffff;
    }
  }
  else {
    iVar6 = (int)(fVar7 * 1.4013e-45);
  }
  cStack_21 = (char)iVar6 +
              ((char)(iVar6 + (int)((ulonglong)((longlong)iVar6 * (longlong)iVar2) >> 0x20) >> 7) -
              (char)(iVar6 >> 0x1f));
  cStack_24 = (char)iVar4 +
              ((char)(iVar4 + (int)((ulonglong)(iVar4 * lVar1) >> 0x20) >> 7) -
              (char)(iVar4 >> 0x1f));
  cStack_23 = (char)iVar5 +
              ((char)(iVar5 + (int)((ulonglong)((longlong)iVar5 * (longlong)iVar2) >> 0x20) >> 7) -
              (char)(iVar5 >> 0x1f));
  FUN_400d1d1c(4,7,&cStack_24);
  return;
}



// Function at 0x400d27a8

void FUN_400d27a8(void)

{
  longlong lVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  char cStack_24;
  char cStack_23;
  char cStack_22;
  char cStack_21;
  
  memw();
  fVar7 = (*DAT_400d0024 + DAT_400d00f4) * DAT_400d00e8;
  fVar3 = (float)FUN_400f83dc(fVar7,DAT_400d00ec);
  iVar2 = DAT_400d009c;
  if (NAN(fVar3 * 1.0)) {
    iVar4 = -0x80000000;
    if (0.0 <= fVar3) {
      iVar4 = 0x7fffffff;
    }
  }
  else {
    iVar4 = (int)(fVar3 * 1.4013e-45);
  }
  lVar1 = (longlong)DAT_400d009c;
  fVar3 = (float)FUN_400f83dc(fVar7,DAT_400d00f0);
  if (NAN(fVar3 * 1.0)) {
    iVar5 = -0x80000000;
    if (0.0 <= fVar3) {
      iVar5 = 0x7fffffff;
    }
  }
  else {
    iVar5 = (int)(fVar3 * 1.4013e-45);
  }
  fVar3 = (float)FUN_400f83dc(fVar7,DAT_400d00f4);
  if (NAN(fVar3 * 1.0)) {
    iVar6 = -0x80000000;
    if (0.0 <= fVar3) {
      iVar6 = 0x7fffffff;
    }
  }
  else {
    iVar6 = (int)(fVar3 * 1.4013e-45);
  }
  cStack_22 = (char)iVar6 +
              ((char)(iVar6 + (int)((ulonglong)((longlong)iVar6 * (longlong)iVar2) >> 0x20) >> 7) -
              (char)(iVar6 >> 0x1f));
  if (NAN(fVar7 * 1.0)) {
    iVar6 = -0x80000000;
    if (0.0 <= fVar7) {
      iVar6 = 0x7fffffff;
    }
  }
  else {
    iVar6 = (int)(fVar7 * 1.4013e-45);
  }
  cStack_21 = (char)iVar6 +
              ((char)(iVar6 + (int)((ulonglong)((longlong)iVar6 * (longlong)iVar2) >> 0x20) >> 7) -
              (char)(iVar6 >> 0x1f));
  cStack_24 = (char)iVar4 +
              ((char)(iVar4 + (int)((ulonglong)(iVar4 * lVar1) >> 0x20) >> 7) -
              (char)(iVar4 >> 0x1f));
  cStack_23 = (char)iVar5 +
              ((char)(iVar5 + (int)((ulonglong)((longlong)iVar5 * (longlong)iVar2) >> 0x20) >> 7) -
              (char)(iVar5 >> 0x1f));
  FUN_400d1d1c(4,4,&cStack_24);
  return;
}



// Function at 0x400d287c

void FUN_400d287c(void)

{
  longlong lVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  char cStack_24;
  char cStack_23;
  char cStack_22;
  char cStack_21;
  
  memw();
  fVar7 = (*(float *)(DAT_400d0024 + 4) + DAT_400d00f4) * DAT_400d00e8;
  fVar3 = (float)FUN_400f83dc(fVar7,DAT_400d00ec);
  iVar2 = DAT_400d009c;
  if (NAN(fVar3 * 1.0)) {
    iVar4 = -0x80000000;
    if (0.0 <= fVar3) {
      iVar4 = 0x7fffffff;
    }
  }
  else {
    iVar4 = (int)(fVar3 * 1.4013e-45);
  }
  lVar1 = (longlong)DAT_400d009c;
  fVar3 = (float)FUN_400f83dc(fVar7,DAT_400d00f0);
  if (NAN(fVar3 * 1.0)) {
    iVar5 = -0x80000000;
    if (0.0 <= fVar3) {
      iVar5 = 0x7fffffff;
    }
  }
  else {
    iVar5 = (int)(fVar3 * 1.4013e-45);
  }
  fVar3 = (float)FUN_400f83dc(fVar7,DAT_400d00f4);
  if (NAN(fVar3 * 1.0)) {
    iVar6 = -0x80000000;
    if (0.0 <= fVar3) {
      iVar6 = 0x7fffffff;
    }
  }
  else {
    iVar6 = (int)(fVar3 * 1.4013e-45);
  }
  cStack_22 = (char)iVar6 +
              ((char)(iVar6 + (int)((ulonglong)((longlong)iVar6 * (longlong)iVar2) >> 0x20) >> 7) -
              (char)(iVar6 >> 0x1f));
  if (NAN(fVar7 * 1.0)) {
    iVar6 = -0x80000000;
    if (0.0 <= fVar7) {
      iVar6 = 0x7fffffff;
    }
  }
  else {
    iVar6 = (int)(fVar7 * 1.4013e-45);
  }
  cStack_21 = (char)iVar6 +
              ((char)(iVar6 + (int)((ulonglong)((longlong)iVar6 * (longlong)iVar2) >> 0x20) >> 7) -
              (char)(iVar6 >> 0x1f));
  cStack_24 = (char)iVar4 +
              ((char)(iVar4 + (int)((ulonglong)(iVar4 * lVar1) >> 0x20) >> 7) -
              (char)(iVar4 >> 0x1f));
  cStack_23 = (char)iVar5 +
              ((char)(iVar5 + (int)((ulonglong)((longlong)iVar5 * (longlong)iVar2) >> 0x20) >> 7) -
              (char)(iVar5 >> 0x1f));
  FUN_400d1d1c(4,5,&cStack_24);
  return;
}



// Function at 0x400d2950

void FUN_400d2950(void)

{
  longlong lVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  char cStack_24;
  char cStack_23;
  char cStack_22;
  char cStack_21;
  
  memw();
  fVar7 = (*(float *)(DAT_400d0024 + 8) + DAT_400d00f4) * DAT_400d00e8;
  fVar3 = (float)FUN_400f83dc(fVar7,DAT_400d00ec);
  iVar2 = DAT_400d009c;
  if (NAN(fVar3 * 1.0)) {
    iVar4 = -0x80000000;
    if (0.0 <= fVar3) {
      iVar4 = 0x7fffffff;
    }
  }
  else {
    iVar4 = (int)(fVar3 * 1.4013e-45);
  }
  lVar1 = (longlong)DAT_400d009c;
  fVar3 = (float)FUN_400f83dc(fVar7,DAT_400d00f0);
  if (NAN(fVar3 * 1.0)) {
    iVar5 = -0x80000000;
    if (0.0 <= fVar3) {
      iVar5 = 0x7fffffff;
    }
  }
  else {
    iVar5 = (int)(fVar3 * 1.4013e-45);
  }
  fVar3 = (float)FUN_400f83dc(fVar7,DAT_400d00f4);
  if (NAN(fVar3 * 1.0)) {
    iVar6 = -0x80000000;
    if (0.0 <= fVar3) {
      iVar6 = 0x7fffffff;
    }
  }
  else {
    iVar6 = (int)(fVar3 * 1.4013e-45);
  }
  cStack_22 = (char)iVar6 +
              ((char)(iVar6 + (int)((ulonglong)((longlong)iVar6 * (longlong)iVar2) >> 0x20) >> 7) -
              (char)(iVar6 >> 0x1f));
  if (NAN(fVar7 * 1.0)) {
    iVar6 = -0x80000000;
    if (0.0 <= fVar7) {
      iVar6 = 0x7fffffff;
    }
  }
  else {
    iVar6 = (int)(fVar7 * 1.4013e-45);
  }
  cStack_21 = (char)iVar6 +
              ((char)(iVar6 + (int)((ulonglong)((longlong)iVar6 * (longlong)iVar2) >> 0x20) >> 7) -
              (char)(iVar6 >> 0x1f));
  cStack_24 = (char)iVar4 +
              ((char)(iVar4 + (int)((ulonglong)(iVar4 * lVar1) >> 0x20) >> 7) -
              (char)(iVar4 >> 0x1f));
  cStack_23 = (char)iVar5 +
              ((char)(iVar5 + (int)((ulonglong)((longlong)iVar5 * (longlong)iVar2) >> 0x20) >> 7) -
              (char)(iVar5 >> 0x1f));
  FUN_400d1d1c(4,6,&cStack_24);
  return;
}



// Function at 0x400d2a24

void FUN_400d2a24(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 uStack_2e;
  undefined1 uStack_2d;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_25;
  int iStack_24;
  
  iVar1 = DAT_400d0024;
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  memw();
  uStack_2e = *(float *)(DAT_400d0024 + 0x44) != DAT_400d0028;
  memw();
  uStack_2d = *(float *)(DAT_400d0024 + 0x48) != DAT_400d0028;
  memw();
  uStack_2c = *(float *)(DAT_400d0024 + 0x4c) != DAT_400d0028;
  memw();
  uStack_2b = *(float *)(DAT_400d0024 + 0x50) != DAT_400d0028;
  memw();
  uStack_2a = *(float *)(DAT_400d0024 + 0x54) != DAT_400d0028;
  memw();
  uStack_29 = *(float *)(DAT_400d0024 + 0x58) != DAT_400d0028;
  memw();
  uStack_28 = *(float *)(DAT_400d0024 + 0x5c) != DAT_400d0028;
  memw();
  uVar2 = (*DAT_400d008c)(*(undefined4 *)(DAT_400d0024 + 0x10));
  uVar2 = (*DAT_400d006c)((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),DAT_400d0028,DAT_400d00b4);
  (*DAT_400d0064)((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),DAT_400d0028,DAT_400d00b8);
  FUN_400e9c44();
  uStack_27 = (*DAT_400d00bc)();
  memw();
  uVar2 = (*DAT_400d008c)(*(undefined4 *)(iVar1 + 0x18));
  uVar2 = (*DAT_400d006c)((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),DAT_400d0028,DAT_400d00b4);
  (*DAT_400d0064)((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),DAT_400d0028,DAT_400d00b8);
  FUN_400e9c44();
  uStack_26 = (*DAT_400d00bc)();
  memw();
  uVar2 = (*DAT_400d008c)(*(undefined4 *)(iVar1 + 0x20));
  uVar2 = (*DAT_400d006c)((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),DAT_400d0028,DAT_400d00b4);
  (*DAT_400d0064)((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),DAT_400d0028,DAT_400d00b8);
  FUN_400e9c44();
  uStack_25 = (*DAT_400d00bc)();
  FUN_400d1d1c(10,8,&uStack_2e);
  memw();
  memw();
  if (iStack_24 == *DAT_400d0098) {
    return;
  }
  func_0x400831d4();
  return;
}



// Function at 0x400d2bd4

void FUN_400d2bd4(void)

{
  FUN_400df928();
  func_0x4008a9fc(DAT_400d00f8);
  FUN_400d1cfc();
  return;
}



// Function at 0x400d2be8

void FUN_400d2be8(int *param_1,int param_2)

{
  param_1[2] = 0;
  if (param_2 != 0) {
    *param_1 = param_2;
    param_1[3] = (int)PTR_LAB_400d00fc;
    param_1[2] = (int)PTR_FUN_400d0100;
  }
  return;
}



// Function at 0x400d2c00

void FUN_400d2c00(void)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  int iVar4;
  undefined1 auStack_34 [8];
  code *pcStack_2c;
  int iStack_24;
  
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  FUN_400df76c(10,1);
  FUN_400df860(0);
  iVar4 = DAT_400d0024;
  memw();
  *(undefined4 *)(DAT_400d0024 + 0xc) = DAT_400d0104;
  fVar1 = DAT_400d0028;
  memw();
  *(float *)(iVar4 + 0x10) = DAT_400d0028;
  uVar2 = DAT_400d0108;
  memw();
  *(undefined4 *)(iVar4 + 0x14) = DAT_400d0108;
  memw();
  *(undefined4 *)(iVar4 + 0x18) = DAT_400d002c;
  memw();
  memw();
  *(undefined4 *)(iVar4 + 0x34) = *(undefined4 *)(iVar4 + 0x18);
  memw();
  memw();
  *(undefined4 *)(iVar4 + 0x38) = *(undefined4 *)(iVar4 + 0x30);
  memw();
  *(undefined4 *)(iVar4 + 0x1c) = uVar2;
  memw();
  *(float *)(iVar4 + 0x20) = fVar1;
  memw();
  *(float *)(iVar4 + 0x44) = fVar1;
  memw();
  *(float *)(iVar4 + 0x48) = fVar1;
  memw();
  *(float *)(iVar4 + 0x4c) = fVar1;
  memw();
  *(float *)(iVar4 + 0x50) = fVar1;
  memw();
  *(float *)(iVar4 + 0x54) = fVar1;
  fVar3 = DAT_400d0080;
  memw();
  *(float *)(iVar4 + 0x58) = DAT_400d0080;
  memw();
  *(float *)(iVar4 + 0x5c) = fVar3;
  memw();
  *(undefined4 *)(iVar4 + 0x60) = uVar2;
  memw();
  *(undefined4 *)(iVar4 + 100) = DAT_400d010c;
  memw();
  *(undefined4 *)(iVar4 + 0x68) = DAT_400d0110;
  FUN_400d5714(0xf,1);
  memw();
  *(float *)(iVar4 + 0x7c) = fVar1;
  memw();
  *(float *)(iVar4 + 0x40) = fVar3;
  FUN_400d4df8(DAT_400d00a0,DAT_400d0118,DAT_400d0114,0xffffffff,0xffffffff,0,DAT_400d011c,0x70);
  FUN_400d17fc();
  iVar4 = FUN_400d3d60(DAT_400d003c,DAT_400d0120);
  uVar2 = DAT_400d003c;
  if (iVar4 != 0) {
    FUN_400f78fc(DAT_400d003c,0);
    FUN_400f7904(uVar2,6);
  }
  FUN_400d1bac();
  memw();
  *(float *)(DAT_400d0024 + 0x78) = DAT_400d0080;
  iVar4 = FUN_400d489c(DAT_400d0040,DAT_400d0120);
  if (iVar4 == 0) {
    FUN_400d51b0(DAT_400d00a0,DAT_400d0124);
    iVar4 = 0;
    do {
      func_0x4008a9fc(10);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x1f5);
    memw();
    *(float *)(DAT_400d0024 + 0x78) = DAT_400d0028;
    FUN_400d51b0(DAT_400d00a0,DAT_400d0128);
  }
  memw();
  if ((*(float *)(DAT_400d0024 + 0x78) != DAT_400d0028) &&
     (memw(), *(float *)(DAT_400d0024 + 0x7c) != DAT_400d0028)) {
    memw();
    if (*(float *)(DAT_400d0024 + 0x7c) == DAT_400d0080) {
      FUN_400d48ec(DAT_400d0040);
    }
    else {
      memw();
      if (*(float *)(DAT_400d0024 + 0x7c) == DAT_400d0088) {
        FUN_400d4938(DAT_400d0040);
      }
    }
  }
  FUN_400d329c(DAT_400d0038);
  FUN_400d2be8(auStack_34,PTR_DAT_400d012c);
  FUN_400d5098(DAT_400d00a0,auStack_34,0);
  if (pcStack_2c != (code *)0x0) {
    (*pcStack_2c)(auStack_34,auStack_34,3);
  }
  memw();
  memw();
  if (iStack_24 == *DAT_400d0098) {
    return;
  }
  func_0x400831d4();
  return;
}



// Function at 0x400d2e48

void FUN_400d2e48(void)

{
  FUN_400d1724(0,DAT_400d0020);
  return;
}



// Function at 0x400d30a0

void FUN_400d30a0(int param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    FUN_400d5714(*(undefined1 *)(param_1 + 2),0);
  }
  return;
}



// Function at 0x400d30b8

void FUN_400d30b8(int param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    FUN_400d5714(*(undefined1 *)(param_1 + 2),1);
  }
  return;
}



// Function at 0x400d30d0

bool FUN_400d30d0(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = FUN_400d3858(param_2,7);
  return *(byte *)(param_2 + 7) == uVar1;
}



// Function at 0x400d30f0

int FUN_400d30f0(int param_1,undefined4 param_2,byte param_3)

{
  int iVar1;
  byte bVar2;
  
  if (param_3 < *(byte *)(param_1 + 7)) {
    FUN_400f7734(*(undefined4 *)(param_1 + 0xc));
    for (bVar2 = 0; bVar2 <= param_3; bVar2 = bVar2 + 1) {
      iVar1 = FUN_400d3718(*(undefined4 *)(param_1 + 0xc),param_2,1);
      if (iVar1 == 0) {
        return 0;
      }
      if ((bVar2 == param_3) && (iVar1 = FUN_400d30d0(param_1,param_2), iVar1 != 0)) {
        return iVar1;
      }
    }
  }
  return 0;
}



// Function at 0x400d3138

bool FUN_400d3138(int param_1,int param_2)

{
  int iVar1;
  
  func_0x40081178(*(undefined4 *)(param_1 + 0xc));
  if (param_2 == 0) {
    FUN_400d36e8(*(undefined4 *)(param_1 + 0xc));
  }
  else {
    FUN_400d36bc(*(undefined4 *)(param_1 + 0xc),param_2);
  }
  FUN_400d35c4(*(undefined4 *)(param_1 + 0xc),0xb4,0);
  iVar1 = func_0x40081524(*(undefined4 *)(param_1 + 0xc));
  func_0x40081178(*(undefined4 *)(param_1 + 0xc));
  return iVar1 == 0;
}



// Function at 0x400d3178

bool FUN_400d3178(int param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = func_0x40081178(*(undefined4 *)(param_1 + 0xc));
  if (iVar3 == 0) {
    bVar1 = false;
  }
  else {
    FUN_400d36bc(*(undefined4 *)(param_1 + 0xc),param_2);
    FUN_400d35c4(*(undefined4 *)(param_1 + 0xc),0xbe,0);
    for (uVar4 = 0; uVar4 < 9; uVar4 = uVar4 + 1 & 0xff) {
      uVar2 = FUN_400d3694(*(undefined4 *)(param_1 + 0xc));
      *(undefined1 *)(param_3 + uVar4) = uVar2;
    }
    iVar3 = func_0x40081178(*(undefined4 *)(param_1 + 0xc));
    bVar1 = iVar3 == 1;
  }
  return bVar1;
}



// Function at 0x400d31cc

int FUN_400d31cc(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = FUN_400d3178(param_1,param_2,param_3);
  if (iVar1 != 0) {
    iVar2 = FUN_400f76e0(param_1,param_3,9);
    if (iVar2 == 0) {
      uVar3 = FUN_400d3858(param_3,8);
      if (*(byte *)(param_3 + 8) != uVar3) {
        iVar1 = 0;
      }
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}



// Function at 0x400d3208

undefined4 FUN_400d3208(undefined4 param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_2d [4];
  byte bStack_29;
  int iStack_24;
  
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  if (*param_2 == '\x10') {
    uVar2 = 0xc;
  }
  else {
    iVar1 = FUN_400d31cc(param_1,param_2,auStack_2d);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else if ((*param_2 == ';') && ((char)bStack_29 < '\0')) {
      uVar2 = 0xc;
    }
    else if (bStack_29 == 0x3f) {
      uVar2 = 10;
    }
    else if (bStack_29 < 0x40) {
      if (bStack_29 == 0x1f) {
        uVar2 = 9;
      }
      else {
        uVar2 = 0;
      }
    }
    else if (bStack_29 == 0x5f) {
      uVar2 = 0xb;
    }
    else if (bStack_29 == 0x7f) {
      uVar2 = 0xc;
    }
    else {
      uVar2 = 0;
    }
  }
  memw();
  memw();
  if (iStack_24 == *DAT_400d0098) {
    return uVar2;
  }
  uVar2 = func_0x400831d4();
  return uVar2;
}



// Function at 0x400d329c

void FUN_400d329c(char *param_1)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  undefined1 auStack_2c [8];
  int iStack_24;
  
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  for (bVar3 = 0; bVar3 < 3; bVar3 = bVar3 + 1) {
    FUN_400f7734(*(undefined4 *)(param_1 + 0xc));
    param_1[7] = '\0';
    param_1[8] = '\0';
    FUN_400d5ee4(0x32);
    while (iVar1 = FUN_400d3718(*(undefined4 *)(param_1 + 0xc),auStack_2c,1), iVar1 != 0) {
      iVar1 = FUN_400d30d0(param_1,auStack_2c);
      if (iVar1 != 0) {
        param_1[7] = param_1[7] + '\x01';
        iVar1 = FUN_400f769c(param_1,auStack_2c);
        if (iVar1 != 0) {
          param_1[8] = param_1[8] + '\x01';
          if ((*param_1 == '\0') && (iVar1 = FUN_400d3138(param_1,auStack_2c), iVar1 != 0)) {
            *param_1 = '\x01';
          }
          uVar2 = FUN_400d3208(param_1,auStack_2c);
          if ((byte)param_1[3] < uVar2) {
            param_1[3] = (char)uVar2;
          }
        }
      }
    }
    if (param_1[7] != '\0') break;
  }
  memw();
  memw();
  if (iStack_24 == *DAT_400d0098) {
    return;
  }
  func_0x400831d4();
  return;
}



// Function at 0x400d3350

float FUN_400d3350(int param_1)

{
  float fVar1;
  
  fVar1 = DAT_400d0150;
  if (DAT_400d0154 <= param_1) {
    fVar1 = ((float)param_1 / 1.0) * DAT_400d0158;
  }
  return fVar1;
}



// Function at 0x400d3374

bool FUN_400d3374(int param_1)

{
  int iVar1;
  
  iVar1 = func_0x40081524(*(undefined4 *)(param_1 + 0xc));
  return iVar1 == 1;
}



// Function at 0x400d3388

void FUN_400d3388(char *param_1,undefined1 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1[5] == '\0') || (*param_1 != '\0')) {
    uVar2 = FUN_400f7700(param_2);
    FUN_400d30a0(param_1);
    FUN_400d5ee4(uVar2);
    FUN_400d30b8(param_1);
  }
  else {
    while (iVar1 = FUN_400d3374(param_1), iVar1 == 0) {
      iVar1 = FUN_400d5ecc();
      if (0x2ed < (uint)(iVar1 - param_3)) {
        return;
      }
      FUN_400d5e9c();
    }
  }
  return;
}



// Function at 0x400d33cc

undefined8 FUN_400d33cc(undefined1 *param_1)

{
  undefined4 uVar1;
  
  func_0x40081178(*(undefined4 *)(param_1 + 0xc));
  FUN_400d36e8(*(undefined4 *)(param_1 + 0xc));
  FUN_400d35c4(*(undefined4 *)(param_1 + 0xc),0x44,*param_1);
  uVar1 = FUN_400d5ecc();
  if (param_1[4] != '\0') {
    FUN_400d3388(param_1,param_1[3],uVar1);
  }
  return CONCAT44(uVar1,1);
}



// Function at 0x400d3418

uint FUN_400d3418(undefined4 param_1,char *param_2,byte *param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  bVar1 = param_3[1];
  uVar4 = DAT_400d015c;
  if (-1 < (char)bVar1) {
    uVar4 = 0;
  }
  if ((*param_2 == ';') && ((char)param_3[4] < '\0')) {
    if ((*param_3 & 1) != 0) {
      bVar1 = param_3[2];
      if ((bVar1 & 1) != 0) {
        return DAT_400d0160;
      }
      if ((bVar1 & 2) != 0) {
        return DAT_400d0164;
      }
      if ((bVar1 & 4) == 0) {
        return DAT_400d0168;
      }
      return DAT_400d016c;
    }
    uVar2 = (uint)bVar1 << 0xb | (*param_3 & 0xfc) << 3;
  }
  else {
    uVar2 = (uint)bVar1 << 0xb | (uint)*param_3 << 3;
  }
  uVar2 = uVar2 | uVar4;
  if ((*param_2 == '\x10') && (uVar3 = (uint)param_3[7], uVar3 != 0)) {
    uVar2 = ((uVar2 << 3 & DAT_400d0170) - 0x20) + (int)((uVar3 - param_3[6]) * 0x80) / (int)uVar3 |
            uVar4;
  }
  return uVar2;
}



// Function at 0x400d34c4

undefined4 FUN_400d34c4(undefined4 param_1,undefined4 param_2,byte param_3)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  undefined1 auStack_2d [9];
  int iStack_24;
  
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  bVar3 = 0;
  do {
    uVar2 = DAT_400d0168;
    if (param_3 < bVar3) goto LAB_400d3502;
    iVar1 = FUN_400d31cc(param_1,param_2,auStack_2d);
    bVar3 = bVar3 + 1;
  } while (iVar1 == 0);
  uVar2 = FUN_400d3418(param_1,param_2,auStack_2d);
LAB_400d3502:
  memw();
  memw();
  if (iStack_24 != *DAT_400d0098) {
    uVar2 = func_0x400831d4();
    return uVar2;
  }
  return uVar2;
}



// Function at 0x400d3518

undefined4 FUN_400d3518(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  
  FUN_400d34c4(param_1,param_2,param_3);
  uVar1 = FUN_400d3350();
  return uVar1;
}



// Function at 0x400d3530

undefined4 FUN_400d3530(undefined4 param_1,undefined1 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_2c [8];
  int iStack_24;
  
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  iVar1 = FUN_400d30f0(param_1,auStack_2c,param_2);
  uVar2 = DAT_400d0150;
  if (iVar1 != 0) {
    uVar2 = FUN_400d3518(param_1,auStack_2c,0);
  }
  memw();
  memw();
  if (iStack_24 != *DAT_400d0098) {
    uVar2 = func_0x400831d4();
    return uVar2;
  }
  return uVar2;
}



// Function at 0x400d3578

void FUN_400d3578(undefined1 *param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  *param_1 = 0;
  param_1[3] = 9;
  param_1[4] = 1;
  param_1[5] = 1;
  param_1[6] = 1;
  param_1[1] = 0;
  FUN_400f772c(param_1,0);
  param_1[0x18] = 0xff;
  param_1[0x19] = 0;
  return;
}



// Function at 0x400d35b0

void FUN_400d35b0(undefined4 param_1,undefined4 param_2)

{
  FUN_400d3578(param_1);
  FUN_400f7678(param_1,param_2);
  return;
}



// Function at 0x400d35c4

void FUN_400d35c4(uint *param_1,byte param_2,char param_3)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  for (bVar3 = 1; bVar3 != 0; bVar3 = bVar3 << 1) {
    func_0x4008134c(param_1,(bVar3 & param_2) != 0);
  }
  if (param_3 == '\0') {
    uStack_28 = DAT_400d0174;
    uStack_24 = 0;
    func_0x4008b620(&uStack_28,0xffffffff);
    uVar2 = *param_1;
    uVar1 = 0x1fe << 0x20 - (0x20 - ((uVar2 ^ 0xffffffff) & 0x1f)) | DAT_400d0178 >> (uVar2 & 0x1f);
    if ((uVar2 & 0x20) != 0) {
      uVar1 = 0xff >> (uVar2 & 0x1f);
    }
    if ((uVar1 & 1) != 0) {
      if (uVar2 < 0x20) {
        memw();
        *(int *)(DAT_400d017c + 0x28) = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
      }
      else {
        memw();
        *(int *)(DAT_400d017c + 0x34) = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
      }
    }
    uVar1 = *param_1;
    if (uVar1 < 0x20) {
      memw();
      *(int *)(DAT_400d017c + 0xc) = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
    }
    else if (uVar1 < 0x2e) {
      memw();
      *(int *)(DAT_400d017c + 0x18) = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
    }
    func_0x4008b770(&uStack_28);
  }
  return;
}



// Function at 0x400d3694

uint FUN_400d3694(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = 0;
  for (uVar3 = 1; uVar3 != 0; uVar3 = (uVar3 & 0x7f) << 1) {
    iVar2 = func_0x40081524(param_1);
    if (iVar2 != 0) {
      uVar1 = uVar3 | uVar1;
    }
  }
  return uVar1;
}



// Function at 0x400d36bc

void FUN_400d36bc(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  FUN_400d35c4(param_1,0x55,0);
  for (uVar1 = 0; uVar1 < 8; uVar1 = uVar1 + 1 & 0xff) {
    FUN_400d35c4(param_1,*(undefined1 *)(param_2 + uVar1),0);
  }
  return;
}



// Function at 0x400d36e8

void FUN_400d36e8(undefined4 param_1)

{
  FUN_400d35c4(param_1,0xcc,0);
  return;
}



// Function at 0x400d36fc

void FUN_400d36fc(uint *param_1,uint param_2)

{
  FUN_400d5678(param_2 & 0xff,1);
  *param_1 = param_2 & 0xff;
  param_1[1] = 0;
  FUN_400f7734(param_1);
  return;
}



// Function at 0x400d3718

undefined1 FUN_400d3718(int param_1,int param_2,char param_3)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  uint uVar8;
  
  if (*(char *)(param_1 + 0x12) == '\0') {
    iVar3 = func_0x40081178(param_1);
    if (iVar3 == 0) {
      *(undefined1 *)(param_1 + 0x10) = 0;
      *(undefined1 *)(param_1 + 0x12) = 0;
      *(undefined1 *)(param_1 + 0x11) = 0;
      return 0;
    }
    if (param_3 == '\0') {
      FUN_400d35c4(param_1,0xec,0);
    }
    else {
      FUN_400d35c4(param_1,0xf0,0);
    }
    uVar6 = 1;
    uVar8 = 0;
    bVar2 = 0;
    bVar7 = 1;
    do {
      uVar4 = func_0x40081524(param_1);
      uVar5 = func_0x40081524(param_1);
      if (uVar4 == 1 && uVar5 == 1) break;
      if (uVar4 == uVar5) {
        if (bVar7 < *(byte *)(param_1 + 0x10)) {
          bVar1 = (*(byte *)(param_1 + uVar8 + 8) & uVar6) == 0;
        }
        else {
          bVar1 = *(byte *)(param_1 + 0x10) != bVar7;
        }
        uVar4 = (uint)!bVar1;
        if ((uVar4 == 0) && (bVar2 = bVar7, bVar7 < 9)) {
          *(byte *)(param_1 + 0x11) = bVar7;
        }
      }
      if (uVar4 == 1) {
        *(byte *)(param_1 + uVar8 + 8) = (byte)uVar6 | *(byte *)(param_1 + uVar8 + 8);
      }
      else {
        *(byte *)(param_1 + uVar8 + 8) = ((byte)uVar6 ^ 0xff) & *(byte *)(param_1 + uVar8 + 8);
      }
      func_0x4008134c(param_1,uVar4);
      bVar7 = bVar7 + 1;
      uVar4 = uVar6 & 0x7f;
      uVar6 = uVar4 << 1;
      if (uVar4 == 0) {
        uVar8 = uVar8 + 1 & 0xff;
        uVar6 = 1;
      }
    } while (uVar8 < 8);
    if (0x40 < bVar7) {
      *(byte *)(param_1 + 0x10) = bVar2;
      if (bVar2 == 0) {
        *(undefined1 *)(param_1 + 0x12) = 1;
      }
      if (*(char *)(param_1 + 8) != '\0') {
        for (iVar3 = 0; iVar3 < 8; iVar3 = iVar3 + 1) {
          *(undefined1 *)(param_2 + iVar3) = *(undefined1 *)(param_1 + iVar3 + 8);
        }
        return 1;
      }
    }
  }
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined1 *)(param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 0x11) = 0;
  return 0;
}



// Function at 0x400d3858

void FUN_400d3858(undefined4 param_1,char param_2)

{
  bool bVar1;
  
  do {
    bVar1 = param_2 != '\0';
    param_2 = param_2 + -1;
  } while (bVar1);
  return;
}



// Function at 0x400d3894

void FUN_400d3894(undefined4 *param_1,byte param_2)

{
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[2] = 1000;
  *param_1 = DAT_400d0184;
  *(byte *)(param_1 + 4) = param_2 & 1;
  *(undefined1 *)((int)param_1 + 0x11) = 0xff;
  *(undefined1 *)((int)param_1 + 0x12) = 0xff;
  param_1[5] = 0x80;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  *(undefined2 *)(param_1 + 0xb) = 0;
  param_1[0xc] = 0x32;
  *(undefined1 *)(param_1 + 0xd) = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  return;
}



// Function at 0x400d38e0

void FUN_400d38e0(int param_1)

{
  if (*(int *)(param_1 + 0x18) != 0) {
    func_0x4008dbfc();
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    func_0x4008dbfc();
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}



// Function at 0x400d3904

undefined4 FUN_400d3904(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    iVar2 = func_0x4008dbdc(*(undefined4 *)(param_1 + 0x14));
    *(int *)(param_1 + 0x18) = iVar2;
    if (iVar2 == 0) {
      return 0;
    }
  }
  if (*(int *)(param_1 + 0x24) == 0) {
    iVar2 = func_0x4008dbdc(*(undefined4 *)(param_1 + 0x14));
    *(int *)(param_1 + 0x24) = iVar2;
    if (iVar2 == 0) {
      FUN_400d38e0(param_1);
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



// Function at 0x400d3944

uint FUN_400d3944(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x3c) == 0) {
    iVar1 = func_0x400893a4(1);
    *(int *)(param_1 + 0x3c) = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
  }
  iVar1 = func_0x400896ec(*(undefined4 *)(param_1 + 0x3c),0xffffffff);
  if (iVar1 != 1) {
    return 0;
  }
  if (*(char *)(param_1 + 0x40) == '\0') {
    uVar2 = FUN_400d58f0(*(undefined1 *)(param_1 + 0x10));
    if (uVar2 != 0) goto LAB_400d396a;
    uVar2 = FUN_400d3904(param_1);
    if ((uVar2 != 0) && (uVar2 = FUN_400f7820(param_1,param_2,param_3), uVar2 != 0)) {
      iVar1 = FUN_400d5918(*(undefined1 *)(param_1 + 0x10),(int)*(char *)(param_1 + 0x11),
                           (int)*(char *)(param_1 + 0x12),param_4);
      uVar2 = (uint)(iVar1 == 0);
      if (iVar1 == 0) goto LAB_400d396a;
    }
  }
  else {
    uVar2 = 0;
  }
  FUN_400d38e0(param_1);
LAB_400d396a:
  func_0x40089194(*(undefined4 *)(param_1 + 0x3c),0,0);
  return uVar2;
}



// Function at 0x400d39dc

bool FUN_400d39dc(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x3c) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = func_0x400896ec(*(int *)(param_1 + 0x3c),0xffffffff);
    if (iVar1 != 1) {
      return false;
    }
    if (*(char *)(param_1 + 0x40) == '\0') {
      iVar1 = FUN_400d58f0(*(undefined1 *)(param_1 + 0x10));
      if (iVar1 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_400d5a50(*(undefined1 *)(param_1 + 0x10));
      }
    }
    else {
      iVar1 = FUN_400d5898(*(undefined1 *)(param_1 + 0x10));
      if (iVar1 == 0) {
        *(undefined1 *)(param_1 + 0x40) = 0;
      }
    }
    FUN_400d38e0(param_1);
    func_0x40089194(*(undefined4 *)(param_1 + 0x3c),0,0);
  }
  return iVar1 == 0;
}



// Function at 0x400d3a4c

void FUN_400d3a4c(undefined4 *param_1)

{
  *param_1 = DAT_400d0184;
  FUN_400d39dc(param_1);
  if (param_1[0xf] != 0) {
    func_0x400899b0();
  }
  return;
}



// Function at 0x400d3a64

void FUN_400d3a64(undefined4 param_1)

{
  FUN_400d3a4c(param_1);
  FUN_400e8230(param_1);
  return;
}



// Function at 0x400d3a78

void FUN_400d3a78(int param_1,int param_2)

{
  if ((param_1 == 1) && (param_2 == DAT_400d0020)) {
    FUN_400d3894(DAT_400d0120,0);
    FUN_400d3894(DAT_400d0188,1);
  }
  if ((param_1 == 0) && (param_2 == DAT_400d0020)) {
    FUN_400d3a4c(DAT_400d0188);
    FUN_400d3a4c(DAT_400d0120);
  }
  return;
}



// Function at 0x400d3ab4

void FUN_400d3ab4(int param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x40) == '\0') {
    if ((*(char *)(param_1 + 0x34) != '\0') &&
       (iVar2 = *(int *)(param_1 + 0x38), iVar1 = func_0x4008a674(), iVar2 == iVar1)) {
      func_0x40089194(*(undefined4 *)(param_1 + 0x3c),0,0);
    }
    if ((*(int *)(param_1 + 0x3c) != 0) &&
       (iVar1 = func_0x400896ec(*(int *)(param_1 + 0x3c),0xffffffff), iVar1 == 1)) {
      *(undefined1 *)(param_1 + 0x34) = 0;
      *(undefined2 *)(param_1 + 0x2c) = param_2;
      *(undefined4 *)(param_1 + 0x28) = 0;
    }
  }
  return;
}



// Function at 0x400d3afc

undefined4 FUN_400d3afc(int param_1,char param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0x40) == '\0') {
    if (*(int *)(param_1 + 0x24) == 0) {
      uVar2 = 4;
    }
    else if (param_2 == '\0') {
      *(undefined1 *)(param_1 + 0x34) = 1;
      uVar2 = func_0x4008a674();
      *(undefined4 *)(param_1 + 0x38) = uVar2;
      uVar2 = 0;
    }
    else {
      iVar1 = FUN_400d5af4(*(undefined1 *)(param_1 + 0x10),*(undefined2 *)(param_1 + 0x2c),
                           *(int *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x28),
                           *(undefined4 *)(param_1 + 0x30));
      func_0x40089194(*(undefined4 *)(param_1 + 0x3c),0,0);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else if (iVar1 == 0x107) {
        uVar2 = 5;
      }
      else if (iVar1 == -1) {
        uVar2 = 2;
      }
      else {
        uVar2 = 4;
      }
    }
  }
  else {
    uVar2 = 4;
  }
  return uVar2;
}



// Function at 0x400d3b6c

undefined4 FUN_400d3b6c(int param_1,short param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 0x40) == '\0') {
    if (*(int *)(param_1 + 0x18) == 0) {
      uVar2 = 0;
    }
    else if (*(int *)(param_1 + 0x24) == 0) {
      uVar2 = 0;
    }
    else {
      if ((*(char *)(param_1 + 0x34) == '\0') ||
         (iVar3 = *(int *)(param_1 + 0x38), iVar1 = func_0x4008a674(), iVar3 != iVar1)) {
        if ((*(int *)(param_1 + 0x3c) == 0) ||
           (iVar1 = func_0x400896ec(*(int *)(param_1 + 0x3c),0xffffffff), iVar1 != 1)) {
          return 0;
        }
        *(undefined4 *)(param_1 + 0x1c) = 0;
        *(undefined4 *)(param_1 + 0x20) = 0;
        FUN_400d5c14(*(undefined1 *)(param_1 + 0x10),param_2,*(undefined4 *)(param_1 + 0x18),param_3
                     ,*(undefined4 *)(param_1 + 0x30),param_1 + 0x20);
      }
      else {
        if (*(short *)(param_1 + 0x2c) != param_2) {
          return 0;
        }
        *(undefined1 *)(param_1 + 0x34) = 0;
        *(undefined4 *)(param_1 + 0x1c) = 0;
        *(undefined4 *)(param_1 + 0x20) = 0;
        FUN_400d5cb0(*(undefined1 *)(param_1 + 0x10),param_2,*(undefined4 *)(param_1 + 0x24),
                     *(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x18),param_3,
                     *(undefined4 *)(param_1 + 0x30),param_1 + 0x20);
      }
      func_0x40089194(*(undefined4 *)(param_1 + 0x3c),0,0);
      uVar2 = *(undefined4 *)(param_1 + 0x20);
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



// Function at 0x400d3c14

undefined1 FUN_400d3c14(undefined4 param_1,undefined1 param_2,undefined1 param_3,char param_4)

{
  undefined1 uVar1;
  
  uVar1 = FUN_400d3b6c(param_1,param_2,param_3,param_4 != '\0');
  return uVar1;
}



// Function at 0x400d3c34

void FUN_400d3c34(undefined4 param_1,undefined1 param_2)

{
  FUN_400d3ab4(param_1,param_2);
  return;
}



// Function at 0x400d3c44

undefined4 FUN_400d3c44(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400d3afc(param_1,1);
  return uVar1;
}



// Function at 0x400d3c58

void FUN_400d3c58(void)

{
  FUN_400d3a78(1,DAT_400d0020);
  return;
}



// Function at 0x400d3c68

void FUN_400d3c68(void)

{
  FUN_400d3a78(0,DAT_400d0020);
  return;
}



// Function at 0x400d3c78

void FUN_400d3c78(undefined4 param_1)

{
  FUN_400e8230(param_1);
  return;
}



// Function at 0x400d3c84

void FUN_400d3c84(undefined4 param_1)

{
  FUN_400e8230(param_1);
  return;
}



// Function at 0x400d3c90

void FUN_400d3c90(int param_1,int param_2)

{
  func_0x40086818(param_2,0,0x28);
  func_0x40086d48(param_2,DAT_400d018c,0xb);
  *(undefined1 *)(param_2 + 0xb) = 0;
  *(undefined4 *)(param_2 + 0xc) = 1;
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_2 + 0x14) = 0xc;
  *(undefined4 *)(param_2 + 0x24) = 0;
  *(undefined4 *)(param_2 + 0x1c) = DAT_400d0028;
  *(undefined4 *)(param_2 + 0x18) = DAT_400d00e8;
  *(undefined4 *)(param_2 + 0x20) = DAT_400d0088;
  return;
}



// Function at 0x400d3cd0

void FUN_400d3cd0(int param_1,int param_2)

{
  func_0x40086818(param_2,0,0x28);
  func_0x40086d48(param_2,DAT_400d0190,0xb);
  *(undefined1 *)(param_2 + 0xb) = 0;
  *(undefined4 *)(param_2 + 0xc) = 1;
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_2 + 0x14) = 0xd;
  *(undefined4 *)(param_2 + 0x24) = 0;
  *(undefined4 *)(param_2 + 0x1c) = DAT_400d0194;
  *(undefined4 *)(param_2 + 0x18) = DAT_400d0198;
  *(undefined4 *)(param_2 + 0x20) = DAT_400d019c;
  return;
}



// Function at 0x400d3d10

void FUN_400d3d10(int param_1)

{
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_400e8230();
  }
  if (*(int **)(param_1 + 0x10) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x10) + 4))();
  }
  if (*(int **)(param_1 + 0x14) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x14) + 4))();
  }
  return;
}



// Function at 0x400d3d38

int FUN_400d3d38(int param_1)

{
  int iVar1;
  undefined1 auStack_21 [33];
  
  auStack_21[0] = 0x94;
  iVar1 = FUN_400d426c(*(undefined4 *)(param_1 + 0xc),auStack_21,1,1,0);
  if (iVar1 != 0) {
    FUN_400d5ee4(1);
  }
  return iVar1;
}



// Function at 0x400d3d60

int FUN_400d3d60(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_400e8230();
  }
  if (*(int **)(param_1 + 0x10) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x10) + 4))();
  }
  if (*(int **)(param_1 + 0x14) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x14) + 4))();
  }
  uVar1 = FUN_400e79d4(0x10);
  FUN_400f7978(uVar1,0x44,param_2);
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  iVar2 = FUN_400d4240(uVar1,1);
  if ((iVar2 != 0) && (iVar2 = FUN_400d3d38(param_1), iVar2 != 0)) {
    puVar3 = (undefined4 *)FUN_400e79d4(0xc);
    *puVar3 = DAT_400d01a0;
    puVar3[1] = 0x401;
    puVar3[2] = param_1;
    *(undefined4 **)(param_1 + 0x14) = puVar3;
    puVar3 = (undefined4 *)FUN_400e79d4(0xc);
    *puVar3 = DAT_400d01a4;
    puVar3[1] = 0x400;
    puVar3[2] = param_1;
    *(undefined4 **)(param_1 + 0x10) = puVar3;
  }
  return iVar2;
}



// Function at 0x400d3dfc

void FUN_400d3dfc(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  func_0x40086818(param_2 + 1,0,0x20);
  *param_2 = 0x24;
  param_2[1] = (uint)*(ushort *)((int)param_1 + 10);
  param_2[2] = 0xd;
  param_2[4] = param_3;
  param_2[5] = *param_1;
  return;
}



// Function at 0x400d3e20

void FUN_400d3e20(int param_1,undefined4 *param_2,undefined4 param_3)

{
  func_0x40086818(param_2 + 1,0,0x20);
  *param_2 = 0x24;
  param_2[1] = (uint)*(ushort *)(param_1 + 8);
  param_2[2] = 0xc;
  param_2[4] = param_3;
  param_2[5] = *(undefined4 *)(param_1 + 4);
  return;
}



// Function at 0x400d3e44

int FUN_400d3e44(float *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  float *pfVar5;
  float fVar6;
  undefined1 uStack_31;
  float local_30;
  float local_2c;
  byte bStack_26;
  byte bStack_25;
  byte bStack_24;
  byte bStack_23;
  byte bStack_22;
  byte bStack_21;
  
  uVar1 = FUN_400d5ecc();
  uStack_31 = 0xfd;
  fVar6 = param_1[7];
  if (fVar6 == 0.0) {
    if (param_1[6] == 1.4013e-45) {
      uStack_31 = 0xf6;
      uVar4 = 5;
    }
    else {
      uVar4 = 10;
    }
    if (param_1[6] == 2.8026e-45) {
      uStack_31 = 0xe0;
      uVar4 = 2;
    }
  }
  else {
    uVar4 = 10;
  }
  if (fVar6 == 1.4013e-45) {
    uStack_31 = 0x39;
    uVar4 = 0x44c;
  }
  if (fVar6 == 2.8026e-45) {
    uStack_31 = 0x32;
    uVar4 = 0x6e;
  }
  if (fVar6 == 4.2039e-45) {
    uStack_31 = 0x2f;
    uVar4 = 0x44c;
  }
  if (fVar6 == 5.60519e-45) {
    uStack_31 = 0x24;
    uVar4 = 0x6e;
  }
  if (fVar6 == 7.00649e-45) {
    uStack_31 = 0x1e;
    uVar4 = 0x44c;
  }
  if (fVar6 == 8.40779e-45) {
    uStack_31 = 0x15;
    uVar4 = 0x6e;
  }
  iVar2 = FUN_400d426c(param_1[3],&uStack_31,1,1,0);
  if (iVar2 != 0) {
    FUN_400d5ee4(uVar4);
    iVar2 = FUN_400d4320(param_1[3],&bStack_26,6,1);
    if (iVar2 != 0) {
      uVar3 = FUN_400f7898(&bStack_26,2);
      if (bStack_24 == uVar3) {
        uVar3 = FUN_400f7898(&bStack_23,2);
        if (bStack_21 == uVar3) {
          fVar6 = (float)FUN_400f83dc(((float)((uint)bStack_26 * 0x100 + (uint)bStack_25) / 1.0) *
                                      DAT_400d01a8,DAT_400d00f0);
          *param_1 = fVar6 - DAT_400d01ac;
          fVar6 = (float)FUN_400f83dc(((float)((uint)bStack_23 * 0x100 + (uint)bStack_22) / 1.0) *
                                      DAT_400d01b0,DAT_400d00f0);
          fVar6 = fVar6 - DAT_400d01b4;
          param_1[1] = fVar6;
          pfVar5 = param_1 + 1;
          local_30 = DAT_400d0028;
          if (fVar6 < DAT_400d0028) {
            pfVar5 = &local_30;
          }
          local_2c = DAT_400d00e8;
          if (DAT_400d00e8 < *pfVar5) {
            pfVar5 = &local_2c;
          }
          param_1[1] = *pfVar5;
          if (param_3 != 0) {
            FUN_400d3dfc(param_1,param_3,uVar1);
          }
          if (param_2 != 0) {
            FUN_400d3e20(param_1,param_2,uVar1);
          }
        }
        else {
          iVar2 = 0;
        }
      }
      else {
        iVar2 = 0;
      }
    }
  }
  return iVar2;
}



// Function at 0x400d3ffc

undefined4 FUN_400d3ffc(int param_1,undefined4 param_2)

{
  FUN_400d3e44(*(undefined4 *)(param_1 + 8),0,param_2);
  return 1;
}



// Function at 0x400d400c

undefined4 FUN_400d400c(int *param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  byte bStack_22;
  byte bStack_21;
  
  bStack_22 = (byte)(short)param_1[4];
  bStack_21 = (byte)((ushort)(short)param_1[4] >> 8);
  if (*param_1 == 0) {
    iVar3 = param_1[1];
    if (iVar3 == 0) {
      if (param_1[2] == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = FUN_400f7950(param_1[2],&bStack_22,*(undefined1 *)((int)param_1 + 0x13),param_2,
                             param_3);
      }
    }
    else {
      iVar4 = param_1[3];
      if (iVar4 == 3) {
        bVar2 = bStack_21 & 0xfe;
        bStack_21 = bStack_22;
        bStack_22 = bVar2;
        uVar1 = FUN_400d45fc(iVar3,param_2,param_3,&bStack_22,*(byte *)((int)param_1 + 0x13) + 1);
      }
      else {
        if (iVar4 == 0) {
          bStack_22 = bStack_22 & 0x7f;
        }
        if (iVar4 == 2) {
          bStack_22 = bStack_22 | 0x80;
        }
        if (iVar4 == 1) {
          bStack_22 = bStack_22 & 0x7f | 0x40;
        }
        uVar1 = FUN_400d45fc(iVar3,param_2,param_3,&bStack_22,*(undefined1 *)((int)param_1 + 0x13));
      }
    }
  }
  else {
    uVar1 = FUN_400d426c(*param_1,param_2,param_3,1,&bStack_22,*(undefined1 *)((int)param_1 + 0x13))
    ;
  }
  return uVar1;
}



// Function at 0x400d40c4

undefined4 FUN_400d40c4(int param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  param_3 = param_3 & 0xff;
  if (param_3 == 0) {
    param_3 = (uint)*(byte *)(param_1 + 0x12);
  }
  if (param_3 < 5) {
    *(uint *)(param_1 + 0x1c) = param_2;
    for (iVar2 = 0; iVar2 < (int)param_3; iVar2 = iVar2 + 1) {
      if (*(char *)(param_1 + 0x14) == '\0') {
        *(char *)(param_1 + iVar2 + 0x15) = (char)param_2;
      }
      else {
        *(char *)(param_1 + (param_3 - iVar2) + 0x14) = (char)param_2;
      }
      param_2 = param_2 >> 8;
    }
    uVar1 = FUN_400d400c(param_1,param_1 + 0x15,param_3);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



// Function at 0x400d4118

undefined4 FUN_400d4118(int *param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  byte bStack_22;
  byte bStack_21;
  
  bStack_22 = (byte)(short)param_1[4];
  bStack_21 = (byte)((ushort)(short)param_1[4] >> 8);
  if (*param_1 == 0) {
    iVar3 = param_1[1];
    if (iVar3 == 0) {
      if (param_1[2] == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = FUN_400f7928(param_1[2],&bStack_22,*(undefined1 *)((int)param_1 + 0x13),param_2,
                             param_3);
      }
    }
    else {
      iVar4 = param_1[3];
      if (iVar4 == 3) {
        bVar2 = bStack_21 | 1;
        bStack_21 = bStack_22;
        bStack_22 = bVar2;
        uVar1 = FUN_400d466c(iVar3,&bStack_22,*(byte *)((int)param_1 + 0x13) + 1,param_2,param_3,
                             0xff);
      }
      else {
        if (iVar4 == 0) {
          bStack_22 = bStack_22 | 0x80;
        }
        if (iVar4 == 2) {
          bStack_22 = bStack_22 & 0x7f;
        }
        if (iVar4 == 1) {
          bStack_22 = bStack_22 | 0xc0;
        }
        uVar1 = FUN_400d466c(iVar3,&bStack_22,*(undefined1 *)((int)param_1 + 0x13),param_2,param_3,
                             0xff);
      }
    }
  }
  else {
    uVar1 = FUN_400d4360(*param_1,&bStack_22,*(undefined1 *)((int)param_1 + 0x13),param_2,param_3,0)
    ;
  }
  return uVar1;
}



// Function at 0x400d41cc

int FUN_400d41cc(int param_1,short *param_2)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = FUN_400d4118(param_1,param_1 + 0x15,2);
  if (iVar2 != 0) {
    if (*(char *)(param_1 + 0x14) == '\0') {
      bVar1 = *(byte *)(param_1 + 0x16);
      *param_2 = (ushort)bVar1 << 8;
      *param_2 = CONCAT11(bVar1,*(undefined1 *)(param_1 + 0x15));
    }
    else {
      bVar1 = *(byte *)(param_1 + 0x15);
      *param_2 = (ushort)bVar1 << 8;
      *param_2 = CONCAT11(bVar1,*(undefined1 *)(param_1 + 0x16));
    }
  }
  return iVar2;
}



// Function at 0x400d4210

int FUN_400d4210(undefined1 *param_1)

{
  int iVar1;
  
  if ((param_1[8] != '\0') || (iVar1 = FUN_400d4240(param_1,1), iVar1 != 0)) {
    FUN_400d3c34(*(undefined4 *)(param_1 + 4),*param_1);
    iVar1 = FUN_400d3c44(*(undefined4 *)(param_1 + 4));
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}



// Function at 0x400d4240

undefined4 FUN_400d4240(int param_1,char param_2)

{
  undefined4 uVar1;
  
  FUN_400d3944(*(undefined4 *)(param_1 + 4),0xffffffff,0xffffffff,0);
  *(undefined1 *)(param_1 + 8) = 1;
  if (param_2 == '\0') {
    uVar1 = 1;
  }
  else {
    uVar1 = FUN_400d4210(param_1);
  }
  return uVar1;
}



// Function at 0x400d426c

undefined4
FUN_400d426c(undefined1 *param_1,undefined4 param_2,int param_3,undefined1 param_4,int param_5,
            int param_6)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(uint *)(param_1 + 0xc) < (uint)(param_3 + param_6)) {
    uVar1 = 0;
  }
  else {
    FUN_400d3c34(*(undefined4 *)(param_1 + 4),*param_1);
    if ((param_6 == 0 || param_5 == 0) ||
       (iVar2 = (**(code **)(**(int **)(param_1 + 4) + 0xc))(*(int **)(param_1 + 4),param_5,param_6)
       , param_6 == iVar2)) {
      iVar2 = (**(code **)(**(int **)(param_1 + 4) + 0xc))(*(int **)(param_1 + 4),param_2,param_3);
      if (param_3 == iVar2) {
        iVar2 = FUN_400d3afc(*(undefined4 *)(param_1 + 4),param_4);
        if (iVar2 == 0) {
          uVar1 = 1;
        }
        else {
          uVar1 = 0;
        }
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



// Function at 0x400d42e4

undefined4 FUN_400d42e4(undefined1 *param_1,int param_2,uint param_3,undefined1 param_4)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = FUN_400d3c14(*(undefined4 *)(param_1 + 4),*param_1,param_3 & 0xff,param_4);
  if (param_3 == uVar2) {
    for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 1 & 0xffff) {
      uVar1 = (**(code **)(**(int **)(param_1 + 4) + 0x1c))();
      *(undefined1 *)(param_2 + uVar2) = uVar1;
    }
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



// Function at 0x400d4320

undefined4 FUN_400d4320(int param_1,int param_2,uint param_3,char param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  
  uVar2 = 0;
  while( true ) {
    if (param_3 <= uVar2) {
      return 1;
    }
    uVar3 = param_3 - uVar2;
    if (*(uint *)(param_1 + 0xc) < param_3 - uVar2) {
      uVar3 = *(uint *)(param_1 + 0xc);
    }
    if (uVar2 < param_3 - uVar3) {
      cVar4 = '\0';
    }
    else {
      cVar4 = param_4;
      if (param_4 == '\0') {
        cVar4 = '\0';
      }
    }
    iVar1 = FUN_400d42e4(param_1,param_2 + uVar2,uVar3,cVar4);
    if (iVar1 == 0) break;
    uVar2 = uVar2 + uVar3;
  }
  return 0;
}



// Function at 0x400d4360

int FUN_400d4360(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined1 param_6)

{
  int iVar1;
  
  iVar1 = FUN_400d426c(param_1,param_2,param_3,param_6,0);
  if (iVar1 != 0) {
    iVar1 = FUN_400d4320(param_1,param_4,param_5,1);
  }
  return iVar1;
}



// Function at 0x400d4390

void FUN_400d4390(int *param_1,byte *param_2,uint param_3)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uStack_30;
  uint uStack_24;
  
  if (*param_1 == 0) {
    if (param_1[3] == 0) {
      uStack_24 = 1;
    }
    else {
      uStack_24 = 0x80;
    }
    bVar2 = (*param_2 & uStack_24) == 0;
    uVar5 = DAT_400d01b8 / (uint)param_1[2];
    uVar6 = uVar5 & 0xff;
    for (uStack_30 = 0; uStack_30 < param_3; uStack_30 = uStack_30 + 1) {
      uVar7 = (uint)param_2[uStack_30];
      uVar4 = 0;
      uVar3 = uStack_24;
      while (uVar3 != 0) {
        if (uVar6 != 0) {
          FUN_400d5ef0(uVar5 & 0xff);
        }
        if ((char)param_1[4] == '\0' || (char)param_1[4] == '\x02') {
          uVar8 = uVar3 & uVar7;
          bVar1 = uVar8 != 0;
          if ((*(char *)((int)param_1 + 0x13) != -1) && (bVar2 != bVar1)) {
            bVar2 = bVar1;
            if (uVar8 == 0) {
              memw();
              memw();
              *(uint *)param_1[6] = *(uint *)param_1[6] & (param_1[10] ^ 0xffffffffU);
            }
            else {
              memw();
              memw();
              *(uint *)param_1[6] = *(uint *)param_1[6] | param_1[10];
            }
          }
          memw();
          memw();
          *(uint *)param_1[7] = *(uint *)param_1[7] | param_1[0xc];
          if (uVar6 != 0) {
            FUN_400d5ef0(uVar5 & 0xff);
          }
          if (((char)param_1[5] != -1) && (memw(), (*(uint *)param_1[8] & param_1[0xb]) != 0)) {
            uVar4 = uVar4 | uVar3;
          }
          memw();
          memw();
          *(uint *)param_1[7] = *(uint *)param_1[7] & (param_1[0xc] ^ 0xffffffffU);
        }
        else {
          memw();
          memw();
          *(uint *)param_1[7] = *(uint *)param_1[7] | param_1[0xc];
          if (uVar6 != 0) {
            FUN_400d5ef0(uVar5 & 0xff);
          }
          if (*(char *)((int)param_1 + 0x13) != -1) {
            if ((uVar3 & uVar7) == 0) {
              memw();
              memw();
              *(uint *)param_1[6] = *(uint *)param_1[6] & (param_1[10] ^ 0xffffffffU);
            }
            else {
              memw();
              memw();
              *(uint *)param_1[6] = *(uint *)param_1[6] | param_1[10];
            }
          }
          memw();
          memw();
          *(uint *)param_1[7] = *(uint *)param_1[7] & (param_1[0xc] ^ 0xffffffffU);
          if (((char)param_1[5] != -1) && (memw(), (*(uint *)param_1[8] & param_1[0xb]) != 0)) {
            uVar4 = uVar4 | uVar3;
          }
        }
        if ((char)param_1[5] != -1) {
          param_2[uStack_30] = (byte)uVar4;
        }
        if (param_1[3] == 0) {
          uVar3 = (uVar3 & 0x7f) << 1;
        }
        else {
          uVar3 = uVar3 >> 1;
        }
      }
    }
  }
  else {
    FUN_400d4b04(*param_1,param_2,param_3);
  }
  return;
}



// Function at 0x400d4580

undefined1 FUN_400d4580(undefined4 param_1,undefined1 param_2)

{
  undefined1 auStack_21 [33];
  
  auStack_21[0] = param_2;
  FUN_400d4390(param_1,auStack_21,1);
  return auStack_21[0];
}



// Function at 0x400d4598

void FUN_400d4598(int *param_1)

{
  if (*param_1 != 0) {
    FUN_400d4a78(*param_1,*(undefined4 *)param_1[1],((undefined4 *)param_1[1])[1]);
  }
  return;
}



// Function at 0x400d45ac

void FUN_400d45ac(int *param_1)

{
  if (*param_1 != 0) {
    FUN_400d4ac0();
  }
  return;
}



// Function at 0x400d45b8

void FUN_400d45b8(int param_1,undefined1 param_2)

{
  if (*(char *)(param_1 + 0x11) != -1) {
    FUN_400d5714(*(char *)(param_1 + 0x11),param_2);
  }
  return;
}



// Function at 0x400d45d4

void FUN_400d45d4(undefined4 param_1)

{
  FUN_400d4598(param_1);
  FUN_400d45b8(param_1,0);
  return;
}



// Function at 0x400d45e8

void FUN_400d45e8(undefined4 param_1)

{
  FUN_400d45b8(param_1,1);
  FUN_400d45ac(param_1);
  return;
}



// Function at 0x400d45fc

undefined4 FUN_400d45fc(int *param_1,int param_2,uint param_3,int param_4,uint param_5)

{
  uint uVar1;
  
  FUN_400d45d4(param_1);
  if (*param_1 == 0) {
    for (uVar1 = 0; uVar1 < param_5; uVar1 = uVar1 + 1) {
      FUN_400d4580(param_1,*(undefined1 *)(param_4 + uVar1));
    }
    for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1) {
      FUN_400d4580(param_1,*(undefined1 *)(param_2 + uVar1));
    }
  }
  else {
    if (param_5 != 0) {
      FUN_400d4ae4(*param_1,param_4,0,param_5);
    }
    if (param_3 != 0) {
      FUN_400d4ae4(*param_1,param_2,0,param_3);
    }
  }
  FUN_400d45e8(param_1);
  return 1;
}



// Function at 0x400d466c

undefined4
FUN_400d466c(int *param_1,int param_2,uint param_3,int param_4,uint param_5,undefined1 param_6)

{
  undefined1 uVar1;
  uint uVar2;
  
  FUN_400d45d4(param_1);
  if (*param_1 == 0) {
    for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 1) {
      FUN_400d4580(param_1,*(undefined1 *)(param_2 + uVar2));
    }
  }
  else if (param_3 != 0) {
    FUN_400d4ae4(*param_1,param_2,0,param_3);
  }
  for (uVar2 = 0; uVar2 < param_5; uVar2 = uVar2 + 1) {
    uVar1 = FUN_400d4580(param_1,param_6);
    *(undefined1 *)(param_4 + uVar2) = uVar1;
  }
  FUN_400d45e8(param_1);
  return 1;
}



// Function at 0x400d46d0

void FUN_400d46d0(undefined4 *param_1,undefined1 param_2)

{
  *param_1 = 0;
  *(undefined1 *)((int)param_1 + 5) = param_2;
  param_1[3] = 0;
  param_1[4] = DAT_400d0028;
  return;
}



// Function at 0x400d46e4

void FUN_400d46e4(undefined4 *param_1)

{
  FUN_400e8230(*param_1);
  return;
}



// Function at 0x400d46f0

int FUN_400d46f0(undefined4 *param_1)

{
  undefined1 uVar1;
  ushort uStack_42;
  undefined1 auStack_40 [64];
  
  FUN_400f790c(auStack_40,*param_1,2,2,1);
  uVar1 = FUN_400d41cc(auStack_40,&uStack_42);
  *(undefined1 *)(param_1 + 1) = uVar1;
  return ((int)(uint)uStack_42 >> 3) << 2;
}



// Function at 0x400d471c

int FUN_400d471c(undefined4 *param_1)

{
  undefined1 uVar1;
  short sStack_42;
  undefined1 auStack_40 [64];
  
  FUN_400f790c(auStack_40,*param_1,1,2,1);
  uVar1 = FUN_400d41cc(auStack_40,&sStack_42);
  *(undefined1 *)(param_1 + 1) = uVar1;
  return (int)sStack_42;
}



// Function at 0x400d4744

int FUN_400d4744(undefined4 *param_1)

{
  undefined1 uVar1;
  short sStack_62;
  undefined1 auStack_60 [32];
  undefined1 auStack_40 [64];
  
  FUN_400f790c(auStack_60,*param_1,5,2,1);
  FUN_400d40c4(auStack_60,param_1[2],2);
  FUN_400f790c(auStack_40,*param_1,4,2,1);
  uVar1 = FUN_400d41cc(auStack_40,&sStack_62);
  *(undefined1 *)(param_1 + 1) = uVar1;
  return (int)sStack_62;
}



// Function at 0x400d4784

int FUN_400d4784(undefined4 *param_1)

{
  undefined1 uVar1;
  short sStack_62;
  undefined1 auStack_60 [32];
  undefined1 auStack_40 [64];
  
  FUN_400f790c(auStack_60,*param_1,5,2,1);
  FUN_400d40c4(auStack_60,param_1[2],2);
  FUN_400f790c(auStack_40,*param_1,3,2,1);
  uVar1 = FUN_400d41cc(auStack_40,&sStack_62);
  *(undefined1 *)(param_1 + 1) = uVar1;
  return (int)sStack_62;
}



// Function at 0x400d47c4

undefined4 FUN_400d47c4(undefined4 param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  FUN_400d471c(param_1);
  uVar2 = (*DAT_400d00e4)();
  (*DAT_400d0064)((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),DAT_400d01bc,DAT_400d01c0);
  uVar1 = (*DAT_400d01c4)();
  return uVar1;
}



// Function at 0x400d47e8

undefined4 FUN_400d47e8(undefined4 param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  FUN_400d46f0(param_1);
  uVar2 = (*DAT_400d00e4)();
  (*DAT_400d0064)((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),DAT_400d01c8,DAT_400d01cc);
  uVar1 = (*DAT_400d01c4)();
  return uVar1;
}



// Function at 0x400d480c

undefined4 FUN_400d480c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_400d4744(param_1);
  uVar2 = FUN_400f83dc((float)iVar1 / 1.0,(float)*(uint *)(param_1 + 0xc) / 1.0);
  return uVar2;
}



// Function at 0x400d482c

float FUN_400d482c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_400d4784(param_1);
  return *(float *)(param_1 + 0x10) * ((float)iVar1 / 1.0);
}



// Function at 0x400d4844

void FUN_400d4844(undefined4 *param_1)

{
  undefined1 uVar1;
  undefined1 auStack_60 [32];
  undefined1 auStack_40 [64];
  
  param_1[2] = DAT_400d01d0;
  param_1[3] = 10;
  param_1[4] = DAT_400d0088;
  FUN_400f790c(auStack_60,*param_1,5,2,1);
  FUN_400d40c4(auStack_60,param_1[2],2);
  FUN_400f790c(auStack_40,*param_1,0,2,1);
  uVar1 = FUN_400d40c4(auStack_40,DAT_400d01d4,2);
  *(undefined1 *)(param_1 + 1) = uVar1;
  return;
}



// Function at 0x400d4890

void FUN_400d4890(undefined4 param_1)

{
  FUN_400d4844(param_1);
  return;
}



// Function at 0x400d489c

int FUN_400d489c(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*param_1 == 0) {
    iVar1 = FUN_400e79d4(0x10);
    FUN_400f7978(iVar1,*(undefined1 *)((int)param_1 + 5),param_2);
    *param_1 = iVar1;
  }
  iVar1 = FUN_400d4240(*param_1,1);
  if (iVar1 != 0) {
    FUN_400d4890(param_1);
  }
  return iVar1;
}



// Function at 0x400d48ec

void FUN_400d48ec(undefined4 *param_1)

{
  undefined1 uVar1;
  undefined1 auStack_60 [32];
  undefined1 auStack_40 [64];
  
  param_1[2] = DAT_400d01d8;
  param_1[3] = 0x19;
  param_1[4] = DAT_400d01dc;
  FUN_400f790c(auStack_60,*param_1,5,2,1);
  FUN_400d40c4(auStack_60,param_1[2],2);
  FUN_400f790c(auStack_40,*param_1,0,2,1);
  uVar1 = FUN_400d40c4(auStack_40,DAT_400d01d4,2);
  *(undefined1 *)(param_1 + 1) = uVar1;
  return;
}



// Function at 0x400d4938

void FUN_400d4938(undefined4 *param_1)

{
  undefined1 uVar1;
  undefined1 auStack_60 [32];
  undefined1 auStack_40 [64];
  
  param_1[2] = DAT_400d01e0;
  param_1[3] = 0x14;
  param_1[4] = DAT_400d0080;
  FUN_400f790c(auStack_60,*param_1,5,2,1);
  FUN_400d40c4(auStack_60,param_1[2],2);
  FUN_400f790c(auStack_40,*param_1,0,2,1);
  uVar1 = FUN_400d40c4(auStack_40,0x19f,2);
  *(undefined1 *)(param_1 + 1) = uVar1;
  return;
}



// Function at 0x400d4984

void FUN_400d4984(undefined1 *param_1,undefined1 param_2)

{
  undefined4 uVar1;
  
  *param_1 = param_2;
  *(undefined4 *)(param_1 + 4) = 0;
  param_1[8] = 0;
  param_1[9] = 0xff;
  param_1[10] = 0xff;
  param_1[0xb] = 0xff;
  param_1[0xc] = 0xff;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = DAT_400d01e4;
  param_1[0x18] = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  uVar1 = func_0x400893a4(1);
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  return;
}



// Function at 0x400d49b4

void FUN_400d49b4(int param_1,char param_2)

{
  if ((param_2 == '\0') || (*(char *)(param_1 + 8) != '\0')) {
    if ((param_2 == '\0') && (*(char *)(param_1 + 8) != '\0')) {
      FUN_400d634c(*(undefined4 *)(param_1 + 4));
      FUN_400d619c(*(undefined4 *)(param_1 + 4),(int)*(char *)(param_1 + 0xc));
    }
  }
  else {
    FUN_400d6218(*(undefined4 *)(param_1 + 4),0,(int)*(char *)(param_1 + 0xc));
    FUN_400d630c(*(undefined4 *)(param_1 + 4));
  }
  *(char *)(param_1 + 8) = param_2;
  return;
}



// Function at 0x400d49fc

void FUN_400d49fc(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    FUN_400d60b4(*(int *)(param_1 + 4),(int)*(char *)(param_1 + 9));
    FUN_400d60f8(*(undefined4 *)(param_1 + 4),(int)*(char *)(param_1 + 10));
    FUN_400d6158(*(undefined4 *)(param_1 + 4),(int)*(char *)(param_1 + 0xb));
    FUN_400d49b4(param_1,0);
    FUN_400d6390(*(undefined4 *)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}



// Function at 0x400d4a34

void FUN_400d4a34(int param_1)

{
  FUN_400d49fc(param_1);
  if (*(int *)(param_1 + 0x1c) != 0) {
    func_0x400899b0();
  }
  return;
}



// Function at 0x400d4a48

void FUN_400d4a48(int param_1,int param_2)

{
  if ((param_1 == 1) && (param_2 == DAT_400d0020)) {
    FUN_400d4984(DAT_400d01e8,3);
  }
  if ((param_1 == 0) && (param_2 == DAT_400d0020)) {
    FUN_400d4a34(DAT_400d01e8);
  }
  return;
}



// Function at 0x400d4a78

void FUN_400d4a78(int param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 uStack_23;
  
  do {
    iVar1 = func_0x400896ec(*(undefined4 *)(param_1 + 0x1c),0xffffffff);
  } while (iVar1 != 1);
  iVar1 = FUN_400f7a30(*(undefined4 *)(param_1 + 4));
  if ((*(int *)(param_1 + 0x14) != param_2) || (*(int *)(param_1 + 0x10) != iVar1)) {
    *(int *)(param_1 + 0x14) = param_2;
    uVar2 = FUN_400d6698(param_2);
    *(undefined4 *)(param_1 + 0x10) = uVar2;
  }
  uStack_23 = (undefined1)(param_3 >> 8);
  FUN_400d6418(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x10),uStack_23,param_3 & 0xff
              );
  *(undefined1 *)(param_1 + 0x18) = 1;
  return;
}



// Function at 0x400d4ac0

void FUN_400d4ac0(int param_1)

{
  if (*(char *)(param_1 + 0x18) != '\0') {
    *(undefined1 *)(param_1 + 0x18) = 0;
    FUN_400d6540(*(undefined4 *)(param_1 + 4));
    func_0x40089194(*(undefined4 *)(param_1 + 0x1c),0,0);
  }
  return;
}



// Function at 0x400d4ae4

void FUN_400d4ae4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (*(char *)(param_1 + 0x18) == '\0') {
    FUN_400d63bc(*(undefined4 *)(param_1 + 4));
  }
  else {
    FUN_400d6554(*(undefined4 *)(param_1 + 4),param_2,param_3,param_4);
  }
  return;
}



// Function at 0x400d4b04

void FUN_400d4b04(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_400d4ae4(param_1,param_2,param_2,param_3);
  return;
}



// Function at 0x400d4b18

void FUN_400d4b18(void)

{
  FUN_400d4a48(1,DAT_400d0020);
  return;
}



// Function at 0x400d4b28

void FUN_400d4b28(void)

{
  FUN_400d4a48(0,DAT_400d0020);
  return;
}



// Function at 0x400d4b38

undefined4 FUN_400d4b38(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400d6b48(*(undefined4 *)(param_1 + 0x14));
  return uVar1;
}



// Function at 0x400d4b44

undefined4 FUN_400d4b44(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400d6b84(*(undefined4 *)(param_1 + 0x14));
  return uVar1;
}



// Function at 0x400d4b50

undefined4 FUN_400d4b50(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x18))(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = FUN_400d6c8c(param_1[5]);
  }
  return uVar2;
}



// Function at 0x400d4bb0

void FUN_400d4bb0(int param_1)

{
  FUN_400d6de0(*(undefined4 *)(param_1 + 0x14));
  return;
}



// Function at 0x400d4bbc

undefined4 FUN_400d4bbc(int param_1,undefined1 param_2)

{
  FUN_400d6cec(*(undefined4 *)(param_1 + 0x14),param_2);
  return 1;
}



// Function at 0x400d4be0

void FUN_400d4be0(void)

{
  int iVar1;
  
  iVar1 = FUN_400d4b38(DAT_400d00a0);
  if (iVar1 != 0) {
    FUN_400f79a0();
  }
  iVar1 = FUN_400d4b38(DAT_400d01ec);
  if (iVar1 != 0) {
    FUN_400f79a8();
  }
  iVar1 = FUN_400d4b38(DAT_400d01f0);
  if (iVar1 != 0) {
    FUN_400f79b0();
  }
  return;
}



// Function at 0x400d4c18

void FUN_400d4c18(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  param_1[1] = 0;
  param_1[3] = 0;
  param_1[2] = 1000;
  *param_1 = DAT_400d01f4;
  param_1[4] = param_2;
  param_1[5] = 0;
  param_1[6] = 0x100;
  param_1[7] = 0;
  param_1[10] = 0;
  param_1[0xe] = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined1 *)((int)param_1 + 0x41) = 2;
  *(undefined1 *)((int)param_1 + 0x42) = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  *(undefined1 *)(param_1 + 0x13) = 0xff;
  *(undefined1 *)((int)param_1 + 0x4d) = 0xff;
  *(undefined1 *)((int)param_1 + 0x4e) = 0xff;
  *(undefined1 *)((int)param_1 + 0x4f) = 0xff;
  uVar1 = func_0x400893a4(1);
  param_1[0x12] = uVar1;
  return;
}



// Function at 0x400d4c90

void FUN_400d4c90(int param_1)

{
  FUN_400d5ea4(PTR_LAB_400d0200,DAT_400d01fc,DAT_400d01f8,param_1,0x18,param_1 + 0x44,0xffffffff);
  return;
}



// Function at 0x400d4cb0

void FUN_400d4cb0(int param_1)

{
  if (*(int *)(param_1 + 0x44) != 0) {
    func_0x4008a900();
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  return;
}



// Function at 0x400d4cc4

void FUN_400d4cc4(int param_1,char param_2)

{
  int iVar1;
  
  if (param_2 != '\0') {
    if (*(code **)(param_1 + 0x28) != (code *)0x0) {
      (**(code **)(param_1 + 0x28))(param_1 + 0x20,param_1 + 0x20,3);
      *(undefined4 *)(param_1 + 0x28) = 0;
      *(undefined4 *)(param_1 + 0x2c) = 0;
    }
    if (*(code **)(param_1 + 0x38) != (code *)0x0) {
      (**(code **)(param_1 + 0x38))(param_1 + 0x30,param_1 + 0x30,3);
      *(undefined4 *)(param_1 + 0x38) = 0;
      *(undefined4 *)(param_1 + 0x3c) = 0;
    }
    iVar1 = FUN_400d6fc0();
    if (*(int *)(param_1 + 0x10) == iVar1) {
      FUN_400d6f9c(0);
    }
    *(undefined1 *)(param_1 + 0x42) = 0;
    FUN_400d68e8(*(undefined4 *)(param_1 + 0x14),(int)*(char *)(param_1 + 0x4c),
                 (int)*(char *)(param_1 + 0x4d),(int)*(char *)(param_1 + 0x4e),
                 (int)*(char *)(param_1 + 0x4f));
    *(undefined1 *)(param_1 + 0x4f) = 0xff;
    *(undefined1 *)(param_1 + 0x4e) = 0xff;
    *(undefined1 *)(param_1 + 0x4d) = 0xff;
    *(undefined1 *)(param_1 + 0x4c) = 0xff;
  }
  FUN_400d5ee4(10);
  FUN_400d6b24(*(undefined4 *)(param_1 + 0x14));
  *(undefined4 *)(param_1 + 0x14) = 0;
  FUN_400d4cb0(param_1);
  return;
}



// Function at 0x400d4d60

void FUN_400d4d60(undefined4 *param_1)

{
  *param_1 = DAT_400d01f4;
  FUN_400d4cc4(param_1,1);
  if (param_1[0x12] != 0) {
    func_0x400899b0();
  }
  if ((code *)param_1[0xe] != (code *)0x0) {
    (*(code *)param_1[0xe])(param_1 + 0xc,param_1 + 0xc,3);
  }
  if ((code *)param_1[10] != (code *)0x0) {
    (*(code *)param_1[10])(param_1 + 8,param_1 + 8,3);
  }
  return;
}



// Function at 0x400d4d98

void FUN_400d4d98(undefined4 param_1)

{
  FUN_400d4d60(param_1);
  FUN_400e8230(param_1);
  return;
}



// Function at 0x400d4dac

void FUN_400d4dac(int param_1,int param_2)

{
  if ((param_1 == 1) && (param_2 == DAT_400d0020)) {
    FUN_400d4c18(DAT_400d00a0,0);
    FUN_400d4c18(DAT_400d01ec,1);
    FUN_400d4c18(DAT_400d01f0,2);
  }
  if ((param_1 == 0) && (param_2 == DAT_400d0020)) {
    FUN_400d4d60(DAT_400d01f0);
    FUN_400d4d60(DAT_400d01ec);
    FUN_400d4d60(DAT_400d00a0);
  }
  return;
}



// Function at 0x400d4df8

void FUN_400d4df8(int param_1,uint param_2,undefined4 param_3,uint param_4,uint param_5,
                 undefined1 param_6,uint param_7,undefined1 param_8)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 uVar5;
  char cVar6;
  uint uVar8;
  char cStack_38;
  uint uVar7;
  
  uVar7 = param_4 & 0xff;
  cVar6 = (char)param_4;
  uVar8 = param_5 & 0xff;
  cStack_38 = (char)param_5;
  if ((*(uint *)(param_1 + 0x10) < 3) && (*(int *)(param_1 + 0x48) != 0)) {
    do {
      iVar1 = func_0x400896ec(*(undefined4 *)(param_1 + 0x48),0xffffffff);
    } while (iVar1 != 1);
    iVar1 = FUN_400d6a9c(*(undefined4 *)(param_1 + 0x14));
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x10);
      if (iVar1 == 1) {
        if ((uVar7 & uVar8) >> 7 != 0) {
          cStack_38 = '\n';
          cVar6 = '\t';
        }
      }
      else if (iVar1 == 2) {
        if ((uVar7 & uVar8) >> 7 != 0) {
          cStack_38 = '\x11';
          cVar6 = '\x10';
        }
      }
      else if ((iVar1 == 0) && ((uVar7 & uVar8) >> 7 != 0)) {
        cStack_38 = '\x01';
        cVar6 = '\x03';
      }
    }
    if (*(int *)(param_1 + 0x14) != 0) {
      FUN_400d4cc4(param_1,0);
    }
    uVar7 = DAT_400d0204;
    if (param_2 != 0) {
      uVar7 = param_2;
    }
    uVar2 = FUN_400d6df0(*(undefined1 *)(param_1 + 0x10),uVar7,param_3,(int)cVar6,(int)cStack_38,
                         *(undefined2 *)(param_1 + 0x18),*(undefined2 *)(param_1 + 0x1c),param_6,
                         param_8);
    *(undefined4 *)(param_1 + 0x14) = uVar2;
    if (param_2 == 0) {
      FUN_400d704c();
      iVar3 = FUN_400d5ecc();
      iVar1 = 0;
      while ((iVar4 = FUN_400d5ecc(), (uint)(iVar4 - iVar3) < param_7 &&
             (iVar1 = FUN_400d70a4(*(undefined4 *)(param_1 + 0x14)), iVar1 == 0))) {
        FUN_400d5e9c();
      }
      FUN_400d4cc4(param_1,0);
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x14) = 0;
      }
      else {
        FUN_400d5ee4(100);
        uVar2 = FUN_400d6df0(*(undefined1 *)(param_1 + 0x10),iVar1,param_3,(int)cVar6,(int)cStack_38
                             ,*(undefined2 *)(param_1 + 0x18),*(undefined2 *)(param_1 + 0x1c),
                             param_6,param_8);
        *(undefined4 *)(param_1 + 0x14) = uVar2;
      }
    }
    if ((*(int *)(param_1 + 0x14) != 0) &&
       (((*(int *)(param_1 + 0x28) != 0 || (*(int *)(param_1 + 0x38) != 0)) &&
        (*(int *)(param_1 + 0x44) == 0)))) {
      FUN_400d4c90(param_1,param_1);
    }
    FUN_400d6ab4(*(undefined4 *)(param_1 + 0x14),*(undefined1 *)(param_1 + 0x41));
    if (*(char *)(param_1 + 0x42) == '\0') {
      if (DAT_400d0208 < param_2) {
        uVar5 = 0x78;
      }
      else if (*(int *)(param_1 + 0x28) == 0) {
        uVar5 = 1;
      }
      else if (*(char *)(param_1 + 0x40) == '\0') {
        uVar5 = 1;
      }
      else {
        uVar5 = 0x78;
      }
      FUN_400d6aec(*(undefined4 *)(param_1 + 0x14),uVar5);
      *(undefined1 *)(param_1 + 0x42) = uVar5;
    }
    *(char *)(param_1 + 0x4c) = cVar6;
    *(char *)(param_1 + 0x4d) = cStack_38;
    func_0x40089194(*(undefined4 *)(param_1 + 0x48),0,0);
  }
  return;
}



// Function at 0x400d4fbc

/* WARNING: Control flow encountered bad instruction data */

void FUN_400d4fbc(int param_1)

{
  if (*(int *)(param_1 + 8) != 0) {
    (**(code **)(param_1 + 0xc))(param_1);
    return;
  }
  FUN_400e841c();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// Function at 0x400d4fd0

/* WARNING: Control flow encountered bad instruction data */

void FUN_400d4fd0(int param_1,undefined4 param_2)

{
  undefined4 auStack_24 [9];
  
  auStack_24[0] = param_2;
  if (*(int *)(param_1 + 8) != 0) {
    (**(code **)(param_1 + 0xc))(param_1,auStack_24);
    return;
  }
  FUN_400e841c();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// Function at 0x400d5060

void FUN_400d5060(int param_1,int param_2)

{
  *(undefined4 *)(param_1 + 8) = 0;
  if (*(code **)(param_2 + 8) != (code *)0x0) {
    (**(code **)(param_2 + 8))(param_1,param_2,2);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 8);
  }
  return;
}



// Function at 0x400d5098

void FUN_400d5098(int param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uStack_34;
  undefined4 uStack_30;
  code *pcStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  do {
    iVar1 = func_0x400896ec(*(undefined4 *)(param_1 + 0x48),0xffffffff);
  } while (iVar1 != 1);
  FUN_400d5060(&uStack_34,param_2);
  uVar5 = *(undefined4 *)(param_1 + 0x20);
  uVar3 = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x20) = uStack_34;
  *(undefined4 *)(param_1 + 0x24) = uStack_30;
  pcVar4 = *(code **)(param_1 + 0x28);
  *(code **)(param_1 + 0x28) = pcStack_2c;
  uVar2 = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(param_1 + 0x2c) = uStack_28;
  uStack_34 = uVar5;
  uStack_30 = uVar3;
  pcStack_2c = pcVar4;
  uStack_28 = uVar2;
  if (pcVar4 != (code *)0x0) {
    (*pcVar4)(&uStack_34,&uStack_34,3);
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    if (*(char *)(param_1 + 0x41) == '\0') {
      param_3 = '\0';
    }
    *(char *)(param_1 + 0x40) = param_3;
    if (param_3 != '\0') {
      FUN_400d6aec(*(undefined4 *)(param_1 + 0x14),0x78);
    }
    if ((*(int *)(param_1 + 0x14) != 0) && (*(int *)(param_1 + 0x44) == 0)) {
      FUN_400d4c90(param_1,param_1);
    }
  }
  func_0x40089194(*(undefined4 *)(param_1 + 0x48),0,0);
  memw();
  memw();
  if (iStack_24 == *DAT_400d0098) {
    return;
  }
  func_0x400831d4();
  return;
}



// Function at 0x400d5168

void FUN_400d5168(void)

{
  FUN_400d4dac(0,DAT_400d0020);
  return;
}



// Function at 0x400d5178

undefined4 FUN_400d5178(int *param_1,int param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    pcVar2 = *(code **)(*param_1 + 0xc);
    uVar1 = func_0x40086c6c(param_2);
    uVar1 = (*pcVar2)(param_1,param_2,uVar1);
  }
  return uVar1;
}



// Function at 0x400d519c

undefined4 FUN_400d519c(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400d5178(param_1,DAT_400d020c);
  return uVar1;
}



// Function at 0x400d51b0

int FUN_400d51b0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_400d5178(param_1,param_2);
  iVar2 = FUN_400d519c(param_1);
  return iVar1 + iVar2;
}



// Function at 0x400d51c8

int FUN_400d51c8(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_400d5ecc();
  param_1[3] = iVar1;
  do {
    iVar1 = (**(code **)(*param_1 + 0x1c))(param_1);
    if (-1 < iVar1) {
      return iVar1;
    }
    iVar1 = FUN_400d5ecc();
  } while ((uint)(iVar1 - param_1[3]) < (uint)param_1[2]);
  return -1;
}



// Function at 0x400d51f4

void FUN_400d51f4(undefined4 param_1,undefined1 *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  while ((uVar1 < param_3 && (iVar2 = FUN_400d51c8(param_1), -1 < iVar2))) {
    *param_2 = (char)iVar2;
    uVar1 = uVar1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}



// Function at 0x400d5214

undefined4 FUN_400d5214(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  FUN_400d5524(param_1,DAT_400d0210);
  uVar1 = FUN_400d51c8(param_2);
  while (-1 < (int)uVar1) {
    FUN_400d5640(param_1,uVar1 & 0xff);
    uVar1 = FUN_400d51c8(param_2);
  }
  return param_1;
}



// Function at 0x400d525c

/* WARNING: Removing unreachable block (ram,0x400d5286) */

undefined4 FUN_400d525c(int *param_1)

{
  if ((-1 < *(char *)((int)param_1 + 0xf)) && (*param_1 != 0)) {
    func_0x4008dbfc();
  }
  *(byte *)((int)param_1 + 0xf) = *(byte *)((int)param_1 + 0xf) & 0x7f;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return 0;
}



// Function at 0x400d528c

void FUN_400d528c(undefined4 param_1)

{
  FUN_400d525c(param_1);
  return;
}



// Function at 0x400d5298

/* WARNING: Removing unreachable block (ram,0x400d535a) */
/* WARNING: Removing unreachable block (ram,0x400d539b) */
/* WARNING: Removing unreachable block (ram,0x400d53a1) */

undefined4 FUN_400d5298(int *param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  undefined1 auStack_33 [15];
  int iStack_24;
  
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  if (param_2 < 0xe) {
    if ((*(char *)((int)param_1 + 0xf) < '\0') || (*param_1 == 0)) {
      if (*(char *)((int)param_1 + 0xf) < '\0') {
        uVar3 = (uint)param_1[3] >> 0x18 & 0x7f;
      }
      else {
        uVar3 = param_1[2];
      }
      *(byte *)((int)param_1 + 0xf) = *(byte *)((int)param_1 + 0xf) | 0x80;
      *(byte *)((int)param_1 + 0xf) = (byte)(uVar3 & 0xffff) & 0x7f | 0x80;
      *(undefined1 *)((int)param_1 + (uVar3 & 0xffff)) = 0;
    }
    else {
      func_0x400866b8(auStack_33,*param_1,param_2);
      piVar7 = param_1;
      if (-1 < *(char *)((int)param_1 + 0xf)) {
        piVar7 = (int *)*param_1;
      }
      func_0x4008dbfc(piVar7);
      if (*(char *)((int)param_1 + 0xf) < '\0') {
        uVar3 = (uint)param_1[3] >> 0x18 & 0x7f;
      }
      else {
        uVar3 = param_1[2];
      }
      *(byte *)((int)param_1 + 0xf) = *(byte *)((int)param_1 + 0xf) | 0x80;
      func_0x400866b8(param_1,auStack_33,param_2);
      uVar3 = uVar3 & 0xffff;
      if (*(char *)((int)param_1 + 0xf) < '\0') {
        *(byte *)((int)param_1 + 0xf) = *(byte *)((int)param_1 + 0xf) & 0x80 | (byte)uVar3 & 0x7f;
        *(undefined1 *)((int)param_1 + uVar3) = 0;
      }
      else {
        param_1[2] = uVar3;
        if (*param_1 != 0) {
          *(undefined1 *)(*param_1 + uVar3) = 0;
        }
      }
    }
    uVar2 = 1;
  }
  else {
    uVar3 = param_2 + 0x10 & 0xfffffff0;
    if (DAT_400d0020 < uVar3) {
      uVar2 = 0;
    }
    else {
      if (*(char *)((int)param_1 + 0xf) < '\0') {
        uVar4 = (uint)param_1[3] >> 0x18 & 0x7f;
        uVar2 = 0;
      }
      else {
        uVar4 = param_1[2];
        uVar2 = *param_1;
      }
      iVar1 = func_0x4008dbe8(uVar2,uVar3);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        if (*(char *)((int)param_1 + 0xf) < '\0') {
          iVar5 = 0xe;
        }
        else {
          iVar5 = param_1[1];
        }
        uVar6 = iVar5 + 1;
        if (*(char *)((int)param_1 + 0xf) < '\0') {
          func_0x400867b0(iVar1,param_1,0xf);
        }
        if (uVar6 < uVar3) {
          func_0x40086818(iVar1 + uVar6,0,uVar3 - uVar6);
        }
        *(byte *)((int)param_1 + 0xf) = *(byte *)((int)param_1 + 0xf) & 0x7f;
        param_1[1] = uVar3 - 1;
        *param_1 = iVar1;
        param_1[2] = uVar4 & 0xffff;
        if (iVar1 != 0) {
          *(undefined1 *)(iVar1 + (uVar4 & 0xffff)) = 0;
        }
        uVar2 = 1;
      }
    }
  }
  memw();
  memw();
  if (iStack_24 == *DAT_400d0098) {
    return uVar2;
  }
  uVar2 = func_0x400831d4();
  return uVar2;
}



// Function at 0x400d5454

int FUN_400d5454(undefined4 *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar3 = param_1;
  if (-1 < *(char *)((int)param_1 + 0xf)) {
    puVar3 = (undefined4 *)*param_1;
  }
  if (puVar3 != (undefined4 *)0x0) {
    if (*(char *)((int)param_1 + 0xf) < '\0') {
      uVar2 = 0xe;
    }
    else {
      uVar2 = param_1[1];
    }
    if (param_2 <= uVar2) {
      return 1;
    }
  }
  iVar1 = FUN_400d5298(param_1,param_2);
  if (iVar1 != 0) {
    if (*(char *)((int)param_1 + 0xf) < '\0') {
      uVar2 = (uint)param_1[3] >> 0x18 & 0x7f;
    }
    else {
      uVar2 = param_1[2];
    }
    if (uVar2 == 0) {
      if (-1 < *(char *)((int)param_1 + 0xf)) {
        param_1 = (undefined4 *)*param_1;
      }
      *(undefined1 *)param_1 = 0;
    }
  }
  return iVar1;
}



// Function at 0x400d54c0

void FUN_400d54c0(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_400d5454(param_1,param_3);
  if (iVar1 == 0) {
    FUN_400d525c(param_1);
  }
  else {
    piVar2 = param_1;
    if (-1 < *(char *)((int)param_1 + 0xf)) {
      piVar2 = (int *)*param_1;
    }
    func_0x400867b0(piVar2,param_2,param_3 + 1);
    if (*(char *)((int)param_1 + 0xf) < '\0') {
      *(byte *)((int)param_1 + 0xf) = *(byte *)((int)param_1 + 0xf) & 0x80 | (byte)param_3 & 0x7f;
      *(undefined1 *)((int)param_1 + param_3) = 0;
    }
    else {
      param_1[2] = param_3;
      if (*param_1 != 0) {
        *(undefined1 *)(*param_1 + param_3) = 0;
      }
    }
  }
  return;
}



// Function at 0x400d5524

/* WARNING: Removing unreachable block (ram,0x400d553d) */

void FUN_400d5524(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  *(byte *)((int)param_1 + 0xf) = *(byte *)((int)param_1 + 0xf) & 0x7f;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  if (param_2 != 0) {
    uVar1 = func_0x40086c6c(param_2);
    FUN_400d54c0(param_1,param_2,uVar1);
  }
  return;
}



// Function at 0x400d5554

void FUN_400d5554(int param_1,int param_2)

{
  if ((param_1 == 1) && (param_2 == DAT_400d0020)) {
    FUN_400d5524(DAT_400d0218,DAT_400d0214);
  }
  if ((param_1 == 0) && (param_2 == DAT_400d0020)) {
    FUN_400d528c(DAT_400d0218);
  }
  return;
}



// Function at 0x400d5584

int FUN_400d5584(int *param_1,int *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  if (*(char *)((int)param_1 + 0xf) < '\0') {
    uVar5 = (uint)param_1[3] >> 0x18 & 0x7f;
  }
  else {
    uVar5 = param_1[2];
  }
  iVar3 = param_3 + uVar5;
  if (param_2 == (int *)0x0) {
    return 0;
  }
  if (param_3 == 0) {
    return 1;
  }
  iVar2 = FUN_400d5454(param_1,iVar3);
  if (iVar2 == 0) {
    return 0;
  }
  cVar1 = *(char *)((int)param_1 + 0xf);
  piVar4 = param_1;
  if (-1 < cVar1) {
    piVar4 = (int *)*param_1;
  }
  if (piVar4 <= param_2) {
    if (cVar1 < '\0') {
      uVar5 = (uint)param_1[3] >> 0x18 & 0x7f;
    }
    else {
      uVar5 = param_1[2];
    }
    if (param_2 < (int *)((int)piVar4 + uVar5)) {
      func_0x400867b0((int *)((int)piVar4 + uVar5),param_2,param_3 + 1);
      goto LAB_400d55e0;
    }
  }
  if (cVar1 < '\0') {
    uVar5 = (uint)param_1[3] >> 0x18 & 0x7f;
  }
  else {
    uVar5 = param_1[2];
  }
  func_0x400866b8((int)piVar4 + uVar5,param_2,param_3 + 1);
LAB_400d55e0:
  if (*(char *)((int)param_1 + 0xf) < '\0') {
    *(byte *)((int)param_1 + 0xf) = *(byte *)((int)param_1 + 0xf) & 0x80 | (byte)iVar3 & 0x7f;
    *(undefined1 *)((int)param_1 + iVar3) = 0;
  }
  else {
    param_1[2] = iVar3;
    if (*param_1 != 0) {
      *(undefined1 *)(*param_1 + iVar3) = 0;
    }
  }
  return iVar2;
}



// Function at 0x400d5640

undefined4 FUN_400d5640(undefined4 param_1,byte param_2)

{
  undefined4 uVar1;
  ushort auStack_22 [17];
  
  auStack_22[0] = (ushort)param_2;
  uVar1 = FUN_400d5584(param_1,auStack_22,1);
  return uVar1;
}



// Function at 0x400d5658

void FUN_400d5658(void)

{
  FUN_400d5554(1,DAT_400d0020);
  return;
}



// Function at 0x400d5668

void FUN_400d5668(void)

{
  FUN_400d5554(0,DAT_400d0020);
  return;
}



// Function at 0x400d5678

void FUN_400d5678(uint param_1,uint param_2)

{
  uint uVar1;
  int iStack_38;
  int iStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  
  uVar1 = 0x1fe << 0x20 - (0x20 - ((param_1 & 0xff ^ 0xffffffff) & 0x1f)) |
          DAT_400d0178 >> (param_1 & 0x1f);
  if ((param_1 & 0x20) != 0) {
    uVar1 = 0xff >> (param_1 & 0x1f);
  }
  if ((uVar1 & 1) != 0) {
    iStack_34 = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
    if ((param_1 & 0x20) == 0) {
      iStack_38 = iStack_34;
      iStack_34 = 0;
    }
    else {
      iStack_38 = 0;
    }
    uStack_30 = 0;
    uStack_2c = 0;
    uStack_28 = 0;
    memw();
    uStack_24 = *(uint *)(DAT_400d017c + ((param_1 & 0xff) + 0x20) * 4 + 8) >> 7 & 7;
    if ((param_2 & 0xff) < 0x20) {
      uStack_30 = param_2 & 3;
      if ((param_2 & 0x10) != 0) {
        uStack_30 = uStack_30 | 4;
      }
      uStack_2c = (uint)((param_2 & 4) != 0);
      if ((param_2 & 8) != 0) {
        uStack_28 = 1;
      }
    }
    FUN_400d7db0(&iStack_38);
  }
  return;
}



// Function at 0x400d5714

void FUN_400d5714(undefined1 param_1,undefined1 param_2)

{
  FUN_400d7b54(param_1,param_2);
  return;
}



// Function at 0x400d5724

void FUN_400d5724(char param_1,undefined4 param_2)

{
  int iStack_38;
  int iStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  iStack_34 = 1 << 0x20 - (0x20 - ((int)param_1 & 0x1fU));
  if (((int)param_1 & 0x20U) == 0) {
    iStack_38 = iStack_34;
    iStack_34 = 0;
  }
  else {
    iStack_38 = 0;
  }
  uStack_2c = 1;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_30 = param_2;
  FUN_400d7db0(&iStack_38);
  return;
}



// Function at 0x400d5758

undefined4 FUN_400d5758(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    if (-1 < *(char *)(param_1 + 6)) {
      (*DAT_400d021c)((int)*(char *)(param_1 + 6),0x100,0);
      if (*(char *)(param_1 + 4) == '\0') {
        uVar1 = 0x1d;
      }
      else if (*(char *)(param_1 + 4) == '\x01') {
        uVar1 = 0x5f;
      }
      else {
        uVar1 = 0;
      }
      (*DAT_400d0220)(0x30,uVar1,0);
      FUN_400d5724((int)*(char *)(param_1 + 6),1);
      *(undefined1 *)(param_1 + 6) = 0xff;
    }
    if (*(char *)(param_1 + 5) < 0) {
      uVar1 = 1;
    }
    else {
      (*DAT_400d021c)((int)*(char *)(param_1 + 5),0x100,0);
      if (*(char *)(param_1 + 4) == '\0') {
        uVar1 = 0x1e;
      }
      else if (*(char *)(param_1 + 4) == '\x01') {
        uVar1 = 0x60;
      }
      else {
        uVar1 = 0;
      }
      (*DAT_400d0220)(0x30,uVar1,0);
      FUN_400d5724((int)*(char *)(param_1 + 5),1);
      *(undefined1 *)(param_1 + 5) = 0xff;
      uVar1 = 1;
    }
  }
  return uVar1;
}



// Function at 0x400d5804

void FUN_400d5804(int *param_1)

{
  int iVar1;
  
  FUN_400d5758(param_1);
  iVar1 = *param_1;
  memw();
  memw();
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & DAT_400d0224;
  memw();
  memw();
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & DAT_400d0140;
  memw();
  memw();
  *(uint *)(*param_1 + 0x28) = *(uint *)(*param_1 + 0x28) & DAT_400d0228;
  memw();
  *(undefined4 *)(*param_1 + 0x24) = DAT_400d022c;
  if (param_1[5] != 0) {
    FUN_400e385c();
    param_1[5] = 0;
  }
  if (param_1[6] != 0) {
    func_0x4008a900();
    param_1[6] = 0;
  }
  if (param_1[8] != 0) {
    func_0x40088818();
    param_1[8] = 0;
  }
  if (param_1[9] != 0) {
    func_0x400899b0();
    param_1[9] = 0;
  }
  if (param_1[7] != 0) {
    func_0x400899b0();
    param_1[7] = 0;
  }
  param_1[10] = 0;
  return;
}



// Function at 0x400d5898

undefined4 FUN_400d5898(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  param_1 = param_1 & 0xff;
  if (param_1 < 2) {
    iVar2 = param_1 * 0x30 + DAT_400d0230;
    iVar3 = *(int *)(iVar2 + 0x2c);
    if (iVar3 == 0) {
      uVar1 = 0x101;
    }
    else {
      func_0x400896ec(iVar3,0xffffffff);
      FUN_400d5804(iVar2);
      iVar2 = *(int *)(DAT_400d0230 + param_1 * 0x30 + 0x2c);
      if (iVar2 == 0) {
        uVar1 = 0;
      }
      else {
        func_0x40089194(iVar2,0,0);
        uVar1 = 0;
      }
    }
  }
  else {
    uVar1 = 0x102;
  }
  return uVar1;
}



// Function at 0x400d58f0

undefined1 FUN_400d58f0(uint param_1)

{
  undefined1 uVar1;
  
  if ((param_1 & 0xff) < 2) {
    memw();
    uVar1 = *(undefined1 *)(DAT_400d0234 + (param_1 & 0xff) * 0xc);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



// Function at 0x400d5918

int FUN_400d5918(uint param_1,char param_2,char param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined4 local_3c;
  int iStack_38;
  int iStack_34;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  undefined2 uStack_2e;
  uint uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  undefined2 uStack_22;
  
  param_1 = param_1 & 0xff;
  if (param_1 < 2) {
    memw();
    if (*(int *)(DAT_400d0234 + param_1 * 0xc + 8) == 0) {
      uVar1 = func_0x400893a4(1);
      iVar2 = DAT_400d0234 + param_1 * 0xc;
      memw();
      *(undefined4 *)(iVar2 + 8) = uVar1;
      memw();
      if (*(int *)(iVar2 + 8) == 0) {
        return 0x101;
      }
    }
    memw();
    iVar2 = func_0x400896ec(*(undefined4 *)(DAT_400d0234 + param_1 * 0xc + 8),0xffffffff);
    if (iVar2 == 1) {
      memw();
      if (*(char *)(DAT_400d0234 + param_1 * 0xc) == '\0') {
        uVar4 = DAT_400d0238;
        if ((param_4 != 0) && (uVar4 = param_4, DAT_400d01e4 < param_4)) {
          uVar4 = DAT_400d01e4;
        }
        uStack_2e = 0;
        uStack_28 = 0;
        uStack_26 = 0;
        uStack_24 = 0;
        uStack_22 = 0;
        local_3c = 1;
        iStack_34 = (int)param_3;
        iStack_38 = (int)param_2;
        uStack_2f = 1;
        uStack_30 = 1;
        uStack_2c = uVar4;
        iVar2 = FUN_400d8978(param_1,&local_3c);
        if ((iVar2 == 0) && (iVar2 = FUN_400d8424(param_1,local_3c,0,0), iVar2 == 0)) {
          puVar3 = (undefined1 *)(DAT_400d0234 + param_1 * 0xc);
          memw();
          *puVar3 = 1;
          memw();
          *(uint *)(puVar3 + 4) = uVar4;
          FUN_400d8338(param_1,DAT_400d023c);
        }
        memw();
        func_0x40089194(*(undefined4 *)(DAT_400d0234 + param_1 * 0xc + 8),0,0);
      }
      else {
        iVar2 = -1;
      }
    }
    else {
      iVar2 = -1;
    }
  }
  else {
    iVar2 = 0x102;
  }
  return iVar2;
}



// Function at 0x400d5a50

int FUN_400d5a50(uint param_1)

{
  int iVar1;
  
  param_1 = param_1 & 0xff;
  if (param_1 < 2) {
    memw();
    if (*(int *)(DAT_400d0234 + param_1 * 0xc + 8) != 0) {
      memw();
      iVar1 = func_0x400896ec(*(undefined4 *)(DAT_400d0234 + param_1 * 0xc + 8),0xffffffff);
      if (iVar1 == 1) {
        memw();
        if (*(char *)(DAT_400d0234 + param_1 * 0xc) == '\0') {
          iVar1 = -1;
        }
        else {
          iVar1 = FUN_400d8178(param_1);
          if (iVar1 == 0) {
            memw();
            *(undefined1 *)(DAT_400d0234 + param_1 * 0xc) = 0;
          }
        }
        memw();
        func_0x40089194(*(undefined4 *)(DAT_400d0234 + param_1 * 0xc + 8),0,0);
        return iVar1;
      }
    }
    iVar1 = -1;
  }
  else {
    iVar1 = 0x102;
  }
  return iVar1;
}



// Function at 0x400d5af4

int FUN_400d5af4(uint param_1,uint param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_cc [168];
  int iStack_24;
  
  param_1 = param_1 & 0xff;
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  if (param_1 < 2) {
    memw();
    if (*(int *)(DAT_400d0234 + param_1 * 0xc + 8) != 0) {
      memw();
      iVar2 = func_0x400896ec(*(undefined4 *)(DAT_400d0234 + param_1 * 0xc + 8),0xffffffff);
      if (iVar2 == 1) {
        memw();
        if (*(char *)(DAT_400d0234 + param_1 * 0xc) == '\0') {
          iVar2 = -1;
        }
        else {
          func_0x40086818(auStack_cc,0,0xa8);
          iVar1 = FUN_400f7a5c(auStack_cc,0xa8);
          iVar2 = FUN_400d8c50();
          if ((((iVar2 == 0) && (iVar2 = FUN_400d8ce0(iVar1,(param_2 & 0x7f) << 1,1), iVar2 == 0))
              && ((param_4 == 0 || (iVar2 = FUN_400d8d44(iVar1,param_3,param_4,1), iVar2 == 0)))) &&
             (iVar2 = FUN_400d8c94(iVar1), iVar2 == 0)) {
            iVar2 = FUN_400d8f78(param_1,iVar1,param_5);
          }
          if (iVar1 != 0) {
            FUN_400f7a8c(iVar1);
          }
        }
        memw();
        func_0x40089194(*(undefined4 *)(DAT_400d0234 + param_1 * 0xc + 8),0,0);
        goto LAB_400d5b75;
      }
    }
    iVar2 = -1;
  }
  else {
    iVar2 = 0x102;
  }
LAB_400d5b75:
  memw();
  memw();
  if (iStack_24 != *DAT_400d0098) {
    iVar2 = func_0x400831d4();
    return iVar2;
  }
  return iVar2;
}



// Function at 0x400d5c14

undefined8
FUN_400d5c14(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 *param_6)

{
  uint uVar1;
  int iVar2;
  
  param_1 = param_1 & 0xff;
  uVar1 = param_2 & 0xffff;
  if (param_1 < 2) {
    memw();
    if (*(int *)(DAT_400d0234 + param_1 * 0xc + 8) != 0) {
      memw();
      iVar2 = func_0x400896ec(*(undefined4 *)(DAT_400d0234 + param_1 * 0xc + 8),0xffffffff);
      if (iVar2 == 1) {
        memw();
        if (*(char *)(DAT_400d0234 + param_1 * 0xc) == '\0') {
          iVar2 = -1;
        }
        else {
          iVar2 = FUN_400d91f4(param_1,param_2 & 0xff,param_3,param_4,param_5);
          if (iVar2 == 0) {
            *param_6 = param_4;
          }
          else {
            *param_6 = 0;
          }
        }
        uVar1 = param_1 * 0xc;
        memw();
        func_0x40089194(*(undefined4 *)(DAT_400d0234 + uVar1 + 8),0,0);
        goto LAB_400d5c81;
      }
    }
    iVar2 = -1;
  }
  else {
    iVar2 = 0x102;
  }
LAB_400d5c81:
  return CONCAT44(uVar1,iVar2);
}



// Function at 0x400d5cb0

int FUN_400d5cb0(uint param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 *param_8)

{
  int iVar1;
  
  param_1 = param_1 & 0xff;
  if (param_1 < 2) {
    memw();
    if (*(int *)(DAT_400d0234 + param_1 * 0xc + 8) != 0) {
      memw();
      iVar1 = func_0x400896ec(*(undefined4 *)(DAT_400d0234 + param_1 * 0xc + 8),0xffffffff);
      if (iVar1 == 1) {
        memw();
        if (*(char *)(DAT_400d0234 + param_1 * 0xc) == '\0') {
          iVar1 = -1;
        }
        else {
          iVar1 = FUN_400d9274(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
          if (iVar1 == 0) {
            *param_8 = param_6;
          }
          else {
            *param_8 = 0;
          }
        }
        memw();
        func_0x40089194(*(undefined4 *)(DAT_400d0234 + param_1 * 0xc + 8),0,0);
        return iVar1;
      }
    }
    iVar1 = -1;
  }
  else {
    iVar1 = 0x102;
  }
  return iVar1;
}



// Function at 0x400d5d58

undefined4 FUN_400d5d58(uint param_1,undefined4 param_2,byte param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  param_1 = param_1 & 0xff;
  uStack_30 = (uint)param_3;
  if (param_1 < 0x10 && uStack_30 < 0x15) {
    uVar3 = param_1 >> 1 & 3;
    uStack_24 = 0;
    uStack_34 = param_1 >> 3;
    uStack_2c = uVar3;
    uStack_28 = param_2;
    iVar2 = FUN_400d9910(&uStack_34);
    if (iVar2 == 0) {
      *(byte *)(DAT_400d0240 + param_1) = param_3;
      uVar1 = FUN_400d9ed8(param_1 >> 3,uVar3);
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



// Function at 0x400d5dbc

void FUN_400d5dbc(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_1 & 0xff;
  if (uVar1 < 0x10) {
    iVar2 = 1 << 0x20 - (0x20 - (*(byte *)(DAT_400d0240 + uVar1) & 0x1f));
    if (iVar2 + -1 == param_2 && iVar2 != 2) {
      param_2 = iVar2;
    }
    FUN_400d9d8c(uVar1 >> 3,param_1 & 7,param_2);
    FUN_400d9a24(uVar1 >> 3,param_1 & 7);
  }
  return;
}



// Function at 0x400d5e10

void FUN_400d5e10(uint param_1,uint param_2)

{
  uint uVar1;
  uint local_40;
  uint uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uVar1 = param_2 & 0xff;
  if (uVar1 < 0x10) {
    uStack_2c = FUN_400d9e3c(uVar1 >> 3,param_2 & 7);
    uStack_34 = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    local_40 = param_1 & 0xff;
    uStack_3c = uVar1 >> 3;
    uStack_38 = param_2 & 7;
    uStack_30 = uVar1 >> 1 & 3;
    FUN_400d9bd8(&local_40);
  }
  return;
}



// Function at 0x400d5e4c

void FUN_400d5e4c(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  (*DAT_400d021c)(param_1,param_2,param_3,param_4);
  return;
}



// Function at 0x400d5e64

void FUN_400d5e64(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  (*DAT_400d021c)(param_1,0x100,param_2,param_3);
  return;
}



// Function at 0x400d5e7c

void FUN_400d5e7c(undefined1 param_1,char param_2,undefined1 param_3)

{
  undefined4 uVar1;
  
  if (param_2 == '\0') {
    uVar1 = 0x30;
  }
  else {
    uVar1 = 0x38;
  }
  (*DAT_400d0220)(uVar1,param_1,param_3);
  return;
}



// Function at 0x400d5e9c

void FUN_400d5e9c(void)

{
  func_0x40088b04();
  return;
}



// Function at 0x400d5ea4

undefined4
FUN_400d5ea4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,uint param_7)

{
  undefined4 uVar1;
  
  if (param_7 < 2) {
    uVar1 = func_0x40089f48(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else {
    uVar1 = func_0x40089f48(param_1,param_2,param_3,param_4,param_5,param_6,DAT_400d0140);
  }
  return uVar1;
}



// Function at 0x400d5ecc

undefined4 FUN_400d5ecc(void)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar2 = func_0x40084ac8();
  uVar1 = (*DAT_400d0248)((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),DAT_400d0244,DAT_400d0028);
  return uVar1;
}



// Function at 0x400d5ee4

void FUN_400d5ee4(undefined4 param_1)

{
  func_0x4008a9fc(param_1);
  return;
}



// Function at 0x400d5ef0

/* WARNING: Removing unreachable block (ram,0x400d5f2f) */
/* WARNING: Removing unreachable block (ram,0x400d5f11) */
/* WARNING: Removing unreachable block (ram,0x400d5f38) */

void FUN_400d5ef0(uint param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar1 = func_0x40084ac8();
  if (param_1 != 0) {
    if (uVar1 + param_1 < uVar1) {
      do {
        uVar2 = func_0x40084ac8();
      } while (uVar1 + param_1 < uVar2);
    }
    do {
      uVar2 = func_0x40084ac8();
    } while (uVar2 < uVar1 + param_1);
  }
  return;
}



// Function at 0x400d5f40

void FUN_400d5f40(void)

{
  int iVar1;
  undefined4 uVar2;
  int aiStack_24 [9];
  
  iVar1 = FUN_400f79d8();
  if (iVar1 == 0) {
    uVar2 = FUN_400dc960();
    iVar1 = FUN_400dcb90(uVar2,aiStack_24);
    if ((iVar1 == 0) && (aiStack_24[0] == 1)) {
      iVar1 = FUN_400f79d0();
      if (iVar1 == 0) {
        FUN_400dcb84();
      }
      else {
        FUN_400dcb78();
      }
    }
  }
  FUN_400d72e4(0xf0);
  FUN_400f91d0(DAT_400d024c,1);
  iVar1 = FUN_400ddb6c();
  if (((iVar1 + DAT_400d0250 == 0 || iVar1 + DAT_400d0254 == 0) &&
      (iVar1 = FUN_400dd700(1,2,0), iVar1 != 0)) &&
     (iVar1 = FUN_400dd7e4(iVar1,0,*(undefined4 *)(iVar1 + 0x10)), iVar1 == 0)) {
    FUN_400ddb6c();
  }
  iVar1 = FUN_400f7a54();
  if (iVar1 == 0) {
    FUN_400e42b8(3);
  }
  FUN_400f79c8();
  FUN_400f79c0();
  return;
}



// Function at 0x400d5fd8

void FUN_400d5fd8(int *param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 local_60 [24];
  
  if (param_1 != (int *)0x0) {
    if (0x40 < param_4) {
      param_4 = 0x40;
    }
    uVar2 = param_4 + 3 >> 2;
    func_0x40086818(local_60,0,0x40);
    if (param_2 == 0) {
      func_0x40086818(local_60,0xff,param_4);
    }
    else {
      func_0x400866b8(local_60,param_2,param_4);
    }
    uVar3 = DAT_400d025c;
    memw();
    uVar1 = param_4 * 8 - 1 & DAT_400d0258;
    memw();
    *(uint *)(*param_1 + 0x28) = *(uint *)(*param_1 + 0x28) & DAT_400d025c | uVar1;
    memw();
    memw();
    *(uint *)(*param_1 + 0x2c) = *(uint *)(*param_1 + 0x2c) & uVar3 | uVar1;
    for (uVar3 = 0; uVar3 < uVar2; uVar3 = uVar3 + 1) {
      memw();
      *(undefined4 *)(*param_1 + (uVar3 + 0x20) * 4) = local_60[uVar3];
    }
    memw();
    memw();
    *(uint *)*param_1 = *(uint *)*param_1 | DAT_400d0260;
    do {
      memw();
    } while ((*(uint *)*param_1 & 0x40000) != 0);
    if (param_3 != 0) {
      for (uVar3 = 0; uVar3 < uVar2; uVar3 = uVar3 + 1) {
        memw();
        local_60[uVar3] = *(undefined4 *)(*param_1 + (uVar3 + 0x20) * 4);
      }
      func_0x400866b8(param_3,local_60,param_4);
    }
  }
  return;
}



// Function at 0x400d60b4

void FUN_400d60b4(int param_1,char param_2)

{
  if (param_1 != 0) {
    if (param_2 < '\0') {
      if (*(char *)(param_1 + 8) == '\x02') {
        param_2 = '\x0e';
      }
      else if (*(char *)(param_1 + 8) == '\x03') {
        param_2 = '\x12';
      }
      else {
        param_2 = '\x06';
      }
    }
    FUN_400d5e64(param_2,0);
    FUN_400d5678(param_2,1);
  }
  return;
}



// Function at 0x400d60f8

void FUN_400d60f8(int param_1,char param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  if (param_1 != 0) {
    if (param_2 < '\0') {
      if (*(char *)(param_1 + 8) == '\x02') {
        param_2 = '\f';
      }
      else if (*(char *)(param_1 + 8) == '\x03') {
        param_2 = '\x13';
      }
      else {
        param_2 = '\a';
      }
    }
    cVar1 = *(char *)(param_1 + 8);
    if (cVar1 == '\0') {
      uVar2 = 1;
    }
    else if (cVar1 == '\x01') {
      uVar2 = 1;
    }
    else if (cVar1 == '\x02') {
      uVar2 = 9;
    }
    else if (cVar1 == '\x03') {
      uVar2 = 0x40;
    }
    else {
      uVar2 = 0;
    }
    FUN_400d5e7c(uVar2,0);
    FUN_400d5678(param_2,1);
  }
  return;
}



// Function at 0x400d6158

void FUN_400d6158(int param_1,char param_2)

{
  if (param_1 != 0) {
    if (param_2 < '\0') {
      if (*(char *)(param_1 + 8) == '\x02') {
        param_2 = '\r';
      }
      else if (*(char *)(param_1 + 8) == '\x03') {
        param_2 = '\x17';
      }
      else {
        param_2 = '\b';
      }
    }
    FUN_400d5e64(param_2,0);
    FUN_400d5678(param_2,1);
  }
  return;
}



// Function at 0x400d619c

void FUN_400d619c(int param_1,char param_2)

{
  if (param_1 != 0) {
    if (param_2 < '\0') {
      if (*(char *)(param_1 + 8) == '\x02') {
        param_2 = '\x0f';
      }
      else if (*(char *)(param_1 + 8) == '\x03') {
        param_2 = '\x05';
      }
      else {
        param_2 = '\v';
      }
    }
    FUN_400d5e64(param_2,0);
    FUN_400d5678(param_2,1);
  }
  return;
}



// Function at 0x400d61e0

void FUN_400d61e0(int *param_1,uint param_2)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    do {
      iVar1 = func_0x400896ec(param_1[1],0xffffffff);
    } while (iVar1 != 1);
    memw();
    memw();
    *(uint *)(*param_1 + 0x34) = *(uint *)(*param_1 + 0x34) & (param_2 & 7 ^ 0xffffffff);
    func_0x40089194(param_1[1],0,0);
  }
  return;
}



// Function at 0x400d6218

void FUN_400d6218(int param_1,uint param_2,char param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  param_2 = param_2 & 0xff;
  if ((param_1 != 0) && (param_2 < 3)) {
    if (param_3 < '\0') {
      if (*(char *)(param_1 + 8) == '\x02') {
        param_3 = '\x0f';
        param_2 = 0;
      }
      else if (*(char *)(param_1 + 8) == '\x03') {
        param_3 = '\x05';
        param_2 = 0;
      }
      else {
        param_3 = '\v';
        param_2 = 0;
      }
    }
    FUN_400d5678(param_3,3);
    cVar1 = *(char *)(param_1 + 8);
    if (cVar1 == '\0') {
      if (param_2 == 0) {
        uVar2 = 5;
      }
      else if (param_2 == 1) {
        uVar2 = 6;
      }
      else if (param_2 == 2) {
        uVar2 = 7;
      }
      else {
        uVar2 = 5;
      }
    }
    else if (cVar1 == '\x01') {
      if (param_2 == 0) {
        uVar2 = 5;
      }
      else if (param_2 == 1) {
        uVar2 = 6;
      }
      else if (param_2 == 2) {
        uVar2 = 7;
      }
      else {
        uVar2 = 5;
      }
    }
    else if (cVar1 == '\x02') {
      if (param_2 == 0) {
        uVar2 = 0xb;
      }
      else if (param_2 == 1) {
        uVar2 = 0x3d;
      }
      else if (param_2 == 2) {
        uVar2 = 0x3e;
      }
      else {
        uVar2 = 0xb;
      }
    }
    else if (cVar1 == '\x03') {
      if (param_2 == 0) {
        uVar2 = 0x44;
      }
      else if (param_2 == 1) {
        uVar2 = 0x45;
      }
      else if (param_2 == 2) {
        uVar2 = 0x46;
      }
      else {
        uVar2 = 0x44;
      }
    }
    else {
      uVar2 = 0;
    }
    FUN_400d5e4c(param_3,uVar2,0);
    FUN_400d61e0(param_1,1 << 0x20 - (0x20 - (param_2 & 0x1f)) & 0xff);
  }
  return;
}



// Function at 0x400d630c

void FUN_400d630c(int *param_1)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    do {
      iVar1 = func_0x400896ec(param_1[1],0xffffffff);
    } while (iVar1 != 1);
    memw();
    memw();
    *(uint *)(*param_1 + 0x1c) = *(uint *)(*param_1 + 0x1c) | 0x20;
    memw();
    memw();
    *(uint *)(*param_1 + 0x1c) = *(uint *)(*param_1 + 0x1c) | 0x10;
    func_0x40089194(param_1[1],0,0);
  }
  return;
}



// Function at 0x400d634c

void FUN_400d634c(int *param_1)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    do {
      iVar1 = func_0x400896ec(param_1[1],0xffffffff);
    } while (iVar1 != 1);
    memw();
    memw();
    *(uint *)(*param_1 + 0x1c) = *(uint *)(*param_1 + 0x1c) & 0xffffffdf;
    memw();
    memw();
    *(uint *)(*param_1 + 0x1c) = *(uint *)(*param_1 + 0x1c) & 0xffffffef;
    func_0x40089194(param_1[1],0,0);
  }
  return;
}



// Function at 0x400d6390

void FUN_400d6390(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    FUN_400d7274(param_1,PTR_LAB_400d0264);
    do {
      iVar1 = func_0x400896ec(*(undefined4 *)(param_1 + 4),0xffffffff);
    } while (iVar1 != 1);
    FUN_400f79e0(param_1);
    func_0x40089194(*(undefined4 *)(param_1 + 4),0,0);
  }
  return;
}



// Function at 0x400d63bc

void FUN_400d63bc(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  
  if (param_1 != 0) {
    do {
      iVar1 = func_0x400896ec(*(undefined4 *)(param_1 + 4),0xffffffff);
    } while (iVar1 != 1);
    while (param_4 != 0) {
      if (param_4 < 0x41) {
        FUN_400d5fd8(param_1,param_2,param_3,param_4);
        param_4 = 0;
      }
      else {
        FUN_400d5fd8(param_1,param_2,param_3,0x40);
        param_4 = param_4 - 0x40;
        if (param_2 != 0) {
          param_2 = param_2 + 0x40;
        }
        if (param_3 != 0) {
          param_3 = param_3 + 0x40;
        }
      }
    }
    func_0x40089194(*(undefined4 *)(param_1 + 4),0,0);
  }
  return;
}



// Function at 0x400d6418

void FUN_400d6418(int *param_1,undefined4 param_2,char param_3,char param_4)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    do {
      iVar1 = func_0x400896ec(param_1[1],0xffffffff);
    } while (iVar1 != 1);
    memw();
    *(undefined4 *)(*param_1 + 0x18) = param_2;
    if (param_3 == '\x02') {
      memw();
      memw();
      *(uint *)(*param_1 + 0x34) = *(uint *)(*param_1 + 0x34) | DAT_400d026c;
      memw();
      memw();
      *(uint *)(*param_1 + 0x1c) = *(uint *)(*param_1 + 0x1c) | 0x80;
    }
    else if (param_3 == '\x03') {
      memw();
      memw();
      *(uint *)(*param_1 + 0x34) = *(uint *)(*param_1 + 0x34) | DAT_400d026c;
      memw();
      memw();
      *(uint *)(*param_1 + 0x1c) = *(uint *)(*param_1 + 0x1c) & 0xffffff7f;
    }
    else if (param_3 == '\x01') {
      memw();
      memw();
      *(uint *)(*param_1 + 0x34) = *(uint *)(*param_1 + 0x34) & DAT_400d0268;
      memw();
      memw();
      *(uint *)(*param_1 + 0x1c) = *(uint *)(*param_1 + 0x1c) | 0x80;
    }
    else {
      memw();
      memw();
      *(uint *)(*param_1 + 0x34) = *(uint *)(*param_1 + 0x34) & DAT_400d0268;
      memw();
      memw();
      *(uint *)(*param_1 + 0x1c) = *(uint *)(*param_1 + 0x1c) & 0xffffff7f;
    }
    if (param_4 == '\x01') {
      memw();
      memw();
      *(uint *)(*param_1 + 8) = *(uint *)(*param_1 + 8) & DAT_400d0270;
      memw();
      memw();
      *(uint *)(*param_1 + 8) = *(uint *)(*param_1 + 8) & DAT_400d0274;
    }
    else if (param_4 == '\0') {
      memw();
      memw();
      *(uint *)(*param_1 + 8) = *(uint *)(*param_1 + 8) | DAT_400d0278;
      memw();
      memw();
      *(uint *)(*param_1 + 8) = *(uint *)(*param_1 + 8) | DAT_400d027c;
    }
  }
  return;
}



// Function at 0x400d6540

void FUN_400d6540(int param_1)

{
  if (param_1 != 0) {
    func_0x40089194(*(undefined4 *)(param_1 + 4),0,0);
  }
  return;
}



// Function at 0x400d6554

void FUN_400d6554(int *param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_24 [9];
  
  if (param_1 != (int *)0x0) {
    uVar5 = param_4 >> 2;
    if ((param_4 & 3) != 0) {
      uVar5 = uVar5 + 1;
    }
    for (; uVar2 = DAT_400d025c, param_4 != 0; param_4 = param_4 - uVar4) {
      uVar4 = (param_4 < 0x40) * param_4 + (uint)(param_4 >= 0x40) * 0x40;
      uVar3 = (uVar5 < 0x10) * uVar5 + (uint)(uVar5 >= 0x10) * 0x10;
      memw();
      uVar1 = uVar4 * 8 - 1 & DAT_400d0258;
      memw();
      *(uint *)(*param_1 + 0x28) = *(uint *)(*param_1 + 0x28) & DAT_400d025c | uVar1;
      memw();
      memw();
      *(uint *)(*param_1 + 0x2c) = *(uint *)(*param_1 + 0x2c) & uVar2 | uVar1;
      if (param_2 == 0) {
        for (uVar2 = 0; uVar2 < uVar3; uVar2 = uVar2 + 1) {
          memw();
          *(undefined4 *)(*param_1 + (uVar2 + 0x20) * 4) = 0xffffffff;
        }
      }
      else {
        for (uVar2 = 0; uVar2 < uVar3; uVar2 = uVar2 + 1) {
          memw();
          *(undefined4 *)(*param_1 + (uVar2 + 0x20) * 4) = *(undefined4 *)(param_2 + uVar2 * 4);
        }
      }
      memw();
      memw();
      *(uint *)*param_1 = *(uint *)*param_1 | DAT_400d0260;
      do {
        memw();
      } while ((*(uint *)*param_1 & 0x40000) != 0);
      if (param_3 != 0) {
        uVar2 = uVar4 & 3;
        if (uVar2 == 0) {
          for (; uVar2 < uVar3; uVar2 = uVar2 + 1) {
            memw();
            *(undefined4 *)(param_3 + uVar2 * 4) = *(undefined4 *)(*param_1 + (uVar2 + 0x20) * 4);
          }
        }
        else {
          for (uVar1 = 0; uVar1 < uVar3 - 1; uVar1 = uVar1 + 1) {
            memw();
            *(undefined4 *)(param_3 + uVar1 * 4) = *(undefined4 *)(*param_1 + (uVar1 + 0x20) * 4);
          }
          memw();
          local_24[0] = *(undefined4 *)(*param_1 + (uVar3 + 0x1f) * 4);
          iVar6 = uVar3 + DAT_400d0280;
          for (uVar1 = 0; uVar1 < uVar2; uVar1 = uVar1 + 1) {
            *(undefined1 *)(param_3 + iVar6 * 4 + uVar1) = *(undefined1 *)((int)local_24 + uVar1);
          }
        }
      }
      if (param_2 != 0) {
        param_2 = param_2 + uVar3 * 4;
      }
      if (param_3 != 0) {
        param_3 = param_3 + uVar3 * 4;
      }
      uVar5 = uVar5 - uVar3;
    }
  }
  return;
}



// Function at 0x400d6698

uint FUN_400d6698(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  
  uVar1 = FUN_400d7414();
  uVar9 = DAT_400d0284;
  if ((param_1 < uVar1) &&
     (uVar9 = DAT_400d0288,
     uVar1 / (((DAT_400d0288 >> 0x12 & 0x1fff) + 1) * ((DAT_400d0288 >> 0xc & 0x3f) + 1)) <= param_1
     )) {
    uVar9 = 0;
    uVar8 = 0;
    for (uVar7 = 1; uVar7 < 0x40; uVar7 = uVar7 + 1 & 0xff) {
      uVar5 = (uVar7 & 0x3f) << 0xc;
      uVar10 = uVar9;
      cVar3 = -2;
      while (cVar6 = cVar3 + '\x01', uVar9 = uVar10, cVar3 < '\x02') {
        uVar9 = ((int)cVar6 + (uVar1 / ((uVar5 >> 0xc & 0x3f) + 1)) / param_1) - 1;
        if (DAT_400d028c < (int)uVar9) {
          uVar9 = uVar5 | DAT_400d0290;
        }
        else if ((int)uVar9 < 1) {
          uVar9 = uVar5 & DAT_400d0294;
        }
        else {
          uVar9 = uVar5 & DAT_400d0294 | (uVar9 & 0x1fff) << 0x12;
        }
        uVar4 = (uVar9 >> 0xc & 0x3f) + 1;
        uVar5 = uVar9 & 0xffffffc0 | uVar4 >> 1;
        param_2 = uVar1 / (uVar4 * ((uVar9 >> 0x12 & 0x1fff) + 1));
        uVar9 = uVar5;
        if (param_2 == param_1) break;
        cVar3 = cVar6;
        if ((int)param_2 < (int)param_1) {
          iVar2 = param_1 - param_2;
          if (iVar2 < 1) {
            iVar2 = -iVar2;
          }
          iVar11 = param_1 - uVar8;
          if (iVar11 < 1) {
            iVar11 = -iVar11;
          }
          if (iVar2 < iVar11) {
            uVar8 = param_2;
            uVar10 = uVar5;
          }
        }
      }
      if (param_1 == param_2) {
        return uVar9;
      }
    }
  }
  return uVar9;
}



// Function at 0x400d6814

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_400d6814(byte param_1)

{
  bool bVar1;
  uint *puVar2;
  
  do {
    memw();
    memw();
    memw();
  } while ((*(uint *)(DAT_400d02a4 + 0x1c) >> 0x10 & 0xff) == 0x80);
  puVar2 = DAT_400d029c;
  if (DAT_400d02a4 != DAT_400d0298) {
    puVar2 = DAT_400d02a0;
  }
  bVar1 = false;
  while( true ) {
    if (bVar1) {
      return;
    }
    if ((uint)((int)puVar2 + DAT_400d02a8) <= DAT_400d02ac) break;
    memw();
    *puVar2 = (uint)param_1;
    bVar1 = true;
  }
  func_0x4008dacc(DAT_400d02b8,0xf9,DAT_400d02b4,DAT_400d02b0);
  return;
}



// Function at 0x400d6878

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_400d6878(byte param_1)

{
  bool bVar1;
  uint *puVar2;
  
  do {
    memw();
    memw();
    memw();
  } while ((*(uint *)(DAT_400d02c0 + 0x1c) >> 0x10 & 0xff) == 0x80);
  puVar2 = DAT_400d029c;
  if ((DAT_400d02c0 != DAT_400d0298) && (puVar2 = DAT_400d02a0, DAT_400d02c0 != DAT_400d02a4)) {
    puVar2 = DAT_400d02bc;
  }
  bVar1 = false;
  while( true ) {
    if (bVar1) {
      return;
    }
    if ((uint)((int)puVar2 + DAT_400d02a8) <= DAT_400d02ac) break;
    memw();
    *puVar2 = (uint)param_1;
    bVar1 = true;
  }
  func_0x4008dacc(DAT_400d02b8,0xf9,DAT_400d02b4,DAT_400d02b0);
  return;
}



// Function at 0x400d68e8

undefined4 * FUN_400d68e8(undefined4 *param_1,char param_2,char param_3,char param_4,char param_5)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  if (param_1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  do {
    iVar1 = func_0x400896ec(*param_1,0xffffffff);
  } while (iVar1 != 1);
  if (-1 < param_3) {
    puVar3 = *(uint **)(DAT_400d02c4 + param_3 * 4);
    if (DAT_400d02ac < (uint)((int)puVar3 + DAT_400d02a8)) {
      memw();
      memw();
      *puVar3 = *puVar3 & DAT_400d02d4 | DAT_400d01e0;
      (*DAT_400d02dc)((int)param_3,0x100,0);
      goto LAB_400d6949;
    }
    func_0x4008dacc(DAT_400d02d0,0x27d,DAT_400d02cc,DAT_400d02c8);
LAB_400d6a4f:
    func_0x4008dacc(DAT_400d02d0,0x27d,DAT_400d02cc,DAT_400d02c8);
LAB_400d6a5e:
    func_0x4008dacc(DAT_400d02d0,0x27d,DAT_400d02cc,DAT_400d02c8);
LAB_400d6a6d:
    func_0x4008dacc(DAT_400d02d0,0x27d,DAT_400d02cc,DAT_400d02c8);
    uVar2 = FUN_400d7414();
    if (uVar2 <= DAT_400d02e8) {
      param_1 = (undefined4 *)
                ((int)param_1 * (0x50 / (uint)((ulonglong)uVar2 * (ulonglong)DAT_400d02e4 >> 0x32)))
      ;
    }
    return param_1;
  }
LAB_400d6949:
  if (-1 < param_2) {
    puVar3 = *(uint **)(DAT_400d02c4 + param_2 * 4);
    if ((uint)((int)puVar3 + DAT_400d02a8) <= DAT_400d02ac) goto LAB_400d6a4f;
    memw();
    memw();
    *puVar3 = *puVar3 & DAT_400d02d4 | DAT_400d01e0;
    (*DAT_400d02e0)(0x30,*(uint *)(DAT_400d02d8 + (uint)*(byte *)(param_1 + 1) * 0x18 + 4) >> 0x14,0
                   );
  }
  if (-1 < param_5) {
    puVar3 = *(uint **)(DAT_400d02c4 + param_5 * 4);
    if ((uint)((int)puVar3 + DAT_400d02a8) <= DAT_400d02ac) goto LAB_400d6a5e;
    memw();
    memw();
    *puVar3 = *puVar3 & DAT_400d02d4 | DAT_400d01e0;
    (*DAT_400d02dc)((int)param_5,0x100,0);
  }
  if (-1 < param_4) {
    puVar3 = *(uint **)(DAT_400d02c4 + param_4 * 4);
    if ((uint)((int)puVar3 + DAT_400d02a8) <= DAT_400d02ac) goto LAB_400d6a6d;
    memw();
    memw();
    *puVar3 = *puVar3 & DAT_400d02d4 | DAT_400d01e0;
    (*DAT_400d02e0)(0x30,*(uint *)(DAT_400d02d8 + (uint)*(byte *)(param_1 + 1) * 0x18 + 0xc) >> 0x14
                    ,0);
  }
  func_0x40089194(*param_1,0,0);
  return param_1;
}



// Function at 0x400d6a7c

int FUN_400d6a7c(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_400d7414();
  if (uVar1 <= DAT_400d02e8) {
    param_1 = param_1 * (0x50 / (uint)((ulonglong)uVar1 * (ulonglong)DAT_400d02e4 >> 0x32));
  }
  return param_1;
}



// Function at 0x400d6a9c

undefined4 FUN_400d6a9c(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_400dc704(*(undefined1 *)(param_1 + 4));
  }
  return uVar1;
}



// Function at 0x400d6ab4

bool FUN_400d6ab4(undefined4 *param_1,undefined1 param_2)

{
  bool bVar1;
  int iVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    bVar1 = false;
  }
  else {
    do {
      iVar2 = func_0x400896ec(*param_1,0xffffffff);
    } while (iVar2 != 1);
    iVar2 = FUN_400dc7ec(*(undefined1 *)(param_1 + 1),param_2);
    bVar1 = iVar2 == 0;
    func_0x40089194(*param_1,0,0,0);
  }
  return bVar1;
}



// Function at 0x400d6aec

bool FUN_400d6aec(undefined4 *param_1,undefined1 param_2)

{
  bool bVar1;
  int iVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    bVar1 = false;
  }
  else {
    do {
      iVar2 = func_0x400896ec(*param_1,0xffffffff);
    } while (iVar2 != 1);
    iVar2 = FUN_400dc744(*(undefined1 *)(param_1 + 1),param_2);
    bVar1 = iVar2 == 0;
    func_0x40089194(*param_1,0,0,0);
  }
  return bVar1;
}



// Function at 0x400d6b24

void FUN_400d6b24(undefined4 *param_1)

{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    do {
      iVar1 = func_0x400896ec(*param_1,0xffffffff);
    } while (iVar1 != 1);
    FUN_400dc3cc(*(undefined1 *)(param_1 + 1));
    func_0x40089194(*param_1,0,0);
  }
  return;
}



// Function at 0x400d6b48

int FUN_400d6b48(undefined4 *param_1)

{
  int iVar1;
  int aiStack_24 [9];
  
  if (param_1 == (undefined4 *)0x0) {
    aiStack_24[0] = 0;
  }
  else {
    do {
      iVar1 = func_0x400896ec(*param_1,0xffffffff);
    } while (iVar1 != 1);
    FUN_400dc100(*(undefined1 *)(param_1 + 1),aiStack_24);
    if (*(char *)((int)param_1 + 5) != '\0') {
      aiStack_24[0] = aiStack_24[0] + 1;
    }
    func_0x40089194(*param_1,0,0);
  }
  return aiStack_24[0];
}



// Function at 0x400d6b84

int FUN_400d6b84(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iStack_28;
  uint uStack_24;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar2 = 0;
  }
  else {
    do {
      iVar2 = func_0x400896ec(*param_1,0xffffffff);
    } while (iVar2 != 1);
    cVar1 = *(char *)(param_1 + 1);
    iVar2 = DAT_400d0298;
    if ((cVar1 != '\0') && (iVar2 = DAT_400d02a4, cVar1 != '\x01')) {
      iVar2 = DAT_400d02c0;
    }
    memw();
    uStack_24 = *(uint *)(iVar2 + 0x1c);
    memw();
    memw();
    iVar2 = 0x80 - (uStack_24 >> 0x10 & 0xff);
    iStack_28 = 0;
    iVar3 = FUN_400dc17c(cVar1,&iStack_28);
    if (iVar3 == 0) {
      iVar2 = iVar2 + iStack_28;
    }
    func_0x40089194(*param_1,0,0);
  }
  return iVar2;
}



// Function at 0x400d6c8c

undefined1 FUN_400d6c8c(undefined4 *param_1)

{
  int iVar1;
  undefined1 auStack_21 [33];
  
  if (param_1 == (undefined4 *)0x0) {
    auStack_21[0] = 0;
  }
  else {
    auStack_21[0] = 0;
    do {
      iVar1 = func_0x400896ec(*param_1,0xffffffff);
    } while (iVar1 != 1);
    if (*(char *)((int)param_1 + 5) == '\0') {
      iVar1 = FUN_400dbfa4(*(undefined1 *)(param_1 + 1),auStack_21,1,0x14);
      if (iVar1 < 1) {
        auStack_21[0] = 0;
      }
      else {
        *(undefined1 *)((int)param_1 + 5) = 1;
        *(undefined1 *)((int)param_1 + 6) = auStack_21[0];
      }
    }
    else {
      auStack_21[0] = *(undefined1 *)((int)param_1 + 6);
    }
    func_0x40089194(*param_1,0,0);
  }
  return auStack_21[0];
}



// Function at 0x400d6cec

void FUN_400d6cec(undefined4 *param_1,undefined1 param_2)

{
  int iVar1;
  undefined1 auStack_24 [36];
  
  auStack_24[0] = param_2;
  if (param_1 != (undefined4 *)0x0) {
    do {
      iVar1 = func_0x400896ec(*param_1,0xffffffff);
    } while (iVar1 != 1);
    FUN_400dbf18(*(undefined1 *)(param_1 + 1),auStack_24,1);
    func_0x40089194(*param_1,0,0);
  }
  return;
}



// Function at 0x400d6d18

void FUN_400d6d18(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((param_1 != (undefined4 *)0x0 && param_2 != 0) && (param_3 != 0)) {
    do {
      iVar1 = func_0x400896ec(*param_1,0xffffffff);
    } while (iVar1 != 1);
    FUN_400dbf18(*(undefined1 *)(param_1 + 1),param_2,param_3);
    func_0x40089194(*param_1,0,0);
  }
  return;
}



// Function at 0x400d6d58

/* WARNING: Control flow encountered bad instruction data */

void FUN_400d6d58(undefined4 *param_1,char param_2)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  
  if (param_1 != (undefined4 *)0x0) {
    do {
      iVar2 = func_0x400896ec(*param_1,0xffffffff);
    } while (iVar2 != 1);
    do {
      cVar1 = *(char *)(param_1 + 1);
      iVar2 = DAT_400d0298;
      if ((cVar1 != '\0') && (iVar2 = DAT_400d02a4, cVar1 != '\x01')) {
        iVar2 = DAT_400d02c0;
      }
      memw();
      memw();
      memw();
      if ((*(uint *)(iVar2 + 0x1c) >> 0x10 & 0xff) == 0) {
        memw();
        if ((*(uint *)(iVar2 + 0x1c) >> 0x18 & 0xf) == 0) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
      }
      else {
        bVar3 = false;
      }
    } while (!bVar3);
    if ((param_2 == '\0') && (iVar2 = FUN_400dc204(cVar1), iVar2 != 0)) {
      func_0x40088988(iVar2,DAT_400d02f8,0x1c7,DAT_400d02f4,DAT_400d02f0);
      cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    func_0x40089194(*param_1,0,0);
  }
  return;
}



// Function at 0x400d6de0

void FUN_400d6de0(undefined4 param_1)

{
  FUN_400d6d58(param_1,1);
  return;
}



// Function at 0x400d6df0

int FUN_400d6df0(uint param_1,undefined4 param_2,uint param_3,char param_4,char param_5,
                undefined2 param_6,undefined2 param_7,char param_8,undefined1 param_9)

{
  int iVar1;
  int iVar2;
  undefined4 uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  undefined1 uStack_28;
  undefined4 uStack_24;
  
  param_1 = param_1 & 0xff;
  if (2 < param_1) {
    return 0;
  }
  iVar1 = param_1 * 0xc + DAT_400d02fc;
  iVar2 = FUN_400dc704(param_1);
  if (iVar2 != 0) {
    FUN_400d6b24(iVar1);
  }
  if (*(int *)(DAT_400d02fc + param_1 * 0xc) == 0) {
    iVar2 = func_0x400893a4(1);
    *(int *)(DAT_400d02fc + param_1 * 0xc) = iVar2;
    if (iVar2 == 0) {
      return 0;
    }
  }
  do {
    iVar2 = func_0x400896ec(*(undefined4 *)(DAT_400d02fc + param_1 * 0xc),0xffffffff);
  } while (iVar2 != 1);
  uStack_38 = param_3 >> 2 & 3;
  uStack_34 = param_3 & 3;
  uStack_30 = param_3 >> 4 & 3;
  uStack_2c = 0;
  uStack_28 = param_9;
  uStack_24 = 0;
  uStack_3c = FUN_400d6a7c(param_2);
  iVar2 = FUN_400dc4a0(param_1,param_6,param_7,0x14,param_1 * 0xc + DAT_400d02fc + 8,0);
  if (iVar2 == 0) {
    iVar2 = FUN_400dbba4(param_1,&uStack_3c);
    if (iVar2 != 0) goto LAB_400d6f27;
    iVar2 = FUN_400db8e4(param_1,(int)param_5,(int)param_4,0xffffffff);
    if (iVar2 == 0) {
      if ((param_8 == '\0') || (iVar2 = FUN_400db4ac(param_1,0x24), iVar2 == 0)) {
        func_0x40089194(*(undefined4 *)(DAT_400d02fc + param_1 * 0xc),0,0);
        FUN_400d6de0(iVar1);
        return iVar1;
      }
      goto LAB_400d6f45;
    }
  }
  else {
    iVar2 = func_0x40088988(iVar2,DAT_400d02f8,0xd5,DAT_400d0304,DAT_400d0300);
LAB_400d6f27:
    iVar2 = func_0x40088988(iVar2,DAT_400d02f8,0xd6,DAT_400d0304,DAT_400d0308);
  }
  iVar2 = func_0x40088988(iVar2,DAT_400d02f8,0xd7,DAT_400d0304,DAT_400d030c);
LAB_400d6f45:
  func_0x40088988(iVar2,DAT_400d02f8,0xdc,DAT_400d0304,DAT_400d0310);
  return 0;
}



// Function at 0x400d6f5c

void FUN_400d6f5c(void)

{
  int iVar1;
  
  iVar1 = *DAT_400d0314;
  if (iVar1 == 1) {
    (*DAT_400d0324)(PTR_FUN_400d031c);
  }
  else if (iVar1 == 2) {
    (*DAT_400d0324)(PTR_FUN_400d0320);
  }
  else if (iVar1 == 0) {
    (*DAT_400d0324)(PTR_LAB_400d0318);
  }
  else {
    (*DAT_400d0324)(0);
  }
  return;
}



// Function at 0x400d6f9c

void FUN_400d6f9c(int param_1)

{
  if ((param_1 == 0) || (2 < *(byte *)(param_1 + 4))) {
    *DAT_400d0314 = 0xffffffff;
  }
  else {
    *DAT_400d0314 = (uint)*(byte *)(param_1 + 4);
  }
  FUN_400d6f5c();
  return;
}



// Function at 0x400d6fc0

undefined4 FUN_400d6fc0(void)

{
  return *DAT_400d0314;
}



// Function at 0x400d6fcc

int FUN_400d6fcc(undefined4 *param_1,char param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = DAT_400d0298;
    if ((*(char *)(param_1 + 1) != '\0') && (iVar2 = DAT_400d02a4, *(char *)(param_1 + 1) != '\x01')
       ) {
      iVar2 = DAT_400d02c0;
    }
    while (memw(), (*(uint *)(iVar2 + 0x30) & 0x3ff) < 0x1e) {
      if (param_2 != '\0') {
        return 0;
      }
      (*DAT_400d0328)(1000);
    }
    do {
      iVar1 = func_0x400896ec(*param_1,0xffffffff);
    } while (iVar1 != 1);
    memw();
    memw();
    iVar2 = (int)((*(uint *)(iVar2 + 0x28) & DAT_400d023c) +
                 (*(uint *)(iVar2 + 0x2c) & DAT_400d023c)) >> 1;
    func_0x40089194(*param_1,0,0);
  }
  return iVar2;
}



// Function at 0x400d704c

uint FUN_400d704c(uint param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = DAT_400d0298;
    if ((*(char *)(param_1 + 4) != '\0') && (iVar1 = DAT_400d02a4, *(char *)(param_1 + 4) != '\x01')
       ) {
      iVar1 = DAT_400d02c0;
    }
    memw();
    memw();
    *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & DAT_400d032c | DAT_400d01f8;
    memw();
    memw();
    *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & 0xfffffffe;
    memw();
    param_1 = *(uint *)(iVar1 + 0x18) | 1;
    memw();
    *(uint *)(iVar1 + 0x18) = param_1;
  }
  return param_1;
}



// Function at 0x400d70a4

uint FUN_400d70a4(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    if (*DAT_400d0330 == '\0') {
      FUN_400d704c(param_1);
      *DAT_400d0330 = '\x01';
    }
    uVar1 = FUN_400d6fcc(param_1,1);
    if (uVar1 != 0) {
      iVar3 = DAT_400d0298;
      if ((*(char *)(param_1 + 4) != '\0') &&
         (iVar3 = DAT_400d02a4, *(char *)(param_1 + 4) != '\x01')) {
        iVar3 = DAT_400d02c0;
      }
      memw();
      memw();
      *(uint *)(iVar3 + 0x18) = *(uint *)(iVar3 + 0x18) & 0xfffffffe;
      *DAT_400d0330 = '\0';
      uVar2 = FUN_400d7414();
      uVar2 = uVar2 / uVar1;
      for (uVar1 = 1; uVar1 < 0x10; uVar1 = uVar1 + 1) {
        uVar4 = *(uint *)(DAT_400d0334 + uVar1 * 4);
        if (uVar2 <= uVar4) {
          if (uVar2 - *(int *)(DAT_400d0334 + (uVar1 - 1) * 4) < uVar4 - uVar2) {
            uVar1 = uVar1 - 1;
          }
          break;
        }
      }
      uVar1 = *(uint *)(DAT_400d0334 + uVar1 * 4);
    }
  }
  return uVar1;
}



// Function at 0x400d7188

undefined4 FUN_400d7188(void)

{
  return DAT_400d01e0;
}



// Function at 0x400d7190

void FUN_400d7190(void)

{
  undefined4 uVar1;
  
  *DAT_400d0338 = 0;
  FUN_400d5f40();
  uVar1 = FUN_400d7188();
  FUN_400d5ea4(PTR_LAB_400d0348,DAT_400d0344,uVar1,0,1,DAT_400d0340,1);
  return;
}



// Function at 0x400d71b8

uint FUN_400d71b8(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_400d034c;
  if (*(uint *)(param_1 + 0xc) < 0x50) {
    uVar1 = (uint)(*(int *)(param_1 + 4) * DAT_400d01e4) / *(uint *)(param_1 + 8);
  }
  return uVar1;
}



// Function at 0x400d71d8

void FUN_400d71d8(void)

{
  int iVar1;
  
  memw();
  if (*DAT_400d0350 == '\0') {
    memw();
    *DAT_400d0350 = '\x01';
    iVar1 = func_0x400893a4(1);
    *DAT_400d0354 = iVar1;
    if (iVar1 == 0) {
      memw();
      *DAT_400d0350 = '\0';
    }
  }
  return;
}



// Function at 0x400d7218

void FUN_400d7218(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  FUN_400d71d8();
  func_0x400896ec(*DAT_400d0354,0xffffffff);
  puVar1 = (undefined4 *)*DAT_400d0358;
  if (puVar1 != (undefined4 *)0x0) {
    if (param_1 == 0) {
      for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[1]) {
        (*(code *)puVar1[3])(puVar1[2],0,param_2,param_3);
      }
    }
    else {
      do {
        puVar2 = puVar1;
        puVar1 = (undefined4 *)puVar2[1];
      } while ((undefined4 *)puVar2[1] != (undefined4 *)0x0);
      for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
        (*(code *)puVar2[3])(puVar2[2],param_1,param_2,param_3);
      }
    }
  }
  func_0x40089194(*DAT_400d0354,0,0);
  return;
}



// Function at 0x400d7274

undefined4 FUN_400d7274(int param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  FUN_400d71d8();
  func_0x400896ec(*DAT_400d0354,0xffffffff);
  for (piVar2 = (int *)*DAT_400d0358;
      (piVar2 != (int *)0x0 && ((piVar2[3] != param_2 || (piVar2[2] != param_1))));
      piVar2 = (int *)piVar2[1]) {
  }
  if (piVar2 == (int *)0x0) {
    func_0x40089194(*DAT_400d0354,0,0);
    uVar1 = 0;
  }
  else {
    if (*piVar2 == 0) {
      *DAT_400d0358 = piVar2[1];
    }
    else {
      *(int *)(*piVar2 + 4) = piVar2[1];
    }
    if ((int *)piVar2[1] != (int *)0x0) {
      *(int *)piVar2[1] = *piVar2;
    }
    func_0x4008dbfc();
    func_0x40089194(*DAT_400d0354,0,0);
    uVar1 = 1;
  }
  return uVar1;
}



// Function at 0x400d72e4

int FUN_400d72e4(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 auStack_40 [12];
  uint uStack_34;
  undefined1 auStack_30 [12];
  uint uStack_24;
  
  uVar1 = func_0x40087478();
  if (uVar1 != 0) {
    if (uVar1 < 0x28) {
      if ((param_1 < uVar1) && (uVar1 >> 1 != param_1)) {
        return 0;
      }
    }
    else if (((param_1 < uVar1) && (uVar1 >> 1 != param_1)) && (uVar1 >> 2 != param_1)) {
      return 0;
    }
  }
  if (((uVar1 < param_1 && param_1 != 0xf0) && (param_1 != 0xa0)) && (param_1 != 0x50)) {
    iVar2 = 0;
  }
  else {
    if (((param_1 == 0xf0) && (memw(), (*DAT_400d035c & 0x2000) != 0)) &&
       (memw(), (*DAT_400d035c & 0x1000) != 0)) {
      param_1 = 0xa0;
    }
    func_0x400874fc(auStack_30);
    if (uStack_24 == param_1) {
      iVar2 = 1;
    }
    else {
      iVar2 = func_0x400874a0(param_1,auStack_40);
      if (iVar2 != 0) {
        uVar1 = FUN_400d71b8(auStack_30);
        uVar3 = FUN_400d71b8(auStack_40);
        if (*DAT_400d0358 != 0) {
          FUN_400d7218(0,uVar1,uVar3);
        }
        func_0x4008773c(auStack_40);
        if (uVar1 != uVar3) {
          func_0x4008758c(uVar3);
          func_0x40084be0((uint)((ulonglong)uVar3 * (ulonglong)DAT_400d02e4 >> 0x32));
        }
        uVar4 = uVar3;
        if (0x4f < uStack_34) {
          uVar4 = uStack_34 * DAT_400d01e4;
        }
        *DAT_400d0360 = (uint)((ulonglong)uVar4 * (ulonglong)DAT_400d02ec >> 0x26);
        if (*DAT_400d0358 != 0) {
          FUN_400d7218(1,uVar1,uVar3);
        }
      }
    }
  }
  return iVar2;
}



// Function at 0x400d7414

undefined4 FUN_400d7414(void)

{
  undefined4 uVar1;
  undefined1 auStack_30 [48];
  
  func_0x400874fc(auStack_30);
  uVar1 = FUN_400d71b8(auStack_30);
  return uVar1;
}



// Function at 0x400d7428

uint FUN_400d7428(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 < 0x28) {
    uVar1 = (*(uint *)(DAT_400d0364 + param_1 * 4) ^ 0xffffffff) >> 0x1f;
  }
  return uVar1;
}



// Function at 0x400d7448

undefined4 FUN_400d7448(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  
  uVar1 = (*DAT_400d0384)(DAT_400d0178,DAT_400d0368,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0370,DAT_400d0374,uVar2,DAT_400d0370,DAT_400d036c,0xb7,DAT_400d0378);
    uVar2 = 0x102;
  }
  else {
    puVar3 = (uint *)((uint)*(byte *)(DAT_400d037c + param_1) + DAT_400d0380);
    memw();
    uVar2 = 0;
    memw();
    *puVar3 = *puVar3 & 0xfffffdff;
    memw();
  }
  return uVar2;
}



// Function at 0x400d74ac

undefined4 FUN_400d74ac(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = (*DAT_400d0384)(DAT_400d0178,DAT_400d0368,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0370,DAT_400d0374,uVar2,DAT_400d0370,DAT_400d0388,0xc5,DAT_400d0378);
    uVar2 = 0x102;
  }
  else {
    iVar3 = *(int *)*DAT_400d038c;
    if (0x1f < (int)param_1) goto LAB_400d7528;
    memw();
    *(int *)(iVar3 + 0x28) = 1 << 0x20 - (0x20 - ((uint)param_1 & 0x1f));
    while (param_1 = (undefined4 *)(((int)param_1 + DAT_400d0390) * 4),
          (uint)((int)param_1 + DAT_400d02a8) <= DAT_400d02ac) {
      memw();
      iVar3 = func_0x4008dacc(DAT_400d039c,0x153,DAT_400d0398,DAT_400d0394);
LAB_400d7528:
      memw();
      memw();
      memw();
      memw();
      memw();
      memw();
      *(uint *)(iVar3 + 0x34) =
           *(uint *)(iVar3 + 0x34) & 0xffffff00 |
           1 << 0x20 - (0x20 - ((uint)param_1 & 0x1f)) & 0xffU;
      memw();
    }
    memw();
    *param_1 = 0x100;
    uVar2 = 0;
    memw();
  }
  return uVar2;
}



// Function at 0x400d7570

undefined4 FUN_400d7570(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = (*DAT_400d0384)(DAT_400d0178,DAT_400d0368,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0370,DAT_400d0374,uVar2,DAT_400d0370,DAT_400d03a0,0xdb,DAT_400d0378);
    uVar2 = 0x102;
  }
  else {
    iVar3 = *(int *)*DAT_400d038c + (param_1 + 0x20) * 4;
    memw();
    memw();
    *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) | 4;
    uVar2 = 0;
    memw();
  }
  return uVar2;
}



// Function at 0x400d75d4

undefined4 FUN_400d75d4(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = (*DAT_400d0384)(DAT_400d0178,DAT_400d0368,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0370,DAT_400d0374,uVar2,DAT_400d0370,DAT_400d03a4,0xd4,DAT_400d0378);
    uVar2 = 0x102;
  }
  else {
    iVar3 = *(int *)*DAT_400d038c + (param_1 + 0x20) * 4;
    memw();
    memw();
    *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) & 0xfffffffb;
    uVar2 = 0;
    memw();
  }
  return uVar2;
}



// Function at 0x400d7638

undefined4 FUN_400d7638(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  
  uVar1 = (*DAT_400d0384)(DAT_400d0178,DAT_400d0368,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0370,DAT_400d0374,uVar2,DAT_400d0370,DAT_400d03a8,0xbe,DAT_400d0378);
    uVar2 = 0x102;
  }
  else {
    puVar3 = *(uint **)(DAT_400d02c4 + param_1 * 4);
    if ((uint)((int)puVar3 + DAT_400d02a8) <= DAT_400d02ac) {
      func_0x4008dacc(DAT_400d039c,0x13f,DAT_400d03b0,DAT_400d03ac);
    }
    memw();
    memw();
    *puVar3 = *puVar3 | 0x200;
    uVar2 = 0;
    memw();
  }
  return uVar2;
}



// Function at 0x400d76b4

undefined4 FUN_400d76b4(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (*DAT_400d0384)(DAT_400d0178,DAT_400d0368,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0370,DAT_400d0374,uVar2,DAT_400d0370,DAT_400d03b4,0x9e,DAT_400d0378);
    uVar2 = 0x102;
  }
  else {
    uVar2 = 0;
    FUN_400e0c10(*DAT_400d038c,param_1,param_2);
  }
  return uVar2;
}



// Function at 0x400d7704

undefined4 FUN_400d7704(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = (*DAT_400d0384)(DAT_400d0178,DAT_400d03b8,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0370,DAT_400d0374,uVar2,DAT_400d0370,DAT_400d03bc,0xcc,DAT_400d03c0);
    uVar2 = 0x102;
  }
  else {
    iVar3 = *(int *)*DAT_400d038c;
    if ((int)param_1 < 0x20) {
      memw();
      *(int *)(iVar3 + 0x24) = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
    }
    else {
      memw();
      memw();
      memw();
      memw();
      memw();
      memw();
      *(uint *)(iVar3 + 0x30) =
           *(uint *)(iVar3 + 0x30) & 0xffffff00 | 1 << 0x20 - (0x20 - (param_1 & 0x1f)) & 0xffU;
      memw();
    }
    memw();
    (*DAT_400d02dc)(param_1,0x100,0);
    uVar2 = 0;
  }
  return uVar2;
}



// Function at 0x400d77ac

undefined8 FUN_400d77ac(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  
  uVar1 = (*DAT_400d0384)(DAT_400d0178,DAT_400d0368,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0370,DAT_400d0374,uVar2,DAT_400d0370,DAT_400d03c4,0x47,DAT_400d0378);
    uVar2 = 0x102;
  }
  else {
    param_2 = FUN_400d7428(param_1);
    uVar2 = DAT_400d03c8;
    if (param_2 == 0) {
      func_0x4008b620(DAT_400d03c8,0xffffffff);
      puVar3 = *(uint **)(DAT_400d02c4 + param_1 * 4);
      if ((uint)((int)puVar3 + DAT_400d02a8) <= DAT_400d02ac) {
        func_0x4008dacc(DAT_400d039c,0x32,DAT_400d03d0,DAT_400d03cc);
      }
      memw();
      memw();
      *puVar3 = *puVar3 | 0x100;
      memw();
      func_0x4008b770(uVar2);
    }
    else {
      FUN_400da4a0(param_1);
    }
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}



// Function at 0x400d784c

undefined8 FUN_400d784c(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  
  uVar1 = (*DAT_400d0384)(DAT_400d0178,DAT_400d0368,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0370,DAT_400d0374,uVar2,DAT_400d0370,DAT_400d03d4,0x5a,DAT_400d0378);
    uVar2 = 0x102;
  }
  else {
    param_2 = FUN_400d7428(param_1);
    uVar2 = DAT_400d03c8;
    if (param_2 == 0) {
      func_0x4008b620(DAT_400d03c8,0xffffffff);
      puVar3 = (uint *)((uint)*(byte *)(DAT_400d037c + param_1) + DAT_400d0380);
      memw();
      memw();
      *puVar3 = *puVar3 & 0xfffffeff;
      memw();
      func_0x4008b770(uVar2);
    }
    else {
      FUN_400da530(param_1);
    }
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}



// Function at 0x400d78d4

undefined8 FUN_400d78d4(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  
  uVar1 = (*DAT_400d0384)(DAT_400d0178,DAT_400d0368,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0370,DAT_400d0374,uVar2,DAT_400d0370,DAT_400d03d8,0x6d,DAT_400d0378);
    uVar2 = 0x102;
  }
  else {
    param_2 = FUN_400d7428(param_1);
    uVar2 = DAT_400d03c8;
    if (param_2 == 0) {
      func_0x4008b620(DAT_400d03c8,0xffffffff);
      puVar3 = *(uint **)(DAT_400d02c4 + param_1 * 4);
      if ((uint)((int)puVar3 + DAT_400d02a8) <= DAT_400d02ac) {
        func_0x4008dacc(DAT_400d039c,0x55,DAT_400d03dc,DAT_400d03cc);
      }
      memw();
      memw();
      *puVar3 = *puVar3 | 0x80;
      memw();
      func_0x4008b770(uVar2);
    }
    else {
      FUN_400da5c4(param_1);
    }
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}



// Function at 0x400d7974

undefined8 FUN_400d7974(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  
  uVar1 = (*DAT_400d0384)(DAT_400d0178,DAT_400d0368,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0370,DAT_400d0374,uVar2,DAT_400d0370,DAT_400d03e0,0x80,DAT_400d0378);
    uVar2 = 0x102;
  }
  else {
    param_2 = FUN_400d7428(param_1);
    uVar2 = DAT_400d03c8;
    if (param_2 == 0) {
      func_0x4008b620(DAT_400d03c8,0xffffffff);
      puVar3 = (uint *)((uint)*(byte *)(DAT_400d037c + param_1) + DAT_400d0380);
      memw();
      memw();
      *puVar3 = *puVar3 & 0xffffff7f;
      memw();
      func_0x4008b770(uVar2);
    }
    else {
      FUN_400da654(param_1);
    }
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}



// Function at 0x400d79fc

undefined4 FUN_400d79fc(int param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar1 = (*DAT_400d0384)(DAT_400d0178,DAT_400d0368,param_1);
  uVar5 = DAT_400d03c8;
  if ((uVar1 & 1) == 0) {
    uVar2 = func_0x4008d9f8();
    uVar3 = 0x93;
    uVar5 = DAT_400d0378;
  }
  else {
    if (param_2 < 6) {
      func_0x4008b620(DAT_400d03c8,0xffffffff);
      iVar4 = *(int *)*DAT_400d038c + (param_1 + 0x20) * 4;
      memw();
      memw();
      *(uint *)(iVar4 + 8) = *(uint *)(iVar4 + 8) & 0xfffffc7f | (param_2 & 7) << 7;
      memw();
      func_0x4008b770(uVar5);
      return 0;
    }
    uVar2 = func_0x4008d9f8();
    uVar3 = 0x94;
    memw();
    uVar5 = DAT_400d03e8;
  }
  memw();
  FUN_400e4a50(1,DAT_400d0370,DAT_400d0374,uVar2,DAT_400d0370,DAT_400d03e4,uVar3,uVar5);
  return 0x102;
}



// Function at 0x400d7a94

undefined4 FUN_400d7a94(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 in_PRID;
  
  uVar2 = (*DAT_400d0384)(DAT_400d0178,DAT_400d0368,param_1);
  uVar3 = DAT_400d03c8;
  if ((uVar2 & 1) == 0) {
    uVar3 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0370,DAT_400d0374,uVar3,DAT_400d0370,DAT_400d03ec,0xa5,DAT_400d0378);
    uVar3 = 0x102;
  }
  else {
    func_0x4008b620(DAT_400d03c8,0xffffffff);
    iVar1 = DAT_400d038c;
    if (*(int *)(DAT_400d038c + 0xc) == 3) {
      uVar2 = rsr(in_PRID);
      *(uint *)(DAT_400d038c + 0xc) = uVar2 >> 0xd & 1;
    }
    memw();
    func_0x4008b770(uVar3);
    uVar3 = FUN_400d76b4(param_1,*(undefined4 *)(iVar1 + 0xc));
  }
  return uVar3;
}



// Function at 0x400d7b04

undefined4 FUN_400d7b04(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (*DAT_400d0384)(DAT_400d0178,DAT_400d0368,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0370,DAT_400d0374,uVar2,DAT_400d0370,DAT_400d03f0,0xb0,DAT_400d0378);
    uVar2 = 0x102;
  }
  else {
    uVar2 = 0;
    FUN_400e0c8c(*DAT_400d038c,param_1);
  }
  return uVar2;
}



// Function at 0x400d7b54

undefined4 FUN_400d7b54(uint param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = (*DAT_400d0384)(DAT_400d0178,DAT_400d03b8,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0370,DAT_400d0374,uVar2,DAT_400d0370,DAT_400d03f4,0xe2,DAT_400d03c0);
    uVar2 = 0x102;
  }
  else {
    iVar3 = *(int *)*DAT_400d038c;
    if (param_2 == 0) {
      if (0x1f < (int)param_1) {
        memw();
        memw();
        memw();
        memw();
        memw();
        memw();
        *(uint *)(iVar3 + 0x18) =
             *(uint *)(iVar3 + 0x18) & 0xffffff00 | 1 << 0x20 - (0x20 - (param_1 & 0x1f)) & 0xffU;
        memw();
        return 0;
      }
      memw();
      *(int *)(iVar3 + 0xc) = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
      memw();
    }
    else if ((int)param_1 < 0x20) {
      memw();
      *(int *)(iVar3 + 8) = 1 << 0x20 - (0x20 - (param_1 & 0x1f));
    }
    else {
      memw();
      memw();
      memw();
      memw();
      memw();
      memw();
      *(uint *)(iVar3 + 0x14) =
           *(uint *)(iVar3 + 0x14) & 0xffffff00 | 1 << 0x20 - (0x20 - (param_1 & 0x1f)) & 0xffU;
      memw();
    }
    uVar2 = 0;
    memw();
  }
  return uVar2;
}



// Function at 0x400d7c38

uint FUN_400d7c38(uint param_1)

{
  uint uVar1;
  
  if ((int)param_1 < 0x20) {
    memw();
    uVar1 = *(uint *)(*(int *)*DAT_400d038c + 0x3c) >> (param_1 & 0x1f);
  }
  else {
    memw();
    memw();
    memw();
    uVar1 = (int)(*(uint *)(*(int *)*DAT_400d038c + 0x40) & 0xff) >> (param_1 & 0x1f);
    memw();
  }
  return uVar1 & 1;
}



// Function at 0x400d7c78

undefined4 FUN_400d7c78(undefined4 param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar1 = (*DAT_400d0384)(DAT_400d0178,DAT_400d0368,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = func_0x4008d9f8();
    uVar3 = 0xee;
    uVar4 = DAT_400d0378;
LAB_400d7c9c:
    memw();
    FUN_400e4a50(1,DAT_400d0370,DAT_400d0374,uVar2,DAT_400d0370,DAT_400d03f8,uVar3,uVar4);
    return 0x102;
  }
  if (3 < param_2) {
    uVar2 = func_0x4008d9f8();
    uVar3 = 0xef;
    memw();
    uVar4 = DAT_400d03fc;
    goto LAB_400d7c9c;
  }
  if (param_2 == 2) {
    FUN_400d78d4(param_1);
LAB_400d7cdb:
    FUN_400d77ac(param_1);
  }
  else {
    if (param_2 == 3) {
      FUN_400d7974();
    }
    else {
      if (param_2 != 1) {
        FUN_400d7974();
        goto LAB_400d7cdb;
      }
      FUN_400d78d4(param_1);
    }
    FUN_400d784c(param_1);
  }
  return 0;
}



// Function at 0x400d7d04

undefined4 FUN_400d7d04(undefined4 param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (*DAT_400d0384)(DAT_400d0178,DAT_400d0368,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0370,DAT_400d0374,uVar2,DAT_400d0370,DAT_400d0400,0x112,DAT_400d0378);
  }
  else {
    uVar1 = (*DAT_400d0384)(DAT_400d0178,DAT_400d03b8,param_1);
    if (((uVar1 & 1) != 0) || ((param_2 & 2) == 0)) {
      if ((param_2 & 1) == 0) {
        FUN_400d7448(param_1);
      }
      else {
        FUN_400d7638();
      }
      if ((param_2 & 2) == 0) {
        FUN_400d74ac(param_1);
      }
      else {
        FUN_400d7704();
      }
      if ((param_2 & 4) != 0) {
        FUN_400d7570();
        return 0;
      }
      FUN_400d75d4(param_1);
      return 0;
    }
    uVar2 = func_0x4008d9f8();
    FUN_400e4a50(1,DAT_400d0370,DAT_400d0404,uVar2,DAT_400d0370,param_1);
  }
  return 0x102;
}



// Function at 0x400d7db0

undefined4 FUN_400d7db0(uint *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  uVar6 = *param_1;
  uVar5 = param_1[1];
  if ((uVar6 == 0 && uVar5 == 0) || ((uVar6 & DAT_400d0408) != 0 || (uVar5 & 0xffffff00) != 0)) {
    uVar1 = func_0x4008d9f8();
    uVar8 = DAT_400d040c;
  }
  else {
    uVar4 = param_1[2] & 2;
    if ((uVar4 == 0) || (uVar4 = 0, (uVar6 & DAT_400d0408) == 0 && (uVar5 & 0xfffffffc) == 0)) {
      do {
        uVar2 = (*DAT_400d0384)(uVar6,uVar5,uVar4);
        if ((uVar2 & 1) != 0) {
          puVar7 = *(uint **)(uVar4 * 4 + DAT_400d02c4);
          if (puVar7 != (uint *)0x0) goto LAB_400d7e3e;
          uVar9 = 0x14b;
          uVar8 = DAT_400d041c;
          uVar1 = DAT_400d0418;
          uVar10 = DAT_400d0414;
          while( true ) {
            func_0x4008dacc(uVar8,uVar9,uVar1,uVar10);
LAB_400d7e3e:
            iVar3 = FUN_400d7428(uVar4);
            if (iVar3 != 0) {
              FUN_400da410(uVar4);
            }
            if ((param_1[2] & 1) == 0) {
              FUN_400d7448(uVar4);
            }
            else {
              FUN_400d7638();
            }
            if ((param_1[2] & 4) == 0) {
              FUN_400d75d4(uVar4);
            }
            else {
              FUN_400d7570();
            }
            if ((param_1[2] & 2) == 0) {
              FUN_400d74ac(uVar4);
            }
            else {
              FUN_400d7704();
            }
            if (param_1[3] == 0) {
              FUN_400d784c(uVar4);
            }
            else {
              FUN_400d77ac();
            }
            if (param_1[4] == 0) {
              FUN_400d7974(uVar4);
            }
            else {
              FUN_400d78d4();
            }
            FUN_400d79fc(uVar4,param_1[5]);
            if (param_1[5] == 0) {
              FUN_400d7b04(uVar4);
            }
            else {
              FUN_400d7a94();
            }
            if (DAT_400d02ac < (uint)((int)puVar7 + DAT_400d02a8)) break;
            uVar9 = 0x27d;
            uVar8 = DAT_400d039c;
            uVar1 = DAT_400d0424;
            uVar10 = DAT_400d0420;
          }
          memw();
          memw();
          *puVar7 = *puVar7 & DAT_400d02d4 | DAT_400d01e0;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 != 0x28);
      memw();
      return 0;
    }
    uVar1 = func_0x4008d9f8();
    uVar8 = DAT_400d0410;
  }
  FUN_400e4a50(1,DAT_400d0370,uVar8,uVar1,DAT_400d0370);
  return 0x102;
}



// Function at 0x400d7f00

void FUN_400d7f00(int param_1,int param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(*(int *)*DAT_400d038c + (param_2 + 0x4c) * 4);
  memw();
  memw();
  *puVar1 = *puVar1 & 0xffffff7f;
  puVar1 = *(uint **)(DAT_400d02c4 + param_1 * 4);
  if ((uint)((int)puVar1 + DAT_400d02a8) <= DAT_400d02ac) {
    memw();
    func_0x4008dacc(DAT_400d039c,0x272,DAT_400d042c,DAT_400d0428);
  }
  memw();
  memw();
  *puVar1 = *puVar1 | 0x200;
  memw();
  return;
}



// Function at 0x400d7f64

void FUN_400d7f64(uint param_1,int param_2,uint param_3)

{
  uint *puVar1;
  
  puVar1 = (uint *)(*(int *)*DAT_400d038c + ((param_1 & 0xff) + 0x14c) * 4);
  memw();
  memw();
  *puVar1 = *puVar1 & 0xfffffbff;
  memw();
  memw();
  *puVar1 = *puVar1 & DAT_400d0430 | (param_3 & 1) << 0xb;
  puVar1 = *(uint **)(DAT_400d02c4 + (param_1 & 0xff) * 4);
  if ((uint)((int)puVar1 + DAT_400d02a8) <= DAT_400d02ac) {
    memw();
    func_0x4008dacc(DAT_400d039c,0x27d,DAT_400d0424,DAT_400d0420);
  }
  memw();
  memw();
  *puVar1 = param_2 << 0xc & DAT_400d0434 | *puVar1 & DAT_400d02d4;
  memw();
  return;
}



// Function at 0x400d7ff0

void FUN_400d7ff0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1 * 0x1c + 8 + DAT_400d0438;
  iVar1 = DAT_400d0438 + param_1 * 0x1c;
  func_0x4008b620(iVar2,0xffffffff);
  if (*(char *)(iVar1 + 0x10) == '\0') {
    FUN_400da230(*(undefined4 *)(DAT_400d043c + param_1 * 0xc + 8));
    *(undefined1 *)(iVar1 + 0x10) = 1;
    memw();
  }
  memw();
  func_0x4008b770(iVar2);
  return;
}



// Function at 0x400d8038

void FUN_400d8038(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1 * 0x1c + 8 + DAT_400d0438;
  iVar1 = DAT_400d0438 + param_1 * 0x1c;
  func_0x4008b620(iVar2,0xffffffff);
  if (*(char *)(iVar1 + 0x10) != '\0') {
    FUN_400da2dc(*(undefined4 *)(DAT_400d043c + param_1 * 0xc + 8));
    *(undefined1 *)(iVar1 + 0x10) = 0;
    memw();
  }
  memw();
  func_0x4008b770(iVar2);
  return;
}



// Function at 0x400d8080

void FUN_400d8080(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = DAT_400d0440;
  if (*(int *)(param_1 + 0xc) == 0) {
    uVar2 = func_0x4008d9f8();
    uVar3 = DAT_400d0448;
  }
  else {
    uVar2 = func_0x4008d9f8();
    uVar3 = DAT_400d0444;
  }
  FUN_400e4a50(1,uVar1,uVar3,uVar2,uVar1);
  return;
}



// Function at 0x400d80ac

undefined4 FUN_400d80ac(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  
  piVar1 = param_1;
  if (param_1 != (int *)0x0) goto LAB_400d80c6;
  uVar6 = 0x47c;
  uVar4 = DAT_400d044c;
  while( true ) {
    func_0x4008dacc(DAT_400d0454,uVar6,DAT_400d0450,uVar4);
LAB_400d80c6:
    piVar1 = (int *)*piVar1;
    if (piVar1 == (int *)0x0) {
      iVar2 = param_1[3];
      if (iVar2 == 0) {
        iVar2 = func_0x400842c4(1,0x14,DAT_400d0458);
        *param_1 = iVar2;
        if (iVar2 == 0) goto LAB_400d811a;
      }
      else {
        if ((uint)param_1[4] < 0x14) goto LAB_400d8171;
        *param_1 = iVar2;
        param_1[3] = iVar2 + 0x14;
        param_1[4] = param_1[4] - 0x14;
      }
      param_1[1] = *param_1;
      param_1[2] = *param_1;
      goto LAB_400d80ee;
    }
    iVar2 = param_1[1];
    if (iVar2 != 0) break;
    uVar6 = 0x487;
    uVar4 = DAT_400d045c;
  }
  iVar3 = param_1[3];
  if (iVar3 == 0) {
    iVar3 = func_0x400842c4(1,0x14,DAT_400d0458);
    *(int *)(iVar2 + 0x10) = iVar3;
    if (iVar3 != 0) goto LAB_400d814d;
    memw();
LAB_400d811a:
    uVar4 = 0xffffffff;
  }
  else {
    uVar5 = param_1[4];
    if (0x13 < uVar5) {
      *(int *)(iVar2 + 0x10) = iVar3;
      param_1[3] = iVar3 + 0x14;
      param_1[4] = uVar5 - 0x14;
LAB_400d814d:
      param_1[1] = *(int *)(param_1[1] + 0x10);
      memw();
LAB_400d80ee:
      memw();
      func_0x400866b8(param_1[1],param_2,0x10);
      *(undefined4 *)(param_1[1] + 0x10) = 0;
      memw();
      return 0;
    }
LAB_400d8171:
    uVar4 = 0x101;
  }
  memw();
  FUN_400d8080(param_1);
  return uVar4;
}



// Function at 0x400d8178

undefined4 FUN_400d8178(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = DAT_400d0468;
  if (param_1 < 2) {
    iVar4 = param_1 * 4;
    iVar3 = *(int *)(DAT_400d0468 + iVar4);
    if (iVar3 == 0) {
      uVar2 = func_0x4008d9f8();
      memw();
      FUN_400e4a50(1,DAT_400d0440,DAT_400d046c,uVar2,DAT_400d0440,DAT_400d0460,0x19b);
      uVar2 = 0xffffffff;
    }
    else {
      FUN_400f7ee4(DAT_400d0438 + param_1 * 0x1c,DAT_400d022c);
      FUN_400e385c(*(undefined4 *)(iVar3 + 8));
      *(undefined4 *)(iVar3 + 8) = 0;
      if (*(int *)(iVar3 + 0xac) != 0) {
        memw();
        func_0x400896ec(*(int *)(iVar3 + 0xac),0xffffffff);
        func_0x40089194(*(undefined4 *)(iVar3 + 0xac),0,0,0);
        func_0x400899b0(*(undefined4 *)(iVar3 + 0xac));
      }
      if (*(int *)(*(int *)(iVar1 + iVar4) + 0x4c) != 0) {
        func_0x400899b0();
        *(undefined4 *)(*(int *)(iVar1 + iVar4) + 0x4c) = 0;
      }
      if (*(int *)(iVar3 + 0xb0) != 0) {
        memw();
        func_0x400899b0();
      }
      if (*(int *)(iVar3 + 0xb4) != 0) {
        func_0x400899b0();
      }
      if (*(int *)(iVar3 + 0xbc) != 0) {
        func_0x40088818();
        *(undefined4 *)(iVar3 + 0xbc) = 0;
        *(undefined4 *)(iVar3 + 0xb8) = 0;
      }
      if (*(int *)(iVar3 + 0xc4) != 0) {
        memw();
        func_0x40088818();
        *(undefined4 *)(iVar3 + 0xc4) = 0;
        *(undefined4 *)(iVar3 + 0xc0) = 0;
      }
      iVar3 = *(int *)(iVar1 + iVar4);
      if (*(int *)(iVar3 + 0x50) != 0) {
        memw();
        func_0x4008dbfc();
      }
      func_0x4008dbfc(iVar3);
      *(undefined4 *)(iVar1 + iVar4) = 0;
      memw();
      uVar2 = 0;
      FUN_400d8038(param_1);
    }
  }
  else {
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0440,DAT_400d0464,uVar2,DAT_400d0440,DAT_400d0460,0x19a);
    uVar2 = 0x102;
  }
  return uVar2;
}



// Function at 0x400d8290

undefined4 FUN_400d8290(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = DAT_400d0438;
  if (param_1 < 2) {
    iVar3 = param_1 * 0x1c + 8 + DAT_400d0438;
    func_0x4008b620(iVar3,0xffffffff);
    FUN_400e0844(iVar1 + param_1 * 0x1c);
    func_0x4008b770(iVar3);
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0440,DAT_400d0464,uVar2,DAT_400d0440,DAT_400d0470,0x1d3);
    uVar2 = 0x102;
  }
  return uVar2;
}



// Function at 0x400d82e4

undefined4 FUN_400d82e4(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = DAT_400d0438;
  if (param_1 < 2) {
    iVar3 = param_1 * 0x1c + 8 + DAT_400d0438;
    func_0x4008b620(iVar3,0xffffffff);
    FUN_400e0870(iVar1 + param_1 * 0x1c);
    func_0x4008b770(iVar3);
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0440,DAT_400d0464,uVar2,DAT_400d0440,DAT_400d0474,0x1dc);
    uVar2 = 0x102;
  }
  return uVar2;
}



// Function at 0x400d8338

undefined4 FUN_400d8338(uint param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar1 = DAT_400d0438;
  if (param_1 < 2) {
    if (param_2 - 1U <= DAT_400d047c) {
      iVar3 = param_1 * 0x1c + 8 + DAT_400d0438;
      func_0x4008b620(iVar3,0xffffffff);
      FUN_400e089c(iVar1 + param_1 * 0x1c,param_2);
      func_0x4008b770(iVar3);
      return 0;
    }
    uVar2 = func_0x4008d9f8();
    uVar5 = 0x347;
    memw();
    uVar4 = DAT_400d0480;
  }
  else {
    uVar2 = func_0x4008d9f8();
    uVar5 = 0x346;
    uVar4 = DAT_400d0464;
  }
  memw();
  FUN_400e4a50(1,DAT_400d0440,uVar4,uVar2,DAT_400d0440,DAT_400d0478,uVar5);
  return 0x102;
}



// Function at 0x400d83b8

undefined4
FUN_400d83b8(uint param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_1 < 2) {
    if (param_2 != 0) {
      uVar2 = FUN_400e383c(*(undefined1 *)(DAT_400d043c + param_1 * 0xc + 4),param_4,param_2,param_3
                           ,param_5);
      return uVar2;
    }
    uVar1 = func_0x4008d9f8();
    uVar3 = 0x359;
    memw();
    uVar2 = DAT_400d0488;
  }
  else {
    uVar1 = func_0x4008d9f8();
    uVar3 = 0x358;
    uVar2 = DAT_400d0464;
  }
  memw();
  FUN_400e4a50(1,DAT_400d0440,uVar2,uVar1,DAT_400d0440,DAT_400d0484,uVar3);
  return 0x102;
}



// Function at 0x400d8424

undefined4 FUN_400d8424(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  uint *puVar7;
  int iVar8;
  undefined4 uVar9;
  
  iVar1 = DAT_400d0468;
  if (1 < param_1) {
    memw();
    uVar2 = func_0x4008d9f8();
    uVar9 = 0xf3;
    uVar5 = DAT_400d0464;
LAB_400d8449:
    memw();
    FUN_400e4a50(1,DAT_400d0440,uVar5,uVar2,DAT_400d0440,DAT_400d048c,uVar9);
    return 0x102;
  }
  if (((param_2 != 1) && (param_3 < 0x65)) && (param_4 < 0x65)) {
    uVar2 = func_0x4008d9f8();
    uVar9 = 0xf5;
    memw();
    uVar5 = DAT_400d0490;
    goto LAB_400d8449;
  }
  iVar8 = param_1 * 4;
  piVar6 = (int *)(DAT_400d0468 + iVar8);
  if (*piVar6 != 0) {
    uVar2 = func_0x4008d9f8();
    uVar5 = DAT_400d04a0;
LAB_400d84c1:
    FUN_400e4a50(1,DAT_400d0440,uVar5,uVar2,DAT_400d0440);
    return 0xffffffff;
  }
  if ((param_5 & 0x400) == 0) {
    memw();
    iVar3 = func_0x4008dc54(1,200);
  }
  else {
    iVar3 = func_0x400842c4(1,200,DAT_400d0458);
  }
  *piVar6 = iVar3;
  puVar7 = *(uint **)(iVar1 + iVar8);
  if (puVar7 == (uint *)0x0) {
    memw();
    uVar2 = func_0x4008d9f8();
    uVar5 = DAT_400d0494;
    goto LAB_400d84c1;
  }
  puVar7[1] = param_2;
  puVar7[0x15] = param_5;
  *puVar7 = param_1;
  puVar7[3] = 0;
  puVar7[5] = 0;
  puVar7[4] = 2;
  if (param_2 == 0) {
    if (param_3 != 0) {
      memw();
      uVar4 = func_0x4008849c(param_3);
      puVar7[0x2f] = uVar4;
      if (uVar4 != 0) {
        puVar7[0x2e] = param_3;
        goto LAB_400d85cc;
      }
LAB_400d850c:
      memw();
      uVar2 = func_0x4008d9f8();
      uVar5 = DAT_400d0498;
      goto LAB_400d851c;
    }
    puVar7[0x2f] = 0;
    puVar7[0x2e] = 0;
    memw();
LAB_400d85cc:
    if (param_4 == 0) {
      puVar7[0x31] = 0;
      memw();
    }
    else {
      memw();
      uVar4 = func_0x4008849c(param_4,2);
      puVar7[0x31] = uVar4;
      if (uVar4 == 0) goto LAB_400d850c;
    }
    puVar7[0x30] = param_4;
    memw();
    uVar4 = func_0x400893a4(1);
    puVar7[0x2c] = uVar4;
    memw();
    uVar4 = func_0x400893a4(1);
    puVar7[0x2d] = uVar4;
    if ((puVar7[0x2c] != 0) && (uVar4 != 0 && puVar7[0x2c] != 0)) {
LAB_400d867e:
      memw();
      FUN_400d7ff0(param_1);
      uVar5 = DAT_400d022c;
      iVar3 = param_1 * 0x1c + DAT_400d0438;
      FUN_400f7ee4(iVar3,DAT_400d022c);
      FUN_400f7ed4(iVar3,uVar5);
      FUN_400d83b8(param_1,DAT_400d04a4,*(int *)(iVar1 + iVar8),param_5,*(int *)(iVar1 + iVar8) + 8)
      ;
      if (param_2 == 0) {
        FUN_400f8020(iVar3);
        return 0;
      }
      return 0;
    }
  }
  else {
    memw();
    uVar4 = func_0x400893a4(1);
    puVar7[0x2b] = uVar4;
    if ((param_5 & 0x400) == 0) {
      memw();
      uVar4 = func_0x400890ac(1,4,0);
    }
    else {
      memw();
      uVar4 = func_0x400842c4(1,4,DAT_400d0458);
      puVar7[0x14] = uVar4;
      if (uVar4 == 0) {
        memw();
        uVar2 = func_0x4008d9f8();
        uVar5 = DAT_400d0494;
        goto LAB_400d851c;
      }
      memw();
      uVar5 = func_0x40086818(puVar7 + 0x16,0,0x54);
      uVar4 = func_0x40088ffc(1,4,uVar4,uVar5,0);
    }
    puVar7[0x13] = uVar4;
    if ((puVar7[0x2b] != 0) && (puVar7[0x13] != 0)) {
      puVar7[0xf] = 0;
      puVar7[0xe] = 0;
      puVar7[0x10] = 0;
      puVar7[0x31] = 0;
      puVar7[0x2e] = 0;
      puVar7[0x30] = 0;
      goto LAB_400d867e;
    }
  }
  memw();
  uVar2 = func_0x4008d9f8();
  uVar5 = DAT_400d049c;
LAB_400d851c:
  FUN_400e4a50(1,DAT_400d0440,uVar5,uVar2,DAT_400d0440);
  iVar3 = *(int *)(iVar1 + iVar8);
  if (iVar3 != 0) {
    if (*(int *)(iVar3 + 0xbc) != 0) {
      func_0x40088818();
      iVar3 = *(int *)(iVar1 + iVar8);
      *(undefined4 *)(iVar3 + 0xbc) = 0;
      *(undefined4 *)(iVar3 + 0xb8) = 0;
    }
    if (*(int *)(*(int *)(iVar1 + iVar8) + 0xc4) != 0) {
      memw();
      func_0x40088818();
      iVar3 = *(int *)(iVar1 + iVar8);
      *(undefined4 *)(iVar3 + 0xc4) = 0;
      *(undefined4 *)(iVar3 + 0xc0) = 0;
    }
    if (*(int *)(*(int *)(iVar1 + iVar8) + 0x4c) != 0) {
      memw();
      func_0x400899b0();
      *(undefined4 *)(*(int *)(iVar1 + iVar8) + 0x4c) = 0;
    }
    if (*(int *)(*(int *)(iVar1 + iVar8) + 0xac) != 0) {
      memw();
      func_0x400899b0();
    }
    if (*(int *)(*(int *)(iVar1 + iVar8) + 0xb0) != 0) {
      func_0x400899b0();
    }
    if (*(int *)(*(int *)(iVar1 + iVar8) + 0xb4) != 0) {
      func_0x400899b0();
    }
    iVar3 = *(int *)(iVar1 + iVar8);
    if (*(int *)(iVar3 + 0x50) != 0) {
      func_0x4008dbfc();
      *(undefined4 *)(iVar3 + 0x50) = 0;
    }
  }
  memw();
  func_0x4008dbfc(*(undefined4 *)(iVar1 + iVar8));
  *(undefined4 *)(iVar1 + iVar8) = 0;
  memw();
  return 0xffffffff;
}



// Function at 0x400d8728

undefined4 FUN_400d8728(int param_1,int param_2,int param_3,uint param_4,char param_5,int param_6)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  byte *pbVar7;
  uint *puVar8;
  undefined4 uVar9;
  uint *in_t0;
  undefined4 uVar10;
  uint uStack_2c;
  
  param_4 = param_4 & 0xff;
  if (param_1 < 2) {
    if ((param_2 < 0) ||
       (uVar4 = (*DAT_400d0384)(DAT_400d0178,DAT_400d03b8,param_2), (uVar4 & 1) != 0)) {
      if (((param_3 < 0) ||
          (uVar4 = (*DAT_400d0384)(DAT_400d0178,DAT_400d03b8,param_3), (uVar4 & 1) != 0)) ||
         ((uVar4 = (*DAT_400d0384)(DAT_400d0178,DAT_400d0368,param_3),
          ((uVar4 ^ 0xffffffff) & 1) == 0 && (param_6 == 0)))) {
        if ((param_2 < 0) ||
           ((param_4 == 0 ||
            (uVar4 = (*DAT_400d0384)(DAT_400d0178,DAT_400d03b8,param_2), (uVar4 & 1) != 0)))) {
          if ((param_3 < 0) ||
             ((param_5 == '\0' ||
              (uVar4 = (*DAT_400d0384)(DAT_400d0178,DAT_400d03b8,param_3), (uVar4 & 1) != 0)))) {
            if (param_3 != param_2) {
              pbVar7 = (byte *)(DAT_400d043c + param_1 * 0xc);
              bVar1 = pbVar7[2];
              bVar2 = pbVar7[3];
              if (param_2 < 0) goto LAB_400d88f5;
              puVar6 = (uint *)(uint)*pbVar7;
              uStack_2c = (uint)pbVar7[1];
              memw();
              FUN_400d7b54(param_2,1);
              puVar8 = *(uint **)(DAT_400d02c4 + param_2 * 4);
              if (DAT_400d02ac < (uint)((int)puVar8 + DAT_400d02a8)) goto LAB_400d88ac;
              do {
                puVar8 = in_t0;
                func_0x4008dacc(DAT_400d04c4,0x27d,DAT_400d04c0,DAT_400d04bc);
                in_t0 = puVar8;
LAB_400d88ac:
                memw();
                memw();
                *puVar8 = *puVar8 & DAT_400d02d4 | DAT_400d01e0;
                memw();
                FUN_400d7d04(param_2,7);
                uVar9 = 0;
                if (param_4 == 0) {
                  uVar9 = 3;
                }
                FUN_400d7c78(param_2,uVar9);
                (*DAT_400d02dc)(param_2,puVar6,0);
                (*DAT_400d02e0)(param_2,uStack_2c,0);
LAB_400d88f5:
                if (param_3 < 0) goto LAB_400d895d;
                FUN_400d7b54(param_3,1);
                puVar6 = *(uint **)(DAT_400d02c4 + param_3 * 4);
                param_4 = (int)puVar6 + DAT_400d02a8;
              } while (param_4 <= DAT_400d02ac);
              memw();
              memw();
              *puVar6 = *puVar6 & DAT_400d02d4 | DAT_400d01e0;
              memw();
              FUN_400d7d04(param_3,7);
              (*DAT_400d02dc)(param_3,bVar1,0);
              (*DAT_400d02e0)(param_3,bVar2,0);
              uVar9 = 0;
              if (param_5 == '\0') {
                uVar9 = 3;
              }
              FUN_400d7c78(param_3,uVar9);
LAB_400d895d:
              iVar5 = DAT_400d0438 + param_1 * 0x1c;
              *(int *)(iVar5 + 0x14) = param_3;
              *(int *)(iVar5 + 0x18) = param_2;
              memw();
              return 0;
            }
            uVar3 = func_0x4008d9f8();
            uVar10 = 0x372;
            memw();
            uVar9 = DAT_400d04b8;
            goto LAB_400d874b;
          }
          uVar3 = func_0x4008d9f8();
          uVar10 = 0x371;
        }
        else {
          uVar3 = func_0x4008d9f8();
          uVar10 = 0x36e;
        }
        memw();
        uVar9 = DAT_400d04b4;
      }
      else {
        uVar3 = func_0x4008d9f8();
        uVar10 = 0x36b;
        memw();
        uVar9 = DAT_400d04b0;
      }
    }
    else {
      uVar3 = func_0x4008d9f8();
      uVar10 = 0x366;
      memw();
      uVar9 = DAT_400d04ac;
    }
  }
  else {
    uVar3 = func_0x4008d9f8();
    uVar10 = 0x365;
    uVar9 = DAT_400d0464;
  }
LAB_400d874b:
  memw();
  FUN_400e4a50(1,DAT_400d0440,uVar9,uVar3,DAT_400d0440,DAT_400d04a8,uVar10);
  return 0x102;
}



// Function at 0x400d8978

int FUN_400d8978(uint param_1,uint *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (param_1 < 2) {
    if (param_2 == (uint *)0x0) {
      uVar1 = func_0x4008d9f8();
      uVar5 = 0x2a7;
      memw();
      uVar4 = DAT_400d0488;
    }
    else if (*param_2 < 2) {
      if (*param_2 == 1) {
        if ((param_2[4] <= DAT_400d04d0) && (param_2[6] == 0)) {
LAB_400d8a30:
          iVar2 = FUN_400d8728(param_1,param_2[1],param_2[2],(char)param_2[3],
                               *(undefined1 *)((int)param_2 + 0xd));
          if (iVar2 != 0) {
            return iVar2;
          }
          FUN_400d7ff0(param_1);
          iVar2 = DAT_400d0438;
          iVar3 = param_1 * 0x1c + 8 + DAT_400d0438;
          func_0x4008b620(iVar3,0xffffffff);
          uVar1 = DAT_400d022c;
          iVar2 = param_1 * 0x1c + iVar2;
          FUN_400f7ee4(iVar2,DAT_400d022c);
          FUN_400f7ed4(iVar2,uVar1);
          if (*param_2 == 0) {
            FUN_400e0a94();
            FUN_400e08c0(iVar2,*(undefined2 *)((int)param_2 + 0x12),(char)param_2[4] != '\0');
            FUN_400f7f90(iVar2,0x1c);
            FUN_400f7f6c(iVar2,5);
            FUN_400f7f38(iVar2,10);
            FUN_400e089c(iVar2,DAT_400d04d8);
            FUN_400f8020(iVar2);
          }
          else {
            FUN_400e0b50(iVar2,param_1);
            FUN_400f7e3c(iVar2,7);
            FUN_400e094c(iVar2,param_2[4],1);
          }
          func_0x4008bbe0(iVar2);
          func_0x4008b770(iVar3);
          return 0;
        }
        uVar1 = func_0x4008d9f8();
        uVar5 = 0x2ac;
      }
      else {
        if ((param_2[5] <= DAT_400d04d0) && (param_2[6] == 0)) goto LAB_400d8a30;
        uVar1 = func_0x4008d9f8();
        uVar5 = 0x2b5;
      }
      memw();
      uVar4 = DAT_400d04d4;
    }
    else {
      uVar1 = func_0x4008d9f8();
      uVar5 = 0x2a8;
      memw();
      uVar4 = DAT_400d04cc;
    }
  }
  else {
    uVar1 = func_0x4008d9f8();
    uVar5 = 0x2a6;
    uVar4 = DAT_400d0464;
  }
  memw();
  FUN_400e4a50(1,DAT_400d0440,uVar4,uVar1,DAT_400d0440,DAT_400d04c8,uVar5);
  return 0x102;
}



// Function at 0x400d8adc

void FUN_400d8adc(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined1 uStack_3d;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 auStack_24 [9];
  
  piVar4 = (int *)(DAT_400d0438 + param_1 * 0x1c);
  memw();
  uVar8 = ((uint *)*piVar4)[0xe];
  memw();
  uVar5 = *(uint *)*piVar4;
  memw();
  FUN_400f7fe0(piVar4,&uStack_38,&uStack_3c);
  FUN_400f8000(piVar4,&uStack_30,&uStack_34);
  FUN_400f7fc0(piVar4,&uStack_28,&uStack_2c);
  FUN_400e0934(piVar4,auStack_24);
  FUN_400f7eb8(piVar4,&uStack_3d);
  FUN_400d8038(param_1);
  iVar9 = piVar4[5];
  iVar6 = piVar4[6];
  FUN_400d7d04(iVar9,6);
  FUN_400d7d04(iVar6,7);
  FUN_400d7b54(iVar9,0);
  FUN_400d7b54(iVar6,1);
  (*DAT_400d04dc)(5);
  iVar10 = 10;
  while ((iVar3 = FUN_400d7c38(iVar6), iVar3 == 0 && (iVar10 = iVar10 + -1, iVar10 != 0))) {
    memw();
    FUN_400d7b54(iVar9,1);
    (*DAT_400d04dc)(5);
    FUN_400d7b54(iVar9,0);
    (*DAT_400d04dc)(5);
  }
  FUN_400d7b54(iVar6,0);
  FUN_400d7b54(iVar9,1);
  (*DAT_400d04dc)(5);
  FUN_400d7b54(iVar6,1);
  FUN_400d8728(param_1,iVar6,iVar9,1,1);
  FUN_400d7ff0(param_1);
  FUN_400e0b50(piVar4,param_1);
  uVar2 = DAT_400d022c;
  FUN_400f7ee4(piVar4,DAT_400d022c);
  FUN_400f7ed4(piVar4,uVar2);
  uVar1 = DAT_400d0228;
  puVar7 = *(uint **)(DAT_400d0438 + param_1 * 0x1c);
  memw();
  memw();
  *puVar7 = *puVar7 & DAT_400d0228 | uVar5 & 0x3fff;
  memw();
  memw();
  puVar7[0xe] = puVar7[0xe] & uVar1 | uVar8 & 0x3fff;
  memw();
  FUN_400f7f00(piVar4,uStack_38,uStack_3c);
  FUN_400e08f8(piVar4,uStack_30,uStack_34);
  FUN_400f7f38(piVar4,uStack_28,uStack_2c);
  FUN_400e089c(piVar4,auStack_24[0]);
  FUN_400f7e3c(piVar4,uStack_3d);
  return;
}



// Function at 0x400d8c50

undefined4 FUN_400d8c50(int param_1)

{
  undefined4 uVar1;
  undefined1 auStack_30 [48];
  
  if (param_1 == 0) {
    uVar1 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0440,DAT_400d04e4,uVar1,DAT_400d0440,DAT_400d04e0,0x496);
    uVar1 = 0x102;
  }
  else {
    func_0x40086818(auStack_30,0);
    uVar1 = FUN_400d80ac(param_1,auStack_30);
  }
  return uVar1;
}



// Function at 0x400d8c94

undefined4 FUN_400d8c94(int param_1)

{
  undefined4 uVar1;
  undefined4 auStack_30 [12];
  
  if (param_1 == 0) {
    uVar1 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0440,DAT_400d04e4,uVar1,DAT_400d0440,DAT_400d04e8,0x49e);
    uVar1 = 0x102;
  }
  else {
    func_0x40086818(auStack_30,0);
    auStack_30[0] = DAT_400d04ec;
    memw();
    uVar1 = FUN_400d80ac(param_1,auStack_30);
  }
  return uVar1;
}



// Function at 0x400d8ce0

undefined4 FUN_400d8ce0(int param_1,undefined1 param_2,uint param_3)

{
  undefined4 uVar1;
  uint uStack_30;
  undefined1 uStack_2c;
  undefined4 uStack_24;
  
  if (param_1 == 0) {
    uVar1 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0440,DAT_400d04e4,uVar1,DAT_400d0440,DAT_400d04f0,0x4bd);
    uVar1 = 0x102;
  }
  else {
    func_0x40086818(&uStack_30,0,0xc);
    uStack_30 = (param_3 & 1) << 8 | DAT_400d01f8;
    memw();
    uStack_24 = 1;
    memw();
    uStack_2c = param_2;
    uVar1 = FUN_400d80ac(param_1,&uStack_30);
  }
  return uVar1;
}



// Function at 0x400d8d44

undefined4 FUN_400d8d44(int param_1,undefined1 *param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uStack_30;
  undefined1 *puStack_2c;
  int iStack_24;
  
  if (param_2 == (undefined1 *)0x0) {
    uVar1 = func_0x4008d9f8();
    uVar3 = 0x4a6;
    uVar2 = DAT_400d0488;
  }
  else {
    if (param_1 != 0) {
      if (param_3 == 1) {
        uVar2 = FUN_400d8ce0(param_1,*param_2,param_4 & 0xff);
        return uVar2;
      }
      func_0x40086818(&uStack_30,0,0xc);
      uStack_30 = (param_4 & 1) << 8 | DAT_400d01f8;
      memw();
      puStack_2c = param_2;
      iStack_24 = param_3;
      uVar2 = FUN_400d80ac(param_1,&uStack_30);
      return uVar2;
    }
    uVar1 = func_0x4008d9f8();
    uVar3 = 0x4a7;
    memw();
    uVar2 = DAT_400d04e4;
  }
  memw();
  FUN_400e4a50(1,DAT_400d0440,uVar2,uVar1,DAT_400d0440,DAT_400d04f4,uVar3);
  return 0x102;
}



// Function at 0x400d8dd0

undefined4 FUN_400d8dd0(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uStack_30;
  int iStack_2c;
  undefined4 uStack_24;
  
  if (param_2 == 0) {
    uVar1 = func_0x4008d9f8();
    uVar3 = 0x4db;
    uVar2 = DAT_400d0488;
  }
  else if (param_1 == 0) {
    uVar1 = func_0x4008d9f8();
    uVar3 = 0x4dc;
    memw();
    uVar2 = DAT_400d04e4;
  }
  else {
    if (param_3 < 3) {
      func_0x40086818(&uStack_30,0,0xc);
      if (param_3 == 2) {
        param_3 = 1;
      }
      uStack_30 = (uStack_30 & 0xfffffbff | (param_3 & 1) << 10) & DAT_400d0500 | DAT_400d01d0;
      uStack_24 = 1;
      memw();
      iStack_2c = param_2;
      uVar2 = FUN_400d80ac(param_1,&uStack_30);
      return uVar2;
    }
    uVar1 = func_0x4008d9f8();
    uVar3 = 0x4dd;
    memw();
    uVar2 = DAT_400d04fc;
  }
  memw();
  FUN_400e4a50(1,DAT_400d0440,uVar2,uVar1,DAT_400d0440,DAT_400d04f8,uVar3);
  return 0x102;
}



// Function at 0x400d8e84

int FUN_400d8e84(int param_1,int param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uStack_30;
  int iStack_2c;
  int iStack_24;
  
  if (param_2 == 0) {
    uVar1 = func_0x4008d9f8();
    uVar5 = 0x4ed;
    uVar4 = DAT_400d0488;
  }
  else if (param_1 == 0) {
    uVar1 = func_0x4008d9f8();
    uVar5 = 0x4ee;
    memw();
    uVar4 = DAT_400d04e4;
  }
  else if (param_4 < 3) {
    if (param_3 != 0) {
      if (param_4 != 2) {
        func_0x40086818(&uStack_30,0,0xc);
        uStack_30 = (param_4 & 1) << 10 | DAT_400d01d0;
        memw();
        iStack_2c = param_2;
        iStack_24 = param_3;
        iVar2 = FUN_400d80ac(param_1,&uStack_30);
        return iVar2;
      }
      if (param_3 != 1) {
        func_0x40086818(&uStack_30,0,0xc);
        iVar3 = param_3 + -1;
        uStack_30 = DAT_400d01d0;
        memw();
        iStack_2c = param_2;
        iStack_24 = iVar3;
        iVar2 = FUN_400d80ac(param_1,&uStack_30);
        if (iVar2 != 0) {
          return iVar2;
        }
        param_3 = 1;
        param_2 = param_2 + iVar3;
      }
      iVar2 = FUN_400d8dd0(param_1,param_2,param_3);
      return iVar2;
    }
    uVar1 = func_0x4008d9f8();
    uVar5 = 0x4f0;
    memw();
    uVar4 = DAT_400d0508;
  }
  else {
    uVar1 = func_0x4008d9f8();
    uVar5 = 0x4ef;
    memw();
    uVar4 = DAT_400d04fc;
  }
  memw();
  FUN_400e4a50(1,DAT_400d0440,uVar4,uVar1,DAT_400d0440,DAT_400d0504,uVar5);
  return 0x102;
}



// Function at 0x400d8f78

undefined4 FUN_400d8f78(int param_1,int *param_2,uint param_3)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  bool bVar9;
  uint *puVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  undefined4 uVar14;
  int aiStack_24 [9];
  
  if (param_1 < 2) {
    iVar8 = *(int *)(DAT_400d0468 + param_1 * 4);
    if (iVar8 == 0) {
      uVar2 = func_0x4008d9f8();
      uVar14 = 0x592;
      uVar3 = DAT_400d0510;
    }
    else {
      if (*(int *)(iVar8 + 4) == 1) {
        if (param_2 == (int *)0x0) {
          uVar2 = func_0x4008d9f8();
          uVar14 = 0x594;
          memw();
          uVar3 = DAT_400d04e4;
          goto LAB_400d8f95;
        }
        if ((*(uint *)(iVar8 + 0x54) & 0x400) == 0) {
LAB_400d90bc:
          iVar4 = func_0x40089fe4();
          iVar5 = func_0x400896ec(*(undefined4 *)(iVar8 + 0xac),param_3);
          if (iVar5 == 0) {
            return 0x107;
          }
          func_0x40088f60(*(undefined4 *)(iVar8 + 0x4c),0);
          iVar5 = param_1 * 0x1c + DAT_400d0438;
          if ((*(int *)(iVar8 + 0x10) == 5) || (iVar6 = FUN_400f7fb0(iVar5), iVar6 != 0)) {
            FUN_400d8adc(param_1);
            *(undefined1 *)(DAT_400d052c + param_1) = 0;
            memw();
          }
          memw();
          FUN_400d8290(param_1);
          FUN_400d82e4(param_1);
          iVar11 = *param_2;
          iVar12 = param_2[2];
          iVar6 = param_2[1];
          *(undefined4 *)(iVar11 + 8) = 0;
          *(int *)(iVar8 + 0x3c) = iVar6;
          *(int *)(iVar8 + 0x38) = iVar11;
          *(undefined4 *)(iVar8 + 0xc) = 0;
          *(undefined4 *)(iVar8 + 0x14) = 0;
          *(int *)(iVar8 + 0x40) = iVar12;
          *(undefined4 *)(iVar8 + 0x10) = 2;
          memw();
          FUN_400d8290(param_1);
          FUN_400d82e4(param_1);
          uVar3 = DAT_400d022c;
          FUN_400f7ee4(iVar5,DAT_400d022c);
          FUN_400f7ed4(iVar5,uVar3);
          func_0x40081640(param_1,0);
          do {
            iVar5 = func_0x40089fe4();
            iVar6 = 1000;
            if ((uint)(iVar5 - iVar4) <= param_3) {
              uVar13 = (param_3 + iVar4) - iVar5;
              iVar6 = (uint)(uVar13 < 1000) * 1000 + (uVar13 >= 1000) * uVar13;
            }
            iVar5 = func_0x400895a0(*(undefined4 *)(iVar8 + 0x4c),aiStack_24,iVar6);
            if (iVar5 != 1) goto LAB_400d9181;
          } while (aiStack_24[0] != 1);
          if (*(int *)(iVar8 + 0x10) == 5) {
LAB_400d9181:
            FUN_400d8adc(param_1);
            *(undefined1 *)(DAT_400d052c + param_1) = 0;
            memw();
            uVar3 = 0x107;
          }
          else {
            uVar3 = 0;
            if (*(int *)(iVar8 + 0x10) == 3) {
              pbVar7 = (byte *)(DAT_400d052c + param_1);
              if ((byte)(*pbVar7 + 1) < 10) {
                *pbVar7 = *pbVar7 + 1;
                memw();
              }
              else {
                *pbVar7 = 0;
                memw();
                memw();
                FUN_400d8adc(param_1);
              }
              uVar3 = 0xffffffff;
              memw();
            }
          }
          *(undefined4 *)(iVar8 + 0x10) = 4;
          memw();
          func_0x40089194(*(undefined4 *)(iVar8 + 0xac),0,0);
          return uVar3;
        }
        bVar9 = true;
        for (puVar10 = (uint *)*param_2; puVar10 != (uint *)0x0; puVar10 = (uint *)puVar10[4]) {
          if (!bVar9) goto LAB_400d9040;
          bVar9 = true;
          if ((*puVar10 & DAT_400d0518) == DAT_400d01f8) {
            bVar1 = puVar10[3] != 1;
          }
          else {
            bVar1 = (*puVar10 & DAT_400d0518) == 0x1000;
          }
          if ((bVar1) && (uVar13 = puVar10[1], bVar9 = bVar1, uVar13 != 0)) {
            bVar9 = uVar13 + DAT_400d051c <= DAT_400d0520 || uVar13 + DAT_400d0524 <= DAT_400d028c;
          }
        }
        if (bVar9) goto LAB_400d90bc;
LAB_400d9040:
        uVar3 = func_0x4008d9f8();
        FUN_400e4a50(1,DAT_400d0440,DAT_400d0528,uVar3,DAT_400d0440);
        goto LAB_400d8f9d;
      }
      uVar2 = func_0x4008d9f8();
      uVar14 = 0x593;
      memw();
      uVar3 = DAT_400d0514;
    }
    memw();
    FUN_400e4a50(1,DAT_400d0440,uVar3,uVar2,DAT_400d0440,DAT_400d050c,uVar14);
    uVar3 = 0x103;
  }
  else {
    uVar2 = func_0x4008d9f8();
    uVar14 = 0x591;
    uVar3 = DAT_400d0464;
LAB_400d8f95:
    memw();
    FUN_400e4a50(1,DAT_400d0440,uVar3,uVar2,DAT_400d0440,DAT_400d050c,uVar14);
LAB_400d8f9d:
    uVar3 = 0x102;
  }
  return uVar3;
}



// Function at 0x400d91f4

int FUN_400d91f4(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  undefined1 auStack_d8 [12];
  undefined1 *puStack_cc;
  undefined4 uStack_c8;
  undefined1 auStack_c4 [160];
  int iStack_24;
  
  piVar1 = DAT_400d0098;
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  memw();
  func_0x40086818(auStack_d8,0,0xb4);
  puStack_cc = auStack_c4;
  uStack_c8 = 0xa0;
  memw();
  iVar2 = FUN_400d8c50(auStack_d8);
  if (((iVar2 == 0) && (iVar2 = FUN_400d8ce0(auStack_d8,(param_2 & 0x7f) << 1 | 1,1), iVar2 == 0))
     && (iVar2 = FUN_400d8e84(auStack_d8,param_3,param_4,2), iVar2 == 0)) {
    FUN_400d8c94(auStack_d8);
    iVar2 = FUN_400d8f78(param_1,auStack_d8,param_5);
  }
  memw();
  memw();
  if (iStack_24 != *piVar1) {
    func_0x400831d4();
  }
  return iVar2;
}



// Function at 0x400d9274

int FUN_400d9274(undefined4 param_1,char param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined1 auStack_d8 [12];
  undefined1 *puStack_cc;
  undefined4 uStack_c8;
  undefined1 auStack_c4 [160];
  int iStack_24;
  
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  memw();
  func_0x40086818(auStack_d8,0,0xb4);
  puStack_cc = auStack_c4;
  uStack_c8 = 0xa0;
  memw();
  iVar1 = FUN_400d8c50(auStack_d8);
  if (iVar1 == 0) {
    iVar1 = FUN_400d8ce0(auStack_d8,param_2 << 1,1);
    if ((((iVar1 == 0) && (iVar1 = FUN_400d8d44(auStack_d8,param_3,param_4,1), iVar1 == 0)) &&
        (iVar1 = FUN_400d8c50(auStack_d8), iVar1 == 0)) &&
       ((iVar1 = FUN_400d8ce0(auStack_d8,param_2 << 1 | 1,1), iVar1 == 0 &&
        (iVar1 = FUN_400d8e84(auStack_d8,param_5,param_6,2), iVar1 == 0)))) {
      FUN_400d8c94(auStack_d8);
      iVar1 = FUN_400d8f78(param_1,auStack_d8,param_7);
    }
  }
  memw();
  memw();
  if (iStack_24 != *DAT_400d0098) {
    iVar1 = func_0x400831d4();
    return iVar1;
  }
  return iVar1;
}



// Function at 0x400d931c

void FUN_400d931c(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_400d0530 + (param_1 * 8 + param_2) * 4);
  if (iVar1 != 0) {
    func_0x40089194(*(undefined4 *)(iVar1 + 0x18),0,0);
  }
  return;
}



// Function at 0x400d9340

int FUN_400d9340(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_400e327c();
  if (iVar1 == 0) {
    uVar2 = func_0x4008d9f8();
    FUN_400e4a50(1,DAT_400d0538,DAT_400d053c,uVar2,DAT_400d0538);
  }
  else {
    uVar2 = FUN_400e32d0();
    *DAT_400d0534 = uVar2;
  }
  memw();
  return iVar1;
}



// Function at 0x400d9374

undefined4 FUN_400d9374(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  
  uVar1 = DAT_400d0540;
  func_0x4008b620(DAT_400d0540,0xffffffff);
  puVar4 = (undefined4 *)(DAT_400d0544 + param_1 * 4);
  if (param_3 == 1) {
    piVar5 = (int *)*puVar4;
    iVar2 = *piVar5;
    iVar6 = 8;
    if (piVar5[1] == 1) {
      iVar6 = 0x10;
    }
    memw();
    uVar3 = 1 << 0x20 - (0x20 - (param_2 + iVar6 & 0x1fU)) | *(uint *)(iVar2 + 0x188);
  }
  else {
    piVar5 = (int *)*puVar4;
    iVar6 = 8;
    iVar2 = *piVar5;
    if (piVar5[1] == 1) {
      iVar6 = 0x10;
    }
    memw();
    uVar3 = (uint)(0xfffffffefffffffe >> 0x20 - (param_2 + iVar6 & 0x1fU)) &
            *(uint *)(iVar2 + 0x188);
  }
  memw();
  *(uint *)(iVar2 + 0x188) = uVar3;
  memw();
  func_0x4008b770(uVar1);
  return 0;
}



// Function at 0x400d93e8

void FUN_400d93e8(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_400d0530 + (param_1 * 8 + param_2) * 4);
  if (iVar1 != 0) {
    func_0x400896ec(*(undefined4 *)(iVar1 + 0x18),0xffffffff);
    FUN_400d9374(param_1,param_2,0);
  }
  return;
}



// Function at 0x400d9410

undefined4 FUN_400d9410(uint param_1,uint param_2,uint param_3,uint param_4,int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  uint *puVar4;
  undefined4 uVar5;
  
  uVar2 = DAT_400d0540;
  if (param_1 < 2) {
    if (param_2 < 4) {
      piVar3 = (int *)(DAT_400d0544 + param_1 * 4);
      if (*piVar3 == 0) {
        uVar2 = func_0x4008d9f8();
        memw();
        FUN_400e4a50(1,DAT_400d0538,DAT_400d0554,uVar2,DAT_400d0538,DAT_400d0548,0xca,DAT_400d0558);
        return 0x103;
      }
      memw();
      func_0x4008b620(DAT_400d0540,0xffffffff);
      piVar3 = (int *)*piVar3;
      puVar4 = (uint *)(*piVar3 + (piVar3[1] * 4 + param_2 + 0x28) * 8);
      memw();
      memw();
      *puVar4 = *puVar4 & DAT_400d0560 | (param_3 & DAT_400d055c) << 5;
      memw();
      memw();
      *puVar4 = *puVar4 & DAT_400d0274 | (uint)(param_5 == 1) << 0x19;
      memw();
      memw();
      *puVar4 = *puVar4 & 0xffffffe0 | param_4 & 0x1f;
      if (param_1 == 1) {
        puVar4 = (uint *)(**(int **)(DAT_400d0544 + 4) +
                         ((*(int **)(DAT_400d0544 + 4))[1] * 4 + param_2 + 0x28) * 8);
        memw();
        memw();
        *puVar4 = *puVar4 | DAT_400d0278;
      }
      memw();
      func_0x4008b770(uVar2);
      return 0;
    }
    uVar1 = func_0x4008d9f8();
    uVar5 = 0xc9;
    memw();
    uVar2 = DAT_400d0550;
  }
  else {
    uVar1 = func_0x4008d9f8();
    uVar5 = 200;
    uVar2 = DAT_400d054c;
  }
  memw();
  FUN_400e4a50(1,DAT_400d0538,uVar2,uVar1,DAT_400d0538,DAT_400d0548,uVar5);
  return 0x102;
}



// Function at 0x400d9548

undefined4 FUN_400d9548(int param_1,undefined4 param_2,int param_3,int param_4,uint param_5)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint local_28 [10];
  
  puVar8 = DAT_400d0534;
  if (param_3 == 0) {
    uVar5 = param_4 << 0x20 - (0x20 - (param_5 & 0x1f));
    uVar6 = uVar5 >> 1;
    memw();
    iVar2 = (*DAT_400d0248)(uVar6 + DAT_400d0564,uVar6 + DAT_400d0564 < uVar6,uVar5,0);
    param_3 = 3;
    if ((DAT_400d056c < iVar2 - 0x100U) && (param_3 = 1, param_1 == 0)) {
      iVar2 = (*DAT_400d0248)(uVar6 + DAT_400d0570,(uVar6 + DAT_400d0570 < uVar6) + '\x04',uVar5,0);
      param_3 = 1;
    }
    if ((DAT_400d056c < iVar2 - 0x100U) && (param_1 == 1)) {
      local_28[1] = 0;
      puVar8 = local_28;
      local_28[0] = 1;
      iVar2 = 0;
      do {
        puVar1 = DAT_400d0534;
        uVar7 = *puVar8;
        if (uVar7 == 0) {
          if (*DAT_400d0534 != 0) {
LAB_400d9694:
            uVar9 = *puVar1;
            goto LAB_400d95f9;
          }
          memw();
          iVar3 = FUN_400d9340();
          if (iVar3 != 0) goto LAB_400d9694;
        }
        else {
          uVar9 = 0;
          if (uVar7 == 1) {
            uVar9 = DAT_400d034c;
          }
LAB_400d95f9:
          uVar10 = uVar9 * 0x100 + uVar6;
          memw();
          iVar2 = (*DAT_400d0248)(uVar10,(uint)(uVar10 < uVar9 * 0x100) + (uVar9 >> 0x18),uVar5,0);
          if (iVar2 - 0x100U <= DAT_400d056c) goto LAB_400d9630;
        }
        puVar8 = puVar8 + 1;
      } while (local_28 + 2 != puVar8);
    }
LAB_400d95ec:
    uVar7 = 1;
  }
  else {
    if (param_3 != 2) {
      uVar7 = DAT_400d01e4;
      if ((param_3 != 3) && (uVar7 = DAT_400d034c, param_3 != 1)) {
        func_0x4008dacc(DAT_400d0588,0x1bc,DAT_400d0584,DAT_400d0580);
        uVar7 = DAT_400d01e4;
      }
      uVar6 = param_4 << 0x20 - (0x20 - (param_5 & 0x1f));
      uVar5 = uVar7 * 0x100 + (uVar6 >> 1);
      iVar2 = (*DAT_400d0248)(uVar5,(uint)(uVar5 < uVar7 * 0x100) + (uVar7 >> 0x18),uVar6,0);
      goto LAB_400d95ec;
    }
    if (param_1 != 1) {
      uVar4 = func_0x4008d9f8();
      memw();
      FUN_400e4a50(1,DAT_400d0538,DAT_400d057c,uVar4,DAT_400d0538,DAT_400d0578,0x1db);
      return 0x102;
    }
    if (*DAT_400d0534 == 0) {
      iVar3 = FUN_400d9340();
      iVar2 = 0;
      if (iVar3 == 0) goto LAB_400d9703;
    }
    uVar6 = param_4 << 0x20 - (0x20 - (param_5 & 0x1f));
    uVar7 = *puVar8 * 0x100;
    uVar5 = uVar7 + (uVar6 >> 1);
    iVar2 = (*DAT_400d0248)(uVar5,(uint)(uVar5 < uVar7) + (*puVar8 >> 0x18),uVar6,0);
    uVar7 = 0;
    param_3 = 1;
  }
LAB_400d9630:
  if (iVar2 - 0x100U <= DAT_400d056c) {
    if (param_1 == 1) {
      memw();
      FUN_400e3964(uVar7 == 0);
      uVar4 = DAT_400d0540;
      func_0x4008b620(DAT_400d0540,0xffffffff);
      memw();
      memw();
      *(uint *)(**(int **)(DAT_400d0544 + 4) + 400) =
           *(uint *)(**(int **)(DAT_400d0544 + 4) + 400) & 0xfffffffe | uVar7 & 1;
      memw();
      func_0x4008b770(uVar4);
    }
    FUN_400d9410(param_1,param_2,iVar2,param_5,param_3);
    return 0;
  }
LAB_400d9703:
  uVar4 = func_0x4008d9f8();
  FUN_400e4a50(1,DAT_400d0538,DAT_400d058c,uVar4,DAT_400d0538,iVar2);
  return 0xffffffff;
}



// Function at 0x400d9768

undefined4 FUN_400d9768(uint param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  uint *puVar4;
  undefined4 uVar5;
  
  uVar2 = DAT_400d0540;
  if (param_1 < 2) {
    if (param_3 < 4) {
      piVar3 = (int *)(DAT_400d0544 + param_1 * 4);
      if (*piVar3 == 0) {
        uVar2 = func_0x4008d9f8();
        memw();
        FUN_400e4a50(1,DAT_400d0538,DAT_400d0554,uVar2,DAT_400d0538,DAT_400d0590,0xef,DAT_400d0558);
        return 0x103;
      }
      func_0x4008b620(DAT_400d0540,0xffffffff);
      piVar3 = (int *)*piVar3;
      puVar4 = (uint *)(*piVar3 + param_2 * 0x14 + piVar3[1] * 0xa0);
      memw();
      memw();
      *puVar4 = *puVar4 & 0xfffffffc | param_3 & 3;
      if (param_1 == 1) {
        memw();
        func_0x40081a38(param_2);
      }
      func_0x4008b770(uVar2);
      return 0;
    }
    uVar1 = func_0x4008d9f8();
    uVar5 = 0xee;
    memw();
    uVar2 = DAT_400d0550;
  }
  else {
    uVar1 = func_0x4008d9f8();
    uVar5 = 0xed;
    uVar2 = DAT_400d054c;
  }
  memw();
  FUN_400e4a50(1,DAT_400d0538,uVar2,uVar1,DAT_400d0538,DAT_400d0590,uVar5);
  return 0x102;
}



// Function at 0x400d983c

undefined4 FUN_400d983c(uint param_1,uint param_2)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 uVar3;
  uint *puVar4;
  undefined4 uVar5;
  
  uVar3 = DAT_400d0540;
  if (param_1 < 2) {
    if (param_2 < 4) {
      piVar2 = (int *)(DAT_400d0544 + param_1 * 4);
      if (*piVar2 == 0) {
        uVar3 = func_0x4008d9f8();
        memw();
        FUN_400e4a50(1,DAT_400d0538,DAT_400d0554,uVar3,DAT_400d0538,DAT_400d0594,0xfb,DAT_400d0558);
        return 0x103;
      }
      func_0x4008b620(DAT_400d0540,0xffffffff);
      piVar2 = (int *)*piVar2;
      puVar4 = (uint *)(*piVar2 + (piVar2[1] * 4 + param_2 + 0x28) * 8);
      memw();
      memw();
      *puVar4 = *puVar4 | DAT_400d0598;
      memw();
      memw();
      *puVar4 = *puVar4 & DAT_400d059c;
      memw();
      func_0x4008b770(uVar3);
      return 0;
    }
    uVar1 = func_0x4008d9f8();
    uVar5 = 0xfa;
    memw();
    uVar3 = DAT_400d0550;
  }
  else {
    uVar1 = func_0x4008d9f8();
    uVar5 = 0xf9;
    uVar3 = DAT_400d054c;
  }
  memw();
  FUN_400e4a50(1,DAT_400d0538,uVar3,uVar1,DAT_400d0538,DAT_400d0594,uVar5);
  return 0x102;
}



// Function at 0x400d9910

int FUN_400d9910(uint *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if (param_1 == (uint *)0x0) {
    uVar1 = func_0x4008d9f8();
    uVar8 = 0x227;
    uVar2 = DAT_400d05a4;
    uVar7 = DAT_400d05a0;
  }
  else {
    uVar5 = *param_1;
    if (uVar5 < 2) {
      if ((param_1[4] == 2) && ((uVar5 & 1) == 0)) {
        uVar1 = func_0x4008d9f8();
        uVar8 = 0x22d;
        memw();
        uVar2 = DAT_400d05a8;
        uVar7 = DAT_400d05a0;
      }
      else {
        uVar8 = param_1[1];
        uVar7 = param_1[3];
        uVar6 = param_1[2];
        FUN_400da230(0);
        if ((uVar8 - 1 < 0x14) && (uVar7 != 0)) {
          if (3 < uVar6) {
            memw();
            uVar2 = func_0x4008d9f8();
            FUN_400e4a50(1,DAT_400d0538,DAT_400d05b0,uVar2,DAT_400d0538,uVar6);
            return 0x102;
          }
          piVar3 = (int *)(DAT_400d0544 + uVar5 * 4);
          if (*piVar3 == 0) {
            iVar4 = func_0x400842c4(1,8,DAT_400d0458);
            *piVar3 = iVar4;
            if (iVar4 == 0) {
              return 0x101;
            }
            memw();
            FUN_400e0834(iVar4,uVar5);
          }
          iVar4 = FUN_400d9548(uVar5,uVar6,param_1[4],uVar7,uVar8);
          if (iVar4 == 0) {
            FUN_400d983c(uVar5,uVar6);
            return 0;
          }
          return iVar4;
        }
        uVar1 = func_0x4008d9f8();
        memw();
        uVar2 = DAT_400d05ac;
      }
    }
    else {
      uVar1 = func_0x4008d9f8();
      uVar8 = 0x22c;
      memw();
      uVar2 = DAT_400d054c;
      uVar7 = DAT_400d05a0;
    }
  }
  memw();
  FUN_400e4a50(1,DAT_400d0538,uVar2,uVar1,DAT_400d0538,uVar7,uVar8);
  return 0x102;
}



// Function at 0x400d9a24

undefined4 FUN_400d9a24(uint param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  uint *puVar4;
  undefined4 uVar5;
  
  uVar2 = DAT_400d0540;
  if (param_1 < 2) {
    if (param_2 < 8) {
      piVar3 = (int *)(DAT_400d0544 + param_1 * 4);
      if (*piVar3 == 0) {
        uVar2 = func_0x4008d9f8();
        memw();
        FUN_400e4a50(1,DAT_400d0538,DAT_400d0554,uVar2,DAT_400d0538,DAT_400d05b4,0x288,DAT_400d0558)
        ;
        return 0x103;
      }
      func_0x4008b620(DAT_400d0540,0xffffffff);
      piVar3 = (int *)*piVar3;
      puVar4 = (uint *)(*piVar3 + param_2 * 0x14 + piVar3[1] * 0xa0);
      memw();
      memw();
      *puVar4 = *puVar4 | 4;
      memw();
      memw();
      puVar4[3] = puVar4[3] | DAT_400d0284;
      if (param_1 == 1) {
        memw();
        func_0x40081a38(param_2);
      }
      func_0x4008b770(uVar2);
      return 0;
    }
    uVar1 = func_0x4008d9f8();
    uVar5 = 0x287;
    memw();
    uVar2 = DAT_400d05b8;
  }
  else {
    uVar1 = func_0x4008d9f8();
    uVar5 = 0x286;
    uVar2 = DAT_400d054c;
  }
  memw();
  FUN_400e4a50(1,DAT_400d0538,uVar2,uVar1,DAT_400d0538,DAT_400d05b4,uVar5);
  return 0x102;
}



// Function at 0x400d9b04

undefined4 FUN_400d9b04(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_1 < 2) {
    if (param_2 < 8) {
      if (param_4 <= DAT_400d023c) {
        if (*(int *)(DAT_400d0544 + param_1 * 4) == 0) {
          uVar2 = func_0x4008d9f8();
          memw();
          FUN_400e4a50(1,DAT_400d0538,DAT_400d0554,uVar2,DAT_400d0538,DAT_400d05bc,700,DAT_400d0558)
          ;
          return 0x103;
        }
        FUN_400d93e8(param_1,param_2);
        memw();
        func_0x40081a4c(param_1,param_2,param_4,param_3,1,0,0,0);
        FUN_400d931c(param_1,param_2);
        return 0;
      }
      uVar1 = func_0x4008d9f8();
      uVar3 = 699;
      memw();
      uVar2 = DAT_400d05c0;
    }
    else {
      uVar1 = func_0x4008d9f8();
      uVar3 = 0x2ba;
      memw();
      uVar2 = DAT_400d05b8;
    }
  }
  else {
    uVar1 = func_0x4008d9f8();
    uVar3 = 0x2b9;
    uVar2 = DAT_400d054c;
  }
  memw();
  FUN_400e4a50(1,DAT_400d0538,uVar2,uVar1,DAT_400d0538,DAT_400d05bc,uVar3);
  return 0x102;
}



// Function at 0x400d9bd8

undefined4 FUN_400d9bd8(int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  
  if (param_1 == (int *)0x0) {
    uVar1 = func_0x4008d9f8();
    uVar14 = 0x255;
    uVar13 = DAT_400d05c8;
  }
  else {
    uVar5 = param_1[2];
    uVar4 = param_1[1];
    if (uVar5 < 8) {
      if (uVar4 < 2) {
        iVar6 = *param_1;
        uVar2 = (*DAT_400d0384)(DAT_400d0178,DAT_400d03b8,iVar6);
        if ((uVar2 & 1) == 0) {
          uVar1 = func_0x4008d9f8();
          uVar14 = 0x260;
          memw();
          uVar13 = DAT_400d05d0;
        }
        else {
          uVar2 = param_1[4];
          if (uVar2 < 4) {
            uVar7 = param_1[3];
            if (uVar7 < 2) {
              iVar9 = param_1[5];
              iVar10 = param_1[6];
              uVar11 = param_1[7];
              memw();
              FUN_400da230(0);
              piVar12 = (int *)(DAT_400d0544 + uVar4 * 4);
              if (*piVar12 == 0) {
                memw();
                iVar3 = func_0x400842c4(1,8,DAT_400d0458);
                *piVar12 = iVar3;
                if (iVar3 == 0) {
                  return 0x101;
                }
                memw();
                FUN_400e0834(iVar3,uVar4);
              }
              FUN_400d9b04(uVar4,uVar5,iVar9,iVar10);
              FUN_400d9a24(uVar4,uVar5);
              FUN_400d9768(uVar4,uVar5,uVar2);
              FUN_400d9374(uVar4,uVar5,uVar7);
              puVar8 = *(uint **)(DAT_400d02c4 + iVar6 * 4);
              if ((uint)((int)puVar8 + DAT_400d02a8) <= DAT_400d02ac) {
                func_0x4008dacc(DAT_400d05e0,0x27d,DAT_400d05dc,DAT_400d05d8);
              }
              memw();
              memw();
              *puVar8 = *puVar8 & DAT_400d02d4 | DAT_400d01e0;
              memw();
              FUN_400d7d04(iVar6,2);
              (*DAT_400d02dc)(iVar6,*(byte *)(DAT_400d05e4 + uVar4) + uVar5,uVar11 & 1,0);
              return 0;
            }
            uVar1 = func_0x4008d9f8();
            uVar14 = 0x262;
            memw();
            uVar13 = DAT_400d05d4;
          }
          else {
            uVar1 = func_0x4008d9f8();
            uVar14 = 0x261;
            memw();
            uVar13 = DAT_400d0550;
          }
        }
      }
      else {
        uVar1 = func_0x4008d9f8();
        uVar14 = 0x25f;
        memw();
        uVar13 = DAT_400d054c;
      }
    }
    else {
      uVar1 = func_0x4008d9f8();
      uVar14 = 0x25e;
      memw();
      uVar13 = DAT_400d05cc;
    }
  }
  memw();
  FUN_400e4a50(1,DAT_400d0538,uVar13,uVar1,DAT_400d0538,DAT_400d05c4,uVar14);
  return 0x102;
}



// Function at 0x400d9d8c

undefined4 FUN_400d9d8c(uint param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_1 < 2) {
    if (param_2 < 8) {
      if (*(int *)(DAT_400d0544 + param_1 * 4) == 0) {
        uVar2 = func_0x4008d9f8();
        memw();
        FUN_400e4a50(1,DAT_400d0538,DAT_400d0554,uVar2,DAT_400d0538,DAT_400d05e8,0x2d0,DAT_400d0558)
        ;
        return 0x103;
      }
      FUN_400d93e8(param_1,param_2);
      memw();
      func_0x40081a4c(param_1,param_2,0xffffffff,param_3,1,0,0,0);
      FUN_400d931c(param_1,param_2);
      return 0;
    }
    uVar1 = func_0x4008d9f8();
    uVar3 = 0x2cf;
    memw();
    uVar2 = DAT_400d05b8;
  }
  else {
    uVar1 = func_0x4008d9f8();
    uVar3 = 0x2ce;
    uVar2 = DAT_400d054c;
  }
  memw();
  FUN_400e4a50(1,DAT_400d0538,uVar2,uVar1,DAT_400d0538,DAT_400d05e8,uVar3);
  return 0x102;
}



// Function at 0x400d9e3c

undefined4 FUN_400d9e3c(uint param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 auStack_24 [9];
  
  if (param_1 < 2) {
    if (param_2 < 8) {
      iVar3 = *(int *)(DAT_400d0544 + param_1 * 4);
      if (iVar3 == 0) {
        uVar2 = func_0x4008d9f8();
        memw();
        FUN_400e4a50(1,DAT_400d0538,DAT_400d0554,uVar2,DAT_400d0538,DAT_400d05ec,0x2e4,DAT_400d0558)
        ;
        return 0x103;
      }
      auStack_24[0] = 0;
      memw();
      func_0x4008bd4c(iVar3,param_2,auStack_24);
      return auStack_24[0];
    }
    uVar1 = func_0x4008d9f8();
    uVar4 = 0x2e3;
    memw();
    uVar2 = DAT_400d05b8;
  }
  else {
    uVar1 = func_0x4008d9f8();
    uVar4 = 0x2e2;
    uVar2 = DAT_400d054c;
  }
  memw();
  FUN_400e4a50(1,DAT_400d0538,uVar2,uVar1,DAT_400d0538,DAT_400d05ec,uVar4);
  return 0x102;
}



// Function at 0x400d9ed8

undefined4 FUN_400d9ed8(uint param_1,uint param_2)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  int aiStack_24 [9];
  
  uVar3 = DAT_400d0540;
  if (param_1 < 2) {
    if (param_2 < 4) {
      piVar2 = (int *)(DAT_400d0544 + param_1 * 4);
      if (*piVar2 == 0) {
        uVar3 = func_0x4008d9f8();
        memw();
        FUN_400e4a50(1,DAT_400d0538,DAT_400d0554,uVar3,DAT_400d0538,DAT_400d05f0,0x304,DAT_400d0558)
        ;
        return 0x103;
      }
      func_0x4008b620(DAT_400d0540,0xffffffff);
      piVar2 = (int *)*piVar2;
      puVar7 = (uint *)(*piVar2 + (piVar2[1] * 4 + param_2 + 0x28) * 8);
      memw();
      uVar4 = *puVar7;
      memw();
      uVar6 = *puVar7;
      aiStack_24[0] = 1;
      memw();
      FUN_400f7dfc(piVar2,param_2,aiStack_24);
      uVar5 = DAT_400d034c;
      if (aiStack_24[0] != 1) {
        if (aiStack_24[0] == 2) {
          uVar5 = *DAT_400d0534;
        }
        else {
          uVar5 = 0;
          if (aiStack_24[0] == 3) {
            uVar5 = DAT_400d01e4;
          }
        }
      }
      func_0x4008b770(uVar3);
      uVar8 = (*DAT_400d0248)(uVar5 << 8,uVar5 >> 0x18,1 << 0x20 - (0x20 - (uVar6 & 0x1f)),0);
      uVar3 = (*DAT_400d0248)((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(uVar4 << 9) >> 0xe,0);
      return uVar3;
    }
    uVar1 = func_0x4008d9f8();
    uVar9 = 0x303;
    memw();
    uVar3 = DAT_400d05f4;
  }
  else {
    uVar1 = func_0x4008d9f8();
    uVar9 = 0x302;
    uVar3 = DAT_400d054c;
  }
  memw();
  FUN_400e4a50(1,DAT_400d0538,uVar3,uVar1,DAT_400d0538,DAT_400d05f0,uVar9);
  return 0x102;
}



// Function at 0x400d9fe8

undefined4 FUN_400d9fe8(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 2;
  if (param_1 != 0x10) {
    if (param_1 < 0x11) {
      uVar1 = DAT_400d05fc;
      if (param_1 != 7) {
        if (param_1 < 8) {
          uVar1 = DAT_400d05f8;
          if (param_1 != 3) {
            if (param_1 < 4) {
              uVar1 = 4;
              if ((param_1 != 1) && (uVar1 = 0x20, param_1 < 2)) {
                uVar1 = DAT_400d01f8;
              }
            }
            else {
              uVar1 = DAT_400d0260;
              if ((param_1 != 5) && (uVar1 = 0x10, param_1 < 6)) {
                uVar1 = 0x80;
              }
            }
          }
        }
        else {
          uVar1 = DAT_400d0608;
          if (param_1 != 0xb) {
            if (param_1 < 0xc) {
              uVar1 = DAT_400d0600;
              if ((param_1 != 9) && (uVar1 = DAT_400d0604, param_1 < 10)) {
                uVar1 = DAT_400d01e0;
              }
            }
            else {
              uVar1 = DAT_400d01d0;
              if ((((param_1 != 0xd) && (uVar1 = 0x100, 0xc < param_1)) &&
                  (uVar1 = 0x200, param_1 != 0xe)) && (uVar1 = 0x400, param_1 != 0xf)) {
                uVar1 = 0;
              }
            }
          }
        }
      }
    }
    else {
      uVar1 = DAT_400d0600;
      if (param_1 != 0x18) {
        if (param_1 < 0x19) {
          if (param_1 == 0x14) {
            return DAT_400d01e0;
          }
          if (param_1 < 0x15) {
            if (param_1 == 0x12) {
              return DAT_400d060c;
            }
            if (param_1 < 0x13) {
              return 0x40;
            }
            return DAT_400d0610;
          }
          if (param_1 == 0x16) {
            return DAT_400d0614;
          }
          uVar1 = 0x10;
          if (0x16 < param_1) {
            return DAT_400d0134;
          }
        }
        else {
          if (param_1 == 0x1c) {
            return DAT_400d01f8;
          }
          if (param_1 < 0x1d) {
            if (param_1 == 0x1a) {
              return DAT_400d0618;
            }
            if (param_1 < 0x1b) {
              return 0x406;
            }
            return 0x3c9;
          }
          if (param_1 == 0x1e) {
            return 1;
          }
          if (param_1 < 0x1e) {
            return DAT_400d061c;
          }
          if (param_1 == 0x1f) {
            return 2;
          }
          uVar1 = 0;
          if (param_1 == 0x20) {
            uVar1 = 4;
          }
        }
      }
    }
  }
  return uVar1;
}



// Function at 0x400da100

undefined4 FUN_400da100(uint param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_1 == 0xd) {
    return DAT_400d01d0;
  }
  if (param_1 < 0xe) {
    if (param_1 == 6) {
      return 0x10;
    }
    if (6 < param_1) {
      if (param_1 == 9) {
        return DAT_400d0600;
      }
      if (9 < param_1) {
        if (param_1 == 0xb) {
          return DAT_400d0608;
        }
        if (0xb < param_1) {
          return 0x100;
        }
        return DAT_400d0604;
      }
      if (param_1 == 7) {
        return DAT_400d05fc;
      }
      if (param_1 == 8) {
        return DAT_400d01e0;
      }
      return 0;
    }
    if (param_1 == 2) {
      return 0x20;
    }
    if (2 < param_1) {
      if (param_1 == 4) {
        return 0x80;
      }
      if (4 < param_1) {
        return DAT_400d0260;
      }
      return DAT_400d05f8;
    }
    if (param_1 == 0) {
      return DAT_400d01f8;
    }
    iVar1 = param_1 - 1;
    uVar3 = 4;
  }
  else {
    if (param_1 == 0x14) {
      return 0x40;
    }
    if (param_1 < 0x15) {
      if (param_1 == 0x10) {
        return 2;
      }
      if (0x10 < param_1) {
        if (param_1 == 0x12) {
          return DAT_400d060c;
        }
        if (0x12 < param_1) {
          return DAT_400d0610;
        }
        return 0x40;
      }
      if (param_1 == 0xe) {
        return 0x200;
      }
      iVar1 = param_1 - 0xf;
      uVar3 = 0x400;
    }
    else {
      if (param_1 == 0x19) {
        return 4;
      }
      if (0x19 < param_1) {
        if (param_1 == 0x1f) {
          if (param_2 != 0) {
            return 10;
          }
          return 2;
        }
        if (param_1 == 0x20) {
          if (param_2 == 0) {
            return 4;
          }
          return 0x14;
        }
        if (param_1 != 0x1e) {
          return 0;
        }
        if (param_2 == 0) {
          return 1;
        }
        return 0x19;
      }
      if (param_1 == 0x16) {
        return DAT_400d0614;
      }
      if (param_1 < 0x16) {
        return 0x20;
      }
      iVar1 = param_1 - 0x17;
      uVar3 = 0x80;
    }
  }
  uVar2 = 0;
  if (iVar1 == 0) {
    uVar2 = uVar3;
  }
  return uVar2;
}



// Function at 0x400da200

undefined4 FUN_400da200(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x1e) {
    uVar1 = DAT_400d0628;
    if ((param_1 < 0x17) && (uVar1 = DAT_400d0620, param_1 - 0x14 < 2)) {
      uVar1 = DAT_400d0628;
    }
  }
  else {
    uVar1 = DAT_400d0620;
    if (param_1 < 0x21) {
      uVar1 = DAT_400d0624;
    }
  }
  return uVar1;
}



// Function at 0x400da230

void FUN_400da230(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  if (0x21 < param_1) {
    func_0x4008dacc(DAT_400d0640,0x11,DAT_400d063c,DAT_400d0638);
  }
  func_0x4008b5f8();
  uVar1 = DAT_400d0644;
  func_0x4008b620(DAT_400d0644,0xffffffff);
  iVar2 = DAT_400d0648;
  if (*(char *)(DAT_400d0648 + param_1) == '\0') {
    if (param_1 < 0x1e) {
      puVar5 = DAT_400d0634;
      if ((param_1 < 0x17) && (puVar5 = DAT_400d062c, param_1 - 0x14 < 2)) {
        puVar5 = DAT_400d0634;
      }
    }
    else {
      puVar5 = DAT_400d062c;
      if (param_1 < 0x21) {
        puVar5 = DAT_400d0630;
      }
    }
    uVar3 = func_0x40084644(puVar5);
    uVar4 = FUN_400d9fe8(param_1);
    memw();
    *puVar5 = uVar3 | uVar4;
    memw();
    puVar5 = (uint *)FUN_400da200(param_1);
    uVar3 = func_0x40084644();
    uVar4 = FUN_400da100(param_1,1);
    memw();
    *puVar5 = (uVar4 ^ 0xffffffff) & uVar3;
  }
  *(char *)(iVar2 + param_1) = *(char *)(iVar2 + param_1) + '\x01';
  memw();
  memw();
  func_0x4008b5f8();
  func_0x4008b770(uVar1);
  return;
}



// Function at 0x400da2dc

void FUN_400da2dc(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  char cVar5;
  
  if (0x21 < param_1) {
    func_0x4008dacc(DAT_400d0640,0x1c,DAT_400d064c,DAT_400d0638);
  }
  func_0x4008b5f8();
  uVar1 = DAT_400d0644;
  func_0x4008b620(DAT_400d0644,0xffffffff);
  cVar5 = *(char *)(DAT_400d0648 + param_1) + -1;
  *(char *)(DAT_400d0648 + param_1) = cVar5;
  memw();
  if (cVar5 == '\0') {
    if (param_1 < 0x1e) {
      puVar4 = DAT_400d0634;
      if ((param_1 < 0x17) && (puVar4 = DAT_400d062c, param_1 - 0x14 < 2)) {
        puVar4 = DAT_400d0634;
      }
    }
    else {
      puVar4 = DAT_400d062c;
      if (param_1 < 0x21) {
        puVar4 = DAT_400d0630;
      }
    }
    memw();
    uVar2 = func_0x40084644(puVar4);
    uVar3 = FUN_400d9fe8(param_1);
    memw();
    *puVar4 = (uVar3 ^ 0xffffffff) & uVar2;
    memw();
    puVar4 = (uint *)FUN_400da200(param_1);
    uVar2 = func_0x40084644();
    uVar3 = FUN_400da100(param_1,0);
    memw();
    *puVar4 = uVar2 | uVar3;
  }
  memw();
  func_0x4008b5f8();
  func_0x4008b770(uVar1);
  return;
}



// Function at 0x400da38c

void FUN_400da38c(uint param_1)

{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  if (0x21 < param_1) {
    func_0x4008dacc(DAT_400d0640,0x27,DAT_400d0650,DAT_400d0638);
  }
  func_0x4008b5f8();
  uVar1 = DAT_400d0644;
  func_0x4008b620(DAT_400d0644,0xffffffff);
  puVar2 = (uint *)FUN_400da200(param_1);
  uVar3 = func_0x40084644();
  uVar4 = FUN_400da100(param_1,0);
  memw();
  *puVar2 = uVar3 | uVar4;
  memw();
  uVar3 = func_0x40084644(puVar2);
  memw();
  *puVar2 = (uVar4 ^ 0xffffffff) & uVar3;
  memw();
  func_0x4008b5f8();
  func_0x4008b770(uVar1);
  return;
}



// Function at 0x400da3f0

uint FUN_400da3f0(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 < 0x28) {
    uVar1 = (*(uint *)(DAT_400d0364 + param_1 * 4) ^ 0xffffffff) >> 0x1f;
  }
  return uVar1;
}



// Function at 0x400da410

undefined4 FUN_400da410(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  int *piVar4;
  int *in_t0;
  
  iVar1 = FUN_400da3f0(param_1);
  uVar2 = DAT_400d0660;
  if (iVar1 == 0) {
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0658,DAT_400d065c,uVar2,DAT_400d0658,DAT_400d0654,0x28);
    uVar2 = 0x102;
  }
  else {
    func_0x4008b620(DAT_400d0660,0xffffffff);
    piVar4 = (int *)(DAT_400d0664 + *(int *)(DAT_400d0364 + param_1 * 4) * 0x38);
    puVar3 = (uint *)*piVar4;
    if ((uint)((int)puVar3 + DAT_400d02a8) <= DAT_400d02ac) {
      piVar4 = in_t0;
      func_0x4008dacc(DAT_400d0670,0x3a,DAT_400d066c,DAT_400d0668);
    }
    memw();
    memw();
    *puVar3 = (piVar4[1] ^ 0xffffffffU) & *puVar3;
    memw();
    func_0x4008b770(uVar2);
    uVar2 = 0;
  }
  return uVar2;
}



// Function at 0x400da4a0

undefined4 FUN_400da4a0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  int *piVar4;
  uint uVar5;
  uint in_t0;
  
  iVar1 = FUN_400da3f0(param_1);
  uVar2 = DAT_400d0660;
  if (iVar1 == 0) {
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0658,DAT_400d065c,uVar2,DAT_400d0658,DAT_400d0674,0x6d);
    uVar2 = 0x102;
  }
  else {
    func_0x4008b620(DAT_400d0660,0xffffffff);
    piVar4 = (int *)(DAT_400d0664 + *(int *)(DAT_400d0364 + param_1 * 4) * 0x38);
    uVar5 = piVar4[4];
    if (uVar5 != 0) {
      puVar3 = (uint *)*piVar4;
      if ((uint)((int)puVar3 + DAT_400d02a8) <= DAT_400d02ac) {
        uVar5 = in_t0;
        func_0x4008dacc(DAT_400d0670,0xab,DAT_400d067c,DAT_400d0678);
      }
      memw();
      memw();
      *puVar3 = uVar5 | *puVar3;
    }
    memw();
    func_0x4008b770(uVar2);
    uVar2 = 0;
  }
  return uVar2;
}



// Function at 0x400da530

undefined4 FUN_400da530(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  int *piVar4;
  uint uVar5;
  
  iVar1 = FUN_400da3f0(param_1);
  uVar2 = DAT_400d0660;
  if (iVar1 == 0) {
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0658,DAT_400d065c,uVar2,DAT_400d0658,DAT_400d0680,0x77);
    uVar2 = 0x102;
  }
  else {
    func_0x4008b620(DAT_400d0660,0xffffffff);
    piVar4 = (int *)(DAT_400d0664 + *(int *)(DAT_400d0364 + param_1 * 4) * 0x38);
    uVar5 = piVar4[4];
    if (uVar5 != 0) {
      puVar3 = (uint *)*piVar4;
      if ((uint)((int)puVar3 + DAT_400d02a8) <= DAT_400d02ac) {
        uVar5 = func_0x4008dacc(DAT_400d0670,0xb7,DAT_400d0684,DAT_400d0668);
      }
      memw();
      memw();
      *puVar3 = (uVar5 ^ 0xffffffff) & *puVar3;
    }
    memw();
    func_0x4008b770(uVar2);
    uVar2 = 0;
  }
  return uVar2;
}



// Function at 0x400da5c4

undefined4 FUN_400da5c4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  int *piVar4;
  uint uVar5;
  uint in_t0;
  
  iVar1 = FUN_400da3f0(param_1);
  uVar2 = DAT_400d0660;
  if (iVar1 == 0) {
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0658,DAT_400d065c,uVar2,DAT_400d0658,DAT_400d0688,0x81);
    uVar2 = 0x102;
  }
  else {
    func_0x4008b620(DAT_400d0660,0xffffffff);
    piVar4 = (int *)(DAT_400d0664 + *(int *)(DAT_400d0364 + param_1 * 4) * 0x38);
    uVar5 = piVar4[5];
    if (uVar5 != 0) {
      puVar3 = (uint *)*piVar4;
      if ((uint)((int)puVar3 + DAT_400d02a8) <= DAT_400d02ac) {
        uVar5 = in_t0;
        func_0x4008dacc(DAT_400d0670,0xc3,DAT_400d068c,DAT_400d0678);
      }
      memw();
      memw();
      *puVar3 = uVar5 | *puVar3;
    }
    memw();
    func_0x4008b770(uVar2);
    uVar2 = 0;
  }
  return uVar2;
}



// Function at 0x400da654

undefined4 FUN_400da654(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint *puVar3;
  int *piVar4;
  uint uVar5;
  
  iVar1 = FUN_400da3f0(param_1);
  uVar2 = DAT_400d0660;
  if (iVar1 == 0) {
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0658,DAT_400d065c,uVar2,DAT_400d0658,DAT_400d0690,0x8b);
    uVar2 = 0x102;
  }
  else {
    func_0x4008b620(DAT_400d0660,0xffffffff);
    piVar4 = (int *)(DAT_400d0664 + *(int *)(DAT_400d0364 + param_1 * 4) * 0x38);
    uVar5 = piVar4[5];
    if (uVar5 != 0) {
      puVar3 = (uint *)*piVar4;
      if ((uint)((int)puVar3 + DAT_400d02a8) <= DAT_400d02ac) {
        uVar5 = func_0x4008dacc(DAT_400d0670,0xcf,DAT_400d0694,DAT_400d0668);
      }
      memw();
      memw();
      *puVar3 = (uVar5 ^ 0xffffffff) & *puVar3;
    }
    memw();
    func_0x4008b770(uVar2);
    uVar2 = 0;
  }
  return uVar2;
}



// Function at 0x400da7b8

undefined4 FUN_400da7b8(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(DAT_400d06b4 + param_1 * 4);
  iVar3 = *(int *)(iVar2 + 0xb4) + 1;
  if (*(int *)(iVar2 + 0xbc) <= iVar3) {
    iVar3 = 0;
  }
  uVar1 = 0xffffffff;
  if (*(int *)(iVar2 + 0xb8) != iVar3) {
    uVar1 = 0;
    *(undefined4 *)(*(int *)(iVar2 + 0xc0) + *(int *)(iVar2 + 0xb4) * 4) = param_2;
    *(int *)(iVar2 + 0xb4) = iVar3;
  }
  memw();
  return uVar1;
}



// Function at 0x400da7f0

undefined4 FUN_400da7f0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = *(int *)(DAT_400d06b4 + param_1 * 4);
  iVar1 = *(int *)(iVar2 + 0xb8);
  while (*(int *)(iVar2 + 0xb4) != iVar1) {
    piVar4 = (int *)(*(int *)(iVar2 + 0xc0) + iVar1 * 4);
    iVar1 = iVar1 + 1;
    iVar3 = *piVar4 - param_2;
    *piVar4 = iVar3;
    if (*(int *)(iVar2 + 0xbc) <= iVar1) {
      iVar1 = 0;
    }
    if (iVar3 < 0) {
      *(int *)(iVar2 + 0xb8) = iVar1;
      memw();
    }
  }
  return 0;
}



// Function at 0x400da834

undefined4 FUN_400da834(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(DAT_400d02d8 + (param_1 * 6 + param_3) * 4);
  uVar1 = 0;
  if ((((uVar2 & DAT_400d06b8) != DAT_400d06b8) && ((uVar2 & 0x7fff) != DAT_400d06bc)) &&
     (uVar3 = (uint)(short)((int)(uVar2 << 0x11) >> 0x11), uVar3 == param_2)) {
    FUN_400d7f64(uVar3 & 0xff,(int)(uVar2 << 0xd) >> 0x1c,0);
    uVar1 = 1;
    if ((uVar2 & 0x80000) != 0) {
      FUN_400d7f00(uVar3,uVar2 >> 0x14);
      uVar1 = 1;
    }
  }
  return uVar1;
}



// Function at 0x400da888

void FUN_400da888(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar1 = DAT_400d06c0;
  iVar3 = param_1 * 0x10;
  iVar2 = iVar3 + 4 + DAT_400d06c0;
  iVar4 = DAT_400d06c0 + iVar3;
  func_0x4008b620(iVar2,0xffffffff);
  if (*(char *)(iVar4 + 0xc) == '\0') {
    uVar5 = *(undefined4 *)(DAT_400d02d8 + param_1 * 0x18 + 0x14);
    FUN_400da230(uVar5);
    if (param_1 != 0) {
      FUN_400da38c(uVar5);
    }
    *(undefined1 *)(iVar1 + iVar3 + 0xc) = 1;
    memw();
  }
  memw();
  func_0x4008b770(iVar2);
  return;
}



// Function at 0x400da8d4

undefined4 FUN_400da8d4(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 auStack_24 [9];
  
  iVar2 = DAT_400d06c0;
  iVar4 = param_1 * 0x10;
  auStack_24[0] = 0;
  memw();
  func_0x4008b5f8();
  iVar3 = iVar4 + 4 + iVar2;
  func_0x4008b620(iVar3,0xffffffff);
  uVar1 = DAT_400d0134;
  if (*(int *)(*(int *)(DAT_400d06b4 + param_1 * 4) + 0xc) == 1) {
    iVar5 = *(int *)(iVar2 + iVar4);
    memw();
    memw();
    *(uint *)(iVar5 + 0x20) = *(uint *)(iVar5 + 0x20) & 0xffffffbf;
    memw();
    *(uint *)(iVar5 + 0x10) = uVar1;
    memw();
    memw();
    *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | uVar1;
  }
  memw();
  FUN_400e11ec(iVar2 + iVar4,param_2,param_3,auStack_24);
  func_0x4008b5f8();
  func_0x4008b770(iVar3);
  return auStack_24[0];
}



// Function at 0x400da948

void FUN_400da948(byte *param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  uint uVar15;
  uint local_50;
  int iStack_4c;
  undefined4 uStack_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  byte bStack_24;
  
  uVar4 = (uint)*param_1;
  iVar5 = uVar4 * 0x10;
  piVar11 = (int *)(iVar5 + DAT_400d06c0);
  local_50 = 0;
  iStack_4c = 0;
  iVar3 = iVar5 + 4 + DAT_400d06c0;
LAB_400da966:
  do {
    while( true ) {
      uVar10 = DAT_400d06d8;
      uVar14 = DAT_400d06cc;
      iVar13 = DAT_400d06c0;
      iVar9 = DAT_400d06b4;
      uVar15 = DAT_400d0260;
      uVar7 = DAT_400d01e0;
      iVar12 = *piVar11;
      memw();
      uVar8 = *(uint *)(iVar12 + 8);
      if (uVar8 == 0) {
        if (iStack_4c == 1) {
          func_0x40084c6c(0);
        }
        return;
      }
      uStack_2c = 8;
      if ((uVar8 & 2) == 0) break;
      memw();
      func_0x4008b620(iVar3,0xffffffff);
      memw();
      memw();
      *(uint *)(*piVar11 + 0xc) = *(uint *)(*piVar11 + 0xc) & 0xfffffffd;
      memw();
      func_0x4008b770(iVar3);
      iVar9 = *piVar11;
      memw();
      *(undefined4 *)(iVar9 + 0x10) = 2;
      if (param_1[0xde] == 0) {
        if (param_1[200] != 0) {
          if (*(int *)(param_1 + 0xc4) != 0) goto LAB_400da9d8;
          uVar14 = *(undefined4 *)(param_1 + 0xf8);
          param_1[200] = 0;
          memw();
          goto LAB_400da9ca;
        }
        if (*(int *)(param_1 + 0xc4) != 0) {
LAB_400da9d8:
          memw();
          uStack_44 = *(uint *)(iVar9 + 0x1c);
          memw();
          memw();
          uVar7 = 0x80 - (uStack_44 >> 0x10 & 0xff);
          bVar2 = true;
          bVar1 = false;
LAB_400da9f5:
          if (uVar7 != 0) {
            if (((*(int *)(param_1 + 0xd4) != 0) && (*(int *)(param_1 + 0xcc) != 0)) &&
               (*(int *)(param_1 + 0xd8) != 0)) goto LAB_400daa95;
            piVar6 = (int *)func_0x400886f0(*(undefined4 *)(param_1 + 0xec),&uStack_48);
            *(int **)(param_1 + 0xd0) = piVar6;
            if (piVar6 != (int *)0x0) goto code_r0x400daa5a;
          }
          if (bVar1) {
            piVar6 = (int *)(DAT_400d06c0 + iVar5);
            memw();
            *(undefined4 *)(*piVar6 + 0x10) = 2;
            memw();
            func_0x4008b620(iVar3,0xffffffff);
            iVar9 = *piVar6;
            memw();
            memw();
            *(uint *)(iVar9 + 0xc) = *(uint *)(iVar9 + 0xc) | 2;
            goto LAB_400daa24;
          }
          goto LAB_400daa2c;
        }
      }
    }
    if ((uVar8 & DAT_400d06c4) != 0) {
      if (*DAT_400d06c8 == '\x01') {
        uVar8 = uVar8 | DAT_400d0260;
        *DAT_400d06c8 = '\0';
        memw();
      }
      uVar7 = uVar8 & uVar15;
      if (param_1[0x1c] != 0) {
        memw();
        func_0x4008b620(iVar3,0xffffffff);
        piVar6 = (int *)(DAT_400d06c0 + iVar5);
        iVar9 = *piVar6;
        memw();
        memw();
        *(uint *)(iVar9 + 0xc) = *(uint *)(iVar9 + 0xc) & 0xfffffefe;
        memw();
        func_0x4008b770(iVar3);
        iVar9 = *piVar6;
        memw();
        *(undefined4 *)(iVar9 + 0x10) = 0x101;
        if (uVar7 == 0) goto LAB_400daa2c;
        memw();
        *(uint *)(iVar9 + 0x10) = uVar15;
        uStack_2c = 7;
        uStack_28 = local_50;
        *DAT_400d06c8 = '\x01';
        memw();
        goto LAB_400dae04;
      }
      memw();
      uStack_3c = *(uint *)(iVar12 + 0x1c);
      memw();
      memw();
      memw();
      uStack_40 = *(uint *)(iVar12 + 0x60);
      memw();
      memw();
      memw();
      if ((uStack_40 >> 2 & 0x7ff) < (uStack_40 >> 0xd & 0x7ff)) {
        memw();
        memw();
        local_50 = (uStack_40 >> 0xd & 0x7ff) - (uStack_40 >> 2 & 0x7ff);
      }
      else {
        memw();
        memw();
        if ((uStack_40 >> 0xd & 0x7ff) < (uStack_40 >> 2 & 0x7ff)) {
          memw();
          memw();
          local_50 = ((uStack_40 >> 0xd & 0x7ff) + 0x80) - (uStack_40 >> 2 & 0x7ff);
        }
        else {
          local_50 = 0;
          if ((uStack_3c & 0xff) != 0) {
            local_50 = 0x80;
          }
        }
      }
      if ((*(char *)(*(int *)(DAT_400d06b4 + uVar4 * 4) + 0x11) != '\0') && ((uVar8 & 0x100) == 0))
      {
        local_50 = local_50 - 1;
      }
      memw();
      FUN_400e1248(piVar11,param_1 + 0x2c,&local_50);
      uVar14 = DAT_400d06cc;
      iVar9 = *(int *)(DAT_400d06c0 + iVar5);
      memw();
      uStack_38 = *(uint *)(iVar9 + 0x54);
      memw();
      memw();
      memw();
      uStack_34 = *(uint *)(iVar9 + 0x54);
      memw();
      memw();
      uVar15 = uStack_34 >> 8 & 0xff;
      if (uVar7 == 0) {
        bStack_24 = (byte)(uVar8 >> 8) & 1;
        memw();
        memw();
        *(undefined4 *)(iVar9 + 0x10) = 0x101;
        uStack_28 = local_50;
        memw();
        uStack_2c = uVar7;
        func_0x4008b620(uVar14,0xffffffff);
        if (*(code **)(param_1 + 0xe0) != (code *)0x0) {
          (**(code **)(param_1 + 0xe0))(uVar4,0,&iStack_4c);
        }
        func_0x4008b770(uVar14);
        uVar10 = 0xffffffff;
      }
      else {
        memw();
        *(uint *)(iVar9 + 0x10) = DAT_400d0260;
        iVar9 = 0;
        uStack_2c = 7;
        uStack_28 = local_50;
        uVar8 = local_50;
        do {
          uVar10 = uVar8 - 1;
          if ((int)uVar10 < 0) break;
          iVar9 = iVar9 + 1;
          if ((uint)param_1[uVar8 + 0x2b] != (uStack_38 & 0xff)) {
            iVar9 = 0;
          }
          uVar8 = uVar10;
        } while (iVar9 < (int)uVar15);
      }
      param_1[0xac] = (byte)local_50;
      memw();
      memw();
      iVar9 = func_0x4008860c(*(undefined4 *)(param_1 + 0xe8),param_1 + 0x2c,local_50 & 0xff,
                              &iStack_4c);
      if (iVar9 == 0) {
        param_1[0x1c] = 1;
        memw();
        memw();
        func_0x4008b620(iVar3,0xffffffff);
        memw();
        memw();
        *(uint *)(*(int *)(DAT_400d06c0 + iVar5) + 0xc) =
             *(uint *)(*(int *)(DAT_400d06c0 + iVar5) + 0xc) & 0xfffffefe;
        memw();
        func_0x4008b770(iVar3);
        if (uStack_2c == 7) {
          func_0x4008b620(iVar3,0xffffffff);
          iVar9 = *(int *)(param_1 + 0x14);
          if ((int)local_50 < (int)uVar15) {
            iVar13 = iVar9 - (uVar15 - local_50);
          }
          else {
            iVar13 = uVar10 + iVar9;
            if ((int)uVar10 < 0) {
              iVar13 = (uint)param_1[0xac] + iVar9;
            }
          }
          FUN_400da7b8(uVar4,iVar13);
          func_0x4008b770(iVar3);
          if (*(int *)(param_1 + 0xe4) != 0) {
            func_0x400893d4(*(int *)(param_1 + 0xe4),&uStack_2c,&iStack_4c,0);
          }
        }
        uStack_2c = 2;
        goto LAB_400dacce;
      }
      func_0x4008b620(iVar3,0xffffffff);
      if (uVar7 != 0) {
        if ((int)local_50 < (int)uVar15) {
          uVar10 = -(uVar15 - local_50);
        }
        else if ((int)uVar10 < 0) goto LAB_400dad94;
        FUN_400da7b8(uVar4,*(int *)(param_1 + 0x14) + uVar10);
      }
LAB_400dad94:
      *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + (uint)param_1[0xac];
      memw();
LAB_400daa24:
      memw();
      func_0x4008b770(iVar3);
      goto LAB_400daa2c;
    }
    if ((uVar8 & 0x10) != 0) {
      func_0x4008b620(iVar3,0xffffffff);
      FUN_400e1134(piVar11);
      func_0x4008b770(iVar3);
      uVar14 = DAT_400d06cc;
      func_0x4008b620(DAT_400d06cc,0xffffffff);
      if (*(code **)(param_1 + 0xe0) != (code *)0x0) {
        (**(code **)(param_1 + 0xe0))(uVar4,2,&iStack_4c);
      }
      func_0x4008b770(uVar14);
      memw();
      *(undefined4 *)(*(int *)(DAT_400d06c0 + iVar5) + 0x10) = 0x10;
      uStack_2c = 3;
      memw();
LAB_400dacce:
      memw();
      goto LAB_400dae04;
    }
    if ((uVar8 & 0x80) != 0) {
      memw();
      *(undefined4 *)(iVar12 + 0x10) = 0x80;
      uStack_2c = 1;
      memw();
      goto LAB_400dacce;
    }
    if ((uVar8 & 8) != 0) {
      func_0x4008b620(DAT_400d06cc,0xffffffff);
      if (*(code **)(param_1 + 0xe0) != (code *)0x0) {
        (**(code **)(param_1 + 0xe0))(uVar4,2,&iStack_4c);
      }
      func_0x4008b770(uVar14);
      memw();
      *(undefined4 *)(*(int *)(iVar13 + iVar5) + 0x10) = 8;
      uStack_2c = 4;
      memw();
      goto LAB_400dacce;
    }
    if ((uVar8 & 4) != 0) {
      func_0x4008b620(DAT_400d06cc,0xffffffff);
      if (*(code **)(param_1 + 0xe0) != (code *)0x0) {
        (**(code **)(param_1 + 0xe0))(uVar4,2,&iStack_4c);
      }
      func_0x4008b770(uVar14);
      memw();
      *(undefined4 *)(*(int *)(iVar13 + iVar5) + 0x10) = 4;
      uStack_2c = 5;
      memw();
      goto LAB_400dacce;
    }
    if ((uVar8 & 0x1000) != 0) {
      memw();
      func_0x4008b620(iVar3,0xffffffff);
      FUN_400e1190(piVar11,0);
      iVar9 = *piVar11;
      memw();
      memw();
      *(uint *)(iVar9 + 0xc) = *(uint *)(iVar9 + 0xc) & DAT_400d06d0;
      if (param_1[0xdc] == 1) {
        memw();
        memw();
        *(uint *)(iVar9 + 0xc) = *(uint *)(iVar9 + 0xc) | 2;
      }
      memw();
      func_0x4008b770(iVar3);
      memw();
      *(uint *)(*(int *)(iVar13 + iVar5) + 0x10) = DAT_400d01d0;
      if (param_1[0xdc] != 1) {
        uVar14 = *(undefined4 *)(param_1 + 0x100);
        goto LAB_400da9ca;
      }
      param_1[0xdc] = 0;
      param_1[0xde] = 0;
      memw();
      memw();
      goto LAB_400daa2c;
    }
    if ((uVar8 & DAT_400d01e0) != 0) {
      func_0x4008b620(iVar3,0xffffffff);
      memw();
      memw();
      *(uint *)(*piVar11 + 0xc) = *(uint *)(*piVar11 + 0xc) & DAT_400d06d4;
      memw();
      func_0x4008b770(iVar3);
      memw();
      *(uint *)(*piVar11 + 0x10) = uVar7;
      memw();
      goto LAB_400daa2c;
    }
    if ((uVar8 & DAT_400d0260) != 0) {
      uStack_2c = 7;
      memw();
      *(uint *)(iVar12 + 0x10) = DAT_400d0260;
      memw();
      goto LAB_400dacce;
    }
    if ((uVar8 & DAT_400d06d8) == 0) {
      if ((uVar8 & 0x4000) != 0) {
        iVar13 = uVar4 * 4;
        if (*(int *)(*(int *)(DAT_400d06b4 + iVar13) + 0xc) == 1) break;
        goto LAB_400db022;
      }
      memw();
      *(uint *)(iVar12 + 0x10) = uVar8;
      memw();
    }
    else {
      func_0x4008b620(iVar3,0xffffffff);
      FUN_400e1134(piVar11);
      *(undefined1 *)(*(int *)(DAT_400d06b4 + uVar4 * 4) + 0x10) = 1;
      memw();
      memw();
      func_0x4008b770(iVar3);
      memw();
      *(uint *)(*(int *)(iVar13 + iVar5) + 0x10) = uVar10;
      uStack_2c = 8;
      memw();
    }
  } while( true );
  memw();
  uStack_30 = *(uint *)(iVar12 + 0x1c);
  memw();
  memw();
  if ((uStack_30 >> 0x10 & 0xff) == 0) {
    memw();
    if ((uStack_30 >> 0x18 & 0xf) == 0) {
LAB_400db022:
      memw();
      *(undefined4 *)(iVar12 + 0x10) = DAT_400d0134;
      memw();
      func_0x4008b620(iVar3,0xffffffff);
      piVar6 = (int *)(DAT_400d06c0 + iVar5);
      iVar12 = *piVar6;
      memw();
      memw();
      *(uint *)(iVar12 + 0xc) = *(uint *)(iVar12 + 0xc) & DAT_400d06dc;
      if (*(int *)(*(int *)(iVar9 + iVar13) + 0xc) == 1) {
        memw();
        FUN_400e1134(piVar11);
        iVar12 = *piVar6;
        memw();
        memw();
        *(uint *)(iVar12 + 0x20) = *(uint *)(iVar12 + 0x20) | 0x40;
      }
      memw();
      func_0x4008b770(iVar3);
      uVar14 = *(undefined4 *)(*(int *)(iVar9 + iVar13) + 0xfc);
LAB_400da9ca:
      memw();
      func_0x400894c4(uVar14,&iStack_4c);
LAB_400daa2c:
      if (uStack_2c != 8) {
LAB_400dae04:
        if (*(int *)(param_1 + 0xe4) != 0) {
          memw();
          func_0x400893d4(*(int *)(param_1 + 0xe4),&uStack_2c,&iStack_4c,0);
        }
      }
    }
    else {
      memw();
    }
  }
  goto LAB_400da966;
code_r0x400daa5a:
  if (*(int *)(param_1 + 0xd4) == 0) {
    param_1[0xcc] = 0;
    param_1[0xcd] = 0;
    param_1[0xce] = 0;
    param_1[0xcf] = 0;
    *(int *)(param_1 + 0xd4) = piVar6[2];
    if (*piVar6 == 6) {
      param_1[0xdc] = 1;
      memw();
      param_1[0xdd] = (byte)piVar6[1];
      memw();
    }
    memw();
    func_0x400887cc(*(undefined4 *)(param_1 + 0xec),piVar6,&iStack_4c);
  }
  else if (*(int *)(param_1 + 0xcc) == 0) {
    *(int **)(param_1 + 0xcc) = piVar6;
    *(undefined4 *)(param_1 + 0xd8) = uStack_48;
    memw();
    bVar1 = bVar2;
  }
  if (*(int *)(param_1 + 0xd4) != 0) {
LAB_400daa95:
    if ((*(int *)(param_1 + 0xcc) != 0) && (uVar15 = *(uint *)(param_1 + 0xd8), uVar15 != 0)) {
      iVar9 = FUN_400da8d4(uVar4,*(int *)(param_1 + 0xcc),
                           (uVar15 < uVar7) * uVar15 + (uVar15 >= uVar7) * uVar7);
      uVar7 = uVar7 - iVar9;
      iVar13 = *(int *)(param_1 + 0xd8);
      *(int *)(param_1 + 0xcc) = *(int *)(param_1 + 0xcc) + iVar9;
      *(int *)(param_1 + 0xd4) = *(int *)(param_1 + 0xd4) - iVar9;
      *(int *)(param_1 + 0xd8) = iVar13 - iVar9;
      bVar1 = bVar2;
      if (iVar13 - iVar9 == 0) {
        memw();
        func_0x400887cc(*(undefined4 *)(param_1 + 0xec),*(undefined4 *)(param_1 + 0xd0),&iStack_4c);
        param_1[0xd0] = 0;
        param_1[0xd1] = 0;
        param_1[0xd2] = 0;
        param_1[0xd3] = 0;
        param_1[0xcc] = 0;
        param_1[0xcd] = 0;
        param_1[0xce] = 0;
        param_1[0xcf] = 0;
        if ((*(int *)(param_1 + 0xd4) == 0) && (param_1[0xdc] == 1)) {
          piVar6 = (int *)(DAT_400d06c0 + iVar5);
          memw();
          *(uint *)(*piVar6 + 0x10) = DAT_400d01d0;
          memw();
          func_0x4008b620(iVar3,0xffffffff);
          FUN_400e1190(piVar11,param_1[0xdd]);
          iVar9 = *piVar6;
          memw();
          memw();
          *(uint *)(iVar9 + 0xc) = *(uint *)(iVar9 + 0xc) | DAT_400d01d0;
          memw();
          func_0x4008b770(iVar3);
          param_1[0xde] = 1;
          memw();
          memw();
          bVar1 = false;
        }
      }
    }
  }
  goto LAB_400da9f5;
}



// Function at 0x400db0cc

void FUN_400db0cc(int param_1)

{
  if (*(int *)(param_1 + 0xf8) != 0) {
    func_0x400899b0();
  }
  if (*(int *)(param_1 + 0xfc) != 0) {
    func_0x400899b0();
  }
  if (*(int *)(param_1 + 0x100) != 0) {
    func_0x400899b0();
  }
  if (*(int *)(param_1 + 0xf4) != 0) {
    func_0x400899b0();
  }
  if (*(int *)(param_1 + 0xf0) != 0) {
    func_0x400899b0();
  }
  if (*(int *)(param_1 + 0xe4) != 0) {
    func_0x400899b0();
  }
  if (*(int *)(param_1 + 0xe8) != 0) {
    func_0x40088818();
  }
  if (*(int *)(param_1 + 0xec) != 0) {
    func_0x40088818();
  }
  func_0x4008dbfc(param_1);
  return;
}



// Function at 0x400db12c

undefined4 FUN_400db12c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = DAT_400d06c0;
  if (param_1 < 3) {
    iVar3 = param_1 * 0x10 + 4 + DAT_400d06c0;
    func_0x4008b620(iVar3,0xffffffff);
    uVar4 = *(uint *)(*(int *)(DAT_400d06b4 + param_1 * 4) + 0xb0) & 0x101;
    iVar2 = *(int *)(iVar2 + param_1 * 0x10);
    memw();
    *(uint *)(iVar2 + 0x10) = uVar4;
    memw();
    memw();
    *(uint *)(iVar2 + 0xc) = uVar4 | *(uint *)(iVar2 + 0xc);
    memw();
    func_0x4008b770(iVar3);
    uVar1 = 0;
  }
  else {
    uVar1 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d06e4,DAT_400d06e8,uVar1,DAT_400d06e4,DAT_400d06e0,0x18d);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



// Function at 0x400db1a0

char FUN_400db1a0(int param_1)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  
  piVar2 = (int *)(DAT_400d06b4 + param_1 * 4);
  iVar1 = *piVar2;
  cVar3 = *(char *)(iVar1 + 0x1c);
  if ((cVar3 == '\0') ||
     (iVar1 = func_0x40088530(*(undefined4 *)(iVar1 + 0xe8),iVar1 + 0x2c,
                              *(undefined1 *)(iVar1 + 0xac),1), iVar1 != 1)) {
    cVar3 = '\0';
  }
  else {
    iVar1 = param_1 * 0x10 + 4 + DAT_400d06c0;
    func_0x4008b620(iVar1,0xffffffff);
    iVar4 = *piVar2;
    *(uint *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + (uint)*(byte *)(iVar4 + 0xac);
    *(undefined1 *)(iVar4 + 0x1c) = 0;
    memw();
    memw();
    func_0x4008b770(iVar1);
    FUN_400db12c(*(undefined4 *)*piVar2);
  }
  return cVar3;
}



// Function at 0x400db4ac

undefined4 FUN_400db4ac(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = DAT_400d06c0;
  if (param_1 < 3) {
    iVar3 = param_1 * 0x10 + 4 + DAT_400d06c0;
    func_0x4008b620(iVar3,0xffffffff);
    FUN_400e0e74(iVar1 + param_1 * 0x10,param_2);
    func_0x4008b770(iVar3);
    uVar2 = 0;
  }
  else {
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d06e4,DAT_400d06e8,uVar2,DAT_400d06e4,DAT_400d0714,0x13f);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



// Function at 0x400db4fc

undefined4 FUN_400db4fc(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = DAT_400d06c0;
  if (param_1 < 3) {
    iVar3 = param_1 * 0x10 + 4 + DAT_400d06c0;
    func_0x4008b620(iVar3,0xffffffff);
    iVar4 = *(int *)(DAT_400d06b4 + param_1 * 4);
    *(uint *)(iVar4 + 0xb0) = *(uint *)(iVar4 + 0xb0) & (param_2 ^ 0xffffffff);
    iVar2 = *(int *)(iVar2 + param_1 * 0x10);
    memw();
    memw();
    *(uint *)(iVar2 + 0xc) = (param_2 ^ 0xffffffff) & *(uint *)(iVar2 + 0xc);
    memw();
    func_0x4008b770(iVar3);
    uVar1 = 0;
  }
  else {
    uVar1 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d06e4,DAT_400d06e8,uVar1,DAT_400d06e4,DAT_400d0718,0x19a);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



// Function at 0x400db570

undefined4 FUN_400db570(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  
  if (param_1 < 3) {
    piVar4 = (int *)(DAT_400d06b4 + param_1 * 4);
    if (*piVar4 == 0) {
      uVar1 = func_0x4008d9f8();
      memw();
      FUN_400e4a50(1,DAT_400d06e4,DAT_400d0720,uVar1,DAT_400d06e4,DAT_400d071c,0x209);
      uVar1 = 0x103;
    }
    else {
      iVar2 = func_0x4008dbdc(param_2 << 2);
      uVar1 = 0x101;
      if (iVar2 != 0) {
        iVar3 = param_1 * 0x10 + 4 + DAT_400d06c0;
        func_0x4008b620(iVar3,0xffffffff);
        iVar6 = *piVar4;
        uVar5 = *(undefined4 *)(iVar6 + 0xc0);
        *(int *)(iVar6 + 0xbc) = param_2;
        *(int *)(iVar6 + 0xc0) = iVar2;
        *(undefined4 *)(iVar6 + 0xb8) = 0;
        *(undefined4 *)(iVar6 + 0xb4) = 0;
        memw();
        func_0x4008b770(iVar3);
        uVar1 = 0;
        func_0x4008dbfc(uVar5);
      }
    }
  }
  else {
    uVar1 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d06e4,DAT_400d06e8,uVar1,DAT_400d06e4,DAT_400d071c,0x208);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



// Function at 0x400db614

undefined4 FUN_400db614(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400db4fc(param_1,0x101);
  return uVar1;
}



// Function at 0x400db628

undefined4 FUN_400db628(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400db4fc(param_1,2);
  return uVar1;
}



// Function at 0x400db63c

undefined4 FUN_400db63c(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (param_1 < 3) {
    if (param_3 < 0x80) {
      iVar3 = param_1 * 0x10 + 4 + DAT_400d06c0;
      piVar2 = (int *)(DAT_400d06c0 + param_1 * 0x10);
      if (param_2 == 0) {
        func_0x4008b620(iVar3,0xffffffff);
        memw();
        memw();
        *(uint *)(*piVar2 + 0xc) = *(uint *)(*piVar2 + 0xc) & 0xfffffffd;
        memw();
        func_0x4008b770(iVar3);
        return 0;
      }
      memw();
      *(undefined4 *)(*piVar2 + 0x10) = 2;
      memw();
      func_0x4008b620(iVar3,0xffffffff);
      FUN_400e0e50(piVar2,param_3);
      memw();
      memw();
      *(uint *)(*piVar2 + 0xc) = *(uint *)(*piVar2 + 0xc) | 2;
      memw();
      func_0x4008b770(iVar3);
      return 0;
    }
    uVar1 = func_0x4008d9f8();
    uVar5 = 0x26a;
    memw();
    uVar4 = DAT_400d0728;
  }
  else {
    uVar1 = func_0x4008d9f8();
    uVar5 = 0x269;
    uVar4 = DAT_400d06e8;
  }
  memw();
  FUN_400e4a50(1,DAT_400d06e4,uVar4,uVar1,DAT_400d06e4,DAT_400d0724,uVar5);
  return 0xffffffff;
}



// Function at 0x400db6f8

uint FUN_400db6f8(int param_1,int param_2,uint param_3,int param_4,undefined4 param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  
  iVar3 = param_1 * 4;
  piVar4 = (int *)(DAT_400d06b4 + iVar3);
  memw();
  func_0x400896ec(*(undefined4 *)(*piVar4 + 0xf4),0xffffffff);
  iVar6 = *piVar4;
  *(undefined1 *)(iVar6 + 0x10) = 0;
  memw();
  uVar1 = param_3;
  if (*(int *)(iVar6 + 0xc4) < 1) {
    while (uVar2 = DAT_400d01d0, uVar1 != 0) {
      iVar6 = func_0x400896ec(*(undefined4 *)(*piVar4 + 0xf8),0xffffffff);
      if (iVar6 == 1) {
        memw();
        uVar2 = FUN_400da8d4(param_1,param_2,uVar1);
        if (uVar2 < uVar1) {
          *(undefined1 *)(*piVar4 + 200) = 1;
          memw();
          memw();
          FUN_400db63c(param_1,1,10);
        }
        param_2 = param_2 + uVar2;
        uVar1 = uVar1 - uVar2;
      }
    }
    if (param_4 != 0) {
      piVar4 = (int *)(DAT_400d06c0 + param_1 * 0x10);
      iVar6 = param_1 * 0x10 + 4 + DAT_400d06c0;
      memw();
      *(uint *)(*piVar4 + 0x10) = DAT_400d01d0;
      memw();
      func_0x4008b620(iVar6,0xffffffff);
      FUN_400e1190(piVar4,param_5);
      memw();
      memw();
      *(uint *)(*piVar4 + 0xc) = *(uint *)(*piVar4 + 0xc) | uVar2;
      memw();
      func_0x4008b770(iVar6);
      func_0x400896ec(*(undefined4 *)(*(int *)(DAT_400d06b4 + iVar3) + 0x100),0xffffffff);
    }
    func_0x40089194(*(undefined4 *)(*(int *)(DAT_400d06b4 + iVar3) + 0xf8),0,0);
  }
  else {
    memw();
    uVar1 = func_0x4008884c(*(undefined4 *)(iVar6 + 0xec));
    uStack_2c = 0;
    if (param_4 != 0) {
      uStack_2c = 6;
    }
    memw();
    uStack_28 = param_5;
    uStack_24 = param_3;
    func_0x40088530(*(undefined4 *)(*piVar4 + 0xec),&uStack_2c,0xc,0xffffffff);
    iVar6 = 0;
    uVar1 = uVar1 >> 1;
    uVar2 = param_3;
    while (uVar2 != 0) {
      iVar5 = (uVar1 < uVar2) * uVar1 + (uVar1 >= uVar2) * uVar2;
      iVar7 = param_2 + iVar6;
      iVar6 = iVar5 + iVar6;
      memw();
      func_0x40088530(*(undefined4 *)(*piVar4 + 0xec),iVar7,iVar5,0xffffffff);
      uVar2 = uVar2 - iVar5;
      memw();
      FUN_400db63c(param_1,1,10);
    }
  }
  func_0x40089194(*(undefined4 *)(*(int *)(DAT_400d06b4 + iVar3) + 0xf4),0,0);
  return param_3;
}



// Function at 0x400db87c

int FUN_400db87c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 *param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 auStack_24 [9];
  
  if (param_1 < 3) {
    iVar2 = FUN_400e383c(*(undefined1 *)(DAT_400d02d8 + param_1 * 0x18 + 0x10),param_4,param_2,
                         param_3,auStack_24);
    if (iVar2 == 0) {
      *(undefined4 *)(*(int *)(DAT_400d06b4 + param_1 * 4) + 8) = auStack_24[0];
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = auStack_24[0];
        memw();
      }
    }
  }
  else {
    uVar1 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d06e4,DAT_400d06e8,uVar1,DAT_400d06e4,DAT_400d072c,0x27d);
    iVar2 = -1;
  }
  return iVar2;
}



// Function at 0x400db8e4

undefined4 FUN_400db8e4(int param_1,uint *param_2,uint *param_3,uint *param_4,int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  undefined4 uVar7;
  uint *in_t0;
  
  if (param_1 < 0) {
    uVar1 = func_0x4008d9f8();
    uVar2 = 0x2b2;
    uVar7 = DAT_400d06e8;
  }
  else if (param_1 < 3) {
    if (((int)param_2 < 0) ||
       (uVar3 = (*DAT_400d0384)(DAT_400d0178,DAT_400d03b8,param_2), (uVar3 & 1) != 0)) {
      if (((int)param_3 < 0) ||
         (uVar3 = (*DAT_400d0384)(DAT_400d0178,DAT_400d0368,param_3), (uVar3 & 1) != 0)) {
        if (((int)param_4 < 0) ||
           (uVar3 = (*DAT_400d0384)(DAT_400d0178,DAT_400d03b8,param_4), (uVar3 & 1) != 0)) {
          if ((param_5 < 0) ||
             (uVar3 = (*DAT_400d0384)(DAT_400d0178,DAT_400d0368,param_5), (uVar3 & 1) != 0)) {
            if ((int)param_2 < 0) goto LAB_400dba59;
            iVar4 = FUN_400da834(param_1,param_2,0);
            if (iVar4 != 0) goto LAB_400dba59;
            puVar6 = *(uint **)(DAT_400d02c4 + (int)param_2 * 4);
            puVar5 = (uint *)0x0;
            if (DAT_400d02ac < (uint *)((int)puVar6 + DAT_400d02a8)) goto LAB_400dba1b;
LAB_400dba0c:
            puVar6 = in_t0;
            func_0x4008dacc(DAT_400d074c,0x27d,DAT_400d0748,DAT_400d0744);
            in_t0 = puVar6;
LAB_400dba1b:
            memw();
            memw();
            *puVar6 = *puVar6 & DAT_400d02d4 | DAT_400d01e0;
            memw();
            FUN_400d7b54(param_2,1);
            (*DAT_400d02dc)(param_2,*(uint *)(DAT_400d02d8 + param_1 * 0x18) >> 0x14,puVar5,puVar5);
LAB_400dba59:
            if ((-1 < (int)param_3) && (iVar4 = FUN_400da834(param_1,param_3,1), iVar4 == 0))
            goto code_r0x400dba6c;
            goto LAB_400dbac5;
          }
          uVar1 = func_0x4008d9f8();
          uVar2 = 0x2b7;
          memw();
          uVar7 = DAT_400d0740;
        }
        else {
          uVar1 = func_0x4008d9f8();
          uVar2 = 0x2b6;
          memw();
          uVar7 = DAT_400d073c;
        }
      }
      else {
        uVar1 = func_0x4008d9f8();
        uVar2 = 0x2b5;
        memw();
        uVar7 = DAT_400d0738;
      }
    }
    else {
      uVar1 = func_0x4008d9f8();
      uVar2 = 0x2b4;
      memw();
      uVar7 = DAT_400d0734;
    }
  }
  else {
    uVar1 = func_0x4008d9f8();
    uVar2 = 0x2b3;
    uVar7 = DAT_400d06e8;
  }
  memw();
  FUN_400e4a50(1,DAT_400d06e4,uVar7,uVar1,DAT_400d06e4,DAT_400d0730,uVar2);
  return 0xffffffff;
code_r0x400dba6c:
  puVar6 = *(uint **)(DAT_400d02c4 + (int)param_3 * 4);
  param_2 = (uint *)((int)puVar6 + DAT_400d02a8);
  puVar5 = (uint *)0x0;
  if (DAT_400d02ac < param_2) {
    memw();
    memw();
    *puVar6 = *puVar6 & DAT_400d02d4 | DAT_400d01e0;
    memw();
    FUN_400d7c78(param_3,0);
    FUN_400d7d04(param_3,1);
    (*DAT_400d02e0)(param_3,*(uint *)(DAT_400d02d8 + param_1 * 0x18 + 4) >> 0x14,0);
LAB_400dbac5:
    if ((-1 < (int)param_4) && (iVar4 = FUN_400da834(param_1,param_4,2), iVar4 == 0)) {
      puVar5 = *(uint **)(DAT_400d02c4 + (int)param_4 * 4);
      param_2 = (uint *)((int)puVar5 + DAT_400d02a8);
      if (param_2 <= DAT_400d02ac) {
        param_3 = (uint *)0x0;
        goto LAB_400dba0c;
      }
      memw();
      memw();
      *puVar5 = *puVar5 & DAT_400d02d4 | DAT_400d01e0;
      memw();
      FUN_400d7d04(param_4,2);
      (*DAT_400d02dc)(param_4,*(uint *)(DAT_400d02d8 + param_1 * 0x18 + 8) >> 0x14,0,0);
    }
    if ((param_5 < 0) || (iVar4 = FUN_400da834(param_1,param_5,3), iVar4 != 0)) {
      return 0;
    }
    param_4 = *(uint **)(DAT_400d02c4 + param_5 * 4);
    param_3 = (uint *)((int)param_4 + DAT_400d02a8);
    if (DAT_400d02ac < param_3) {
      memw();
      memw();
      *param_4 = *param_4 & DAT_400d02d4 | DAT_400d01e0;
      memw();
      FUN_400d7c78(param_5,0);
      FUN_400d7d04(param_5,1);
      (*DAT_400d02e0)(param_5,*(uint *)(DAT_400d02d8 + param_1 * 0x18 + 0xc) >> 0x14,0);
      return 0;
    }
    param_2 = (uint *)0x0;
    puVar5 = DAT_400d02ac;
  }
  goto LAB_400dba0c;
}



// Function at 0x400dbba4

undefined4 FUN_400dbba4(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (param_1 < 3) {
    if (param_2 == (undefined4 *)0x0) {
      uVar1 = func_0x4008d9f8();
      uVar5 = 0x2f7;
      memw();
      uVar4 = DAT_400d0754;
    }
    else if ((*(byte *)(param_2 + 5) & 0x80) == 0) {
      if ((uint)param_2[4] < 4) {
        if ((uint)param_2[1] < 4) {
          FUN_400da888(param_1);
          iVar3 = param_1 * 0x10 + 4 + DAT_400d06c0;
          iVar2 = param_1 * 0x10 + DAT_400d06c0;
          func_0x4008b620(iVar3,0xffffffff);
          FUN_400e0f5c(iVar2,param_1);
          FUN_400e0cfc(iVar2,param_2[6]);
          FUN_400e0d28(iVar2,*param_2);
          FUN_400f80fc(iVar2,param_2[2]);
          FUN_400f80c4(iVar2,param_2[1]);
          FUN_400f803c(iVar2,param_2[3]);
          FUN_400e0e28(iVar2,0);
          FUN_400e0dc0(iVar2,param_2[4],*(undefined1 *)(param_2 + 5));
          func_0x4008b770(iVar3);
          FUN_400e1134(iVar2);
          FUN_400e1100(iVar2);
          return 0;
        }
        uVar1 = func_0x4008d9f8();
        uVar5 = 0x2fa;
        memw();
        uVar4 = DAT_400d06f0;
      }
      else {
        uVar1 = func_0x4008d9f8();
        uVar5 = 0x2f9;
        memw();
        uVar4 = DAT_400d075c;
      }
    }
    else {
      uVar1 = func_0x4008d9f8();
      uVar5 = 0x2f8;
      memw();
      uVar4 = DAT_400d0758;
    }
  }
  else {
    uVar1 = func_0x4008d9f8();
    uVar5 = 0x2f6;
    uVar4 = DAT_400d06e8;
  }
  memw();
  FUN_400e4a50(1,DAT_400d06e4,uVar4,uVar1,DAT_400d06e4,DAT_400d0750,uVar5);
  return 0xffffffff;
}



// Function at 0x400dbcc0

undefined4 FUN_400dbcc0(int param_1,uint *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  iVar2 = DAT_400d06c0;
  if (param_1 < 3) {
    if (param_2 != (uint *)0x0) {
      param_1 = param_1 * 0x10;
      piVar3 = (int *)(DAT_400d06c0 + param_1);
      memw();
      *(undefined4 *)(*piVar3 + 0x10) = DAT_400d0764;
      iVar4 = param_1 + 4 + iVar2;
      memw();
      func_0x4008b620(iVar4,0xffffffff);
      uVar5 = *param_2 & 0x100;
      if (uVar5 != 0) {
        uVar5 = (uint)(byte)param_2[1];
      }
      FUN_400e1078(piVar3,uVar5);
      if ((*param_2 & 1) != 0) {
        FUN_400f815c(piVar3,*(undefined1 *)((int)param_2 + 6));
      }
      if ((*param_2 & 2) != 0) {
        FUN_400e0e50(piVar3,*(undefined1 *)((int)param_2 + 5));
      }
      iVar2 = *(int *)(iVar2 + param_1);
      memw();
      memw();
      *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | *param_2;
      memw();
      func_0x4008b770(iVar4);
      return 0;
    }
    uVar1 = func_0x4008d9f8();
    uVar7 = 0x313;
    memw();
    uVar6 = DAT_400d0754;
  }
  else {
    uVar1 = func_0x4008d9f8();
    uVar7 = 0x312;
    uVar6 = DAT_400d06e8;
  }
  memw();
  FUN_400e4a50(1,DAT_400d06e4,uVar6,uVar1,DAT_400d06e4,DAT_400d0760,uVar7);
  return 0xffffffff;
}



// Function at 0x400dbf18

undefined4 FUN_400dbf18(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_1 < 3) {
    if (*(int *)(DAT_400d06b4 + param_1 * 4) == 0) {
      uVar1 = func_0x4008d9f8();
      uVar3 = 0x505;
      memw();
      uVar2 = DAT_400d0720;
    }
    else {
      if (param_2 != 0) {
        if (param_3 == 0) {
          return 0;
        }
        uVar2 = FUN_400db6f8(param_1,param_2,param_3,0,0);
        return uVar2;
      }
      uVar1 = func_0x4008d9f8();
      uVar3 = 0x506;
      memw();
      uVar2 = DAT_400d077c;
    }
  }
  else {
    uVar1 = func_0x4008d9f8();
    uVar3 = 0x504;
    uVar2 = DAT_400d06e8;
  }
  memw();
  FUN_400e4a50(1,DAT_400d06e4,uVar2,uVar1,DAT_400d06e4,DAT_400d0778,uVar3);
  return 0xffffffff;
}



// Function at 0x400dbfa4

int FUN_400dbfa4(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 auStack_24 [9];
  
  if (param_1 < 3) {
    if (param_2 == 0) {
      uVar1 = func_0x4008d9f8();
      uVar9 = 0x529;
      memw();
      uVar8 = DAT_400d0784;
    }
    else {
      piVar3 = (int *)(DAT_400d06b4 + param_1 * 4);
      if (*piVar3 != 0) {
        iVar2 = func_0x400896ec(*(undefined4 *)(*piVar3 + 0xf0),param_4);
        if (iVar2 != 1) {
          return -1;
        }
        iVar4 = param_1 * 0x10 + 4 + DAT_400d06c0;
        iVar2 = 0;
        do {
          while( true ) {
            iVar5 = *piVar3;
            if (param_3 == 0) {
              uVar8 = *(undefined4 *)(iVar5 + 0xf0);
              memw();
              goto LAB_400dc0f9;
            }
            if (*(int *)(iVar5 + 0x20) == 0) break;
LAB_400dc071:
            uVar7 = *(uint *)(*piVar3 + 0x20);
            iVar5 = (param_3 < uVar7) * param_3 + (param_3 >= uVar7) * uVar7;
            param_3 = param_3 - iVar5;
            iVar6 = param_2 + iVar2;
            iVar2 = iVar2 + iVar5;
            memw();
            func_0x400866b8(iVar6,*(undefined4 *)(*piVar3 + 0x24),iVar5);
            func_0x4008b620(iVar4,0xffffffff);
            iVar6 = *piVar3;
            *(int *)(iVar6 + 0x14) = *(int *)(iVar6 + 0x14) - iVar5;
            memw();
            FUN_400da7f0(param_1,iVar5);
            *(int *)(iVar6 + 0x24) = *(int *)(iVar6 + 0x24) + iVar5;
            memw();
            func_0x4008b770(iVar4);
            iVar6 = *piVar3;
            iVar5 = *(int *)(iVar6 + 0x20) - iVar5;
            *(int *)(iVar6 + 0x20) = iVar5;
            if (iVar5 == 0) {
              memw();
              func_0x4008877c(*(undefined4 *)(iVar6 + 0xe8),*(undefined4 *)(iVar6 + 0x28));
              iVar5 = *piVar3;
              *(undefined4 *)(iVar5 + 0x28) = 0;
              *(undefined4 *)(iVar5 + 0x24) = 0;
              memw();
              FUN_400db1a0(param_1);
            }
          }
          iVar5 = func_0x400886ac(*(undefined4 *)(iVar5 + 0xe8),auStack_24,param_4);
          if (iVar5 != 0) {
            iVar6 = *piVar3;
            *(int *)(iVar6 + 0x28) = iVar5;
            *(int *)(iVar6 + 0x24) = iVar5;
            *(undefined4 *)(iVar6 + 0x20) = auStack_24[0];
            goto LAB_400dc071;
          }
          iVar5 = FUN_400db1a0(param_1);
        } while (iVar5 != 0);
        uVar8 = *(undefined4 *)(*piVar3 + 0xf0);
LAB_400dc0f9:
        func_0x40089194(uVar8,0,0,0);
        return iVar2;
      }
      uVar1 = func_0x4008d9f8();
      uVar9 = 0x52a;
      memw();
      uVar8 = DAT_400d0720;
    }
  }
  else {
    memw();
    uVar1 = func_0x4008d9f8();
    uVar9 = 0x528;
    uVar8 = DAT_400d06e8;
  }
  memw();
  FUN_400e4a50(1,DAT_400d06e4,uVar8,uVar1,DAT_400d06e4,DAT_400d0780,uVar9);
  return -1;
}



// Function at 0x400dc100

undefined4 FUN_400dc100(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (param_1 < 3) {
    piVar3 = (int *)(DAT_400d06b4 + param_1 * 4);
    if (*piVar3 != 0) {
      iVar2 = param_1 * 0x10 + 4 + DAT_400d06c0;
      func_0x4008b620(iVar2,0xffffffff);
      *param_2 = *(undefined4 *)(*piVar3 + 0x14);
      memw();
      func_0x4008b770(iVar2);
      return 0;
    }
    uVar1 = func_0x4008d9f8();
    uVar5 = 0x564;
    memw();
    uVar4 = DAT_400d0720;
  }
  else {
    uVar1 = func_0x4008d9f8();
    uVar5 = 0x563;
    uVar4 = DAT_400d06e8;
  }
  memw();
  FUN_400e4a50(1,DAT_400d06e4,uVar4,uVar1,DAT_400d06e4,DAT_400d0788,uVar5);
  return 0xffffffff;
}



// Function at 0x400dc17c

undefined4 FUN_400dc17c(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (param_1 < 3) {
    iVar2 = *(int *)(DAT_400d06b4 + param_1 * 4);
    if (iVar2 == 0) {
      uVar1 = func_0x4008d9f8();
      uVar4 = 0x56e;
      memw();
      uVar3 = DAT_400d0720;
    }
    else {
      if (param_2 != (int *)0x0) {
        *param_2 = *(int *)(iVar2 + 0xc4) - *(int *)(iVar2 + 0xd4);
        memw();
        return 0;
      }
      uVar1 = func_0x4008d9f8();
      uVar4 = 0x56f;
      memw();
      uVar3 = DAT_400d0790;
    }
  }
  else {
    uVar1 = func_0x4008d9f8();
    uVar4 = 0x56d;
    uVar3 = DAT_400d06e8;
  }
  memw();
  FUN_400e4a50(1,DAT_400d06e4,uVar3,uVar1,DAT_400d06e4,DAT_400d078c,uVar4);
  return 0x102;
}



// Function at 0x400dc204

undefined4 FUN_400dc204(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  undefined4 uVar10;
  int aiStack_24 [9];
  
  if (param_1 < 3) {
    iVar7 = param_1 * 4;
    iVar5 = *(int *)(DAT_400d06b4 + iVar7);
    if (iVar5 != 0) {
      func_0x400896ec(*(undefined4 *)(iVar5 + 0xf0),0xffffffff);
      iVar8 = param_1 * 0x10;
      iVar6 = iVar8 + 4 + DAT_400d06c0;
      memw();
      func_0x4008b620(iVar6,0xffffffff);
      memw();
      memw();
      *(uint *)(*(int *)(DAT_400d06c0 + iVar8) + 0xc) =
           *(uint *)(*(int *)(DAT_400d06c0 + iVar8) + 0xc) & 0xfffffefe;
      memw();
      func_0x4008b770(iVar6);
      while( true ) {
        if (*(int *)(iVar5 + 0x28) != 0) {
          func_0x4008877c(*(undefined4 *)(iVar5 + 0xe8));
          func_0x4008b620(iVar6,0xffffffff);
          *(int *)(*(int *)(DAT_400d06b4 + iVar7) + 0x14) =
               *(int *)(*(int *)(DAT_400d06b4 + iVar7) + 0x14) - *(int *)(iVar5 + 0x20);
          memw();
          FUN_400da7f0(param_1);
          func_0x4008b770(iVar6);
          *(undefined4 *)(iVar5 + 0x24) = 0;
          *(undefined4 *)(iVar5 + 0x20) = 0;
          *(undefined4 *)(iVar5 + 0x28) = 0;
        }
        memw();
        iVar3 = func_0x400886ac(*(undefined4 *)(iVar5 + 0xe8),aiStack_24,0);
        if (iVar3 == 0) break;
        func_0x4008b620(iVar6,0xffffffff);
        piVar9 = (int *)(DAT_400d06b4 + iVar7);
        *(int *)(*piVar9 + 0x14) = *(int *)(*piVar9 + 0x14) - aiStack_24[0];
        memw();
        FUN_400da7f0(param_1);
        func_0x4008b770(iVar6);
        func_0x4008877c(*(undefined4 *)(iVar5 + 0xe8),iVar3);
        iVar3 = *piVar9;
        if ((*(char *)(iVar3 + 0x1c) != '\0') &&
           (iVar3 = func_0x40088530(*(undefined4 *)(iVar3 + 0xe8),iVar3 + 0x2c,
                                    *(undefined1 *)(iVar3 + 0xac),1), iVar3 == 1)) {
          func_0x4008b620(iVar6,0xffffffff);
          iVar3 = *piVar9;
          *(uint *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + (uint)*(byte *)(iVar3 + 0xac);
          *(undefined1 *)(iVar3 + 0x1c) = 0;
          memw();
          memw();
          func_0x4008b770(iVar6);
        }
      }
      memw();
      func_0x4008b620(iVar6,0xffffffff);
      iVar7 = *(int *)(DAT_400d06b4 + iVar7);
      bVar1 = *(int *)(iVar7 + 0x14) != 0;
      if (bVar1) {
        *(undefined4 *)(iVar7 + 0x14) = 0;
      }
      *(undefined1 *)(iVar7 + 0x1c) = 0;
      memw();
      memw();
      func_0x4008b770(iVar6);
      if (bVar1) {
        uVar4 = func_0x4008d9f8();
        FUN_400e4a50(1,DAT_400d06e4,DAT_400d0798,uVar4,DAT_400d06e4);
      }
      iVar8 = DAT_400d06c0 + iVar8;
      *(undefined4 *)(iVar5 + 0x24) = 0;
      *(undefined4 *)(iVar5 + 0x20) = 0;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      memw();
      FUN_400e1134(iVar8);
      FUN_400db12c(param_1);
      func_0x40089194(*(undefined4 *)(iVar5 + 0xf0),0,0,0);
      return 0;
    }
    uVar2 = func_0x4008d9f8();
    uVar10 = 0x579;
    memw();
    uVar4 = DAT_400d0720;
  }
  else {
    uVar2 = func_0x4008d9f8();
    uVar10 = 0x578;
    uVar4 = DAT_400d06e8;
  }
  memw();
  FUN_400e4a50(1,DAT_400d06e4,uVar4,uVar2,DAT_400d06e4,DAT_400d0794,uVar10);
  return 0xffffffff;
}



// Function at 0x400dc3cc

undefined4 FUN_400dc3cc(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  
  if (param_1 < 3) {
    piVar6 = (int *)(DAT_400d06b4 + param_1 * 4);
    uVar1 = 0;
    iVar2 = *piVar6;
    if (iVar2 != 0) {
      iVar5 = param_1 * 0x10;
      memw();
      FUN_400e385c(*(undefined4 *)(iVar2 + 8));
      FUN_400db614(param_1);
      FUN_400db628(param_1);
      iVar2 = DAT_400d06c0;
      iVar3 = iVar5 + 4 + DAT_400d06c0;
      func_0x4008b620(iVar3,0xffffffff);
      iVar7 = *piVar6;
      iVar8 = *(int *)(iVar7 + 0xc0);
      if (iVar8 != 0) {
        *(undefined4 *)(iVar7 + 0xc0) = 0;
        *(undefined4 *)(iVar7 + 0xb4) = 0;
        *(undefined4 *)(iVar7 + 0xb8) = 0;
      }
      memw();
      func_0x4008b770(iVar3);
      func_0x4008dbfc(iVar8);
      puVar4 = (undefined4 *)(DAT_400d06b4 + param_1 * 4);
      FUN_400db0cc(*puVar4);
      *puVar4 = 0;
      memw();
      func_0x4008b620(iVar3,0xffffffff);
      if (*(char *)(iVar2 + iVar5 + 0xc) != '\0') {
        if (param_1 != 0) {
          FUN_400da2dc(*(undefined4 *)(DAT_400d02d8 + param_1 * 0x18 + 0x14));
        }
        *(undefined1 *)(iVar2 + iVar5 + 0xc) = 0;
        memw();
      }
      memw();
      func_0x4008b770(iVar3);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d06e4,DAT_400d06e8,uVar1,DAT_400d06e4,DAT_400d079c,0x691);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



// Function at 0x400dc4a0

int FUN_400dc4a0(int param_1,int param_2,int param_3,int param_4,undefined4 *param_5,uint param_6)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  undefined4 uVar8;
  int *piVar9;
  undefined4 uVar10;
  uint uStack_34;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  if (2 < param_1) {
    memw();
    uVar3 = func_0x4008d9f8();
    uVar10 = 0x642;
    uVar8 = DAT_400d06e8;
LAB_400dc4c2:
    memw();
    FUN_400e4a50(1,DAT_400d06e4,uVar8,uVar3,DAT_400d06e4,DAT_400d07a0,uVar10);
    return -1;
  }
  if (param_2 < 0x81) {
    uVar3 = func_0x4008d9f8();
    uVar10 = 0x643;
    memw();
    uVar8 = DAT_400d07a4;
    goto LAB_400dc4c2;
  }
  if ((param_3 < 0x81) && (param_3 != 0)) {
    uVar3 = func_0x4008d9f8();
    uVar10 = 0x644;
    memw();
    uVar8 = DAT_400d07a8;
    goto LAB_400dc4c2;
  }
  uStack_34 = param_6;
  if ((param_6 & 0x400) != 0) {
    uStack_34 = param_6 & 0xfffffbff;
  }
  iVar6 = param_1 * 4;
  piVar9 = (int *)(DAT_400d06b4 + iVar6);
  if (*piVar9 != 0) {
    uVar3 = func_0x4008d9f8();
    uVar8 = DAT_400d07b0;
    goto LAB_400dc55f;
  }
  memw();
  piVar4 = (int *)func_0x400842c4(1,0x104,DAT_400d01d0);
  if (piVar4 == (int *)0x0) {
    *piVar9 = 0;
  }
  else {
    if (param_4 < 1) {
LAB_400dc56e:
      if (0 < param_3) {
        iVar5 = func_0x4008849c(param_3,0);
        piVar4[0x3b] = iVar5;
        if (iVar5 == 0) {
          memw();
          goto LAB_400dc6ba;
        }
      }
      iVar5 = func_0x4008849c(param_2,2);
      piVar4[0x3a] = iVar5;
      memw();
      iVar5 = func_0x400893a4(1);
      piVar4[0x3d] = iVar5;
      memw();
      iVar5 = func_0x400893a4(1);
      piVar4[0x3c] = iVar5;
      memw();
      iVar5 = func_0x400890ac(1,0,3);
      piVar4[0x40] = iVar5;
      memw();
      iVar5 = func_0x400890ac(1,0,3);
      piVar4[0x3f] = iVar5;
      memw();
      iVar5 = func_0x400890ac(1,0,3);
      piVar4[0x3e] = iVar5;
      if (((((piVar4[0x3a] != 0) && (piVar4[0x3c] != 0)) && (piVar4[0x3d] != 0)) &&
          ((piVar4[0x40] != 0 && (bVar1 = piVar4[0x3f] == 0, !bVar1)))) &&
         (bVar7 = iVar5 == 0 || bVar1, iVar5 != 0 && !bVar1)) {
        piVar9 = (int *)(DAT_400d06b4 + iVar6);
        piVar4[1] = param_4;
        piVar4[3] = 0;
        *(undefined2 *)(piVar4 + 4) = 0;
        piVar4[0x33] = 0;
        piVar4[0x34] = 0;
        piVar4[0x35] = 0;
        *(undefined2 *)(piVar4 + 0x37) = 0;
        *(undefined1 *)((int)piVar4 + 0xde) = 0;
        piVar4[5] = 0;
        *(undefined1 *)(piVar4 + 7) = 0;
        *(undefined1 *)(piVar4 + 0x32) = 0;
        memw();
        piVar4[9] = 0;
        piVar4[8] = 0;
        piVar4[10] = 0;
        piVar4[0x31] = param_3;
        piVar4[0x38] = 0;
        *piVar4 = param_1;
        piVar4[0x2c] = 0x101;
        *piVar9 = (int)piVar4;
        memw();
        func_0x40089194(iVar5,0,bVar7,bVar7);
        FUN_400db570(param_1,10);
        if (param_5 != (undefined4 *)0x0) {
          *param_5 = *(undefined4 *)(*piVar9 + 0xe4);
          memw();
        }
        uStack_28 = *DAT_400d07b4;
        uStack_24 = DAT_400d07b4[1];
        memw();
        FUN_400da888(param_1);
        iVar5 = *(int *)(DAT_400d06c0 + param_1 * 0x10);
        memw();
        piVar9 = (int *)(DAT_400d06b4 + iVar6);
        memw();
        *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) & DAT_400d015c;
        puVar2 = PTR_FUN_400d07b8;
        iVar6 = *piVar9;
        memw();
        *(undefined4 *)(iVar5 + 0x10) = DAT_400d0764;
        memw();
        iVar6 = FUN_400db87c(param_1,puVar2,iVar6,uStack_34,iVar6 + 8);
        if ((iVar6 == 0) && (iVar6 = FUN_400dbcc0(param_1,&uStack_28), iVar6 == 0)) {
          return 0;
        }
        FUN_400dc3cc(param_1);
        return iVar6;
      }
    }
    else {
      iVar5 = func_0x400890ac(param_4,0xc,0);
      piVar4[0x39] = iVar5;
      if (iVar5 != 0) goto LAB_400dc56e;
    }
LAB_400dc6ba:
    memw();
    FUN_400db0cc(piVar4);
    *(undefined4 *)(DAT_400d06b4 + iVar6) = 0;
    memw();
  }
  memw();
  uVar3 = func_0x4008d9f8();
  uVar8 = DAT_400d07ac;
LAB_400dc55f:
  FUN_400e4a50(1,DAT_400d06e4,uVar8,uVar3,DAT_400d06e4);
  return -1;
}



// Function at 0x400dc704

undefined4 FUN_400dc704(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 < 3) && (*(int *)(DAT_400d06b4 + param_1 * 4) != 0)) {
    uVar1 = 1;
  }
  return uVar1;
}



// Function at 0x400dc720

void FUN_400dc720(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((param_1 < 3) && (iVar1 = *(int *)(DAT_400d06b4 + param_1 * 4), iVar1 != 0)) {
    *(undefined4 *)(iVar1 + 0xe0) = param_2;
  }
  memw();
  return;
}



// Function at 0x400dc73c

undefined4 FUN_400dc73c(void)

{
  return DAT_400d06cc;
}



// Function at 0x400dc744

undefined4 FUN_400dc744(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  
  iVar1 = DAT_400d06c0;
  if (param_1 < 3) {
    if (param_2 - 1U < 0x7e) {
      if (*(int *)(DAT_400d06b4 + param_1 * 4) == 0) {
        uVar3 = func_0x4008d9f8();
        FUN_400e4a50(1,DAT_400d06e4,DAT_400d07c4,uVar3,DAT_400d06e4);
        return 0x103;
      }
      iVar4 = param_1 * 0x10 + 4 + DAT_400d06c0;
      func_0x4008b620(iVar4,0xffffffff);
      piVar5 = (int *)(iVar1 + param_1 * 0x10);
      memw();
      if ((*(uint *)(*piVar5 + 0xc) & 1) != 0) {
        FUN_400f815c(piVar5,param_2);
      }
      func_0x4008b770(iVar4);
      return 0;
    }
    uVar2 = func_0x4008d9f8();
    uVar6 = 0x6d8;
    memw();
    uVar3 = DAT_400d07c0;
  }
  else {
    uVar2 = func_0x4008d9f8();
    uVar6 = 0x6d6;
    uVar3 = DAT_400d06e8;
  }
  memw();
  FUN_400e4a50(1,DAT_400d06e4,uVar3,uVar2,DAT_400d06e4,DAT_400d07bc,uVar6);
  return 0x102;
}



// Function at 0x400dc7ec

undefined4 FUN_400dc7ec(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  iVar2 = DAT_400d06c0;
  param_2 = param_2 & 0xff;
  if (param_1 < 3) {
    iVar3 = param_1 * 0x10 + DAT_400d06c0;
    uVar5 = FUN_400e10dc(iVar3);
    if (param_2 <= uVar5) {
      iVar2 = param_1 * 0x10 + 4 + iVar2;
      func_0x4008b620(iVar2,0xffffffff);
      FUN_400e1078(iVar3,param_2);
      func_0x4008b770(iVar2);
      return 0;
    }
    uVar1 = func_0x4008d9f8();
    memw();
    uVar4 = DAT_400d07cc;
  }
  else {
    uVar1 = func_0x4008d9f8();
    uVar5 = 0x6f8;
    uVar4 = DAT_400d06e8;
    param_2 = DAT_400d07c8;
  }
  memw();
  FUN_400e4a50(1,DAT_400d06e4,uVar4,uVar1,DAT_400d06e4,param_2,uVar5);
  return 0x102;
}



// Function at 0x400dc864

int FUN_400dc864(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined1 auStack_124 [256];
  int iStack_24;
  
  piVar1 = DAT_400d0098;
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  uStack_12c = *(undefined4 *)(param_1 + 0xc);
  uStack_128 = *(undefined4 *)(param_1 + 0x10);
  memw();
  iVar2 = FUN_400dd3a8(param_2,&uStack_12c,auStack_124);
  if (iVar2 != 0) {
    iVar2 = DAT_400d07d0;
  }
  memw();
  memw();
  if (iStack_24 != *piVar1) {
    iVar2 = func_0x400831d4();
    return iVar2;
  }
  return iVar2;
}



// Function at 0x400dc8ac

int FUN_400dc8ac(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uStack_28;
  int aiStack_24 [9];
  
  iVar2 = FUN_400dd700(1,0);
  if (iVar2 == 0) {
    uVar3 = func_0x4008d9f8();
    FUN_400e4a50(1,DAT_400d07d4,DAT_400d07d8,uVar3,DAT_400d07d4);
  }
  else {
    aiStack_24[0] = 0;
    memw();
    iVar4 = FUN_400dd828(iVar2,0,*(undefined4 *)(iVar2 + 0x10),0,aiStack_24,&uStack_28);
    iVar1 = aiStack_24[0];
    if (iVar4 == 0) {
      func_0x400866b8(param_1,aiStack_24[0],0x20);
      func_0x400866b8(param_1 + 0x20,iVar1 + 0x1000);
      func_0x400821ac(uStack_28);
    }
    else {
      uVar3 = func_0x4008d9f8();
      FUN_400e4a50(1,DAT_400d07d4,DAT_400d07dc,uVar3,DAT_400d07d4,iVar4);
      iVar2 = 0;
    }
  }
  return iVar2;
}



// Function at 0x400dc928

int FUN_400dc928(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)(param_1 + param_3 * 0x20);
  *puVar4 = param_2;
  memw();
  uVar2 = FUN_400dcc40(puVar4);
  uVar1 = DAT_400d01d0;
  puVar4[7] = uVar2;
  memw();
  iVar3 = FUN_400dd7e4(param_4,param_3 << 0xc,uVar1);
  if (iVar3 == 0) {
    iVar3 = FUN_400dd720(param_4,param_3 << 0xc,puVar4,0x20);
  }
  return iVar3;
}



// Function at 0x400dc960

/* WARNING: Control flow encountered bad instruction data */

uint FUN_400dc960(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  puVar1 = DAT_400d07e0;
  uVar2 = *DAT_400d07e0;
  if (uVar2 == 0) {
    uVar3 = FUN_400dd928(PTR_FUN_400d07e4);
    if (uVar3 != 0xffffffff) goto LAB_400dc985;
    uVar6 = 0x224;
    uVar7 = DAT_400d07e8;
    while( true ) {
      func_0x4008dacc(DAT_400d07f0,uVar6,DAT_400d07ec,uVar7);
LAB_400dc985:
      iVar4 = FUN_400dd690(0,0xff,0);
      if (iVar4 != 0) break;
      uVar6 = 0x229;
      uVar7 = DAT_400d07f4;
    }
    while( true ) {
      uVar2 = FUN_400dd6e4(iVar4);
      if ((*(uint *)(uVar2 + 0xc) <= uVar3) &&
         (uVar3 < *(uint *)(uVar2 + 0xc) + *(int *)(uVar2 + 0x10))) break;
      iVar4 = FUN_400dd610(iVar4);
      if (iVar4 == 0) {
        func_0x4008da40();
        iVar4 = 0x10;
        do {
          iVar5 = FUN_400dd700(0,iVar4,0);
          if (iVar5 == 0) {
            return iVar4 - 0x10U & 0xff;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 != 0x21);
        func_0x4008dacc(DAT_400d07f0,0x17a,DAT_400d07fc,DAT_400d07f8);
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    }
    FUN_400dd6d8();
    *puVar1 = uVar2;
  }
  memw();
  return uVar2;
}



// Function at 0x400dc9cc

/* WARNING: Control flow encountered bad instruction data */

uint FUN_400dc9cc(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0x10;
  do {
    iVar1 = FUN_400dd700(0,iVar2,0);
    if (iVar1 == 0) {
      return iVar2 - 0x10U & 0xff;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0x21);
  func_0x4008dacc(DAT_400d07f0,0x17a,DAT_400d07fc,DAT_400d07f8);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// Function at 0x400dca04

bool FUN_400dca04(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  char acStack_62 [2];
  int aiStack_60 [8];
  undefined1 auStack_40 [64];
  
  iVar1 = FUN_400dc8ac(acStack_62 + 2);
  if ((iVar1 != 0) && (uVar2 = FUN_400dc9cc(), uVar2 != 0)) {
    acStack_62[0] = FUN_400dcc54(acStack_62 + 2);
    memw();
    memw();
    acStack_62[1] = FUN_400dcc54(auStack_40);
    memw();
    memw();
    uVar3 = FUN_400f7ab0(acStack_62 + 2,acStack_62,1);
    if (uVar3 != 0xffffffff) {
      uVar3 = (uVar3 ^ 0xffffffff) & 1;
      if (acStack_62[uVar3] == '\0') {
        iVar1 = FUN_400dd700(0,0,0);
        if ((iVar1 != 0) && (iVar1 = FUN_400dc864(iVar1,1), iVar1 == 0)) {
          return true;
        }
        if (acStack_62[uVar3] == '\0') {
          return false;
        }
      }
      iVar1 = FUN_400dd700(0,(*(int *)(acStack_62 + uVar3 * 0x20 + 2) - 1U) % uVar2 + 0x10);
      if (iVar1 != 0) {
        iVar1 = FUN_400dc864(iVar1,1);
        return iVar1 == 0;
      }
    }
  }
  return false;
}



// Function at 0x400dcab4

int FUN_400dcab4(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 auStack_60 [6];
  int aiStack_48 [18];
  
  iVar1 = FUN_400dc8ac(auStack_60);
  if (iVar1 == 0) {
    iVar3 = 0x105;
    goto LAB_400dcaf4;
  }
  uVar2 = FUN_400dcd84(auStack_60);
  if ((uVar2 == 0xffffffff) || (iVar3 = FUN_400dc9cc(), iVar3 == 0)) {
LAB_400dcb57:
    uVar4 = func_0x4008d9f8();
    FUN_400e4a50(1,DAT_400d07d4,DAT_400d0808,uVar4,DAT_400d07d4);
    iVar3 = -1;
  }
  else {
    if (param_1 == 0) {
      iVar3 = FUN_400dca04();
      if (iVar3 == 0) {
        uVar4 = func_0x4008d9f8();
        FUN_400e4a50(1,DAT_400d07d4,DAT_400d0804,uVar4,DAT_400d07d4);
        iVar3 = DAT_400d0800;
        goto LAB_400dcaf4;
      }
      aiStack_48[uVar2 * 8] = 3;
      if ((uVar2 & 0xff) < 2) {
        memw();
        iVar3 = FUN_400dc928(auStack_60,auStack_60[uVar2 * 8],uVar2 & 0xff,iVar1);
        if (iVar3 != 0) goto LAB_400dcaf4;
        func_0x400831b4();
        goto LAB_400dcb57;
      }
    }
    else {
      iVar3 = 0;
      if (aiStack_48[uVar2 * 8] == 2) goto LAB_400dcaf4;
      aiStack_48[uVar2 * 8] = 2;
      if ((uVar2 & 0xff) < 2) {
        iVar3 = FUN_400dc928(auStack_60,auStack_60[uVar2 * 8],uVar2 & 0xff,iVar1);
        goto LAB_400dcaf4;
      }
    }
    iVar3 = 0x102;
  }
LAB_400dcaf4:
  memw();
  return iVar3;
}



// Function at 0x400dcb78

undefined4 FUN_400dcb78(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400dcab4(1);
  return uVar1;
}



// Function at 0x400dcb84

undefined4 FUN_400dcb84(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400dcab4(0);
  return uVar1;
}



// Function at 0x400dcb90

undefined4 FUN_400dcb90(int param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int local_60 [6];
  int aiStack_48 [9];
  int iStack_24;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0 || param_1 == 0)) {
    return 0x102;
  }
  if (*(int *)(param_1 + 4) != 0) {
    return 0x106;
  }
  if (0xf < *(int *)(param_1 + 8) - 0x10U) {
    return 0x106;
  }
  uVar1 = FUN_400dc9cc();
  iVar2 = FUN_400dc8ac(local_60);
  if ((iVar2 == 0) || (uVar1 == 0)) {
LAB_400dcbd1:
    uVar5 = 0x105;
  }
  else {
    uVar3 = *(int *)(param_1 + 8) - 0x10;
    if (uVar3 == (local_60[0] - 1U) % uVar1) {
      iVar4 = FUN_400dcc40(local_60);
      iVar2 = 0;
      if (aiStack_48[1] != iVar4) goto LAB_400dcbe8;
    }
    else {
LAB_400dcbe8:
      if ((uVar3 != (aiStack_48[2] - 1U) % uVar1) ||
         (iVar2 = FUN_400dcc40(aiStack_48 + 2), iStack_24 != iVar2)) goto LAB_400dcbd1;
      iVar2 = 1;
    }
    uVar5 = 0;
    *param_2 = aiStack_48[iVar2 * 8];
    memw();
  }
  return uVar5;
}



// Function at 0x400dcc40

undefined4 FUN_400dcc40(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_400d080c)(0xffffffff,param_1,4);
  return uVar1;
}



// Function at 0x400dcc54

undefined4 FUN_400dcc54(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = FUN_400f7a94(param_1);
  uVar2 = 0;
  if (iVar1 == 0) {
    iVar3 = *(int *)(param_1 + 0x1c);
    iVar1 = FUN_400dcc40(param_1);
    uVar2 = 0;
    if (iVar3 == iVar1) {
      uVar2 = 1;
    }
  }
  return uVar2;
}



// Function at 0x400dcc78

undefined4 FUN_400dcc78(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (*(short *)(param_1 + 0xc) == 0) {
    uVar2 = func_0x40083e58();
    uVar6 = DAT_400d0818;
    uVar1 = 0;
    if (1 < param_2) {
      return 0;
    }
    uVar4 = (uint)((ulonglong)uVar2 * (ulonglong)DAT_400d0818 >> 0x25);
    iVar3 = uVar2 + uVar4 * -100;
    uVar5 = (uint)*(ushort *)(param_1 + 0xf);
    if (uVar2 < uVar5) {
      memw();
      uVar1 = func_0x4008d9f8();
      uVar6 = (uint)((ulonglong)uVar5 * (ulonglong)uVar6 >> 0x25);
      memw();
      FUN_400e4a50(1,DAT_400d0810,DAT_400d081c,uVar1,DAT_400d0810,uVar6,uVar5 + uVar6 * -100,uVar4,
                   iVar3);
      uVar1 = 0xffffffff;
    }
    if (param_2 != 1) {
      return uVar1;
    }
    uVar6 = (uint)*(ushort *)(param_1 + 0x11);
    if (0xfffd < (uVar6 - 1 & 0xffff)) {
      return uVar1;
    }
    if (uVar2 <= uVar6) {
      return uVar1;
    }
    uVar1 = func_0x4008d9f8();
    uVar2 = (uint)((ulonglong)uVar6 * (ulonglong)DAT_400d0818 >> 0x25);
    memw();
    FUN_400e4a50(1,DAT_400d0810,DAT_400d0820,uVar1,DAT_400d0810,uVar2,uVar6 + uVar2 * -100,uVar4,
                 iVar3);
  }
  else {
    uVar1 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d0810,DAT_400d0814,uVar1,DAT_400d0810,0,*(undefined2 *)(param_1 + 0xc));
  }
  return 0xffffffff;
}



// Function at 0x400dcd84

undefined4 FUN_400dcd84(int param_1)

{
  undefined4 uVar1;
  undefined1 uStack_22;
  undefined1 uStack_21;
  
  uVar1 = 0xffffffff;
  if (param_1 != 0) {
    uStack_22 = FUN_400dcc54(param_1);
    memw();
    memw();
    uStack_21 = FUN_400dcc54(param_1 + 0x20);
    memw();
    memw();
    uVar1 = FUN_400f7ab0(param_1,&uStack_22,1);
  }
  return uVar1;
}



// Function at 0x400dcdb8

undefined4 FUN_400dcdb8(void)

{
  undefined4 uVar1;
  
  uVar1 = func_0x40082244(0);
  return uVar1;
}



// Function at 0x400dcdc4

int FUN_400dcdc4(uint param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int aiStack_24 [9];
  
  aiStack_24[0] = *DAT_400d0824;
  if (aiStack_24[0] == 0) {
    iVar2 = param_1 - (param_1 & DAT_400d0830);
    memw();
    iVar3 = func_0x4008213c(param_1 & DAT_400d0830,iVar2 + param_2,0,aiStack_24);
    if (iVar3 == 0) {
      return aiStack_24[0] + iVar2;
    }
    uVar1 = func_0x4008d9f8();
    FUN_400e4a50(1,DAT_400d0828,DAT_400d0834,uVar1,DAT_400d0828,iVar3);
  }
  else {
    uVar1 = func_0x4008d9f8();
    FUN_400e4a50(1,DAT_400d0828,DAT_400d082c,uVar1,DAT_400d0828);
  }
  return 0;
}



// Function at 0x400dce24

void FUN_400dce24(int param_1)

{
  int *piVar1;
  
  piVar1 = DAT_400d0824;
  if ((param_1 != 0) && (*DAT_400d0824 != 0)) {
    func_0x400821ac();
  }
  *piVar1 = 0;
  memw();
  return;
}



// Function at 0x400dce40

undefined4 FUN_400dce40(undefined4 param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_4 == '\0') || (iVar1 = func_0x40083e78(), iVar1 == 0)) {
    uVar2 = func_0x40082c20(param_1,param_2,param_3);
  }
  else {
    uVar2 = func_0x40082310(param_1,param_2,param_3);
  }
  return uVar2;
}



// Function at 0x400dce6c

int FUN_400dce6c(int param_1,uint param_2,int *param_3,int param_4,uint param_5)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte abStack_35 [17];
  int iStack_24;
  
  iVar5 = param_3[0x37];
  memw();
  memw();
  iStack_24 = *DAT_400d0098;
  iVar4 = (iVar5 + 0x10U & 0xfffffff0) - iVar5;
  if ((param_1 != 0) || ((param_5 ^ 1) != 0)) {
    memw();
    iVar5 = FUN_400dce40(iVar5 + *param_3,abStack_35 + 1,iVar4,1);
    if (iVar5 != 0) goto LAB_400dcef9;
  }
  iVar5 = DAT_400d0838;
  bVar1 = abStack_35[iVar4];
  uVar3 = (param_2 >> 0x18 ^ param_2 >> 0x10 ^ param_2 ^ param_2 >> 8) & 0xff;
  if ((bVar1 == uVar3) || ((param_5 ^ 1) == 0)) {
    if (param_1 != 0) {
      memw();
      FUN_400dd3d8(param_1,abStack_35 + 1,iVar4);
    }
    iVar5 = 0;
    param_3[0x37] = param_3[0x37] + iVar4;
    memw();
  }
  else if (param_4 == 0) {
    memw();
    uVar2 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d083c,DAT_400d0840,uVar2,DAT_400d083c,uVar3,(uint)bVar1);
  }
LAB_400dcef9:
  memw();
  memw();
  if (iStack_24 != *DAT_400d0098) {
    iVar4 = func_0x400831d4();
    return iVar4;
  }
  return iVar5;
}



// Function at 0x400dcf40

int FUN_400dcf40(undefined4 *param_1,undefined4 param_2,int *param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  puVar3 = param_1 + 1;
  func_0x40086818(puVar3,0,0xfc);
  *param_1 = param_2;
  memw();
  iVar1 = FUN_400dce40(param_2,puVar3,0x18,1);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (param_4 != 0) {
    if ((*(char *)((int)param_1 + 0x1b) != '\0') && (param_3 != (int *)0x0)) {
      iVar1 = FUN_400dd3b8();
      *param_3 = iVar1;
      if (iVar1 == 0) {
        return 0x101;
      }
      memw();
      FUN_400dd3d8(iVar1,puVar3,0x18);
    }
    uVar4 = *param_1;
    if (*(char *)(param_1 + 1) != -0x17) {
      if (param_5 != 0) {
        return DAT_400d0838;
      }
      uVar2 = func_0x4008d9f8();
      FUN_400e4a50(1,DAT_400d083c,DAT_400d0844,uVar2,DAT_400d083c,uVar4);
      return DAT_400d0838;
    }
    iVar1 = FUN_400dcc78(puVar3,1);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (0x10 < *(byte *)((int)param_1 + 5)) {
      if (param_5 != 0) {
        return DAT_400d0838;
      }
      uVar2 = func_0x4008d9f8();
      memw();
      FUN_400e4a50(1,DAT_400d083c,DAT_400d0848,uVar2,DAT_400d083c,uVar4,
                   *(undefined1 *)((int)param_1 + 5),0x10);
      return DAT_400d0838;
    }
  }
  param_1[0x37] = 0x18;
  memw();
  return 0;
}



// Function at 0x400dd014

int FUN_400dd014(int *param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (*(char *)((int)param_1 + 0x1b) != '\0') {
    iVar1 = FUN_400dce40(*param_1 + param_1[0x37],param_1 + 0x38,0x20,1);
    if (iVar1 != 0) {
      return iVar1;
    }
    param_1[0x37] = param_1[0x37] + 0x20;
  }
  iVar1 = DAT_400d0838;
  uVar2 = param_1[0x37];
  iVar4 = 0;
  if ((param_2 < uVar2) && (iVar4 = iVar1, param_3 == 0)) {
    memw();
    uVar3 = func_0x4008d9f8();
    memw();
    FUN_400e4a50(1,DAT_400d083c,DAT_400d084c,uVar3,DAT_400d083c,uVar2,param_2);
  }
  return iVar4;
}



// Function at 0x400dd06c

int FUN_400dd06c(uint *param_1,int param_2,int param_3,uint *param_4)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint *puStack_3c;
  uint uStack_34;
  uint *puStack_30;
  
  uVar12 = param_1[0x37];
  iVar8 = 0;
  uVar2 = *param_1;
  puStack_3c = param_1 + 7;
  uVar7 = uVar2 + uVar12;
  puStack_30 = param_1 + 0x27;
  while( true ) {
    if ((int)(uint)*(byte *)((int)param_1 + 5) <= iVar8) {
      if (uVar7 < *param_1) {
        iVar8 = DAT_400d0838;
        if (param_2 == 0) {
          memw();
          uVar3 = func_0x4008d9f8();
          FUN_400e4a50(1,DAT_400d083c,DAT_400d0870,uVar3,DAT_400d083c);
          iVar8 = DAT_400d0838;
        }
      }
      else {
        param_1[0x37] = (param_1[0x37] - (uVar2 + uVar12)) + uVar7;
        memw();
        iVar8 = 0;
      }
      return iVar8;
    }
    iVar4 = FUN_400dce40(uVar7,puStack_3c,8,1);
    if (iVar4 != 0) break;
    if (param_3 != 0) {
      FUN_400dd3d8(param_3,puStack_3c,8);
    }
    uVar5 = puStack_3c[1];
    if (((uVar5 & 3) != 0) || (DAT_400d0258 < uVar5)) {
      if (param_2 != 0) {
        return DAT_400d0838;
      }
      uVar3 = func_0x4008d9f8();
      FUN_400e4a50(1,DAT_400d083c,DAT_400d0854,uVar3,DAT_400d083c,param_1[(iVar8 + 2) * 2 + 4]);
      return DAT_400d0838;
    }
    uVar7 = uVar7 + 8;
    uVar9 = *puStack_3c;
    if (((uVar9 + DAT_400d0858 <= DAT_400d085c) || (uVar9 + DAT_400d0860 <= DAT_400d0864)) &&
       (((uVar9 ^ uVar7) & 0xffff) != 0)) {
      if (param_2 != 0) {
        return DAT_400d0838;
      }
      memw();
      uVar3 = func_0x4008d9f8();
      memw();
      FUN_400e4a50(1,DAT_400d083c,DAT_400d0868,uVar3,DAT_400d083c,iVar8,uVar9,uVar7);
      return DAT_400d0838;
    }
    iVar4 = FUN_400dcdb8();
    memw();
    uStack_34 = uVar7;
    for (; uVar5 != 0; uVar5 = uVar5 - uVar9) {
      uVar9 = (iVar4 - (uint)((uStack_34 & 0xffff) != 0)) * 0x10000;
      uVar9 = (uVar9 < uVar5) * uVar9 + (uVar9 >= uVar5) * uVar5;
      if (param_4 != (uint *)0x0) {
        iVar6 = FUN_400dcdc4(uStack_34,uVar9);
        if (iVar6 == 0) {
          uVar3 = func_0x4008d9f8();
          memw();
          FUN_400e4a50(1,DAT_400d083c,DAT_400d086c,uVar3,DAT_400d083c,uStack_34,uVar9);
          return -1;
        }
        for (uVar10 = 0; uVar10 < uVar9; uVar10 = uVar10 + 4) {
          *param_4 = *param_4 ^ *(uint *)(iVar6 + uVar10);
          if ((param_3 != 0) && ((uVar10 & 0x3ff) == 0)) {
            uVar11 = uVar9 - uVar10;
            memw();
            FUN_400dd3d8(param_3,(uint *)(iVar6 + uVar10),
                         (uVar11 < 0x400) * uVar11 + (uint)(uVar11 >= 0x400) * 0x400);
          }
        }
        FUN_400dce24(iVar6);
      }
      uStack_34 = uStack_34 + uVar9;
    }
    iVar8 = iVar8 + 1;
    *puStack_30 = uVar7;
    puVar1 = puStack_3c + 1;
    puStack_3c = puStack_3c + 2;
    uVar7 = uVar7 + *puVar1;
    memw();
    puStack_30 = puStack_30 + 1;
  }
  uVar3 = func_0x4008d9f8();
  FUN_400e4a50(1,DAT_400d083c,DAT_400d0850,uVar3,DAT_400d083c,uVar7);
  return iVar4;
}



// Function at 0x400dd258

int FUN_400dd258(int param_1,int *param_2,int param_3)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uStack_4c;
  int local_48;
  undefined1 auStack_44 [32];
  int iStack_24;
  
  iVar5 = 0x102;
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  uStack_4c = 0xef;
  local_48 = 0;
  if (param_3 != 0) {
    if (DAT_400d0598 < (uint)param_2[1]) {
      if (param_1 != 1) {
        memw();
        uVar2 = func_0x4008d9f8();
        FUN_400e4a50(1,DAT_400d083c,DAT_400d0874,uVar2,DAT_400d083c,param_2[1]);
        iVar5 = 0x102;
      }
    }
    else {
      iVar3 = *param_2;
      bVar1 = param_1 == 1;
      piVar6 = (int *)0x0;
      if (iVar3 != 0x1000) {
        piVar6 = &local_48;
      }
      iVar5 = FUN_400dcf40(param_3,iVar3,piVar6,1,bVar1);
      if ((iVar5 == 0) && (iVar5 = FUN_400dd06c(param_3,bVar1,local_48,&uStack_4c), iVar5 == 0)) {
        uVar2 = func_0x40084368();
        iVar5 = FUN_400dce6c(local_48,uStack_4c,param_3,bVar1,uVar2);
        if ((iVar5 == 0) && (iVar5 = FUN_400dd014(param_3,param_2[1],bVar1), iVar5 == 0)) {
          if (((iVar3 != DAT_400d01d0) && (local_48 != 0)) &&
             (iVar4 = func_0x40084368(), iVar3 = local_48, iVar4 == 0)) {
            func_0x40086818(auStack_44,0,0x20);
            FUN_400dd408(iVar3,auStack_44);
            FUN_400f7b00(auStack_44,0x20,DAT_400d0878);
            iVar5 = func_0x40086624(param_3 + 0xe0,auStack_44,0x20);
            if (iVar5 != 0) {
              uVar2 = func_0x4008d9f8();
              FUN_400e4a50(1,DAT_400d083c,DAT_400d087c,uVar2,DAT_400d083c);
              FUN_400f7b00(param_3 + 0xe0,0x20,DAT_400d0880);
              iVar5 = DAT_400d0838;
            }
            local_48 = 0;
          }
          if (local_48 != 0) {
            memw();
            FUN_400dd408(local_48,0);
            local_48 = 0;
          }
          if (iVar5 == 0) goto LAB_400dd38c;
        }
      }
    }
    if (local_48 != 0) {
      FUN_400dd408(local_48,0);
    }
    func_0x40086818(param_3,0,0x100);
  }
LAB_400dd38c:
  memw();
  memw();
  if (iStack_24 != *DAT_400d0098) {
    memw();
    iVar5 = func_0x400831d4();
    return iVar5;
  }
  return iVar5;
}



// Function at 0x400dd3a8

undefined4 FUN_400dd3a8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400dd258(param_1,param_2,param_3);
  return uVar1;
}



// Function at 0x400dd3b8

int FUN_400dd3b8(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = func_0x4008dbdc(0x70);
  if (iVar1 != 0) {
    FUN_400e7190();
    iVar2 = FUN_400e71d0(iVar1,0);
    if (iVar2 == 0) {
      return iVar1;
    }
  }
  return 0;
}



// Function at 0x400dd3d8

void FUN_400dd3d8(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  uVar4 = CONCAT44(param_2,param_1);
  if (param_1 != 0) goto LAB_400dd3f4;
  uVar2 = 0x1e;
  uVar3 = DAT_400d0884;
  while( true ) {
    uVar4 = func_0x4008dacc(DAT_400d088c,uVar2,DAT_400d0888,uVar3);
LAB_400dd3f4:
    iVar1 = FUN_400e7314((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
    if (iVar1 == 0) break;
    uVar2 = 0x21;
    uVar3 = DAT_400d0890;
  }
  return;
}



// Function at 0x400dd408

void FUN_400dd408(int param_1,int param_2)

{
  int iVar1;
  int extraout_a3;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = param_2;
  if (param_1 != 0) goto LAB_400dd41f;
  uVar2 = 0x27;
  uVar3 = DAT_400d0884;
  while( true ) {
    func_0x4008dacc(DAT_400d088c,uVar2,DAT_400d0894,uVar3);
    iVar1 = extraout_a3;
LAB_400dd41f:
    if ((param_2 == 0) || (iVar1 = FUN_400e732c(param_1,iVar1), iVar1 == 0)) break;
    uVar2 = 0x2b;
    uVar3 = DAT_400d0890;
  }
  FUN_400e71a4(param_1);
  func_0x4008dbfc(param_1);
  return;
}



// Function at 0x400dd444

int FUN_400dd444(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined1 auStack_90 [20];
  undefined1 auStack_7c [88];
  int iStack_24;
  
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  memw();
  func_0x40085334(DAT_400d0898);
  piVar1 = DAT_400d089c;
  if (*DAT_400d089c == 0) {
    (*DAT_400d08c4)(auStack_7c);
    iVar2 = func_0x4008213c(0,DAT_400d01d0,0,&iStack_a4,&uStack_a0);
    if (iVar2 == 0) {
      iVar2 = iStack_a4 + DAT_400d0600;
      iVar8 = iStack_a4 + DAT_400d08a0;
      puVar7 = (undefined4 *)0x0;
      puVar6 = (undefined4 *)0x0;
      iStack_a4 = iVar2;
      while (iVar2 != iVar8) {
        func_0x400866b8(&uStack_9c,iVar2,0x20);
        if ((uStack_9c & 0xffff) == (DAT_400d08a4 & 0xffff)) {
          (*DAT_400d08cc)(&uStack_9c,auStack_7c);
          iVar2 = func_0x40086624(&uStack_9c,iVar2 + 0x10);
          if (iVar2 != 0) {
            uVar3 = func_0x4008d9f8();
            FUN_400e4a50(1,DAT_400d08b4,DAT_400d08bc,uVar3,DAT_400d08b4);
            iVar2 = 0x103;
            goto LAB_400dd4db;
          }
          *piVar1 = (int)puVar7;
          iVar2 = 0;
          goto LAB_400dd5b4;
        }
        if ((uStack_9c & 0xffff) != (DAT_400d08a8 & 0xffff)) break;
        (*DAT_400d08c8)(auStack_7c,&uStack_9c,0x20);
        puVar4 = (undefined4 *)func_0x4008dc54(0x30,1);
        if (puVar4 == (undefined4 *)0x0) break;
        *puVar4 = *DAT_400d08ac;
        puVar4[3] = uStack_98;
        puVar4[4] = uStack_94;
        puVar4[1] = uStack_9c >> 0x10 & 0xff;
        puVar4[2] = uStack_9c >> 0x18;
        *(byte *)((int)puVar4 + 0x25) = (byte)auStack_90._16_4_ & 1;
        *(undefined1 *)(puVar4 + 10) = 0;
        memw();
        memw();
        iVar5 = func_0x40083e78();
        if (iVar5 == 0) {
          *(undefined1 *)((int)puVar4 + 0x25) = 0;
          memw();
        }
        else if ((uStack_9c._2_1_ == '\0') || ((uStack_9c & DAT_400d08b0) == DAT_400d060c)) {
          *(undefined1 *)((int)puVar4 + 0x25) = 1;
          memw();
          memw();
        }
        memw();
        func_0x40086d48(puVar4 + 5,auStack_90,0x10);
        if (puVar6 == (undefined4 *)0x0) {
          puVar4[0xb] = puVar7;
          puVar7 = puVar4;
        }
        else {
          puVar4[0xb] = puVar6[0xb];
          puVar6[0xb] = puVar4;
          memw();
        }
        iVar2 = iVar2 + 0x20;
        memw();
        puVar6 = puVar4;
      }
      memw();
      uVar3 = func_0x4008d9f8();
      FUN_400e4a50(1,DAT_400d08b4,DAT_400d08b8,uVar3,DAT_400d08b4);
      iVar2 = 0x105;
LAB_400dd4db:
      while (puVar7 != (undefined4 *)0x0) {
        puVar6 = (undefined4 *)puVar7[0xb];
        func_0x4008dbfc(puVar7);
        puVar7 = puVar6;
      }
LAB_400dd5b4:
      memw();
      func_0x400821ac(uStack_a0);
      if (iVar2 == 0) goto LAB_400dd466;
    }
    uVar3 = func_0x4008d9f8();
    FUN_400e4a50(1,DAT_400d08b4,DAT_400d08c0,uVar3,DAT_400d08b4,iVar2);
  }
  else {
LAB_400dd466:
    iVar2 = 0;
  }
  func_0x40085374(DAT_400d0898);
  memw();
  memw();
  if (iStack_24 == *DAT_400d0098) {
    return iVar2;
  }
  iVar2 = func_0x400831d4();
  return iVar2;
}



// Function at 0x400dd610

int * FUN_400dd610(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == (int *)0x0) {
    func_0x4008dacc(DAT_400d08d8,0x6a,DAT_400d08d4,DAT_400d08d0);
  }
  uVar1 = DAT_400d0898;
  if (param_1[3] != 0) {
    func_0x40085334(DAT_400d0898);
    while ((iVar3 = param_1[3], iVar3 != 0 &&
           ((((*param_1 != 0xff && (*param_1 != *(int *)(iVar3 + 4))) ||
             ((param_1[1] != 0xff && (param_1[1] != *(int *)(iVar3 + 8))))) ||
            ((param_1[2] != 0 && (iVar2 = func_0x40086a70(param_1[2],iVar3 + 0x14), iVar2 != 0))))))
          ) {
      param_1[3] = *(int *)(iVar3 + 0x2c);
      memw();
    }
    func_0x40085374(uVar1);
    iVar3 = param_1[3];
    if (iVar3 != 0) {
      param_1[4] = iVar3;
      param_1[3] = *(int *)(iVar3 + 0x2c);
      memw();
      return param_1;
    }
  }
  func_0x4008dbfc(param_1);
  return (int *)0x0;
}



// Function at 0x400dd690

undefined4 FUN_400dd690(int param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  piVar1 = DAT_400d089c;
  if (((*DAT_400d089c == 0) && (iVar3 = FUN_400dd444(), iVar3 != 0)) ||
     ((param_1 == 0xff && (param_2 != 0xff)))) {
    uVar2 = 0;
  }
  else {
    piVar4 = (int *)func_0x4008dbdc(0x14);
    *piVar4 = param_1;
    piVar4[3] = *piVar1;
    piVar4[4] = 0;
    piVar4[1] = param_2;
    piVar4[2] = param_3;
    memw();
    uVar2 = FUN_400dd610();
  }
  return uVar2;
}



// Function at 0x400dd6d8

void FUN_400dd6d8(undefined4 param_1)

{
  func_0x4008dbfc(param_1);
  return;
}



// Function at 0x400dd6e4

undefined4 FUN_400dd6e4(int param_1)

{
  if (param_1 == 0) {
    func_0x4008dacc(DAT_400d08d8,0x131,DAT_400d08e0,DAT_400d08dc);
  }
  return *(undefined4 *)(param_1 + 0x10);
}



// Function at 0x400dd700

int FUN_400dd700(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_400dd690(param_1,param_2,param_3);
  iVar2 = iVar1;
  if (iVar1 != 0) {
    iVar2 = FUN_400dd6e4();
    func_0x4008dbfc(iVar1);
  }
  return iVar2;
}



// Function at 0x400dd720

undefined4 FUN_400dd720(int *param_1,uint param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    func_0x4008dacc(DAT_400d08d8,0x1c8,DAT_400d08e8,DAT_400d08e4);
  }
  uVar1 = 0x102;
  if ((param_2 <= (uint)param_1[4]) && (uVar1 = 0x104, param_2 + param_4 <= (uint)param_1[4])) {
    iVar2 = *param_1;
    if (*(char *)((int)param_1 + 0x25) == '\0') {
      uVar1 = func_0x4008293c(iVar2,param_3,param_2 + param_1[3]);
    }
    else {
      uVar1 = 0x106;
      if (iVar2 == *DAT_400d08ac) {
        uVar1 = func_0x40082aa4(iVar2,param_2 + param_1[3],param_3);
      }
    }
  }
  return uVar1;
}



// Function at 0x400dd774

undefined4 FUN_400dd774(undefined4 *param_1,uint param_2,undefined4 param_3,int param_4)

{
  undefined4 extraout_a3;
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    func_0x4008dacc(DAT_400d08d8,0x1e9,DAT_400d08ec,DAT_400d08e4);
    param_3 = extraout_a3;
  }
  uVar1 = 0x102;
  if ((param_2 <= (uint)param_1[4]) && (uVar1 = 0x104, param_2 + param_4 <= (uint)param_1[4])) {
    uVar1 = func_0x4008282c(*param_1,param_3,param_2 + param_1[3]);
  }
  return uVar1;
}



// Function at 0x400dd7ac

undefined4 FUN_400dd7ac(undefined4 *param_1,uint param_2,undefined4 param_3,int param_4)

{
  undefined4 extraout_a3;
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    func_0x4008dacc(DAT_400d08d8,0x1fb,DAT_400d08f0,DAT_400d08e4);
    param_3 = extraout_a3;
  }
  uVar1 = 0x102;
  if ((param_2 <= (uint)param_1[4]) && (uVar1 = 0x104, param_2 + param_4 <= (uint)param_1[4])) {
    uVar1 = func_0x4008293c(*param_1,param_3,param_2 + param_1[3]);
  }
  return uVar1;
}



// Function at 0x400dd7e4

undefined4 FUN_400dd7e4(undefined4 *param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    func_0x4008dacc(DAT_400d08d8,0x20e,DAT_400d08f4,DAT_400d08e4);
  }
  uVar1 = 0x102;
  if ((((param_2 <= (uint)param_1[4]) && (uVar1 = 0x104, param_2 + param_3 <= (uint)param_1[4])) &&
      ((param_3 & 0xfff) == 0)) && (uVar1 = 0x102, (param_2 & 0xfff) == 0)) {
    uVar1 = func_0x40082620(*param_1,param_2 + param_1[3]);
  }
  return uVar1;
}



// Function at 0x400dd828

int FUN_400dd828(int *param_1,uint param_2,int param_3,undefined4 param_4,int *param_5,
                undefined4 param_6)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    func_0x4008dacc(DAT_400d08d8,0x22e,DAT_400d08f8,DAT_400d08e4,param_6);
  }
  iVar2 = 0x102;
  if (((param_2 <= (uint)param_1[4]) && (iVar2 = 0x104, param_2 + param_3 <= (uint)param_1[4])) &&
     (iVar2 = 0x106, *param_1 == *DAT_400d08ac)) {
    uVar1 = param_2 + param_1[3] & 0xffff;
    iVar2 = func_0x4008213c(param_2 + param_1[3] & DAT_400d0830,param_3 + uVar1);
    if (iVar2 == 0) {
      *param_5 = *param_5 + uVar1;
    }
  }
  memw();
  return iVar2;
}



// Function at 0x400dd884

int FUN_400dd884(int *param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint extraout_a3;
  int *piVar2;
  uint uVar3;
  int *in_t0;
  undefined4 uStack_28;
  undefined4 auStack_24 [9];
  
  piVar2 = param_1;
  uVar3 = param_2;
  if (param_1 == (int *)0x0) {
    piVar2 = in_t0;
    func_0x4008dacc(DAT_400d08d8,0x19e,DAT_400d08fc,DAT_400d08e4);
    uVar3 = extraout_a3;
  }
  iVar1 = 0x102;
  if ((param_2 <= (uint)param_1[4]) && (iVar1 = 0x104, param_2 + param_4 <= (uint)param_1[4])) {
    if (*(char *)((int)piVar2 + 0x25) == '\0') {
      iVar1 = func_0x4008282c(*piVar2,param_3,param_2 + piVar2[3],param_4);
    }
    else {
      iVar1 = 0x106;
      if ((*piVar2 == *DAT_400d08ac) &&
         (iVar1 = FUN_400dd828(piVar2,uVar3,param_4,0,&uStack_28,auStack_24), iVar1 == 0)) {
        func_0x400866b8(param_3,uStack_28,param_4);
        func_0x400821ac(auStack_24[0]);
      }
    }
  }
  return iVar1;
}



// Function at 0x400dd928

uint FUN_400dd928(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  if (DAT_400d0908 < param_1 + DAT_400d0904) {
    uVar1 = ((int)(param_1 + DAT_400d0904) >> 0x10) + 0x40;
    if ((int)param_1 <= DAT_400d090c) {
      iVar2 = param_1 + DAT_400d0860;
      if (iVar2 < 0) {
        iVar2 = iVar2 + DAT_400d0020;
      }
      uVar1 = iVar2 >> 0x10;
    }
    if ((uVar1 < 0x100) && (uVar1 = func_0x40081e88(), uVar1 != 0x100)) {
      return (uVar1 & 0xff) << 0x10 | param_1 & 0xffff;
    }
  }
  return 0xffffffff;
}



// Function at 0x400dd98c

void FUN_400dd98c(void)

{
  FUN_400dda94();
  return;
}



// Function at 0x400dd994

undefined4 FUN_400dd994(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (iVar2 == 0) {
    iVar2 = *DAT_400d08ac;
  }
  *param_1 = iVar2;
  uVar1 = DAT_400d0910;
  if (iVar2 != 0) {
    memw();
    iVar2 = FUN_400f7b08();
    if (iVar2 != 0) {
      uVar1 = 0;
    }
  }
  return uVar1;
}



// Function at 0x400dd9b8

undefined4 FUN_400dd9b8(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = func_0x40082470(param_1,param_2,1);
  return uVar1;
}



// Function at 0x400dd9c8

undefined4 FUN_400dd9c8(char param_1)

{
  undefined4 uVar1;
  
  if (param_1 == '\0') {
    uVar1 = FUN_400dda70(*DAT_400d08ac);
  }
  else {
    uVar1 = func_0x40082dac();
  }
  return uVar1;
}



// Function at 0x400dda70

undefined4 FUN_400dda70(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_400d0934;
  uVar3 = *DAT_400d0930;
  func_0x40086818(DAT_400d0934 + 1,0,0xc);
  uVar2 = DAT_400d0938;
  *(undefined4 **)(param_1 + 0xc) = puVar1;
  *(undefined4 *)(param_1 + 8) = uVar2;
  *puVar1 = uVar3;
  memw();
  return 0;
}



// Function at 0x400dda94

void FUN_400dda94(void)

{
  int iVar1;
  
  iVar1 = func_0x400893a4(4);
  *DAT_400d093c = iVar1;
  if (iVar1 == 0) {
    memw();
    func_0x4008dacc(DAT_400d0948,0x5d,DAT_400d0944,DAT_400d0940);
  }
  return;
}



// Function at 0x400ddab8

void FUN_400ddab8(void)

{
  func_0x40089878(*DAT_400d093c,0xffffffff);
  return;
}



// Function at 0x400ddadc

void FUN_400ddadc(void)

{
  if (*DAT_400d094c != 0) {
    func_0x40089194(*DAT_400d094c,0,0);
  }
  return;
}



// Function at 0x400ddaf4

void FUN_400ddaf4(void)

{
  if (*DAT_400d094c != 0) {
    func_0x400896ec(*DAT_400d094c,0xffffffff);
  }
  return;
}



// Function at 0x400ddb08

undefined4 FUN_400ddb08(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_400d094c;
  if (*DAT_400d094c == 0) {
    iVar2 = func_0x400893a4(1);
    *piVar1 = iVar2;
    if (iVar2 == 0) {
      memw();
      return 0x101;
    }
  }
  return 0;
}



// Function at 0x400ddb2c

int FUN_400ddb2c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_400ddb08();
  if (iVar1 == 0) {
    FUN_400ddaf4();
    uVar2 = FUN_400de028();
    iVar1 = FUN_400de13c(uVar2,param_1);
    memw();
    FUN_400ddadc();
  }
  return iVar1;
}



// Function at 0x400ddb6c

undefined4 FUN_400ddb6c(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400ddb2c(DAT_400d0950);
  return uVar1;
}



// Function at 0x400ddb7c

int FUN_400ddb7c(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iStack_48;
  undefined1 auStack_44 [2];
  byte bStack_42;
  undefined1 auStack_3c [20];
  undefined1 uStack_28;
  undefined1 uStack_27;
  int iStack_24;
  
  piVar1 = DAT_400d0098;
  memw();
  iStack_24 = *DAT_400d0098;
  iVar2 = *(int *)(param_1 + 0x10);
  memw();
  do {
    if (iVar2 == 0) {
LAB_400ddc24:
      memw();
      memw();
      if (iStack_24 != *piVar1) {
        iVar2 = func_0x400831d4();
        return iVar2;
      }
      return iVar2;
    }
    iStack_48 = 0;
    while( true ) {
      memw();
      iVar3 = FUN_400de698(iVar2,0xff,0x48,0,&iStack_48,auStack_44,0xff,0xff);
      if (iVar3 != 0) break;
      piVar4 = (int *)func_0x4008dbdc(0x1c);
      if (piVar4 == (int *)0x0) {
        iVar2 = 0x101;
        goto LAB_400ddc24;
      }
      *piVar4 = 0;
      piVar4[1] = 0;
      memw();
      func_0x40086d48(piVar4 + 2,auStack_3c,0x10);
      *(undefined1 *)((int)piVar4 + 0x17) = 0;
      memw();
      *(undefined1 *)(piVar4 + 6) = auStack_44[0];
      memw();
      *(undefined1 *)((int)piVar4 + 0x1a) = uStack_27;
      memw();
      *(undefined1 *)((int)piVar4 + 0x19) = uStack_28;
      memw();
      if (param_2[1] != 0) {
        *(int **)(param_2[1] + 4) = piVar4;
      }
      *piVar4 = param_2[1];
      iVar3 = *param_2;
      piVar4[1] = 0;
      param_2[1] = (int)piVar4;
      if (iVar3 == 0) {
        *param_2 = (int)piVar4;
      }
      param_2[2] = param_2[2] + 1;
      iStack_48 = (uint)bStack_42 + iStack_48;
      memw();
    }
    iVar2 = *(int *)(iVar2 + 4);
  } while( true );
}



// Function at 0x400ddc38

void FUN_400ddc38(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iStack_e8;
  undefined1 uStack_e4;
  undefined1 uStack_e3;
  byte bStack_e2;
  undefined1 uStack_e1;
  undefined1 auStack_dc [24];
  undefined1 auStack_c4 [32];
  undefined1 auStack_a4 [32];
  undefined1 auStack_84 [32];
  undefined1 auStack_64 [32];
  char acStack_44 [3];
  byte bStack_41;
  undefined1 auStack_3c [24];
  int iStack_24;
  
  memw();
  iStack_24 = *DAT_400d0098;
  iVar2 = *(int *)(param_1 + 0x10);
  memw();
  do {
    if (iVar2 == 0) {
      memw();
      memw();
      if (iStack_24 != *DAT_400d0098) {
        func_0x400831d4();
        return;
      }
      return;
    }
    iStack_e8 = 0;
    while( true ) {
      memw();
      iVar3 = FUN_400de698(iVar2,0xff,0x42,0,&iStack_e8,&uStack_e4,0xff,0xff);
      if (iVar3 != 0) break;
      iVar3 = *param_2;
      func_0x400866b8(auStack_c4,&uStack_e4,0x20);
      uVar4 = func_0x400866b8(auStack_a4,auStack_c4,0x20);
      func_0x400866b8(auStack_64,uVar4,0x20);
      func_0x400866b8(acStack_44,auStack_64,0x20);
      func_0x400866b8(auStack_84,acStack_44,0x20);
      func_0x400866b8(auStack_64,auStack_84,0x20);
      func_0x400866b8(acStack_44,auStack_64,0x20);
      cVar1 = acStack_44[0];
      uVar6 = (uint)bStack_41;
      for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
        memw();
        iVar5 = func_0x40086cd0(auStack_3c,iVar3 + 8,0xf);
        if ((((iVar5 == 0) && (*(char *)(iVar3 + 0x18) == cVar1)) &&
            (*(byte *)(iVar3 + 0x1a) <= uVar6)) &&
           (uVar6 < (uint)*(byte *)(iVar3 + 0x19) + (uint)*(byte *)(iVar3 + 0x1a)))
        goto LAB_400ddd36;
      }
      FUN_400de85c(iVar2,uStack_e4,uStack_e3,auStack_dc,uStack_e1,0xff);
LAB_400ddd36:
      iStack_e8 = (uint)bStack_e2 + iStack_e8;
      memw();
    }
    iVar2 = *(int *)(iVar2 + 4);
  } while( true );
}



// Function at 0x400ddd5c

void FUN_400ddd5c(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  
  while (piVar2 = (int *)*param_1, piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    piVar2 = (int *)piVar2[1];
    if (iVar1 == 0) {
      *param_1 = piVar2;
      memw();
    }
    else {
      *(int **)(iVar1 + 4) = piVar2;
    }
    if (piVar2 == (int *)0x0) {
      param_1[1] = iVar1;
      memw();
    }
    else {
      *piVar2 = iVar1;
    }
    param_1[2] = param_1[2] + -1;
    memw();
    func_0x4008dbfc();
  }
  return;
}



// Function at 0x400ddd94

void FUN_400ddd94(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_400ddd5c(param_1 + 0x38);
  iVar1 = *(int *)(param_1 + 0x28);
  if (iVar1 != 0) {
    iVar2 = iVar1 + *(int *)(iVar1 + -4) * 0x54;
    for (iVar3 = iVar2; iVar1 != iVar3; iVar3 = iVar3 + -0x54) {
      FUN_400de2a0(iVar3 + -0x10);
    }
    FUN_400e79c8(iVar2 + (((uint)(iVar2 - iVar1) >> 2) * DAT_400d0954 & DAT_400d0280) * -0x54 + -4);
  }
  return;
}



// Function at 0x400dddf0

int FUN_400dddf0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  int *piStack_50;
  int *piStack_4c;
  int *piStack_48;
  undefined1 uStack_44;
  char cStack_43;
  byte bStack_42;
  undefined1 auStack_3c [16];
  undefined1 uStack_2c;
  int iStack_24;
  
  piVar1 = DAT_400d0098;
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  memw();
  iVar3 = FUN_400dee98(param_1 + 0x10,*(undefined4 *)(param_1 + 8),param_2,param_3);
  if (iVar3 == 0) {
    FUN_400ddd5c(param_1 + 0x38);
    *(undefined4 *)(param_1 + 0x44) = 0;
    for (piVar5 = *(int **)(param_1 + 0x10); uVar2 = DAT_400d0140, piVar5 != (int *)0x0;
        piVar5 = (int *)piVar5[1]) {
      piStack_50 = (int *)0x0;
      while( true ) {
        memw();
        iVar3 = FUN_400de698(piVar5,0,1,0,&piStack_50,&uStack_44,0xff,0xff);
        if (iVar3 != 0) break;
        puVar4 = (undefined4 *)func_0x4008dbdc(0x1c);
        if (puVar4 == (undefined4 *)0x0) {
          *(undefined4 *)(param_1 + 100) = 0;
          memw();
          goto LAB_400ddf1d;
        }
        *puVar4 = 0;
        puVar4[1] = 0;
        memw();
        func_0x40086d48(puVar4 + 2,auStack_3c,0x10);
        *(undefined1 *)((int)puVar4 + 0x17) = 0;
        memw();
        if (cStack_43 != '\x01') {
          iVar3 = -1;
          goto LAB_400dde1d;
        }
        *(undefined1 *)(puVar4 + 6) = uStack_2c;
        memw();
        memw();
        FUN_400f7b18(param_1 + 0x38,puVar4);
        iVar3 = param_1 + (uint)(*(byte *)(puVar4 + 6) >> 5) * 4;
        *(uint *)(iVar3 + 0x44) =
             *(uint *)(iVar3 + 0x44) | 1 << 0x20 - (0x20 - (*(byte *)(puVar4 + 6) & 0x1f));
        piStack_50 = (int *)((uint)bStack_42 + (int)piStack_50);
        memw();
      }
    }
    *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) & 0xfffffffe | 1;
    *(uint *)(param_1 + 0x60) = *(uint *)(param_1 + 0x60) & uVar2 | DAT_400d0284;
    *(undefined4 *)(param_1 + 100) = 1;
    memw();
    piStack_50 = piVar5;
    piStack_4c = piVar5;
    piStack_48 = piVar5;
    iVar3 = FUN_400ddb7c(param_1,&piStack_50);
    if (iVar3 == 0) {
      FUN_400ddc38(param_1,&piStack_50);
      while (iVar3 = 0, piStack_50 != (int *)0x0) {
        piVar5 = (int *)*piStack_50;
        piVar6 = (int *)piStack_50[1];
        if (piVar5 == (int *)0x0) {
          memw();
          piStack_50 = piVar6;
        }
        else {
          piVar5[1] = (int)piVar6;
        }
        if (piVar6 == (int *)0x0) {
          memw();
          piStack_4c = piVar5;
        }
        else {
          *piVar6 = (int)piVar5;
        }
        piStack_48 = (int *)((int)piStack_48 + -1);
        memw();
        func_0x4008dbfc();
      }
    }
    else {
      *(undefined4 *)(param_1 + 100) = 0;
LAB_400ddf1d:
      iVar3 = 0x101;
      memw();
    }
  }
  else {
    *(undefined4 *)(param_1 + 100) = 0;
  }
LAB_400dde1d:
  memw();
  memw();
  if (iStack_24 == *piVar1) {
    return iVar3;
  }
  memw();
  iVar3 = func_0x400831d4();
  return iVar3;
}



// Function at 0x400ddf70

undefined4 FUN_400ddf70(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400dd774(*(undefined4 *)(param_1 + 0xc),param_2,param_3,param_4);
  return uVar1;
}



// Function at 0x400ddf88

undefined4 FUN_400ddf88(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400dd7ac(*(undefined4 *)(param_1 + 0xc),param_2,param_3,param_4);
  return uVar1;
}



// Function at 0x400ddfa0

undefined4 FUN_400ddfa0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400dd7e4(*(undefined4 *)(param_1 + 0xc),param_2,param_3);
  return uVar1;
}



// Function at 0x400ddfb0

void FUN_400ddfb0(undefined4 param_1)

{
  func_0x4008dbfc(param_1);
  return;
}



// Function at 0x400ddfbc

undefined4 FUN_400ddfbc(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  
  uVar1 = 0x102;
  if ((param_4 & 0xf) == 0) {
    uVar1 = FUN_400dd884(*(undefined4 *)(param_1 + 0xc),param_2,param_3,param_4);
  }
  return uVar1;
}



// Function at 0x400ddfdc

undefined4 FUN_400ddfdc(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  
  uVar1 = 0x102;
  if ((param_4 & 0xf) == 0) {
    uVar1 = FUN_400dd720(*(undefined4 *)(param_1 + 0xc),param_2,param_3,param_4);
  }
  return uVar1;
}



// Function at 0x400ddffc

void FUN_400ddffc(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  param_1[1] = 0;
  param_1[2] = 0;
  uVar1 = DAT_400d0958;
  param_1[3] = param_2;
  *param_1 = uVar1;
  if (param_2 == 0) {
    memw();
    func_0x4008da40();
  }
  return;
}



// Function at 0x400de01c

void FUN_400de01c(undefined4 param_1)

{
  func_0x4008dbfc(param_1);
  return;
}



// Function at 0x400de028

int FUN_400de028(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  piVar1 = DAT_400d095c;
  if (*DAT_400d095c == 0) {
    puVar3 = (undefined4 *)func_0x4008dbdc(0x28);
    uVar2 = DAT_400d0960;
    if (puVar3 != (undefined4 *)0x0) {
      puVar3[1] = 0;
      *puVar3 = uVar2;
      puVar3[2] = 0;
      puVar3[3] = 0;
      puVar3[4] = 0;
      puVar3[5] = 0;
      puVar3[6] = 0;
      puVar3[7] = 0;
      puVar3[8] = 0;
      puVar3[9] = 0;
    }
    *piVar1 = (int)puVar3;
  }
  memw();
  return *piVar1;
}



// Function at 0x400de05c

void FUN_400de05c(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x10);
  while( true ) {
    if (iVar1 == 0) {
      return;
    }
    uVar2 = (**(code **)(**(int **)(iVar1 + 8) + 8))();
    iVar3 = func_0x40086a70(uVar2,param_2);
    if (iVar3 == 0) break;
    iVar1 = *(int *)(iVar1 + 4);
  }
  return;
}



// Function at 0x400de080

int FUN_400de080(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = (**(code **)(*param_2 + 8))(param_2);
  piVar2 = (int *)FUN_400de05c(param_1,uVar1);
  if (piVar2 == (int *)0x0) {
    piVar3 = (int *)func_0x4008dbdc(0x68);
    iVar5 = 0x101;
    if (piVar3 == (int *)0x0) goto LAB_400de0f6;
    *piVar3 = 0;
    piVar3[1] = 0;
    piVar3[4] = 0;
    piVar3[5] = 0;
    piVar3[6] = 0;
    piVar3[7] = 0;
    piVar3[8] = 0;
    piVar3[9] = 0;
    piVar3[10] = 0;
    piVar3[0xe] = 0;
    piVar3[0xf] = 0;
    piVar3[0x10] = 0;
    piVar3[0x19] = 0;
    piVar3[2] = (int)param_2;
    piVar2 = piVar3;
  }
  else {
    for (piVar3 = *(int **)(param_1 + 0x1c); piVar3 != (int *)0x0; piVar3 = (int *)piVar3[2]) {
      if (piVar3 == param_2) {
        FUN_400f7b70(param_1 + 0x1c,piVar3);
        (**(code **)(*piVar3 + 4))(piVar3);
        piVar3 = (int *)0x0;
        break;
      }
    }
  }
  memw();
  iVar5 = FUN_400dddf0(piVar2,param_3,param_4);
  if (piVar3 != (int *)0x0) {
    if (iVar5 == 0) {
      iVar4 = *(int *)(param_1 + 0x14);
      if (iVar4 != 0) {
        *(int **)(iVar4 + 4) = piVar3;
      }
      *piVar3 = iVar4;
      piVar3[1] = 0;
      *(int **)(param_1 + 0x14) = piVar3;
      if (*(int *)(param_1 + 0x10) == 0) {
        *(int **)(param_1 + 0x10) = piVar3;
      }
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
    }
    else {
      memw();
      FUN_400ddd94(piVar3);
      func_0x4008dbfc(piVar3);
    }
  }
LAB_400de0f6:
  memw();
  return iVar5;
}



// Function at 0x400de13c

int FUN_400de13c(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *local_24 [9];
  
  uVar1 = func_0x40086c6c(param_2);
  iVar2 = 0x102;
  if (uVar1 < 0x11) {
    iVar3 = FUN_400de05c(param_1,param_2);
    iVar2 = 0;
    if (iVar3 == 0) {
      local_24[0] = (int *)0x0;
      memw();
      iVar2 = FUN_400df1fc(param_2,local_24);
      if (iVar2 == 0) {
        uVar1 = (**(code **)(*local_24[0] + 0x24))();
        iVar2 = FUN_400de080(param_1,local_24[0],0,uVar1 >> 0xc);
        if (iVar2 == 0) {
          iVar3 = *(int *)(param_1 + 0x20);
          if (iVar3 != 0) {
            *(int **)(iVar3 + 8) = local_24[0];
          }
          local_24[0][2] = 0;
          local_24[0][1] = iVar3;
          *(int **)(param_1 + 0x20) = local_24[0];
          if (*(int *)(param_1 + 0x1c) == 0) {
            *(int **)(param_1 + 0x1c) = local_24[0];
          }
          *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
          goto LAB_400de1a0;
        }
      }
      if (local_24[0] != (int *)0x0) {
        (**(code **)(*local_24[0] + 4))();
      }
    }
  }
LAB_400de1a0:
  memw();
  return iVar2;
}



// Function at 0x400de1b4

undefined4 FUN_400de1b4(int *param_1,undefined4 param_2,byte param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  iVar1 = FUN_400df260(param_2);
  if (param_1[2] == 0) {
LAB_400de1f5:
    piVar2 = (int *)func_0x4008dbdc(0x80);
    uVar5 = 0x101;
    if (piVar2 == (int *)0x0) goto LAB_400de1ee;
    FUN_400f7bac();
    iVar3 = param_1[1];
    if (iVar3 != 0) {
      *(int **)(iVar3 + 4) = piVar2;
    }
    *piVar2 = iVar3;
    piVar2[1] = 0;
    param_1[1] = (int)piVar2;
    if (*param_1 == 0) {
      *param_1 = (int)piVar2;
    }
    param_1[2] = param_1[2] + 1;
    piVar2[3] = (uint)param_3 | iVar1 << 8;
    piVar2[2] = piVar2[2] + 1;
    memw();
  }
  else {
    iVar3 = param_1[1];
    uVar4 = *(uint *)(iVar3 + 8);
    if (0x1c < uVar4) goto LAB_400de1f5;
    *(uint *)(iVar3 + 8) = uVar4 + 1;
    *(byte *)(iVar3 + (uVar4 + 3) * 4) = param_3;
    memw();
    iVar3 = iVar3 + uVar4 * 4;
    *(uint *)(iVar3 + 0xc) = (uint)*(byte *)(iVar3 + 0xc) | iVar1 << 8;
  }
  uVar5 = 0;
LAB_400de1ee:
  memw();
  return uVar5;
}



// Function at 0x400de23c

uint FUN_400de23c(int *param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = FUN_400df260(param_3);
  iVar3 = *param_1;
  do {
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    for (iVar4 = 0; *(int *)(iVar3 + 8) != iVar4; iVar4 = iVar4 + 1) {
      iVar5 = iVar3 + iVar4 * 4;
      uVar2 = (uint)*(byte *)(iVar5 + 0xc);
      if (((param_2 <= uVar2) && (*(uint *)(iVar5 + 0xc) >> 8 == (uVar1 & DAT_400d0258))) &&
         (uVar2 != 0xff)) {
        return uVar2;
      }
    }
    iVar3 = *(int *)(iVar3 + 4);
  } while( true );
}



// Function at 0x400de280

void FUN_400de280(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  while (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 4);
    FUN_400f7bcc(param_1,iVar1);
    func_0x4008dbfc(iVar1);
    iVar1 = iVar2;
  }
  return;
}



// Function at 0x400de2a0

void FUN_400de2a0(undefined4 param_1)

{
  FUN_400de280(param_1);
  return;
}



// Function at 0x400de2ac

undefined4 FUN_400de2ac(int *param_1,uint param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar3 = *param_1;
  do {
    if (iVar3 == 0) {
      return 0;
    }
    iVar5 = 0;
    bVar2 = false;
    iVar4 = *(int *)(iVar3 + 8);
    bVar1 = false;
    while (iVar4 != iVar5) {
      iVar6 = iVar3 + iVar5 * 4;
      uVar7 = (uint)*(byte *)(iVar6 + 0xc);
      if (uVar7 == param_2) {
        bVar2 = true;
        *(undefined1 *)(iVar6 + 0xc) = 0xff;
        memw();
LAB_400de2da:
        if (bVar1) goto LAB_400de2e9;
      }
      else {
        if (uVar7 == 0xff) goto LAB_400de2da;
        bVar1 = true;
LAB_400de2e9:
        if (bVar2) {
          return 1;
        }
      }
      iVar5 = iVar5 + 1;
      memw();
    }
    iVar4 = *(int *)(iVar3 + 4);
    if (!bVar1) {
      FUN_400f7bcc(param_1,iVar3);
      func_0x4008dbfc(iVar3);
    }
    iVar3 = iVar4;
    if (bVar2) {
      return 1;
    }
  } while( true );
}



// Function at 0x400de310

void FUN_400de310(undefined1 *param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 int param_5,undefined1 param_6)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[3] = param_6;
  memw();
  *(undefined4 *)(param_1 + 8) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  if (param_5 == 0) {
    param_1[8] = 0;
    memw();
    memw();
  }
  else {
    memw();
    func_0x40086d48(param_1 + 8,param_5,0xf);
    param_1[0x17] = 0;
    memw();
  }
  memw();
  return;
}



// Function at 0x400de35c

void FUN_400de35c(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0xffffffff;
  *(undefined1 *)(param_1 + 5) = 0xfe;
  memw();
  param_1[0xe] = 0xffffffff;
  param_1[0xf] = 0xffffffff;
  param_1[0x10] = 0;
  memw();
  FUN_400f7b9c(param_1 + 0x11);
  param_1[0x14] = 0;
  memw();
  return;
}



// Function at 0x400de390

undefined4 FUN_400de390(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_400d080c)(0xffffffff,param_1 + 4,0x18);
  return uVar1;
}



// Function at 0x400de3a4

int FUN_400de3a4(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined4 uStack_28;
  int iStack_24;
  
  piVar1 = DAT_400d0098;
  iVar2 = -1;
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  if (*(int *)(param_1 + 0xc) == -1) {
    *(undefined4 *)(param_1 + 0xc) = 0xfffffffe;
    uStack_3b = 0xff;
    memw();
    local_44 = 0xfffffffe;
    uStack_40 = *(undefined4 *)(param_1 + 0x10);
    uStack_3c = *(undefined1 *)(param_1 + 0x14);
    memw();
    memw();
    uStack_28 = FUN_400de390(&local_44);
    memw();
    iVar2 = (**(code **)(**(int **)(param_1 + 0x50) + 0x14))
                      (*(int **)(param_1 + 0x50),*(undefined4 *)(param_1 + 8),&local_44,0x20);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x38) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
      memw();
    }
    else {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
  }
  memw();
  memw();
  if (iStack_24 != *piVar1) {
    memw();
    iVar2 = func_0x400831d4();
    return iVar2;
  }
  return iVar2;
}



// Function at 0x400de434

int FUN_400de434(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = -1;
  if (*(uint *)(param_1 + 0x38) < 0x7e) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x18))
                      (*(int **)(param_1 + 0x50),
                       *(int *)(param_1 + 8) + 0x40 + *(uint *)(param_1 + 0x38) * 0x20,param_2,0x20)
    ;
    if (iVar1 == 0) {
      iVar1 = FUN_400f7c20(param_1,*(undefined4 *)(param_1 + 0x38),2);
      if (iVar1 == 0) {
        if (*(int *)(param_1 + 0x3c) == -1) {
          *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x38);
        }
        *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + 1;
        memw();
        *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
        memw();
      }
    }
    else {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
  }
  memw();
  return iVar1;
}



// Function at 0x400de498

undefined4 FUN_400de498(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = DAT_400d0964;
  if ((*(int *)(param_1 + 0xc) - 1U < 0xfffffffe) && (*(int *)(param_1 + 0xc) != -0x10)) {
    *param_2 = *(undefined4 *)(param_1 + 0x10);
    uVar1 = 0;
  }
  memw();
  return uVar1;
}



// Function at 0x400de4bc

undefined4 FUN_400de4bc(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = DAT_400d0968;
  if (*(int *)(param_1 + 0xc) == -1) {
    uVar1 = 0;
    *(undefined4 *)(param_1 + 0x10) = param_2;
  }
  memw();
  return uVar1;
}



// Function at 0x400de4d4

int FUN_400de4d4(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x1c))
                    (*(int **)(param_1 + 0x50),*(undefined4 *)(param_1 + 8),DAT_400d01d0);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x38) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;
    *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
    memw();
    FUN_400de280(param_1 + 0x44);
  }
  else {
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  memw();
  return iVar1;
}



// Function at 0x400de510

int FUN_400de510(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int aiStack_24 [9];
  
  iVar3 = *(int *)(param_1 + 0x3c);
  iVar4 = -1;
  if (iVar3 == param_2) {
    uVar1 = *(uint *)(param_1 + 0x38);
    *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;
    for (uVar2 = iVar3 + param_3; uVar2 < (uVar1 < 0x7e) * uVar1 + (uint)(uVar1 >= 0x7e) * 0x7e;
        uVar2 = uVar2 + 1) {
      memw();
      iVar4 = FUN_400f7d2c(param_1 + 0x18,uVar2,aiStack_24);
      if (iVar4 != 0) goto LAB_400de541;
      if (aiStack_24[0] == 2) {
        *(uint *)(param_1 + 0x3c) = uVar2;
        goto LAB_400de541;
      }
    }
    iVar4 = 0;
  }
LAB_400de541:
  memw();
  return iVar4;
}



// Function at 0x400de554

int FUN_400de554(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_4c [4];
  int iStack_48;
  undefined1 auStack_44 [2];
  byte bStack_42;
  int iStack_40;
  int iStack_24;
  
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  memw();
  FUN_400de498(param_1,auStack_4c);
  iVar1 = FUN_400f7d2c(param_1 + 0x18,param_2,&iStack_48);
  iVar2 = iVar1;
  if (iVar1 != 0) goto LAB_400de5e2;
  if (iStack_48 == 2) {
    iVar2 = FUN_400f7d04(param_1,param_2,auStack_44);
    if (iVar2 != 0) goto LAB_400de5e2;
    iVar2 = FUN_400df234(auStack_44);
    if (iStack_40 != iVar2) {
      FUN_400de2ac(param_1 + 0x44,param_2);
      iVar2 = FUN_400f7c20(param_1,param_2,0);
      *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + -1;
      memw();
      *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + 1;
      memw();
      goto LAB_400de5cb;
    }
    FUN_400de2ac(param_1 + 0x44,param_2);
    uVar3 = (uint)bStack_42;
    iVar4 = param_2 + uVar3;
    while (iVar4 = iVar4 + -1, param_2 <= iVar4) {
      memw();
      iVar2 = FUN_400f7d2c(param_1 + 0x18,iVar4,&iStack_48);
      if (iVar2 != 0) goto LAB_400de5e2;
      if (iStack_48 == 2) {
        *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + -1;
        memw();
      }
      *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + 1;
      memw();
      memw();
    }
    if (uVar3 == 1) {
      iVar2 = FUN_400f7c20(param_1,param_2,0);
    }
    else {
      iVar2 = FUN_400f7c80(param_1,param_2,param_2 + uVar3,0);
    }
    if (iVar2 != 0) goto LAB_400de5e2;
  }
  else {
    iVar2 = FUN_400f7c20(param_1,param_2,0);
LAB_400de5cb:
    if (iVar2 != 0) goto LAB_400de5e2;
    uVar3 = 1;
  }
  if (((*(int *)(param_1 + 0x3c) != param_2) ||
      (iVar2 = FUN_400de510(param_1,param_2,uVar3), iVar2 == 0)) &&
     (iVar2 = iVar1, *(uint *)(param_1 + 0x38) < uVar3 + param_2)) {
    *(uint *)(param_1 + 0x38) = uVar3 + param_2;
    memw();
  }
LAB_400de5e2:
  memw();
  memw();
  if (iStack_24 != *DAT_400d0098) {
    memw();
    iVar2 = func_0x400831d4();
    return iVar2;
  }
  return iVar2;
}



// Function at 0x400de698

int FUN_400de698(int param_1,byte param_2,byte param_3,int param_4,uint *param_5,byte *param_6,
                byte param_7,byte param_8)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uStack_60;
  int iStack_48;
  undefined1 auStack_44 [32];
  int iStack_24;
  
  memw();
  iStack_24 = *DAT_400d0098;
  iVar7 = *(int *)(param_1 + 0xc);
  memw();
  bVar2 = iVar7 == -0x10;
  bVar3 = iVar7 == 0;
  if (((bVar2 || bVar3) ||
      (bVar5 = iVar7 == -1 || (bVar2 || bVar3), iVar7 == -1 || (bVar2 || bVar3))) ||
     (uVar6 = *param_5, 0x7d < uVar6)) {
LAB_400de6e8:
    memw();
    iVar7 = DAT_400d0970;
  }
  else {
    uVar8 = *(uint *)(param_1 + 0x3c);
    uStack_60 = (uVar6 < uVar8) * uVar8 + (uVar6 >= uVar8) * uVar6;
    uVar6 = *(uint *)(param_1 + 0x38);
    if ((bVar5 || param_3 != 0xff && param_4 != 0) && (param_2 != 0xff || bVar5)) {
      memw();
      FUN_400de310(auStack_44,param_2,param_3,0,param_4,param_7);
      uStack_60 = FUN_400de23c(param_1 + 0x44,uStack_60,auStack_44);
      if (0x7d < uStack_60) goto LAB_400de6e8;
    }
LAB_400de748:
    do {
      do {
        uVar8 = uStack_60;
        if ((uVar6 < 0x7e) * uVar6 + (uint)(uVar6 >= 0x7e) * 0x7e <= uVar8) goto LAB_400de6e8;
        uStack_60 = uVar8 + 1;
        memw();
        iVar7 = FUN_400f7d2c(param_1 + 0x18,uVar8,&iStack_48);
        if (iVar7 != 0) goto LAB_400de77b;
      } while (iStack_48 != 2);
      iVar4 = FUN_400f7d04(param_1,uVar8,param_6);
      if (iVar4 != 0) break;
      iVar7 = FUN_400df234(param_6);
      if (iVar7 == *(int *)(param_6 + 4)) {
        bVar1 = param_6[1];
        memw();
        iVar7 = FUN_400f7bf8(bVar1);
        if (iVar7 != 0) {
          uStack_60 = param_6[2] + uVar8;
        }
        if ((param_2 == 0xff) || (*param_6 == param_2)) {
          if (param_4 != 0) {
            memw();
            iVar7 = func_0x40086cd0(param_4,param_6 + 8,0xf);
            if (iVar7 != 0) goto LAB_400de748;
          }
          iVar7 = DAT_400d096c;
          if ((param_7 == 0xff) || (param_3 != 0x42)) {
            if (param_3 == 0x48) {
              if ((param_6[3] != 0xff) || ((param_8 != 0xff && (param_6[0x1d] != param_8))))
              goto LAB_400de748;
            }
            else if (param_3 == 0xff) goto LAB_400de850;
            if (param_3 == bVar1) goto LAB_400de850;
            if (((param_2 & param_7) == 0xff) && (param_4 == 0)) goto LAB_400de748;
          }
          else {
            if (param_6[3] != param_7) goto LAB_400de748;
            if (bVar1 == 0x42) {
LAB_400de850:
              *param_5 = uVar8;
              memw();
              iVar7 = iVar4;
              goto LAB_400de77b;
            }
          }
          *param_5 = uVar8;
          memw();
          goto LAB_400de77b;
        }
        goto LAB_400de748;
      }
      iVar4 = FUN_400de554(param_1,uVar8);
    } while (iVar4 == 0);
    *(undefined4 *)(param_1 + 0xc) = 0;
    iVar7 = iVar4;
  }
LAB_400de77b:
  memw();
  memw();
  if (iStack_24 == *DAT_400d0098) {
    return iVar7;
  }
  memw();
  iVar7 = func_0x400831d4();
  return iVar7;
}



// Function at 0x400de85c

int FUN_400de85c(undefined4 param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6)

{
  int *piVar1;
  int iVar2;
  undefined4 uStack_48;
  undefined1 auStack_44 [32];
  int iStack_24;
  
  piVar1 = DAT_400d0098;
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  uStack_48 = 0;
  memw();
  iVar2 = FUN_400de698(param_1,param_2,param_3,param_4,&uStack_48,auStack_44,param_5,param_6);
  if (iVar2 == 0) {
    iVar2 = FUN_400de554(param_1,uStack_48);
  }
  memw();
  memw();
  if (iStack_24 != *piVar1) {
    iVar2 = func_0x400831d4();
    return iVar2;
  }
  return iVar2;
}



// Function at 0x400de8b4

int FUN_400de8b4(int param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uStack_70;
  int iStack_6c;
  uint uStack_68;
  undefined1 uStack_64;
  undefined1 uStack_63;
  byte bStack_62;
  int iStack_60;
  undefined1 auStack_5c [24];
  undefined1 uStack_44;
  undefined1 uStack_43;
  byte bStack_42;
  int iStack_40;
  int iStack_24;
  
  memw();
  iStack_24 = *DAT_400d0098;
  iVar7 = param_1 + 0x18;
  memw();
  bVar1 = (*(uint *)(param_1 + 0xc) & 0xfffffffb) == 0xfffffff8;
  if ((bVar1) || (*(uint *)(param_1 + 0xc) == 0xfffffffe || bVar1)) {
    memw();
    iVar2 = (**(code **)(**(int **)(param_1 + 0x50) + 0xc))
                      (*(int **)(param_1 + 0x50),*(int *)(param_1 + 8) + 0x20,iVar7);
    if (iVar2 != 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
      goto LAB_400de909;
    }
  }
  iVar5 = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  do {
    memw();
    iVar2 = FUN_400f7d2c(iVar7,iVar5,&uStack_70);
    if (iVar2 != 0) goto LAB_400de909;
    if (uStack_70 == 2) {
      if (*(int *)(param_1 + 0x3c) == -1) {
        *(int *)(param_1 + 0x3c) = iVar5;
      }
      *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + 1;
      memw();
    }
    else if (uStack_70 == 0) {
      *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + 1;
      memw();
      memw();
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 != 0x7e);
  if (*(uint *)(param_1 + 0xc) == 0xfffffffe) {
    iVar5 = 0;
    do {
      memw();
      iVar2 = FUN_400f7d2c(iVar7,iVar5,&uStack_70);
      iVar4 = iVar2;
      if (iVar2 != 0) goto LAB_400deb45;
      if (uStack_70 == 3) {
        *(int *)(param_1 + 0x38) = iVar5;
        break;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 != 0x7e);
    do {
      if (0x7d < *(uint *)(param_1 + 0x38)) goto LAB_400dea22;
      memw();
      iVar4 = (**(code **)(**(int **)(param_1 + 0x50) + 0xc))
                        (*(int **)(param_1 + 0x50),
                         *(int *)(param_1 + 8) + 0x40 + *(uint *)(param_1 + 0x38) * 0x20,&iStack_6c,
                         4);
      if (iVar4 != 0) goto LAB_400de9ac;
      if (iStack_6c == -1) goto LAB_400dea22;
      uStack_68 = uStack_70;
      memw();
      iVar4 = FUN_400f7d2c(iVar7,*(undefined4 *)(param_1 + 0x38),&uStack_68);
      if (iVar4 != 0) goto LAB_400deb45;
      iVar4 = FUN_400f7c20(param_1,*(undefined4 *)(param_1 + 0x38),0);
      if (iVar4 != 0) goto LAB_400de9ac;
      *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
      if (uStack_68 == 2) {
        *(short *)(param_1 + 0x40) = *(short *)(param_1 + 0x40) + -1;
        memw();
      }
      *(short *)(param_1 + 0x42) = *(short *)(param_1 + 0x42) + 1;
      memw();
      memw();
    } while( true );
  }
  if ((*(uint *)(param_1 + 0xc) & 0xfffffffb) == 0xfffffff8) {
    for (uVar6 = *(uint *)(param_1 + 0x3c); uVar6 < 0x7e; uVar6 = uVar6 + 1) {
      iVar4 = FUN_400f7d2c(iVar7,uVar6,&uStack_70);
      if (iVar4 != 0) goto LAB_400deb45;
      if (uStack_70 == 2) {
        iVar4 = FUN_400f7d04(param_1,uVar6,&uStack_44);
        iVar5 = iStack_40;
        if (iVar4 != 0) goto LAB_400de9ac;
        iVar4 = FUN_400df234(&uStack_44);
        if (iVar5 == iVar4) {
          if (bStack_42 == 0) {
            iVar4 = -1;
            goto LAB_400deb45;
          }
          iVar4 = FUN_400de1b4(param_1 + 0x44,&uStack_44,uVar6);
          if (iVar4 != 0) goto LAB_400de9ac;
          uVar9 = (uint)bStack_42;
          iVar5 = FUN_400f7bf8(uStack_43);
          if (iVar5 != 0) {
            uVar11 = uVar6;
            do {
              uVar11 = uVar11 + 1;
              if (uVar6 + uVar9 <= uVar11) goto LAB_400debec;
              memw();
              iVar4 = FUN_400f7d2c(iVar7,uVar11,&uStack_70);
              if (iVar4 != 0) goto LAB_400deb45;
            } while (uStack_70 == 2);
            FUN_400de554(param_1,uVar6);
          }
LAB_400debec:
          uVar6 = uVar6 + (uVar9 - 1);
        }
        else {
          iVar4 = FUN_400de554(param_1,uVar6);
          if (iVar4 != 0) goto LAB_400de9ac;
        }
      }
    }
  }
  goto LAB_400de909;
LAB_400de9ac:
  *(undefined4 *)(param_1 + 0xc) = 0;
  memw();
  goto LAB_400deb45;
LAB_400dea22:
  uVar11 = *(uint *)(param_1 + 0x38);
  uVar6 = 0xffffffff;
  for (uVar9 = 0; uVar9 < (uVar11 < 0x7e) * uVar11 + (uint)(uVar11 >= 0x7e) * 0x7e;
      uVar9 = uVar9 + uVar8) {
    memw();
    iVar4 = FUN_400f7d2c(iVar7,uVar9,&uStack_70);
    if (iVar4 != 0) goto LAB_400deb45;
    if (uStack_70 == 0) {
LAB_400dea4f:
      uVar8 = 1;
LAB_400dea51:
      uVar6 = 0xffffffff;
    }
    else {
      if (uStack_70 == 1) {
        iVar4 = FUN_400de554(param_1,uVar9);
        if (iVar4 == 0) goto LAB_400dea4f;
        goto LAB_400de9ac;
      }
      iVar4 = FUN_400f7d04(param_1,uVar9,&uStack_64);
      iVar5 = iStack_60;
      if (iVar4 != 0) goto LAB_400de9ac;
      iVar4 = FUN_400df234(&uStack_64);
      uVar6 = uVar9;
      if (iVar5 == iVar4) {
        iVar4 = FUN_400de1b4(param_1 + 0x44,&uStack_64,uVar9);
        if (iVar4 != 0) goto LAB_400de9ac;
        uVar3 = FUN_400de23c(param_1 + 0x44,0,&uStack_64);
        iVar5 = FUN_400f7bf8(uStack_63);
        uVar8 = 1;
        if (iVar5 != 0) {
          uVar8 = (uint)bStack_62;
          for (uVar10 = uVar9; uVar10 < uVar9 + uVar8; uVar10 = uVar10 + 1) {
            memw();
            iVar4 = FUN_400f7d2c(iVar7,uVar10,&uStack_70);
            if (iVar4 != 0) goto LAB_400deb45;
            if (uStack_70 != 2) {
              FUN_400de554(param_1,uVar9);
              goto LAB_400dea51;
            }
          }
        }
        if (uVar3 < uVar9) {
          FUN_400de554(param_1,uVar3);
        }
      }
      else {
        iVar4 = FUN_400de554(param_1,uVar9);
        if (iVar4 != 0) goto LAB_400de9ac;
        uVar8 = 1;
      }
    }
  }
  if (uVar6 == 0xffffffff) goto LAB_400de909;
  uStack_68 = 0;
  memw();
  iVar7 = FUN_400de698(param_1,uStack_64,uStack_63,auStack_5c,&uStack_68,&uStack_44,0xff,0xff);
  if (((iVar7 != 0) || (uVar6 <= uStack_68)) || (iVar4 = FUN_400de554(param_1), iVar4 == 0))
  goto LAB_400de909;
  *(undefined4 *)(param_1 + 0xc) = 0;
LAB_400deb45:
  iVar2 = iVar4;
  memw();
LAB_400de909:
  memw();
  memw();
  if (iStack_24 != *DAT_400d0098) {
    memw();
    iVar7 = func_0x400831d4();
    return iVar7;
  }
  return iVar2;
}



// Function at 0x400dec0c

int FUN_400dec0c(int param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int *piVar8;
  int local_44;
  undefined4 uStack_40;
  byte bStack_3c;
  undefined1 uStack_3b;
  int iStack_28;
  int iStack_24;
  
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  iVar4 = 0x102;
  if (param_2 == (int *)0x0) goto LAB_400deca0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(int **)(param_1 + 0x50) = param_2;
  *(int *)(param_1 + 8) = param_3 << 0xc;
  uStack_3b = 0xff;
  memw();
  memw();
  iVar2 = (**(code **)(*param_2 + 0xc))(param_2,param_3 << 0xc,&local_44,0x20);
  uVar1 = DAT_400d0978;
  uVar6 = 0;
  if (iVar2 == 0) {
    if (local_44 == -1) {
      *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
      memw();
      piVar3 = (int *)FUN_400e79b4(0x200,uVar1);
      if (piVar3 == (int *)0x0) {
        iVar4 = 0x101;
        goto LAB_400deca0;
      }
      iVar5 = 0;
      do {
        iVar4 = (**(code **)(**(int **)(param_1 + 0x50) + 0xc))
                          (*(int **)(param_1 + 0x50),iVar5 + *(int *)(param_1 + 8),piVar3,0x200);
        piVar8 = piVar3;
        if (iVar4 != 0) {
          *(undefined4 *)(param_1 + 0xc) = 0;
          memw();
          FUN_400e79c8(piVar3);
          goto LAB_400deca0;
        }
        do {
          if (*piVar8 != -1) {
LAB_400decc7:
            if (piVar3 + 0x80 != piVar8) {
              *(undefined4 *)(param_1 + 0xc) = 0xfffffff0;
              goto LAB_400decce;
            }
            break;
          }
          if (piVar8[1] != -1) {
            piVar8 = piVar8 + 1;
            goto LAB_400decc7;
          }
          if (piVar8[2] != -1) {
            piVar8 = piVar8 + 2;
            goto LAB_400decc7;
          }
          if (piVar8[3] != -1) {
            piVar8 = piVar8 + 3;
            goto LAB_400decc7;
          }
          piVar8 = piVar8 + 4;
        } while (piVar3 + 0x80 != piVar8);
        iVar5 = iVar5 + 0x200;
      } while (iVar5 != DAT_400d01d0);
LAB_400decce:
      memw();
      FUN_400e79c8(piVar3);
    }
    else {
      iVar4 = FUN_400de390(&local_44);
      if (iStack_28 == iVar4) {
        *(int *)(param_1 + 0xc) = local_44;
        *(undefined4 *)(param_1 + 0x10) = uStack_40;
        iVar4 = DAT_400d0974;
        if (bStack_3c < 0xfe) goto LAB_400deca0;
        *(byte *)(param_1 + 0x14) = bStack_3c;
        memw();
        memw();
      }
      else {
        local_44 = -0x10;
        memw();
      }
    }
    uVar7 = *(uint *)(param_1 + 0xc);
    if (uVar7 != 0xfffffffc) {
      if (uVar7 < 0xfffffffd) {
        if (uVar7 != 0xfffffff8) {
LAB_400ded60:
          uVar6 = 0xfffffff0;
          goto LAB_400ded62;
        }
      }
      else if (uVar7 != 0xfffffffe) {
        iVar4 = iVar2;
        if (uVar7 == 0xffffffff) goto LAB_400deca0;
        goto LAB_400ded60;
      }
    }
    iVar4 = FUN_400de8b4(param_1);
  }
  else {
LAB_400ded62:
    *(undefined4 *)(param_1 + 0xc) = uVar6;
    memw();
    iVar4 = iVar2;
  }
LAB_400deca0:
  memw();
  memw();
  if (iStack_24 != *DAT_400d0098) {
    iVar4 = func_0x400831d4();
    return iVar4;
  }
  return iVar4;
}



// Function at 0x400ded7c

int FUN_400ded7c(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iStack_48;
  undefined1 auStack_44 [2];
  byte bStack_42;
  int iStack_24;
  
  piVar1 = DAT_400d0098;
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  iVar4 = DAT_400d0970;
  if ((*(int *)(param_1 + 0x3c) != -1) &&
     ((*(int *)(param_2 + 0xc) != -1 || (iVar4 = FUN_400de3a4(param_2), iVar4 == 0)))) {
    uVar3 = *(uint *)(param_1 + 0x3c);
    while (uVar2 = uVar3, uVar2 < 0x7e) {
      memw();
      iVar4 = FUN_400f7d2c(param_1 + 0x18,uVar2,&iStack_48);
      if (iVar4 != 0) goto LAB_400dedcd;
      if (iStack_48 == 2) {
        iVar4 = FUN_400f7d04(param_1,uVar2,auStack_44);
        if (((iVar4 != 0) ||
            (iVar4 = FUN_400de1b4(param_2 + 0x44,auStack_44,*(undefined4 *)(param_2 + 0x38)),
            iVar4 != 0)) || (iVar4 = FUN_400de434(param_2,auStack_44), iVar4 != 0))
        goto LAB_400dedcd;
        uVar3 = bStack_42 + uVar2;
        if (0x7e < uVar3) goto LAB_400dedc0;
        while (uVar2 = uVar2 + 1, uVar2 < uVar3) {
          FUN_400f7d04(param_1,uVar2,auStack_44);
          iVar4 = FUN_400de434(param_2,auStack_44);
          if (iVar4 != 0) goto LAB_400dedcd;
        }
      }
      else {
        if (*(uint *)(param_1 + 0x3c) == uVar2) {
LAB_400dedc0:
          iVar4 = -1;
          goto LAB_400dedcd;
        }
        uVar3 = uVar2 + 1;
      }
    }
    iVar4 = 0;
  }
LAB_400dedcd:
  memw();
  memw();
  if (iStack_24 == *piVar1) {
    return iVar4;
  }
  iVar4 = func_0x400831d4();
  return iVar4;
}



// Function at 0x400dee40

void FUN_400dee40(int *param_1)

{
  while (*param_1 != 0) {
    FUN_400f7d84(param_1);
  }
  return;
}



// Function at 0x400dee54

int FUN_400dee54(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_400d097c;
  if ((*(int *)(param_1 + 0x14) != 0) &&
     ((iVar1 = *(int *)(param_1 + 0xc), *(int *)(iVar1 + 0xc) != -0x10 ||
      (iVar2 = FUN_400de4d4(iVar1), iVar2 == 0)))) {
    FUN_400f7d84(param_1 + 0xc,*(undefined4 *)(param_1 + 0xc));
    FUN_400f7d60(param_1,iVar1);
    FUN_400de4bc(iVar1,*(undefined4 *)(param_1 + 0x24));
    iVar2 = 0;
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
  }
  memw();
  return iVar2;
}



// Function at 0x400dee98

uint FUN_400dee98(int *param_1,int param_2,int param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  int iStack_58;
  uint uStack_4c;
  uint uStack_48;
  undefined1 uStack_44;
  char cStack_43;
  byte bStack_42;
  undefined1 uStack_41;
  undefined1 auStack_3c [24];
  int iStack_24;
  
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  if (param_2 == 0) {
    uVar2 = 0x102;
  }
  else {
    piVar4 = param_1 + 3;
    param_1[7] = param_3;
    param_1[8] = param_4;
    memw();
    FUN_400dee40(param_1);
    memw();
    FUN_400dee40(piVar4);
    iVar13 = -1;
    if (param_4 <= DAT_400d0984) {
      iVar13 = param_4 * 0x54 + 4;
    }
    puVar1 = (uint *)FUN_400e79b4(iVar13,DAT_400d0978);
    puVar7 = puVar1;
    if (puVar1 != (uint *)0x0) {
      puVar7 = puVar1 + 1;
      iStack_58 = param_4 - 1;
      *puVar1 = param_4;
      puVar1 = puVar7;
      while (-1 < iStack_58) {
        memw();
        FUN_400de35c(puVar1);
        puVar1 = puVar1 + 0x15;
        iStack_58 = iStack_58 + -1;
        memw();
      }
    }
    iVar13 = param_1[6];
    param_1[6] = (int)puVar7;
    if (iVar13 != 0) {
      iVar8 = iVar13 + *(int *)(iVar13 + -4) * 0x54;
      iVar6 = iVar8;
      while (iVar13 != iVar6) {
        memw();
        FUN_400de2a0(iVar6 + -0x10);
        iVar6 = iVar6 + -0x54;
      }
      FUN_400e79c8(iVar8 + (((uint)(iVar8 - iVar13) >> 2) * DAT_400d0954 & DAT_400d0280) * -0x54 +
                           -4);
    }
    if (param_1[6] == 0) {
      uVar2 = 0x101;
    }
    else {
      iVar6 = param_3 + param_4;
      iVar13 = 0;
      while (param_3 != iVar6) {
        uVar2 = FUN_400dec0c(param_1[6] + iVar13,param_2,param_3);
        if (uVar2 != 0) goto LAB_400df025;
        iVar8 = FUN_400de498(param_1[6] + iVar13,&uStack_4c);
        uVar2 = uStack_4c;
        if (iVar8 == 0) {
          for (piVar10 = (int *)*param_1; piVar10 != (int *)0x0; piVar10 = (int *)piVar10[1]) {
            iVar8 = FUN_400de498(piVar10,&uStack_48);
            if ((iVar8 == 0) && (uVar2 < uStack_48)) {
              piVar9 = (int *)(param_1[6] + iVar13);
              iVar8 = param_1[2];
              iVar12 = *piVar10;
              if (iVar12 == 0) {
                puVar11 = (undefined4 *)*param_1;
                *piVar9 = 0;
                piVar9[1] = (int)puVar11;
                if (puVar11 != (undefined4 *)0x0) {
                  *puVar11 = piVar9;
                }
                *param_1 = (int)piVar9;
                if (param_1[1] == 0) {
                  param_1[1] = (int)piVar9;
                }
              }
              else {
                *(int **)(iVar12 + 4) = piVar9;
                *piVar10 = (int)piVar9;
                piVar9[1] = (int)piVar10;
                *piVar9 = iVar12;
                memw();
              }
              param_1[2] = iVar8 + 1;
              goto LAB_400deff6;
            }
          }
          iVar8 = param_1[6];
          piVar10 = param_1;
        }
        else {
          iVar8 = param_1[6];
          piVar10 = piVar4;
        }
        FUN_400f7d60(piVar10,iVar8 + iVar13);
LAB_400deff6:
        iVar13 = iVar13 + 0x54;
        param_3 = param_3 + 1;
        memw();
      }
      if (param_1[2] == 0) {
        param_1[9] = 0;
        memw();
        uVar2 = FUN_400dee54(param_1);
      }
      else {
        uVar3 = FUN_400de498(param_1[1],&uStack_48);
        uVar2 = uVar3;
        if (uVar3 != 0) {
          uVar2 = func_0x40088988(uVar3,DAT_400d0990,0x32,DAT_400d098c,DAT_400d0988);
        }
        iVar13 = param_1[1];
        param_1[9] = uStack_48 + 1;
        uVar5 = 0xffffffff;
        uStack_48 = uVar2;
        while( true ) {
          memw();
          iVar6 = FUN_400de698(iVar13,0xff,0xff,0,&uStack_48,&uStack_44,0xff,0xff);
          if (iVar6 != 0) break;
          uVar5 = bStack_42 + uStack_48;
          memw();
          uStack_48 = uVar5;
        }
        if (uVar5 != 0xffffffff) {
          for (iVar6 = *param_1; iVar13 != iVar6; iVar6 = *(int *)(iVar6 + 4)) {
            if ((*(int *)(iVar6 + 0xc) != -8) &&
               (iVar8 = FUN_400de85c(iVar6,uStack_44,cStack_43,auStack_3c,uStack_41,0xff),
               iVar8 == 0)) goto LAB_400df0cd;
          }
          if (cStack_43 == 'H') {
            iVar13 = *param_1;
            while ((iVar13 != iVar6 &&
                   ((*(int *)(iVar13 + 0xc) == -8 ||
                    (iVar8 = FUN_400de85c(iVar13,uStack_44,0x41,auStack_3c,uStack_41,0xff),
                    iVar8 != 0))))) {
              iVar13 = *(int *)(iVar13 + 4);
            }
          }
        }
LAB_400df0cd:
        for (iVar13 = *param_1; iVar13 != 0; iVar13 = *(int *)(iVar13 + 4)) {
          if (*(int *)(iVar13 + 0xc) == -8) {
            iVar6 = param_1[1];
            if (*(int *)(iVar6 + 0xc) == -2) {
              uVar2 = FUN_400de4d4(iVar6);
              if (uVar2 != 0) goto LAB_400df025;
              FUN_400f7d84(param_1,iVar6);
              FUN_400f7d60(piVar4,iVar6);
            }
            uVar2 = FUN_400dee54(param_1);
            if ((uVar2 != 0) ||
               (((uVar2 = FUN_400ded7c(iVar13,param_1[1]), uVar2 != 0 && (uVar2 + DAT_400d0994 != 0)
                 ) || (uVar2 = FUN_400de4d4(iVar13), uVar2 != 0)))) goto LAB_400df025;
            FUN_400f7d84(param_1,iVar13);
            FUN_400f7d60(piVar4,iVar13);
            break;
          }
        }
        uVar2 = uVar3;
        if (param_1[5] == 0) {
          uVar2 = DAT_400d0980;
        }
      }
    }
  }
LAB_400df025:
  memw();
  memw();
  if (iStack_24 == *DAT_400d0098) {
    return uVar2;
  }
  uVar2 = func_0x400831d4();
  return uVar2;
}



// Function at 0x400df1fc

undefined4 FUN_400df1fc(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_400dd700(1,2,param_1);
  uVar3 = 0x105;
  if (iVar1 != 0) {
    uVar3 = DAT_400d0998;
    if (*(char *)(iVar1 + 0x25) == '\0') {
      iVar2 = func_0x4008dbdc(0x10);
      uVar3 = 0x101;
      if (iVar2 != 0) {
        FUN_400ddffc(iVar2,iVar1);
        *param_2 = iVar2;
        uVar3 = 0;
      }
    }
  }
  memw();
  return uVar3;
}



// Function at 0x400df234

undefined4 FUN_400df234(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_400d080c)(0xffffffff,param_1,4);
  uVar1 = (*DAT_400d080c)(uVar1,param_1 + 8,0x10);
  uVar1 = (*DAT_400d080c)(uVar1,param_1 + 0x18,8);
  return uVar1;
}



// Function at 0x400df260

undefined4 FUN_400df260(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*DAT_400d080c)(0xffffffff,param_1,1);
  uVar1 = (*DAT_400d080c)(uVar1,param_1 + 8,0x10);
  uVar1 = (*DAT_400d080c)(uVar1,param_1 + 3,1);
  return uVar1;
}



// Function at 0x400df288

void FUN_400df288(undefined4 param_1)

{
  func_0x4008dbfc(param_1);
  return;
}



// Function at 0x400df294

undefined4 FUN_400df294(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = DAT_400d09a0;
  iVar2 = FUN_400df424(DAT_400d09a0,PTR_FUN_400d099c);
  if (iVar2 == 0) {
    iVar2 = func_0x400893a4(1);
    *DAT_400d09a4 = iVar2;
    if (iVar2 != 0) {
      return 0;
    }
    memw();
    FUN_400df464(*puVar1);
  }
  return 0x101;
}



// Function at 0x400df2c4

undefined4 FUN_400df2c4(void)

{
  undefined4 uVar1;
  
  uVar1 = func_0x4008d9f8();
  FUN_400e4a50(1,DAT_400d09ac,DAT_400d09b0,uVar1,DAT_400d09ac,DAT_400d09a8);
  return 0x58;
}



// Function at 0x400df2e4

undefined4 FUN_400df2e4(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0x16;
  if ((param_1 != (int *)0x0) &&
     ((param_2 == (int *)0x0 ||
      ((*param_2 != 0 && (param_2 = (int *)param_2[1], param_2 < (int *)0x3)))))) {
    piVar1 = (int *)func_0x4008dbdc(8);
    uVar3 = 0xc;
    if (piVar1 != (int *)0x0) {
      piVar1[1] = (int)param_2;
      uVar3 = 4;
      if (param_2 != (int *)0x1) {
        uVar3 = 1;
      }
      memw();
      iVar2 = func_0x400893a4(uVar3);
      *piVar1 = iVar2;
      if (*piVar1 == 0) {
        memw();
        func_0x4008dbfc(piVar1);
        uVar3 = 0xb;
      }
      else {
        *param_1 = (int)piVar1;
        uVar3 = 0;
        memw();
      }
    }
  }
  return uVar3;
}



// Function at 0x400df35c

undefined4 FUN_400df35c(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (param_1 == (int *)0x0) {
LAB_400df3b2:
    uVar3 = 0x16;
  }
  else {
    puVar2 = (undefined4 *)*param_1;
    if (puVar2 != (undefined4 *)0xffffffff) {
      if (puVar2 == (undefined4 *)0x0) goto LAB_400df3b2;
      iVar1 = func_0x400830b0(puVar2,0);
      if (iVar1 == 0x10) {
        return 0x10;
      }
      uVar3 = *puVar2;
      if (puVar2[1] != 1) goto LAB_400df391;
      iVar1 = func_0x40089368(uVar3);
      while (iVar1 != 1) {
        uVar3 = func_0x4008dacc(DAT_400d09c0,0x254,DAT_400d09bc,DAT_400d09b8);
LAB_400df391:
        iVar1 = func_0x40089194(uVar3,0,0);
      }
      func_0x400899b0(*puVar2);
      func_0x4008dbfc(puVar2);
    }
    uVar3 = 0;
  }
  return uVar3;
}



// Function at 0x400df3b8

void FUN_400df3b8(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = DAT_400d09c4;
  func_0x4008b620(DAT_400d09c4,0xffffffff);
  for (piVar2 = (int *)*DAT_400d09c8; (piVar2 != (int *)0x0 && (*piVar2 != param_1));
      piVar2 = (int *)piVar2[2]) {
  }
  func_0x4008b770(uVar1);
  return;
}



// Function at 0x400df424

undefined4 FUN_400df424(int *param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  
  piVar3 = (int *)func_0x4008dbdc(0xc);
  uVar1 = DAT_400d09c4;
  uVar4 = 0xc;
  if (piVar3 != (int *)0x0) {
    func_0x4008b620(DAT_400d09c4,0xffffffff);
    piVar2 = DAT_400d09c8;
    iVar5 = 1;
    piVar6 = (int *)*DAT_400d09c8;
    if (piVar6 != (int *)0x0) {
      iVar5 = *piVar6 + 1;
    }
    *param_1 = iVar5;
    *piVar2 = (int)piVar3;
    *piVar3 = iVar5;
    piVar3[1] = param_2;
    piVar3[2] = (int)piVar6;
    memw();
    func_0x4008b770(uVar1);
    uVar4 = 0;
  }
  return uVar4;
}



// Function at 0x400df464

undefined4 FUN_400df464(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = DAT_400d09c4;
  func_0x4008b620(DAT_400d09c4,0xffffffff);
  iVar2 = FUN_400df3b8(param_1);
  if (iVar2 != 0) {
    iVar4 = *DAT_400d09c8;
    if (*DAT_400d09c8 == iVar2) {
      *DAT_400d09c8 = *(int *)(iVar2 + 8);
    }
    else {
      do {
        iVar3 = iVar4;
        iVar4 = *(int *)(iVar3 + 8);
      } while (iVar4 != iVar2);
      *(int *)(iVar3 + 8) = *(int *)(iVar2 + 8);
      memw();
    }
    memw();
    func_0x4008dbfc();
  }
  func_0x4008b770(uVar1);
  return 0;
}



// Function at 0x400df4a8

int * FUN_400df4a8(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)func_0x4008a87c(0);
  if (piVar1 != (int *)0x0) {
    for (piVar1 = (int *)*piVar1; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[2]) {
      if (param_1 == *piVar1) {
        return (int *)piVar1[1];
      }
    }
  }
  return piVar1;
}



// Function at 0x400df4cc

undefined4 FUN_400df4cc(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  
  iVar1 = FUN_400df3b8(param_1);
  if (iVar1 == 0) {
    return 2;
  }
  piVar2 = (int *)func_0x4008a87c(0);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)func_0x4008dc54(1,4);
    if (piVar2 != (int *)0x0) {
      func_0x4008a84c(0,0,piVar2,PTR_LAB_400d09d8);
      goto LAB_400df505;
    }
LAB_400df4f0:
    uVar6 = 0xc;
  }
  else {
LAB_400df505:
    piVar8 = (int *)*piVar2;
    for (piVar3 = piVar8; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[2]) {
      if (param_1 == *piVar3) {
        if (param_2 == 0) {
          if (piVar8 == piVar3) {
            *piVar2 = piVar3[2];
          }
          else {
            do {
              piVar2 = piVar8;
              piVar8 = (int *)piVar2[2];
            } while (piVar8 != piVar3);
            piVar2[2] = piVar3[2];
            memw();
          }
          memw();
          func_0x4008dbfc(piVar3);
        }
        else {
          piVar3[1] = param_2;
        }
        goto LAB_400df53a;
      }
    }
    if (param_2 != 0) {
      piVar3 = (int *)func_0x4008dbdc(0xc);
      if (piVar3 == (int *)0x0) goto LAB_400df4f0;
      piVar3[1] = param_2;
      iVar5 = *piVar2;
      *piVar3 = param_1;
      iVar1 = iVar5;
      iVar7 = 0;
      while (iVar4 = iVar1, iVar4 != 0) {
        iVar7 = iVar4;
        iVar1 = *(int *)(iVar4 + 8);
      }
      if (iVar7 == 0) {
        piVar3[2] = iVar5;
        *piVar2 = (int)piVar3;
        memw();
        return 0;
      }
      piVar3[2] = *(int *)(iVar7 + 8);
      *(int **)(iVar7 + 8) = piVar3;
      memw();
    }
LAB_400df53a:
    uVar6 = 0;
    memw();
  }
  return uVar6;
}



// Function at 0x400df58c

int * FUN_400df58c(int param_1,undefined1 *param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  *param_2 = 1;
  memw();
  piVar1 = *(int **)*DAT_400d09dc;
  piVar2 = (int *)0x0;
  while (piVar1 != (int *)0x0) {
    piVar3 = piVar1;
    if ((*piVar1 != param_1) && (piVar3 = piVar2, (char)piVar1[1] == '\0')) {
      *param_2 = 0;
      memw();
    }
    piVar1 = (int *)piVar1[2];
    memw();
    piVar2 = piVar3;
  }
  memw();
  return piVar2;
}



// Function at 0x400df5c8

void FUN_400df5c8(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = DAT_400d09e0;
  func_0x4008ca8c(DAT_400d09e0);
  func_0x4008cb88(uVar1);
  func_0x4008cc00(uVar1);
  iVar2 = *(int *)*DAT_400d09dc;
  while (iVar2 != 0) {
    *(undefined1 *)(iVar2 + 4) = 0;
    memw();
    iVar2 = *(int *)(iVar2 + 8);
    memw();
  }
  return;
}



// Function at 0x400df76c

undefined4 FUN_400df76c(undefined4 param_1,undefined1 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  
  uVar2 = DAT_400d09f0;
  func_0x4008b620(DAT_400d09f0,0xffffffff);
  piVar1 = DAT_400d09dc;
  iVar6 = *DAT_400d09dc;
  if (iVar6 == 0) {
    puVar4 = (undefined4 *)func_0x4008dc54(1,0x10);
    *piVar1 = (int)puVar4;
    puVar3 = PTR_LAB_400d0a18;
    if (puVar4 == (undefined4 *)0x0) {
      memw();
      func_0x4008b770(uVar2);
      return 0x101;
    }
    *puVar4 = 0;
    puVar4[1] = param_1;
    *(undefined1 *)(puVar4 + 2) = param_2;
    memw();
    memw();
    iVar6 = FUN_400e383c(0x10,0,puVar3,0,puVar4 + 3);
    if (iVar6 != 0) {
      func_0x40088988(iVar6,DAT_400d0a24,0xd6,DAT_400d0a20,DAT_400d0a1c);
    }
    FUN_400da230(8);
    uVar5 = DAT_400d09e0;
    func_0x4008c6e4(DAT_400d09e0,1,DAT_400d0a28);
    func_0x4008ca8c(uVar5);
    iVar6 = *(int *)(*piVar1 + 4);
  }
  else {
    *(undefined4 *)(iVar6 + 4) = param_1;
    uVar5 = DAT_400d09e0;
    *(undefined1 *)(iVar6 + 8) = param_2;
    memw();
    memw();
    func_0x4008ca8c(uVar5);
    func_0x4008cb00(uVar5);
    iVar6 = *(int *)(*piVar1 + 4);
  }
  func_0x4008c934(uVar5,0,iVar6 * 2000,1);
  func_0x4008c934(uVar5,1,*(int *)(*piVar1 + 4) * 4000,3);
  func_0x4008cab0(uVar5);
  func_0x4008cc00(uVar5);
  func_0x4008b770(uVar2);
  return 0;
}



// Function at 0x400df860

undefined4 FUN_400df860(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  char acStack_21 [33];
  
  uVar1 = DAT_400d09f0;
  func_0x4008b620(DAT_400d09f0,0xffffffff);
  piVar5 = DAT_400d09dc;
  if (*DAT_400d09dc == 0) {
    func_0x4008b770(uVar1);
    return 0x103;
  }
  if (param_1 == 0) {
    param_1 = func_0x4008a674();
  }
  iVar2 = FUN_400df58c(param_1,acStack_21);
  if (iVar2 != 0) {
    func_0x4008b770(uVar1);
    return 0x102;
  }
  piVar3 = (int *)func_0x4008dc54(1,0xc);
  if (piVar3 == (int *)0x0) {
    func_0x4008b770(uVar1);
    return 0x101;
  }
  piVar5 = (int *)*piVar5;
  *(undefined1 *)(piVar3 + 1) = 1;
  memw();
  iVar2 = *piVar5;
  *piVar3 = param_1;
  piVar3[2] = 0;
  if (iVar2 == 0) {
    *piVar5 = (int)piVar3;
  }
  else {
    do {
      iVar4 = iVar2;
      iVar2 = *(int *)(iVar4 + 8);
    } while (iVar2 != 0);
    *(int **)(iVar4 + 8) = piVar3;
    memw();
  }
  memw();
  iVar2 = func_0x4008a00c(0);
  if (param_1 == iVar2) {
    uVar6 = 0;
  }
  else {
    iVar2 = func_0x4008a00c(1);
    if (param_1 != iVar2) goto LAB_400df914;
    uVar6 = 1;
  }
  iVar2 = FUN_400dfd88(PTR_LAB_400d0a2c,uVar6);
  if (iVar2 != 0) {
    func_0x40088988(iVar2,DAT_400d0a24,0x129,DAT_400d0a34,DAT_400d0a30);
  }
LAB_400df914:
  if (acStack_21[0] != '\0') {
    FUN_400df5c8();
  }
  func_0x4008b770(uVar1);
  return 0;
}



// Function at 0x400df928

undefined4 FUN_400df928(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  char acStack_21 [33];
  
  uVar1 = DAT_400d09f0;
  func_0x4008b620(DAT_400d09f0,0xffffffff);
  if (*DAT_400d09dc == 0) {
    func_0x4008b770(uVar1);
    uVar1 = 0x103;
  }
  else {
    uVar2 = func_0x4008a674();
    iVar3 = FUN_400df58c(uVar2,acStack_21);
    if (iVar3 == 0) {
      func_0x4008b770(uVar1);
      uVar1 = 0x105;
    }
    else {
      *(undefined1 *)(iVar3 + 4) = 1;
      memw();
      if (acStack_21[0] != '\0') {
        memw();
        FUN_400df5c8();
      }
      func_0x4008b770(uVar1);
      uVar1 = 0;
    }
  }
  return uVar1;
}



// Function at 0x400df98c

void FUN_400df98c(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 in_PRID;
  
  uVar3 = rsr(in_PRID);
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 1;
    (*DAT_400d0a38)(uVar3 >> 0xd & 1,iVar1,6);
    iVar1 = iVar2;
  } while (iVar2 != 0x45);
  return;
}



// Function at 0x400df9b0

void FUN_400df9b0(void)

{
  memw();
  *DAT_400d0a3c = 1;
  memw();
  return;
}



// Function at 0x400df9c4

void FUN_400df9c4(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  iVar2 = param_1;
  do {
    if (iVar2 == 1) {
      while( true ) {
        if (param_1 == 1) {
          func_0x40087158(1);
        }
        iVar1 = func_0x40087974(2,0x400);
        if (iVar1 != 0) goto LAB_400df9f1;
        if (iVar3 != 1) break;
        iVar3 = 0;
      }
      iVar3 = iVar3 + -1;
      iVar2 = 0;
    }
LAB_400df9f1:
    func_0x40087250(iVar2);
    iVar1 = func_0x40087974(0,0x400);
    if (iVar1 != 0) {
      FUN_400e3258();
      return;
    }
  } while( true );
}



// Function at 0x400dfafc

void FUN_400dfafc(void)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  iVar3 = (*DAT_400d0a78)(0);
  iVar4 = (*DAT_400d0a78)(1);
  if ((iVar3 - 0xbU < 3) || (iVar4 - 0xbU < 3)) {
    uVar6 = func_0x40084644(DAT_400d062c);
    uVar6 = uVar6 ^ 0xffffffff;
    uVar9 = func_0x40084644(DAT_400d0630);
    uVar9 = uVar9 ^ 0xffffffff;
    uVar5 = func_0x40084644(DAT_400d0634);
    uVar5 = uVar5 ^ 0xffffffff;
  }
  else {
    uVar9 = 0xf;
    uVar6 = DAT_400d0a60;
    uVar5 = DAT_400d0a5c;
  }
  iVar3 = FUN_400e5070(1);
  if (iVar3 == 0) {
    uVar6 = uVar6 & 0xfffffffd;
    uVar8 = DAT_400d0a64;
  }
  else {
    uVar6 = uVar6 & 0xffffffbd;
    uVar8 = DAT_400d0a68;
  }
  uVar6 = uVar6 | uVar8;
  iVar3 = FUN_400e5070(2);
  puVar1 = DAT_400d0a70;
  if (iVar3 != 0) {
    uVar6 = uVar6 & DAT_400d0a6c;
  }
  uVar7 = func_0x40084644(DAT_400d0a70);
  uVar8 = DAT_400d05fc;
  memw();
  *puVar1 = uVar7 | DAT_400d05fc;
  puVar1 = DAT_400d0a74;
  memw();
  uVar7 = func_0x40084644(DAT_400d0a74);
  memw();
  *puVar1 = uVar7 | uVar8;
  puVar1 = DAT_400d062c;
  memw();
  uVar8 = func_0x40084644(DAT_400d062c);
  memw();
  *puVar1 = (uVar6 ^ 0xffffffff) & uVar8;
  puVar1 = DAT_400d0620;
  memw();
  uVar8 = func_0x40084644(DAT_400d0620);
  memw();
  *puVar1 = uVar6 | uVar8;
  puVar2 = DAT_400d0630;
  memw();
  uVar6 = func_0x40084644(DAT_400d0630);
  puVar1 = DAT_400d0624;
  memw();
  *puVar2 = (uVar9 ^ 0xffffffff) & uVar6;
  memw();
  uVar6 = func_0x40084644(puVar1);
  memw();
  *puVar1 = uVar9 | uVar6;
  puVar1 = DAT_400d0634;
  memw();
  uVar6 = func_0x40084644(DAT_400d0634);
  memw();
  *puVar1 = (uVar5 ^ 0xffffffff) & uVar6;
  memw();
  FUN_400da230(0x18);
  return;
}



// Function at 0x400dfcf4

void FUN_400dfcf4(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 in_PRID;
  
  uVar3 = DAT_400d0a8c;
  func_0x4008b620(DAT_400d0a8c,0xffffffff);
  uVar2 = rsr(in_PRID);
  memw();
  *(undefined4 *)(DAT_400d0a90 + (uVar2 >> 0xd & 1) * 4) = 0;
  memw();
  func_0x4008b770(uVar3);
  uVar2 = rsr(in_PRID);
  if ((uVar2 >> 0xd & 1) != 0) goto LAB_400dfd45;
  uVar3 = 0x18;
  while (iVar1 = FUN_400e383c(uVar3,0x400), iVar1 != 0) {
    func_0x40088988(iVar1,DAT_400d0aa4,0x71,DAT_400d0aa0,DAT_400d0a9c);
LAB_400dfd45:
    uVar3 = 0x19;
  }
  return;
}



// Function at 0x400dfd54

void FUN_400dfd54(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined1 in_PRID;
  
  uVar2 = rsr(in_PRID);
  puVar3 = (undefined4 *)((uVar2 >> 0xd & 1) * 0x20 + DAT_400d0aa8);
  iVar5 = 0;
  bVar1 = true;
  do {
    if (((code *)*puVar3 != (code *)0x0) && (iVar4 = (*(code *)*puVar3)(), iVar4 == 0)) {
      bVar1 = false;
    }
    iVar5 = iVar5 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar5 != 8);
  if (bVar1) {
    FUN_400f8288();
  }
  return;
}



// Function at 0x400dfd88

undefined4 FUN_400dfd88(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_400d0aac;
  uVar2 = 0x102;
  if (param_2 < 2) {
    func_0x4008b620(DAT_400d0aac,0xffffffff);
    if (*(int *)(param_2 * 0x20 + DAT_400d0aa8) == 0) {
      *(undefined4 *)(DAT_400d0aa8 + param_2 * 0x20) = param_1;
      memw();
      func_0x4008b770(uVar1);
      uVar2 = 0;
    }
    else {
      func_0x4008b770(uVar1,1);
      uVar2 = 0x101;
    }
  }
  return uVar2;
}



// Function at 0x400dfde0

undefined4 FUN_400dfde0(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_400d0aac;
  uVar2 = 0x102;
  if (param_2 < 2) {
    func_0x4008b620(DAT_400d0aac,0xffffffff);
    if (*(int *)(param_2 * 0x20 + DAT_400d0ab0) == 0) {
      *(undefined4 *)(DAT_400d0ab0 + param_2 * 0x20) = param_1;
      memw();
      func_0x4008b770(uVar1);
      uVar2 = 0;
    }
    else {
      func_0x4008b770(uVar1,1);
      uVar2 = 0x101;
    }
  }
  return uVar2;
}



// Function at 0x400dfee4

void FUN_400dfee4(void)

{
  int iVar1;
  uint uVar2;
  undefined1 in_PRID;
  
  uVar2 = rsr(in_PRID);
  FUN_400dfde0(DAT_400d0ac4,uVar2 >> 0xd & 1);
  FUN_400e3450(0x1a);
  uVar2 = rsr(in_PRID);
  (*DAT_400d0a38)(uVar2 >> 0xd & 1,0x14,0x1a);
  *DAT_400d0ac8 = 0;
  memw();
  iVar1 = FUN_400e3aa4();
  if (iVar1 != 0) {
    *DAT_400d0acc = 0xe;
  }
  memw();
  FUN_400e3440(0x1a);
  return;
}



// Function at 0x400dff2c

void FUN_400dff2c(undefined1 param_1)

{
  undefined1 auStack_34 [12];
  undefined4 uStack_28;
  uint uStack_24;
  
  memw();
  uStack_28 = 0;
  do {
    memw();
    uStack_24 = *(uint *)(*DAT_400d0ad0 + 0x1c);
    memw();
    memw();
  } while ((uStack_24 >> 0x10 & 0xff) == 0x80);
  memw();
  auStack_34[0] = param_1;
  FUN_400e11ec(DAT_400d0ad0,auStack_34,1,&uStack_28);
  return;
}



// Function at 0x400dff68

void FUN_400dff68(void)

{
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  local_30 = *DAT_400d0ad4;
  uStack_2c = DAT_400d0ad4[1];
  uStack_28 = *DAT_400d0ad8;
  uStack_24 = DAT_400d0ad8[1];
  memw();
  func_0x4008ca8c(&local_30);
  func_0x4008cb00(&local_30);
  func_0x4008cc00(&local_30);
  func_0x4008ca8c(&uStack_28);
  func_0x4008cb00(&uStack_28);
  func_0x4008cc00(&uStack_28);
  return;
}



// Function at 0x400dffa8

void FUN_400dffa8(char *param_1)

{
  while( true ) {
    if (*param_1 == '\0') break;
    FUN_400dff2c();
    param_1 = param_1 + 1;
  }
  return;
}



// Function at 0x400dffd0

void FUN_400dffd0(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 8;
  do {
    uVar1 = param_1 >> 0x1c;
    if (uVar1 < 10) {
      iVar3 = uVar1 + 0x30;
    }
    else {
      iVar3 = uVar1 + 0x57;
    }
    iVar2 = iVar2 + -1;
    FUN_400dff2c(iVar3);
    param_1 = param_1 << 4;
  } while (iVar2 != 0);
  return;
}



// Function at 0x400dfffc

void FUN_400dfffc(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (int)((longlong)param_1 * (longlong)DAT_400d0ae0 >> 0x22) - (param_1 >> 0x1f);
  if (iVar1 == 0) {
    uVar2 = 0x20;
  }
  else {
    uVar2 = iVar1 + 0x30U & 0xff;
  }
  FUN_400dff2c(uVar2);
  FUN_400dff2c(param_1 + iVar1 * -10 + 0x30U & 0xff);
  return;
}



// Function at 0x400e003c

void FUN_400e003c(void)

{
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  local_30 = *DAT_400d0ad4;
  uStack_2c = DAT_400d0ad4[1];
  uStack_28 = *DAT_400d0ad8;
  uStack_24 = DAT_400d0ad8[1];
  memw();
  func_0x4008c6e4(&local_30,1,DAT_400d0a28,0);
  func_0x4008ca8c(&local_30);
  func_0x4008c934(&local_30,0,2000,3);
  func_0x4008cab0(&local_30);
  func_0x4008cc00(&local_30);
  func_0x4008ca8c(&uStack_28);
  func_0x4008cb00(&uStack_28);
  func_0x4008cc00(&uStack_28);
  return;
}



// Function at 0x400e0094

void FUN_400e0094(undefined4 *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined *puVar8;
  undefined4 uVar9;
  undefined1 auStack_65 [65];
  int iStack_24;
  
  piVar2 = DAT_400d0098;
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  memw();
  FUN_400e003c();
  if (*DAT_400d0ae8 == '\0') {
    if (param_1[2] != 0) {
      FUN_400dffa8(DAT_400d0aec);
      FUN_400dfffc(*param_1);
      FUN_400dffa8(DAT_400d0af0);
      FUN_400dffa8(param_1[2]);
      FUN_400dffa8(DAT_400d0af4);
    }
  }
  else {
    puVar8 = PTR_LAB_400d0ae4;
    if (*DAT_400d0adc == 0) {
      puVar8 = (undefined *)0x0;
    }
    param_1[3] = 0;
    param_1[2] = 0;
    param_1[4] = puVar8;
    param_1[1] = 3;
  }
  if (param_1[3] != 0) {
    memw();
    FUN_400dffa8();
  }
  uVar9 = DAT_400d0af8;
  FUN_400dffa8(DAT_400d0af8);
  if ((code *)param_1[4] != (code *)0x0) {
    (*(code *)param_1[4])(param_1[7]);
  }
  FUN_400dffa8(uVar9);
  iVar5 = func_0x40084368();
  uVar3 = DAT_400d0b04;
  if (iVar5 != 0) {
    FUN_400dffa8(DAT_400d0afc);
    FUN_400dffd0(param_1[6]);
    FUN_400dffa8(DAT_400d0b00);
    FUN_400dff68();
    func_0x4008ba40(0,param_1[6]);
    memw();
    memw();
    if (iStack_24 == *piVar2) {
      return;
    }
    func_0x400831d4();
    return;
  }
  iVar5 = func_0x4008cc24(DAT_400d0b04);
  if (iVar5 == 0) {
    func_0x4008c6e4(uVar3,0,0,0);
    uVar6 = func_0x40087298();
    func_0x4008ca8c(uVar3);
    uVar7 = (*DAT_400d0248)(uVar6 * DAT_400d0b08,
                            (int)((ulonglong)uVar6 * (ulonglong)DAT_400d0b08 >> 0x20),DAT_400d0244,
                            DAT_400d0028);
    func_0x4008c934(uVar3,0,uVar7,3);
    func_0x4008cab0(uVar3);
    func_0x4008cc00(uVar3);
  }
  FUN_400e003c();
  if ((code *)param_1[5] != (code *)0x0) {
    (*(code *)param_1[5])(param_1[7]);
  }
  FUN_400dffa8(uVar9);
  FUN_400dffa8(DAT_400d0b0c);
  func_0x40081af8(auStack_65,0x41);
  FUN_400dffa8(auStack_65);
  FUN_400dffa8(uVar9);
  FUN_400dffa8(uVar9);
  pcVar4 = DAT_400d0b10;
  cVar1 = *DAT_400d0b10;
  if (cVar1 == '\0') goto LAB_400e0205;
  FUN_400dffa8(DAT_400d0b14);
  do {
    func_0x4008ca8c(uVar3);
    func_0x4008cb00(uVar3);
    func_0x4008cc00(uVar3);
    iVar5 = func_0x400837c0();
    if (iVar5 == 0) {
      param_1 = (undefined4 *)param_1[1];
      uVar9 = 5;
      if ((param_1 != (undefined4 *)0x1) && (uVar9 = 6, param_1 != (undefined4 *)0x2)) {
        uVar9 = 4;
      }
      func_0x4008378c(uVar9);
    }
    FUN_400dffa8(DAT_400d0b18);
    FUN_400e0594();
LAB_400e0205:
    FUN_400dff68();
    *pcVar4 = '\x01';
    memw();
    memw();
    FUN_400e565c(param_1);
    *pcVar4 = cVar1;
    memw();
    memw();
    FUN_400e003c();
  } while( true );
}



// Function at 0x400e022c

void FUN_400e022c(void)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined1 in_PRID;
  
  for (puVar1 = DAT_400d0b1c; DAT_400d0b20 <= puVar1; puVar1 = puVar1 + -2) {
    uVar2 = rsr(in_PRID);
    if ((puVar1[1] & 1 << ((byte)(uVar2 >> 0xd) & 1)) != 0) {
      (*(code *)*puVar1)();
    }
  }
  uVar2 = rsr(in_PRID);
  memw();
  *(undefined1 *)(DAT_400d0b24 + (uVar2 >> 0xd & 1)) = 1;
  memw();
  return;
}



// Function at 0x400e0594

/* WARNING: Control flow encountered bad instruction data */

void FUN_400e0594(void)

{
  int iVar1;
  
  iVar1 = func_0x40083950();
  if (iVar1 == -1) {
    func_0x400837dc();
  }
  func_0x40083174();
  cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// Function at 0x400e05f4

void FUN_400e05f4(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(*(uint *)(param_1 + 4) & 0xfffffffc);
  if ((uint)((int)puVar2 + DAT_400d0b98) <= DAT_400d0864) {
    FUN_400dffa8(DAT_400d0b9c);
    FUN_400dffd0(puVar2 + -1);
    FUN_400dffa8(DAT_400d0ba0);
    memw();
    FUN_400dffd0(puVar2[-1]);
    uVar1 = DAT_400d0ba4;
    FUN_400dffa8(DAT_400d0ba4);
    memw();
    FUN_400dffd0(*puVar2);
    FUN_400dffa8(uVar1);
    memw();
    FUN_400dffd0(puVar2[1]);
  }
  return;
}



// Function at 0x400e0648

void FUN_400e0648(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 in_DEBUGCAUSE;
  
  uVar2 = rsr(in_DEBUGCAUSE);
  FUN_400dffa8(DAT_400d0ba8);
  if ((uVar2 & 1) != 0) {
    FUN_400dffa8(DAT_400d0bac);
  }
  if ((uVar2 & 2) != 0) {
    FUN_400dffa8(DAT_400d0bb0);
  }
  if ((uVar2 & 4) != 0) {
    uVar1 = DAT_400d0bbc;
    if ((uVar2 & 0x100) != 0) {
      func_0x4008a8ac(*(int *)(DAT_400d0b64 + 4) == param_1);
      uVar1 = func_0x4008a828();
      FUN_400dffa8(DAT_400d0bb4);
      FUN_400dffa8(uVar1);
      uVar1 = DAT_400d0bb8;
    }
    FUN_400dffa8(uVar1);
  }
  if ((uVar2 & 8) != 0) {
    FUN_400dffa8(DAT_400d0bc0);
  }
  if ((uVar2 & 0x10) != 0) {
    FUN_400dffa8(DAT_400d0bc4);
  }
  if ((uVar2 & 0x20) != 0) {
    FUN_400dffa8(DAT_400d0bc8);
  }
  return;
}



// Function at 0x400e0784

void FUN_400e0784(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = *(uint *)(param_1 + 0x50);
  uVar2 = DAT_400d0bf8;
  if (uVar1 < 0x28) {
    uVar2 = *(undefined4 *)(DAT_400d0bfc + uVar1 * 4);
  }
  *(undefined4 *)(param_2 + 8) = uVar2;
  *(undefined4 *)(param_2 + 0xc) = DAT_400d0c00;
  if (uVar1 == 0) {
    *(undefined **)(param_2 + 0x10) = PTR_FUN_400d0c04;
  }
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 4);
  memw();
  return;
}



// Function at 0x400e07b4

void FUN_400e07b4(int param_1,undefined4 *param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x50);
  if (iVar3 == 5) {
    *param_2 = 0;
  }
  else {
    if (iVar3 != 6) {
      if (iVar3 == 7) {
        uVar2 = func_0x40083950();
        *param_2 = uVar2;
        memw();
      }
      goto LAB_400e07c5;
    }
    *param_2 = 1;
    memw();
  }
  param_2[1] = 1;
LAB_400e07c5:
  param_2[2] = DAT_400d0c08;
  iVar3 = *(int *)(param_1 + 0x50);
  param_2[3] = 0;
  if ((iVar3 < 8) &&
     (param_2[2] = *(undefined4 *)(DAT_400d0c0c + iVar3 * 4), puVar1 = PTR_FUN_400d0c10, iVar3 == 1)
     ) {
    param_2[1] = 0;
    param_2[4] = puVar1;
  }
  memw();
  return;
}



// Function at 0x400e0834

void FUN_400e0834(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = DAT_400d0c14;
  param_1[1] = param_2;
  *param_1 = uVar1;
  memw();
  return;
}



// Function at 0x400e0844

void FUN_400e0844(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  memw();
  memw();
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) | DAT_400d01e0;
  memw();
  memw();
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & DAT_400d06d4;
  memw();
  return;
}



// Function at 0x400e0870

void FUN_400e0870(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  memw();
  memw();
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) | DAT_400d01d0;
  memw();
  memw();
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & DAT_400d06d0;
  memw();
  return;
}



// Function at 0x400e089c

void FUN_400e089c(int *param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(*param_1 + 0xc) = *(uint *)(*param_1 + 0xc) & DAT_400d0c18 | param_2 & DAT_400d023c;
  memw();
  return;
}



// Function at 0x400e08c0

void FUN_400e08c0(int *param_1,uint param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  memw();
  memw();
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & DAT_400d0224 | param_2 & 0x7fff;
  memw();
  memw();
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & DAT_400d0140 | param_3 << 0x1f;
  memw();
  return;
}



// Function at 0x400e08f8

void FUN_400e08f8(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  memw();
  memw();
  *(uint *)(iVar1 + 0x4c) = *(uint *)(iVar1 + 0x4c) & 0xfffffc00 | param_2 & 0x3ff;
  memw();
  memw();
  *(uint *)(iVar1 + 0x48) = *(uint *)(iVar1 + 0x48) & DAT_400d0228 | param_3 & 0x3fff;
  memw();
  return;
}



// Function at 0x400e0934

void FUN_400e0934(int *param_1,uint *param_2)

{
  memw();
  *param_2 = *(uint *)(*param_1 + 0xc) & DAT_400d023c;
  memw();
  return;
}



// Function at 0x400e094c

uint * FUN_400e094c(uint *param_1,uint param_2)

{
  uint uVar1;
  uint extraout_a3;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *in_t0;
  
  if (param_2 == 0xffffffff) {
    param_2 = DAT_400d04d0;
  }
  param_2 = DAT_400d034c / param_2;
  uVar7 = param_2 >> 1;
  puVar3 = (uint *)(uVar7 & 0xffff);
  uVar8 = (uint)puVar3 >> 1;
  uVar5 = (int)puVar3 * 0x14 & 0xffff;
  puVar2 = (uint *)*param_1;
  if (puVar3 != (uint *)0x0) goto LAB_400e0988;
  uVar6 = 0x79;
  uVar8 = DAT_400d0c1c;
  puVar2 = in_t0;
  while( true ) {
    uVar7 = DAT_400d0c20;
    func_0x4008dacc(DAT_400d0c24,uVar6);
    puVar3 = puVar2;
    uVar5 = extraout_a3;
    in_t0 = puVar2;
LAB_400e0988:
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_400d0228 | (int)puVar3 - 1U & 0x3fff;
    uVar1 = DAT_400d0228;
    if ((uint *)0xd < puVar3) break;
    uVar6 = 0x82;
    memw();
    uVar8 = DAT_400d0c28;
    puVar2 = in_t0;
  }
  memw();
  puVar4 = (uint *)((int)puVar3 - 7);
  if ((puVar2[0x14] & 8) != 0) {
    memw();
    if ((puVar2[0x14] & 7) < 3) {
      puVar4 = puVar3 + -2;
    }
    else {
      memw();
      param_1 = (uint *)puVar2[0x14];
      memw();
      puVar4 = (uint *)((int)puVar3 - ((puVar2[0x14] & 7) + 6));
    }
  }
  memw();
  memw();
  puVar2[0xe] = puVar2[0xe] & DAT_400d0228 | (uint)puVar4 & 0x3fff;
  uVar9 = uVar7 & 0x3ff;
  memw();
  memw();
  puVar2[0xc] = puVar2[0xc] & 0xfffffc00 | param_2 >> 2 & 0x3ff;
  memw();
  memw();
  puVar2[0xd] = puVar2[0xd] & 0xfffffc00 | uVar8 & 0x3ff;
  memw();
  memw();
  puVar2[0x11] = puVar2[0x11] & 0xfffffc00 | uVar9;
  memw();
  memw();
  puVar2[0x13] = puVar2[0x13] & 0xfffffc00 | uVar9;
  memw();
  memw();
  puVar2[0x10] = puVar2[0x10] & 0xfffffc00 | uVar9;
  memw();
  memw();
  puVar2[0x12] = puVar2[0x12] & uVar1 | uVar7 & 0x3fff;
  memw();
  memw();
  puVar2[3] = puVar2[3] & DAT_400d0c18 | uVar5;
  memw();
  return param_1;
}



// Function at 0x400e0a94

void FUN_400e0a94(int *param_1)

{
  int iVar1;
  
  memw();
  memw();
  memw();
  memw();
  memw();
  iVar1 = *param_1;
  memw();
  memw();
  *(undefined4 *)(iVar1 + 4) = 3;
  memw();
  memw();
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & DAT_400d0430;
  memw();
  memw();
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & 0xfffffbff;
  memw();
  memw();
  *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) & 0xffffffbf;
  memw();
  memw();
  *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) & 0xffffff7f;
  memw();
  memw();
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) | DAT_400d01e0;
  memw();
  memw();
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & DAT_400d06d4;
  memw();
  memw();
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) | DAT_400d01d0;
  memw();
  memw();
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & DAT_400d06d0;
  memw();
  return;
}



// Function at 0x400e0b50

void FUN_400e0b50(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  memw();
  param_1[1] = *(int *)(iVar1 + 0xf8);
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  *(undefined4 *)(iVar1 + 4) = 0x13;
  memw();
  memw();
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & 0xfffffbff;
  memw();
  memw();
  *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) & 0xffffffbf;
  memw();
  memw();
  *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) & 0xffffff7f;
  memw();
  memw();
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) | DAT_400d01e0;
  memw();
  memw();
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & DAT_400d06d4;
  memw();
  memw();
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) | DAT_400d01d0;
  memw();
  memw();
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & DAT_400d06d0;
  memw();
  return;
}



// Function at 0x400e0c10

void FUN_400e0c10(int *param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *param_1;
  if ((int)param_2 < 0x20) {
    memw();
    *(int *)(iVar1 + 0x4c) = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
  }
  else {
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    *(uint *)(iVar1 + 0x58) =
         *(uint *)(iVar1 + 0x58) & 0xffffff00 | 1 << 0x20 - (0x20 - (param_2 & 0x1f)) & 0xffU;
    memw();
  }
  iVar1 = iVar1 + (param_2 + 0x20) * 4;
  memw();
  uVar2 = DAT_400d0600;
  if (param_3 != 0) {
    uVar2 = DAT_400d01e0;
  }
  memw();
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) & DAT_400d0c2c | uVar2;
  memw();
  return;
}



// Function at 0x400e0c8c

void FUN_400e0c8c(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  iVar1 = iVar2 + (param_2 + 0x20) * 4;
  memw();
  memw();
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) & DAT_400d0c2c;
  if ((int)param_2 < 0x20) {
    memw();
    *(int *)(iVar2 + 0x4c) = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
  }
  else {
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    *(uint *)(iVar2 + 0x58) =
         *(uint *)(iVar2 + 0x58) & 0xffffff00 | 1 << 0x20 - (0x20 - (param_2 & 0x1f)) & 0xffU;
    memw();
  }
  memw();
  return;
}



// Function at 0x400e0cfc

void FUN_400e0cfc(int *param_1,int param_2)

{
  memw();
  memw();
  *(uint *)(*param_1 + 0x20) =
       *(uint *)(*param_1 + 0x20) & DAT_400d0c30 | (uint)(param_2 == 0) << 0x1b;
  memw();
  return;
}



// Function at 0x400e0d28

void FUN_400e0d28(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  memw();
  iVar1 = DAT_400d034c;
  if ((*(uint *)(iVar2 + 0x20) & 0x8000000) == 0) {
    iVar1 = DAT_400d01e4;
  }
  param_2 = (uint)(iVar1 << 4) / param_2;
  memw();
  memw();
  *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & DAT_400d0c18 | (param_2 << 8) >> 0xc;
  memw();
  memw();
  *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & DAT_400d0c34 | (param_2 & 0xf) << 0x14;
  memw();
  return;
}



// Function at 0x400e0d7c

void FUN_400e0d7c(int *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  
  memw();
  iVar2 = DAT_400d034c;
  if ((*(uint *)(*param_1 + 0x20) & 0x8000000) == 0) {
    iVar2 = DAT_400d01e4;
  }
  memw();
  uVar1 = *(uint *)(*param_1 + 0x14);
  memw();
  memw();
  memw();
  *param_2 = (uint)(iVar2 << 4) / ((uVar1 & DAT_400d023c) << 4 | uVar1 >> 0x14 & 0xf);
  memw();
  return;
}



// Function at 0x400e0dc0

void FUN_400e0dc0(int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if ((param_2 & 1) == 0) {
    memw();
    uVar1 = *(uint *)(iVar2 + 0x24) & DAT_400d0c3c;
  }
  else {
    memw();
    memw();
    *(uint *)(iVar2 + 0x24) = *(uint *)(iVar2 + 0x24) & DAT_400d0c38 | (param_3 & 0x7f) << 0x10;
    memw();
    uVar1 = *(uint *)(iVar2 + 0x24) | DAT_400d05f8;
  }
  memw();
  *(uint *)(iVar2 + 0x24) = uVar1;
  memw();
  if ((param_2 & 2) == 0) {
    uVar1 = *(uint *)(iVar2 + 0x20) & DAT_400d0c40;
  }
  else {
    uVar1 = *(uint *)(iVar2 + 0x20) | DAT_400d0600;
  }
  memw();
  *(uint *)(iVar2 + 0x20) = uVar1;
  memw();
  return;
}



// Function at 0x400e0e28

void FUN_400e0e28(int *param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(*param_1 + 0x40) = *(uint *)(*param_1 + 0x40) & DAT_400d0c44 | (param_2 & 0x3ff) << 10;
  memw();
  return;
}



// Function at 0x400e0e50

void FUN_400e0e50(int *param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(*param_1 + 0x24) = *(uint *)(*param_1 + 0x24) & DAT_400d0c48 | (param_2 & 0x7f) << 8;
  memw();
  return;
}



// Function at 0x400e0e74

void FUN_400e0e74(int *param_1,uint param_2)

{
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  *(uint *)(*param_1 + 0x20) =
       (((((((*(uint *)(*param_1 + 0x20) & DAT_400d06d0 | (param_2 & 1) << 0xc) & DAT_400d06d4 |
            (param_2 >> 1 & 1) << 0xd) & DAT_400d0c4c | (param_2 >> 2 & 1) << 0x13) & DAT_400d0c50 |
          (param_2 >> 3 & 1) << 0x14) & DAT_400d0c54 | (param_2 >> 4 & 1) << 0x15) & DAT_400d0c58 |
        (param_2 >> 5 & 1) << 0x16) & DAT_400d0c3c | (param_2 >> 6 & 1) << 0x17) & DAT_400d059c |
       (param_2 >> 7 & 1) << 0x18;
  memw();
  return;
}



// Function at 0x400e0f5c

void FUN_400e0f5c(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = *param_1;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | DAT_400d0c5c;
  memw();
  iVar2 = DAT_400d034c;
  if ((*(uint *)(iVar1 + 0x20) & 0x8000000) == 0) {
    iVar2 = DAT_400d01e4;
  }
  uVar3 = (uint)((ulonglong)(uint)(iVar2 << 4) * (ulonglong)DAT_400d0c60 >> 0x20);
  memw();
  memw();
  *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) & DAT_400d0c18 | uVar3 >> 0x14;
  memw();
  memw();
  *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) & DAT_400d0c34 | (uVar3 >> 0x10 & 0xf) << 0x14;
  memw();
  memw();
  *(uint *)(iVar1 + 0x44) = *(uint *)(iVar1 + 0x44) & 0xfffffffe;
  memw();
  memw();
  *(uint *)(iVar1 + 0x44) = *(uint *)(iVar1 + 0x44) & 0xfffffff7;
  memw();
  memw();
  *(uint *)(iVar1 + 0x44) = *(uint *)(iVar1 + 0x44) & 0xffffffef;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & DAT_400d0a6c;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0xfffffffd;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | 0xc;
  memw();
  memw();
  *(uint *)(iVar1 + 0x44) = *(uint *)(iVar1 + 0x44) & 0xfffffffb;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0xffffffcf | 0x10;
  memw();
  memw();
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & DAT_400d0c44;
  memw();
  memw();
  *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) & DAT_400d0c3c;
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & DAT_400d0c40;
  memw();
  return;
}



// Function at 0x400e1078

void FUN_400e1078(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = FUN_400f817c(param_1);
  iVar3 = *param_1;
  uVar4 = iVar1 * (param_2 & 0xff);
  memw();
  uVar2 = (uVar4 & 0xffff) + 7 >> 3;
  if ((*(uint *)(iVar3 + 0x20) & 0x8000000) == 0) {
    uVar2 = (uVar4 & 0x1fff) << 3;
  }
  memw();
  if (uVar2 == 0) {
    uVar2 = *(uint *)(iVar3 + 0x24) & DAT_400d0140;
  }
  else {
    memw();
    *(uint *)(iVar3 + 0x24) = *(uint *)(iVar3 + 0x24) & DAT_400d0c64 | (uVar2 & 0x7f) << 0x18;
    memw();
    uVar2 = *(uint *)(iVar3 + 0x24) | DAT_400d0284;
  }
  memw();
  *(uint *)(iVar3 + 0x24) = uVar2;
  memw();
  return;
}



// Function at 0x400e10dc

uint FUN_400e10dc(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_400f817c(param_1);
  iVar2 = 0x3f8;
  memw();
  if ((*(uint *)(*param_1 + 0x20) >> 0x1b & 1) == 0) {
    iVar2 = 0xf;
  }
  return iVar2 / iVar1 & 0xffff;
}



// Function at 0x400e1100

void FUN_400e1100(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 == DAT_400d0298) {
    memw();
    memw();
    *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | DAT_400d0260;
    memw();
    memw();
    *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & DAT_400d0c68;
  }
  memw();
  return;
}



// Function at 0x400e1134

void FUN_400e1134(int *param_1)

{
  uint uVar1;
  
  do {
    memw();
    memw();
    memw();
    memw();
    uVar1 = *(uint *)(*param_1 + 0x60);
    memw();
    if ((*(uint *)(*param_1 + 0x1c) & 0xff) == 0) {
      memw();
      memw();
      if ((uVar1 >> 2 & 0x7ff) == (uVar1 >> 0xd & 0x7ff)) {
        return;
      }
    }
    memw();
    memw();
  } while( true );
}



// Function at 0x400e1190

void FUN_400e1190(int *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (param_2 == 0) {
    memw();
    uVar1 = *(uint *)(iVar2 + 0x20) & 0xfffffeff;
  }
  else {
    memw();
    memw();
    memw();
    memw();
    memw();
    memw();
    *(uint *)(iVar2 + 0x40) = *(uint *)(iVar2 + 0x40) & DAT_400d0c78 | (param_2 & 0xff) << 0x14;
    memw();
    uVar1 = *(uint *)(iVar2 + 0x20) | 0x100;
  }
  memw();
  *(uint *)(iVar2 + 0x20) = uVar1;
  memw();
  return;
}



// Function at 0x400e11ec

void FUN_400e11ec(int *param_1,int param_2,uint param_3,uint *param_4)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  
  iVar1 = DAT_400d0298;
  iVar6 = *param_1;
  memw();
  memw();
  memw();
  uVar3 = 0x80 - (*(uint *)(iVar6 + 0x1c) >> 0x10 & 0xff);
  uVar4 = param_3 & 0xffff;
  if ((uVar3 & 0xffff) <= param_3) {
    uVar4 = uVar3 & 0xffff;
  }
  *param_4 = uVar4;
  puVar5 = DAT_400d029c;
  if ((iVar6 != iVar1) && (puVar5 = DAT_400d02a0, iVar6 != DAT_400d02a4)) {
    puVar5 = DAT_400d02bc;
  }
  uVar3 = 0;
  while (uVar3 < uVar4) {
    pbVar2 = (byte *)(param_2 + uVar3);
    uVar3 = uVar3 + 1;
    memw();
    *puVar5 = (uint)*pbVar2;
    memw();
  }
  memw();
  return;
}



// Function at 0x400e1248

void FUN_400e1248(int *param_1,int param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  iVar3 = *param_1;
  if (0 < *param_3) goto LAB_400e1299;
  memw();
  memw();
  memw();
  memw();
  uVar5 = *(uint *)(iVar3 + 0x60);
  memw();
  memw();
  memw();
  if ((uVar5 >> 2 & 0x7ff) < (uVar5 >> 0xd & 0x7ff)) {
    memw();
    uVar1 = uVar5 >> 0xd & 0x7ff;
    memw();
LAB_400e1293:
    iVar2 = uVar1 - (uVar5 >> 2 & 0x7ff);
  }
  else {
    memw();
    memw();
    if ((uVar5 >> 0xd & 0x7ff) < (uVar5 >> 2 & 0x7ff)) {
      memw();
      uVar1 = (uVar5 >> 0xd & 0x7ff) + 0x80;
      memw();
      goto LAB_400e1293;
    }
    iVar2 = 0;
    if ((*(uint *)(iVar3 + 0x1c) & 0xff) != 0) {
      iVar2 = 0x80;
    }
  }
  *param_3 = iVar2;
LAB_400e1299:
  iVar2 = *param_3;
  puVar6 = DAT_400d0c6c;
  if ((iVar3 != DAT_400d0298) && (puVar6 = DAT_400d0c70, iVar3 != DAT_400d02a4)) {
    puVar6 = DAT_400d0c74;
  }
  iVar3 = 0;
  while (iVar2 != iVar3) {
    memw();
    puVar4 = (undefined1 *)(param_2 + iVar3);
    iVar3 = iVar3 + 1;
    *puVar4 = (char)*puVar6;
    memw();
    memw();
  }
  memw();
  return;
}



// Function at 0x400e13fc

undefined4 FUN_400e13fc(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((*(int *)(param_1 + 4) == DAT_400d0c80) && (DAT_400d0c90 < (uint)(param_2 + DAT_400d0c8c))) {
    uVar1 = 0;
  }
  return uVar1;
}



// Function at 0x400e1420

undefined4 FUN_400e1420(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400e13fc(param_1,param_2);
  return uVar1;
}



// Function at 0x400e1434

void FUN_400e1434(byte *param_1)

{
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  memw();
  *(uint *)(DAT_400d0a50 + 0xd4) =
       ((((param_1[3] & 1) << 0xe & DAT_400d0c40 | (param_1[4] & 1) << 0xf | DAT_400d0c94) &
         DAT_400d0270 | (param_1[2] & 1) << 0x1a) & DAT_400d0c98 | (*param_1 & 7) << 0x1b) &
       DAT_400d0c9c | (param_1[1] & 1) << 0x1e;
  memw();
  return;
}



// Function at 0x400e14f0

void FUN_400e14f0(uint param_1)

{
  memw();
  memw();
  *(uint *)(DAT_400d0a50 + 0x3c) = *(uint *)(DAT_400d0a50 + 0x3c) & 0xffffff7f | (param_1 & 1) << 7;
  memw();
  return;
}



// Function at 0x400e1514

void FUN_400e1514(void)

{
  memw();
  memw();
  *(uint *)(DAT_400d0a50 + 0x48) = *(uint *)(DAT_400d0a50 + 0x48) | 0x80;
  memw();
  return;
}



// Function at 0x400e1534

uint FUN_400e1534(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 0xffffffff;
  if ((param_1 != 0) && (param_2 < 0x40)) {
    uVar1 = (uint)*(byte *)(DAT_400d0ca0 + param_2 * 3 + 2);
  }
  return uVar1;
}



// Function at 0x400e1554

int FUN_400e1554(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xb4);
  iVar1 = func_0x40086cd0(param_2,param_1 + 0xa4,iVar3);
  if (iVar1 != 0) {
    func_0x4008dacc(DAT_400d0cb0,0x128,DAT_400d0cac,DAT_400d0ca8);
  }
  iVar2 = func_0x40086c6c(param_2);
  iVar1 = DAT_400d0ca4;
  if (iVar3 != iVar2) {
    iVar1 = param_2 + iVar3;
  }
  return iVar1;
}



// Function at 0x400e1588

undefined4
FUN_400e1588(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  memw();
  iVar1 = func_0x4008dbdc(0xc0);
  uVar3 = 0x101;
  if (iVar1 != 0) {
    for (iVar2 = 0; iVar2 != *DAT_400d0cb4; iVar2 = iVar2 + 1) {
      if (*(int *)(iVar2 * 4 + DAT_400d0cb8) == 0) goto LAB_400e15d4;
    }
    if (iVar2 == 8) {
      func_0x4008dbfc(iVar1);
      uVar3 = 0x101;
    }
    else {
      *DAT_400d0cb4 = iVar2 + 1;
LAB_400e15d4:
      *(int *)(DAT_400d0cb8 + iVar2 * 4) = iVar1;
      if (param_2 == -1) {
        func_0x40086818(iVar1 + 0xa4,0,0xf);
      }
      else {
        memw();
        func_0x40086b94(iVar1 + 0xa4,param_1);
      }
      func_0x400866b8(iVar1,param_3,0xa4);
      uVar3 = 0;
      *(int *)(iVar1 + 0xb4) = param_2;
      *(undefined4 *)(iVar1 + 0xb8) = param_4;
      *(int *)(iVar1 + 0xbc) = iVar2;
      if (param_5 != (int *)0x0) {
        *param_5 = iVar2;
        memw();
      }
    }
  }
  return uVar3;
}



// Function at 0x400e1618

undefined4
FUN_400e1618(char *param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  if (param_2 != 0xffffffff) {
    if ((param_2 == 1) || (0xf < param_2)) {
      return 0x102;
    }
    if (1 < param_2) {
      if (*param_1 != '/') {
        return 0x102;
      }
      if (param_1[param_2 - 1] == '/') {
        return 0x102;
      }
    }
  }
  uVar1 = FUN_400e1588(param_1,param_2,param_3,param_4,param_5);
  return uVar1;
}



// Function at 0x400e1658

undefined4 FUN_400e1658(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = func_0x40086c6c(param_1);
  uVar1 = FUN_400e1618(param_1,uVar1,param_2,param_3,0);
  return uVar1;
}



// Function at 0x400e1674

undefined4 FUN_400e1674(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((-1 < (int)param_1) && (uVar1 = 0, param_1 < *DAT_400d0cb4)) {
    uVar1 = *(undefined4 *)(DAT_400d0cb8 + param_1 * 4);
  }
  return uVar1;
}



// Function at 0x400e1694

undefined4 FUN_400e1694(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 < 0x40) {
    uVar1 = FUN_400e1674((int)*(char *)(DAT_400d0ca0 + param_1 * 3 + 1));
  }
  return uVar1;
}



// Function at 0x400e16b8

void FUN_400e16b8(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  uVar1 = func_0x40086c6c(param_1);
  uVar8 = 0xffffffff;
  iVar2 = *DAT_400d0cb4;
  iVar3 = 0;
  for (iVar6 = 0; iVar2 != iVar6; iVar6 = iVar6 + 1) {
    iVar7 = *(int *)(iVar6 * 4 + DAT_400d0cb8);
    if (((iVar7 != 0) && (uVar5 = *(uint *)(iVar7 + 0xb4), uVar5 <= uVar1)) && (uVar5 != 0xffffffff)
       ) {
      memw();
      iVar4 = func_0x40086624(param_1,iVar7 + 0xa4,uVar5);
      if ((iVar4 == 0) &&
         ((uVar9 = uVar8, iVar3 == 0 && uVar5 == 0 ||
          (((uVar1 <= uVar5 || (*(char *)(param_1 + uVar5) == '/')) &&
           (uVar9 = uVar5, (int)uVar8 < (int)uVar5)))))) {
        iVar3 = iVar7;
        uVar8 = uVar9;
      }
    }
  }
  memw();
  return;
}



// Function at 0x400e1744

undefined4
FUN_400e1744(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte *pbVar1;
  uint *puVar2;
  undefined4 uVar3;
  code *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  puVar2 = (uint *)FUN_400e16b8(param_2);
  uVar3 = 2;
  if (puVar2 == (uint *)0x0) goto LAB_400e1762;
  uVar3 = FUN_400e1554(puVar2,param_2);
  pcVar4 = (code *)puVar2[6];
  if (pcVar4 != (code *)0x0) {
    if ((*puVar2 & 1) == 0) {
      iVar5 = (*pcVar4)(uVar3,param_3,param_4);
    }
    else {
      iVar5 = (*pcVar4)(puVar2[0x2e],uVar3,param_3,param_4);
    }
    uVar3 = DAT_400d0cbc;
    if (iVar5 < 0) {
      puVar6 = (undefined4 *)FUN_400ea128();
      uVar3 = *puVar6;
      goto LAB_400e1762;
    }
    func_0x40085334(DAT_400d0cbc);
    pbVar1 = DAT_400d0ca0;
    if (DAT_400d0ca0[1] == 0xff) {
      uVar7 = puVar2[0x2f];
      *DAT_400d0ca0 = *DAT_400d0ca0 & 0xfe;
      pbVar1[1] = (byte)uVar7;
      pbVar1[2] = (byte)iVar5;
      memw();
      memw();
      func_0x40085374(uVar3);
      return 0;
    }
    func_0x40085374(uVar3);
    pcVar4 = (code *)puVar2[7];
    if (pcVar4 != (code *)0x0) {
      if ((*puVar2 & 1) == 0) {
        (*pcVar4)(iVar5);
      }
      else {
        (*pcVar4)(puVar2[0x2e],iVar5);
      }
      uVar3 = 0xc;
      goto LAB_400e1762;
    }
  }
  uVar3 = 0x58;
LAB_400e1762:
  *param_1 = uVar3;
  memw();
  return 0xffffffff;
}



// Function at 0x400e1980

undefined4 FUN_400e1980(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  puVar1 = (uint *)FUN_400e1694(param_2);
  iVar2 = FUN_400e1534(puVar1,param_2);
  if ((puVar1 == (uint *)0x0) || (iVar2 < 0)) {
    uVar3 = 9;
  }
  else {
    pcVar4 = (code *)puVar1[8];
    if (pcVar4 != (code *)0x0) {
      if ((*puVar1 & 1) == 0) {
        uVar3 = (*pcVar4)(iVar2,param_3);
      }
      else {
        uVar3 = (*pcVar4)(puVar1[0x2e],iVar2,param_3);
      }
      goto LAB_400e199b;
    }
    uVar3 = 0x58;
  }
  *param_1 = uVar3;
  uVar3 = 0xffffffff;
LAB_400e199b:
  memw();
  return uVar3;
}



// Function at 0x400e1bc0

undefined4 FUN_400e1bc0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_400e1674(*DAT_400d0ccc);
  (**(code **)(iVar1 + 4))(*DAT_400d0cc8,param_2,param_3);
  return param_3;
}



// Function at 0x400e1be0

undefined4 FUN_400e1be0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_400e1674(*DAT_400d0ccc);
  uVar2 = (**(code **)(iVar1 + 0x20))(param_1,param_2);
  return uVar2;
}



// Function at 0x400e1bf8

undefined4 FUN_400e1bf8(void)

{
  int iVar1;
  
  iVar1 = FUN_400e1674(*DAT_400d0ccc);
  (**(code **)(iVar1 + 0x1c))(*DAT_400d0cc8);
  return 0;
}



// Function at 0x400e1c14

undefined4 FUN_400e1c14(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_400e1674(*DAT_400d0ccc);
  uVar2 = (**(code **)(iVar1 + 0xc))(*DAT_400d0cc8,param_2,param_3);
  return uVar2;
}



// Function at 0x400e1c34

undefined4 FUN_400e1c34(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_400e1674(*DAT_400d0ccc);
  uVar2 = (**(code **)(iVar1 + 0x54))(*DAT_400d0cc8,param_2,param_3);
  return uVar2;
}



// Function at 0x400e1c58

undefined4 FUN_400e1c58(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_400e1674(*DAT_400d0ccc);
  uVar2 = (**(code **)(iVar1 + 0x5c))(*DAT_400d0cc8);
  return uVar2;
}



// Function at 0x400e1c78

undefined4 FUN_400e1c78(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_400e1674(*DAT_400d0ccc);
  uVar2 = (**(code **)(iVar1 + 0x60))(DAT_400d0cc4,param_2);
  return uVar2;
}



// Function at 0x400e1c98

undefined4 FUN_400e1c98(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_400e1674(*DAT_400d0ccc);
  uVar2 = (**(code **)(iVar1 + 0xa0))(param_1);
  return uVar2;
}



// Function at 0x400e1cb4

undefined4 FUN_400e1cb4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_400e1674(*DAT_400d0ccc);
  uVar2 = (**(code **)(iVar1 + 0x70))(*DAT_400d0cc8,param_2,param_3);
  return uVar2;
}



// Function at 0x400e1cd8

undefined4 FUN_400e1cd8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_400e1674(*DAT_400d0ccc);
  uVar2 = (**(code **)(iVar1 + 0x74))(*DAT_400d0cc8,param_2);
  return uVar2;
}



// Function at 0x400e1cf4

undefined4 FUN_400e1cf4(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_400e1674(*DAT_400d0ccc);
  uVar2 = (**(code **)(iVar1 + 0x78))(*DAT_400d0cc8);
  return uVar2;
}



// Function at 0x400e1d14

undefined4 FUN_400e1d14(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_400e1674(*DAT_400d0ccc);
  uVar2 = (**(code **)(iVar1 + 0x7c))(*DAT_400d0cc8,param_2);
  return uVar2;
}



// Function at 0x400e1d30

undefined4
FUN_400e1d30(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  
  memw();
  iVar1 = FUN_400e1674(*DAT_400d0ccc);
  memw();
  uVar2 = (**(code **)(iVar1 + 0x8c))(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return uVar2;
}



// Function at 0x400e1d60

undefined4 FUN_400e1d60(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400e1658(DAT_400d0cd4,DAT_400d0cd0,0);
  return uVar1;
}



// Function at 0x400e1d98

void FUN_400e1d98(int param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = **(int **)(DAT_400d0cd8 + param_1 * 4);
  do {
    memw();
    memw();
    memw();
  } while (0x80 - (*(uint *)(iVar2 + 0x1c) >> 0x10 & 0xff) < 2);
  puVar1 = DAT_400d029c;
  if ((iVar2 != DAT_400d0298) && (puVar1 = DAT_400d02a0, iVar2 != DAT_400d02a4)) {
    puVar1 = DAT_400d02bc;
  }
  memw();
  *puVar1 = param_2 & 0xff;
  memw();
  return;
}



// Function at 0x400e1de8

uint FUN_400e1de8(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = **(int **)(DAT_400d0cd8 + param_1 * 4);
  memw();
  memw();
  memw();
  memw();
  uVar2 = *(uint *)(iVar4 + 0x60);
  memw();
  memw();
  memw();
  if ((uVar2 >> 2 & 0x7ff) < (uVar2 >> 0xd & 0x7ff)) {
    memw();
    uVar3 = uVar2 >> 0xd & 0x7ff;
    memw();
  }
  else {
    memw();
    memw();
    if ((uVar2 >> 2 & 0x7ff) <= (uVar2 >> 0xd & 0x7ff)) {
      if ((*(uint *)(iVar4 + 0x1c) & 0xff) == 0) {
        return 0xffffffff;
      }
      goto LAB_400e1e40;
    }
    memw();
    uVar3 = (uVar2 >> 0xd & 0x7ff) + 0x80;
    memw();
  }
  if (uVar3 == (uVar2 >> 2 & 0x7ff)) {
    return 0xffffffff;
  }
LAB_400e1e40:
  puVar1 = DAT_400d0c6c;
  if ((iVar4 != DAT_400d0298) && (puVar1 = DAT_400d0c70, iVar4 != DAT_400d02a4)) {
    puVar1 = DAT_400d0c74;
  }
  memw();
  memw();
  return *puVar1 & 0xff;
}



// Function at 0x400e1e98

int FUN_400e1e98(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_400d0cd8 + param_1 * 4);
  iVar1 = *(int *)(iVar2 + 4);
  if (iVar1 == -1) {
    iVar1 = (**(code **)(iVar2 + 0x20))(param_1);
  }
  else {
    *(undefined4 *)(iVar2 + 4) = 0xffffffff;
  }
  memw();
  return iVar1;
}



// Function at 0x400e27b4

undefined4 FUN_400e27b4(uint param_1)

{
  if (2 < param_1) {
    func_0x4008dacc(DAT_400d0d30,0x125,DAT_400d0d38,DAT_400d0d28);
  }
  return 0;
}



// Function at 0x400e27d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_400e27d0(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int unaff_retaddr;
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint in_t0;
  
  func_0x4008dacc(DAT_400d0d30,0xe9,DAT_400d0d40,DAT_400d0d3c);
  cust0();
  if (in_t0 < param_4) {
    uVar1 = *(undefined4 *)(_DAT_400cebe8 + 0x28);
    if (((*(int *)(unaff_retaddr + 0x94) == 0) ||
        (iVar2 = func_0x40086a70(uVar1,DAT_400d0d48), iVar2 == 0)) ||
       (iVar2 = func_0x40086a70(uVar1,DAT_400d0d4c), iVar2 == 0)) {
      if (param_2 == 0) goto LAB_400e2820;
      param_1 = 6;
      goto LAB_400e280c;
    }
    puVar3 = (undefined4 *)FUN_400ea128();
    uVar1 = 2;
  }
  else {
LAB_400e280c:
    if (((param_2 & param_1) != 0) && (param_2 = param_2 & 1, param_2 == 0)) goto LAB_400e2820;
    puVar3 = (undefined4 *)FUN_400ea128();
    uVar1 = 0xd;
  }
  *puVar3 = uVar1;
  param_2 = 0xffffffff;
LAB_400e2820:
  memw();
  return param_2;
}



// Function at 0x400e28b8

int FUN_400e28b8(uint param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  if (2 < param_1) {
    func_0x4008dacc(DAT_400d0d30,0xc2,DAT_400d0d58,DAT_400d0d28);
  }
  pcVar3 = param_2 + param_3;
  iVar2 = *(int *)(DAT_400d0cd8 + param_1 * 4);
  func_0x40085344(iVar2 + 0xc);
  for (; param_2 != pcVar3; param_2 = param_2 + 1) {
    cVar1 = *param_2;
    if (((cVar1 != '\n') || (*(int *)(iVar2 + 0x14) == 2)) ||
       ((**(code **)(iVar2 + 0x1c))(param_1,0xd), *(int *)(iVar2 + 0x14) != 1)) {
      (**(code **)(iVar2 + 0x1c))(param_1,cVar1);
    }
  }
  func_0x40085384(iVar2 + 0xc);
  return param_3;
}



// Function at 0x400e2a04

void FUN_400e2a04(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_400e3d88(param_1,param_2,param_3);
  return;
}



// Function at 0x400e2a14

void FUN_400e2a14(undefined4 param_1)

{
  FUN_400e3dd8(param_1);
  return;
}



// Function at 0x400e2a20

undefined4 FUN_400e2a20(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = func_0x40089194(*param_1,0,0);
  return uVar1;
}



// Function at 0x400e2a38

int FUN_400e2a38(void)

{
  int iVar1;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_28 = DAT_400d0174;
  uStack_24 = 0;
  memw();
  iVar1 = func_0x400840b4(8,DAT_400d0458);
  if (iVar1 != 0) {
    func_0x400866b8(iVar1,&uStack_28);
  }
  return iVar1;
}



// Function at 0x400e2a60

int * FUN_400e2a60(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  uVar1 = DAT_400d0458;
  piVar2 = (int *)func_0x400842c4(1,8,DAT_400d0458);
  if (piVar2 != (int *)0x0) {
    iVar3 = func_0x400842c4(1,0x54,uVar1);
    piVar2[1] = iVar3;
    if (iVar3 != 0) {
      iVar3 = func_0x40089150(param_1,param_2,iVar3);
      *piVar2 = iVar3;
      if (iVar3 != 0) goto LAB_400e2aaa;
    }
    if (piVar2[1] != 0) {
      func_0x4008dbfc();
    }
    memw();
    func_0x4008dbfc(piVar2);
    piVar2 = (int *)0x0;
  }
LAB_400e2aaa:
  memw();
  return piVar2;
}



// Function at 0x400e2ad8

undefined4 FUN_400e2ad8(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = func_0x400896ec(*param_1,param_2);
  return uVar1;
}



// Function at 0x400e2aec

void FUN_400e2aec(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iStack_3c;
  int iStack_38;
  uint uStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  
  func_0x40086818(param_1,0,0x1c);
  iVar2 = *DAT_400d0d64;
  while (iVar2 != 0) {
    iVar1 = FUN_400f81e4(iVar2,param_2);
    if (iVar1 != 0) {
      FUN_400f9044(*(undefined4 *)(iVar2 + 0x1c),&iStack_3c);
      *param_1 = *param_1 + iStack_3c;
      param_1[1] = param_1[1] + iStack_38;
      uVar3 = param_1[2];
      param_1[2] = (uVar3 < uStack_34) * uStack_34 + (uVar3 >= uStack_34) * uVar3;
      param_1[3] = param_1[3] + iStack_30;
      param_1[4] = param_1[4] + iStack_2c;
      param_1[5] = param_1[5] + iStack_28;
      param_1[6] = param_1[6] + iStack_24;
    }
    iVar2 = *(int *)(iVar2 + 0x20);
    memw();
  }
  return;
}



// Function at 0x400e2b6c

void FUN_400e2b6c(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_400d0610 < (uint)(*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc))) {
    func_0x4008dacc(DAT_400d0d70,0x21,DAT_400d0d6c,DAT_400d0d68);
  }
  uVar1 = FUN_400f9030();
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  memw();
  return;
}



// Function at 0x400e2b98

void FUN_400e2b98(void)

{
  int iVar1;
  
  for (iVar1 = *DAT_400d0d64; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x20)) {
    if (*(int *)(iVar1 + 0x1c) == 0) {
      FUN_400e2b6c(iVar1);
      if (*(int *)(iVar1 + 0x1c) != 0) {
        func_0x4008d79c(*(int *)(iVar1 + 0x1c),iVar1 + 0x14);
      }
    }
  }
  return;
}



// Function at 0x400e2dac

undefined4 FUN_400e2dac(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  piVar2 = DAT_400d0d64;
  bVar1 = param_1 == 0;
  if ((((bVar1) || (param_2 == 0 || bVar1)) || (param_3 == 0 || (param_2 == 0 || bVar1))) ||
     (param_3 <= param_2)) {
    uVar4 = 0x102;
  }
  else {
    for (iVar5 = *DAT_400d0d64; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x20)) {
      if (((*(int *)(iVar5 + 0xc) < param_3) && (param_2 <= *(int *)(iVar5 + 0xc))) ||
         ((*(int *)(iVar5 + 0x10) < param_3 && (param_2 < *(int *)(iVar5 + 0x10))))) {
        return 0xffffffff;
      }
    }
    iVar5 = func_0x400840b4(0x24,DAT_400d0458);
    if (iVar5 == 0) {
      uVar4 = 0x101;
    }
    else {
      func_0x400866b8(iVar5,param_1,0xc);
      uVar4 = DAT_400d0174;
      *(int *)(iVar5 + 0xc) = param_2;
      *(int *)(iVar5 + 0x10) = param_3;
      *(undefined4 *)(iVar5 + 0x14) = uVar4;
      *(undefined4 *)(iVar5 + 0x18) = 0;
      memw();
      iVar3 = FUN_400f9030(param_2,param_3 - param_2);
      *(int *)(iVar5 + 0x1c) = iVar3;
      *(undefined4 *)(iVar5 + 0x20) = 0;
      if (iVar3 != 0) {
        memw();
        func_0x4008d79c(iVar3,iVar5 + 0x14);
        uVar4 = DAT_400d0d8c;
        func_0x4008b620(DAT_400d0d8c,0xffffffff);
        *(int *)(iVar5 + 0x20) = *piVar2;
        *piVar2 = iVar5;
        memw();
        func_0x4008b770(uVar4);
        return 0;
      }
      uVar4 = 0x104;
    }
    func_0x4008dbfc(iVar5);
  }
  return uVar4;
}



// Function at 0x400e2e64

undefined4 FUN_400e2e64(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = 0x102;
  if (param_1 != 0) {
    piVar2 = DAT_400d0d94;
    for (iVar1 = 0; *DAT_400d0d90 != iVar1; iVar1 = iVar1 + 1) {
      if ((*piVar2 <= param_1) && (param_1 < *piVar2 + piVar2[1])) {
        uVar3 = FUN_400e2dac(DAT_400d0d7c + DAT_400d0d94[iVar1 * 4 + 2] * 0x14 + 4,param_1,param_2);
        return uVar3;
      }
      piVar2 = piVar2 + 4;
    }
    uVar3 = 0x105;
  }
  return uVar3;
}



// Function at 0x400e2ed4

int FUN_400e2ed4(uint *param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  uint *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  undefined4 uVar14;
  uint uVar15;
  uint uVar16;
  uint *puVar17;
  uint uVar18;
  uint *in_t0;
  int in_WindowStart;
  undefined8 uVar19;
  undefined1 auStack_60 [16];
  uint *puStack_50;
  uint *puStack_4c;
  uint *puStack_48;
  uint uStack_44;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  int iStack_24;
  
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  iVar9 = *DAT_400d0d90;
  iVar5 = (uint)(in_WindowStart == 0) * (int)auStack_60;
  iVar2 = (uint)(in_WindowStart != 0) * (int)(auStack_60 + iVar9 * -0x10);
  memw();
  puStack_48 = param_1;
  puStack_50 = (uint *)func_0x400866b8(iVar5 + iVar2 + 0x10,DAT_400d0d94,iVar9 * 0x10);
  iVar1 = (uint)(in_WindowStart == 0) * (iVar5 + iVar2);
  iVar5 = (uint)(in_WindowStart != 0) *
          ((iVar5 + iVar2) - ((DAT_400d0d98 - DAT_400d0d9c) + 0xfU & 0xfffffff0));
  puVar8 = (uint *)(iVar1 + iVar5 + 0x10);
  uVar7 = DAT_400d0d98 - DAT_400d0d9c >> 3;
  memw();
  func_0x400866b8(puVar8);
  FUN_400f84d0(puVar8,uVar7,8,PTR_FUN_400d0da0);
  uVar13 = 0xfffffffc;
  uVar15 = uVar7 - 1;
  uVar12 = 0;
  puVar4 = puVar8;
  puVar10 = puStack_50;
  while (uVar19 = CONCAT44(uVar13,uVar12), uVar12 != uVar7) {
    uVar12 = puVar4[1] + 3 & uVar13;
    puVar11 = (uint *)(uVar13 & *puVar4);
    *puVar4 = (uint)puVar11;
    puVar4[1] = uVar12;
    if ((int)puVar11 <= (int)uVar12) goto LAB_400e2fa1;
    uVar14 = 0x62;
    uVar6 = DAT_400d0da4;
    puVar10 = in_t0;
    while( true ) {
      memw();
      uVar15 = DAT_400d0da8;
      uVar19 = func_0x4008dacc(DAT_400d0dac,uVar14,DAT_400d0da8,uVar6);
      puVar11 = puVar10;
      in_t0 = puVar10;
LAB_400e2fa1:
      puVar17 = puVar4 + 2;
      if (uVar15 <= (uint)uVar19) goto LAB_400e2fee;
      if ((int)puVar11 < (int)puVar4[2]) break;
      uVar14 = 100;
      uVar6 = DAT_400d0db0;
      puVar10 = in_t0;
    }
    if ((int)puVar4[2] < (int)uVar12) {
      uVar7 = *DAT_400d0920;
      puVar10 = in_t0;
      if (uVar7 != 0) {
        memw();
        puStack_50 = puVar17;
        uVar6 = func_0x4008d9f8();
        uVar7 = puStack_50[1];
        *(uint *)(iVar1 + iVar5) = uVar7;
        puVar17 = (uint *)*puVar4;
        memw();
        uVar15 = DAT_400d0db4;
        (*DAT_400d092c)(DAT_400d0db8,uVar6,DAT_400d0db4,puVar17,puVar4[1],*puStack_50);
        puVar10 = in_t0;
      }
      uVar19 = func_0x4008da40();
      in_t0 = puVar10;
    }
LAB_400e2fee:
    puVar4 = puVar17;
    uVar13 = (uint)((ulonglong)uVar19 >> 0x20);
    uVar12 = (int)uVar19 + 1;
  }
  puStack_4c = puVar10 + iVar9 * 4;
  puVar4 = puStack_48;
LAB_400e2f51:
  if (puVar10 == puStack_4c) {
    memw();
    memw();
    if (iStack_24 == *DAT_400d0098) {
      return (int)puVar4 - (int)puStack_48 >> 4;
    }
    memw();
    iVar5 = func_0x400831d4();
    return iVar5;
  }
  uStack_34 = *puVar10;
  uStack_30 = puVar10[1];
  uStack_2c = puVar10[2];
  uStack_28 = puVar10[3];
  uStack_44 = 0;
  uVar15 = uStack_30;
  uVar12 = uStack_34;
  uVar13 = uStack_34 + uStack_30;
  puVar11 = puVar8;
  while (uStack_44 != uVar7) {
    uVar18 = puVar11[1];
    uVar16 = uVar13;
    if ((int)uVar12 < (int)uVar18) {
      uVar16 = *puVar11;
      if ((int)uVar13 <= (int)uVar16) break;
      bVar3 = (int)uVar13 <= (int)uVar18 && (int)uVar16 <= (int)uVar12;
      if (bVar3) goto LAB_400e3075;
      if (((int)uVar18 < (int)uVar13) && ((int)uVar12 < (int)uVar16)) {
        uVar15 = uVar16 - uVar12;
        puVar10[1] = uStack_30 - (uVar18 - uStack_34);
        *puVar10 = uVar18;
        if (0x10 < (int)uVar15) goto LAB_400e305f;
        goto LAB_400e2f51;
      }
      if ((int)uVar12 < (int)uVar16) {
        uVar15 = uVar16 - uVar12;
      }
      else {
        uVar15 = uVar13 - uVar18;
        uVar12 = uVar18;
        uVar16 = uVar13;
      }
    }
    puVar11 = puVar11 + 2;
    uStack_44 = uStack_44 + 1;
    memw();
    uVar13 = uVar16;
  }
  bVar3 = true;
  if (0x10 < uVar15) goto code_r0x400e301d;
  goto LAB_400e3075;
code_r0x400e301d:
  memw();
LAB_400e305f:
  puVar4[1] = uVar15;
  *puVar4 = uVar12;
  puVar4[2] = uStack_2c;
  puVar4[3] = uStack_28;
  puVar4 = puVar4 + 4;
  uStack_34 = uVar12;
  uStack_30 = uVar15;
  if (bVar3) {
LAB_400e3075:
    puVar10 = puVar10 + 4;
    memw();
  }
  goto LAB_400e2f51;
}



// Function at 0x400e30a4

void FUN_400e30a4(uint *param_1,uint param_2,uint *param_3)

{
  bool bVar1;
  uint extraout_a3;
  uint *puVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  uint in_t0;
  uint in_SCOMPARE1;
  undefined1 uVar11;
  uint uVar12;
  undefined1 in_PRID;
  uint auStack_24 [9];
  
  uVar12 = 0;
  uVar4 = rsil(3);
  uVar6 = rsil(3);
  uVar3 = rsr(in_PRID);
  uVar5 = uVar3 ^ DAT_400d0dbc;
  uVar10 = (int)DAT_400d0dc0 + DAT_400d0dc4;
  puVar2 = DAT_400d0dc0;
  do {
    uVar8 = DAT_400d0174;
    if (DAT_400d0864 < uVar10) goto LAB_400e310c;
    memw();
    uVar12 = uVar12 & 0xffffcfff;
    auStack_24[0] = uVar3;
    FUN_400e30a4(puVar2,DAT_400d0174,auStack_24);
    while (uVar5 != auStack_24[0]) {
      bVar1 = auStack_24[0] + DAT_400d0dc8 != 0;
      uVar9 = DAT_400d0dd0;
      if ((uVar3 == auStack_24[0]) || (!bVar1)) {
        uVar3 = puVar2[1];
        if ((uVar3 == 0) == bVar1) {
          uVar7 = 0x7b;
          uVar10 = DAT_400d0dd8;
        }
        else if (uVar3 < 0xff) {
          puVar2[1] = uVar3 + 1;
          uVar11 = (undefined1)uVar12;
          wsr(uVar11,uVar6);
          rsync();
          memw();
          uVar3 = *param_1;
          if (uVar3 == param_2) {
            memw();
            *param_1 = *param_3;
          }
          param_2 = rsil(3);
          uVar6 = rsr(in_PRID);
          param_1 = (uint *)*puVar2;
          if ((uint *)uVar6 == param_1) {
            param_1 = (uint *)(puVar2[1] - 1);
            puVar2[1] = (uint)param_1;
            if (param_1 == (uint *)0x0) {
              *puVar2 = DAT_400d0174;
LAB_400e3188:
              wsr(uVar11,param_2);
              rsync();
              memw();
              wsr(uVar11,uVar4);
              *param_3 = uVar3;
              memw();
              return;
            }
            puVar2 = (uint *)0xff;
            if (param_1 < 0x100) goto LAB_400e3188;
            uVar7 = 0xa4;
            uVar9 = DAT_400d0de4;
            uVar10 = DAT_400d0de8;
          }
          else {
            uVar7 = 0x9e;
            memw();
            uVar9 = DAT_400d0de4;
            uVar10 = DAT_400d0de0;
          }
        }
        else {
          uVar7 = 0x7c;
          uVar10 = DAT_400d0ddc;
        }
      }
      else {
        uVar7 = 0x7a;
        uVar10 = DAT_400d0dcc;
      }
      uVar12 = uVar12 & 0xffffcfff;
      uVar5 = in_t0;
      func_0x4008dacc(DAT_400d0dd4,uVar7,uVar9);
      uVar6 = uVar5;
      uVar8 = extraout_a3;
      in_t0 = uVar5;
LAB_400e310c:
      wsr((char)in_SCOMPARE1,uVar8);
      auStack_24[0] = *puVar2;
      if (auStack_24[0] == in_SCOMPARE1) {
        *puVar2 = uVar3;
      }
      memw();
    }
  } while( true );
}



// Function at 0x400e31b0

undefined8 FUN_400e31b0(void)

{
  undefined4 uVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined8 uVar11;
  
  func_0x4008b5f8();
  uVar1 = DAT_400d0dec;
  func_0x4008b620(DAT_400d0dec,0xffffffff);
  puVar3 = DAT_400d0df8;
  puVar2 = DAT_400d0df4;
  uVar5 = DAT_400d0028;
  memw();
  uVar4 = *DAT_400d0df0;
  if (uVar4 == 0) {
    *DAT_400d0df4 = DAT_400d0028;
    puVar2[1] = uVar5;
    *puVar3 = uVar5;
    puVar3[1] = uVar5;
  }
  memw();
  uVar11 = func_0x40087a28();
  uVar6 = (uint)uVar11 - *puVar3;
  uVar7 = (uint)((ulonglong)uVar6 * (ulonglong)uVar4 >> 0x20);
  uVar5 = ((int)((ulonglong)uVar11 >> 0x20) - puVar3[1]) - (uint)((uint)uVar11 < uVar6);
  uVar8 = uVar5 * uVar4;
  uVar10 = uVar7 << 0xd | uVar6 * uVar4 >> 0x13;
  uVar6 = uVar10 + uVar8 * 0x2000;
  uVar9 = *puVar2;
  *puVar2 = uVar6 + uVar9;
  puVar2[1] = (uint)(uVar6 + uVar9 < uVar6) +
              (uint)(uVar6 < uVar10) +
              (uVar7 >> 0x13) +
              (uVar8 >> 0x13 | (int)((ulonglong)uVar5 * (ulonglong)uVar4 >> 0x20) << 0xd) +
              puVar2[1];
  *(undefined8 *)puVar3 = uVar11;
  memw();
  func_0x4008b5f8();
  func_0x4008b770(uVar1);
  return *(undefined8 *)puVar2;
}



// Function at 0x400e3258

void FUN_400e3258(undefined4 param_1)

{
  FUN_400e31b0();
  memw();
  *DAT_400d0df0 = param_1;
  memw();
  return;
}



// Function at 0x400e326c

undefined4 FUN_400e326c(void)

{
  memw();
  return *DAT_400d0df0;
}



// Function at 0x400e327c

undefined4 FUN_400e327c(void)

{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  
  uVar1 = DAT_400d0dfc;
  func_0x4008b620(DAT_400d0dfc,0xffffffff);
  pcVar2 = DAT_400d0e00;
  if (*DAT_400d0e00 == '\0') {
    func_0x4008779c();
    func_0x40087974(1,100);
    iVar3 = func_0x40087b58();
    *DAT_400d0e04 = iVar3;
    if (iVar3 == 0) {
      memw();
      func_0x4008b770(uVar1);
      return 0;
    }
  }
  *pcVar2 = *pcVar2 + '\x01';
  memw();
  memw();
  func_0x4008b770(uVar1);
  return 1;
}



// Function at 0x400e32d0

int FUN_400e32d0(void)

{
  return *DAT_400d0e04 << 8;
}



// Function at 0x400e32e0

uint * FUN_400e32e0(uint param_1,uint param_2)

{
  uint *puVar1;
  
  for (puVar1 = (uint *)*DAT_400d0e08;
      (puVar1 != (uint *)0x0 &&
      (((*puVar1 >> 0x10 & 1) != param_2 || ((*puVar1 >> 0x11 & 0x1f) != param_1))));
      puVar1 = (uint *)puVar1[2]) {
  }
  return puVar1;
}



// Function at 0x400e3304

ushort FUN_400e3304(uint *param_1,uint param_2,uint param_3,int param_4)

{
  ushort uVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = *param_1 >> 0x11 & 0x1f;
  iVar4 = FUN_400e6928(uVar5,param_3);
  uVar3 = 0;
  if ((iVar4 != 1) && (param_4 != -1 || iVar4 != 2)) {
    bVar2 = FUN_400e6914(uVar5);
    uVar3 = 0;
    if ((param_2 & 1 << (bVar2 & 0x1f)) != 0) {
      iVar4 = FUN_400e6900(uVar5);
      if ((param_2 & 0x200) == 0) {
        if (iVar4 == 1) {
          return 0;
        }
      }
      else if (iVar4 == 0) {
        return 0;
      }
      uVar1 = (ushort)*param_1;
      if ((uVar1 & 1) == 0) {
        if ((uVar1 & 0xc) == 0xc) {
          func_0x4008dacc(DAT_400d0e14,0xfb,DAT_400d0e10,DAT_400d0e0c);
        }
        if ((uVar1 & 8) == 0) {
          if ((uVar1 & 4) == 0) {
            uVar3 = FUN_400e3abc(uVar5,param_3 & 0xff);
            uVar3 = (uVar3 ^ 1) & 0xff;
          }
          else if (((param_2 & 0x100) != 0) && (uVar3 = 1, (param_2 >> 10 & 1) != (uVar1 >> 1 & 1)))
          {
            uVar3 = uVar1 & 8;
          }
        }
      }
    }
  }
  return uVar3;
}



// Function at 0x400e33a4

uint * FUN_400e33a4(uint param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  
  puVar2 = (uint *)FUN_400e32e0(param_1,param_2);
  if ((puVar2 == (uint *)0x0) &&
     (puVar2 = (uint *)func_0x400840b4(0xc,DAT_400d0458), puVar2 != (uint *)0x0)) {
    puVar2 = (uint *)func_0x40086818(puVar2,0,0xc);
    puVar1 = DAT_400d0e08;
    *puVar2 = (*puVar2 & DAT_400d0e18 | (param_1 & 0x1f) << 0x11) & DAT_400d0a6c |
              (param_2 & 1) << 0x10;
    puVar6 = (uint *)*puVar1;
    puVar3 = (uint *)0x0;
    for (puVar4 = puVar6;
        ((puVar4 != (uint *)0x0 && (uVar5 = *puVar4, (uVar5 >> 0x10 & 1) <= (param_2 & 1))) &&
        ((((uVar5 ^ *puVar2) & DAT_400d060c) != 0 || ((uVar5 >> 0x11 & 0x1f) < (param_1 & 0x1f)))));
        puVar4 = (uint *)puVar4[2]) {
      puVar3 = puVar4;
    }
    if ((puVar3 == (uint *)0x0) || (puVar6 == (uint *)0x0 || puVar3 == (uint *)0x0)) {
      puVar2[2] = (uint)puVar4;
      *puVar1 = (uint)puVar2;
    }
    else {
      puVar3[2] = (uint)puVar2;
      puVar2[2] = (uint)puVar4;
      memw();
    }
  }
  memw();
  return puVar2;
}



// Function at 0x400e3440

void FUN_400e3440(uint param_1)

{
  func_0x4008ed78(1 << 0x20 - (0x20 - (param_1 & 0x1f)));
  return;
}



// Function at 0x400e3450

void FUN_400e3450(uint param_1)

{
  func_0x4008ed90(1 << 0x20 - (0x20 - (param_1 & 0x1f)));
  return;
}



// Function at 0x400e3460

undefined4
FUN_400e3460(uint param_1,uint param_2,int param_3,int param_4,int param_5,undefined4 param_6,
            undefined4 *param_7)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  int *piVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  uint *in_t0;
  undefined1 in_PRID;
  int iStack_4c;
  uint uStack_48;
  int iStack_44;
  uint local_2c [11];
  
  if (((((param_2 & 0x300) == 0x300) || (((param_2 & 0xf0) != 0 && (param_5 != 0)))) ||
      (((param_2 & 0x100) != 0 && ((param_5 == 0 || ((int)param_1 < 0)))))) ||
     (((param_3 != 0 && (param_4 == 0)) ||
      (((((param_2 & 0x400) != 0 && (param_5 != 0)) &&
        (DAT_400d0b6c < (uint)(param_5 + DAT_400d0b68))) &&
       (DAT_400d028c < (uint)(param_5 + DAT_400d0b74))))))) {
    return 0x102;
  }
  if ((param_2 & 0xfe) == 0) {
    uVar5 = 2;
    if ((param_2 & 0x100) == 0) {
      uVar5 = 0xe;
    }
    param_2 = param_2 | uVar5;
  }
  if (param_1 == 0xffffffff) {
    uVar5 = 6;
LAB_400e34f5:
    if (param_1 == 0xfffffffa) {
      uVar5 = 0xb;
    }
  }
  else {
    uVar5 = 0xf;
    if (param_1 == 0xfffffffe) goto LAB_400e34f5;
    uVar5 = 0x10;
    if (((param_1 != 0xfffffffd) && (uVar5 = 7, param_1 != 0xfffffffc)) &&
       (uVar5 = 0x1d, param_1 != 0xfffffffb)) {
      uVar5 = 0xffffffff;
      goto LAB_400e34f5;
    }
  }
  memw();
  puVar2 = (undefined4 *)func_0x400840b4(8,DAT_400d0458);
  if (puVar2 != (undefined4 *)0x0) {
    memw();
    func_0x4008b620(DAT_400d0e1c,0xffffffff);
    uVar6 = rsr(in_PRID);
    uVar6 = uVar6 >> 0xd & 1;
    memw();
    func_0x40086818(local_2c,0,0xc);
    uStack_48 = param_2;
    if ((param_2 & 0xfe) == 0) {
      uStack_48 = param_2 | 0xe;
    }
    uVar12 = 4;
    for (puVar8 = (uint *)*DAT_400d0e08; puVar8 != (uint *)0x0; puVar8 = (uint *)puVar8[2]) {
      uVar11 = *puVar8;
      if (((ushort)*puVar8 & uVar12) == 0) {
        if ((param_1 == (int)(uVar11 << 2) >> 0x18) && (uVar6 == (uVar11 >> 0x10 & 1))) {
LAB_400e3600:
          if ((uVar5 != 0xffffffff) && (uVar5 != (uVar11 >> 0x11 & 0x1f))) goto LAB_400e35cc;
          memw();
          iVar3 = FUN_400e3304(puVar8,uStack_48,uVar6,uVar5);
          if (iVar3 == 0) goto LAB_400e35cc;
          uVar5 = *puVar8;
          goto LAB_400e3622;
        }
      }
      else if (uVar6 == (uVar11 >> 0x10 & 1)) {
        piVar9 = (int *)puVar8[1];
        if (piVar9 == (int *)0x0) {
          uVar12 = DAT_400d0e24;
          puVar8 = in_t0;
          piVar9 = (int *)func_0x4008dacc(DAT_400d0e14,0xa7,DAT_400d0e24,DAT_400d0e20);
          in_t0 = puVar8;
        }
        do {
          if (param_1 == (*piVar9 << 0x17) >> 0x18) goto LAB_400e3600;
          piVar9 = (int *)piVar9[5];
        } while (piVar9 != (int *)0x0);
      }
    }
    if (uVar5 == 0xffffffff) {
      iStack_4c = 9;
      iStack_44 = DAT_400d0140;
      uVar5 = 0;
      uVar12 = 0xffffffff;
      do {
        memw();
        puVar8 = (uint *)FUN_400e32e0(uVar5,uVar6);
        if (puVar8 == (uint *)0x0) {
          local_2c[0] = local_2c[0] & DAT_400d0e18 | (uVar5 & 0x1f) << 0x11;
          puVar8 = local_2c;
        }
        memw();
        iVar3 = FUN_400e3304(puVar8,uStack_48,uVar6,0xffffffff);
        if (iVar3 == 0) goto LAB_400e35c4;
        if ((uStack_48 & 0x100) == 0) {
          iVar3 = FUN_400e6914(uVar5);
joined_r0x400e36e3:
          if (iVar3 < iStack_4c) {
LAB_400e36d1:
            memw();
            uVar12 = uVar5;
            iStack_4c = iVar3;
          }
        }
        else if ((*puVar8 & 4) == 0) {
          if (uVar12 == 0xffffffff) {
            iVar3 = FUN_400e6914(uVar5);
            goto joined_r0x400e36e3;
          }
        }
        else {
          iVar7 = 0;
          for (uVar11 = puVar8[1]; uVar11 != 0; uVar11 = *(uint *)(uVar11 + 0x14)) {
            iVar7 = iVar7 + 1;
          }
          iVar3 = FUN_400e6914(uVar5);
          if ((iVar7 < iStack_44) || (iVar3 < iStack_4c)) {
            memw();
            iStack_44 = iVar7;
            goto LAB_400e36d1;
          }
        }
LAB_400e35c4:
        uVar5 = uVar5 + 1;
      } while (uVar5 != 0x20);
      if (uVar12 == 0xffffffff) goto LAB_400e35cc;
    }
    else {
      puVar8 = (uint *)FUN_400e32e0(uVar5,uVar6);
      if (puVar8 == (uint *)0x0) {
        local_2c[0] = local_2c[0] & DAT_400d0e18 | (uVar5 & 0x1f) << 0x11;
        puVar8 = local_2c;
      }
      memw();
      iVar3 = FUN_400e3304(puVar8,uStack_48,uVar6,uVar5);
      if (iVar3 == 0) {
LAB_400e35cc:
        func_0x4008b770(DAT_400d0e1c);
        func_0x4008dbfc(puVar2);
        return 0x105;
      }
      uVar5 = *puVar8;
LAB_400e3622:
      uVar12 = uVar5 >> 0x11 & 0x1f;
    }
    puVar8 = (uint *)FUN_400e33a4(uVar12,uVar6);
    uVar1 = DAT_400d0e1c;
    if (puVar8 != (uint *)0x0) {
      if ((param_2 & 0x100) == 0) {
        *(ushort *)puVar8 = 8;
        memw();
        if (param_5 != 0) {
          memw();
          FUN_400e3ae0(uVar12 & 0xff,param_5,param_6);
        }
        if ((param_2 & 0x200) != 0) {
          func_0x4008ecf0(1 << 0x20 - (0x20 - (uVar12 & 0x1f)));
        }
        *puVar8 = *puVar8 & DAT_400d0e2c | (param_1 & 0xff) << 0x16;
        memw();
LAB_400e375a:
        puVar10 = (uint *)(DAT_400d0e30 + uVar6 * 4);
        uVar5 = 1 << 0x20 - (0x20 - (uVar12 & 0x1f));
        uVar11 = *puVar10;
        if ((param_2 & 0x400) == 0) {
          *(ushort *)puVar8 = (ushort)*puVar8 & 0xfffd;
          memw();
          uVar5 = uVar5 | uVar11;
          memw();
        }
        else {
          *(ushort *)puVar8 = (ushort)*puVar8 | 2;
          memw();
          uVar5 = (uVar5 ^ 0xffffffff) & uVar11;
        }
        *puVar10 = uVar5;
        if (-1 < (int)param_1) {
          memw();
          (*DAT_400d0a38)(uVar6,param_1,uVar12);
        }
        *puVar2 = puVar8;
        puVar2[1] = puVar8[1];
        memw();
        FUN_400e3440(uVar12);
        if ((param_2 & 0x800) != 0) {
          func_0x40084558(puVar2);
        }
        func_0x4008b770(DAT_400d0e1c);
        if (param_7 == (undefined4 *)0x0) {
          func_0x4008dbfc(puVar2);
        }
        else {
          *param_7 = puVar2;
        }
        memw();
        return 0;
      }
      iVar3 = func_0x4008dbdc(0x18);
      if (iVar3 != 0) {
        puVar4 = (ushort *)func_0x40086818(iVar3,0,0x18);
        *(int *)(puVar4 + 2) = param_3;
        *(int *)(puVar4 + 6) = param_5;
        uVar5 = puVar8[1];
        *(int *)(puVar4 + 4) = param_4;
        *(uint *)(puVar4 + 10) = uVar5;
        *(undefined4 *)(puVar4 + 8) = param_6;
        *puVar4 = *puVar4 & 0xfe00 | (ushort)((param_1 & 0xff) << 1);
        uVar1 = DAT_400d0e28;
        memw();
        puVar8[1] = (uint)puVar4;
        *(ushort *)puVar8 = (ushort)*puVar8 | 4;
        memw();
        memw();
        FUN_400e3ae0(uVar12 & 0xff,uVar1,puVar8);
        goto LAB_400e375a;
      }
    }
    func_0x4008b770(uVar1);
    func_0x4008dbfc(puVar2);
  }
  return 0x101;
}



// Function at 0x400e383c

undefined4
FUN_400e383c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  
  memw();
  uVar1 = FUN_400e3460(param_1,param_2,0,0,param_3,param_4,param_5);
  return uVar1;
}



// Function at 0x400e385c

int FUN_400e385c(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  ushort *puVar9;
  undefined1 in_PRID;
  undefined8 uVar10;
  
  uVar1 = DAT_400d0e1c;
  if (param_1 == (int *)0x0) {
    iVar2 = 0x102;
  }
  else {
    uVar6 = *(uint *)*param_1 >> 0x10 & 1;
    uVar3 = rsr(in_PRID);
    if (uVar6 == (uVar3 >> 0xd & 1)) {
      func_0x4008b620(DAT_400d0e1c,0xffffffff);
      func_0x40084558(param_1);
      puVar9 = (ushort *)*param_1;
      uVar5 = *puVar9 & 4;
      if ((*puVar9 & 4) != 0) {
        uVar10 = CONCAT44(puVar9,*(int *)(puVar9 + 2));
        if (*(int *)(puVar9 + 2) == 0) {
          uVar10 = func_0x4008dacc(DAT_400d0e14,0x28d,DAT_400d0e3c,DAT_400d0e38);
        }
        iVar2 = 0;
        iVar7 = (int)uVar10;
        do {
          iVar4 = *(int *)(iVar7 + 0x14);
          if (param_1[1] == iVar7) {
            if (iVar2 == 0) {
              *(int *)((int)((ulonglong)uVar10 >> 0x20) + 4) = iVar4;
              memw();
            }
            else {
              *(int *)(iVar2 + 0x14) = iVar4;
            }
            memw();
            func_0x4008dbfc();
            break;
          }
          iVar2 = iVar7;
          iVar7 = iVar4;
        } while (iVar4 != 0);
        uVar5 = (ushort)(*(int *)(*param_1 + 4) == 0);
      }
      if (((*(uint *)*param_1 & 8) != 0) || (uVar5 != 0)) {
        uVar3 = *(uint *)*param_1 >> 0x11 & 0x1f;
        FUN_400e3ae0(uVar3,0,uVar3);
        uVar3 = *(uint *)*param_1 & DAT_400d0e40 | DAT_400d0e44;
        *(uint *)*param_1 = uVar3;
        puVar8 = (uint *)(DAT_400d0e30 + (uVar3 >> 0x10 & 1) * 4);
        *puVar8 = (uint)(0xfffffffefffffffe >> 0x20 - (uVar3 >> 0x11 & 0x1f)) & *puVar8;
      }
      memw();
      func_0x4008b770(uVar1);
      func_0x4008dbfc(param_1);
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_400e5014(uVar6,PTR_LAB_400d0e34,param_1);
      iVar2 = -(uint)(iVar2 != 0);
    }
  }
  return iVar2;
}



// Function at 0x400e3964

void FUN_400e3964(undefined1 param_1)

{
  *DAT_400d0e48 = param_1;
  memw();
  memw();
  return;
}



// Function at 0x400e3978

void FUN_400e3978(void)

{
  int iVar1;
  uint *puVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  int *in_t0;
  undefined8 uVar11;
  
  puVar8 = DAT_400d0e54;
  iVar6 = 0;
  iVar9 = 0x27;
  iVar10 = 1;
  uVar7 = 0xffffffff;
  memw();
  uVar5 = *DAT_400d0e4c & DAT_400d055c;
  memw();
  memw();
  *DAT_400d0e4c = *DAT_400d0e4c & DAT_400d0e50;
  while ((iVar1 = DAT_400d02a8, uVar11 = CONCAT44(iVar6,uVar5), iVar6 <= iVar9 && (uVar5 != 0))) {
    piVar4 = *(int **)(iVar6 * 4 + DAT_400d0364);
    if ((uVar5 & 1 << ((byte)piVar4 & 0x1f)) != 0) {
      piVar3 = (int *)(DAT_400d0664 + (int)piVar4 * 0x38);
      memw();
      memw();
      *puVar8 = (uVar7 ^ piVar3[10]) & *puVar8;
      puVar2 = (uint *)*piVar3;
      if ((uint)((int)puVar2 + iVar1) <= DAT_400d02ac) {
        memw();
        uVar7 = DAT_400d0e5c;
        puVar8 = DAT_400d0e58;
        piVar3 = in_t0;
        uVar11 = func_0x4008dacc(DAT_400d0e60,0xec);
        piVar4 = piVar3;
        in_t0 = piVar3;
      }
      iVar6 = (int)((ulonglong)uVar11 >> 0x20);
      uVar5 = (uint)uVar11 & (uVar7 ^ iVar10 << 0x20 - (0x20 - ((uint)piVar4 & 0x1f)));
      memw();
      memw();
      *puVar2 = (uVar7 ^ piVar3[9]) & *puVar2;
    }
    iVar6 = iVar6 + 1;
    memw();
  }
  memw();
  return;
}



// Function at 0x400e3aa4

bool FUN_400e3aa4(void)

{
  uint uVar1;
  
  uVar1 = func_0x40083e58();
  return 299 < uVar1;
}



// Function at 0x400e3abc

bool FUN_400e3abc(int param_1,int param_2)

{
  return *(int *)(DAT_400d0e64 + (param_1 * 2 + param_2) * 8) != DAT_400d0e68;
}



// Function at 0x400e3ae0

int FUN_400e3ae0(uint param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined1 in_PRID;
  
  iVar1 = DAT_400d0e68;
  if ((param_1 < 0x20) && (*(byte *)(DAT_400d0e6c + param_1) < 4)) {
    uVar4 = rsr(in_PRID);
    iVar5 = (uVar4 >> 0xd & 1) + param_1 * 2;
    piVar3 = (int *)(iVar5 * 8 + DAT_400d0e64);
    iVar2 = *piVar3;
    if (param_2 == 0) {
      *piVar3 = DAT_400d0e68;
      piVar3[1] = iVar5;
      memw();
    }
    else {
      *piVar3 = param_2;
      piVar3[1] = param_3;
    }
    if (iVar2 != iVar1) {
      return iVar2;
    }
    memw();
  }
  return 0;
}



// Function at 0x400e3c68

undefined4 FUN_400e3c68(int *param_1,int *param_2)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0x103;
  if ((*DAT_400d0e84 != 0) && (uVar4 = 0x102, param_1 != (int *)0x0)) {
    iVar3 = *param_1;
    if ((iVar3 == 0) || (param_2 == (int *)0x0 || iVar3 == 0)) {
      uVar4 = 0x102;
    }
    else {
      uVar4 = 0x102;
      if (param_1[2] == 0) {
        iVar1 = func_0x4008dc54(1,0x20);
        uVar4 = 0x101;
        if (iVar1 != 0) {
          *(int *)(iVar1 + 0x10) = iVar3;
          iVar3 = param_1[4];
          *(int *)(iVar1 + 0x14) = param_1[1];
          uVar2 = 2;
          if ((char)iVar3 == '\0') {
            uVar2 = 0;
          }
          *(undefined1 *)(iVar1 + 0xf) = uVar2;
          memw();
          *param_2 = iVar1;
          uVar4 = 0;
        }
      }
    }
  }
  memw();
  return uVar4;
}



// Function at 0x400e3cc8

undefined4 FUN_400e3cc8(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar2 = 0x102;
  if (param_1 != (int *)0x0) {
    uVar2 = 0x103;
    if (*param_1 == 0 && param_1[1] == 0) {
      uVar3 = func_0x40084ac8();
      func_0x400847a4(0);
      *(byte *)((int)param_1 + 0xf) = *(byte *)((int)param_1 + 0xf) & 0xfe;
      uVar1 = DAT_400d025c;
      memw();
      param_1[4] = DAT_400d0e7c;
      param_1[3] = param_1[3] & uVar1;
      *(undefined8 *)param_1 = uVar3;
      param_1[2] = 0;
      memw();
      func_0x400847bc(param_1,0);
      func_0x40084834(0);
      uVar2 = 0;
    }
  }
  return uVar2;
}



// Function at 0x400e3d24

undefined4 FUN_400e3d24(void)

{
  FUN_400e3e40();
  FUN_400e3df8();
  return 0;
}



// Function at 0x400e3d88

void FUN_400e3d88(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 auStack_2c [4];
  undefined4 uStack_28;
  
  iVar1 = DAT_400d0e98;
  if (*(int *)(param_1 + 4) != DAT_400d0e98) {
    func_0x40086818(param_1,0,0x14);
    *(int *)(param_1 + 4) = iVar1;
  }
  if (*(int *)(param_1 + 0x10) == 0) {
    memw();
    func_0x40086818(auStack_2c,0,0xc);
    uStack_28 = DAT_400d0e9c;
    memw();
    uStack_34 = param_2;
    uStack_30 = param_3;
    iVar1 = FUN_400e3c68(&uStack_34,param_1 + 0x10);
    if (iVar1 != 0) {
      func_0x40088988(iVar1,DAT_400d0ea8,0x45,DAT_400d0ea4,DAT_400d0ea0);
    }
  }
  return;
}



// Function at 0x400e3dd8

void FUN_400e3dd8(int param_1)

{
  if (*(int *)(param_1 + 4) == DAT_400d0e98) {
    FUN_400e3cc8(*(undefined4 *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 4) = 0;
  }
  memw();
  return;
}



// Function at 0x400e3df8

void FUN_400e3df8(void)

{
  uint *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  uVar6 = FUN_400e31b0();
  uVar3 = (uint)uVar6 - *DAT_400d0eac;
  iVar4 = DAT_400d0eac[1];
  uVar7 = func_0x40084ac8();
  puVar1 = DAT_400d0eb0;
  uVar5 = uVar3 - (int)uVar7;
  *DAT_400d0eb0 = uVar5;
  puVar2 = PTR_FUN_400d0eb4;
  puVar1[1] = ((((int)((ulonglong)uVar6 >> 0x20) - iVar4) - (uint)((uint)uVar6 < uVar3)) -
              (int)((ulonglong)uVar7 >> 0x20)) - (uint)(uVar3 < uVar5);
  memw();
  FUN_400f8b38(puVar2);
  return;
}



// Function at 0x400e3e40

void FUN_400e3e40(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  
  FUN_400da230(8);
  puVar2 = DAT_400d0ebc;
  puVar1 = DAT_400d0eb8;
  memw();
  *DAT_400d0eb8 = 0;
  memw();
  *puVar2 = 0;
  puVar2 = DAT_400d0ec4;
  memw();
  *DAT_400d0ec0 = 0;
  memw();
  *puVar2 = 0xffffffff;
  memw();
  *DAT_400d0ec8 = 0xffffffff;
  memw();
  *DAT_400d0ecc = 1;
  memw();
  memw();
  *DAT_400d0ed0 = *DAT_400d0ed0 | 8;
  memw();
  memw();
  *puVar1 = *puVar1 & DAT_400d0ed4 | DAT_400d0ed8;
  memw();
  memw();
  *puVar1 = *puVar1 | DAT_400d0edc;
  memw();
  return;
}



// Function at 0x400e3ebc

int FUN_400e3ebc(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  *DAT_400d0ee0 = param_1;
  puVar1 = DAT_400d0ee4;
  memw();
  iVar2 = FUN_400e383c(0x11,DAT_400d0eec,DAT_400d0ee8,0,DAT_400d0ee4);
  if (iVar2 == 0) {
    memw();
    memw();
    *DAT_400d0ef8 = *DAT_400d0ef8 | 8;
    memw();
    iVar2 = func_0x40084388();
    func_0x40084be0((int)((longlong)iVar2 * (longlong)DAT_400d02e4 >> 0x32) - (iVar2 >> 0x1f));
    iVar2 = FUN_400e326c();
    memw();
    memw();
    *DAT_400d0efc = iVar2 << 7 | *DAT_400d0efc & 0x3f;
    memw();
    iVar2 = func_0x400844dc(*puVar1);
    if (iVar2 != 0) {
      func_0x40088988(iVar2,DAT_400d0f08,0xff,DAT_400d0f04,DAT_400d0f00);
      iVar2 = DAT_400d0f0c;
      iVar4 = func_0x40089334(1,DAT_400d0f0c);
      if (iVar4 == iVar2) goto LAB_400e3f80;
      uVar6 = 0x174;
      uVar3 = DAT_400d0f10;
      while( true ) {
        func_0x4008dacc(DAT_400d0f18,uVar6,DAT_400d0f14,uVar3);
LAB_400e3f80:
        iVar2 = DAT_400d0f1c;
        iVar5 = func_0x40089334(4,DAT_400d0f1c);
        if (iVar5 == iVar2) break;
        uVar6 = 0x176;
        uVar3 = DAT_400d0f20;
      }
      *DAT_400d0f24 = iVar5;
      *DAT_400d0f28 = iVar5;
      *DAT_400d0f2c = iVar5;
      *DAT_400d0f30 = iVar4;
      memw();
      return iVar4;
    }
  }
  else if (*DAT_400d0920 != 0) {
    uVar3 = func_0x4008d9f8();
    (*DAT_400d092c)(DAT_400d0ef4,uVar3,DAT_400d0ef0,iVar2);
  }
  return iVar2;
}



// Function at 0x400e3fb8

void FUN_400e3fb8(undefined4 param_1)

{
  FUN_400e3ffc(param_1,0);
  return;
}



// Function at 0x400e3ffc

/* WARNING: Removing unreachable block (ram,0x400e4036) */

void FUN_400e3ffc(void)

{
  undefined4 uVar1;
  ulonglong *puVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  longlong lVar13;
  ulonglong uVar14;
  
  lVar13 = func_0x4008da40();
  puVar2 = DAT_400d0f48;
  cust0();
  if (lVar13 != 0) {
    uVar14 = FUN_400e419c();
    if (*puVar2 <= uVar14) {
      if ((int)*puVar2 == 0 && *(int *)((int)puVar2 + 4) == 0) goto LAB_400e4024;
      uVar14 = FUN_400e419c();
      uVar10 = (uint)(uVar14 >> 6);
      iVar4 = (int)((uVar14 >> 6) >> 0x20);
      uVar12 = *(uint *)((int)puVar2 + 4) << 0x1a | (uint)*puVar2 >> 6;
      uVar6 = uVar10 - uVar12;
      uVar11 = *(uint *)((int)puVar2 + 4) >> 6;
      iVar8 = (iVar4 - uVar11) - (uint)(uVar10 < uVar6);
      if ((iVar8 < 1) && ((iVar8 != 0 || (uVar6 == 0)))) goto LAB_400e4024;
      *(int *)((int)puVar2 + 4) = (int)(uVar14 >> 0x20);
      puVar3 = DAT_400d0f4c;
      *(int *)puVar2 = (int)uVar14;
      uVar1 = DAT_400d0028;
      uVar7 = puVar3[1];
      uVar5 = *puVar3;
      if ((int)uVar7 < 0) {
        uVar9 = (uint)(uVar5 + uVar6 < uVar5) + uVar7 + iVar8;
        if ((int)uVar9 < 0) {
          *puVar3 = uVar5 + uVar6;
          lVar13 = lVar13 + CONCAT44(uVar11,uVar12);
          uVar6 = (uint)lVar13;
          puVar3[1] = uVar9;
          uVar10 = uVar6 - uVar10;
          lVar13 = CONCAT44(((int)((ulonglong)lVar13 >> 0x20) - iVar4) - (uint)(uVar6 < uVar10),
                            uVar10);
        }
        else {
LAB_400e4098:
          lVar13 = lVar13 + CONCAT44(uVar7,uVar5);
          *(undefined4 *)((int)puVar2 + 4) = DAT_400d0028;
          *(undefined4 *)puVar2 = uVar1;
          memw();
        }
      }
      else {
        uVar11 = uVar5 - uVar6;
        uVar10 = (uVar7 - iVar8) - (uint)(uVar5 < uVar11);
        if (((int)uVar10 < 1) && ((uVar10 != 0 || (uVar11 == 0)))) goto LAB_400e4098;
        *puVar3 = uVar11;
        puVar3[1] = uVar10;
        lVar13 = lVar13 + CONCAT44(iVar8,uVar6);
        memw();
      }
      memw();
      FUN_400e41bc((int)lVar13,(int)((ulonglong)lVar13 >> 0x20));
      goto LAB_400e4024;
    }
  }
  uVar1 = DAT_400d0028;
  *(undefined4 *)puVar2 = DAT_400d0028;
  *(undefined4 *)((int)puVar2 + 4) = uVar1;
LAB_400e4024:
  memw();
  return;
}



// Function at 0x400e411c

void FUN_400e411c(int *param_1)

{
  longlong lVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined8 uVar9;
  
  uVar3 = DAT_400d0f50;
  func_0x40085334(DAT_400d0f50);
  piVar2 = DAT_400d0f48;
  if (*DAT_400d0f48 != 0 || DAT_400d0f48[1] != 0) {
    func_0x400e4004();
    iVar4 = DAT_400d0028;
    *piVar2 = DAT_400d0028;
    piVar2[1] = iVar4;
  }
  memw();
  func_0x40085374(uVar3);
  iVar8 = *param_1;
  uVar6 = iVar8 * DAT_400d01e4;
  lVar1 = (longlong)DAT_400d01e4;
  iVar4 = param_1[1];
  uVar5 = uVar6 + iVar4;
  uVar9 = FUN_400e419c();
  uVar7 = uVar5 - (int)uVar9;
  FUN_400e41bc(uVar7,(((uint)(uVar5 < uVar6) +
                      (int)((ulonglong)(iVar8 * lVar1) >> 0x20) + (iVar4 >> 0x1f)) -
                     (int)((ulonglong)uVar9 >> 0x20)) - (uint)(uVar5 < uVar7));
  return;
}



// Function at 0x400e4184

undefined4 FUN_400e4184(int param_1)

{
  if (param_1 != 0) {
    FUN_400e411c(param_1);
  }
  return 0;
}



// Function at 0x400e4194

void FUN_400e4194(void)

{
  FUN_400e4294();
  return;
}



// Function at 0x400e419c

void FUN_400e419c(void)

{
  func_0x40084a40();
  return;
}



// Function at 0x400e41bc

void FUN_400e41bc(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = DAT_400d0f58;
  func_0x40085334(DAT_400d0f58);
  memw();
  *DAT_400d0f5c = param_1;
  memw();
  *DAT_400d0f60 = param_2;
  memw();
  func_0x40085374(uVar1);
  return;
}



// Function at 0x400e41e4

undefined8 FUN_400e41e4(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = DAT_400d0f58;
  func_0x40085334(DAT_400d0f58);
  memw();
  uVar2 = *DAT_400d0f5c;
  memw();
  uVar3 = *DAT_400d0f60;
  func_0x40085374(uVar1);
  return CONCAT44(uVar3,uVar2);
}



// Function at 0x400e4208

void FUN_400e4208(void)

{
  uint *puVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar3 = FUN_400e31b0();
  uVar4 = func_0x40084a40();
  puVar1 = DAT_400d0f54;
  uVar2 = (uint)uVar3 - (int)uVar4;
  *DAT_400d0f54 = uVar2;
  puVar1[1] = ((int)((ulonglong)uVar3 >> 0x20) - (int)((ulonglong)uVar4 >> 0x20)) -
              (uint)((uint)uVar3 < uVar2);
  memw();
  return;
}



// Function at 0x400e4234

void FUN_400e4234(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 auStack_28 [40];
  
  FUN_400edcc0(auStack_28,0);
  FUN_400e4184(auStack_28,0);
  uVar4 = FUN_400e31b0();
  uVar5 = func_0x40084a40();
  uVar6 = FUN_400e41e4();
  uVar1 = (uint)uVar4 - (int)uVar5;
  uVar2 = *DAT_400d0f54 - uVar1;
  uVar3 = uVar2 + (int)uVar6;
  FUN_400e41bc(uVar3,(uint)(uVar3 < uVar2) +
                     ((DAT_400d0f54[1] -
                      (((int)((ulonglong)uVar4 >> 0x20) - (int)((ulonglong)uVar5 >> 0x20)) -
                      (uint)((uint)uVar4 < uVar1))) - (uint)(*DAT_400d0f54 < uVar2)) +
                     (int)((ulonglong)uVar6 >> 0x20));
  return;
}



// Function at 0x400e4294

void FUN_400e4294(void)

{
  FUN_400e4208();
  return;
}



// Function at 0x400e429c

int FUN_400e429c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_400e2e64(param_1,param_2);
  if (iVar1 == 0x104) {
    iVar1 = 0;
  }
  return iVar1;
}



// Function at 0x400e42b8

undefined4 FUN_400e42b8(uint param_1)

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  puVar2 = DAT_400d0f68;
  if ((*DAT_400d0f64 == 0) && ((param_1 & *DAT_400d0f68) != 0)) {
    bVar1 = true;
    uVar6 = 0;
    iVar7 = 0;
    puVar5 = DAT_400d0f68;
    do {
      uVar8 = *puVar5;
      *puVar5 = (param_1 ^ 0xffffffff) & uVar8;
      if ((uVar8 != 0) && (uVar8 == (param_1 & uVar8))) {
        if (bVar1) {
          uVar6 = puVar5[1];
        }
        if (iVar7 == 6) goto LAB_400e4328;
        uVar8 = puVar5[3];
        if (((uVar8 == 0) || (uVar8 != (param_1 & uVar8))) || (puVar5[2] != puVar5[4])) {
          iVar3 = FUN_400e429c(uVar6);
          if (iVar3 == 0) goto LAB_400e4344;
          uVar4 = 0x556;
          goto LAB_400e4322;
        }
        bVar1 = false;
      }
      while( true ) {
        iVar7 = iVar7 + 1;
        puVar5 = puVar5 + 3;
        if (iVar7 != 7) break;
        if (param_1 != 3) {
LAB_400e42f2:
          uVar4 = 0;
          goto LAB_400e42f4;
        }
        if ((DAT_400d0f78 == DAT_400d0f7c) || (iVar3 = FUN_400e429c(), iVar3 == 0)) {
          if ((DAT_400d0f80 == DAT_400d0f84) || (iVar3 = FUN_400e429c(), iVar3 == 0))
          goto LAB_400e42f2;
          uVar4 = 0x56c;
        }
        else {
          uVar4 = 0x566;
        }
LAB_400e4322:
        while( true ) {
          func_0x40088988(iVar3,DAT_400d0f74,uVar4,DAT_400d0f70,DAT_400d0f6c);
LAB_400e4328:
          iVar3 = FUN_400e429c(uVar6,puVar2[0x14]);
          if (iVar3 == 0) break;
          uVar4 = 0x55c;
        }
LAB_400e4344:
        bVar1 = true;
      }
    } while( true );
  }
  uVar4 = 0x103;
LAB_400e42f4:
  memw();
  return uVar4;
}



// Function at 0x400e438c

undefined4 FUN_400e438c(int param_1,byte *param_2,undefined1 param_3,int param_4,undefined4 param_5)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  uVar1 = 0x101;
  if ((int)(*param_2 + 2 + param_4) < 0x41) {
    puVar2 = (undefined1 *)(param_1 + (uint)*param_2);
    puVar2[1] = (char)param_4;
    *puVar2 = param_3;
    memw();
    memw();
    func_0x400866b8(puVar2 + 2,param_5,param_4);
    uVar1 = 0;
    *param_2 = (char)param_4 + '\x02' + *param_2;
    memw();
  }
  memw();
  return uVar1;
}



// Function at 0x400e43d0

undefined4
FUN_400e43d0(uint param_1,undefined4 param_2,undefined4 param_3,byte *param_4,undefined4 param_5,
            undefined4 param_6,int param_7,int param_8,int param_9)

{
  bool bVar1;
  byte bVar2;
  uint *puVar3;
  int iVar4;
  byte bVar5;
  undefined4 ****ppppuVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  code *pcVar10;
  int iVar11;
  byte bVar12;
  uint uVar13;
  byte bVar14;
  undefined4 uVar15;
  undefined1 uStack_b9;
  undefined4 ***pppuStack_b8;
  undefined4 uStack_b4;
  int iStack_ac;
  int iStack_a8;
  int iStack_a4;
  uint uStack_a0;
  undefined4 uStack_9c;
  undefined8 uStack_98;
  undefined1 auStack_90 [16];
  byte *pbStack_80;
  undefined1 auStack_7c [64];
  undefined1 uStack_3c;
  undefined1 auStack_3b [23];
  int iStack_24;
  
  puVar3 = DAT_400d0f88;
  uVar15 = 0x105;
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  uStack_98 = CONCAT44(uStack_98._4_4_,(undefined4)uStack_98);
  if (((char)DAT_400d0f88[3] != '\0') &&
     (uStack_98 = CONCAT44(uStack_98._4_4_,(undefined4)uStack_98), (param_1 & *DAT_400d0f88) != 0))
  {
    memw();
    func_0x40086818(&uStack_98,0,0x70);
    iStack_ac = param_7;
    iStack_a8 = param_8;
    iStack_a4 = param_9;
    memw();
    uStack_a0 = param_1;
    uStack_9c = param_2;
    uStack_98 = FUN_400e4ae8();
    memw();
    func_0x40086c24(auStack_90,param_3,0x10);
    iVar4 = iStack_a8;
    iVar9 = iStack_ac;
    uStack_3c = 0x40;
    memw();
    uStack_b9 = 0;
    memw();
    iVar8 = iStack_a4;
    pbStack_80 = param_4;
    for (; *param_4 != 0; param_4 = param_4 + 1) {
      if (*param_4 == 0x25) {
        do {
          param_4 = param_4 + 1;
          if (0x10 < (byte)(*param_4 - 0x20)) break;
        } while ((DAT_400d0f8c & 1 << (*param_4 - 0x20 & 0x1f)) != 0);
        memw();
        for (; (byte)(*param_4 - 0x30) < 10; param_4 = param_4 + 1) {
        }
        if (*param_4 == 0x2e) {
          do {
            param_4 = param_4 + 1;
          } while ((byte)(*param_4 - 0x30) < 10);
        }
        bVar12 = 0;
        bVar5 = 0;
        for (; bVar2 = *param_4, bVar2 != 0; param_4 = param_4 + 1) {
          if (bVar2 == 0x6a) {
            bVar14 = 5;
LAB_400e4538:
            bVar5 = 8;
            bVar12 = bVar14;
          }
          else if (bVar2 < 0x6b) {
            bVar14 = 8;
            if (bVar2 == 0x4c) goto LAB_400e4538;
            if (bVar2 != 0x68) break;
            bVar1 = bVar12 == 2;
            bVar5 = 2;
            bVar12 = 2;
            if (bVar1) {
              bVar5 = 1;
              bVar12 = 1;
            }
          }
          else {
            if (bVar2 == 0x74) {
              bVar12 = 6;
            }
            else if (bVar2 == 0x7a) {
              bVar12 = 7;
            }
            else {
              if (bVar2 != 0x6c) break;
              if (bVar12 == 3) {
                bVar14 = 4;
                goto LAB_400e4538;
              }
              bVar12 = 3;
            }
            bVar5 = 4;
          }
        }
        pppuStack_b8 = (undefined4 ****)0x0;
        uStack_b4 = 0;
        if (bVar2 == 100) {
LAB_400e46b1:
          if (bVar12 == 3) {
            iVar11 = iVar8 + 4;
            iVar7 = iVar4;
            if ((0x18 < iVar11) && (iVar7 = iVar9, iVar8 < 0x19)) {
              iVar11 = 0x24;
            }
            pppuStack_b8 = *(undefined4 ****)(iVar7 + iVar11 + -4);
            uVar15 = 3;
LAB_400e478e:
            ppppuVar6 = &pppuStack_b8;
            iVar8 = iVar11;
            goto LAB_400e4798;
          }
          if (bVar12 < 4) {
            iVar11 = iVar8 + 4;
            if (bVar12 == 1) {
              iVar7 = iVar4;
              if ((0x18 < iVar11) && (iVar7 = iVar9, iVar8 < 0x19)) {
                iVar11 = 0x24;
              }
              uVar15 = 0;
              pppuStack_b8 = (undefined4 ***)(*(uint *)(iVar7 + iVar11 + -4) & 0xff);
              memw();
              goto LAB_400e472d;
            }
            if (bVar12 < 2) goto LAB_400e46c4;
            iVar7 = iVar4;
            if ((0x18 < iVar11) && (iVar7 = iVar9, iVar8 < 0x19)) {
              iVar11 = 0x24;
            }
            uVar15 = 1;
            pppuStack_b8 = (undefined4 ***)(*(uint *)(iVar7 + iVar11 + -4) & 0xffff);
            memw();
LAB_400e475d:
            ppppuVar6 = &pppuStack_b8;
            memw();
            iVar8 = iVar11;
            goto LAB_400e4798;
          }
          if (bVar12 == 5) {
            uVar13 = iVar8 + 7U & 0xfffffff8;
            iVar8 = uVar13 + 8;
            iVar7 = iVar4;
            if ((0x18 < iVar8) && (iVar7 = iVar9, (int)uVar13 < 0x19)) {
              iVar8 = 0x28;
            }
            uStack_b4 = *(undefined4 *)(iVar7 + iVar8 + -4);
            uVar15 = 5;
            pppuStack_b8 = *(undefined4 ****)(iVar7 + iVar8 + -8);
          }
          else {
            if (4 < bVar12) {
              if (bVar12 == 6) {
                iVar11 = iVar8 + 4;
                iVar7 = iVar4;
                if ((0x18 < iVar11) && (iVar7 = iVar9, iVar8 < 0x19)) {
                  iVar11 = 0x24;
                }
                pppuStack_b8 = *(undefined4 ****)(iVar7 + iVar11 + -4);
                uVar15 = 6;
                memw();
                goto LAB_400e475d;
              }
              if (bVar12 != 7) goto LAB_400e4709;
LAB_400e46c4:
              iVar11 = iVar8 + 4;
              iVar7 = iVar4;
              if ((0x18 < iVar11) && (iVar7 = iVar9, iVar8 < 0x19)) {
                iVar11 = 0x24;
              }
              pppuStack_b8 = *(undefined4 ****)(iVar7 + iVar11 + -4);
              ppppuVar6 = &pppuStack_b8;
              bVar5 = 4;
              uVar15 = 2;
              goto LAB_400e46e3;
            }
            uVar13 = iVar8 + 7U & 0xfffffff8;
            iVar8 = uVar13 + 8;
            iVar7 = iVar4;
            if ((0x18 < iVar8) && (iVar7 = iVar9, (int)uVar13 < 0x19)) {
              iVar8 = 0x28;
            }
            uStack_b4 = *(undefined4 *)(iVar7 + iVar8 + -4);
            uVar15 = 4;
            pppuStack_b8 = *(undefined4 ****)(iVar7 + iVar8 + -8);
LAB_400e47cf:
            memw();
          }
LAB_400e4814:
          memw();
          iVar7 = FUN_400e438c(auStack_7c,&uStack_b9,uVar15,bVar5,&pppuStack_b8);
        }
        else {
          if (bVar2 < 0x65) {
            if (bVar2 == 0x4f) {
LAB_400e45ac:
              iVar11 = iVar8 + 4;
              iVar7 = iVar4;
              if ((0x18 < iVar11) && (iVar7 = iVar9, iVar8 < 0x19)) {
                iVar11 = 0x24;
              }
              pppuStack_b8 = *(undefined4 ****)(iVar7 + iVar11 + -4);
              bVar5 = 4;
              uVar15 = 0xb;
              memw();
              goto LAB_400e478e;
            }
            if (0x4f < bVar2) {
              if (bVar2 == 0x58) goto LAB_400e4885;
              if (bVar2 < 0x59) {
                if (bVar2 == 0x55) goto LAB_400e45ac;
              }
              else {
                if (bVar2 == 0x61) goto LAB_400e4551;
                if (bVar2 == 99) {
                  iVar11 = iVar8 + 4;
                  iVar7 = iVar4;
                  if ((0x18 < iVar11) && (iVar7 = iVar9, iVar8 < 0x19)) {
                    iVar11 = 0x24;
                  }
                  bVar5 = 1;
                  uVar15 = 0;
                  pppuStack_b8 = (undefined4 ***)(*(uint *)(iVar7 + iVar11 + -4) & 0xff);
                  memw();
                  memw();
                  goto LAB_400e469f;
                }
              }
              goto LAB_400e44ec;
            }
            if (bVar2 != 0x44) {
              if (0x44 < bVar2) {
                bVar14 = 0x47;
                goto LAB_400e454e;
              }
              if (bVar2 != 0x41) goto LAB_400e44ec;
LAB_400e4551:
              if (bVar12 == 3) {
LAB_400e455d:
                uVar13 = iVar8 + 7U & 0xfffffff8;
                iVar8 = uVar13 + 8;
                iVar7 = iVar4;
                if ((0x18 < iVar8) && (iVar7 = iVar9, (int)uVar13 < 0x19)) {
                  iVar8 = 0x28;
                }
                uStack_b4 = *(undefined4 *)(iVar7 + iVar8 + -4);
                pppuStack_b8 = *(undefined4 ****)(iVar7 + iVar8 + -8);
                bVar5 = 8;
                uVar15 = 0xe;
                memw();
                goto LAB_400e4814;
              }
              if (bVar12 != 8) {
                if (bVar12 != 0) goto LAB_400e4709;
                goto LAB_400e455d;
              }
              uVar13 = iVar8 + 7U & 0xfffffff8;
              iVar8 = uVar13 + 8;
              iVar7 = iVar4;
              if ((0x18 < iVar8) && (iVar7 = iVar9, (int)uVar13 < 0x19)) {
                iVar8 = 0x28;
              }
              uStack_b4 = *(undefined4 *)(iVar7 + iVar8 + -4);
              uVar15 = 0xf;
              pppuStack_b8 = *(undefined4 ****)(iVar7 + iVar8 + -8);
              memw();
LAB_400e4991:
              memw();
              goto LAB_400e4814;
            }
            iVar11 = iVar8 + 4;
            iVar7 = iVar4;
            if ((0x18 < iVar11) && (iVar7 = iVar9, iVar8 < 0x19)) {
              iVar11 = 0x24;
            }
            pppuStack_b8 = *(undefined4 ****)(iVar7 + iVar11 + -4);
            bVar5 = 4;
            uVar15 = 3;
LAB_400e469f:
            ppppuVar6 = &pppuStack_b8;
            memw();
            iVar8 = iVar11;
          }
          else if (bVar2 < 0x71) {
            if (bVar2 < 0x6f) {
              if (bVar2 != 0x69) {
                if (bVar2 < 0x6a) {
                  bVar14 = 0x67;
LAB_400e454e:
                  if (bVar2 <= bVar14) goto LAB_400e4551;
                }
LAB_400e44ec:
                iVar7 = iVar8 + 4;
                if ((0x18 < iVar7) && (iVar8 < 0x19)) {
                  iVar7 = 0x24;
                }
                iVar8 = iVar7;
                memw();
                goto LAB_400e4709;
              }
              goto LAB_400e46b1;
            }
LAB_400e4885:
            if (bVar12 == 3) {
              iVar11 = iVar8 + 4;
              iVar7 = iVar4;
              if ((0x18 < iVar11) && (iVar7 = iVar9, iVar8 < 0x19)) {
                iVar11 = 0x24;
              }
              pppuStack_b8 = *(undefined4 ****)(iVar7 + iVar11 + -4);
              uVar15 = 10;
              memw();
              goto LAB_400e475d;
            }
            if (bVar12 < 4) {
              iVar11 = iVar8 + 4;
              if (bVar12 == 1) {
                iVar7 = iVar4;
                if ((0x18 < iVar11) && (iVar7 = iVar9, iVar8 < 0x19)) {
                  iVar11 = 0x24;
                }
                ppppuVar6 = &pppuStack_b8;
                uVar15 = 7;
                pppuStack_b8 = (undefined4 ***)(*(uint *)(iVar7 + iVar11 + -4) & 0xff);
                memw();
                memw();
                goto LAB_400e46e3;
              }
              if (bVar12 < 2) {
LAB_400e489c:
                iVar11 = iVar8 + 4;
                iVar7 = iVar4;
                if ((0x18 < iVar11) && (iVar7 = iVar9, iVar8 < 0x19)) {
                  iVar11 = 0x24;
                }
                pppuStack_b8 = *(undefined4 ****)(iVar7 + iVar11 + -4);
                bVar5 = 4;
                uVar15 = 9;
                memw();
                goto LAB_400e469f;
              }
              iVar7 = iVar4;
              if ((0x18 < iVar11) && (iVar7 = iVar9, iVar8 < 0x19)) {
                iVar11 = 0x24;
              }
              uVar15 = 8;
              pppuStack_b8 = (undefined4 ***)(*(uint *)(iVar7 + iVar11 + -4) & 0xffff);
              memw();
              memw();
            }
            else {
              if (bVar12 == 5) {
                uVar13 = iVar8 + 7U & 0xfffffff8;
                iVar8 = uVar13 + 8;
                iVar7 = iVar4;
                if ((0x18 < iVar8) && (iVar7 = iVar9, (int)uVar13 < 0x19)) {
                  iVar8 = 0x28;
                }
                uStack_b4 = *(undefined4 *)(iVar7 + iVar8 + -4);
                uVar15 = 0xc;
                pppuStack_b8 = *(undefined4 ****)(iVar7 + iVar8 + -8);
                memw();
                goto LAB_400e47cf;
              }
              if (bVar12 < 5) {
                uVar13 = iVar8 + 7U & 0xfffffff8;
                iVar8 = uVar13 + 8;
                iVar7 = iVar4;
                if ((0x18 < iVar8) && (iVar7 = iVar9, (int)uVar13 < 0x19)) {
                  iVar8 = 0x28;
                }
                uStack_b4 = *(undefined4 *)(iVar7 + iVar8 + -4);
                uVar15 = 0xb;
                pppuStack_b8 = *(undefined4 ****)(iVar7 + iVar8 + -8);
                goto LAB_400e4991;
              }
              if (bVar12 == 6) goto LAB_400e489c;
              if (bVar12 != 7) goto LAB_400e4709;
              iVar11 = iVar8 + 4;
              iVar7 = iVar4;
              if ((0x18 < iVar11) && (iVar7 = iVar9, iVar8 < 0x19)) {
                iVar11 = 0x24;
              }
              pppuStack_b8 = *(undefined4 ****)(iVar7 + iVar11 + -4);
              uVar15 = 0xd;
              memw();
            }
LAB_400e472d:
            ppppuVar6 = &pppuStack_b8;
            memw();
            iVar8 = iVar11;
          }
          else {
            if ((bVar2 == 0x75) || (bVar2 == 0x78)) goto LAB_400e4885;
            if (bVar2 != 0x73) goto LAB_400e44ec;
            iVar11 = iVar8 + 4;
            iVar7 = iVar4;
            if ((0x18 < iVar11) && (iVar7 = iVar9, iVar8 < 0x19)) {
              iVar11 = 0x24;
            }
            ppppuVar6 = *(undefined4 *****)(iVar7 + iVar11 + -4);
            bVar5 = 0;
            pppuStack_b8 = ppppuVar6;
            if (ppppuVar6 != (undefined4 ****)0x0) {
              memw();
              bVar5 = func_0x40086c6c(ppppuVar6);
            }
            uVar15 = 0x10;
LAB_400e46e3:
            memw();
            iVar8 = iVar11;
          }
LAB_400e4798:
          memw();
          iVar7 = FUN_400e438c(auStack_7c,&uStack_b9,uVar15,bVar5,ppppuVar6);
        }
        if (iVar7 != 0) break;
      }
LAB_400e4709:
    }
    uStack_3c = uStack_b9;
    memw();
    memw();
    iVar9 = func_0x4008a828(0);
    if (iVar9 != 0) {
      func_0x40086c24(auStack_3b,iVar9,0x10);
    }
    uVar15 = 0xffffffff;
    pcVar10 = (code *)puVar3[1];
    if (pcVar10 != (code *)0x0) {
      uVar15 = (*pcVar10)(&uStack_a0,0x78,puVar3[2]);
    }
  }
  memw();
  memw();
  if (iStack_24 != *DAT_400d0098) {
    uVar15 = func_0x400831d4();
    return uVar15;
  }
  return uVar15;
}



// Function at 0x400e4a38

void FUN_400e4a38(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_400f92c8(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



// Function at 0x400e4a50

void FUN_400e4a50(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  uint unaff_retaddr;
  int iVar1;
  uint uVar2;
  undefined1 auStack_70 [12];
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined1 *puStack_44;
  undefined1 *puStack_40;
  undefined4 uStack_3c;
  undefined1 *puStack_38;
  undefined1 *puStack_34;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined4 uStack_24;
  undefined1 auStack_20 [32];
  
  puStack_40 = auStack_70;
  puStack_44 = auStack_20;
  uStack_3c = 0xc;
  memw();
  uStack_64 = param_4;
  uStack_60 = param_5;
  uStack_5c = param_6;
  iVar1 = func_0x40086a70(param_2,DAT_400d0f90);
  if (iVar1 != 0) {
    uVar2 = unaff_retaddr & 0x3fffffff | DAT_400d0f94 & 0xc0000000;
    if ((int)uVar2 < 0) {
      uVar2 = uVar2 & DAT_400d0280 | DAT_400d0088;
    }
    puStack_38 = puStack_44;
    puStack_34 = puStack_40;
    uStack_30 = uStack_3c;
    if ((param_1 == 1) || (param_1 == 2)) {
      puStack_2c = puStack_44;
      puStack_28 = puStack_40;
      uStack_24 = uStack_3c;
      memw();
      FUN_400e43d0(param_1,uVar2 - 3,param_2,param_3);
    }
  }
  FUN_400e4a38(param_1,param_2,param_3,puStack_44,puStack_40,uStack_3c);
  return;
}



// Function at 0x400e4ae8

undefined8 FUN_400e4ae8(void)

{
  int iVar1;
  uint uVar2;
  int iStack_28;
  int iStack_24;
  
  iVar1 = FUN_400edcc0(&iStack_28,0);
  if (iVar1 == 0) {
    uVar2 = iStack_28 * DAT_400d01e4 + iStack_24;
    iVar1 = (uint)(uVar2 < (uint)(iStack_28 * DAT_400d01e4)) +
            (int)((ulonglong)((longlong)iStack_28 * (longlong)DAT_400d01e4) >> 0x20) +
            (iStack_24 >> 0x1f);
  }
  else {
    uVar2 = func_0x4008d9f8();
    iVar1 = (int)((ulonglong)uVar2 * 1000 >> 0x20);
    uVar2 = uVar2 * 1000;
  }
  return CONCAT44(iVar1,uVar2);
}



// Function at 0x400e4b40

int FUN_400e4b40(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_2 == 0 || param_3 == 0) || (param_1 == 0 || (param_2 == 0 || param_3 == 0))) {
    iVar2 = 0x102;
  }
  else {
    while( true ) {
      uVar1 = FUN_400f8270(param_3,8);
      func_0x40086818(param_2,0,uVar1);
      iVar2 = FUN_400e4b98(param_1,param_2,param_3,PTR_FUN_400d0f9c);
      if (iVar2 != DAT_400d0fa0) break;
      func_0x4008a9fc(1);
    }
  }
  return iVar2;
}



// Function at 0x400e4b8c

undefined4 FUN_400e4b8c(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400f8248();
  return uVar1;
}



// Function at 0x400e4b98

void FUN_400e4b98(undefined4 *param_1,undefined4 param_2,uint param_3,code *param_4)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int aiStack_24 [9];
  
  aiStack_24[0] = 0;
  memw();
  uVar3 = FUN_400f8250(param_1);
  if (param_3 != 0) {
    uVar3 = (uVar3 < param_3) * uVar3 + (uVar3 >= param_3) * param_3;
  }
  memw();
  puVar6 = (undefined4 *)*DAT_400d0fa8;
  puVar4 = (undefined1 *)0x0;
  do {
    if (((puVar4 != (undefined1 *)0x0) || ((int)uVar3 <= aiStack_24[0])) ||
       (puVar4 = (undefined1 *)*param_1, puVar4 == (undefined1 *)0x0)) {
      memw();
      param_1 = DAT_400d0fa8;
      if (((puVar4 == (undefined1 *)0x0) &&
          ((param_4 == (code *)PTR_LAB_400d0fb4 ||
           (param_4 = (code *)(uint)(param_4 == (code *)PTR_FUN_400d0f9c),
           param_1 = (undefined4 *)PTR_FUN_400d0f9c, param_4 != (code *)0x0)))) &&
         ((param_1 = puVar6, puVar6 != (undefined4 *)*DAT_400d0fa8 || (((uint)puVar6 & 1) != 0)))) {
        puVar4 = DAT_400d0fa0;
      }
      if (aiStack_24[0] <= (int)uVar3) {
        return;
      }
      memw();
      func_0x4008dacc(DAT_400d0fc0,0x58,DAT_400d0fbc,DAT_400d0fb8);
    }
    uVar7 = (uint)(byte)puVar4[1] + (uint)*(ushort *)(puVar4 + 2);
    if (((uVar7 < 0x101) && ((iVar8 = FUN_400e4ea4(*puVar4), iVar8 != 1 || (uVar7 < 0xc1)))) &&
       ((iVar8 != 2 || (uVar7 < 0x81)))) {
      puVar4 = (undefined1 *)0x0;
    }
    else {
      puVar4 = DAT_400d0fa4;
      if (*DAT_400d0920 != 0) {
        uVar5 = func_0x4008d9f8();
        (*DAT_400d092c)(DAT_400d0fb0,uVar5,DAT_400d0fac);
        puVar4 = DAT_400d0fa4;
      }
    }
    iVar8 = 0;
    while( true ) {
      if ((puVar4 != (undefined1 *)0x0) || ((int)uVar3 <= aiStack_24[0])) goto LAB_400e4d08;
      puVar4 = (undefined1 *)*param_1;
      uVar7 = (uint)(byte)puVar4[1];
      iVar10 = ((int)uVar7 >> 5) + iVar8;
      uVar14 = (*(ushort *)(puVar4 + 2) + uVar7) - 1;
      uVar12 = *(ushort *)(puVar4 + 2) + uVar7 + 0x1e;
      if (-1 < (int)uVar14) {
        uVar12 = uVar14;
      }
      if ((int)uVar12 >> 5 < iVar10) break;
      uVar12 = uVar7 & 0x1f;
      if (iVar8 != 0) {
        uVar12 = 0;
      }
      iVar13 = 0;
      memw();
      iVar11 = 0;
      while ((int)uVar7 <= (int)uVar14) {
        uVar9 = uVar7 + 1;
        bVar1 = (uVar9 & 0x1f) == 0;
        iVar13 = iVar13 + 1;
        if ((bVar1) || (bVar2 = uVar7 == uVar14, uVar7 = uVar9, bVar2 || bVar1)) {
          if (iVar8 == iVar11) {
            if ((int)uVar3 < aiStack_24[0] + iVar13) {
              iVar13 = uVar3 - aiStack_24[0];
            }
            goto LAB_400e4ce5;
          }
          iVar13 = 0;
          uVar7 = uVar9;
          iVar11 = iVar11 + 1;
        }
      }
      iVar13 = 0;
LAB_400e4ce5:
      iVar8 = iVar8 + 1;
      puVar4 = (undefined1 *)(*param_4)(iVar10,*puVar4,uVar12,iVar13,param_2,aiStack_24);
    }
    puVar4 = (undefined1 *)0x0;
LAB_400e4d08:
    param_1 = param_1 + 1;
  } while( true );
}



// Function at 0x400e4d10

undefined4 FUN_400e4d10(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_1 < (int *)0x4) goto LAB_400e4d25;
  uVar1 = 0x105;
  uVar2 = DAT_400d0fc4;
  while( true ) {
    while( true ) {
      func_0x4008dacc(DAT_400d0fc0,uVar1,DAT_400d0fc8,uVar2);
LAB_400e4d25:
      param_1 = (int *)(DAT_400d0fcc + (int)param_1 * 8);
      if (param_2 <= (undefined4 *)((uint)(param_1[1] - *param_1) >> 2)) break;
      uVar1 = 0x106;
      uVar2 = DAT_400d0fd0;
    }
    param_2 = (undefined4 *)((int)param_2 * 4 + *param_1);
    param_1 = (int *)((int)param_2 + DAT_400d02a8);
    if (DAT_400d02ac < param_1) break;
    uVar1 = 0x10b;
    uVar2 = DAT_400d0fd4;
  }
  memw();
  return *param_2;
}



// Function at 0x400e4d6c

undefined4
FUN_400e4d6c(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,int param_5,
            uint *param_6)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  
  uVar2 = FUN_400e4d10(param_2,param_1);
  uVar3 = 0xffffffff;
  if (param_4 != 0x20) {
    uVar3 = (1 << 0x20 - (0x20 - (param_4 & 0x1f))) - 1;
  }
  uVar3 = uVar2 >> (param_3 & 0x1f) & uVar3;
  uVar7 = *param_6;
  uVar2 = uVar7 & DAT_400d0fd8;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffff8) + 1;
  }
  if (uVar2 != 0) {
    uVar5 = uVar7 + 7;
    if (-1 < (int)uVar7) {
      uVar5 = uVar7;
    }
    pbVar6 = (byte *)(param_5 + ((int)uVar5 >> 3));
    memw();
    bVar1 = (*DAT_400d0fdc)(uVar3,0,uVar2);
    *pbVar6 = bVar1 | *pbVar6;
    memw();
    iVar4 = 8 - uVar2;
    uVar2 = (uint)(iVar4 < (int)param_4) * iVar4 + (iVar4 >= (int)param_4) * param_4;
    param_4 = param_4 - uVar2;
    *param_6 = uVar7 + uVar2;
  }
  iVar4 = 0;
  while (0 < (int)param_4) {
    uVar7 = *param_6;
    iVar4 = iVar4 + uVar2;
    uVar2 = uVar7 + 7;
    if (-1 < (int)uVar7) {
      uVar2 = uVar7;
    }
    pbVar6 = (byte *)(param_5 + ((int)uVar2 >> 3));
    memw();
    bVar1 = (*DAT_400d0384)(uVar3,0,iVar4);
    *pbVar6 = bVar1 | *pbVar6;
    memw();
    uVar2 = ((int)param_4 < 8) * param_4 + (uint)((int)param_4 >= 8) * 8;
    param_4 = param_4 - uVar2;
    *param_6 = uVar7 + uVar2;
    memw();
  }
  memw();
  return 0;
}



// Function at 0x400e4e74

uint FUN_400e4e74(void)

{
  uint uVar1;
  
  memw();
  uVar1 = *DAT_400d0fe4 & 3;
  if ((uVar1 == 0) || (uVar1 == 3 || uVar1 == 0)) {
    uVar1 = 0;
  }
  else if (uVar1 != 1) {
    uVar1 = 2;
  }
  return uVar1;
}



// Function at 0x400e4ea4

int FUN_400e4ea4(int param_1)

{
  if (param_1 != 0) {
    param_1 = FUN_400e4e74();
  }
  return param_1;
}



// Function at 0x400e4eb4

undefined4 FUN_400e4eb4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  func_0x4008a674();
  uVar1 = func_0x4008a698();
  param_1 = param_1 * 4;
  puVar3 = (undefined4 *)(DAT_400d0fe8 + param_1);
  uVar2 = func_0x4008a698(*puVar3);
  if (uVar2 < uVar1) {
    func_0x4008a6bc(*puVar3,uVar1);
  }
  puVar3 = (undefined4 *)(DAT_400d0fec + param_1);
  memw();
  func_0x400896ec(*puVar3,0xffffffff);
  func_0x4008a6bc(*(undefined4 *)(DAT_400d0fe8 + param_1),uVar1);
  memw();
  *(undefined4 *)(DAT_400d0ff0 + param_1) = param_2;
  memw();
  *(undefined4 *)(DAT_400d0ff4 + param_1) = param_3;
  memw();
  *(undefined4 *)(DAT_400d0ff8 + param_1) = param_4;
  memw();
  func_0x40089194(*(undefined4 *)(DAT_400d0ffc + param_1),0,0);
  func_0x400896ec(*(undefined4 *)(DAT_400d1000 + param_1),0xffffffff);
  func_0x40089194(*puVar3,0,0);
  return 0;
}



// Function at 0x400e4f44

void FUN_400e4f44(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_33 [15];
  int iStack_24;
  
  piVar2 = DAT_400d0098;
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  iVar3 = 0;
  iVar5 = 0;
  do {
    while( true ) {
      memw();
      FUN_400ea8dc(auStack_33,0xf,DAT_400d1004,iVar5);
      uVar4 = func_0x400893a4(1);
      *(undefined4 *)(iVar3 + DAT_400d0fec) = uVar4;
      memw();
      uVar4 = func_0x400890ac(1,0,3);
      *(undefined4 *)(iVar3 + DAT_400d1000) = uVar4;
      memw();
      uVar4 = func_0x400890ac(1,0,3);
      iVar6 = DAT_400d0fe8 + iVar3;
      *(undefined4 *)(iVar3 + DAT_400d0ffc) = uVar4;
      memw();
      iVar6 = func_0x40089f48(DAT_400d1008,auStack_33,0x400,iVar5,0x18,iVar6,iVar5);
      if (iVar6 == 1) break;
      func_0x4008dacc(DAT_400d1014,0x73,DAT_400d1010,DAT_400d100c);
      iVar5 = 1;
    }
    iVar3 = iVar3 + 4;
    bVar1 = iVar5 != 1;
    iVar5 = 1;
  } while (bVar1);
  memw();
  memw();
  if (iStack_24 == *piVar2) {
    return;
  }
  func_0x400831d4();
  return;
}



// Function at 0x400e4fec

undefined4 FUN_400e4fec(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0x102;
  if (param_1 < 2) {
    iVar1 = func_0x4008a8c8();
    uVar2 = 0x103;
    if (iVar1 == 2) {
      uVar2 = FUN_400e4eb4(param_1,param_2,param_3,0);
    }
  }
  return uVar2;
}



// Function at 0x400e5014

undefined4 FUN_400e5014(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0x102;
  if (param_1 < 2) {
    iVar1 = func_0x4008a8c8();
    uVar2 = 0x103;
    if (iVar1 == 2) {
      uVar2 = FUN_400e4eb4(param_1,param_2,param_3,1);
    }
  }
  return uVar2;
}



// Function at 0x400e503c

void FUN_400e503c(void)

{
  uint uVar1;
  undefined1 in_PRID;
  
  uVar1 = rsr(in_PRID);
  uVar1 = uVar1 >> 0xd & 1;
  FUN_400e3450(0x1f);
  (*DAT_400d0a38)(uVar1,uVar1 + 0x1a,0x1f);
  FUN_400e3440(0x1f);
  if (uVar1 != 0) {
    memw();
    *DAT_400d1018 = 1;
  }
  memw();
  return;
}



// Function at 0x400e5070

undefined1 FUN_400e5070(int param_1)

{
  memw();
  memw();
  memw();
  return *(undefined1 *)(DAT_400d101c + param_1);
}



// Function at 0x400e508c

void FUN_400e508c(void)

{
  undefined1 in_MEMCTL;
  
  wsr(in_MEMCTL,0);
  func_0x40086fb8();
  return;
}



// Function at 0x400e509c

void FUN_400e509c(void)

{
  undefined4 uVar1;
  
  uVar1 = func_0x40081d9c();
  *DAT_400d091c = uVar1;
  memw();
  return;
}



// Function at 0x400e50ac

undefined4 FUN_400e50ac(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_retaddr;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 in_WindowBase;
  undefined1 in_WindowStart;
  undefined1 uVar7;
  undefined1 auStack_20 [32];
  
  uVar3 = DAT_400d1028;
  *DAT_400d1020 = *(undefined4 *)(param_1 + 0x1c);
  uVar4 = DAT_400d1024;
  memw();
  uVar7 = 0;
  func_0x40086818(uVar3,0xa5,0x464);
  func_0x4008eccc();
  iVar1 = DAT_400d102c;
  uVar6 = rsr(uVar7);
  uVar5 = rsr(in_WindowBase);
  uVar3 = rsr(in_WindowStart);
  *(undefined4 *)(DAT_400d102c + 0x10) = uVar3;
  *(uint *)((uVar4 & 0xfffffff0) - 0x3c) = uVar4 & 0xfffffff0;
  *(undefined4 *)(iVar1 + 0xc) = uVar5;
  *(undefined1 **)iVar1 = auStack_20;
  *(undefined4 *)(iVar1 + 4) = unaff_retaddr;
  *(undefined4 *)(iVar1 + 8) = uVar6;
  uVar4 = rsr(uVar7);
  wsr(uVar7,uVar4 & DAT_400d1030);
  rsync();
  uVar4 = rsr(in_WindowBase);
  wsr(in_WindowStart,1 << 0x20 - (0x20 - (uVar4 & 0x1f)));
  rsync();
  uVar4 = rsr(uVar7);
  wsr(uVar7,uVar4 | DAT_400d0260);
  rsync();
  memw();
  FUN_400e6198(param_1);
  iVar2 = FUN_400e6060(param_2);
  if (iVar2 != 0) {
    uVar3 = func_0x4008d960();
    (*DAT_400d092c)(DAT_400d1038,uVar3,DAT_400d1034,iVar2);
  }
  wsr(uVar7,*(uint *)(iVar1 + 8) & DAT_400d0c68);
  rsync();
  wsr(in_WindowBase,*(undefined4 *)(iVar1 + 0xc));
  rsync();
  wsr(in_WindowStart,*(undefined4 *)(iVar1 + 0x10));
  rsync();
  wsr(uVar7,*(uint *)(iVar1 + 8));
  rsync();
  return *(undefined4 *)(iVar1 + 0xc);
}



// Function at 0x400e5180

void FUN_400e5180(void)

{
  FUN_400e61f4();
  return;
}



// Function at 0x400e5188

undefined4 FUN_400e5188(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = func_0x4008b31c(param_1);
  return uVar1;
}



// Function at 0x400e5194

int FUN_400e5194(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if (param_2 == (int *)0x0) {
    func_0x4008dacc(DAT_400d1044,0x10a,DAT_400d1040,DAT_400d103c);
  }
  iVar6 = DAT_400d1064;
  iVar5 = DAT_400d1060;
  iVar4 = DAT_400d105c;
  iVar3 = DAT_400d1058;
  iVar7 = DAT_400d1054;
  iVar8 = DAT_400d1050;
  iVar2 = DAT_400d104c;
  iVar1 = DAT_400d1048;
  if (param_1 == 1) {
    *param_2 = DAT_400d1050;
    memw();
  }
  else if (param_1 == 0) {
    *param_2 = DAT_400d1048;
    iVar7 = iVar2;
    iVar8 = iVar1;
  }
  else if (param_1 == 2) {
    *param_2 = DAT_400d1058;
    memw();
    iVar7 = iVar4;
    iVar8 = iVar3;
  }
  else {
    if (param_1 != 3) {
      return -1;
    }
    *param_2 = DAT_400d1060;
    memw();
    iVar7 = iVar6;
    iVar8 = iVar5;
  }
  memw();
  return iVar7 - iVar8;
}



// Function at 0x400e51f8

undefined4 FUN_400e51f8(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400e6268(param_1,0x158);
  return uVar1;
}



// Function at 0x400e520c

undefined4 FUN_400e520c(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 in_PRID;
  
  uVar2 = rsr(in_PRID);
  uVar1 = func_0x4008a8ac(uVar2 >> 0xd & 1);
  return uVar1;
}



// Function at 0x400e521c

int FUN_400e521c(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_2c [4];
  int iStack_28;
  int iStack_24;
  
  func_0x40086818(auStack_2c,0,0xc);
  if (param_3 != (int *)0x0) {
    param_3[1] = 0;
  }
  memw();
  func_0x4008b2e0(param_1,auStack_2c);
  param_2[1] = iStack_28;
  *param_2 = param_1;
  param_2[2] = iStack_24;
  memw();
  iVar1 = func_0x40084c4c();
  if ((iVar1 == 0) && (iVar1 = FUN_400e520c(), param_1 == iVar1)) {
    param_2[1] = *DAT_400d1020;
  }
  memw();
  iVar1 = FUN_400e6328(param_2);
  if ((iVar1 != 0) && (iVar2 = FUN_400e520c(), param_1 == iVar2)) {
    FUN_400e67f8(param_1);
    iVar2 = func_0x40084c4c();
    if (iVar2 != 0) {
      if (param_3 != (int *)0x0) {
        iVar3 = param_2[2];
        iVar2 = param_2[1];
        *param_3 = iVar2;
        param_3[1] = (iVar3 + 3) - iVar2 & 0xfffffffc;
      }
      param_2[1] = *DAT_400d1020;
      memw();
      iVar2 = FUN_400e6204();
      param_2[2] = iVar2;
    }
  }
  memw();
  return iVar1;
}



// Function at 0x400e52a4

undefined4 FUN_400e52a4(int param_1)

{
  FUN_400e6830(param_1 + 0x28);
  return 0;
}



// Function at 0x400e52b4

int FUN_400e52b4(undefined4 param_1,uint *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar2 = FUN_400f82a0();
  puVar1 = DAT_400d1068;
  uVar4 = *param_2 & 0x1f;
  if (uVar4 != 0) {
    uVar4 = 0x20 - uVar4;
  }
  uVar4 = *param_2 + iVar2 + uVar4;
  if ((uint)DAT_400d1068[1] < uVar4) {
    uVar3 = func_0x4008d960();
    (*DAT_400d092c)(DAT_400d1070,uVar3,DAT_400d106c);
    iVar2 = 0x101;
  }
  else {
    *param_2 = uVar4;
    memw();
    func_0x40086818(param_1,0,0x2c);
    uVar4 = *param_2 >> 0xc;
    if ((*param_2 & 0xfff) != 0) {
      uVar4 = uVar4 + 1;
    }
    if ((uint)puVar1[1] < uVar4 << 0xc) {
      func_0x4008da40();
    }
    iVar2 = func_0x40082620(*DAT_400d08ac,*puVar1);
    if (iVar2 != 0) {
      uVar3 = func_0x4008d960();
      (*DAT_400d092c)(DAT_400d1074,uVar3,DAT_400d106c,iVar2);
    }
  }
  return iVar2;
}



// Function at 0x400e533c

int FUN_400e533c(int *param_1,uint *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint auStack_24 [9];
  
  auStack_24[0] = 0;
  memw();
  iVar1 = FUN_400dd700(1,3,0);
  if (iVar1 == 0) {
    uVar2 = func_0x4008d960();
    (*DAT_400d092c)(DAT_400d1078,uVar2,DAT_400d106c);
    iVar1 = 0x105;
  }
  else {
    if (*(uint *)(iVar1 + 0x10) < 4) {
      uVar2 = func_0x4008d960();
      (*DAT_400d092c)(DAT_400d107c,uVar2,DAT_400d106c);
    }
    else {
      iVar3 = FUN_400dd884(iVar1,0,auStack_24,4);
      if (iVar3 != 0) {
        uVar2 = func_0x4008d960();
        (*DAT_400d092c)(DAT_400d1080,uVar2,DAT_400d106c,iVar3);
        return iVar3;
      }
      if (auStack_24[0] != 0xffffffff) {
        if ((3 < auStack_24[0]) && (auStack_24[0] <= *(uint *)(iVar1 + 0x10))) {
          *param_1 = iVar1;
          *param_2 = auStack_24[0];
          memw();
          return 0;
        }
        uVar2 = func_0x4008d960();
        (*DAT_400d092c)(DAT_400d1084,uVar2,DAT_400d106c,auStack_24[0]);
      }
    }
    iVar1 = 0x104;
  }
  return iVar1;
}



// Function at 0x400e53e4

undefined4 FUN_400e53e4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = func_0x40083e78();
  if ((iVar1 == 0) || (*(char *)(DAT_400d1068 + 8) == '\0')) {
    uVar2 = func_0x4008293c(*DAT_400d08ac,param_2,param_1,param_3);
  }
  else {
    uVar2 = func_0x40082aa4(*DAT_400d08ac,param_1,param_2);
  }
  return uVar2;
}



// Function at 0x400e560c

void FUN_400e560c(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_400dd700(1,3,0);
  puVar1 = DAT_400d1068;
  if (iVar2 == 0) {
    uVar3 = func_0x4008d960();
    (*DAT_400d092c)(DAT_400d1098,uVar3,DAT_400d106c);
  }
  else {
    *DAT_400d1068 = *(undefined4 *)(iVar2 + 0xc);
    puVar1[1] = *(undefined4 *)(iVar2 + 0x10);
    *(undefined1 *)(puVar1 + 2) = *(undefined1 *)(iVar2 + 0x25);
    memw();
    memw();
    uVar3 = (*DAT_400d080c)(0,puVar1,0xc);
    puVar1[3] = uVar3;
    memw();
  }
  return;
}



// Function at 0x400e565c

void FUN_400e565c(undefined4 param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  piVar1 = DAT_400d1068;
  iVar3 = (*DAT_400d080c)(0,DAT_400d1068,0xc);
  if (piVar1[3] == iVar3) {
    if ((*piVar1 == 0) || ((uint)piVar1[1] < 4)) {
      uVar4 = func_0x4008d960();
      (*DAT_400d092c)(DAT_400d10a0,uVar4,DAT_400d106c);
    }
    else {
      func_0x40082300(DAT_400d10a4);
      FUN_400dd9c8(1);
      puVar2 = DAT_400d10a8;
      *DAT_400d10a8 = PTR_FUN_400d10ac;
      puVar2[1] = PTR_FUN_400d10b0;
      puVar2[3] = PTR_LAB_400d10b4;
      puVar2[2] = PTR_LAB_400d10b8;
      puVar2[4] = DAT_400d10bc;
      memw();
      FUN_400e50ac(param_1);
    }
  }
  else {
    uVar4 = func_0x4008d960();
    (*DAT_400d092c)(DAT_400d109c,uVar4,DAT_400d106c,iVar3,piVar1[3]);
  }
  return;
}



// Function at 0x400e56e4

int FUN_400e56e4(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uStack_7c;
  int iStack_78;
  undefined4 uStack_74;
  undefined1 auStack_70 [32];
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [36];
  undefined4 uStack_28;
  int iStack_24;
  
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  uStack_7c = 0;
  memw();
  func_0x40086818(auStack_50,0,0x2c);
  iStack_78 = 0;
  memw();
  uVar1 = FUN_400f82a0();
  uStack_74 = 0;
  memw();
  func_0x40086818(auStack_70,0,0x20);
  if (0x20 < uVar1) {
    func_0x4008dacc(DAT_400d10c8,0x178,DAT_400d10c4,DAT_400d10c0);
  }
  iVar2 = FUN_400e533c(&uStack_7c,&iStack_78);
  if (iVar2 == 0) {
    uVar5 = iStack_78 - uVar1;
    FUN_400e6830(&uStack_28);
    iVar6 = 0;
    for (; uVar5 != 0; uVar5 = uVar5 - iVar7) {
      iVar7 = (uVar5 < 0x20) * uVar5 + (uint)(uVar5 >= 0x20) * 0x20;
      iVar2 = FUN_400dd884(uStack_7c,iVar6,auStack_4c,iVar7);
      if (iVar2 != 0) {
        uVar3 = func_0x4008d960();
        uVar4 = DAT_400d10cc;
        goto LAB_400e57a2;
      }
      FUN_400e6848(uStack_28,auStack_4c,iVar7);
      iVar6 = iVar6 + iVar7;
    }
    FUN_400e6890(uStack_28,&uStack_74);
    iVar2 = FUN_400dd884(uStack_7c,iStack_78 - uVar1,auStack_70,uVar1);
    if (iVar2 == 0) {
      iVar2 = func_0x40086624(uStack_74,auStack_70,uVar1);
      if (iVar2 != 0) {
        uVar4 = func_0x4008d960();
        (*DAT_400d092c)(DAT_400d10d4,uVar4,DAT_400d106c);
        FUN_400e68c4(DAT_400d10d8,uStack_74);
        FUN_400e68c4(DAT_400d10dc,auStack_70);
        iVar2 = 0x109;
      }
    }
    else {
      uVar3 = func_0x4008d960();
      uVar4 = DAT_400d10d0;
LAB_400e57a2:
      (*DAT_400d092c)(uVar4,uVar3,DAT_400d106c,iVar2);
    }
  }
  memw();
  memw();
  if (iStack_24 != *DAT_400d0098) {
    iVar2 = func_0x400831d4();
    return iVar2;
  }
  return iVar2;
}



// Function at 0x400e5810

void FUN_400e5810(void)

{
  int iVar1;
  undefined4 uStack_28;
  undefined4 auStack_24 [9];
  
  FUN_400e560c();
  uStack_28 = 0;
  auStack_24[0] = 0;
  memw();
  iVar1 = FUN_400e56e4();
  if (iVar1 == 0) {
    FUN_400e533c(&uStack_28,auStack_24);
  }
  return;
}



// Function at 0x400e5830

int FUN_400e5830(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  
  if (param_3 == 0) {
    uVar2 = func_0x4008d960();
    (*DAT_400d092c)(DAT_400d10e8,uVar2,DAT_400d10e4,DAT_400d10e0,0xfd);
    return -3;
  }
  func_0x40086818(&uStack_2c,0,0xc);
  iVar3 = func_0x40086c6c(param_1);
  iVar1 = DAT_400d10f4;
  if (0x20 < iVar3 + 1U) {
    uVar2 = func_0x4008d960();
    (*DAT_400d092c)(DAT_400d10f0,uVar2,DAT_400d10e4,DAT_400d10ec,0xd7,iVar3 + 1U);
    iVar3 = 0;
    goto LAB_400e5887;
  }
  uVar6 = param_4 + 3U & 0xfffffffc;
  uVar7 = iVar3 + 4U & 0xfffffffc;
  iVar3 = uVar6 + 0xc + uVar7;
  if (*(short *)(DAT_400d10f4 + 0x48) == 2) {
    memw();
    func_0x400866b8(DAT_400d10f8,param_1,uVar7);
    memw();
    uStack_2c = uVar7;
    iStack_28 = param_4;
    uStack_24 = param_2;
    iVar4 = (**(code **)(*(int *)(iVar1 + 0x54) + 8))
                      (*(undefined4 *)(*(int *)(iVar1 + 0x54) + 0x10),&uStack_2c,0xc);
    if (iVar4 == 0) {
      iVar4 = (**(code **)(*(int *)(iVar1 + 0x54) + 8))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x54) + 0x10),DAT_400d10f8,uVar7);
      if (iVar4 == 0) {
        iVar4 = (**(code **)(*(int *)(iVar1 + 0x54) + 8))
                          (*(undefined4 *)(*(int *)(iVar1 + 0x54) + 0x10),param_3,uVar6);
        if (iVar4 == 0) goto LAB_400e5969;
        uVar5 = func_0x4008d960();
        uVar8 = 0xef;
        uVar2 = DAT_400d1104;
      }
      else {
        uVar5 = func_0x4008d960();
        uVar8 = 0xeb;
        uVar2 = DAT_400d1100;
      }
    }
    else {
      uVar5 = func_0x4008d960();
      uVar8 = 0xe7;
      uVar2 = DAT_400d10fc;
    }
    (*DAT_400d092c)(uVar2,uVar5,DAT_400d10e4,DAT_400d10ec,uVar8,iVar4);
    iVar3 = -2;
  }
  else {
LAB_400e5969:
    if (0 < iVar3) {
      return iVar3;
    }
  }
LAB_400e5887:
  uVar2 = func_0x4008d960();
  (*DAT_400d092c)(DAT_400d1108,uVar2,DAT_400d10e4,DAT_400d10e0,0x101,iVar3);
  return iVar3;
}



// Function at 0x400e5974

undefined4 FUN_400e5974(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 auStack_24 [9];
  
  iVar1 = FUN_400e636c(param_1,auStack_24);
  if (iVar1 == 0) {
    uVar2 = func_0x4008d960();
    (*DAT_400d092c)(DAT_400d110c,uVar2,DAT_400d10e4,*param_1);
    uVar2 = 0xfffffffd;
  }
  else {
    uVar2 = FUN_400e5830(DAT_400d1110,1,auStack_24[0],iVar1);
  }
  return uVar2;
}



// Function at 0x400e59b0

undefined4 FUN_400e59b0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_400d10f4 + 0x54);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(DAT_400d10f4 + 0x4c);
  memw();
  iVar2 = (**(code **)(iVar2 + 8))(*(undefined4 *)(iVar2 + 0x10),param_1,0x20);
  uVar1 = 0x20;
  if (iVar2 != 0) {
    uVar1 = func_0x4008d960();
    (*DAT_400d092c)(DAT_400d1118,uVar1,DAT_400d10e4,DAT_400d1114,0x97,iVar2);
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}



// Function at 0x400e59f4

uint FUN_400e59f4(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint local_40 [2];
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  
  func_0x40086818(local_40,0,0x20);
  iVar1 = DAT_400d10f4;
  if (param_2 == 0) {
    uVar2 = func_0x4008d960();
    (*DAT_400d092c)(DAT_400d1120,uVar2,DAT_400d10e4,DAT_400d111c,0xa7);
    uVar3 = 0xfffffffd;
  }
  else {
    uVar4 = param_3 + 3U & 0xfffffffc;
    local_40[0] = (uint)*(ushort *)(DAT_400d10f4 + 0x48);
    if (local_40[0] == 0) {
      *(short *)(DAT_400d10f4 + 0x50) = *(short *)(DAT_400d10f4 + 0x50) + 1;
      memw();
      uVar3 = uVar4 + 0x20;
      memw();
    }
    else {
      if (local_40[0] == 1) {
        uStack_28 = 6;
        memw();
        uStack_38 = param_1;
        uStack_34 = param_1;
        uStack_30 = uVar4;
        uStack_2c = uVar4;
        uVar3 = FUN_400e59b0(local_40);
        if ((int)uVar3 < 1) {
          uVar2 = func_0x4008d960();
          (*DAT_400d092c)(DAT_400d1124,uVar2,DAT_400d10e4,DAT_400d111c,0xb8,uVar3);
          return uVar3;
        }
        iVar5 = *(int *)(iVar1 + 0x4c);
      }
      else {
        iVar5 = (**(code **)(*(int *)(DAT_400d10f4 + 0x54) + 8))
                          (*(undefined4 *)(*(int *)(DAT_400d10f4 + 0x54) + 0x10),param_2,uVar4);
        if (iVar5 != 0) {
          uVar2 = func_0x4008d960();
          (*DAT_400d092c)(DAT_400d1128,uVar2,DAT_400d10e4,DAT_400d111c,0xc2,iVar5);
          return 0xfffffffe;
        }
        iVar5 = *(int *)(iVar1 + 0x4c);
        uVar3 = uVar4;
      }
      *(uint *)(iVar1 + 0x4c) = iVar5 + uVar4;
      memw();
    }
  }
  return uVar3;
}



// Function at 0x400e5ad0

int FUN_400e5ad0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_40 [4];
  int iStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  
  func_0x40086818(local_40,0,0x20);
  iVar1 = DAT_400d10f4;
  if (*(short *)(DAT_400d10f4 + 0x48) == 1) {
    uStack_28 = 6;
    local_40[0] = 4;
    memw();
    iStack_30 = param_1;
    iStack_2c = param_1;
    iVar2 = FUN_400e59b0(local_40);
    if (iVar2 < 1) {
      uVar3 = func_0x4008d960();
      (*DAT_400d092c)(DAT_400d1130,uVar3,DAT_400d10e4,DAT_400d112c,0x164,iVar2);
      param_1 = iVar2;
    }
    else {
      *(int *)(iVar1 + 0x4c) = *(int *)(iVar1 + 0x4c) + param_1;
      param_1 = 0x20;
      memw();
    }
  }
  else if (*(short *)(DAT_400d10f4 + 0x48) == 0) {
    param_1 = param_1 + 0x20;
    *(short *)(DAT_400d10f4 + 0x50) = *(short *)(DAT_400d10f4 + 0x50) + 1;
    memw();
    memw();
  }
  else {
    *(int *)(DAT_400d10f4 + 0x4c) = *(int *)(DAT_400d10f4 + 0x4c) + param_1;
    memw();
  }
  return param_1;
}



// Function at 0x400e5b54

int FUN_400e5b54(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  int iStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 auStack_64 [3];
  undefined4 uStack_58;
  undefined2 uStack_54;
  undefined1 auStack_52 [10];
  undefined2 uStack_48;
  undefined2 uStack_46;
  uint uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined4 uStack_28;
  int iStack_24;
  
  puVar3 = DAT_400d10f4;
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  uVar1 = *(ushort *)(DAT_400d10f4 + 0x12);
  if (uVar1 == 1) {
    uVar2 = *(undefined2 *)(DAT_400d10f4 + 0x14);
    memw();
    func_0x40086818(auStack_52,0,0x2e);
    uStack_58 = DAT_400d1134;
    uStack_54 = 0x101;
    auStack_52[0] = (undefined1)uVar1;
    uStack_48 = 4;
    memw();
    memw();
    uStack_46 = FUN_400f8290();
    memw();
    uStack_40 = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_28 = 0;
    uStack_30 = DAT_400d1138;
    uStack_2a = 0x28;
    memw();
    uStack_3c = 0x34;
    memw();
    uStack_44 = (uint)uVar1;
    uStack_2c = uVar2;
    iVar9 = (**(code **)(puVar3[0x15] + 8))(*(undefined4 *)(puVar3[0x15] + 0x10),&uStack_58);
    if (iVar9 == 0) goto LAB_400e5c36;
    uVar8 = func_0x4008d960();
    (*DAT_400d092c)(DAT_400d1140,uVar8,DAT_400d10e4,DAT_400d113c,0x87,iVar9);
    iVar9 = -2;
  }
  else {
LAB_400e5c36:
    iVar9 = 0x34;
    if (*(short *)(puVar3 + 0x12) == 2) {
      iVar9 = 0;
    }
  }
  iVar6 = iVar9;
  if (*(short *)(puVar3 + 0x12) == 2) {
    if (iVar9 < 0) {
      uVar4 = func_0x4008d960();
      uVar11 = 0x221;
      uVar8 = DAT_400d1148;
    }
    else {
LAB_400e5c61:
      func_0x40086818(&uStack_70,0,0xc);
      uStack_78 = 0;
      iStack_74 = 0;
      memw();
      func_0x40086818(auStack_64,0,0xc);
      FUN_400e5180();
      iVar5 = FUN_400e520c();
      iVar6 = FUN_400e521c(iVar5,auStack_64,0);
      if (iVar6 == 0) {
        iVar6 = 0;
LAB_400e5c96:
        iVar5 = 0;
        while (iVar5 = FUN_400e5188(iVar5), iVar5 != 0) {
          iVar7 = FUN_400e520c();
          if ((iVar5 != iVar7) && (iVar7 = FUN_400e521c(iVar5,auStack_64,0), iVar7 != 0)) {
            iVar7 = FUN_400e5974(auStack_64);
            if (*(short *)(puVar3 + 0x12) == 1) {
              if (iVar7 < 0) {
                uVar4 = func_0x4008d960();
                uVar11 = 0x193;
                memw();
                uVar8 = DAT_400d115c;
                iVar6 = iVar7;
                goto LAB_400e5cfa;
              }
            }
            else if (iVar7 < 1) {
              uVar4 = func_0x4008d960();
              uVar11 = 0x195;
              memw();
              uVar8 = DAT_400d1160;
              iVar6 = iVar7;
              goto LAB_400e5cfa;
            }
            iVar6 = iVar6 + iVar7;
          }
        }
        iVar5 = FUN_400e5ad0(iVar6);
        if (0 < iVar5) {
          FUN_400e5180();
          iVar7 = 0;
LAB_400e5e7e:
          iVar7 = FUN_400e5188(iVar7);
          if (iVar7 != 0) {
            iVar6 = FUN_400e521c(iVar7,&uStack_70,&uStack_78);
            if (iVar6 != 0) {
              iVar6 = FUN_400e59f4(uStack_70,uStack_70,0x158);
              if (iVar6 < 1) {
                uVar4 = func_0x4008d960();
                uVar8 = DAT_400d10e4;
                (*DAT_400d092c)(DAT_400d1168,uVar4,DAT_400d10e4,uStack_70,iVar6);
                uVar4 = func_0x4008d960();
                memw();
                (*DAT_400d092c)(DAT_400d1170,uVar4,uVar8,DAT_400d116c,0x1a6,uStack_70,iVar6);
              }
              else {
                auStack_64[0] = 0;
                memw();
                uVar8 = FUN_400e62e8(&uStack_70,&uStack_7c,auStack_64);
                iVar10 = FUN_400e59f4(uStack_7c,auStack_64[0],uVar8);
                if (iVar10 < 1) {
                  uVar8 = func_0x4008d960();
                  (*DAT_400d092c)(DAT_400d1174,uVar8,DAT_400d10e4,uStack_70,uStack_6c,iVar10);
                  if (iVar10 == -2) {
                    uVar8 = func_0x4008d960();
                    memw();
                    (*DAT_400d092c)(DAT_400d1178,uVar8,DAT_400d10e4,DAT_400d116c,0x1aa,uStack_70,
                                    0xfffffffe);
                    iVar6 = -2;
                    goto LAB_400e5e0c;
                  }
                }
                iVar6 = iVar10 + iVar6;
                if (0 < iVar6) {
                  iVar5 = iVar5 + iVar6;
                  if (iStack_74 != 0) {
                    iVar6 = FUN_400e59f4(uStack_78,uStack_78);
                    if (iVar6 < 1) {
                      uVar8 = func_0x4008d960();
                      (*DAT_400d092c)(DAT_400d1184,uVar8,DAT_400d10e4,DAT_400d117c,0x1d4,iVar6);
                      goto LAB_400e5e2f;
                    }
                    iVar5 = iVar5 + iVar6;
                  }
                  goto LAB_400e5e7e;
                }
              }
LAB_400e5e0c:
              uVar8 = func_0x4008d960();
              memw();
              (*DAT_400d092c)(DAT_400d1180,uVar8,DAT_400d10e4,DAT_400d117c,0x1cb,iVar7,iVar6);
              goto LAB_400e5e2f;
            }
            goto LAB_400e5e7e;
          }
          iVar7 = 0;
          iVar10 = 0;
          auStack_64[0] = 0;
          do {
            memw();
            iVar6 = FUN_400e5194(iVar10,auStack_64);
            if (iVar6 < 0) {
              uVar8 = func_0x4008d960();
              (*DAT_400d092c)(DAT_400d118c,uVar8,DAT_400d10e4,DAT_400d1188,0x1e5);
              iVar6 = -3;
LAB_400e5eb8:
              uVar8 = func_0x4008d960();
              (*DAT_400d092c)(DAT_400d1194,uVar8,DAT_400d10e4,DAT_400d1144,0x22d,iVar6);
              goto LAB_400e5c1f;
            }
            if (iVar6 != 0) {
              iVar6 = FUN_400e59f4(auStack_64[0],auStack_64[0],iVar6);
              if (iVar6 < 1) {
                uVar8 = func_0x4008d960();
                (*DAT_400d092c)(DAT_400d1190,uVar8,DAT_400d10e4,DAT_400d1188,0x1ed,iVar6);
                iVar7 = iVar6;
                if (iVar6 != 0) goto LAB_400e5eb8;
                break;
              }
              iVar7 = iVar7 + iVar6;
            }
            iVar10 = iVar10 + 1;
          } while (iVar10 != 4);
          auStack_64[0] = 0;
          memw();
          func_0x40081af8(DAT_400d1198,0x42);
          uVar8 = FUN_400f8298();
          *puVar3 = uVar8;
          memw();
          iVar10 = FUN_400e5830(DAT_400d11a0,DAT_400d119c,puVar3,0x48);
          if (iVar10 < 1) {
            uVar8 = func_0x4008d960();
            (*DAT_400d092c)(DAT_400d11a8,uVar8,DAT_400d10e4,DAT_400d11a4,0x204,iVar10);
            iVar6 = iVar10;
          }
          else {
            iVar6 = FUN_400e681c(auStack_64);
            if (iVar6 == 0) {
              uVar8 = func_0x4008d960();
              (*DAT_400d092c)(DAT_400d11ac,uVar8,DAT_400d10e4);
              iVar6 = -3;
            }
            else {
              iVar6 = FUN_400e5830(DAT_400d11b0,0x2a5,auStack_64[0],iVar6);
              if (iVar6 < 1) {
                uVar4 = func_0x4008d960();
                uVar11 = 0x212;
                uVar8 = DAT_400d11b4;
              }
              else {
                iVar6 = FUN_400e5ad0(iVar10 + iVar6);
                if (0 < iVar6) {
                  iVar6 = iVar6 + iVar9 + iVar5 + iVar7;
                  goto LAB_400e5c1f;
                }
                uVar4 = func_0x4008d960();
                uVar11 = 0x217;
                uVar8 = DAT_400d11b8;
              }
              (*DAT_400d092c)(uVar8,uVar4,DAT_400d10e4,DAT_400d11a4,uVar11,iVar6);
            }
          }
          uVar4 = func_0x4008d960();
          uVar11 = 0x233;
          uVar8 = DAT_400d11bc;
          goto LAB_400e5c19;
        }
        uVar8 = func_0x4008d960();
        (*DAT_400d092c)(DAT_400d1164,uVar8,DAT_400d10e4,DAT_400d1150,0x19c,iVar5);
        iVar6 = iVar5;
      }
      else {
        iVar6 = FUN_400e5974(auStack_64);
        if (*(short *)(puVar3 + 0x12) == 1) {
          if (-1 < iVar6) goto LAB_400e5c96;
          uVar4 = func_0x4008d960();
          uVar11 = 0x181;
          uVar8 = DAT_400d1154;
        }
        else {
          if (0 < iVar6) goto LAB_400e5c96;
          uVar4 = func_0x4008d960();
          uVar11 = 0x183;
          memw();
          uVar8 = DAT_400d1158;
        }
LAB_400e5cfa:
        memw();
        (*DAT_400d092c)(uVar8,uVar4,DAT_400d10e4,DAT_400d1150,uVar11,iVar5,iVar6);
      }
      uVar8 = func_0x4008d960();
      (*DAT_400d092c)(DAT_400d11c4,uVar8,DAT_400d10e4,DAT_400d117c,0x1bb,iVar6);
LAB_400e5e2f:
      uVar4 = func_0x4008d960();
      uVar11 = 0x228;
      uVar8 = DAT_400d11c0;
    }
  }
  else {
    if (0 < iVar9) goto LAB_400e5c61;
    uVar4 = func_0x4008d960();
    uVar11 = 0x223;
    uVar8 = DAT_400d114c;
  }
LAB_400e5c19:
  (*DAT_400d092c)(uVar8,uVar4,DAT_400d10e4,DAT_400d1144,uVar11,iVar6);
LAB_400e5c1f:
  memw();
  memw();
  if (iStack_24 != *DAT_400d0098) {
    iVar9 = func_0x400831d4();
    return iVar9;
  }
  return iVar6;
}



// Function at 0x400e6060

int FUN_400e6060(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int aiStack_24 [9];
  
  iVar5 = DAT_400d10f4;
  aiStack_24[0] = 0x14;
  if (param_1 == (undefined4 *)0x0) {
    memw();
    uVar2 = func_0x4008d960();
    (*DAT_400d092c)(DAT_400d11cc,uVar2,DAT_400d10e4,DAT_400d11c8,0x241);
    return 0x102;
  }
  *(undefined2 *)(DAT_400d10f4 + 0x48) = 0;
  memw();
  *(undefined4 **)(iVar5 + 0x54) = param_1;
  memw();
  iVar3 = FUN_400e5b54();
  if (iVar3 < 0) {
    return iVar3;
  }
  aiStack_24[0] = aiStack_24[0] + iVar3;
  if ((code *)*param_1 != (code *)0x0) {
    memw();
    iVar3 = (*(code *)*param_1)(param_1[4],aiStack_24);
    if (iVar3 != 0) {
      uVar4 = func_0x4008d960();
      uVar2 = DAT_400d11d0;
      goto LAB_400e60ce;
    }
  }
  if (((code *)param_1[1] == (code *)0x0) || (iVar3 = (*(code *)param_1[1])(param_1[4]), iVar3 == 0)
     ) {
    piVar1 = DAT_400d11d8;
    *DAT_400d11d8 = aiStack_24[0];
    memw();
    iVar3 = FUN_400f8298();
    piVar1[1] = iVar3;
    piVar1[2] = 0;
    piVar1[3] = 0;
    piVar1[4] = 0;
    memw();
    iVar3 = (*(code *)param_1[2])(param_1[4],piVar1,0x14);
    if (iVar3 == 0) {
      *(undefined2 *)(iVar5 + 0x48) = 1;
      memw();
      *(uint *)(iVar5 + 0x4c) = (uint)*(ushort *)(iVar5 + 0x50) * 0x20 + 0x34;
      memw();
      iVar3 = FUN_400e5b54();
      if (iVar3 < 0) {
        return iVar3;
      }
      *(undefined2 *)(iVar5 + 0x48) = 2;
      memw();
      *(uint *)(iVar5 + 0x4c) = (uint)*(ushort *)(iVar5 + 0x50) * 0x20 + 0x34;
      memw();
      iVar5 = FUN_400e5b54();
      if (iVar5 < 0) {
        return iVar5;
      }
      if ((code *)param_1[3] == (code *)0x0) {
        return 0;
      }
      iVar3 = (*(code *)param_1[3])(param_1[4]);
      if (iVar3 == 0) {
        return 0;
      }
      uVar4 = func_0x4008d960();
      uVar2 = DAT_400d11e0;
    }
    else {
      uVar4 = func_0x4008d960();
      uVar2 = DAT_400d11dc;
    }
  }
  else {
    uVar4 = func_0x4008d960();
    uVar2 = DAT_400d11d4;
  }
LAB_400e60ce:
  (*DAT_400d092c)(uVar2,uVar4,DAT_400d10e4,iVar3);
  return iVar3;
}



// Function at 0x400e6198

void FUN_400e6198(int param_1)

{
  char cVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = DAT_400d11e4;
  *DAT_400d11e4 = 0xef;
  puVar2[1] = 0xbe;
  puVar2[2] = 0xad;
  puVar2[3] = 0xde;
  puVar2[8] = 0xff;
  puVar2[9] = 0xff;
  puVar2[10] = 0;
  puVar2[0xb] = 0;
  puVar2[5] = 0;
  puVar2[6] = 0;
  puVar2[7] = 0;
  puVar2[4] = 0xe8;
  memw();
  puVar3 = *(undefined4 **)(param_1 + 0x1c);
  cVar1 = *(char *)(param_1 + 0x20);
  *puVar3 = DAT_400d11e8;
  if (cVar1 != '\0') {
    puVar3[0x14] = puVar3[0x14] + 0x40;
  }
  memw();
  return;
}



// Function at 0x400e61f4

void FUN_400e61f4(void)

{
  *DAT_400d11ec = 0;
  memw();
  return;
}



// Function at 0x400e6204

int FUN_400e6204(void)

{
  uint uVar1;
  undefined1 in_PRID;
  
  uVar1 = rsr(in_PRID);
  return DAT_400d11f0 + ((uVar1 >> 0xd & 1) + 1) * 0x830;
}



// Function at 0x400e6224

bool FUN_400e6224(int param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 4);
  bVar1 = false;
  if ((uVar3 + DAT_400d11f4 <= DAT_400d11f8) && ((uVar3 & 0xf) == 0)) {
    uVar2 = *(uint *)(param_1 + 8);
    if ((DAT_400d0c90 < uVar2 + DAT_400d0c8c) || (uVar2 <= uVar3)) {
      bVar1 = false;
    }
    else {
      bVar1 = uVar2 - uVar3 <= DAT_400d060c;
    }
  }
  return bVar1;
}



// Function at 0x400e6268

undefined4 FUN_400e6268(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (DAT_400d0c90 < (uint)(param_1 + DAT_400d0c8c)) {
    if (DAT_400d028c < (uint)(param_1 + DAT_400d0524)) {
      iVar1 = DAT_400d1208;
      uVar2 = DAT_400d028c;
      if ((uint)(param_1 + DAT_400d1204) <= DAT_400d028c) goto LAB_400e62d7;
      goto LAB_400e6284;
    }
    if ((uint)(param_2 + DAT_400d1200 + param_1) <= DAT_400d028c) {
      return 1;
    }
  }
  else {
    if ((uint)(param_2 + DAT_400d11fc + param_1) <= DAT_400d0c90) {
      return 1;
    }
LAB_400e6284:
    if ((uint)(param_1 + DAT_400d0dc4) <= DAT_400d0864) {
      if (DAT_400d0864 < (uint)(param_2 + DAT_400d120c + param_1)) {
        return 0;
      }
      return 1;
    }
  }
  iVar1 = DAT_400d1210;
  uVar2 = DAT_400d0b6c;
  if (DAT_400d0b6c < (uint)(param_1 + DAT_400d0b68)) {
    return 0;
  }
LAB_400e62d7:
  if (uVar2 < (uint)(param_2 + iVar1 + param_1)) {
    return 0;
  }
  return 1;
}



// Function at 0x400e62e8

int FUN_400e62e8(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int in_t0;
  
  uVar2 = *(uint *)(param_1 + 4);
  uVar4 = *(uint *)(param_1 + 8);
  iVar1 = uVar2 - uVar4;
  if (iVar1 < 1) {
    iVar1 = -iVar1;
  }
  iVar3 = (uVar2 < uVar4) * uVar2 + (uVar2 >= uVar4) * uVar4;
  if ((param_3 == (int *)0x0) || (param_2 == (int *)0x0)) {
    iVar3 = in_t0;
    func_0x4008dacc(DAT_400d121c,0x158,DAT_400d1218,DAT_400d1214);
  }
  uVar2 = iVar3 + DAT_400d1220;
  *param_2 = iVar3;
  if (uVar2 <= DAT_400d1224) {
    iVar3 = DAT_400d1228;
  }
  *param_3 = iVar3;
  memw();
  return iVar1;
}



// Function at 0x400e6328

int FUN_400e6328(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_400e51f8(*param_1);
  iVar2 = iVar1;
  if ((iVar1 != 0) && (iVar2 = FUN_400e6224(param_1), iVar2 == 0)) {
    iVar2 = *DAT_400d11ec;
    *DAT_400d11ec = iVar2 + 1;
    iVar2 = iVar2 * 0x70 + DAT_400d026c;
    param_1[1] = iVar2;
    param_1[2] = iVar2 + 0x70;
    iVar2 = iVar1;
  }
  memw();
  return iVar2;
}



// Function at 0x400e636c

undefined4 FUN_400e636c(undefined1 *param_1,int *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  undefined1 in_EPC1;
  undefined1 in_EPC2;
  undefined1 in_EPC3;
  undefined1 in_EPC4;
  undefined1 in_EPC5;
  undefined1 in_EPC6;
  undefined1 in_EPS2;
  undefined1 in_EPS3;
  undefined1 in_EPS4;
  undefined1 in_EPS5;
  undefined1 in_EPS6;
  undefined4 uStack_28;
  int *apiStack_24 [9];
  
  uStack_28 = 0;
  apiStack_24[0] = (int *)0x0;
  if ((param_1 == (undefined1 *)0x0) || (param_2 == (int *)0x0)) {
    memw();
    func_0x4008dacc(DAT_400d121c,0x1ae,DAT_400d1230,DAT_400d122c);
  }
  uVar5 = FUN_400e62e8(param_1,&uStack_28,apiStack_24);
  iVar4 = DAT_400d1234;
  *(undefined1 *)(DAT_400d1234 + 0x18) = *param_1;
  memw();
  *(undefined1 *)(iVar4 + 0x19) = param_1[1];
  memw();
  uVar1 = param_1[2];
  uVar2 = param_1[3];
  *(undefined1 *)(iVar4 + 0xc) = 0;
  *(undefined1 *)(iVar4 + 0x1b) = uVar2;
  *(undefined1 *)(iVar4 + 0xd) = 0;
  *(undefined1 *)(iVar4 + 0x1a) = uVar1;
  iVar8 = DAT_400d11e4;
  iVar7 = DAT_400d0020;
  memw();
  if (uVar5 < 0x70) {
    memw();
    uVar6 = func_0x4008d960();
    uVar11 = DAT_400d1238;
    (*DAT_400d092c)(DAT_400d123c,uVar6,DAT_400d1238,uVar5);
    uVar6 = func_0x4008d960();
    (*DAT_400d092c)(DAT_400d1240,uVar6,uVar11);
  }
  else {
    if (*apiStack_24[0] == DAT_400d11e8) {
      iVar7 = apiStack_24[0][0x14];
      *(char *)(DAT_400d11e4 + 8) = (char)iVar7;
      *(char *)(iVar8 + 9) = (char)((uint)iVar7 >> 8);
      *(char *)(iVar8 + 0xb) = (char)((uint)iVar7 >> 0x18);
      memw();
      iVar10 = apiStack_24[0][0x15];
      *(char *)(iVar8 + 10) = (char)((uint)iVar7 >> 0x10);
      *(undefined1 *)(iVar8 + 4) = 0xe8;
      *(char *)(iVar8 + 0x11) = (char)((uint)iVar10 >> 8);
      *(char *)(iVar8 + 0x12) = (char)((uint)iVar10 >> 0x10);
      *(char *)(iVar8 + 0x10) = (char)iVar10;
      *(undefined1 *)(iVar8 + 0xc) = 0xee;
      *(undefined1 *)(iVar8 + 5) = 0;
      *(undefined1 *)(iVar8 + 6) = 0;
      *(undefined1 *)(iVar8 + 7) = 0;
      *(char *)(iVar8 + 0x13) = (char)((uint)iVar10 >> 0x18);
      *(undefined1 *)(iVar8 + 0xd) = 0;
      *(undefined1 *)(iVar8 + 0xe) = 0;
      *(undefined1 *)(iVar8 + 0xf) = 0;
      *(undefined1 *)(iVar8 + 0x14) = 0xc2;
      *(undefined1 *)(iVar8 + 0x15) = 0;
      *(undefined1 *)(iVar8 + 0x16) = 0;
      *(undefined1 *)(iVar8 + 0x17) = 0;
      uVar11 = rsr(in_EPS2);
      *(char *)(iVar8 + 0x19) = (char)((uint)uVar11 >> 8);
      *(char *)(iVar8 + 0x18) = (char)uVar11;
      *(char *)(iVar8 + 0x1a) = (char)((uint)uVar11 >> 0x10);
      *(char *)(iVar8 + 0x1b) = (char)((uint)uVar11 >> 0x18);
      *(undefined1 *)(iVar8 + 0x1c) = 0xc3;
      *(undefined1 *)(iVar8 + 0x1d) = 0;
      *(undefined1 *)(iVar8 + 0x1e) = 0;
      *(undefined1 *)(iVar8 + 0x1f) = 0;
      uVar11 = rsr(in_EPS3);
      *(char *)(iVar8 + 0x21) = (char)((uint)uVar11 >> 8);
      *(char *)(iVar8 + 0x20) = (char)uVar11;
      *(char *)(iVar8 + 0x22) = (char)((uint)uVar11 >> 0x10);
      *(char *)(iVar8 + 0x23) = (char)((uint)uVar11 >> 0x18);
      *(undefined1 *)(iVar8 + 0x24) = 0xc4;
      *(undefined1 *)(iVar8 + 0x25) = 0;
      *(undefined1 *)(iVar8 + 0x26) = 0;
      *(undefined1 *)(iVar8 + 0x27) = 0;
      uVar11 = rsr(in_EPS4);
      *(char *)(iVar8 + 0x29) = (char)((uint)uVar11 >> 8);
      *(char *)(iVar8 + 0x28) = (char)uVar11;
      *(char *)(iVar8 + 0x2a) = (char)((uint)uVar11 >> 0x10);
      *(char *)(iVar8 + 0x2b) = (char)((uint)uVar11 >> 0x18);
      *(undefined1 *)(iVar8 + 0x2c) = 0xc5;
      *(undefined1 *)(iVar8 + 0x2d) = 0;
      *(undefined1 *)(iVar8 + 0x2e) = 0;
      *(undefined1 *)(iVar8 + 0x2f) = 0;
      uVar11 = rsr(in_EPS5);
      *(char *)(iVar8 + 0x31) = (char)((uint)uVar11 >> 8);
      *(char *)(iVar8 + 0x30) = (char)uVar11;
      *(char *)(iVar8 + 0x32) = (char)((uint)uVar11 >> 0x10);
      *(char *)(iVar8 + 0x33) = (char)((uint)uVar11 >> 0x18);
      *(undefined1 *)(iVar8 + 0x34) = 0xc6;
      *(undefined1 *)(iVar8 + 0x35) = 0;
      *(undefined1 *)(iVar8 + 0x36) = 0;
      *(undefined1 *)(iVar8 + 0x37) = 0;
      uVar11 = rsr(in_EPS6);
      *(char *)(iVar8 + 0x39) = (char)((uint)uVar11 >> 8);
      *(char *)(iVar8 + 0x38) = (char)uVar11;
      *(char *)(iVar8 + 0x3a) = (char)((uint)uVar11 >> 0x10);
      *(char *)(iVar8 + 0x3b) = (char)((uint)uVar11 >> 0x18);
      *(undefined1 *)(iVar8 + 0x3c) = 0xb1;
      *(undefined1 *)(iVar8 + 0x3d) = 0;
      *(undefined1 *)(iVar8 + 0x3e) = 0;
      *(undefined1 *)(iVar8 + 0x3f) = 0;
      uVar11 = rsr(in_EPC1);
      *(char *)(iVar8 + 0x41) = (char)((uint)uVar11 >> 8);
      *(char *)(iVar8 + 0x40) = (char)uVar11;
      *(char *)(iVar8 + 0x42) = (char)((uint)uVar11 >> 0x10);
      *(char *)(iVar8 + 0x43) = (char)((uint)uVar11 >> 0x18);
      *(undefined1 *)(iVar8 + 0x44) = 0xb2;
      *(undefined1 *)(iVar8 + 0x45) = 0;
      *(undefined1 *)(iVar8 + 0x46) = 0;
      *(undefined1 *)(iVar8 + 0x47) = 0;
      uVar11 = rsr(in_EPC2);
      *(char *)(iVar8 + 0x49) = (char)((uint)uVar11 >> 8);
      *(char *)(iVar8 + 0x48) = (char)uVar11;
      *(char *)(iVar8 + 0x4a) = (char)((uint)uVar11 >> 0x10);
      *(char *)(iVar8 + 0x4b) = (char)((uint)uVar11 >> 0x18);
      *(undefined1 *)(iVar8 + 0x4c) = 0xb3;
      *(undefined1 *)(iVar8 + 0x4d) = 0;
      *(undefined1 *)(iVar8 + 0x4e) = 0;
      *(undefined1 *)(iVar8 + 0x4f) = 0;
      uVar11 = rsr(in_EPC3);
      *(char *)(iVar8 + 0x51) = (char)((uint)uVar11 >> 8);
      *(char *)(iVar8 + 0x50) = (char)uVar11;
      *(char *)(iVar8 + 0x52) = (char)((uint)uVar11 >> 0x10);
      *(char *)(iVar8 + 0x53) = (char)((uint)uVar11 >> 0x18);
      *(undefined1 *)(iVar8 + 0x54) = 0xb4;
      *(undefined1 *)(iVar8 + 0x55) = 0;
      *(undefined1 *)(iVar8 + 0x56) = 0;
      *(undefined1 *)(iVar8 + 0x57) = 0;
      uVar11 = rsr(in_EPC4);
      *(char *)(iVar8 + 0x59) = (char)((uint)uVar11 >> 8);
      *(char *)(iVar8 + 0x58) = (char)uVar11;
      *(char *)(iVar8 + 0x5a) = (char)((uint)uVar11 >> 0x10);
      *(char *)(iVar8 + 0x5b) = (char)((uint)uVar11 >> 0x18);
      *(undefined1 *)(iVar8 + 0x5c) = 0xb5;
      *(undefined1 *)(iVar8 + 0x5d) = 0;
      *(undefined1 *)(iVar8 + 0x5e) = 0;
      *(undefined1 *)(iVar8 + 0x5f) = 0;
      uVar11 = rsr(in_EPC5);
      *(char *)(iVar8 + 0x61) = (char)((uint)uVar11 >> 8);
      *(char *)(iVar8 + 0x60) = (char)uVar11;
      *(char *)(iVar8 + 0x62) = (char)((uint)uVar11 >> 0x10);
      *(char *)(iVar8 + 99) = (char)((uint)uVar11 >> 0x18);
      *(undefined1 *)(iVar8 + 100) = 0xb6;
      *(undefined1 *)(iVar8 + 0x65) = 0;
      *(undefined1 *)(iVar8 + 0x66) = 0;
      *(undefined1 *)(iVar8 + 0x67) = 0;
      uVar11 = rsr(in_EPC6);
      *(char *)(iVar8 + 0x68) = (char)uVar11;
      *(char *)(iVar8 + 0x69) = (char)((uint)uVar11 >> 8);
      *(char *)(iVar8 + 0x6a) = (char)((uint)uVar11 >> 0x10);
      *(char *)(iVar8 + 0x6b) = (char)((uint)uVar11 >> 0x18);
      memw();
    }
    else {
      apiStack_24[0][0x15] = 0;
      apiStack_24[0][0x14] = iVar7;
      if (*apiStack_24[0] == 0) {
        uVar12 = apiStack_24[0][1];
        *(char *)(iVar4 + 0x49) = (char)(uVar12 >> 8);
        *(char *)(iVar4 + 0x4a) = (char)(uVar12 >> 0x10);
        *(char *)(iVar4 + 0x48) = (char)uVar12;
        *(char *)(iVar4 + 0x4b) = (char)(uVar12 >> 0x18);
        memw();
        iVar7 = apiStack_24[0][2];
        *(char *)(iVar4 + 0x4c) = (char)iVar7;
        *(char *)(iVar4 + 0x4d) = (char)((uint)iVar7 >> 8);
        *(char *)(iVar4 + 0x4e) = (char)((uint)iVar7 >> 0x10);
        *(char *)(iVar4 + 0x4f) = (char)((uint)iVar7 >> 0x18);
        memw();
        uVar9 = apiStack_24[0][4];
        *(char *)(iVar4 + 0x149) = (char)(uVar9 >> 8);
        *(char *)(iVar4 + 0x14a) = (char)(uVar9 >> 0x10);
        *(char *)(iVar4 + 0x14b) = (char)(uVar9 >> 0x18);
        *(char *)(iVar4 + 0x148) = (char)uVar9;
        memw();
        iVar7 = apiStack_24[0][5];
        *(char *)(iVar4 + 0x14c) = (char)iVar7;
        *(char *)(iVar4 + 0x14d) = (char)((uint)iVar7 >> 8);
        *(char *)(iVar4 + 0x14e) = (char)((uint)iVar7 >> 0x10);
        *(char *)(iVar4 + 0x14f) = (char)((uint)iVar7 >> 0x18);
        memw();
        iVar7 = apiStack_24[0][6];
        *(char *)(iVar4 + 0x150) = (char)iVar7;
        *(char *)(iVar4 + 0x151) = (char)((uint)iVar7 >> 8);
        *(char *)(iVar4 + 0x152) = (char)((uint)iVar7 >> 0x10);
        *(char *)(iVar4 + 0x153) = (char)((uint)iVar7 >> 0x18);
        memw();
        iVar7 = apiStack_24[0][7];
        *(char *)(iVar4 + 0x155) = (char)((uint)iVar7 >> 8);
        *(char *)(iVar4 + 0x156) = (char)((uint)iVar7 >> 0x10);
        uVar5 = DAT_400d0280;
        memw();
        uVar12 = uVar12 & DAT_400d0280;
        *(char *)(iVar4 + 0x154) = (char)iVar7;
        *(char *)(iVar4 + 0x157) = (char)((uint)iVar7 >> 0x18);
        *(char *)(iVar4 + 0x49) = (char)(uVar12 >> 8);
        *(char *)(iVar4 + 0x4a) = (char)(uVar12 >> 0x10);
        *(char *)(iVar4 + 0x4b) = (char)(uVar12 >> 0x18);
        memw();
        if ((int)uVar9 < 0) {
          uVar9 = uVar9 & uVar5;
          *(char *)(iVar4 + 0x149) = (char)(uVar9 >> 8);
          *(char *)(iVar4 + 0x14a) = (char)(uVar9 >> 0x10);
          *(char *)(iVar4 + 0x14b) = (char)(uVar9 >> 0x18);
          memw();
          memw();
        }
        goto LAB_400e63f4;
      }
    }
    *(char *)(iVar4 + 0x48) = (char)apiStack_24[0][1];
    memw();
    *(undefined1 *)(iVar4 + 0x49) = *(undefined1 *)((int)apiStack_24[0] + 5);
    memw();
    uVar5 = apiStack_24[0][2];
    *(undefined1 *)(iVar4 + 0x4a) = *(undefined1 *)((int)apiStack_24[0] + 6);
    memw();
    *(undefined1 *)(iVar4 + 0x4b) = *(undefined1 *)((int)apiStack_24[0] + 7);
    uVar1 = (undefined1)(uVar5 >> 8);
    *(undefined1 *)(iVar4 + 0x4d) = uVar1;
    uVar2 = (undefined1)(uVar5 >> 0x10);
    *(undefined1 *)(iVar4 + 0x4e) = uVar2;
    uVar3 = (undefined1)(uVar5 >> 0x18);
    *(undefined1 *)(iVar4 + 0x4f) = uVar3;
    *(byte *)(iVar4 + 0x4c) = (byte)uVar5;
    memw();
    iVar7 = apiStack_24[0][3];
    *(char *)(iVar4 + 0x148) = (char)iVar7;
    *(char *)(iVar4 + 0x149) = (char)((uint)iVar7 >> 8);
    *(char *)(iVar4 + 0x14a) = (char)((uint)iVar7 >> 0x10);
    *(char *)(iVar4 + 0x14b) = (char)((uint)iVar7 >> 0x18);
    memw();
    *(char *)(iVar4 + 0x5c) = (char)apiStack_24[0][0x13];
    memw();
    *(undefined1 *)(iVar4 + 0x5d) = *(undefined1 *)((int)apiStack_24[0] + 0x4d);
    memw();
    iVar7 = apiStack_24[0][0x16];
    *(undefined1 *)(iVar4 + 0x5e) = *(undefined1 *)((int)apiStack_24[0] + 0x4e);
    memw();
    *(undefined1 *)(iVar4 + 0x5f) = *(undefined1 *)((int)apiStack_24[0] + 0x4f);
    *(char *)(iVar4 + 0x50) = (char)iVar7;
    *(char *)(iVar4 + 0x51) = (char)((uint)iVar7 >> 8);
    *(char *)(iVar4 + 0x53) = (char)((uint)iVar7 >> 0x18);
    memw();
    iVar8 = apiStack_24[0][0x17];
    *(char *)(iVar4 + 0x52) = (char)((uint)iVar7 >> 0x10);
    *(char *)(iVar4 + 0x54) = (char)iVar8;
    *(char *)(iVar4 + 0x55) = (char)((uint)iVar8 >> 8);
    *(char *)(iVar4 + 0x57) = (char)((uint)iVar8 >> 0x18);
    memw();
    iVar7 = apiStack_24[0][0x18];
    *(char *)(iVar4 + 0x56) = (char)((uint)iVar8 >> 0x10);
    *(char *)(iVar4 + 0x58) = (char)iVar7;
    *(char *)(iVar4 + 0x59) = (char)((uint)iVar7 >> 8);
    *(char *)(iVar4 + 0x5a) = (char)((uint)iVar7 >> 0x10);
    *(char *)(iVar4 + 0x5b) = (char)((uint)iVar7 >> 0x18);
    memw();
    if ((uVar5 & 0x20) != 0) {
      *(byte *)(iVar4 + 0x4c) = (byte)uVar5 & 0xef;
      *(undefined1 *)(iVar4 + 0x4d) = uVar1;
      *(undefined1 *)(iVar4 + 0x4e) = uVar2;
      *(undefined1 *)(iVar4 + 0x4f) = uVar3;
      memw();
      memw();
    }
  }
LAB_400e63f4:
  *param_2 = iVar4;
  memw();
  return 0x24c;
}



// Function at 0x400e67f8

void FUN_400e67f8(undefined4 param_1)

{
  undefined1 *puVar1;
  
  puVar1 = DAT_400d11e4;
  *DAT_400d11e4 = (char)param_1;
  puVar1[1] = (char)((uint)param_1 >> 8);
  puVar1[2] = (char)((uint)param_1 >> 0x10);
  puVar1[3] = (char)((uint)param_1 >> 0x18);
  memw();
  memw();
  return;
}



// Function at 0x400e681c

undefined4 FUN_400e681c(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = DAT_400d11e4;
  }
  memw();
  return 0x94;
}



// Function at 0x400e6830

void FUN_400e6830(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_400d1244;
  if (param_1 != (undefined4 *)0x0) {
    *DAT_400d1244 = 0;
    puVar1[1] = 0;
    *param_1 = puVar1;
  }
  memw();
  return;
}



// Function at 0x400e6848

void FUN_400e6848(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int extraout_a3;
  int iVar2;
  
  iVar2 = param_2;
  if (param_1 == (undefined4 *)0x0) {
    func_0x4008dacc(DAT_400d1250,0x58,DAT_400d124c,DAT_400d1248);
    iVar2 = extraout_a3;
  }
  if (param_2 == 0) {
    uVar1 = func_0x4008d960();
    (*DAT_400d092c)(DAT_400d1258,uVar1,DAT_400d1254);
  }
  else {
    uVar1 = (*DAT_400d080c)(*param_1,iVar2,param_3);
    *param_1 = uVar1;
    param_1[1] = param_1[1] + param_3;
  }
  memw();
  return;
}



// Function at 0x400e6890

undefined4 FUN_400e6890(int param_1,int *param_2)

{
  if ((param_1 == 0) && (param_2 != (int *)0x0 && param_1 == 0)) {
    func_0x4008dacc(DAT_400d1250,0x71,DAT_400d1260,DAT_400d125c);
  }
  if (param_2 != (int *)0x0) {
    *param_2 = param_1;
  }
  memw();
  return 4;
}



// Function at 0x400e68c4

void FUN_400e68c4(int param_1,undefined4 *param_2)

{
  int extraout_a3;
  int iVar1;
  
  iVar1 = param_1;
  if (param_2 == (undefined4 *)0x0) {
    func_0x4008dacc(DAT_400d1250,0xb2,DAT_400d1268,DAT_400d1264);
    iVar1 = extraout_a3;
  }
  if (param_1 != 0) {
    (*DAT_400d092c)(DAT_400d126c,iVar1);
  }
  (*DAT_400d092c)(DAT_400d1270,*param_2);
  (*DAT_400d092c)(DAT_400d1274);
  return;
}



// Function at 0x400e6900

undefined4 FUN_400e6900(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_400e6940();
  return *(undefined4 *)(iVar1 + param_1 * 0x10 + 4);
}



// Function at 0x400e6914

undefined4 FUN_400e6914(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_400e6940();
  return *(undefined4 *)(iVar1 + param_1 * 0x10);
}



// Function at 0x400e6928

undefined4 FUN_400e6928(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_400e6940();
  return *(undefined4 *)(iVar1 + param_1 * 0x10 + param_2 * 4 + 8);
}



// Function at 0x400e6940

undefined4 FUN_400e6940(void)

{
  return DAT_400d1278;
}



// Function at 0x400e6948

void FUN_400e6948(void)

{
  FUN_400f91d0(DAT_400d127c,1);
  FUN_400f91d0(DAT_400d1280,1);
  FUN_400f91d0(DAT_400d1284,1);
  FUN_400f91d0(DAT_400d1288,1);
  return;
}



// Function at 0x400e6970

void FUN_400e6970(int param_1,byte *param_2)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint *puStack_150;
  uint *puStack_14c;
  int iStack_148;
  uint local_140 [4];
  uint uStack_130;
  uint uStack_12c;
  uint uStack_128;
  uint uStack_124;
  uint local_120 [72];
  
  puStack_150 = (uint *)(param_1 + 8);
  puStack_14c = local_140;
  local_140[0] = *puStack_150;
  local_120[0] = (uint)*param_2 << 0x18 | (uint)param_2[1] << 0x10 | (uint)param_2[3] |
                 (uint)param_2[2] << 8;
  piVar3 = DAT_400d128c;
  puVar4 = local_120;
  do {
    iVar5 = ((uint)(CONCAT44(uStack_130,uStack_130) >> 6) ^
             (uint)(CONCAT44(uStack_130,uStack_130) >> 0xb) ^
            (uint)(CONCAT44(uStack_130,uStack_130) >> 0x19)) + *piVar3 + *puVar4 +
            ((uStack_128 ^ uStack_12c) & uStack_130 ^ uStack_128) + uStack_124;
    uVar7 = local_140[3] + iVar5;
    uVar6 = ((uint)(CONCAT44(local_140[0],local_140[0]) >> 2) ^
             (uint)(CONCAT44(local_140[0],local_140[0]) >> 0xd) ^
            (uint)(CONCAT44(local_140[0],local_140[0]) >> 0x16)) +
            ((local_140[0] | local_140[1]) & local_140[2] | local_140[0] & local_140[1]) + iVar5;
    iVar5 = piVar3[1] + puVar4[1] + uStack_128 + ((uStack_130 ^ uStack_12c) & uVar7 ^ uStack_12c) +
            ((uint)(CONCAT44(uVar7,uVar7) >> 6) ^ (uint)(CONCAT44(uVar7,uVar7) >> 0xb) ^
            (uint)(CONCAT44(uVar7,uVar7) >> 0x19));
    uVar10 = ((uint)(CONCAT44(uVar6,uVar6) >> 2) ^ (uint)(CONCAT44(uVar6,uVar6) >> 0xd) ^
             (uint)(CONCAT44(uVar6,uVar6) >> 0x16)) +
             ((uVar6 | local_140[0]) & local_140[1] | uVar6 & local_140[0]) + iVar5;
    uVar8 = local_140[2] + iVar5;
    iVar5 = piVar3[2] + puVar4[2] + uStack_12c + ((uVar7 ^ uStack_130) & uVar8 ^ uStack_130) +
            ((uint)(CONCAT44(uVar8,uVar8) >> 6) ^ (uint)(CONCAT44(uVar8,uVar8) >> 0xb) ^
            (uint)(CONCAT44(uVar8,uVar8) >> 0x19));
    uVar12 = ((uint)(CONCAT44(uVar10,uVar10) >> 2) ^ (uint)(CONCAT44(uVar10,uVar10) >> 0xd) ^
             (uint)(CONCAT44(uVar10,uVar10) >> 0x16)) +
             ((uVar6 | uVar10) & local_140[0] | uVar6 & uVar10) + iVar5;
    uVar9 = local_140[1] + iVar5;
    iVar5 = piVar3[3] + puVar4[3] + uStack_130 + ((uVar7 ^ uVar8) & uVar9 ^ uVar7) +
            ((uint)(CONCAT44(uVar9,uVar9) >> 6) ^ (uint)(CONCAT44(uVar9,uVar9) >> 0xb) ^
            (uint)(CONCAT44(uVar9,uVar9) >> 0x19));
    uVar11 = ((uint)(CONCAT44(uVar12,uVar12) >> 2) ^ (uint)(CONCAT44(uVar12,uVar12) >> 0xd) ^
             (uint)(CONCAT44(uVar12,uVar12) >> 0x16)) +
             ((uVar10 | uVar12) & uVar6 | uVar10 & uVar12) + iVar5;
    local_140[0] = local_140[0] + iVar5;
    iVar5 = piVar3[4] + puVar4[4] + uVar7 + ((uVar8 ^ uVar9) & local_140[0] ^ uVar8) +
            ((uint)(CONCAT44(local_140[0],local_140[0]) >> 6) ^
             (uint)(CONCAT44(local_140[0],local_140[0]) >> 0xb) ^
            (uint)(CONCAT44(local_140[0],local_140[0]) >> 0x19));
    local_140[3] = ((uint)(CONCAT44(uVar11,uVar11) >> 2) ^ (uint)(CONCAT44(uVar11,uVar11) >> 0xd) ^
                   (uint)(CONCAT44(uVar11,uVar11) >> 0x16)) +
                   ((uVar12 | uVar11) & uVar10 | uVar12 & uVar11) + iVar5;
    uStack_124 = uVar6 + iVar5;
    iVar5 = piVar3[5] + puVar4[5] + uVar8 + ((uVar9 ^ local_140[0]) & uStack_124 ^ uVar9) +
            ((uint)(CONCAT44(uStack_124,uStack_124) >> 6) ^
             (uint)(CONCAT44(uStack_124,uStack_124) >> 0xb) ^
            (uint)(CONCAT44(uStack_124,uStack_124) >> 0x19));
    local_140[2] = ((uint)(CONCAT44(local_140[3],local_140[3]) >> 2) ^
                    (uint)(CONCAT44(local_140[3],local_140[3]) >> 0xd) ^
                   (uint)(CONCAT44(local_140[3],local_140[3]) >> 0x16)) +
                   ((uVar11 | local_140[3]) & uVar12 | uVar11 & local_140[3]) + iVar5;
    uStack_128 = uVar10 + iVar5;
    iVar5 = piVar3[6] + puVar4[6] + uVar9 +
            ((local_140[0] ^ uStack_124) & uStack_128 ^ local_140[0]) +
            ((uint)(CONCAT44(uStack_128,uStack_128) >> 6) ^
             (uint)(CONCAT44(uStack_128,uStack_128) >> 0xb) ^
            (uint)(CONCAT44(uStack_128,uStack_128) >> 0x19));
    local_140[1] = ((uint)(CONCAT44(local_140[2],local_140[2]) >> 2) ^
                    (uint)(CONCAT44(local_140[2],local_140[2]) >> 0xd) ^
                   (uint)(CONCAT44(local_140[2],local_140[2]) >> 0x16)) +
                   ((local_140[3] | local_140[2]) & uVar11 | local_140[3] & local_140[2]) + iVar5;
    uStack_12c = uVar12 + iVar5;
    puVar1 = puVar4 + 7;
    puVar4 = puVar4 + 8;
    piVar2 = piVar3 + 7;
    piVar3 = piVar3 + 8;
    iVar5 = *piVar2 + *puVar1 + local_140[0] + ((uStack_124 ^ uStack_128) & uStack_12c ^ uStack_124)
            + ((uint)(CONCAT44(uStack_12c,uStack_12c) >> 6) ^
               (uint)(CONCAT44(uStack_12c,uStack_12c) >> 0xb) ^
              (uint)(CONCAT44(uStack_12c,uStack_12c) >> 0x19));
    uStack_130 = uVar11 + iVar5;
    local_140[0] = ((uint)(CONCAT44(local_140[1],local_140[1]) >> 2) ^
                    (uint)(CONCAT44(local_140[1],local_140[1]) >> 0xd) ^
                   (uint)(CONCAT44(local_140[1],local_140[1]) >> 0x16)) +
                   ((local_140[2] | local_140[1]) & local_140[3] | local_140[2] & local_140[1]) +
                   iVar5;
  } while (DAT_400d1290 != piVar3);
  iStack_148 = 6;
  puVar4 = local_120;
  do {
    uVar6 = puVar4[0xe];
    uVar7 = puVar4[1];
    uVar6 = ((uint)(CONCAT44(uVar6,uVar6) >> 0x11) ^ (uint)(CONCAT44(uVar6,uVar6) >> 0x13) ^
            uVar6 >> 10) + puVar4[9] + *puVar4 +
            ((uint)(CONCAT44(uVar7,uVar7) >> 7) ^ (uint)(CONCAT44(uVar7,uVar7) >> 0x12) ^ uVar7 >> 3
            );
    puVar4[0x10] = uVar6;
    uVar9 = puVar4[0xf];
    uVar8 = puVar4[2];
    uVar7 = ((uint)(CONCAT44(uVar9,uVar9) >> 0x11) ^ (uint)(CONCAT44(uVar9,uVar9) >> 0x13) ^
            uVar9 >> 10) + uVar7 + puVar4[10] +
            ((uint)(CONCAT44(uVar8,uVar8) >> 7) ^ (uint)(CONCAT44(uVar8,uVar8) >> 0x12) ^ uVar8 >> 3
            );
    uVar9 = puVar4[3];
    uVar8 = ((uint)(CONCAT44(uVar6,uVar6) >> 0x11) ^ (uint)(CONCAT44(uVar6,uVar6) >> 0x13) ^
            uVar6 >> 10) + uVar8 + puVar4[0xb] +
            ((uint)(CONCAT44(uVar9,uVar9) >> 7) ^ (uint)(CONCAT44(uVar9,uVar9) >> 0x12) ^ uVar9 >> 3
            );
    uVar11 = puVar4[4];
    puVar4[0x11] = uVar7;
    uVar7 = ((uint)(CONCAT44(uVar7,uVar7) >> 0x11) ^ (uint)(CONCAT44(uVar7,uVar7) >> 0x13) ^
            uVar7 >> 10) + uVar9 + puVar4[0xc] +
            ((uint)(CONCAT44(uVar11,uVar11) >> 7) ^ (uint)(CONCAT44(uVar11,uVar11) >> 0x12) ^
            uVar11 >> 3);
    puVar4[0x12] = uVar8;
    uVar10 = puVar4[5];
    uVar8 = ((uint)(CONCAT44(uVar8,uVar8) >> 0x11) ^ (uint)(CONCAT44(uVar8,uVar8) >> 0x13) ^
            uVar8 >> 10) + uVar11 + puVar4[0xd] +
            ((uint)(CONCAT44(uVar10,uVar10) >> 7) ^ (uint)(CONCAT44(uVar10,uVar10) >> 0x12) ^
            uVar10 >> 3);
    puVar4[0x13] = uVar7;
    uVar9 = puVar4[6];
    uVar7 = ((uint)(CONCAT44(uVar7,uVar7) >> 0x11) ^ (uint)(CONCAT44(uVar7,uVar7) >> 0x13) ^
            uVar7 >> 10) + puVar4[0xe] + uVar10 +
            ((uint)(CONCAT44(uVar9,uVar9) >> 7) ^ (uint)(CONCAT44(uVar9,uVar9) >> 0x12) ^ uVar9 >> 3
            );
    puVar4[0x14] = uVar8;
    uVar10 = puVar4[7];
    puVar4[0x16] = ((uint)(CONCAT44(uVar8,uVar8) >> 0x11) ^ (uint)(CONCAT44(uVar8,uVar8) >> 0x13) ^
                   uVar8 >> 10) + puVar4[0xf] + uVar9 +
                   ((uint)(CONCAT44(uVar10,uVar10) >> 7) ^ (uint)(CONCAT44(uVar10,uVar10) >> 0x12) ^
                   uVar10 >> 3);
    puVar4[0x15] = uVar7;
    uVar8 = puVar4[8];
    puVar4[0x17] = ((uint)(CONCAT44(uVar7,uVar7) >> 0x11) ^ (uint)(CONCAT44(uVar7,uVar7) >> 0x13) ^
                   uVar7 >> 10) + uVar6 + uVar10 +
                   ((uint)(CONCAT44(uVar8,uVar8) >> 7) ^ (uint)(CONCAT44(uVar8,uVar8) >> 0x12) ^
                   uVar8 >> 3);
    iStack_148 = iStack_148 + -1;
    puVar4 = puVar4 + 8;
  } while (iStack_148 != 0);
  do {
    uVar6 = *puStack_14c;
    puStack_14c = puStack_14c + 1;
    *puStack_150 = *puStack_150 + uVar6;
    puStack_150 = puStack_150 + 1;
  } while ((uint *)(param_1 + 0x28) != puStack_150);
  memw();
  return;
}



// Function at 0x400e7190

void FUN_400e7190(undefined4 param_1)

{
  func_0x40086818(param_1,0,0x70);
  return;
}



// Function at 0x400e71a4

void FUN_400e71a4(undefined1 *param_1)

{
  undefined1 *puVar1;
  
  if (param_1 != (undefined1 *)0x0) {
    if (*(int *)(param_1 + 0x6c) == 1) {
      FUN_400e7600();
    }
    puVar1 = param_1 + 0x70;
    while (param_1 != puVar1) {
      memw();
      *param_1 = 0;
      param_1 = param_1 + 1;
      memw();
    }
  }
  return;
}



// Function at 0x400e71d0

undefined4 FUN_400e71d0(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  if (param_2 == 0) {
    param_1[2] = DAT_400d1294;
    param_1[3] = DAT_400d1298;
    param_1[4] = DAT_400d129c;
    param_1[5] = DAT_400d12a0;
    param_1[6] = DAT_400d12a4;
    param_1[7] = DAT_400d12a8;
    param_1[8] = DAT_400d12ac;
    uVar1 = DAT_400d12b0;
  }
  else {
    param_1[2] = DAT_400d12b4;
    param_1[3] = DAT_400d12b8;
    param_1[4] = DAT_400d12bc;
    param_1[5] = DAT_400d12c0;
    param_1[6] = DAT_400d12c4;
    param_1[7] = DAT_400d12c8;
    param_1[8] = DAT_400d12cc;
    memw();
    uVar1 = DAT_400d12d0;
  }
  param_1[9] = uVar1;
  param_1[0x1a] = param_2;
  if (param_1[0x1b] == 1) {
    memw();
    FUN_400e7600();
  }
  param_1[0x1b] = 0;
  memw();
  return 0;
}



// Function at 0x400e7250

undefined4 FUN_400e7250(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0x6c) == 0) {
    if ((*(int *)(param_1 + 0x68) == 0) && (iVar1 = FUN_400e75ec(1), iVar1 != 0)) {
      *(undefined4 *)(param_1 + 0x6c) = 1;
    }
    else {
      *(undefined4 *)(param_1 + 0x6c) = 2;
      iVar1 = 0;
      memw();
    }
  }
  if (*(int *)(param_1 + 0x6c) == 1) {
    memw();
    FUN_400e7678();
  }
  else {
    FUN_400e6970(param_1,param_2,iVar1);
  }
  return 0;
}



// Function at 0x400e72a0

int FUN_400e72a0(uint *param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *param_1 & 0x3f;
  uVar2 = *param_1 + param_3;
  uVar4 = 0x40 - uVar3;
  *param_1 = uVar2;
  if (uVar2 < param_3) {
    param_1[1] = param_1[1] + 1;
  }
  if ((uVar3 != 0) && (uVar4 <= param_3)) {
    memw();
    func_0x400866b8((int)(param_1 + 10) + uVar3,param_2,uVar4);
    iVar1 = FUN_400e7250(param_1,param_1 + 10);
    if (iVar1 != 0) {
      return iVar1;
    }
    param_3 = uVar3 + (param_3 - 0x40);
    param_2 = param_2 + uVar4;
    uVar3 = 0;
  }
  param_2 = param_2 + param_3;
  while( true ) {
    iVar1 = param_2 - param_3;
    if (param_3 < 0x40) {
      if (param_3 != 0) {
        func_0x400866b8((int)param_1 + uVar3 + 0x28,iVar1,param_3);
      }
      return 0;
    }
    iVar1 = FUN_400e7250(param_1,iVar1);
    if (iVar1 != 0) break;
    param_3 = param_3 - 0x40;
  }
  return iVar1;
}



// Function at 0x400e7314

undefined4 FUN_400e7314(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_3 != 0) {
    uVar1 = FUN_400e72a0(param_1,param_2,param_3);
  }
  return uVar1;
}



// Function at 0x400e732c

int FUN_400e732c(uint *param_1,undefined1 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  byte bStack_29;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_25;
  int iStack_24;
  
  piVar1 = DAT_400d0098;
  uVar4 = *param_1;
  memw();
  iStack_24 = *DAT_400d0098;
  iVar3 = param_1[1] << 3;
  memw();
  bStack_29 = (byte)iVar3 | (byte)(uVar4 >> 0x1d);
  uStack_2c = (undefined1)((uint)iVar3 >> 0x18);
  iVar2 = uVar4 << 3;
  uStack_2b = (undefined1)((uint)iVar3 >> 0x10);
  uStack_28 = (undefined1)((uint)iVar2 >> 0x18);
  uStack_27 = (undefined1)((uint)iVar2 >> 0x10);
  uStack_26 = (undefined1)((uint)iVar2 >> 8);
  uVar4 = uVar4 & 0x3f;
  iVar5 = 0x78 - uVar4;
  uStack_25 = (undefined1)iVar2;
  uStack_2a = (undefined1)((uint)iVar3 >> 8);
  memw();
  if (uVar4 < 0x38) {
    iVar5 = 0x38 - uVar4;
  }
  memw();
  iVar2 = FUN_400e7314(param_1,DAT_400d12d4,iVar5);
  if ((iVar2 == 0) && (iVar2 = FUN_400e72a0(param_1,&uStack_2c,8), iVar2 == 0)) {
    if (param_1[0x1b] == 1) {
      FUN_400e7648(1,param_1 + 2);
    }
    *param_2 = *(undefined1 *)((int)param_1 + 0xb);
    memw();
    param_2[1] = (char)*(undefined2 *)((int)param_1 + 10);
    memw();
    param_2[2] = (char)(param_1[2] >> 8);
    memw();
    param_2[3] = (char)param_1[2];
    memw();
    param_2[4] = *(undefined1 *)((int)param_1 + 0xf);
    memw();
    param_2[5] = (char)*(undefined2 *)((int)param_1 + 0xe);
    memw();
    param_2[6] = (char)(param_1[3] >> 8);
    memw();
    param_2[7] = (char)param_1[3];
    memw();
    param_2[8] = *(undefined1 *)((int)param_1 + 0x13);
    memw();
    param_2[9] = (char)*(undefined2 *)((int)param_1 + 0x12);
    memw();
    param_2[10] = (char)(param_1[4] >> 8);
    memw();
    param_2[0xb] = (char)param_1[4];
    memw();
    param_2[0xc] = *(undefined1 *)((int)param_1 + 0x17);
    memw();
    param_2[0xd] = (char)*(undefined2 *)((int)param_1 + 0x16);
    memw();
    param_2[0xe] = (char)(param_1[5] >> 8);
    memw();
    param_2[0xf] = (char)param_1[5];
    memw();
    param_2[0x10] = *(undefined1 *)((int)param_1 + 0x1b);
    memw();
    param_2[0x11] = (char)*(undefined2 *)((int)param_1 + 0x1a);
    memw();
    param_2[0x12] = (char)(param_1[6] >> 8);
    memw();
    param_2[0x13] = (char)param_1[6];
    memw();
    param_2[0x14] = *(undefined1 *)((int)param_1 + 0x1f);
    memw();
    param_2[0x15] = (char)*(undefined2 *)((int)param_1 + 0x1e);
    memw();
    param_2[0x16] = (char)(param_1[7] >> 8);
    memw();
    param_2[0x17] = (char)param_1[7];
    memw();
    param_2[0x18] = *(undefined1 *)((int)param_1 + 0x23);
    memw();
    param_2[0x19] = (char)*(undefined2 *)((int)param_1 + 0x22);
    memw();
    param_2[0x1a] = (char)(param_1[8] >> 8);
    memw();
    param_2[0x1b] = (char)param_1[8];
    memw();
    if (param_1[0x1a] == 0) {
      param_2[0x1c] = *(undefined1 *)((int)param_1 + 0x27);
      memw();
      param_2[0x1d] = (char)*(undefined2 *)((int)param_1 + 0x26);
      memw();
      param_2[0x1e] = (char)(param_1[9] >> 8);
      memw();
      param_2[0x1f] = (char)param_1[9];
      memw();
      iVar2 = 0;
    }
  }
  if (param_1[0x1b] == 1) {
    memw();
    FUN_400e7600();
    param_1[0x1b] = 2;
  }
  memw();
  memw();
  if (iStack_24 != *piVar1) {
    memw();
    iVar2 = func_0x400831d4();
    return iVar2;
  }
  return iVar2;
}



// Function at 0x400e7514

int FUN_400e7514(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int in_SCOMPARE1;
  
  iVar1 = DAT_400d12d8;
  iVar4 = 0;
  if ((param_1 != 0) && (iVar4 = 1, param_1 != 1)) {
    iVar4 = 2;
  }
  piVar5 = (int *)(DAT_400d12d8 + iVar4 * 4);
  memw();
  iVar2 = *piVar5;
  if (iVar2 == 0) {
    iVar3 = func_0x400890ac(1,0,3);
    iVar2 = iVar3;
    if (iVar3 == 0) {
      iVar2 = func_0x4008dacc(DAT_400d12e4,0x72,DAT_400d12e0,DAT_400d12dc);
    }
    func_0x40089194(iVar2,0,0,0);
    wsr((char)in_SCOMPARE1,0);
    iVar2 = *piVar5;
    if (iVar2 == in_SCOMPARE1) {
      *piVar5 = iVar3;
    }
    if (iVar2 != 0) {
      func_0x400899b0(iVar3);
    }
    memw();
    iVar2 = *(int *)(iVar1 + iVar4 * 4);
  }
  return iVar2;
}



// Function at 0x400e7574

undefined4 FUN_400e7574(undefined4 param_1,undefined4 param_2)

{
  byte *pbVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  byte bVar5;
  
  uVar2 = FUN_400e7514(param_1);
  iVar3 = func_0x400896ec(uVar2,param_2);
  uVar2 = DAT_400d12e8;
  uVar4 = 0;
  if (iVar3 != 0) {
    func_0x4008b620(DAT_400d12e8,0xffffffff);
    pbVar1 = DAT_400d12ec;
    if (*DAT_400d12ec == 0) {
      FUN_400da230(0x1f);
    }
    bVar5 = *pbVar1 + 1;
    *pbVar1 = bVar5;
    memw();
    if (3 < bVar5) {
      memw();
      func_0x4008dacc(DAT_400d12e4,0xa0,DAT_400d12f4,DAT_400d12f0);
    }
    func_0x4008b770(uVar2);
    uVar4 = 1;
  }
  return uVar4;
}



// Function at 0x400e75d0

void FUN_400e75d0(void)

{
  func_0x4008b620(DAT_400d12f8,0xffffffff);
  return;
}



// Function at 0x400e75e0

void FUN_400e75e0(void)

{
  func_0x4008b770(DAT_400d12f8);
  return;
}



// Function at 0x400e75ec

undefined4 FUN_400e75ec(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400e7574(param_1,0);
  return uVar1;
}



// Function at 0x400e7600

void FUN_400e7600(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = FUN_400e7514(param_1);
  uVar2 = DAT_400d12e8;
  func_0x4008b620(DAT_400d12e8,0xffffffff);
  cVar1 = *DAT_400d12ec;
  *DAT_400d12ec = cVar1 + -1;
  memw();
  if ((char)(cVar1 + -1) == '\0') {
    memw();
    FUN_400da2dc(0x1f);
  }
  func_0x4008b770(uVar2);
  func_0x40089194(uVar3,0,0);
  return;
}



// Function at 0x400e7648

void FUN_400e7648(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  FUN_400e7514(param_1);
  iVar1 = func_0x40089984();
  if (iVar1 != 0) {
    func_0x4008dacc(DAT_400d12e4,0xc1,DAT_400d1300,DAT_400d12fc);
  }
  FUN_400e789c();
  FUN_400e75d0();
  FUN_400e7918(param_1,param_2);
  FUN_400e75e0();
  return;
}



// Function at 0x400e7678

void FUN_400e7678(int param_1,undefined4 param_2,undefined1 param_3)

{
  int iVar1;
  
  FUN_400e7514(param_1);
  iVar1 = func_0x40089984();
  if (iVar1 != 0) {
    func_0x4008dacc(DAT_400d12e4,0xd5,DAT_400d1304,DAT_400d12fc);
  }
  FUN_400e789c();
  FUN_400e75d0();
  if (-1 < param_1) {
    if (param_1 < 2) {
      iVar1 = 0x10;
    }
    else if (param_1 < 4) {
      iVar1 = 0x20;
    }
  }
  FUN_400e78c8(param_1,param_2,iVar1,param_3);
  FUN_400e75e0();
  return;
}



// Function at 0x400e7720

undefined4 FUN_400e7720(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400e7740();
  return uVar1;
}



// Function at 0x400e7740

undefined4 FUN_400e7740(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  code *pcVar5;
  int iVar6;
  
  iVar6 = DAT_400e772c;
  piVar1 = DAT_400e76c4;
  if (*(int *)(DAT_400e772c + 8) == 0) {
    iVar3 = (**(code **)(*DAT_400e76c4 + 0x18))(1);
    *(int *)(iVar6 + 8) = iVar3;
    if (iVar3 == 0) {
      memw();
      uVar4 = (**(code **)(*piVar1 + 0x4c))();
      FUN_400e7874(DAT_400e7730,uVar4);
      return 0x101;
    }
  }
  piVar2 = DAT_400e7734;
  piVar1 = DAT_400e76c4;
  if (*DAT_400e7734 == 0) {
    iVar3 = (**(code **)(*DAT_400e76c4 + 4))();
    *piVar2 = iVar3;
    if (iVar3 == 0) {
      memw();
      uVar4 = (**(code **)(*piVar1 + 0x4c))();
      FUN_400e7874(DAT_400e7738,uVar4);
      iVar6 = *(int *)(iVar6 + 8);
      pcVar5 = *(code **)(*piVar1 + 0x1c);
      goto LAB_400e77d6;
    }
  }
  iVar3 = FUN_400e77ec();
  piVar1 = DAT_400e76c4;
  if (iVar3 == 0) {
    return 0;
  }
  uVar4 = (**(code **)(*DAT_400e76c4 + 0x4c))();
  FUN_400e7874(DAT_400e773c,uVar4);
  (**(code **)(*piVar1 + 0x1c))(*(undefined4 *)(iVar6 + 8));
  iVar6 = *piVar2;
  pcVar5 = *(code **)(*piVar1 + 8);
LAB_400e77d6:
  (*pcVar5)(iVar6);
  return 0x101;
}



// Function at 0x400e77ec

undefined4 FUN_400e77ec(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  puVar2 = DAT_400e77e0;
  piVar1 = DAT_400e76c4;
  if (DAT_400e77e0[4] == 0) {
    iVar3 = (**(code **)(*DAT_400e76c4 + 0x18))(1);
    puVar2[4] = iVar3;
    if (iVar3 == 0) {
      memw();
      uVar4 = (**(code **)(*piVar1 + 0x4c))();
      FUN_400e7874(DAT_400e77e4,uVar4);
      return 0x101;
    }
  }
  *puVar2 = DAT_400e77e8;
  memw();
  return 0;
}



// Function at 0x400e7830

undefined4 FUN_400e7830(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  undefined1 auStack_74 [80];
  int iStack_24;
  
  piVar1 = DAT_400d0098;
  memw();
  iStack_24 = *DAT_400d0098;
  memw();
  memw();
  uVar2 = FUN_400f12b4(auStack_74,0x4f,param_1,param_2,param_3,param_4);
  memw();
  memw();
  if (iStack_24 != *piVar1) {
    uVar2 = func_0x400831d4();
    return uVar2;
  }
  return uVar2;
}



// Function at 0x400e7874

undefined4
FUN_400e7874(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  undefined1 auStack_50 [4];
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined4 uStack_24;
  undefined1 auStack_20 [32];
  
  puStack_28 = auStack_50;
  puStack_2c = auStack_20;
  uStack_24 = 4;
  memw();
  uStack_4c = param_2;
  uStack_48 = param_3;
  uStack_44 = param_4;
  uStack_40 = param_5;
  uStack_3c = param_6;
  uVar1 = FUN_400e7830(param_1,puStack_2c,auStack_50);
  return uVar1;
}



// Function at 0x400e789c

void FUN_400e789c(void)

{
  int iVar1;
  
  do {
    do {
      iVar1 = func_0x40084644(DAT_400d1308);
    } while (iVar1 != 0);
    iVar1 = func_0x40084644(DAT_400d130c);
  } while (((iVar1 != 0) || (iVar1 = func_0x40084644(DAT_400d1310), iVar1 != 0)) ||
          (iVar1 = func_0x40084644(DAT_400d1314), iVar1 != 0));
  return;
}



// Function at 0x400e78c8

void FUN_400e78c8(int param_1,undefined4 *param_2,int param_3,char param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  FUN_400e789c();
  puVar1 = param_2 + param_3;
  iVar3 = DAT_400d1318 - (int)param_2;
  while (param_2 != puVar1) {
    uVar2 = (*DAT_400d1324)(*param_2);
    puVar4 = (undefined4 *)(iVar3 + (int)param_2);
    param_2 = param_2 + 1;
    *puVar4 = uVar2;
    memw();
  }
  if (param_4 == '\0') {
    puVar1 = (undefined4 *)(param_1 * 0x10 + DAT_400d1320);
  }
  else {
    puVar1 = (undefined4 *)((param_1 + DAT_400d131c) * 0x10);
  }
  memw();
  *puVar1 = 1;
  memw();
  return;
}



// Function at 0x400e7918

void FUN_400e7918(uint param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  undefined4 uVar5;
  
  memw();
  *(undefined4 *)(param_1 * 0x10 + DAT_400d1328) = 1;
  uVar2 = 8;
  if (param_1 != 1) {
    if (1 < (int)param_1) goto LAB_400e7963;
    uVar2 = 0;
    if (param_1 == 0) {
      uVar2 = 5;
    }
  }
  do {
    param_1 = param_1 - 2;
    memw();
    FUN_400e789c();
    if (param_1 < 2) {
      uVar5 = rsil(5);
      param_1 = 0;
      puVar3 = param_2;
      while (param_1 < uVar2) {
        iVar4 = param_1 * 4;
        uVar1 = func_0x4008465c(iVar4 + DAT_400d1318);
        param_1 = param_1 + 2;
        puVar3[1] = uVar1;
        memw();
        uVar1 = func_0x4008465c(iVar4 + DAT_400d132c);
        *puVar3 = uVar1;
        puVar3 = puVar3 + 2;
        memw();
      }
      (*DAT_400d1330)(uVar5);
    }
    else {
      func_0x40084668(param_2,DAT_400d1318,uVar2);
    }
    puVar3 = param_2 + uVar2;
    while (puVar3 != param_2) {
      param_1 = *param_2;
      param_2 = param_2 + 1;
      if (param_1 != 0) {
        return;
      }
    }
    func_0x4008da40();
LAB_400e7963:
    uVar2 = 0;
    if ((int)param_1 < 4) {
      uVar2 = 0x10;
    }
  } while( true );
}



// Function at 0x400e79b4

undefined4 FUN_400e79b4(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400e7afc(param_1,param_2);
  return uVar1;
}



// Function at 0x400e79c8

void FUN_400e79c8(undefined4 param_1)

{
  FUN_400e8230(param_1);
  return;
}



// Function at 0x400e79d4

int FUN_400e79d4(int param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  int *piVar5;
  
  if (param_1 == 0) {
    param_1 = 1;
  }
  while (iVar3 = func_0x4008dbdc(param_1), iVar3 == 0) {
    pcVar4 = (code *)FUN_400e823c();
    if (pcVar4 == (code *)0x0) {
      piVar5 = (int *)FUN_400e86f4(4);
      uVar2 = DAT_400d133c;
      puVar1 = PTR_FUN_400d1338;
      param_1 = DAT_400d1334;
      *piVar5 = DAT_400d1334;
      pcVar4 = (code *)FUN_400e7a74(piVar5,uVar2,puVar1);
    }
    (*pcVar4)();
  }
  return iVar3;
}



// Function at 0x400e7a08

void FUN_400e7a08(uint param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *in_t0;
  int in_SCOMPARE1;
  
  piVar3 = (int *)(param_2 + -0x40);
  if (1 < param_1) {
    piVar3 = in_t0;
    FUN_400e824c(*(undefined4 *)(param_2 + -0x24));
  }
  memw();
  iVar4 = *piVar3;
  do {
    iVar5 = iVar4 + -1;
    wsr((char)in_SCOMPARE1,iVar4);
    iVar2 = *piVar3;
    if (iVar2 == in_SCOMPARE1) {
      *piVar3 = iVar5;
    }
    bVar1 = iVar2 != iVar4;
    iVar4 = iVar2;
  } while (bVar1);
  if (iVar5 == 0) {
    if ((code *)piVar3[5] != (code *)0x0) {
      (*(code *)piVar3[5])(param_2 + 0x20);
    }
    FUN_400e8724(param_2 + 0x20);
  }
  return;
}



// Function at 0x400e7a44

void FUN_400e7a44(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  *(undefined4 *)(param_1 + -0x60) = 0;
  *(undefined4 *)(param_1 + -0x50) = param_2;
  *(undefined4 *)(param_1 + -0x4c) = param_3;
  uVar2 = FUN_400e82a8();
  *(undefined4 *)(param_1 + -0x48) = uVar2;
  uVar3 = FUN_400e8280();
  uVar2 = DAT_400d1344;
  *(undefined4 *)(param_1 + -0x20) = DAT_400d1340;
  puVar1 = PTR_FUN_400d1348;
  *(undefined4 *)(param_1 + -0x44) = uVar3;
  *(undefined4 *)(param_1 + -0x1c) = uVar2;
  *(undefined **)(param_1 + -0x18) = puVar1;
  return;
}



// Function at 0x400e7a74

void FUN_400e7a74(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  
  iVar1 = FUN_400e81c0();
  *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
  puVar2 = (undefined4 *)FUN_400e7a44(param_1,param_2,param_3);
  *puVar2 = 1;
  FUN_400e8d60(puVar2 + 0x10);
  FUN_400e832c(puVar2 + 0x10);
  piVar3 = (int *)FUN_400e8290();
  cust0();
  iVar4 = *piVar3;
  iVar1 = (int)puVar2 + 0x41;
  piVar3[1] = iVar1;
  if (iVar4 != 0) {
    uVar5 = *(uint *)(iVar4 + 0x30) + DAT_400d134c;
    if (((uint)(uVar5 < *(uint *)(iVar4 + 0x30)) + *(int *)(iVar4 + 0x34) + DAT_400d1350 == 0) &&
       (uVar5 < 2)) {
      *(int *)(iVar4 + 0x14) = -*(int *)(iVar4 + 0x14);
    }
    else {
      *piVar3 = 0;
    }
    iVar1 = iVar4 + 0x30;
    FUN_400e8f6c(iVar1);
    FUN_400e832c(iVar1);
  }
  FUN_400e8290();
  FUN_400e8230(iVar1);
  return;
}



// Function at 0x400e7afc

int FUN_400e7afc(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  if (param_1 == 0) {
    param_1 = 1;
  }
  while ((iVar1 = func_0x4008dbdc(param_1), iVar1 == 0 &&
         (pcVar2 = (code *)FUN_400e823c(), pcVar2 != (code *)0x0))) {
    (*pcVar2)();
  }
  return iVar1;
}



// Function at 0x400e7b34

int * FUN_400e7b34(uint param_1,int param_2,int param_3,int *param_4)

{
  int *piVar1;
  int *in_t0;
  
  if (param_1 == 0x50) {
    piVar1 = (int *)(param_3 + 3U & 0xfffffffc);
    in_t0 = (int *)*piVar1;
    piVar1 = piVar1 + 1;
  }
  else {
    if ((param_1 & 0xf) < 0xd) {
                    /* WARNING: Could not recover jumptable at 0x400e7b61. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      piVar1 = (int *)(**(code **)(DAT_400d1354 + (param_1 & 0xf) * 4))();
      return piVar1;
    }
    piVar1 = (int *)func_0x4008da40();
    if (in_t0 != (int *)0x0) {
      if ((param_1 & 0x70) == 0x10) {
        param_2 = param_3;
      }
      in_t0 = (int *)((int)in_t0 + param_2);
      if ((char)param_1 < '\0') {
        in_t0 = (int *)*in_t0;
      }
    }
  }
  *param_4 = (int)in_t0;
  return piVar1;
}



// Function at 0x400e7c10

undefined4 FUN_400e7c10(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_30 [12];
  
  uVar2 = (uint)*(byte *)(param_1 + 0x14);
  if (uVar2 != 0xff) {
    uVar1 = uVar2 & 7;
    if (uVar1 == 2) {
      iVar3 = 2;
      goto LAB_400e7c49;
    }
    if (uVar1 < 3) {
      iVar3 = 4;
      if ((*(byte *)(param_1 + 0x14) & 7) == 0) goto LAB_400e7c49;
    }
    else {
      if (uVar1 == 3) {
        iVar3 = 4;
        goto LAB_400e7c49;
      }
      iVar3 = 8;
      if (uVar1 == 4) goto LAB_400e7c49;
    }
    uVar2 = func_0x4008da40();
  }
  iVar3 = 0;
LAB_400e7c49:
  FUN_400e7b34(uVar2,*(undefined4 *)(param_1 + 8),*(int *)(param_1 + 0xc) - param_2 * iVar3,local_30
              );
  return local_30[0];
}



// Function at 0x400e7c60

int FUN_400e7c60(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_40 [4];
  undefined4 auStack_30 [12];
  
  iVar3 = *(int *)(param_1 + 0xc) + (param_4 ^ 0xffffffff);
  auStack_30[0] = param_3;
  do {
    iVar3 = FUN_400f82e4(iVar3,local_40);
    if (local_40[0] == 0) {
      return 0;
    }
    uVar1 = FUN_400e7c10(param_1);
    iVar2 = FUN_400f8348(uVar1,param_2,auStack_30);
  } while (iVar2 == 0);
  return iVar2;
}



// Function at 0x400e7c98

undefined4 FUN_400e7c98(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 != 0xff) {
    param_1 = param_1 & 0x70;
    if (param_1 == 0x20) {
      uVar1 = FUN_400e8d58(param_2);
      return uVar1;
    }
    if (param_1 < 0x21) {
      if (param_1 == 0) {
        return 0;
      }
      if (param_1 == 0x10) {
        return 0;
      }
    }
    else {
      if (param_1 == 0x40) {
        uVar1 = FUN_400e8d30();
        return uVar1;
      }
      if (param_1 == 0x50) {
        return 0;
      }
      if (param_1 == 0x30) {
        uVar1 = FUN_400e8d50();
        return uVar1;
      }
    }
    func_0x4008da40();
  }
  return 0;
}



// Function at 0x400e7cf0

undefined4 FUN_400e7cf0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400e7c98(param_2,param_1);
  uVar1 = FUN_400e7b34(param_2,uVar1,param_3,param_4);
  return uVar1;
}



// Function at 0x400e7d0c

int FUN_400e7d0c(int param_1,char *param_2,undefined4 *param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int local_30 [12];
  
  uVar3 = 0;
  if (param_1 != 0) {
    uVar3 = FUN_400e8d30(param_1);
  }
  *param_3 = uVar3;
  pcVar4 = param_2 + 1;
  if (*param_2 == -1) {
    param_3[1] = uVar3;
  }
  else {
    pcVar4 = (char *)FUN_400e7cf0(param_1,*param_2,pcVar4,param_3 + 1);
  }
  cVar1 = *pcVar4;
  *(char *)(param_3 + 5) = cVar1;
  pcVar4 = pcVar4 + 1;
  if (cVar1 == -1) {
    param_3[3] = 0;
  }
  else {
    pcVar4 = (char *)FUN_400f82e4(pcVar4,local_30);
    param_3[3] = pcVar4 + local_30[0];
  }
  *(char *)((int)param_3 + 0x15) = *pcVar4;
  iVar2 = FUN_400f82e4(pcVar4 + 1,local_30);
  param_3[4] = iVar2 + local_30[0];
  return iVar2;
}



// Function at 0x400e7d74

undefined4
FUN_400e7d74(int param_1,uint param_2,uint param_3,int param_4,uint *param_5,undefined4 param_6)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint in_t0;
  int local_70;
  int iStack_6c;
  undefined4 uStack_68;
  int iStack_64;
  uint uStack_60;
  undefined1 uStack_5c;
  undefined1 uStack_5b;
  int iStack_58;
  uint uStack_54;
  uint uStack_50;
  int iStack_4c;
  int iStack_48;
  uint *puStack_44;
  uint uStack_40;
  uint uStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  int iStack_2c;
  uint uStack_28;
  uint uStack_24;
  
  puStack_44 = (uint *)0x0;
  iStack_48 = 0;
  if (param_1 != 1) {
    return 3;
  }
  uStack_3c = param_3 + DAT_400d134c;
  uStack_34 = (uint)(uStack_3c < param_3) + param_4 + DAT_400d1350;
  uStack_30 = 1;
  if ((uStack_34 != 0) || (1 < uStack_3c)) {
    uStack_30 = 0;
  }
  iVar6 = 1;
  uStack_38 = uStack_30 & param_2 == 6;
  if (uStack_38 == 0) {
    uVar4 = FUN_400e8d28(param_6);
    if (uVar4 != 0) {
      uStack_24 = FUN_400e7d0c(param_6,uVar4,&local_70);
      uStack_68 = FUN_400e7c98(uStack_5c,param_6);
      uVar1 = FUN_400e8d10(param_6,&iStack_48);
      uVar3 = uStack_24;
      if (iStack_48 == 0) {
        uVar1 = uVar1 - 1;
      }
      do {
        if (uStack_60 <= uVar3) {
          uVar5 = 0;
          uVar1 = 0;
          uVar3 = 0;
          iVar6 = 1;
          goto LAB_400e7f55;
        }
        uVar2 = FUN_400e7cf0(0,uStack_5b,uVar3,&iStack_4c);
        uVar2 = FUN_400e7cf0(0,uStack_5b,uVar2,&uStack_50);
        uVar2 = FUN_400e7cf0(0,uStack_5b,uVar2,&uStack_54);
        uVar5 = FUN_400f82e4(uVar2,&iStack_58);
        uVar3 = uStack_60;
      } while ((uVar1 < (uint)(local_70 + iStack_4c)) ||
              (uVar3 = uVar5, local_70 + iStack_4c + uStack_50 <= uVar1));
      uVar1 = uStack_54;
      if (uStack_54 != 0) {
        uVar1 = uStack_54 + iStack_6c;
      }
      if (iStack_58 == 0) {
        if (uVar1 != 0) {
          uVar3 = 0;
          goto LAB_400e7f53;
        }
      }
      else if (uVar1 != 0) {
        uVar3 = uStack_60 + iStack_58 + -1;
        if (uVar3 != 0) {
          puStack_44 = param_5 + 8;
          if ((*param_5 & 1) != 0) {
            puStack_44 = (uint *)param_5[-0xc];
          }
          uStack_40 = puStack_44[-0x14];
          uStack_28 = param_2 >> 3 & 1 ^ 1;
          do {
            iStack_2c = FUN_400f830c(uVar3,&uStack_50);
            FUN_400f830c(iStack_2c,&uStack_54);
            if (uStack_50 == 0) {
              uStack_38 = 1;
            }
            else {
              if ((int)uStack_50 < 1) {
                if (((uStack_40 == 0) || (uStack_28 == 0)) || (uStack_30 == 0)) {
                  FUN_400f82e4(iStack_64 + (uStack_50 ^ 0xffffffff),&iStack_58);
                  uVar5 = (uint)(iStack_58 == 0);
                }
                else {
                  uVar5 = FUN_400e7c60(&local_70,uStack_40,puStack_44);
                  uVar5 = uVar5 ^ 1;
                }
                uVar5 = uVar5 & 0xff;
              }
              else {
                iVar6 = FUN_400e7c10(&local_70,uStack_50);
                if (iVar6 == 0) goto LAB_400e8021;
                if (uStack_40 == 0) goto LAB_400e7f34;
                uVar5 = FUN_400f8348(iVar6,uStack_40,&puStack_44);
              }
              if (uVar5 != 0) goto LAB_400e8021;
            }
LAB_400e7f34:
            if (uStack_54 == 0) goto LAB_400e8029;
            uVar3 = iStack_2c + uStack_54;
          } while( true );
        }
LAB_400e7f53:
        uVar5 = 0;
        iVar6 = 2;
        goto LAB_400e7f55;
      }
    }
  }
  else {
    uVar5 = param_5[-6];
    uVar4 = param_5[-4];
    uVar1 = param_5[-3];
    uVar3 = 3;
    if (uVar1 != 0) {
      iVar6 = 3;
    }
    do {
      if ((((param_2 & 8) == 0) && (param_2 = uStack_34, uStack_34 == 0)) &&
         (uVar3 = uStack_3c, uStack_3c < 2)) {
        if (iVar6 == 1) goto LAB_400e7fa1;
LAB_400e7fa9:
        if ((int)uVar5 < 0) {
          uStack_24 = uVar5;
          FUN_400e7d0c(param_6,uVar4,&local_70);
          uStack_68 = FUN_400e7c98(uStack_5c,param_6);
          uVar4 = FUN_400e7c98(uStack_5c,param_6);
          param_5[-3] = uVar4;
          uVar5 = uStack_24;
        }
LAB_400e7fde:
        uStack_24 = uVar5;
        FUN_400e8cec(param_6,2,param_5);
        FUN_400e8cec(param_6,3,uStack_24);
        FUN_400e8d20(param_6,uVar1);
        return 7;
      }
      if (iVar6 != 1) {
        if (-1 < (int)uVar5) goto LAB_400e7fde;
        FUN_400e82b8();
LAB_400e7fa1:
        uVar5 = in_t0;
        FUN_400e82f4(param_5);
        goto LAB_400e7fa9;
      }
      FUN_400e8290();
LAB_400e8021:
      iVar6 = 3;
      uVar5 = uStack_50;
LAB_400e7f55:
    } while ((param_2 & 1) == 0);
    if (iVar6 != 2) {
      if ((uStack_34 == 0) && (uStack_3c < 2)) {
        param_5[-6] = uVar5;
        param_5[-5] = uVar3;
        param_5[-4] = uVar4;
        param_5[-2] = (uint)puStack_44;
        param_5[-3] = uVar1;
      }
      return 6;
    }
  }
  return 8;
LAB_400e8029:
  if (uStack_38 == 0) {
    return 8;
  }
  goto LAB_400e7f53;
}



// Function at 0x400e803c

void FUN_400e803c(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 auStack_40 [8];
  undefined4 uStack_38;
  
  FUN_400e832c(param_1);
  uStack_38 = *(undefined4 *)(param_1 + -0xc);
  uVar6 = *(undefined4 *)(param_1 + -0x10);
  uVar5 = *(undefined4 *)(param_1 + -0x18);
  uVar4 = *(undefined4 *)(param_1 + -0x24);
  FUN_400e829c(*(undefined4 *)(param_1 + -0x28));
  FUN_400e832c(param_1 + -0x30);
  puVar1 = (undefined4 *)FUN_400e81a4();
  puVar1 = (undefined4 *)*puVar1;
  puVar2 = puVar1 + 0x14;
  if ((puVar1[0xc] & 1) != 0) {
    puVar2 = (undefined4 *)*puVar1;
  }
  FUN_400e7d0c(0,uVar6,auStack_40);
  iVar3 = FUN_400e7c60(auStack_40,puVar2[-0x14],puVar2,uVar5);
  if (iVar3 != 0) {
    func_0x400e7aa0();
  }
  FUN_400e824c(uVar4);
  FUN_400e8388();
  FUN_400e8388();
  FUN_400e8ed8(puVar2);
  do {
    ill();
  } while( true );
}



// Function at 0x400e80e4

bool FUN_400e80e4(char *param_1,char *param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = true;
  if ((param_1 != param_2) && (bVar2 = false, *param_1 != '*')) {
    iVar1 = func_0x40086a70(param_1,param_2);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}



// Function at 0x400e810c

undefined4
FUN_400e810c(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7,int *param_8)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 4);
  if ((param_5 == param_7) && (iVar2 = FUN_400e80e4(uVar1,*(undefined4 *)(param_6 + 4)), iVar2 != 0)
     ) {
    param_8[2] = param_3;
  }
  else {
    iVar2 = FUN_400e80e4(uVar1,*(undefined4 *)(param_4 + 4));
    if (iVar2 != 0) {
      *param_8 = param_5;
      param_8[1] = param_3;
      param_8[3] = 1;
    }
  }
  return 0;
}



// Function at 0x400e8144

int FUN_400e8144(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  
  iVar1 = FUN_400e80e4(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_2 + 4));
  if (iVar1 != 0) {
    param_4[3] = 8;
    *param_4 = param_3;
    param_4[1] = 6;
  }
  return iVar1;
}



// Function at 0x400e8164

int FUN_400e8164(int param_1,int *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = FUN_400e80e4(*(undefined4 *)(param_1 + 4),param_2[1]);
  if ((iVar1 == 0) && (param_4 < 4)) {
    iVar1 = (**(code **)(*param_2 + 0x14))(param_2,param_1,param_3);
  }
  return iVar1;
}



// Function at 0x400e8184

void FUN_400e8184(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    iVar2 = *param_1;
    while (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 0x10);
      FUN_400e9004(iVar2 + 0x30);
      iVar2 = iVar1;
    }
    func_0x4008dbfc(param_1);
  }
  return;
}



// Function at 0x400e81a4

undefined4 FUN_400e81a4(void)

{
  undefined4 uVar1;
  
  uVar1 = DAT_400d135c;
  if (*(char *)(DAT_400d1360 + 1) != '\0') {
    uVar1 = FUN_400df4a8(*DAT_400d1360);
  }
  return uVar1;
}



// Function at 0x400e81c0

undefined4 * FUN_400e81c0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  puVar1 = DAT_400d1360;
  puVar2 = DAT_400d135c;
  if ((*(char *)(DAT_400d1360 + 1) != '\0') &&
     (puVar2 = (undefined4 *)FUN_400df4a8(*DAT_400d1360), puVar2 == (undefined4 *)0x0)) {
    puVar2 = (undefined4 *)func_0x4008dbdc(8);
    puVar3 = puVar2;
    if (puVar2 != (undefined4 *)0x0) goto LAB_400e81e3;
    do {
      puVar3 = (undefined4 *)FUN_400e8290();
LAB_400e81e3:
      iVar4 = FUN_400df4cc(*puVar1,puVar3);
    } while (iVar4 != 0);
    *puVar2 = 0;
    puVar2[1] = 0;
  }
  return puVar2;
}



// Function at 0x400e81f8

void FUN_400e81f8(void)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  
  puVar2 = PTR_FUN_400d1364;
  iVar1 = DAT_400d1360;
  *(undefined1 *)(DAT_400d1360 + 4) = 0;
  iVar3 = FUN_400df424(iVar1,puVar2);
  *(bool *)(iVar1 + 4) = iVar3 == 0;
  return;
}



// Function at 0x400e821c

void FUN_400e821c(void)

{
  if (*(char *)(DAT_400d1360 + 1) != '\0') {
    FUN_400df464(*DAT_400d1360);
  }
  return;
}



// Function at 0x400e8230

void FUN_400e8230(undefined4 param_1)

{
  func_0x4008dbfc(param_1);
  return;
}



// Function at 0x400e823c

undefined4 FUN_400e823c(void)

{
  memw();
  memw();
  return *DAT_400d1368;
}



// Function at 0x400e824c

undefined4 FUN_400e824c(code *param_1,int param_2)

{
  (*param_1)();
  func_0x4008da40();
  FUN_400e832c(param_1);
  func_0x4008da40();
  FUN_400e8388();
  if (param_2 != -1) {
    FUN_400e8ed8(param_1);
  }
  FUN_400e803c();
  cust0();
  memw();
  memw();
  return *(undefined4 *)param_1;
}



// Function at 0x400e8280

undefined4 FUN_400e8280(void)

{
  memw();
  memw();
  return *DAT_400d136c;
}



// Function at 0x400e8290

void FUN_400e8290(void)

{
  FUN_400e8280();
  FUN_400e824c();
  do {
    ill();
  } while( true );
}



// Function at 0x400e829c

void FUN_400e829c(code *param_1)

{
  (*param_1)();
  FUN_400e8290();
  do {
    ill();
  } while( true );
}



// Function at 0x400e82a8

undefined4 FUN_400e82a8(void)

{
  memw();
  memw();
  return *DAT_400d1370;
}



// Function at 0x400e82b8

void FUN_400e82b8(void)

{
  FUN_400e82a8();
  FUN_400e829c();
  do {
    ill();
  } while( true );
}



// Function at 0x400e82cc

void FUN_400e82cc(undefined4 *param_1)

{
  *param_1 = DAT_400d1334;
  FUN_400f83d4(param_1);
  return;
}



// Function at 0x400e82f4

uint * FUN_400e82f4(uint *param_1)

{
  undefined4 *puVar1;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 in_a14;
  int in_a15;
  uint *in_t0;
  uint *puVar2;
  
  puVar2 = param_1;
  if (param_1 != (uint *)0x0) {
    FUN_400e832c(param_1);
    uVar5 = *param_1 + DAT_400d134c;
    if (((uint)(uVar5 < *param_1) + param_1[1] + DAT_400d1350 == 0) && (uVar5 < 2)) {
      puVar2 = param_1 + -0xc;
      FUN_400e824c(param_1[-9]);
    }
  }
  puVar1 = (undefined4 *)FUN_400e8290();
  cust0();
  *(undefined4 *)(in_a15 + 0x3c) = in_a14;
  puVar3 = puVar2 + -0xc;
  puVar4 = (uint *)*puVar1;
  uVar5 = *puVar2 + DAT_400d134c;
  if (((uint)(uVar5 < *puVar2) + puVar2[1] + DAT_400d1350 == 0) && (uVar5 < 2)) {
    uVar5 = puVar2[-7];
    if ((int)uVar5 < 0) {
      uVar5 = -uVar5;
    }
    puVar2[-7] = uVar5 + 1;
    puVar1[1] = puVar1[1] + -1;
    if (puVar4 != puVar3) {
      puVar2[-8] = (uint)puVar4;
      *puVar1 = puVar3;
    }
    puVar4 = (uint *)puVar2[-2];
  }
  else {
    if (puVar4 != (uint *)0x0) {
      puVar3 = in_t0;
      puVar1 = (undefined4 *)FUN_400e8290();
      puVar4 = puVar3;
    }
    *puVar1 = puVar3;
  }
  return puVar4;
}



// Function at 0x400e832c

uint * FUN_400e832c(uint *param_1)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *in_t0;
  
  puVar1 = (undefined4 *)FUN_400e81c0();
  puVar2 = param_1 + -0xc;
  puVar3 = (uint *)*puVar1;
  uVar4 = *param_1 + DAT_400d134c;
  if (((uint)(uVar4 < *param_1) + param_1[1] + DAT_400d1350 == 0) && (uVar4 < 2)) {
    uVar4 = param_1[-7];
    if ((int)uVar4 < 0) {
      uVar4 = -uVar4;
    }
    param_1[-7] = uVar4 + 1;
    puVar1[1] = puVar1[1] + -1;
    if (puVar3 != puVar2) {
      param_1[-8] = (uint)puVar3;
      *puVar1 = puVar2;
    }
    puVar3 = (uint *)param_1[-2];
  }
  else {
    if (puVar3 != (uint *)0x0) {
      puVar2 = in_t0;
      puVar1 = (undefined4 *)FUN_400e8290();
      puVar3 = puVar2;
    }
    *puVar1 = puVar2;
  }
  return puVar3;
}



// Function at 0x400e8388

void FUN_400e8388(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int in_t0;
  
  piVar1 = (int *)FUN_400e81a4();
  iVar2 = *piVar1;
  if (iVar2 == 0) {
    return;
  }
  uVar4 = *(uint *)(iVar2 + 0x30) + DAT_400d134c;
  if (((uint)(uVar4 < *(uint *)(iVar2 + 0x30)) + *(int *)(iVar2 + 0x34) + DAT_400d1350 == 0) &&
     (uVar4 < 2)) {
    iVar3 = *(int *)(iVar2 + 0x14);
    if (iVar3 < 0) {
      iVar3 = iVar3 + 1;
      if (iVar3 == 0) {
        *piVar1 = *(int *)(iVar2 + 0x10);
      }
    }
    else {
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) {
        iVar3 = *(int *)(iVar2 + 0x10);
        goto LAB_400e83d1;
      }
      if (iVar3 < 0) {
        iVar2 = in_t0;
        FUN_400e8290();
        iVar3 = iVar2;
      }
    }
    *(int *)(iVar2 + 0x14) = iVar3;
  }
  else {
    iVar3 = 0;
LAB_400e83d1:
    *piVar1 = iVar3;
    FUN_400e9004(iVar2 + 0x30);
  }
  return;
}



// Function at 0x400e83ec

undefined4 FUN_400e83ec(void)

{
  return DAT_400d1378;
}



// Function at 0x400e83f4

void FUN_400e83f4(undefined4 *param_1)

{
  *param_1 = DAT_400d137c;
  FUN_400f83d4(param_1);
  return;
}



// Function at 0x400e841c

/* WARNING: Control flow encountered bad instruction data */

void FUN_400e841c(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)FUN_400e86f4(4);
  uVar2 = DAT_400d1384;
  puVar1 = PTR_FUN_400d1380;
  *puVar3 = DAT_400d137c;
  FUN_400e7a74(puVar3,uVar2,puVar1);
  cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// Function at 0x400e845c

bool FUN_400e845c(char *param_1,char *param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = true;
  if ((param_1 != param_2) && (bVar2 = false, *param_1 != '*')) {
    iVar1 = func_0x40086a70(param_1,param_2);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}



// Function at 0x400e8484

undefined4 FUN_400e8484(int param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_5 == param_3) &&
     (iVar1 = FUN_400e845c(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_4 + 4)), iVar1 != 0))
  {
    return 6;
  }
  uVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x20))
                    (*(int **)(param_1 + 8),param_2,param_3,param_4,param_5);
  return uVar2;
}



// Function at 0x400e84b0

undefined4
FUN_400e84b0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int *param_8)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 4);
  iVar1 = FUN_400e845c(uVar2,*(undefined4 *)(param_4 + 4));
  if (iVar1 == 0) {
    if ((param_5 == param_7) &&
       (iVar1 = FUN_400e845c(uVar2,*(undefined4 *)(param_6 + 4)), iVar1 != 0)) {
      param_8[2] = param_3;
      return 0;
    }
    uVar2 = (**(code **)(**(int **)(param_1 + 8) + 0x1c))
                      (*(int **)(param_1 + 8),param_2,param_3,param_4,param_5,param_6,param_7,
                       param_8);
  }
  else {
    *param_8 = param_5;
    param_8[1] = param_3;
    if (param_2 < 0) {
      uVar2 = 0;
      if (param_2 == -2) {
        param_8[3] = 1;
      }
    }
    else {
      iVar1 = 1;
      if (param_7 == param_5 + param_2) {
        iVar1 = 6;
      }
      param_8[3] = iVar1;
      uVar2 = 0;
    }
  }
  return uVar2;
}



// Function at 0x400e853c

int FUN_400e853c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_400e8144(param_1,param_2,param_3,param_4);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x18))
                      (*(int **)(param_1 + 8),param_2,param_3,param_4);
  }
  return iVar1;
}



// Function at 0x400e8564

undefined4 FUN_400e8564(void)

{
  return DAT_400d138c;
}



// Function at 0x400e856c

undefined4 FUN_400e856c(void)

{
  return DAT_400d1390;
}



// Function at 0x400e8574

void FUN_400e8574(undefined4 *param_1)

{
  *param_1 = DAT_400d1394;
  FUN_400f83d4(param_1);
  return;
}



// Function at 0x400e8588

void FUN_400e8588(undefined4 *param_1)

{
  *param_1 = DAT_400d1398;
  FUN_400f83d4(param_1);
  return;
}



// Function at 0x400e85b0

void FUN_400e85b0(undefined4 param_1)

{
  FUN_400e8588(param_1);
  FUN_400e87a8(param_1,4);
  return;
}



// Function at 0x400e85c4

void FUN_400e85c4(undefined4 param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = func_0x400830f4(param_1);
  if (iVar3 != 0) {
    puVar4 = (undefined4 *)FUN_400e86f4(4);
    uVar2 = DAT_400d13a0;
    puVar1 = PTR_FUN_400d139c;
    *puVar4 = DAT_400d1394;
    FUN_400e7a74(puVar4,uVar2,puVar1);
  }
  return;
}



// Function at 0x400e85e8

void FUN_400e85e8(undefined4 *param_1,int param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = func_0x4008311c(*param_1);
  if (iVar3 != 0) {
    puVar4 = (undefined4 *)FUN_400e86f4(4);
    uVar2 = DAT_400d13a8;
    puVar1 = PTR_FUN_400d13a4;
    *puVar4 = DAT_400d1398;
    FUN_400e7a74(puVar4,uVar2,puVar1);
    if (param_2 != -1) {
      FUN_400e8ed8(param_1);
    }
    FUN_400e803c();
  }
  return;
}



// Function at 0x400e8624

void FUN_400e8624(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int local_30 [12];
  
  iVar3 = DAT_400d13b0;
  piVar1 = (int *)(param_1 + -0x10);
  local_30[0] = DAT_400d13b0;
  FUN_400e85c4(DAT_400d13b0);
  piVar4 = *(int **)(iVar3 + 4);
  if (piVar4 == (int *)0x0) {
LAB_400e8640:
    *(int **)(param_1 + -0xc) = piVar4;
  }
  else {
    iVar6 = *piVar1;
    piVar7 = (int *)((int)piVar1 + iVar6);
    if (piVar7 < piVar4) goto LAB_400e8640;
    piVar8 = DAT_400d13ac;
    if (piVar4 == piVar7) {
      iVar5 = *piVar4;
      *(int *)(param_1 + -0xc) = piVar4[1];
      *piVar1 = iVar5 + iVar6;
    }
    else {
      while ((piVar2 = (int *)piVar4[1], piVar2 != (int *)0x0 && (piVar7 < piVar2))) {
        piVar8 = piVar4 + 1;
        piVar4 = piVar2;
      }
      if (piVar7 == piVar2) {
        iVar6 = iVar6 + *piVar7;
        piVar4[1] = piVar7[1];
      }
      piVar4 = (int *)*piVar8;
      if (piVar1 == (int *)((int)piVar4 + *piVar4)) {
        *piVar4 = *piVar4 + iVar6;
        goto LAB_400e868f;
      }
      iVar3 = piVar4[1];
      *piVar1 = iVar6;
      *(int *)(param_1 + -0xc) = iVar3;
      iVar3 = *piVar8;
    }
  }
  *(int **)(iVar3 + 4) = piVar1;
LAB_400e868f:
  FUN_400e85e8(local_30);
  return;
}



// Function at 0x400e8698

uint * FUN_400e8698(int param_1)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  int local_30 [12];
  
  iVar1 = DAT_400d13b0;
  local_30[0] = DAT_400d13b0;
  FUN_400e85c4(DAT_400d13b0);
  uVar3 = param_1 + 0x10;
  uVar3 = (uint)(uVar3 < 8) * 8 + (uVar3 >= 8) * uVar3 + 0xf & 0xfffffff0;
  puVar2 = *(uint **)(iVar1 + 4);
  puVar5 = DAT_400d13ac;
  do {
    if (puVar2 == (uint *)0x0) {
LAB_400e86e0:
      FUN_400e85e8(local_30);
      return puVar2;
    }
    puVar6 = (uint *)puVar2[1];
    if (uVar3 <= *puVar2) {
      uVar4 = *puVar2 - uVar3;
      if (uVar4 < 8) {
        *puVar5 = (uint)puVar6;
      }
      else {
        puVar7 = (uint *)((int)puVar2 + uVar3);
        puVar7[1] = (uint)puVar6;
        puVar2 = (uint *)*puVar5;
        *puVar7 = uVar4;
        *puVar2 = uVar3;
        *puVar5 = (uint)puVar7;
      }
      puVar2 = puVar2 + 4;
      goto LAB_400e86e0;
    }
    puVar5 = puVar2 + 1;
    puVar2 = puVar6;
  } while( true );
}



// Function at 0x400e86f4

int FUN_400e86f4(int param_1)

{
  int iVar1;
  int in_t0;
  
  iVar1 = func_0x4008dbdc(param_1 + 0x60);
  if ((iVar1 == 0) && (iVar1 = FUN_400e8698(param_1 + 0x60), iVar1 == 0)) {
    iVar1 = in_t0;
    FUN_400e8290();
  }
  iVar1 = func_0x40086818(iVar1,0,0x60);
  return iVar1 + 0x60;
}



// Function at 0x400e8724

void FUN_400e8724(int param_1)

{
  if ((*(uint *)(DAT_400d13b0 + 8) < param_1 - 0x60U) &&
     (param_1 - 0x60U < *(uint *)(DAT_400d13b0 + 8) + *(int *)(DAT_400d13b0 + 0xc))) {
    FUN_400e8624();
  }
  else {
    func_0x4008dbfc();
  }
  return;
}



// Function at 0x400e8748

void FUN_400e8748(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  iVar1 = DAT_400d13b0;
  FUN_400df2e4(DAT_400d13b0,0);
  *(undefined4 *)(iVar1 + 8) = 0;
  iVar2 = FUN_400f7dd8();
  *(int *)(iVar1 + 0xc) = iVar2;
  if (iVar2 != 0) {
    uVar3 = func_0x4008dbdc();
    *(undefined4 *)(iVar1 + 8) = uVar3;
  }
  piVar4 = *(int **)(iVar1 + 8);
  if (piVar4 == (int *)0x0) {
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 4) = 0;
  }
  else {
    *(int **)(iVar1 + 4) = piVar4;
    *piVar4 = iVar2;
    piVar4[1] = 0;
  }
  return;
}



// Function at 0x400e879c

void FUN_400e879c(void)

{
  FUN_400df35c(DAT_400d13b0);
  return;
}



// Function at 0x400e87a8

void FUN_400e87a8(undefined4 param_1)

{
  FUN_400e8230(param_1);
  return;
}



// Function at 0x400e87b4

void FUN_400e87b4(byte *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = 0;
  do {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = uVar2 | (bVar1 & 0x7f) << 0x20 - (0x20 - (uVar3 & 0x1f));
    uVar3 = uVar3 + 7;
  } while ((char)bVar1 < '\0');
  *param_2 = uVar2;
  return;
}



// Function at 0x400e87dc

void FUN_400e87dc(byte *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = 0;
  do {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = uVar2 | (bVar1 & 0x7f) << 0x20 - (0x20 - (uVar3 & 0x1f));
    uVar3 = uVar3 + 7;
  } while ((char)bVar1 < '\0');
  if ((uVar3 < 0x20) && ((bVar1 & 0x40) != 0)) {
    uVar2 = uVar2 | -1 << 0x20 - (0x20 - (uVar3 & 0x1f));
  }
  *param_2 = uVar2;
  return;
}



// Function at 0x400e8818

int * FUN_400e8818(uint param_1,int param_2,int param_3,int *param_4)

{
  int *piVar1;
  int *in_t0;
  
  if (param_1 == 0x50) {
    piVar1 = (int *)(param_3 + 3U & 0xfffffffc);
    in_t0 = (int *)*piVar1;
    piVar1 = piVar1 + 1;
  }
  else {
    if ((param_1 & 0xf) < 0xd) {
                    /* WARNING: Could not recover jumptable at 0x400e8845. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      piVar1 = (int *)(**(code **)(DAT_400d13b4 + (param_1 & 0xf) * 4))();
      return piVar1;
    }
    piVar1 = (int *)func_0x4008da40();
    if (in_t0 != (int *)0x0) {
      if ((param_1 & 0x70) == 0x10) {
        param_2 = param_3;
      }
      in_t0 = (int *)((int)in_t0 + param_2);
      if ((char)param_1 < '\0') {
        in_t0 = (int *)*in_t0;
      }
    }
  }
  *param_4 = (int)in_t0;
  return piVar1;
}



// Function at 0x400e88ec

undefined4 FUN_400e88ec(uint param_1,int param_2)

{
  if (param_1 != 0xff) {
    param_1 = param_1 & 0x70;
    if (param_1 == 0x20) {
      return *(undefined4 *)(param_2 + 0x24);
    }
    if (param_1 < 0x21) {
      if (param_1 == 0) {
        return 0;
      }
      if (param_1 == 0x10) {
        return 0;
      }
    }
    else {
      if (param_1 == 0x40) {
        return *(undefined4 *)(param_2 + 0x2c);
      }
      if (param_1 == 0x50) {
        return 0;
      }
      if (param_1 == 0x30) {
        return *(undefined4 *)(param_2 + 0x28);
      }
    }
    func_0x4008da40();
  }
  return 0;
}



// Function at 0x400e8938

void FUN_400e8938(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_60 [24];
  
  piVar3 = local_60;
  func_0x400866b8(local_60,param_1,0x38);
  iVar1 = *(int *)(param_2 + 0x10);
  if (iVar1 == 0) {
    iVar4 = param_1[4];
    iVar6 = *(int *)(iVar4 + -0xc);
    uVar2 = *(uint *)(param_2 + 4) >> 2;
    *param_1 = param_1[5] + -0x10;
    iVar1 = iVar6 + uVar2 * -0x10;
    for (iVar5 = 1; iVar5 < (int)uVar2; iVar5 = iVar5 + 1) {
      param_1[iVar5] = iVar1;
      iVar1 = iVar1 + 0x10;
    }
    for (; (int)uVar2 < 4; uVar2 = uVar2 + 1) {
      param_1[uVar2] = *piVar3;
      piVar3 = piVar3 + 1;
    }
  }
  else {
    iVar4 = *(int *)(iVar1 + 4);
    iVar6 = *(int *)(iVar4 + -0xc);
    *param_1 = iVar1;
    param_1[1] = iVar1 + 0x10;
    param_1[2] = iVar1 + 0x20;
    param_1[3] = iVar1 + 0x30;
  }
  param_1[5] = iVar4;
  param_1[4] = iVar6;
  uVar2 = param_1[0xc] & DAT_400d0140;
  if (*(char *)(param_2 + 0xb) != '\0') {
    uVar2 = param_1[0xc] | DAT_400d0284;
  }
  param_1[0xc] = uVar2;
  return;
}



// Function at 0x400e89c4

void FUN_400e89c4(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  uint unaff_retaddr;
  uint uVar2;
  undefined1 auStack_40 [4];
  undefined4 uStack_3c;
  
  uVar2 = (uint)PTR_FUN_400d13b8 & 0xc0000000;
  func_0x40086818(param_1,0,0x38);
  *(uint *)(param_1 + 0x18) = unaff_retaddr & 0x3fffffff | uVar2;
  func_0x40086818(auStack_40,0,0x18);
  uStack_3c = 8;
  *(BADSPACEBASE **)(param_1 + 0x14) = register0x00000004;
  puVar1 = PTR_FUN_400d13b8;
  uVar2 = DAT_400d0904;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(uint *)(param_1 + 0x1c) = (uint)puVar1 & uVar2;
  FUN_400e8938(param_1,auStack_40);
  *(undefined4 *)(param_1 + 0x18) = param_3;
  return;
}



// Function at 0x400e8a10

undefined4 FUN_400e8a10(int *param_1,int *param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte bVar11;
  uint uVar12;
  byte *pbVar13;
  int local_40;
  undefined1 auStack_3c [4];
  uint auStack_38 [2];
  uint uStack_30;
  uint uStack_2c;
  
  func_0x40086818(param_2,0,0x18);
  param_1[8] = 0;
  iVar3 = FUN_400e9b78(param_1[6] + (-1 - (param_1[0xc] >> 0x1f)),param_1 + 9);
  if (iVar3 == 0) goto LAB_400e8ba8;
  iVar6 = (iVar3 + 4) - *(int *)(iVar3 + 4);
  pbVar9 = (byte *)(iVar6 + 9);
  iVar4 = func_0x40086c6c(pbVar9);
  pbVar13 = pbVar9 + iVar4 + 1;
  if ((*(char *)(iVar6 + 9) == 'e') && (*(char *)(iVar6 + 10) == 'h')) {
    iVar4 = *(int *)pbVar13;
    pbVar13 = pbVar13 + 4;
    param_2[3] = iVar4;
    pbVar9 = (byte *)(iVar6 + 0xb);
  }
  uVar5 = FUN_400e87b4(pbVar13,auStack_38);
  pbVar13 = (byte *)FUN_400e87dc(uVar5,auStack_3c);
  if (*(char *)(iVar6 + 8) == '\x01') {
    pbVar7 = pbVar13 + 1;
    uVar8 = (uint)*pbVar13;
  }
  else {
    pbVar7 = (byte *)FUN_400e87b4(pbVar13,auStack_38);
    uVar8 = auStack_38[0];
  }
  param_2[1] = uVar8;
  *(undefined1 *)((int)param_2 + 9) = 0xff;
  pbVar13 = (byte *)0x0;
  if (*pbVar9 == 0x7a) {
    pbVar7 = (byte *)FUN_400e87b4(pbVar7,auStack_38);
    pbVar13 = pbVar7 + auStack_38[0];
    *(undefined1 *)((int)param_2 + 10) = 1;
    pbVar9 = pbVar9 + 1;
  }
  uVar8 = 0x4c;
  while( true ) {
    pbVar10 = pbVar9 + 1;
    uVar12 = (uint)*pbVar9;
    if (uVar12 == 0) break;
    pbVar9 = pbVar10;
    if (uVar12 == uVar8) {
      *(byte *)((int)param_2 + 9) = *pbVar7;
LAB_400e8adf:
      pbVar7 = pbVar7 + 1;
    }
    else {
      if (uVar12 == 0x52) {
        *(byte *)(param_2 + 2) = *pbVar7;
        goto LAB_400e8adf;
      }
      if (uVar12 == 0x50) {
        uStack_30 = (uint)*pbVar7;
        uStack_2c = uVar8;
        uVar5 = FUN_400e88ec(uStack_30,param_1);
        pbVar7 = (byte *)FUN_400e8818(uStack_30,uVar5,pbVar7 + 1,&local_40);
        *param_2 = local_40;
        uVar8 = uStack_2c;
      }
      else {
        pbVar10 = pbVar13;
        if (uVar12 != 0x53) goto LAB_400e8b36;
        *(undefined1 *)((int)param_2 + 0xb) = 1;
      }
    }
  }
  pbVar10 = pbVar7;
  if (pbVar13 == (byte *)0x0) {
LAB_400e8b36:
    if (pbVar10 == (byte *)0x0) {
      return 3;
    }
  }
  bVar1 = *(byte *)(param_2 + 2);
  if (bVar1 == 0xff) {
LAB_400e8b62:
    iVar4 = 0;
  }
  else {
    bVar11 = bVar1 & 7;
    if (bVar11 == 2) {
      iVar4 = 2;
    }
    else if (bVar11 < 3) {
      iVar4 = 4;
      if ((bVar1 & 7) != 0) {
LAB_400e8b5c:
        func_0x4008da40();
        goto LAB_400e8b62;
      }
    }
    else if (bVar11 == 3) {
      iVar4 = 4;
    }
    else {
      iVar4 = 8;
      if (bVar11 != 4) goto LAB_400e8b5c;
    }
  }
  iVar3 = iVar3 + iVar4 * 2 + 8;
  if (*(char *)((int)param_2 + 10) != '\0') {
    iVar3 = FUN_400e87b4(iVar3,&local_40);
  }
  cVar2 = *(char *)((int)param_2 + 9);
  if (cVar2 != -1) {
    uVar5 = FUN_400e88ec(cVar2,param_1);
    FUN_400e8818(cVar2,uVar5,iVar3,&local_40);
    param_1[8] = local_40;
  }
LAB_400e8ba8:
  if ((uint *)*param_1 == (uint *)0x0) {
    iVar3 = 8;
  }
  else {
    uVar8 = *(uint *)*param_1;
    if (uVar8 == 0) {
      return 5;
    }
    iVar3 = (uVar8 >> 0x1e) << 2;
  }
  param_2[1] = iVar3;
  return 0;
}



// Function at 0x400e8bcc

undefined4 FUN_400e8bcc(int param_1,uint param_2)

{
  return *(undefined4 *)(*(int *)(param_1 + ((int)param_2 >> 2) * 4) + (param_2 & 3) * 4);
}



// Function at 0x400e8be8

void FUN_400e8be8(int param_1,int param_2)

{
  uint uVar1;
  
  FUN_400e8938(param_1,param_2);
  uVar1 = *(uint *)(param_2 + 0x14);
  if (uVar1 == 0) {
    uVar1 = FUN_400e8bcc(param_1,*(undefined4 *)(param_2 + 4));
    uVar1 = uVar1 & DAT_400d0280 | *(uint *)(param_1 + 0x1c);
  }
  *(uint *)(param_1 + 0x18) = uVar1;
  return;
}



// Function at 0x400e8c0c

undefined4 FUN_400e8c0c(undefined4 *param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  code *local_40 [16];
  
  iVar2 = 1;
  do {
    iVar1 = FUN_400e8a10(param_2,local_40);
    uVar3 = 0;
    if (*(int *)(param_2 + 0x14) == param_1[4]) {
      uVar3 = 4;
    }
    if (iVar1 != 0) {
      return 2;
    }
    if (local_40[0] != (code *)0x0) {
      iVar1 = (*local_40[0])(1,uVar3 | 2,*param_1,param_1[1],param_1,param_2);
      if (iVar1 == 7) {
        *param_3 = iVar2;
        return 7;
      }
      if (iVar1 != 8) {
        return 2;
      }
    }
    if (uVar3 != 0) {
      func_0x4008da40();
    }
    FUN_400e8be8(param_2,local_40);
    iVar2 = iVar2 + 1;
  } while( true );
}



// Function at 0x400e8c70

int FUN_400e8c70(undefined4 *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  code *apcStack_50 [8];
  int iStack_30;
  undefined4 uStack_2c;
  
  pcVar3 = (code *)param_1[3];
  uVar4 = param_1[4];
  iVar2 = 1;
  while( true ) {
    iStack_30 = FUN_400e8a10(param_2,apcStack_50);
    if ((iStack_30 != 0) && (iStack_30 != 5)) {
      return 2;
    }
    uVar5 = 0x1a;
    if (iStack_30 != 5) {
      uVar5 = 10;
    }
    uStack_2c = 10;
    iVar1 = (*pcVar3)(1,uVar5,*param_1,param_1[1],param_1,param_2,uVar4);
    if (iVar1 != 0) {
      return 2;
    }
    iVar1 = iStack_30;
    if (iStack_30 == 5) break;
    if (apcStack_50[0] != (code *)0x0) {
      iVar1 = (*apcStack_50[0])(1,uStack_2c,*param_1,param_1[1],param_1,param_2);
      if (iVar1 == 7) break;
      if (iVar1 != 8) {
        return 2;
      }
    }
    FUN_400e8be8(param_2,apcStack_50);
    iVar2 = iVar2 + 1;
  }
  *param_3 = iVar2;
  return iVar1;
}



// Function at 0x400e8ce4

undefined4 FUN_400e8ce4(int param_1)

{
  return *(undefined4 *)(param_1 + 0x14);
}



// Function at 0x400e8cec

void FUN_400e8cec(int param_1,uint param_2,undefined4 param_3)

{
  *(undefined4 *)(*(int *)(param_1 + ((int)param_2 >> 2) * 4) + (param_2 & 3) * 4) = param_3;
  return;
}



// Function at 0x400e8d08

undefined4 FUN_400e8d08(int param_1)

{
  return *(undefined4 *)(param_1 + 0x18);
}



// Function at 0x400e8d10

undefined4 FUN_400e8d10(int param_1,uint *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x18);
  *param_2 = *(uint *)(param_1 + 0x30) >> 0x1f;
  return uVar1;
}



// Function at 0x400e8d20

void FUN_400e8d20(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x18) = param_2;
  return;
}



// Function at 0x400e8d28

undefined4 FUN_400e8d28(int param_1)

{
  return *(undefined4 *)(param_1 + 0x20);
}



// Function at 0x400e8d30

undefined4 FUN_400e8d30(int param_1)

{
  return *(undefined4 *)(param_1 + 0x2c);
}



// Function at 0x400e8d38

int FUN_400e8d38(int param_1)

{
  int iVar1;
  undefined1 auStack_30 [8];
  int iStack_28;
  
  iVar1 = FUN_400e9b78(param_1 + -1,auStack_30);
  if (iVar1 != 0) {
    iVar1 = iStack_28;
  }
  return iVar1;
}



// Function at 0x400e8d50

undefined4 FUN_400e8d50(int param_1)

{
  return *(undefined4 *)(param_1 + 0x28);
}



// Function at 0x400e8d58

undefined4 FUN_400e8d58(int param_1)

{
  return *(undefined4 *)(param_1 + 0x24);
}



// Function at 0x400e8d60

undefined8 FUN_400e8d60(undefined4 *param_1)

{
  uint unaff_retaddr;
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int aiStack_b0 [5];
  undefined4 uStack_9c;
  int iStack_98;
  int aiStack_78 [14];
  code *apcStack_40 [16];
  
  func_0x4008b97c();
  FUN_400e89c4(aiStack_78,&stack0x00000000,
               unaff_retaddr & 0x3fffffff | (uint)PTR_FUN_400d13bc & 0xc0000000);
  func_0x400866b8(aiStack_b0,aiStack_78);
  do {
    puVar1 = (undefined4 *)FUN_400e8a10(aiStack_b0,apcStack_40);
    puVar3 = puVar1;
    if (puVar1 == (undefined4 *)0x5) {
LAB_400e8e44:
      return CONCAT44(puVar1,puVar3);
    }
    if (puVar1 != (undefined4 *)0x0) {
LAB_400e8da0:
      puVar3 = (undefined4 *)0x3;
      puVar1 = puVar3;
      goto LAB_400e8e44;
    }
    if (apcStack_40[0] != (code *)0x0) {
      iVar2 = (*apcStack_40[0])(1,1,*param_1,param_1[1],param_1,aiStack_b0);
      if (iVar2 == 6) {
        param_1[4] = uStack_9c;
        param_1[3] = 0;
        func_0x400866b8(aiStack_b0,aiStack_78);
        puVar3 = (undefined4 *)FUN_400e8c0c(param_1,aiStack_b0,apcStack_40);
        if (puVar3 == (undefined4 *)0x7) {
          iVar2 = 0;
          do {
            iVar5 = *(int *)((int)aiStack_78 + iVar2);
            iVar6 = *(int *)((int)aiStack_b0 + iVar2);
            puVar3 = puVar1;
            if (iVar5 != 0) {
              puVar3 = (undefined4 *)0x1;
            }
            if (((uint)(iVar6 != 0) & (uint)puVar3) != 0) {
              puVar3 = puVar1;
              if (iVar5 != iVar6) {
                puVar3 = (undefined4 *)0x1;
              }
              if (((uint)puVar3 & 0xff) != 0) {
                iVar4 = 0;
                do {
                  puVar3 = (undefined4 *)(iVar5 + iVar4);
                  *puVar3 = *(undefined4 *)(iVar6 + iVar4);
                  iVar4 = iVar4 + 4;
                } while (iVar4 != 0x10);
              }
            }
            iVar2 = iVar2 + 4;
          } while (iVar2 != 8);
          puVar1 = (undefined4 *)(iStack_98 * 4 + 2);
        }
        goto LAB_400e8e44;
      }
      if (iVar2 != 8) goto LAB_400e8da0;
    }
    FUN_400e8be8(aiStack_b0,apcStack_40);
  } while( true );
}



// Function at 0x400e8ed8

int FUN_400e8ed8(int param_1)

{
  uint unaff_retaddr;
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  int in_t0;
  undefined4 local_a0 [6];
  int iStack_88;
  undefined4 local_68 [14];
  undefined1 auStack_30 [48];
  
  func_0x4008b97c();
  FUN_400e89c4(local_68,&stack0x00000000,
               unaff_retaddr & 0x3fffffff | (uint)PTR_FUN_400d13c4 & 0xc0000000);
  func_0x400866b8(local_a0,local_68);
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar1 = FUN_400e8c0c();
  }
  else {
    iVar1 = FUN_400e8c70(param_1,local_a0,auStack_30);
  }
  iVar3 = 0;
  uVar7 = 0;
  if (iVar1 != 7) {
    iVar3 = in_t0;
    func_0x4008da40();
  }
  do {
    puVar5 = *(undefined4 **)((int)local_68 + iVar3);
    puVar6 = *(undefined4 **)((int)local_a0 + iVar3);
    uVar4 = uVar7;
    if (puVar6 != (undefined4 *)0x0) {
      uVar4 = 1;
    }
    uVar2 = uVar7;
    if (puVar5 != (undefined4 *)0x0) {
      uVar2 = 1;
    }
    if (((uVar4 & uVar2) != 0) && (puVar5 != puVar6)) {
      *puVar5 = *puVar6;
    }
    iVar3 = iVar3 + 4;
  } while (iVar3 != 8);
  return iStack_88 * 4 + 2;
}



// Function at 0x400e8f6c

undefined4 FUN_400e8f6c(int param_1)

{
  uint unaff_retaddr;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  int in_t0;
  int local_a0 [14];
  int local_68 [14];
  undefined1 auStack_30 [48];
  
  if (*(int *)(param_1 + 0xc) == 0) {
    uVar1 = FUN_400e8d60(param_1);
  }
  else {
    func_0x4008b97c();
    FUN_400e89c4(local_68,&stack0x00000000,unaff_retaddr & 0x3fffffff | DAT_400d13c8 & 0xc0000000);
    func_0x400866b8(local_a0,local_68);
    iVar2 = FUN_400e8c70(param_1,local_a0,auStack_30);
    iVar3 = 0;
    uVar8 = 0;
    if (iVar2 != 7) {
      iVar3 = in_t0;
      func_0x4008da40();
    }
    do {
      uVar1 = 1;
      puVar6 = *(undefined4 **)((int)local_68 + iVar3);
      puVar7 = *(undefined4 **)((int)local_a0 + iVar3);
      uVar5 = uVar8;
      if (puVar7 != (undefined4 *)0x0) {
        uVar5 = 1;
      }
      uVar4 = uVar8;
      if (puVar6 != (undefined4 *)0x0) {
        uVar4 = 1;
      }
      if (((uVar5 & uVar4) != 0) && (puVar6 != puVar7)) {
        *puVar6 = *puVar7;
      }
      iVar3 = iVar3 + 4;
    } while (iVar3 != 8);
  }
  return uVar1;
}



// Function at 0x400e9004

void FUN_400e9004(int param_1)

{
  if (*(code **)(param_1 + 8) != (code *)0x0) {
    (**(code **)(param_1 + 8))(1,param_1);
  }
  return;
}



// Function at 0x400e9014

undefined4 FUN_400e9014(code *param_1,undefined4 param_2)

{
  uint unaff_retaddr;
  int iVar1;
  int iVar2;
  undefined1 auStack_70 [56];
  undefined1 auStack_38 [56];
  
  func_0x4008b97c();
  FUN_400e89c4(auStack_70,&stack0x00000000,
               unaff_retaddr & 0x3fffffff | (uint)PTR_FUN_400d13cc & 0xc0000000);
  while (((iVar1 = FUN_400e8a10(auStack_70,auStack_38), iVar1 == 0 || (iVar1 == 5)) &&
         (iVar2 = (*param_1)(auStack_70,param_2), iVar2 == 0))) {
    if (iVar1 == 5) {
      return 5;
    }
    FUN_400e8be8(auStack_70,auStack_38);
  }
  return 3;
}



// Function at 0x400e9064

void FUN_400e9064(byte *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = 0;
  do {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = uVar2 | (bVar1 & 0x7f) << 0x20 - (0x20 - (uVar3 & 0x1f));
    uVar3 = uVar3 + 7;
  } while ((char)bVar1 < '\0');
  *param_2 = uVar2;
  return;
}



// Function at 0x400e908c

void FUN_400e908c(byte *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = 0;
  do {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = uVar2 | (bVar1 & 0x7f) << 0x20 - (0x20 - (uVar3 & 0x1f));
    uVar3 = uVar3 + 7;
  } while ((char)bVar1 < '\0');
  if ((uVar3 < 0x20) && ((bVar1 & 0x40) != 0)) {
    uVar2 = uVar2 | -1 << 0x20 - (0x20 - (uVar3 & 0x1f));
  }
  *param_2 = uVar2;
  return;
}



// Function at 0x400e90c8

void FUN_400e90c8(undefined4 param_1,code *param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar4 = param_4 * 2;
  while( true ) {
    iVar5 = iVar4 + 1;
    if (param_5 <= iVar5) {
      return;
    }
    if ((iVar4 + 2 < param_5) &&
       (puVar2 = (undefined4 *)(param_3 + iVar5 * 4), iVar1 = (*param_2)(param_1,*puVar2,puVar2[1]),
       iVar1 < 0)) {
      iVar5 = iVar4 + 2;
    }
    puVar2 = (undefined4 *)(param_3 + param_4 * 4);
    puVar3 = (undefined4 *)(param_3 + iVar5 * 4);
    iVar4 = (*param_2)(param_1,*puVar2,*puVar3);
    if (-1 < iVar4) break;
    uVar6 = *puVar2;
    *puVar2 = *puVar3;
    iVar4 = iVar5 * 2;
    *puVar3 = uVar6;
    param_4 = iVar5;
  }
  return;
}



// Function at 0x400e9124

void FUN_400e9124(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar1 = *(uint *)(param_3 + 4);
  uVar3 = uVar1 >> 1;
  while (uVar3 = uVar3 - 1, uVar3 != 0xffffffff) {
    FUN_400e90c8(param_1,param_2,param_3 + 8,uVar3,uVar1);
  }
  iVar2 = param_3 + uVar1 * 4;
  while( true ) {
    uVar1 = uVar1 - 1;
    if ((int)uVar1 < 1) break;
    uVar4 = *(undefined4 *)(param_3 + 8);
    *(undefined4 *)(param_3 + 8) = *(undefined4 *)(iVar2 + 4);
    *(undefined4 *)(iVar2 + 4) = uVar4;
    FUN_400e90c8(param_1,param_2,param_3 + 8,0,uVar1);
    iVar2 = iVar2 + -4;
  }
  return;
}



// Function at 0x400e9174

undefined4 FUN_400e9174(uint param_1)

{
  if (param_1 != 0xff) {
    param_1 = param_1 & 7;
    if (param_1 == 2) {
      return 2;
    }
    if (param_1 < 3) {
      if (param_1 == 0) {
        return 4;
      }
    }
    else {
      if (param_1 == 3) {
        return 4;
      }
      if (param_1 == 4) {
        return 8;
      }
    }
    func_0x4008da40();
  }
  return 0;
}



// Function at 0x400e91a8

undefined4 FUN_400e91a8(uint param_1,int param_2)

{
  if (param_1 != 0xff) {
    param_1 = param_1 & 0x70;
    if (param_1 == 0x20) {
      return *(undefined4 *)(param_2 + 4);
    }
    if (param_1 < 0x21) {
      if (param_1 == 0) {
        return 0;
      }
      if (param_1 == 0x10) {
        return 0;
      }
    }
    else {
      if (param_1 == 0x30) {
        return *(undefined4 *)(param_2 + 8);
      }
      if (param_1 == 0x50) {
        return 0;
      }
    }
    func_0x4008da40();
  }
  return 0;
}



// Function at 0x400e91f0

int * FUN_400e91f0(uint param_1,int param_2,int param_3,int *param_4)

{
  int *piVar1;
  int *in_t0;
  
  if (param_1 == 0x50) {
    piVar1 = (int *)(param_3 + 3U & 0xfffffffc);
    in_t0 = (int *)*piVar1;
    piVar1 = piVar1 + 1;
  }
  else {
    if ((param_1 & 0xf) < 0xd) {
                    /* WARNING: Could not recover jumptable at 0x400e921d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      piVar1 = (int *)(**(code **)(DAT_400d13d0 + (param_1 & 0xf) * 4))();
      return piVar1;
    }
    piVar1 = (int *)func_0x4008da40();
    if (in_t0 != (int *)0x0) {
      if ((param_1 & 0x70) == 0x10) {
        param_2 = param_3;
      }
      in_t0 = (int *)((int)in_t0 + param_2);
      if ((char)param_1 < '\0') {
        in_t0 = (int *)*in_t0;
      }
    }
  }
  *param_4 = (int)in_t0;
  return piVar1;
}



// Function at 0x400e92c4

int FUN_400e92c4(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint local_30;
  uint auStack_2c [11];
  
  uVar3 = *(uint *)(param_1 + 0x10) >> 3 & 0xff;
  uVar1 = FUN_400e91a8(uVar3,param_1);
  FUN_400e91f0(uVar3,uVar1,param_2 + 8,auStack_2c);
  FUN_400e91f0(*(uint *)(param_1 + 0x10) >> 3 & 0xff,uVar1,param_3 + 8,&local_30);
  iVar2 = 1;
  if (auStack_2c[0] <= local_30) {
    iVar2 = -(uint)(auStack_2c[0] < local_30);
  }
  return iVar2;
}



// Function at 0x400e9308

byte FUN_400e9308(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  byte bVar5;
  char *pcVar6;
  undefined1 auStack_30 [4];
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [40];
  
  iVar2 = func_0x40086c6c(param_1 + 9);
  pcVar6 = (char *)(param_1 + 9 + iVar2 + 1);
  if (3 < *(byte *)(param_1 + 8)) {
    if (*pcVar6 != '\x04') {
      return 0xff;
    }
    if (pcVar6[1] != '\0') {
      return 0xff;
    }
    pcVar6 = pcVar6 + 2;
  }
  if (*(char *)(param_1 + 9) == 'z') {
    uVar3 = FUN_400e9064(pcVar6,auStack_2c);
    iVar2 = FUN_400e908c(uVar3,auStack_30);
    if (*(char *)(param_1 + 8) == '\x01') {
      iVar2 = iVar2 + 1;
    }
    else {
      iVar2 = FUN_400e9064(iVar2,auStack_2c);
    }
    pbVar4 = (byte *)FUN_400e9064(iVar2,auStack_2c);
    for (pcVar6 = (char *)(param_1 + 10); cVar1 = *pcVar6, cVar1 != 'R'; pcVar6 = pcVar6 + 1) {
      if (cVar1 == 'P') {
        pbVar4 = (byte *)FUN_400e91f0(*pbVar4 & 0x7f,0,pbVar4 + 1,auStack_28);
      }
      else {
        if (cVar1 != 'L') goto LAB_400e9339;
        pbVar4 = pbVar4 + 1;
      }
    }
    bVar5 = *pbVar4;
  }
  else {
LAB_400e9339:
    bVar5 = 0;
  }
  return bVar5;
}



// Function at 0x400e9398

int FUN_400e9398(uint *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint local_40 [4];
  uint uStack_30;
  undefined4 uStack_2c;
  
  uVar7 = 0;
  uVar3 = 0;
  iVar4 = 0;
  iVar6 = 0;
  do {
    if (*param_2 == 0) {
      return iVar4;
    }
    iVar2 = iVar6;
    if (param_2[1] != 0) {
      iVar2 = (int)param_2 + (4 - param_2[1]);
      if (iVar6 != iVar2) {
        uVar3 = FUN_400e9308(iVar2);
        if (uVar3 == 0xff) {
          return -1;
        }
        uVar7 = FUN_400e91a8(uVar3 & 0xff,param_1);
        uVar5 = param_1[4];
        if ((uVar5 & 0x7f8) == 0x7f8) {
          uVar5 = uVar5 & 0xfffff807 | (uVar3 & 0xff) << 3;
        }
        else {
          if ((uVar5 >> 3 & 0xff) == uVar3) goto LAB_400e93fd;
          uVar5 = uVar5 | 4;
        }
        param_1[4] = uVar5;
      }
LAB_400e93fd:
      uStack_30 = uVar3 & 0xff;
      uStack_2c = uVar7;
      FUN_400e91f0(uStack_30,uVar7,param_2 + 2,local_40);
      uVar1 = FUN_400e9174(uStack_30);
      uVar5 = 0xffffffff;
      if (uVar1 < 4) {
        uVar5 = (1 << 0x20 - ((uVar1 & 3) * -8 + 0x20)) - 1;
      }
      uVar7 = uStack_2c;
      if (((local_40[0] & uVar5) != 0) && (iVar4 = iVar4 + 1, local_40[0] < *param_1)) {
        *param_1 = local_40[0];
      }
    }
    param_2 = (int *)((int)param_2 + *param_2 + 4);
    iVar6 = iVar2;
  } while( true );
}



// Function at 0x400e9454

int * FUN_400e9454(int param_1,int *param_2,int param_3)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint local_40;
  uint auStack_3c [3];
  uint uStack_30;
  undefined4 uStack_2c;
  
  uVar4 = *(uint *)(param_1 + 0x10) >> 3 & 0xff;
  uVar2 = FUN_400e91a8(uVar4,param_1);
  iVar6 = 0;
  do {
    if (*param_2 == 0) {
      return (int *)0x0;
    }
    if (param_2[1] != 0) {
      if (((*(uint *)(param_1 + 0x10) & 4) != 0) &&
         (iVar5 = (int)param_2 + (4 - param_2[1]), bVar1 = iVar6 != iVar5, iVar6 = iVar5, bVar1)) {
        uVar4 = FUN_400e9308(iVar5);
        uVar2 = FUN_400e91a8(uVar4 & 0xff,param_1);
      }
      if (uVar4 == 0) {
        auStack_3c[0] = param_2[2];
        local_40 = param_2[3];
        uVar3 = auStack_3c[0];
      }
      else {
        uStack_30 = uVar4 & 0xff;
        uStack_2c = uVar2;
        uVar2 = FUN_400e91f0(uStack_30,uVar2,param_2 + 2,auStack_3c);
        FUN_400e91f0(uVar4 & 0xf,0,uVar2,&local_40);
        uVar3 = FUN_400e9174(uStack_30);
        uVar7 = 0xffffffff;
        if (uVar3 < 4) {
          uVar7 = (1 << 0x20 - ((uVar3 & 3) * -8 + 0x20)) - 1;
        }
        uVar2 = uStack_2c;
        uVar3 = uVar7 & auStack_3c[0];
      }
      if ((uVar3 != 0) && (param_3 - auStack_3c[0] < local_40)) {
        return param_2;
      }
    }
    param_2 = (int *)((int)param_2 + *param_2 + 4);
  } while( true );
}



// Function at 0x400e9508

undefined4 FUN_400e9508(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400e9308((param_1 + 4) - *(int *)(param_1 + 4));
  return uVar1;
}



// Function at 0x400e951c

int FUN_400e951c(undefined4 param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint local_30;
  uint auStack_2c [11];
  
  uVar1 = FUN_400e9508(param_2);
  uVar2 = FUN_400e91a8(uVar1,param_1);
  FUN_400e91f0(uVar1,uVar2,param_2 + 8,auStack_2c);
  uVar1 = FUN_400e9508(param_3);
  uVar2 = FUN_400e91a8(uVar1,param_1);
  FUN_400e91f0(uVar1,uVar2,param_3 + 8,&local_30);
  iVar3 = 1;
  if (auStack_2c[0] <= local_30) {
    iVar3 = -(uint)(auStack_2c[0] < local_30);
  }
  return iVar3;
}



// Function at 0x400e956c

int FUN_400e956c(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 1;
  if (*(uint *)(param_2 + 8) <= *(uint *)(param_3 + 8)) {
    iVar1 = -(uint)(*(uint *)(param_2 + 8) < *(uint *)(param_3 + 8));
  }
  return iVar1;
}



// Function at 0x400e95b8

void FUN_400e95b8(int param_1,int *param_2,int *param_3)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint local_40 [4];
  uint uStack_30;
  undefined4 uStack_2c;
  
  uVar4 = *(uint *)(param_1 + 0x10) >> 3 & 0xff;
  uVar2 = FUN_400e91a8(uVar4,param_1);
  iVar6 = 0;
  for (; *param_3 != 0; param_3 = (int *)((int)param_3 + *param_3 + 4)) {
    if (param_3[1] != 0) {
      if (((*(uint *)(param_1 + 0x10) & 4) != 0) &&
         (iVar5 = (int)param_3 + (4 - param_3[1]), bVar1 = iVar6 != iVar5, iVar6 = iVar5, bVar1)) {
        uVar4 = FUN_400e9308(iVar5);
        uVar2 = FUN_400e91a8(uVar4 & 0xff,param_1);
      }
      if (uVar4 == 0) {
        local_40[0] = param_3[2];
        uVar3 = local_40[0];
      }
      else {
        uStack_30 = uVar4 & 0xff;
        uStack_2c = uVar2;
        FUN_400e91f0(uStack_30,uVar2,param_3 + 2,local_40);
        uVar3 = FUN_400e9174(uStack_30);
        uVar7 = 0xffffffff;
        if (uVar3 < 4) {
          uVar7 = (1 << 0x20 - ((uVar3 & 3) * -8 + 0x20)) - 1;
        }
        uVar2 = uStack_2c;
        uVar3 = uVar7 & local_40[0];
      }
      if ((uVar3 != 0) && (iVar5 = *param_2, iVar5 != 0)) {
        iVar8 = *(int *)(iVar5 + 4);
        *(int *)(iVar5 + 4) = iVar8 + 1;
        *(int **)(iVar5 + iVar8 * 4 + 8) = param_3;
      }
    }
  }
  return;
}



// Function at 0x400e966c

int FUN_400e966c(uint *param_1,uint param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  int *piVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  uint uVar11;
  code *pcVar12;
  uint uVar13;
  uint *puVar14;
  uint *puVar15;
  uint *local_50;
  uint *puStack_4c;
  uint auStack_48 [2];
  uint *puStack_40;
  uint *puStack_3c;
  uint uStack_38;
  uint *puStack_34;
  uint *puStack_30;
  code *pcStack_2c;
  
  uVar8 = param_1[4];
  if ((uVar8 & 1) != 0) goto LAB_400e9676;
  puVar2 = (uint *)(uVar8 >> 0xb);
  if (puVar2 == (uint *)0x0) {
    piVar5 = (int *)param_1[3];
    if ((uVar8 & 2) != 0) {
      for (; *piVar5 != 0; piVar5 = piVar5 + 1) {
        iVar4 = FUN_400e9398(param_1);
        if (iVar4 == -1) goto LAB_400e969a;
        puVar2 = (uint *)((int)puVar2 + iVar4);
      }
LAB_400e96c1:
      if ((uint *)((uint)puVar2 & DAT_400d13e8) == puVar2) {
        uVar8 = param_1[4] & 0x7ff | (int)puVar2 << 0xb;
      }
      else {
        uVar8 = param_1[4] & 0x7ff;
      }
      param_1[4] = uVar8;
      goto LAB_400e96dd;
    }
    puVar2 = (uint *)FUN_400e9398(param_1,piVar5);
    if (puVar2 != (uint *)0xffffffff) goto LAB_400e96c1;
LAB_400e969a:
    param_1[4] = 0x7f8;
    param_1[3] = DAT_400d13e4;
  }
  else {
LAB_400e96dd:
    if ((*DAT_400d13ec != '\0') && (puVar2 != (uint *)0x0 && *DAT_400d13ec != '\0')) {
      iVar4 = ((int)puVar2 + 2U) * 4;
      local_50 = (uint *)func_0x4008dbdc(iVar4);
      if (local_50 != (uint *)0x0) {
        local_50[1] = 0;
        puStack_4c = (uint *)func_0x4008dbdc(iVar4);
        if (puStack_4c != (uint *)0x0) {
          puStack_4c[1] = 0;
        }
        piVar5 = (int *)param_1[3];
        if ((param_1[4] & 2) == 0) {
          FUN_400e95b8(param_1,&local_50,piVar5);
        }
        else {
          for (; *piVar5 != 0; piVar5 = piVar5 + 1) {
            FUN_400e95b8(param_1,&local_50);
          }
        }
        uVar8 = 0;
        puVar6 = local_50;
        if (local_50 == (uint *)0x0) goto LAB_400e974a;
        if (puVar2 == (uint *)local_50[1]) goto LAB_400e974a;
        do {
          func_0x4008da40();
LAB_400e974a:
          pcVar12 = (code *)PTR_FUN_400d13d4;
          if (((param_1[4] & 4) == 0) &&
             (pcVar12 = (code *)PTR_FUN_400d13d8, (param_1[4] & 0x7f8) != 0)) {
            pcVar12 = (code *)PTR_FUN_400d13dc;
          }
          if (puStack_4c == (uint *)0x0) {
            FUN_400e9124(param_1,pcVar12,puVar6);
            goto LAB_400e9881;
          }
          uVar11 = puVar6[1];
          puStack_40 = puVar6 + uVar11;
          puVar15 = puStack_4c + 2;
          puVar10 = DAT_400d13e0;
          puVar14 = puStack_4c;
          for (puVar3 = puVar6; puStack_40 != puVar3; puVar3 = puVar3 + 1) {
            while ((puVar10 != DAT_400d13e0 &&
                   (puStack_3c = puVar3, uStack_38 = uVar11, puStack_34 = puVar15,
                   puStack_30 = puVar14, pcStack_2c = pcVar12,
                   iVar4 = (*pcVar12)(param_1,puVar3[2],*puVar10), pcVar12 = pcStack_2c,
                   puVar14 = puStack_30, puVar3 = puStack_3c, puVar15 = puStack_34,
                   uVar11 = uStack_38, iVar4 < 0))) {
              puVar9 = *(uint **)((int)puStack_30 + (int)puVar10 + (8 - (int)(puVar6 + 2)));
              *(undefined4 *)((int)puStack_30 + (int)puVar10 + (8 - (int)(puVar6 + 2))) = 0;
              puVar10 = puVar9;
            }
            *puVar15 = (uint)puVar10;
            puVar10 = puVar3 + 2;
            puVar15 = puVar15 + 1;
          }
          iVar4 = 8;
          uVar7 = uVar8;
          for (uVar13 = uVar8; uVar11 != uVar13; uVar13 = uVar13 + 1) {
            if (*(int *)((int)puVar14 + iVar4) == 0) {
              puVar14[uVar7 + 2] = *(uint *)((int)puVar6 + iVar4);
              uVar7 = uVar7 + 1;
            }
            else {
              puVar6[uVar8 + 2] = *(uint *)((int)puVar6 + iVar4);
              uVar8 = uVar8 + 1;
            }
            iVar4 = iVar4 + 4;
          }
          puVar6[1] = uVar8;
          puVar14[1] = uVar7;
          uVar8 = puStack_4c[1];
          puVar6 = (uint *)(local_50[1] + uVar8);
        } while (puVar2 != puVar6);
        pcStack_2c = pcVar12;
        FUN_400e9124(param_1,pcVar12);
        puVar2 = local_50;
        uVar8 = puStack_4c[1];
        if (uVar8 != 0) {
          puVar6 = (uint *)(uVar8 << 2);
          uVar11 = local_50[1];
          pcVar12 = pcStack_2c;
          puVar10 = puStack_4c;
          do {
            uVar8 = uVar8 - 1;
            puVar3 = puVar2 + uVar11 + 1;
            puVar14 = *(uint **)((int)puVar10 + (int)puVar6 + 4);
            while (uVar11 != 0) {
              uStack_38 = uVar11 - 1;
              puStack_3c = puVar10;
              puStack_34 = puVar14;
              puStack_30 = puVar6;
              pcStack_2c = pcVar12;
              iVar4 = (*pcVar12)(param_1,*puVar3,puVar14);
              pcVar12 = pcStack_2c;
              puVar6 = puStack_30;
              puVar10 = puStack_3c;
              puVar14 = puStack_34;
              if (iVar4 < 1) break;
              *(uint *)((int)puVar3 + (int)puStack_30) = *puVar3;
              puVar3 = puVar3 + -1;
              uVar11 = uStack_38;
            }
            puVar2[uVar11 + uVar8 + 2] = (uint)puVar14;
            puVar6 = puVar6 + -1;
          } while (uVar8 != 0);
          puVar2[1] = puVar2[1] + puVar10[1];
        }
        func_0x4008dbfc(puStack_4c);
LAB_400e9881:
        *local_50 = param_1[3];
        param_1[3] = (uint)local_50;
        param_1[4] = param_1[4] | 1;
      }
    }
  }
  if (param_2 < *param_1) {
    return 0;
  }
LAB_400e9676:
  uVar8 = param_1[4];
  piVar5 = (int *)param_1[3];
  if ((uVar8 & 1) == 0) {
    if ((uVar8 & 2) == 0) {
      iVar4 = FUN_400e9454(param_1,piVar5,param_2);
      return iVar4;
    }
    for (; *piVar5 != 0; piVar5 = piVar5 + 1) {
      iVar4 = FUN_400e9454(param_1,*piVar5,param_2);
      if (iVar4 != 0) {
        return iVar4;
      }
    }
  }
  else if ((uVar8 & 4) == 0) {
    if ((uVar8 & 0x7f8) == 0) {
      uVar8 = 0;
      uVar11 = piVar5[1];
      while (uVar7 = uVar11, uVar8 < uVar7) {
        uVar11 = uVar8 + uVar7 >> 1;
        iVar4 = piVar5[uVar11 + 2];
        if (*(uint *)(iVar4 + 8) <= param_2) {
          if (param_2 < *(uint *)(iVar4 + 8) + *(int *)(iVar4 + 0xc)) {
            return iVar4;
          }
          uVar8 = uVar11 + 1;
          uVar11 = uVar7;
        }
      }
    }
    else {
      uVar7 = uVar8 >> 3 & 0xff;
      puStack_34 = (uint *)FUN_400e91a8(uVar7,param_1);
      pcStack_2c = (code *)piVar5[1];
      uVar11 = 0;
      while (uVar11 < pcStack_2c) {
        uVar13 = uVar11 + (int)pcStack_2c >> 1;
        iVar4 = piVar5[uVar13 + 2];
        puStack_30 = (uint *)pcStack_2c;
        pcStack_2c = (code *)uVar13;
        uVar1 = FUN_400e91f0(uVar7,puStack_34,iVar4 + 8,auStack_48);
        FUN_400e91f0(uVar8 >> 3 & 0xf,0,uVar1,&local_50);
        if (auStack_48[0] <= param_2) {
          if (param_2 < auStack_48[0] + (int)local_50) {
            return iVar4;
          }
          uVar11 = (int)pcStack_2c + 1;
          pcStack_2c = (code *)puStack_30;
        }
      }
    }
  }
  else {
    puStack_30 = (uint *)0x0;
    pcVar12 = (code *)piVar5[1];
    while (puStack_30 < pcVar12) {
      uVar11 = (uint)((int)puStack_30 + (int)pcVar12) >> 1;
      iVar4 = piVar5[uVar11 + 2];
      pcStack_2c = pcVar12;
      uVar8 = FUN_400e9508(iVar4);
      puStack_34 = (uint *)(uVar8 & 0xff);
      uVar1 = FUN_400e91a8(puStack_34,param_1);
      uVar1 = FUN_400e91f0(puStack_34,uVar1,iVar4 + 8,auStack_48);
      FUN_400e91f0(uVar8 & 0xf,0,uVar1,&local_50);
      pcVar12 = (code *)uVar11;
      if (auStack_48[0] <= param_2) {
        if (param_2 < auStack_48[0] + (int)local_50) {
          return iVar4;
        }
        puStack_30 = (uint *)(uVar11 + 1);
        pcVar12 = pcStack_2c;
      }
    }
  }
  return 0;
}



// Function at 0x400e99fc

void FUN_400e99fc(undefined1 param_1)

{
  *DAT_400d13ec = param_1;
  return;
}



// Function at 0x400e9a08

void FUN_400e9a08(int *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    param_2[3] = param_1;
    param_2[4] = 0x7f8;
    puVar1 = PTR_FUN_400d13f0;
    *param_2 = 0xffffffff;
    param_2[1] = param_3;
    param_2[2] = param_4;
    if (puVar1 != (undefined *)0x0) {
      func_0x400830f4(DAT_400d13f4);
    }
    uVar2 = *DAT_400d13f8;
    *DAT_400d13f8 = param_2;
    param_2[5] = uVar2;
    if (puVar1 != (undefined *)0x0) {
      func_0x4008311c(DAT_400d13f4);
    }
  }
  return;
}



// Function at 0x400e9a44

void FUN_400e9a44(undefined4 param_1,undefined4 param_2)

{
  FUN_400e9a08(param_1,param_2,0);
  return;
}



// Function at 0x400e9a54

void FUN_400e9a54(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 != 0) {
    uVar1 = func_0x4008dbdc(0x18);
    FUN_400e9a44(param_1,uVar1);
  }
  return;
}



// Function at 0x400e9a6c

void FUN_400e9a6c(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  
  param_2[3] = param_1;
  param_2[4] = 0x7fa;
  puVar1 = PTR_FUN_400d13f0;
  *param_2 = 0xffffffff;
  param_2[1] = param_3;
  param_2[2] = param_4;
  if (puVar1 != (undefined *)0x0) {
    func_0x400830f4(DAT_400d13f4);
  }
  uVar2 = *DAT_400d13f8;
  *DAT_400d13f8 = param_2;
  param_2[5] = uVar2;
  if (puVar1 != (undefined *)0x0) {
    func_0x4008311c(DAT_400d13f4);
  }
  return;
}



// Function at 0x400e9aa0

void FUN_400e9aa0(undefined4 param_1,undefined4 param_2)

{
  FUN_400e9a6c(param_1,param_2,0);
  return;
}



// Function at 0x400e9ab0

void FUN_400e9ab0(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = func_0x4008dbdc(0x18);
  FUN_400e9aa0(param_1,uVar1);
  return;
}



// Function at 0x400e9ac4

void FUN_400e9ac4(int *param_1)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  
  puVar1 = PTR_FUN_400d13f0;
  if (param_1 == (int *)0x0) {
    return;
  }
  if (*param_1 == 0) {
    return;
  }
  if (PTR_FUN_400d13f0 != (undefined *)0x0) {
    func_0x400830f4(DAT_400d13f4);
  }
  iVar2 = *DAT_400d13f8;
  piVar3 = DAT_400d13f8;
  while (iVar2 != 0) {
    if (param_1 == *(int **)(iVar2 + 0xc)) {
      *piVar3 = *(int *)(iVar2 + 0x14);
      goto LAB_400e9b52;
    }
    piVar3 = (int *)(iVar2 + 0x14);
    iVar2 = *(int *)(iVar2 + 0x14);
  }
  iVar2 = *DAT_400d13fc;
  piVar3 = DAT_400d13fc;
LAB_400e9b31:
  if (iVar2 == 0) goto LAB_400e9b4c;
  if ((*(uint *)(iVar2 + 0x10) & 1) != 0) {
    if (param_1 == (int *)**(int **)(iVar2 + 0xc)) {
      *piVar3 = *(int *)(iVar2 + 0x14);
      func_0x4008dbfc();
      goto LAB_400e9b52;
    }
LAB_400e9b2c:
    piVar3 = (int *)(iVar2 + 0x14);
    iVar2 = *(int *)(iVar2 + 0x14);
    goto LAB_400e9b31;
  }
  if (param_1 != *(int **)(iVar2 + 0xc)) goto LAB_400e9b2c;
  *piVar3 = *(int *)(iVar2 + 0x14);
LAB_400e9b52:
  if (puVar1 == (undefined *)0x0) {
    return;
  }
LAB_400e9b38:
  func_0x4008311c(DAT_400d13f4);
  if (iVar2 != 0) {
    return;
  }
LAB_400e9b43:
  func_0x4008da40();
  return;
LAB_400e9b4c:
  if (puVar1 == (undefined *)0x0) goto LAB_400e9b43;
  goto LAB_400e9b38;
}



// Function at 0x400e9b58

undefined4 FUN_400e9b58(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400e9ac4(param_1);
  return uVar1;
}



// Function at 0x400e9b64

void FUN_400e9b64(int *param_1)

{
  if (*param_1 != 0) {
    FUN_400e9ac4(param_1);
    func_0x4008dbfc();
  }
  return;
}



// Function at 0x400e9b78

int FUN_400e9b78(uint param_1,uint *param_2)

{
  undefined *puVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  uint local_30 [12];
  
  puVar1 = PTR_FUN_400d13f0;
  if (PTR_FUN_400d13f0 != (undefined *)0x0) {
    func_0x400830f4(DAT_400d13f4);
  }
  puVar2 = DAT_400d13fc;
  for (puVar5 = (uint *)*DAT_400d13fc; puVar5 != (uint *)0x0; puVar5 = (uint *)puVar5[5]) {
    if (*puVar5 <= param_1) {
      iVar3 = FUN_400e966c(puVar5,param_1);
      goto LAB_400e9bd8;
    }
  }
  do {
    puVar5 = (uint *)*DAT_400d13f8;
    if (puVar5 == (uint *)0x0) {
      iVar3 = 0;
      if (puVar1 == (undefined *)0x0) {
        return 0;
      }
      goto LAB_400e9be8;
    }
    *DAT_400d13f8 = puVar5[5];
    iVar3 = FUN_400e966c(puVar5,param_1);
    puVar7 = puVar2;
    for (puVar6 = (uint *)*puVar2; (puVar6 != (uint *)0x0 && (*puVar5 <= *puVar6));
        puVar6 = (uint *)puVar6[5]) {
      puVar7 = puVar6 + 5;
    }
    puVar5[5] = (uint)puVar6;
    *puVar7 = (uint)puVar5;
LAB_400e9bd8:
  } while (iVar3 == 0);
  if (puVar1 != (undefined *)0x0) {
LAB_400e9be8:
    func_0x4008311c(DAT_400d13f4);
    if (iVar3 == 0) {
      return 0;
    }
  }
  uVar8 = puVar5[4];
  *param_2 = puVar5[1];
  param_2[1] = puVar5[2];
  if ((uVar8 & 4) == 0) {
    uVar8 = uVar8 >> 3 & 0xff;
  }
  else {
    uVar8 = FUN_400e9508(iVar3);
  }
  uVar4 = FUN_400e91a8(uVar8 & 0xff,puVar5);
  FUN_400e91f0(uVar8 & 0xff,uVar4,iVar3 + 8,local_30);
  param_2[2] = local_30[0];
  return iVar3;
}



// Function at 0x400e9c44

longlong FUN_400e9c44(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  
  lVar3 = CONCAT44(param_2,param_1);
  uVar2 = param_2 >> 0x14 & 0x7ff;
  uVar1 = uVar2 - 0x3ff;
  if ((int)uVar1 < 0x14) {
    if ((int)uVar1 < 0) {
      lVar3 = (ulonglong)(param_2 & DAT_400d0284) << 0x20;
      if (uVar1 == 0xffffffff) {
        lVar3 = (ulonglong)(param_2 & DAT_400d0284 | DAT_400d1400) << 0x20;
      }
    }
    else {
      uVar2 = DAT_400d023c >> (uVar1 & 0x1f);
      lVar3 = CONCAT44(param_2,param_1);
      if ((uVar2 & param_2) != 0 || param_1 != 0) {
        lVar3 = (ulonglong)((DAT_400d0614 >> (uVar1 & 0x1f)) + param_2 & (uVar2 ^ 0xffffffff)) <<
                0x20;
      }
    }
  }
  else if ((int)uVar1 < 0x34) {
    uVar2 = 0xffffffff >> (uVar2 + 0xd & 0x1f);
    if ((param_1 & uVar2) != 0) {
      uVar1 = (1 << 0x20 - (0x20 - (0x33 - uVar1 & 0x1f))) + param_1;
      if (uVar1 < param_1) {
        param_2 = param_2 + 1;
      }
      lVar3 = CONCAT44(param_2,(uVar2 ^ 0xffffffff) & uVar1);
    }
  }
  else {
    lVar3 = CONCAT44(param_2,param_1);
    if (uVar1 == 0x400) {
      lVar3 = (*DAT_400d0068)(param_1,param_2,param_1,param_2);
    }
  }
  return lVar3;
}



// Function at 0x400e9ce8

undefined8 FUN_400e9ce8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_400e9d60(param_1,param_2);
  if (((*DAT_400d1404 != -1) &&
      (iVar1 = (*DAT_400d140c)(param_1,param_2,param_1,param_2), iVar1 == 0)) &&
     (iVar1 = (*DAT_400d0090)(param_1,param_2,DAT_400d0028,DAT_400d0028), iVar1 < 1)) {
    iVar1 = (*DAT_400d1410)(param_1,param_2,DAT_400d0028,DAT_400d0028);
    if (iVar1 == 0) {
      puVar2 = (undefined4 *)FUN_400ea128();
      *puVar2 = 0x22;
      uVar3 = CONCAT44(DAT_400d0c18,DAT_400d0028);
    }
    else {
      puVar2 = (undefined4 *)FUN_400ea128();
      *puVar2 = 0x21;
      uVar3 = FUN_400ea11c(DAT_400d1408);
    }
  }
  return uVar3;
}



// Function at 0x400e9d60

undefined8 FUN_400e9d60(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  
  uVar18 = CONCAT44(param_2,param_1);
  uVar17 = CONCAT44(DAT_400d1414,DAT_400d0028);
  if ((int)DAT_400d023c < (int)param_2) {
    iVar13 = 0;
  }
  else {
    if ((DAT_400d0140 & param_2) == 0 && param_1 == 0) {
LAB_400e9d9e:
      uVar17 = (*DAT_400d006c)((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),DAT_400d0028,
                               DAT_400d0028);
      return uVar17;
    }
    if ((int)param_2 < 0) {
      uVar17 = (*DAT_400d0070)(param_1,param_2,param_1,param_2);
      goto LAB_400e9d9e;
    }
    uVar18 = (*DAT_400d0064)(param_1,param_2,DAT_400d0028,DAT_400d1418);
    iVar13 = -0x36;
  }
  uVar15 = DAT_400d023c;
  uVar16 = (uint)((ulonglong)uVar18 >> 0x20);
  uVar17 = uVar18;
  if (DAT_400d141c < (int)uVar16) {
LAB_400e9e60:
    uVar17 = (*DAT_400d0068)((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar18,
                             (int)((ulonglong)uVar18 >> 0x20));
  }
  else {
    uVar14 = uVar16 & DAT_400d023c;
    uVar12 = uVar14 + DAT_400d1420 & DAT_400d0608;
    uVar18 = (*DAT_400d0070)((int)uVar18,uVar12 ^ DAT_400d1400 | uVar14,DAT_400d0028,DAT_400d1400);
    uVar17 = CONCAT44(DAT_400d0028,DAT_400d0028);
    uVar6 = (undefined4)((ulonglong)uVar18 >> 0x20);
    uVar1 = (undefined4)uVar18;
    iVar13 = ((int)uVar12 >> 0x14) + ((int)uVar16 >> 0x14) + -0x3ff + iVar13;
    if ((int)(uVar14 + 2 & uVar15) < 3) {
      iVar2 = (*DAT_400d1410)(uVar1,uVar6,DAT_400d0028,DAT_400d0028);
      if (iVar2 == 0) {
        if (iVar13 == 0) {
          return uVar17;
        }
        uVar18 = (*DAT_400d00e4)(iVar13);
        uVar1 = (undefined4)((ulonglong)uVar18 >> 0x20);
        uVar17 = (*DAT_400d0064)((int)uVar18,uVar1,DAT_400d1424,DAT_400d1428);
        uVar18 = (*DAT_400d0064)((int)uVar18,uVar1,DAT_400d142c,DAT_400d1430);
        goto LAB_400e9e60;
      }
      uVar17 = (*DAT_400d0064)(uVar1,uVar6,DAT_400d1434,DAT_400d1438);
      uVar17 = (*DAT_400d0070)(DAT_400d0028,DAT_400d143c,(int)uVar17,
                               (int)((ulonglong)uVar17 >> 0x20));
      uVar19 = (*DAT_400d0064)(uVar1,uVar6);
      uVar17 = (*DAT_400d0064)((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar19,
                               (int)((ulonglong)uVar19 >> 0x20));
      if (iVar13 != 0) {
        uVar19 = (*DAT_400d00e4)(iVar13);
        uVar7 = (undefined4)((ulonglong)uVar19 >> 0x20);
        uVar18 = (*DAT_400d0064)((int)uVar19,uVar7,DAT_400d1424,DAT_400d1428);
        uVar19 = (*DAT_400d0064)((int)uVar19,uVar7,DAT_400d142c,DAT_400d1430);
        goto LAB_400ea07a;
      }
    }
    else {
      uVar17 = (*DAT_400d0068)(uVar1,uVar6,DAT_400d0028,DAT_400d0088);
      uVar17 = (*DAT_400d006c)(uVar1,uVar6,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
      uVar8 = (undefined4)((ulonglong)uVar17 >> 0x20);
      uVar7 = (undefined4)uVar17;
      uVar17 = (*DAT_400d00e4)(iVar13);
      uVar9 = (undefined4)((ulonglong)uVar17 >> 0x20);
      uVar3 = (undefined4)uVar17;
      uVar17 = (*DAT_400d0064)(uVar7,uVar8);
      uVar10 = (undefined4)((ulonglong)uVar17 >> 0x20);
      uVar4 = (undefined4)uVar17;
      uVar15 = uVar14 + DAT_400d1440;
      uVar17 = (*DAT_400d0064)(uVar4,uVar10,uVar4,uVar10);
      uVar11 = (undefined4)((ulonglong)uVar17 >> 0x20);
      uVar5 = (undefined4)uVar17;
      uVar17 = (*DAT_400d0064)(uVar5,uVar11,DAT_400d1444,DAT_400d1448);
      uVar17 = (*DAT_400d0068)((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),DAT_400d144c,
                               DAT_400d1450);
      uVar17 = (*DAT_400d0064)((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar5,uVar11);
      uVar17 = (*DAT_400d0068)((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),DAT_400d1454,
                               DAT_400d1458);
      uVar17 = (*DAT_400d0064)((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar5,uVar11);
      uVar17 = (*DAT_400d0068)((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),DAT_400d145c,
                               DAT_400d1460);
      uVar17 = (*DAT_400d0064)((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar4,uVar10);
      uVar19 = (*DAT_400d0064)(uVar5,uVar11,DAT_400d1464,DAT_400d1468);
      uVar19 = (*DAT_400d0068)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),DAT_400d146c,
                               DAT_400d1470);
      uVar19 = (*DAT_400d0064)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),uVar5,uVar11);
      uVar19 = (*DAT_400d0068)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),DAT_400d1474,
                               DAT_400d1478);
      uVar19 = (*DAT_400d0064)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),uVar5,uVar11);
      uVar19 = (*DAT_400d0068)((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar19,
                               (int)((ulonglong)uVar19 >> 0x20));
      uVar4 = (undefined4)((ulonglong)uVar19 >> 0x20);
      if ((int)(DAT_400d147c - uVar14 | uVar15) < 1) {
        uVar17 = (*DAT_400d0070)(uVar1,uVar6,(int)uVar19,uVar4);
        uVar17 = (*DAT_400d0064)((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar7,uVar8);
        if (iVar13 != 0) {
          uVar18 = (*DAT_400d0064)(uVar3,uVar9,DAT_400d1424,DAT_400d1428);
          uVar19 = (*DAT_400d0064)(uVar3,uVar9,DAT_400d142c,DAT_400d1430);
          uVar17 = (*DAT_400d0070)((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar19,
                                   (int)((ulonglong)uVar19 >> 0x20));
          uVar17 = (*DAT_400d0070)((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar1,uVar6);
        }
      }
      else {
        uVar17 = (*DAT_400d0064)(uVar1,uVar6,DAT_400d0028,DAT_400d143c);
        uVar17 = (*DAT_400d0064)((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar1,uVar6);
        uVar5 = (undefined4)((ulonglong)uVar17 >> 0x20);
        uVar19 = (*DAT_400d0068)((int)uVar19,uVar4,(int)uVar17,uVar5);
        uVar19 = (*DAT_400d0064)((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),uVar7,uVar8);
        uVar7 = (undefined4)((ulonglong)uVar19 >> 0x20);
        if (iVar13 == 0) {
          uVar17 = (*DAT_400d0070)((int)uVar17,uVar5,(int)uVar19,uVar7);
        }
        else {
          uVar18 = (*DAT_400d0064)(uVar3,uVar9,DAT_400d1424,DAT_400d1428);
          uVar20 = (*DAT_400d0064)(uVar3,uVar9,DAT_400d142c,DAT_400d1430);
          uVar19 = (*DAT_400d0068)((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar19,uVar7);
LAB_400ea07a:
          uVar17 = (*DAT_400d0070)((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar19,
                                   (int)((ulonglong)uVar19 >> 0x20));
          uVar17 = (*DAT_400d0070)((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar1,uVar6);
        }
      }
    }
    uVar17 = (*DAT_400d0070)((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
                             (int)((ulonglong)uVar17 >> 0x20));
  }
  return uVar17;
}



// Function at 0x400ea11c

undefined8 FUN_400ea11c(void)

{
  return CONCAT44(DAT_400d1480,DAT_400d0028);
}



// Function at 0x400ea128

undefined4 FUN_400ea128(void)

{
  undefined4 uVar1;
  
  uVar1 = func_0x4008a814();
  return uVar1;
}



// Function at 0x400ea134

int FUN_400ea134(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_30;
  undefined4 local_2c [11];
  
  uVar2 = FUN_400f2064(param_1,param_3,local_2c);
  if ((uVar2 != 0) && (iVar3 = func_0x400860c4(param_1), iVar3 != 0)) {
    iVar4 = FUN_400e1744(param_1,param_2,local_2c[0],0x1b6);
    if (-1 < iVar4) {
      FUN_400f8218(1,&local_30);
      if (((*(uint *)(iVar3 + 100) & 1) == 0) && ((*(ushort *)(iVar3 + 0xc) & 0x200) == 0)) {
        func_0x400853c0(*(undefined4 *)(iVar3 + 0x58));
      }
      *(short *)(iVar3 + 0xe) = (short)iVar4;
      uVar1 = DAT_400d1484;
      *(short *)(iVar3 + 0xc) = (short)uVar2;
      *(undefined4 *)(iVar3 + 0x24) = uVar1;
      uVar1 = DAT_400d1488;
      *(int *)(iVar3 + 0x20) = iVar3;
      *(undefined4 *)(iVar3 + 0x28) = uVar1;
      *(undefined4 *)(iVar3 + 0x2c) = DAT_400d148c;
      *(undefined4 *)(iVar3 + 0x30) = DAT_400d1490;
      if ((uVar2 & 0x100) != 0) {
        FUN_400ea204(param_1,iVar3,0,2);
      }
      if (((*(uint *)(iVar3 + 100) & 1) == 0) && ((*(ushort *)(iVar3 + 0xc) & 0x200) == 0)) {
        func_0x400853d8(*(undefined4 *)(iVar3 + 0x58));
      }
      FUN_400f8218(local_30,&local_30);
      return iVar3;
    }
    FUN_400f8218(1,&local_30);
    func_0x4008603c();
    *(undefined2 *)(iVar3 + 0xc) = 0;
    func_0x400853ac(*(undefined4 *)(iVar3 + 0x58));
    func_0x40086048();
    FUN_400f8218(local_30,&local_30);
  }
  return 0;
}



// Function at 0x400ea204

undefined4 FUN_400ea204(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400ea234(param_1,param_2,param_3,param_4);
  return uVar1;
}



// Function at 0x400ea21c

undefined4 FUN_400ea21c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = func_0x4008a814();
  uVar1 = FUN_400ea234(uVar1,param_1,param_2,param_3);
  return uVar1;
}



// Function at 0x400ea234

undefined4 FUN_400ea234(undefined4 *param_1,int *param_2,uint param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  code *pcVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  undefined1 auStack_70 [4];
  uint uStack_6c;
  int iStack_60;
  int iStack_44;
  undefined4 uStack_34;
  uint uStack_30;
  int iStack_2c;
  
  if ((param_1 != (undefined4 *)0x0) && (param_1[6] == 0)) {
    func_0x4008606c(param_1);
  }
  if (param_2 == DAT_400d1494) {
    param_2 = (int *)param_1[1];
  }
  else if (param_2 == DAT_400d1498) {
    param_2 = (int *)param_1[2];
  }
  else if (param_2 == DAT_400d149c) {
    param_2 = (int *)param_1[3];
  }
  FUN_400f8218(1,&uStack_34);
  if (((param_2[0x19] & 1U) == 0) && ((*(ushort *)(param_2 + 3) & 0x200) == 0)) {
    func_0x400853c0(param_2[0x16]);
  }
  if ((*(ushort *)(param_2 + 3) & 0x108) == 0x108) {
    func_0x40085ec8(param_1,param_2);
  }
  pcVar5 = (code *)param_2[0xb];
  if (pcVar5 == (code *)0x0) {
    uVar3 = 0x1d;
LAB_400ea2c6:
    *param_1 = uVar3;
LAB_400ea4a0:
    if (((param_2[0x19] & 1U) == 0) && ((*(ushort *)(param_2 + 3) & 0x200) == 0)) {
      func_0x400853d8(param_2[0x16]);
    }
    FUN_400f8218(uStack_34,&uStack_34);
    uVar3 = 0xffffffff;
  }
  else {
    if (param_4 == 1) {
      iVar2 = FUN_400ea548(param_1,param_2);
      if (iVar2 != -1) {
        param_3 = param_3 + iVar2;
        iVar4 = 0;
        goto LAB_400ea2d7;
      }
      uVar3 = 0xffffffff;
    }
    else {
      iVar4 = param_4;
      if (param_4 == 2) {
        iVar2 = 0;
        param_4 = 0;
      }
      else {
        if (param_4 != 0) {
          uVar3 = 0x16;
          goto LAB_400ea2c6;
        }
        iVar2 = 0;
      }
LAB_400ea2d7:
      if (param_2[4] == 0) {
        iStack_2c = param_4;
        func_0x4008657c(param_1,param_2);
        param_4 = iStack_2c;
      }
      if ((*(ushort *)(param_2 + 3) & DAT_400d14a0) == 0) {
        if ((*(ushort *)(param_2 + 3) & 0x400) == 0) {
          if ((pcVar5 == DAT_400d148c) && (-1 < *(short *)((int)param_2 + 0xe))) {
            uStack_30 = 0x400;
            iStack_2c = param_4;
            iVar1 = FUN_400e1980(param_1,(int)*(short *)((int)param_2 + 0xe),auStack_70);
            if ((iVar1 == 0) && ((uStack_6c & DAT_400d14a4) == DAT_400d0600)) {
              param_2[0x14] = iStack_44;
              *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | (ushort)uStack_30;
              param_4 = iStack_2c;
              goto LAB_400ea349;
            }
          }
          *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | (ushort)DAT_400d01f8;
        }
        else {
LAB_400ea349:
          uVar6 = param_3;
          if (iVar4 != 0) {
            iStack_2c = param_4;
            iVar1 = FUN_400e1980(param_1,(int)*(short *)((int)param_2 + 0xe),auStack_70);
            if (iVar1 != 0) goto LAB_400ea492;
            uVar6 = param_3 + iStack_60;
            param_4 = iStack_2c;
          }
          if (param_4 == 0) {
            if ((*(ushort *)(param_2 + 3) & 0x1000) == 0) {
              uStack_30 = uVar6;
              iVar2 = (*pcVar5)(param_1,param_2[8],0,1);
              uVar6 = uStack_30;
              if (iVar2 == -1) goto LAB_400ea492;
            }
            else {
              iVar2 = param_2[0x15];
            }
            iVar2 = iVar2 - param_2[1];
            if (param_2[0xd] != 0) {
              iVar2 = iVar2 - param_2[0x10];
            }
          }
          piVar8 = (int *)param_2[0xd];
          iVar1 = param_2[4];
          if (piVar8 == (int *)0x0) {
            iVar2 = iVar2 - (*param_2 - iVar1);
            iVar7 = param_2[1] + (*param_2 - iVar1);
          }
          else {
            iVar2 = (iVar2 + param_2[1]) - (param_2[0xf] - iVar1);
            iVar7 = (param_2[0xf] - iVar1) + param_2[0x10];
          }
          if ((iVar2 <= (int)uVar6) && (uVar6 < (uint)(iVar2 + iVar7))) {
            *param_2 = iVar1 + (uVar6 - iVar2);
            param_2[1] = iVar7 - (uVar6 - iVar2);
            if (piVar8 != (int *)0x0) {
              if (piVar8 != param_2 + 0x11) {
                func_0x4008dc14(param_1);
              }
              param_2[0xd] = 0;
            }
            *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) & 0xffdf;
            goto LAB_400ea466;
          }
          iVar1 = param_2[0x14];
          uStack_30 = uVar6;
          iVar2 = (*pcVar5)(param_1,param_2[8],-iVar1 & uVar6,0);
          if (iVar2 != -1) {
            param_2[1] = 0;
            *param_2 = param_2[4];
            if ((int *)param_2[0xd] != (int *)0x0) {
              if ((int *)param_2[0xd] != param_2 + 0x11) {
                func_0x4008dc14(param_1);
              }
              param_2[0xd] = 0;
            }
            *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) & 0xffdf;
            uVar6 = uStack_30 - (-iVar1 & uVar6);
            if (uVar6 == 0) {
LAB_400ea466:
              func_0x40086818(param_2 + 0x17,0,8);
              if (((param_2[0x19] & 1U) == 0) && ((*(ushort *)(param_2 + 3) & 0x200) == 0)) {
                func_0x400853d8(param_2[0x16]);
              }
              FUN_400f8218(uStack_34,&uStack_34);
              return 0;
            }
            iVar2 = func_0x40086880(param_1,param_2);
            if ((iVar2 == 0) && (uVar6 <= (uint)param_2[1])) {
              *param_2 = *param_2 + uVar6;
              param_2[1] = param_2[1] - uVar6;
              goto LAB_400ea466;
            }
          }
        }
      }
LAB_400ea492:
      iVar2 = func_0x40085ec8(param_1,param_2);
      if ((iVar2 != 0) || (iVar2 = (*pcVar5)(param_1,param_2[8],param_3,iVar4), iVar2 == -1))
      goto LAB_400ea4a0;
      if ((int *)param_2[0xd] != (int *)0x0) {
        if ((int *)param_2[0xd] != param_2 + 0x11) {
          func_0x4008dc14(param_1);
        }
        param_2[0xd] = 0;
      }
      uVar3 = DAT_400d14a8;
      *param_2 = param_2[4];
      param_2[1] = 0;
      *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) & (ushort)uVar3;
      func_0x40086818(param_2 + 0x17,0,8);
      uVar3 = 0;
    }
    if (((param_2[0x19] & 1U) == 0) && ((*(ushort *)(param_2 + 3) & 0x200) == 0)) {
      func_0x400853d8(param_2[0x16]);
    }
    FUN_400f8218(uStack_34,&uStack_34);
  }
  return uVar3;
}



// Function at 0x400ea548

int FUN_400ea548(undefined4 *param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_30 [12];
  
  if ((param_1 != (undefined4 *)0x0) && (param_1[6] == 0)) {
    func_0x4008606c(param_1);
  }
  if (param_2 == DAT_400d1494) {
    param_2 = (int *)param_1[1];
  }
  else if (param_2 == DAT_400d1498) {
    param_2 = (int *)param_1[2];
  }
  else if (param_2 == DAT_400d149c) {
    param_2 = (int *)param_1[3];
  }
  FUN_400f8218(1,local_30);
  if (((param_2[0x19] & 1U) == 0) && ((*(ushort *)(param_2 + 3) & 0x200) == 0)) {
    func_0x400853c0(param_2[0x16]);
  }
  if ((code *)param_2[0xb] == (code *)0x0) {
    *param_1 = 0x1d;
LAB_400ea5e2:
    if (((param_2[0x19] & 1U) == 0) && ((*(ushort *)(param_2 + 3) & 0x200) == 0)) {
      func_0x400853d8(param_2[0x16]);
    }
    FUN_400f8218(local_30[0],local_30);
    iVar2 = -1;
  }
  else {
    uVar1 = *(ushort *)(param_2 + 3);
    if (((((uVar1 & 0xc) == 8) && (*param_2 != 0)) && (0 < *param_2 - param_2[4])) &&
       ((uVar1 & 0x100) != 0)) {
      uVar3 = 2;
LAB_400ea5d4:
      iVar2 = (*(code *)param_2[0xb])(param_1,param_2[8],0,uVar3);
      if (iVar2 == -1) goto LAB_400ea5e2;
    }
    else {
      if ((uVar1 & DAT_400d01d0) == 0) {
        uVar3 = 1;
        goto LAB_400ea5d4;
      }
      iVar2 = param_2[0x15];
    }
    uVar1 = *(ushort *)(param_2 + 3);
    if ((uVar1 & 4) == 0) {
      if (((uVar1 & 8) != 0) && (*param_2 != 0)) {
        iVar2 = iVar2 + (*param_2 - param_2[4]);
      }
    }
    else {
      iVar2 = iVar2 - param_2[1];
      if (param_2[0xd] != 0) {
        iVar2 = iVar2 - param_2[0x10];
      }
    }
    if (((param_2[0x19] & 1U) == 0) && ((uVar1 & 0x200) == 0)) {
      func_0x400853d8(param_2[0x16]);
    }
    FUN_400f8218(local_30[0],local_30);
  }
  return iVar2;
}



// Function at 0x400ea64c

undefined4 FUN_400ea64c(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = func_0x4008a814();
  uVar1 = FUN_400ea548(uVar1,param_1);
  return uVar1;
}



// Function at 0x400ea694

undefined4 FUN_400ea694(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = func_0x4008a814();
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x18) == 0)) {
    func_0x4008606c();
  }
  uVar2 = FUN_400ee194(iVar1,*(undefined4 *)(iVar1 + 8),param_1);
  return uVar2;
}



// Function at 0x400ea6d0

undefined4 FUN_400ea6d0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_40;
  int iStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  undefined4 auStack_24 [9];
  
  iStack_3c = func_0x40086c6c(param_2);
  uStack_38 = DAT_400d14ac;
  iStack_28 = iStack_3c + 1;
  uStack_34 = 1;
  uStack_2c = 2;
  local_40 = param_2;
  puStack_30 = (undefined1 *)&local_40;
  if ((param_1 != 0) && (puStack_30 = (undefined1 *)&local_40, *(int *)(param_1 + 0x18) == 0)) {
    puStack_30 = (undefined1 *)&local_40;
    func_0x4008606c(param_1);
  }
  iVar3 = *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 0x18) == 0) {
    func_0x4008606c(param_1);
  }
  if (iVar3 == DAT_400d1494) {
    iVar3 = *(int *)(param_1 + 4);
  }
  else if (iVar3 == DAT_400d1498) {
    iVar3 = *(int *)(param_1 + 8);
  }
  else if (iVar3 == DAT_400d149c) {
    iVar3 = *(int *)(param_1 + 0xc);
  }
  FUN_400f8218(1,auStack_24);
  if (((*(uint *)(iVar3 + 100) & 1) == 0) && ((*(ushort *)(iVar3 + 0xc) & 0x200) == 0)) {
    func_0x400853c0(*(undefined4 *)(iVar3 + 0x58));
  }
  iVar1 = func_0x40086190(param_1,iVar3,&puStack_30);
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    uVar2 = 10;
  }
  if (((*(uint *)(iVar3 + 100) & 1) == 0) && ((*(ushort *)(iVar3 + 0xc) & 0x200) == 0)) {
    func_0x400853d8(*(undefined4 *)(iVar3 + 0x58));
  }
  FUN_400f8218(auStack_24[0],auStack_24);
  return uVar2;
}



// Function at 0x400ea774

undefined4 FUN_400ea774(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = func_0x4008a814();
  uVar1 = FUN_400ea6d0(uVar1,param_1);
  return uVar1;
}



// Function at 0x400ea8dc

int FUN_400ea8dc(undefined1 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 *local_c0 [2];
  int iStack_b8;
  undefined2 uStack_b4;
  undefined2 uStack_b2;
  undefined1 *puStack_b0;
  int iStack_ac;
  undefined1 *puStack_58;
  undefined1 *puStack_54;
  undefined4 uStack_50;
  undefined1 auStack_40 [12];
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 auStack_20 [32];
  
  uStack_34 = param_4;
  uStack_30 = param_5;
  uStack_2c = param_6;
  puVar1 = (undefined4 *)func_0x4008a814();
  if (param_2 < 0) {
    *puVar1 = 0x8b;
    iVar2 = -1;
  }
  else {
    uStack_b4 = 0x208;
    iStack_b8 = 0;
    if (param_2 != 0) {
      iStack_b8 = param_2 + -1;
    }
    uStack_b2 = 0xffff;
    puStack_54 = auStack_40;
    puStack_58 = auStack_20;
    uStack_50 = 0xc;
    local_c0[0] = param_1;
    puStack_b0 = param_1;
    iStack_ac = iStack_b8;
    iVar2 = FUN_400eae10(puVar1,local_c0,param_3);
    if (iVar2 < -1) {
      *puVar1 = 0x8b;
    }
    if (param_2 != 0) {
      *local_c0[0] = 0;
    }
  }
  return iVar2;
}



// Function at 0x400ea950

int FUN_400ea950(int param_1,byte *param_2,int *param_3,int *param_4,int param_5,int param_6,
                undefined4 *param_7)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uStack_3c;
  
  iVar2 = *param_4;
  if ((byte *)*param_7 != (byte *)0x0) {
    param_2 = (byte *)*param_7;
  }
  while ((iVar2 <= param_1 && (*param_2 != 0))) {
    for (; (bVar1 = *param_2, bVar1 != 0 && (bVar1 != 0x25)); param_2 = param_2 + 1) {
    }
    if (bVar1 == 0) break;
    param_2 = param_2 + 1;
    uStack_3c = 0;
    do {
      bVar1 = *param_2;
      param_2 = param_2 + 1;
      iVar3 = uStack_3c * 9;
      uStack_3c = (uint)*(byte *)(DAT_400d14b4 + iVar3 + (uint)*(byte *)(DAT_400d14b0 + (uint)bVar1)
                                 );
      uVar5 = *(byte *)(DAT_400d14b8 + iVar3 + (uint)*(byte *)(DAT_400d14b0 + (uint)bVar1)) - 1 &
              0xff;
      if (uVar5 < 8) {
                    /* WARNING: Could not recover jumptable at 0x400ea9d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar2 = (**(code **)(DAT_400d14bc + uVar5 * 4))();
        return iVar2;
      }
    } while (uStack_3c != 0xb);
  }
  while( true ) {
    if (param_1 < iVar2) {
      *param_4 = iVar2;
      *param_7 = param_2;
      return param_5 + param_1 * 8;
    }
    iVar3 = param_3[2];
    uVar5 = *(int *)(param_6 + iVar2 * 4) - 1;
    if (uVar5 < 6) break;
    iVar4 = iVar3 + 4;
    param_3[2] = iVar4;
    if (iVar4 < 0x19) {
      iVar3 = param_3[1];
    }
    else {
      if (iVar3 < 0x19) {
        param_3[2] = 0x24;
      }
      iVar3 = *param_3;
    }
    *(undefined4 *)(param_5 + iVar2 * 8) = *(undefined4 *)(iVar3 + param_3[2] + -4);
    iVar2 = iVar2 + 1;
  }
                    /* WARNING: Could not recover jumptable at 0x400ead24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (**(code **)(DAT_400d14c8 + uVar5 * 4))();
  return iVar2;
}



// Function at 0x400eae10

/* WARNING: Removing unreachable block (ram,0x400ed0c4) */
/* WARNING: Removing unreachable block (ram,0x400ed0d7) */
/* WARNING: Removing unreachable block (ram,0x400ed13a) */
/* WARNING: Removing unreachable block (ram,0x400ed151) */
/* WARNING: Removing unreachable block (ram,0x400ed164) */
/* WARNING: Removing unreachable block (ram,0x400ed177) */
/* WARNING: Removing unreachable block (ram,0x400ed17a) */
/* WARNING: Removing unreachable block (ram,0x400ed100) */
/* WARNING: Removing unreachable block (ram,0x400ed113) */
/* WARNING: Removing unreachable block (ram,0x400ed129) */
/* WARNING: Removing unreachable block (ram,0x400ed12c) */
/* WARNING: Removing unreachable block (ram,0x400ed134) */
/* WARNING: Removing unreachable block (ram,0x400ed191) */
/* WARNING: Removing unreachable block (ram,0x400ed1b8) */
/* WARNING: Removing unreachable block (ram,0x400ed1cd) */
/* WARNING: Removing unreachable block (ram,0x400ed1d0) */
/* WARNING: Removing unreachable block (ram,0x400ed1af) */
/* WARNING: Removing unreachable block (ram,0x400ed1df) */
/* WARNING: Removing unreachable block (ram,0x400ed210) */
/* WARNING: Removing unreachable block (ram,0x400ed225) */
/* WARNING: Removing unreachable block (ram,0x400ed228) */
/* WARNING: Removing unreachable block (ram,0x400ed206) */
/* WARNING: Removing unreachable block (ram,0x400ed23a) */
/* WARNING: Removing unreachable block (ram,0x400ed285) */
/* WARNING: Removing unreachable block (ram,0x400ed29c) */
/* WARNING: Removing unreachable block (ram,0x400ed2af) */
/* WARNING: Removing unreachable block (ram,0x400ed2c2) */
/* WARNING: Removing unreachable block (ram,0x400ed2c5) */
/* WARNING: Removing unreachable block (ram,0x400ed24b) */
/* WARNING: Removing unreachable block (ram,0x400ed25e) */
/* WARNING: Removing unreachable block (ram,0x400ed274) */
/* WARNING: Removing unreachable block (ram,0x400ed277) */
/* WARNING: Removing unreachable block (ram,0x400ed27f) */
/* WARNING: Removing unreachable block (ram,0x400ed248) */
/* WARNING: Removing unreachable block (ram,0x400ed318) */
/* WARNING: Removing unreachable block (ram,0x400ed32f) */
/* WARNING: Removing unreachable block (ram,0x400ed342) */
/* WARNING: Removing unreachable block (ram,0x400ed352) */
/* WARNING: Removing unreachable block (ram,0x400ed355) */
/* WARNING: Removing unreachable block (ram,0x400ed2e0) */
/* WARNING: Removing unreachable block (ram,0x400ed2f1) */
/* WARNING: Removing unreachable block (ram,0x400ed307) */
/* WARNING: Removing unreachable block (ram,0x400ed30a) */
/* WARNING: Removing unreachable block (ram,0x400ed312) */
/* WARNING: Removing unreachable block (ram,0x400ed3b1) */
/* WARNING: Removing unreachable block (ram,0x400ed3bd) */
/* WARNING: Removing unreachable block (ram,0x400ed4cd) */
/* WARNING: Removing unreachable block (ram,0x400ed4d6) */
/* WARNING: Removing unreachable block (ram,0x400ed4f8) */
/* WARNING: Removing unreachable block (ram,0x400ed50d) */
/* WARNING: Removing unreachable block (ram,0x400ed4ef) */
/* WARNING: Removing unreachable block (ram,0x400ed516) */
/* WARNING: Removing unreachable block (ram,0x400ed534) */
/* WARNING: Removing unreachable block (ram,0x400ed558) */
/* WARNING: Removing unreachable block (ram,0x400ed56d) */
/* WARNING: Removing unreachable block (ram,0x400ed551) */
/* WARNING: Removing unreachable block (ram,0x400ed573) */
/* WARNING: Removing unreachable block (ram,0x400ed579) */
/* WARNING: Removing unreachable block (ram,0x400ed5ae) */
/* WARNING: Removing unreachable block (ram,0x400ed5c4) */
/* WARNING: Removing unreachable block (ram,0x400ed5cf) */
/* WARNING: Removing unreachable block (ram,0x400ed5e0) */
/* WARNING: Removing unreachable block (ram,0x400ed584) */
/* WARNING: Removing unreachable block (ram,0x400ed590) */
/* WARNING: Removing unreachable block (ram,0x400ed5a1) */
/* WARNING: Removing unreachable block (ram,0x400ed5a9) */
/* WARNING: Removing unreachable block (ram,0x400ed5e8) */
/* WARNING: Removing unreachable block (ram,0x400ed4d3) */
/* WARNING: Removing unreachable block (ram,0x400ed607) */
/* WARNING: Removing unreachable block (ram,0x400ed629) */
/* WARNING: Removing unreachable block (ram,0x400ed63d) */
/* WARNING: Removing unreachable block (ram,0x400ed61e) */
/* WARNING: Removing unreachable block (ram,0x400ed645) */
/* WARNING: Removing unreachable block (ram,0x400ed68e) */
/* WARNING: Removing unreachable block (ram,0x400ed6a5) */
/* WARNING: Removing unreachable block (ram,0x400ed6b8) */
/* WARNING: Removing unreachable block (ram,0x400ed6c9) */
/* WARNING: Removing unreachable block (ram,0x400ed658) */
/* WARNING: Removing unreachable block (ram,0x400ed669) */
/* WARNING: Removing unreachable block (ram,0x400ed680) */
/* WARNING: Removing unreachable block (ram,0x400ed688) */
/* WARNING: Removing unreachable block (ram,0x400ed652) */
/* WARNING: Removing unreachable block (ram,0x400ed6d4) */
/* WARNING: Removing unreachable block (ram,0x400ed6e5) */
/* WARNING: Removing unreachable block (ram,0x400ed6e2) */
/* WARNING: Removing unreachable block (ram,0x400ed834) */
/* WARNING: Removing unreachable block (ram,0x400ed83d) */
/* WARNING: Removing unreachable block (ram,0x400ed6e8) */
/* WARNING: Removing unreachable block (ram,0x400ed6f0) */
/* WARNING: Removing unreachable block (ram,0x400ed6ea) */
/* WARNING: Removing unreachable block (ram,0x400ed6fa) */
/* WARNING: Removing unreachable block (ram,0x400ed72c) */
/* WARNING: Removing unreachable block (ram,0x400ed73e) */
/* WARNING: Removing unreachable block (ram,0x400ed720) */
/* WARNING: Removing unreachable block (ram,0x400ed747) */
/* WARNING: Removing unreachable block (ram,0x400ed75f) */
/* WARNING: Removing unreachable block (ram,0x400ed781) */
/* WARNING: Removing unreachable block (ram,0x400ed795) */
/* WARNING: Removing unreachable block (ram,0x400ed779) */
/* WARNING: Removing unreachable block (ram,0x400ed79d) */
/* WARNING: Removing unreachable block (ram,0x400ed7e9) */
/* WARNING: Removing unreachable block (ram,0x400ed800) */
/* WARNING: Removing unreachable block (ram,0x400ed813) */
/* WARNING: Removing unreachable block (ram,0x400ed824) */
/* WARNING: Removing unreachable block (ram,0x400ed7b4) */
/* WARNING: Removing unreachable block (ram,0x400ed7c7) */
/* WARNING: Removing unreachable block (ram,0x400ed7de) */
/* WARNING: Removing unreachable block (ram,0x400ed7e3) */
/* WARNING: Removing unreachable block (ram,0x400ed7b0) */
/* WARNING: Removing unreachable block (ram,0x400ed82c) */
/* WARNING: Removing unreachable block (ram,0x400ed846) */
/* WARNING: Removing unreachable block (ram,0x400ed851) */
/* WARNING: Removing unreachable block (ram,0x400ed85a) */
/* WARNING: Removing unreachable block (ram,0x400ed860) */
/* WARNING: Removing unreachable block (ram,0x400ed891) */
/* WARNING: Removing unreachable block (ram,0x400ed8a6) */
/* WARNING: Removing unreachable block (ram,0x400ed886) */
/* WARNING: Removing unreachable block (ram,0x400ed8af) */
/* WARNING: Removing unreachable block (ram,0x400ed8c7) */
/* WARNING: Removing unreachable block (ram,0x400ed8ed) */
/* WARNING: Removing unreachable block (ram,0x400ed901) */
/* WARNING: Removing unreachable block (ram,0x400ed8e4) */
/* WARNING: Removing unreachable block (ram,0x400ed909) */
/* WARNING: Removing unreachable block (ram,0x400ed951) */
/* WARNING: Removing unreachable block (ram,0x400ed925) */
/* WARNING: Removing unreachable block (ram,0x400ed931) */
/* WARNING: Removing unreachable block (ram,0x400ed942) */
/* WARNING: Removing unreachable block (ram,0x400ed94b) */
/* WARNING: Removing unreachable block (ram,0x400ed91f) */
/* WARNING: Removing unreachable block (ram,0x400ed3d2) */
/* WARNING: Removing unreachable block (ram,0x400ed3f5) */
/* WARNING: Removing unreachable block (ram,0x400ed40a) */
/* WARNING: Removing unreachable block (ram,0x400ed40d) */
/* WARNING: Removing unreachable block (ram,0x400ed3eb) */
/* WARNING: Removing unreachable block (ram,0x400ed416) */
/* WARNING: Removing unreachable block (ram,0x400ed41f) */
/* WARNING: Removing unreachable block (ram,0x400ed428) */
/* WARNING: Removing unreachable block (ram,0x400ed450) */
/* WARNING: Removing unreachable block (ram,0x400ed465) */
/* WARNING: Removing unreachable block (ram,0x400ed468) */
/* WARNING: Removing unreachable block (ram,0x400ed448) */
/* WARNING: Removing unreachable block (ram,0x400ed471) */
/* WARNING: Removing unreachable block (ram,0x400ed4ae) */
/* WARNING: Removing unreachable block (ram,0x400ed4ca) */
/* WARNING: Removing unreachable block (ram,0x400ed96d) */
/* WARNING: Removing unreachable block (ram,0x400ed97e) */
/* WARNING: Removing unreachable block (ram,0x400ed98f) */
/* WARNING: Removing unreachable block (ram,0x400ed97b) */
/* WARNING: Removing unreachable block (ram,0x400ed480) */
/* WARNING: Removing unreachable block (ram,0x400ed48f) */
/* WARNING: Removing unreachable block (ram,0x400ed4a0) */
/* WARNING: Removing unreachable block (ram,0x400ed4a8) */
/* WARNING: Removing unreachable block (ram,0x400ed47b) */
/* WARNING: Removing unreachable block (ram,0x400ed425) */
/* WARNING: Removing unreachable block (ram,0x400ed3ba) */
/* WARNING: Removing unreachable block (ram,0x400ed9b9) */
/* WARNING: Removing unreachable block (ram,0x400ed9d1) */
/* WARNING: Removing unreachable block (ram,0x400ed9e2) */
/* WARNING: Removing unreachable block (ram,0x400ed9e7) */
/* WARNING: Removing unreachable block (ram,0x400eda0c) */
/* WARNING: Removing unreachable block (ram,0x400eda20) */
/* WARNING: Removing unreachable block (ram,0x400eda25) */
/* WARNING: Removing unreachable block (ram,0x400eda88) */
/* WARNING: Removing unreachable block (ram,0x400edabd) */
/* WARNING: Removing unreachable block (ram,0x400edad3) */
/* WARNING: Removing unreachable block (ram,0x400edae0) */
/* WARNING: Removing unreachable block (ram,0x400eda90) */
/* WARNING: Removing unreachable block (ram,0x400eda9f) */
/* WARNING: Removing unreachable block (ram,0x400edab0) */
/* WARNING: Removing unreachable block (ram,0x400edab8) */
/* WARNING: Removing unreachable block (ram,0x400eda8d) */
/* WARNING: Removing unreachable block (ram,0x400eda40) */
/* WARNING: Removing unreachable block (ram,0x400eda6b) */
/* WARNING: Removing unreachable block (ram,0x400eda68) */
/* WARNING: Removing unreachable block (ram,0x400ed9b0) */
/* WARNING: Removing unreachable block (ram,0x400ed9b6) */
/* WARNING: Removing unreachable block (ram,0x400edafd) */
/* WARNING: Removing unreachable block (ram,0x400eda73) */
/* WARNING: Removing unreachable block (ram,0x400eda7f) */
/* WARNING: Removing unreachable block (ram,0x400edb08) */
/* WARNING: Removing unreachable block (ram,0x400edb1d) */
/* WARNING: Removing unreachable block (ram,0x400edb35) */
/* WARNING: Removing unreachable block (ram,0x400edb49) */
/* WARNING: Removing unreachable block (ram,0x400edb2d) */

undefined8
FUN_400eae10(undefined4 *param_1,int *param_2,char *param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  byte bVar1;
  char **ppcVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  byte *pbVar7;
  undefined1 *puVar8;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar9;
  undefined1 auStack_300 [256];
  undefined4 uStack_200;
  byte abStack_180 [100];
  char *local_11c;
  int iStack_118;
  char *local_114 [14];
  char **ppcStack_dc;
  int iStack_d8;
  char *pcStack_d4;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined1 uStack_ae;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  char **ppcStack_90;
  uint uStack_8c;
  byte *pbStack_88;
  undefined4 uStack_84;
  undefined4 *puStack_80;
  int iStack_7c;
  int *piStack_78;
  undefined4 uStack_74;
  uint uStack_70;
  char *pcStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  int iStack_60;
  undefined4 uStack_5c;
  int iStack_58;
  undefined4 uStack_54;
  int iStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  uStack_a0 = param_4;
  uStack_9c = param_5;
  uStack_98 = param_6;
  pbStack_88 = (byte *)param_3;
  puStack_80 = param_1;
  piStack_78 = param_2;
  puVar3 = (undefined4 *)FUN_400f20f0(param_1);
  uStack_44 = *puVar3;
  uStack_54 = func_0x40086c6c();
  puVar8 = auStack_300;
  if (((*(ushort *)(piStack_78 + 3) & 0x80) != 0) && (piStack_78[4] == 0)) {
    iVar4 = func_0x4008dc08(puStack_80,0x40);
    *piStack_78 = iVar4;
    piStack_78[4] = iVar4;
    if (iVar4 == 0) {
      *puStack_80 = 0xc;
      iStack_58 = -1;
      goto LAB_400edcba;
    }
    piStack_78[5] = 0x40;
  }
  ppcStack_dc = &local_11c;
  pcStack_d4 = (char *)0x0;
  iStack_d8 = 0;
  uStack_b8 = 0;
  uStack_200 = 0xffffffff;
  uStack_b4 = 0;
  uStack_74 = 0;
  uStack_68 = DAT_400d0028;
  uStack_64 = DAT_400d0028;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_5c = 0;
  uStack_4c = 0;
  uStack_3c = 0;
  iStack_58 = 0;
  uStack_94 = 0;
  do {
    ppcStack_90 = &local_11c;
    for (pbVar7 = pbStack_88; (*pbVar7 != '\0' && (*pbVar7 != '%'));
        pbVar7 = (byte *)((char *)pbVar7 + 1)) {
    }
    iVar4 = (int)pbVar7 - (int)pbStack_88;
    if (iVar4 != 0) {
      local_11c = (char *)pbStack_88;
      pcStack_d4 = pcStack_d4 + iVar4;
      iStack_d8 = iStack_d8 + 1;
      iStack_118 = iVar4;
      if (iStack_d8 < 8) {
        ppcStack_90 = local_114;
      }
      else {
        iVar5 = FUN_400f2f60(puStack_80,piStack_78,&ppcStack_dc);
        if (iVar5 != 0) goto LAB_400edc6d;
        ppcStack_90 = &local_11c;
      }
      iStack_58 = iStack_58 + iVar4;
    }
    ppcVar2 = ppcStack_90;
    if (*pbVar7 == '\0') {
LAB_400edc44:
      if (pcStack_d4 != (char *)0x0) {
        FUN_400f2f60(puStack_80,piStack_78,&ppcStack_dc);
      }
      goto LAB_400edc6d;
    }
    uStack_ae = 0;
    uStack_84 = 0xffffffff;
    iStack_60 = 0;
    uStack_8c = 0;
    pcStack_6c = (char *)pbVar7 + 2;
    bVar1 = ((char *)pbVar7)[1];
    uStack_70 = (uint)bVar1;
    if (uStack_70 - 0x20 < 0x5b) {
      UNRECOVERED_JUMPTABLE = *(code **)(DAT_400d14e4 + (uStack_70 - 0x20) * 4);
                    /* WARNING: Could not recover jumptable at 0x400eaf92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar9 = (*UNRECOVERED_JUMPTABLE)(uStack_94,pbVar7,0,auStack_300,UNRECOVERED_JUMPTABLE);
      return uVar9;
    }
    if (uStack_70 == 0) goto LAB_400edc44;
    pbStack_88 = abStack_180;
    uStack_40 = 0;
    uStack_48 = 0;
    iStack_50 = 1;
    iStack_60 = 0;
    iStack_7c = 0;
    uStack_84 = 1;
    uStack_8c = 0;
    uStack_ae = 0;
    iVar4 = iStack_d8 + 1;
    *ppcStack_90 = (char *)pbStack_88;
    ppcVar2[1] = (char *)0x1;
    abStack_180[0] = bVar1;
    iStack_d8 = iVar4;
    if (iVar4 < 8) {
      ppcStack_90 = ppcVar2 + 2;
      pcStack_d4 = pcStack_d4 + 1;
    }
    else {
      pcStack_d4 = pcStack_d4 + 1;
      iVar4 = FUN_400f2f60(puStack_80,piStack_78,&ppcStack_dc);
      if (iVar4 != 0) break;
      ppcStack_90 = &local_11c;
    }
    if (((uStack_8c & 4) != 0) && (pcVar6 = (char *)(iStack_60 - iStack_50), 0 < (int)pcVar6)) {
      for (; ppcVar2 = ppcStack_90, iVar4 = iStack_d8 + 1, iStack_d8 = iVar4, 0x10 < (int)pcVar6;
          pcVar6 = pcVar6 + -0x10) {
        *ppcStack_90 = DAT_400d14f4;
        ppcVar2[1] = (char *)0x10;
        if (iVar4 < 8) {
          ppcStack_90 = ppcVar2 + 2;
          pcStack_d4 = pcStack_d4 + 0x10;
        }
        else {
          pcStack_d4 = pcStack_d4 + 0x10;
          iVar4 = FUN_400f2f60(puStack_80,piStack_78,&ppcStack_dc);
          if (iVar4 != 0) goto LAB_400edc60;
          ppcStack_90 = &local_11c;
        }
      }
      ppcStack_90[1] = pcVar6;
      pcVar6 = pcVar6 + (int)pcStack_d4;
      *ppcVar2 = DAT_400d14f4;
      pcStack_d4 = pcVar6;
      if ((7 < iVar4) && (iVar4 = FUN_400f2f60(puStack_80,piStack_78,&ppcStack_dc), iVar4 != 0))
      break;
    }
    iStack_58 = iStack_58 +
                (uint)(iStack_60 < iStack_50) * iStack_50 +
                (uint)(iStack_60 >= iStack_50) * iStack_60;
    if ((pcStack_d4 != (char *)0x0) &&
       (iVar4 = FUN_400f2f60(puStack_80,piStack_78,&ppcStack_dc), iVar4 != 0)) break;
    iStack_d8 = 0;
    if (iStack_7c != 0) {
      func_0x4008dc14(puStack_80,iStack_7c);
    }
    pbStack_88 = (byte *)pcStack_6c;
  } while( true );
LAB_400edc60:
  if (iStack_7c != 0) {
    func_0x4008dc14(puStack_80,iStack_7c);
  }
LAB_400edc6d:
  puVar8 = (undefined1 *)0xffffffff;
  if ((*(ushort *)(piStack_78 + 3) >> 6 & 1) != 0) {
    iStack_58 = -1;
  }
LAB_400edcba:
  return CONCAT44(puVar8,iStack_58);
}



// Function at 0x400edcc0

undefined4 FUN_400edcc0(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = func_0x4008a814();
  uVar1 = func_0x40085484(uVar1,param_1,param_2);
  return uVar1;
}



// Function at 0x400edcd4

int FUN_400edcd4(int param_1,byte *param_2,int *param_3,int *param_4,int param_5,int param_6,
                undefined4 *param_7)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uStack_3c;
  
  iVar2 = *param_4;
  if ((byte *)*param_7 != (byte *)0x0) {
    param_2 = (byte *)*param_7;
  }
  while ((iVar2 <= param_1 && (*param_2 != 0))) {
    for (; (bVar1 = *param_2, bVar1 != 0 && (bVar1 != 0x25)); param_2 = param_2 + 1) {
    }
    if (bVar1 == 0) break;
    param_2 = param_2 + 1;
    uStack_3c = 0;
    do {
      bVar1 = *param_2;
      param_2 = param_2 + 1;
      iVar3 = uStack_3c * 9;
      uStack_3c = (uint)*(byte *)(DAT_400d14b4 + iVar3 + (uint)*(byte *)(DAT_400d14b0 + (uint)bVar1)
                                 );
      uVar5 = *(byte *)(DAT_400d14b8 + iVar3 + (uint)*(byte *)(DAT_400d14b0 + (uint)bVar1)) - 1 &
              0xff;
      if (uVar5 < 8) {
                    /* WARNING: Could not recover jumptable at 0x400edd5d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar2 = (**(code **)(DAT_400d150c + uVar5 * 4))();
        return iVar2;
      }
    } while (uStack_3c != 0xb);
  }
  while( true ) {
    if (param_1 < iVar2) {
      *param_4 = iVar2;
      *param_7 = param_2;
      return param_5 + param_1 * 8;
    }
    iVar3 = param_3[2];
    uVar5 = *(int *)(param_6 + iVar2 * 4) - 1;
    if (uVar5 < 6) break;
    iVar4 = iVar3 + 4;
    param_3[2] = iVar4;
    if (iVar4 < 0x19) {
      iVar3 = param_3[1];
    }
    else {
      if (iVar3 < 0x19) {
        param_3[2] = 0x24;
      }
      iVar3 = *param_3;
    }
    *(undefined4 *)(param_5 + iVar2 * 8) = *(undefined4 *)(iVar3 + param_3[2] + -4);
    iVar2 = iVar2 + 1;
  }
                    /* WARNING: Could not recover jumptable at 0x400ee0a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (**(code **)(DAT_400d1518 + uVar5 * 4))();
  return iVar2;
}



// Function at 0x400ee194

/* WARNING: Removing unreachable block (ram,0x400f0518) */
/* WARNING: Removing unreachable block (ram,0x400f052b) */
/* WARNING: Removing unreachable block (ram,0x400f058e) */
/* WARNING: Removing unreachable block (ram,0x400f05a5) */
/* WARNING: Removing unreachable block (ram,0x400f05b8) */
/* WARNING: Removing unreachable block (ram,0x400f05cb) */
/* WARNING: Removing unreachable block (ram,0x400f05ce) */
/* WARNING: Removing unreachable block (ram,0x400f0554) */
/* WARNING: Removing unreachable block (ram,0x400f0567) */
/* WARNING: Removing unreachable block (ram,0x400f057d) */
/* WARNING: Removing unreachable block (ram,0x400f0580) */
/* WARNING: Removing unreachable block (ram,0x400f0588) */
/* WARNING: Removing unreachable block (ram,0x400f05e5) */
/* WARNING: Removing unreachable block (ram,0x400f060c) */
/* WARNING: Removing unreachable block (ram,0x400f0621) */
/* WARNING: Removing unreachable block (ram,0x400f0624) */
/* WARNING: Removing unreachable block (ram,0x400f0603) */
/* WARNING: Removing unreachable block (ram,0x400f0633) */
/* WARNING: Removing unreachable block (ram,0x400f0664) */
/* WARNING: Removing unreachable block (ram,0x400f0679) */
/* WARNING: Removing unreachable block (ram,0x400f067c) */
/* WARNING: Removing unreachable block (ram,0x400f065a) */
/* WARNING: Removing unreachable block (ram,0x400f068e) */
/* WARNING: Removing unreachable block (ram,0x400f06da) */
/* WARNING: Removing unreachable block (ram,0x400f06f1) */
/* WARNING: Removing unreachable block (ram,0x400f0704) */
/* WARNING: Removing unreachable block (ram,0x400f0717) */
/* WARNING: Removing unreachable block (ram,0x400f071a) */
/* WARNING: Removing unreachable block (ram,0x400f06a0) */
/* WARNING: Removing unreachable block (ram,0x400f06b3) */
/* WARNING: Removing unreachable block (ram,0x400f06c9) */
/* WARNING: Removing unreachable block (ram,0x400f06cc) */
/* WARNING: Removing unreachable block (ram,0x400f06d4) */
/* WARNING: Removing unreachable block (ram,0x400f069c) */
/* WARNING: Removing unreachable block (ram,0x400f076c) */
/* WARNING: Removing unreachable block (ram,0x400f0783) */
/* WARNING: Removing unreachable block (ram,0x400f0796) */
/* WARNING: Removing unreachable block (ram,0x400f07a6) */
/* WARNING: Removing unreachable block (ram,0x400f07a9) */
/* WARNING: Removing unreachable block (ram,0x400f0734) */
/* WARNING: Removing unreachable block (ram,0x400f0745) */
/* WARNING: Removing unreachable block (ram,0x400f075b) */
/* WARNING: Removing unreachable block (ram,0x400f075e) */
/* WARNING: Removing unreachable block (ram,0x400f0766) */
/* WARNING: Removing unreachable block (ram,0x400f0805) */
/* WARNING: Removing unreachable block (ram,0x400f0811) */
/* WARNING: Removing unreachable block (ram,0x400f0924) */
/* WARNING: Removing unreachable block (ram,0x400f092d) */
/* WARNING: Removing unreachable block (ram,0x400f094e) */
/* WARNING: Removing unreachable block (ram,0x400f0963) */
/* WARNING: Removing unreachable block (ram,0x400f0946) */
/* WARNING: Removing unreachable block (ram,0x400f096c) */
/* WARNING: Removing unreachable block (ram,0x400f098a) */
/* WARNING: Removing unreachable block (ram,0x400f09ac) */
/* WARNING: Removing unreachable block (ram,0x400f09c1) */
/* WARNING: Removing unreachable block (ram,0x400f09a7) */
/* WARNING: Removing unreachable block (ram,0x400f09c7) */
/* WARNING: Removing unreachable block (ram,0x400f09cd) */
/* WARNING: Removing unreachable block (ram,0x400f0a02) */
/* WARNING: Removing unreachable block (ram,0x400f0a18) */
/* WARNING: Removing unreachable block (ram,0x400f0a23) */
/* WARNING: Removing unreachable block (ram,0x400f0a34) */
/* WARNING: Removing unreachable block (ram,0x400f09d8) */
/* WARNING: Removing unreachable block (ram,0x400f09e4) */
/* WARNING: Removing unreachable block (ram,0x400f09f5) */
/* WARNING: Removing unreachable block (ram,0x400f09fd) */
/* WARNING: Removing unreachable block (ram,0x400f0a3c) */
/* WARNING: Removing unreachable block (ram,0x400f092a) */
/* WARNING: Removing unreachable block (ram,0x400f0a5e) */
/* WARNING: Removing unreachable block (ram,0x400f0a7d) */
/* WARNING: Removing unreachable block (ram,0x400f0a91) */
/* WARNING: Removing unreachable block (ram,0x400f0a75) */
/* WARNING: Removing unreachable block (ram,0x400f0a99) */
/* WARNING: Removing unreachable block (ram,0x400f0ae2) */
/* WARNING: Removing unreachable block (ram,0x400f0af9) */
/* WARNING: Removing unreachable block (ram,0x400f0b0c) */
/* WARNING: Removing unreachable block (ram,0x400f0b1d) */
/* WARNING: Removing unreachable block (ram,0x400f0aac) */
/* WARNING: Removing unreachable block (ram,0x400f0abd) */
/* WARNING: Removing unreachable block (ram,0x400f0ad4) */
/* WARNING: Removing unreachable block (ram,0x400f0adc) */
/* WARNING: Removing unreachable block (ram,0x400f0aa6) */
/* WARNING: Removing unreachable block (ram,0x400f0b28) */
/* WARNING: Removing unreachable block (ram,0x400f0b39) */
/* WARNING: Removing unreachable block (ram,0x400f0b36) */
/* WARNING: Removing unreachable block (ram,0x400f0c88) */
/* WARNING: Removing unreachable block (ram,0x400f0c91) */
/* WARNING: Removing unreachable block (ram,0x400f0b3c) */
/* WARNING: Removing unreachable block (ram,0x400f0b44) */
/* WARNING: Removing unreachable block (ram,0x400f0b3e) */
/* WARNING: Removing unreachable block (ram,0x400f0b4e) */
/* WARNING: Removing unreachable block (ram,0x400f0b80) */
/* WARNING: Removing unreachable block (ram,0x400f0b92) */
/* WARNING: Removing unreachable block (ram,0x400f0b74) */
/* WARNING: Removing unreachable block (ram,0x400f0b9b) */
/* WARNING: Removing unreachable block (ram,0x400f0bb3) */
/* WARNING: Removing unreachable block (ram,0x400f0bd5) */
/* WARNING: Removing unreachable block (ram,0x400f0be9) */
/* WARNING: Removing unreachable block (ram,0x400f0bcd) */
/* WARNING: Removing unreachable block (ram,0x400f0bf1) */
/* WARNING: Removing unreachable block (ram,0x400f0c3d) */
/* WARNING: Removing unreachable block (ram,0x400f0c54) */
/* WARNING: Removing unreachable block (ram,0x400f0c67) */
/* WARNING: Removing unreachable block (ram,0x400f0c78) */
/* WARNING: Removing unreachable block (ram,0x400f0c08) */
/* WARNING: Removing unreachable block (ram,0x400f0c1b) */
/* WARNING: Removing unreachable block (ram,0x400f0c32) */
/* WARNING: Removing unreachable block (ram,0x400f0c37) */
/* WARNING: Removing unreachable block (ram,0x400f0c04) */
/* WARNING: Removing unreachable block (ram,0x400f0c80) */
/* WARNING: Removing unreachable block (ram,0x400f0c9a) */
/* WARNING: Removing unreachable block (ram,0x400f0ca5) */
/* WARNING: Removing unreachable block (ram,0x400f0cae) */
/* WARNING: Removing unreachable block (ram,0x400f0cb4) */
/* WARNING: Removing unreachable block (ram,0x400f0ce5) */
/* WARNING: Removing unreachable block (ram,0x400f0cfa) */
/* WARNING: Removing unreachable block (ram,0x400f0cdd) */
/* WARNING: Removing unreachable block (ram,0x400f0d03) */
/* WARNING: Removing unreachable block (ram,0x400f0d1b) */
/* WARNING: Removing unreachable block (ram,0x400f0d45) */
/* WARNING: Removing unreachable block (ram,0x400f0d59) */
/* WARNING: Removing unreachable block (ram,0x400f0d3b) */
/* WARNING: Removing unreachable block (ram,0x400f0d61) */
/* WARNING: Removing unreachable block (ram,0x400f0da9) */
/* WARNING: Removing unreachable block (ram,0x400f0d7d) */
/* WARNING: Removing unreachable block (ram,0x400f0d89) */
/* WARNING: Removing unreachable block (ram,0x400f0d9a) */
/* WARNING: Removing unreachable block (ram,0x400f0da3) */
/* WARNING: Removing unreachable block (ram,0x400f0d77) */
/* WARNING: Removing unreachable block (ram,0x400f0826) */
/* WARNING: Removing unreachable block (ram,0x400f0849) */
/* WARNING: Removing unreachable block (ram,0x400f085e) */
/* WARNING: Removing unreachable block (ram,0x400f0861) */
/* WARNING: Removing unreachable block (ram,0x400f083f) */
/* WARNING: Removing unreachable block (ram,0x400f086a) */
/* WARNING: Removing unreachable block (ram,0x400f0873) */
/* WARNING: Removing unreachable block (ram,0x400f087c) */
/* WARNING: Removing unreachable block (ram,0x400f08a4) */
/* WARNING: Removing unreachable block (ram,0x400f08b9) */
/* WARNING: Removing unreachable block (ram,0x400f08bc) */
/* WARNING: Removing unreachable block (ram,0x400f089c) */
/* WARNING: Removing unreachable block (ram,0x400f08c5) */
/* WARNING: Removing unreachable block (ram,0x400f0904) */
/* WARNING: Removing unreachable block (ram,0x400f0920) */
/* WARNING: Removing unreachable block (ram,0x400f0dc5) */
/* WARNING: Removing unreachable block (ram,0x400f0dd6) */
/* WARNING: Removing unreachable block (ram,0x400f0de7) */
/* WARNING: Removing unreachable block (ram,0x400f0dd3) */
/* WARNING: Removing unreachable block (ram,0x400f08d4) */
/* WARNING: Removing unreachable block (ram,0x400f08e3) */
/* WARNING: Removing unreachable block (ram,0x400f08f3) */
/* WARNING: Removing unreachable block (ram,0x400f08f6) */
/* WARNING: Removing unreachable block (ram,0x400f08fe) */
/* WARNING: Removing unreachable block (ram,0x400f08cf) */
/* WARNING: Removing unreachable block (ram,0x400f0879) */
/* WARNING: Removing unreachable block (ram,0x400f080e) */
/* WARNING: Removing unreachable block (ram,0x400f0e11) */
/* WARNING: Removing unreachable block (ram,0x400f0e2a) */
/* WARNING: Removing unreachable block (ram,0x400f0e3b) */
/* WARNING: Removing unreachable block (ram,0x400f0e40) */
/* WARNING: Removing unreachable block (ram,0x400f0e68) */
/* WARNING: Removing unreachable block (ram,0x400f0e7c) */
/* WARNING: Removing unreachable block (ram,0x400f0e81) */
/* WARNING: Removing unreachable block (ram,0x400f0ee4) */
/* WARNING: Removing unreachable block (ram,0x400f0f19) */
/* WARNING: Removing unreachable block (ram,0x400f0f2f) */
/* WARNING: Removing unreachable block (ram,0x400f0f3c) */
/* WARNING: Removing unreachable block (ram,0x400f0eec) */
/* WARNING: Removing unreachable block (ram,0x400f0efb) */
/* WARNING: Removing unreachable block (ram,0x400f0f0c) */
/* WARNING: Removing unreachable block (ram,0x400f0f14) */
/* WARNING: Removing unreachable block (ram,0x400f0ee9) */
/* WARNING: Removing unreachable block (ram,0x400f0e9c) */
/* WARNING: Removing unreachable block (ram,0x400f0ec7) */
/* WARNING: Removing unreachable block (ram,0x400f0ec4) */
/* WARNING: Removing unreachable block (ram,0x400f0e08) */
/* WARNING: Removing unreachable block (ram,0x400f0e0e) */
/* WARNING: Removing unreachable block (ram,0x400f0f59) */
/* WARNING: Removing unreachable block (ram,0x400f0ecf) */
/* WARNING: Removing unreachable block (ram,0x400f0edb) */
/* WARNING: Removing unreachable block (ram,0x400f0f64) */
/* WARNING: Removing unreachable block (ram,0x400f0f7c) */
/* WARNING: Removing unreachable block (ram,0x400f0f95) */
/* WARNING: Removing unreachable block (ram,0x400f0fa9) */
/* WARNING: Removing unreachable block (ram,0x400f0f8c) */

int FUN_400ee194(int param_1,int param_2,byte *param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6)

{
  byte bVar1;
  byte **ppbVar2;
  undefined4 *puVar3;
  int iVar4;
  byte *pbVar5;
  undefined1 *extraout_a3;
  undefined1 *extraout_a3_00;
  code *UNRECOVERED_JUMPTABLE;
  undefined1 *puVar6;
  undefined8 uVar7;
  undefined1 auStack_300 [256];
  undefined4 uStack_200;
  byte abStack_180 [100];
  byte *local_11c;
  int iStack_118;
  byte *local_114 [14];
  byte **ppbStack_dc;
  int iStack_d8;
  byte *pbStack_d4;
  undefined4 auStack_bc [2];
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined1 uStack_aa;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  byte **ppbStack_90;
  uint uStack_8c;
  int iStack_88;
  byte *pbStack_84;
  int iStack_80;
  undefined4 uStack_7c;
  int iStack_78;
  undefined4 uStack_74;
  uint uStack_70;
  byte *pbStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  int iStack_60;
  undefined4 uStack_5c;
  int iStack_58;
  undefined4 uStack_54;
  int iStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  uStack_a0 = param_4;
  uStack_9c = param_5;
  uStack_98 = param_6;
  iStack_88 = param_2;
  pbStack_84 = param_3;
  iStack_80 = param_1;
  puVar3 = (undefined4 *)FUN_400f20f0(param_1);
  uStack_44 = *puVar3;
  uStack_54 = func_0x40086c6c();
  if ((iStack_80 != 0) && (*(int *)(iStack_80 + 0x18) == 0)) {
    func_0x4008606c(iStack_80);
  }
  if (iStack_88 == DAT_400d1494) {
    iStack_88 = *(int *)(iStack_80 + 4);
  }
  else if (iStack_88 == DAT_400d1498) {
    iStack_88 = *(int *)(iStack_80 + 8);
  }
  else if (iStack_88 == DAT_400d149c) {
    iStack_88 = *(int *)(iStack_80 + 0xc);
  }
  FUN_400f8218(1,auStack_bc);
  if (((*(uint *)(iStack_88 + 100) & 1) == 0) && ((*(ushort *)(iStack_88 + 0xc) & 0x200) == 0)) {
    func_0x400853c0(*(undefined4 *)(iStack_88 + 0x58));
  }
  if ((((*(ushort *)(iStack_88 + 0xc) & 8) == 0) || (*(int *)(iStack_88 + 0x10) == 0)) &&
     (iVar4 = func_0x40086edc(iStack_80,iStack_88), iVar4 != 0)) {
    if (((*(uint *)(iStack_88 + 100) & 1) == 0) && ((*(ushort *)(iStack_88 + 0xc) & 0x200) == 0)) {
      func_0x400853d8(*(undefined4 *)(iStack_88 + 0x58));
    }
    FUN_400f8218(auStack_bc[0],auStack_bc);
    iStack_58 = -1;
  }
  else {
    if (((*(ushort *)(iStack_88 + 0xc) & 0x1a) != 10) || (*(short *)(iStack_88 + 0xe) < 0)) {
      puVar6 = auStack_300;
      uStack_200 = 0xffffffff;
      ppbStack_dc = &local_11c;
      pbStack_d4 = (byte *)0x0;
      iStack_d8 = 0;
      uStack_b4 = 0;
      uStack_b0 = 0;
      uStack_74 = 0;
      uStack_68 = DAT_400d0028;
      uStack_64 = DAT_400d0028;
      uStack_3c = 0;
      uStack_34 = 0;
      uStack_5c = 0;
      uStack_4c = 0;
      uStack_38 = 0;
      iStack_58 = 0;
      uStack_94 = 0;
      do {
        ppbStack_90 = &local_11c;
        for (pbVar5 = pbStack_84; (*pbVar5 != 0 && (*pbVar5 != 0x25)); pbVar5 = pbVar5 + 1) {
        }
        iVar4 = (int)pbVar5 - (int)pbStack_84;
        if (iVar4 != 0) {
          pbStack_d4 = pbStack_d4 + iVar4;
          iStack_d8 = iStack_d8 + 1;
          local_11c = pbStack_84;
          iStack_118 = iVar4;
          if (iStack_d8 < 8) {
            ppbStack_90 = local_114;
          }
          else {
            uVar7 = FUN_400f54e4(iStack_80,iStack_88,&ppbStack_dc);
            puVar6 = (undefined1 *)((ulonglong)uVar7 >> 0x20);
            if ((int)uVar7 != 0) goto LAB_400f10cd;
            ppbStack_90 = &local_11c;
          }
          iStack_58 = iStack_58 + iVar4;
        }
        ppbVar2 = ppbStack_90;
        if (*pbVar5 == 0) {
LAB_400f109c:
          if (pbStack_d4 != (byte *)0x0) {
            uVar7 = FUN_400f54e4(iStack_80,iStack_88,&ppbStack_dc);
            puVar6 = (undefined1 *)((ulonglong)uVar7 >> 0x20);
            if ((int)uVar7 != 0) goto LAB_400f10cd;
          }
          iStack_d8 = 0;
          goto LAB_400f10cd;
        }
        uStack_aa = 0;
        uStack_7c = 0xffffffff;
        iStack_60 = 0;
        uStack_8c = 0;
        pbStack_6c = pbVar5 + 2;
        bVar1 = pbVar5[1];
        uStack_70 = (uint)bVar1;
        puVar6 = (undefined1 *)0x2a;
        if (uStack_70 - 0x20 < 0x5b) {
          UNRECOVERED_JUMPTABLE = *(code **)(DAT_400d1534 + (uStack_70 - 0x20) * 4);
                    /* WARNING: Could not recover jumptable at 0x400ee3de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          iVar4 = (*UNRECOVERED_JUMPTABLE)(uStack_94,pbVar5,0,auStack_300,UNRECOVERED_JUMPTABLE);
          return iVar4;
        }
        if (uStack_70 == 0) goto LAB_400f109c;
        pbStack_84 = abStack_180;
        uStack_40 = 0;
        uStack_48 = 0;
        iStack_50 = 1;
        iStack_60 = 0;
        iStack_78 = 0;
        uStack_7c = 1;
        uStack_8c = 0;
        uStack_aa = 0;
        puVar6 = (undefined1 *)0x2a;
        iVar4 = iStack_d8 + 1;
        *ppbStack_90 = pbStack_84;
        ppbVar2[1] = (byte *)0x1;
        abStack_180[0] = bVar1;
        iStack_d8 = iVar4;
        if (iVar4 < 8) {
          ppbStack_90 = ppbVar2 + 2;
          pbStack_d4 = pbStack_d4 + 1;
        }
        else {
          pbStack_d4 = pbStack_d4 + 1;
          uVar7 = FUN_400f54e4(iStack_80,iStack_88,&ppbStack_dc);
          puVar6 = (undefined1 *)((ulonglong)uVar7 >> 0x20);
          if ((int)uVar7 != 0) {
LAB_400f10c0:
            if (iStack_78 != 0) {
              func_0x4008dc14(iStack_80,iStack_78);
              puVar6 = extraout_a3_00;
            }
LAB_400f10cd:
            if (((*(uint *)(iStack_88 + 100) & 1) == 0) &&
               ((*(ushort *)(iStack_88 + 0xc) & 0x200) == 0)) {
              func_0x400853d8(*(undefined4 *)(iStack_88 + 0x58),puVar6);
            }
            FUN_400f8218(auStack_bc[0],auStack_bc);
            if ((*(ushort *)(iStack_88 + 0xc) >> 6 & 1) == 0) {
              return iStack_58;
            }
            return -1;
          }
          ppbStack_90 = &local_11c;
        }
        if (((uStack_8c & 4) != 0) && (pbVar5 = (byte *)(iStack_60 - iStack_50), 0 < (int)pbVar5)) {
          for (; ppbVar2 = ppbStack_90, iVar4 = iStack_d8 + 1, iStack_d8 = iVar4, 0x10 < (int)pbVar5
              ; pbVar5 = pbVar5 + -0x10) {
            *ppbStack_90 = DAT_400d1538;
            ppbVar2[1] = (byte *)0x10;
            if (iVar4 < 8) {
              ppbStack_90 = ppbVar2 + 2;
              pbStack_d4 = pbStack_d4 + 0x10;
            }
            else {
              pbStack_d4 = pbStack_d4 + 0x10;
              uVar7 = FUN_400f54e4(iStack_80,iStack_88,&ppbStack_dc);
              puVar6 = (undefined1 *)((ulonglong)uVar7 >> 0x20);
              if ((int)uVar7 != 0) goto LAB_400f10c0;
              ppbStack_90 = &local_11c;
            }
          }
          ppbStack_90[1] = pbVar5;
          pbVar5 = pbVar5 + (int)pbStack_d4;
          *ppbVar2 = DAT_400d1538;
          pbStack_d4 = pbVar5;
          if (7 < iVar4) {
            uVar7 = FUN_400f54e4(iStack_80,iStack_88,&ppbStack_dc);
            puVar6 = (undefined1 *)((ulonglong)uVar7 >> 0x20);
            if ((int)uVar7 != 0) goto LAB_400f10c0;
          }
        }
        iStack_58 = iStack_58 +
                    (uint)(iStack_60 < iStack_50) * iStack_50 +
                    (uint)(iStack_60 >= iStack_50) * iStack_60;
        if (pbStack_d4 != (byte *)0x0) {
          uVar7 = FUN_400f54e4(iStack_80,iStack_88,&ppbStack_dc);
          puVar6 = (undefined1 *)((ulonglong)uVar7 >> 0x20);
          if ((int)uVar7 != 0) goto LAB_400f10c0;
        }
        iStack_d8 = 0;
        if (iStack_78 != 0) {
          func_0x4008dc14(iStack_80,iStack_78);
          puVar6 = extraout_a3;
        }
        pbStack_84 = pbStack_6c;
      } while( true );
    }
    if (((*(uint *)(iStack_88 + 100) & 1) == 0) && ((*(ushort *)(iStack_88 + 0xc) & 0x200) == 0)) {
      func_0x400853d8(*(undefined4 *)(iStack_88 + 0x58));
    }
    FUN_400f8218(auStack_bc[0],auStack_bc);
    iStack_58 = FUN_400f1168(iStack_80,iStack_88,pbStack_84,uStack_a0,uStack_9c,uStack_98);
  }
  return iStack_58;
}



// Function at 0x400f1148

undefined4
FUN_400f1148(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  
  uVar1 = func_0x4008a814();
  uVar1 = FUN_400ee194(uVar1,param_1,param_2,param_3,param_4,param_5);
  return uVar1;
}



// Function at 0x400f1168

int FUN_400f1168(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_120 [128];
  undefined1 *apuStack_a0 [2];
  undefined4 uStack_98;
  ushort uStack_94;
  undefined2 uStack_92;
  undefined1 *puStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_80;
  undefined4 uStack_78;
  undefined4 auStack_48 [3];
  undefined4 uStack_3c;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  apuStack_a0[0] = auStack_120;
  puStack_90 = auStack_120;
  uStack_94 = *(ushort *)(param_2 + 0xc) & 0xfffd;
  uStack_3c = *(undefined4 *)(param_2 + 100);
  uStack_92 = *(undefined2 *)(param_2 + 0xe);
  uStack_80 = *(undefined4 *)(param_2 + 0x20);
  uStack_88 = 0;
  uStack_78 = *(undefined4 *)(param_2 + 0x28);
  uStack_98 = 0x80;
  uStack_8c = 0x80;
  uStack_30 = param_4;
  uStack_2c = param_5;
  uStack_28 = param_6;
  func_0x40085394(auStack_48);
  iVar1 = FUN_400ee194(param_1,apuStack_a0,param_3,uStack_30,uStack_2c,uStack_28);
  if ((-1 < iVar1) && (iVar2 = func_0x40085ec8(param_1,apuStack_a0), iVar2 != 0)) {
    iVar1 = -1;
  }
  if ((uStack_94 & 0x40) != 0) {
    *(ushort *)(param_2 + 0xc) = *(ushort *)(param_2 + 0xc) | 0x40;
  }
  func_0x400853ac(auStack_48[0]);
  return iVar1;
}



// Function at 0x400f122c

undefined4
FUN_400f122c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  undefined4 uVar1;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x18) == 0)) {
    func_0x4008606c(param_1);
  }
  uVar1 = FUN_400ee194(param_1,*(undefined4 *)(param_1 + 8),param_2,param_3,param_4,param_5);
  return uVar1;
}



// Function at 0x400f125c

int FUN_400f125c(undefined4 *param_1,undefined1 *param_2,int param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                undefined4 param_9)

{
  int iVar1;
  undefined1 *local_90 [2];
  int iStack_88;
  undefined2 uStack_84;
  undefined2 uStack_82;
  undefined1 *puStack_80;
  int iStack_7c;
  
  if (param_3 < 0) {
    *param_1 = 0x8b;
    iVar1 = -1;
  }
  else {
    uStack_84 = 0x208;
    iStack_88 = 0;
    if (param_3 != 0) {
      iStack_88 = param_3 + -1;
    }
    uStack_82 = 0xffff;
    local_90[0] = param_2;
    puStack_80 = param_2;
    iStack_7c = iStack_88;
    iVar1 = FUN_400eae10(param_1,local_90,param_4,param_7,param_8,param_9);
    if (iVar1 < -1) {
      *param_1 = 0x8b;
    }
    if (param_3 != 0) {
      *local_90[0] = 0;
    }
  }
  return iVar1;
}



// Function at 0x400f12b4

undefined4 FUN_400f12b4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = func_0x4008a814();
  uVar1 = FUN_400f125c(uVar1,param_1,param_2,param_3);
  return uVar1;
}



// Function at 0x400f12dc

uint FUN_400f12dc(int param_1,int param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  int iVar12;
  
  uVar9 = 0;
  if (*(int *)(param_2 + 0x10) <= *(int *)(param_1 + 0x10)) {
    iVar3 = *(int *)(param_2 + 0x10) + -1;
    puVar10 = (uint *)(param_2 + 0x14);
    puVar1 = puVar10 + iVar3;
    puVar5 = (uint *)(param_1 + 0x14);
    puVar2 = puVar5 + iVar3;
    uVar4 = *puVar2 / (*puVar1 + 1);
    if (*puVar1 + 1 <= *puVar2) {
      iVar12 = 0;
      puVar11 = puVar5;
      do {
        uVar6 = *puVar10;
        puVar10 = puVar10 + 1;
        uVar9 = (uVar6 & 0xffff) * uVar4 + uVar9;
        uVar6 = (uVar6 >> 0x10) * uVar4 + (uVar9 >> 0x10);
        uVar8 = ((*puVar11 & 0xffff) + iVar12) - (uVar9 & 0xffff);
        uVar9 = uVar6 >> 0x10;
        iVar7 = ((*puVar11 >> 0x10) - (uVar6 & 0xffff)) + ((int)uVar8 >> 0x10);
        iVar12 = iVar7 >> 0x10;
        *puVar11 = iVar7 * 0x10000 | uVar8 & 0xffff;
        puVar11 = puVar11 + 1;
      } while (puVar10 <= puVar1);
      if (*puVar2 == 0) {
        while ((puVar2 = puVar2 + -1, puVar5 < puVar2 && (*puVar2 == 0))) {
          iVar3 = iVar3 + -1;
        }
        *(int *)(param_1 + 0x10) = iVar3;
      }
    }
    iVar12 = FUN_400f267c(param_1,param_2);
    uVar9 = uVar4;
    if (-1 < iVar12) {
      uVar9 = uVar4 + 1;
      puVar10 = (uint *)(param_1 + 0x14);
      puVar2 = (uint *)(param_2 + 0x14);
      iVar12 = 0;
      do {
        uVar4 = ((*puVar10 & 0xffff) + iVar12) - (*puVar2 & 0xffff);
        iVar7 = ((*puVar10 >> 0x10) - (*puVar2 >> 0x10)) + ((int)uVar4 >> 0x10);
        iVar12 = iVar7 >> 0x10;
        *puVar10 = iVar7 * 0x10000 | uVar4 & 0xffff;
        puVar2 = puVar2 + 1;
        puVar10 = puVar10 + 1;
      } while (puVar2 <= puVar1);
      puVar1 = puVar5 + iVar3;
      if (*puVar1 == 0) {
        while ((puVar1 = puVar1 + -1, puVar5 < puVar1 && (*puVar1 == 0))) {
          iVar3 = iVar3 + -1;
        }
        *(int *)(param_1 + 0x10) = iVar3;
      }
    }
  }
  return uVar9;
}



// Function at 0x400f2064

uint FUN_400f2064(undefined4 *param_1,char *param_2,uint *param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  cVar1 = *param_2;
  if (cVar1 == 'r') {
    uVar4 = 0;
    uVar3 = 0;
    uVar2 = 4;
  }
  else if (cVar1 == 'w') {
    uVar4 = 0x600;
    uVar3 = 1;
    uVar2 = 8;
  }
  else {
    if (cVar1 != 'a') {
      *param_1 = 0x16;
      return 0;
    }
    uVar4 = 0x208;
    uVar3 = 1;
    uVar2 = 0x108;
  }
  while( true ) {
    param_2 = param_2 + 1;
    cVar1 = *param_2;
    if (cVar1 == '\0') break;
    if (cVar1 == '+') {
      uVar2 = uVar2 & 0xffffffe3 | 0x10;
      uVar3 = uVar3 & 0xfffffffc | 2;
    }
    else if (cVar1 == 'x') {
      uVar3 = uVar3 | DAT_400d01f8;
    }
  }
  *param_3 = uVar3 | uVar4;
  return uVar2;
}



// Function at 0x400f20e4

int FUN_400f20e4(int param_1)

{
  return param_1 + 0xf0;
}



// Function at 0x400f20f0

int FUN_400f20f0(void)

{
  return *DAT_400d15a4 + 0xf0;
}



// Function at 0x400f2100

int FUN_400f2100(void)

{
  return *DAT_400d15a4 + 0xf0;
}



// Function at 0x400f2110

undefined4
FUN_400f2110(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*DAT_400d15a4 + 0xe4))(param_1,param_2,param_3,param_4,param_5);
  return uVar1;
}



// Function at 0x400f212c

byte * FUN_400f212c(undefined4 param_1,ushort *param_2,byte *param_3,int param_4)

{
  byte *pbVar1;
  ushort local_30 [24];
  
  if (param_2 == (ushort *)0x0) {
    param_2 = local_30;
  }
  pbVar1 = param_3;
  if ((param_3 != (byte *)0x0) && (pbVar1 = (byte *)0xfffffffe, param_4 != 0)) {
    *param_2 = (ushort)*param_3;
    pbVar1 = (byte *)(uint)(*param_3 != 0);
  }
  return pbVar1;
}



// Function at 0x400f2150

undefined4 * FUN_400f2150(int param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    puVar1 = (undefined4 *)func_0x4008dbdc(0x10);
    *(undefined4 **)(param_1 + 0x24) = puVar1;
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)func_0x4008dacc(DAT_400d15ac,0x66,0,DAT_400d15a8);
    }
    puVar1[1] = 0;
    puVar1[2] = 0;
    *puVar1 = 0;
    puVar1[3] = 0;
  }
  iVar3 = *(int *)(param_1 + 0x24);
  if (*(int *)(iVar3 + 0xc) == 0) {
    uVar2 = func_0x4008dc34(param_1,4,0x21);
    *(undefined4 *)(iVar3 + 0xc) = uVar2;
    if (*(int *)(*(int *)(param_1 + 0x24) + 0xc) != 0) goto LAB_400f217c;
LAB_400f21a1:
    puVar1 = (undefined4 *)0x0;
  }
  else {
LAB_400f217c:
    puVar4 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x24) + 0xc) + param_2 * 4);
    puVar1 = (undefined4 *)*puVar4;
    if (puVar1 == (undefined4 *)0x0) {
      iVar3 = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
      puVar1 = (undefined4 *)func_0x4008dc34(param_1,1,(iVar3 + 5) * 4);
      if (puVar1 == (undefined4 *)0x0) goto LAB_400f21a1;
      puVar1[1] = param_2;
      puVar1[2] = iVar3;
    }
    else {
      *puVar4 = *puVar1;
    }
    puVar1[4] = 0;
    puVar1[3] = 0;
  }
  return puVar1;
}



// Function at 0x400f21d8

void FUN_400f21d8(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    puVar1 = (undefined4 *)func_0x4008dbdc(0x10);
    *(undefined4 **)(param_1 + 0x24) = puVar1;
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)func_0x4008dacc(DAT_400d15ac,0x8a,0,DAT_400d15a8);
    }
    puVar1[1] = 0;
    puVar1[2] = 0;
    *puVar1 = 0;
    puVar1[3] = 0;
  }
  if (param_2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x24) + 0xc) + param_2[1] * 4);
    *param_2 = *puVar1;
    *puVar1 = param_2;
  }
  return;
}



// Function at 0x400f2218

int FUN_400f2218(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar3 = *(int *)(param_2 + 0x10);
  uVar4 = *(uint *)(param_2 + 0x14);
  uVar6 = (uVar4 & 0xffff) * param_3 + param_4;
  uVar5 = (uVar4 >> 0x10) * param_3 + (uVar6 >> 0x10);
  uVar4 = uVar5 >> 0x10;
  *(uint *)(param_2 + 0x14) = uVar5 * 0x10000 + (uVar6 & 0xffff);
  iVar1 = param_2;
  if (uVar4 != 0) {
    if (*(int *)(param_2 + 8) <= iVar3) {
      iVar1 = FUN_400f2150(param_1,*(int *)(param_2 + 4) + 1);
      iVar2 = iVar1;
      if (iVar1 == 0) {
        iVar2 = func_0x4008dacc(DAT_400d15ac,0xb5,0,DAT_400d15b0);
      }
      func_0x400866b8(iVar2 + 0xc,param_2 + 0xc,(*(int *)(param_2 + 0x10) + 2) * 4);
      FUN_400f21d8(param_1,param_2);
    }
    *(uint *)(iVar1 + (iVar3 + 4) * 4 + 4) = uVar4;
    *(int *)(iVar1 + 0x10) = iVar3 + 1;
  }
  return iVar1;
}



// Function at 0x400f2298

int FUN_400f2298(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  for (iVar3 = 1;
      iVar3 < (int)((longlong)(param_4 + 8) * (longlong)DAT_400d15b4 >> 0x21) -
              (param_4 + 8 >> 0x1f); iVar3 = iVar3 << 1) {
    iVar4 = iVar4 + 1;
  }
  iVar3 = FUN_400f2150(param_1,iVar4);
  if (iVar3 == 0) {
    iVar3 = func_0x4008dacc(DAT_400d15ac,0xce,0,DAT_400d15b0);
  }
  *(undefined4 *)(iVar3 + 0x14) = param_5;
  *(undefined4 *)(iVar3 + 0x10) = 1;
  if (param_3 < 10) {
    pbVar2 = (byte *)(param_2 + 10);
    param_3 = 9;
    iVar4 = param_3;
  }
  else {
    pbVar2 = (byte *)(param_2 + 9);
    do {
      bVar1 = *pbVar2;
      pbVar2 = pbVar2 + 1;
      iVar3 = FUN_400f2218(param_1,iVar3,10,bVar1 - 0x30);
    } while (pbVar2 != (byte *)(param_2 + param_3));
    pbVar2 = (byte *)(param_2 + 9) + param_3 + -8;
    iVar4 = param_3;
  }
  for (; param_3 < param_4; param_3 = param_3 + 1) {
    iVar3 = FUN_400f2218(param_1,iVar3,10,pbVar2[param_3 - iVar4] - 0x30);
  }
  return iVar3;
}



// Function at 0x400f2330

int FUN_400f2330(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((param_1 & DAT_400d0830) == 0) {
    param_1 = param_1 << 0x10;
    iVar1 = 0x10;
  }
  if ((param_1 & DAT_400d025c) == 0) {
    iVar1 = iVar1 + 8;
    param_1 = param_1 << 8;
  }
  if ((param_1 & DAT_400d15b8) == 0) {
    iVar1 = iVar1 + 4;
    param_1 = param_1 << 4;
  }
  if ((param_1 & DAT_400d0904) == 0) {
    iVar1 = iVar1 + 2;
    param_1 = param_1 << 2;
  }
  if ((-1 < (int)param_1) && (iVar1 = iVar1 + 1, (param_1 >> 0x1e & 1) == 0)) {
    iVar1 = 0x20;
  }
  return iVar1;
}



// Function at 0x400f2378

int FUN_400f2378(uint *param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1;
  if ((uVar2 & 7) == 0) {
    iVar1 = 0;
    if ((uVar2 & 0xffff) == 0) {
      uVar2 = uVar2 >> 0x10;
      iVar1 = 0x10;
    }
    if ((uVar2 & 0xff) == 0) {
      iVar1 = iVar1 + 8;
      uVar2 = uVar2 >> 8;
    }
    if ((uVar2 & 0xf) == 0) {
      iVar1 = iVar1 + 4;
      uVar2 = uVar2 >> 4;
    }
    if ((uVar2 & 3) == 0) {
      iVar1 = iVar1 + 2;
      uVar2 = uVar2 >> 2;
    }
    if ((uVar2 & 1) == 0) {
      uVar2 = uVar2 >> 1;
      iVar1 = iVar1 + 1;
      if (uVar2 == 0) {
        return 0x20;
      }
    }
    *param_1 = uVar2;
  }
  else {
    iVar1 = 0;
    if ((uVar2 & 1) == 0) {
      if ((uVar2 & 2) == 0) {
        *param_1 = uVar2 >> 2;
        iVar1 = 2;
      }
      else {
        *param_1 = uVar2 >> 1;
        iVar1 = 1;
      }
    }
  }
  return iVar1;
}



// Function at 0x400f23e8

int FUN_400f23e8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_400f2150(param_1,1);
  if (iVar1 == 0) {
    iVar1 = func_0x4008dacc(DAT_400d15ac,0x140,0,DAT_400d15b0);
  }
  *(undefined4 *)(iVar1 + 0x14) = param_2;
  *(undefined4 *)(iVar1 + 0x10) = 1;
  return iVar1;
}



// Function at 0x400f2410

int FUN_400f2410(undefined4 param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  int iVar6;
  ushort *puVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  uint *puVar12;
  uint *puVar13;
  int iVar14;
  uint *puVar15;
  uint uVar16;
  
  iVar3 = param_2;
  if (*(int *)(param_2 + 0x10) < *(int *)(param_3 + 0x10)) {
    iVar3 = param_3;
    param_3 = param_2;
  }
  iVar9 = *(int *)(iVar3 + 0x10);
  iVar6 = *(int *)(param_3 + 0x10);
  iVar5 = iVar9 + iVar6;
  iVar14 = *(int *)(iVar3 + 4);
  if (*(int *)(iVar3 + 8) < iVar5) {
    iVar14 = iVar14 + 1;
  }
  iVar14 = FUN_400f2150(param_1,iVar14);
  if (iVar14 == 0) {
    iVar14 = func_0x4008dacc(DAT_400d15ac,0x15d,0,DAT_400d15b0);
  }
  puVar13 = (uint *)(iVar14 + 0x14);
  puVar15 = puVar13 + iVar5;
  for (puVar1 = puVar13; puVar1 < puVar15; puVar1 = puVar1 + 1) {
    *puVar1 = 0;
  }
  puVar4 = (ushort *)(param_3 + 0x14);
  puVar1 = (uint *)(iVar3 + 0x14) + iVar9;
  puVar7 = puVar4 + iVar6 * 2;
  for (; puVar4 < puVar7; puVar4 = puVar4 + 2) {
    uVar8 = (uint)*puVar4;
    if (uVar8 != 0) {
      uVar2 = 0;
      puVar10 = puVar13;
      puVar12 = (uint *)(iVar3 + 0x14);
      do {
        uVar11 = (*puVar12 & 0xffff) * uVar8 + (*puVar10 & 0xffff) + uVar2;
        uVar16 = (*puVar12 >> 0x10) * uVar8 + (*puVar10 >> 0x10) + (uVar11 >> 0x10);
        uVar2 = uVar16 >> 0x10;
        puVar12 = puVar12 + 1;
        *puVar10 = uVar16 * 0x10000 | uVar11 & 0xffff;
        puVar10 = puVar10 + 1;
      } while (puVar12 < puVar1);
      *puVar10 = uVar2;
    }
    uVar8 = (uint)puVar4[1];
    if (uVar8 != 0) {
      uVar11 = *puVar13;
      puVar12 = (uint *)(iVar3 + 0x14);
      uVar2 = 0;
      puVar10 = puVar13;
      do {
        uVar2 = (ushort)*puVar12 * uVar8 + (uint)*(ushort *)((int)puVar10 + 2) + uVar2;
        *puVar10 = uVar2 * 0x10000 | uVar11 & 0xffff;
        uVar11 = *(ushort *)((int)puVar12 + 2) * uVar8 + (uint)(ushort)puVar10[1] + (uVar2 >> 0x10);
        puVar12 = puVar12 + 1;
        puVar10 = puVar10 + 1;
        uVar2 = uVar11 >> 0x10;
      } while (puVar12 < puVar1);
      *puVar10 = uVar11;
    }
    puVar13 = puVar13 + 1;
  }
  while ((0 < iVar5 && (puVar15 = puVar15 + -1, *puVar15 == 0))) {
    iVar5 = iVar5 + -1;
  }
  *(int *)(iVar14 + 0x10) = iVar5;
  return iVar14;
}



// Function at 0x400f2530

undefined4 FUN_400f2530(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if ((param_3 & 3) != 0) {
    param_2 = FUN_400f2218(param_1,param_2,*(undefined4 *)(DAT_400d15bc + ((param_3 & 3) - 1) * 4),0
                          );
  }
  param_3 = (int)param_3 >> 2;
  if (param_3 != 0) {
    if (*(int *)(param_1 + 0x24) == 0) {
      puVar1 = (undefined4 *)func_0x4008dbdc(0x10);
      *(undefined4 **)(param_1 + 0x24) = puVar1;
      if (puVar1 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)func_0x4008dacc(DAT_400d15ac,0x1ae,0,DAT_400d15a8);
      }
      puVar1[1] = 0;
      puVar1[2] = 0;
      *puVar1 = 0;
      puVar1[3] = 0;
    }
    iVar4 = *(int *)(param_1 + 0x24);
    puVar1 = *(undefined4 **)(iVar4 + 8);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)FUN_400f23e8(param_1,0x271);
      *(undefined4 **)(iVar4 + 8) = puVar1;
      *puVar1 = 0;
    }
    while( true ) {
      puVar3 = puVar1;
      if ((param_3 & 1) != 0) {
        uVar2 = FUN_400f2410(param_1,param_2,puVar3);
        FUN_400f21d8(param_1,param_2);
        param_2 = uVar2;
      }
      param_3 = (int)param_3 >> 1;
      if (param_3 == 0) break;
      puVar1 = (undefined4 *)*puVar3;
      if ((undefined4 *)*puVar3 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)FUN_400f2410(param_1,puVar3,puVar3);
        *puVar3 = puVar1;
        *puVar1 = 0;
      }
    }
  }
  return param_2;
}



// Function at 0x400f25d4

uint FUN_400f25d4(undefined4 param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint *puVar8;
  int *piVar9;
  uint *puVar10;
  int *piVar11;
  uint uVar12;
  int iVar13;
  int *in_t0;
  undefined8 uVar14;
  
  iVar3 = (int)param_3 >> 5;
  iVar13 = *(int *)(param_2 + 4);
  iVar2 = iVar3 + *(int *)(param_2 + 0x10);
  iVar6 = iVar2 + 1;
  for (iVar5 = *(int *)(param_2 + 8); iVar5 < iVar6; iVar5 = iVar5 << 1) {
    iVar13 = iVar13 + 1;
  }
  uVar1 = FUN_400f2150(param_1,iVar13);
  piVar9 = (int *)(uVar1 + 0x14);
  piVar7 = (int *)0x0;
  iVar5 = 0;
  piVar11 = piVar9;
  if (uVar1 != 0) goto LAB_400f261c;
  param_3 = uVar1;
  piVar7 = in_t0;
  uVar14 = func_0x4008dacc(DAT_400d15ac,0x1d9,0,DAT_400d15b0);
  piVar9 = piVar7;
  do {
    iVar5 = (int)((ulonglong)uVar14 >> 0x20);
    *(int *)uVar14 = iVar5;
    piVar7 = (int *)((int)piVar7 + 1);
    piVar11 = (int *)uVar14 + 1;
LAB_400f261c:
    uVar14 = CONCAT44(iVar5,piVar11);
  } while ((int)piVar7 < iVar3);
  puVar10 = (uint *)(piVar9 + (uint)(iVar3 < iVar5) * iVar5 + (uint)(iVar3 >= iVar5) * iVar3);
  puVar8 = (uint *)(param_2 + 0x14);
  puVar4 = puVar8 + *(int *)(param_2 + 0x10);
  if ((param_3 & 0x1f) == 0) {
    do {
      uVar12 = *puVar8;
      puVar8 = puVar8 + 1;
      *puVar10 = uVar12;
      puVar10 = puVar10 + 1;
    } while (puVar8 < puVar4);
  }
  else {
    uVar12 = 0;
    do {
      *puVar10 = *puVar8 << 0x20 - (0x20 - (param_3 & 0x1f)) | uVar12;
      uVar12 = *puVar8;
      puVar8 = puVar8 + 1;
      uVar12 = uVar12 >> (0x20 - (param_3 & 0x1f) & 0x1f);
      puVar10 = puVar10 + 1;
    } while (puVar8 < puVar4);
    *puVar10 = uVar12;
    if (uVar12 != 0) {
      iVar6 = iVar2 + 2;
    }
  }
  *(int *)(uVar1 + 0x10) = iVar6 + -1;
  FUN_400f21d8(param_1,param_2);
  return uVar1;
}



// Function at 0x400f267c

int FUN_400f267c(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  
  iVar3 = *(int *)(param_2 + 0x10);
  iVar2 = *(int *)(param_1 + 0x10) - iVar3;
  if (iVar2 == 0) {
    puVar4 = (uint *)(param_1 + 0x14U) + iVar3;
    puVar1 = (uint *)(param_2 + 0x14 + iVar3 * 4);
    do {
      puVar4 = puVar4 + -1;
      puVar1 = puVar1 + -1;
      if (*puVar4 != *puVar1) {
        if (*puVar4 < *puVar1) {
          return -1;
        }
        return 1;
      }
    } while ((uint *)(param_1 + 0x14U) < puVar4);
  }
  return iVar2;
}



// Function at 0x400f26b4

int FUN_400f26b4(undefined4 param_1,int param_2,int param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  uint *puVar10;
  int iVar11;
  uint *puVar12;
  
  iVar1 = FUN_400f267c(param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = FUN_400f2150(param_1,0);
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x10) = 1;
      *(undefined4 *)(iVar1 + 0x14) = 0;
      return iVar1;
    }
    uVar6 = 0x232;
  }
  else {
    iVar8 = param_2;
    if (iVar1 >= 0) {
      iVar8 = param_3;
      param_3 = param_2;
    }
    param_2 = iVar8;
    param_5 = (uint)(iVar1 < 0);
    iVar1 = FUN_400f2150(param_1,*(undefined4 *)(param_3 + 4));
    if (iVar1 != 0) goto LAB_400f2705;
    uVar6 = 0x240;
  }
  iVar1 = func_0x4008dacc(DAT_400d15ac,uVar6,0,DAT_400d15b0);
LAB_400f2705:
  iVar11 = *(int *)(param_3 + 0x10);
  iVar8 = *(int *)(param_2 + 0x10);
  puVar10 = (uint *)(param_2 + 0x14);
  puVar4 = (uint *)(param_3 + 0x14);
  *(uint *)(iVar1 + 0xc) = param_5;
  puVar12 = puVar4 + iVar11;
  puVar9 = puVar10 + iVar8;
  iVar8 = 0;
  puVar2 = (uint *)(iVar1 + 0x14);
  do {
    uVar7 = ((*puVar4 & 0xffff) + iVar8) - (*puVar10 & 0xffff);
    iVar5 = ((*puVar4 >> 0x10) - (*puVar10 >> 0x10)) + ((int)uVar7 >> 0x10);
    iVar8 = iVar5 >> 0x10;
    puVar3 = puVar2 + 1;
    *puVar2 = iVar5 * 0x10000 | uVar7 & 0xffff;
    puVar10 = puVar10 + 1;
    puVar4 = puVar4 + 1;
    puVar2 = puVar3;
  } while (puVar10 < puVar9);
  for (; puVar4 < puVar12; puVar4 = puVar4 + 1) {
    uVar7 = (*puVar4 & 0xffff) + iVar8;
    iVar5 = (*puVar4 >> 0x10) + ((int)uVar7 >> 0x10);
    iVar8 = iVar5 >> 0x10;
    *puVar3 = iVar5 * 0x10000 | uVar7 & 0xffff;
    puVar3 = puVar3 + 1;
  }
  while (puVar3 = puVar3 + -1, *puVar3 == 0) {
    iVar11 = iVar11 + -1;
  }
  *(int *)(iVar1 + 0x10) = iVar11;
  return iVar1;
}



// Function at 0x400f2794

undefined8 FUN_400f2794(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = (DAT_400d1560 & param_2) + DAT_400d159c;
  if (iVar2 < 1) {
    uVar3 = -iVar2 >> 0x14;
    if (0x13 < (int)uVar3) {
      uVar1 = 1;
      iVar2 = DAT_400d0028;
      if ((int)(uVar3 - 0x14) < 0x1f) {
        uVar1 = DAT_400d0284 >> (uVar3 - 0x14 & 0x1f);
      }
      goto LAB_400f27da;
    }
    iVar2 = DAT_400d0614 >> (uVar3 & 0x1f);
  }
  uVar1 = 0;
LAB_400f27da:
  return CONCAT44(iVar2,uVar1);
}



// Function at 0x400f27dc

undefined8 FUN_400f27dc(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  
  iVar8 = *(int *)(param_1 + 0x10);
  puVar7 = (uint *)(param_1 + 0x14);
  puVar6 = puVar7 + iVar8 + -1;
  uVar5 = *puVar6;
  iVar1 = FUN_400f2330(uVar5);
  *param_2 = 0x20 - iVar1;
  if (iVar1 < 0xb) {
    uVar2 = uVar5 >> (0xbU - iVar1 & 0x1f);
    uVar3 = 0;
    if (puVar7 < puVar6) {
      uVar3 = puVar7[iVar8 + -2];
    }
    uVar5 = uVar5 << 0x20 - (0x20 - (iVar1 + 0x15U & 0x1f));
    uVar3 = uVar3 >> (0xbU - iVar1 & 0x1f);
  }
  else {
    uVar3 = 0;
    if (puVar7 < puVar6) {
      puVar6 = puVar7 + iVar8 + -2;
      uVar3 = *puVar6;
    }
    uVar9 = iVar1 - 0xb;
    if (uVar9 == 0) goto LAB_400f287a;
    uVar2 = uVar5 << 0x20 - (0x20 - (uVar9 & 0x1f)) | uVar3 >> (0x20 - uVar9 & 0x1f);
    uVar4 = 0;
    if (puVar7 < puVar6) {
      uVar4 = puVar6[-1];
    }
    uVar5 = uVar3 << 0x20 - (0x20 - (uVar9 & 0x1f));
    uVar3 = uVar4 >> (0x20 - uVar9 & 0x1f);
  }
  uVar3 = uVar5 | uVar3;
  uVar5 = uVar2;
LAB_400f287a:
  return CONCAT44(uVar5 | DAT_400d1400,uVar3);
}



// Function at 0x400f2880

void FUN_400f2880(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,int *param_5,
                 int *param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint local_30;
  uint auStack_2c [11];
  
  iVar1 = FUN_400f2150(param_1,1);
  if (iVar1 == 0) {
    func_0x4008dacc(DAT_400d15ac,0x30a,0,DAT_400d15b0);
  }
  local_30 = DAT_400d023c & param_4;
  uVar5 = param_4 >> 0x14 & 0x7ff;
  if (uVar5 != 0) {
    local_30 = local_30 | DAT_400d0608;
  }
  if (param_3 == 0) {
    iVar4 = FUN_400f2378(&local_30);
    uVar2 = iVar4 + 0x20;
    *(uint *)(iVar1 + 0x14) = local_30;
    iVar4 = 1;
    *(undefined4 *)(iVar1 + 0x10) = 1;
  }
  else {
    auStack_2c[0] = param_3;
    uVar2 = FUN_400f2378(auStack_2c);
    if (uVar2 == 0) {
      *(uint *)(iVar1 + 0x14) = auStack_2c[0];
    }
    else {
      uVar3 = local_30 << 0x20 - (0x20 - (-uVar2 & 0x1f));
      local_30 = local_30 >> (uVar2 & 0x1f);
      *(uint *)(iVar1 + 0x14) = uVar3 | auStack_2c[0];
    }
    iVar4 = 1;
    if (local_30 != 0) {
      iVar4 = 2;
    }
    *(uint *)(iVar1 + 0x18) = local_30;
    *(int *)(iVar1 + 0x10) = iVar4;
  }
  if (uVar5 == 0) {
    *param_5 = uVar2 - 0x432;
    iVar1 = FUN_400f2330(*(undefined4 *)(iVar1 + iVar4 * 4 + 0x10));
    *param_6 = iVar4 * 0x20 - iVar1;
  }
  else {
    *param_5 = (uVar5 - 0x433) + uVar2;
    *param_6 = 0x35 - uVar2;
  }
  return;
}



// Function at 0x400f2930

undefined4 FUN_400f2930(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int local_30;
  int aiStack_2c [11];
  
  uVar5 = FUN_400f27dc(param_1,aiStack_2c);
  iVar2 = (int)((ulonglong)uVar5 >> 0x20);
  uVar6 = FUN_400f27dc(param_2,&local_30);
  iVar4 = (int)((ulonglong)uVar6 >> 0x20);
  iVar3 = (*(int *)(param_1 + 0x10) - *(int *)(param_2 + 0x10)) * 0x20 + (aiStack_2c[0] - local_30);
  if (iVar3 < 1) {
    iVar4 = iVar4 + iVar3 * -0x100000;
  }
  else {
    iVar2 = iVar3 * 0x100000 + iVar2;
  }
  uVar1 = (*DAT_400d006c)((int)uVar5,iVar2,(int)uVar6,iVar4);
  return uVar1;
}



// Function at 0x400f2984

undefined8 FUN_400f2984(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = CONCAT44(DAT_400d1400,DAT_400d0028);
  if (param_1 < 0x18) {
    uVar1 = *(undefined8 *)(DAT_400d158c + param_1 * 8);
  }
  else {
    do {
      param_1 = param_1 + -1;
      uVar1 = (*DAT_400d0064)((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),DAT_400d0028,DAT_400d0084);
    } while (param_1 != 0);
  }
  return uVar1;
}



// Function at 0x400f29bc

void FUN_400f29bc(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)(param_3 + 0x14);
  puVar1 = param_1 + (param_2 + -1 >> 5) + 1;
  puVar3 = puVar2 + *(int *)(param_3 + 0x10);
  for (; puVar2 < puVar3; puVar2 = puVar2 + 1) {
    *param_1 = *puVar2;
    param_1 = param_1 + 1;
  }
  for (; param_1 < puVar1; param_1 = param_1 + 1) {
    *param_1 = 0;
  }
  return;
}



// Function at 0x400f29f4

undefined4 FUN_400f29f4(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = (int *)(param_1 + 0x14);
  iVar1 = *(int *)(param_1 + 0x10);
  iVar2 = (int)param_2 >> 5;
  iVar3 = iVar1;
  if ((((iVar1 < iVar2) || (iVar3 = iVar2, iVar1 <= iVar2)) || ((param_2 & 0x1f) == 0)) ||
     (piVar5[iVar2] == ((uint)piVar5[iVar2] >> (param_2 & 0x1f)) << 0x20 - (0x20 - (param_2 & 0x1f))
     )) {
    piVar4 = piVar5 + iVar3;
    do {
      if (piVar4 <= piVar5) {
        return 0;
      }
      piVar4 = piVar4 + -1;
    } while (*piVar4 == 0);
  }
  return 1;
}



// Function at 0x400f2a44

undefined8 FUN_400f2a44(int param_1,uint param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar1 = DAT_400d0140;
  uVar3 = CONCAT44(param_2,param_1);
  *param_3 = 0;
  uVar2 = uVar1 & param_2;
  if (((int)uVar2 <= DAT_400d141c) && (uVar2 != 0 || param_1 != 0)) {
    if ((param_2 & DAT_400d1560) == 0) {
      uVar3 = (*DAT_400d0064)(param_1,param_2,DAT_400d0028,DAT_400d1418);
      uVar2 = uVar1 & (uint)((ulonglong)uVar3 >> 0x20);
      *param_3 = -0x36;
    }
    uVar1 = DAT_400d143c;
    param_1 = (int)uVar3;
    param_2 = (uint)((ulonglong)uVar3 >> 0x20) & DAT_400d15c4;
    *param_3 = *param_3 + ((int)uVar2 >> 0x14) + -0x3fe;
    param_2 = param_2 | uVar1;
  }
  return CONCAT44(param_2,param_1);
}



// Function at 0x400f2aa0

int FUN_400f2aa0(int param_1,byte *param_2,int *param_3,int *param_4,int param_5,int param_6,
                undefined4 *param_7)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uStack_3c;
  
  iVar2 = *param_4;
  if ((byte *)*param_7 != (byte *)0x0) {
    param_2 = (byte *)*param_7;
  }
  while ((iVar2 <= param_1 && (*param_2 != 0))) {
    for (; (bVar1 = *param_2, bVar1 != 0 && (bVar1 != 0x25)); param_2 = param_2 + 1) {
    }
    if (bVar1 == 0) break;
    param_2 = param_2 + 1;
    uStack_3c = 0;
    do {
      bVar1 = *param_2;
      param_2 = param_2 + 1;
      iVar3 = uStack_3c * 9;
      uStack_3c = (uint)*(byte *)(DAT_400d14b4 + iVar3 + (uint)*(byte *)(DAT_400d14b0 + (uint)bVar1)
                                 );
      uVar5 = *(byte *)(DAT_400d14b8 + iVar3 + (uint)*(byte *)(DAT_400d14b0 + (uint)bVar1)) - 1 &
              0xff;
      if (uVar5 < 8) {
                    /* WARNING: Could not recover jumptable at 0x400f2b29. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar2 = (**(code **)(DAT_400d15c8 + uVar5 * 4))();
        return iVar2;
      }
    } while (uStack_3c != 0xb);
  }
  while( true ) {
    if (param_1 < iVar2) {
      *param_4 = iVar2;
      *param_7 = param_2;
      return param_5 + param_1 * 8;
    }
    iVar3 = param_3[2];
    uVar5 = *(int *)(param_6 + iVar2 * 4) - 1;
    if (uVar5 < 6) break;
    iVar4 = iVar3 + 4;
    param_3[2] = iVar4;
    if (iVar4 < 0x19) {
      iVar3 = param_3[1];
    }
    else {
      if (iVar3 < 0x19) {
        param_3[2] = 0x24;
      }
      iVar3 = *param_3;
    }
    *(undefined4 *)(param_5 + iVar2 * 8) = *(undefined4 *)(iVar3 + param_3[2] + -4);
    iVar2 = iVar2 + 1;
  }
                    /* WARNING: Could not recover jumptable at 0x400f2e74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (**(code **)(DAT_400d15d4 + uVar5 * 4))();
  return iVar2;
}



// Function at 0x400f2f60

undefined4 FUN_400f2f60(undefined4 *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *local_30;
  undefined4 uStack_2c;
  
  if (param_3[2] != 0) {
    local_30 = (undefined4 *)*param_3;
    uStack_2c = 0;
    uVar4 = 0;
    do {
      if (uVar4 != 0) {
        uVar5 = param_2[2];
        if (uVar4 < uVar5) {
LAB_400f3024:
          uVar5 = uVar4;
        }
        else {
          if ((*(ushort *)(param_2 + 3) & 0x480) != 0) {
            iVar2 = *param_2 - param_2[4];
            uVar5 = (param_2[5] * 3) / 2;
            uVar6 = iVar2 + 1 + uVar4;
            iVar3 = (uVar5 < uVar6) * uVar6 + (uVar5 >= uVar6) * uVar5;
            if ((*(ushort *)(param_2 + 3) & 0x400) == 0) {
              iVar1 = func_0x4008dc20(param_1,param_2[4],iVar3);
              if (iVar1 == 0) {
                func_0x4008dc14(param_1,param_2[4]);
                goto LAB_400f3008;
              }
            }
            else {
              iVar1 = func_0x4008dc08(param_1,iVar3);
              if (iVar1 == 0) {
LAB_400f3008:
                *param_1 = 0xc;
                *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x40;
                param_3[2] = 0;
                param_3[1] = 0;
                return 0xffffffff;
              }
              func_0x400866b8(iVar1,param_2[4],iVar2);
              *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) & 0xfb7f | 0x80;
            }
            param_2[4] = iVar1;
            param_2[5] = iVar3;
            *param_2 = iVar1 + iVar2;
            param_2[2] = iVar3 - iVar2;
            uVar5 = uVar4;
          }
          if (uVar4 < uVar5) goto LAB_400f3024;
        }
        func_0x400867b0(*param_2,uStack_2c,uVar5);
        param_2[2] = param_2[2] - uVar5;
        iVar2 = param_3[2];
        *param_2 = *param_2 + uVar5;
        param_3[2] = iVar2 - uVar4;
        if (iVar2 - uVar4 == 0) break;
      }
      uStack_2c = *local_30;
      uVar4 = local_30[1];
      local_30 = local_30 + 2;
    } while( true );
  }
  param_3[1] = 0;
  return 0;
}



// Function at 0x400f5024

int FUN_400f5024(int param_1,byte *param_2,int *param_3,int *param_4,int param_5,int param_6,
                undefined4 *param_7)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uStack_3c;
  
  iVar2 = *param_4;
  if ((byte *)*param_7 != (byte *)0x0) {
    param_2 = (byte *)*param_7;
  }
  while ((iVar2 <= param_1 && (*param_2 != 0))) {
    for (; (bVar1 = *param_2, bVar1 != 0 && (bVar1 != 0x25)); param_2 = param_2 + 1) {
    }
    if (bVar1 == 0) break;
    param_2 = param_2 + 1;
    uStack_3c = 0;
    do {
      bVar1 = *param_2;
      param_2 = param_2 + 1;
      iVar3 = uStack_3c * 9;
      uStack_3c = (uint)*(byte *)(DAT_400d14b4 + iVar3 + (uint)*(byte *)(DAT_400d14b0 + (uint)bVar1)
                                 );
      uVar5 = *(byte *)(DAT_400d14b8 + iVar3 + (uint)*(byte *)(DAT_400d14b0 + (uint)bVar1)) - 1 &
              0xff;
      if (uVar5 < 8) {
                    /* WARNING: Could not recover jumptable at 0x400f50ad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar2 = (**(code **)(DAT_400d15ec + uVar5 * 4))();
        return iVar2;
      }
    } while (uStack_3c != 0xb);
  }
  while( true ) {
    if (param_1 < iVar2) {
      *param_4 = iVar2;
      *param_7 = param_2;
      return param_5 + param_1 * 8;
    }
    iVar3 = param_3[2];
    uVar5 = *(int *)(param_6 + iVar2 * 4) - 1;
    if (uVar5 < 6) break;
    iVar4 = iVar3 + 4;
    param_3[2] = iVar4;
    if (iVar4 < 0x19) {
      iVar3 = param_3[1];
    }
    else {
      if (iVar3 < 0x19) {
        param_3[2] = 0x24;
      }
      iVar3 = *param_3;
    }
    *(undefined4 *)(param_5 + iVar2 * 8) = *(undefined4 *)(iVar3 + param_3[2] + -4);
    iVar2 = iVar2 + 1;
  }
                    /* WARNING: Could not recover jumptable at 0x400f53f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (**(code **)(DAT_400d15f8 + uVar5 * 4))();
  return iVar2;
}



// Function at 0x400f54e4

undefined4 FUN_400f54e4(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (*(int *)(param_3 + 8) == 0) {
    *(undefined4 *)(param_3 + 4) = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = func_0x40086190(param_1,param_2,param_3);
    *(undefined4 *)(param_3 + 8) = 0;
    *(undefined4 *)(param_3 + 4) = 0;
  }
  return uVar1;
}



// Function at 0x400f5508

/* WARNING: Removing unreachable block (ram,0x400f726b) */
/* WARNING: Removing unreachable block (ram,0x400f7294) */
/* WARNING: Removing unreachable block (ram,0x400f72a8) */
/* WARNING: Removing unreachable block (ram,0x400f728c) */
/* WARNING: Removing unreachable block (ram,0x400f715a) */
/* WARNING: Removing unreachable block (ram,0x400f7166) */
/* WARNING: Removing unreachable block (ram,0x400f56a1) */
/* WARNING: Removing unreachable block (ram,0x400f56b4) */
/* WARNING: Removing unreachable block (ram,0x400f56b7) */
/* WARNING: Removing unreachable block (ram,0x400f7180) */
/* WARNING: Removing unreachable block (ram,0x400f71cc) */
/* WARNING: Removing unreachable block (ram,0x400f71e0) */
/* WARNING: Removing unreachable block (ram,0x400f71f3) */
/* WARNING: Removing unreachable block (ram,0x400f7207) */
/* WARNING: Removing unreachable block (ram,0x400f718f) */
/* WARNING: Removing unreachable block (ram,0x400f71a3) */
/* WARNING: Removing unreachable block (ram,0x400f71be) */
/* WARNING: Removing unreachable block (ram,0x400f71c6) */
/* WARNING: Removing unreachable block (ram,0x400f721e) */
/* WARNING: Removing unreachable block (ram,0x400f7248) */
/* WARNING: Removing unreachable block (ram,0x400f725c) */
/* WARNING: Removing unreachable block (ram,0x400f7240) */
/* WARNING: Removing unreachable block (ram,0x400f72ba) */
/* WARNING: Removing unreachable block (ram,0x400f72c6) */
/* WARNING: Removing unreachable block (ram,0x400f730f) */
/* WARNING: Removing unreachable block (ram,0x400f7326) */
/* WARNING: Removing unreachable block (ram,0x400f733a) */
/* WARNING: Removing unreachable block (ram,0x400f734f) */
/* WARNING: Removing unreachable block (ram,0x400f72d4) */
/* WARNING: Removing unreachable block (ram,0x400f72e7) */
/* WARNING: Removing unreachable block (ram,0x400f7301) */
/* WARNING: Removing unreachable block (ram,0x400f7309) */
/* WARNING: Removing unreachable block (ram,0x400f72c3) */
/* WARNING: Removing unreachable block (ram,0x400f7366) */
/* WARNING: Removing unreachable block (ram,0x400f73af) */
/* WARNING: Removing unreachable block (ram,0x400f73c6) */
/* WARNING: Removing unreachable block (ram,0x400f73da) */
/* WARNING: Removing unreachable block (ram,0x400f73eb) */
/* WARNING: Removing unreachable block (ram,0x400f7374) */
/* WARNING: Removing unreachable block (ram,0x400f7387) */
/* WARNING: Removing unreachable block (ram,0x400f73a1) */
/* WARNING: Removing unreachable block (ram,0x400f73a9) */

int FUN_400f5508(int param_1,int param_2,char *param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6)

{
  byte bVar1;
  int iVar2;
  char **ppcVar3;
  uint uVar4;
  char *pcVar5;
  code *UNRECOVERED_JUMPTABLE;
  char *pcVar6;
  char *pcVar7;
  byte abStack_130 [100];
  char *local_cc;
  int iStack_c8;
  char *local_c4 [14];
  char **ppcStack_8c;
  uint uStack_88;
  char *pcStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined1 uStack_72;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  uint uStack_64;
  char **ppcStack_60;
  int iStack_5c;
  int iStack_58;
  char *pcStack_54;
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  undefined4 *puStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  char **ppcStack_30;
  char *pcStack_24;
  
  uStack_70 = param_4;
  uStack_6c = param_5;
  uStack_68 = param_6;
  iStack_5c = param_2;
  pcStack_54 = param_3;
  iStack_50 = param_1;
  if ((param_1 != 0) && (*(int *)(param_1 + 0x18) == 0)) {
    func_0x4008606c(param_1);
  }
  if (iStack_5c == DAT_400d1494) {
    iStack_5c = *(int *)(iStack_50 + 4);
  }
  else if (iStack_5c == DAT_400d1498) {
    iStack_5c = *(int *)(iStack_50 + 8);
  }
  else if (iStack_5c == DAT_400d149c) {
    iStack_5c = *(int *)(iStack_50 + 0xc);
  }
  FUN_400f8218(1,&uStack_80);
  if (((*(uint *)(iStack_5c + 100) & 1) == 0) && ((*(ushort *)(iStack_5c + 0xc) & 0x200) == 0)) {
    func_0x400853c0(*(undefined4 *)(iStack_5c + 0x58));
  }
  if ((((*(ushort *)(iStack_5c + 0xc) & 8) == 0) || (*(int *)(iStack_5c + 0x10) == 0)) &&
     (iVar2 = func_0x40086edc(iStack_50,iStack_5c), iVar2 != 0)) {
    if (((*(uint *)(iStack_5c + 100) & 1) == 0) && ((*(ushort *)(iStack_5c + 0xc) & 0x200) == 0)) {
      func_0x400853d8(*(undefined4 *)(iStack_5c + 0x58));
    }
    FUN_400f8218(uStack_80,&uStack_80);
    iStack_48 = -1;
  }
  else if (((*(ushort *)(iStack_5c + 0xc) & 0x1a) == 10) && (-1 < *(short *)(iStack_5c + 0xe))) {
    if (((*(uint *)(iStack_5c + 100) & 1) == 0) && ((*(ushort *)(iStack_5c + 0xc) & 0x200) == 0)) {
      func_0x400853d8(*(undefined4 *)(iStack_5c + 0x58));
    }
    FUN_400f8218(uStack_80,&uStack_80);
    iStack_48 = FUN_400f75bc(iStack_50,iStack_5c,pcStack_54,uStack_70,uStack_6c,uStack_68);
  }
  else {
    pcStack_84 = (char *)0x0;
    uStack_7c = 0;
    uStack_78 = 0;
    uStack_40 = 0;
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    iStack_48 = 0;
    ppcStack_8c = &local_cc;
    ppcStack_30 = &local_cc;
    while( true ) {
      ppcStack_60 = &local_cc;
      for (pcVar5 = pcStack_54; (*pcVar5 != '\0' && (*pcVar5 != '%')); pcVar5 = pcVar5 + 1) {
      }
      iVar2 = (int)pcVar5 - (int)pcStack_54;
      if (iVar2 != 0) {
        pcStack_84 = pcStack_84 + iVar2;
        ppcStack_60 = local_c4;
        local_cc = pcStack_54;
        iStack_48 = iStack_48 + iVar2;
        iStack_c8 = iVar2;
      }
      ppcVar3 = ppcStack_60;
      uStack_88 = (uint)(iVar2 != 0);
      if (*pcVar5 == '\0') break;
      uStack_72 = 0;
      puStack_44 = &uStack_78;
      iStack_58 = -1;
      iStack_4c = 0;
      uStack_64 = 0;
      pcStack_54 = pcVar5 + 2;
      bVar1 = pcVar5[1];
      uVar4 = (uint)bVar1;
      if (uVar4 - 0x20 < 0x5b) {
        UNRECOVERED_JUMPTABLE = *(code **)(DAT_400d1604 + (uVar4 - 0x20) * 4);
                    /* WARNING: Could not recover jumptable at 0x400f5731. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar2 = (*UNRECOVERED_JUMPTABLE)(pcVar5,0,uVar4,0,0,UNRECOVERED_JUMPTABLE);
        return iVar2;
      }
      if (uVar4 == 0) break;
      iStack_4c = 0;
      iStack_58 = 1;
      uStack_64 = 0;
      uStack_72 = 0;
      *ppcStack_60 = (char *)abStack_130;
      ppcVar3[1] = (char *)0x1;
      uStack_88 = uStack_88 + 1;
      pcStack_84 = pcStack_84 + iStack_58;
      abStack_130[0] = bVar1;
      if ((int)uStack_88 < 8) {
        ppcVar3 = ppcStack_60 + 2;
      }
      else {
        iVar2 = FUN_400f54e4(iStack_50,iStack_5c,&ppcStack_8c);
        if (iVar2 != 0) goto LAB_400f752c;
        ppcVar3 = &local_cc;
      }
      if (((uStack_64 & 4) != 0) && (pcVar5 = (char *)(iStack_4c + -1), 0 < (int)pcVar5)) {
        pcVar6 = (char *)0x10;
        while( true ) {
          *ppcVar3 = DAT_400d1608;
          uStack_88 = uStack_88 + 1;
          if ((int)pcVar5 <= (int)pcVar6) break;
          pcVar7 = pcStack_84 + 0x10;
          ppcVar3[1] = pcVar6;
          ppcVar3 = ppcVar3 + 2;
          pcStack_84 = pcVar7;
          if (7 < (int)uStack_88) {
            pcStack_24 = pcVar6;
            iVar2 = FUN_400f54e4(iStack_50,iStack_5c,&ppcStack_8c);
            if (iVar2 != 0) goto LAB_400f752c;
            ppcVar3 = &local_cc;
            pcVar6 = pcStack_24;
          }
          pcVar5 = pcVar5 + -0x10;
        }
        ppcVar3[1] = pcVar5;
        pcStack_84 = pcVar5 + (int)pcStack_84;
        if ((7 < (int)uStack_88) &&
           (iVar2 = FUN_400f54e4(iStack_50,iStack_5c,&ppcStack_8c), iVar2 != 0)) goto LAB_400f752c;
      }
      iStack_48 = iStack_48 + (uint)(iStack_4c < 1) + (uint)(iStack_4c >= 1) * iStack_4c;
      if ((pcStack_84 != (char *)0x0) &&
         (iVar2 = FUN_400f54e4(iStack_50,iStack_5c,&ppcStack_8c), iVar2 != 0)) goto LAB_400f752c;
    }
    if ((pcStack_84 == (char *)0x0) ||
       (iVar2 = FUN_400f54e4(iStack_50,iStack_5c,&ppcStack_8c), iVar2 == 0)) {
      uStack_88 = 0;
    }
LAB_400f752c:
    if (((*(uint *)(iStack_5c + 100) & 1) == 0) && ((*(ushort *)(iStack_5c + 0xc) & 0x200) == 0)) {
      func_0x400853d8(*(undefined4 *)(iStack_5c + 0x58));
    }
    FUN_400f8218(uStack_80,&uStack_80);
    if ((*(ushort *)(iStack_5c + 0xc) >> 6 & 1) != 0) {
      iStack_48 = -1;
    }
  }
  return iStack_48;
}



// Function at 0x400f759c

undefined4
FUN_400f759c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  
  uVar1 = func_0x4008a814();
  uVar1 = FUN_400f5508(uVar1,param_1,param_2,param_3,param_4,param_5);
  return uVar1;
}



// Function at 0x400f75bc

int FUN_400f75bc(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_120 [128];
  undefined1 *apuStack_a0 [2];
  undefined4 uStack_98;
  ushort uStack_94;
  undefined2 uStack_92;
  undefined1 *puStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_80;
  undefined4 uStack_78;
  undefined4 auStack_48 [3];
  undefined4 uStack_3c;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  apuStack_a0[0] = auStack_120;
  puStack_90 = auStack_120;
  uStack_94 = *(ushort *)(param_2 + 0xc) & 0xfffd;
  uStack_3c = *(undefined4 *)(param_2 + 100);
  uStack_92 = *(undefined2 *)(param_2 + 0xe);
  uStack_80 = *(undefined4 *)(param_2 + 0x20);
  uStack_88 = 0;
  uStack_78 = *(undefined4 *)(param_2 + 0x28);
  uStack_98 = 0x80;
  uStack_8c = 0x80;
  uStack_30 = param_4;
  uStack_2c = param_5;
  uStack_28 = param_6;
  func_0x40085394(auStack_48);
  iVar1 = FUN_400f5508(param_1,apuStack_a0,param_3,uStack_30,uStack_2c,uStack_28);
  if ((-1 < iVar1) && (iVar2 = func_0x40085ec8(param_1,apuStack_a0), iVar2 != 0)) {
    iVar1 = -1;
  }
  if ((uStack_94 & 0x40) != 0) {
    *(ushort *)(param_2 + 0xc) = *(ushort *)(param_2 + 0xc) | 0x40;
  }
  func_0x400853ac(auStack_48[0]);
  return iVar1;
}



// Function at 0x400f765c

undefined4 FUN_400f765c(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  if (param_3 == 1) {
    *param_1 = param_2;
  }
  else if (param_3 == 2) {
    *param_1 = *param_2;
  }
  return 0;
}



// Function at 0x400f7678

void FUN_400f7678(undefined1 *param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  param_1[7] = 0;
  param_1[8] = 0;
  *param_1 = 0;
  param_1[3] = 9;
  param_1[4] = 1;
  param_1[5] = 1;
  param_1[6] = 1;
  return;
}



// Function at 0x400f769c

undefined4 FUN_400f769c(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  
  bVar1 = *param_2;
  if (bVar1 == 0x28) {
    uVar2 = 1;
  }
  else if (bVar1 < 0x29) {
    if (bVar1 == 0x10) {
      uVar2 = 1;
    }
    else if (bVar1 == 0x22) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else if (bVar1 == 0x3b) {
    uVar2 = 1;
  }
  else if (bVar1 == 0x42) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



// Function at 0x400f76e0

undefined4 FUN_400f76e0(undefined4 param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (param_3 <= uVar1) {
      return 1;
    }
    if (*(char *)(param_2 + uVar1) != '\0') break;
    uVar1 = uVar1 + 1;
  }
  return 0;
}



// Function at 0x400f7700

undefined4 FUN_400f7700(char param_1)

{
  undefined4 uVar1;
  
  if (param_1 == '\n') {
    uVar1 = 0xbc;
  }
  else if (param_1 == '\v') {
    uVar1 = 0x177;
  }
  else if (param_1 == '\t') {
    uVar1 = 0x5e;
  }
  else {
    uVar1 = 0x2ee;
  }
  return uVar1;
}



// Function at 0x400f772c

void FUN_400f772c(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  return;
}



// Function at 0x400f7734

void FUN_400f7734(int param_1)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined1 *)(param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 0x11) = 0;
  for (iVar1 = 7; *(undefined1 *)(param_1 + iVar1 + 8) = 0, iVar1 != 0; iVar1 = iVar1 + -1) {
  }
  return;
}



// Function at 0x400f7754

undefined4 FUN_400f7754(void)

{
  return 0;
}



// Function at 0x400f775c

undefined4 FUN_400f775c(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x24))(param_1,param_2,param_3);
  return uVar1;
}



// Function at 0x400f7770

undefined4 FUN_400f7770(int param_1,undefined1 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    uVar1 = 0;
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x28);
    if (uVar2 < *(uint *)(param_1 + 0x14)) {
      *(uint *)(param_1 + 0x28) = uVar2 + 1;
      *(undefined1 *)(*(int *)(param_1 + 0x24) + uVar2) = param_2;
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



// Function at 0x400f77c0

int FUN_400f77c0(int param_1)

{
  return *(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x1c);
}



// Function at 0x400f77cc

uint FUN_400f77cc(int param_1)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x1c);
    if (uVar1 < *(uint *)(param_1 + 0x20)) {
      *(uint *)(param_1 + 0x1c) = uVar1 + 1;
      uVar1 = (uint)*(byte *)(*(int *)(param_1 + 0x18) + uVar1);
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}



// Function at 0x400f7820

undefined4 FUN_400f7820(int param_1,int param_2,int param_3)

{
  if (param_2 < 0) {
    if (*(char *)(param_1 + 0x10) == '\0') {
      param_2 = (int)*(char *)(param_1 + 0x11);
      if (param_2 == -1) {
        param_2 = 0x15;
      }
    }
    else {
      param_2 = (int)*(char *)(param_1 + 0x11);
      if (param_2 == -1) {
        return 0;
      }
    }
  }
  if (param_3 < 0) {
    if (*(char *)(param_1 + 0x10) == '\0') {
      param_3 = (int)*(char *)(param_1 + 0x12);
      if (param_3 == -1) {
        param_3 = 0x16;
      }
    }
    else {
      param_3 = (int)*(char *)(param_1 + 0x12);
      if (param_3 == -1) {
        return 0;
      }
    }
  }
  *(char *)(param_1 + 0x11) = (char)param_2;
  *(char *)(param_1 + 0x12) = (char)param_3;
  return 1;
}



// Function at 0x400f7898

uint FUN_400f7898(byte *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0xff;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    uVar1 = uVar1 ^ *param_1;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      if ((char)uVar1 < '\0') {
        uVar1 = uVar1 << 1 ^ 0x31;
      }
      else {
        uVar1 = uVar1 << 1;
      }
      uVar1 = uVar1 & 0xff;
    }
    param_1 = param_1 + 1;
  }
  return uVar1;
}



// Function at 0x400f78d8

void FUN_400f78d8(void)

{
  return;
}



// Function at 0x400f78e0

void FUN_400f78e0(void)

{
  return;
}



// Function at 0x400f78e8

void FUN_400f78e8(int param_1)

{
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}



// Function at 0x400f78fc

void FUN_400f78fc(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x18) = param_2;
  return;
}



// Function at 0x400f7904

void FUN_400f7904(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  return;
}



// Function at 0x400f790c

void FUN_400f790c(undefined4 *param_1,undefined4 param_2,undefined2 param_3,undefined1 param_4,
                 undefined1 param_5,undefined1 param_6)

{
  param_1[7] = 0;
  *param_1 = param_2;
  param_1[1] = 0;
  *(undefined1 *)((int)param_1 + 0x13) = param_6;
  *(undefined2 *)(param_1 + 4) = param_3;
  *(undefined1 *)(param_1 + 5) = param_5;
  *(undefined1 *)((int)param_1 + 0x12) = param_4;
  return;
}



// Function at 0x400f7928

uint FUN_400f7928(int param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4,
                 undefined2 param_5)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_1 + 0x10);
  if (uVar1 != 0) {
    if (*(code **)(param_1 + 8) == (code *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (**(code **)(param_1 + 8))
                        (*(undefined4 *)(param_1 + 0x14),param_2,param_3,param_4,param_5);
    }
  }
  return uVar1;
}



// Function at 0x400f7950

uint FUN_400f7950(int param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4,
                 undefined2 param_5)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_1 + 0x10);
  if (uVar1 != 0) {
    if (*(code **)(param_1 + 0xc) == (code *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (**(code **)(param_1 + 0xc))
                        (*(undefined4 *)(param_1 + 0x14),param_2,param_3,param_4,param_5);
    }
  }
  return uVar1;
}



// Function at 0x400f7978

void FUN_400f7978(undefined1 *param_1,undefined1 param_2,undefined4 param_3)

{
  *param_1 = param_2;
  *(undefined4 *)(param_1 + 4) = param_3;
  param_1[8] = 0;
  *(undefined4 *)(param_1 + 0xc) = 0x80;
  return;
}



// Function at 0x400f798c

undefined4 FUN_400f798c(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x28))(param_1,param_2,param_3);
  return uVar1;
}



// Function at 0x400f79a0

void FUN_400f79a0(void)

{
  return;
}



// Function at 0x400f79a8

void FUN_400f79a8(void)

{
  return;
}



// Function at 0x400f79b0

void FUN_400f79b0(void)

{
  return;
}



// Function at 0x400f79b8

undefined4 FUN_400f79b8(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



// Function at 0x400f79c0

void FUN_400f79c0(void)

{
  return;
}



// Function at 0x400f79c8

void FUN_400f79c8(void)

{
  return;
}



// Function at 0x400f79d0

undefined4 FUN_400f79d0(void)

{
  return 1;
}



// Function at 0x400f79d8

undefined4 FUN_400f79d8(void)

{
  return 0;
}



// Function at 0x400f79e0

void FUN_400f79e0(int *param_1)

{
  memw();
  memw();
  *(uint *)(*param_1 + 0x38) = *(uint *)(*param_1 + 0x38) & 0xffffffef;
  memw();
  *(undefined4 *)(*param_1 + 0x38) = 0;
  memw();
  *(undefined4 *)(*param_1 + 0x34) = 0;
  memw();
  *(undefined4 *)(*param_1 + 0x1c) = 0;
  memw();
  *(undefined4 *)(*param_1 + 0x20) = 0;
  memw();
  *(undefined4 *)(*param_1 + 8) = 0;
  memw();
  *(undefined4 *)(*param_1 + 0xc) = 0;
  memw();
  *(undefined4 *)(*param_1 + 0x14) = 0;
  memw();
  *(undefined4 *)(*param_1 + 0x18) = 0;
  return;
}



// Function at 0x400f7a30

undefined4 FUN_400f7a30(int *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    memw();
    uVar1 = *(undefined4 *)(*param_1 + 0x18);
  }
  return uVar1;
}



// Function at 0x400f7a44

void FUN_400f7a44(int param_1,undefined4 *param_2)

{
  *param_2 = 0;
  if (param_1 != 0) {
    *param_2 = *(undefined4 *)(param_1 + 8);
  }
  return;
}



// Function at 0x400f7a54

undefined4 FUN_400f7a54(void)

{
  return 1;
}



// Function at 0x400f7a5c

uint * FUN_400f7a5c(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = (uint)(param_1 == (uint *)0x0);
  if ((param_1 == (uint *)0x0) || (param_2 < 0x15)) {
    param_1 = (uint *)0x0;
  }
  else {
    *param_1 = uVar1;
    param_1[1] = uVar1;
    param_1[2] = uVar1;
    param_1[3] = (uint)(param_1 + 5);
    param_1[4] = param_2 - 0x14;
  }
  memw();
  return param_1;
}



// Function at 0x400f7a8c

void FUN_400f7a8c(void)

{
  return;
}



// Function at 0x400f7a94

undefined4 FUN_400f7a94(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((*param_1 != -1) && (1 < param_1[6] - 3U)) {
    uVar1 = 0;
  }
  return uVar1;
}



// Function at 0x400f7ab0

uint FUN_400f7ab0(uint *param_1,char *param_2,char param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_1 == (uint *)0x0) || (param_2 == (char *)0x0 || param_1 == (uint *)0x0)) {
    uVar1 = 0xffffffff;
  }
  else if (*param_2 == '\0') {
    uVar1 = 0xffffffff;
    if (param_2[1] != '\0') {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
    if (param_2[1] != '\0') {
      uVar3 = param_1[8];
      uVar1 = *param_1;
      uVar2 = (uVar1 < uVar3) * uVar1 + (uVar1 >= uVar3) * uVar3;
      if (param_3 != '\0') {
        uVar2 = (uVar1 < uVar3) * uVar3 + (uVar1 >= uVar3) * uVar1;
      }
      uVar1 = (uint)(uVar1 != uVar2);
    }
  }
  return uVar1;
}



// Function at 0x400f7b00

void FUN_400f7b00(void)

{
  return;
}



// Function at 0x400f7b08

bool FUN_400f7b08(int param_1)

{
  return *(int *)(param_1 + 4) != 0;
}



// Function at 0x400f7b18

void FUN_400f7b18(int *param_1,int *param_2)

{
  if (param_1[1] != 0) {
    *(int **)(param_1[1] + 4) = param_2;
  }
  *param_2 = param_1[1];
  param_2[1] = 0;
  param_1[1] = (int)param_2;
  if (*param_1 == 0) {
    *param_1 = (int)param_2;
  }
  param_1[2] = param_1[2] + 1;
  memw();
  return;
}



// Function at 0x400f7b3c

void FUN_400f7b3c(void)

{
  return;
}



// Function at 0x400f7b44

int FUN_400f7b44(int param_1)

{
  return *(int *)(param_1 + 0xc) + 0x14;
}



// Function at 0x400f7b50

undefined4 FUN_400f7b50(int param_1)

{
  return *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xc);
}



// Function at 0x400f7b5c

undefined4 FUN_400f7b5c(int param_1)

{
  return *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
}



// Function at 0x400f7b68

void FUN_400f7b68(void)

{
  return;
}



// Function at 0x400f7b70

void FUN_400f7b70(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_2 + 4);
  iVar2 = *(int *)(param_2 + 8);
  if (iVar1 == 0) {
    *param_1 = iVar2;
    memw();
  }
  else {
    *(int *)(iVar1 + 8) = iVar2;
  }
  if (iVar2 == 0) {
    param_1[1] = iVar1;
    memw();
  }
  else {
    *(int *)(iVar2 + 4) = iVar1;
  }
  param_1[2] = param_1[2] + -1;
  memw();
  return;
}



// Function at 0x400f7b9c

void FUN_400f7b9c(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  memw();
  return;
}



// Function at 0x400f7bac

undefined4 * FUN_400f7bac(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0xff;
  memw();
  return param_1 + 4;
}



// Function at 0x400f7bcc

void FUN_400f7bcc(undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_2;
  piVar2 = (int *)param_2[1];
  if (iVar1 == 0) {
    *param_1 = piVar2;
    memw();
  }
  else {
    *(int **)(iVar1 + 4) = piVar2;
  }
  if (piVar2 == (int *)0x0) {
    param_1[1] = iVar1;
    memw();
  }
  else {
    *piVar2 = iVar1;
  }
  param_1[2] = param_1[2] + -1;
  memw();
  return;
}



// Function at 0x400f7bf8

bool FUN_400f7bf8(char param_1)

{
  return param_1 == '!' || (byte)(param_1 + 0xbfU) < 2;
}



// Function at 0x400f7c20

int FUN_400f7c20(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint auStack_24 [9];
  
  iVar1 = -1;
  if (param_2 < 0x7e) {
    iVar1 = (param_2 >> 4) * 4;
    iVar3 = param_1 + iVar1;
    auStack_24[0] =
         (3 << 0x20 - ((param_2 & 0xf) * -2 + 0x20) ^ 0xffffffffU) & *(uint *)(iVar3 + 0x18) |
         param_3 << 0x20 - ((param_2 & 0xf) * -2 + 0x20);
    piVar2 = *(int **)(param_1 + 0x50);
    *(uint *)(iVar3 + 0x18) = auStack_24[0];
    memw();
    iVar1 = (**(code **)(*piVar2 + 0x14))(piVar2,*(int *)(param_1 + 8) + 0x20 + iVar1,auStack_24,4);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
  }
  memw();
  return iVar1;
}



// Function at 0x400f7c80

int FUN_400f7c80(int param_1,uint param_2,uint param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 auStack_24 [9];
  
  if ((param_2 < param_3) && (param_3 < 0x7f)) {
    param_3 = param_3 - 1;
    uVar3 = param_3 >> 4;
    for (; (int)param_2 <= (int)param_3; param_3 = param_3 - 1) {
      iVar2 = param_1 + (param_3 >> 4) * 4;
      uVar1 = 0xffffffff;
      *(uint *)(iVar2 + 0x18) =
           (3 << 0x20 - ((param_3 & 0xf) * -2 + 0x20) ^ 0xffffffffU) & *(uint *)(iVar2 + 0x18) |
           param_4 << 0x20 - ((param_3 & 0xf) * -2 + 0x20);
      if (param_2 != param_3) {
        uVar1 = param_3 - 1 >> 4;
      }
      if (uVar3 != uVar1) {
        auStack_24[0] = *(undefined4 *)(param_1 + uVar3 * 4 + 0x18);
        memw();
        iVar2 = (**(code **)(**(int **)(param_1 + 0x50) + 0x14))
                          (*(int **)(param_1 + 0x50),*(int *)(param_1 + 8) + 0x20 + uVar3 * 4,
                           auStack_24,4);
        if (iVar2 != 0) {
          return iVar2;
        }
      }
      uVar3 = uVar1;
    }
    iVar2 = 0;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}



// Function at 0x400f7d04

undefined4 FUN_400f7d04(int param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_2 < 0x7e) {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x10))
                      (*(int **)(param_1 + 0x50),param_2 * 0x20 + 0x40 + *(int *)(param_1 + 8),
                       param_3,0x20);
  }
  return uVar1;
}



// Function at 0x400f7d2c

undefined4 FUN_400f7d2c(int param_1,uint param_2,uint *param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_2 < 0x7e) {
    *param_3 = *(uint *)(param_1 + (param_2 >> 4) * 4) >> ((param_2 & 0xf) << 1) & 3;
    uVar1 = 0;
  }
  memw();
  return uVar1;
}



// Function at 0x400f7d60

void FUN_400f7d60(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = param_1[1];
  if (iVar1 != 0) {
    *(int **)(iVar1 + 4) = param_2;
  }
  *param_2 = iVar1;
  param_2[1] = 0;
  param_1[1] = (int)param_2;
  if (*param_1 == 0) {
    *param_1 = (int)param_2;
  }
  param_1[2] = param_1[2] + 1;
  memw();
  return;
}



// Function at 0x400f7d84

void FUN_400f7d84(undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *param_2;
  piVar2 = (int *)param_2[1];
  if (iVar1 == 0) {
    *param_1 = piVar2;
    memw();
  }
  else {
    *(int **)(iVar1 + 4) = piVar2;
  }
  if (piVar2 == (int *)0x0) {
    param_1[1] = iVar1;
    memw();
  }
  else {
    *piVar2 = iVar1;
  }
  param_1[2] = param_1[2] + -1;
  memw();
  return;
}



// Function at 0x400f7db8

void FUN_400f7db8(void)

{
  return;
}



// Function at 0x400f7dc0

void FUN_400f7dc0(void)

{
  return;
}



// Function at 0x400f7dc8

void FUN_400f7dc8(void)

{
  return;
}



// Function at 0x400f7dd0

void FUN_400f7dd0(void)

{
  return;
}



// Function at 0x400f7dd8

undefined4 FUN_400f7dd8(void)

{
  return 0;
}



// Function at 0x400f7de0

undefined4 FUN_400f7de0(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



// Function at 0x400f7de8

undefined4 FUN_400f7de8(int param_1)

{
  return *(undefined4 *)(param_1 + 0x50);
}



// Function at 0x400f7df0

void FUN_400f7df0(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  memw();
  return;
}



// Function at 0x400f7dfc

void FUN_400f7dfc(int *param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  memw();
  if ((*(uint *)(*param_1 + (param_1[1] * 4 + param_2 + 0x28) * 8) & 0x2000000) == 0) {
    uVar1 = 3;
  }
  else if (param_1[1] == 1) {
    memw();
    uVar1 = 1;
    if ((*(uint *)(*param_1 + 400) & 1) == 0) {
      uVar1 = 2;
    }
  }
  else {
    uVar1 = 1;
  }
  *param_3 = uVar1;
  memw();
  return;
}



// Function at 0x400f7e3c

void FUN_400f7e3c(int *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if ((param_2 & 0xff) == 0) {
    memw();
    memw();
    *(uint *)(iVar2 + 0x50) = *(uint *)(iVar2 + 0x50) & 0xfffffff7;
    memw();
    uVar1 = *(uint *)(iVar2 + 0x54) & 0xfffffff7;
    memw();
  }
  else {
    memw();
    memw();
    *(uint *)(iVar2 + 0x50) = *(uint *)(iVar2 + 0x50) & 0xfffffff8 | param_2 & 7;
    memw();
    memw();
    *(uint *)(iVar2 + 0x54) = *(uint *)(iVar2 + 0x54) & 0xfffffff8 | param_2 & 7;
    memw();
    memw();
    *(uint *)(iVar2 + 0x50) = *(uint *)(iVar2 + 0x50) | 8;
    memw();
    uVar1 = *(uint *)(iVar2 + 0x54) | 8;
  }
  memw();
  *(uint *)(iVar2 + 0x54) = uVar1;
  memw();
  return;
}



// Function at 0x400f7eb8

void FUN_400f7eb8(int *param_1,byte *param_2)

{
  memw();
  *param_2 = (byte)*(undefined4 *)(*param_1 + 0x54) & 7;
  memw();
  memw();
  return;
}



// Function at 0x400f7ed4

void FUN_400f7ed4(int *param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(*param_1 + 0x24) = param_2;
  memw();
  return;
}



// Function at 0x400f7ee4

void FUN_400f7ee4(int *param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(*param_1 + 0x28) = (param_2 ^ 0xffffffff) & *(uint *)(*param_1 + 0x28);
  memw();
  return;
}



// Function at 0x400f7f00

void FUN_400f7f00(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  memw();
  memw();
  *(uint *)(iVar1 + 0x44) = *(uint *)(iVar1 + 0x44) & 0xfffffc00 | param_2 & 0x3ff;
  memw();
  memw();
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xfffffc00 | param_3 & 0x3ff;
  memw();
  return;
}



// Function at 0x400f7f38

void FUN_400f7f38(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  memw();
  memw();
  *(uint *)(iVar1 + 0x30) = *(uint *)(iVar1 + 0x30) & 0xfffffc00 | param_3 & 0x3ff;
  memw();
  memw();
  *(uint *)(iVar1 + 0x34) = *(uint *)(iVar1 + 0x34) & 0xfffffc00 | param_2 & 0x3ff;
  memw();
  return;
}



// Function at 0x400f7f6c

void FUN_400f7f6c(int *param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(*param_1 + 0x18) = *(uint *)(*param_1 + 0x18) & 0xfffffc1f | (param_2 & 0x1f) << 5;
  memw();
  return;
}



// Function at 0x400f7f90

void FUN_400f7f90(int *param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(*param_1 + 0x18) = *(uint *)(*param_1 + 0x18) & 0xffffffe0 | param_2 & 0x1f;
  memw();
  return;
}



// Function at 0x400f7fb0

uint FUN_400f7fb0(int *param_1)

{
  memw();
  return *(uint *)(*param_1 + 8) >> 4 & 1;
}



// Function at 0x400f7fc0

void FUN_400f7fc0(int *param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  memw();
  *param_3 = *(uint *)(iVar1 + 0x30) & 0x3ff;
  memw();
  *param_2 = *(uint *)(iVar1 + 0x34) & 0x3ff;
  memw();
  return;
}



// Function at 0x400f7fe0

void FUN_400f7fe0(int *param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  memw();
  *param_2 = *(uint *)(iVar1 + 0x44) & 0x3ff;
  memw();
  *param_3 = *(uint *)(iVar1 + 0x40) & 0x3ff;
  memw();
  return;
}



// Function at 0x400f8000

void FUN_400f8000(int *param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  memw();
  *param_2 = *(uint *)(iVar1 + 0x4c) & 0x3ff;
  memw();
  *param_3 = *(uint *)(iVar1 + 0x48) & 0x3fff;
  memw();
  return;
}



// Function at 0x400f8020

void FUN_400f8020(int *param_1)

{
  memw();
  memw();
  *(uint *)(*param_1 + 0x28) = *(uint *)(*param_1 + 0x28) | 0x81;
  memw();
  return;
}



// Function at 0x400f803c

void FUN_400f803c(int *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *param_1;
  if (param_2 == 3) {
    memw();
    memw();
    *(uint *)(iVar2 + 0x44) = *(uint *)(iVar2 + 0x44) | 4;
    memw();
    uVar1 = *(uint *)(iVar2 + 0x20) & 0xffffffcf;
    uVar3 = 0x10;
  }
  else {
    memw();
    memw();
    *(uint *)(iVar2 + 0x44) = *(uint *)(iVar2 + 0x44) & 0xfffffffb;
    uVar1 = (param_2 & 3) << 4;
    memw();
    uVar3 = *(uint *)(iVar2 + 0x20) & 0xffffffcf;
    memw();
  }
  memw();
  *(uint *)(iVar2 + 0x20) = uVar3 | uVar1;
  memw();
  return;
}



// Function at 0x400f80c4

void FUN_400f80c4(int *param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(*param_1 + 0x20) = *(uint *)(*param_1 + 0x20) & 0xfffffff3 | (param_2 & 3) << 2;
  memw();
  return;
}



// Function at 0x400f80e8

void FUN_400f80e8(int *param_1,uint *param_2)

{
  memw();
  *param_2 = *(uint *)(*param_1 + 0x20) >> 2 & 3;
  memw();
  return;
}



// Function at 0x400f80fc

void FUN_400f80fc(int *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (param_2 != 0) {
    memw();
    memw();
    *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0xfffffffe | param_2 & 1;
  }
  memw();
  memw();
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0xfffffffd | (param_2 >> 1 & 1) << 1;
  memw();
  return;
}



// Function at 0x400f8138

void FUN_400f8138(int *param_1,uint *param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  memw();
  if ((*(uint *)(*param_1 + 0x20) & 2) != 0) {
    memw();
    uVar1 = *(uint *)(*param_1 + 0x20) & 1 | 2;
  }
  *param_2 = uVar1;
  memw();
  return;
}



// Function at 0x400f815c

void FUN_400f815c(int *param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(*param_1 + 0x24) = *(uint *)(*param_1 + 0x24) & 0xffffff80 | param_2 & 0x7f;
  memw();
  return;
}



// Function at 0x400f817c

int FUN_400f817c(int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = *param_1;
  memw();
  memw();
  if ((*(uint *)(iVar2 + 0x44) & 4) != 0) {
    uVar4 = 3;
    memw();
    if ((*(uint *)(iVar2 + 0x20) >> 4 & 3) == 1) goto LAB_400f81a9;
  }
  memw();
  uVar4 = *(uint *)(iVar2 + 0x20) >> 4 & 3;
LAB_400f81a9:
  uVar1 = 0;
  memw();
  if ((*(uint *)(iVar2 + 0x20) & 2) != 0) {
    memw();
    uVar1 = *(uint *)(iVar2 + 0x20) & 1 | 2;
  }
  iVar3 = 2;
  if (uVar4 < 2) {
    iVar3 = 1;
  }
  return (*(uint *)(iVar2 + 0x20) >> 2 & 3) + 6 + (uint)(uVar1 != 0) + iVar3;
}



// Function at 0x400f81dc

void FUN_400f81dc(void)

{
  return;
}



// Function at 0x400f81e4

undefined4 FUN_400f81e4(uint *param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1[7] != 0) && (((*param_1 | param_1[1] | param_1[2]) & param_2) == param_2)) {
    uVar1 = 1;
  }
  return uVar1;
}



// Function at 0x400f820c

int FUN_400f820c(int *param_1,int *param_2)

{
  return *param_1 - *param_2;
}



// Function at 0x400f8218

undefined4 FUN_400f8218(void)

{
  return 0;
}



// Function at 0x400f8220

void FUN_400f8220(void)

{
  return;
}



// Function at 0x400f8228

undefined4 FUN_400f8228(undefined4 *param_1)

{
  *param_1 = 0x58;
  memw();
  return 0xffffffff;
}



// Function at 0x400f8238

void FUN_400f8238(void)

{
  return;
}



// Function at 0x400f8240

void FUN_400f8240(void)

{
  return;
}



// Function at 0x400f8248

undefined4 FUN_400f8248(void)

{
  return 0;
}



// Function at 0x400f8250

int FUN_400f8250(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    while( true ) {
      if (*param_1 == 0) break;
      iVar1 = iVar1 + (uint)*(ushort *)(*param_1 + 2);
      param_1 = param_1 + 1;
    }
  }
  return iVar1;
}



// Function at 0x400f8270

int FUN_400f8270(int param_1,int param_2)

{
  return param_1 / param_2 - ((param_1 % param_2 >> 0x1f) - param_1 % param_2 >> 0x1f);
}



// Function at 0x400f8288

void FUN_400f8288(void)

{
  waiti(0);
  return;
}



// Function at 0x400f8290

undefined4 FUN_400f8290(void)

{
  return 0x5e;
}



// Function at 0x400f8298

undefined4 FUN_400f8298(void)

{
  return 0x100;
}



// Function at 0x400f82a0

undefined4 FUN_400f82a0(void)

{
  return 4;
}



// Function at 0x400f82a8

undefined8 FUN_400f82a8(int param_1,int param_2)

{
  param_1 = param_1 << 0x1d;
  if (param_2 == 1) {
    param_2 = 0;
  }
  else if (param_2 == 0) {
    param_2 = 0xf;
    witlb(param_1,0xf);
    isync();
  }
  else {
    if (param_2 == 2) {
      param_2 = 3;
      witlb(param_1,3);
      isync();
      goto LAB_400f82b9;
    }
    if (param_2 != 3) goto LAB_400f82b9;
    param_2 = 2;
  }
  wdtlb(param_1,param_2);
  dsync();
LAB_400f82b9:
  return CONCAT44(param_2,param_1);
}



// Function at 0x400f82e4

void FUN_400f82e4(byte *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = 0;
  do {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = uVar2 | (bVar1 & 0x7f) << 0x20 - (0x20 - (uVar3 & 0x1f));
    uVar3 = uVar3 + 7;
  } while ((char)bVar1 < '\0');
  *param_2 = uVar2;
  return;
}



// Function at 0x400f830c

void FUN_400f830c(byte *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = 0;
  do {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = uVar2 | (bVar1 & 0x7f) << 0x20 - (0x20 - (uVar3 & 0x1f));
    uVar3 = uVar3 + 7;
  } while ((char)bVar1 < '\0');
  if ((uVar3 < 0x20) && ((bVar1 & 0x40) != 0)) {
    uVar2 = uVar2 | -1 << 0x20 - (0x20 - (uVar3 & 0x1f));
  }
  *param_2 = uVar2;
  return;
}



// Function at 0x400f8348

int FUN_400f8348(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *local_30 [12];
  
  local_30[0] = (undefined4 *)*param_3;
  iVar1 = (**(code **)(*param_2 + 8))(param_2);
  if (iVar1 != 0) {
    local_30[0] = (undefined4 *)*local_30[0];
  }
  iVar1 = (**(code **)(*param_1 + 0x10))(param_1,param_2,local_30,1);
  if (iVar1 != 0) {
    *param_3 = local_30[0];
  }
  return iVar1;
}



// Function at 0x400f837c

bool FUN_400f837c(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  bool bVar1;
  undefined4 local_30;
  uint uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_28 = 0x10;
  local_30 = 0;
  uStack_2c = 0;
  uStack_24 = 0;
  (**(code **)(*param_1 + 0x18))(param_1,param_2,*param_3,&local_30);
  bVar1 = (uStack_2c & 6) == 6;
  if (bVar1) {
    *param_3 = local_30;
  }
  return bVar1;
}



// Function at 0x400f83b0

undefined4
FUN_400f83b0(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  undefined4 uVar1;
  
  uVar1 = 6;
  if (param_5 != param_3) {
    uVar1 = 1;
  }
  return uVar1;
}



// Function at 0x400f83c4

void FUN_400f83c4(void)

{
  return;
}



// Function at 0x400f83cc

undefined4 FUN_400f83cc(void)

{
  return 0;
}



// Function at 0x400f83d4

void FUN_400f83d4(void)

{
  return;
}



// Function at 0x400f83dc

/* WARNING: Control flow encountered bad instruction data */

void FUN_400f83dc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// Function at 0x400f8438

void FUN_400f8438(undefined4 *param_1,undefined4 *param_2,uint param_3,int param_4)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  if (param_4 == 2) {
    if ((int)((int)param_1 + param_3 + ((uint)param_1 ^ 0xffffffff)) < 0) {
      param_3 = 1;
    }
    do {
      uVar1 = *(undefined1 *)param_1;
      *(undefined1 *)param_1 = *(undefined1 *)param_2;
      *(undefined1 *)param_2 = uVar1;
      param_1 = (undefined4 *)((int)param_1 + 1);
      param_2 = (undefined4 *)((int)param_2 + 1);
      param_3 = param_3 - 1;
    } while (param_3 != 0);
  }
  else {
    param_3 = param_3 >> 2;
    if ((int)(param_3 - 1) < 0) {
      param_3 = 1;
    }
    do {
      uVar2 = *param_1;
      *param_1 = *param_2;
      *param_2 = uVar2;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      param_3 = param_3 - 1;
    } while (param_3 != 0);
  }
  return;
}



// Function at 0x400f848c

undefined4 FUN_400f848c(undefined4 param_1,undefined4 param_2,undefined4 param_3,code *param_4)

{
  int iVar1;
  
  iVar1 = (*param_4)(param_1,param_2);
  if (iVar1 < 0) {
    iVar1 = (*param_4)(param_2);
    if (iVar1 < 0) {
      return param_2;
    }
    iVar1 = (*param_4)(param_1,param_3);
    if (iVar1 < 0) {
      return param_3;
    }
  }
  else {
    iVar1 = (*param_4)(param_2,param_3);
    if (0 < iVar1) {
      return param_2;
    }
    iVar1 = (*param_4)(param_1,param_3);
    if (-1 < iVar1) {
      return param_3;
    }
  }
  return param_1;
}



// Function at 0x400f84d0

void FUN_400f84d0(undefined4 *param_1,uint param_2,uint param_3,code *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  uint auStack_80 [17];
  code *pcStack_3c;
  undefined4 *puStack_38;
  undefined4 *puStack_34;
  undefined4 *puStack_30;
  undefined4 *puStack_2c;
  undefined4 *puStack_28;
  undefined4 *puStack_24;
  
  pcStack_3c = param_4;
  auStack_80[0x10] = 2;
  if ((((uint)param_1 | param_3) & 3) == 0) {
    auStack_80[0x10] = (uint)(param_3 != 4);
  }
  uVar8 = 0;
  do {
    while( true ) {
      puVar6 = (undefined4 *)((int)param_1 + param_3);
      puStack_30 = (undefined4 *)((int)param_1 + param_2 * param_3);
      if (6 < param_2) break;
      for (; puVar4 = puVar6, puVar6 < puStack_30; puVar6 = (undefined4 *)((int)puVar6 + param_3)) {
        while (param_1 < puVar4) {
          puVar3 = (undefined4 *)((int)puVar4 - param_3);
          iVar1 = (*pcStack_3c)(puVar3,puVar4);
          if (iVar1 < 1) break;
          if (auStack_80[0x10] == 0) {
            uVar9 = *puVar4;
            *puVar4 = *puVar3;
            *puVar3 = uVar9;
            puVar4 = puVar3;
          }
          else {
            FUN_400f8438(puVar4,puVar3,param_3,auStack_80[0x10]);
            puVar4 = puVar3;
          }
        }
      }
LAB_400f878b:
      if (uVar8 == 0) {
        return;
      }
LAB_400f8770:
      uVar8 = uVar8 - 1;
      param_2 = auStack_80[uVar8 * 2 + 1];
      param_1 = (undefined4 *)auStack_80[uVar8 * 2];
    }
    puVar3 = (undefined4 *)((int)param_1 + (param_2 >> 1) * param_3);
    puVar4 = (undefined4 *)((int)param_1 + (param_2 * param_3 - param_3));
    if (param_2 != 7) {
      puVar2 = puVar4;
      puVar12 = param_1;
      if (0x28 < param_2) {
        iVar1 = (param_2 >> 3) * param_3;
        puStack_28 = puVar3;
        puStack_24 = (undefined4 *)
                     FUN_400f848c(param_1,(undefined4 *)((int)param_1 + iVar1),
                                  (undefined4 *)((int)param_1 + iVar1 + iVar1),pcStack_3c);
        puStack_28 = (undefined4 *)
                     FUN_400f848c((int)puStack_28 - iVar1,puStack_28,
                                  (undefined4 *)((int)puStack_28 + iVar1),pcStack_3c);
        iVar10 = (int)puVar4 + iVar1 * -2;
        puVar2 = (undefined4 *)FUN_400f848c(iVar10,iVar10 + iVar1,puVar4,pcStack_3c);
        puVar3 = puStack_28;
        puVar12 = puStack_24;
      }
      puVar3 = (undefined4 *)FUN_400f848c(puVar12,puVar3,puVar2,pcStack_3c);
    }
    if (auStack_80[0x10] == 0) {
      uVar9 = *param_1;
      *param_1 = *puVar3;
      *puVar3 = uVar9;
    }
    else {
      FUN_400f8438(param_1,puVar3,param_3,auStack_80[0x10]);
    }
    puStack_34 = puVar4;
    puStack_38 = puVar6;
    puVar2 = (undefined4 *)0x0;
    for (puVar3 = puVar6; puVar3 <= puVar4; puVar3 = (undefined4 *)((int)puVar3 + param_3)) {
      puStack_28 = puVar2;
      iVar1 = (*pcStack_3c)(puVar3,param_1);
      puVar2 = puStack_28;
      if (iVar1 < 1) {
        if (iVar1 == 0) {
          if (auStack_80[0x10] == 0) {
            uVar9 = *puStack_38;
            *puStack_38 = *puVar3;
            *puVar3 = uVar9;
          }
          else {
            FUN_400f8438(puStack_38,puVar3,param_3,auStack_80[0x10]);
          }
          puStack_38 = (undefined4 *)((int)puStack_38 + param_3);
          goto LAB_400f8616;
        }
      }
      else {
        while( true ) {
          puStack_28 = puVar2;
          iVar1 = (*pcStack_3c)(puVar4,param_1);
          puStack_2c = (undefined4 *)((int)puVar4 - param_3);
          if (iVar1 < 0) break;
          puVar2 = puStack_28;
          if (iVar1 == 0) {
            if (auStack_80[0x10] == 0) {
              uVar9 = *puVar4;
              *puVar4 = *puStack_34;
              *puStack_34 = uVar9;
            }
            else {
              FUN_400f8438(puVar4,puStack_34,param_3,auStack_80[0x10]);
            }
            puVar2 = (undefined4 *)0x1;
            puStack_34 = (undefined4 *)((int)puStack_34 - param_3);
          }
          puVar4 = puStack_2c;
          if (puStack_2c < puVar3) goto LAB_400f866a;
        }
        if (auStack_80[0x10] == 0) {
          uVar9 = *puVar3;
          *puVar3 = *puVar4;
          *puVar4 = uVar9;
          puVar4 = puStack_2c;
        }
        else {
          FUN_400f8438(puVar3,puVar4,param_3,auStack_80[0x10]);
          puVar4 = puStack_2c;
        }
LAB_400f8616:
        puVar2 = (undefined4 *)0x1;
      }
    }
LAB_400f866a:
    if (puVar2 == (undefined4 *)0x0) {
      for (; puVar4 = puVar6, puVar6 < puStack_30; puVar6 = (undefined4 *)((int)puVar6 + param_3)) {
        while (param_1 < puVar4) {
          puVar3 = (undefined4 *)((int)puVar4 - param_3);
          iVar1 = (*pcStack_3c)(puVar3,puVar4);
          if (iVar1 < 1) break;
          if (auStack_80[0x10] == 0) {
            uVar9 = *puVar4;
            *puVar4 = *puVar3;
            *puVar3 = uVar9;
            puVar4 = puVar3;
          }
          else {
            FUN_400f8438(puVar4,puVar3,param_3,auStack_80[0x10]);
            puVar4 = puVar3;
          }
        }
      }
      goto LAB_400f878b;
    }
    uVar7 = (int)puVar3 - (int)puStack_38;
    iVar1 = (int)puStack_38 - (int)param_1;
    iVar1 = (uint)(iVar1 < (int)uVar7) * iVar1 + (iVar1 >= (int)uVar7) * uVar7;
    if (iVar1 != 0) {
      FUN_400f8438(param_1,(int)puVar3 - iVar1,iVar1,auStack_80[0x10]);
    }
    uVar5 = (int)puStack_34 - (int)puVar4;
    uVar11 = (int)puStack_30 + (-param_3 - (int)puStack_34);
    iVar1 = (uVar11 < uVar5) * uVar11 + (uVar11 >= uVar5) * uVar5;
    if (iVar1 != 0) {
      FUN_400f8438(puVar3,(int)puStack_30 - iVar1,iVar1,auStack_80[0x10]);
    }
    puVar6 = param_1;
    param_2 = uVar5;
    puVar4 = (undefined4 *)((int)puStack_30 - uVar5);
    if (uVar7 < uVar5) {
      puVar6 = (undefined4 *)((int)puStack_30 - uVar5);
      param_2 = uVar7;
      uVar7 = uVar5;
      puVar4 = param_1;
    }
    if (param_2 <= param_3) {
      if (param_3 < uVar7) goto LAB_400f8780;
      goto LAB_400f878b;
    }
    param_2 = param_2 / param_3;
    if (uVar8 < 8) {
      auStack_80[uVar8 * 2] = (uint)puVar6;
      auStack_80[uVar8 * 2 + 1] = uVar7 / param_3;
      uVar8 = uVar8 + 1;
      param_1 = puVar4;
    }
    else {
      FUN_400f84d0(puVar4,param_2,param_3,pcStack_3c);
      if (uVar7 <= param_3) goto LAB_400f8770;
LAB_400f8780:
      param_2 = uVar7 / param_3;
      param_1 = puVar6;
    }
  } while( true );
}



// Function at 0x400f879c

void FUN_400f879c(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  
  memw();
  memw();
  *DAT_400d1610 = *DAT_400d1610 & DAT_400d1614;
  puVar2 = DAT_400d1618;
  memw();
  memw();
  *DAT_400d1618 = (param_1 >> 0x10) << 0x18 | *DAT_400d1618 & DAT_400d0258;
  memw();
  memw();
  *puVar2 = (param_1 >> 8 & 0xff) << 0xe | *puVar2 & DAT_400d161c;
  memw();
  memw();
  *puVar2 = (param_1 & 0xff) << 6 | *puVar2 & DAT_400d1620;
  puVar2 = DAT_400d1624;
  memw();
  memw();
  *DAT_400d1624 = *DAT_400d1624 | DAT_400d1628;
  memw();
  memw();
  *puVar2 = *puVar2 | DAT_400d029c;
  puVar2 = DAT_400d162c;
  memw();
  memw();
  *DAT_400d162c = *DAT_400d162c & DAT_400d1630 | DAT_400d0c5c;
  uVar5 = DAT_400d0598;
  memw();
  memw();
  *puVar2 = *puVar2 & DAT_400d1634 | DAT_400d0598;
  puVar2 = DAT_400d1638;
  if ((param_1 & uVar5) != 0) {
    memw();
    uVar4 = func_0x40084644(DAT_400d1638);
    uVar5 = DAT_400d0430;
    memw();
    *puVar2 = uVar4 & DAT_400d0430;
    puVar2 = DAT_400d163c;
    memw();
    uVar4 = func_0x40084644(DAT_400d163c);
    puVar1 = DAT_400d1640;
    memw();
    *puVar2 = uVar4 & uVar5;
    memw();
    uVar5 = func_0x40084644(puVar1);
    memw();
    *puVar1 = uVar5 & 0xffffff03;
    memw();
    uVar5 = func_0x40084644(puVar1);
    memw();
    *puVar1 = uVar5 & 0xfffffffd;
    memw();
    uVar5 = func_0x40084644(puVar1);
    memw();
    *puVar1 = uVar5 & 0xfffffffe;
    puVar3 = DAT_400d1644;
    memw();
    func_0x40084644(DAT_400d1644);
    memw();
    *puVar3 = 0;
    puVar2 = DAT_400d1648;
    memw();
    uVar5 = func_0x40084644(DAT_400d1648);
    memw();
    *puVar2 = uVar5 & 0xfffffffe;
    puVar2 = DAT_400d164c;
    memw();
    uVar5 = func_0x40084644(DAT_400d164c);
    memw();
    *puVar2 = uVar5 & 0xfffffeff;
    memw();
    uVar5 = func_0x40084644(puVar2);
    memw();
    *puVar2 = uVar5 & 0xfffffffe;
  }
  puVar2 = DAT_400d1654;
  if ((param_1 & 0x2000000) != 0) {
    memw();
    memw();
    *DAT_400d1650 = *DAT_400d1650 & DAT_400d0270;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_400d06d4;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_400d0c58;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_400d0c4c;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_400d0a6c;
    memw();
    memw();
    *puVar2 = *puVar2 | DAT_400d0608;
    memw();
    memw();
    *puVar2 = *puVar2 | DAT_400d0604;
    memw();
    memw();
    *puVar2 = *puVar2 | DAT_400d0134;
    puVar1 = DAT_400d1610;
    memw();
    memw();
    *DAT_400d1610 = *DAT_400d1610 & DAT_400d059c;
    memw();
    memw();
    *puVar1 = *puVar1 | DAT_400d05f8;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_400d0430;
    memw();
    memw();
    *puVar2 = *puVar2 & 0xfffffdff;
    puVar2 = DAT_400d162c;
    memw();
    memw();
    *DAT_400d162c = *DAT_400d162c & DAT_400d0140;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_400d0268;
    if ((param_1 & 0x4000000) == 0) {
      memw();
      uVar5 = *puVar2 & DAT_400d165c;
    }
    else {
      memw();
      uVar5 = *puVar2 | DAT_400d1658;
    }
    memw();
    *puVar2 = uVar5;
    puVar2 = DAT_400d1660;
    memw();
    memw();
    *DAT_400d1660 = *DAT_400d1660 & 0xffffffef;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_400d0c50;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_400d0c68;
    puVar1 = DAT_400d1668;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_400d1664;
    memw();
    memw();
    *puVar1 = *puVar1 & DAT_400d166c;
    puVar2 = DAT_400d1670;
    memw();
    memw();
    *puVar1 = *puVar1 & DAT_400d0c4c;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_400d0140;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_400d0268;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_400d1674;
    memw();
    memw();
    *puVar1 = *puVar1 & 0xfffffffa;
    memw();
    memw();
    *puVar1 = *puVar1 & 0xffffffdf;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_400d06dc;
    memw();
    memw();
    *puVar2 = *puVar2 & DAT_400d06d0;
  }
  memw();
  memw();
  *DAT_400d1670 = *DAT_400d1670 | DAT_400d1658;
  memw();
  memw();
  *DAT_400d1660 = *DAT_400d1660 | DAT_400d0604;
  memw();
  *DAT_400d06ac = 0;
  memw();
  *DAT_400d06a4 = 0xffffffff;
  memw();
  return;
}



// Function at 0x400f8b38

undefined4 FUN_400f8b38(int param_1)

{
  undefined4 uVar1;
  
  if (*DAT_400d1678 == param_1) {
    uVar1 = 0x103;
  }
  else if (*DAT_400d1678 == 0) {
    *DAT_400d1678 = param_1;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x101;
  }
  memw();
  return uVar1;
}



// Function at 0x400f8b7c

void FUN_400f8b7c(void)

{
  uint uVar1;
  int *piVar2;
  int *in_t0;
  undefined1 in_PRID;
  
  uVar1 = rsr(in_PRID);
  piVar2 = DAT_400d167c;
  if ((uVar1 >> 0xd & 1) < 2) goto LAB_400f8b91;
  do {
    piVar2 = in_t0;
    func_0x4008da40();
    in_t0 = piVar2;
LAB_400f8b91:
    do {
      memw();
    } while (*piVar2 == 0);
    FUN_400dfee4();
    FUN_400dfcf4();
    func_0x4008b524();
  } while( true );
}



// Function at 0x400f8c28

void FUN_400f8c28(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = DAT_400d1698;
  if (param_3 == 0) {
    uVar1 = DAT_400d169c;
  }
  FUN_400ea694(DAT_400d16a0,param_1,uVar1,param_2,param_1 + -8);
  return;
}



// Function at 0x400f8c48

void FUN_400f8c48(int param_1,code *param_2,undefined4 param_3)

{
  uint uVar1;
  
  if (param_2 == (code *)0x0) {
    param_2 = (code *)PTR_FUN_400d16a4;
  }
  param_1 = param_1 + -4;
  while( true ) {
    if (param_1 == 0) {
      return;
    }
    uVar1 = *(uint *)(param_1 + 4) & 0xfffffffc;
    if (uVar1 == 0) break;
    (*param_2)(param_1 + 8,uVar1,(*(uint *)(param_1 + 4) ^ 0xffffffff) & 1,param_3);
    param_1 = param_1 + 8 + (*(uint *)(param_1 + 4) & 0xfffffffc) + -4;
  }
  return;
}



// Function at 0x400f8c80

uint FUN_400f8c80(int param_1,uint param_2)

{
  if ((param_2 == 0) || (param_1 == 0)) {
    param_2 = 0;
  }
  else {
    param_2 = -((int)(DAT_400d0284 >> (LZCOUNT(param_2) & 0x1fU)) /
               (int)(*(uint *)(param_1 + 0x10) >> 0xe & 0x3f)) & param_2;
  }
  return param_2;
}



// Function at 0x400f8cac

uint * FUN_400f8cac(uint param_1,uint *param_2,int param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  uint *extraout_a3;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  undefined4 uVar7;
  uint *puVar8;
  int iVar9;
  undefined4 uVar10;
  uint in_t0;
  
  uVar3 = param_3 - 8U & 0xfffffffc;
  if (((uint)param_2 & 3) == 0) {
    uVar1 = func_0x4008cc64(param_1);
    if ((0xb < uVar3) && (uVar3 <= uVar1)) {
      puVar8 = param_2 + -1;
      *param_2 = *param_2 & 1 | uVar3 | 1;
      uVar5 = *(uint *)(param_1 + 0x10);
      uVar4 = uVar5 >> 0x17 & 0xff;
      uVar1 = 0;
      if (uVar4 <= uVar3) goto LAB_400f8d3b;
      uVar3 = (int)uVar3 / (int)(uVar4 / (uVar5 >> 0xe & 0x3f));
      uVar4 = 0;
      do {
        iVar9 = *(int *)(param_1 + 0x20);
        uVar5 = *(uint *)(iVar9 + ((uVar5 >> 0xe & 0x3f) * uVar4 + uVar3) * 4);
        if (uVar5 == 0) {
          uVar7 = 0xe9;
          uVar10 = DAT_400d16b0;
        }
        else {
          puVar8[2] = uVar5;
          puVar8[3] = param_1;
          *(uint **)(uVar5 + 0xc) = puVar8;
          if (puVar8 + 2 == (uint *)((int)puVar8 + 0xbU & 0xfffffffc)) {
            uVar1 = *(uint *)(param_1 + 0x18);
            *(uint **)(iVar9 + ((*(uint *)(param_1 + 0x10) >> 0xe & 0x3f) * uVar4 + uVar3) * 4) =
                 puVar8;
            *(uint *)(param_1 + 0x18) = uVar1 | 1 << 0x20 - (0x20 - (uVar4 & 0x1f));
            puVar6 = (uint *)(*(int *)(param_1 + 0x1c) + uVar4 * 4);
            *puVar6 = *puVar6 | 1 << 0x20 - (0x20 - (uVar3 & 0x1f));
            puVar2 = (undefined4 *)((puVar8[1] & 0xfffffffc) + (int)(puVar8 + 2));
            puVar2[-1] = puVar8;
            *puVar2 = 2;
            memw();
            return param_2;
          }
          uVar7 = 0xef;
          memw();
          uVar10 = DAT_400d16bc;
        }
        memw();
        uVar5 = in_t0;
        func_0x4008dacc(DAT_400d16b8,uVar7,DAT_400d16b4,uVar10);
        uVar3 = uVar5;
        puVar8 = extraout_a3;
        in_t0 = uVar5;
LAB_400f8d3b:
        uVar4 = uVar1;
        if (uVar3 != 0) {
          uVar4 = 0x20 - LZCOUNT(uVar3);
        }
        uVar1 = (uVar4 - 1) - (uVar5 >> 0x14 & 7);
        uVar3 = uVar3 >> (uVar1 & 0x1f) ^ 1 << 0x20 - (0x20 - (uVar5 >> 0x14 & 7));
        uVar4 = uVar4 - (uVar5 >> 5 & 7);
      } while( true );
    }
    FUN_400ea694(DAT_400d16ac,0x14,uVar1 + 8);
  }
  else {
    FUN_400ea694(DAT_400d16a8,4);
  }
  return (uint *)0x0;
}



// Function at 0x400f8dd8

uint FUN_400f8dd8(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  uint in_t0;
  
  uVar2 = DAT_400d0134;
  if (param_1 != 0) {
    if ((param_1 & 3) == 0) {
      if (0x23 < param_2) {
        uVar4 = 0x20U - LZCOUNT(param_2) & 0xff;
        uVar1 = *(uint *)(param_1 + 0x10) & DAT_400d16c4 | (0x20U - LZCOUNT(param_2) & 0x3f) << 8;
        *(uint *)(param_1 + 0x10) = uVar1;
        uVar3 = DAT_400d16c8;
        if (param_2 <= uVar2) {
          uVar3 = uVar1 & DAT_400d16c8;
          uVar2 = DAT_400d16cc;
          uVar1 = in_t0;
          goto LAB_400f8e29;
        }
        while( true ) {
          uVar3 = uVar1 & uVar3;
          uVar2 = DAT_400d16d0;
          uVar1 = in_t0;
          if (param_2 <= DAT_400d0260) {
            uVar2 = DAT_400d0610;
          }
LAB_400f8e29:
          *(uint *)(param_1 + 0x10) = uVar3 | uVar2;
          uVar2 = *(uint *)(param_1 + 0x10) >> 0x14;
          uVar3 = (uVar2 & 7) + 2;
          uVar7 = 1 << 0x20 - (0x20 - (uVar2 & 7));
          uVar8 = uVar7 & 0x3f;
          uVar7 = uVar7 & 0x3f;
          uVar2 = uVar4 + (1 - (uVar3 & 7)) & 0x1f;
          uVar4 = 1 << 0x20 - (0x20 - (uVar3 & 7));
          *(uint *)(param_1 + 0x10) =
               ((*(uint *)(param_1 + 0x10) & 0xffffff1f | (uVar3 & 7) << 5) & DAT_400d16d4 &
                0xffffffe0 | uVar7 << 0xe | uVar2) & DAT_400d16d8 | (uVar4 & 0xff) << 0x17;
          iVar5 = (uVar2 + 9 + uVar2 * uVar8) * 4;
          *(int *)(param_1 + 0x14) = iVar5;
          if (param_2 < iVar5 + 0xcU) break;
          uVar3 = param_1 + 0x27 & 0xfffffffc;
          iVar5 = uVar3 + uVar2 * 4;
          iVar6 = 0;
          *(uint *)(param_1 + 8) = param_1;
          *(uint *)(param_1 + 0xc) = param_1;
          *(undefined4 *)(param_1 + 0x18) = 0;
          *(uint *)(param_1 + 0x1c) = uVar3;
          *(int *)(param_1 + 0x20) = iVar5;
          if (uVar7 < 0x21) {
            if ((int)uVar4 / (int)uVar8 == 4) {
              for (; iVar6 < (int)(*(uint *)(param_1 + 0x10) & 0x1f); iVar6 = iVar6 + 1) {
                *(undefined4 *)(iVar6 * 4 + uVar3) = 0;
                iVar10 = 0;
                while (uVar2 = *(uint *)(param_1 + 0x10) >> 0xe & 0x3f, iVar10 < (int)uVar2) {
                  *(uint *)(iVar5 + (iVar6 * uVar2 + iVar10) * 4) = param_1;
                  iVar10 = iVar10 + 1;
                  memw();
                }
              }
              memw();
              return param_1;
            }
            uVar9 = 0x1fe;
            uVar11 = DAT_400d16e4;
          }
          else {
            uVar9 = 0x1fb;
            uVar11 = DAT_400d16dc;
          }
          memw();
          uVar3 = func_0x4008dacc(DAT_400d16b8,uVar9,DAT_400d16e0,uVar11);
          param_2 = 0x20;
          uVar4 = uVar1;
          in_t0 = uVar1;
        }
      }
    }
    else {
      FUN_400ea694(DAT_400d16c0,4);
    }
  }
  return 0;
}



// Function at 0x400f8f34

int FUN_400f8f34(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    param_3 = param_2;
  }
  iVar1 = FUN_400f8dd8(param_1,param_3);
  if (iVar1 != 0) {
    FUN_400f8cac(iVar1,param_1 + *(int *)(iVar1 + 0x14),param_2 - *(int *)(iVar1 + 0x14));
  }
  return iVar1;
}



// Function at 0x400f8f58

undefined4 * FUN_400f8f58(undefined4 *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    func_0x4008dacc(DAT_400d16f0,0x6f,DAT_400d16ec,DAT_400d16e8);
  }
  if (0x13 < param_2) {
    iVar2 = param_2 - 0x14;
    iVar1 = FUN_400f8f34(param_1 + 5,iVar2,0);
    param_1[4] = iVar1;
    if (iVar1 != 0) {
      *param_1 = 0;
      memw();
      iVar1 = func_0x4008d620();
      param_1[1] = iVar2 - iVar1;
      param_1[3] = iVar2;
      param_1[2] = iVar2 - iVar1;
      memw();
      return param_1;
    }
  }
  return (undefined4 *)0x0;
}



// Function at 0x400f8fa8

void FUN_400f8fa8(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  func_0x40086818(param_2,0,0x1c);
  if (param_1 != 0) {
    func_0x4008d6b0(param_1);
    uVar1 = func_0x4008cf70(*(undefined4 *)(param_1 + 0x10));
    FUN_400f8c48(uVar1,PTR_FUN_400d16f4,param_2);
    iVar6 = param_2[4];
    iVar2 = func_0x4008cc44();
    iVar4 = *(int *)(param_1 + 0xc);
    iVar3 = func_0x4008d620(*(undefined4 *)(param_1 + 0x10));
    iVar7 = *(int *)(param_1 + 4);
    iVar5 = *(int *)(param_1 + 8);
    param_2[1] = ((iVar4 - iVar7) - iVar3) - iVar6 * iVar2;
    uVar1 = *(undefined4 *)(param_1 + 0x10);
    param_2[3] = iVar5;
    *param_2 = iVar7;
    memw();
    iVar2 = FUN_400f8c80(uVar1,param_2[2]);
    param_2[2] = iVar2;
    memw();
    func_0x4008d6c0(param_1);
  }
  return;
}



// Function at 0x400f9004

void FUN_400f9004(undefined4 param_1,uint param_2,int param_3,int param_4)

{
  if (param_3 == 0) {
    *(int *)(param_4 + 0x14) = *(int *)(param_4 + 0x14) + 1;
    if (*(uint *)(param_4 + 8) < param_2) {
      *(uint *)(param_4 + 8) = param_2;
      memw();
    }
  }
  else {
    *(int *)(param_4 + 0x10) = *(int *)(param_4 + 0x10) + 1;
  }
  *(int *)(param_4 + 0x18) = *(int *)(param_4 + 0x18) + 1;
  memw();
  return;
}



// Function at 0x400f9030

undefined4 FUN_400f9030(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_400f8f58(param_1,param_2);
  return uVar1;
}



// Function at 0x400f9044

void FUN_400f9044(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  
  FUN_400f8fa8(param_1,param_2);
  param_2[1] = param_2[1] + param_2[4] * -0xc;
  uVar1 = 0;
  if (0xc < param_2[2]) {
    uVar1 = param_2[2] - 0xc;
  }
  param_2[2] = uVar1;
  uVar1 = 0;
  if (0xc < *param_2) {
    uVar1 = *param_2 - 0xc;
  }
  *param_2 = uVar1;
  uVar1 = 0;
  if (0xc < param_2[3]) {
    uVar1 = param_2[3] - 0xc;
  }
  param_2[3] = uVar1;
  memw();
  return;
}



// Function at 0x400f9090

void FUN_400f9090(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  iVar1 = DAT_400d16f8;
  while (param_1 < 0xf) {
    iVar5 = param_1 * 2 + 1;
    iVar3 = param_1 * 2 + 2;
    if (*(uint *)(iVar1 + iVar3 * 8 + 4) >> 3 <= *(uint *)(iVar1 + iVar5 * 8 + 4) >> 3) {
      iVar5 = iVar3;
    }
    puVar4 = (undefined4 *)(iVar1 + iVar5 * 8);
    puVar2 = (undefined4 *)(iVar1 + param_1 * 8);
    uVar8 = puVar4[1];
    uVar7 = *puVar2;
    uVar6 = puVar2[1];
    *puVar2 = *puVar4;
    puVar2[1] = uVar8;
    *puVar4 = uVar7;
    puVar4[1] = uVar6;
    memw();
    param_1 = iVar5;
  }
  return;
}



// Function at 0x400f90e4

uint FUN_400f90e4(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  piVar2 = DAT_400d16fc;
  piVar1 = DAT_400d16f8;
  iVar6 = *DAT_400d16fc;
  piVar3 = DAT_400d16f8;
  for (iVar8 = 0; piVar4 = DAT_400d170c, iVar8 != iVar6; iVar8 = iVar8 + 1) {
    if ((iVar8 != 0) &&
       ((uint)piVar1[iVar8 * 2 + 1] >> 3 <= (uint)piVar1[(iVar8 - 1U & 0xfffffffe) + 1] >> 3)) {
      iVar8 = func_0x4008dacc(DAT_400d1708,0xdc,DAT_400d1704,DAT_400d1700);
    }
    if (param_1 == *piVar3) {
      uVar5 = piVar1[iVar8 * 2 + 1] & 7;
      if (iVar6 == 0x1f) {
        iVar6 = *DAT_400d1710;
        *DAT_400d1710 = iVar6 + 1;
        piVar1[iVar8 * 2 + 1] = piVar1[iVar8 * 2 + 1] & 7U | iVar6 << 3;
        memw();
        FUN_400f9090();
      }
      goto LAB_400f9173;
    }
    piVar3 = piVar3 + 2;
  }
  do {
    piVar4 = (int *)*piVar4;
    if (piVar4 == (int *)0x0) {
      uVar5 = *DAT_400d0920;
      goto LAB_400f9189;
    }
    iVar8 = func_0x40086a70(param_1,(int)piVar4 + 5);
  } while (iVar8 != 0);
  uVar5 = (uint)*(byte *)(piVar4 + 1);
LAB_400f9189:
  uVar7 = *DAT_400d1710 << 3;
  *DAT_400d1710 = *DAT_400d1710 + 1;
  if (iVar6 == 0x1f) {
    *piVar1 = param_1;
    piVar1[1] = uVar5 & 7 | uVar7;
    memw();
    FUN_400f9090(0);
  }
  else {
    piVar1[iVar6 * 2] = param_1;
    (piVar1 + iVar6 * 2)[1] = uVar5 & 7 | uVar7;
    *piVar2 = iVar6 + 1;
  }
  *DAT_400d1714 = *DAT_400d1714 + 1;
  memw();
LAB_400f9173:
  func_0x4008d9dc();
  return uVar5;
}



// Function at 0x400f91d0

void FUN_400f91d0(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  
  func_0x4008d980();
  iVar1 = func_0x40086a70(param_1,DAT_400d1718);
  piVar3 = DAT_400d170c;
  if (iVar1 == 0) {
    *DAT_400d0920 = param_2;
    while (piVar6 = (int *)*piVar3, piVar6 != (int *)0x0) {
      *piVar3 = *piVar6;
      memw();
      func_0x4008dbfc();
    }
    *DAT_400d16fc = 0;
    *DAT_400d1710 = 0;
    *DAT_400d1714 = 0;
LAB_400f91fd:
    memw();
    func_0x4008d9dc();
    return;
  }
  piVar6 = (int *)*DAT_400d170c;
  iVar1 = (int)piVar6;
  do {
    if (piVar6 == (int *)0x0) {
      iVar2 = func_0x40086c6c(param_1);
      piVar6 = (int *)func_0x4008dbdc(iVar2 + 6);
      if (piVar6 == (int *)0x0) goto LAB_400f91fd;
      *(char *)(piVar6 + 1) = (char)param_2;
      memw();
      memw();
      func_0x400866b8((int)piVar6 + 5,param_1,iVar2 + 1);
      *piVar6 = iVar1;
      *piVar3 = (int)piVar6;
      memw();
LAB_400f925c:
      iVar1 = DAT_400d16f8;
      piVar5 = (int *)*DAT_400d16fc;
      piVar6 = (int *)0x0;
      while( true ) {
        if (piVar5 == piVar6) goto LAB_400f91fd;
        piVar3 = (int *)((int)piVar6 * 8);
        if ((piVar6 != (int *)0x0) &&
           (*(uint *)((int)piVar3 + iVar1 + 4) >> 3 <=
            *(uint *)(iVar1 + ((int)piVar6 - 1U >> 1) * 8 + 4) >> 3)) break;
        puVar4 = (undefined4 *)(iVar1 + (int)piVar3);
        iVar2 = func_0x40086a70(*puVar4,param_1);
        if (iVar2 == 0) {
          puVar4[1] = puVar4[1] & 0xfffffff8 | param_2 & 7;
          memw();
          goto LAB_400f91fd;
        }
        piVar6 = (int *)((int)piVar6 + 1);
      }
      memw();
      func_0x4008dacc(DAT_400d1708,0x86,DAT_400d171c,DAT_400d1700);
    }
    else {
      iVar2 = func_0x40086a70((int)piVar6 + 5,param_1);
      if (iVar2 == 0) {
        *(char *)(piVar6 + 1) = (char)param_2;
        memw();
        goto LAB_400f925c;
      }
    }
    piVar6 = (int *)*piVar6;
  } while( true );
}



// Function at 0x400f92c8

void FUN_400f92c8(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  uint uVar2;
  
  memw();
  iVar1 = func_0x4008d9a8();
  if ((iVar1 != 0) && (uVar2 = FUN_400f90e4(param_2), param_1 <= uVar2)) {
    (*(code *)*DAT_400d1720)(param_3,param_4,param_5,param_6);
  }
  return;
}



// Function at 0x400f92f8

void FUN_400f92f8(void)

{
  do {
    ill();
  } while( true );
}



