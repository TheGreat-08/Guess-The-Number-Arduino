# Hardware Setup
# Overview

This document explains the hardware components and wiring connections used to implement the Guess The Number game using an Arduino-based embedded system.
The system uses a 4×4 keypad for user input, an LCD display for feedback messages, and LED indicators to provide visual hints about the guessed number.

# Hardware Components

Arduino Uno	                 1	     -   Main microcontroller used to control the system,
4×4 Matrix Keypad	           1	     -   Used for entering numbers and selecting game mode,
16×2 LCD Display (I2C)	     1	     -   Displays instructions and hints,
Red LED	                     1	     -   Indicates guess is higher than the target number,
Yellow LED	                 1	     -   Indicates guess is very close to the target,
Green LED	                   1	     -   Indicates the correct guess,
Resistors (220Ω)	           3	     -   Used to limit current for LEDs,
Breadboard	                 1	     -   Used for circuit connections,
Jumper Wires	                       -   Several	Used for connecting components 

# Pin Configuration

Arduino to Keypad Connection:
Row 1	         -        Pin 9,
Row 2          -        Pin 8,
Row 3	         -        Pin 7,
Row 4	         -        Pin 6,
Column 1	     -        Pin 5,
Column 2	     -        Pin 4,
Column 3	     -        Pin 3,
Column 4       -        Pin 2

The keypad allows the user to input numbers and control commands for the game.

Arduino to LCD (I2C) Connection
VCC	     -     5V,
GND	     -     GND,
SDA	     -     A4,
SCL	     -     A5

The LCD module communicates with the Arduino using the I2C protocol, reducing the number of required wires.

Arduino to LED Connections

Red LED	     -     Pin 10	  -          Indicates guess is too high,
Yellow LED	 -     Pin 11	  -          Indicates guess is close,
Green LED	   -     Pin 12	  -          Indicates correct guess

Each LED is connected in series with a 220Ω resistor to prevent excessive current flow.

# Circuit Setup

Follow these steps to assemble the hardware:

Place the Arduino Uno on the workspace.
Connect the 4×4 keypad rows and columns to the Arduino digital pins.
Connect the LCD display using the I2C interface:

VCC → 5V,
GND → GND,
SDA → A4,
SCL → A5

Connect the LEDs:

Connect the anode of each LED to the Arduino pin.
Connect the cathode through a 220Ω resistor to GND.
Ensure all connections are secure before powering the system.

# Hardware Working Principle

The hardware operates through interaction between input, processing, and output devices:
The keypad sends user input to the Arduino.
The Arduino processes the guess and compares it with the stored number.

The LCD displays hints such as:

Higher
Lower
So Close
Correct

The LEDs provide visual feedback based on the result of the comparison.
This combination of hardware components enables an interactive number guessing game.

# Simulation Platform

The hardware circuit was tested using:

TinkerCad Arduino Simulator
This platform allows testing of the circuit and code before implementing it on physical hardware.

# Conclusion

The hardware setup integrates input devices, processing hardware, and output indicators to create an interactive embedded system. The combination of Arduino, keypad, LCD, and LED indicators ensures clear communication between the system and the user during gameplay.
