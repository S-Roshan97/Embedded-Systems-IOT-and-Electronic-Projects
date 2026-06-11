  
  int RedLed = 12;
  int BlueLed = 10;
  int Buzzer = 4;
  int MQ6GasSensor = A5;
  
  // Your threshold value
  int sensorThres = 300;
  
  void setup() {
    pinMode(RedLed, OUTPUT);
    pinMode(BlueLed, OUTPUT);
    pinMode(Buzzer, OUTPUT);
    pinMode(MQ6GasSensor, INPUT);
    Serial.begin(9600);
  }
  void loop() {
    int analogSensor = analogRead(MQ6GasSensor);
    Serial.print("Pin A0: ");
    Serial.println(analogSensor);
    // Checks if it has reached the threshold value
    if (analogSensor > sensorThres)
    {
      digitalWrite(RedLed, HIGH);
      digitalWrite(BlueLed, LOW);
      tone(Buzzer, 500, 200);
    }
    else
    {
      digitalWrite(RedLed, LOW);
      digitalWrite(BlueLed, HIGH);
      noTone(Buzzer);
    }
    delay(100);
  }
  
  
  
  
