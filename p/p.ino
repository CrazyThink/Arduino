#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int row_pin[] = {22, 23, 24, 25, 26, 27, 28, 29};
int col_pin[] = {32, 33, 34, 35, 36, 37, 38, 39};
int seg_pins[] = {46, 47, 48, 49};
int sel_pins[] = {40, 41, 42, 43, 44, 45};

int led[][8] = {{1, 0, 0, 0, 1, 1, 1, 1},
                {1, 0, 0, 0, 1, 1, 1, 1},
                {1, 1, 0, 1, 0, 1, 1, 1},
                {0, 0, 0, 0, 0, 1, 1, 1},
                {0, 1, 0, 1, 1, 1, 1, 1},
                {1, 0, 1, 0, 1, 1, 0, 0},
                {1, 0, 1, 0, 1, 1, 0, 0},
                {1, 0, 1, 0, 0, 1, 1, 1}};

int led2[][8] ={{1, 0, 0, 0, 1, 1, 1, 1},
                {1, 0, 0, 0, 1, 1, 1, 1},
                {1, 1, 0, 1, 1, 1, 1, 1},
                {0, 0, 0, 0, 0, 0, 1, 1},
                {1, 1, 0, 1, 1, 1, 1, 1},
                {1, 0, 1, 0, 1, 0, 1, 1},
                {1, 0, 1, 1, 0, 1, 1, 1},
                {1, 0, 1, 1, 1, 1, 1, 1}};
int i = 0;
int a = 0;
int pos = 0;
int cnt = 0;
bool ball = false;

void setup() {
  int i;
  for(i = 0; i < 8; i++) pinMode(row_pin[i], OUTPUT);
  for(i = 0; i < 8; i++) pinMode(col_pin[i], OUTPUT);
  for(i = 0; i < 8; i++) digitalWrite(row_pin[i], LOW);
  for(i = 0; i < 8; i++) digitalWrite(col_pin[i], HIGH);
  for(i = 0; i < 4; i++) pinMode(seg_pins[i], OUTPUT);
  for(i = 0; i < 6; i++) pinMode(sel_pins[i], OUTPUT);
  for(i = 0; i < 4; i++) digitalWrite(seg_pins[i], HIGH);
  for(i = 0; i < 6; i++) digitalWrite(sel_pins[i], HIGH);
  lcd.begin(16, 2);
  pinMode(10, OUTPUT);
  lcd.setCursor(5, 0);
  lcd.print("GOAL!!");
}

void loop() {
  if(ball == false)
    nokick();
  else{
    kick();
    roll();
    if(cnt%100 == 0){
      i = (i + 1) % 6;
      if(i == 0) goal(), ball = false;
      else if(i == 1) reset();
    }
  }

  a = (a + 1) % 8;
  cnt = (cnt + 1) % 1000;
  if(cnt == 0) ball = true;
}

void nokick(){
  digitalWrite(row_pin[a], HIGH);
  for(int j = 0; j < 8; j++)
    digitalWrite(col_pin[j], led[a][j]);
  delay(1);
  digitalWrite(row_pin[a], LOW);
}

void kick(){
  digitalWrite(row_pin[a], HIGH);
  for(int j = 0; j < 8; j++)
    digitalWrite(col_pin[j], led2[a][j]);
   delay(1);
  digitalWrite(row_pin[a], LOW);
}

void roll(){
  digitalWrite(sel_pins[5-i], LOW);
  delay(1);
  digitalWrite(sel_pins[5-i], HIGH);
}

void goal(){
  digitalWrite(10, HIGH);
}

void reset(){
  digitalWrite(10, LOW);
}

