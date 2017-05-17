
#include <Servo.h>

String message;

int k = 5;
int val = 50;

Servo ServoLeftBase1;
Servo ServoLeftBase2;
Servo ServoRightBase1;
Servo ServoRightBase2;

Servo ServoLeftMiddle1;
Servo ServoLeftMiddle2;
Servo ServoRightMiddle1;
Servo ServoRightMiddle2;

void initM() {
  ServoLeftBase1.attach(2);
  ServoLeftBase1.write(40);

  ServoLeftBase2.attach(3);
  ServoLeftBase2.write(40);

  ServoRightBase1.attach(4);
  ServoRightBase1.write(40);

  ServoRightBase2.attach(5);
  ServoRightBase2.write(40);

  ServoLeftMiddle1.attach(6);
  ServoLeftMiddle1.write(60);

  ServoLeftMiddle2.attach(7);
  ServoLeftMiddle2.write(60);

  ServoRightMiddle1.attach(8);
  ServoRightMiddle1.write(60);

  ServoRightMiddle2.attach(9);
  ServoRightMiddle2.write(60);
}

void setAngle(Servo servo, int angle) {
  int current = servo.read();
  servo.write(current + angle);
}

void resetLegPosition() {
  ServoLeftBase1.write(40);
  ServoLeftBase2.write(40);
  ServoRightBase1.write(40);
  ServoRightBase2.write(40);
  ServoLeftMiddle1.write(60);
  ServoLeftMiddle2.write(60);
  ServoRightMiddle1.write(60);
  ServoRightMiddle2.write(60);
}

void moveLegUp(Servo servo, int side) {
  switch (side) {
    case 1:
      for (int i = 0; i <= k ; i++) {
        setAngle(servo, i);
        delay(val);
      }
      break;
    case 2:
      for (int i = 0; i <= k ; i++) {
        setAngle(servo, -i);
        delay(val);
      }
      break;
    default:
      break;
  }
}
void moveLegDown(Servo servo, int side) {
  switch (side) {
    case 1:
      for (int i = 0; i <= k ; i++) {
        setAngle(servo, -i);
        delay(val);
      }
      break;
    case 2:
      for (int i = 0; i <= k ; i++) {
        setAngle(servo, i);
        delay(val);
      }
      break;
    default:
      break;
  }
}
void moveLegForward(Servo servo, int side) {
  switch (side) {
    case 1:
      for (int i = 0; i <= k ; i++) {
        setAngle(servo, i);
        delay(val);
      }
      break;
    case 2:
      for (int i = 0; i <= k ; i++) {
        setAngle(servo, -i);
        delay(val);
      }
      break;
    default:
      break;
  }
}
void moveLegBackward(Servo servo, int side) {
  switch (side) {
    case 1:
      for (int i = 0; i <= k ; i++) {
        setAngle(servo, -i);
        delay(val);
      }
      break;
    case 2:
      for (int i = 0; i <= k ; i++) {
        setAngle(servo, i);
        delay(val);
      }
      break;
    default:
      break;
  }
}
void goForward() {
  // move the first left leg
  moveLegUp(ServoLeftMiddle1, 2);
  moveLegForward(ServoLeftBase1, 2);
  moveLegDown(ServoLeftMiddle1, 2);

  // move the first right leg
  moveLegUp(ServoRightMiddle1, 1);
  moveLegForward(ServoRightBase1, 1);
  moveLegDown(ServoRightMiddle1, 1);

  // move the second left leg
  moveLegUp(ServoLeftMiddle2, 2);
  moveLegForward(ServoLeftBase2, 2);
  moveLegDown(ServoLeftMiddle2, 2);

  // move the second right leg
  moveLegUp(ServoRightMiddle2, 1);
  moveLegForward(ServoRightBase2, 1);
  moveLegDown(ServoRightMiddle2, 1);

  resetLegPosition();
}
void startPattern() {
  for (int i = 0; i < 30; i++) {
    //    LeftMiddle1.setAngle(i);
    //    LeftMiddle2.setAngle(i);
    //    RightMiddle1.setAngle(i);
    //    RightMiddle2.setAngle(i);
    delay(10);
  }
}
void readM() {
  message = "";
  message += char(Serial.read());
}

void setup()
{
  initM();
  Serial.begin(9600);
}

void loop()
{

  goForward();
//  moveLegUp(ServoLeftMiddle1, 2);
//  delay(2000);
//  moveLegDown(ServoLeftMiddle1, 2);
//  delay(2000);

//  moveLegForward(ServoLeftBase1, 2);
//  delay(2000);
//  moveLegBackward(ServoLeftBase1, 2);
//  delay(2000);



  /*
    while(Serial.available()>0)
    {
    //    message+=char(Serial.read());
    readM();

    if(message == "q"){
      for(int k=0; k<30; k++){
        LeftMiddle1.setAngle(k);
        LeftMiddle2.setAngle(k);
        RightMiddle1.setAngle(k);
        RightMiddle2.setAngle(k);
        delay(10);
       }
       for(int k=30; k>=0; k--){
        LeftMiddle1.setAngle(k);
        LeftMiddle2.setAngle(k);
        RightMiddle1.setAngle(k);
        RightMiddle2.setAngle(k);
        delay(10);
       }
       readM();
    }
    //==================== Go Forward ==========================
    if(message == "1"){
       for(int k=0; k<30; k++){
        LeftMiddle1.setAngle(k);
        delay(10);
       }
       for(int k=0; k<30; k++){
        LeftBase1.setAngle(k);
        delay(10);
       }
       readM();

    //==================== Go Backward ==========================
    }else if(message == "2"){

    //==================== Turn Right ==========================
    }else if(message == "3"){

    //==================== Turn Left ==========================
    }else if(message == "4"){

    //==================== Speed UP ==========================
    }else if(message == "5"){

    //==================== Speed Down ==========================
    }else if(message == "6"){

    //==================== StandBy ==========================
    }else if(message == "7"){

    //==================== U Tern Left ==========================
    }else if(message == "l"){

    //==================== U Tern Right ==========================
    }else if(message == "r"){

    }
    message="";
    delay(100);
    }

  */
}

