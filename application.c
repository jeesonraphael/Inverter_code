#include "adc.h"
#include "pwm.h"



void main()
{
  unsigned int a;
  TRISB = 0x00; //PORTB as output
  TRISC = 0x00; //PORTC as output
  TRISA = 0xFF; //PORTA as input
  ADC_Init(); //Initializes ADC Module
  /*-------------------------------------adc section------------------------------*/
  
  
  unsigned int i=0,j=0;
  PWM1_Init(5000);
  PWM2_Init(5000);
  TRISD = 0xFF;
  PWM1_Duty(0);
  PWM2_Duty(0);
  PWM1_Start();
  PWM2_Start();
  
  
  

  do
  {
    a = ADC_Read(0); //Reading Analog Channel 0
    PORTB = a; //Lower 8 bits to PORTB
    PORTC = a>>8; //Higher 2 bits to PORTC

    /*------------------------------adc section---------------------------------------*/
    
    if(RD0 == 0 && i<1000)
      i=i+10;
    if(RD1 == 0 && i>0)
      i=i-10;
    if(RD2 == 0 && j<1000)
      j=j+10;
    if(RD3 == 0 && j>0)
      j=j-10;
    PWM1_Duty(i);
    PWM2_Duty(j);

	
    __delay_ms(100); //Delay

    
  }while(1); //Infinite Loop
  
  
}
