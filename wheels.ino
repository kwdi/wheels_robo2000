
#include <Encoder.h>

Encoder E1(2, 3); //UpRight
Encoder E2(18, 19); //UPLeft



int DirectionPin1 = 50; //direction of rotation of the right wheel (forward HIGH, LOW back) 
int DirectionPin2 = 51; //direction of the left wheel (forward HIGH, LOW back)
int PwmPin1 = 5; //right wheel speed with PWM 
int PwmPin2 = 4; //left wheel speed with PWM
int ShutPin1 = 52; 
int ShutPin2 = 53; 
int enablePin1 = 48; 
int enablePin2 = 49; 


void setup()
{
  
  pinMode(DirectionPin1, OUTPUT); //direction of rotation of the right wheel 
  pinMode(DirectionPin2, OUTPUT); //direction of rotation of the left wheel 
  pinMode(lederror, OUTPUT);
  pinMode(ShutPin1, OUTPUT);
  pinMode(PwmPin1, OUTPUT);
  pinMode(enablePin1, OUTPUT);
  pinMode(ShutPin2, OUTPUT);
  pinMode(PwmPin2, OUTPUT);
  pinMode(enablePin2, OUTPUT); 
  
  //setting for movement
  digitalWrite(enablePin1, HIGH);
  digitalWrite(ShutPin1, LOW);
  digitalWrite(enablePin2, HIGH);
  digitalWrite(ShutPin2, LOW);
  //
}

void loop()
{
}
