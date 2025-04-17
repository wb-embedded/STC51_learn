#include "STC89C5XRC.H"
#include "./Int/Int_Digtal.h"
#include <INTRINS.H>
#include "./Com/Com_Util.h"

void main()
{
  int i = 100, j = 0;
  SMG_EN = 0; //SMG_EN 低电平有效
  LED_EN = 0; //LED_EN 高电平有效
  while(1)
  {
    if(j == 1000)
    {
      j = 0;
      if(i >= 0)
      {
        Int_Digtal_SetCache(i);
        i--;
      }
    }
    j++;
    Int_Digtal_FlushDigtal();
  }
}
