#include "Dri_Interrupt.h"

void Dri_Interrupt_Init()
{
    //总中断允许控制位
    EA = 1;

    //外部中断0允许控制位
    EX0 = 1;

    //外部中断0中断源类型选择位
    IT0 = 1;
}

static void Dri_Interrupt_Func() interrupt 0
{
    P00 = ~P00;
}