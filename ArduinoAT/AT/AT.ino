#include<SoftwareSerial.h>
SoftwareSerial Soft(5,6);
void setup()
{
  Serial.begin(38400);
  Soft.begin(38400);
}
void loop()
{
  while(Serial.available())
  {
    Soft.write(Serial.read());
  }
  while(Soft.available())
  {
    Serial.write((char)Soft.read());
  }
}
