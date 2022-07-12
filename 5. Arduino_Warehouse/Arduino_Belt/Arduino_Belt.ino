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
UltraSonicDistanceSensor_hshop  SRF05(TRIGGER_PIN,ECHO_PIN);  // SRF05(triggerPin, echoPin)

DC dcL(IN2, IN1);// dcL(dirPin, pwmPin)
DC dcR(IN4, IN3);

float cm = 0;     //unit cm
float lastcm = 0;
bool flagDetectObstacles = false;

/*------------------ End Variable declare ---------*/
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  dcL.init();
  dcR.init();
}
 
float readUltrasonic(){
  return SRF05.measureDistanceCm();
}

void readSensor(){                        // [Read Sensor]
  cm = readUltrasonic(); 
  Serial.println(cm);
  if(cm <10 && lastcm <10 ){
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
  }
  lastcm = cm;
  delay(80);
}
void loop() {
  readSensor();
}
