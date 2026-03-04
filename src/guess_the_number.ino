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
