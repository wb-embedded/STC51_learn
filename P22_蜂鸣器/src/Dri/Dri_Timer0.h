#ifndef __DRI_TIMER0_H__
#define __DRI_TIMER0_H__

#include "STC89C5xRC.H"
#include "STDIO.H"

#define MAX_CALLBACK_COUNT 4

typedef void (*Callback)(void);

void Dri_Timer0_Init();

void Dri_Timer0_Register(Callback func);

void Dri_Timer0_DeRegister(Callback func);

#endif