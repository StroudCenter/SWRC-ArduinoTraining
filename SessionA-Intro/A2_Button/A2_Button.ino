/*
  Button
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 6, when pressing a pushbutton attached to pin 4. 

 */

const int buttonPin = 4;     // the number of the pushbutton pin
const int greenLEDpin = 6;      // the number of the green LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  Serial.print("Button teseting sketch!");
  // initialize the LED pin as an output:
  pinMode(greenLEDpin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);     
  digitalWrite(buttonPin, HIGH);
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == LOW) {     
    // turn LED on:    
    digitalWrite(greenLEDpin, HIGH);  
    Serial.print("Button!");
  } 
  else {
    // turn LED off:
    digitalWrite(greenLEDpin, LOW); 
  }
}
