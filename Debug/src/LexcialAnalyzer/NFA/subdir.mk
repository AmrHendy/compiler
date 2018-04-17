################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/LexcialAnalyzer/NFA/NFA.cpp \
../src/LexcialAnalyzer/NFA/NFABuilder.cpp 

OBJS += \
./src/LexcialAnalyzer/NFA/NFA.o \
./src/LexcialAnalyzer/NFA/NFABuilder.o 

CPP_DEPS += \
./src/LexcialAnalyzer/NFA/NFA.d \
./src/LexcialAnalyzer/NFA/NFABuilder.d 


# Each subdirectory must supply rules for building sources it contributes
src/LexcialAnalyzer/NFA/%.o: ../src/LexcialAnalyzer/NFA/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


