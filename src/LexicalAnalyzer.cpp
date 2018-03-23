/*
 * LexicalAnalyzer.cpp
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */

#include "LexicalAnalyzer.h"

LexicalAnalyzer::LexicalAnalyzer(string language_rules_directory, string user_prog_directory){
	TransitionTable minimized_dfa_table = LexcialAnalyzerGenerator::generate_minimal_dfa(language_rules_directory);
	Tokenizer tokenizer(minimized_dfa_table, user_prog_directory);
	LexicalAnalyzer::tokenizer = tokenizer;
}

LexicalAnalyzer::~LexicalAnalyzer() {
	// TODO Auto-generated destructor stub
}

Token LexicalAnalyzer::next_token(){
	return tokenizer.next_token();
}

