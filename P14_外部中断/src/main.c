#include "STC89C5XRC.H"
#include "Dri_Interrupt.h"
#include "Com_Util.h"

void main()
{
    // SMG_EN = 0; //SMG_EN �͵�ƽ��Ч
    // LED_EN = 0; //LED_EN �ߵ�ƽ��Ч
    Dri_Interrupt_Init();
    while(1)
    {
      // P32 = ~P32;//P32Ϊ�������ţ��ⲿ�ж�����Դ
      IE0 = ~IE0;
      Delay10ms(100);
    }
}
