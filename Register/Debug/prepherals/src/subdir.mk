################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../prepherals/src/clock.c 

OBJS += \
./prepherals/src/clock.o 

C_DEPS += \
./prepherals/src/clock.d 


# Each subdirectory must supply rules for building sources it contributes
prepherals/src/%.o prepherals/src/%.su prepherals/src/%.cyclo: ../prepherals/src/%.c prepherals/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429xx -c -I../Inc -I"C:/Users/Ali/Desktop/Register/CMSIS/Include" -I"C:/Users/Ali/Desktop/Register/Inc" -I"C:/Users/Ali/Desktop/Register/Register/Inc" -I"C:/Users/Ali/Desktop/Register/CMSIS/Include" -I"C:/Users/Ali/Desktop/Register/perepherals/inc" -I"C:/Users/Ali/Desktop/Register/prepherals/inc" -I"C:/Users/Ali/Desktop/Register/CMSIS/Device/ST/STM32F4xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-prepherals-2f-src

clean-prepherals-2f-src:
	-$(RM) ./prepherals/src/clock.cyclo ./prepherals/src/clock.d ./prepherals/src/clock.o ./prepherals/src/clock.su

.PHONY: clean-prepherals-2f-src

