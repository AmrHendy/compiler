################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../LOGGER/Logger.cpp \
../LOGGER/logger_tester.cpp 

OBJS += \
./LOGGER/Logger.o \
./LOGGER/logger_tester.o 

CPP_DEPS += \
./LOGGER/Logger.d \
./LOGGER/logger_tester.d 


# Each subdirectory must supply rules for building sources it contributes
LOGGER/%.o: ../LOGGER/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


