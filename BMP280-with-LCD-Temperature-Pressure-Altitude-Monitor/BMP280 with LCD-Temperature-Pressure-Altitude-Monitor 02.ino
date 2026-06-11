
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include "Wire.h" // For I2C
#include "LCD.h" // For LCD
#include "LiquidCrystal_I2C.h" 
// Set the LCD address to 0x27 or 0x3f for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7);
#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11
#define BMP_CS 10
Adafruit_BMP280 bme; // I2C if this is definded we use i2c communication
//Adafruit_BMP280 bme(BMP_CS); // hardware SPI
//Adafruit_BMP280 bme(BMP_CS, BMP_MOSI, BMP_MISO, BMP_SCK);
void setup() {

   lcd.begin (20,4); // 16 x 2 LCD module
   lcd.setBacklightPin(3,POSITIVE); // BL, BL_POL
   lcd.setBacklight(HIGH);
  Serial.begin(9600);
  Serial.println(F("BMP280 test"));
  if (!bme.begin()) {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
  }
}
void loop() {
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");
  Serial.print("Pressure = ");
  Serial.print(bme.readPressure());
  Serial.println(" Pa");
  Serial.print("Approx altitude = ");
  Serial.print(bme.readAltitude(1013.25)); // this should be adjusted to your local forcase
  Serial.println(" m");
  Serial.println();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(bme.readPressure());
  lcd.setCursor(12, 0);
  lcd.print(bme.readAltitude(1008.70));
  lcd.setCursor(0, 1);
  lcd.print("  Pa          m");
  lcd.setCursor(1,3 );
  lcd.print(bme.readTemperature());
   lcd.setCursor(5, 3);
  lcd.print(" ^C");
  delay(2000);
}
