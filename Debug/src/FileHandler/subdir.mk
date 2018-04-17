################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/FileHandler/FileReader.cpp \
../src/FileHandler/FileWriter.cpp 

OBJS += \
./src/FileHandler/FileReader.o \
./src/FileHandler/FileWriter.o 

CPP_DEPS += \
./src/FileHandler/FileReader.d \
./src/FileHandler/FileWriter.d 


# Each subdirectory must supply rules for building sources it contributes
src/FileHandler/%.o: ../src/FileHandler/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


