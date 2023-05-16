 int out2 = 30;
int out1 = 28;
int out3 = 32;
int out4 = 34;
int out5 = 36;
int capteur_r;
int capteur_rm;
int capteur_m;
int capteur_lm;
int capteur_l;
//moteur left
int vitesseA = 8;//Left
int pinA1 = 48;
int pinA2 = 46;
int pinB2 = 42;
int pinB1 = 44;
int vitesseB = 10;//

void setup() {
  Serial.begin(9600);
  pinMode (out1, INPUT);
  pinMode (out2, INPUT);
  pinMode (out3, INPUT);
  pinMode (out4, INPUT);
  pinMode (out5, INPUT);
  pinMode(vitesseA , OUTPUT);
  pinMode(pinA1 , OUTPUT);
  pinMode(pinA2 , OUTPUT);
  pinMode(pinB2 , OUTPUT);
  pinMode(pinB1 , OUTPUT);
  pinMode(vitesseB , OUTPUT);
}

void forward() {
  digitalWrite(pinA1 , LOW);
  digitalWrite(pinA2, HIGH);
  analogWrite(vitesseB , 240); //RIGHT
  digitalWrite(pinB1 , LOW);
  digitalWrite(pinB2 , HIGH);
  analogWrite(vitesseA , 250); //LEFT
}

void stop_f() {
  digitalWrite(pinA1 , LOW);
  digitalWrite(pinA2, HIGH);
  analogWrite(vitesseB ,0); //RIGHT
  digitalWrite(pinB1 , LOW);
  digitalWrite(pinB2 , HIGH);
  analogWrite(vitesseA , 0); //LEFT
}

void left() {
  digitalWrite(pinA1 , LOW);
  digitalWrite(pinA2 , HIGH);
  analogWrite(vitesseB , 160); //R
  digitalWrite(pinB1 , LOW);
  digitalWrite(pinB2 , HIGH);//L
  analogWrite(vitesseA , 250 );
}
void right() {
  digitalWrite(pinA1 , LOW);
  digitalWrite(pinA2 , HIGH);
  analogWrite(vitesseB , 250);//R
  digitalWrite(pinB1 , LOW);
  digitalWrite(pinB2 , HIGH);
  analogWrite(vitesseA , 160);//L
}


void Moveleft() {
  digitalWrite(pinA1 , LOW);
  digitalWrite(pinA2 , HIGH);
  analogWrite(vitesseB , 250);//R
  digitalWrite(pinB1 , LOW);
  digitalWrite(pinB2 , HIGH);//L
  analogWrite(vitesseA , 0);
}

void Moveright() {
  digitalWrite(pinA1 , LOW);
  digitalWrite(pinA2 , HIGH);
  analogWrite(vitesseB , 0);//R
  digitalWrite(pinB1 , LOW);
  digitalWrite(pinB2 , HIGH);//L
  analogWrite(vitesseA , 250);
}

void loop() {
  capteur_lm = digitalRead(out2);
  capteur_l = digitalRead(out1);
  capteur_m = digitalRead(out3);
  capteur_rm = digitalRead(out4);
  capteur_r = digitalRead(out5);
  Serial.print(capteur_l );
  Serial.print("   ");
    Serial.print(capteur_lm );
  Serial.print("   ");
  Serial.print(capteur_m );
  Serial.print("   ");
  Serial.print(capteur_rm );
  Serial.print("   ");
  Serial.println(capteur_r );
  if (capteur_l == 0) {
    Moveleft();
  }
  else if( capteur_lm == 0 ){
    left();
  }
  else if (capteur_r == 0 ) {
    Moveright();
  }
  else if (capteur_rm == 0 ) {
    right();
  }
  else if (capteur_m == 0) {
    forward();
  }
  while (capteur_l == 0 && capteur_lm == 0 && capteur_m == 0) {
    stop_f();                                                                
  }
  while(capteur_r == 0 && capteur_rm == 0 && capteur_m == 0) {
    stop_f();
  }
  while(capteur_r == 0 && capteur_rm == 0 && capteur_m == 0 && capteur_l == 0 && capteur_lm == 0) {
    stop_f();
  }
}
