#ifndef PINS_H_
#define PINS_H_

#if defined(TTGO_T_Beam_V0_7) || defined(TTGO_T_Beam_V1_0) || defined(TTGO_T_Beam_V1_2)
#undef I2C_SDA
#undef I2C_SCL
#undef OLED_RST

#define I2C_SDA 21
#define I2C_SCL 22
#define OLED_RST 16

#define BUTTON_PIN 38 // The middle button GPIO on the T-Beam

#ifdef TTGO_T_Beam_V0_7
#define GPS_RX 15
#define GPS_TX 12
#endif

#if defined(TTGO_T_Beam_V1_0) || defined(TTGO_T_Beam_V1_2)
#define GPS_RX 12
#define GPS_TX 34
#endif

#endif

#if defined(T_BEAM_S3_SUPREME)


#ifndef USING_SX1262
#define USING_SX1262
#endif

// RTC, BME280. SH1106 OLED, 
#define I2C_SDA                     17
#define I2C_SCL                     18
#define OLED_RST                    -1  // not existing

// PMU
#define I2C1_SDA                    42
#define I2C1_SCL                    41
#define PMU_IRQ                     40

#define GPS_RX                      9
#define GPS_TX                      8
#define GPS_WAKEUP_PIN              7
#define GPS_PPS_PIN                 6

#define BUTTON_PIN                  0
#define BUTTON_PIN_MASK             GPIO_SEL_0
#define BUTTON_CONUT                (1)
#define BUTTON_ARRAY                {BUTTON_PIN}

#define LORA_SCK                   (12)
#define LORA_MISO                  (13)
#define LORA_MOSI                  (11)
#define LORA_CS                    (10)
#define LORA_DIO0                  (-1)
#define LORA_RST                   (5)
#define LORA_DIO1                  (1)
#define LORA_BUSY                  (4)
#define LORA_IRQ                   (-1)

#define SPI_MOSI                    (35)
#define SPI_SCK                     (36)
#define SPI_MISO                    (37)
#define SPI_CS                      (47)
#define IMU_CS                      (34)
#define IMU_INT                     (33)

#define SDCARD_MOSI                 SPI_MOSI
#define SDCARD_MISO                 SPI_MISO
#define SDCARD_SCLK                 SPI_SCK
#define SDCARD_CS                   SPI_CS

#define PIN_NONE                    (-1)
#define RTC_INT                     (14)

#define GPS_BAUD_RATE               9600

#define HAS_SDCARD
#define HAS_GPS
#define HAS_DISPLAY
#define HAS_PMU

#define __HAS_SPI1__
#define __HAS_SENSOR__

#define PMU_WIRE_PORT               Wire1
#define DISPLAY_MODEL               U8G2_SH1106_128X64_NONAME_F_HW_I2C
#define BOARD_VARIANT_NAME          "T-Beam S3"

#endif

#endif