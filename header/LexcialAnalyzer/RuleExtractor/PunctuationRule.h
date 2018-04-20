/*
 * PunctuationRule.h
 * Created on: Mar 17, 2018
 * Author: Amr Hendy
 */

#ifndef PUNCTUATIONRULE_H_
#define PUNCTUATIONRULE_H_

#include <string>
#include <vector>
#include "Rule.h"
#include "../Helper/NumberGenerator.h"

using namespace std;

class PunctuationRule
{
public:
    PunctuationRule();

    virtual ~PunctuationRule();

    void appendPunctuations(string rule);

    vector<pair<string, int> > punctuations;
};
#endif /* PUNCTUATIONRULE_H_ */


//~ Formatted by Jindent --- http://www.jindent.com
