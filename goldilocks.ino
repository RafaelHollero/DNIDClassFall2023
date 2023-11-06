// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int PIN_RED = 6;
const int PIN_GREEN = 8;
const int PIN_BLUE = 7;

bool playSound = true;
bool writeEnabled = true;
bool button1Enabled = true;
bool button2Enabled = true;
bool button3Enabled = true;


  // set up the LCD's number of columns and rows:
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode(13, INPUT);
  pinMode(10, INPUT);
  pinMode(9, INPUT);
  pinMode(PIN_RED,   OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE,  OUTPUT);
  Serial.begin(9600);
}

void tasting_screen() {
    lcd.setCursor(0, 0);
    lcd.print("Tasting.        ");
    lcd.setCursor(0, 1);
    lcd.print("        ");
    delay(1000);
    lcd.setCursor(8, 0);
    lcd.print(".");
    delay(1000);
    lcd.setCursor(9, 0);
    lcd.print(".");
    delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int switchState1 = digitalRead(13);
  int switchState2 = digitalRead(10);
  int switchState3 = digitalRead(9);
  if(switchState1 == 1 && button1Enabled)
  {
    tasting_screen();
    lcd.setCursor(0, 0);
    lcd.print("Too hot!        ");
    lcd.setCursor(0, 1);
    lcd.print("        ");
    button1Enabled = false;
    button2Enabled = false;
    button3Enabled = false;
    analogWrite(PIN_RED,   200);
    analogWrite(PIN_GREEN, 0);
    analogWrite(PIN_BLUE,  0);
    if(playSound)
    {
      Serial.println("hot");
      playSound = false;
      delay(50);
      writeEnabled = true;
    }
    delay(3500);
  }
  else if (switchState2 == 1 && button2Enabled)
  {
    tasting_screen();
    lcd.setCursor(0, 0);
    lcd.print("Too cold!        ");
    lcd.setCursor(0, 1);
    lcd.print("        ");
    button1Enabled = false;
    button2Enabled = false;
    button3Enabled = false;
    analogWrite(PIN_RED,   0);
    analogWrite(PIN_GREEN, 0);
    analogWrite(PIN_BLUE,  200);
    if(playSound)
    {
      Serial.println("cold");
      playSound = false;
      delay(50);
      writeEnabled = true;
    }
    delay(2000);
  }
  else if (switchState3 == 1 && button3Enabled)
  {
    tasting_screen();
    lcd.setCursor(0, 0);
    lcd.print("Just right!       ");
    lcd.setCursor(0, 1);
    lcd.print("        ");
    button1Enabled = false;
    button2Enabled = false;
    button3Enabled = false;
    analogWrite(PIN_RED,   0);
    analogWrite(PIN_GREEN, 255);
    analogWrite(PIN_BLUE,  0);
    if(playSound)
    {
      Serial.println("right");
      playSound = false;
      delay(50);
      writeEnabled = true;
    }
    delay(2000);
  }
  else
  {
    lcd.setCursor(0, 0);
    lcd.print("Try a porridge!  ");
    button1Enabled = true;
    button2Enabled = true;
    button3Enabled = true;
    analogWrite(PIN_RED,   0);
    analogWrite(PIN_GREEN, 0);
    analogWrite(PIN_BLUE,  0);
    playSound = true;
    if(writeEnabled)
    {
      Serial.println("off");
      writeEnabled = false;
    }
  }
  
}