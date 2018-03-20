/*
 * RuleExtractor.h
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#ifndef RULEEXTRACTOR_H_
#define RULEEXTRACTOR_H_

#include <vector>
#include <string>
#include <map>
#include "Rule.h"
#include "KeyWordRule.h"
#include "PunctuationRule.h"
#include "RegularRule.h"

using namespace std;

class RuleExtractor {
public:
	RuleExtractor();
	virtual ~RuleExtractor();
	void extractRule(string rule);
	vector<Rule> getAllRules();


private:
	KeyWordRule keyWordRule;
	PunctuationRule punctuationRule;
	RegularRule regularRule;

	string removeSpaces(string str);
};

#endif /* RULEEXTRACTOR_H_ */
