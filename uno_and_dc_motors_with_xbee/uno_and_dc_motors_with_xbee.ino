

int incomingByte;      // a variable to read incoming serial data into

int leftmotorForward = 8; // pin 8 --- left motor (+) green wire
int leftmotorBackward = 11; // pin 11 --- left motor (-) black wire
int leftMotorSpeedPin = 9; // pin 9 --- left motor speed signal

int rightmotorForward = 12; // pin 12 --- right motor (+) green wire
int rightmotorBackward = 13; // pin 13 --- right motor (-) black
int rightMotorSpeedPin = 10; // pin 10 --- right motor speed signal

int leftMotorSpeed = 0;
int rightMotorSpeed = 0;

int turnPotVal = NULL;       // variable to store the value coming from the sensor


void setup() 
{ 
  pinMode(leftmotorForward, OUTPUT);
  pinMode(leftmotorBackward, OUTPUT);
  pinMode(leftMotorSpeedPin, OUTPUT);
  pinMode(rightmotorForward, OUTPUT);
  pinMode(rightmotorBackward, OUTPUT);
  pinMode(rightMotorSpeedPin, OUTPUT);
  
  Serial.begin(9600);
} 
 
 
void loop() 
{ 

 
  if (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
      turnPotVal = Serial.parseInt(); 
    
  }
 /*
 int potval = analogRead(A2);
 Serial.print("Received Value = ");
 Serial.println(potval);
 
 Serial.print("Constrained Value = ");
 Serial.println(turnPotVal);
 */
 
 
 
 turnPotVal = turnPotVal/4;
 
    //if (Serial.read() == '\n') {
    //turnPotVal = analogRead(potPin);    // read the value from the potentiometer
    
    //Serial.println(turnPotVal);
    
     if (turnPotVal > 145) {
      
        rightMotorSpeed = abs(turnPotVal);
        leftMotorSpeed = 0;
      
      } else if (turnPotVal < 110) {
    
        rightMotorSpeed = 0;
        leftMotorSpeed = abs(255 - turnPotVal);
        
      } else {
      
        rightMotorSpeed = 255;
        leftMotorSpeed = 255;
      
    }
    
    /*
    Serial.print("right motor speed = ");
    Serial.println(rightMotorSpeed);
    Serial.print("left motor speed = ");
    Serial.println(leftMotorSpeed);
    Serial.println("/n");
    */

    
    //analogWrite(motorPinA, rightMotorSpeed);
    //analogWrite(motorPinB, leftMotorSpeed);
    
    analogWrite(leftMotorSpeedPin,leftMotorSpeed); //Enable left motor by setting speed
    analogWrite(rightMotorSpeedPin,rightMotorSpeed); //Enable left motor by setting speed
    digitalWrite(leftmotorBackward,LOW); // Drives LOW outputs down first to avoid damage
    digitalWrite(rightmotorBackward,LOW);
    digitalWrite(leftmotorForward,HIGH);
    digitalWrite(rightmotorForward,HIGH);
    //}
  
} 

