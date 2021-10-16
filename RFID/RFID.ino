#include <SPI.h>
#include <RFID.h>
#include <Servo.h>
#define SS_PIN 10
#define RST_PIN 9
int servo = 6;
int ledH = 7;
int ledM = 3;
int buzz = 2;
RFID rfid(SS_PIN,RST_PIN);

Servo myservo;  // create servo object to control a servo

void setup() {
  myservo.attach(6);
  myservo.write(0);
  Serial.begin(9600);                       
  SPI.begin();
  rfid.init();
  pinMode(ledH, OUTPUT);
  pinMode(ledM, OUTPUT);
  pinMode(buzz, OUTPUT);
}
 
void loop() {
  
   if(rfid.isCard()){
        if(rfid.readCardSerial()){
            if(rfid.serNum[0] == 131){
             benar();
             myservo.write(90);
             Serial.println("Akses diterima");
             } else {
            salah();
            myservo.write(0);
            Serial.println("Akses ditolak");
            
    }
      }
        }
    rfid.halt();
}

void benar(){
  digitalWrite(ledM, LOW);
  digitalWrite(ledH, HIGH);
  digitalWrite(buzz, HIGH);
  delay(300);
  digitalWrite(ledH, LOW);
  digitalWrite(buzz, LOW);
}
void salah(){
  digitalWrite(ledH, LOW);
  digitalWrite(ledM, HIGH);
  digitalWrite(buzz, HIGH);
  delay(1000);
  digitalWrite(ledM, LOW);
  digitalWrite(buzz, LOW);
}
