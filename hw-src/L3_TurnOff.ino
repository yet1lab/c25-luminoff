//======================================================
//               STATIC TURN-OFF CLASS
//======================================================
class TurnOff {
private:
  inline static int idx = 0;
  inline static arr<bool, 16> BITS;
  inline static arr<Time, 16> OFFS = {
    "08h00","09h00","10h00","11h00","12h00","13h00","14h00","15h00",
    "16h00","17h00","18h00","19h00","19h20","20h10","21h00","21h50"
  };

public:
  static void update() {
    str_t hex = "8005"; // get request
    i32_t val = (i32_t) strtoul(hex.c_str(), nullptr, 16);

    for (int i = 0; i < 16; i++) BITS[i] = (val>>(15-i)) & 1;
  }

  static void next(const Time& actTime) {
    idx = std::upper_bound(OFFS.begin(), OFFS.end(), actTime) - OFFS.begin();
    if(idx >= OFFS.size()) idx = 0;
  }

  static int min()   { return OFFS[idx].daymin; }

  static const char* str() {
    OFFS[idx].buffer[0][10] = BITS[idx] ? 'x' : ' ';
    return OFFS[idx].str(0);
  }

  static bool less_15min(const Time& actTime) {
    return BITS[idx] && (OFFS[idx].daymin - actTime.daymin) < 15;
  }
  static bool offTime(const Time& actTime) {
    return BITS[idx] && (OFFS[idx].daymin - actTime.daymin) < 2;
  }
};