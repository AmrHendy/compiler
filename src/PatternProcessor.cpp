/*
 * PatternProcessor.cpp
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#include "PatternProcessor.h"
#include "RuleExtractor.h"
#include "FileHandler.h"

using namespace std;

PatternProcessor::PatternProcessor(string fileName) {
	FileHandler fileHandler;
	file_lines = fileHandler.readFile(fileName);
}

PatternProcessor::~PatternProcessor() {
	// TODO Auto-generated destructor stub
}

vector<Rule> PatternProcessor::getRules(){
	RuleExtractor ruleExtractor;
	vector<Rule> all_rules;
	for(string str : file_lines){
		ruleExtractor.extractRule(str);
	}
	return ruleExtractor.getAllRules();
}
