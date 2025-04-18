#include "Int_Keyboard.h"

bit Int_Keyboard_IsPressedBySw1()
{
    if(P42)
    {
       return 0;
    }
    Delay10ms();
    if(P42)
    {
        return 0;
    }
    while(1)
    {
        if(P42)
        {
            Delay10ms();
            if(P42)
            {
                return 1;
            }
        }
    }
}

bit Int_Keyboard_IsPressedBySw2()
{
    if(P43)
    {
        return 0;
    }
    Delay10ms();
    if(P43)
    {
        return 0;
    }
    while(1)
    {
        if(P43)
        {
            Delay10ms();
            if(P43)
            {
                return 1;
            }
        }
    }
}

bit Int_Keyboard_IsPressedBySw3()
{
    if(P32)
    {
        return 0;
    }
    Delay10ms();
    if(P32)
    {
        return 0;
    }
    while(1)
    {
        if(P32)
        {
            Delay10ms();
            if(P32)
            {
                return 1;
            }
        }
    }
}

bit Int_Keyboard_IsPressedBySw4()
{
    if(P33)
    {
        return 0;
    }
    Delay10ms();
    if(P33)
    {
        return 0;
    }
    while(1)
    {
        if(P33)
        {
            Delay10ms();
            if(P33)
            {
                return 1;
            }
        }
    }
}