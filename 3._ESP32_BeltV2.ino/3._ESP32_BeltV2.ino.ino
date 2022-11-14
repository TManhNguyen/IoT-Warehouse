#define BLYNK_TEMPLATE_ID "TMPLoW7W4kNL"
#define BLYNK_DEVICE_NAME "Autonomous Warehouse"
#define BLYNK_AUTH_TOKEN "h5xLM0vLqZL3OBgSC8VMFDnUy73VFoKa"

#include <ESP32Servo.h>
Servo ServoA;
Servo ServoB;

int pos = 0;    // variable to store the servo position
// Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33
int servoPinA = 18;
int servoPinB = 19;
int spd = 0;

#define PIN_IN1  27 // ESP32 pin GIOP27 connected to the IN1 pin L298N
#define PIN_IN2  26 // ESP32 pin GIOP26 connected to the IN2 pin L298N
#define PIN_ENA  14 // ESP32 pin GIOP14 connected to the EN1 pin L298N
#define PIN_IN3  33 // ESP32 pin GIOP33 connected to the IN3 pin L298N
#define PIN_IN4  25 // ESP32 pin GIOP25 connected to the IN4 pin L298N
#define PIN_ENB  15 // ESP32 pin GIOP15 connected to the ENB pin L298N

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "h5xLM0vLqZL3OBgSC8VMFDnUy73VFoKa";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Hotspotify";
char pass[] = "huhuhuhu";
int speed_motor = 240;

void setup()
{
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  ServoA.setPeriodHertz(50);    // standard 50 hz servo
  ServoB.setPeriodHertz(50);    // standard 50 hz servo
  ServoA.attach(servoPinA, 500, 2400);
  ServoB.attach(servoPinB, 500, 2400);

  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);
  pinMode(PIN_ENA, OUTPUT);
  pinMode(PIN_IN3, OUTPUT);
  pinMode(PIN_IN4, OUTPUT);
  pinMode(PIN_ENB, OUTPUT);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
}


BLYNK_WRITE(V0)
{
  if (param.asInt() == 1) {
    pushing_package(1);
    pull_con();
    delay(10000);
    slow_con();    
    Blynk.virtualWrite(V0, 0);
  } else {
    slow_con();
  }
}
BLYNK_WRITE(V1)
{
  if (param.asInt() == 1) {
    pushing_package(2);
    pull_con();
    delay(10000);
    slow_con();
    Blynk.virtualWrite(V1, 0);
  } else {
    slow_con();
  }
}

BLYNK_WRITE(V2)
{
  speed_motor = param.asInt();
}

void pull_con() {
  set_direction(1);
  for (spd = 130; spd <= speed_motor; spd += 1) {
    analogWrite(PIN_ENA, spd);
    analogWrite(PIN_ENB, spd);
    delay(20); //hold speed to protect motor
  }
}

void slow_con() {
  set_direction(1);
  for (spd = speed_motor; spd >= 130; spd -= 1) {
    analogWrite(PIN_ENA, spd);
    analogWrite(PIN_ENB, spd);
    delay(20);
  }
  spd = 0;
  analogWrite(PIN_ENA, spd);
  analogWrite(PIN_ENB, spd);
}

void set_direction(int dir) {
  digitalWrite(PIN_IN1, dir);
  digitalWrite(PIN_IN2, !dir);
  digitalWrite(PIN_IN3, dir);
  digitalWrite(PIN_IN4, !dir);
}

void pushing_package(int AorB) {
  if (AorB == 1) {
    ServoAPush();
  }
  if (AorB == 2) {
    ServoBPush();
  }
}

void ServoAPush() {
  for (pos = 70; pos >= 0; pos -= 1) {
    ServoA.write(pos);
    delay(15);
  }
  delay(100);
  for (pos = 0; pos <= 70; pos += 1) {
    ServoA.write(pos);
    delay(15);
  }
}

void ServoBPush() {
  for (pos = 0; pos <= 70; pos += 1) {
    ServoB.write(pos);
    delay(15);
  }
  delay(100);
  for (pos = 70; pos >= 0; pos -= 1) {
    ServoB.write(pos);
    delay(15);
  }
}
