#include "./Int/Int_Digtal.h"
#include "./Int/Int_Keyboard.h"

unsigned char str[8];

void coverNumToBin(unsigned char num, unsigned char* str)
{
    unsigned char i;
    for(i = 0; i < 8; i++)
    {
        str[i] = s_digtal_codes[0];
    }
    i = 7;
    while(num != 0)
    {
        str[i] = s_digtal_codes[num % 2];
        num /= 2;
        i--;
    }
}

void main()
{
    unsigned long num = 0, i;
    SMG_EN = 0;
    LED_EN = 0;
    coverNumToBin(255, str);
    Int_Digtal_SetCacheByBin(str);
    while(1)
    {
        i = 0;
        // if(Int_Keyboard_IsPressedBySw1())
        // {
        //     num += 1;
        // }
        // if(Int_Keyboard_IsPressedBySw2())
        // {
        //     num += 10;
        // }
        // if(Int_Keyboard_IsPressedBySw3())
        // {
        //     num += 100;
        // }
        // if(Int_Keyboard_IsPressedBySw4())
        // {
        //     num += 1000;
        // }
        // Int_Digtal_SetCache(num);
        while(i < 100)
        {
            Int_Digtal_FlushDigtal();
            i++;
        }
    }
}