    
  #include <IRremote.h>
  #include <Servo.h>
  
  
  int RECV_PIN = 11;
  int SERVO_PIN = 6;
  int pos = 90;
  
  unsigned long lastCode; 
  IRrecv irrecv(RECV_PIN);  
  decode_results results; 
  Servo myservo;
  
  void setup()
  {  
    irrecv.enableIRIn(); 
    myservo.attach(SERVO_PIN);
    myservo.write(pos); 
  }
  
  void loop() 
  {
    if (irrecv.decode(&results))
    {
      if (results.value == 0xFFFFFFFF)
      {
        results.value = lastCode;
      }
      if (results.value == 0x20DF609F)
      {
        lastCode = results.value ;
  
        pos = 0;
  
        if (pos > 180) {
          pos = 180;
        }
        myservo.write(pos);
      }
      if (results.value == 0x20DFE01F)
      {
        lastCode = results.value ;
        pos = 180;
  
  
        if (pos < 0) {
          pos = 0;
        }
        myservo.write(pos);
      }
      if (results.value == 0x20DFC23D )
      {
        lastCode = results.value ;
  
        pos = 90;
  
        myservo.write(pos);
      }
  
      delay(30);
      irrecv.resume(); 
    }  
  }
  
