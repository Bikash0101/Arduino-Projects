char s;                 
int a, b, c, d, e, f, g, h;
int MS;

int LM1 = 3;                      // +
int LM2 = 4;                      //-
int enA = 10;       
int enB = 11; 
int RM1 = 5;                      // +
int RM2 = 6;                     // -



void setup() {

  Serial.begin(9600);

  pinMode(led, OUTPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(enB, OUTPUT);
}



void loop() {
  
  if (Serial.available()) {
    s = Serial.read();
    Serial.println(s);
    
      if (s == '0') { MS = 0; }

      if (s == '1') { MS = 30; }

      if (s == '2') { MS = 60; }
      
      if (s == '3') { MS = 75; }
      
      if (s == '4') { MS = 90; }
      
      if (s == '5') { MS = 110; }
      
      if (s == '6') { MS = 140; }
      
      if (s == '7') { MS = 160; }
      
      if (s == '8') { MS = 200; }
      
      if (s == '9') { MS = 255; }

    if (s == '0' || s == '1' || s == '2' || s == '3') {
      a = 150;
      b = 0;
    }
    if (s == '4' || s == '5' || s == '6' || s == '7') {
      a = 200;
      b = 0;
    }
    if (s == '8' || s == '9'  ) {
      a = 255;
      b = 0;
    }


    if (s == 'F') {
      analogWrite(enA, MS);
      analogWrite(enB, MS);
      forward();
    }

    else if (s == 'B') {
      analogWrite(enA, MS);
      analogWrite(enB, MS);
      backward();
    }

    else if (s == 'L') {
      analogWrite(enA, MS);
      analogWrite(enB, MS);
      leftspin();
    }

    else if (s == 'R') {
      analogWrite(enA, MS);
      analogWrite(enB, MS);
      rightspin();
    }

    else if (s == 'I') {
      analogWrite(enA, a);
      analogWrite(enB, b);
      fright();
    }

    else if (s == 'G') {
      analogWrite(enA, a);
      analogWrite(enB, b);
      fleft();
    }

    else if (s == 'H') {
      analogWrite(enA, a);
      analogWrite(enB, b);
      bleft();
    }

    else if (s == 'J') {
      analogWrite(enA, a);
      analogWrite(enB, b);
      bright();
    }

    else if (s == 'S') {
      stopcar(); 
    }
  }
}

void forward() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}


void backward() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
}


void fleft() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}



void fright() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}


void bleft() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
}


void bright() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);

}


void leftspin() {
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}


void rightspin() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
}


void stopcar() {
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}
