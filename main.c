#include "NU32.h"
#include "PWM.h"
#include "Ultrasonic.h"
#include "main.h"
#define MAX_MESSAGE_LENGTH 200

char message[MAX_MESSAGE_LENGTH];
int range;

void setup(){
    init_pwm_dir(D4, D5);
    init_pwm_dir(D2, D3);
    set_speed(D4, 2000);
    set_speed(D2, 0);
    init_ultrasonic(D11, D10);
    set_pin_mode(D0, IN);
    //set_pin(D0, LOW);
}

void loop(){
    if (user_switch_pressed()){
        set_pin_mode(D0, OUT);
        set_pin(D0, HIGH);
    }
    //sprintf(message, "help me\n", range);
    //NU32_WriteUART1(message);
    range = ping_ultrasonic(D11, D10, 250);
    sprintf(message, "%d cm\n", range);
    NU32_WriteUART1(message);
    if(range > 30){
        set_speed(D2, 1200);
        set_pin(D3, LOW);
    } else if(range < 7){
        set_speed(D2, 800);
        set_pin(D3, HIGH);
    } else {
        set_speed(D2, 0);
        set_pin(D3, 0);
    }

    WriteCoreTimer(0);
    while(ReadCoreTimer() < 4000000){}
    //NU32_WriteUART1(message);

}
