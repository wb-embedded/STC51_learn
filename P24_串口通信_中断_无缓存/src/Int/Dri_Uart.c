#include "Dri_Uart.h"

static char s_res;
// 没有新数据为0，有新数据为1，正在发送为0，发送完毕为1
static bit s_rdata_flag = 0, s_tdata_flag = 0;

void Dri_Uart_Init()
{
    // 中断总开关
    EA = 1;
    // 串口中断开关
    ES = 1;

    // 串口工作模式
    SM0 = 0;
    SM1 = 1;
    SM2 = 0;
    REN = 1;
    TI  = 1;
    RI  = 0;

    // 设置串口工作频率 SMOD
    PCON &= 0x7F;

    // 设置定时器1工作模式
    TMOD &= 0x0F;
    TMOD |= 0x20;
    TH1 = TL1 = 0xFD;
    TR1       = 1;
}

static void Dri_Uart_Func() interrupt 4
{
    if (RI) {
        s_res        = SBUF;
        s_rdata_flag = 1;
        RI           = 0;
    } else {
        s_tdata_flag = 1;
        TI           = 0;
    }
}

unsigned char Dri_Uart_Rdata()
{
    if (s_rdata_flag) {
        s_rdata_flag = 0;
        return s_res;
    }
    return 0;
}

void Dri_Uart_Tdata(unsigned char tdata)
{
    while (!s_tdata_flag);
    s_tdata_flag = 0;
    SBUF         = tdata;
}