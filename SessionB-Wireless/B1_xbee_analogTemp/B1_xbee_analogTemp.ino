//TMP36 Analog Temperature Sensor

#include <SoftwareSerial.h>
SoftwareSerial xbeeSerial(2,3);


String LoggerName = "DemoA";   //change "DemoA" to a unique name before uploading!!!



int sensorPin = 0;   //the analog pin the TMP36's Vout (sense) pin is connected to
                        //the resolution is 10 mV / degree centigrade with a
                        //500 mV offset to allow for negative temperatures
 
void setup()
{
  Serial.begin(9600);  
  xbeeSerial.begin(38400);                     
}
 
void loop()                     
{

 int reading = analogRead(sensorPin);  
 float voltage = reading * 5.0;
 voltage /= 1024.0; 
 
 Serial.print(voltage); Serial.println(" volts");
 
 float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                               //to degrees ((volatge - 500mV) times 100)
 Serial.print(temperatureC); Serial.println(" degrees C");
 
 float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
 Serial.print(temperatureF); Serial.println(" degrees F");
 Serial.println();
 
 
 xbeeSerial.print("LoggerID=");
 xbeeSerial.print(LoggerName);
 xbeeSerial.print("&TempC="); 
 xbeeSerial.print(temperatureC);
 xbeeSerial.println();
 
 
 delay(5000);                      //waiting a few seconds
}
