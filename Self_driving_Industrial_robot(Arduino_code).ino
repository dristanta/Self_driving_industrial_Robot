#include <Servo.h>
Servo myservo;
Servo myservo1;
Servo myservo2;//pins for servo

#define m11 2    // rear motor
#define m12 3
#define m21 4   // front motor
#define m22 5
#define sensor1 6
#define sensor2 7
#define sensor3 8
#define sensor4 9
int a = 0;
int pos = 0; //for servo
void setup() 
{
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
  myservo.attach(10);
  myservo1.attach(11);
  myservo2.attach(12);
}

void loop() {
 if (a==0)
 { 
 if(digitalRead(sensor1)==HIGH &&digitalRead(sensor2)== HIGH)
 forward();
 else if(digitalRead(sensor1)==HIGH && digitalRead(sensor2) == LOW)
 left();
 else if(digitalRead(sensor1)==LOW && digitalRead(sensor2) == HIGH)
 right();
 else if(digitalRead(sensor1)==LOW && digitalRead(sensor2) == LOW)
    {a=1;
    Stop();
   //open
  for (pos = 0; pos <= 90; pos += 1) { // pos = 0; pos <= 180; pos += 1 goes from 0 degrees to 180 degrees
  myservo2.write(pos);              // tell servo to go to position in variable 'pos'
  delay(100);                       // waits 15ms for the servo to reach the position
  }
  //DOWN  
  for (pos = 180; pos >= 90; pos -= 1) { // goes from 0 degrees to 180 degrees
  myservo1.write(pos);              // tell servo to go to position in variable 'pos'
  delay(50);                       // waits 15ms for the servo to reach the position
  }
  //close
  for (pos = 90; pos >= 0; pos -= 1) { // pos = 0; pos <= 180; pos += 1 goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15); }
 //UP 
 delay(1000);
 for (pos = 90; pos <= 180; pos += 1) { // pos = 0; pos <= 180; pos += 1 goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position
  } 
 //ROTATE 
 for (pos = 80; pos >= 0; pos -= 1) { // pos = 0; pos <= 180; pos += 1 goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 15ms for the servo to reach the position
  }
  //DOWN  
delay(1000);
  for (pos = 180; pos >= 90; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position
  }
    //open
  for (pos = 0; pos <= 90; pos += 1) { // pos = 0; pos <= 180; pos += 1 goes from 0 degrees to 180 degrees
  // in steps of 1 degree
  myservo2.write(pos);              // tell servo to go to position in variable 'pos'
  delay(100);                       // waits 15ms for the servo to reach the position
  }
 //UP 
 delay(1000);
 for (pos = 90; pos <= 180; pos += 1) { // pos = 0; pos <= 180; pos += 1 goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position
  }
//lower most servo go to the above cart position ROTATE
 for (pos = 0; pos <=80; pos += 1) { // pos = 0; pos <= 180; pos += 1 goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 15ms for the servo to reach the position
  } 
}
 else if(digitalRead(sensor1)==LOW && digitalRead(sensor2) == LOW && digitalRead(sensor3)==HIGH && digitalRead(sensor4) == HIGH)
 Stop();
 }
 else
 { 
 if(digitalRead(sensor3)==LOW &&digitalRead(sensor4) == LOW)
 forward1();
 else if(digitalRead(sensor3)==LOW && digitalRead(sensor4) == HIGH)
 left1();
 else if(digitalRead(sensor3)==HIGH && digitalRead(sensor4) == LOW)
 right1();
 else if(digitalRead(sensor3)==HIGH && digitalRead(sensor4) == HIGH)
   {Stop();
    a=0;
    //ROTATE 
 for (pos = 80; pos >= 0; pos -= 1) { // pos = 0; pos <= 180; pos += 1 goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 15ms for the servo to reach the position
  }
  //DOWN  
delay(1000);
  for (pos = 180; pos >= 90; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position
  }
   //close
   for (pos = 90; pos >= 0; pos -= 1) { // pos = 0; pos <= 180; pos += 1 goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15); }
 //UP 
 delay(1000);
 for (pos = 90; pos <= 180; pos += 1) { // pos = 0; pos <= 180; pos += 1 goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position
  }                      // waits 15ms for the servo to reach the position
//lower most servo go to the above cart position ROTATE
 for (pos = 0; pos <=80; pos += 1) { // pos = 0; pos <= 180; pos += 1 goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(100);                       // waits 15ms for the servo to reach the position
  } 
  //DOWN  
  for (pos = 180; pos >= 90; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position
  }
  //open
  for (pos = 0; pos <= 90; pos += 1) { // pos = 0; pos <= 180; pos += 1 goes from 0 degrees to 180 degrees
  // in steps of 1 degree
  myservo2.write(pos);              // tell servo to go to position in variable 'pos'
  delay(100);                       // waits 15ms for the servo to reach the position
  }
 //UP 
 delay(1000);
 for (pos = 90; pos <= 180; pos += 1) { // pos = 0; pos <= 180; pos += 1 goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position
  }   
   }
 else if(digitalRead(sensor1)==LOW && digitalRead(sensor2) == LOW && digitalRead(sensor3)==HIGH && digitalRead(sensor4) == HIGH)
 Stop();
 }
}
void right()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, HIGH);
   digitalWrite(m21, LOW);
   digitalWrite(m22, LOW);
   delay(100);
}
void left()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);
   digitalWrite(m22, HIGH); 
   delay(100);
}
void forward1()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
}
void forward()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, HIGH);
   digitalWrite(m21, LOW);
   digitalWrite(m22, HIGH);
}
void left1()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW); 
   delay(100);
}
void right1()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);
   digitalWrite(m22, LOW);
   delay(100);
}
void Stop()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);
   digitalWrite(m22, LOW);
}

