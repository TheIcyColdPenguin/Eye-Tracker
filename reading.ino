#define leftEyePin A0
#define rightEyePin A1



int getEyeReading (uint8_t pin, int readings = 5) {
    int sensorCumulativeValue = 0;
    
    for (int i = 0; i < readings; i ++) {
        delay(20);
        sensorCumulativeValue += analogRead(pin);
    }
    // return sensorCumulativeValue/readings;
    int sensorVal = map
      (
        sensorCumulativeValue / readings,
        // (pin==leftEyePin?250:450), (pin==leftEyePin?581:615),
        (pin==leftEyePin?250:540), (pin==leftEyePin?581:600),
        0, 255
      );
    return constrain(sensorVal, 0, 255);
}
void setup () {
    pinMode(leftEyePin, INPUT);
    pinMode(rightEyePin, INPUT);
    Serial.begin(9600);
}

void loop () {
    int left = getEyeReading(leftEyePin);
    int right = getEyeReading(rightEyePin);
    Serial.print(left);
    Serial.print(",");
    Serial.println(right);
}
