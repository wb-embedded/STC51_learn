#include "STC89C5XRC.H"
#include "Int_Digtal.h"
#include "Int_MatrixKey.h"

void main()
{
  unsigned char idx;
  SMG_EN = 0; //SMG_EN �͵�ƽ��Ч
  LED_EN = 0; //LED_EN �ߵ�ƽ��Ч
  while(1)
  {
    if(idx = Int_MatrixKey_GetPressedKey())
    {
      Int_Digtal_SetCache(idx);
    }
    Int_Digtal_FlushDigtal();
  }
}
