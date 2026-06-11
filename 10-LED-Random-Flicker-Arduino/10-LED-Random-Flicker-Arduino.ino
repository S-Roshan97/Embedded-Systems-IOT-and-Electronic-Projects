int leds[10] = {2,3,4,5,6,7,8,9,10,11,};

void setup(){
  for (int jj; jj<sizeof(leds)/sizeof(int);jj++){
    pinMode(leds[jj],OUTPUT);
    delay(10);
  }
}

void loop(){
  digitalWrite(leds[random(0,sizeof(leds)/sizeof(int))],HIGH);
  delay(random(20,200));
  digitalWrite(leds[random(0,sizeof(leds)/sizeof(int))],LOW);
}
