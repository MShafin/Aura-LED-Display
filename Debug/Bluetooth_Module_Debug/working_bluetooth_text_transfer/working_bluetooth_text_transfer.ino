#include<SoftwareSerial.h>

SoftwareSerial BT(10,11); //connect rx->11 tx->10
char data;

void setup()
{
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH);
  Serial.begin(38400);
  BT.begin(38400);
  Serial.println("hello world");
}
void loop()
{
  if(BT.available()){
    data = BT.read();    
Serial.print(data);
  }
  
  if(data == 'l'){
    data = ' ';
    Serial.println("clear");
  }
}
