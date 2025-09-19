#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "photoelectric_sensor.h"
#include "Buzzer.h"
int main(void) {
    Photoelectric_Sensor_Init();
    Buzzer_Init();
    while (1) {
 
       if (Photoelectric_Sensor_Getnum() == 0) {
           Delay_ms(50);
            Buzzer_On();
           Delay_ms(50);
           
       }
       else if (Photoelectric_Sensor_Getnum() == 1) {
           Delay_ms(50);
           Buzzer_OFF();
           Delay_ms(50);
       }
        
    }
}
