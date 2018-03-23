################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Alpha.cpp \
../src/AndOperator.cpp \
../src/CompositeState.cpp \
../src/DFAMachine.cpp \
../src/DFATableBuilder.cpp \
../src/FileHandler.cpp \
../src/KeyWordRule.cpp \
../src/KleeneClosureOperator.cpp \
../src/Machine.cpp \
../src/Main.cpp \
../src/NFA.cpp \
../src/NFABuilder.cpp \
../src/NumberGenerator.cpp \
../src/OrOperator.cpp \
../src/Partition.cpp \
../src/PatternProcessor.cpp \
../src/PositiveClosureOperator.cpp \
../src/PostfixExpressionHandler.cpp \
../src/PunctuationRule.cpp \
../src/RegularRule.cpp \
../src/Row.cpp \
../src/Rule.cpp \
../src/RuleElement.cpp \
../src/RuleExtractor.cpp \
../src/State.cpp \
../src/Token.cpp \
../src/Tokenizer.cpp \
../src/TransitionTable.cpp 

OBJS += \
./src/Alpha.o \
./src/AndOperator.o \
./src/CompositeState.o \
./src/DFAMachine.o \
./src/DFATableBuilder.o \
./src/FileHandler.o \
./src/KeyWordRule.o \
./src/KleeneClosureOperator.o \
./src/Machine.o \
./src/Main.o \
./src/NFA.o \
./src/NFABuilder.o \
./src/NumberGenerator.o \
./src/OrOperator.o \
./src/Partition.o \
./src/PatternProcessor.o \
./src/PositiveClosureOperator.o \
./src/PostfixExpressionHandler.o \
./src/PunctuationRule.o \
./src/RegularRule.o \
./src/Row.o \
./src/Rule.o \
./src/RuleElement.o \
./src/RuleExtractor.o \
./src/State.o \
./src/Token.o \
./src/Tokenizer.o \
./src/TransitionTable.o 

CPP_DEPS += \
./src/Alpha.d \
./src/AndOperator.d \
./src/CompositeState.d \
./src/DFAMachine.d \
./src/DFATableBuilder.d \
./src/FileHandler.d \
./src/KeyWordRule.d \
./src/KleeneClosureOperator.d \
./src/Machine.d \
./src/Main.d \
./src/NFA.d \
./src/NFABuilder.d \
./src/NumberGenerator.d \
./src/OrOperator.d \
./src/Partition.d \
./src/PatternProcessor.d \
./src/PositiveClosureOperator.d \
./src/PostfixExpressionHandler.d \
./src/PunctuationRule.d \
./src/RegularRule.d \
./src/Row.d \
./src/Rule.d \
./src/RuleElement.d \
./src/RuleExtractor.d \
./src/State.d \
./src/Token.d \
./src/Tokenizer.d \
./src/TransitionTable.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


