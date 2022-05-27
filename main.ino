#include <Servo.h>
#define inputCLK 2
#define inputDT 3

Servo myservo;

int counter = 0;
int LED = 4;
int currentStateCLK;
int previousStateCLK;
int switchPin = 11;                        // button pin
bool switchState = HIGH;                    // button value
String encdir = "";                        //encoder direction

void setup() {

  pinMode(inputCLK, INPUT);
  pinMode(inputDT, INPUT);
  pinMode(LED,OUTPUT);
  pinMode (switchPin, INPUT_PULLUP);
  Serial.begin(9600);
  myservo.attach(8);
  previousStateCLK = digitalRead(inputCLK);

  Serial.println("jom start!");

}

void loop() {

  // BUTTON
  switchState = digitalRead(switchPin);

  //apabila suis ditekan(pressed)(LOW), print message
  //LED menyala
  if (switchState =! switchState) {
    digitalWrite(LED,HIGH);
    Serial.print("Switch pressed : ");
    Serial.println("LED ON");
    Serial.println();
    delay(1000);
  }
  else {
    digitalWrite(LED,LOW);
    }

  //Rotary encoder dan Servo
  
  currentStateCLK = digitalRead(inputCLK);

  if (currentStateCLK != previousStateCLK)
  {
    if (digitalRead(inputDT) != currentStateCLK)
    {
      counter --;
      encdir = "clockwise";
      if (counter < 0)
      {
        counter = 0;
      }
    }
    else
    {
      counter ++;
      encdir = "anticlockwise";
      if (counter > 180)
      {
        counter = 180;
      }
    }

    myservo.write(counter);
    Serial.print("Servo Position: ");
    Serial.print(counter);
    Serial.println(" degree");
    Serial.print("Encoder Rotary Direction:  ");
    Serial.println(encdir);
    Serial.println();
  }
  previousStateCLK = currentStateCLK;
}
