#ifndef _ULTRASONIC_H
#define _ULTRASONIC_H

void init_ultrasonic(int echo, int trig);
int read_ultrasonic(void);
double ping_ultrasonic(int echo, int trig, int max_distance);
double ping_ultrasonic_median(int echo, int trig, int max_distance, int iterations);
int partition(int array[], int left, int right);
int find_median(int array[], int length);
void swap(int array[], int i, int j);

#endif