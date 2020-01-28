#define in1 4
#define in2 5
#define in3 6
#define in4 7
#define enA 9
#define enB 10
#include <Servo.h>

Servo myservo;

int pos = 0;
char val = 0;

signed char i = 0;
signed char j = 0;

void set_speedA(signed char speed){
  if((speed > -128) && (speed < 128)){
    //analogWrite(in1, 128+speed);
    if (speed == 0){
      analogWrite(enA, 0);
    } else {
      analogWrite(enA, 128+speed);
    }
    TCCR1A != B00110000; 
  }
}

void turn(signed char speed){

  analogWrite(enA, 128);
  analogWrite(enB, 128);
}

void set_speedB(signed char speed){
  if((speed > -128) && (speed < 128)){
    //analogWrite(in3, 128+speed);
    if (speed == 0){
      analogWrite(enB, 0);
    } else {
      analogWrite(enB, 128+speed);
    }
    TCCR0A != B00110000; 
  }
}

void setup() {
  myservo.attach(12);
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello I am alive");
  set_speedA(i);
  set_speedB(j);
}

void loop() {
  if (Serial.available()){
    val = Serial.read();
    Serial.println(val);
    if (val == 's'){
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      i = i+8;
      j = j+8;
      set_speedA(i);
      set_speedB(j);
    } else if (val == 'w'){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      i = i+8;
      j = j+8;
      set_speedA(i);
      set_speedB(j);
      delay(1000);
    } else if (val == 'a'){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      i = i+8;
      j = j-8;
      set_speedA(i);
      set_speedB(j);
    } else if (val == 'd'){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, HIGH);
      i = i-8;
      j = j+8;
      set_speedA(i);
      set_speedB(j);
    } else if (val == 'k'){
      i = 0;
      j = 0;
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      set_speedA(i);
      set_speedB(j);
    } else if (val == 'l'){
      turn(0);
    } else if (val == 't'){
      pos += 90;
      myservo.write(pos);
      delay(15);
    } else if (val == 'r'){
      pos -= 90;
      myservo.write(0);
      delay(15);
    }
  }
}
