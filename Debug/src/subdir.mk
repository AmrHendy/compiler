################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/FileHandler.cpp \
../src/PatternProcessor.cpp \
../src/RuleExtractor.cpp \
../src/compiler.cpp 

OBJS += \
./src/FileHandler.o \
./src/PatternProcessor.o \
./src/RuleExtractor.o \
./src/compiler.o 

CPP_DEPS += \
./src/FileHandler.d \
./src/PatternProcessor.d \
./src/RuleExtractor.d \
./src/compiler.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


