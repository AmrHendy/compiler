/*
 * Rule.cpp
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#include "Rule.h"

Rule::Rule(string ruleName, string rulePattern) {
	Rule::ruleName = ruleName;
	Rule::rulePattern = rulePattern;

}

Rule::~Rule() {
	// TODO Auto-generated destructor stub
}

string Rule::toPostfix(){
	string postfixRule;
	return postfixRule;
}
