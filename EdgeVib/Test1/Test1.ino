#include <Arduino.h>

const int actuatorPins[4] = {2, 3, 4, 5};

const int patternA[] = {2, 500, 1, 500, 3, 500, -1, 0}; // Motor 3 -> Motor 2 -> Motor 4
const int patternB[] = {0, 500, 2, 500, 3, 500, 2, 500, -1, 0}; // Motor 1 -> Motor 3 -> Motor 4 -> Motor 3
const int patternC[] = {1, 500, 2, 500, 3, 500, -1, 0}; // Motor 2 -> Motor 3 -> Motor 4
const int patternD[] = {1, 500, 3, 500, 2, 500, 3, 500, -1, 0}; // Motor 2 -> Motor 4 -> Motor 3 -> Motor 4
const int patternE[] = {1, 500, 0, 500, 2, 500, 3, 500, -1, 0}; // Motor 2 -> Motor 1 -> Motor 3 -> Motor 4
const int patternF[] = {1, 500, 0, 500, 2, 500, -1, 0}; // Motor 2 -> Motor 1 -> Motor 3 
const int patternG[] = {1, 500, 0, 500, 2, 500, 3, 500, 2, 500, -1, 0}; // Motor 2 -> Motor 1 -> Motor 3 -> Motor 4 -> Motor 3
const int patternH[] = {0, 500, 2, 500, 1, 500, 3, 500, -1, 0}; // Motor 1 -> Motor 3 -> Motor 2 -> Motor 4
const int patternI[] = {0, 500, 2, 500, -1, 0}; // Motor 1 -> Motor 3
const int patternJ[] = {1, 500, 3, 500, 2, 500, -1, 0}; // Motor 2 -> Motor 4 -> Motor 3
const int patternK[] = {0, 500, 2, 500, 1, 500, 2, 500, 3, 500, -1, 0}; // Motor 1 -> Motor 3 -> Motor 2 -> Motor 3 -> Motor 4
const int patternL[] = {0, 500, 2, 500, 3, 500, -1, 0}; // Motor 1 -> Motor 3 -> Motor 4
const int patternM[] = {2, 500, 0, 500, 3, 500, 1, 500, 3, 500, -1, 0}; // Motor 3 -> Motor 1 -> Motor 4 -> Motor 2 -> Motor 4
const int patternN[] = {2, 500, 0, 500, 3, 500, 1, 500, -1, 0}; // Motor 3 -> Motor 1 -> Motor 4 -> Motor 2
const int patternO[] = {1, 500, 0, 500, 2, 500, 3, 500, 1, 500, -1, 0}; // Motor 2 -> Motor 1 -> Motor 3 -> Motor 4 -> Motor 2
const int patternP[] = {2, 500, 0, 500, 1, 500, 2, 500, -1, 0}; // Motor 3 -> Motor 1 -> Motor 2 -> Motor 3
const int patternQ[] = {1, 500, 0, 500, 2, 500, 3, 500, 1, 500, 3, 500, -1, 0}; // Motor 2 -> Motor 1 -> Motor 3 -> Motor 4 -> Motor 2 -> Motor 4
const int patternR[] = {2, 500, 0, 500, 1, 500, -1, 0}; // Motor 3 -> Motor 1 -> Motor 2
const int patternS[] = {1, 500, 0, 500, 3, 500, 2, 500, -1, 0}; // Motor 2 -> Motor 1 -> Motor 4 -> Motor 3
const int patternT[] = {0, 500, 1, 500, 3, 500, -1, 0}; // Motor 1 -> Motor 2 -> Motor 4
const int patternU[] = {0, 500, 2, 500, 3, 500, 1, 500, -1, 0}; // Motor 1 -> Motor 3 -> Motor 4 -> Motor 2
const int patternV[] = {0, 500, 2, 500, 1, 500, -1, 0}; // Motor 1 -> Motor 3 -> Motor 2
const int patternW[] = {0, 500, 2, 500, 1, 500, 3, 500, 1, 500, -1, 0}; // Motor 1 -> Motor 3 -> Motor 2 -> Motor 4 -> Motor 2
const int patternX[] = {0, 500, 3, 500, 1, 500, 2, 500, -1, 0}; // Motor 1 -> Motor 4 -> Motor 2 -> Motor 3
const int patternY[] = {0, 500, 3, 500, 1, 500, 3, 500, -1, 0}; // Motor 1 -> Motor 4 -> Motor 2 -> Motor 4
const int patternZ[] = {0, 500, 1, 500, 2, 500, 3, 500, -1, 0}; // Motor 1 -> Motor 2 -> Motor 3 -> Motor 4
const int pattern0[] = {1, 500, 0, 500, 2, 500, 3, 500, 1, 500, 2, 500, -1, 0};  // Motor 2 -> Motor 1 -> Motor 3 -> Motor 4 -> Motor 2 -> Motor 3
const int pattern1[] = {1, 500, 3, 500, -1, 0};  // Motor 2 -> Motor 4
const int pattern2[] = {2, 500, 1, 500, 2, 500, 3, 500, -1, 0};  // Motor 3 -> Motor 2 -> Motor 3 -> Motor 4
const int pattern3[] = {0, 500, 1, 500, 3, 500, 2, 500, -1, 0};  // Motor 1 -> Motor 2 -> Motor 4 -> Motor 3
const int pattern4[] = {1, 500, 2, 500, 3, 500, 1, 500, 3, 500, -1, 0};  // Motor 2 -> Motor 3 -> Motor 4 -> Motor 2 -> Motor 4
const int pattern5[] = {1, 500, 0, 500, 1, 500, 3, 500, 2, 500, -1, 0};  // Motor 2 -> Motor 1 -> Motor 2 -> Motor 4 -> Motor 3
const int pattern6[] = {1, 500, 2, 500, 3, 500, 2, 500, -1, 0};  // Motor 2 -> Motor 3 -> Motor 4 -> Motor 3
const int pattern7[] = {0, 500, 1, 500, 2, 500, -1, 0};  // Motor 1 -> Motor 2 -> Motor 3
const int pattern8[] = {0, 500, 1, 500, 3, 500, 2, 500, -1, 0};  // Motor 1 -> Motor 2 -> Motor 4 -> Motor 3
const int pattern9[] = {1, 500, 0, 500, 3, 500, 2, 500, 1, 500, -1, 0};  // Motor 2 -> Motor 1 -> Motor 4 -> Motor 3 -> Motor 2

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(actuatorPins[i], OUTPUT);
    digitalWrite(actuatorPins[i], LOW);
  }

  Serial.begin(9600);
  while (!Serial);

  Serial.println("You are good to go.");
  Serial.println("Enter a letter to display its pattern (A to z) or number from (0 to 9):");
}

void clearActuators() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(actuatorPins[i], LOW);
  }
}

void executePattern(const int pattern[]) {
  int i = 0;
  while (pattern[i] != -1) {
    int pinIndex = pattern[i];
    int duration = pattern[i + 1];
    digitalWrite(actuatorPins[pinIndex], HIGH);
    delay(duration);
    digitalWrite(actuatorPins[pinIndex], LOW);
    i += 2;
  }
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    if (input.length() > 0) {
      char letter = toupper(input.charAt(0));
      Serial.print("Displaying pattern for: ");
      Serial.println(letter);

      switch (letter) {
        case 'A':
          executePattern(patternA);
          break;
        case 'B':
          executePattern(patternB);
          break;
        case 'C':
          executePattern(patternC);
          break;
        case 'D':
          executePattern(patternD);
          break;
        case 'E':
          executePattern(patternE);
          break;
        case 'F':
          executePattern(patternF);
          break;
        case 'G':
          executePattern(patternG);
          break;
        case 'H':
          executePattern(patternH);
          break;
        case 'I':
          executePattern(patternI);
          break;
        case 'J':
          executePattern(patternJ);
          break;
        case 'K':
          executePattern(patternK);
          break;
        case 'L':
          executePattern(patternL);
          break;
        case 'M':
          executePattern(patternM);
          break;
        case 'N':
          executePattern(patternN);
          break;
        case 'O':
          executePattern(patternO);
          break;
        case 'P':
          executePattern(patternP);
          break;
        case 'Q':
          executePattern(patternQ);
          break;
        case 'R':
          executePattern(patternR);
          break;
        case 'S':
          executePattern(patternS);
          break;
        case 'T':
          executePattern(patternT);
          break;
        case 'U':
          executePattern(patternU);
          break;
        case 'V':
          executePattern(patternV);
          break;
        case 'W':
          executePattern(patternW);
          break;
        case 'X':
          executePattern(patternX);
          break;
        case 'Y':
          executePattern(patternY);
          break;
        case 'Z':
          executePattern(patternZ);
          break;
        case '0':
          executePattern(pattern0);
          break;
        case '1':
          executePattern(pattern1);
          break;
        case '2':
          executePattern(pattern2);
          break;
        case '3':
          executePattern(pattern3);
          break;
        case '4':
          executePattern(pattern4);
          break;
        case '5':
          executePattern(pattern5);
          break;
        case '6':
          executePattern(pattern6);
          break;
        case '7':
          executePattern(pattern7);
          break;
        case '8':
          executePattern(pattern8);
          break;
        case '9':
          executePattern(pattern9);
          break;
        default:
          Serial.println("Invalid input.");
          break;
      }
      clearActuators();
    }
  }
}
