#include <Wire.h>
#include <Encoder.h>

Encoder E1(2, 3); //UpRight
Encoder E2(18, 19); //UPLeft

const int Speed = 180;


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
  Wire.begin(2);        // join i2c bus
  Wire.onReceive(receiveEvent); // register event

  Serial.begin(9600);
  
  pinMode(DirectionPin1, OUTPUT); //direction of rotation of the right wheel 
  pinMode(DirectionPin2, OUTPUT); //direction of rotation of the left wheel 
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

void go(){
  digitalWrite(DirectionPin1, HIGH);
  analogWrite(PwmPin1, Speed);                              
  digitalWrite(DirectionPin2, HIGH); 
  analogWrite(PwmPin2, Speed); 
}

void backwards(){
  digitalWrite(DirectionPin1, LOW);
  analogWrite(PwmPin1, Speed);                              
  digitalWrite(DirectionPin2, LOW); 
  analogWrite(PwmPin2, Speed);
}

void turnleft(int t){
  digitalWrite(DirectionPin1, LOW);
  analogWrite(PwmPin1, Speed);                              
  digitalWrite(DirectionPin2, HIGH); 
  analogWrite(PwmPin2, Speed);
  delay(t);
}

void turnright(int t){
  digitalWrite(DirectionPin1, HIGH);
  analogWrite(PwmPin1, Speed);                              
  digitalWrite(DirectionPin2, LOW); 
  analogWrite(PwmPin2, Speed);
  delay(t);
}  

void stopmove(){
  analogWrite(PwmPin1, 0);                              
  analogWrite(PwmPin2, 0);
}  

void receiveEvent(int howMany)
{
  while(1 < Wire.available()) // loop through all but the last
  {
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
}
void loop()
{
  delay(100);
}
