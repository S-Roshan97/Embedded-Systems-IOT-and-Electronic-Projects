#include <NewPing.h>
int trig = 7;
int echo = 8;


int buzzer = 11;

NewPing sonar(trig,echo);

void setup() {
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  
  Serial.println(sonar.ping_cm());
  while(sonar.ping_cm()<=50)
  {
    digitalWrite(buzzer,HIGH);
    delay(100);
  }
  digitalWrite(buzzer,LOW);
}
