################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/ds1307/ds1307_for_stm32_hal.c 

OBJS += \
./Core/ds1307/ds1307_for_stm32_hal.o 

C_DEPS += \
./Core/ds1307/ds1307_for_stm32_hal.d 


# Each subdirectory must supply rules for building sources it contributes
Core/ds1307/%.o Core/ds1307/%.su Core/ds1307/%.cyclo: ../Core/ds1307/%.c Core/ds1307/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I"../Core/ssd1306" -I"../Core/gps_neo6" -I../Core/ds1307 -I"../Core/bme280" -O1 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-ds1307

clean-Core-2f-ds1307:
	-$(RM) ./Core/ds1307/ds1307_for_stm32_hal.cyclo ./Core/ds1307/ds1307_for_stm32_hal.d ./Core/ds1307/ds1307_for_stm32_hal.o ./Core/ds1307/ds1307_for_stm32_hal.su

.PHONY: clean-Core-2f-ds1307

