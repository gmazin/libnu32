#include "NU32.h"
#include "PWM.h"
#include "Ultrasonic.h"
#include "Servo.h"
#include "main.h"
#define MAX_MESSAGE_LENGTH 200
#define CORNER_TURN 0
#define FIXING_TURN_LEFT 1
#define FIXING_TURN_RIGHT 2
#define STRAIGHT 3

char message[MAX_MESSAGE_LENGTH];
int range;
int prev_range;
int state;

void turnLeft()
{
    enable_pwm(D0);
    WriteCoreTimer(0);
    set_rcservo(D0, 180);
    while(ReadCoreTimer() < 20000000);
    disable_pwm(D0);
}

void resetTurn()
{
    enable_pwm(D0);
    WriteCoreTimer(0);
    set_rcservo(D0, 90);
    while(ReadCoreTimer() < 20000000);
    disable_pwm(D0);
}

void setup(){
    
    init_pwm_dir(D4, D7);
    set_speed(D4, 2000);
    set_pin(D7, LOW);
    //init_pwm_dir(D2, D3);
    //set_speed(D2, 2000);
    //set_pin(D3, LOW);
    //set_speed(D4, 0);
    //set_pin(D5, LOW);
    init_ultrasonic(D11, D10);
    //set_pin_mode(D0, IN);
    //set_pin(D0, LOW);
    range = 0;
    state = STRAIGHT;
    
    set_pin_mode(D0, IN);
    init_rcservo(D0);
    
}

void loop(){
    if (user_switch_pressed()){
        set_pin_mode(D0, OUT);
        set_pin(D0, HIGH);
    }
    //sprintf(message, "help me\n", range);
    //NU32_WriteUART1(message);
    prev_range = range;
    range = ping_ultrasonic(D11, D10, 250);
    sprintf(message, "%d cm  %d STATE\n", range, state);
    NU32_WriteUART1(message);/*
    if(state == CORNER_TURN){
        if(range < 60){
            set_speed(D4, 0);
            set_pin(D5, LOW);
            state = STRAIGHT;
        }
    } else if(state == FIXING_TURN_LEFT){
        if(range > prev_range){
            set_speed(D4, 0);
            set_pin(D5, LOW);
            state = STRAIGHT;
        }
    } else if(state == FIXING_TURN_RIGHT){
        if(range > 8){
            set_speed(D4, 0);
            set_pin(D5, LOW);
            state = STRAIGHT;
        }
    } else {
        if(range > 60){
            set_speed(D4, 300);
            set_pin(D5, LOW);
            state = CORNER_TURN;
        }
        else if(range > 20 && range > prev_range){
            set_speed(D4, 300);
            set_pin(D5, LOW);
            state = FIXING_TURN_LEFT;
        } else if(range <= 8){
            set_speed(D4, 300);
            set_pin(D5, HIGH);
            state = FIXING_TURN_RIGHT;
        }
    }
    */
    if(range > 60){
        turnLeft();
        WriteCoreTimer(0);
        while(ReadCoreTimer() < 80000000)
        resetTurn();
    }
    WriteCoreTimer(0);
    while(ReadCoreTimer() < 4000000){}
    //NU32_WriteUART1(message);
/*
    if (user_switch_pressed()){
        enable_pwm(D0);
        WriteCoreTimer(0);
        set_rcservo(D0, 180);
        while(ReadCoreTimer() < 20000000);
        disable_pwm(D0);
    }*/
}
