const int EnableL = 10;
const int HighL = 8;       // LEFT SIDE MOTOR
const int LowL = 9;
 
const int EnableR = 5;
const int HighR = 7;       //RIGHT SIDE MOTOR
const int LowR = 6;
 
const int D0 = 0;
const int D1 = 1;
const int D2 = 2;
const int D3 = 3;

int a,b,c,d,data;
 
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
pinMode(D3, INPUT_PULLUP);
}
 
void Data()
{
   a = digitalRead(D0);
   b = digitalRead(D1);
   c = digitalRead(D2);
   d = digitalRead(D3);

   data = 8*d+4*c+2*b+a; // binary to decimal
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

  Turn(150,200);
  return;
  Data();
  switch (data) {
    case 0:
      Stop();
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
    case 5: // right 1
      Turn(200,180);
      break;
    case 6: // right 2
      Turn(200,150);
      break;
    case 7: // left 1
      Turn(180,200);
      break;
    case 8: // left 2
      Turn(150,200);
      break;
  }
}