#include "CTBot.h"
#include "DHT.h"

#define DHTPIN D8
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
CTBot myBot;
TBMessage msg;

String ssid = "ssid";
String pass = "passk";
String token = "tkn"
const int id = 99999;

int kondisi_counter = 0;
int suhu_counter = 0;
int counter = 0;

void setup() {
  pinMode(D13, OUTPUT);
  dht.begin();
  Serial.begin(115200);
  Serial.println("Starting...");
  myBot.wifiConnect(ssid, pass);
  myBot.setTelegramToken(token);

  myBot.sendMessage(id, "voidRoom start!");
  Serial.println("Pesan Terkirim");
}

void loop() {
  kondisi();
  suhu();
  lampu();
  delay(500);
}

void lampu() {
  if (myBot.getNewMessage(msg)) {
    if (msg.text == "on") {
      digitalWrite(D13, HIGH);
      counter = 1;
    } else if (msg.text == "off") {
      digitalWrite(D13, LOW);
      counter = 0;
    }
  }
}
