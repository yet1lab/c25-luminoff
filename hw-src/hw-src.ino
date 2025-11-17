//======================================================
//                 INITIAL SETUP
//======================================================
#include <array>
#include <vector>
#include <time.h>
#include <Wire.h>
#include <WiFi.h>
#include "esp_timer.h"

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
