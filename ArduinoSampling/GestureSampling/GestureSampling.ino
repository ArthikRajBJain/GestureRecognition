#include<Wire.h>
/*
VCC  -  5V
GND  -  GND
SDA  -  A4
SCL  -  A5
*/
int acc_x, acc_y, acc_z;
float a_x,a_y,a_z;
float a_a_x,a_a_y,a_a_z;
float acc_total_vector;
int sample = 2;

void start_IMU()
{
  //POWER MANAGEMENT
  Wire.beginTransmission(0x68);
  Wire.write(0x6B);
  Wire.write(0x00);
  Wire.endTransmission();
  //ACCELEROMETER RANGE(+/-8g)
  Wire.beginTransmission(0x68);
  Wire.write(0x1C);
  Wire.write(0x10);
  Wire.endTransmission();
}

void read_IMU()
{
  Wire.beginTransmission(0x68);
  Wire.write(0x3B);
  Wire.endTransmission();
  Wire.requestFrom(0x68,6);
  while(Wire.available() < 6);
  acc_x = Wire.read()<<8|Wire.read();
  acc_y = Wire.read()<<8|Wire.read();
  acc_z = Wire.read()<<8|Wire.read();
}

void calculate()
{
  read_IMU();
  a_x=acc_x*2.0/8192.0;
  a_y=acc_y*2.0/8192.0;
  a_z=acc_z*2.0/8192.0;
  acc_total_vector = sqrt((a_x*a_x)+(a_y*a_y)+(a_z*a_z));
  a_a_x = asin((float)a_y/acc_total_vector)*180.0/3.141592654;
  a_a_y = asin((float)a_x/acc_total_vector)*180.0/3.141592654;
  a_a_z = atan((float)a_z/acc_total_vector)*180.0/3.141592654;
  if(a_z<0)
  {
    if(a_a_y>0)
    a_a_y=180-a_a_y;
    else
    a_a_y=-180-a_a_y;
    if(a_a_x>0)
    a_a_x=180-a_a_x;
    else
    a_a_x=-180-a_a_x;
  }
}

void setup() 
{
  Wire.begin();
  Serial.begin(9600);
  start_IMU();
  pinMode(sample,INPUT_PULLUP);
  Serial.begin(115200);
}

int sampleNum = 0;

void loop() 
{
  while(!digitalRead(sample))
  {
    sampleNum = 0;
    while(sampleNum<41)
    {
      if(sampleNum == 40)
      {
        ReadAngle(1);
      }
      else
      {
        ReadAngle(0);
      }
      sampleNum++;
      delay(20);
    }
    Serial.print("\n");
  }
}

float ReadAngle(int i)
{
  read_IMU();
  calculate();
  Serial.print(a_a_x);
  Serial.print(",");
  Serial.print(a_a_y);
  Serial.print(",");
  Serial.print(a_a_z);
  if(i == 0)
  {
    Serial.print(",");
  }
}
