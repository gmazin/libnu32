#ifndef __PWM_H
#define	__PWM_H

void init_pwm(int pin);
void init_pwm_dir(int pwm_pin, int dir_pin);
void set_speed(int pwm_pin, int speed);
void enable_pwm(int pin);
void disable_pwm(int pin);

#endif	/* PWM_H */

