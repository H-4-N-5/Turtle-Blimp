int turnPotPin = A2;    // select the input pin for the potentiometer
int turnPotValue = 0;  // variable to store the value coming from the sensor

void setup() {
   Serial.begin(9600); 
}

void loop() {
  turnPotValue = analogRead(turnPotPin);    
  Serial.println(turnPotValue);       
  delay(200);                  
}
