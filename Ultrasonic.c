/*
 * File:   Ultrasonic.c
 * Author: gmazin
 */
#include <plib.h>
#include "NU32.h"
#include "Ultrasonic.h"



void init_ultrasonic(int echo, int trig)
{
    set_pin_mode(echo, IN);
    set_pin_mode(trig, OUT);
    set_pin(trig, LOW);
   
  //TRISEbits.TRISE8 = 1; // ECHO to A2, NU32 input pin
  //TRISEbits.TRISE9 = 0; // TRIG to A3, NU32 output pin
  //LATEbits.LATE9 = 0; // start off
}

double ping_ultrasonic(int echo, int trig, int max_distance) //max_distance in cm
{//ping HC-SR04 ultrasonic range finder, 10us trigger pulse, sends eight 40kHz pulses
    int start_time;
    int max_time; //max_time in system cycles
    int flight_time;
    
    max_time = max_distance * 4640; //Distance(cm) = Time(us)/58, 80 cycles per us, 58*80=4640
    start_time = ReadCoreTimer();
    set_pin(trig, HIGH);
    while(ReadCoreTimer() - start_time < 800){ //800 cycles at 80MHz, 10us trigger pulse 
    }
    set_pin(trig, LOW);
    while(!get_pin(echo)){
    }
    start_time = ReadCoreTimer();
    while(get_pin(echo) && (ReadCoreTimer() - start_time < max_time)){
    }
    flight_time = ReadCoreTimer() - start_time;
    return flight_time / 4640;
}

double ping_ultrasonic_median(int echo, int trig, int max_distance, int iterations)
{
    int flight_time[iterations];
    int i;
    int start_time;
    for(i = 0; i < iterations; i++){
        flight_time[i] = ping_ultrasonic(echo, trig, max_distance);
        start_time = ReadCoreTimer();
        while(ReadCoreTimer() - start_time < 4000000){//i think this is 50 ms
        }
    }
    return find_median(flight_time, iterations);
}

int partition(int array[], int left, int right)
{
  int high = right-1;
  unsigned int pivot = array[high];
  int swap_index = left;
  int i;

  for(i = left; i < high; i++){
    if(array[i] < pivot){
      swap(array, swap_index, i);
      swap_index++;
    }
  }
  swap(array, swap_index, high);
  return swap_index;
}

int find_median(int array[], int length)
{
  int left = 0;
  int right = length;
  int k = length/2; //only use arrays with odd number of elements
  int pivot_index;



  while(1){
    pivot_index = partition(array, left, right);

    if(pivot_index == k){
      return array[pivot_index];
    } else if(pivot_index < k){
      left = pivot_index + 1;
    } else {
      right = pivot_index;
    }
  }
}

void swap(int array[], int i, int j)
{
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

// return the time of flight of the ultrasonic signal

int read_ultrasonic(void)
{
    


  int flight_time[5];
  int av_flight = 0;
  int i;
  int start_time;

  // read the sensor 5 times and average the result
  for (i = 0; i < 5; i++) {
    start_time = ReadCoreTimer();

    // pulse the trigger for 20us to send the ultrasonic signals
    LATEbits.LATE9 = 1;
    while (ReadCoreTimer() - start_time < 1600) {
    }
    LATEbits.LATE9 = 0;

    // wait for echo to go high
    while (!PORTEbits.RE8) {
    }
    start_time = ReadCoreTimer();

    // wait until the ECHO pin goes low, or 12ms has passed
    while (PORTEbits.RE8 && (ReadCoreTimer() - start_time < 480000)) {
    }
    flight_time[i] = ReadCoreTimer() - start_time;
  }

  for (i = 0; i < 5; i++) {
    av_flight = av_flight + flight_time[i];
  }

  av_flight = av_flight / 5;

  return av_flight;
}