# System Design
# Overview

The Guess The Number system is an embedded application designed using an Arduino Uno microcontroller, a 4×4 matrix keypad, a 16×2 LCD display (I²C), and LED indicators. The system creates an interactive number guessing game where one user sets a number and another user attempts to guess it.

The system compares the guessed number with the stored number and provides feedback using both text messages on the LCD and LED indicators. The feedback helps the user adjust their guesses until the correct number is found.

This design demonstrates fundamental concepts of embedded systems, user input processing, decision logic, and hardware interfacing.

# System Architecture

The system architecture consists of three major parts:

1. Input Module
2. Processing Module
3. Output Module
          +--------------------+
          |     4x4 Keypad     |
          |   (User Input)     |
          +----------+---------+
                     |
                     v
              +-------------+
              |  Arduino    |
              |  Uno MCU    |
              | (Processing)|
              +------+------+ 
                     |
        +------------+-------------+
        |                          |
        v                          v
+---------------+           +---------------+
|   LCD Display |           | LED Indicators|
|   (Messages)  |           | Status Output |
+---------------+           +---------------+
# Hardware Components
Component	Description

Arduino Uno	Main microcontroller used for system control
4×4 Matrix Keypad	Used to enter the secret number and guess numbers
16×2 LCD Display (I²C)	Displays system messages and hints
LEDs (Red, Yellow, Green)	Provide visual feedback for different conditions
Resistors	Used to limit current for LEDs
Breadboard	Used for circuit prototyping
Jumper Wires	Used for electrical connections

# Functional Modules
1. Input Module

The 4×4 matrix keypad is used as the primary input device.
It allows the user to:

Enter the number
Enter guess values
Select game mode

Key functions:

Key	Function
A	Generate random number
B	Allow User 1 to set the number
0-99	Used for entering numbers

The keypad sends input signals to the Arduino digital pins, which are interpreted by the program.

2. Processing Module

The Arduino Uno acts as the central processing unit of the system.

Its responsibilities include:

Reading keypad input
Storing the secret number
Comparing guessed number with the stored number
Controlling LCD messages
Controlling LED indicators
Running the game loop until the correct guess is made

The program uses the following programming concepts:

Variables
Conditional statements
Loops
Input/Output handling
Comparison logic

3. Output Module

The output module provides feedback to the user through:

LCD Display
The 16×2 LCD display shows messages such as:

Enter number

Higher

Lower

So Close!

Correct

This helps guide the user during gameplay.

LED Indicators
LED Color	Meaning
Red LED	Guess is higher and lower than target
Yellow LED	Guess is so close
Green LED	Correct guess

The LEDs provide quick visual feedback.

# System Workflow

The working process of the system follows these steps:

System starts and initializes all components.

User selects the game mode:

A → Random number generation

B → Manual number entry

The secret number is stored in the system.

User enters a guess using the keypad.

The Arduino compares the guess with the stored number.

System provides feedback:

Higher

Lower

So Close

The process repeats until the correct number is guessed.

When the correct number is entered:

LCD displays “Correct!”

Green LED turns ON

Game ends.

# Design Considerations

The system design was developed with the following considerations:

User-friendly interface using keypad and LCD
Real-time feedback using LEDs
Simple logic implementation for beginners
Modular design for easy upgrades
Low hardware complexity

# Future Improvements

The system can be further improved by adding advanced features such as:

Graphical user interface
Score tracking system
Timer for guesses
Mobile or web integration
Multiplayer support
Difficulty levels

These improvements can enhance both usability and educational value.

# Conclusion

The Guess The Number system design demonstrates how embedded systems can be used to develop interactive applications. The integration of input devices, processing logic, and output modules creates a complete system capable of guiding users through the guessing process. The design effectively combines hardware and software components to create an engaging learning tool for beginners in embedded systems and programming.

