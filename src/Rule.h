/*
 * Rule.h
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#ifndef RULE_H_
#define RULE_H_

#include <string>
#include <vector>
#include "RuleElement.h"
#include "PostfixExpressionHandler.h"

using namespace std;

class Rule {
public:
	Rule(string ruleName, string rulePattern);
	virtual ~Rule();
	vector<RuleElement> toPostfix();

private:
	string ruleName, rulePattern;
};

#endif /* RULE_H_ */
