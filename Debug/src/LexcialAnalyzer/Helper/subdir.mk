################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/LexcialAnalyzer/Helper/Alpha.cpp \
../src/LexcialAnalyzer/Helper/NumberGenerator.cpp 

OBJS += \
./src/LexcialAnalyzer/Helper/Alpha.o \
./src/LexcialAnalyzer/Helper/NumberGenerator.o 

CPP_DEPS += \
./src/LexcialAnalyzer/Helper/Alpha.d \
./src/LexcialAnalyzer/Helper/NumberGenerator.d 


# Each subdirectory must supply rules for building sources it contributes
src/LexcialAnalyzer/Helper/%.o: ../src/LexcialAnalyzer/Helper/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


