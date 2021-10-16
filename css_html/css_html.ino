#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ESP8266WebServer.h>
#include<ESP8266mDNS.h>
#include<Servo.h>

const char*ssid = "ssid";
const char*password = "passk";

int x = 90;

ESP8266WebServer server(80);
String webPage = "";

Servo myservo;

void kiri() {
  if (x == 180) {
    x = x;
  } else {
    x = x + 30;
  }
  myservo.write(x);
  delay(500);
}

void kanan() {
  if (x == 0) {
    x = x;
  } else {
    x = x - 30;
  }
  myservo.write(x);
  delay(500);
}

void setup() {
  webPage += "<!DOCTYPE html>\n<html>\n<head>\n<style>\nh1{\n\tcolor: blue;\n    font-family: verdana;\n    font-size: 300%;\n    }\n\n.button {\n  background-color: #4CAF50; /* Green */\n  border: none;\n  color: white;\n  padding: 15px 32px;\n  text-align: center;\n  text-decoration: none;\n  display: inline-block;\n  font-size: 16px;\n  margin: 4px 2px;\n  cursor: pointer;\n}\n.button2 {background-color: #008CBA;}\n    \n</style>\n</head>\n\n<body>\n\n<center><h1>WebCam Servo</h>\n<center>\n<a href='\kiri\'><button class=\"button button2\">Kiri</button></a>\n<a href='\kanan\'><button class=\"button button2\">Kanan</button></a>\n\n</body>\n</html>\n";
  myservo.attach(D2);
  myservo.write(x);
  delay(200);

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  Serial.println("");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");

  }
  Serial.println("");
  Serial.print("Connected to");
  Serial.println(ssid);
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266", WiFi.localIP()))
  {
    Serial.println("MDNS responder started");

  }
  server.on("/", []() {
    server.send(200, "text/html", webPage);
  });
  server.on("/kiri", []() {
    server.send(200, "text/html", webPage);
    kiri();
    Serial.println(x);
  });
  server.on("/kanan", []() {
    server.send(200, "text/html", webPage);
    kanan();
    Serial.println(x);
  });
  server.begin();

}

void loop() {
  server.handleClient();

}
