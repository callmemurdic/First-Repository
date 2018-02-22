int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int BUTTON = 4;

void setup()
{
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(LED3,OUTPUT);
pinMode(BUTTON,INPUT);

}

void loop(){
 
if(digitalRead(BUTTON) == HIGH){
digitalWrite(LED1,HIGH);
delay(1000);
digitalWrite(LED2,HIGH);
delay(500);
digitalWrite(LED3,HIGH);
//delay(500);

}else{


digitalWrite(LED1,HIGH);
digitalWrite(LED2,HIGH);
digitalWrite(LED3,HIGH);


//}
}




