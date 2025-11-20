#include <Arduino_GFX_Library.h>
#include "TCA9554.h"


#define GFX_BL 25 // default backlight pin, you may replace DF_GFX_BL to actual backlight pin

TCA9554 TCA(0x20);

Arduino_DataBus *bus = new Arduino_ESP32SPI(27 /* DC */, 5 /* CS */, 18 /* SCK */, 23 /* MOSI */, 19 /* MISO */);

Arduino_GFX *gfx = new Arduino_ST7796(bus, GFX_NOT_DEFINED  /* RST */, 0 /* rotation */, true /* IPS */);



void setup(void)
{
#ifdef DEV_DEVICE_INIT
  DEV_DEVICE_INIT();
#endif
  Wire.begin(21, 22);
  TCA.begin();
  TCA.pinMode1(0,OUTPUT);
  TCA.write1(0, 1);
  delay(10);
  TCA.write1(0, 0);
  delay(10);
  TCA.write1(0, 1);
  delay(200);

  Serial.begin(115200);
  // Serial.setDebugOutput(true);
  // while(!Serial);
  Serial.println("Arduino_GFX Hello World example");

  // Init Display
  if (!gfx->begin())
  {
    Serial.println("gfx->begin() failed!");
  }
  gfx->fillScreen(RGB565_BLACK);

#ifdef GFX_BL
  pinMode(GFX_BL, OUTPUT);
  digitalWrite(GFX_BL, HIGH);
#endif

  gfx->setCursor(10, 10);
  gfx->setTextColor(RGB565_RED);
  gfx->println("Hello World!");

  delay(5000); // 5 seconds
}

void loop()
{
  gfx->setCursor(random(gfx->width()), random(gfx->height()));
  gfx->setTextColor(random(0xffff), random(0xffff));
  gfx->setTextSize(random(6) /* x scale */, random(6) /* y scale */, random(2) /* pixel_margin */);
  gfx->println("Hello World!");

  delay(1000); // 1 second
}
