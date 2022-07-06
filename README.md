# B2C Automated Warehouse with IoT
This project is used to demonstrated the workflow for setting up Shopify to control any hardware/robots using Internet of Things technology.
This project was developed for educational demonstration purposes.
This program was developed for [Center of Digital Excellence, RMIT University Vietnam](https://code-rmit.edu.vn/)

# Expected Outcomes

When fully setup, customer can shop on an website and order items. A system of conveyor belt and robot will pick up items, and deliver to their address accordingly.
For the simulation, the conveyor belt, delivery robots, and destination will be scaled down.


# System Architecture

This project used multiple different protocols to communicate between platforms and devices. The flowchart below will describe the main data flow process.
![enter image description here](https://github.com/TManhNguyen/IoT-Warehouse/blob/main/media/IoT%20Warehouse.jpg?raw=true)

## Platforms Usage

 1. **E-commerce website hosting**: Shopify is used to quickly create a mockup of an e-commerce website  with webhook support. Currently running on Shopify Basic plan.
 2. **Webhook handler**: Webhook.site is used to catch webhook, process JSON data and forward request to Blynk. Currently running on Webhook.site Pro plan. (Zapier is also offering a free version with 100req/mo)
 3. **IoT Platform**: Blynk is used to receive HTTP request and communicate with SOC. Currently running on Blynk Free plan.
 4. **Hardware Controller**: ESP32-S (NODE MCU) are used to connect with Blynk server. A range of other SOC is also supported by Blynk, but preferably a SOC supports WiFi connection.
#### Optional:
 5.   **Delivery Robot**: Sphero RVR is used to simulate a delivery robot. RVR offers self-correction on movement. Any other robots will work just fine.
 6. **Robot Interfacing**: Arduino Uno is used to receive command from ESP32-S and control Sphero RVR via UART.

##  Bill of Materials

|Item|Quantity  |Note|
|--|--|--|
|[ESP32-S](https://www.waveshare.com/nodemcu-32s.htm) |2  ||
|[Arduino Uno R3](https://docs.arduino.cc/hardware/uno-rev3)|2  ||
|[L298n Motor Controller](https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/)|2|To control motors for conveyor belt|
|[Generic DC Motor](https://techmartgh.com/product/geared-dc-motor-with-wheel/)|2|To roll conveyor belt|
|[Sphero RVR](https://sphero.com/products/rvr)|1|Delivery Robot|
|[18650 Battery](https://www.automaxx.in/product/18650-li-ion-2000mah-rechargeable-battery/)|2|To power conveyor belt|
|Jumpers|Plenty||
|Breadboard|A few||
|DIY Conveyor Belt|1|Made from a few [mBot Ultimate 2.0 sets](https://www.electromaker.io/shop/product/mbot-ranger-stem-edu-robot-kit?srsltid=AQP2TeOpQF3UteQWXzXLJKvGsyb56YhDhXLu1lv4_qR7iXvtWxUKbfIqy0A)	|
Links for ref only, I did not purchase from these shops nor affiliate with any of them.
