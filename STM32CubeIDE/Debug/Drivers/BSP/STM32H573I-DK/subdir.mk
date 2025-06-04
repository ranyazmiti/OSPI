################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/STM32H573I-DK/stm32h573i_discovery_xspi.c 

OBJS += \
./Drivers/BSP/STM32H573I-DK/stm32h573i_discovery_xspi.o 

C_DEPS += \
./Drivers/BSP/STM32H573I-DK/stm32h573i_discovery_xspi.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32H573I-DK/%.o Drivers/BSP/STM32H573I-DK/%.su Drivers/BSP/STM32H573I-DK/%.cyclo: ../Drivers/BSP/STM32H573I-DK/%.c Drivers/BSP/STM32H573I-DK/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H573xx -c -I../../littlefs-2.10.2 -I../../Drivers/BSP -I../../Core/Inc -I../../Drivers/STM32H5xx_HAL_Driver/Inc -I../../Drivers/STM32H5xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H5xx/Include -I../../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STM32H573I-2d-DK

clean-Drivers-2f-BSP-2f-STM32H573I-2d-DK:
	-$(RM) ./Drivers/BSP/STM32H573I-DK/stm32h573i_discovery_xspi.cyclo ./Drivers/BSP/STM32H573I-DK/stm32h573i_discovery_xspi.d ./Drivers/BSP/STM32H573I-DK/stm32h573i_discovery_xspi.o ./Drivers/BSP/STM32H573I-DK/stm32h573i_discovery_xspi.su

.PHONY: clean-Drivers-2f-BSP-2f-STM32H573I-2d-DK

