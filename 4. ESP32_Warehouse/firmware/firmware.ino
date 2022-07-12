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
#include <HTTPClient.h>

char auth[] = BLYNK_AUTH_TOKEN;
String serverName = "https://sgp1.blynk.cloud/external/api/update?token=pjFg4XOFm09VZtyVWbHbevDj1lFrCkyQ&";
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Hotspotify";
char pass[] = "huhuhuhu";



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
}

BLYNK_WRITE(V3)
{
  int pinValue1 = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue1 == 1){
    digitalWrite(2, HIGH);   
    delay(1000);                      
    digitalWrite(2, LOW);
    delay(1000); 
    Blynk.virtualWrite(V3,0); 
  } 
}

BLYNK_WRITE(V4)
{
  int pinValue2 = param.asInt(); // assigning incoming value from pin V1 to a variable
  if (pinValue2 == 1){
    digitalWrite(4, HIGH);   
    delay(1000);                      
    digitalWrite(4, LOW);
    delay(1000); 
    Blynk.virtualWrite(V4,0); 
  }
}

void loop()
{
  Blynk.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
