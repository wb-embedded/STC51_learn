#include "Dri_Timer0.h"

static unsigned int s_ms_count = 0;

void Dri_Time0_Init()
{
    //总中断允许位
    EA = 1;
    //定时器0中断开关
    ET0 = 1;
    //设置TMOD
    TMOD &= 0xF0;
    TMOD |= 0x01;
    //设置TR0
    TR0 = 1;
    //设置脉冲计数器初值,晶振频率和时长都会造成影响
    TL0 = 64614 % 256;
    TH0 = 64614 / 256;
}

static void Dri_Time0_Func() interrupt 1
{
    TL0 = 64614 % 256;
    TH0 = 64614 / 256;

    s_ms_count++;

    if(s_ms_count == 1000)
    {
        P00 = ~P00;
        s_ms_count = 0;
    }
}