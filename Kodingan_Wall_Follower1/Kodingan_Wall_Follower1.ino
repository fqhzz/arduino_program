/* Berikut merupakan kodingan
 * Wall Follower untuk menyelesaikan
 * rintangan seperti berikut:
 *  
 * FINISH
 *|   ---|
 *|      |
 *|      |
 *|---   |
 *|      |
 *|      |
 *|   ---|
 *|      |
 *|      |
 *|---   |
 * START
 * 
 * Legenda:
 * + START    =     Posisi awal robot
 * + FINISH   =     Tujuan akhir robot
 * + ---      =     dinding atau checkpoint
 * +  |       =     dinding atau checkpoint
 */

//Deklarasi pin motor
int M11 = 9;
int M12 = 10;
int M21 = 5;
int M22 = 6;

int jarak = 17; //jarak untuk belok
int checkpoint = 1; //menghitung checkpoint
int waktukanan = 380; //waktu untuk berbelok
int waktukiri = 350; //waktu untuk berbelok

void setup() {
  //Baud Rate untuk komunikasi mikrokontroler dengan komputer
  Serial.begin(9600);
  
  //Penentuan mode pin sebagai output
  pinMode(M11, OUTPUT);
  pinMode(M12, OUTPUT);
  pinMode(M21, OUTPUT);
  pinMode(M22, OUTPUT);
}

void loop() {
  //Penentuan pin Trigger, Echo 
  int cm = sensor_ping(2,7);

  // Penentuan Kondisi
  if (cm > 20) { //Kondisi maju
    MAJU ();
  }
  else if (cm <= 15 && checkpoint == 1) { //checkpoint pertama
    KIRI();
    delay(750);
    checkpoint++;
  }
  else if (cm <= 13 && checkpoint == 2) { //checkpoint kedua
    KANAN();
    delay(750);
    checkpoint++;
  }
  /*else if (cm <= jarak && checkpoint == 3) { //checkpoint ketiga
    KANAN();
    delay(450);
    checkpoint++;
  }
  else if (cm <= jarak && checkpoint == 4) { //checkpoint keempat
    KANAN();
    delay(450);
    checkpoint++;
  }
  else if (cm <= jarak && checkpoint == 5) { //checkpoint keempat
    KIRI();
    delay(450);
    checkpoint++;
  }
  else if (cm <= jarak && checkpoint == 6) { //checkpoint keempat
    KIRI();
    delay(450);
    checkpoint++;
  }*/
}

//fungsi maju
void MAJU (){
  analogWrite(M11, 120);
  analogWrite(M12, 0);
  analogWrite(M21, 120);
  analogWrite(M22, 0);
}

//fungsi belok kanan
void KANAN (){
  analogWrite(M11, 0);
  analogWrite(M12, 180);
  analogWrite(M21, 180);
  analogWrite(M22, 0);
}

//fungsi belok kiri
void KIRI (){
  analogWrite(M11, 180);
  analogWrite(M12, 0);
  analogWrite(M21, 0);
  analogWrite(M22, 180);
}

//fungsi mendeteksi dengan sensor, menggunakan pin Trigger dan Echo  
int sensor_ping(const int trigPin,const int echoPin) {
  long duration, cm ;
  
  //pinmode trigpin sebagai output
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //pinmode echopin sebagai input
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);

  //Mengeprint output pada serial monitor 
  Serial.print(cm);
  Serial.print(" cm");

  //Memberikan jarak 1 line kebawah (ENTER)
  Serial.println();
  delay(100);
  return(cm);
}

//mengkonversi data sensor menjadi satuan detik
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 27 / 2;
}
