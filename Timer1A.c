// Timer1A.c
// Runs TM4C123
// Authors: Roy Mears, Jonathan Ramirez, Nolan Nguyen, Christian Mata
// Date: 09/11/24
// Use TIMER1 in 16-bit periodic mode to generate trigger pulse and measure sensor delay
// Functions for calculating time passed and timer control
#include "tm4c123gh6pm.h"
#include "stdint.h"



// ***************** TimerA1_Init ****************
// initialize clock and configuration before being started
// Inputs:  none
// Outputs: none
void Timer1A_Init(){
  SYSCTL_RCGCTIMER_R |= SYSCTL_RCGCTIMER_R1;   // 0) activate TIMER1 clk
		while ((SYSCTL_RCGC2_R&SYSCTL_RCGCTIMER_R1)!=SYSCTL_RCGCTIMER_R1){}; // wait for clock to start

  TIMER1_CTL_R |= 0x00000000;    // 1) disable TIMER1A during setup
  TIMER1_CFG_R |= 0x00000004;    // 2) configure for 16-bit mode   
  TIMER1_TAMR_R |= 0x00000002;   // 3) input periodic down count


 }

 
// ***************** Timer1A_Start ****************
// 
// Inputs:  none
// Outputs: none
void Timer1A_Start(unsigned long prescale,unsigned long period ){
  TIMER1_TAILR_R = (period-1);    // 4) reload value
  TIMER1_TAPR_R = prescale;       // 5) bus clock prescale value
  TIMER1_CTL_R |= 0x00000001;      // enable TIMER1A
}
 

// ***************** Timer1A_Stop ****************
// 
// Inputs:  none
// Outputs: none
void Timer1A_Stop(){
	TIMER1_CTL_R = 0x00000000; // stop timer
}


// ***************** Timer1A_Elapsed ****************
// 
// Inputs:  none
// Outputs: none
uint32_t Timer1A_Elapsed(){
	return ((TIMER1_TAILR_R - TIMER1_TAR_R)*TIMER1_TAPR_R+1); // subtract the current count from the start count to get elapsed value
}

