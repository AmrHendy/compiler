################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/LexcialAnalyzer/NFA/NFAOperators/AndOperator.cpp \
../src/LexcialAnalyzer/NFA/NFAOperators/KleeneClosureOperator.cpp \
../src/LexcialAnalyzer/NFA/NFAOperators/OrOperator.cpp \
../src/LexcialAnalyzer/NFA/NFAOperators/PositiveClosureOperator.cpp 

OBJS += \
./src/LexcialAnalyzer/NFA/NFAOperators/AndOperator.o \
./src/LexcialAnalyzer/NFA/NFAOperators/KleeneClosureOperator.o \
./src/LexcialAnalyzer/NFA/NFAOperators/OrOperator.o \
./src/LexcialAnalyzer/NFA/NFAOperators/PositiveClosureOperator.o 

CPP_DEPS += \
./src/LexcialAnalyzer/NFA/NFAOperators/AndOperator.d \
./src/LexcialAnalyzer/NFA/NFAOperators/KleeneClosureOperator.d \
./src/LexcialAnalyzer/NFA/NFAOperators/OrOperator.d \
./src/LexcialAnalyzer/NFA/NFAOperators/PositiveClosureOperator.d 


# Each subdirectory must supply rules for building sources it contributes
src/LexcialAnalyzer/NFA/NFAOperators/%.o: ../src/LexcialAnalyzer/NFA/NFAOperators/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


