#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
int main(void) {
    OLED_Init();
    while (1) {
        OLED_ShowChar(1,1,'a');
        OLED_ShowString(2,1,"hello world");
    }
}
