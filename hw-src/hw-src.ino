//======================================================
//                 INITIAL SETUP
//======================================================
#include <array>
#include <vector>
#include <time.h>
#include <Wire.h>
#include <WiFi.h>
#include <U8g2lib.h>
#include "esp_timer.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>

#define gent_t template<typename T>
#define gents_t template<typename... Ts>
#define genkv_t template<typename K, typename V>
#define gentn_t template<typename T, std::size_t N >

using str_t = String;
using i32_t = std::int32_t;
using u32_t = std::uint32_t;

gent_t using vec = std::vector<T>;
gentn_t using arr = std::array<T, N>;
genkv_t using dic = std::unordered_map<K, V>;
//=======================================================
//                   CUSTOM TYPES
//=======================================================
struct Msg {
  int x, y;
  String txt;
};

struct ClkData {
  int hour, min;
  String day;
};
enum BTN_STATE {
  Long_Press,
  Short_Press,
  Long_Release,
  Short_Release
};