// initialization 
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);

// keypad init
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// LED pins
#define GREEN 11
#define RED 12
#define ORANGE 13

// variables
String inputNumber = "";
int secretNumber = 0;
int tries = 5;

bool gameStarted = false;
bool waitingForUser1 = false;
bool waitingForGuess = false;
bool gameEnded = false;
char currentMode = ' ';

void setup() {
  lcd.init();
  lcd.backlight();
  randomSeed(analogRead(A0));

  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(ORANGE, OUTPUT);

  clearLEDs();

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Greetings!!!");
  lcd.setCursor(0,1);
  lcd.print("Welcome Player");
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("#-->submit");
  delay(1500);

  showStartScreen();
}

void loop() {

  char key = keypad.getKey();
  if (!key) return;

  // game end
  if (gameEnded) {
    if (key == 'D') {
      gameEnded = false;
      startMode(currentMode);
    }
    else if (key == 'C') {
      resetGame();
    }
    return;
  }

  // start
  if (!gameStarted && key == 'D') {
    gameStarted = true;
    lcd.clear();
    lcd.print("A: Random");
    lcd.setCursor(0,1);
    lcd.print("B: Set Number");
    return;
  }

  // random mode
  if (gameStarted && key == 'A') {
    currentMode = 'A';
    startMode('A');
    return;
  }

  // user1 mode
  if (gameStarted && key == 'B') {
    currentMode = 'B';
    waitingForUser1 = true;
    inputNumber = "";
    lcd.clear();
    lcd.print("User1 Enter:");
    lcd.setCursor(0,1);
    return;
  }

  // user1 input
  if (waitingForUser1) {

    if (key >= '0' && key <= '9') {
      if (inputNumber.length() < 2) {
        inputNumber += key;

        lcd.setCursor(0,1);
        lcd.print("                ");
        lcd.setCursor(0,1);

        for (int i = 0; i < inputNumber.length(); i++) {
          lcd.print("*");
        }
      }
    }

    else if (key == '#') {
      if (inputNumber.length() == 0) return;

      secretNumber = inputNumber.toInt();
      waitingForUser1 = false;
      waitingForGuess = true;
      inputNumber = "";
      tries = 5;

      lcd.clear();
      lcd.print("Pass to User2");
      delay(2000);
      

      showGuessScreen();
    }
    return;
  }
// guessing
  if (waitingForGuess) {

    if (key >= '0' && key <= '9') {
      inputNumber += key;

      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      lcd.print(inputNumber);
    }

    else if (key == '#') {

      int guess = inputNumber.toInt();
      inputNumber = "";
      tries--;

      lcd.clear();
      clearLEDs();

      if (guess == secretNumber) {
        lcd.print("Correct!");
        digitalWrite(GREEN, HIGH);
        delay(2000);
        digitalWrite(GREEN, LOW);
        endGame();
        return;
      }

      int difference = abs(guess - secretNumber);

      if (difference <= 5) {
        lcd.print("So Close!");
        digitalWrite(ORANGE, HIGH);
      }
      else {
        lcd.print(guess < secretNumber ? "Higher" : "Lower");
        digitalWrite(RED, HIGH);
      }

      delay(1200);
      clearLEDs();

      if (tries == 0) {
        lcd.clear();
        lcd.print("Oops,try again!");
        lcd.setCursor(0,1);
        lcd.print("Num:");
        lcd.print(secretNumber);
        digitalWrite(RED, HIGH);
        endGame();
        return;
      }

      showGuessScreen();
    }
  }
}
