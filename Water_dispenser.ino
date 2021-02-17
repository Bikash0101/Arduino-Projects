char t;
int trig=12;
int echo=13;
int duration,distance;

#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {

  Serial.begin(9600);
    myservo.attach(2);        //signal pin for servo motor
    pinMode(trig, OUTPUT);
      pinMode(echo, INPUT);
}


void loop() {
  
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
delayMicroseconds(2);
duration = pulseIn(echo, HIGH);
distance = (duration/2) / 29.1;          //from formula and calculation...distance in cm..
  t=Serial.read();
  Serial.println(distance);

if (distance>0 && distance<4){

    myservo.write(180);          
}
else {
    myservo.write(0); 
}


}
