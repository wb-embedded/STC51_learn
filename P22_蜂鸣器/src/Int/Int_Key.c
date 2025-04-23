#include "Int_Key.h"

unsigned char s_sw3_status, s_sw4_status, s_sw5_status, s_sw6_status;
unsigned char s_sw3_before_status, s_sw4_before_status, s_sw5_before_status, s_sw6_before_status;

static void Int_Key_CallbackFunc()
{
    s_sw3_status <<= 1;
    s_sw3_status |= SW3;

    s_sw4_status <<= 1;
    s_sw4_status |= SW4;

    s_sw5_status <<= 1;
    s_sw5_status |= SW5;

    s_sw6_status <<= 1;
    s_sw6_status |= SW6;
}

void Int_Key_Init()
{
    s_sw3_status = 0xFF;
    s_sw4_status = 0xFF;
    s_sw5_status = 0xFF;
    s_sw6_status = 0xFF;

    s_sw3_before_status = 2;
    s_sw4_before_status = 2;
    s_sw5_before_status = 2;
    s_sw6_before_status = 2;

    Dri_Timer0_Register(Int_Key_CallbackFunc);
}

unsigned char Int_Key_GetSw3Status()
{
    if(s_sw3_before_status == 2 && s_sw3_status == 0x00)
    {
        s_sw3_before_status = 1;
        return 1;
    }
    if(s_sw3_before_status == 1 && s_sw3_status == 0xFF)
    {
        s_sw3_before_status = 2;
        return 2;
    }
    return 0;
}

unsigned char Int_Key_GetSw4Status()
{
    if (s_sw4_before_status == 2 && s_sw4_status == 0x00) {
        s_sw4_before_status = 1;
        return 1;
    }
    if (s_sw4_before_status == 1 && s_sw4_status == 0xFF) {
        s_sw4_before_status = 2;
        return 2;
    }
    return 0;
}

unsigned char Int_Key_GetSw5Status()
{
    if (s_sw5_before_status == 2 && s_sw5_status == 0x00) {
        s_sw5_before_status = 1;
        return 1;
    }
    if (s_sw5_before_status == 1 && s_sw5_status == 0xFF) {
        s_sw5_before_status = 2;
        return 2;
    }
    return 0;
}

unsigned char Int_Key_GetSw6Status()
{
    if (s_sw6_before_status == 2 && s_sw6_status == 0x00) {
        s_sw6_before_status = 1;
        return 1;
    }
    if (s_sw6_before_status == 1 && s_sw6_status == 0xFF) {
        s_sw6_before_status = 2;
        return 2;
    }
    return 0;
}