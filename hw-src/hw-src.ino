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

const char* ssid = "luminoff";      // seu SSID (PARA TESTES)
const char* password = "luminoff";  // sua senha (PARA TESTES)
struct Msg {
  int x, y;
  String txt;
};  // Struct

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE, 6, 5);
