  
  #include <SPI.h>
  #include <Adafruit_Sensor.h>
  #include <Adafruit_BMP280.h>
  #include "Wire.h"
  #include "LCD.h"
  #include "LiquidCrystal_I2C.h"
  int i;
  
  LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7);
  #define BMP_SCK 13
  #define BMP_MISO 12
  #define BMP_MOSI 11
  #define BMP_CS 10
  Adafruit_BMP280 bme;
  
  
  void setup()
  {
  
    lcd.begin (20, 4);
    lcd.setBacklightPin(3, POSITIVE);
    lcd.setBacklight(HIGH);
    Serial.begin(9600);
    Serial.println(F("BMP280 test"));
    if (!bme.begin()) {
      Serial.println("Could not find a valid BMP280 sensor, check wiring!");
      while (1);
    }
  }
  void loop()
  {
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" *C");
    Serial.print("Pressure = ");
    Serial.print(bme.readPressure());
    Serial.println(" Pa");
    Serial.print("Approx altitude = ");
    Serial.print(bme.readAltitude(1010.00));
    Serial.println(" m");
    Serial.println();
    lcd.clear();
  
    lcd.setCursor(0, 0);
    lcd.print(bme.readPressure());
  
    lcd.setCursor(12, 0);
    lcd.print(bme.readAltitude(1011.60));
  
    lcd.setCursor(0, 1);
    lcd.print("  Pa          m");
  
    lcd.setCursor(1, 3 );
    lcd.print(bme.readTemperature());
  
    lcd.setCursor(5, 3);
    lcd.print(" ^C");
  
    lcd.setCursor(13, 3 );
    i = (bme.readTemperature() * 9 / 5 + 32);
    lcd.print(i);
    lcd.setCursor(15, 3);
    lcd.print(" F");
    delay(2000);
  }
