#ifndef __INT_KEY_H__
#define __INT_KEY_H__

#include "STC89C5xRC.H"
#include "Dri_Timer0.h"

void Int_Key_Init();
unsigned char Int_Key_GetSw1Status();
unsigned char Int_Key_GetSw2Status();
unsigned char Int_Key_GetSw3Status();
unsigned char Int_Key_GetSw4Status();

#endif