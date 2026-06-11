#include <WiFi.h>
#include <WebServer.h>

/* Put your SSID & Password */
const char* ssid = "ESP32";  // Enter SSID here
const char* password = "12345678";  //Enter Password here

/* Put IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

WebServer server(80);

uint8_t LED1pin = 2;
bool LED1status = LOW;

uint8_t RELAY = 5;
bool RELAYstatus = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(LED1pin, OUTPUT);
  pinMode(RELAY, OUTPUT);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  
  server.on("/", handle_OnConnect);
  server.on("/led1on", handle_led1on);
  server.on("/led1off", handle_led1off);
  server.on("/RELAYon", handle_RELAYon);
  server.on("/RELAYoff", handle_RELAYoff);
  server.onNotFound(handle_NotFound);
  
  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
  if(LED1status)
  {digitalWrite(LED1pin, HIGH);}
  else
  {digitalWrite(LED1pin, LOW);}
  
  if(RELAYstatus)
  {digitalWrite(RELAY, HIGH);}
  else
  {digitalWrite(RELAY, LOW);}
}

void handle_OnConnect() {
  LED1status = LOW;
  RELAYstatus = LOW;
  Serial.println("GPIO2 Status: OFF | GPIO5 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1status,RELAYstatus)); 
}

void handle_led1on() {
  LED1status = HIGH;
  Serial.println("GPIO2 Status: ON");
  server.send(200, "text/html", SendHTML(true,RELAYstatus)); 
}

void handle_led1off() {
  LED1status = LOW;
  Serial.println("GPIO2 Status: OFF");
  server.send(200, "text/html", SendHTML(false,RELAYstatus)); 
}

void handle_RELAYon() {
  RELAYstatus = HIGH;
  Serial.println("GPIO5 Status: ON");
  server.send(200, "text/html", SendHTML(LED1status,true)); 
}

void handle_RELAYoff() {
  RELAYstatus = LOW;
  Serial.println("GPIO5 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1status,false)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

String SendHTML(uint8_t led1stat,uint8_t led2stat){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>LED Control</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 20px;} h3 {color: #444444;margin-bottom: 40px;} h2 {color: #444444;margin-bottom: 20px;}\n";
  ptr +=".button {display: block;width: 80px;background-color:#ff0000;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #ff0000;}\n";
  ptr +=".button-on:active {background-color: #0000FF;}\n";
  ptr +=".button-off {background-color: #0000FF;}\n";
  ptr +=".button-off:active {background-color: #ff0000;}\n";
  ptr +="p {font-size: 17px;color: #000000;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>ESP32 WEB SERVER</h1>\n";
  ptr +="<h2>Using Access Point(AP) Mode</h2>\n";
  ptr +="<h3>~Roshan Geeks YouTube Channel~</h3>\n";
  
   if(led1stat)
  {ptr +="<p>LED Status: ON</p><a class=\"button button-off\" href=\"/led1off\">OFF</a>\n";}
  else
  {ptr +="<p>LED Status: OFF</p><a class=\"button button-on\" href=\"/led1on\">ON</a>\n";}

  if(led2stat)
  {ptr +="<p>RELAY SWITH Status: ON</p><a class=\"button button-off\" href=\"/RELAYoff\">OFF</a>\n";}
  else
  {ptr +="<p>RELAY SWITH Status: OFF</p><a class=\"button button-on\" href=\"/RELAYon\">ON</a>\n";}

  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
