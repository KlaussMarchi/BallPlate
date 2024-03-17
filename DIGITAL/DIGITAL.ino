#include <Servo.h>

#define TRIGGER_PIN 8
#define ECHO_PIN 9
#define SERVO_PIN 11
#define T 0.15
Servo servo;

float getInput(){
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(10);

    float duration = pulseIn(ECHO_PIN, HIGH);
    return duration * 0.034 / 2;
}

float applyStep(int magnitude){
    int output = mapFloat(magnitude, -100, 100, 45, 135);
    servo.write(output);
}

double computeController(double inputValue, double setpoint){
    static double Y_n1, Y_n2, Y_n3, Y_n4;
    static double X_n1, X_n2, X_n3, X_n4;
    
    double X_n = setpoint - inputValue;
    double Y_n = 55.9685956922464*X_n - 98.9537313153433*X_n1 - 12.7189261538842*X_n2 + 98.9537313153433*X_n3 - 43.2496695383622*X_n4 + 2.0*Y_n2 - Y_n4;

    if(Y_n < -100)
        Y_n = -100;

    if(Y_n > 100)
        Y_n = 100;
    
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
    applyStep(0);

    Serial.println("INICIANDO...");
    delay(2000);
}

void loop() {
    static unsigned long time = millis();
    float time_passed = (millis() - time)/1000.0;

    if(time_passed < T)
        return;
    
    time = millis();

    float setpoint = 20;
    float input = getInput();
    float output = computeController(input, setpoint);
    applyStep(output);

    //Serial.println("-100, " + String(output) + ", 100");
    Serial.println("0, " + String(input) + ", " + String(setpoint) );

    //Serial.println("input:  " + String(input));
    //Serial.println("output: " + String(output));
    //Serial.println("erro:   " + String(setpoint-input));
    Serial.println();
}

float mapFloat(float x, float Xo, float X, float Yo, float Y){
    float mapped = (Y-Yo)/(X-Xo)*(x-Xo) + Yo;

    if(mapped < Yo)
        return Yo;

    if(mapped > Y)
        return Y;

    return mapped;
}

double smooth(double val) {
    const int TAM = 15;
    static double array[TAM];
    static double sum = 0.0;
    static int i = 0;

    sum = sum - array[i];
    array[i] = val;

    sum = sum + array[i];
    i++;

    if (i == TAM)
        i = 0;

    return sum / TAM;
}