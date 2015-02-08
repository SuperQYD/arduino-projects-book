const int sensorPin = A0; //Initallizes the constant "sensorPin"...//
const float baselineTemp = 20.0; //Intiallizes the constant "baselineTemp"...//

//Function "setup" resets pins...//
void setup(){

  int pinNumber; //A variable used to reset the pins..."

  Serial.begin(9600); //Starts the Serial Port inputs...//

  //Resets the pins and turns them off...//
  for(pinNumber = 2; pinNumber < 5; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

//Function "loop" begins the main processes//
void loop(){

  //"sensorVal" is set to the value recieved from the analog pin (A0 - temperature sensor)...//
  int sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal/1024.0) * 5.0;
  float temperature = (voltage - 0.5) * 100;

  //Sensor Display//
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);


  //Voltage Display//
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(" , degrees C: ");

  //Temperature Display//
  Serial.println(temperature);

  //If the temperature is less than 20 degrees celsius...//
  if(temperature < baselineTemp){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } 
  //If the temperature is greater than 22 degrees and less than 24 degrees...//
  else if(temperature >= baselineTemp+2 && temperature < baselineTemp +4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  //If the temperature is greater than 24 degrees and less than 26 degrees...//
  else if(temperature >= baselineTemp +4 && temperature < baselineTemp+6){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  //If the temperature is greater than 26 degrees...//
  else if(temperature >= baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  delay(1);
}
