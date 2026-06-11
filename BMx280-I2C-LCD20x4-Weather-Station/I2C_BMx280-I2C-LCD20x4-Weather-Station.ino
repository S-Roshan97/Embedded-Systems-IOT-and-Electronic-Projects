#include <Wire.h>


#include "Wire.h" // For I2C
#include "LCD.h" // For LCD
#include "LiquidCrystal_I2C.h"
char formattedValue[5];

#include <Arduino.h>
#include <BMx280MI.h>
#define I2C_ADDRESS 0x76
BMx280I2C bmx280(I2C_ADDRESS);
// Added library*
//Set the pins on the I2C chip used for LCD connections
//ADDR,EN,R/W,RS,D4,D5,D6,D7

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7); // 0x27 is the default I2C bus address of the backpack-see article
void setup()
{

  // put your setup code here, to run once:
  Serial.begin(9600);

  //wait for serial connection to open (only necessary on some boards)
  while (!Serial);

  Wire.begin();

  //begin() checks the Interface, reads the sensor ID (to differentiate between BMP280 and BME280)
  //and reads compensation parameters.
  if (!bmx280.begin())
  {
    Serial.println("begin() failed. check your BMx280 Interface and I2C Address.");
    while (1);
  }

  if (bmx280.isBME280())
    Serial.println("sensor is a BME280");
  else
    Serial.println("sensor is a BMP280");

  //reset sensor to default parameters.
  bmx280.resetToDefaults();

  //by default sensing is disabled and must be enabled by setting a non-zero
  //oversampling setting.
  //set an oversampling setting for pressure and temperature measurements.
  bmx280.writeOversamplingPressure(BMx280MI::OSRS_P_x16);
  bmx280.writeOversamplingTemperature(BMx280MI::OSRS_T_x16);

  //if sensor is a BME280, set an oversampling setting for humidity measurements.
  if (bmx280.isBME280())
    bmx280.writeOversamplingHumidity(BMx280MI::OSRS_H_x16);

lcd.setBacklightPin(3, POSITIVE); // BL, BL_POL
 lcd.setBacklight(HIGH);  
 // 16 x 2 LCD module

}
void loop()
{
  lcd.begin (20, 4);
  int P = bmx280.getPressure();
  int T = bmx280.getTemperature();
  
  if (!bmx280.measure())
  {
    Serial.println("could not start measurement, is a measurement already running?");
    return;
  }
  delay(10);
  do
  {
    delay(10);
  }
  while (!bmx280.hasValue());

  
  lcd.print("P=>");
  sprintf(formattedValue, "%04d", P) ;
  lcd.print(formattedValue);
  lcd.setCursor(0, 1);
  lcd.print("T=>");
  sprintf(formattedValue, "%04d", T);
  lcd.print(formattedValue);
  lcd.setCursor(0, 2);
  delay(500);
 
}
