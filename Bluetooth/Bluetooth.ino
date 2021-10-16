#define M11 5
#define M12 3
#define M21 10
#define M22 9

#include<SoftwareSerial.h>
SoftwareSerial blue(11,12);
char bdata = 0;

void setup() {
pinMode(M11, OUTPUT);
pinMode(M12, OUTPUT);
pinMode(M21, OUTPUT);
pinMode(M22, OUTPUT);
Serial.begin(9600);
blue.begin(9600);
}

void loop() {
  if(blue.available()){
    bdata = blue.read();
    Serial.println(bdata);
    if(bdata == '1'){
      digitalWrite(M11, HIGH);
      digitalWrite(M12, LOW);
      digitalWrite(M21, HIGH);
      digitalWrite(M22, LOW);
    }
    else if(bdata == '2'){
      digitalWrite(M11, LOW);
      digitalWrite(M12, HIGH);
      digitalWrite(M21, LOW);
      digitalWrite(M22, HIGH);
   }
   else if(bdata == '0'){
      digitalWrite(M11, LOW);
      digitalWrite(M12, LOW);
      digitalWrite(M21, LOW);
      digitalWrite(M22, LOW);
   }
  }
}
