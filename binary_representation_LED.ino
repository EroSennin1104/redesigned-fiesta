int dec;
int bi;
int i;

void setup()
{
  Serial.begin(9600);
  for(i=5;i<=9;i++)
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
  if(Serial.available())
  {
    Serial.print("Enter a Number from 0 to 31");
    Serial.read(dec);
  } 
  for(i=9;i>=5;i--)
  {
   bi=dec%2;
   if(bi==1)
   {
     digitalWrite(i,HIGH);
   }
   dec=dec/2;   
  }  
}
