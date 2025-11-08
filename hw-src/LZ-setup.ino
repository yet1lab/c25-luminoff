//======================================================
//                 CONFIGURATIONS
//======================================================
void setup(){
  u8g2.begin();
  u8g2.setContrast(255); // set contrast to maximum 
  u8g2.setBusClock(400000); //400kHz I2C 
  u8g2.setFont(u8g2_font_ncenB08_tr);
  
  delay(1000);
  WiFi.begin(ssid, password);

  oledPrint(Msg{5,23,"Wifi: ..."});
  while (WiFi.status() != WL_CONNECTED) delay(500);

  oledPrint(Msg{5,23,"Wifi: OK"});
  delay(1500);
//===============================================================
oledPrint(
    Msg{3, 12, getTime()},
    Msg{5, 23, "Fake: 14h00"},
    Msg{5, 35, "Desl: 14h00"}
  );
}
