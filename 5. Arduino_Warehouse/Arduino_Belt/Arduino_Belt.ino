#include "dc.h"
#include "UltraSonicDistanceSensor_hshop.h"
/*================== define PIN ===================*/
#define IN1             5
#define IN2             4
#define IN3             6
#define IN4             7
/*
  OUT1----Left Black
  OUT2----Left Red
  OUT3----Right Black
  OUT4----Right Red
*/

#define TRIGGER_PIN     9
#define ECHO_PIN        8
/*------------------ End define PIN ---------------*/
/*================== Variable declare =============*/
UltraSonicDistanceSensor_hshop  SRF05(TRIGGER_PIN, ECHO_PIN); // SRF05(triggerPin, echoPin)

DC dcL(IN2, IN1);// dcL(dirPin, pwmPin)
DC dcR(IN4, IN3);
int speedRobot = 200;
float cm = 20;     //unit cm
float lastcm = 20;
bool flagDetectObstacles = false;

/*------------------ End Variable declare ---------*/
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  dcL.init();
  dcR.init();
}

float readUltrasonic() {
  return SRF05.measureDistanceCm();
}

void readSensor() {
  Forward(250);
  cm = readUltrasonic();
  Serial.println(cm);
  while (cm > 8 || lastcm > 8 || cm < 0 ) {
    cm = readUltrasonic();
    Serial.println(cm);
    lastcm = cm;
    delay(80);
  }
  digitalWrite(13, HIGH);
  delay(2000);
  digitalWrite(13, LOW);
  Stop();
}
void loop() {
  if (digitalRead(A0) == 1) {
    // Switch package 1
    readSensor();
  } if (digitalRead(A1) == 1) {
    // Switch package 2
    readSensor();
  }
  Serial.println(digitalRead(A0));
  Serial.println(digitalRead(A1));
  delay(100);
}

void Backward(int _speed_) {
  dcL.forward(_speed_);
  dcR.forward(_speed_);
}

void Forward(int _speed_) {
  dcL.backward(_speed_);
  dcR.backward(_speed_);
}

void Stop() {
  dcL.forward(0);
  dcR.forward(0);
}
