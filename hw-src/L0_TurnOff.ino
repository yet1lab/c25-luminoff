class TurnOff {
private:
  inline static arr<bool, 16> BITS;

public:
  static void get() {
    str_t hex = "1A3F"; // get request
    i32_t val = (i32_t) strtoul(hex.c_str(), nullptr, 16);

    for (int i = 0; i < 16; i++) BITS[i] = (val>>(15-i)) & 1;
  }

  static void next() {
    // get next index turnOff
    // res = (cond) ? "✓" : "❌"
  }
};