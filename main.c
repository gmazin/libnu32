#include "NU32.h"
#include "PWM.h"

int main(void) {
    startup();
    init_pwm_dir(D4, D5);
    set_speed(D4, 100);
    while (1){
        if (user_switch_pressed()) set_speed(D4, 0);
    }
}