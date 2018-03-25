################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../NFA/NFA_OPERATORS/AndOperator.cpp \
../NFA/NFA_OPERATORS/KleeneClosureOperator.cpp \
../NFA/NFA_OPERATORS/OrOperator.cpp \
../NFA/NFA_OPERATORS/PositiveClosureOperator.cpp 

OBJS += \
./NFA/NFA_OPERATORS/AndOperator.o \
./NFA/NFA_OPERATORS/KleeneClosureOperator.o \
./NFA/NFA_OPERATORS/OrOperator.o \
./NFA/NFA_OPERATORS/PositiveClosureOperator.o 

CPP_DEPS += \
./NFA/NFA_OPERATORS/AndOperator.d \
./NFA/NFA_OPERATORS/KleeneClosureOperator.d \
./NFA/NFA_OPERATORS/OrOperator.d \
./NFA/NFA_OPERATORS/PositiveClosureOperator.d 


# Each subdirectory must supply rules for building sources it contributes
NFA/NFA_OPERATORS/%.o: ../NFA/NFA_OPERATORS/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


