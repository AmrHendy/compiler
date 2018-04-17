################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/SyntaxAnalyzer/GrammerExtractor/GrammerParser.cpp \
../src/SyntaxAnalyzer/GrammerExtractor/Node.cpp \
../src/SyntaxAnalyzer/GrammerExtractor/Production.cpp \
../src/SyntaxAnalyzer/GrammerExtractor/ProductionElement.cpp 

OBJS += \
./src/SyntaxAnalyzer/GrammerExtractor/GrammerParser.o \
./src/SyntaxAnalyzer/GrammerExtractor/Node.o \
./src/SyntaxAnalyzer/GrammerExtractor/Production.o \
./src/SyntaxAnalyzer/GrammerExtractor/ProductionElement.o 

CPP_DEPS += \
./src/SyntaxAnalyzer/GrammerExtractor/GrammerParser.d \
./src/SyntaxAnalyzer/GrammerExtractor/Node.d \
./src/SyntaxAnalyzer/GrammerExtractor/Production.d \
./src/SyntaxAnalyzer/GrammerExtractor/ProductionElement.d 


# Each subdirectory must supply rules for building sources it contributes
src/SyntaxAnalyzer/GrammerExtractor/%.o: ../src/SyntaxAnalyzer/GrammerExtractor/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


