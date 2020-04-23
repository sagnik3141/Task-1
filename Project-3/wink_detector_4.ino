/*
  "wink_detector_4.ino"
  Code by LINGIB
  https://www.instructables.com/member/lingib/instructables/
  Last update 12 April 2020.

  ---------------
  About:
  ---------------
  This software allows the user to control up to two LEDS or other device(s) by winking.
  - The left-eye controls one LED/device
  - The right-eye controls the other
  - Only one LED may be controlled at a time
  - Normal blinks are ignored

  A home-made head-band with three sensors is required.

  ---------------
  Setting up:
  ---------------
  This software expects a modified AD8232 ECG monitor break-out board
  and two threshold detectors fashioned from an LM324 quad op-amp.
  An instructable detailing how to modify the AD8232 PCB may be found at
  https://www.instructables.com/member/lingib/instructables/

  The modified AD8232 ECG monitor has three leads ... one reference and two inputs.
  - The reference lead lead is positioned between your eyebrows
  - The input leads are placed one above each eye at eyebrow level.
  - Reverse the input leads if the LED flashes are reversed

  The threshold detectors output a logic high whenever the AD8232
  output voltage falls below 0.2 volts or exceeds 2.8 volts.

  ---------------
  Terms of use:
  ---------------
  The software is provided "AS IS", without any warranty of any kind, express or implied,
  including but not limited to the warranties of mechantability, fitness for a particular
  purpose and noninfringement. In no event shall the authors or copyright holders be liable
  for any claim, damages or other liability, whether in an action of contract, tort or
  otherwise, arising from, out of or in connection with the software or the use or other
  dealings in the software.
*/

// ==================================
//  Globals
// ==================================

// ----- Definitions
#define OPEN LOW                        // Comparator output is LOW when eye is open
#define CLOSED HIGH                     // Comparator output is HIGH when eye is closed
#define ON HIGH                         // Comparator output is LOW when eye is open
#define OFF LOW                         // Comparator output is HIGH when eye is closed

// ----- Wiring
const byte LeftEye = 4;                 // Comparator output for left eye on pin D4
const byte RightEye = 5;                // Comparator output for right eye on pin D5
const byte LeftLed = 6;                 // LED for left eye connected to pin D6
const byte RightLed = 7;                // LED for right eye connected to pin D7

// ----- Eye logic
bool LeftEyeState;                      // Holds current eye state
bool RightEyeState;                     // Holds current eye state

// ----- Wink detection logic
unsigned long LeftStopTime;
unsigned long RightStopTime;
unsigned long StopTime = 1000000UL;     // 1000000 uS = 1 second

// ==================================
//  setup()
// ==================================
void setup() {
  // ----- Configure Serial port
  Serial.begin(115200);

  // ----- Configure eyes as inputs
  pinMode(LeftEye, INPUT_PULLUP);
  pinMode(RightEye, INPUT_PULLUP);

  // ----- Configure LEDs as outputs
  pinMode(LeftLed, OUTPUT);
  pinMode(RightLed, OUTPUT);

  // ----- Force loop() to wait until both eyes are open
  LeftEyeState = CLOSED;
  RightEyeState = CLOSED;
  digitalWrite(LeftLed, ON);         // LEDs indicate eyes states
  digitalWrite(RightLed, ON);

  // ----- Start the lock-out timers
  LeftStopTime = micros();
  RightStopTime = micros();
}

// ==================================
//  loop()
// ==================================
void loop()
{
  // ----- Check for left-wink
  /*
     This code block cannot be entered until the RightStopTime delay has elapsed.
     This delay is set by the right-wink detector and prevents false readings from
     the left-wink detector.
  */
  if (micros() > RightStopTime) {
    LeftEyeState = digitalRead(LeftEye);
    while (LeftEyeState == CLOSED) {
      digitalWrite(LeftLed, ON);                            // Left eye closed
      LeftEyeState = digitalRead(LeftEye);
      LeftStopTime = micros() + StopTime;                   // Disable right-wink detector for 1 second
    }
    digitalWrite(LeftLed, OFF);                             // Left eye open
  }

  // ----- Check for right-wink
  /*
     This code block cannot be entered until the LeftStopTime delay has elapsed.
     This delay is set by the left-wink detector and prevents false readings from
     the right-wink detector.
  */
  if (micros() > LeftStopTime) {
    RightEyeState = digitalRead(RightEye);
    while (RightEyeState == CLOSED) {
      digitalWrite(RightLed, ON);                           // Right eye closed
      RightEyeState = digitalRead(RightEye);
      RightStopTime = micros() + StopTime;                  // Disable left-wink detector for 1 second
    }
    digitalWrite(RightLed, OFF);                            // Right eye open
  }
}
