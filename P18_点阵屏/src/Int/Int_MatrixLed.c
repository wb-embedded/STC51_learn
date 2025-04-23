#include "Int_MatrixLed.h"

static unsigned char s_pics[8];

void Int_MatrixLed_SetCache(unsigned char *pics)
{
    unsigned char i;

    for (i = 0; i < 8; i++) {
        s_pics[i] = pics[i];
    }
}

void Int_MatrixLed_Flush()
{
    unsigned char i;
    for (i = 0; i < 8; i++) {
        P0 = 0xFF;
        if (i == 0)
            SER = 1;
        else {
            SER = 0;
        }
        SCK = 0;
        SCK = 1;
        RCK = 0;
        RCK = 1;
        P0  = ~s_pics[i];
    }
}