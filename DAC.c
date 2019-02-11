// Runs on LM4F120 or TM4C123, 
// Implementation of the 4-bit digital to analog converter
// Port B bits 3-0 have the 4-bit DAC

#include "DAC.h"
#include "..//tm4c123gh6pm.h"

// **************DAC_Init*********************
// Initialize 4-bit DAC
void DAC_Init(void){volatile unsigned long delay;
SYSCTL_RCGC2_R|=SYSCTL_RCGC2_GPIOB;
SYSCTL_RCGC2_R|=SYSCTL_RCGC2_GPIOF;
delay=SYSCTL_RCGC2_R;
GPIO_PORTB_AMSEL_R&=~0x0F;
GPIO_PORTB_AFSEL_R&=~0x0F;
GPIO_PORTB_PCTL_R&=~0x0000FFFF;
GPIO_PORTB_DR8R_R|=0x0F;
GPIO_PORTB_DIR_R|=0x0F;
GPIO_PORTB_DEN_R|=0x0F;

GPIO_PORTF_AMSEL_R&=~0x02;
GPIO_PORTF_AFSEL_R&=~0x02;
GPIO_PORTF_PCTL_R&=~0x000000F0;
GPIO_PORTF_DIR_R|=0x02;
GPIO_PORTF_DEN_R|=0x02;
}

// **************DAC_Out*********************
// output to DAC
// Input: 4-bit data, 0 to 15 
void DAC_Out(unsigned long data){
GPIO_PORTB_DATA_R=data;
GPIO_PORTF_DATA_R^=0x02;
}
