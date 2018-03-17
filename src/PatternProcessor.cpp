/*
 * PatternProcessor.cpp
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#include "PatternProcessor.h"
#include "RuleExtractor.h"

using namespace std;

PatternProcessor::PatternProcessor(vector<string> file_lines) {
	PatternProcessor::file_lines = file_lines;
}

PatternProcessor::~PatternProcessor() {
	// TODO Auto-generated destructor stub
}

vector<vector<string> > PatternProcessor::getRules(){
	RuleExtractor ruleExtractor;
	vector<vector<string> > all_rules;
	for(string str : file_lines){
		all_rules.push_back(ruleExtractor.extractRule(str));
	}
	return all_rules;
}
