#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Timer.h"
int main(void) {
    OLED_Init();
    Timer_Init();
    while (1) {
        OLED_ShowString(1,1,"time:");
        OLED_ShowNum(1,6,Timer_Getnum(),2);
        OLED_ShowString(2,1,"TimeCount:");
        OLED_ShowNum(3,1,Timer_GetCount(),6);
        
//        OLED_ShowString(2,1,"TimePrescaler:");
//        OLED_ShowNum(3,1,Timer_GetPrescaler(),5);
    }
}
