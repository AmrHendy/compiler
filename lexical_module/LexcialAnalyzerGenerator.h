/*
 * LexcialAnalyzerGenerator.h
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */

#ifndef LEXCIALANALYZERGENERATOR_H_
#define LEXCIALANALYZERGENERATOR_H_

#include <iostream>
#include <string>
#include "STRUCTURES/TransitionTable.h"
#include "Rule_Extractor/PatternProcessor.h"
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

#endif /* LEXCIALANALYZERGENERATOR_H_ */
