//======================================================
//               OLED BASIC FUNCIONS
//======================================================
#include <U8g2lib.h>

int width = 72, height = 40; 
int xOffset = 28, yOffset = 24;

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE, 6, 5);

struct Msg {
  int x, y;
  const char* txt;
};
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
