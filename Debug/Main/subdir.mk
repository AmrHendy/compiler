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
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


