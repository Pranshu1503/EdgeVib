const int LRA1 = 12;
const int LRA2 = 10;
const int LRA3 = 9;
const int LRA4 = 8;
const int LRA5 = 7;

const int funcGenPin = A0;

unsigned long timePeriod = 0;

void setup() {
  Serial.begin(9600);

  pinMode(LRA1, OUTPUT);
  pinMode(LRA2, OUTPUT);
  pinMode(LRA3, OUTPUT);
  pinMode(LRA4, OUTPUT);
  pinMode(LRA5, OUTPUT);

  Serial.println("Enter the time period for the sine wave (in ms):");
}

void loop() {
  if (Serial.available() > 0) {
    timePeriod = Serial.parseInt();
    if (timePeriod > 0) {
      while (Serial.available() > 0) {
        Serial.read();
      }

      Serial.print("Time period: ");
      Serial.print(timePeriod);
      Serial.println(" ms");

      unsigned long delayTime = timePeriod / 8;

      unsigned long onTime = delayTime * 2; 

      Serial.println("Starting sine wave effect...");

      int funcGenValue = analogRead(funcGenPin);
      
      int pwmValue = map(funcGenValue, 0, 1023, 0, 255);

      analogWrite(LRA1, pwmValue); // 0 rad
      delay(onTime); 
      analogWrite(LRA1, 0);
      delay(onTime - delayTime); 

      analogWrite(LRA2, pwmValue); // π/2 rad
      delay(onTime);
      analogWrite(LRA2, 0);
      delay(onTime - delayTime);

      analogWrite(LRA3, pwmValue); // π rad
      delay(onTime);
      analogWrite(LRA3, 0);
      delay(onTime - delayTime);

      analogWrite(LRA4, pwmValue); // 3π/2 rad
      delay(onTime);
      analogWrite(LRA4, 0);
      delay(onTime - delayTime);

      analogWrite(LRA5, pwmValue); // 2π rad
      delay(onTime);
      analogWrite(LRA5, 0);
      delay(onTime - delayTime);

      Serial.println("Sine wave effect completed. Press Enter to start again.");

      delay(2000);

      Serial.println("Enter the time period for the sine wave (in ms):");
    } else {
      Serial.println("Invalid time period. Please enter a positive integer.");
    }
  }
}
