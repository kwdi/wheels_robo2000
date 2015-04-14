#include <Wire.h>
#include <Encoder.h>

Encoder E1(2, 3); //UpRight
Encoder E2(18, 19); //UPLeft

//byte x = 0;

const int Speed = 180;
int Trans = 0; //transmission value
const int t = 900; //Time the robot spends turning (miliseconds) (turntime)


int DirectionPin1 = 40; //direction of rotation of the right wheel (forward HIGH, LOW back) 
int DirectionPin2 = 44; //direction of the left wheel (forward HIGH, LOW back)
int PwmPin1 = 5; //right wheel speed with PWM 
int PwmPin2 = 7; //left wheel speed with PWM
int ShutPin1 = 22; 
int ShutPin2 = 26; 
int enablePin1 = 32; 
int enablePin2 = 36; 


void setup()
{
  Wire.begin(5);        // join i2c bus
  Wire.onReceive(receiveEvent); // register event 

  Serial.begin(9600);

  pinMode(DirectionPin1, OUTPUT); //direction of rotation of the LEFT wheel 
  pinMode(DirectionPin2, OUTPUT); //direction of rotation of the RIGHT wheel 
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

void receiveEvent(int bytes)
{ 
  int x;
  if(Wire.available() != 0)
  {
      x = Wire.read();
      Serial.print("Received: ");
      Serial.println(x);

  } 

    if(x==1){
      Serial.println("1");
        go();
    } 
    else if(x==2){
      Serial.println("2");
        backwards();
    } 
    else if(x==3){
      Serial.println("3");
        turnleft(t);
    }
    else if(x==4){
      Serial.println("4");
        turnright(t);
    }
    else {
      Serial.println("else");
      stopmove();
    }


  
} 



void loop(){
  

}
