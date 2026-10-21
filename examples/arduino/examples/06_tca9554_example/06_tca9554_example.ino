#include "TCA9554.h"


TCA9554 TCA(0x20);


void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("TCA9554_LIB_VERSION: ");
  Serial.println(TCA9554_LIB_VERSION);
  Serial.println();

  Wire.begin(21, 22);
  TCA.begin();


  Serial.println("Set pinMode8 OUTPUT");
  for (int pin = 0; pin < 8; pin++)
  {
    TCA.pinMode1(pin, OUTPUT);
  }

  for (int pin = 0; pin < 8; pin++)
  {
    TCA.write1(pin, LOW);
  }
  delay(1000);
  Serial.println("Set pinMode8 INPUT");
  for (int pin = 0; pin < 8; pin++)
  {
    TCA.pinMode1(pin, INPUT);
  }
}


void loop()
{
  Serial.print("INPUT->");
  for (int pin = 0; pin < 8; pin++)
  {
    int val = TCA.read1(pin);
    Serial.printf("pin%d: %d\t", pin, val);
  }
  Serial.println();
  Serial.println("\ndone...");
  delay(1000);
}
