//
// Copyright (c) 2021 Fw-Box (https://fw-box.com)
// Author: Hartman Hsieh
//
// Description :
//   
// Required Library :
//

#ifndef __FWBOX_PCF8574_H__
#define __FWBOX_PCF8574_H__

#include <Arduino.h>
#include <Wire.h>

#define PCF_P0 0
#define PCF_P1 1
#define PCF_P2 2
#define PCF_P3 3
#define PCF_P4 4
#define PCF_P5 5
#define PCF_P6 6
#define PCF_P7 7

void beginPCF();
void beginPCF(uint8_t address);
void writePCF(uint8_t val);
void writePCF(int pin, int val);
int readPCF();
int readPCF(int pin);

#endif // __FWBOX_PCF8574_H__
