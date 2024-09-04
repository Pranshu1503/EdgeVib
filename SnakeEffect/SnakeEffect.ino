/////////#include <stdio.h>

void setup()

{

pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
pinMode(14, OUTPUT);
pinMode(15, OUTPUT);
pinMode(16, OUTPUT);
pinMode(17, OUTPUT);
pinMode(18, OUTPUT);
pinMode(19, OUTPUT);
pinMode(20, OUTPUT);
pinMode(21, OUTPUT);


Serial.begin(9600);

while (!Serial);

Serial.println("You are good to go.");

}

void loop() {

int state = 2;

while(state <= 21)
{digitalWrite(state, HIGH);
Serial.println("Accuator No. ");
Serial.print(state);
delay(200);
digitalWrite(state, LOW);
state = state + 1;
}

}