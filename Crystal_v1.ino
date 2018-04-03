#include <Wire.h>
#include <ZX_Sensor.h>

char A;
char B;

#include <Wire.h>
#include <ZX_Sensor.h>

// Constants
const int ZX_ADDR = 0x10;  // ZX Sensor I2C address
const int analogInPin = A4;
const int analogOutPinRed = 9;
int outputValue = 0;
int sensorValue = 0; 
int val = 0; 

int LED1 = 13;

// Global Variables
ZX_Sensor zx_sensor = ZX_Sensor(ZX_ADDR);
uint8_t xpos;
uint8_t zpos;

void setup() {

  Serial.begin(9600);
   pinMode(LED1, OUTPUT);

}

void loop() {
  val = analogRead(ZX_ADDR);
   if ( zx_sensor.positionAvailable() ) {
    xpos = zx_sensor.readX();
    zpos = zx_sensor.readZ();
   //Serial.println(xpos);
   //Serial.println(zpos);
    //Serial.write(xpos);
    //Serial.write(zpos);
    
if (zpos <= 40) {
 Serial.write('a');
                           digitalWrite(LED1, HIGH);
  //Serial.println('a');
} 
if  (zpos <= 100 && zpos > 40) {
  Serial.write('b');
                           digitalWrite(LED1, LOW);
  //Serial.println('b');
}

if (zpos > 100 && xpos < 120){
 Serial.write('c');
  //Serial.println('c');
}                                           //play w more if statements
if ( zpos > 100 && xpos >= 120) {
  Serial.write('d');
  //Serial.println('d');
}

   }

sensorValue = analogRead(analogInPin);
outputValue = map(zpos, 0, 1000, 0, 255); 
analogWrite(analogOutPinRed, outputValue);
   
}

  
  //Serial.write(9600);
      

