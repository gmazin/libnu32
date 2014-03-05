/* Code to control an RC servo motor
 This example uses a PWM pin
 so you are limited to controlling 5 RC servos*/

//////LIBRARIES
#include <plib.h>
#include "NU32.h"

//////GLOBAL VARIABLES

//////FUNCTION PROTOTYPES

//////MAIN
int main(void) {
	NU32_Startup();
	NU32_Initialize();
	NU32_EnableUART1Interrupt();

	// set a 50Hz timer for the PWM signal to the rc servo
  T2CON = 0;  // turn off TMR2, T2CON<ON> = 0
  OC1CON = 0; // turn off OC1, OC1CON<ON> = 0
  T2CONbits.TCKPS = 0b111; // set prescaler 1:256, see RM Section 14 pp. 9-10
  TMR2 = 0;   // start TMR2 counting from zero
  PR2 = 6249; // set period match value
  /* now TMR2 has a period of (PR2 + 1) / PBCLK * 2^T2CON<TCKPS> = 20ms or 50Hz. */

  OC1CONbits.OCM = 0b110; // enable PWM mode with no fault protection
	/* 0 degrees on the servo is a 0.5ms pulse, or OC1RS = (6250/0.02s)*0.0005s = 157 */
	/* 180 degrees on the servo is a 2.5ms pulse, or OC1RS = (6250/0.02s)*0.0025s = 781 */
	/* 90 degrees on the servo is a 1.5ms pulse, or OC1RS = (6250/0.02s)*0.0015s = 467 */
	/* so DON'T SET OC1RS OUTSIDE THE RANGE 157-781*/
  OC1RS = 467; // duty cycle is OC1RS/(PR2+1)
  OC1R = 467;  // set initial PWM duty cycle in counts
                // don't write to OC1R while PWM is running (it's read-only),
                // instead use OC1RS.

  T2CONbits.ON = 1;  // turn on TMR2
  OC1CONbits.ON = 1; // turn on OC1 (pin D0)

	// infinite loop
	int i = 0;
	while (1) {
		// sweep from 10 degrees to 170 degrees and back
		// use (6250/.02)*(0.0005+0.002*(x/180)) to calculate OC1RS for x degrees
		// so start i at 191 and go to 746 and make steps of 5 degrees or 17
		// thats 32 steps, lets make it take 1s, so delay 0.0313s each time
		// thats 1252000 core timer ticks
		for (i=191;i<746;i=i+17) {
			OC1RS = i;
			WriteCoreTimer(0);
			while(ReadCoreTimer() < 1252000);
		}
		for (i=746;i>191;i=i-17) {
			OC1RS = i;
			WriteCoreTimer(0);
			while(ReadCoreTimer() < 1252000);
		}
	}
	return 0;
}

//////FUNCTIONS

//////ISRs

// UART ISR
void __ISR(_UART_1_VECTOR, ipl2) IntUart1Handler(void) {
	// Is this an RX interrupt?
	if (INTGetFlag(INT_SOURCE_UART_RX(UART1))) {

		char data = UARTGetDataByte(UART1);
		PutCharacter(UART1, data);
		NU32LED1 = !NU32LED1;
		NU32LED2 = !NU32LED2;

		// Clear the RX interrupt Flag
		INTClearFlag(INT_SOURCE_UART_RX(UART1));
	}

	// We don't care about TX interrupt
	if (INTGetFlag(INT_SOURCE_UART_TX(UART1))) {
		INTClearFlag(INT_SOURCE_UART_TX(UART1));
	}
}
