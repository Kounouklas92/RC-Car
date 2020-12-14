#include <Servo.h> 
#include <String.h>

Servo esc;
Servo servo;
int escval;
int serial[8];
int servoval;



void setup() 
{  
      
  Serial.begin(9600);
 int k=0;
  esc.attach(9);
    servo.attach(10);
  while(k<3){
  esc.writeMicroseconds(1470);  // set esc to mid-point(0 speed)
   delay(30);
    esc.writeMicroseconds(1550);  // set esc to mid-point(0 speed)
   delay(30);
   k++;}
 


} 


int k=0;




void loop() {
if (Serial.available()==7)
 {
 for(int n=0; n<7; n++){
  serial[n] = Serial.read(); 
 }
    
escval  =  ((serial[0]-'0')*1000)+((serial[1]-'0')*100)+((serial[2]-'0')*10)+((serial[3]-'0'));
servoval=((serial[4]-'0')*10)+((serial[5]-'0'));
servoval = map(servoval, 0, 90, 50, 110); //gia to servo vazoume 0 ews 90 me 45 to kentro
   
  if (escval>1500){
    k=0;}
   if(escval<1500&&k==0){
     delay(20);
     esc.writeMicroseconds(escval);  
   delay(150);                      
    esc.writeMicroseconds(1600);
   delay(150);
   k=1;
    }
   esc.writeMicroseconds(escval);  
   delay(20);
   esc.writeMicroseconds(escval);  
   delay(20);
   servo.write(servoval);              
    delay(15); 
     Serial.print("esc:");
   Serial.println(escval);
    Serial.print("servoangle:");
   Serial.println(servoval);
 } 
   delay(10);
  } 
