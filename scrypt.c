const int EnableL = 10;
const int HighL = 8;       // LEFT SIDE MOTOR
const int LowL = 9;
 
const int EnableR = 5;
const int HighR = 7;       //RIGHT SIDE MOTOR
const int LowR = 6;
 
const int D0 = 0;
const int D1 = 2;
const int D2 = 3;
 
int a,b,c,data;
 
void setup() {
pinMode(EnableL, OUTPUT);      
pinMode(HighL, OUTPUT);
pinMode(LowL, OUTPUT);
 
pinMode(EnableR, OUTPUT);
pinMode(HighR, OUTPUT);
pinMode(LowR, OUTPUT);
 
pinMode(D0, INPUT_PULLUP);
pinMode(D1, INPUT_PULLUP);
pinMode(D2, INPUT_PULLUP);
}
 
void Data()
{
   a = digitalRead(D0);
   b = digitalRead(D1);
   c = digitalRead(D2);
 
   data = 4*c+2*b+a; // binary to decimal
}
 
void Stop()
{
  analogWrite(EnableL, 0);
  analogWrite(EnableR, 0);
}

void Turn(int leftSpeed, int rightSpeed) 
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL, leftSpeed);
 
  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR, rightSpeed);
}

void Forward(int mSpeed)
{
  Turn(mSpeed, mSpeed);
}

void Backward(int mSpeed)
{
  digitalWrite(HighL, HIGH);
  digitalWrite(LowL, LOW);
  analogWrite(EnableL, mSpeed);
 
  digitalWrite(HighR, HIGH);
  digitalWrite(LowR, LOW);
  analogWrite(EnableR, mSpeed);
}

void RightSpin(int mSpeed) {
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL, mSpeed);
 
  digitalWrite(HighR, HIGH);
  digitalWrite(LowR, LOW);
  analogWrite(EnableR, mSpeed);
}

void LeftSpin(int mSpeed) {
  digitalWrite(HighL, HIGH);
  digitalWrite(LowL, LOW);
  analogWrite(EnableL, mSpeed);
 
  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR, mSpeed);
}

void loop()
{
  Data();
  switch (data) {
    case 0:
      Forward(255);
      break;
    case 1:
      Forward(200);
      break;
    case 2:
      Backward(200);
      break;
    case 3:
      RightSpin(180);
      break;
    case 4:
      LeftSpin(180);
      break;      
    case 7:
      Stop();
      break;
  }
}