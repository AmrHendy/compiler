################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/LexcialAnalyzer/Tokenizer/Token.cpp \
../src/LexcialAnalyzer/Tokenizer/Tokenizer.cpp 

OBJS += \
./src/LexcialAnalyzer/Tokenizer/Token.o \
./src/LexcialAnalyzer/Tokenizer/Tokenizer.o 

CPP_DEPS += \
./src/LexcialAnalyzer/Tokenizer/Token.d \
./src/LexcialAnalyzer/Tokenizer/Tokenizer.d 


# Each subdirectory must supply rules for building sources it contributes
src/LexcialAnalyzer/Tokenizer/%.o: ../src/LexcialAnalyzer/Tokenizer/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


