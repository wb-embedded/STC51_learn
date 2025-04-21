#ifndef __INT_DIGTAL_H__
#define __INT_DIGTAL_H__
#include "STC89C5XRC.H"
#include "Dri_Timer0.h"

#define SMG_EN P36
#define LED_EN P34

//������ʾ�����ּ��ص�����
void Int_Digtal_SetCache(unsigned long num);

//�������е�����ˢд�������
void Int_Digtal_FlushDigtal();

void Int_Digtal_Init();

void Int_Digtal_Callback();

#endif