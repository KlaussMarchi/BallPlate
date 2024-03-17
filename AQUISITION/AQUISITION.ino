#include <Servo.h>

#define TRIGGER_PIN 8
#define ECHO_PIN 9
#define SERVO_PIN 11
Servo servo;


float applyStep(int magnitude){
  int output = mapFloat(magnitude, -100, 100, 45, 135);
  servo.write(output);
}

float getOutput(){
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(10);

  float duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}

void setup(){
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  servo.attach(SERVO_PIN);

  Serial.begin(9600);
  applyStep(0);        // PONTO MORTO

  delay(1000);
  Serial.println("READY");

  while(!Serial.available())
    continue;
  
  delay(2000);
}

void loop(){
  static unsigned long time = millis();
  float time_passed = (millis() - time)/1000.0;

  int step = 100;
  applyStep(step);
  float distance = getOutput();

  String response = "[" + String(time_passed) + "," + String(step) + "," + String(distance) + "]";
  Serial.println(response);
}

float mapFloat(float x, float Xo, float X, float Yo, float Y){
    float mapped = (Y-Yo)/(X-Xo)*(x-Xo) + Yo;

    if(mapped < Yo)
        return Yo;

    if(mapped > Y)
        return Y;

    return mapped;
}
