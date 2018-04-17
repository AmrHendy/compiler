/*
 * PostfixExpressionHandler.h
 * Created on: Mar 18, 2018
 * Author: Amr Hendy
 */

#ifndef POSTFIXEXPRESSIONHANDLER_H_
#define POSTFIXEXPRESSIONHANDLER_H_

#include <string>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include "RuleElement.h"
#include "../GENERATORS/Alpha.h"

using namespace std;

class PostfixExpressionHandler
{
public:
    PostfixExpressionHandler(vector<pair<char,int> > operationWeights);
    virtual ~PostfixExpressionHandler();

    vector<RuleElement> toPostfix(string expression);


private:
    bool isOperation(char ch);
    bool isHigherOrder(char ch1, char ch2);
    vector<RuleElement> convertToRule(string postfixStr, vector<int> operatorsPosition);
    map<char,int> weights;
    set<char> operations;
};

#endif /* POSTFIXEXPRESSIONHANDLER_H_ */
