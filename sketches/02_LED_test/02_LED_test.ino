// This is free and unencumbered software released into the public domain.
//
// For more information, please refer to <http://unlicense.org/>
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
//  - circuit: www.instructables.com/id/PWM-an-RGB-LED-Strip-with-Arduino/
//
// Instructions:
// 1) Ensure your Arduino is not connected to an external power supply
// 2) Connect Arduino to your computer via USB
// 3) Upload this sketch
// 4) Disconnect from computer, turn on external power supply (powers Arduino)
// 5) Each color channel should fade up and down, if not check your connections

// PWM Outputs
const byte R_CHANNEL = 4;
const byte G_CHANNEL = 5;
const byte B_CHANNEL = 6;

void setup(){
  pinMode(R_CHANNEL, OUTPUT);
  pinMode(G_CHANNEL, OUTPUT);
  pinMode(B_CHANNEL, OUTPUT);
}

void loop(){
  fade(R_CHANNEL);
  fade(G_CHANNEL);
  fade(B_CHANNEL);
}

void fade(byte c){
  for(byte val = 0; val <= 255; val++){
    digitalWrite(c, val);
    delay(10);
  }

  for(byte val = 0; val >= 0; val--){
    digitalWrite(c, val);
    delay(10);
  }

  delay(100);
  return;
}
