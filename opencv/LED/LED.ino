int posisi=500;
int LED =D13;
char baca[3];
int ap;
void setup() {
  // put your setup code here, to run once:
pinMode(LED,OUTPUT);
Serial.begin(9600);
}

void loop() {
  int ap = Serial.parseInt(); 
if (Serial.available()>0){


Serial.println(ap);

if (ap<250) {
  digitalWrite(LED,LOW);
  }

if (ap>250) {
 
  digitalWrite(LED,HIGH);
}


}

}
