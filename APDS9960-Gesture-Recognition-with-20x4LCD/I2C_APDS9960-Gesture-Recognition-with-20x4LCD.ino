#include "Wire.h"
#include "LCD.h"
#include "LiquidCrystal_I2C.h"
#include "Adafruit_APDS9960.h"
Adafruit_APDS9960 apds;

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7);

void setup()
{
  Serial.begin(115200);

  if (!apds.begin()) {
    Serial.println("failed to initialize device! Please check your wiring.");
  }
  else Serial.println("Device initialized!");

  apds.enableProximity(true);
  apds.enableGesture(true);

  lcd.begin (16, 2);
  lcd.setBacklightPin(3, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.print("   Hello, World!");
  lcd.setCursor(0, 1);
  lcd.print("Gesture direction==>");
  lcd.setCursor(0, 2);

}
void loop()
{
  uint8_t gesture = apds.readGesture();
  if (gesture == APDS9960_DOWN)   lcd.print(" DOWN=v ");
  lcd.setCursor(6, 2);
  if (gesture == APDS9960_UP)   lcd.print(" UP=^   ");
  lcd.setCursor(6, 2);
  if (gesture == APDS9960_LEFT) lcd.print("<=LEFT ");
  lcd.setCursor(6, 2);
  if (gesture == APDS9960_RIGHT)lcd.print("RIGHT=>");
  lcd.setCursor(6, 2);
}
