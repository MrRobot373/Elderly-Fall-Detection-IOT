#define BLYNK_TEMPLATE_ID "TMPL3slln2SoC"
#define BLYNK_TEMPLATE_NAME "Fall Detection camera movement"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include<Servo.h>
Servo servo1, servo2;

char auth[] = "V4ekXUK67C9jzaWf41h-khvwKd5Tu5Kq";
char ssid[] = "LAPTOP-87RVDTOI 7100"; // Change your Wifi/ Hotspot Name
char pass[] = "ehhf2140"; // Change your Wifi/ Hotspot Password

BLYNK_WRITE(V0)
{
  int s0 = param.asInt(); 
  servo1.write(s0);
  Blynk.virtualWrite(V5, s0);
}
BLYNK_WRITE(V1)
{
  int s1 = param.asInt(); 
  servo2.write(s1);
  Blynk.virtualWrite(V6, s1);
}


void setup()
{
  Serial.begin(115200);
  servo1.attach(D2);
  servo2.attach(D3);

  Blynk.begin(auth, ssid, pass);//Splash screen delay
  delay(2000); 
}

void loop() 
{
  Blynk.run();
}
