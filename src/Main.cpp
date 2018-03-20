/*
 * compiler.cpp
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#include <bits/stdc++.h>
#include "FileHandler.h"
#include "PatternProcessor.h"

using namespace std;

int main() {
	PatternProcessor patternProcessor("input.txt");
	vector<Rule> rules = patternProcessor.getRules();

	/*
	for(Rule rule : rules){
		rule.toPostfix();
	}
	*/
	return 0;
}
