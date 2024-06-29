
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_SH110X.h>
#include <Wire.h>
#include <logger.h>

#include "display.h"
#include "pins.h"

extern logging::Logger logger;

#if !defined(USING_SH1106)
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RST);
# endif

#if defined(USING_SH1106)
Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &Wire, -1);
# endif

// cppcheck-suppress unusedFunction
void setup_display() {
  if (OLED_RST != -1) {
    pinMode(OLED_RST, OUTPUT);
    digitalWrite(OLED_RST, LOW);
    delay(20);
    digitalWrite(OLED_RST, HIGH);
  }

  Wire.begin(I2C_SDA, I2C_SCL);
  delay(50);
  #if !defined(USING_SX1262)
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3c, false, false)) {
    logger.log(logging::LoggerLevel::LOGGER_LEVEL_ERROR, "SSD1306", "allocation failed!");
    while (true) {
    }
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
  logger.log(logging::LoggerLevel::LOGGER_LEVEL_ERROR, "SX1106", "ini...");
  if (!display.begin(0x3C, true)) {
    logger.log(logging::LoggerLevel::LOGGER_LEVEL_ERROR, "SX1106", "init failed!");
    while (true) {
    }
  }

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("LORA SENDER ");
  display.display();
  #endif

}

// cppcheck-suppress unusedFunction
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
    display.oled_command(SH110X_DISPLAYOFF);
    display.oled_command(SH110X_DISPLAYON);
  } else {
    display.oled_command(SH110X_DISPLAYOFF);
  }
  #endif
}

// cppcheck-suppress unusedFunction
void show_display(String header, int wait) {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println(header);
  #if !defined(USING_SH1106)
  display.ssd1306_command(SSD1306_SETCONTRAST);
  display.ssd1306_command(1);
  #endif
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
  #if !defined(USING_SH1106)
  display.ssd1306_command(SSD1306_SETCONTRAST);
  display.ssd1306_command(1);
  #endif
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
  #if !defined(USING_SH1106)
  display.ssd1306_command(SSD1306_SETCONTRAST);
  display.ssd1306_command(1);
  #endif
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
  #if !defined(USING_SH1106)
  display.ssd1306_command(SSD1306_SETCONTRAST);
  display.ssd1306_command(1);
  #endif
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
  #if !defined(USING_SH1106)
  display.ssd1306_command(SSD1306_SETCONTRAST);
  display.ssd1306_command(1);
  #endif
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
  #if !defined(USING_SH1106)
  display.ssd1306_command(SSD1306_SETCONTRAST);
  display.ssd1306_command(1);
  #endif
  display.display();
  delay(wait);
}
