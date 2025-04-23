#ifndef __INT_MATRIXLED_H__
#define __INT_MATRIXLED_H__

#include "STC89C5xRC.H"
#include "Dri_Timer0.h"

#define MATRIXLED_EN P35 // �͵�ƽ��Ч
#define LED_EN       P34 // �ߵ�ƽ��Ч
#define SER          P10
#define RCK          P11
#define SCK          P12

void Int_MatrixLED_Init();
void Int_MatrixLED_SetPics(unsigned char *pics);

#endif