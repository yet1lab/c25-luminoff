//======================================================
//               CONSTANT EXECUTION
//======================================================
void loop(){
  delay(1000);
  std::array<int, 3> fake = ClockTime::get(1000);
  std::array<int, 3> orig = ClockTime::get(60000);
  
  oledPrint(
      Msg{3, 12, ClockTime::strFull(orig) },
      Msg{5, 23, "Fake: " + ClockTime::strHour(fake) },
      Msg{5, 35, "OFF: 14h00"}
  );
}
