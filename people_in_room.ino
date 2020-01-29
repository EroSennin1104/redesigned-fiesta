int IR1=7,IR2=8;    //Initialisation of Sensor variables
int num=0;

void setup()
{
  pinMode(IR1,INPUT);    
  pinMode(IR2,INPUT);
  Serial.begin(9600);
}

void display()     //Number of people in the room at particular time
{
  Serial.println("The number of people in the room is");
  Serial.print(num);
}

void loop()
{
  if(digitalRead(IR1)==HIGH)    //For entering
  {
    num++;
    display();
    delay(1200);
  }
    if(digitalRead(IR2)==HIGH) //For exiting
  {
    num--;
    display();
    delay(1200);
  }
    if(digitalRead(IR1)==HIGH&&digitalRead(IR2)==HIGH) //When two people try to enter and exit at the same time
  {
    Serial.println("Please step back");
    delay(5000);
  }
}  
