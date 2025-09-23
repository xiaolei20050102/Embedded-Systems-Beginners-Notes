#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "rotary_encoder.h"
int main(void) {
    OLED_Init();
    RotaryEncoder_Init();
    int16_t sum = 0;
    
    while (1) {
        OLED_ShowString(1,1,"Count:");
        OLED_ShowNum(1,7,sum += RotaryEncoder_GetCount(),3);
    }
}
