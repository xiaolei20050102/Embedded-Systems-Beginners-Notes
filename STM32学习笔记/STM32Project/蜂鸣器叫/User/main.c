#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main() {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//配置外设时钟
    
    GPIO_InitTypeDef GPIO_InitStruct_B_12;//初始化GPIO结构体
    GPIO_InitStruct_B_12.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct_B_12.GPIO_Pin = GPIO_Pin_12;//可以或起来一起初始化
    GPIO_InitStruct_B_12.GPIO_Speed = GPIO_Speed_50MHz;
    
    GPIO_Init(GPIOB,&GPIO_InitStruct_B_12);
    
    while (1) {
        GPIO_ResetBits(GPIOB,GPIO_Pin_12);
        Delay_ms(500);//休眠500ms
        GPIO_SetBits(GPIOB,GPIO_Pin_12);
        Delay_ms(500);
    }
    
}
