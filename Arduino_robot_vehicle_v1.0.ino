#include <Servo.h>

// Servo object
Servo myServo;  
// Servo pin
#define SERVO_PIN 13  

// Ultrasonic sensor pins
#define TRIG_PIN A1
#define ECHO_PIN A0

// Motor pins
#define RIGHT_FORWARD 6  
#define RIGHT_BACKWARD 7  
#define LEFT_BACKWARD 8  
#define LEFT_FORWARD 9   

// IR sensor pins
#define left_ir 2
#define right_ir 4
#define front_ir 3 

void setup() {
  Serial.begin(9600);
  
  myServo.attach(SERVO_PIN);

  // DC motors setup
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(RIGHT_BACKWARD, OUTPUT);
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(LEFT_BACKWARD, OUTPUT);

  // IR sensors
  pinMode(left_ir, INPUT);
  pinMode(right_ir, INPUT);
  pinMode(front_ir, INPUT);

  // Ultrasonic sensor
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  myServo.write(0);
  stop_motors();
  delay(2000);
}

void loop() {
  int left_blocked = digitalRead(left_ir);
  int right_blocked = digitalRead(right_ir);
  int front_blocked = digitalRead(front_ir);

  stop_motors();

  // Function that calculates next direction of the robot.
  int x = 1;
  float last_distance = 0;
  int go_on = 0;
  // Measure next move:
  for (int iter = 0; iter <= 180; iter += 90) {
    myServo.write(iter);
    // Give servo more time to rotate (for precise ultrasonic measurement)
    // If measurements of distance don´t work, make sure sensor won´t measure while in rotation (it has to remain static) -> extend delay 
    delay(1000);
    float distance = measure_distance();

    if (distance > last_distance && distance < 500.0) { // If the distance is higher than 500, it means that it didn´t detect any obstacle
      last_distance = distance;
      go_on = iter / 90;
    }
    delay(400);
  }
  myServo.write(0);
  Serial.println(last_distance);
  if (last_distance < 800.0) {
    if (last_distance < 28.5) { x = 3; }
    if (go_on == 0) {
      move_right(90 * x);
    }
    else if (go_on == 2) {
      move_left(90 * x);
    }
    if (x != 2) {
      move_forward(((int)last_distance * 17)); 
    }
  } else { // If all measurements in all directions failed (no obstacles anywhere), move forward for 2 seconds
    move_forward(2000);
  }
  delay(1000);
}

// Ultrasonic measurement:
float measure_distance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
    
  float distance = duration * 0.034 / 2;
  delay(250);
  return distance;
}

// Functions for Controlling DC motors: 
void stop_motors() {
  digitalWrite(RIGHT_FORWARD, LOW);
  digitalWrite(RIGHT_BACKWARD, LOW);
  digitalWrite(LEFT_FORWARD, LOW);
  digitalWrite(LEFT_BACKWARD, LOW);
}

void move_forward(int period) {
  digitalWrite(RIGHT_FORWARD, LOW);
  digitalWrite(RIGHT_BACKWARD, HIGH);
  digitalWrite(LEFT_FORWARD, HIGH);
  digitalWrite(LEFT_BACKWARD, LOW);
  delay(period);
  stop_motors();
  delay(250);
}

void move_left(int degrees) { // function takes degrees on input and turns the robot in left direction
  int turning_time = (int)(5.55 * degrees);
  digitalWrite(RIGHT_FORWARD, LOW);
  digitalWrite(RIGHT_BACKWARD, HIGH); 
  digitalWrite(LEFT_FORWARD, LOW);
  digitalWrite(LEFT_BACKWARD, LOW);
  delay(turning_time);
  stop_motors();
  delay(250);
}

void move_right(int degrees) {
  int turning_time = (int)(5.55 * degrees);
  digitalWrite(RIGHT_FORWARD, LOW);
  digitalWrite(RIGHT_BACKWARD, LOW);
  digitalWrite(LEFT_FORWARD, HIGH); 
  digitalWrite(LEFT_BACKWARD, LOW);
  delay(turning_time);
  stop_motors();
}