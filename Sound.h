// Sound.h
// Runs on LM4F120 or TM4C123,
// Use the SysTick timer to request interrupts at a particular period.

// **************Sound_Init*********************
// Initialize Systick periodic interrupts
// Also initializes DAC
void Sound_Init(void);

// **************Sound_Tone*********************
// Change SysTick periodic interrupts to start sound output
// Input: interrupt period
//           Units of period are 12.5ns
//           Maximum is 2^24-1
//           Minimum is determined by length of ISR
void Sound_Tone(unsigned long period);


// **************Sound_Off*********************
// stop outputing to DAC
// Output: none
void Sound_Off(void);

