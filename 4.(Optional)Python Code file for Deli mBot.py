import cyberpi
import time
import mbot2
import mbuild

calibrated_square_angle = 94
offset = 0
distance = 0
colour = "white"
message = 0

# #wifi stuffs
# while not cyberpi.wifi.is_connect():
#     cyberpi.wifi.connect("Hotspotify", "huhuhuhu")
#     cyberpi.display.show_label('Connecting', 16, "center", index= 0)
#     time.sleep(0.5)
# cyberpi.display.show_label('Network Connected', 16, "center", index= 0)


def drive_calibrated(x, y):
  mbot2.drive_power(x, y * (-1.1))


#Servo
def drop_things():
  mbot2.EM_stop(port="all")
  for x in range(0, 129, 3):
    mbot2.servo_set(x, "S4")
    time.sleep(0.01)
  for x in range(129, 0, -3):
    mbot2.servo_set(x, "S4")
    time.sleep(0.01)
  mbot2.servo_set(0, "S4")
  drive_calibrated(20, 20)
  time.sleep(0.5)


while 1:
  if (mbot2.read_digital("S2") == 1): message = 1
  if (mbot2.read_digital("S1") == 1): message = 2
  cyberpi.display.show_label(message, 16, "center", index=0)
  time.sleep(1)
  if message != "0":
    drive_calibrated(20, 20)
    cyberpi.display.clear()
    time.sleep(0.3)
    colour = mbuild.quad_rgb_sensor.get_color_sta("R1", index=1)

    while (colour != "blue"):
      distance = mbuild.ultrasonic2.get(index=1)
      offset = mbuild.quad_rgb_sensor.get_offset_track(index=1)
      colour = str(mbuild.quad_rgb_sensor.get_color_sta("L1", index=1))
      # cyberpi.display.show_label("Distance = " + str(distance), 16, "mid", index = 0)
      # cyberpi.display.show_label("Offset = " + str(offset), 16, "mid", index = 0)
      cyberpi.display.show_label("Colour = " + colour, 16, "mid", index=0)

      if (offset == 0): drive_calibrated(20, 20)
      elif (0 < offset < 94): drive_calibrated(10, 12 + (abs(offset) / 2.3))
      elif (-94 < offset < 0): drive_calibrated(12 + (abs(offset) / 2.3), 10)
      elif (0 < offset < 100): drive_calibrated(-10, 10)
      elif (-100 < offset < 0): drive_calibrated(10, -10)
      else: mbot2.EM_stop(port="all")

      while (distance < 10):
        mbot2.EM_stop(port="all")
        time.sleep(1)
        distance = mbuild.ultrasonic2.get(index=1)

      if (message == 1):
        if (colour == "red"):
          drop_things()
      if (message == 2):
        if (colour == "green"):
          drop_things()

    message = "0"
    mbot2.EM_stop(port="all")
