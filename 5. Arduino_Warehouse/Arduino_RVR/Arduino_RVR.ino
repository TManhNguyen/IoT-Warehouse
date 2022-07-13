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
  myservo.attach(3);
  myservo.write(0);              // tell servo to go to position in variable 'pos'

} 
void dropPackage(){
   for (ServoPos = 0; ServoPos <= 130; ServoPos += 1) { // goes from 0 degrees to 180 degrees
    myservo.write(ServoPos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }delay(1000);
  myservo.write(0);
}

void loop() {
  rvr.resetYaw();
  if (digitalRead(A0) == 1) {
    digitalWrite(13,1);
    driveControl.rollStart(0, 32);
    delay(1400);
    driveControl.rollStop(0);
    dropPackage();
    driveControl.rollStart(180, -32);
    delay(1250);
    driveControl.rollStop(270);
    delay(500);
    driveControl.rollStart(270, 48);
    delay(2000);
    driveControl.rollStop(270);
    driveControl.rollStart(90, -48);
    delay(1500);
    driveControl.rollStart(0,1);
    delay(1000);
    digitalWrite(13,0);

  }if (digitalRead(A2) == 1){
    digitalWrite(13,1);
    driveControl.rollStart(90, 48);
    delay(1700);
    driveControl.rollStop(0);
    delay(500);
    driveControl.rollStart(0, 32);
    delay(1800);
    driveControl.rollStop(0);
    dropPackage();
    driveControl.rollStart(180, -32);
    delay(1650);
    int count = 2 ;
    while(count > 0 ){
      driveControl.rollStart(270, 48);
      delay(1200);
      count = count-1;
    }
    driveControl.rollStop(270);
    driveControl.rollStart(90, -48);
    delay(1500);
    driveControl.rollStop(0);
    driveControl.rollStart(0,1);
    delay(1000);
    digitalWrite(13,0);
  }
}
