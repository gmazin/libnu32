/*
 * File:   Ultrasonic.c
 * Author: gmazin
 */

#include "NU32.h"

void init_ultrasonic(void);
int read_ultrasonic(void);

void init_ultrasonic(void)
{
  TRISEbits.TRISE8 = 1; // ECHO to A2, NU32 input pin
  TRISEbits.TRISE9 = 0; // TRIG to A3, NU32 output pin
  LATEbits.LATE9 = 0; // start off
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