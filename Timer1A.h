// Timer1A.c
// Runs TM4C123
// Authors: Roy Mears, Jonathan Ramirez, Nolan Nguyen, Christian Mata
// Date: 09/11/24
// Use TIMER1 in 16-bit periodic mode to generate trigger pulse and measure sensor delay
// Functions for calculating time passed and timer control



#ifndef __TIMER0INTS_H__ 
#define __TIMER0INTS_H__
#include "stdint.h"
// ***************** Timer1A_Init ****************
// Inputs:
// Outputs: none
void Timer1A_Init();

// ***************** Timer1A_Stop_Measure****************
// Inputs:
// Outputs: none
void Timer1A_Stop();

// ***************** Timer1A_Start ****************
// Inputs:
// Outputs: none
void Timer1A_Start(unsigned long prescale,unsigned long period );

// ***************** Timer1A_Elapsed ****************
// Inputs:
// Outputs: none
uint32_t Timer1A_Elapsed();



#endif 
