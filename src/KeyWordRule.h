/*
 * KeyWordRule.h
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#ifndef KEYWORDRULE_H_
#define KEYWORDRULE_H_

#include "Rule.h"
#include <string>

using namespace std;

class KeyWordRule {
public:
	KeyWordRule();
	virtual ~KeyWordRule();
	void appendkeyWords(string rule);
	Rule getKeyWordRule();

	vector<string> keyWords;
};

#endif /* KEYWORDRULE_H_ */
