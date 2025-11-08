//======================================================
//                 INITIAL SETUP
//======================================================
#include <Wire.h>
#include <WiFi.h>
#include <U8g2lib.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

String hour;
int width = 72;
int height = 40;
int xOffset = 28;
int yOffset = 24; 

const char* ssid = "luminoff";          // seu SSID (PARA TESTES)
const char* password = "luminoff";      // sua senha (PARA TESTES)
struct Msg { int x, y; String txt; };   // Struct

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

  oledPrint(Msg{5,23,"Wifi: ..."});
  while (WiFi.status() != WL_CONNECTED) delay(500);

  oledPrint(Msg{5,23,"Wifi: OK"});
  delay(1500);
//===============================================================
oledPrint(
    Msg{3, 12, getTime()},
    Msg{5, 23, "Fake: 14h00"},
    Msg{5, 35, "Desl: 14h00"}
  );
}
//======================================================
//               CONSTANT EXECUTION
//======================================================
void loop(){

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
//======================================================
//               GET TIME FUNCTION
//======================================================
String getTime() {
  bool httpOK;
  HTTPClient http;
  String output = "";
  DeserializationError error;
  StaticJsonDocument<1024> doc;

  for (int attempt = 0; attempt < 8; attempt++) {
    oledPrint(
      Msg{5,18, "Get Time"},
      Msg{5,30, "Attempt: " + String(attempt + 1)}
    );
    http.begin("http://worldtimeapi.org/api/timezone/America/Recife");
    
    http.setTimeout(2000);
    httpOK = http.GET() == HTTP_CODE_OK;
    String payload = http.getString();

    if (httpOK) error = deserializeJson(doc, payload);
    if (!error) output = doc["datetime"].as<String>();
    if (output.length() >= 10) return output.substring(11, 16);

    http.end();
    delay(1000);
  }
  return output;
}
