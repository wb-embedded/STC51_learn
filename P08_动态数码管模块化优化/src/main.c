#include "STC89C5XRC.H"
#include "./Int/Int_Digtal.h"

void main()
{
    SMG_EN = 0; //SMG_EN �͵�ƽ��Ч
    LED_EN = 0; //LED_EN �ߵ�ƽ��Ч
    Int_Digtal_SetCache(12345);
    while(1)
    {
      Int_Digtal_FlushDigtal();
    }
}
