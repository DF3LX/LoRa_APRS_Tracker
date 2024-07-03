#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <logger.h>

#include "display.h"
#include "pins.h"

extern logging::Logger logger;

#if !defined(USING_SH1106)
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RST);
# endif

#if defined(USING_SH1106)
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);
# endif

void setup_display() {
  if (OLED_RST != -1) {
    pinMode(OLED_RST, OUTPUT);
    digitalWrite(OLED_RST, LOW);
    delay(20);
    digitalWrite(OLED_RST, HIGH);
  }

  #if !defined(USING_SX1262)
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3c, false, false)) {
  logger.log(logging::LoggerLevel::LOGGER_LEVEL_ERROR, "SSD1306", "allocation failed!");
  }

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("LORA SENDER ");
  display.ssd1306_command(SSD1306_SETCONTRAST);
  display.ssd1306_command(1);
  display.display();

  #endif

  #if defined(USING_SH1106)
  logger.log(logging::LoggerLevel::LOGGER_LEVEL_INFO, "SX1106", "ini...");
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_inb19_mr);
  u8g2.drawStr(0, 30, "DF3LX-7");
  u8g2.drawHLine(2, 35, 47);
  u8g2.drawHLine(3, 36, 47);
  u8g2.drawVLine(45, 32, 12);
  u8g2.drawVLine(46, 33, 12);
  u8g2.setFont(u8g2_font_inb19_mf);
  u8g2.drawStr(58, 60, "LoRa");
  u8g2.sendBuffer();
  u8g2.setFont(u8g2_font_fur11_tf);
  delay(3000);
  #endif

}


void display_toggle(bool toggle) {
  #if !defined(USING_SH1106)
  if (toggle) {
    display.ssd1306_command(SSD1306_DISPLAYON);
  } else {
    display.ssd1306_command(SSD1306_DISPLAYOFF);
  }
  #endif

  #if defined(USING_SH1106)
  if (toggle) {

  }
  #endif
}


void show_display(String header, int wait) {
  #if !defined(USING_SH1106)
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println(header);
  display.display();
  #endif

  #if defined(USING_SH1106)
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_NokiaLargeBold_tf );
  u8g2.drawStr(0, 0, header.c_str());
  u8g2.sendBuffer();
  #endif
  delay(wait);
}


void show_display(String header, String line1, int wait) {
  #if !defined(USING_SH1106)
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println(header);
  display.setTextSize(1);
  display.setCursor(0, 16);
  display.println(line1);
  display.setCursor(0, 26);
  display.ssd1306_command(SSD1306_SETCONTRAST);
  display.ssd1306_command(1);
  display.display();
  #endif

  #if defined(USING_SH1106)
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_NokiaLargeBold_tf );
  u8g2.drawStr(0, 0, header.c_str());
  u8g2.setFont(u8g2_font_fub25_tn);
  u8g2.drawStr(0, 16, line1.c_str());
  u8g2.sendBuffer();
  #endif
  delay(wait);
}


void show_display(String header, String line1, String line2, int wait) {
  #if !defined(USING_SH1106)
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println(header);
  display.setTextSize(1);
  display.setCursor(0, 16);
  display.println(line1);
  display.setCursor(0, 26);
  display.println(line2);
  display.setCursor(0, 36);
  display.ssd1306_command(SSD1306_SETCONTRAST);
  display.ssd1306_command(1);
  display.display();
  #endif

  #if defined(USING_SH1106)
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_NokiaLargeBold_tf );
  u8g2.drawStr(0, 0, header.c_str());
  u8g2.setFont(u8g2_font_fub25_tn);
  u8g2.drawStr(0, 16, line1.c_str());
  u8g2.drawStr(0, 26, line2.c_str());
  u8g2.sendBuffer();
  #endif
  delay(wait);
}


void show_display(String header, String line1, String line2, String line3, int wait) {
  #if !defined(USING_SH1106)
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println(header);
  display.setTextSize(1);
  display.setCursor(0, 16);
  display.println(line1);
  display.setCursor(0, 26);
  display.println(line2);
  display.setCursor(0, 36);
  display.println(line3);
  display.ssd1306_command(SSD1306_SETCONTRAST);
  display.ssd1306_command(1);
  display.display();
  #endif

  #if defined(USING_SH1106)
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_NokiaLargeBold_tf );
  u8g2.drawStr(0, 0, header.c_str());
  u8g2.setFont(u8g2_font_fub25_tn);
  u8g2.drawStr(0, 16, line1.c_str());
  u8g2.drawStr(0, 26, line2.c_str());
  u8g2.drawStr(0, 36, line3.c_str());
  u8g2.sendBuffer();
  #endif
  delay(wait);
}


void show_display(String header, String line1, String line2, String line3, String line4, int wait) {
  #if !defined(USING_SH1106)
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println(header);
  display.setTextSize(1);
  display.setCursor(0, 16);
  display.println(line1);
  display.setCursor(0, 26);
  display.println(line2);
  display.setCursor(0, 36);
  display.println(line3);
  display.setCursor(0, 46);
  display.println(line4);
  display.ssd1306_command(SSD1306_SETCONTRAST);
  display.ssd1306_command(1);
  display.display();
  #endif

  #if defined(USING_SH1106)
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_NokiaLargeBold_tf );
  u8g2.drawStr(0, 0, header.c_str());
  u8g2.setFont(u8g2_font_fub25_tn);
  u8g2.drawStr(0, 16, line1.c_str());
  u8g2.drawStr(0, 26, line2.c_str());
  u8g2.drawStr(0, 36, line3.c_str());
  u8g2.drawStr(0, 46, line4.c_str());
  u8g2.sendBuffer();
  #endif
  delay(wait);
}


void show_display(String header, String line1, String line2, String line3, String line4, String line5, int wait) {
  #if !defined(USING_SH1106)
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println(header);
  display.setTextSize(1);
  display.setCursor(0, 16);
  display.println(line1);
  display.setCursor(0, 26);
  display.println(line2);
  display.setCursor(0, 36);
  display.println(line3);
  display.setCursor(0, 46);
  display.println(line4);
  display.setCursor(0, 56);
  display.println(line5);
  display.ssd1306_command(SSD1306_SETCONTRAST);
  display.ssd1306_command(1);
  display.display();
  #endif

  #if defined(USING_SH1106)
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_NokiaLargeBold_tf );
  u8g2.drawStr(0, 0, header.c_str());
  u8g2.setFont(u8g2_font_fub25_tn);
  u8g2.drawStr(0, 16, line1.c_str());
  u8g2.drawStr(0, 26, line2.c_str());
  u8g2.drawStr(0, 36, line3.c_str());
  u8g2.drawStr(0, 46, line4.c_str());
  u8g2.drawStr(0, 56, line5.c_str());
  u8g2.sendBuffer();
  #endif
  delay(wait);
}
