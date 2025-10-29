#include "led.h"
#include "main.h" // 包含此文件以获取HAL库定义和GPIO引脚定义

// --- 模块私有定义 ---

// 软件PWM的分辨率
#define SW_PWM_RESOLUTION   256
// 软件PWM中用于稳定频率的忙等待循环次数
#define SW_PWM_DELAY_CYCLES 5

/**
 * @brief 初始化LED所使用的硬件资源 (GPIO)。
 * @details 此函数专门负责板载LED (PC13)引脚的初始化。
 * @param None
 * @retval None
 */
void led_init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  // 使能LED所连接的GPIO端口时钟
  __HAL_RCC_GPIOC_CLK_ENABLE();

  // 配置GPIO引脚：LED_SYS_Pin (PC13)
  GPIO_InitStruct.Pin = LED_SYS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD; // 开漏输出
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_SYS_GPIO_Port, &GPIO_InitStruct);

  // 初始化后默认将引脚设置为高电平 (LED熄灭)
  HAL_GPIO_WritePin(LED_SYS_GPIO_Port, LED_SYS_Pin, GPIO_PIN_SET);
}

/**
 * @brief 设置LED的亮度。
 * @details 通过软件PWM实现。在一个短暂的周期内，根据亮度值控制LED亮灭时间的比例。
 *          这是一个阻塞式的低效实现。
 * @param brightness 亮度值 (0-255)。
 * @retval None
 */
void led_set_brightness(uint8_t brightness)
{
  for (int i = 0; i < SW_PWM_RESOLUTION; i++)
  {
    if (i < brightness)
    {
      // LED亮 (低电平有效)
      HAL_GPIO_WritePin(LED_SYS_GPIO_Port, LED_SYS_Pin, GPIO_PIN_RESET);
    }
    else
    {
      // LED灭 (高电平有效)
      HAL_GPIO_WritePin(LED_SYS_GPIO_Port, LED_SYS_Pin, GPIO_PIN_SET);
    }
    // 短暂忙等待以设定PWM频率。这个值需要微调以达到无闪烁的效果。
    for (volatile int d = 0; d < 30; d++);
  }
}
