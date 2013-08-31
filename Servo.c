/*
 * File:   Servo.c
 * Author: gmazin
 */

#include "NU32.h"

void init_rcservo(void);
void set_rcservo(int degrees);

void init_rcservo(void) {
  // set a 50Hz timer for the PWM signal to the rc servo
  T2CON = 0; // turn off TMR2, T2CON<ON> = 0
  OC1CON = 0; // turn off OC1, OC1CON<ON> = 0
  T2CONbits.TCKPS = 0b111; // set prescaler 1:256, see RM Section 14 pp. 9-10
  TMR2 = 0; // start TMR2 counting from zero
  PR2 = 6249; // set period match value
  /* now TMR2 has a period of (PR2 + 1) / PBCLK * 2^T2CON<TCKPS> = 20ms or 50Hz. */

  OC1CONbits.OCM = 0b110; // enable PWM mode with no fault protection
  /* 0 degrees on the servo is a 0.5ms pulse, or OC1RS = (6250/0.02s)*0.0005s = 157 */
  /* 180 degrees on the servo is a 2.5ms pulse, or OC1RS = (6250/0.02s)*0.0025s = 781 */
  /* 90 degrees on the servo is a 1.5ms pulse, or OC1RS = (6250/0.02s)*0.0015s = 467 */
  /* so DON'T SET OC1RS OUTSIDE THE RANGE 157-781*/
  OC1RS = 467; // duty cycle is OC1RS/(PR2+1)
  OC1R = 467; // set initial PWM duty cycle in counts
  // don't write to OC1R while PWM is running (it's read-only),
  // instead use OC1RS.

  T2CONbits.ON = 1; // turn on TMR2
  OC1CONbits.ON = 1; // turn on OC1 (pin D0)
}

void set_rcservo(int degrees) {
  float set_valuef = degrees * 3.467+157.0; //(degrees-0)*(781-157)/(180-0)+157;
  int set_valuei = set_valuef;

  OC1RS = set_valuei;
}
