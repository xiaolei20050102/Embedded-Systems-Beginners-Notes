#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"
int main(void) {
    LED_Init();
    Key_Init();
    //按下按钮1，灯1状态取反，2同理
    while (1) {
        uint16_t keynum = KeyGetNum();
        if (keynum == 1) {
            LED1_Negation();
        }
        if (keynum == 2) {
            LED2_Negation();
        }
    }
}
