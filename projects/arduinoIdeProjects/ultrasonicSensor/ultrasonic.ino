// Define ports and variables
int TRIG = 10;
int ECHO = 9;
int BUZZER = 7;
int LED = 6;
int DURATION;
int DISTANCE;


void setup() {
  // Set inputs/outputs and general configurations
  pinMode(TRIG, OUTPUT); 
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);  // To communicate and print
}

void loop() {
  // Initialize trigger
  digitalWrite(TRIG, LOW);
  delayMicroseconds(4);
  // Power up Trigger 
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  DURATION = pulseIn(ECHO, HIGH);
  DURATION = DURATION / 2; // Time out
  DISTANCE = DURATION * 0.0343 ; // d = t/2 * Vsound 

  // Turn on LED and BUZZER
  if (DISTANCE <= 50 && DISTANCE > 0) {
    digitalWrite(BUZZER, HIGH);
    digitalWrite(LED, HIGH);
    delay(5 * DISTANCE);
    digitalWrite(BUZZER, LOW);
    digitalWrite(LED, LOW);
  }

  Serial.print("DISTANCE (cm): ");
  Serial.println(DISTANCE);
  delay(50);

}
