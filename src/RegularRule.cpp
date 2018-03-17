/*
 * RegularRule.cpp
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#include "RegularRule.h"

RegularRule::RegularRule() {
	// TODO Auto-generated constructor stub

}

RegularRule::~RegularRule() {
	// TODO Auto-generated destructor stub
}

//rule is a string on pattern LHS = RHS
void RegularRule::parseRegularDefinition(string rule){
	int equalIndex = rule.find("=");
	//remove spaces from the result string
	string LHS = rule.substr(0, equalIndex);
	string RHS = rule.substr(equalIndex + 1);
	string resultRHS;

	for(int index = 0; index < RHS.size();index++){
		// check the case a\-z means a-z not the range [a-z]
		if(index >= 1 && index + 1 < RHS.size() && RHS[index] == '-' && RHS[index - 1] != '\\'){
			resultRHS[resultRHS.length() - 1] = '(';
			for(char ch = RHS[index - 1]; ch <= RHS[index + 1]; ch++){
				resultRHS += ch + '|';
			}
			resultRHS[resultRHS.length() - 1] = ')';
			index++;
		}
		else{
			resultRHS += RHS[index];
		}
	}

	vector<string> splittedRHS = split(resultRHS);
	string finalResultRHS;
	for(string str : splittedRHS){
		if(regularDefinitions[str] != regularDefinitions.end()){
			finalResultRHS += '(' + substituteDefinition(str) + ')';
		}
		else{
			finalResultRHS += str;
		}
	}
	regularDefinitions[LHS] = finalResultRHS;
}



string RegularRule::substituteDefinition(string defName){
	return regularDefinitions[defName];
}


// split the string str to vector of strings according to [ | * + ( )]
vector<string> RegularRule::split(string str){
	vector<string> splittedStr;
	set<char> delmiters = {'|', '*', '+', '(', ')'};
	string currentStr = "";
	for(int index = 0; index < str.length(); index++){
		if(delmiters.count(str[index]) != 0){
			if(!currentStr.empty()){
				splittedStr.push_back(currentStr);
			}
			splittedStr.push_back("" + str[index]);
			currentStr = "";
		}
		else{
			currentStr += str[index];
		}
	}
	if(!currentStr.empty()){
		splittedStr.push_back(currentStr);
	}
	return splittedStr;
}

//rule is a string on pattern LHS : RHS
void RegularRule::parseRegularExpression(string rule){

}

