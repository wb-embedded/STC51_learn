#ifndef __INT_MATRIXLED_H__
#define __INT_MATRIXLED_H__

#include "STC89C5xRC.H"

#define MATRIX_LED_EN P35
#define LED_EN        P34
#define SER           P10
#define RCK           P11
#define SCK           P12

void Int_MatrixLed_Flush();

void Int_MatrixLed_Move(unsigned char pics);

#endif