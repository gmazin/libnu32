/*
 * File:   Servo.c
 * Author: gmazin
 */
#include <plib.h>
#include "NU32.h"
#include "Servo.h"

void init_rcservo(int pin)
{
    T3CON = 0; //turn off Timer2 when configuring it
    T3CONbits.TCKPS = 0b111; //prescaler N=256 (2^7)
    TMR3 = 0; //initial Timer2 count to 0
    PR3 = 6249; //the period will be (PR2+1)*N*12.5ns = 20ms, or 50Hz
    switch(pin){
        case D0:
            OC1CON = 0; //i guess turn off OC1 when configuring it too
            OC1CONbits.OCM = 0b110;
            /*
             * 0 degrees = 0.5ms pulse = (6250/.02)*.0005 = 157
             * 90 degrees = 1.5ms pulse = (6250/.02)*.0015 = 469
             * 180 degrees = 2.5ms pulse = (6250/.02)*.0025 = 781
             */
            OC1RS = 469;
            OC1R = 469;
            OC1CONbits.ON = 1;
            break;
        case D1:
            OC2CON = 0;
            OC2CONbits.OCM = 0b110;
            OC2RS = 469;
            OC2R = 469;
            OC2CONbits.ON = 1;
            break;
        case D2:
            OC3CON = 0;
            OC3CONbits.OCM = 0b110;
            OC3RS = 469;
            OC3R = 469;
            OC3CONbits.ON = 1;
            break;
        case D3:
            OC4CON = 0;
            OC4CONbits.OCM = 0b110;
            OC4RS = 469;
            OC4R = 469;
            OC4CONbits.ON = 1;
            break;
        case D4:
            OC5CON = 0;
            OC5CONbits.OCM = 0b110;
            OC5RS = 469;
            OC5R = 469;
            OC5CONbits.ON = 1;
            break;
        default:
            break;
    }
    T3CONbits.ON = 1;
}

void set_rcservo(int pin, int degrees)
{
    float set_valuef;
    int set_valuei;

    set_valuef = degrees * 3.467+157.0;
    set_valuei = set_valuef;

    switch(pin){
        case D0:
            OC1RS = set_valuei;
            //OC1RS = (int)(157 + ((degrees/180.0) * 624));
            break;
        case D1:
            OC2RS = set_valuei;
            //OC2RS = (int)(157 + ((degrees/180.0) * 624));
            break;
        case D2:
            OC3RS = set_valuei;
            //OC3RS = (int)(157 + ((degrees/180.0) * 624));
            break;
        case D3:
            OC4RS = set_valuei;
            //OC4RS = (int)(157 + ((degrees/180.0) * 624));
            break;
        case D4:
            OC5RS = set_valuei;
            //OC5RS = (int)(157 + ((degrees/180.0) * 624));
            break;
        default:
            break;
    }
}

int read_rcservo(int pin)
{
    ///can we just access the value in OCxRS? readable?
    return 0;
}
