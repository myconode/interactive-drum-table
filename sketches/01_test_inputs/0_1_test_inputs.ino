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
// Instructions:
// 1) a| Ensure your four (or more) potentiometers are hooked up properly
//       - Potentiometer basics: https://www.arduino.cc/en/tutorial/potentiometer
//    b| Ensure toggle switch is configured correctly
//       - Toggle basics: https://www.arduino.cc/en/tutorial/switch
// 2) Ensure your Arduino is not connected to an external power supply
// 3) Connect Arduino to your computer via USB
// 4) Upload this sketch
// 5) Open the Serial Monitor to confirm the values of the potentiometers,
//    each should be between 0 & 255
//
// Potentiometer reference:
// There are three terminals on a potentiometer ( +POWER+ | INPUT | -GROUND- )
// Hook the + & - terminals up to the POWER section of your Arduino (5V and GND pins)
// Connect the middle pin to an Analog Input

// Analog Inputs
const byte R = A0;
const byte G = A1;
const byte B = A2;
const byte S = A3;

// Digital Input
const byte MODE = 8;

void setup(){
  Serial.begin(9600);

  // potentiometers
  pinMode(R, INPUT);
  pinMode(G, INPUT);
  pinMode(B, INPUT);
  pinMode(S, INPUT);

  // switch
  pinMode(MODE, INPUT);
}

void loop(){
  Serial.println("MODE  :" + digitalRead(MODE));
  Serial.println("RED   :" + map(analogRead(R), 0, 1024, 0, 255) );
  Serial.println("GREEN :" + map(analogRead(G), 0, 1024, 0, 255) );
  Serial.println("BLUE  :" + map(analogRead(B), 0, 1024, 0, 255) );
  Serial.println("SPEED :" + map(analogRead(S), 0, 1024, 0, 100) );
  Serial.println("----------------------");
  delay(750);
}

