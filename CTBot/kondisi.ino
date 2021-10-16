void kondisi() {
  if (msg.text == "kondisi" && kondisi_counter == 0) {
    if (counter == 0) {
      myBot.sendMessage(id, "Kondisi lampu mati");
    }
    else if (counter == 1) {
      myBot.sendMessage(id, "Kondisi lampu nyala");
    }
    kondisi_counter = 1;
  }
}
