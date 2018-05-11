
//  Variables
int pulse = 0;        // PURPLE WIRE ANALOG PIN 0
int FSR = 1;    //Analog 1
int fsr = 0;    //FSR variable



//int LED13 = 13;

int Signal1;                // holds the incoming raw data. Signal value can range from 0-1024
int Pthreshold = 550;            // Determine which Signal to "count as a beat", and which to ingore.

// The SetUp Function:
void setup() {
   Serial.begin(9600);         // Set's up Serial Communication at certain speed.
   //Serial.print(Signal1);
   //pinMode(LED13, OUTPUT);

}

// The Main Loop Function
void loop() {

  Signal1 = analogRead(pulse);  // Read the PulseSensor's value.
                                              //  "Signal" variable.
  fsr = analogRead(FSR);       //Read FSR

//Serial.print(Signal1);

if(Signal1 > Pthreshold){ Serial.print('1'); }    // Send the Signal value to Serial Plotter.

   
   Serial.print(' ');
   
   Serial.print(fsr);

   
   Serial.print('\n');

   
   delay(35);


}
