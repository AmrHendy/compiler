################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Main/LexcialAnalyzerGenerator.cpp \
../Main/LexicalAnalyzer.cpp \
../Main/Main.cpp 

OBJS += \
./Main/LexcialAnalyzerGenerator.o \
./Main/LexicalAnalyzer.o \
./Main/Main.o 

CPP_DEPS += \
./Main/LexcialAnalyzerGenerator.d \
./Main/LexicalAnalyzer.d \
./Main/Main.d 


# Each subdirectory must supply rules for building sources it contributes
Main/%.o: ../Main/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


