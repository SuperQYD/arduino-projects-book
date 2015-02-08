int switchState = 0; //The state of the button (on/off)//

void setup(){
  pinMode(3, OUTPUT); //Green LED//
  pinMode(4, OUTPUT); //Red LED//
  pinMode(5, OUTPUT); //Red LED//
  pinMode(2, INPUT); //The Switch//
}

void loop(){
  switchState = digitalRead(2); //"switchState" is set to the current state of the button (on/off)//

  if(switchState == LOW){ //If the button is not pressed...//
    
    digitalWrite(3, HIGH); //Green LED ON//
    digitalWrite(4, LOW); //Red LED OFF//
    digitalWrite(5, LOW); //Red LED OFF//

  } else { //If the button is pressed//

    digitalWrite(3, LOW); //Green LED OFF//
    digitalWrite(4, LOW); //Red LED OFF//
    digitalWrite(5, HIGH); //Red LED ON//
  
    delay(250); //Wait a quarter of a second//
    digitalWrite(4, HIGH); //Red LED ON//
    digitalWrite(5, LOW); //Red LED OFF//
    delay(250);
  }
}
