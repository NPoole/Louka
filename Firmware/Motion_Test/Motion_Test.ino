#include <Servo.h>

Servo headLeft;  
Servo headRight; 
Servo jaw; 
String input;
char servoName;
int headLift = 60;
int headTwist = 0;
int jawOpen = 0;

void setup() {
  headLeft.attach(11);  
  headRight.attach(10);  
  jaw.attach(9);  
  Serial.begin(115200);
  Serial.println("Attached");
  updateServos();
  randomSeed(analogRead(A0));
}

void loop() {

  headLift = random(30,70);
  headTwist = random(-20,20);
  updateServos();
  delay(random(0,30)*100);
  if(random(0,100)>40){
    bork();
  }  
  delay(random(0,30)*10);
  if(random(0,100)>70){
    bork();
  }
  delay(random(0,30)*10);
}

void bork(){
  jawOpen = 90;
  updateServos();
  delay(100);
  jawOpen = 0;
  headLift += 30;  
  updateServos();
  delay(200);
  headLift -= 30;
  updateServos();
}

void updateServos(){
  headLeft.write(constrain(map(headLift, 100, 0, 90, 160)+headTwist,90,160));
  headRight.write(constrain(map(headLift, 100, 0, 100, 30)+headTwist,30,100));
  jaw.write(map(jawOpen,0,100,90,150));
}
