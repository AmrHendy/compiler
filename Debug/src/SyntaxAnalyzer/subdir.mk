################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/SyntaxAnalyzer/SyntaxAnalyzer.cpp \
../src/SyntaxAnalyzer/SyntaxAnalyzerGenerator.cpp \
../src/SyntaxAnalyzer/SyntaxModule.cpp 

OBJS += \
./src/SyntaxAnalyzer/SyntaxAnalyzer.o \
./src/SyntaxAnalyzer/SyntaxAnalyzerGenerator.o \
./src/SyntaxAnalyzer/SyntaxModule.o 

CPP_DEPS += \
./src/SyntaxAnalyzer/SyntaxAnalyzer.d \
./src/SyntaxAnalyzer/SyntaxAnalyzerGenerator.d \
./src/SyntaxAnalyzer/SyntaxModule.d 


# Each subdirectory must supply rules for building sources it contributes
src/SyntaxAnalyzer/%.o: ../src/SyntaxAnalyzer/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


