/*
 * RegularRule.h
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#ifndef REGULARRULE_H_
#define REGULARRULE_H_

#include <string>
#include <map>
#include <vector>
#include "Rule.h"
#include "../Helper/NumberGenerator.h"

using namespace std;

class RegularRule
{
public:
    RegularRule();

    virtual ~RegularRule();

    void parseRegularExpression(string rule);

    void parseRegularDefinition(string rule);

    map<string, string>                      regularDefinitions;
    vector<pair<pair<string, string>, int> > regularExpressions;

private:
    vector<string> split(string str);

    string substituteDefinition(string defName);

    string removeSpaces(string str);
};
#endif /* REGULARRULE_H_ */


//~ Formatted by Jindent --- http://www.jindent.com
