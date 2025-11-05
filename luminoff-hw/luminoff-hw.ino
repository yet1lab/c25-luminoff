#include <U8g2lib.h>
#include <Wire.h>

// there is no 72x40 constructor in u8g2 hence the 72x40 screen is mapped in the middle of the 132x64 pixel buffer of the SSD1306 controller
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE, 6, 5);
int width = 72;
int height = 40;
int xOffset = 28; // = (132-w)/2
int yOffset = 24; // = (64-h)/2

void setup(){
     delay(1000);
     u8g2.begin();
     u8g2.setContrast(255); // set contrast to maximum 
     u8g2.setBusClock(400000); //400kHz I2C 
     u8g2.setFont(u8g2_font_ncenB08_tr);
}

void loop(void){
    u8g2.clearBuffer(); // clear the internal memory
    u8g2.drawFrame(xOffset+0, yOffset+0, width, height); //draw a frame around the border
    u8g2.setCursor(xOffset+3, yOffset+12);
    u8g2.printf("14h00");
    u8g2.setCursor(xOffset+5, yOffset+23);
    u8g2.printf("Fake: 14h00");
    u8g2.setCursor(xOffset+5, yOffset+35);
    u8g2.printf("Desl: 14h00");
    u8g2.sendBuffer(); // transfer internal memory to the display
}
