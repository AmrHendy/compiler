/*
 * LexcialAnalyzerGenerator.h
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */

#ifndef MAIN_LEXCIALANALYZERGENERATOR_H_
#define MAIN_LEXCIALANALYZERGENERATOR_H_

#include <iostream>
#include <string>
#include "MachineStructure/TransitionTable.h"
#include "RuleExtractor/PatternProcessor.h"
#include "NFA/NFA.h"
#include "DFA/DFAMachine.h"


using namespace std;

class LexcialAnalyzerGenerator
{
public:
    LexcialAnalyzerGenerator();
    virtual ~LexcialAnalyzerGenerator();

    static TransitionTable generate_minimal_dfa(string language_rules_directory);
};

#endif /* MAIN_LEXCIALANALYZERGENERATOR_H_ */
