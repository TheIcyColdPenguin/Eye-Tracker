int sensorPin = A0;
int duration = 1000;

int calibrationZero;
int calibrationOne;

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(11, OUTPUT);

  // Far
  Serial.begin(9600);
}
void loop() {
  analogWrite(11, 0);
  Serial.print("Far calibration...");
  delay(duration);

  int sensorCumulativeValue = 0;
  int reads = 0;
  unsigned long timeStart = millis();
  do {
    delay(20);
    sensorCumulativeValue += analogRead(sensorPin);
    reads++;
  } while (millis() <= timeStart + duration);
  calibrationZero = sensorCumulativeValue / reads;

  Serial.print(calibrationZero);
  Serial.println();

  // Close
  Serial.print("Close calibration...");
  analogWrite(11, 220);
  delay(duration);

  sensorCumulativeValue = 0;
  reads = 0;
  timeStart = millis();
  do {
    delay(20);
    sensorCumulativeValue += analogRead(sensorPin);
    reads++;
  } while (millis() <= timeStart + duration);
  calibrationOne = sensorCumulativeValue / reads;

  Serial.print(calibrationOne);
  Serial.println();
}