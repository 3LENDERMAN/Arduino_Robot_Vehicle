# **Arduino Obstacle Avoiding Robot Vehicle**

This repository showcases a common Arduino Uno project – an autonomous robot vehicle that avoids obstacles.

The robot continuously scans its surroundings and detects obstacles in three directions (left, right, and front) using an ultrasonic sensor. Based on the measured distances, it moves toward the direction with the most open space.

## **System Overview**
The Arduino robot consists of an Arduino UNO, DC motors, and an ultrasonic sensor. The movement is determined by the measured distances in three directions (L – left, R – right, F – front).

The robot moves toward the **direction with the most open space**.
After ultrasonic sensor calculates distance it moves in that empty space for (distance in cm * 17) milliseconds - for average robot velocity of 37cm per second.

If it reaches a corner where obstacles are detected in all directions within 15 cm, it reverses to its previous position.

If obstacles are detected in all directions within 15–25 cm, the robot turns 180° and continues.

If an obstacle is not detected by the ultrasonic sensor, IR sensors serve as a backup to ensure the robot does not get stuck or crash into an obstacle.

## **Used Libraries** 
- **[Servo](https://docs.arduino.cc/libraries/servo/)**

## **All Used Components**
**Essential Components**
- Motor driver L298N
- 2× DC motor 3–6V (with gearbox)
- 2× 67mm wheels
- 360° rotary wheel
- Arduino Uno
- Servo MG90S
- Ultrasonic sensor HC-SR04
- 4× AA batteries + holder for 4 batteries
- Mini ON/OFF rocker switch
- 240x147mm laminate board or hard cardboard
- Dupont cables (14x F-M, 18x M-M)

**Optional Components**

- 3V LED fiber 280mm + holder for 2× AA batteries
- 3× Infrared sensor (for detecting close-up objects within 6 cm)
- Mini breadboard ZY-25 (for infrared sensors)
- 9V battery with connector (some motor drivers may not provide enough power for both the Arduino and motors)

- You will also need screws for rotary wheel,
- Hot glue gun to connect components to laminate board (or small screws),
- Black electritian tape for edges and
- Rubber tube to isolate soldered areas.

## **Common Troubleshooting Issues**

- Building the robot may present various challenges, even when following the exact procedure.

### **Hardware Malfunctions:** 

Before assembling everything, test each component individually to ensure proper functionality.

Soldering: Make sure dc motors are soldered properly and are holding tight. Be careful when soldering the led filament, it shouldn't be exposed to high temperatures for longer periods of time.

Motor Issues: If the DC motors produce noise but do not move, the issue may be insufficient voltage or motors spinning in opposite directions, which can confuse the L298N motor driver’s H-bridge.

## **Circuit Diagrams**

![circuit_image (2)](https://github.com/user-attachments/assets/ceca9151-d7a9-4645-8f2b-cc17dfc58804)

## **Final Build**

Below is the final appearance of the project:
### Appearence from the front side

![PXL_20250218_172159793-removebg-preview](https://github.com/user-attachments/assets/fd0173e3-41d3-4e35-b6c4-e16ea9689873)

## Appearence from top view (on the left), bottom (on the right)

![PXL_20250218_172212789-removebg-preview](https://github.com/user-attachments/assets/71c9aac4-5a73-425d-9a66-107cdc4d1305)


### **Note**

- There is an option to control speed of rotation of the wheels with method known as PWM (Pulse width modulation) which essentially just limits supply voltage and thus changes the rotary velocity.
- To enable this, you need to connect the pin ENA and ENB to arduino uno digital pins (only those supporting pwm - small wave symbol next to the pin) and set it as OUTPUT.
- Speed is then controlled by value in interval  40 - 255.
- Without this method, wheel rotation will be at maximum. 
