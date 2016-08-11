/* 
  Useless Box by Oscar Gonzalez
  August 2016 - BricoGeek.com
*/

#include <Servo.h>

Servo myservo;
#define SERVO_PIN     9
#define SERVO_MIN     15
#define SERVO_MAX     100

#define SWITCH_PIN    6

static void movFunc01() {
  Serial.println("Function 01");
  delay(400);
  myservo.write(55);
  delay(800);
  for (int pos = SERVO_MAX-SERVO_MIN; pos <= SERVO_MAX ; pos += 1) { 
    // in steps of 1 degree
    myservo.write(pos);
    delay(15);                       
  }    
  myservo.write(SERVO_MIN);
}
void movFunc02() {
  Serial.println("Function 02");
  delay(400);
  myservo.write(55);
  delay(1000);
  for (int pos = SERVO_MAX-SERVO_MIN; pos <= SERVO_MAX ; pos += 1) { 
    // in steps of 1 degree
    myservo.write(pos);
    delay(25);
  }    
  myservo.write(SERVO_MIN);
}
void movFunc03() {
  Serial.println("Function 02");
  delay(200);
  for (int pos = SERVO_MIN; pos <= 60 ; pos += 1) { 
    // in steps of 1 degree
    myservo.write(pos);
    delay(10);
  }    
  delay(900);
  for (int pos = 60; pos <= SERVO_MAX ; pos += 1) { 
    // in steps of 1 degree
    myservo.write(pos);
    delay(20);
  }      

  for (int pos = SERVO_MAX; pos >= SERVO_MIN ; pos -= 1) { 
    // in steps of 1 degree
    myservo.write(pos);
    delay(45);
  }        
  myservo.write(SERVO_MIN);
}
void movFunc04() {
  delay(400);
  for (int j=0 ; j<5 ; j++)
  {
    myservo.write(SERVO_MIN+20); delay(60);  
    myservo.write(SERVO_MIN); delay(60);
  }
  delay(550);
  for (int pos = SERVO_MIN; pos <= SERVO_MAX ; pos += 1) { 
    // in steps of 1 degree
    myservo.write(pos);              
    delay(2);                       
  }    
  delay(200);
  
  for (int pos = SERVO_MAX; pos >= SERVO_MIN ; pos -= 1) { 
    // in steps of 1 degree
    myservo.write(pos);
    delay(10);
  }          
}
void movFunc05() {
  for (int pos = SERVO_MIN; pos <= SERVO_MAX ; pos += 1) { 
    // in steps of 1 degree
    myservo.write(pos);              
    delay(8);                       
  }    
  for (int pos = SERVO_MAX; pos >= SERVO_MIN ; pos -= 1) { 
    // in steps of 1 degree
    myservo.write(pos);
    delay(10);
  }            
}

void setup() {

  pinMode(SERVO_PIN, OUTPUT);
  pinMode(SWITCH_PIN, INPUT_PULLUP);

  Serial.begin(9600);
  
  myservo.attach(SERVO_PIN);
  myservo.write(SERVO_MIN);

  randomSeed(analogRead(0));
  Serial.println("Useless Box");
}

void loop() {  

   if (!digitalRead(SWITCH_PIN))
   {
      int rnd = random(0, 5);
      
      switch (rnd)
      {
        case 0: { movFunc01(); }; break; 
        case 1: { movFunc02(); }; break; 
        case 2: { movFunc03(); }; break; 
        case 3: { movFunc04(); }; break; 
        case 4: { movFunc05(); }; break; 
      }
      delay(1000);
   }


}

