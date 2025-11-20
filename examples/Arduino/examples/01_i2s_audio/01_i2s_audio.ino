//**********************************************************************************************************
//*    audioI2S-- I2S audiodecoder for ESP32,                                                              *
//**********************************************************************************************************
//
// first release on 11/2018
// Version 3  , Jul.02/2020
//
//
// THE SOFTWARE IS PROVIDED "AS IS" FOR PRIVATE USE ONLY, IT IS NOT FOR COMMERCIAL USE IN WHOLE OR PART OR CONCEPT.
// FOR PERSONAL USE IT IS SUPPLIED WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHOR
// OR COPYRIGHT HOLDER BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE
//

#include "Arduino.h"
#include "Audio.h"
#include "SPI.h"
#include "SD.h"
#include "FS.h"

#include "es8311.h"
#include "esp_check.h"
#include "TCA9554.h"
#include "Wire.h"

// Digital I/O used
#define SD_CS 15
#define SPI_MOSI 23
#define SPI_MISO 19
#define SPI_SCK 18

#define I2S_DOUT 12
#define I2S_BCLK 2
#define I2S_LRC 4

#define I2C_SDA 21
#define I2C_SCL 22

#define EXAMPLE_SAMPLE_RATE (16000)
#define EXAMPLE_MCLK_MULTIPLE (256)  // If not using 24-bit data width, 256 should be enough
#define EXAMPLE_MCLK_FREQ_HZ (EXAMPLE_SAMPLE_RATE * EXAMPLE_MCLK_MULTIPLE)
#define EXAMPLE_VOICE_VOLUME (75)

TCA9554 TCA(0x20);
Audio audio;


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
  // ESP_RETURN_ON_ERROR(es8311_sample_frequency_config(es_handle, EXAMPLE_SAMPLE_RATE * EXAMPLE_MCLK_MULTIPLE, EXAMPLE_SAMPLE_RATE), TAG, "set es8311 sample frequency failed");
  ESP_RETURN_ON_ERROR(es8311_voice_volume_set(es_handle, EXAMPLE_VOICE_VOLUME, NULL), TAG, "set es8311 volume failed");
  ESP_RETURN_ON_ERROR(es8311_microphone_config(es_handle, false), TAG, "set es8311 microphone failed");

  return ESP_OK;
}


void setup() {
  Serial.begin(115200);
  Wire.begin(I2C_SDA, I2C_SCL);
  TCA.begin();
  TCA.pinMode1(2,OUTPUT);
  TCA.write1(2, 1);

  es8311_codec_init();

  SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI, SD_CS);
  if (!SD.begin(SD_CS)) {
    esp_rom_printf("Card Mount Failed\n");
    while (1) {
    };
  }

  audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
  audio.setVolume(21);  // 0...21

  audio.connecttoFS(SD, "music/1.mp3");
}

void loop() {
  vTaskDelay(1);
  audio.loop();
  if (Serial.available()) {  // put streamURL in serial monitor
    audio.stopSong();
    String r = Serial.readString();
    r.trim();
    if (r.length() > 5) audio.connecttohost(r.c_str());
    log_i("free heap=%i", ESP.getFreeHeap());
  }
}

// optional
void audio_info(const char *info) {
  Serial.print("info        ");
  Serial.println(info);
}
void audio_id3data(const char *info) {  //id3 metadata
  Serial.print("id3data     ");
  Serial.println(info);
}
void audio_eof_mp3(const char *info) {  //end of file
  Serial.print("eof_mp3     ");
  Serial.println(info);
}
void audio_showstation(const char *info) {
  Serial.print("station     ");
  Serial.println(info);
}
void audio_showstreamtitle(const char *info) {
  Serial.print("streamtitle ");
  Serial.println(info);
}
void audio_bitrate(const char *info) {
  Serial.print("bitrate     ");
  Serial.println(info);
}
void audio_commercial(const char *info) {  //duration in sec
  Serial.print("commercial  ");
  Serial.println(info);
}
void audio_icyurl(const char *info) {  //homepage
  Serial.print("icyurl      ");
  Serial.println(info);
}
void audio_lasthost(const char *info) {  //stream URL played
  Serial.print("lasthost    ");
  Serial.println(info);
}
