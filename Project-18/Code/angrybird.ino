void setup() {
  Serial.begin(9600); //Transmit at 9600 Baud Rate
}

boolean Mclick = false;

void loop() {
  int potValue = analogRead(A0); //variable to store potValue
  int FlexValue = analogRead(A1); //variable to store Flex Value
 // Serial.println(FlexValue);
 // Serial.print("POT: ");
 // Serial.println(potValue);
 // Serial.print("Flex: ");

  if (FlexValue>=65 && FlexValue<=115) //my flex sensor varies from 65 to 120, your might be different
  {
  FlexValue = map (FlexValue,120,65,0,100);  //based on bending convert to 0 to 100
  
  if (FlexValue>=5) // 1 and 0 is used for mouse click so start from 5
   { 
   Mclick=true; 
   Serial.write(1);  //1 is sent to make mouse left click 
   Serial.write(FlexValue); //Flex value is the distance to move mouse in X direction
   }
  else
  { 
  Mclick=false; 
  Serial.write(0);}
  }

  else
   { 
  Mclick=false; 
  Serial.write(0);}
  
 if (potValue<=200)
 {
  potValue = map(potValue,0,200,101,201); //Based in turn convert to 101 to 201
  Serial.write(potValue); //Pot value is the distance to move mouse in Y direction
 }

  delay(500);     //stability delay   
}