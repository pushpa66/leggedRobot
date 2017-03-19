#include <Servo.h>


class Motor {
  private:
    int calibrateAngle;
    int dataPin;
    int currentAngle;
    int previousAngle;
    Servo myServo;
  public:

//    void drawPattern(char patternID);
  Motor(Servo myServo, int dataPin, int calibrateAngle)
  {
   this->myServo = myServo;
   this->dataPin = dataPin;
   this->myServo.attach(this->dataPin);
   this->calibrateAngle = calibrateAngle;
  }
  void initAngle(){
    myServo.write(this->calibrateAngle);
    this->currentAngle = calibrateAngle;
    this->previousAngle = calibrateAngle;
  }
  void setAngle(int angle){
    int i = angle - this->previousAngle;
    if(i > 0){
       for(int k  = 1; k <= i; k++){
        this->myServo.write(this->previousAngle + k);
       } 
    }else if(i < 0){
       for(int k  = 1; k <=(-i); k++){
        this->myServo.write(this->previousAngle - k);
        delay(10);
       } 
    }
  }
};


String message;
Servo myServo_1; 
Motor myServo_Left_Base1(myServo_1, 4, 0);
Servo myServo_2;
Motor myServo_Left_Base2(myServo_2, 4, 0);
Servo myServo_3;
Motor myServo_Left_Middle1(myServo_3, 5, 0);
Servo myServo_4;
Motor mySrvo_Left_Middle2(myServo_4, 7, 0);

Servo myServo_5;
Motor myServo_Right_Base1(myServo_5, 8, 0);
Servo myServo_6;
Motor myServo_Right_Base2(myServo_6, 9, 0);
Servo myServo_7;
Motor myServo_Right_Middle1(myServo_7, 10, 0);
Servo myServo_8;
Motor myServo_Right_Middle2(myServo_8, 11, 0);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  while(Serial.available()>0)
  {
    message+=char(Serial.read());
//==================== Go Forward ==========================   
    if(message == "1"){ 
 
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
     
//==================== Arm Move Up ==========================
    }else if(message == "8"){
      
//==================== Arm Move Down ==========================
    }else if(message == "9"){
      
//==================== Grab Box ==========================
    }else if(message == "0"){
      
//==================== U Tern Left ==========================
    }else if(message == "l"){
     
//==================== U Tern Right ==========================
    }else if(message == "r"){
     
    }
    message="";
    delay(100);
  }
} 

