

char tag[] ="180088F889E1"; 
char input[12];         
int count = 0;        
boolean flag = 0; 
void setup()  
{
  pinMode(2,OUTPUT); 
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);    

}
    void loop()
{
  digitalWrite(3,1);
  if(Serial.available())
  {
    count = 0;
  while(Serial.available() && count < 12)
    {
      input[count] = Serial.read(); 
      count++; 
      delay(5);
    }
    if(count == 12)
    {
      count =0;
      flag = 1;
      while(count<12 && flag !=0)  
      {
        if(tag[count]==input[count])
        flag = 1; 
        else
        flag= 0;
}
    if(flag == 1) 
    {
      digitalWrite(2,HIGH);
       digitalWrite(3,LOW);
      delay(5000);
      digitalWrite(2,LOW);
    }
     if(flag == 0)
      {
       for(int k =0; k<= 10; k++)
      {
        digitalWrite(4,HIGH);
      }
      }
    }
  }
}
