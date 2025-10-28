# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## 常用命令

### 构建
本项目使用 CMake 进行构建。典型的构建流程如下：

1.  **配置项目**:
    ```bash
    cmake -B build
    ```
    这将在 `build` 目录下生成构建文件。

2.  **构建项目**:
    ```bash
    cmake --build build
    ```
    这将编译源代码并生成可执行文件。

## 高层代码架构

本项目是一个基于 **STM32F103C8T6 微控制器** 的嵌入式固件项目。

*   **构建系统**: 使用 **CMake** 进行管理。
*   **配置**: `F103C8T6.ioc` 文件是 **STM32CubeIDE/CubeMX** 项目配置文件，用于配置微控制器外设并生成初始化代码。
*   **核心源代码**: 主要的应用程序逻辑位于 `Core/Src` 目录下的 `main.c`。
    *   `main.c` 负责系统初始化（如时钟配置 `SystemClock_Config()` 和 GPIO 初始化 `MX_GPIO_Init()`）以及主应用程序循环。
    *   目前，`main.c` 的主循环中包含一个简单的 LED 闪烁功能。
*   **驱动**: `Drivers` 目录包含 **STM32Cube HAL (硬件抽象层)** 库，用于与微控制器的硬件外设进行交互。
*   **启动文件**: `startup_stm32f103xb.s` 是微控制器的启动汇编文件。
*   **链接脚本**: `STM32F103XX_FLASH.ld` 是用于将编译后的代码链接到微控制器闪存的链接脚本。

总的来说，这是一个典型的 STM32CubeMX 生成的嵌入式项目，方便开发者在此基础上添加自定义功能。