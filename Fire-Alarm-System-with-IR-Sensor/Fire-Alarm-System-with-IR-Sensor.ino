
int sensor = 2;
int buzzer = 11;

void setup()
{
  pinMode(sensor, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  if (digitalRead(sensor) == LOW)
  {
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(100);
  }
  else
  {
    digitalWrite(buzzer, LOW);
  }
}
