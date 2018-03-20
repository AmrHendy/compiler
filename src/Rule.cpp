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
	/* dot we represent it by $ as input can have . decimal point. */
	vector<pair<char, int> > operationWeights = {{'*', 3}, {'+', 3}, {'$', 2}, {'|', 1}};
	PostfixExpressionHandler postfixHandler(operationWeights);
	return postfixHandler.toPostfix(rulePattern);
}
