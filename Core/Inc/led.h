#ifndef __LED_H
#define __LED_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 初始化LED所使用的硬件资源 (GPIO)。
 * @param None
 * @retval None
 */
void led_init(void);

/**
 * @brief 设置LED的亮度。
 * @param brightness 亮度值 (0-255)，0为完全熄灭，255为最亮。
 * @retval None
 */
void led_set_brightness(uint8_t brightness);

#ifdef __cplusplus
}
#endif

#endif /* __LED_H */
