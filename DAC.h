// DAC.h
// Runs on LM4F120 or TM4C123, 
// Header file for the 4-bit digital to analog converter

// **************DAC_Init*********************
// Initialize 4-bit DAC
void DAC_Init(void);


// **************DAC_Out*********************
// output to DAC
// Input: 4-bit data, 0 to 15 
void DAC_Out(unsigned long data);
  


