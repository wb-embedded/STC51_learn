#include "./Int/Int_Digtal.h"
#include "./Int/Int_Keyboard.h"

void main()
{
    unsigned long num = 0, i;
    SMG_EN = 0;
    LED_EN = 0;
    while(1)
    {
        i = 0;
        if(Int_Keyboard_IsPressedBySw1())
        {
            num += 1;
        }
        if(Int_Keyboard_IsPressedBySw2())
        {
            num += 10;
        }
        if(Int_Keyboard_IsPressedBySw3())
        {
            num += 100;
        }
        if(Int_Keyboard_IsPressedBySw4())
        {
            num += 1000;
        }
        Int_Digtal_SetCache(num);
        while(i < 100)
        {
            Int_Digtal_FlushDigtal();
            i++;
        }
    }
}