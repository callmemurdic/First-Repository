#include <Wire.h>
#include <ZX_Sensor.h>

char A;
char B;

#include <Wire.h>
#include <ZX_Sensor.h>

// Constants
const int ZX_ADDR = 0x10;  // ZX Sensor I2C address
const int analogInPin = A4;
const int analogOutPinRed = 4;
int outputValue = 0;
int sensorValue = 0; 
int val = 0; 

int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int LED4 = 10;
int LED5 = 9;


// Global Variables
ZX_Sensor zx_sensor = ZX_Sensor(ZX_ADDR);
uint8_t xpos;
uint8_t zpos;

void setup() {

  Serial.begin(9600);
   pinMode(LED1, OUTPUT);
   pinMode(LED2, OUTPUT);
   pinMode(LED3, OUTPUT);
   pinMode(LED4, OUTPUT);
   pinMode(LED5, OUTPUT);

   //pinMode(LED7, OUTPUT);

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

    digitalWrite(LED5, HIGH);

    //digitalWrite(LED7, HIGH);
    
if (zpos <= 40) {
 //Serial.write('a');
 
 digitalWrite(LED3, HIGH);
 delay(1000);
 digitalWrite(LED3, LOW);
 delay(500);


 
 digitalWrite(LED1, HIGH);
 digitalWrite(LED2, LOW);
 
  Serial.println('a');
  
} 

if  (zpos <= 100 && zpos > 40) {
  //Serial.write('b');

  digitalWrite(LED4, HIGH);
  delay(50);
  digitalWrite(LED4, LOW);
  delay(50);
  
                           digitalWrite(LED3, LOW);
                           digitalWrite(LED1, LOW);
                           digitalWrite(LED2, LOW);
                           
  Serial.println('b');
  
}

if (zpos > 100 && xpos < 120){
 //Serial.write('c');
 digitalWrite(LED5, HIGH);
 delay(700);
 digitalWrite(LED5, LOW);
 delay(100);
  digitalWrite(LED5, HIGH);
 delay(400);
 digitalWrite(LED5, LOW);
 delay(60);
                            digitalWrite(LED2, HIGH);
                            
  Serial.println('c');
  
}                                           //play w more if statements
if ( zpos > 100 && xpos >= 120) {
  //Serial.write('d');
  
                            digitalWrite(LED2, HIGH);
                            
  Serial.println('d');
  
}

   }

//sensorValue = analogRead(analogInPin);
//outputValue = map(zpos, 0, 1000, 0, 255); 
//analogWrite(analogOutPinRed, outputValue);
   
}



  
  //Serial.write(9600);
      

