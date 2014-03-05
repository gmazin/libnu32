#ifndef __NU32_H
#define	__NU32_H

#define NU32LED1 LATAbits.LATA4
#define NU32LED2 LATAbits.LATA5
#define NU32USER PORTCbits.RC13
#define B0 0
#define B1 1
#define B2 2
#define B3 3
#define B4 4
#define B5 5
#define B6 6
#define B7 7
#define B8 8
#define B9 9
#define B10 10
#define B11 11
#define B12 12
#define B13 13
#define B14 14
#define B15 15
#define D0 16
#define D1 17
#define D2 18
#define D3 19
#define D4 20
#define D5 21
#define D6 22
#define D7 23
#define D8 24
#define D9 25
#define D10 26
#define D11 27
#define D12 28
#define D13 29
#define D14 30
#define D15 31
#define HIGH 1
#define LOW 0
#define SYS_FREQ 80000000           // 80 million Hz

void startup();
void NU32_ReadUART1(char* string,int maxLength);
void NU32_WriteUART1(const char *string);
void NU32_EnableUART1Interrupt();
void NU32_DisableUART1Interrupt();
void write_string(UART_MODULE id, const char *string);
void put_character(UART_MODULE id, const char character);
int user_switch_pressed();
void set_pin(int pin, int state);
int get_pin(int pin);


#endif	/* NU32_H */

