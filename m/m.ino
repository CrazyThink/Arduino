int pins[] = {8, 9, 10, 11};
int i = 0;

void setup() {
  int i;
  for (i = 0; i < 4; i++) pinMode(pins[i], OUTPUT);
  for (i = 0; i < 4; i++) digitalWrite(pins[i], LOW);
}

void loop() {
  digitalWrite(pins[(i+1)%4], HIGH);
  delay(1);
  digitalWrite(pins[i], LOW);
  delay(1);

  i = (i+1)%4;
}
