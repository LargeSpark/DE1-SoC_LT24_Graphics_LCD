################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Graphics/graphics.c 

C_DEPS += \
./Graphics/graphics.d 

OBJS += \
./Graphics/graphics.o 


# Each subdirectory must supply rules for building sources it contributes
Graphics/%.o: ../Graphics/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 5'
	armcc --cpu=Cortex-A9.no_neon.no_vfp --arm -O0 -g --md --depend_format=unix_escaped --no_depend_system_headers --depend_dir="Graphics" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


