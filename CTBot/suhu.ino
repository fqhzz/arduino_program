void suhu() {
  int t = dht.readTemperature();
  Serial.println(t);
  if (msg.text == "suhu" && suhu_counter == 0) {
    if (t == 27) {
      myBot.sendMessage(id, "27");
    } else if (t == 28) {
      myBot.sendMessage(id, "28");
    } else if (t == 29) {
      myBot.sendMessage(id, "29");
    } else if (t == 30) {
      myBot.sendMessage(id, "30");
    } else if (t == 31) {
      myBot.sendMessage(id, "31");
    } else if (t == 32) {
      myBot.sendMessage(id, "32");
    } else if (t == 26) {
      myBot.sendMessage(id, "26");
    }
    delay(1000);
    myBot.sendMessage(id, "Apakah Anda ingin menyalakan kipas? (y/t)");
    delay(3000);
    suhu_counter = 1;
  }
  if (msg.text == "y") {
    digitalWrite(D13, HIGH);
  } else if (msg.text == "t") {
    digitalWrite(D13, LOW);
  }
}
