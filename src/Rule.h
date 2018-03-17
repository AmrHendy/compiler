/*
 * Rule.h
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#ifndef RULE_H_
#define RULE_H_

#include <string>

using namespace std;

class Rule {
public:
	Rule(string ruleName, string rulePattern);
	virtual ~Rule();
	string toPostfix();

private:
	string ruleName, rulePattern;
};

#endif /* RULE_H_ */
