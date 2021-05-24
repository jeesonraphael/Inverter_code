#include<htc.h>

#define _XTAL_FREQ 20000000
#define TMR2PRESCALE 4

long freq;

int PWM_Max_Duty();
void PWM1_Init(long fre);
void PWM2_Init(long fre);
void PWM1_Duty(unsigned int duty);
void PWM2_Duty(unsigned int duty);
void PWM1_Start(void);
void PWM1_Stop(void);
void PWM2_Start(void);
void PWM2_Stop(void);

