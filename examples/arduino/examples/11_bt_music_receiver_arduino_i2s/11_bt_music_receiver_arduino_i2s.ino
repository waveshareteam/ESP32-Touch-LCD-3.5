/*
  Streaming Music from Bluetooth
  
  Copyright (C) 2020 Phil Schatzmann
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// ==> Example which shows how to use the built in ESP32 I2S < 3.0.0

#include "ESP_I2S.h"
#include "BluetoothA2DPSink.h"
#include "es8311.h"
#include "TCA9554.h"
#include "esp_check.h"
#include <U8g2lib.h>
#include <Arduino_GFX_Library.h>


// #include "u8g2_font_unifont_h_utf8.h"

#define I2C_SDA 21
#define I2C_SCL 22

#define I2S_NUM I2S_NUM_0

#define I2S_MCK_PIN -1
#define I2S_BCK_PIN 2
#define I2S_LRCK_PIN 4
#define I2S_DOUT_PIN 12
#define I2S_DIN_PIN 34

#define EXAMPLE_SAMPLE_RATE (44100)
#define EXAMPLE_MCLK_MULTIPLE (256)  // If not using 24-bit data width, 256 should be enough
#define EXAMPLE_MCLK_FREQ_HZ (EXAMPLE_SAMPLE_RATE * EXAMPLE_MCLK_MULTIPLE)
#define EXAMPLE_VOICE_VOLUME (70)

#define GFX_BL 25  // default backlight pin, you may replace DF_GFX_BL to actual backlight pin

Arduino_DataBus *bus = new Arduino_ESP32SPI(27 /* DC */, 5 /* CS */, 18 /* SCK */, 23 /* MOSI */, 19 /* MISO */);

Arduino_GFX *gfx = new Arduino_ST7796(bus, GFX_NOT_DEFINED /* RST */, 1 /* rotation */, true /* IPS */);

I2SClass i2s;
TCA9554 TCA(0x20);
BluetoothA2DPSink a2dp_sink(i2s);

static esp_err_t es8311_codec_init(void) {
  es8311_handle_t es_handle = es8311_create(I2C_NUM_0, ES8311_ADDRRES_0);
  ESP_RETURN_ON_FALSE(es_handle, ESP_FAIL, TAG, "es8311 create failed");
  const es8311_clock_config_t es_clk = {
    .mclk_inverted = false,
    .sclk_inverted = false,
    .mclk_from_mclk_pin = false,
    // .mclk_frequency = EXAMPLE_MCLK_FREQ_HZ,
    .sample_frequency = EXAMPLE_SAMPLE_RATE
  };

  ESP_ERROR_CHECK(es8311_init(es_handle, &es_clk, ES8311_RESOLUTION_32, ES8311_RESOLUTION_32));
  ESP_RETURN_ON_ERROR(es8311_voice_volume_set(es_handle, EXAMPLE_VOICE_VOLUME, NULL), TAG, "set es8311 volume failed");
  ESP_RETURN_ON_ERROR(es8311_microphone_config(es_handle, false), TAG, "set es8311 microphone failed");

  return ESP_OK;
}

void avrc_rn_play_pos_callback(uint32_t play_pos) {
  Serial.printf("Play position is %d (%d seconds)\n", play_pos, (int)round(play_pos / 1000.0));
}

void avrc_rn_playstatus_callback(esp_avrc_playback_stat_t playback) {
  switch (playback) {
    case esp_avrc_playback_stat_t::ESP_AVRC_PLAYBACK_STOPPED:
      Serial.println("Stopped.");
      break;
    case esp_avrc_playback_stat_t::ESP_AVRC_PLAYBACK_PLAYING:
      Serial.println("Playing.");
      break;
    case esp_avrc_playback_stat_t::ESP_AVRC_PLAYBACK_PAUSED:
      Serial.println("Paused.");
      break;
    case esp_avrc_playback_stat_t::ESP_AVRC_PLAYBACK_FWD_SEEK:
      Serial.println("Forward seek.");
      break;
    case esp_avrc_playback_stat_t::ESP_AVRC_PLAYBACK_REV_SEEK:
      Serial.println("Reverse seek.");
      break;
    case esp_avrc_playback_stat_t::ESP_AVRC_PLAYBACK_ERROR:
      Serial.println("Error.");
      break;
    default:
      Serial.printf("Got unknown playback status %d\n", playback);
  }
}

void avrc_metadata_callback(uint8_t id, const uint8_t *text) {
  Serial.printf("==> AVRC metadata rsp: attribute id 0x%x, %s\n", id, text);
  switch (id) {
    case ESP_AVRC_MD_ATTR_TITLE:
      // gfx->fillRect(0, 30, gfx->width(), 20, RGB565_WHITE);
      gfx->setTextColor(RGB565_BLACK, RGB565_WHITE);
      gfx->setCursor(10, 50);
      gfx->printf("%-120s", text);
      break;
    case ESP_AVRC_MD_ATTR_ARTIST:
      // gfx->fillRect(10, 80, gfx->width(), 20, RGB565_WHITE);
      gfx->setTextColor(RGB565_BLUE, RGB565_WHITE);
      gfx->setCursor(10, 100);
      gfx->printf("%-120s", text);
      break;
    case ESP_AVRC_MD_ATTR_ALBUM:
      // gfx->fillRect(10, 120, gfx->width(), 20, RGB565_WHITE);
      gfx->setTextColor(RGB565_MAGENTA, RGB565_WHITE);
      gfx->setCursor(10, 150);
      gfx->printf("%-120s", text);
      break;
  }

  // if (id == ESP_AVRC_MD_ATTR_PLAYING_TIME) {
  //   uint32_t playtime = String((char*)text).toInt();
  //   Serial.printf("==> Playing time is %d ms (%d seconds)\n", playtime, (int)round(playtime/1000.0));
  // }
}

void setup() {
  Serial.begin(115200);
  Wire.begin(I2C_SDA, I2C_SCL);
  es8311_codec_init();
  TCA.begin();
  TCA.pinMode1(2, OUTPUT);
  TCA.write1(2, 1);
  TCA.pinMode1(0, OUTPUT);
  TCA.write1(0, 1);
  delay(10);
  TCA.write1(0, 0);
  delay(10);
  TCA.write1(0, 1);
  delay(200);

  if (!gfx->begin(80 * 1000 * 1000)) {
    Serial.println("gfx->begin() failed!");
  }
  gfx->fillScreen(RGB565_WHITE);
  gfx->setUTF8Print(true);
#ifdef GFX_BL
  pinMode(GFX_BL, OUTPUT);
  digitalWrite(GFX_BL, HIGH);
#endif
  gfx->setFont(u8g2_font_unifont_h_utf8);
  gfx->setTextColor(RGB565_RED, RGB565_WHITE);
  gfx->setCursor(10, 200);
  gfx->println("Bluetooth is not connected");

  i2s.setPins(I2S_BCK_PIN, I2S_LRCK_PIN, I2S_DOUT_PIN, I2S_DIN_PIN, I2S_MCK_PIN);
  // Initialize the I2S bus in standard mode
  if (!i2s.begin(I2S_MODE_STD, EXAMPLE_SAMPLE_RATE, I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_STEREO, I2S_STD_SLOT_BOTH)) {
    Serial.println("Failed to initialize I2S bus!");
    return;
  }
  a2dp_sink.set_avrc_rn_playstatus_callback(avrc_rn_playstatus_callback);
  a2dp_sink.set_avrc_rn_play_pos_callback(avrc_rn_play_pos_callback);
  a2dp_sink.set_avrc_metadata_callback(avrc_metadata_callback);
  // a2dp_sink.start("AudioKit");
  a2dp_sink.start("ESP32-Touch-LCD-3.5", true);
  while (!a2dp_sink.is_connected())
    delay(1000);
  gfx->setTextColor(RGB565_RED, RGB565_WHITE);
  gfx->setCursor(10, 200);
  gfx->println("Bluetooth is connected     ");
  // Serial.println("Play or pause music to test callbacks.");
}

void loop() {
}
