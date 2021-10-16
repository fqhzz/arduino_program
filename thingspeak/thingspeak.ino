#include "DHT.h"
#include <ESP8266WiFi.h>

// replace with your channel’s thingspeak API key and your SSID and password
String apiKey = "API";
const char* ssid = "ssid"; //nama wifi
const char* password = "passk"; //password wifi
const char* server = "api.thingspeak.com"; //biarkan isinya ga usah dirubah apithingspeak
 
#define DHTPIN D4
#define DHTTYPE DHT11 

//sensor tanah
int sensorPin = A0; //pin sensor
int powerPin = D6; //sensor tanah

DHT dht(DHTPIN, DHTTYPE);
WiFiClient client;
 
void setup() 
{
  Serial.begin(115200);
  //sensor tanah
  pinMode(powerPin, OUTPUT);
  digitalWrite(powerPin, LOW);
  
  dht.begin();
  WiFi.begin(ssid, password);
   
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
   
  WiFi.begin(ssid, password);
 
while (WiFi.status() != WL_CONNECTED) 
{
  delay(500);
  Serial.print(".");
}
  Serial.println("");
  Serial.println("WiFi connected");
}
 
void loop() 
{
  delay(2000);
 float h = dht.readHumidity();
  float t = dht.readTemperature();
 
  if (isnan(h) || isnan(t)) 
  {
  Serial.println("Failed to read from DHT sensor!");
  return;
  }
   
  if (client.connect(server,80)) {
  String postStr = apiKey;
  postStr +="&field1=";
  postStr += String(h);
  postStr +="&field2=";
  postStr += String(t);
  postStr += "&field3=";
  postStr += String(bacaSensor());
  postStr += "\r\n\r\n\r\n";
   
  client.print("POST /update HTTP/1.1\n");
  client.print("Host: api.thingspeak.com\n");
  client.print("Connection: close\n");
  client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
  client.print("Content-Type: application/x-www-form-urlencoded\n");
  client.print("Content-Length: ");
  client.print(postStr.length());
  client.print("\n\n\n");
  client.print(postStr);
   
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" degrees Celsius Humidity: ");
  Serial.print(h);
  Serial.println(" Nilai Kelembapan Tanah: ");
  Serial.println(bacaSensor());
  Serial.println(" Sending data to Thingspeak"); 
  }
  client.stop();
  Serial.println("Waiting 20 secs");
  // thingspeak needs at least a 15 sec delay between updates
  // 20 seconds to be safe
   
  delay(20000);
}

int bacaSensor() {
  // hidupkan power
  digitalWrite(powerPin, HIGH);
  delay(500);
  // baca nilai analog dari sensor
  int nilaiSensor = analogRead(sensorPin);
  digitalWrite(powerPin, LOW);
  // makin lembab maka makin tinggi nilai outputnya
  return 1023 - nilaiSensor;
}
