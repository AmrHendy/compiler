/*
 * KeyWordRule.h
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#ifndef KEYWORDRULE_H_
#define KEYWORDRULE_H_

#include "Rule.h"
#include "../GENERATORS/NumberGenerator.h"
#include <string>
#include <vector>

using namespace std;

class KeyWordRule {
public:
	KeyWordRule();
	virtual ~KeyWordRule();
	void appendkeyWords(string rule);

	vector<pair<string, int> > keyWords;
};

#endif /* KEYWORDRULE_H_ */
