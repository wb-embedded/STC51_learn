#include "Com_Util.h"

void Delay1ms(unsigned char ms) //@11.0592MHz
{
    unsigned char data i, j;

    while (ms--) {
        _nop_();
        i = 2;
        j = 199;
        do {
            while (--j);
        } while (--i);
    }
}

void Delay10us(unsigned char ms) //@11.0592MHz
{
    unsigned char data i;

    while (ms--) {
        i = 2;
        while (--i);
    }
}