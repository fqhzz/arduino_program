int LED = LED_BUILTIN;
void setup() {
  // put your setup code here, to run once:
pinMode(LED,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() >0){
  int angka = Serial.read();
  Serial.println(angka);

} 
}
