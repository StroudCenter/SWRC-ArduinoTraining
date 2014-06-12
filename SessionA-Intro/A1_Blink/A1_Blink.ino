/*
  Blink
  This code blinks the LEDs on the SWRC sensor board 
  Trying on Git.
 
 */

int redLEDpin = 5;
int greenLEDpin = 6;

int redledState = LOW; 
int greenledState = HIGH;

int delaytime = 1000;    

void setup() {

  pinMode(redLEDpin, OUTPUT);    // pin number for the Red LED
  pinMode(greenLEDpin, OUTPUT);    // pin number for the Green LED
}

void loop() {
    if (redledState == LOW)
      redledState = HIGH;
    else
      redledState = LOW;   

    if (greenledState == LOW)
      greenledState = HIGH;
    else
      greenledState = LOW;      
      
    digitalWrite (redLEDpin, redledState);
    digitalWrite (greenLEDpin, greenledState);  
      
    delay(delaytime);  
}
