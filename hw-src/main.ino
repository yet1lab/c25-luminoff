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
});

//======================================================
void setup() {
  setCpuFrequencyMhz(160);
  u8g2.begin();
  u8g2.setContrast(255); // set contrast to maximum 
  u8g2.setBusClock(1000000); //1 MHz I2C 
  u8g2.setFont(u8g2_font_ncenB08_tr);
  delay(1000);

  pinMode(RELAY, OUTPUT);
  pinMode(R_LED, OUTPUT);
  pinMode(B_LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  if (digitalRead(BUTTON) == 0) btnState = Long_Press;

  Task::setup();
  attachInterrupt(digitalPinToInterrupt(BUTTON), btnMachine, CHANGE);
//========================================= 
  // ledMachineTask.loopIn(100000); // 100ms

  Connection::getWifi("luminoff", "luminoff");
  Connection::getRTC(-3, "pool.ntp.org");
  TurnOff::update();
 
  oledTask.loopIn(500000); // 200ms
}

void loop(){

}
