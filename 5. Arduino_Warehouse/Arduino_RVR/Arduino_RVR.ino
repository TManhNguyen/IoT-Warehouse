#include <SpheroRVR.h>
#include <Servo.h>

static DriveControl driveControl;
int item1, item2, item3, item4;
int ServoPos = 0;
Servo myservo;

void setup() {
  // set up communication with the RVR
  rvr.configUART(&Serial);
  // get the RVR's DriveControl
  driveControl = rvr.getDriveControl();
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  myservo.attach(3);
  myservo.write(0);              // tell servo to go to position in variable 'pos'

}
void dropPackage() {
  for (ServoPos = 0; ServoPos <= 130; ServoPos += 1) { 
    myservo.write(ServoPos);            
    delay(15);                      
  } delay(1000);
  for (ServoPos = 0; ServoPos <= 130; ServoPos += 1) { 
    myservo.write(130-ServoPos);            
    delay(15);             
  }
}

void roll(int direction, int speed, float time) {
  driveControl.rollStart(direction, speed);
  delay(time*1000);
  driveControl.rollStop(direction);
  delay(250);
}

void loop() {
  rvr.resetYaw();
  if (digitalRead(A0) == 1) {
    digitalWrite(13, 1);
    roll(0, 32, 2);
    roll(270, 32, 2);
    dropPackage();
    roll(90, 32, 2);
    roll(180, 32, 2);
    driveControl.rollStop(0);
    digitalWrite(13, 0);

  } if (digitalRead(A1) == 1) {
    digitalWrite(13, 1);
    roll(0, 32, 2);
    roll(90, 32, 2);
    dropPackage();
    roll(270, 32, 2);
    roll(180, 32, 2);
    driveControl.rollStop(0);
    digitalWrite(13, 0);
  }
}
