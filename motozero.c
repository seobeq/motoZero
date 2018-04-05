#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <stdlib.h>

// prototypes
void start();
void stop();
void forward();
void backward();

int main(){
// ##############
wiringPiSetup();

// motor 1
int motor1a = 5;
int motor1b = 2;
softPwmCreate(21, 0, 100);

// motor 2
int motor2a = 22;
int motor2b = 3;
softPwmCreate(0, 0, 100);

// motor 1 outputs
pinMode(5, OUTPUT);
pinMode(2, OUTPUT);

// motor 2 outputs
pinMode(22, OUTPUT);
pinMode(3, OUTPUT);
// ###############

// main
start();
forward();
delay(1000);
stop();
delay(1000);
start();
backward();
delay(1000);
stop();

return(0);
}

// function definitions
void forward(){
digitalWrite(5, HIGH);
digitalWrite(2, LOW);
digitalWrite(22, LOW);
digitalWrite(3, HIGH);
}

void stop(){
softPwmWrite(21, 0);
softPwmWrite(0, 0);
digitalWrite(21, LOW);
digitalWrite(0, LOW);
}

void start(){
softPwmWrite(21, 50);
softPwmWrite(0, 50);
}

void backward(){
digitalWrite(5, LOW);
digitalWrite(2, HIGH);
digitalWrite(22, HIGH);
digitalWrite(3, LOW);
}


