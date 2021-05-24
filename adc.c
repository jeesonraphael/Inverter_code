#include "adc.h"

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

