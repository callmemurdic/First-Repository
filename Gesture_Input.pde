import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
import ddf.minim.signals.*;
import ddf.minim.spi.*;
import ddf.minim.ugens.*;
import processing.serial.*;

Minim minim;
AudioPlayer tone;
AudioPlayer tone2;
AudioPlayer tone3;
AudioPlayer mahooty;
AudioPlayer McCandlish ;
FFT fft; //time domain buffer
Serial myPort;      // The serial port

int[] serialInArray = new int[2]; // Where we'll put what we receive
int xpos, ypos;     // Starting position of the ball
boolean firstContact = false;  // Whether we've heard from the microcontroller
char val;

/////////////////////////


void setup() {
  
 size(256, 256); // Stage size
 minim = new Minim(this); // load files
 mahooty = minim.loadFile("mahooty1.mp3");
 McCandlish = minim.loadFile("McCandlish.mp3");
 tone = minim.loadFile("tone.mp3");
 tone2 = minim.loadFile("tone2.mp3");
 tone3 = minim.loadFile("tone3.mp3");
 //fft = new FFT (mahooty.bufferSize(), mahooty.sampleRate() );
 //tone.loop();
 //printArray(Serial.list());
 String portName = Serial.list()[1]; // right side USB
 myPort = new Serial(this, portName, 9600);
}

void draw() {
  
  if ( myPort.available() > 0) { // If data is available,
val = myPort.readChar(); // read it and store it in val
}
println (val); //prints to Processing console
//fft.forward(mahooty.mix); // perform a forward FFT on the samples in mix buffer,
if (val==('a')){     // if ypos is closer to sensors ( < )
  mahooty.rewind();
  mahooty.play();
}

  
if (val==('b')){   //ypos is past "close up" threshold
tone.rewind();
  tone.play();

  }

  if (val==('c')){   //xpos is less than "halfway" threshold
    tone2.rewind();
    tone2.play();
  }

    if (val==('d')){   //xpos is less than "halfway" threshold
    tone3.rewind();
    tone3.play();
    mahooty.pause();
}

}