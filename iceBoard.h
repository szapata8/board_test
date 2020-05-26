#ifndef __PUZZLE_MAIN_H__
#define __PUZZLE_MAIN_H__

#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal.h>

extern Adafruit_NeoPixel leds;
extern LiquidCrystal lcd;

#define BUZZER_PIN 9

#define NEOPIXEL_PIN 3
#define LED_COUNT 8

#define S1_PIN 4
#define S2_PIN 5
#define S3_PIN 6
#define S4_PIN 7

#define BU_PIN 11
#define BL_PIN 8
#define BC_PIN 10
#define BD_PIN 12
#define BR_PIN 13

#define LCD_DB7_PIN A0
#define LCD_DB6_PIN A1
#define LCD_DB5_PIN A2
#define LCD_DB4_PIN A3
#define LCD_E_PIN A4
#define LCD_RS_PIN A5

#define IR_PIN 2

#define BRIGHTNESS 10

#define OFF (0)
#define BLUE (BRIGHTNESS)
#define GREEN (BRIGHTNESS << 8)
#define RED (((uint32_t)BRIGHTNESS) << 16)
#define YELLOW (RED | GREEN)
#define PURPLE (RED | BLUE)
#define AQUA (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

Adafruit_NeoPixel leds(LED_COUNT, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
LiquidCrystal lcd(LCD_RS_PIN, LCD_E_PIN, LCD_DB4_PIN, LCD_DB5_PIN, LCD_DB6_PIN, LCD_DB7_PIN);

void iceboard_setup_io()
{
    pinMode(S1_PIN, INPUT);
    pinMode(S2_PIN, INPUT);
    pinMode(S3_PIN, INPUT);
    pinMode(S4_PIN, INPUT);

    pinMode(BU_PIN, INPUT);
    pinMode(BL_PIN, INPUT);
    pinMode(BC_PIN, INPUT);
    pinMode(BD_PIN, INPUT);
    pinMode(BR_PIN, INPUT);

    lcd.begin(16, 2);
    Serial.begin(9600);

    leds.begin();
    leds.clear();
}

void puzzle_done();
uint32_t pack_color(uint8_t red, uint8_t green, uint8_t blue);

#endif