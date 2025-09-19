#include "stm32f10x.h"                  // Device header
void Buzzer_Init(void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    GPIO_InitTypeDef  GPIO_InitStruct_B12;
    GPIO_InitStruct_B12.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct_B12.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStruct_B12.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB,&GPIO_InitStruct_B12);
    GPIO_SetBits(GPIOB,GPIO_Pin_12);
}
void Buzzer_On(void) {
    GPIO_ResetBits(GPIOB,GPIO_Pin_12);
}
void Buzzer_OFF(void) {
    GPIO_SetBits(GPIOB,GPIO_Pin_12);
}
