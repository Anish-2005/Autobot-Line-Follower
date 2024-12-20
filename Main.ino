// Arduino Line Follower Robot Code


#define enA 6 //Enable1 L293 Pin enA 

#define in1 13 //Motor1  L293 Pin in1 

#define in2 12 //Motor1  L293 Pin in1 

#define in3 10 //Motor2  L293 Pin in1 

#define in4 11 //Motor2  L293 Pin in1 

#define enB 3 //Enable2 L293 Pin enB 

#define R_S 5//ir sensor Right

#define L_S 4 //ir sensor Left

int speed1 = 65,speed2=65;
void setup(){ 

pinMode(R_S, INPUT); 

pinMode(L_S, INPUT); 

pinMode(enA, OUTPUT); 

pinMode(in1, OUTPUT); 

pinMode(in2, OUTPUT); 

pinMode(in3, OUTPUT); 

pinMode(in4, OUTPUT); 

pinMode(enB, OUTPUT);

digitalWrite(enA, HIGH); 

digitalWrite(enB, HIGH); 

  //The problem with TT gear motors is that, at very low pwm value it does not even rotate.
  //If we increase the PWM value then it rotates faster and our robot is not controlled in that speed and goes out of line.
  //For that we need to increase the frequency of analogWrite.
  //Below line is important to change the frequency of PWM signal on pin D5 and D6
  //Because of this, motor runs in controlled manner (lower speed) at high PWM value.
  //This sets frequecny as 7812.5 hz.

//TCCR0B = TCCR0B & B11111000 | B00000010 ;

//delay(1000);

}

void loop(){  

if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)){forward();}   //if Right Sensor and Left Sensor are at White color then it will call forword function

if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)){turnRight();} //if Right Sensor is Black and Left Sensor is White then it will call turn Right function  

if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)){turnLeft();}  //if Right Sensor is White and Left Sensor is Black then it will call turn Left function

if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 1)){Stop();} //if Right Sensor and Left Sensor are at Black color then it will call Stop function





}

void forward(){  //forword
  analogWrite(enA, speed1); 

  analogWrite(enB, speed2); 

  digitalWrite(in1, HIGH); //Right Motor forword Pin 
  
  digitalWrite(in2, LOW);  //Right Motor backword Pin 
  
  digitalWrite(in3, HIGH);  //Left Motor backword Pin 
  
  digitalWrite(in4, LOW); //Left Motor forword Pin 

}

void turnRight(){ //turnRight
    analogWrite(enA, speed1); 

  analogWrite(enB, speed2);

digitalWrite(in1, LOW);  //Right Motor forword Pin 

digitalWrite(in2, HIGH); //Right Motor backword Pin  

digitalWrite(in3, HIGH);  //Left Motor backword Pin 

 digitalWrite(in4, LOW); //Left Motor forword Pin 

}

void turnLeft(){ //turnLeft
    analogWrite(enA, speed1); 

  analogWrite(enB, speed2);

digitalWrite(in1, HIGH); //Right Motor forword Pin 

digitalWrite(in2, LOW);  //Right Motor backword Pin 

digitalWrite(in3, LOW); //Left Motor backword Pin 

digitalWrite(in4, HIGH);  //Left Motor forword Pin 

}

void Stop(){ //stop

digitalWrite(in1, LOW); //Right Motor forword Pin 

digitalWrite(in2, LOW); //Right Motor backword Pin 

digitalWrite(in3, LOW); //Left Motor backword Pin 

digitalWrite(in4, LOW); //Left Motor forword Pin 

}