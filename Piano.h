// Piano.h
// Runs on LM4F120 or TM4C123,
// There are four keys in the piano

// **************Piano_Init*********************
// Initialize piano key inputs
void Piano_Init(void); 
  

// **************Piano_In*********************
// Input from piano key inputs
// Output: 0 to 15 depending on keys
// 0x01 is key 0 pressed, 0x02 is key 1 pressed,
// 0x04 is key 2 pressed, 0x08 is key 3 pressed
unsigned long Piano_In(void);
