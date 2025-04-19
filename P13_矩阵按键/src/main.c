#include "STC89C5XRC.H"
#include "Int_Digtal.h"
#include "Int_MatrixKey.h"

void main()
{
  unsigned char idx;
  SMG_EN = 0; //SMG_EN 低电平有效
  LED_EN = 0; //LED_EN 高电平有效
  while(1)
  {
    if(idx = Int_MatrixKey_GetPressedKey())
    {
      Int_Digtal_SetCache(idx);
    }
    Int_Digtal_FlushDigtal();
  }
}
