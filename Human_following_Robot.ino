int m1 = 10;
int m2 = 9;
int m3 = 3;
int m4 = 4;

int IRL = 8;
int IRR = 2;
int IRB = 5;
bool IR_L;
bool IR_R;
bool IR_B;

int trigPin = 7;
int echoPin = 6;
long duration;
int distance;


void setup() 
{
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
  
  pinMode(IRL,INPUT);
  pinMode(IRR,INPUT);
  pinMode(IRB,INPUT);
  
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = duration * 0.034/2;
  
  IR_L = digitalRead(IRL);
  IR_R = digitalRead(IRR);
  IR_B = digitalRead(IRB);
  
  if(distance >= 10 && distance <= 30)
  {
    if(IR_L == 1 & IR_R == 1)
    {
      digitalWrite(m1,HIGH);
      digitalWrite(m2,LOW);
      digitalWrite(m3,HIGH);
      digitalWrite(m4,LOW);
    }
    else if(IR_L == 0 & IR_R == 1)
    {
      digitalWrite(m1,LOW);
      digitalWrite(m2,HIGH);
      digitalWrite(m3,HIGH);
      digitalWrite(m4,LOW);
    }
    else if(IR_L == 1 & IR_R == 0)
    {
      digitalWrite(m1,HIGH);
      digitalWrite(m2,LOW);
      digitalWrite(m3,LOW);
      digitalWrite(m4,HIGH);
    }
    else
    {
      digitalWrite(m1,LOW);
      digitalWrite(m2,LOW);
      digitalWrite(m3,LOW);
      digitalWrite(m4,LOW);
    }
  }
  else if(distance <= 5 && IR_B == 1)
  {
    digitalWrite(m1,LOW);
    digitalWrite(m2,HIGH);
    digitalWrite(m3,LOW);
    digitalWrite(m4,HIGH);
  }
  else
  {
    digitalWrite(m1,LOW);
    digitalWrite(m2,LOW);
    digitalWrite(m3,LOW);
    digitalWrite(m4,LOW);
  }
}
