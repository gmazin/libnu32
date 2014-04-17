#include <plib.h>
#include "NU32.h"

void init_pwm(int pin) {
  T2CON = 0;
  switch (pin) {
	case D0:
	  OC1CONbits.OCM = 0b110; 
	  OC1RS = 500; // duty cycle = OC1RS/(PR2+1) = 25%
	  OC1R = 500; 
	  OC1CONbits.ON = 1; 
	  T2CONbits.ON = 1; 
	  OC1RS = 0;
	  break;	
	case D1:
	  OC2CONbits.OCM = 0b110; 
	  OC2RS = 500; 
	  OC2R = 500; 
	  OC2CONbits.ON = 1; 
	  T2CONbits.ON = 1; 
	  OC2RS = 0;
	  break;
	case D2:
	  OC3CONbits.OCM = 0b110; 
	  OC3RS = 500; 
	  OC3R = 500; 
	  OC3CONbits.ON = 1; 
	  T2CONbits.ON = 1; 
	  OC3RS = 0;
	  break;
	case D3:
          OC4CONbits.OCM = 0b110; 
	  OC4RS = 500; 
	  OC4R = 500; 
	  OC4CONbits.ON = 1; 
	  T2CONbits.ON = 1; 
	  OC4RS = 0;
	  break;
	case D4:
	  OC5CONbits.OCM = 0b110; 
	  OC5RS = 500; 
	  OC5R = 500; 
	  OC5CONbits.ON = 1; 
	  T2CONbits.ON = 1; 
	  OC5RS = 0;
	  break;
	default:
	//add serial message if possible
  	  break;

  }

}

void init_pwm_dir(int pwm_pin, int dir_pin) {
  init_pwm(pwm_pin);
  set_pin(dir_pin, 0);
}

void set_speed(int pwm_pin, int speed) {
  if (speed > 100) speed = 0;
  speed = speed*20; //100*20 = 2000. max duty cycle
  switch (pwm_pin) {
	case D0:
	  OC1RS = speed;
	  break;	
	case D1:
	  OC2RS = speed;
	  break;
	case D2:
	  OC3RS = speed;
	  break;
	case D3:
	  OC4RS = speed;
	  break;
	case D4:
	  OC5RS = speed;
	  break;
	default:
	//add serial message if possible
  	  break;
  }
}
	
/*
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
}*/
