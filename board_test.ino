#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>

#include "iceBoard.h"

void setup()
{
    iceboard_setup_io();
}

void loop()
{
    int S1 = digitalRead(S1_PIN);
    int S2 = digitalRead(S2_PIN);
    int S3 = digitalRead(S3_PIN);
    int S4 = digitalRead(S4_PIN);
    int BUp = digitalRead(BU_PIN);
    int BLeft = digitalRead(BL_PIN);
    int BCenter = digitalRead(BC_PIN);
    int BRight = digitalRead(BR_PIN);
    int BDown = digitalRead(BD_PIN);
    String switches = "Switches: ";
    switches += S1;
    switches += S2;
    switches += S3;
    switches += S4;

    String buttons = "Buttons: ";
    buttons += BUp;
    buttons += BLeft;
    buttons += BCenter;
    buttons += BRight;
    buttons += BDown;

    // Serial.println(switches);
    // Serial.println(buttons);

    lcd.clear();
    lcd.print(switches);
    lcd.setCursor(0, 1);
    lcd.print(buttons);

    // Buzzer
    if (digitalRead(BC_PIN))
    {
        analogWrite(BUZZER_PIN, 128);
    }
    else
    {
        analogWrite(BUZZER_PIN, 0);
    }

    // Neopixels
    int brightness = 1 + digitalRead(BL_PIN) + digitalRead(BC_PIN) + digitalRead(BU_PIN) + digitalRead(BR_PIN) + digitalRead(BD_PIN);

    // scale brightness to 0-255 range
    // (brightness = 0, no buttons pressed)
    // (brightness = 6, all buttons pressed)
    // (scale 1-6 to 255 range)
    brightness *= 42;

    int red = brightness * digitalRead(S1_PIN);
    int green = brightness * digitalRead(S2_PIN);
    int blue = brightness * digitalRead(S3_PIN);
    int white = brightness * digitalRead(S4_PIN);

    int i;
    for (i = 0; i < LED_COUNT; i++)
    {
        leds.setPixelColor(i, red, green, blue);
    }
    leds.show();

    delay(100);
}
