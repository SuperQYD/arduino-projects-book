//LED Pin Input Locations//
const int greenLEDPin = 9; 
const int blueLEDPin = 10;
const int redLEDPin = 11;

//LED Analog Input Positions//
const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

//Resetting the Values of the LEDS//
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

//Resetting the Values of the Photoresistors//
int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

//Function "setup" for setting values//
void setup(){
  //Starts the Serial Communication//
  Serial.begin(9600);

  //Labeling the LEDS as "ouput"//
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

//Function "loop" for updating values//
void loop(){
  //Sensor Values of the LED//
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  
  //Window for monitoring values//
  Serial.print("Raw Sensor Values \t Red: ");
  Serial.print(redSensorValue);
  Serial.print("\t Green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t Blue: ");
  Serial.print(blueSensorValue);

  //Current Value of the LEDS//
  redValue = redSensorValue/4;
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;

  //Window for monitoring current values//
  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(redValue);
  Serial.print("\t Green: ");
  Serial.print(greenValue);
  Serial.print("\t Blue: ");
  Serial.print(blueValue);
  
  //Changes the resistance//
  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
}


