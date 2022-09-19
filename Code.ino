#define S_A  10  //speed motor a
#define M_A1  9 //motor a = + phai
#define M_A2  8//motor a = -
#define M_B1  7 //motor b = -
#define M_B2  6 //motor b = + trai
#define S_B  11  //speed motor b

#define R_S 2 //sincer R
#define S_S 4 //sincer S 
#define L_S 3 //sincer L

int R ;
int M ;
int L;

int check = 0;

void IR() {
  R = digitalRead(R_S);
  L = digitalRead(L_S);
}

void setup()
{
  pinMode(M_A1, OUTPUT);
  pinMode(M_A2, OUTPUT);
  pinMode(M_B1, OUTPUT);
  pinMode(M_B2, OUTPUT);
  pinMode(S_A, OUTPUT);
  pinMode(S_B, OUTPUT);
  
  pinMode(L_S, INPUT);
  pinMode(S_S, INPUT);
  pinMode(R_S, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), IR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), IR, CHANGE);
  analogWrite(S_A, 100);
  analogWrite(S_B, 98);

  delay(2500);
}
void loop()
{
  run();
}

void run()
{
  if ((L == 0) && (digitalRead(S_S) == 1) && (R == 0)) {
    check = 3;
    forword();
  }
  if ((L == 1) && (digitalRead(S_S) == 1) && (R == 0)) {
    check = 1;
    turnLeft();
  }
  if ((L == 1) && (digitalRead(S_S) == 0) && (R == 0)) {
    check = 1;
    turnLeft();
  }
  if ((L == 0) && (digitalRead(S_S) == 1) && (R == 1)) {
    check = 2;
    turnRight();
  }
  if ((L == 0) && (digitalRead(S_S) == 0) && (R == 1)) {
    check = 2;
    turnRight();
  }
  if ((L == 1) && (digitalRead(S_S) == 1) && (R == 1)) {
    forword();
  }
  if ((L == 0) && (digitalRead(S_S) == 0) && (R == 0)) {
    if(check == 1){//xoay vong trai
      vongTrai();
      check = 0;
    }
    else if(check == 2){//xoay vong phai
      vongPhai();
      check = 0;
    }
    else if(check == 3){//di thang tiep tuc
      forword();
      check = 0;
    }
  }

}

void forword() {
  digitalWrite(M_A1, HIGH);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW);
}

void lui() {
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, HIGH);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, HIGH);
}


void vongPhai() {
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, HIGH);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW);
}

void turnRight() {
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW);
}

void vongTrai() {
  digitalWrite(M_A1, HIGH);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, HIGH);
}

void turnLeft() {
  digitalWrite(M_A1, HIGH);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, LOW);
}

void Stop() {
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, LOW);
}
