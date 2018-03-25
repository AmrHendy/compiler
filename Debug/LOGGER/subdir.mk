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
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


