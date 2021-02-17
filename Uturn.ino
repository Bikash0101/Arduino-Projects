int trig1 = 3;
int echo1 = 2;
int Rled1 = 4;            
int Gled1 = 5;

int trig2 = 6;
int echo2 = 7;
int Rled2 = 8;
int Gled2 = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(Rled1, OUTPUT);
  pinMode(Gled1, OUTPUT);

  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(Rled2, OUTPUT);
  pinMode(Gled2, OUTPUT);

}

void loop() {


  int duration1, distance1, duration2, distance2;

  digitalWrite(trig1, HIGH);
  digitalWrite(trig2, HIGH);
  delay(1);
  digitalWrite(trig1, LOW);
  digitalWrite(trig2, LOW);
  // Measure the pulse input in echo pin
  duration1 = pulseIn(echo1, HIGH);
  duration2 = pulseIn(echo2, HIGH);
  // Distance is half the duration devided by 29.1 (from datasheet)
  distance1 = (duration1 / 2) / 29.1;
  distance2 = (duration2 / 2) / 29.1;
  Serial.println(distance1, distance2); 


  if (distance1 > 0 && distance1 <= 6 )
  {
    digitalWrite(Gled1, LOW);
    digitalWrite(Rled1, HIGH);
    delay(1500);

  }
  else {
    digitalWrite(Rled1, LOW);
    digitalWrite(Gled1, HIGH);

  }


  if (distance2 <= 5 && distance2 > 0)
  {
    digitalWrite(Gled2, LOW);
    digitalWrite(Rled2, HIGH);
    delay(1500);

  }
  else {
    digitalWrite(Rled2, LOW);
    digitalWrite(Gled2, HIGH);
  }
  if ((distance1 > 0 && distance1 <= 6 ) && (distance2 <= 6 && distance2 > 0))
  {
    digitalWrite(Rled1, HIGH);
    digitalWrite(Rled2, HIGH);
    delay(1000);
    digitalWrite(Rled1, LOW);
    digitalWrite(Rled2, LOW);
  }
}
