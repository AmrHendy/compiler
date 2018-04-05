################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../NFA/NFA.cpp \
../NFA/NFABuilder.cpp 

OBJS += \
./NFA/NFA.o \
./NFA/NFABuilder.o 

CPP_DEPS += \
./NFA/NFA.d \
./NFA/NFABuilder.d 


# Each subdirectory must supply rules for building sources it contributes
NFA/%.o: ../NFA/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


