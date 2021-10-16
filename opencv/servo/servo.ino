/*
  # Face tracking using arduino - Code #
  # Code by Harsh Dethe
  # 09 Sep 2018.
*/

#include<Servo.h>

Servo servoVer; //Vertical Servo
Servo servoHor; //Horizontal Servo

int x;

int prevX;

void setup()
{
  Serial.begin(9600);
 //Attach Vertical Servo to Pin 5
  servoHor.attach(6); //Attach Horizontal Servo to Pin 6

  servoHor.write(90);
}

void Pos()
{
  if(prevX != x)
  {
    int servoX = map(x, 600, 0, 70, 179);

    servoX = min(servoX, 179);
    servoX = max(servoX, 70);
   
    servoHor.write(servoX);
  }
}

void loop()
{
  if(Serial.available() > 0)
  {
    
      x = Serial.parseInt();
      Serial.println("qwe"+x);
      
    while(Serial.available() > 0)
    {
      Serial.read();
    }
  }
}
  

