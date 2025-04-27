#include "Dri_Uart.h"

void Dri_Uart_Init()
{
    // 设置SM0,SM1,SM2,选用方式1,SM0 = 0,SM1 = 1,SM2 = 0
    SM0 = 0;
    SM1 = 1;
    SM2 = 0;

    // 设置接收使能端
    REN = 1;

    // 设置中断请求位RI，TI
    RI = 0;
    TI = 1;

    // 根据波特率设置SMOD
    PCON &= 0x7F;

    // 设置定时器
    TMOD &= 0x0F;
    TMOD |= 0x20;
    TH1 = TL1 = 0xFD;
    TR1       = 1;
}