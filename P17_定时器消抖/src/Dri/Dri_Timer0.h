#ifndef __DRI_TIMER0_H__
#define __DRI_TIMER0_H__

#include "STC89C5xRC.H"
#include "STDIO.H"

#define MAX_CALLBACK_SIZE 4

typedef void (*CallbackFunc)(void);

void Dri_Timer0_Init();
void Dri_Timer0_RegisterCallbackFunc(CallbackFunc);
void Dri_Timer0_DeRegisterCallbackFunc(CallbackFunc);

#endif