#include "Wire.h"
#include "LCD.h"
#include "LiquidCrystal_I2C.h"
#include <NewPing.h>


#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

char formattedValue[5];

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7);
void setup()
{
  Serial.begin(115200);

  lcd.begin (16, 2);
  lcd.setBacklightPin(3, POSITIVE);
  lcd.setBacklight(HIGH);


}
void loop()
{
  delay(50);

  Serial.print(sonar.ping_cm());
  lcd.setCursor(3, 0);
  lcd.print("<Distance>");
  lcd.setCursor(9, 1);
  lcd.print("cm");

  int a3Value = (sonar.ping_cm());
  lcd.setCursor(5, 1);
  sprintf(formattedValue, "%03d", a3Value);
  lcd.print(formattedValue);
}
