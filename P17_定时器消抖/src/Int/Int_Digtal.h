#ifndef __INT_DIGTAL_H__
#define __INT_DIGTAL_H__
#include "STC89C5XRC.H"

#define SMG_EN P36
#define LED_EN P34

// 将待显示的数字加载到缓存
void Int_Digtal_SetCache(unsigned long num);

// 将缓存中的数字刷写到数码管
void Int_Digtal_FlushDigtal();

void Int_Digtal_Init();

void Int_Digtal_Callback();

#endif