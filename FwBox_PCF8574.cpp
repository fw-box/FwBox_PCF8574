//
// Copyright (c) 2021 Fw-Box (https://fw-box.com)
// Author: Hartman Hsieh
//
// Description :
//   
//
// Required Library :
//

#include "FwBox_PCF8574.h"


uint8_t PCFAddress = 0x20;

void beginPCF()
{
  beginPCF(0x20);
}

void beginPCF(uint8_t address)
{
  PCFAddress = address;
  Wire.begin();
}

void writePCF(uint8_t val)
{
  Wire.beginTransmission(PCFAddress);
  Wire.write(val);
  Wire.endTransmission();
}

void writePCF(int pin, int val)
{
  int datai = readPCF();
  if (datai == -1)
    return;

  uint8_t data8 = (uint8_t)datai;
  uint8_t new_data = data8;

  if (pin < 0 && pin >= 8) {
    return;
  }

  if (val) {
    new_data = data8 | ((uint8_t)(1 << pin));
  }
  else {
    new_data = data8 & (~((uint8_t)(1 << pin)));
  }

  writePCF(new_data);
}

int readPCF()
{
  if (Wire.requestFrom((uint8_t)PCFAddress, (uint8_t)1) != 1) {
    return -1;
  }
  return (uint8_t)Wire.read();
}

int readPCF(int pin)
{
  int datai = readPCF();
  if (datai == -1)
    return -1;

  uint8_t data8 = (uint8_t)datai;

  if (pin < 0 && pin >= 8) {
    return -1;
  }

  if (data8 & ((uint8_t)(1 << pin)))
    return 1;
  else
    return 0;
}
