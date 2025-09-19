#include "stm32f10x.h"                  // Device header
uint16_t senser_count = 0;

void ThroughBeamphotoelectricSensor_Init(void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//使能GPIOB外设的时钟
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//使能AFIO时钟
    
    //配置GPIOB_Pin14引脚
    GPIO_InitTypeDef GPIO_InitStruct_B_14;
    GPIO_InitStruct_B_14.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStruct_B_14.GPIO_Pin = GPIO_Pin_14;
    GPIO_InitStruct_B_14.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB,&GPIO_InitStruct_B_14);
    
    //将PB14映射到EXTI14中断线，即选择PB14为外部中断引脚
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);
    
    EXTI_InitTypeDef EXTI_InitStruct;//定义结构体变量
    EXTI_InitStruct.EXTI_Line = EXTI_Line14;//选择配置外部中断的14号线
    EXTI_InitStruct.EXTI_LineCmd = ENABLE;
    EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;//指定外部中断线为 中断模式
    EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;//指定外部中断线为上升沿触发
    EXTI_Init(&EXTI_InitStruct);
    
    
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//配置NVIC中断优先级（分组2：2位抢占优先级，2位子优先级）
    
    NVIC_InitTypeDef NVIC_InitStruct;
    NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;//选择配置NVIC的EXTI15_10线
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;//设置抢占优先级
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;//设置子优先级
    NVIC_Init(&NVIC_InitStruct);//应用配置
      
}
uint16_t ThroughBeamphotoelectricSensor_GetCount(void) {
    return senser_count;
}
void EXTI15_10_IRQHandler (void) {
    if (EXTI_GetITStatus(EXTI_Line14) == SET) {// 确认中断源为EXTI14
        senser_count++;
        EXTI_ClearITPendingBit(EXTI_Line14);//// 必须清除中断标志位！
    }
}
