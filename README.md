# uPiano

This concept project is an independent proposition, a part of a distance online course for embedded systems and microcontrollers. 
Code writing and designing process was guided by Dr. Jonathan W Valvano. Using the following references: 
  - Introduction to the MSP432 Microcontroller-- ISBN-10: 1512185671.
  - Real-Time Interfacing to the MSP432 Microcontroller-- ISBN-10: 1514676583.
  - https://courses.edx.org/courses/course-v1:UTAustinX+UT.6.20x+2T2018/course/

# DAC Implementation:
  - Four-bit D/A creating 16 precision.
  - The sampling rate is a function of the desired sinusoidal wave.
  - DAC is triggered using SW "SysTick interrupts"
  - Calculations for the SysTick interrupt delays are attached in an Excel sheet. 

# Input Interface:
  - Four positive logic push buttons interfaced with PORT E.
  - Each button is corresponding to an individual tone.
  - 
# Debugging approach:
  - Non-intrusive debugging using Keil logic analyzer.
  - A heartbeat interfaced with the built-in LED on the launchpad, indicating functionality.
  - minimally intrusive debugging using UART serial port to plot data acquired out of the DAC.
