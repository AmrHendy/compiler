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
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


