#include <SoftwareSerial.h>
SoftwareSerial BT(2, 4); 

void setup()  
{
  Serial.begin(115200);
  // set digital pin to control as an output
  pinMode(13, OUTPUT);
  // set the data rate for the SoftwareSerial port
  BT.begin(9600);
  // Send test message to other device
  BT.println("Hello from Arduino");
}
char a; // stores incoming character from other device
void loop() 
{
  if (BT.available())
  // if text arrived in from BT serial...
  {
    a=(BT.read());
    Serial.println(a);
    if (a=='1')
    {
      digitalWrite(13, HIGH);
      BT.println("LED on");
    }
    if (a=='2')
    {
      digitalWrite(13, LOW);
      BT.println("LED off");
    }
    if (a=='?')
    {
      BT.println("Send '1' to turn LED on");
      BT.println("Send '2' to turn LED on");
    }   
  
  }
}
