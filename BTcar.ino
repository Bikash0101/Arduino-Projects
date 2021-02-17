char s;
int a;
int enA=5;
int enB=6;

void setup(){
Serial.begin(9600);
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
pinMode(10,OUTPUT);
pinMode(enA,OUTPUT);
pinMode(enB,OUTPUT);
}

void loop(){
if (Serial.available()){
s=Serial.read();
Serial.println(s);
}
if (s=='0'){
  a=0;
}
else if ((s=='1') || (s=='2') || (s=='3'))
{
  a=80;
}

else if ((s=='4') || (s=='5') || (s=='6'))
{
  a=150;
}

else if ((s=='7') || (s=='8') || (s=='9'))
{
  a=255;
}

if (s=='F'){
  analogWrite(enA,a);
    analogWrite(enB,a);
digitalWrite(13,HIGH);
digitalWrite(12,LOW);
digitalWrite(11,HIGH);
digitalWrite(10,LOW);
}

if (s=='B'){
  analogWrite(enA,a);
    analogWrite(enB,a);
digitalWrite(12,HIGH);
digitalWrite(13,LOW);
digitalWrite(10,HIGH);
digitalWrite(11,LOW);
}

if (s=='L'){
  analogWrite(enA,a);
    analogWrite(enB,a);
digitalWrite(13,HIGH);
digitalWrite(12,LOW);
digitalWrite(11,LOW);
digitalWrite(10,HIGH);
}

if (s=='R'){
  analogWrite(enA,a);
    analogWrite(enB,a);
digitalWrite(13,LOW);
digitalWrite(12,HIGH);
digitalWrite(11,HIGH);
digitalWrite(10,LOW);
}

else
{
digitalWrite(13,LOW);
digitalWrite(12,LOW);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
}
}
