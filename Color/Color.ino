#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

// TCS230 pins connected to Arduino
const int s0 = 5;
const int s1 = 6;
const int s2 = 7;
const int s3 = 8;
const int out = 9;

const int echoPin=12;
const int trigPin=11;
long duration, distance;

const int  buttonIncrement = 3;
const int  buttonDecrement = 2;
const int  buttonEnter = 4;
int Sisa;
int Harga;
int Hasil;
int Increment = 0;
int Decrement = 0;
int Enter = 0;


// Variables
int red = 0;
int green = 0;
int blue = 0;

int ml;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);


  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);

  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(4, 0);
  lcd.print("Detector");
  lcd.setCursor(2, 1);
  lcd.print("Harga Bensin");
  delay(2000);
  lcd.clear();
  
}

void loop()
{
  ultrasonic();
  color();
  Serial.print("R =");
  Serial.print(red, DEC);
  Serial.print(" G = ");
  Serial.print(green, DEC);
  Serial.print(" B = ");
  Serial.print(blue, DEC);
  Serial.println("\t");
  Serial.println(distance);

  if (red < 38 && green < 41 && blue < 11)
  {
    iculA();
  }
  if (red > 58 && green > 56 && blue > 43)
  {
    iculB();
      }
  else 
   {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Tidak Terdeteksi");
      delay(5000); 
      lcd.clear();
    }
    }

void color()
{
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  //count OUT, pRed, RED
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s3, HIGH);
  //count OUT, pBLUE, BLUE
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s2, HIGH);
  //count OUT, pGreen, GREEN
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}

void ultrasonic() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn (echoPin, HIGH);
distance = (duration/2) / 29.1;

if (distance==11)
{
  ml = 900;
}
else if (distance==10)
{
  ml = 800;
}
else if (distance==9)
{
  ml = 700;
}
else if (distance==8)
{
  ml = 600;
}
else if (distance==7)
{
  ml = 500;
}
else if (distance==6)
{
  ml = 400;
}
else if (distance==5)
{
  ml = 300;
}
else if (distance==4)
{
  ml = 200;
}
else if (distance==3)
{
  ml = 100;
}
else if (distance>=1561)
{
  lcd.setCursor(0,1);
  lcd.print("FULL");
  lcd.clear();
  ml = "FULL";
}
else
{
  lcd.setCursor(0,1);
  lcd.print("KOSONG");
  lcd.clear();
  ml = "KOSONG";
}
}

void iculA() {
      lcd.setCursor(0, 0);
      lcd.print("Pertalite");
      lcd.setCursor(0, 1);
      lcd.print(ml);
      lcd.print(" ml");
      delay(3000);
      lcd.clear();

        for(int a; a<1000; a++){
      lcd.setCursor(0,0);
      lcd.print("1 Liter: ");
   Increment = digitalRead(buttonIncrement);
     if (Increment == HIGH)
     {
      Harga = Harga + 50;
      lcd.setCursor(10,0); 
      lcd.print(Harga); 
     }
      delay(100);
   {
   Decrement = digitalRead(buttonDecrement);
     if (Decrement == HIGH)
     {
      Harga = Harga - 50;
      lcd.setCursor(10,0);   
      lcd.print(Harga);
      if(Harga < 99){
        lcd.setCursor(12,0);
        lcd.print(" ");
      } else if(Harga > 99 && Harga < 999){
        lcd.setCursor(13,0);
        lcd.print(" ");
      }
      else if(Harga > 999 && Harga < 9999){
        lcd.setCursor(14,0);
        lcd.print(" ");
      }
      Serial.println(Harga);
      delay(10);
     }
      delay(100);      
}
 {
   Enter = digitalRead(buttonEnter);
     if (Enter == HIGH)
     {      
      float hrgperml = float (Harga) / 1000;
      float ghj = float (hrgperml) * ml;
      lcd.setCursor(0,1); 
      lcd.print("Total :");  
      lcd.print(ghj);
      delay(2000);
     }     
}
}
}

void iculB() {
      lcd.setCursor(0, 0);
      lcd.print("Pertamax");
      lcd.setCursor(0, 1);
      lcd.print(ml);
      lcd.print(" ml");
      delay(3000);
      lcd.clear();
      
        for(int a=0; a<1000; a++){
      lcd.setCursor(0,0);
      lcd.print("1 Liter: ");
   Increment = digitalRead(buttonIncrement);
     if (Increment == HIGH)
     {
      Harga = Harga + 50;
      lcd.setCursor(10,0); 
      lcd.print(Harga); 
     }
      delay(100);
   {
   Decrement = digitalRead(buttonDecrement);
     if (Decrement == HIGH)
     {
      Harga = Harga - 50;
      lcd.setCursor(10,0);   
      lcd.print(Harga);
      if(Harga < 99){
        lcd.setCursor(12,0);
        lcd.print(" ");
      } else if(Harga > 99 && Harga < 999){
        lcd.setCursor(13,0);
        lcd.print(" ");
      }
      else if(Harga > 999 && Harga < 9999){
        lcd.setCursor(14,0);
        lcd.print(" ");
      }
      Serial.println(Harga);
      delay(10);
     }
      delay(100);      
}
 {
   Enter = digitalRead(buttonEnter);
     if (Enter == HIGH)
     {      
      float hrgperml = float (Harga) / 1000;
      float ghj = float (hrgperml) * ml;
      lcd.setCursor(0,1); 
      lcd.print("Total :");  
      lcd.print(ghj);
      delay(100);
     }     
 }
}
}
