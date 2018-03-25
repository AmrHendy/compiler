################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../STRUCTURES/CompositeState.cpp \
../STRUCTURES/Machine.cpp \
../STRUCTURES/Partition.cpp \
../STRUCTURES/PartitionRapper.cpp \
../STRUCTURES/Row.cpp \
../STRUCTURES/State.cpp \
../STRUCTURES/TransitionTable.cpp 

OBJS += \
./STRUCTURES/CompositeState.o \
./STRUCTURES/Machine.o \
./STRUCTURES/Partition.o \
./STRUCTURES/PartitionRapper.o \
./STRUCTURES/Row.o \
./STRUCTURES/State.o \
./STRUCTURES/TransitionTable.o 

CPP_DEPS += \
./STRUCTURES/CompositeState.d \
./STRUCTURES/Machine.d \
./STRUCTURES/Partition.d \
./STRUCTURES/PartitionRapper.d \
./STRUCTURES/Row.d \
./STRUCTURES/State.d \
./STRUCTURES/TransitionTable.d 


# Each subdirectory must supply rules for building sources it contributes
STRUCTURES/%.o: ../STRUCTURES/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


