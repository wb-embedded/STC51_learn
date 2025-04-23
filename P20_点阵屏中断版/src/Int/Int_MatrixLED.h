#ifndef __INT_MATRIXLED_H__
#define __INT_MATRIXLED_H__

#include "STC89C5xRC.H"

#define MATRIXLED_EN P35 // 低电平有效
#define LED_EN       P36 // 高电平有效

void Int_MatrixLED_Init();

#endif