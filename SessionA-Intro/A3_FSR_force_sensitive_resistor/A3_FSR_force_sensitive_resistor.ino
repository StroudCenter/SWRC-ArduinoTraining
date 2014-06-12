/* Force Sensitive Resistor sketch. 
   This code will allow you to control the brightness of two LEDs by squeezing a 
   Force Sensitive Resistor.  Sensor data is also printed out via the serial port.
   */
 
 
int fsrAnalogPin = 1;   // FSR is connected to analog 1 when using the SWRC sensor shield
int redLEDpin = 5;      // Red LED is connected to Digital pin 5 (PWM pin)
int greenLEDpin = 6;    // Green LED is connected to Digital pin 6 (PWM pin)
int fsrReading;         // the analog reading from the FSR resistor divider
int LEDbrightness, LEDbrightnessNeg;     //a number between 0 and 255 that controlls the brightness of the LED  

 
void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  Serial.print("Force Sensitive Resistor!");
  pinMode(redLEDpin, OUTPUT);       //sets red LED pin as an output
  pinMode(greenLEDpin, OUTPUT);     //sets green LED pin as an output 
}
 
void loop(void) {
  fsrReading = analogRead(fsrAnalogPin);    //does an analog read sample of the voltage coming from the FSR sensor
  Serial.print("Analog reading = ");        //prints the data to the serial port
  Serial.println(fsrReading);
  //digitalWrite(5, HIGH);
  // we'll need to change the range from the analog reading (0-1023) down to the range
  // used by analogWrite (0-255) with map function
  LEDbrightness = map(fsrReading, 0, 1000, 0, 255);
  LEDbrightnessNeg = map(fsrReading, 0, 1000, 255, 0);
  // LED gets brighter the harder you press
  analogWrite(redLEDpin, LEDbrightness);
  analogWrite(greenLEDpin, LEDbrightnessNeg); 
  delay(50);       //waits 100ms (0.1 second) then starts the loop over again
}
