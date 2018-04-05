################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DFA/DFAMachine.cpp \
../DFA/DFATableBuilder.cpp \
../DFA/DfaTableMin.cpp 

OBJS += \
./DFA/DFAMachine.o \
./DFA/DFATableBuilder.o \
./DFA/DfaTableMin.o 

CPP_DEPS += \
./DFA/DFAMachine.d \
./DFA/DFATableBuilder.d \
./DFA/DfaTableMin.d 


# Each subdirectory must supply rules for building sources it contributes
DFA/%.o: ../DFA/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


