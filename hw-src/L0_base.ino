//=======================================================
//                  CONTROL VARIABLES
//=======================================================
int width = 72;
int height = 40;
int xOffset = 28;
int yOffset = 24;

const char* ssid = "luminoff";      // seu SSID (PARA TESTES)
const char* password = "luminoff";  // sua senha (PARA TESTES)

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE, 6, 5);
//=======================================================
constexpr const char* DAYS[] = {
  "Sun","Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

constexpr const char* OFFstr[] = {
  "08h00","09h00","10h00","11h00","12h00","13h00","14h00","15h00",
  "16h00","17h00","18h00","19h00","19h20","20h10","21h00","21h50"
};

arr<int, 16> makeOFFmin() {
  arr<int, 16> out;
  std::transform(OFFstr, OFFstr + 16, out.begin(), [](const char* s){
    int hour = String(s).substring(0,2).toInt();
    int min = String(s).substring(3,5).toInt();
    return hour*60 + min;
  });
  return out;
}

arr<int, 16> OFFmin = makeOFFmin();
