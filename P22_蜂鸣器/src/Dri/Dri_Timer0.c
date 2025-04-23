#include "Dri_Timer0.h"

static Callback s_func[MAX_CALLBACK_COUNT];

void Dri_Timer0_Init()
{
    unsigned char i;
    EA  = 1;
    ET0 = 1;
    TMOD &= 0xF0;
    TMOD |= 0x01;
    TL0 = 64614;
    TH0 = 64614 >> 8;
    TR0 = 1;
    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        s_func[i] = NULL;
    }
}

void Dri_Timer0_Register(Callback func)
{
    unsigned char i;
    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        if (s_func[i] == func) {
            return;
        }
    }
    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        if (s_func[i] == NULL) {
            s_func[i] = func;
            return;
        }
    }
}

void Dri_Timer0_DeRegister(Callback func)
{
    unsigned char i;
    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        if (s_func[i] == func) {
            s_func[i] = NULL;
            return;
        }
    }
}

static void Dri_Timer0_Func() interrupt 1
{
    unsigned char i;
    TL0 = 64614;
    TH0 = 64614 >> 8;

    for (i = 0; i < MAX_CALLBACK_COUNT; i++) {
        if (s_func[i] != NULL) {
            s_func[i]();
        }
    }
}