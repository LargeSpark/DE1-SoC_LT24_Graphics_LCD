################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Timer/Timer.c 

C_DEPS += \
./Timer/Timer.d 

OBJS += \
./Timer/Timer.o 


# Each subdirectory must supply rules for building sources it contributes
Timer/%.o: ../Timer/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 5'
	armcc --cpu=Cortex-A9.no_neon.no_vfp --arm -O0 -g --md --depend_format=unix_escaped --no_depend_system_headers --depend_dir="Timer" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


