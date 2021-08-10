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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  beginPCF();
  writePCF(0xff);
  uint8_t val8 = readPCF();
  Serial.println("P0 P1 P2 P3");
  Serial.printf(" %d  %d  %d  %d\n", 1 & (val8 >> 0), 1 & (val8 >> 1), 1 & (val8 >> 2), 1 & (val8 >> 3));
}

void loop() {
  // put your main code here, to run repeatedly:
  writePCF(PCF_P4, HIGH);
  writePCF(PCF_P5, LOW);
  writePCF(PCF_P6, HIGH);
  writePCF(PCF_P7, LOW);
  delay(1000);
  writePCF(PCF_P4, LOW);
  writePCF(PCF_P5, HIGH);
  writePCF(PCF_P6, LOW);
  writePCF(PCF_P7, HIGH);
  delay(1000);

  writePCF(PCF_P0, HIGH);
  writePCF(PCF_P1, HIGH);
  writePCF(PCF_P2, HIGH);
  writePCF(PCF_P3, HIGH);
  Serial.println("P0 P1 P2 P3");
  Serial.printf(" %d  %d  %d  %d\n", readPCF(PCF_P0), readPCF(PCF_P1), readPCF(PCF_P2), readPCF(PCF_P3));
}
