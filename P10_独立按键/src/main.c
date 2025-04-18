#include "Int_Keyboard.h"

void main()
{
    while(1)
    {
        if(Int_Keyboard_IsPressedBySw1())
        {
            P00 = ~P00;
        }
        if(Int_Keyboard_IsPressedBySw2())
        {
            P01 = ~P01;
        }
        if(Int_Keyboard_IsPressedBySw3())
        {
            P02 = ~P02;
        }
        if(Int_Keyboard_IsPressedBySw4())
        {
            P03 = ~P03;
        }
    }
}