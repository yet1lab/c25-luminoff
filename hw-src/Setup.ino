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

ClockTime::sync();
std::array<int, 3> fake = ClockTime::get(1000);
std::array<int, 3> orig = ClockTime::get(60000);

oledPrint(
    Msg{3, 12, ClockTime::strFull(orig) },
    Msg{5, 23, "Fake: " + ClockTime::strHour(fake) },
    Msg{5, 35, "OFF: 14h00"}
  );
}
