#include "Int_Key.h"

static unsigned char s_sw1_status, s_sw2_status, s_sw3_status, s_sw4_status;
static unsigned char s_sw1_before_status, s_sw2_before_status, s_sw3_before_status, s_sw4_before_status;

static void Int_Key_CallbackFunc()
{
    s_sw1_status <<= 1;
    s_sw1_status |= P42;

    s_sw2_status <<= 1;
    s_sw2_status |= P43;

    s_sw3_status <<= 1;
    s_sw3_status |= P32;

    s_sw4_status <<= 1;
    s_sw4_status |= P33;
}

// 1表示按下，2表示抬起，0表示与之前状态一致
void Int_Key_Init()
{
    s_sw1_status = 0xFF;
    s_sw2_status = 0xFF;
    s_sw3_status = 0xFF;
    s_sw4_status = 0xFF;

    s_sw1_before_status = 2;
    s_sw2_before_status = 2;
    s_sw3_before_status = 2;
    s_sw4_before_status = 2;

    Dri_Timer0_RegisterCallbackFunc(Int_Key_CallbackFunc);
}

// 1表示按下，2表示抬起，0表示与之前状态一致
unsigned char Int_Key_GetSw1Status()
{
    if (s_sw1_before_status == 2 && s_sw1_status == 0x00) {
        s_sw1_before_status = 1;
        return 1;
    }
    if (s_sw1_before_status == 1 && s_sw1_status == 0xFF) {
        s_sw1_before_status = 2;
        return 2;
    }
    return 0;
}

unsigned char Int_Key_GetSw2Status()
{
    if (s_sw2_before_status == 2 && s_sw2_status == 0x00) {
        s_sw2_before_status = 1;
        return 1;
    }
    if (s_sw2_before_status == 1 && s_sw2_status == 0xFF) {
        s_sw2_before_status = 2;
        return 2;
    }
    return 0;
}

unsigned char Int_Key_GetSw3Status()
{
    if (s_sw3_before_status == 2 && s_sw3_status == 0x00) {
        s_sw3_before_status = 1;
        return 1;
    }
    if (s_sw3_before_status == 1 && s_sw3_status == 0xFF) {
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