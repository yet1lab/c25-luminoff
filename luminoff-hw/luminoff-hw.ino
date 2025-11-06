//======================================================
//                 INITIAL SETUP
//======================================================
#include <Wire.h>
#include <WiFi.h>
#include <U8g2lib.h>

int width = 72;
int height = 40;
int xOffset = 28;
int yOffset = 24; 

const char* ssid = "luminoff";               // seu SSID (PARA TESTES)
const char* password = "luminoff";           // sua senha (PARA TESTES)
struct Msg { int x, y; const char* txt; };   // Struct

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE, 6, 5);
//======================================================
//                 CONFIGURATIONS
//======================================================
void setup(){
  delay(1000);
  u8g2.begin();
  u8g2.setContrast(255); // set contrast to maximum 
  u8g2.setBusClock(400000); //400kHz I2C 
  u8g2.setFont(u8g2_font_ncenB08_tr);
  
  delay(1000);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    oledPrint(Msg{5,23,"Wifi: ..."});
  }

  oledPrint(Msg{5,23, "Wifi: OK"});
  delay(1500);
}
//======================================================
//               CONSTANT EXECUTION
//======================================================
void loop(){
  oledPrint(
    Msg{3,12,"13h00"},
    Msg{5,23,"Fake: 14h00"},
    Msg{5,35,"Desl: 14h00"}
  );
}
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
