class TurnOff {
private:
  inline static int idx;
  inline static arr<bool, 16> BITS;
  inline static arr<int, 16> OFFmin = mkOFFmin(); //

public:
  static void get() {
    str_t hex = "8A3F"; // get request
    i32_t val = (i32_t) strtoul(hex.c_str(), nullptr, 16);

    for (int i = 0; i < 16; i++) BITS[i] = (val>>(15-i)) & 1;
  }
  
  static void next(int clkMin) {
    auto it = std::upper_bound(OFFmin.begin(), OFFmin.end(), clkMin);
    idx = it - OFFmin.begin();
    if(idx >= OFFmin.size()) idx = 0;
  }


  static int min()   { return OFFmin[idx]; }
  static str_t str() { return OFFstr[idx] + String(BITS[idx] ? "x" : " "); }
};