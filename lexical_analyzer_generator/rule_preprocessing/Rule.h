#ifndef RULE_H_
#define RULE_H_

#include "lexical_analyzer_generator/rule_preprocessing/RuleElement.h"

class Rule
{
    public:
        Rule();
        virtual ~Rule();

        vector<RuleElement> toPostfix() ;


    private:
};

#endif // RULE_H
