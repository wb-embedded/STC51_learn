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

void Int_Digtal_SetCache(unsigned long num)
{
    unsigned char i;
    for(i = 0; i < 8; i++)
    {
        s_buff[i] = 0x00;
    }
    if(num == 0)
    {
        s_buff[7] = s_digtal_codes[0];
        return;
    }
    i = 7;
    while(num != 0)
    {
        s_buff[i] = s_digtal_codes[num % 10];
        num /= 10;
        i--;
    }
}

void Int_Digtal_FlushDigtal()
{
    unsigned char i;
    for(i = 0; i < 8; i++)
    {
        Int_Digtal_DisplaySingle(i, s_buff[i]);
    }
}

void Int_Digtal_SetCacheByBin(unsigned char* str)
{
    unsigned char i;
    for(i = 0; i < 8; i++)
    {
        s_buff[i] = str[i];
    }
}