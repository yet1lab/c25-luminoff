//======================================================
//              STATIC CONECTION CLASS
//======================================================
tm basertc;
time_t baseunix;
int64_t basetime;

class Connection {
public:
  static void getWifi(const char* ssid, const char* password) {
    WiFi.begin(ssid, password);
    oledPrint(Msg{5,23,"Wifi: ..."});
    while (WiFi.status() != WL_CONNECTED) delay(500);
  }

  static void getRTC(const long  gmt, const char* ntpServer, const int daylight=0) {
    oledPrint(
      Msg{5,18, "Wifi: OK"},
      Msg{5,30, "Get Time..."}
    );
    configTime(gmt*3600, daylight, ntpServer);
    getLocalTime(&basertc);
    basetime = esp_timer_get_time(); 
    baseunix = mktime(&basertc);
  }
};