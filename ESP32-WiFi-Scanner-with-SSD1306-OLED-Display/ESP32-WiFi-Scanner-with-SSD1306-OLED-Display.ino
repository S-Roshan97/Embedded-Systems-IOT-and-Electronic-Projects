#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET    -1 // Reset pin (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS  0x3C // I2C address for the OLED display

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA); // Set Wi-Fi to Station mode
  WiFi.disconnect(); // Disconnect from any previous networks
  
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (1); // Loop forever if display initialization fails
  }
  
  display.clearDisplay();
  display.setTextSize(0.8);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("     Wi-Fi Scan...");
  display.display();
}

void loop() {
  int n = WiFi.scanNetworks(); // Scan for Wi-Fi networks
  
  display.clearDisplay(); // Clear the OLED display
 
  
  if (n == 0) {
    display.setCursor(0, 0);
    display.print("  No networks found");
  } else {
    display.setCursor(0, 0);
    display.print("   Networks Found:");
    display.setCursor(0, 16); // Start from the top
    
    int networksToDisplay = (n > 5) ? 5 : n; // Display up to 5 networks
    
    for (int i = 0; i < networksToDisplay; i++) {
      String ssid = WiFi.SSID(i);
      int rssi = WiFi.RSSI(i);
      display.printf("%d:%s(%ddB)\n", i + 1, ssid.c_str(), rssi);
      display.setCursor(0, (i + 2.5) * 10);
    }
  }
  
  display.display(); // Update the display
  delay(5000); // Delay between scans
}
