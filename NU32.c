#include <plib.h>
#include "NU32.h"
#include "main.h"

#define DESIRED_BAUDRATE_NU32 230400 // Baudrate for RS232

// Private Buffers
char NU32_RS232OutBuffer[32]; // Buffer for sprintf in serial tx

void write_string(UART_MODULE id, const char *string);
void put_character(UART_MODULE id, const char character);
/* Perform startup routines:
 * Make NU32LED1 and NU32LED2 pins outputs (NU32USER is by default an input)
 * Initialize the serial ports - UART1 (no interrupt) and UART4 (with interrupt)
 */
int main(void){
  startup();
  setup();
  while (1) loop();
}
 
void startup() {
  // set to maximum performance and enable all interrupts
  SYSTEMConfig(SYS_FREQ, SYS_CFG_ALL);
  INTEnableSystemMultiVectoredInt();
  // disable JTAG to get A4 and A5 back - chances are this is fine if you're using the bootloader
  DDPCONbits.JTAGEN = 0;

  TRISACLR = 0x0030; // Make A5 and A4 outputs (L2 and L1 on the silkscreen)
  NU32LED1 = 1; // L1 is off
  NU32LED2 = 0; // L2 is on

  // turn on UART1 without an interrupt
  UARTConfigure(UART1, UART_ENABLE_PINS_TX_RX_ONLY );
  UARTSetFifoMode(UART1, UART_INTERRUPT_ON_TX_NOT_FULL | UART_INTERRUPT_ON_RX_NOT_EMPTY);
  UARTSetLineControl(UART1, UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1);
  UARTSetDataRate(UART1, SYS_FREQ, DESIRED_BAUDRATE_NU32);
  UARTEnable(UART1, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));

  // turn on UART4 with an interrupt
  UARTConfigure(UART4, UART_ENABLE_PINS_TX_RX_ONLY);
  UARTSetFifoMode(UART4, UART_INTERRUPT_ON_TX_DONE | UART_INTERRUPT_ON_RX_NOT_EMPTY);
  UARTSetLineControl(UART4, UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1);
  UARTSetDataRate(UART4, SYS_FREQ, DESIRED_BAUDRATE_NU32);
  UARTEnable(UART4, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));

  // Configure UART4 RX Interrupt
  INTEnable(INT_U4RX, INT_ENABLED);
  INTSetVectorPriority(INT_UART_4_VECTOR, INT_PRIORITY_LEVEL_3);
  INTSetVectorSubPriority(INT_UART_4_VECTOR, INT_SUB_PRIORITY_LEVEL_0);

  // Set all AN pins (B0-B15) for analog input
  TRISBSET = 0xFFFF;
  AD1PCFGCLR = 0xFFFF;

  // ---- INITIALIZE ANALOG ---- //

  AD1CON1bits.FORM = 0b000; // Select 16-bit integer output
  AD1CON1bits.ASAM = 1; // Auto Sample
  AD1CON1bits.SSRC = 0b111; // Auto convert sampled data to digital
  AD1CON2bits.VCFG = 0b000; // Select the vrefs to be Vdd and Vss

  AD1CON2bits.CSCNA = 1; // Enable ADC Scaning
  AD1CSSL = 0xFFFF; // Select all AN pins for scanning
  AD1CON2bits.SMPI = 16 - 1; // Select 3 samples per interupt
  /* In scanning mode, this number must be at least as big as
   * the number of channels you are scanning/
   */

  AD1CON3bits.ADRC = 1; // Use internal RC clock
  AD1CON3bits.SAMC = 2; // Set sampling time 2*Tad
  AD1CON1bits.ADON = 1; // Turn the ADC on
  
  // ---- INITIALIZE PWM TIMERS ---- //
  
  T2CON = 0;  // this value will turn off TMR2, T2CON<ON> = 0
  T2CONbits.TCKPS = 2; // set prescaler 1:4
  TMR2 = 0;   // start TMR2 counting from zero
  PR2 = 1999; // set period match value
  
  T3CON = 0; // turn off TMR1 (servo)
  T3CONbits.TCKPS = 0b111; // set prescaler 1:256
  TMR3 = 0; // start TMR2 counting from zero
  PR3 = 6249; 
  
  
}


// Enable UART1 interrupt, so don't use NU32_ReadUART1 anymore
void NU32_EnableUART1Interrupt(void) {
  // turn off the module to change the settings
  UARTEnable(UART1, UART_ENABLE_FLAGS(UART_DISABLE));

  // Configure UART1 RX Interrupt
  UARTConfigure(UART1, UART_ENABLE_PINS_TX_RX_ONLY );
  UARTSetFifoMode(UART1, UART_INTERRUPT_ON_TX_DONE | UART_INTERRUPT_ON_RX_NOT_EMPTY);
  UARTSetLineControl(UART1, UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1);
  UARTSetDataRate(UART1, SYS_FREQ, DESIRED_BAUDRATE_NU32);
  UARTEnable(UART1, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));
  INTEnable(INT_U1RX, INT_ENABLED);
  INTSetVectorPriority(INT_UART_1_VECTOR, INT_PRIORITY_LEVEL_2);
  INTSetVectorSubPriority(INT_UART_1_VECTOR, INT_SUB_PRIORITY_LEVEL_0);

}

// Disable UART1 interrupt, so you can use NU32_ReadUART1 again
void NU32_DisableUART1Interrupt(void) {
  // turn off the module to change the settings
  UARTEnable(UART1, UART_ENABLE_FLAGS(UART_DISABLE));

  // Configure UART1 RX Interrupt to off
  UARTConfigure(UART1, UART_ENABLE_PINS_TX_RX_ONLY);
  UARTSetFifoMode(UART1, UART_INTERRUPT_ON_TX_DONE | UART_INTERRUPT_ON_RX_NOT_EMPTY);
  UARTSetLineControl(UART1, UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1);
  UARTSetDataRate(UART1, SYS_FREQ, DESIRED_BAUDRATE_NU32);
  UARTEnable(UART1, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));
  INTEnable(INT_U1RX, INT_DISABLED);
}

/* Read from UART1
 * block other functions until you get a '\r' or '\n'
 * send the pointer to your char array and the number of elements in the array
 */
void NU32_ReadUART1(char * message, int maxLength) {
  char data;
  int complete = 0, num_bytes = 0;
  // loop until you get a '\r' or '\n'
  while (!complete) {
    if (UARTReceivedDataIsAvailable(UART1)) {
      data = UARTGetDataByte(UART1);
      if ((data == '\n') || (data == '\r')) {
        complete = 1;
      } else {
        message[num_bytes] = data;
        num_bytes++;
        // roll over if the array is too small
        if (num_bytes >= maxLength) {
          num_bytes = 0;
        }
      }
    }
  }
  // end the string
  message[num_bytes] = '\0';
}

// Write a charater array using UART1
void NU32_WriteUART1(const char *string) {
  write_string(UART1, string);
}

// Write a string over the serial port
void write_string(UART_MODULE id, const char *string) {
  while (*string != '\0') {
    while (!UARTTransmitterIsReady(id));
    UARTSendDataByte(id, (char) *string);
    string++;
    while (!UARTTransmissionHasCompleted(id));
  }
}

// Put a character over the serial port, called by write_string
void put_character(UART_MODULE id, const char character) {
  while (!UARTTransmitterIsReady(id));
  UARTSendDataByte(id, character);
  while (!UARTTransmissionHasCompleted(id));
}

// do a software reset and go into bootloader mode if you get a 'B'
void __ISR(_UART_4_VECTOR, ipl3) IntUart4Handler(void) {
  // Is this an RX interrupt?
  if (INTGetFlag(INT_SOURCE_UART_RX(UART4))) {

    char data = UARTGetDataByte(UART4);

    NU32LED1 = !NU32LED1;
    NU32LED2 = !NU32LED2;

    if (data == 'B') {
      sprintf(NU32_RS232OutBuffer, "Switching to bootloader\r\n");
      write_string(UART1, NU32_RS232OutBuffer);
      SoftReset();
    }

    // Clear the RX interrupt Flag
    INTClearFlag(INT_SOURCE_UART_RX(UART4));
  }

  // We don't care about TX interrupt
  if (INTGetFlag(INT_SOURCE_UART_TX(UART4))) {
    INTClearFlag(INT_SOURCE_UART_TX(UART4));
  }
}

int get_pin(int pin) {
  switch (pin) {
    case B0:
      return ADC1BUF0;
      break;
    case B1:
      return ADC1BUF1;
      break;
    case B2:
      return ADC1BUF2;
      break;
    case B3:
      return ADC1BUF3;
      break;
    case B4:
      return ADC1BUF4;
      break;
    case B5:
      return ADC1BUF5;
      break;
    case B6:
      return ADC1BUF6;
      break;
    case B7:
      return ADC1BUF7;
      break;
    case B8:
      return ADC1BUF8;
      break;
    case B9:
      return ADC1BUF9;
      break;
    case B10:
      return ADC1BUFA;
      break;
    case B11:
      return ADC1BUFB;
      break;
    case B12:
      return ADC1BUFC;
      break;
    case B13:
      return ADC1BUFD;
      break;
    case B14:
      return ADC1BUFE;
      break;
    case B15:
      return ADC1BUFF;
      break;
    case D0:
      return PORTDbits.RD0;
      break;
    case D1:
      return PORTDbits.RD1;
      break;
    case D2:
      return PORTDbits.RD2;
      break;
    case D3:
      return PORTDbits.RD3;
      break;
    case D4:
      return PORTDbits.RD4;
      break;
    case D5:
      return PORTDbits.RD5;
      break;
    case D6:
      return PORTDbits.RD6;
      break;
    case D7:
      return PORTDbits.RD7;
      break;
    case D8:
      return PORTDbits.RD8;
      break;
    case D9:
      return PORTDbits.RD9;
      break;
    case D10:
      return PORTDbits.RD10;
      break;
    case D11:
      return PORTDbits.RD11;
      break;
    case D12:
      return PORTDbits.RD12;
      break;
    case D13:
      return PORTDbits.RD13;
      break;
    case D14:
      return PORTDbits.RD14;
      break;
    case D15:
      return PORTDbits.RD15;
      break;
  }
}

void set_pin(int pin, int value) {
  switch (pin) {
    case B0:
      
      break;
    case B1:
      
      break;
    case B2:
      
      break;
    case B3:
      
      break;
    case B4:
      
      break;
    case B5:
      
      break;
    case B6:
      
      break;
    case B7:
      
      break;
    case B8:
      
      break;
    case B9:
      
      break;
    case B10:
      
      break;
    case B11:
      
      break;
    case B12:
      
      break;
    case B13:
      
      break;
    case B14:
      
      break;
    case B15:
      
      break;
    case D0:
      LATDbits.LATD0 = value;
      break;
    case D1:
      LATDbits.LATD1 = value;
      break;
    case D2:
      LATDbits.LATD2 = value;
      break;
    case D3:
      LATDbits.LATD3 = value;
      break;
    case D4:
      LATDbits.LATD4 = value;
      break;
    case D5:
      LATDbits.LATD5 = value;
      break;
    case D6:
      LATDbits.LATD6 = value;
      break;
    case D7:
      LATDbits.LATD7 = value;
      break;
    case D8:
      LATDbits.LATD8 = value;
      break;
    case D9:
      LATDbits.LATD9 = value;
      break;
    case D10:
      LATDbits.LATD10 = value;
      break;
    case D11:
      LATDbits.LATD11 = value;
      break;
    case D12:
      LATDbits.LATD12 = value;
      break;
    case D13:
      LATDbits.LATD13 = value;
      break;
    case D14:
      LATDbits.LATD14 = value;
      break;
    case D15:
      LATDbits.LATD15 = value;
      break;
  }
}

int user_switch_pressed() {
    return !PORTCbits.RC13;
}
