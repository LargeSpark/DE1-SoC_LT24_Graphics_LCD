################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Report/testcode.cpp 

OBJS += \
./Report/testcode.o 

CPP_DEPS += \
./Report/testcode.d 


# Each subdirectory must supply rules for building sources it contributes
Report/%.o: ../Report/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler 5'
	armcc --cpu=Cortex-A9.no_neon.no_vfp --arm -O0 -g --md --depend_format=unix_escaped --no_depend_system_headers --depend_dir="Report" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


