#include <NewPing.h>
#include <Servo.h>

int trig = 12;
int echo = 11;
int maxDistance = 200;

Servo myservoa;
NewPing sonar(trig, echo, maxDistance);

void setup() {
  myservoa.attach(9);
  Serial.begin(9600);
}

void loop() {
  int distance = sonar.ping_cm();
  Serial.println(distance);

  if (distance > 0 && distance <= 10) {
    myservoa.write(180);  // open
  } else {
    myservoa.write(0);    // close
  }

  delay(100);
}