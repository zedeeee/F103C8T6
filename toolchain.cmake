# 设置目标系统信息
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# 指定交叉编译工具链的前缀
set(TOOLCHAIN_PREFIX arm-none-eabi-)

# 指定C、C++和汇编编译器
set(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}g++)
set(CMAKE_ASM_COMPILER ${TOOLCHAIN_PREFIX}gcc)

# 指定链接器和其他二进制工具
set(CMAKE_OBJCOPY ${TOOLCHAIN_PREFIX}objcopy)
set(CMAKE_OBJDUMP ${TOOLCHAIN_PREFIX}objdump)
set(CMAKE_SIZE ${TOOLCHAIN_PREFIX}size)

# 设置编译器标志
# -mcpu=cortex-m3:      指定CPU核心
# -mthumb:              使用Thumb指令集
# -ffunction-sections:  将每个函数放入独立的section，便于链接器优化
# -fdata-sections:      将每个数据项放入独立的section
# -specs=nosys.specs:   使用简化的系统调用存根
set(COMMON_FLAGS "-mcpu=cortex-m3 -mthumb -ffunction-sections -fdata-sections --specs=nosys.specs")
set(CMAKE_C_FLAGS "${COMMON_FLAGS} -std=c11" CACHE INTERNAL "C compiler flags")
set(CMAKE_CXX_FLAGS "${COMMON_fLAGS} -std=c++17" CACHE INTERNAL "C++ compiler flags")
set(CMAKE_ASM_FLAGS "${COMMON_FLAGS}" CACHE INTERNAL "Assembly compiler flags")

# 设置链接器标志
# -Wl,-gc-sections:     移除未使用的section
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--gc-sections" CACHE INTERNAL "Linker flags")

# 设置工具链查找模式
# CMAKE_FIND_ROOT_PATH_MODE_PROGRAM=NEVER: 不在宿主机系统查找程序
# CMAKE_FIND_ROOT_PATH_MODE_LIBRARY=ONLY: 只在目标系统路径查找库
# CMAKE_FIND_ROOT_PATH_MODE_INCLUDE=ONLY: 只在目标系统路径查找头文件
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
