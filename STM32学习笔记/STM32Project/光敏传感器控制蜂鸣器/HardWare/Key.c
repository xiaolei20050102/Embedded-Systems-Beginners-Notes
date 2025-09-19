#include "stm32f10x.h"                  // Device header
#include "Delay.h"
void Key_Init(void) {
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStruct_B1_B11;
    GPIO_InitStruct_B1_B11.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStruct_B1_B11.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_11;
    GPIO_InitStruct_B1_B11.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB,&GPIO_InitStruct_B1_B11);
    
}

uint8_t KeyGetNum(void) {
     //uint8_t num = 0;
    //GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1);
    //num2 = GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11);
      
     if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) == 0) {//如果按下（输入低电位）
         Delay_ms(20);//按下消抖
         
         
         //原代码的 while会强制等待用户松手，确保一次按下只触发一次。
        //去掉后，用户按住不放时，外层循环会持续收到键值，无法实现“按下-松开才算一次”的逻辑。
         while (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) == 0);//堵塞，防止主函数循环给带走了。
         Delay_ms(20);//松手消抖
         return 1;//返回1证明按键1按下过
     }
     if (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11) == 0) {
         Delay_ms(20);
         while (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11) == 0);
         Delay_ms(20);
         return 2;
     }
     return 0;
}

