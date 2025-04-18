#include "Int_Digtal.h"
#include "Int_Keyboard.h"

void coverNumToBin(unsigned char num, unsigned char* p_data)
{
    unsigned char i;
    for(i = 0; i < 8; i++)
    {
        p_data[i] = 0;
    }
    i = 7;
    while(num != 0)
    {
        p_data[i] = num % 2;
        num /= 2;
        i--;
    }
}

void main()
{
    unsigned char num = 255;
    unsigned char str[8];
    SMG_EN = 0;
    LED_EN = 0;
    coverNumToBin(num, str);
    Int_Digtal_SetCacheByBin(str);
    while(1)
    {
        // i = 0;
        if(Int_Keyboard_IsPressedBySw1())
        {
            num *= 2;
            coverNumToBin(num, str);
            Int_Digtal_SetCacheByBin(str);
        }
        if(Int_Keyboard_IsPressedBySw2())
        {
            num /= 2;
            coverNumToBin(num, str);
            Int_Digtal_SetCacheByBin(str);
        }
        if(Int_Keyboard_IsPressedBySw3())
        {
            num += 1;
            coverNumToBin(num, str);
            Int_Digtal_SetCacheByBin(str);
        }
        if(Int_Keyboard_IsPressedBySw4())
        {
            num = 0;
            coverNumToBin(num, str);
            Int_Digtal_SetCacheByBin(str);
        }
        Int_Digtal_FlushDigtal();
    }
}
