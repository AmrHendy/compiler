################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/LexcialAnalyzer/MachineStructure/CompositeState.cpp \
../src/LexcialAnalyzer/MachineStructure/Machine.cpp \
../src/LexcialAnalyzer/MachineStructure/Partition.cpp \
../src/LexcialAnalyzer/MachineStructure/Row.cpp \
../src/LexcialAnalyzer/MachineStructure/State.cpp \
../src/LexcialAnalyzer/MachineStructure/TransitionTable.cpp 

OBJS += \
./src/LexcialAnalyzer/MachineStructure/CompositeState.o \
./src/LexcialAnalyzer/MachineStructure/Machine.o \
./src/LexcialAnalyzer/MachineStructure/Partition.o \
./src/LexcialAnalyzer/MachineStructure/Row.o \
./src/LexcialAnalyzer/MachineStructure/State.o \
./src/LexcialAnalyzer/MachineStructure/TransitionTable.o 

CPP_DEPS += \
./src/LexcialAnalyzer/MachineStructure/CompositeState.d \
./src/LexcialAnalyzer/MachineStructure/Machine.d \
./src/LexcialAnalyzer/MachineStructure/Partition.d \
./src/LexcialAnalyzer/MachineStructure/Row.d \
./src/LexcialAnalyzer/MachineStructure/State.d \
./src/LexcialAnalyzer/MachineStructure/TransitionTable.d 


# Each subdirectory must supply rules for building sources it contributes
src/LexcialAnalyzer/MachineStructure/%.o: ../src/LexcialAnalyzer/MachineStructure/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


