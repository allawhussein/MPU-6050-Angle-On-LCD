#include <Wire.h>

float ax, ay, az; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();

  Wire.beginTransmission(0x68);
  Wire.write(0x6b);
  Wire.write(0x00);
  Wire.endTransmission();
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(0x68);
  Wire.write(0x3b);
  Wire.endTransmission(false);

  Wire.requestFrom(0x68, 6, true);

  ax = (Wire.read()<<8|Wire.read()) / 16384.0;
  ay = (Wire.read()<<8|Wire.read()) / 16384.0;
  az = (Wire.read()<<8|Wire.read()) / 16384.0;

  Serial.print("the value of x");
  Serial.print(ax);
  Serial.print("  ");
  Serial.print("the value of y");
  Serial.print(ay);
  Serial.print("  ");
  Serial.print("the value of z");
  Serial.println(az);

  delay (500);

}
