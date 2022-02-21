################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../Dio_Prog.c \
../EEPROM_INIT.c \
../I2C_Prog.c \
../button.c \
../main.c \
../segment.c \
../timer0_prog.c \
../timer1_prog.c \
../timer2_prog.c 

OBJS += \
./ADC.o \
./Dio_Prog.o \
./EEPROM_INIT.o \
./I2C_Prog.o \
./button.o \
./main.o \
./segment.o \
./timer0_prog.o \
./timer1_prog.o \
./timer2_prog.o 

C_DEPS += \
./ADC.d \
./Dio_Prog.d \
./EEPROM_INIT.d \
./I2C_Prog.d \
./button.d \
./main.d \
./segment.d \
./timer0_prog.d \
./timer1_prog.d \
./timer2_prog.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


