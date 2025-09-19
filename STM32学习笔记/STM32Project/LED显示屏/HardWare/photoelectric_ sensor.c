#include "stm32f10x.h"                  // Device header
void Photoelectric_Sensor_Init (void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStruct_B13;
    GPIO_InitStruct_B13.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStruct_B13.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStruct_B13.GPIO_Speed = GPIO_Speed_50MHz;
    
    GPIO_Init(GPIOB,&GPIO_InitStruct_B13);
    
}
//有光输入低电位
uint8_t Photoelectric_Sensor_Getnum(void) {
  return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13);
}
