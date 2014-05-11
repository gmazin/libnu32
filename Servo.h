/* 
 * File:   Servo.h
 * Author: Mechatronics
 *
 * Created on May 9, 2014, 6:37 PM
 */

#ifndef SERVO_H
#define	SERVO_H

void init_rcservo(int pin);
void set_rcservo(int pin, int degrees);
int read_rcservo(int pin);

#endif	/* SERVO_H */

