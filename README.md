# ⚡ Embedded Systems, IoT & Electronic Projects

A collection of **Embedded Systems, IoT, and Electronics Projects** focused on sensors, automation, robotics, and real-world hardware applications.

This repository demonstrates practical implementations using Arduino, ESP32, Raspberry Pi Pico, MicroPython, and various sensor modules along with circuit designs and code examples suitable for beginners, hobbyists, and electronics enthusiasts.

---

## 🚀 Projects Included

### 🌡️ 1. BMP280 Weather Monitor with LCD
**Folder:** `BMP280-with-LCD-Temperature-Pressure-Altitude-Monitor`

Reads temperature, atmospheric pressure, and altitude from a BMP280 sensor and displays real-time values on an I2C LCD display. Includes two variants: one using SPI communication and one using I2C.

- **Sensor:** Adafruit BMP280
- **Display:** I2C LCD (16×2 / 20×4)
- **Libraries:** `Adafruit_BMP280`, `LiquidCrystal_I2C`

---

### 🌦️ 2. BMx280 Weather Station (I2C + 20×4 LCD)
**Folder:** `BMx280-I2C-LCD20x4-Weather-Station`

Extended weather station using the BMx280MI library for broader BME/BMP280 compatibility. Displays temperature, pressure, and altitude on a 20×4 LCD display.

- **Sensor:** BMx280 (I2C, address 0x76)
- **Display:** I2C 20×4 LCD
- **Libraries:** `BMx280MI`, `LiquidCrystal_I2C`

---

### 🌈 3. TCS34725 Color Sensor with RGB LED
**Folder:** `TCS34725-Color-Sensor-with-RGB-LED`

Reads color data from the TCS34725 sensor and controls an RGB LED to visually match the detected color.

- **Sensor:** Adafruit TCS34725
- **Output:** RGB LED response
- **Libraries:** `Adafruit_TCS34725`

---

### 🎨 4. TCS34725 Color Sensor with Lux Measurement
**Folder:** `TCS34725RGB-Color-Sensor-with-Lux-Measurement-Arduino`

Extends the color sensor project with Lux (light intensity) and color temperature (Kelvin) measurement, reported over Serial Monitor.

- **Sensor:** Adafruit TCS34725
- **Output:** Serial Monitor (RGB, Lux, Color Temp)
- **Libraries:** `Adafruit_TCS34725`

---

### ☀️ 5. SI1145 UV Index Monitor
**Folder:** `Arduino-SI1145UV-Index-Monitor`

Measures UV index using the SI1145 sensor and displays categorized UV levels (Low / Medium / High / Extreme) on a 16×2 I2C LCD.

- **Sensor:** SI1145
- **Display:** I2C 16×2 LCD
- **Libraries:** `Adafruit_SI1145`, `LiquidCrystal_I2C`

---

### 📏 6. Ultrasonic Distance Display System
**Folder:** `Arduino-Real-Time-Distance-Display-System`

Real-time distance measurement using HC-SR04 ultrasonic sensor displayed on a 16×2 I2C LCD.

- **Sensor:** HC-SR04 (via `NewPing`)
- **Display:** I2C 16×2 LCD
- **Libraries:** `NewPing`, `LiquidCrystal_I2C`

---

### 🚨 7. Ultrasonic Distance Alarm System
**Folder:** `HC-SR04-Ultrasonic-Distance-Alarm-System`

Triggers a buzzer alarm when an object comes within 50 cm of the sensor. Useful for security or parking assistance.

- **Sensor:** HC-SR04 (via `NewPing`)
- **Output:** Buzzer
- **Use Case:** Proximity alarm, parking sensor

---

### 🤖 8. Ultrasonic Servo Control System
**Folder:** `HC-SR04-Ultrasonic-Servo-Control-System`

Controls a servo motor angle based on detected distance — enabling automatic gate or smart door applications.

- **Sensor:** HC-SR04 (via `NewPing`)
- **Output:** Servo motor
- **Use Case:** Automatic gate, smart door

---

### 🎮 9. IR Remote Servo Control System
**Folder:** `IR-Remote-Servo-Control-System`

Controls a servo motor to 0°, 90°, or 180° positions using an IR remote control, with support for repeat-key behavior.

- **Module:** IR Receiver + Servo Motor
- **Libraries:** `IRremote`, `Servo`

---

### ❤️ 10. Pulse Sensor Heart Rate Monitor
**Folder:** `Arduino-Pulse-Sensor-Heart-Rate-BPM-Monitor`

Reads BPM from an analog pulse sensor and displays it on an I2C LCD with a custom animated heart character.

- **Sensor:** Analog pulse sensor (pin A0)
- **Display:** I2C LCD with custom heart animation
- **Libraries:** `LiquidCrystal_I2C`

---

### ✋ 11. APDS9960 Gesture Recognition
**Folder:** `APDS9960-Gesture-Recognition-with-20x4LCD`

Detects hand gestures (UP, DOWN, LEFT, RIGHT) using the APDS9960 sensor and displays results on a 20×4 LCD.

- **Sensor:** APDS9960
- **Display:** I2C 20×4 LCD
- **Libraries:** `Adafruit_APDS9960`, `LiquidCrystal_I2C`

---

### 🔐 12. Touch-Based Door Lock System
**Folder:** `Door-lock-with-Touch-sensor-with-LCD-status`

Uses a touch sensor to toggle a servo motor between locked and unlocked positions, with LCD status display.

- **Input:** Touch sensor (digital)
- **Output:** Servo motor + I2C 16×2 LCD
- **Libraries:** `Servo`, `LiquidCrystal_I2C`

---

### 🔥 13. Fire Alarm System with IR Sensor
**Folder:** `Fire-Alarm-System-with-IR-Sensor`

Triggers a buzzer alarm when the IR flame sensor detects fire. Simple digital input/output implementation.

- **Sensor:** IR Flame sensor
- **Output:** Buzzer

---

### 💨 14. Gas Leakage Detector Alarm System
**Folder:** `Gas-Leakage-Detector-Alarm-System-Using-Arduino-Nano`

Reads gas concentration from an MQ-6 sensor on an Arduino Nano. Triggers a red LED and buzzer alarm when the level exceeds a threshold, and lights a blue LED when safe.

- **Sensor:** MQ-6 Gas Sensor (analog, pin A5)
- **Output:** Red LED, Blue LED, Buzzer
- **Platform:** Arduino Nano

---

### 🎹 15. Arduino Piano
**Folder:** `Arduino Piano with Arduino`

8-key piano using push buttons and a passive piezo buzzer. Each button maps to a musical note (C, D, E, F, G, A, B, C).

- **Input:** 8 push buttons (pins 2–9)
- **Output:** Passive buzzer (pin 12)

---

### 💡 16. 10-LED Random Flicker Effect
**Folder:** `10-LED-Random-Flicker-Arduino`

Randomly turns LEDs on and off across 10 pins with randomized timing to create a flickering candle/fire effect.

- **Output:** 10 LEDs (pins 2–11)

---

### 🏎️ 17. Knight Rider LED Scanner Effect
**Folder:** `Knight-Rider-LED-Scanner-Effect`

Classic back-and-forth scanning LED effect across 10 LEDs, mimicking the iconic KITT scanner from Knight Rider.

- **Output:** 10 LEDs (pins 2–11)

---

### 🌈 18. WS2812 RGB LED Demo Reel (FastLED)
**Folder:** `DemoReel100_WS2812 with Arduino`

FastLED DemoReel100 demo showcasing multiple animation patterns (rainbow, confetti, sinelon, juggle, BPM) on a 24-pixel WS2812 LED ring/strip.

- **Hardware:** WS2812 LED strip (24 LEDs, data pin 6)
- **Libraries:** `FastLED`

---

### 🌐 19. ESP32 Web Server – LED & Fan Control
**Folder:** `Create-A-Simple-ESP32-Web-Server-LED-Fan-Control`

ESP32 hosted in Access Point mode serving a web interface to toggle an LED and a relay (fan/appliance). Connect to the ESP32's WiFi hotspot and control from any browser.

- **Platform:** ESP32
- **Features:** WiFi Access Point, HTTP web server, LED + Relay control
- **Libraries:** `WiFi`, `WebServer`
- 📺 [YouTube Demo](https://youtu.be/2GL9-OlBlc8) | [YouTube Short](https://youtube.com/shorts/Vb1_ktTgZTs)

---

### 🌐 20. ESP32-C3 WiFi Web Server Smart Control System
**Folder:** `ESP32-C3-WiFi-Web-Server-Smart-Control-System`

Updated web server project optimized for the **ESP32-C3 Super Mini**. Controls an on-board LED (GPIO8) and an external relay (GPIO5) via a styled web dashboard.

- **Platform:** ESP32-C3 Super Mini
- **Features:** WiFi AP mode (192.168.4.1), LED + Relay toggle
- **Libraries:** `WiFi`, `WebServer`

---

### 📶 21. ESP32 WiFi Scanner with OLED Display
**Folder:** `ESP32-WiFi-Scanner-with-SSD1306-OLED-Display`

Scans nearby WiFi networks and displays each SSID and signal strength (RSSI) on an SSD1306 128×64 OLED display.

- **Platform:** ESP32
- **Display:** SSD1306 OLED (128×64, I2C address 0x3C)
- **Libraries:** `WiFi`, `Adafruit_SSD1306`, `Adafruit_GFX`

---

### 📊 22. Raspberry Pi Pico – Real-Time Distance Visualizer (MicroPython)
**Folder:** `Rasberry-pico-Real-Time-Distance-Measurement with-SSD1306 OLED`

MicroPython project for the Raspberry Pi Pico. Measures distance with HC-SR04 and renders a smooth animated bar graph on a 128×64 SSD1306 OLED display.

- **Platform:** Raspberry Pi Pico
- **Language:** MicroPython
- **Sensor:** HC-SR04 (trigger GPIO27, echo GPIO28)
- **Display:** SSD1306 OLED (I2C: SCL GPIO5, SDA GPIO4)
- **Files:** `main.py`, `hcsr04.py`, `ssd1306.py`

---

## 🧰 Components Used

| Category | Parts |
|---|---|
| **Microcontrollers** | Arduino UNO / Nano, ESP32, ESP32-C3 Super Mini, Raspberry Pi Pico |
| **Sensors** | BMP280, BMx280, TCS34725, SI1145, HC-SR04, APDS9960, MQ-6, IR Flame Sensor, Pulse Sensor |
| **Displays** | SSD1306 OLED (128×64), I2C LCD 16×2, I2C LCD 20×4 |
| **Actuators** | Servo Motor, Relay Module, Passive Buzzer, WS2812 RGB LED Strip |
| **Input Modules** | IR Receiver, Touch Sensor, Push Buttons |
| **Passive Components** | LEDs, Resistors, Breadboard, Jumper Wires |

---

## 🛠️ Technologies & Skills

- Arduino C / C++
- MicroPython
- Embedded Systems Design
- IoT Web Server Programming (ESP32)
- I2C & SPI Communication
- PWM & Servo Control
- Sensor Interfacing & Calibration
- Serial Communication & Debugging
- FastLED Animation Programming

---

## 🎯 Purpose of This Repository

This repository is created for:

- Learning Embedded Systems & IoT development hands-on
- Sensor integration and hardware interfacing practice
- Automation and smart system design examples
- Portfolio showcase for electronics engineering projects

---

## 🚀 Future Improvements

- Cloud IoT integration (Firebase / MQTT)
- Mobile app control (Bluetooth / WiFi)
- Real-time data dashboards
- AI-based sensor analysis
- Advanced robotics projects

---

## 👨‍💻 Author

**Arduino & Embedded Systems Projects by Sivasangar Roshan**
