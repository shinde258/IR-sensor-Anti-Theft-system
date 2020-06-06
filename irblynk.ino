//Rudra DIY Crafts 
//Blynk Alert system
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
char auth[] = " 2EFePo5RpntEA-1sUnQBuFxOXCy62325"; //Auth code sent via Email
char ssid[] = "Shinde"; //Wifi name
char pass[] = "Praveen$258";  //Wifi Password
int flag=0;
void notifyOnThings()
{
  int isButtonPressed = digitalRead(D3);
  if (isButtonPressed==1 && flag==0) {
    Serial.println("Shinde Someone in the House");
    Blynk.notify("Alert : Shinde Someone in the House");
    flag=1;
  }
  else if (isButtonPressed==0)
  { 
    flag=0;
  }
}
void setup()
{
Serial.begin(9600);
Blynk.begin(auth, ssid, pass); 
pinMode(D3,INPUT_PULLUP);
timer.setInterval(1000L,notifyOnThings); 
}
void loop()
{
  Blynk.run();
  timer.run();
}
