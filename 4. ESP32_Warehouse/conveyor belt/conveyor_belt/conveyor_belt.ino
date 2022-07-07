/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID           "TMPLmu_7ZQ93"
#define BLYNK_DEVICE_NAME           "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "pjFg4XOFm09VZtyVWbHbevDj1lFrCkyQ"


// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Hotspotify";
char pass[] = "huhuhuhu";

BlynkTimer timer;

// This function is called every time the Virtual Pin 0 state changes

// This function is called every time the device is connected to the Blynk.Cloud


// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V0, millis() / 1000);
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  pinMode(0, OUTPUT); 
  pinMode(4, OUTPUT);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
}

BLYNK_WRITE(V1)
{
  int pinValue1 = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue1 == 1){
    digitalWrite(2, HIGH);   
    delay(1000);                      
    digitalWrite(2, LOW);
    delay(1000); 
    Blynk.virtualWrite(V1,0); 
    Blynk.virtualWrite(V3,1); 
  } 
}

BLYNK_WRITE(V2)
{
  int pinValue2 = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue2 == 1){
    digitalWrite(4, HIGH);   
    delay(1000);                      
    digitalWrite(4, LOW);
    delay(1000); 
    Blynk.virtualWrite(V2,0); 
    Blynk.virtualWrite(V4,1); 
  }
}

void loop()
{
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
