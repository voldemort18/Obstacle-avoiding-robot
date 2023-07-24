#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>


double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
void Backward();
void Left();
void Right();
void Forward();
void Stop();


void Backward()
{
    analogWrite(byte(10),byte(0));
    
    analogWrite(byte(11),byte(255));
    
    analogWrite(byte(6),byte(0));
    
    analogWrite(byte(9),byte(255));
    
}

void Left()
{
    analogWrite(byte(10),byte(255));
    
    analogWrite(byte(11),byte(0));
    
    analogWrite(byte(6),byte(0));
    
    analogWrite(byte(9),byte(255));
    
}

void Right()
{
    analogWrite(byte(10),byte(0));
    
    analogWrite(byte(11),byte(255));
    
    analogWrite(byte(6),byte(255));
    
    analogWrite(byte(9),byte(0));
    
}

void Forward()
{
    analogWrite(byte(10),byte(255));
    
    analogWrite(byte(11),byte(0));
    
    analogWrite(byte(6),byte(255));
    
    analogWrite(byte(9),byte(0));
    
}

void Stop()
{
    analogWrite(byte(10),byte(0));
    
    analogWrite(byte(11),byte(0));
    
    analogWrite(byte(6),byte(0));
    
    analogWrite(byte(9),byte(0));
    
}


void setup(){
    
    pinMode(byte(10),byte(1));
    pinMode(byte(11),byte(1));
    pinMode(byte(6),byte(1));
    pinMode(byte(9),byte(1));
    pinMode(byte(2),byte(0));
    pinMode(byte(3),byte(0));
}

void loop(){
    
    _delay(1);
    if((((digitalRead(byte(3)))==(0))) && (((digitalRead(byte(2)))==(0)))){
        Stop();
        _delay(1);
        Forward();
        _delay(0.2);
        Stop();
        _delay(1);
    }
    if((((digitalRead(byte(3)))==(0))) && (((digitalRead(byte(2)))==(1)))){
        _delay(1);
        Stop();
        _delay(1);
        Backward();
        _delay(0.3);
        Left();
        _delay(0.2);
        Stop();
        _delay(1);
    }
    if((((digitalRead(byte(3)))==(1))) && (((digitalRead(byte(2)))==(0)))){
        _delay(1);
        Stop();
        _delay(1);
        Backward();
        _delay(0.3);
        Right();
        _delay(0.2);
        Stop();
        _delay(1);
    }
    if((((digitalRead(byte(3)))==(1))) && (((digitalRead(byte(2)))==(1)))){
        _delay(1);
        Stop();
        _delay(1);
        Backward();
        _delay(0.3);
        Right();
        _delay(0.2);
        Left();
    }
    
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    
}
