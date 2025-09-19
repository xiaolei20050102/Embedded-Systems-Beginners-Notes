#include "stm32f10x.h"                  // Device header
void LED_Init (void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStruct_A1_A2;
    GPIO_InitStruct_A1_A2.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct_A1_A2.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
    GPIO_InitStruct_A1_A2.GPIO_Speed = GPIO_Speed_50MHz;
    
    GPIO_Init(GPIOA,&GPIO_InitStruct_A1_A2);
    
    GPIO_SetBits(GPIOA,GPIO_Pin_1);
    GPIO_SetBits(GPIOA,GPIO_Pin_2);
}

void LED1_ON(void) {
   GPIO_ResetBits(GPIOA,GPIO_Pin_1);
}

void LED1_OFF(void) {
    GPIO_SetBits(GPIOA,GPIO_Pin_1);
}

void LED2_ON(void) {
    GPIO_ResetBits(GPIOA,GPIO_Pin_2);
}
void LED2_OFF(void) {
    GPIO_SetBits(GPIOA,GPIO_Pin_2);
}

//LED1的状态取反
void LED1_Negation(void) {
    if (GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_1) == 0) {
        GPIO_SetBits(GPIOA,GPIO_Pin_1);
    }
    else if (GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_1) == 1) {
        GPIO_ResetBits(GPIOA,GPIO_Pin_1);
    }
}
//LED2的状态取反
void LED2_Negation(void) {
    if (GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_2) == 0) {
        GPIO_SetBits(GPIOA,GPIO_Pin_2);
    }
    else if (GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_2) == 1) {
        GPIO_ResetBits(GPIOA,GPIO_Pin_2);
    }
}

