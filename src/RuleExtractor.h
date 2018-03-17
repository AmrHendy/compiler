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

using namespace std;

class RuleExtractor {
public:
	RuleExtractor();
	virtual ~RuleExtractor();
	void extractRule(string rule);


private:
	void parseKeWord(string rule);
	void parsePunctuation(string rule);
	void parseRegularExpression(string rule);
};

#endif /* RULEEXTRACTOR_H_ */
