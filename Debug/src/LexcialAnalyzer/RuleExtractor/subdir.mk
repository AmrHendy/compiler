################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/LexcialAnalyzer/RuleExtractor/KeyWordRule.cpp \
../src/LexcialAnalyzer/RuleExtractor/PatternProcessor.cpp \
../src/LexcialAnalyzer/RuleExtractor/PostfixExpressionHandler.cpp \
../src/LexcialAnalyzer/RuleExtractor/PunctuationRule.cpp \
../src/LexcialAnalyzer/RuleExtractor/RegularRule.cpp \
../src/LexcialAnalyzer/RuleExtractor/Rule.cpp \
../src/LexcialAnalyzer/RuleExtractor/RuleElement.cpp \
../src/LexcialAnalyzer/RuleExtractor/RuleExtractor.cpp 

OBJS += \
./src/LexcialAnalyzer/RuleExtractor/KeyWordRule.o \
./src/LexcialAnalyzer/RuleExtractor/PatternProcessor.o \
./src/LexcialAnalyzer/RuleExtractor/PostfixExpressionHandler.o \
./src/LexcialAnalyzer/RuleExtractor/PunctuationRule.o \
./src/LexcialAnalyzer/RuleExtractor/RegularRule.o \
./src/LexcialAnalyzer/RuleExtractor/Rule.o \
./src/LexcialAnalyzer/RuleExtractor/RuleElement.o \
./src/LexcialAnalyzer/RuleExtractor/RuleExtractor.o 

CPP_DEPS += \
./src/LexcialAnalyzer/RuleExtractor/KeyWordRule.d \
./src/LexcialAnalyzer/RuleExtractor/PatternProcessor.d \
./src/LexcialAnalyzer/RuleExtractor/PostfixExpressionHandler.d \
./src/LexcialAnalyzer/RuleExtractor/PunctuationRule.d \
./src/LexcialAnalyzer/RuleExtractor/RegularRule.d \
./src/LexcialAnalyzer/RuleExtractor/Rule.d \
./src/LexcialAnalyzer/RuleExtractor/RuleElement.d \
./src/LexcialAnalyzer/RuleExtractor/RuleExtractor.d 


# Each subdirectory must supply rules for building sources it contributes
src/LexcialAnalyzer/RuleExtractor/%.o: ../src/LexcialAnalyzer/RuleExtractor/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


