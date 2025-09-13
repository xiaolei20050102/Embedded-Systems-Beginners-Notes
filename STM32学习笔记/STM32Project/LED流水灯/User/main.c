#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main() {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//配置外设时钟
    
    GPIO_InitTypeDef GPIO_InitStruct_A_0_1_2_3;//初始化GPIO结构体
    GPIO_InitStruct_A_0_1_2_3.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct_A_0_1_2_3.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;//可以或起来一起初始化
    GPIO_InitStruct_A_0_1_2_3.GPIO_Speed = GPIO_Speed_50MHz;
    
    GPIO_Init(GPIOA,&GPIO_InitStruct_A_0_1_2_3);
    
    while (1) {
        
        GPIO_ResetBits(GPIOA,GPIO_Pin_0);
        Delay_ms(50);//休眠500ms
        GPIO_SetBits(GPIOA,GPIO_Pin_0);
        Delay_ms(50);
        
        
        GPIO_ResetBits(GPIOA,GPIO_Pin_1);
        Delay_ms(50);//休眠500ms
        GPIO_SetBits(GPIOA,GPIO_Pin_1);
        Delay_ms(50);

        GPIO_ResetBits(GPIOA,GPIO_Pin_2);
        Delay_ms(50);//休眠500ms
        GPIO_SetBits(GPIOA,GPIO_Pin_2);
        Delay_ms(50);

        GPIO_ResetBits(GPIOA,GPIO_Pin_3);
        Delay_ms(50);//休眠500ms
        GPIO_SetBits(GPIOA,GPIO_Pin_3);
        Delay_ms(50);       
    }
    
}
