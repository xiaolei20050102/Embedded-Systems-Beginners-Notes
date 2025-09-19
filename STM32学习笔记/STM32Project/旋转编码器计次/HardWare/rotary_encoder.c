#include "stm32f10x.h"                  // Device header
int16_t count = 0;
void RotaryEncoder_Init() {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB,&GPIO_InitStruct);
    
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource0);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource1);
    
    
    EXTI_InitTypeDef EXTI_InitStruct_0;
    EXTI_InitStruct_0.EXTI_Line = EXTI_Line0;
    EXTI_InitStruct_0.EXTI_LineCmd = ENABLE;
    EXTI_InitStruct_0.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct_0.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_Init(&EXTI_InitStruct_0);
    
    EXTI_InitTypeDef EXTI_InitStruct_1;
    EXTI_InitStruct_1.EXTI_Line = EXTI_Line1;
    EXTI_InitStruct_1.EXTI_LineCmd = ENABLE;
    EXTI_InitStruct_1.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStruct_1.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_Init(&EXTI_InitStruct_1);
    
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    
    
    NVIC_InitTypeDef NVIC_InitStruct_0;
    NVIC_InitStruct_0.NVIC_IRQChannel = EXTI0_IRQn;
    NVIC_InitStruct_0.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct_0.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStruct_0.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&NVIC_InitStruct_0);
    
    NVIC_InitTypeDef NVIC_InitStruct_1;
    NVIC_InitStruct_1.NVIC_IRQChannel = EXTI1_IRQn;
    NVIC_InitStruct_1.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct_1.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStruct_1.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&NVIC_InitStruct_1);    
    
}
int16_t RotaryEncoder_GetCount() {
    int16_t temp = count;
    count = 0;
    return temp;
}
void EXTI0_IRQHandler(void) {
    if (EXTI_GetITStatus(EXTI_Line0) == SET) {
        if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) == 0) {
            count--;
        }
        EXTI_ClearITPendingBit(EXTI_Line0);
    }
}
void EXTI1_IRQHandler(void) {
    if (EXTI_GetITStatus(EXTI_Line1) == SET) {
        if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0) == 0) {
            count++;
        }
        EXTI_ClearITPendingBit(EXTI_Line1);
    }    
}
