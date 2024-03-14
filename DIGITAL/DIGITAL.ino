#include <Servo.h>

#define TRIGGER_PIN 8
#define ECHO_PIN 9
#define SERVO_PIN 11
#define T 0.1

#define MIN_OUT 19795.39764271524
#define MAX_OUT 1422565.3028866444

Servo servo;


float computeController(float inputValue, float setpoint){
    static float Y_n1, Y_n2, Y_n3, Y_n4;
    static float X_n1, X_n2, X_n3, X_n4;
    
    float X_n = setpoint - inputValue;
    float Y_n = 989.769882135762*X_n + 1793.64993808818*X_n1 - 177.161801197327*X_n2 - 1793.64993808818*X_n3 - 812.608080938436*X_n4 + 2.0*Y_n2 - Y_n4;
    Y_n = mapFloat(Y_n, MIN_OUT, MAX_OUT, 45, 135);

    X_n4 = X_n3;
    X_n3 = X_n2;
    X_n2 = X_n1;
    X_n1 = X_n; 

    Y_n4 = Y_n3;
    Y_n3 = Y_n2;
    Y_n2 = Y_n1;
    Y_n1 = Y_n;
    return Y_n;
}

void setup() {
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    servo.attach(SERVO_PIN);
    
    Serial.begin(9600);
    applyOutput(90);

    Serial.println("INICIANDO...");
    delay(2000);
}

void loop() {
    static unsigned long time = millis();
    float time_passed = (millis() - time)/1000.0;

    if(time_passed < T)
        return;
    
    time = millis();

    float setpoint = 10;
    float input    = getInput();
    float output   = computeController(input, setpoint);

    applyOutput(output);
    Serial.println("input:  " + String(input));
    Serial.println("output: " + String(output));
    Serial.println("erro:   " + String(setpoint-input));
    Serial.println();
}

float getInput(){
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(10);

  float duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}

void applyOutput(int output){
    if(output < 45)
        output = 45;

    if(output > 135)
        output = 135;

    servo.write(output);
}

float mapFloat(float x, float Xo, float X, float Yo, float Y){
    float mapped = (Y-Yo)/(X-Xo)*(X-Xo)*(x-Xo) + Yo;

    if(mapped < Yo)
        return Yo;

    if(mapped > Y)
        return Y;

    return mapped;
}
