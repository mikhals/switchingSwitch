
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
Servo servo2;
// twelve servo objects can be created on most boards
int MAX=130;
int SLOW=1;
int DELAY=20;

volatile int pos = 0;    // variable to store the servo position
volatile int targetPos = 0;

volatile int pos2= 0;    // variable to store the servo position
volatile int targetPos2 = 0;


ICACHE_RAM_ATTR
void onLED(){
  digitalWrite(LED_BUILTIN,LOW);
  targetPos=130;
  targetPos2=0;
}
ICACHE_RAM_ATTR
void offLED(){
  digitalWrite(LED_BUILTIN,HIGH);
  targetPos=0;
  targetPos2=140;
}




void setup() {
  pinMode(D6, INPUT_PULLUP);
  pinMode(D5, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(D6),onLED,FALLING);
  attachInterrupt(digitalPinToInterrupt(D5),offLED,FALLING);
  myservo.attach(D9);  
  servo2.attach(D7);  
  
  Serial.begin (9600);
  // put your setup code here, to run once:

}

void loop() {
  
  Serial.printf("%d %d\n",digitalRead(D5),digitalRead(D6));
  move();
}

void move(){

  while(targetPos!=pos){
    if(pos<targetPos){
      pos++;
      myservo.write(pos);
      delay(DELAY);
    }
    else if (pos>targetPos){
      pos--;
      myservo.write(pos);
      delay(DELAY);
    }
    if(pos2<targetPos2){
      pos2++;
      servo2.write(pos2);
      delay(DELAY);
    }
    else if (pos2>targetPos2){
      pos2--;
      servo2.write(pos2);
      delay(DELAY);
    }
    
    else{}

    Serial.printf("%d %d\n",digitalRead(D11),digitalRead(D12));
  }
}
