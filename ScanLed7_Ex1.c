#include <AT89X52.h>

#define LED7_DATA_PORT           P0
#define LED7_CTRL_PORT           P2

#define LED7_DISABLE_ALL        0xF0
#define LED7_DIG1_ENABLE        0x70
#define LED7_DIG2_ENABLE        0xB0
#define LED7_DIG3_ENABLE        0xD0
#define LED7_DIG4_ENABLE        0xE0

/** Led 7 Data                   0     1     2     3     4     5     6     7     8     9   */
unsigned char u8ArrLed7[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};



void Delay_Ms(unsigned int time);
void Led7_CtrlPower(unsigned char u8Status);

void main(void)
{
    unsigned char u8Cnt=0;
    

	while(1)
	{
        /** Step 1: 1st led display number 6*/
        Led7_CtrlPower(LED7_DISABLE_ALL);           //turn off all led
        LED7_DATA_PORT = u8ArrLed7[6];
        Led7_CtrlPower(LED7_DIG1_ENABLE);           // turn on 1st led 
        Delay_Ms(5);
        /** Step 2: 2nd led display number 7*/
        Led7_CtrlPower(LED7_DISABLE_ALL);           //turn off all led
        LED7_DATA_PORT = u8ArrLed7[7];
        Led7_CtrlPower(LED7_DIG2_ENABLE);           // turn on 2nd led 
        Delay_Ms(5);
        /** Step 3: 3rd led display number 8*/
        Led7_CtrlPower(LED7_DISABLE_ALL);           //turn off all led
        LED7_DATA_PORT = u8ArrLed7[8];
        Led7_CtrlPower(LED7_DIG3_ENABLE);           // turn on 3rd led 
        Delay_Ms(5);
        /** Step 4: 4th led display number 9*/
        Led7_CtrlPower(LED7_DISABLE_ALL);           //turn off all led
        LED7_DATA_PORT = u8ArrLed7[9];
        Led7_CtrlPower(LED7_DIG4_ENABLE);           // turn on 4th led 
        Delay_Ms(5);
	}
}


/** Delay */
void Delay_Ms(unsigned int time)
{
    unsigned int i,j;
    
    for(i=0;i<time;i++)
    {
        for(j=0;j<125;j++);
    }
}

void Led7_CtrlPower(unsigned char u8Status)
{
    unsigned char u8PortValue;
    
    u8PortValue = LED7_CTRL_PORT & 0x0F;
    
    LED7_CTRL_PORT = (u8Status | u8PortValue);
}











