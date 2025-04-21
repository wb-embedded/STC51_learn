#ifndef __DRI_TIMER0_H__
#define __DRI_TIMER0_H__

#include "STC89C5xRC.H"
#include "STDIO.H"

typedef void (*CallbackFunction)(void);

void Dri_Timer0_Init();

void Dri_Timer0_RegisterCallbackFunc(CallbackFunction);

void Dri_Timer0_DeRegisterCallbackFunc(CallbackFunction);

#endif