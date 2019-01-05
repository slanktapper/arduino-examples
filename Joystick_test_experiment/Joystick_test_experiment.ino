/*
 * Author: SMRAZA KEEN
 * Date:2016/6/29
 * IDE V1.6.9
 * Email:TechnicSmraza@outlook.com
 * Function:
 */
//#include <LiquidCrystal.h>
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int xpotPin = A0;
int ypotPin = A1;            
int bpotPin = 2; 
int xval=0;       //Initialize a variable
int yval=0;
int bval=0;
void setup()                                                                                     
{
  Serial.begin(9600);   //Display Address
  pinMode(xpotPin,INPUT);
  pinMode(ypotPin,INPUT);
  pinMode(bpotPin,INPUT); 
  delay(2000);
}
void loop()
{ 
  xval = analogRead(xpotPin);   //Read Values from the xpotPin
  yval = analogRead(ypotPin);   
  bval = digitalRead(bpotPin);   
  Serial.print("X=");            //Display "X="
  Serial.println(xval);
  Serial.print("Y=");       
  Serial.println(yval);  
  if (bval==LOW)
  {
//    Serial.setCursor(0, 1) ;   
    Serial.print("Button ON"); 
  }
  else
  {
//  Serial.setCursor(0, 1) ;
  Serial.print("Button OFF"); 
  }
  delay(150); //After 150ms the screen will be refreshed
}
