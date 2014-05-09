#ifndef _ULTRASONIC_H
#define _ULTRASONIC_H

void init_ultrasonic(int echo, int trig);
int read_ultrasonic(void);
int ping_ultrasonic(int echo, int trig, int max_distance);
int ping_ultrasonic_median(int echo, int trig, int max_distance, int iterations);

#endif