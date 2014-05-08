#include "NU32.h"
#include "PWM.h"
#include "main.h"

void setup(){
    init_pwm_dir(D4, D5);
    init_pwm_dir(D2, D3);
    set_speed(D4, 1970);
    set_speed(D2, 2000);
}

void loop(){
    
}
