/*
 * RuleExtractor.h
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#ifndef RULEEXTRACTOR_H_
#define RULEEXTRACTOR_H_

#include <vector>
#include <string>

using namespace std;

class RuleExtractor {
public:
	RuleExtractor();
	virtual ~RuleExtractor();
	vector<string> extractRule(string rule);
};

#endif /* RULEEXTRACTOR_H_ */
