#include "Int_MatrixKey.h"

unsigned char Int_MatrixKey_GetPressedKey()
{
    P2 = 0xFE; // 1111 1110
    if(P24 == 0)
    {
        Delay10ms();
        if(P24 == 0)
        {
            while(1)
            {
                if(P24 == 1)
                {
                    Delay10ms();
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
        Delay10ms();
        if(P25 == 0)
        {
            while(1)
            {
                if(P25 == 1)
                {
                    Delay10ms();
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
        Delay10ms();
        if(P26 == 0)
        {
            while(1)
            {
                if(P26 == 1)
                {
                    Delay10ms();
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
        Delay10ms();
        if(P27 == 0)
        {
            while(1)
            {
                if(P27 == 1)
                {
                    Delay10ms();
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
        Delay10ms();
        if(P24 == 0)
        {
            while(1)
            {
                if(P24 == 1)
                {
                    Delay10ms();
                    if(P24 == 1)
                    {
                        return 11;
                    }
                }
            }
        }
    }
    if(P25 == 0)
    {
        Delay10ms();
        if(P25 == 0)
        {
            while(1)
            {
                if(P25 == 1)
                {
                    Delay10ms();
                    if(P25 == 1)
                    {
                        return 12;
                    }
                }
            }
        }
    }
    if(P26 == 0)
    {
        Delay10ms();
        if(P26 == 0)
        {
            while(1)
            {
                if(P26 == 1)
                {
                    Delay10ms();
                    if(P26 == 1)
                    {
                        return 13;
                    }
                }
            }
        }
    }
    if(P27 == 0)
    {
        Delay10ms();
        if(P27 == 0)
        {
            while(1)
            {
                if(P27 == 1)
                {
                    Delay10ms();
                    if(P27 == 1)
                    {
                        return 14;
                    }
                }
            }
        }
    }
    P2 = 0xFB; // 1111 1011
    if(P24 == 0)
    {
        Delay10ms();
        if(P24 == 0)
        {
            while(1)
            {
                if(P24 == 1)
                {
                    Delay10ms();
                    if(P24 == 1)
                    {
                        return 15;
                    }
                }
            }
        }
    }
    if(P25 == 0)
    {
        Delay10ms();
        if(P25 == 0)
        {
            while(1)
            {
                if(P25 == 1)
                {
                    Delay10ms();
                    if(P25 == 1)
                    {
                        return 16;
                    }
                }
            }
        }
    }
    if(P26 == 0)
    {
        Delay10ms();
        if(P26 == 0)
        {
            while(1)
            {
                if(P26 == 1)
                {
                    Delay10ms();
                    if(P26 == 1)
                    {
                        return 17;
                    }
                }
            }
        }
    }
    if(P27 == 0)
    {
        Delay10ms();
        if(P27 == 0)
        {
            while(1)
            {
                if(P27 == 1)
                {
                    Delay10ms();
                    if(P27 == 1)
                    {
                        return 18;
                    }
                }
            }
        }
    }
    P2 = 0xF7; // 1111 0111
    if(P24 == 0)
    {
        Delay10ms();
        if(P24 == 0)
        {
            while(1)
            {
                if(P24 == 1)
                {
                    Delay10ms();
                    if(P24 == 1)
                    {
                        return 19;
                    }
                }
            }
        }
    }
    if(P25 == 0)
    {
        Delay10ms();
        if(P25 == 0)
        {
            while(1)
            {
                if(P25 == 1)
                {
                    Delay10ms();
                    if(P25 == 1)
                    {
                        return 20;
                    }
                }
            }
        }
    }
    if(P26 == 0)
    {
        Delay10ms();
        if(P26 == 0)
        {
            while(1)
            {
                if(P26 == 1)
                {
                    Delay10ms();
                    if(P26 == 1)
                    {
                        return 21;
                    }
                }
            }
        }
    }
    if(P27 == 0)
    {
        Delay10ms();
        if(P27 == 0)
        {
            while(1)
            {
                if(P27 == 1)
                {
                    Delay10ms();
                    if(P27 == 1)
                    {
                        return 22;
                    }
                }
            }
        }
    }
    return 0;
}