//======================================================
//             STATIC CLOCK TIME CLASS
//======================================================
class ClockTime {
private:
  inline static str_t timeAPI = "";
  inline static i32_t hour = 0, min = 0, day = 0;
  inline static u32_t diff = 0, start = 0, last = 0, act = 0;

public:
  static void sync() {
    timeAPI = getTime();
    hour = timeAPI.substring(0,2).toInt();
    min = timeAPI.substring(3,5).toInt();
    day = timeAPI.substring(6,7).toInt();
    start = millis();
    last = act;
  }

  static ClkData get(u32_t base) {
    act = millis();
    if (act < last) sync();
    diff = (act-last)/base; // minutes diff = 60000ms
    return ClkData{ (hour+( (diff+min)/60 ))%24, (min+diff)%60, DAYS[day] };
  }

  static int getMin(ClkData data) {
    return data.hour*60 + data.min;
  }

  static str_t strHour(ClkData data) {
    char buf[5];
    sprintf(buf, "%02dh%02d", data.hour, data.min);
    return String(buf);
  }

  static str_t strFull(ClkData data) {
    char buf[20];
    sprintf(buf, "%02dh%02d - %s", data.hour, data.min, data.day);
    return String(buf);
  }
};
