#include <SpheroRVR.h>
static DriveControl driveControl;
int item1, item2, item3, item4;

void setup() {
  // set up communication with the RVR
  rvr.configUART(&Serial);
  // get the RVR's DriveControl
  driveControl = rvr.getDriveControl();
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT);
} 

void close_arm() {
  analogWrite(5, 250);
  delay(4500);
  analogWrite(5, 0);
}

void open_arm() {
  analogWrite(6, 250);
  delay(3500);
  analogWrite(6, 0);
}
  
void loop() {
  rvr.resetYaw();
  if (digitalRead(A0) == 1) {
    driveControl.rollStart(0, 32);
    delay(1400);
    driveControl.rollStop(0);
    close_arm();
    driveControl.rollStart(180, -32);
    delay(1250);
    driveControl.rollStop(270);
    delay(500);
    driveControl.rollStart(270, 48);
    delay(2000);
    driveControl.rollStop(270);
    open_arm();
    driveControl.rollStart(90, -48);
    delay(1500);
    driveControl.rollStart(0,1);
    delay(1000);
  }if (digitalRead(A2) == 1){
    driveControl.rollStart(90, 48);
    delay(1700);
    driveControl.rollStop(0);
    delay(500);
    driveControl.rollStart(0, 32);
    delay(1800);
    driveControl.rollStop(0);
    close_arm();
    driveControl.rollStart(180, -32);
    delay(1650);
    int count = 2 ;
    while(count > 0 ){
      driveControl.rollStart(270, 48);
      delay(1200);
      count = count-1;
    }
    driveControl.rollStop(270);
    open_arm();
    driveControl.rollStart(90, -48);
    delay(1500);
    driveControl.rollStop(0);
    driveControl.rollStart(0,1);
    delay(1000);
  }
}
