/*
 * PostfixExpressionHandler.cpp
 * Created on: Mar 20, 2018
 * Author: Amr Hendy
 */

#include "PostfixExpressionHandler.h"

PostfixExpressionHandler::PostfixExpressionHandler(vector<pair<char,int> > operationWeights) {
	for(pair<char,int> op : operationWeights){
		operations.insert(op.first);
		weights[op.first] = op.second;
	}
}

PostfixExpressionHandler::~PostfixExpressionHandler() {
	// TODO Auto-generated destructor stub
}


vector<RuleElement> PostfixExpressionHandler::toPostfix(string expression){
	string currentExpression = "";
	stack<char> operators;
	vector<int> operatorsPosition;

	int lastDot = -1;

	for(int index = 0; index < expression.length(); index++){
		if(isOperation(expression[index])){
			while(!operators.empty() && operators.top() != '('
					&& isHigherOrder(operators.top(), expression[index])){
				operatorsPosition.push_back(currentExpression.length());
				currentExpression += operators.top();
				operators.pop();
			}
			operators.push(expression[index]);
		}
		else if(expression[index] == '('){
			/* first check if we want to add concatenation. */
			if(index > 0 && expression[index - 1] != '(' && expression[index - 1] != '|' && index - 1 != lastDot){
				string str = expression.substr(0, index);
				str += '$';
				str += expression.substr(index);
				expression = str;
				lastDot = index;
				index--;
				continue;
			}
			operators.push(expression[index]);
		}
		else if(expression[index] == ')'){
			while(operators.top() != '('){
				operatorsPosition.push_back(currentExpression.length());
				currentExpression += operators.top();
				operators.pop();
			}
			operators.pop();
		}
		else{
			/* first check if we want to add concatenation. */
			if(index > 0 && expression[index - 1] != '(' && expression[index - 1] != '|' && index - 1 != lastDot){
				string str = expression.substr(0, index);
				str += '$';
				str += expression.substr(index);
				expression = str;
				lastDot = index;
				index--;
				continue;
			}
			if(expression[index] == '\\'){
				if(index + 1 <= expression.length() - 1){
					index++;
					/* check epsilon after /
					 * we will mark it in the rule by char #
					 * or we can use boolean attribute inside RuleElement
					 * to indicate which that element is epsilon or not.
					 * */
					if(expression[index] == 'L'){
						currentExpression += '#';
					}
					else{
						currentExpression += expression[index];
					}
				}
			}
			else{
				currentExpression += expression[index];
			}
		}
	}

	while(!operators.empty()){
		operatorsPosition.push_back(currentExpression.length());
		currentExpression += operators.top();
		operators.pop();
	}

	cout << currentExpression << endl;
	vector<RuleElement> ruleElements = convertToRule(currentExpression, operatorsPosition);
	return ruleElements;
}


vector<RuleElement> PostfixExpressionHandler::convertToRule(string postfixStr, vector<int> operatorsPosition){
	vector<RuleElement> ruleElements;
	reverse(operatorsPosition.begin(), operatorsPosition.end());
	for(int index = 0; index < postfixStr.length(); index++){
		if(operatorsPosition.size() > 0 && operatorsPosition.back() == index){
			RuleElement ruleElement = RuleElement(postfixStr[index], Type::operation);
			operatorsPosition.pop_back();
			ruleElements.push_back(ruleElement);
		}
		else{
			RuleElement ruleElement = RuleElement(postfixStr[index], Type::alpha);
			ruleElements.push_back(ruleElement);
		}
	}
	/* Set the Alpha. */
	for(RuleElement elem : ruleElements){
		if(elem.isAlpha()){
			Alpha::insertAlphabet(elem.getContent());
		}
	}
	return ruleElements;
}

bool PostfixExpressionHandler::isOperation(char ch){
	return operations.find(ch) != operations.end();
}

bool PostfixExpressionHandler::isHigherOrder(char ch1, char ch2){
	return weights[ch1] >= weights[ch2];
}
