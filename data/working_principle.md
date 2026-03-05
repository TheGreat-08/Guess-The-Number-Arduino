## Working Principle

The Guess the Number system is implemented using an Arduino Uno. The system allows the user to play a number guessing game using a keypad, LCD display, and LEDs.

When the program starts, the LCD displays a welcome message and asks the user to press 'D' to start the game. After starting, the system provides two modes of operation.

Mode A – Random Mode:
In this mode, the Arduino generates a random secret number between 1 and 99. The player must guess the number using the keypad.

Mode B – Set Number Mode:
In this mode, Player 1 enters a secret number using the keypad. The number is hidden on the LCD using '*' symbols. The system then asks Player 2 to guess the number.

The guessed number entered through the keypad is read by the Arduino and compared with the secret number.

If the guessed number is equal to the secret number, the system displays a success message on the LCD and the green LED turns ON indicating the correct guess.

If the guessed number is very close to the secret number (difference less than or equal to 5), the system displays "So Close!" and the orange LED turns ON.

If the guessed number is far from the secret number, the system displays a hint message. If the guess is smaller than the secret number, the LCD displays "Higher". If the guess is larger than the secret number, the LCD displays "Lower". In these cases, the red LED turns ON.

The player has a limited number of attempts to guess the correct number. The game continues until the correct number is guessed or the attempts are exhausted.

This system demonstrates user interaction, keypad input handling, decision making, and basic game logic using Arduino.
