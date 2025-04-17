#ifndef __INT_DIGTAL_H__
#define __INT_DIGTAL_H__

#include "../STC89C5xRC.H"

#define SMG_EN P36
#define LED_EN P34

static unsigned char s_buff[8];

static unsigned char s_digtal_codes[10] = {
    0x3F,//0
    0x06,//1
    0x5B,//2
    0x4F,//3
    0x66,//4
    0x6D,//5
    0x7D,//6
    0x07,//7
    0x7F,//8
    0x6F//9
};

static void Int_Digtal_DisplaySingle(unsigned char, unsigned char);
void Int_Digtal_SetCache(unsigned long num);
void Int_Digtal_FlushDigtal();
void Int_Digtal_SetCacheByBin(unsigned char* str);

#endif