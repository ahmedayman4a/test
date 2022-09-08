#define ir_center_pin 9
#define ir_left_pin 10
#define ir_right_pin 8
#define motor1_pin1 6
#define motor1_pin2 7
#define motor2_pin1 4
#define motor2_pin2 5
#define us_trigger_pin 3
#define us_echo_pin 2

bool isBlackDetected = LOW;

bool turningRight = false;
bool turningLeft = false;

void setup()
{
  pinMode(ir_center_pin,INPUT);
    pinMode(ir_left_pin,INPUT);
    pinMode(ir_right_pin,INPUT);

    pinMode(motor1_pin1,OUTPUT);
    pinMode(motor1_pin2,OUTPUT);
    pinMode(motor2_pin1,OUTPUT);
    pinMode(motor2_pin2,OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    int rightPinRead = digitalRead(ir_right_pin);
    int leftPinRead = digitalRead(ir_left_pin);
    int centerPinRead = digitalRead(ir_center_pin);
//  if ((centerPinRead == isBlackDetected) && (rightPinRead != isBlackDetected) &&  (leftPinRead != isBlackDetected))
//    {
//        moveForward();
//    }

    if (rightPinRead == isBlackDetected)
    {
        turnRight();
        delay(2000);
        moveForward();
    }
    else if (leftPinRead == isBlackDetected)
    {
        turnLeft();
        delay(2000);
        moveForward();
    }
    else{
        moveForward();
    }
    // else if (centerPinRead != isBlackDetected){
    //     moveForward();
    //     delay(2000);
    //     // if (digitalRead(ir_center_pin) != isBlackDetected){

    //     // }
    // }
    
}
void turnRight(){
    digitalWrite(motor1_pin1, HIGH);
    digitalWrite(motor1_pin2,LOW);
    digitalWrite(motor2_pin1,LOW);
    digitalWrite(motor2_pin2,LOW);
}

void turnLeft(){
    digitalWrite(motor1_pin1, LOW);
    digitalWrite(motor1_pin2,LOW);
    digitalWrite(motor2_pin1,HIGH);
    digitalWrite(motor2_pin2,LOW);
}
void moveForward(){
    digitalWrite(motor1_pin1, HIGH);
    digitalWrite(motor1_pin2,LOW);
    digitalWrite(motor2_pin1,HIGH);
    digitalWrite(motor2_pin2,LOW);
}
