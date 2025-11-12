//======================================================
//                 CONFIGURATIONS
//======================================================
void setup() {
  pinMode(RELAY, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  if (digitalRead(BUTTON) == 0) btnState = Long_Press;

  esp_timer_create(&offTimer_args, &offTimer);
  esp_timer_create(&unlockTimer_args, &unlockTimer);
  attachInterrupt(digitalPinToInterrupt(BUTTON), btnMachine, CHANGE);

//=========================================
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
  ClockTime::sync();
  TurnOff::get();
}
