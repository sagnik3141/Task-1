/*

    MPU6050 Librarey: https://github.com/jarzebski/Arduino-MPU6050  (c) 2014 by Korneliusz Jarzebski   
*/

#include <Wire.h> //Lib for IIC communication
#include <MPU6050.h> //Lib for MPU6050
#include <SoftwareSerial.h>// import the serial library

SoftwareSerial BT(10, 11);  // RX, TX

MPU6050 mpu;

unsigned long timer = 0;

unsigned long timer2 = 0;

float timeStep = 0.01;
float pitch = 0;
float roll = 0;
float yaw = 0;
float temp =0;

void setup() 
{
  Serial.begin(115200);

  BT.begin(9600); //start the Bluetooth communication at 9600 baudrate

  // Initialize MPU6050
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }
  
  mpu.calibrateGyro();   // Calibrate gyroscope during start

  mpu.setThreshold(3); //Controls the sensitivty 
}

void loop()
{
  timer = millis();

  //Read Gyro and Temperature sensor values
  Vector norm = mpu.readNormalizeGyro();
  temp = mpu.readTemperature();

  // Calculate Pitch, Roll and Yaw
  pitch = pitch + norm.YAxis * timeStep;
  roll = roll + norm.XAxis * timeStep;
  yaw = yaw + norm.ZAxis * timeStep;

  // Print values
  Serial.print(" Pitch = ");
  Serial.print(pitch);
  Serial.print(" Roll = ");
  Serial.print(roll);  
  Serial.print(" Yaw = ");
  Serial.print(yaw);
  Serial.print(" Temp = ");
  Serial.print(temp);
  Serial.println(" *C");

  delay((timeStep*1000) - (millis() - timer)); //makes sure we read only at a an interval of 0.01 secounds

  if ((millis()-timer2) > 200)
  send_BT();
}

void send_BT()
{   
  int t;
  int x;
  int y;

  if (roll>-100 && roll<100)
  x = map (roll, -100, 100, 0, 100);

  if (pitch>-100 && pitch<100)
  y = map (pitch, -100, 100, 100, 200);

  if (temp>0 && temp<50)
  t = 200 + int(temp); 
  
  BT.write(x); 
  BT.write(y);
  BT.write(t); 

  timer2 = millis();
}
