/*
 * LexcialAnalyzerGenerator.h
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */

#ifndef LEXCIALANALYZERGENERATOR_H_
#define LEXCIALANALYZERGENERATOR_H_

#include <string>
#include "TransitionTable.h"
#include "PatternProcessor.h"
#include "NFA.h"
#include "DFAMachine.h"

using namespace std;

class LexcialAnalyzerGenerator {
public:
	LexcialAnalyzerGenerator();
	virtual ~LexcialAnalyzerGenerator();

    static TransitionTable generate_minimal_dfa(string language_rules_directory);
};

#endif /* LEXCIALANALYZERGENERATOR_H_ */
