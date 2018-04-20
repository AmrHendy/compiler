################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Tester/Tester.cpp 

OBJS += \
./src/Tester/Tester.o 

CPP_DEPS += \
./src/Tester/Tester.d 


# Each subdirectory must supply rules for building sources it contributes
src/Tester/%.o: ../src/Tester/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


