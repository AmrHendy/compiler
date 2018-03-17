/*
 * PunctuationRule.h
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#ifndef PUNCTUATIONRULE_H_
#define PUNCTUATIONRULE_H_
#include <string>
#include <vector>
#include "Rule.h"

using namespace std;

class PunctuationRule {
public:
	PunctuationRule();
	virtual ~PunctuationRule();
	void appendPunctuations(string rule);
	Rule getPunctuationRule();

	vector<string> punctuations;

};

#endif /* PUNCTUATIONRULE_H_ */
