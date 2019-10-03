#include <Arduino.h>

#define B 2
#define A 4

volatile int count;

void handleEncoder()
{
  if (digitalRead(B) == digitalRead(A))
    count++;
  else
    count--;
}

void setup() {
  Serial.begin(115200);
  count = 0;
  pinMode(B, INPUT);
  pinMode(A, INPUT);

  attachInterrupt(0, handleEncoder, CHANGE);
}

void loop() {
  Serial.println(count);
  delay(100);
}