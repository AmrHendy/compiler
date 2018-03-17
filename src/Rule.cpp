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

vector<RuleElement> Rule::toPostfix(){
	RuleElement ruleElem('a', Type::alpha);
	vector<RuleElement> vec;
	vec.push_back(ruleElem);
	return vec;
}
