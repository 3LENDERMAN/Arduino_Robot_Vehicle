# **Arduino Obstacle Avoiding Robot Vehicle**
This repository showcases a common Arduino Uno project – an autonomous robot vehicle that avoids obstacles.

The robot continuously scans its surroundings and detects obstacles in three directions (left, right, and front) using an ultrasonic sensor. Based on the measured distances, it moves toward the direction with the most open space.

## **System Overview**
The Arduino robot consists of an Arduino UNO, DC motors, and an ultrasonic sensor. The movement is determined by the measured distances in three directions (L – left, R – right, F – front).

The robot moves toward the **direction with the most open space**.
If it reaches a corner where obstacles are detected in all directions within 15 cm, it reverses to its previous position.
If obstacles are detected in all directions within 15–25 cm, the robot turns 180° and continues.
If an obstacle is not detected by the ultrasonic sensor, IR sensors serve as a backup to ensure the robot does not get stuck or crash into an obstacle.

## **Used Libraries** 
- **[SoftwareSerial](https://docs.arduino.cc/learn/built-in-libraries/software-serial/)**
- **[Servo](https://docs.arduino.cc/libraries/servo/)**

## **Hardware Components Used**
**Essential Components**
- Motor driver L298N
- 2× DC motor 3–6V (with shaft)
- 2× 69mm wheels
- 360° rotary wheel
- Arduino Uno
- Servo MG90S
- Ultrasonic sensor HC-SR04
- 4× AA batteries + holder for 4 batteries

**Optional Components**

- 3V LED fiber 280mm + holder for 2× AA batteries
- 3× Infrared sensor (for detecting close-up objects within 6 cm)
- Mini breadboard ZY-25 (for infrared sensors)
- 9V battery with connector (some motor drivers may not provide enough power for both the Arduino and motors)


## **Common Troubleshooting Issues**

- Building the robot may present various challenges, even when following the exact procedure.

### **Hardware Malfunctions:** 

Before assembling everything, test each component individually to ensure proper functionality.
Motor Issues: If the DC motors produce noise but do not move, the issue may be insufficient voltage or motors spinning in opposite directions, which can confuse the L298N motor driver’s H-bridge.

## **Circuit Diagrams**

Work in progress...

## **Final Build**

Below is the final appearance of the project:
Work in progress...
