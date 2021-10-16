void server_setup() {
  server.on("/", []() {
    server.send(200, "text/html", webPage);
  });
  server.on("/maju", []() {
    server.send(200, "text/html", webPage);
    maju();
  }) ;
  server.on("/mundur", []() {
    server.send(200, "text/html", webPage);
    mundur();
  }) ;
  server.on("/kanan", []() {
    server.send(200, "text/html", webPage);
    kanan();
  }) ;
  server.on("/kiri", []() {
    server.send(200, "text/html", webPage);
    kiri();
  }) ;

  server.on("/atas", []() {
    server.send(200, "text/html", webPage);
    atas();
  }) ;
  server.on("/bawah", []() {
    server.send(200, "text/html", webPage);
    bawah();
  }) ;
  server.on("/buka", []() {
    server.send(200, "text/html", webPage);
    buka();
  }) ;
  server.on("/tutup", []() {
    server.send(200, "text/html", webPage);
    tutup();
  }) ;
  
  server.begin();
}
