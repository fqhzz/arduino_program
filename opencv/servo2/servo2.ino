#include <Servo.h>
int LED =D13;      //jika uno hilangkan "d"nya
char baca[3];
int ap;
int pos;
Servo myservo; 
void setup() {

pinMode(LED,OUTPUT);
Serial.begin(9600);
myservo.attach(D2);
pos = 90;
myservo.write(pos);   
delay(2000);
}

void loop() {
int ap = Serial.parseInt(); 

if (Serial.available()>0){
Serial.println(ap);

if (ap<270) {
     delay(50); 
  digitalWrite(LED,LOW);
    myservo.write(pos);              
    pos++;
  }
  
if (ap>370) {
 delay(50);  
  digitalWrite(LED,HIGH);
    myservo.write(pos);              
    pos--;  
}
}
}
