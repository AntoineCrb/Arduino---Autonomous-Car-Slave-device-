const int EnableL = 10;
const int HighL = 8;       // LEFT SIDE MOTOR
const int LowL = 9;
 
const int EnableR = 5;
const int HighR = 7;       //RIGHT SIDE MOTOR
const int LowR = 6;
 
const int D0 = 0;       //Raspberry pin 25
const int D1 = 1;       //Raspberry pin 24
const int D2 = 2;       //Raspberry pin 23
const int D3 = 3;       //Raspberry pin 22
 
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

void Turn(leftSpeed, rightSpeed) {
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL, leftSpeed);
 
  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR, rightSpeed);
}

void Forward(speed)
{
  Turn(speed, speed)
}

void Backward(speed)
{
  digitalWrite(HighL, HIGH);
  digitalWrite(LowL, LOW);
  analogWrite(EnableL, speed);
 
  digitalWrite(HighR, HIGH);
  digitalWrite(LowR, LOW);
  analogWrite(EnableR, speed);
}

void RightSpin(speed) {
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL, speed);
 
  digitalWrite(HighR, HIGH);
  digitalWrite(LowR, LOW);
  analogWrite(EnableR, speed);
}

void LeftSpin(speed) {
  digitalWrite(HighL, HIGH);
  digitalWrite(LowL, LOW);
  analogWrite(EnableL, speed);
 
  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR, speed);
}

void loop()
{
  Data();
  switch (data) {
    case 0: Stop();
    case 1: Forward(255);
    case 2: Backward(255);
    case 3: RightSpin(150);
    case 4: LeftSpin(150);
    default: Stop();
  }
}