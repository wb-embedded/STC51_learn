#include "Dri_Uart.h"

static unsigned char s_res;
static bit s_r_flag = 0, s_t_flag = 0;

void Dri_Uart_Init()
{
    EA  = 1;
    ES  = 1;
    SM0 = 0;
    SM1 = 1;
    SM2 = 0;
    REN = 1;
    TI  = 1;
    RI  = 0;
    PCON &= 0x7F;
    TMOD &= 0x0F;
    TMOD |= 0x20;
    TH1 = TL1 = 0xFD;
    TR1       = 1;
}

static void Dri_Uart_Func() interrupt 4
{
    if (RI) {
        s_res    = SBUF;
        s_r_flag = 1;
        RI       = 0;
    } else {
        s_t_flag = 1;
        TI       = 0;
    }
}

unsigned char Dri_Uart_Rdata()
{
    if (s_r_flag) {
        s_r_flag = 0;
        return s_res;
    }
    return 0;
}

void Dri_Uart_Tdata(unsigned char tdata)
{
    while (!s_t_flag);
    s_t_flag = 0;
    SBUF     = tdata;
}