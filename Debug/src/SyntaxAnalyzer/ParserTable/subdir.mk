################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/SyntaxAnalyzer/ParserTable/DerivationTable.cpp \
../src/SyntaxAnalyzer/ParserTable/FirstFollow.cpp 

OBJS += \
./src/SyntaxAnalyzer/ParserTable/DerivationTable.o \
./src/SyntaxAnalyzer/ParserTable/FirstFollow.o 

CPP_DEPS += \
./src/SyntaxAnalyzer/ParserTable/DerivationTable.d \
./src/SyntaxAnalyzer/ParserTable/FirstFollow.d 


# Each subdirectory must supply rules for building sources it contributes
src/SyntaxAnalyzer/ParserTable/%.o: ../src/SyntaxAnalyzer/ParserTable/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


