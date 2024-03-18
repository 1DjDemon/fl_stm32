################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/gps_neo6/gps_neo6.c 

OBJS += \
./Core/gps_neo6/gps_neo6.o 

C_DEPS += \
./Core/gps_neo6/gps_neo6.d 


# Each subdirectory must supply rules for building sources it contributes
Core/gps_neo6/%.o Core/gps_neo6/%.su Core/gps_neo6/%.cyclo: ../Core/gps_neo6/%.c Core/gps_neo6/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I"../Core/ssd1306" -I"../Core/gps_neo6" -I../Core/ds1307 -I"../Core/bme280" -O1 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-gps_neo6

clean-Core-2f-gps_neo6:
	-$(RM) ./Core/gps_neo6/gps_neo6.cyclo ./Core/gps_neo6/gps_neo6.d ./Core/gps_neo6/gps_neo6.o ./Core/gps_neo6/gps_neo6.su

.PHONY: clean-Core-2f-gps_neo6

