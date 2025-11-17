//======================================================
//               CONSTANT EXECUTION
//======================================================
Time orig, used;

void setup() {
  pinMode(RELAY, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  if (digitalRead(BUTTON) == 0) btnState = Long_Press;

  esp_timer_create(&pressTimer_args, &pressTimer);
  esp_timer_create(&unlockTimer_args, &unlockTimer);
  attachInterrupt(digitalPinToInterrupt(BUTTON), btnMachine, CHANGE);

//=========================================
  u8g2.begin();
  u8g2.setContrast(255); // set contrast to maximum 
  u8g2.setBusClock(400000); //400kHz I2C 
  u8g2.setFont(u8g2_font_ncenB08_tr);
  
  delay(1000);
  Connection::getWifi("luminoff", "luminoff");
  Connection::getRTC(-3, "pool.ntp.org");
  TurnOff::update();
}

void loop(){
  delay(100);
  orig.update();
  used.addsec(60);

  TurnOff::next(used);
  oledPrint(
      Msg{4, 12, orig.str(0, "%Hh%M - %a") },
      Msg{4, 23, used.str(1, "Fake: %Hh%M") },
      Msg{4, 35, TurnOff::str() }
  );
}
