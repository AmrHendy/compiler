################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/LexcialAnalyzer/DFA/DFAMachine.cpp \
../src/LexcialAnalyzer/DFA/DFATableBuilder.cpp \
../src/LexcialAnalyzer/DFA/DfaTableMin.cpp 

OBJS += \
./src/LexcialAnalyzer/DFA/DFAMachine.o \
./src/LexcialAnalyzer/DFA/DFATableBuilder.o \
./src/LexcialAnalyzer/DFA/DfaTableMin.o 

CPP_DEPS += \
./src/LexcialAnalyzer/DFA/DFAMachine.d \
./src/LexcialAnalyzer/DFA/DFATableBuilder.d \
./src/LexcialAnalyzer/DFA/DfaTableMin.d 


# Each subdirectory must supply rules for building sources it contributes
src/LexcialAnalyzer/DFA/%.o: ../src/LexcialAnalyzer/DFA/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


