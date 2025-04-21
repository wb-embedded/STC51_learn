#include "STC89C5XRC.H"
#include "Int_Digtal.h"
#include "Dri_Timer0.h"

void main()
{
    Dri_Timer0_Init();
    Int_Digtal_Init();
    Int_Digtal_SetCache(12345678);
    while (1) {
    }
}
