/*
 * PunctuationRule.cpp
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#include "PunctuationRule.h"
#include <sstream>

PunctuationRule::PunctuationRule()
{
    // TODO Auto-generated constructor stub
}

PunctuationRule::~PunctuationRule()
{
    // TODO Auto-generated destructor stub
}

// we send the string including []
void PunctuationRule::appendPunctuations(string rule)
{
    string rule_str = rule.substr(1, rule.length() - 2);
    stringstream ss(rule_str);
    string punc;
    while(ss >> punc)
    {
        punctuations.push_back({punc, 2});
    }
}
