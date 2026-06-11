int timer = 50;

void setup() {
  for (int thisPin = 2; thisPin <= 11; thisPin++)
  {
    pinMode(thisPin ,OUTPUT);
  }
}

void loop() {
  // loop from the lowest to the highest:
  for(int thisPin = 2; thisPin <=11; thisPin++)
  {
    digitalWrite(thisPin, HIGH);
    delay(timer);
    digitalWrite(thisPin, LOW);
  }
  //loop from the highest to the lowest:
  for( int thisPin = 11; thisPin >= 2;thisPin--)
  {
    digitalWrite(thisPin, HIGH);
    delay(timer);
    digitalWrite(thisPin, LOW);
  }
}
