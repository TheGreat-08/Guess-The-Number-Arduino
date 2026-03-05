# Components Used and Explanation
1. Arduino UNO
Arduino UNO is the main controller of the system. It runs the program and processes the user’s input. It generates the random number and compares it with the guessed number entered by the user.

2. Keypad
The keypad is used by the user to enter the guessed number. The input from the keypad is sent to the Arduino for processing.

3. LCD Display (I2C)
The LCD display is used to show messages such as instructions, guessed number status, and the result (correct, higher, or lower). The I2C module helps reduce the number of connecting wires.

4. LEDs
LEDs are used as indicators in the system. They give visual feedback to the user when the guessed number is correct or incorrect.

5. Resistors
Resistors are used to limit the current flowing through the LEDs. This prevents damage to the LEDs and ensures proper operation of the circuit.

6. Breadboard
A breadboard is used to build the circuit without soldering. It helps connect all the components easily during testing and development.

7. Jumper Wires
Jumper wires are used to make electrical connections between Arduino, keypad, LEDs, LCD, and other components on the breadboard.
