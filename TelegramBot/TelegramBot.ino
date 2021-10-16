#include <ESP8266WiFi.h>
#include  <WiFiClientSecure.h>
#include <TelegramBot.h>

const char* ssid     = "ssid";
const char* password = "passk";
const char BotToken[] = "tkn"
WiFiClientSecure net_ssl;
TelegramBot bot (BotToken, net_ssl);

void setup()
{
  Serial.begin(9600);
  while (!Serial) {}  //Start running when the serial is open
  delay(3000);
  // attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  while (WiFi.begin(ssid, password) != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  pinMode(D7, OUTPUT);
  bot.begin();
  message m = bot.getUpdates();
  bot.sendMessage(m.chat_id, "LOGIN");
}

void loop()
{
  message m = bot.getUpdates();
  if (m.text.equals("on"))
  {
    digitalWrite(D7, HIGH);
    bot.sendMessage(m.chat_id, "The Led is now ON");
  }
  else if (m.text.equals("off"))
  {
    digitalWrite(D7, LOW);
    bot.sendMessage(m.chat_id, "The Led is now OFF");
  }
}
