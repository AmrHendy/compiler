/*
 * RegularRule.h
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#ifndef REGULARRULE_H_
#define REGULARRULE_H_

#include <string>
#include "Rule.h"

using namespace std;

class RegularRule {
public:
	RegularRule();
	virtual ~RegularRule();

	void parseRegularExpression(string rule);
	void parseRegularDefinition(string rule);
};

#endif /* REGULARRULE_H_ */
