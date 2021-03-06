/*
 * RegularRule.cpp
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#include "../../../header/LexcialAnalyzer/RuleExtractor/RegularRule.h"
#include <set>
#include <iostream>


RegularRule::RegularRule()
{
    // TODO Auto-generated constructor stub

}

RegularRule::~RegularRule()
{
    // TODO Auto-generated destructor stub
}

//rule is a string on pattern LHS = RHS
void RegularRule::parseRegularDefinition(string rule)
{
    int equalIndex = rule.find("=");
    //remove spaces from the result string
    string LHS = removeSpaces(rule.substr(0, equalIndex));
    string RHS = removeSpaces(rule.substr(equalIndex + 1));
    string resultRHS;

    for(int index = 0; index < (int)RHS.size(); index++)
    {
        // check the case a\-z means a-z not the range [a-z]
        if(index >= 1 && index + 1 < (int)RHS.size() && RHS[index] == '-' && RHS[index - 1] != '\\')
        {
            resultRHS[resultRHS.length() - 1] = '(';
            for(char ch = RHS[index - 1]; ch <= RHS[index + 1]; ch++)
            {
                resultRHS += ch;
                resultRHS += '|';
            }
            resultRHS[resultRHS.length() - 1] = ')';
            index++;
        }
        else
        {
            resultRHS += RHS[index];
        }
    }

    vector<string> splittedRHS = split(resultRHS);
    string finalResultRHS;
    for(string str : splittedRHS)
    {
        if(regularDefinitions.find(str) != regularDefinitions.end())
        {
            finalResultRHS += '(';
            finalResultRHS += substituteDefinition(str);
            finalResultRHS += ')';
        }
        else
        {
            finalResultRHS += str;
        }
    }
    regularDefinitions[LHS] = finalResultRHS;
}



string RegularRule::substituteDefinition(string defName)
{
    return regularDefinitions[defName];
}


// split the string str to vector of strings according to [ | * + ( ) space]
vector<string> RegularRule::split(string str)
{
    vector<string> splittedStr;
    set<char> delmiters = {'|', '*', '+', '(', ')', ' '};
    string currentStr = "";
    for(int index = 0; index < (int)str.length(); index++)
    {
        if(delmiters.count(str[index]) != 0)
        {
            if(!currentStr.empty())
            {
                splittedStr.push_back(currentStr);
            }
            currentStr = "";
            currentStr += str[index];
            if(!removeSpaces(currentStr).empty())
                splittedStr.push_back(currentStr);
            currentStr = "";
        }
        else
        {
            currentStr += str[index];
        }
    }
    if(!removeSpaces(currentStr).empty())
    {
        splittedStr.push_back(currentStr);
    }


    return splittedStr;
}

//rule is a string on pattern LHS : RHS
void RegularRule::parseRegularExpression(string rule)
{
    int colonIndex = rule.find(":");
    //remove spaces from the result string
    string LHS = removeSpaces(rule.substr(0, colonIndex));
    string RHS = rule.substr(colonIndex + 1);


    vector<string> splittedRHS = split(RHS);
    string finalResultRHS;
    for(string str : splittedRHS)
    {
        if(regularDefinitions.find(str) != regularDefinitions.end())
        {
            finalResultRHS += '(';
            finalResultRHS += substituteDefinition(str);
            finalResultRHS += ')';
        }
        else
        {
            finalResultRHS += str;
        }
    }
    regularExpressions.push_back({{LHS, finalResultRHS}, NumberGenerator::getNextUniqueInt()});
}


string RegularRule::removeSpaces(string str)
{
    string trimmedStr = "";
    for(int index = 0; index < (int)str.length(); index++)
    {
        if(str[index] != ' ')
        {
            trimmedStr += str[index];
        }
    }
    return trimmedStr;
}

