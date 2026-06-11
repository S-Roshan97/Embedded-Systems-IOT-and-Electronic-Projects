from machine import Pin, I2C
import ssd1306
from hcsr04 import HCSR04
from time import sleep

# Initialize I2C for SSD1306 OLED
i2c = I2C(0, scl=Pin(5), sda=Pin(4))
oled = ssd1306.SSD1306_I2C(128, 64, i2c, addr=0x3C)

# Initialize HC-SR04 Ultrasonic Sensor
sensor = HCSR04(trigger_pin=27, echo_pin=28, echo_timeout_us=10000)

MAX_DISTANCE = 20   # cm — full-scale distance on bar
SMOOTH_STEPS = 10   # number of animation steps
SLEEP_STEP = 0.05   # delay between animation frames

sleep(1)
old_bar_width = 0

while True:
    try:
        # Get new distance reading
        distance = sensor.distance_cm()
        inches = distance / 2.54  # convert to inches
        print("Distance: {:.2f} cm | {:.2f} in".format(distance, inches))

        # Map distance to bar width (0–128 pixels)
        new_bar_width = int((distance / MAX_DISTANCE) * 128)
        new_bar_width = max(0, min(128, new_bar_width))

        # Smooth animation
        step = (new_bar_width - old_bar_width) / SMOOTH_STEPS
        for i in range(SMOOTH_STEPS + 1):
            current_width = int(old_bar_width + step * i)

            # Clear OLED
            oled.fill(0)
            oled.text("Distance:", 0, 5)
            oled.text("{:.1f} cm".format(distance), 0, 20)
            oled.text("{:.1f} in".format(inches), 0, 30)

            # Draw bar outline
            y = 45
            for x in range(0, 128):
                oled.pixel(x, y, 1)
                oled.pixel(x, y + 9, 1)
            for dy in range(0, 10):
                oled.pixel(0, y + dy, 1)
                oled.pixel(127, y + dy, 1)

            # Draw filled portion
            for x in range(1, current_width - 1):
                for dy in range(1, 9):
                    oled.pixel(x, y + dy, 1)

            oled.show()
            sleep(SLEEP_STEP)

        old_bar_width = new_bar_width

    except OSError as e:
        print("Error:", e)
        oled.fill(0)
        oled.text("Sensor Error", 0, 20)
        oled.show()
        sleep(1)
