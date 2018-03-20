################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/FileHandler.cpp \
../src/KeyWordRule.cpp \
../src/Main.cpp \
../src/PatternProcessor.cpp \
../src/PostfixExpressionHandler.cpp \
../src/PunctuationRule.cpp \
../src/RegularRule.cpp \
../src/Rule.cpp \
../src/RuleElement.cpp \
../src/RuleExtractor.cpp 

OBJS += \
./src/FileHandler.o \
./src/KeyWordRule.o \
./src/Main.o \
./src/PatternProcessor.o \
./src/PostfixExpressionHandler.o \
./src/PunctuationRule.o \
./src/RegularRule.o \
./src/Rule.o \
./src/RuleElement.o \
./src/RuleExtractor.o 

CPP_DEPS += \
./src/FileHandler.d \
./src/KeyWordRule.d \
./src/Main.d \
./src/PatternProcessor.d \
./src/PostfixExpressionHandler.d \
./src/PunctuationRule.d \
./src/RegularRule.d \
./src/Rule.d \
./src/RuleElement.d \
./src/RuleExtractor.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


