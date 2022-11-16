################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/timer0_pwm/timer0_pwm.c 

OBJS += \
./MCAL/timer0_pwm/timer0_pwm.o 

C_DEPS += \
./MCAL/timer0_pwm/timer0_pwm.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/timer0_pwm/%.o: ../MCAL/timer0_pwm/%.c MCAL/timer0_pwm/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


