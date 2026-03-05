# System Design

# Overview

This document describes the testing process carried out for the Guess The Number embedded system project developed using Arduino Uno, 4×4 Keypad, 16×2 LCD (I2C), and LED indicators.
The purpose of testing is to verify that the system behaves correctly according to the project requirements and provides accurate feedback to the user.

1. The testing focuses on:
2. Keypad input detection
3. Number comparison logic
4. LCD message display
5. LED indication for hints
6. Game modes (Manual and Random)

# Testing Environment

# Component	Description
Microcontroller	Arduino Uno
Input Device	4×4 Matrix Keypad
Output Display	16×2 LCD (I2C)
Indicators	Red, Yellow, Green LEDs
Simulation	TinkerCad
Programming Language	Arduino C/C++
Test Case 1 – System Initialization
Objective: Verify that the system starts correctly.

# Parameter	Description
Test Action	Power ON the Arduino
Expected Result	LCD displays system startup message or prompt
Actual Result	LCD shows game prompt
Status	Pass
Test Case 2 – Manual Number Entry Mode
Objective: Verify that User 1 can set the secret number.

# Parameter	Description
Test Action	Press B on keypad
Expected Result	System allows User 1 to enter a secret number
Actual Result	System accepts input and stores number
Status	Pass
Test Case 3 – Random Number Mode
Objective: Verify random number generation.

# Parameter	Description
Test Action	Press A on keypad
Expected Result	Arduino generates a random number
Actual Result	Random number stored by system
Status	Pass
Test Case 4 – Guess Higher Than Target
Objective: Verify system response when guessed number is greater.

# Parameter	Description
Test Action	Enter number higher than target
Expected Result	LCD shows "Lower" and red LED turns ON
Actual Result	LCD displays Lower and red LED glows
Status	Pass
Test Case 5 – Guess Lower Than Target
Objective: Verify system response when guessed number is lower.

# Parameter	Description
Test Action	Enter number lower than target
Expected Result	LCD shows "Higher"
Actual Result	LCD displays Higher
Status	Pass
Test Case 6 – Guess Close to Target
Objective: Verify "So Close" hint.

# Parameter	Description
Test Action	Enter number near the target value
Expected Result	LCD displays "So Close" and yellow LED turns ON
Actual Result	Correct message and LED indication
Status	Pass
Test Case 7 – Correct Guess
Objective: Verify correct guess condition.

# Parameter	Description
Test Action	Enter correct number
Expected Result	LCD displays "Correct!" and green LED turns ON
Actual Result	Correct message shown and green LED glows
Status	Pass

# Testing Summary
Total Tests	Passed	Failed
7	
7	
0
(To be completed by Documentation Team)
