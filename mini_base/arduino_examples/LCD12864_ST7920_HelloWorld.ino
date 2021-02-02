#include "U8g2lib.h" // by olikraus

#define LCDROTATION U8G2_R0
#define SCK_E_CLOCK PB13
#define MOSI_RW_DATA PB15
#define SS_RS_CS PB12
#define RST_RESET PA3

//U8G2_ST7920_128X64_F_2ND_HW_SPI disp(LCDROTATION, SS_RS_CS, RST_RESET);
// THE LINE BELOW WORKS, but slow: software SPI.
U8G2_ST7920_128X64_F_SW_SPI disp(LCDROTATION, SCK_E_CLOCK, MOSI_RW_DATA, SS_RS_CS, RST_RESET);

int ypos = 22;

void setup(){
  disp.begin();
  delay(100);
  disp.setBusClock(1000000); // If higher gives artifacts on the screen over time
  delay(100);
}

void loop(){
  // Show something
  disp.clearBuffer();
  disp.setFontMode(1);
  disp.setDrawColor(1);
  disp.setFont(u8g2_font_victoriamedium8_8r);
  disp.drawStr(5,10,"HELLO WORLD!"); //pos X, Y, "text"
  disp.sendBuffer();
  delay(500);

}
