#include "STC89C5XRC.H"
#include "Dri_Interrupt.h"
#include "Com_Util.h"

void main()
{
    // SMG_EN = 0; //SMG_EN 低电平有效
    // LED_EN = 0; //LED_EN 高电平有效
    Dri_Interrupt_Init();
    while(1)
    {
      // P32 = ~P32;//P32为复用引脚，外部中断请求源
      IE0 = ~IE0;
      Delay10ms(100);
    }
}
