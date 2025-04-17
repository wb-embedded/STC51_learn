#include "STC89C5XRC.H"
#include "./Int/Int_Digtal.h"

void main()
{
    SMG_EN = 0; //SMG_EN 低电平有效
    LED_EN = 0; //LED_EN 高电平有效
    Int_Digtal_SetCache(12345);
    while(1)
    {
      Int_Digtal_FlushDigtal();
    }
}
