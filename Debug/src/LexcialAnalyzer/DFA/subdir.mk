################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/LexcialAnalyzer/DFA/DFAMachine.cpp \
../src/LexcialAnalyzer/DFA/DFATableBuilder.cpp 

OBJS += \
./src/LexcialAnalyzer/DFA/DFAMachine.o \
./src/LexcialAnalyzer/DFA/DFATableBuilder.o 

CPP_DEPS += \
./src/LexcialAnalyzer/DFA/DFAMachine.d \
./src/LexcialAnalyzer/DFA/DFATableBuilder.d 


# Each subdirectory must supply rules for building sources it contributes
src/LexcialAnalyzer/DFA/%.o: ../src/LexcialAnalyzer/DFA/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


