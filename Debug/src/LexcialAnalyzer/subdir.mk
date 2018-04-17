################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/LexcialAnalyzer/LexcialAnalyzerGenerator.cpp \
../src/LexcialAnalyzer/LexicalModule.cpp 

OBJS += \
./src/LexcialAnalyzer/LexcialAnalyzerGenerator.o \
./src/LexcialAnalyzer/LexicalModule.o 

CPP_DEPS += \
./src/LexcialAnalyzer/LexcialAnalyzerGenerator.d \
./src/LexcialAnalyzer/LexicalModule.d 


# Each subdirectory must supply rules for building sources it contributes
src/LexcialAnalyzer/%.o: ../src/LexcialAnalyzer/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


