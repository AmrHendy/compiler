/*
 * LexcialAnalyzerGenerator.cpp
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */

#include "LexcialAnalyzerGenerator.h"
#include <iostream>

LexcialAnalyzerGenerator::LexcialAnalyzerGenerator() {
	// TODO Auto-generated constructor stub

}

LexcialAnalyzerGenerator::~LexcialAnalyzerGenerator() {
	// TODO Auto-generated destructor stub
}

TransitionTable LexcialAnalyzerGenerator::generate_minimal_dfa(string language_rules_directory){
	PatternProcessor pattern_processor = PatternProcessor(language_rules_directory);
	vector<Rule> processed_rules = pattern_processor.getRules();
	NFA nfa_generator = NFA(processed_rules);
	Machine* nfa_machine = nfa_generator.generate_nfa_machine();

	//cout << "Finsihing NFA Machiner << endl";

	DFAMachine dfa_machine = DFAMachine(nfa_machine);
	TransitionTable minimized_dfa_table = dfa_machine.get_minimized_dfa_table();
	return minimized_dfa_table;
}
