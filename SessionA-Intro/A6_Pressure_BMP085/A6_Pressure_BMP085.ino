//BMP085 Barometric Pressure sensor board

#include <Wire.h>
#include <BMP085.h>

BMP085 bmp;

int readcount = 40;
float pressureAvg = 0;  
  
void setup() {
  Serial.begin(9600);
  bmp.begin();  
}
  
void loop() {
   // Serial.print("Temperature = ");
   // Serial.print(bmp.readTemperature());
  //  Serial.println(" *C");
    
   // Serial.print("Pressure = ");
   // Serial.print(bmp.readPressure());
   // Serial.println(" Pa");
    
    pressureAvg = 0; 
    
    for (int i = 0; i < readcount; i++){
      pressureAvg += bmp.readPressure();
      delay(5);
     }
     
     pressureAvg /= readcount;
     
     float pressureMbar = pressureAvg / 100.0;
     //pressureAvg = alt*3.2808;
    
    // Calculate altitude assuming 'standard' barometric
    // pressure of 1013.25 millibar = 101325 Pascal
    Serial.print("Pressure = ");
    Serial.print(pressureMbar,2);
    //Serial.print(bmp.readAltitude());
    Serial.println(" mbar");


    
    //Serial.println();
    delay(1000);
}
