#ifndef __INT_KEY_H__
#define __INT_KEY_H__

#include "Dri_Timer0.h"

#define SW3 P42
#define SW4 P43
#define SW5 P32
#define SW6 P33

void Int_Key_Init();
unsigned char Int_Key_GetSw3Status();
unsigned char Int_Key_GetSw4Status();
unsigned char Int_Key_GetSw5Status();
unsigned char Int_Key_GetSw6Status();

#endif