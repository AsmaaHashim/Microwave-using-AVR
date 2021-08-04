################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LCD.c \
../keypad.c \
../main.c \
../microWave.c \
../timer0.c \
../timer1.c 

OBJS += \
./LCD.o \
./keypad.o \
./main.o \
./microWave.o \
./timer0.o \
./timer1.o 

C_DEPS += \
./LCD.d \
./keypad.d \
./main.d \
./microWave.d \
./timer0.d \
./timer1.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


