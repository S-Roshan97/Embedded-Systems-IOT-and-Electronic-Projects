#include <WiFi.h>
#include <WebServer.h>

/* ---------- WiFi AP Setup ---------- */
const char* ssid = "ESP32_AP";      // WiFi SSID
const char* password = "12345678";  // WiFi Password

IPAddress local_ip(192, 168, 4, 1); // Default AP IP
IPAddress gateway(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);

/* ---------- Pin Setup ---------- */
// ⚠️ ESP32 Super Mini Pin Mapping (use GPIO numbers, not D numbers)
#define LED1_PIN  8   // On-board LED (usually GPIO2)
#define RELAY_PIN 5   // External relay connected to GPIO5

bool LED1status = LOW;
bool RELAYstatus = LOW;

/* ---------- Web Server ---------- */
WebServer server(80);

/* ---------- Function Prototypes ---------- */
void handle_OnConnect();
void handle_led1on();
void handle_led1off();
void handle_RELAYon();
void handle_RELAYoff();
void handle_NotFound();
String SendHTML(bool led1stat, bool relaystat);

void setup() {
  Serial.begin(115200);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  // Start Access Point
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);

  Serial.println();
  Serial.print("Access Point IP: ");
  Serial.println(WiFi.softAPIP());

  // Route setup
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

  // Control LED and Relay
  digitalWrite(LED1_PIN, LED1status);
  digitalWrite(RELAY_PIN, RELAYstatus);
}

/* ---------- Web Request Handlers ---------- */
void handle_OnConnect() {
  LED1status = LOW;
  RELAYstatus = LOW;
  Serial.println("LED1: OFF | RELAY: OFF");
  server.send(200, "text/html", SendHTML(LED1status, RELAYstatus));
}

void handle_led1on() {
  LED1status = HIGH;
  Serial.println("LED1: ON");
  server.send(200, "text/html", SendHTML(LED1status, RELAYstatus));
}

void handle_led1off() {
  LED1status = LOW;
  Serial.println("LED1: OFF");
  server.send(200, "text/html", SendHTML(LED1status, RELAYstatus));
}

void handle_RELAYon() {
  RELAYstatus = HIGH;
  Serial.println("RELAY: ON");
  server.send(200, "text/html", SendHTML(LED1status, RELAYstatus));
}

void handle_RELAYoff() {
  RELAYstatus = LOW;
  Serial.println("RELAY: OFF");
  server.send(200, "text/html", SendHTML(LED1status, RELAYstatus));
}

void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}

/* ---------- HTML Page ---------- */
String SendHTML(bool led1stat, bool relaystat) {
  String ptr = "<!DOCTYPE html><html>";
  ptr += "<head><meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  ptr += "<title>ESP32 Web Server</title>";
  ptr += "<style>";
  ptr += "body {font-family: Helvetica; text-align: center; margin-top: 50px;}";
  ptr += ".button {display: inline-block; width: 120px; padding: 15px; font-size: 20px;";
  ptr += "color: white; border: none; border-radius: 6px; cursor: pointer; margin: 10px;}";
  ptr += ".on {background-color: #4CAF50;}";
  ptr += ".off {background-color: #f44336;}";
  ptr += "</style></head><body>";
  ptr += "<h1>ESP32 Super Mini Web Server</h1>";
  ptr += "<h3>~ Roshan Geeks YouTube Channel ~</h3>";

  // LED Section
  if (led1stat)
    ptr += "<p>LED Status: ON</p><a class='button off' href='/led1off'>Turn OFF</a>";
  else
    ptr += "<p>LED Status: OFF</p><a class='button on' href='/led1on'>Turn ON</a>";

  // Relay Section
  if (relaystat)
    ptr += "<p>Relay Status: ON</p><a class='button off' href='/RELAYoff'>Turn OFF</a>";
  else
    ptr += "<p>Relay Status: OFF</p><a class='button on' href='/RELAYon'>Turn ON</a>";

  ptr += "</body></html>";
  return ptr;
}
