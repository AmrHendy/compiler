################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/Tester/subdir.mk
-include src/SyntaxAnalyzer/ParserTable/subdir.mk
-include src/SyntaxAnalyzer/GrammerExtractor/subdir.mk
-include src/SyntaxAnalyzer/GrammerElimination/subdir.mk
-include src/SyntaxAnalyzer/subdir.mk
-include src/LexcialAnalyzer/Tokenizer/subdir.mk
-include src/LexcialAnalyzer/RuleExtractor/subdir.mk
-include src/LexcialAnalyzer/NFA/NFAOperators/subdir.mk
-include src/LexcialAnalyzer/NFA/subdir.mk
-include src/LexcialAnalyzer/MachineStructure/subdir.mk
-include src/LexcialAnalyzer/Helper/subdir.mk
-include src/LexcialAnalyzer/DFA/subdir.mk
-include src/LexcialAnalyzer/subdir.mk
-include src/FileHandler/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: compiler

# Tool invocations
compiler: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross G++ Linker'
	g++  -o "compiler" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(C_DEPS)$(CPP_DEPS) compiler
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
