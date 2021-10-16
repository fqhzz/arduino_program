void atas() {
  if (x == 180) {
    x = x;
  } else {
    x = x + 30;
  }
  myservo.write(x);
  delay(1000);
}

void bawah() {
  if (x == 0) {
    x = x;
  } else {
    x = x - 30;
  }
  myservo.write(x);
  delay(1000);
}

void tutup() {
  if (y == 180) {
    y = y;
  } else {
    y = y + 30;
  }
  myservo1.write(y);
  delay(1000);
}

void buka() {
  if (y == 0) {
    y = y;
  } else {
    y = y - 30;
  }
  myservo1.write(y);
  delay(1000);
}
