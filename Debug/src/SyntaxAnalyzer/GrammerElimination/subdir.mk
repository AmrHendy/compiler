################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/SyntaxAnalyzer/GrammerElimination/LeftFactoringElimination.cpp \
../src/SyntaxAnalyzer/GrammerElimination/LeftRecursionElimination.cpp 

OBJS += \
./src/SyntaxAnalyzer/GrammerElimination/LeftFactoringElimination.o \
./src/SyntaxAnalyzer/GrammerElimination/LeftRecursionElimination.o 

CPP_DEPS += \
./src/SyntaxAnalyzer/GrammerElimination/LeftFactoringElimination.d \
./src/SyntaxAnalyzer/GrammerElimination/LeftRecursionElimination.d 


# Each subdirectory must supply rules for building sources it contributes
src/SyntaxAnalyzer/GrammerElimination/%.o: ../src/SyntaxAnalyzer/GrammerElimination/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


