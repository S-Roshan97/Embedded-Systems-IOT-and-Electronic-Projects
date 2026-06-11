#include "Wire.h" // For I2C
#include "LCD.h" // For LCD
#include "LiquidCrystal_I2C.h" 
 
// Include Adafruit SI1145 Library
#include <Adafruit_SI1145.h>

 
 
// Define object lcd
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7);
 
// Define object uv
Adafruit_SI1145 uv = Adafruit_SI1145();
 
void setup()
{
   lcd.setBacklightPin(3,POSITIVE); // BL, BL_POL
   lcd.setBacklight(HIGH);
  // Set display type as 16 char, 2 rows
  lcd.begin(16,2);
  
  // Initialize UV sensor
  uv.begin();
 
}
 
void loop() {
  
  // Read UV level
  float UVindex = uv.readUV();
  // Divide by 100 for UV index
  UVindex /= 100.0; 
      
  // Display UV Index on LCD
  
  // Clear the display
    lcd.clear();
    
  // Print on top line
  lcd.setCursor(0,0);
  lcd.print("UV Index: ");
  lcd.print(UVindex);
  
  // Print bottom line
  lcd.setCursor(0,1);
  
  if (UVindex < 3.0) 
  {
    lcd.print("Low UV Level");
  }
   else if (UVindex >= 3 && UVindex < 6) 
  {
    lcd.print("Medium UV Level"); 
  } 
   else if (UVindex >= 6 && UVindex < 8) 
  {
    lcd.print("High UV Level"); 
  } 
   else
  {
    lcd.print("Extreme UV Level");  
  }    
  
  delay(1000);
}
