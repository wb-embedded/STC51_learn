#ifndef __INT_MATRIXLED_H__
#define __INT_MATRIXLED_H__

#include "STC89C5xRC.H"

#define SER P10
#define RCK P11
#define SCK P12
#define LED_MATRIX_EN P35
#define LED_EN        P34

void Int_MatrixLed_SetCache(unsigned char *pics);
void Int_MatrixLed_Flush();

#endif