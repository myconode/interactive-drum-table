// This is free and unencumbered software released into the public domain.
// For more information, please refer to <http://unlicense.org/>
//
// Author: thelostspore <http://github.com/thelostspore>
//
// NOTE: THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
//
// ------------------------------------------------------------------------
//
// This sketch tests RGB color channels for a 9-12V RGB LED strip.
//  - LED circuit: www.instructables.com/id/PWM-an-RGB-LED-Strip-with-Arduino/
//
// Instructions:
// 1) Ensure your Arduino is not connected to an external power supply
// 2) Connect Arduino to your computer via USB
// 3) Upload this sketch
// 4) Disconnect from computer, turn on external power supply (powers Arduino)
// 5) Have fun!

// Analog Inputs
const byte R = A0;
const byte G = A1;
const byte B = A2;
const byte S = A3;

// PWM Outputs
const byte R_CHANNEL = 4;
const byte G_CHANNEL = 5;
const byte B_CHANNEL = 6;

// Digital Input
const byte MODE = 9;

// References
byte C_MODE = 0;

void setup(){
  // potentiometers
  pinMode(R, INPUT);
  pinMode(G, INPUT);
  pinMode(B, INPUT);
  pinMode(S, INPUT);

  // switch
  pinMode(MODE, INPUT);

  // RGB color channels
  pinMode(R_CHANNEL, OUTPUT);
  pinMode(G_CHANNEL, OUTPUT);
  pinMode(B_CHANNEL, OUTPUT);

  // Initialize pseudo-random number generator
  randomSeed(7);
}

void loop(){
  C_MODE = digitalRead(MODE);

  if(C_MODE==0){
    colorMix();
  }else{
    autoFade();
  }
}

void colorMix(){
  digitalWrite(R_CHANNEL, map(analogRead(R), 0, 1024, 0, 255));
  digitalWrite(G_CHANNEL, map(analogRead(G), 0, 1024, 0, 255));
  digitalWrite(B_CHANNEL, map(analogRead(B), 0, 1024, 0, 255));
  return;
}

void autoFade(){
  int speed = map(analogRead(S), 0, 1024, 1000, 20000);

  byte ran_r = random(0, 256);
  byte ran_g = random(0, 256);
  byte ran_b = random(0, 256);

  for(byte val = 0; val < 255; val++){
    digitalWrite(R_CHANNEL, ran_r);
    digitalWrite(G_CHANNEL, ran_g);
    digitalWrite(B_CHANNEL, ran_b);
    delay(20);
  }

  delay(speed);

  for(byte val = 0; val >= 0; val--){
    digitalWrite(R_CHANNEL, ran_r);
    digitalWrite(G_CHANNEL, ran_g);
    digitalWrite(B_CHANNEL, ran_b);
    delay(20);
  }

  delay(50);
  return;
}
