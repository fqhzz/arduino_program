#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <Servo.h>

#define M11 D6
#define M12 D5
#define M21 D11
#define M22 D10

Servo myservo;
Servo myservo1;
int x = 45;
int y = 120;

const char* ssid = "ssid";
const char* password = "passk";

ESP8266WebServer server(80);
String webPage = "";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  pinMode(M11, OUTPUT);
  pinMode(M12, OUTPUT);
  pinMode(M21, OUTPUT);
  pinMode(M22, OUTPUT);

  myservo.attach(1);
  myservo1.attach(4);
  myservo1.write(y);
  myservo.write(x);

  design();
  server_setup();
}

void loop() {
  server.handleClient();
}
