/*
 * RuleExtractor.cpp
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#include "RuleExtractor.h"
#include <iostream>

using namespace std;

RuleExtractor::RuleExtractor() {
	keyWordRule = KeyWordRule();
	punctuationRule = PunctuationRule();
	regularRule = RegularRule();
}

RuleExtractor::~RuleExtractor() {
	// TODO Auto-generated destructor stub
}

void RuleExtractor::extractRule(string rule){
	string rule_trimmed = removeSpaces(rule);
	if(rule_trimmed[0] == '{'){
		keyWordRule.appendkeyWords(rule);
	}
	else if(rule_trimmed[0] == '['){
		punctuationRule.appendPunctuations(rule);
	}
	else{
		int colon_index = rule_trimmed.find(':');
		int equal_index = rule_trimmed.find('=');
		if(colon_index != string::npos && equal_index != string::npos){
			if(equal_index < colon_index){
				regularRule.parseRegularDefinition(rule);
			}
			else{
				regularRule.parseRegularExpression(rule);
			}
		}
		else if(colon_index != string::npos){
			regularRule.parseRegularExpression(rule);
		}
		else if(equal_index != string::npos){
			regularRule.parseRegularDefinition(rule);
		}
	}
}


vector<Rule> RuleExtractor::getAllRules(){
	vector<Rule> all;

	/*
	vector<string> v1 = keyWordRule.keyWords;
	vector<string> v2 = punctuationRule.punctuations;
	vector<pair<string, string> > v3 = regularRule.regularExpressions;
	cout << "KEYWORDS\n";
	for(string s : v1)cout << removeSpaces(s) << endl;
	cout << "==============================================\n";

	cout << "PUNCUTATIONS\n";
	for(string s : v2)cout << removeSpaces(s) << endl;
	cout << "==============================================\n";


	cout << "REGULAR EXPRESSIONS\n";
	for(pair<string,string> p : v3)cout << removeSpaces(p.first) << "  =  " << removeSpaces(p.second) << endl;
	cout << "==============================================\n";

	*/

	for(string keyWord : keyWordRule.keyWords){
		keyWord = removeSpaces(keyWord);
		Rule rule("T_" + keyWord, keyWord);
		all.push_back(rule);
		rule.toPostfix();
	}


	for(pair<string,string> p : regularRule.regularExpressions){
		p.first = removeSpaces(p.first);
		p.second = removeSpaces(p.second);
		Rule rule(p.first, p.second);
		all.push_back(rule);
		rule.toPostfix();
	}


	for(string punc : punctuationRule.punctuations){
		punc = removeSpaces(punc);
		Rule rule("T_" + punc, punc);
		all.push_back(rule);
		rule.toPostfix();
	}

	return all;
}

string RuleExtractor::removeSpaces(string str){
	string trimmedStr = "";
	for(int index = 0; index < str.length(); index++){
		if(str[index] != ' '){
			trimmedStr += str[index];
		}
	}
	return trimmedStr;
}

