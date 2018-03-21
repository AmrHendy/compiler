#ifndef RULE_H_
#define RULE_H_

#include "lexical_analyzer_generator/rule_preprocessing/RuleElement.h"
#include <vector>

using namespace std ;


class Rule
{
    public:
    Rule();
        virtual ~Rule();
        vector<RuleElement> toPostfix() ;
};

#endif // RULE_H
