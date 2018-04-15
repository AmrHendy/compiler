################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../FileWriter.cpp \
../GrammerParser.cpp \
../Node.cpp \
../Production.cpp \
../ProductionElement.cpp \
../Tester.cpp 

OBJS += \
./FileWriter.o \
./GrammerParser.o \
./Node.o \
./Production.o \
./ProductionElement.o \
./Tester.o 

CPP_DEPS += \
./FileWriter.d \
./GrammerParser.d \
./Node.d \
./Production.d \
./ProductionElement.d \
./Tester.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -std=c++11 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


