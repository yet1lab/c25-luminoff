//======================================================
//                 CLOCK TIME CLASS
//======================================================
class Time {
public:
  tm rtc;
  time_t unix;
  u32_t daymin;
  char buffer[10][20];

  Time() : daymin(0) {  }

  Time(const char* strbuf) {
    sscanf(strbuf, "%dh%02d", &rtc.tm_hour, &rtc.tm_min);
    daymin = rtc.tm_hour*60 + rtc.tm_min;
    str(0, "OFF: %Hh%M");
  }

  void update(){
    getLocalTime(&rtc);
    daymin = rtc.tm_hour*60 + rtc.tm_min;
  }
  void addsec(u32_t secstep){
    unix = (time_t)(unix+secstep);
    rtc = *localtime(&unix);
    daymin = rtc.tm_hour*60 + rtc.tm_min;
  }

  const char* str(int buf) {
    return buffer[buf];
  }
  const char* str(int buf, const char* fmt) {
    strftime(buffer[buf], 20, fmt, &rtc);
    return buffer[buf];
  }
  bool operator<(const Time& other) const {
    return daymin < other.daymin;
  }
};