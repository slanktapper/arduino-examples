/*
 * Author: SMRAZA KEEN
 * Date:2016/6/29
 * IDE V1.6.9
 * Email:TechnicSmraza@outlook.com
 * Function:
 */
//#include <LiquidCrystal.h>
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define STEPPER_PIN_1 9
#define STEPPER_PIN_2 10
#define STEPPER_PIN_3 11
#define STEPPER_PIN_4 12
int step_number = 0;
int count = 0;
int stepDir = false;


int xpotPin = A0;
int ypotPin = A1;            
int bpotPin = 2; 
int xval=0;       //Initialize a variable
int xvalstart=0;       
int yval=0;       
int yvalstart=0;
int bval=0;
int delayMs = 64;
int xvstep = 100;
void setup()                                                                                     
{
  Serial.begin(9600);   //Display Address
  pinMode(xpotPin,INPUT);
  xvalstart = analogRead(xpotPin);   
  
  pinMode(ypotPin,INPUT);
  yvalstart = analogRead(xpotPin);   
  
  pinMode(bpotPin,INPUT); 
  
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);
  delay(1000);
}
void loop()
{ 
  xval = analogRead(xpotPin);   //Read Values from the xpotPin
  yval = analogRead(ypotPin);   
//  if (yval <10)
//  {
//    xvstep -= 1;
//  }
//  else if (yval > 1010)
//  {
//    xvstep += 1;
//  }
  bval = digitalRead(bpotPin);   
//  Serial.print("X=");            //Display "X="
//  Serial.println(xval);
//  Serial.print("Y=");       
//  Serial.println(yval);  
  stepDir = (xval < xvalstart);
  xval = xval - xvalstart;
  if (xval < 0)
  {
    xval *= (0-1);
  }
  delayMs = 64;
  if (xval > 5)
  {
    while (xval >= xvstep)
    {
      xval -= xvstep;
      delayMs /= 2;
    }
    OneStep(stepDir);
  }   
//  Serial.print("X=");
//  Serial.print(xval);
//  Serial.print(" delay= ");  
//  Serial.print(delayMs);
//  Serial.print(" Y=");
//  Serial.print(yval);
//  Serial.print(" xvstep= ");  
//  Serial.println(xvstep);
//  
  delay(delayMs); //After 150ms the screen will be refreshed
}



void OneStep(bool dir){
    if(dir){
switch(step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  break;
} 
  }else{
    switch(step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
 
  
} 
  }
step_number++;
  if(step_number > 3){
    step_number = 0;
  }
}
