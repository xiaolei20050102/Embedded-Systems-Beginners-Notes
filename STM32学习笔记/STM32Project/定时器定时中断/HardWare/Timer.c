#include "stm32f10x.h"                  // Device header
int16_t timer_num = 60;
void Timer_Init(void) {
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);//TIME2定时器使能
    
    TIM_InternalClockConfig(TIM2);//配置为内部时钟源
    
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;//定义一个定时器时基初始化结构体
    TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;//配置输入捕获滤波器的时钟分频
    TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;//配置计数模式
    TIM_TimeBaseInitStruct.TIM_Period = 10000 - 1;//ARR在0~65535，设置定时器的溢出值
    TIM_TimeBaseInitStruct.TIM_Prescaler = 7200 - 1; //PSC在0~65535
    TIM_TimeBaseInitStruct.TIM_RepetitionCounter = 0;//重复寄存器，高级定时器才有
    TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStruct);//初始化定时器
    
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);//定时器中断使能
    
    TIM_ClearFlag(TIM2,TIM_IT_Update);//手动清除标志位，不然复位初始化后立刻触发中断了。
    
    
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    NVIC_InitTypeDef NVIC_InitStruct;
    NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;//中断通道
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&NVIC_InitStruct);
  
    TIM_Cmd(TIM2,ENABLE);//使能定时器
    
}
uint16_t Timer_GetCount(void) {
    return TIM_GetCounter(TIM2);
}
uint16_t Timer_GetPrescaler(void) {
    return TIM_GetPrescaler(TIM2);
}
uint16_t Timer_Getnum(void) {
    return timer_num;
}
void TIM2_IRQHandler (void) {
    if (TIM_GetITStatus(TIM2,TIM_IT_Update) == SET) {
        timer_num--;
        if (timer_num == -1) timer_num = 60;
        TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
    }
}
