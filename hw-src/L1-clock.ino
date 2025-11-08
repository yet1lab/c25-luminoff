class ClockTime {
private:
  inline static String timeAPI = "";
  inline static int hour = 0, min = 0, day = 0;
  inline static unsigned long diff = 0, start = 0, last = 0, act = 0;

public:
  static void sync() {
    timeAPI = getTime();
    hour = timeAPI.substring(0,2).toInt();
    min = timeAPI.substring(3,5).toInt();
    day = timeAPI.substring(6,7).toInt();
    start = millis();
    last = act;
  }

  static std::array<int, 3> get(unsigned long base) {
    act = millis();
    if (act < last) sync();
    diff = (act-last)/base; // minutes diff = 60000ms
    return { (hour+( (diff+min)/60 ))%24, (min+diff)%60, day };
  }

  static String strHour(std::array<int, 3> clockData) {
    char buf[5];
    sprintf(buf, "%02dh%02d", clockData[0], clockData[1]);
    return String(buf);
  }

  static String strFull(std::array<int, 3> clockData) {
    char buf[20];
    sprintf(buf, "%02dh%02d - %s", clockData[0], clockData[1], DAYS[clockData[2]]);
    return String(buf);
  }
};
