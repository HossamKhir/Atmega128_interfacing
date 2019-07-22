################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/src/LCD.c \
../HAL/src/ultrasonic.c 

OBJS += \
./HAL/src/LCD.o \
./HAL/src/ultrasonic.o 

C_DEPS += \
./HAL/src/LCD.d \
./HAL/src/ultrasonic.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/src/%.o: ../HAL/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega128 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


