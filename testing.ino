#define leftEyePin A0
#define rightEyePin A1
#define upEyePin A2
#define downEyePin A3



int getEyeReading (uint8_t pin, int readings = 5) {
    int sensorCumulativeValue = 0;
    
    for (int i = 0; i < readings; i ++) {
        delay(20);
        sensorCumulativeValue += analogRead(pin);
    }
    return sensorCumulativeValue/readings;
    // int sensorVal = map
    //   (
    //     sensorCumulativeValue / readings,
    //     // (pin==leftEyePin?250:450), (pin==leftEyePin?581:615),
    //     (pin==leftEyePin?250:540), (pin==leftEyePin?581:600),
    //     0, 255
    //   );
    // return constrain(sensorVal, 0, 255);
}
void setup () {
    pinMode(leftEyePin, INPUT);
    pinMode(rightEyePin, INPUT);
    pinMode(upEyePin, INPUT);
    pinMode(downEyePin, INPUT);
    Serial.begin(9600);
}

void loop () {
    int left = getEyeReading(upEyePin);
    int right = getEyeReading(downEyePin);
    Serial.print("up:");
    Serial.print(left);
    Serial.print(",down:");
    Serial.println(right);
}
