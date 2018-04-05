################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GENERATORS/Alpha.cpp \
../GENERATORS/NumberGenerator.cpp 

OBJS += \
./GENERATORS/Alpha.o \
./GENERATORS/NumberGenerator.o 

CPP_DEPS += \
./GENERATORS/Alpha.d \
./GENERATORS/NumberGenerator.d 


# Each subdirectory must supply rules for building sources it contributes
GENERATORS/%.o: ../GENERATORS/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


