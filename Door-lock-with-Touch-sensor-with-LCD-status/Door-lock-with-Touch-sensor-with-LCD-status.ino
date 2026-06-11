#include <LCD.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

//I2C pins declaration
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
const int servoPin = 3; // Servo pin
const int touchPin = 7; // Pushtouch pin
int ledPin = 10;
int touchState = 0;
int directionState = 0;
Servo myservo;
int pos = 0;
void setup() {
  lcd.begin(16, 2);
  lcd.print(" Touch Based");
  lcd.setCursor(0, 1);
  lcd.print("Door Lock System");
  myservo.attach(3);
  pinMode(touchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}
void loop() {
  touchState = digitalRead(touchPin);
  if (directionState == 0) {
    if (touchState == HIGH) {
      directionState = 1;
      for (pos = 0; pos < 180; pos += 1)
        digitalWrite(ledPin, 1);
      lcd.clear();
      lcd.print("Status: Unlocked");
      lcd.setCursor(0, 1);
      lcd.print("Touch to Lock");
      delay(100);
      {
        myservo.write(pos);
        delay(5); // waits 15ms to reach the position
      }
    }
  } else if (directionState == 1) {
    if (touchState == HIGH) {
      directionState = 0;
      for (pos = 180; pos >= 1; pos -= 1)
        digitalWrite(ledPin, 0);
      lcd.clear();
      lcd.print("Status: Locked %");
      lcd.setCursor(0, 1);
      lcd.print("Touch to Unlock");
       delay(100);
      {
        myservo.write(pos);
        delay(5);
      }
    }
  }
}
