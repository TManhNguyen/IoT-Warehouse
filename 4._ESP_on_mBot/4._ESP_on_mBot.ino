/*************************************************************

  This sketch shows how to read values from Virtual Pins

  App project setup:
    Slider widget (0...100) on Virtual Pin V1
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPLoW7W4kNL"
#define BLYNK_DEVICE_NAME "Autonomous Warehouse"
#define BLYNK_AUTH_TOKEN "h5xLM0vLqZL3OBgSC8VMFDnUy73VFoKa"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Hotspotify";
char pass[] = "huhuhuhu";



void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, INPUT);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin V1
BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();
  if (pinValue == 1) {
    delay(10000);
    digitalWrite(D0, HIGH);
    delay(2000);
    digitalWrite(D0, LOW);
  } else {
    digitalWrite(D0, LOW);
  }
}

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  if (pinValue == 1) {
    delay(10000);
    digitalWrite(D1, HIGH);
    delay(2000);
    digitalWrite(D1, LOW);
  } else {
    digitalWrite(D1, LOW);
  }
}


void loop()
{
  Blynk.run();
}
