// Runs on LM4F120 or TM4C123, 
// Port E bits 3-0 have 4 piano keys

#include "Piano.h"
#include "..//tm4c123gh6pm.h"

#define C 4778  //Reload value for SysTick interrupt corresponding to the desired frequency "Tone"
#define D 4257
#define E 3792
#define G 3189

// **************Piano_Init*********************
// Initialize piano key inputs
void Piano_Init(void){volatile unsigned long delay;
SYSCTL_RCGC2_R|=SYSCTL_RCGC2_GPIOE;
delay=SYSCTL_RCGC2_R;
GPIO_PORTE_AMSEL_R&=~0x0F;
GPIO_PORTE_AFSEL_R&=~0x0F;
GPIO_PORTE_PCTL_R&=~0x0000FFFF;
GPIO_PORTE_DIR_R&=~0x0F;
GPIO_PORTE_PDR_R|=0x0F;
GPIO_PORTE_DEN_R|=0x0F;
}
// **************Piano_In*********************
//Input for Data register interfaced with the pushbuttons, 
//decides the playing note outof the available values in the array.
unsigned long Piano_In(void){unsigned long note[16]={0,C,D,0,E,0,0,0,G,0,0,0,0,0,0,0};
  return note[GPIO_PORTE_DATA_R];
}
