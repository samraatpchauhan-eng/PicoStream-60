  #include "HX711.h"

  HX711 scale;
  float calibFactor = 420.0;
  
  const int PIN_ENCODER_A = 0;
  const int PIN_ENCODER_B = 1;
  const int TOGGLE_SWITCH = 2;
  const int HX711_DT = 6;
  const int HX711_SCK = 7;
  const int FAN_PWM = 15;

  int fanSpeed = 0;
  int lastEncStateA;

void setup() {
  pinMode(FAN_PWM, OUTPUT);

  pinMode(TOGGLE_SWITCH, INPUT_PULLUP);
  pinMode(PIN_ENCODER_A, INPUT_PULLUP);
  pinMode(PIN_ENCODER_B, INPUT_PULLUP);

  lastEncStateA = digitalRead(PIN_ENCODER_A);

  analogWriteFreq(25000);
  analogWriteResolution(10);

  scale.begin(HX711_DT, HX711_SCK);
  scale.set_scale(calibFactor);
  scale.tare();
  Serial.begin(115200);
  

}

void loop() {
    if(digitalRead(TOGGLE_SWITCH) == LOW) {
      analogWrite(FAN_PWM, fanSpeed);
    } else {
      analogWrite(FAN_PWM, 0);
    }
    
    int currentA = digitalRead(PIN_ENCODER_A);

    if(currentA != lastEncStateA && currentA == LOW) {
      if(digitalRead(PIN_ENCODER_B) != currentA) {
        fanSpeed += 32;
      } else {
        fanSpeed -= 32;
      }
      fanSpeed = constrain(fanSpeed, 0, 1023);
    }
    lastEncStateA = currentA;

    static unsigned long lastReadTime = 0;
    if(millis() - lastReadTime >= 100) {
      if(scale.is_ready()) {
        float dragGrams = scale.get_units(1);

        Serial.print("Target_PWM:");
        Serial.print(fanSpeed);
        Serial.print(", ");
        Serial.print("Drag Force (grams):");
        Serial.println(dragGrams);
      }
      lastReadTime = millis();
    }
}
