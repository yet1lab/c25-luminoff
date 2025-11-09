//======================================================
//               CONSTANT EXECUTION
//======================================================
void loop(){
  delay(1000);
  ClkData fake = ClockTime::get(1000);
  ClkData orig = ClockTime::get(60000);
  
  oledPrint(
      Msg{3, 12, ClockTime::strFull(orig) },
      Msg{4, 23, "Fake: " + ClockTime::strHour(fake) },
      Msg{4, 35, "OFF: 14h00"}
  );
}
