#include<htc.h>
#include<pic.h>

#define _XTAL_FREQ 8000000

void ADC_Init()
{
  ADCON0 = 0x41; //ADC Module Turned ON and Clock is selected
  ADCON1 = 0xC0; //All pins as Analog Input
                 //With reference voltages VDD and VSS
}

unsigned int ADC_Read(unsigned char channel)
{
  if(channel > 7) //If Invalid channel selected 
    return 0;     //Return 0

  ADCON0 &= 0xC5; //Clearing the Channel Selection Bits
  ADCON0 |= channel<<3; //Setting the required Bits
  __delay_ms(2); //Acquisition time to charge hold capacitor
  GO_nDONE = 1; //Initializes A/D Conversion
  while(GO_nDONE); //Wait for A/D Conversion to complete
  return ((ADRESH<<8)+ADRESL); //Returns Result
}

void main()
{
  unsigned int a;
  TRISB = 0x00; //PORTB as output
  TRISC = 0x00; //PORTC as output
  TRISA = 0xFF; //PORTA as input
  ADC_Init(); //Initializes ADC Module

  do
  {
    a = ADC_Read(0); //Reading Analog Channel 0
    PORTB = a; //Lower 8 bits to PORTB
    PORTC = a>>8; //Higher 2 bits to PORTC
    __delay_ms(100); //Delay
  }while(1); //Infinite Loop
}
