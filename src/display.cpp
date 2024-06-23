
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <Wire.h>
#include <logger.h>

#include "display.h"
#include "pins.h"

extern logging::Logger logger;

Adafruit_SH1106 display(OLED_RST);

// cppcheck-suppress unusedFunction
void setup_display() {
  pinMode(OLED_RST, OUTPUT);
  digitalWrite(OLED_RST, LOW);
  delay(20);
  digitalWrite(OLED_RST, HIGH);

  Wire.begin(OLED_SDA, OLED_SCL);
  // if (!display.begin(SH1106_SWITCHCAPVCC, 0x3c, false)) {
  //   logger.log(logging::LoggerLevel::LOGGER_LEVEL_ERROR, "SH1106", "allocation failed!");
  //   while (true) {
  //   }
  // }

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("LORA SENDER ");
  display.SH1106_command(SH1106_SETCONTRAST);
  display.SH1106_command(1);
  display.display();
}

// cppcheck-suppress unusedFunction
void display_toggle(bool toggle) {
  if (toggle) {
    display.SH1106_command(SH1106_DISPLAYON);
  } else {
    display.SH1106_command(SH1106_DISPLAYOFF);
  }
}

// cppcheck-suppress unusedFunction
void show_display(String header, int wait) {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println(header);
  display.SH1106_command(SH1106_SETCONTRAST);
  display.SH1106_command(1);
  display.display();
  delay(wait);
}

// cppcheck-suppress unusedFunction
void show_display(String header, String line1, int wait) {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println(header);
  display.setTextSize(1);
  display.setCursor(0, 16);
  display.println(line1);
  display.SH1106_command(SH1106_SETCONTRAST);
  display.SH1106_command(1);
  display.display();
  delay(wait);
}

// cppcheck-suppress unusedFunction
void show_display(String header, String line1, String line2, int wait) {
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
  display.SH1106_command(SH1106_SETCONTRAST);
  display.SH1106_command(1);
  display.display();
  delay(wait);
}

// cppcheck-suppress unusedFunction
void show_display(String header, String line1, String line2, String line3, int wait) {
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
  display.SH1106_command(SH1106_SETCONTRAST);
  display.SH1106_command(1);
  display.display();
  delay(wait);
}

// cppcheck-suppress unusedFunction
void show_display(String header, String line1, String line2, String line3, String line4, int wait) {
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
  display.SH1106_command(SH1106_SETCONTRAST);
  display.SH1106_command(1);
  display.display();
  delay(wait);
}

// cppcheck-suppress unusedFunction
void show_display(String header, String line1, String line2, String line3, String line4, String line5, int wait) {
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
  display.SH1106_command(SH1106_SETCONTRAST);
  display.SH1106_command(1);
  display.display();
  delay(wait);
}
