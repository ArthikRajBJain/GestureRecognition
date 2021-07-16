#define M1D PB11
#define M2D PB10
#define M3D PA5
#define M4D PA4
#define M1P PB1
#define M2P PB0
#define M3P PA7
#define M4P PA6

void setup() 
{
  //M1
  pinMode(M1D,OUTPUT);
  pinMode(M1P,OUTPUT);
  //M2
  pinMode(M2D,OUTPUT);
  pinMode(M2P,OUTPUT);
  //M3
  pinMode(M3D,OUTPUT);
  pinMode(M3P,OUTPUT);
  //M4
  pinMode(M4D,OUTPUT);
  pinMode(M4P,OUTPUT);
//  Serial1.begin(38400);
//  Serial.begin(38400);
}

void forward(int x)
{
  digitalWrite(M2D,HIGH);
  analogWrite(M2P,x);
  digitalWrite(M4D,LOW);
  analogWrite(M4P,x);
}

void backward(int x)
{
  digitalWrite(M2D,LOW);
  analogWrite(M2P,x);
  digitalWrite(M4D,HIGH);
  analogWrite(M4P,x);
}

void right(int x)
{
  digitalWrite(M3D,HIGH);
  analogWrite(M3P,x);
  digitalWrite(M1D,HIGH);
  analogWrite(M1P,x);
}

void _reset()
{
  analogWrite(M1P,0);
  analogWrite(M2P,0);
  analogWrite(M3P,0);
  analogWrite(M4P,0);
}
void left(int x)
{
  digitalWrite(M3D,LOW);
  analogWrite(M3P,x);
  digitalWrite(M1D,LOW);
  analogWrite(M1P,x);
}

void loop() 
{
  forward(100);
  delay(1000);
  _reset();
  right(100);
  delay(1000);
  _reset();
  backward(100);
  delay(1000);
  _reset();
  left(100);
  delay(1000);
  _reset();
//  analogWrite(M3P,150);
//  digitalWrite(M3D, HIGH);
//  delay(1000);
//  analogWrite(M3P,150);
//  digitalWrite(M3D, LOW);
//  delay(1000); 
}
