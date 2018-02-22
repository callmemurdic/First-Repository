import processing.serial.*;

Serial myPort;
int val;
int x,y;
float angle;
void setup() {
size(500,500,P3D);

printArray(Serial.list());
String portName = Serial.list()[1]; //change # in [] for port input
myPort = new Serial(this, portName, 9600);

}

void draw(){
if ( myPort.available() > 0) { // If data is available,
val = myPort.read(); // read it and store it in val
}
// draw based on val
 background(0);
  angle= radians(val*1.5);
  translate(width/2,height);
  box(0,val,-120);
  translate(0,-120);
  branch(180);
}
  void branch (float h){
    h=h*0.6;
    if(h>2){
      pushMatrix();
      rotate(angle);
    ellipse(-val,val,h,-h);
    translate(0,-h);
    branch(h);
    popMatrix();
    
          pushMatrix();
      rotate(-angle/val/2);
    box(h,5,-h);
    translate(val,-h);
    branch(h);
    popMatrix();
    println("x:"+x,"y:"+y,"h"+h);
    stroke(255,val,val);

  }
  }