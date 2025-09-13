#include "stm32f10x.h"                  // Device header
int main() {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
    GPIO_InitTypeDef GPIO_InitStruct_GPIO_C_13;
    GPIO_InitStruct_GPIO_C_13.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStruct_GPIO_C_13.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct_GPIO_C_13.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC,&GPIO_InitStruct_GPIO_C_13);//GPIOC本身就是一个指针常量，不需取地址
    //GPIO_SetBits(GPIOC,GPIO_Pin_13);
    GPIO_ResetBits(GPIOC,GPIO_Pin_13);
    while (1) {
        
    }
}
