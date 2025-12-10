//======================================================
//               CONSTANT EXECUTION
//======================================================
Time orig, used;

Task oledTask([](void* arg){
  orig.update();
  used.addsec(60);

  TurnOff::next(used);
  oledPrint(
    Msg{4, 12, orig.str(0, "%Hh%M - %a") },
    Msg{4, 23, used.str(1, "Fake: %Hh%M") },
    Msg{4, 35, TurnOff::str() }
  );
  
  ledState = TurnOff::less_15min(used) ? RED : OFF;
  if (TurnOff::offTime(used)) { digitalWrite(RELAY, LOW); }
});

//======================================================
void setup() {
  setCpuFrequencyMhz(160);
  u8g2.begin();
  u8g2.setContrast(255); // set contrast to maximum 
  u8g2.setBusClock(1000000); //1 MHz I2C 
  u8g2.setFont(u8g2_font_ncenB08_tr);
  delay(1000);

  pinMode(R_LED, OUTPUT);
  pinMode(G_LED, OUTPUT);
  pinMode(B_LED, OUTPUT);

  pinMode(RELAY, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  digitalWrite(G_LED, LOW);
  if (digitalRead(BUTTON) == 0) btnState = Long_Press;

  Task::setup();
  attachInterrupt(digitalPinToInterrupt(BUTTON), btnMachine, CHANGE);
//========================================= 
  // ledMachineTask.loopIn(100000); // 100ms

  Connection::getWifi("luminoff", "luminoff");
  Connection::getRTC(-3, "pool.ntp.org");
  TurnOff::update();

  used.addsec(60*60*21 + 60*30); // add hours to correct
  ledMachineTask.loopIn(200000); // 200 ms 
  oledTask.loopIn(500000);       // 500 ms
}

void loop(){

}
