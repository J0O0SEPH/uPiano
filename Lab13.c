// Runs on LM4F120 or TM4C123
// Use SysTick interrupts to implement a 4-key digital piano
// Port B bits 3-0 have the 4-bit DAC
// Port E bits 3-0 have 4 piano keys

#include "..//tm4c123gh6pm.h"
#include "Sound.h"
#include "Piano.h"
#include "TExaS.h"

void DisableInterrupts(void);
void EnableInterrupts(void);
void delay(unsigned long msec);
int main(void){ 
	 
  TExaS_Init(SW_PIN_PE3210, DAC_PIN_PB3210,ScopeOn); // activate PLL @ 80 MHz, initiates TExaS SW for Dubugging.
   
  Sound_Init();																			 // initialize SysTick timer and DAC
  Piano_Init(); 																		 // initialize pushbuttons interfcace
  EnableInterrupts();
  while(1){             
// input from keys to select tone
		if (Piano_In()>0){Sound_Tone(Piano_In());}  		//Output of fn Piano is the reload value of the SysTick Countdown 
		else{Sound_Off();GPIO_PORTF_DATA_R&=~0x02;} 		//Turn off heartbeat & Sound
  }
}

