#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

const int s0 = 3;
const int s1 = 4;
const int s2 = 5;
const int s3 = 6;
const int out = 7;

int red = 0;
int green = 0;
int blue = 0;
#define buzz 2

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

void setup()
{
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  pinMode(buzz, OUTPUT);

  for(int b=0;b<3;b++){
    digitalWrite(buzz, HIGH);
    delay(500);
    digitalWrite(buzz, LOW);
    delay(200);
  }

  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
  mySoftwareSerial.begin(9600);
  Serial.begin(9600);
  
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));
  
  myDFPlayer.volume(30);  //Set volume value. From 0 to 30
    //Play the first mp3
}

void loop()
{
  color();
  Serial.print("R =");
    Serial.print(red, DEC);
    Serial.print(" G = ");
    Serial.print(green, DEC);
    Serial.print(" B = ");
    Serial.print(blue, DEC);
    Serial.print("\t");
    Serial.println();
    delay (500);
  static unsigned long timer = millis();
  
  if (millis() - timer > 3000) {
    timer = millis();
    //myDFPlayer.next();  //Play next mp3 every 3 second.
  }
  
  if (myDFPlayer.available()) {
    printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
  }
  if (red < 12 && red > 10 && 7 < green && green < 11 && 4 < blue && blue < 8) {
    Serial.println("50.000");
    myDFPlayer.play(6);
    delay(5000);
  }
 else if (5 < red && red < 9 && 7 < green && green < 11 && 6 < blue && blue < 10) {
    Serial.println("5.000");
    myDFPlayer.play(3);
    delay(5000);
  }
   else if (7 < red && red < 11 && 8 < green && green < 12 && 5 < blue && blue < 9) {
    Serial.println("10.000");
    myDFPlayer.play(4);
    delay(5000);
  }
   else if (11 < red && red < 15 && 9 < green && green < 13 && 8 < blue && blue < 12) {
    Serial.println("20.000");
    myDFPlayer.play(5);
    delay(5000);
  }
   else if (8 < red && red < 12 && 8 < green && green < 12 && 10 < blue && blue < 14) {
    Serial.println("1000");
    myDFPlayer.play(1);
    delay(5000); 
  }
   else if (10 < red && red < 14 && 11 < green && green < 15 && 9 < blue && blue < 13) {
    Serial.println("2000");
    myDFPlayer.play(2);
    delay(5000);
  }
   else if (6 < red && red < 10 && 15 < green && green < 19 && 11 < blue && blue < 15) {
    Serial.println("100.000");
    myDFPlayer.play(7);
    delay(5000);
  }
}

void printDetail(uint8_t type, int value){
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }

}
void color()
{
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s3, HIGH);
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s2, HIGH);
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}
