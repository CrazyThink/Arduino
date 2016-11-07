int seg[][8] = {{1, 1, 1, 1, 1, 1, 0, 0},     //0
                {0, 1, 1, 0, 0, 0, 0, 0},     //1
                {1, 1, 0, 1, 1, 0, 1, 0},     //2
                {1, 1, 1, 1, 0, 0, 1, 0},     //3
                {0, 1, 1, 0, 0, 1, 1, 0},     //4
                {1, 0, 1, 1, 0, 1, 1, 0},     //5
                {1, 0, 1, 1, 1, 1, 1, 0},     //6
                {1, 1, 1, 0, 0, 0, 0, 0},     //7
                {1, 1, 1, 1, 1, 1, 1, 0},     //8
                {1, 1, 1, 1, 0, 1, 1, 0} };   //9
  int seg_pins[] = {2, 3, 4, 5, 6, 7, 8, 9};
  int sel_pins[] = {14, 15, 16, 17, 18, 19};
  int sel = 0;
  int cnt = 0;
  int data;
  
void setup() {
  int i;
  for(int i = 0; i < 8; i++) pinMode(seg_pins[i],OUTPUT);
  for(int i = 0; i < 4; i++) pinMode(sel_pins[i],OUTPUT);
  for(int i = 0; i < 8; i++) digitalWrite(seg_pins[i], LOW);
  for(int i = 0; i < 4; i++) digitalWrite(sel_pins[i], HIGH);
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  if(cnt == 0){
    data = analogRead(A0);
    Serial.println(data);
  }
  int num = (data%(int)pow(10,sel+1))/(int)pow(10,sel);
 
  for(int j = 0; j < 8; j++)
    digitalWrite(seg_pins[j], seg[num][j]);
  digitalWrite(sel_pins[sel], LOW);
  delay(2);
  digitalWrite(sel_pins[sel], HIGH);

  sel = (sel + 1) % 4;
  cnt = (cnt + 1) % 100;
}
