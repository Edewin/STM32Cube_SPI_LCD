################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c 

OBJS += \
./Drivers/CMSIS/system_stm32f4xx.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32f4xx.o: /home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))" -DUSE_HAL_DRIVER -DSTM32F401xE -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Inc" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/CMSIS/Include" -I"/home/edutzu-ubuntu/workspace/STM32/STM32Cube_SPI_LCD/againWithLCD/Drivers/CMSIS/Device/ST/STM32F4xx/Include"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


