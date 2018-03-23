/*
 * LexcialAnalyzerGenerator.cpp
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */

#include "LexcialAnalyzerGenerator.h"

LexcialAnalyzerGenerator::LexcialAnalyzerGenerator() {
	// TODO Auto-generated constructor stub

}

LexcialAnalyzerGenerator::~LexcialAnalyzerGenerator() {
	// TODO Auto-generated destructor stub
}

TransitionTable LexcialAnalyzerGenerator::generate_minimal_dfa(string language_rules_directory){
	cout << "hello";
	PatternProcessor pattern_processor(language_rules_directory);
	vector<Rule> processed_rules = pattern_processor.getRules();
	for(Rule rule : processed_rules){
		string str = "";
		for(RuleElement e : rule.toPostfix()){
			str += e.getContent();
		}
		cout << rule.getRuleName() << "==>" << str << endl;
	}

	NFA nfa_generator(processed_rules);
	Machine nfa_machine = nfa_generator.generate_nfa_machine();

	DFAMachine dfa_machine(nfa_machine);
	TransitionTable minimized_dfa_table = dfa_machine.get_minimized_dfa_table();

	return minimized_dfa_table;
}
