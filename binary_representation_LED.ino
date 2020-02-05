int dec;           //Decimal input from the user
int bi;            //Value of bit
int i;             //Loop control variable

void setup()
{
  Serial.begin(9600);
  for(i=5;i<=9;i++)                 //Initialisation of LED pins
  {
    pinMode(i,OUTPUT);
  }
}

void loop()
{
  for(i=5;i<=9;i++)
  {
    digitalWrite(i,LOW);
  }
  if(Serial.available()==0)                   //For recieving user input
  {
    Serial.print("Enter a Number from 0 to 31");
    dec=Serial.parseInt();
  } 
  for(i=9;i>=5;i--)                 
  {
   bi=dec%2;
   if(bi==1)                         //Lighting LED according to bit value
   {
     digitalWrite(i,HIGH);
   }
   dec=dec/2;   
  }  
}
