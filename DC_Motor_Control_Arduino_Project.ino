int pot1 = A0;
int pot2 = A1;
int switch1 = 5;
int switch2 = 6;
int motor1 = 10;
int motor2 = 11;
char x;

void setup() {
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  pinMode(pot1, INPUT);
  pinMode(pot2, INPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    x = Serial.read();
    if (x == 'R' || digitalRead(switch2) == HIGH) {
      analogWrite(motor2, analogRead(pot1));
    }else if(x == 'L' || digitalRead(switch1) == HIGH){
      analogWrite(motor1, analogRead(pot2));
    }else if(x=='S'){
      digitalWrite(motor1, LOW);
      digitalWrite(motor2, LOW);
    }
  }
}
