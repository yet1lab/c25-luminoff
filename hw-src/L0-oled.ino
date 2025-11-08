//======================================================
//               OLED BASIC FUNCIONS
//======================================================
template <typename... Args>
void oledPrint(Args... args) {
  Msg list[] = { args... };

  u8g2.clearBuffer();
  u8g2.drawFrame(xOffset, yOffset, width, height);

  for (auto &msg : list){
    u8g2.setCursor(xOffset + msg.x, yOffset + msg.y);
    u8g2.print(msg.txt);
  }
  u8g2.sendBuffer();
}
