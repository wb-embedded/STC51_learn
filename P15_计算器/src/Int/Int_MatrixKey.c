#include "Int_MatrixKey.h"

unsigned char Int_MatrixKey_GetPressedKey()
{
    P2 = 0xFE; // 1111 1110
    if(P24 == 0)
    {
        Delay10ms(1);
        if(P24 == 0)
        {
            while(1)
            {
                if(P24 == 1)
                {
                    Delay10ms(1);
                    if(P24 == 1)
                    {
                        return 1;
                    }
                }
            }
        }
    }
    if(P25 == 0)
    {
        Delay10ms(1);
        if(P25 == 0)
        {
            while(1)
            {
                if(P25 == 1)
                {
                    Delay10ms(1);
                    if(P25 == 1)
                    {
                        return 2;
                    }
                }
            }
        }
    }
    if(P26 == 0)
    {
        Delay10ms(1);
        if(P26 == 0)
        {
            while(1)
            {
                if(P26 == 1)
                {
                    Delay10ms(1);
                    if(P26 == 1)
                    {
                        return 3;
                    }
                }
            }
        }
    }
    if(P27 == 0)
    {
        Delay10ms(1);
        if(P27 == 0)
        {
            while(1)
            {
                if(P27 == 1)
                {
                    Delay10ms(1);
                    if(P27 == 1)
                    {
                        return 10;
                    }
                }
            }
        }
    }
    P2 = 0xFD; // 1111 1101
    if(P24 == 0)
    {
        Delay10ms(1);
        if(P24 == 0)
        {
            while(1)
            {
                if(P24 == 1)
                {
                    Delay10ms(1);
                    if(P24 == 1)
                    {
                        return 4;
                    }
                }
            }
        }
    }
    if(P25 == 0)
    {
        Delay10ms(1);
        if(P25 == 0)
        {
            while(1)
            {
                if(P25 == 1)
                {
                    Delay10ms(1);
                    if(P25 == 1)
                    {
                        return 5;
                    }
                }
            }
        }
    }
    if(P26 == 0)
    {
        Delay10ms(1);
        if(P26 == 0)
        {
            while(1)
            {
                if(P26 == 1)
                {
                    Delay10ms(1);
                    if(P26 == 1)
                    {
                        return 6;
                    }
                }
            }
        }
    }
    if(P27 == 0)
    {
        Delay10ms(1);
        if(P27 == 0)
        {
            while(1)
            {
                if(P27 == 1)
                {
                    Delay10ms(1);
                    if(P27 == 1)
                    {
                        return 20;
                    }
                }
            }
        }
    }
    P2 = 0xFB; // 1111 1011
    if(P24 == 0)
    {
        Delay10ms(1);
        if(P24 == 0)
        {
            while(1)
            {
                if(P24 == 1)
                {
                    Delay10ms(1);
                    if(P24 == 1)
                    {
                        return 7;
                    }
                }
            }
        }
    }
    if(P25 == 0)
    {
        Delay10ms(1);
        if(P25 == 0)
        {
            while(1)
            {
                if(P25 == 1)
                {
                    Delay10ms(1);
                    if(P25 == 1)
                    {
                        return 8;
                    }
                }
            }
        }
    }
    if(P26 == 0)
    {
        Delay10ms(1);
        if(P26 == 0)
        {
            while(1)
            {
                if(P26 == 1)
                {
                    Delay10ms(1);
                    if(P26 == 1)
                    {
                        return 9;
                    }
                }
            }
        }
    }
    if(P27 == 0)
    {
        Delay10ms(1);
        if(P27 == 0)
        {
            while(1)
            {
                if(P27 == 1)
                {
                    Delay10ms(1);
                    if(P27 == 1)
                    {
                        return 30;
                    }
                }
            }
        }
    }
    P2 = 0xF7; // 1111 0111
    if(P24 == 0)
    {
        Delay10ms(1);
        if(P24 == 0)
        {
            while(1)
            {
                if(P24 == 1)
                {
                    Delay10ms(1);
                    if(P24 == 1)
                    {
                        return 0;
                    }
                }
            }
        }
    }
    if(P25 == 0)
    {
        Delay10ms(1);
        if(P25 == 0)
        {
            while(1)
            {
                if(P25 == 1)
                {
                    Delay10ms(1);
                    if(P25 == 1)
                    {
                        return 50;
                    }
                }
            }
        }
    }
    if(P26 == 0)
    {
        Delay10ms(1);
        if(P26 == 0)
        {
            while(1)
            {
                if(P26 == 1)
                {
                    Delay10ms(1);
                    if(P26 == 1)
                    {
                        return 60;
                    }
                }
            }
        }
    }
    if(P27 == 0)
    {
        Delay10ms(1);
        if(P27 == 0)
        {
            while(1)
            {
                if(P27 == 1)
                {
                    Delay10ms(1);
                    if(P27 == 1)
                    {
                        return 40;
                    }
                }
            }
        }
    }
    return 255;
}