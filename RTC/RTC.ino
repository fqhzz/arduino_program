#include <Servo.h> 
#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;//define a object of DS3231 class
char buf1[20];
Servo myservo;
         
void setup(){ 
  Serial.begin(9600);
  myservo.attach(8);
  Wire.begin();
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
} 
 
void loop(){ 
 timedRelay();
 delay(2000);
}

void timedRelay(){
    DateTime now = rtc.now();
    sprintf(buf1, "%02d:%02d:%02d %02d/%02d/%02d",  now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year());   
    Serial.print(F("Date/Time: "));
    Serial.println(buf1);
    //delay(1000);
    
    if(now.hour() == 17 && now.minute() == 50){
      myservo.write(0);
      delay(1000);
      myservo.write(180);  
      delay(1000);        
      //myservo.write(0); 
      delay(59000);      
    } 
    else if(now.hour() == 24 && now.minute() == 00){
      myservo.write(0);
      delay(1000);
      myservo.write(180);  
      delay(1000);        
      //myservo.write(0);
      delay(8000); 
    }
}
