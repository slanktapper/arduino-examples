int tempPin = A0;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(tempPin);     // read the input pin
  Serial.println(val);   
  delay(500);

}
