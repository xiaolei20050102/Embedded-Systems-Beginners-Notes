#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "through_beam_photoelectric_sensor.h"
int main(void) {
    OLED_Init();
    ThroughBeamphotoelectricSensor_Init();
    while (1) {
        OLED_ShowString(1,1,"Count:");
        OLED_ShowNum(1,7,ThroughBeamphotoelectricSensor_GetCount(),3);
    }
}
