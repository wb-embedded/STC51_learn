#include "Int_MatrixLed.h"

static unsigned char s_pics[8];

void Int_MatrixLed_Move(unsigned char pics)
{
    unsigned char i;
    for (i = 7; i > 0; i--) {
        s_pics[i] = s_pics[i - 1];
    }
    s_pics[i] = pics;
}

void Int_MatrixLed_Flush()
{
    unsigned char i;
    for (i = 0; i < 8; i++) {
        P0 = 0xff;
        if (i == 0) {
            SER = 1;
        } else {
            SER = 0;
        }
        SCK = 0;
        SCK = 1;
        RCK = 0;
        RCK = 1;

        P0 = ~s_pics[i];
    }
}