const int motorSwitch = 10;
const int motorControl1 = 9;
const int motorControl2 = 8;

const int turnSwitch = 5;
const int turnControl1 = 4;
const int turnControl2 = 3;

const int fullSpeed = 255;
const int threeQuarterSpeed = 190;
const int halfSpeed = 127;

void setup() {
  pinMode(motorSwitch, OUTPUT);
  pinMode(motorControl1, OUTPUT);
  pinMode(motorControl2, OUTPUT);

  pinMode(turnSwitch, OUTPUT);
  pinMode(turnControl1, OUTPUT);
  pinMode(turnControl2, OUTPUT);

  digitalWrite(motorSwitch, LOW);
  digitalWrite(turnSwitch, LOW);

  Serial.begin(9600);
}

void loop() {
  Serial.println("Waiting...");
  delay(5000);

  //backward
  Serial.println("Backward:");
  digitalWrite(motorControl1, HIGH);
  digitalWrite(motorControl2, LOW);
  driveSeries();

  delay(2000);

  //foreward
  Serial.println("Foreward:");
  digitalWrite(motorControl1, LOW);
  digitalWrite(motorControl2, HIGH);
  driveSeries(); 

  delay(2000);
  
  //right turn
  Serial.println("Right Turn");
  digitalWrite(turnControl1, HIGH);
  digitalWrite(turnControl2, LOW);
  turnSeries();

  delay(2000);

  //left turn
  Serial.println("Left Turn");
  digitalWrite(turnControl1, LOW);
  digitalWrite(turnControl2, HIGH);
  turnSeries();
}

void driveSeries() {
  Serial.println("1/2 Impulse");
  analogWrite(motorSwitch, halfSpeed);

  delay(3000);
  
  Serial.println("3/4 Impulse");
  analogWrite(motorSwitch, threeQuarterSpeed);

  delay(3000);
  
  Serial.println("Full Impulse");
  analogWrite(motorSwitch, fullSpeed);

  delay(3000);

  //stopping
  Serial.println("Stopping");
  digitalWrite(motorSwitch, LOW);
}

void turnSeries() {
Serial.println("Full Turn");
  analogWrite(turnSwitch, fullSpeed);

  delay(2000);

  Serial.println("Straight");
  digitalWrite(turnSwitch, LOW);
}

