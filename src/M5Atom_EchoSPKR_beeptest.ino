/*
*******************************************************************************
* Copyright (c) 2021 by M5Stack
*                  Equipped with Atom-Lite sample source code
*                          配套  Atom-Lite 示例源代码
* Visit for more information: https://docs.m5stack.com/en/atom/atom_spk
* 获取更多资料请访问：https://docs.m5stack.com/zh_CN/atom/atom_spk
*
* Product:  SPK.
* Date: 2021/9/1
*
* Ported to a M5Stack Atom Echo by @PaulskPt (Github).
* Date: 2024/10/6
* Using example C++ code originally designed for the M5Stack AtomSPK
* ported this to the M5Stack Atom Echo
*
* New describe: Speaker beep example using ATOMECHOSPKR class
*******************************************************************************
*/
#include <M5Atom.h>
#include <FastLED.h>
#include "AtomEchoSPKR.h"

#define NUM_LEDS 1
#define ATOMECHO_LED_PIN 27

CRGB leds[NUM_LEDS];

enum my_colors {RED=0, GREEN, BLUE, WHITE, BLACK};

const char txt1[] = "builtin RGB Led set to: ";
const char txt2[] = " color";

ATOMECHOSPKR echoSPKR;

void LedColor(my_colors color)
{
  switch (color)
  {
    case RED:
      leds[0] = CRGB::Red; // Set the LED to red
      break;
    case GREEN:
      leds[0] = CRGB::Green; // Set the LED to green
      break;
    case BLUE:
      leds[0] = CRGB::Blue; // Set the LED to blue
      break;
    case WHITE:
      leds[0] = CRGB::White; // Set the LED to white
      break;
  case BLACK:
      leds[0] = CRGB::Black; // Set the LED to black
      break;
  default:
      leds[0] = CRGB::Black; // Set the LED to black
      break;
  };
    FastLED.show(); // Update the LED
}

void setup()
{
  const char TAG[] = "setup(): ";

  M5.begin(true, false, false); // Init M5 Atom Echo  (SerialEnable, I2CEnable, DisplayEnable)
  FastLED.addLeds<NEOPIXEL, ATOMECHO_LED_PIN>(leds, NUM_LEDS); // Initialize FastLED
  FastLED.setBrightness(50); // Set brightness
  Serial.println("M5Stack M5Atom Echo new \"ATOMECHOSPKR class\" beep test");
  LedColor(RED);
  Serial.printf("%s%sRED%s\n", TAG, txt1, txt2);
  
  echoSPKR.begin(88200);

  delay(100);
}

// Define two beep tones
beep tone1 = 
{
  .freq    = 1200,
  .time_ms = 100,
  .maxval  = 10000,
  .modal   = false
};

beep tone2 = 
{
  .freq    = 1500,
  .time_ms = 100,
  .maxval  = 10000,
  .modal   = false
};

void loop()
{
  const char TAG[] = "loop(): ";

  while (true)
  {
    if (M5.Btn.wasPressed()) 
    {
      Serial.printf("%sButton was pressed\n", TAG);
      LedColor(GREEN);
      Serial.printf("%s%sGREEN%s\n", TAG, txt1, txt2);

      for (int i = 0; i < 2; i++)  // play a double tone
      {
        echoSPKR.playBeep(tone1);
        delay(100);
        echoSPKR.playBeep(tone2);
        delay(100);
      }
      LedColor(RED);
      Serial.printf("%s%sRED%s\n", TAG, txt1, txt2);
    }
    M5.update();  // Read the press state of the key.
  }
}
