################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Src/freertos.c \
../Application/User/ili9341.c \
/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Src/main.c \
/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Src/stm32f4xx_hal_msp.c \
/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Src/stm32f4xx_hal_timebase_TIM.c \
/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Src/stm32f4xx_it.c 

OBJS += \
./Application/User/freertos.o \
./Application/User/ili9341.o \
./Application/User/main.o \
./Application/User/stm32f4xx_hal_msp.o \
./Application/User/stm32f4xx_hal_timebase_TIM.o \
./Application/User/stm32f4xx_it.o 

C_DEPS += \
./Application/User/freertos.d \
./Application/User/ili9341.d \
./Application/User/main.d \
./Application/User/stm32f4xx_hal_msp.d \
./Application/User/stm32f4xx_hal_timebase_TIM.d \
./Application/User/stm32f4xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/freertos.o: /home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Src/freertos.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Inc" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/CMSIS/Include" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/CMSIS/Device/ST/STM32F4xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/%.o: ../Application/User/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Inc" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/CMSIS/Include" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/CMSIS/Device/ST/STM32F4xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/main.o: /home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Inc" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/CMSIS/Include" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/CMSIS/Device/ST/STM32F4xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f4xx_hal_msp.o: /home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Src/stm32f4xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Inc" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/CMSIS/Include" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/CMSIS/Device/ST/STM32F4xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f4xx_hal_timebase_TIM.o: /home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Src/stm32f4xx_hal_timebase_TIM.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Inc" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/CMSIS/Include" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/CMSIS/Device/ST/STM32F4xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f4xx_it.o: /home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Src/stm32f4xx_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Inc" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/CMSIS/Include" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/CMSIS/Device/ST/STM32F4xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


