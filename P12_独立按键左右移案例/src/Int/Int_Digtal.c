#include "Int_Digtal.h"

static void Int_Digtal_DisplaySingle(unsigned char n, unsigned char num)
{
    //Æ¬Ñ¡
    P0 = 0x00;
    P1 &= 0xc7;
    P1 |= (n << 3);
    //¶ÎÑ¡
    P0 = num;
}

void Int_Digtal_FlushDigtal()
{
    unsigned char i;
    for(i = 0; i < 8; i++)
    {
        Int_Digtal_DisplaySingle(i, s_buff[i]);
    }
}

void Int_Digtal_SetCacheByBin(unsigned char* p_data)
{
    unsigned char i;
    for(i = 0; i < 8; i++)
    {
        s_buff[i] = s_digtal_codes[p_data[i]];
    }
}