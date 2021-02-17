
int a,b,c,d,e,f;
char x;

int led=13;
int LS2=A0;                          //far left sensor
int LS1=A1;                          //near left sensor
int RS1=A2;                          // near right sensor
int RS2=A4;                          // far right sensor


//MOTORS
int LM1=3;                        //+
int LM2=4;                        //-
int MS;  
int enA=10;        
int enB=11;
int RM1=5;                        // +
int RM2=6;                       //-




void setup()
{
pinMode(led,OUTPUT);
pinMode(LS1,INPUT);
pinMode(LS2,INPUT);
pinMode(RS1,INPUT);
pinMode(RS2,INPUT);

pinMode(LM1,OUTPUT);
pinMode(LM2,OUTPUT);
pinMode(enA,OUTPUT);
pinMode(RM1,OUTPUT);
pinMode(RM2,OUTPUT);
Serial.begin(9600);
}

void loop() 
{ 
  a = digitalRead(LS2);
  b = digitalRead(LS1);
  c = digitalRead(RS1);
  d = digitalRead(RS2);
  
if(a==1 && b==1 && c==1 && d==1)
{
  while(1)
  {
    if(Serial.available())
    {
    x = Serial.read();
    Serial.println(x);
  
if(x == '0'){ MS=0;}

if(x == '1'){ MS=30;}

if(x == '2'){ MS=60;}

if(x == '3'){ MS=90;}

if(x == '4'){ MS=120;}

if(x == '5'){ MS=150;}

if(x == '6'){ MS=180;}

if(x == '7'){ MS=210;}

if(x == '8'){ MS=240;}

if(x == '9'){ MS=255;}
  
if(x=='0'){e=0; f=0;}
if (x == '1' || x == '2' || x == '3')           {e=100; f=0;}
if(x=='4' || x == '5' || x == '6' || x == '7')  {e=200; f=0;}          
if(x=='8' || x == '9')                          {e=255; f=0;}


    
if(x == 'F'){
  analogWrite(enA,MS);
  analogWrite(enB,MS);
  forward();}            

else if(x == 'B'){
  analogWrite(enA,MS);
  analogWrite(enB,MS);
  backward();}                              
 
else if(x == 'L'){
  analogWrite(enA,MS);
  analogWrite(enB,MS);
  sleft();}     
 
 else if(x == 'R'){ 
  analogWrite(enA,MS);
  analogWrite(enB,MS);
  sright();}  

else if(x == 'I'){
  analogWrite(enA,e);
  analogWrite(enB,f);
  right();}

else if(x== 'G'){ 
  analogWrite(enA,e);
  analogWrite(enB,f);
  left();}

else if(x == 'H'){
  analogWrite(enA,e);
  analogWrite(enB,f);
  bleft();}

 else if(x == 'J'){
  analogWrite(enA,e);
  analogWrite(enB,f);
  bright();}
 
else if(x == 'S'){stopcar();}}}}


else
{ 
if ((a == 0)&&(b == 0)&&(c == 0)&&(d == 0))     
{
   analogWrite(enA,50);     
   analogWrite(enB,50);
   forward();}



if ((a== 1)&&(b == 1)&&(c == 0)&&(d == 0) || 
(a == 1)&&(b == 1)&&(c == 1)&&(d == 0) ||
(a == 1)&&(b == 0)&&(c == 0)&&(d == 0))           
{  analogWrite(enA,200);     
   analogWrite(enB,200);
  sleft();}


 if ((a == 0)&&(b == 1)&&(c == 0)&&(d == 0))
 {  analogWrite(enA,170);     
   analogWrite(enB,170);
  sleft();}




if ((a == 0)&&(b == 0)&&(c == 1)&&(d == 1) || 
(a == 0)&&(b == 1)&&(c == 1)&&(d == 1)||
(a == 0)&&(b == 0)&&(c == 0)&&(d == 1))             
{  analogWrite(enA,200);     
   analogWrite(enB,200);
   sright();}


 if ((a == 0)&&(b == 0)&&(c == 1)&&(d == 0))
 {  analogWrite(enA,170);     
   analogWrite(enB,170);
  sright();}


if ((a == 1)&&(b == 1)&&(c == 1)&&(d == 1))    
{
stopcar();
digitalWrite(led,HIGH);
}}}




void forward(){
  digitalWrite(LM1,LOW);
  digitalWrite(LM2,HIGH);
  digitalWrite(RM1,HIGH);
  digitalWrite(RM2,LOW);
}

void backward() {
  digitalWrite(LM1,HIGH);
  digitalWrite(LM2,LOW);
  digitalWrite(RM1,LOW);
  digitalWrite(RM2,HIGH);
}

void sright(){
  digitalWrite(LM1,LOW);
  digitalWrite(LM2,HIGH);
  digitalWrite(RM1,LOW);
  digitalWrite(RM2,HIGH);
}

void sleft(){    
  digitalWrite(LM1,HIGH);
  digitalWrite(LM2,LOW);
  digitalWrite(RM1,HIGH);
  digitalWrite(RM2,LOW);
}
        
void left(){   
  analogWrite(enB,255);
  digitalWrite(LM1,LOW);
  digitalWrite(LM2,LOW);
  digitalWrite(RM1,HIGH);
  digitalWrite(RM2,LOW);
}

void right(){   
  analogWrite(enA,255);
  digitalWrite(LM1,LOW);
  digitalWrite(LM2,HIGH);
  digitalWrite(RM1,LOW);
  digitalWrite(RM2,LOW);
}
 
void stopcar()  {
  digitalWrite(LM1,LOW);
  digitalWrite(LM2,LOW);
  digitalWrite(RM1,LOW);
  digitalWrite(RM2,LOW);
}

void bleft(){    
  analogWrite(enA,MS);     
  analogWrite(enB,MS);
  digitalWrite(LM1,HIGH);
  digitalWrite(LM2,LOW);
  digitalWrite(RM1,LOW);
  digitalWrite(RM2,HIGH);
}

 void bright(){  
  analogWrite(enA,MS);     
  analogWrite(enB,MS);
  digitalWrite(LM1,HIGH);
  digitalWrite(LM2,LOW);
  digitalWrite(RM1,LOW);
  digitalWrite(RM2,HIGH);
}

    
  
        
