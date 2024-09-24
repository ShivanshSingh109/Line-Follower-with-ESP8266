// Define IR sensor pins for ESP8266
const int leftIR = D0;   // Left IR sensor (connected to D0)
const int rightIR = D1;  // Right IR sensor (connected to D1)
const int middleIR = D2; // Middle IR sensor (connected to D2)

// Define output pins for motor control
const int motorRightA = D6;  // Control pin A for motor on the right (connected to D6)
const int motorRightB = D7;  // Control pin B for motor on the right (connected to D7)

void setup()
{
  Serial.begin(9600);
  
  // Define motor control pins as outputs
  pinMode(motorRightA, OUTPUT);
  pinMode(motorRightB, OUTPUT);

  // Define IR sensor pins as inputs
  pinMode(middleIR, INPUT);
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);
  
  // Set initial speed for motors (optional if using analogWrite)
  analogWrite(motorLeftA, 255);
  analogWrite(motorRightA, 255);
  
  delay(100);
}

void loop()
{
  // Read sensor values
  bool leftDetected = digitalRead(leftIR);
  bool rightDetected = digitalRead(rightIR);
  bool middleDetected = digitalRead(middleIR);

  // Move forward if only the middle sensor detects the line
  if (leftDetected == 0 && middleDetected == 1 && rightDetected == 0) {
    forword();
  }

  // Slight left if both middle and left sensors detect the line
  else if (leftDetected == 1 && middleDetected == 1 && rightDetected == 0) {
    SturnLeft();
  }

  // Sharp left if only the left sensor detects the line
  else if (leftDetected == 1 && middleDetected == 0 && rightDetected == 0) {
    turnLeft();
  }

  // Slight right if both middle and right sensors detect the line
  else if (leftDetected == 0 && middleDetected == 1 && rightDetected == 1) {
    SturnRight();
  }

  // Sharp right if only the right sensor detects the line
  else if (leftDetected == 0 && middleDetected == 0 && rightDetected == 1) {
    turnRight();
  }

  // Stop if all sensors detect the line
  else if (leftDetected == 1 && middleDetected == 1 && rightDetected == 1) {
    Stop();
  }
}

// Define motor movement functions
void forword() {
  digitalWrite(motorLeftA, HIGH);
  digitalWrite(motorLeftB, HIGH);
  , HIGH);
   HIGH);
  Serial.println("Moving Forward");
}

void SturnRight() {
  digitalWrite(motorLeftA, HIGH);
  digitalWrite(motorLeftB, LOW);
  Serial.println("Slight Turn Right");
}

void turnRight() {
  digitalWrite(motorLeftA, LOW);
  digitalWrite(motorLeftB, LOW);
  Serial.println("Sharp Turn Right");
}

void SturnLeft() {
  digitalWrite(motorLeftA, HIGH);
  digitalWrite(motorLeftB, LOW);
  Serial.println("Slight Turn Left");
}

void turnLeft() {
  digitalWrite(motorLeftA, LOW);
  digitalWrite(motorLeftB, HIGH);
  Serial.println("Sharp Turn Left");
}

void Stop() {
  digitalWrite(motorLeftA, HIGH);
  digitalWrite(motorLeftB, HIGH);
  Serial.println("GO");
}