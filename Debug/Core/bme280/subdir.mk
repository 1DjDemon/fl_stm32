################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/BME280/BME280.c 

OBJS += \
./Core/BME280/BME280.o 

C_DEPS += \
./Core/BME280/BME280.d 


# Each subdirectory must supply rules for building sources it contributes
Core/BME280/%.o Core/BME280/%.su Core/BME280/%.cyclo: ../Core/BME280/%.c Core/BME280/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I"../Core/ssd1306" -I"../Core/gps_neo6" -I../Core/ds1307 -I"../Core/BME280" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-BME280

clean-Core-2f-BME280:
	-$(RM) ./Core/BME280/BME280.cyclo ./Core/BME280/BME280.d ./Core/BME280/BME280.o ./Core/BME280/BME280.su

.PHONY: clean-Core-2f-BME280

