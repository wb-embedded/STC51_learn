#include "Int_MatrixLED.h"

static unsigned char s_pics[8];
static unsigned char s_current_line;

static void Int_MatrixLED_CallbackFlush()
{
    P0 = 0xFF;
    if (s_current_line == 0) {
        SER = 1;
    } else {
        SER = 0;
    }

    SCK = 0;
    SCK = 1;
    RCK = 0;
    RCK = 1;

    P0 = ~s_pics[s_current_line];

    s_current_line++;

    if (s_current_line >= 8) {
        s_current_line = 0;
    }
}

void Int_MatrixLED_Init()
{
    s_current_line = 0;
    MATRIXLED_EN   = 0;
    LED_EN         = 0;
    // Dri_Timer0_RegisterCallbackFunc(Int_MatrixLED_CallbackMove);
    Dri_Timer0_RegisterCallbackFunc(Int_MatrixLED_CallbackFlush);
}

void Int_MatrixLED_SetPics(unsigned char *pics)
{
    unsigned char i;
    for (i = 0; i < 8; i++) {
        s_pics[i] = pics[i];
    }
}