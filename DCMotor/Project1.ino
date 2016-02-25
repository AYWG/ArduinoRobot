#define MAX_SPEED 255
#define MIN_SPEED 0 // not moving
#define SPEED_DEC 5 // decrement value for speed

// Arduino digital pins for controlling DC motors
#define M1_DIR_PIN 4
#define M1_SPEED_PIN 5
#define M2_DIR_PIN 7
#define M2_SPEED_PIN 6

#define FORWARD 0
#define RIGHT 1
#define LEFT 2
 
void setup() { 
  pinMode(M1_DIR_PIN, OUTPUT);   
  pinMode(M2_DIR_PIN, OUTPUT); 
} 
 
void loop() { 

  move_forward(MAX_SPEED);
  //turn_left(2000);
  //turn_left(1000);
  delay(1000);
  stop_motors();
  delay(1000);
  /*
  stop_motors();
  delay(3000);
  turn_right(3000);
  delay(1000);
  turn_left(3000);
  */
  /*
  int value;
  for(value = 0 ; value <= 255; value+=5) 
  { 
    digitalWrite(M2_DIR_PIN, LOW);   
    //digitalWrite(M2, HIGH);       
    analogWrite(M2_SPEED_PIN, value);   //PWM Speed Control
    //analogWrite(E2, value);   //PWM Speed Control
    delay(30);
  } 
    */
}

// Move robot forward at a given speed ranging from MIN_SPEED to MAX_SPEED

void move_forward(int speed) {
  set_motors(FORWARD);
  analogWrite(M1_SPEED_PIN, speed);
  analogWrite(M2_SPEED_PIN, speed);
}

// Turn robot right 90 degrees from forward direction
// time (ms) specifies the duration of turning (adjust for 90 degree turn)

void turn_right(int time) {
  set_motors(RIGHT);
  analogWrite(M1_SPEED_PIN, MAX_SPEED);
  analogWrite(M2_SPEED_PIN, MAX_SPEED);
  delay(time);
  // once turning is finished, stop motors
  stop_motors();
}

// Turn robot left 90 degrees from forward direction
// time (ms) specifies the duration of turning (adjust for 90 degree turn)

void turn_left(int time) {
  set_motors(LEFT);
  analogWrite(M1_SPEED_PIN, MAX_SPEED);
  analogWrite(M2_SPEED_PIN, MAX_SPEED);
  delay(time);
  // once turning is finished, stop motors
  stop_motors();
}

// Slow down robot from MAX_SPEED to MIN_SPEED
// time (ms) specifies duration over which robot slows down

void slow_down(int time) {
  for (int speed = MAX_SPEED; speed > MIN_SPEED; speed -= SPEED_DEC) {
    analogWrite(M1_SPEED_PIN, speed);
    analogWrite(M2_SPEED_PIN, speed);
    delay(time / (MAX_SPEED / SPEED_DEC));
  }
}

// Stops the motors from turning

void stop_motors() {
  analogWrite(M1_SPEED_PIN, MIN_SPEED);
  analogWrite(M2_SPEED_PIN, MIN_SPEED);
}

// Set the motors for a desired direction for the robot

void set_motors(int direction) {
  if (direction == FORWARD) {
    digitalWrite(M1_DIR_PIN, LOW);
    digitalWrite(M2_DIR_PIN, LOW);
  }
  else if (direction == RIGHT) {
    digitalWrite(M1_DIR_PIN, HIGH );
    digitalWrite(M2_DIR_PIN, LOW);
  }
  else {      // direction == LEFT
    digitalWrite(M1_DIR_PIN, LOW);
    digitalWrite(M2_DIR_PIN, HIGH);
  }
}


