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
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


