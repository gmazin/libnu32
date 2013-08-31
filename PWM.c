#include "NU32.h"

void init_pwm_D4_dir_D5(void);
void set_speed_D4_dir_D5(int speed, int dir);

void init_pwm_D4_dir_D5(void) {
  // use D5 as DIR pin
  TRISDbits.TRISD5 = 0;

  // use TIMER2 for the PWM
  T2CONbits.TCKPS = 2; // Timer2 prescaler N=4 (1:4)
  PR2 = 1999; // period = (PR2+1) * N * 12.5 ns = 100 us, 10 kHz
  TMR2 = 0; // initial TMR2 count is 0

  // use OC5 (on D4)
  OC5CONbits.OCM = 0b110; // PWM mode without fault pin; other OC1CON bits are defaults
  OC5RS = 500; // duty cycle = OC1RS/(PR2+1) = 25%
  OC5R = 500; // initialize before turning OC1 on; then it is read-only

  // turn them on
  T2CONbits.ON = 1; // turn on Timer2
  OC5CONbits.ON = 1; // turn on OC1

  // initially off
  OC5RS = 0;
  LATDbits.LATD5 = 0;
}

void set_speed_D4_dir_D5(int speed, int dir) {
  if (dir == 0) {
    LATDbits.LATD5 = 0;
    OC5RS = 1999*speed/100;
  }

  if (dir == 1) {
    LATDbits.LATD5 = 1;
    OC5RS = 1999 - 1999*speed/100;
  }
}
