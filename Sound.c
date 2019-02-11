// Runs on LM4F120 or TM4C123,
// Use the SysTick timer to request interrupts at a particular period.
// This routine calls the 4-bit DAC

#include "Sound.h"
#include "DAC.h"
#include "..//tm4c123gh6pm.h"

// Wave shape is Stored as values in a constant array.
const unsigned long wave[32]={8,9,11,12,13,14,14,15,15,15,14,14,13,12,11,9,8,7,5,4,3,2,2,1,1,1,2,2,3,4,5,7};

// **************Sound_Init*********************
// Initialize Systick periodic interrupts
// Calls DAC_Init() to initialize DAC
void Sound_Init(void){
DAC_Init();
NVIC_ST_CTRL_R&=~0x0F;
NVIC_ST_CURRENT_R=0x01;
NVIC_ST_RELOAD_R=0;
NVIC_ST_CTRL_R=0x07;
NVIC_PRI3_R|=0x0FFFFFF;	
}

// **************Sound_Tone*********************
// Change Systick periodic interrupts to start sound output
// Input: interrupt period
//           Units of period are 12.5ns
//           Maximum is 2^24-1
//           Minimum is determined by length of ISR
void Sound_Tone(unsigned long period){
// this routine sets the RELOAD and starts SysTick
NVIC_ST_RELOAD_R=period;
}

unsigned long i;
// **************Sound_Off*********************
// stop outputing to DAC
// Output: none
void Sound_Off(void){
 // this routine stops the sound output
NVIC_ST_RELOAD_R=0;
i=0;
}

// Interrupt service routine
// Executed every 12.5ns*(period)

void SysTick_Handler(void){
DAC_Out(wave[i]);
i=(i+1)&0x1F;
}
