/*
   firei fighting robot Test Code 5/10/2018
*/

#include <Wire.h>                                                                                 //include the i2c library
#include <Adafruit_PWMServoDriver.h>                                                              //include the PCA9685 adafruit library to easily communicate with the PCA9685 PWM module.

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();                                          // called this way, it uses the default address 0x40

#define flameSensorRight A0                                                                       //define a variable called "flameSensorRight" with a value A0
#define flameSensorMiddle A1                                                                      //define a variable called "flameSensorMiddle" with a value 1
#define flameSensorLeft A2                                                                        //define a variable called "flameSensorLeft" with a value A2

int flameSensorRightReading;                                                                      //define a variable called "flameSensorRightReading" with a data type integer to store the right sensor output value inside.
int flameSensorMiddleReading;                                                                     //define a variable called "flameSensorMiddleReading" with a data type integer to store the middle sensor output value inside.
int flameSensorLeftReading;                                                                       //define a variable called "flameSensorLeftReading" with a data type integer to store the left sensor output value inside.

#define in1 0                                                                                     //defining const. named "in1" with value 0, which refers to the PCA9685 pin 0.
#define in2 1                                                                                     //defining const. named "in2" with value 1, which refers to the PCA9685 pin 1.
#define in3 2                                                                                     //defining const. named "in3" with value 2, which refers to the PCA9685 pin 2.
#define in4 3                                                                                     //defining const. named "in4" with value 3, which refers to the PCA9685 pin 3.
#define enableA 4                                                                                 //defining const. named "enableA" with value 4, which refers to the PCA9685 pin 4.
#define enableB 5                                                                                 //defining const. named "enableB" with value 5, which refers to the PCA9685 pin 5.

#define lowSpeed 1400                                                                             //define a const. named "lowSpeed" with a value 1400, which refers to the pulse-width which will run the motor at a relatively low speed.
#define fullSpeed 4095                                                                            //define a const. named "fullSpeed" with a value 4095, which refers to the pulse-width which will run the motor at the full speed.

#define fireMotor 1                                                                               //define a const. named "fireMotor" with a value 1, which refers to the PICO's pin which connected with the TIP transistor base pib to control the motor fan.

bool fire;                                                                                        //initialize a flag named "fire" with a boolean data type, this flag value will change according to if there is a fire or not.

void setup() {

  pwm.begin();                                                                                    //begin the i2c communication.
  pwm.setPWMFreq(60);                                                                             // Analog servos run at ~60 Hz updates

  pinMode(flameSensorRight, INPUT);                                                               //set the right sensor pin as input pin.
  pinMode(flameSensorMiddle, INPUT);                                                              //set the middle sensor pin as input pin.
  pinMode(flameSensorLeft, INPUT);                                                                //set the left sensor pin as input pin.
  pinMode(fireMotor, OUTPUT);                                                                     //set the fan motor pin as output pin, to be able to write on it.
}

void loop() {

  flameSensorRightReading = digitalRead(flameSensorRight);                                        //read the right sensor output value, then store it in the "flameSensorRightReading" variable.
  flameSensorMiddleReading = digitalRead(flameSensorMiddle);                                      //read the middle sensor output value, then store it in the "flameSensorMiddleReading" variable.
  flameSensorLeftReading = digitalRead(flameSensorLeft);                                          //read the left sensor output value, then store it in the "flameSensorLeftReading" variable.

  /*
     if the fire is at the left side of the motor, ask the robot to turn left, and turn off the fan .
  */

  if (flameSensorLeftReading == 0 && flameSensorMiddleReading == 1 && flameSensorRightReading == 1) {
    turnLeft(lowSpeed);
    fireFightingOff();
  }

  /*
    if the fire isin front of the motor, ask the robot to run forward towards the fire, and make the fire bool true.
  */

  else if (flameSensorLeftReading == 1 && flameSensorMiddleReading == 0 && flameSensorRightReading == 1) {
    forward(lowSpeed);
    fire = true;
  }

  /*
    if the fire is at the right side of the motor, ask the robot to turn right, and turn off the fan .
  */

  else if (flameSensorLeftReading == 1 && flameSensorMiddleReading == 1 && flameSensorRightReading == 0) {
    turnRight(lowSpeed);
    fireFightingOff();
  }

  /*
    if the fire is at the left side of the motor, ask the robot to turn left, and turn off the fan .
  */

  else if (flameSensorLeftReading == 0 && flameSensorMiddleReading == 0 && flameSensorRightReading == 1) {
    turnLeft(lowSpeed);
    fireFightingOff();
  }

  /*
    if the fire is at the right side of the motor, ask the robot to turn right, and turn off the fan .
  */

  else if (flameSensorLeftReading == 1 && flameSensorMiddleReading == 0 && flameSensorRightReading == 0) {
    turnRight(lowSpeed);
    fireFightingOff();
  }

  /*
    if the three sensors senses that thre is a fire, stop running the motors and turn on the fan to put it out.
  */

  else if (flameSensorLeftReading == 0 && flameSensorMiddleReading == 0 && flameSensorRightReading == 0) {
    motorStop();
    fireFightingOn();
  }

  /*
    if the three sensors senses that there is no fire, stop running the motors and turn off the fan.
  */

  else if (flameSensorLeftReading == 1 && flameSensorMiddleReading == 1 && flameSensorRightReading == 1) {
    motorStop();
    fireFightingOff();
  }

  /*
 * while the fire bool variable is TRUE execute the "fireFightingOn" function.
*/
  while (fire == true) {
    fireFightingOn();
  }

}

//*******************************************************************************************  USER-DEFINED FUNCTIONS PART  *****************************************************************************************************************


/*
   the forward function orders the robot to move forward.
   takes no arguments.
   returns nothing
*/

void forward(int motorSpeed) {
  pwm.setPin(in1, 4095);
  pwm.setPin(in2, 0);
  pwm.setPin(in3, 0);
  pwm.setPin(in4, 4095);
  pwm.setPin(enableA, motorSpeed);
  pwm.setPin(enableB, motorSpeed);
}

/*
   the backward function orders the robot to move backward.
   takes no arguments.
   returns nothing
*/

void backward(int motorSpeed) {
  pwm.setPin(in1, 0);
  pwm.setPin(in2, 4095);
  pwm.setPin(in3, 4095);
  pwm.setPin(in4, 0);
  pwm.setPin(enableA, motorSpeed);
  pwm.setPin(enableB, motorSpeed);
}

/*
   the turnLeft function orders the robot to turn left.
   takes no arguments.
   returns nothing
*/

void turnLeft(int motorSpeed) {
  pwm.setPin(in1, 0);
  pwm.setPin(in2, 4095);
  pwm.setPin(in3, 0);
  pwm.setPin(in4, 4095);
  pwm.setPin(enableA, motorSpeed);
  pwm.setPin(enableB, motorSpeed);
}

/*
   the turnRight function orders the robot to turn right.
   takes no arguments.
   returns nothing
*/

void turnRight(int motorSpeed) {
  pwm.setPin(in1, 4095);
  pwm.setPin(in2, 0);
  pwm.setPin(in3, 4095);
  pwm.setPin(in4, 0);
  pwm.setPin(enableA, motorSpeed);
  pwm.setPin(enableB, motorSpeed);
}

/*
   the motorStop function ordes the robot to stop.
   takes no arguments.
   returns nothing
*/

void motorStop() {
  pwm.setPin(in1, 4095);
  pwm.setPin(in2, 4095);
  pwm.setPin(in3, 4095);
  pwm.setPin(in4, 4095);
}

/*
 * the "fireFightingOn" function is responsible for putting out the fire.
 * this function will stop running the robot car motors after 200 miliiseconds, then turn on the fan for 1.5 seconds when the time is over turn it off, then change the fire variable to false.
 * this function return nothing
 * this function takes no arguments.
*/

void fireFightingOn() {

  delay(200);
  motorStop();
  digitalWrite(fireMotor, HIGH);
  delay(1500);
  fireFightingOff();
  fire = false;
}

/*
 * the "fireFightingOff" function is responsible for turning off the fan .
 * this function return nothing
 * this function takes no arguments.
*/

void fireFightingOff() {
  digitalWrite(fireMotor, LOW);
}
