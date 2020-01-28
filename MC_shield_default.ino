#define in1 4
#define in2 5
#define in3 6 
#define in4 7
#define enA 9
#define enB 10

void setup() {
  pinMode(in1, OUTPUT); // Motor Channel A
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT); // Motor Channel B
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
}

void loop(){
  runA(255, false);
  runB(50, false);
  delay(3000);
  //fs();
  runA(0, false);
  runB(0, false);
  delay(1000);
}

void runA(int speed, boolean rev){
  if (rev){
    // Backwards
    digitalWrite(in1, LOW); 
  }else {
    digitalWrite(in1, HIGH);
  }
  digitalWrite(in2, LOW);
  analogWrite(enA, speed);
}

void runB(int speed, boolean rev){
  if (rev) {
    digitalWrite(in3, LOW);
  } else{
    digitalWrite(in3, HIGH);
  }

  digitalWrite(in4, LOW);
  analogWrite(enB, speed); //Try flipping 9 and 10? Or setting them as them same?
} //Grand goal in that sense would be to move the wheels in some shape or form

void fs(){
  digitalWrite(in2, HIGH); //4,5,6,7 as direction //5, 6 same
  digitalWrite(in4, HIGH);
  
}
