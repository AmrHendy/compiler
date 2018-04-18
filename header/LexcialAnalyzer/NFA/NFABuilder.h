#ifndef NFABUILDER_H_  /* Include guard */
#define NFABUILDER_H_

#include <vector>
#include "../MachineStructure/Machine.h"
#include "../RuleExtractor/Rule.h"
#include "NFAOperators/AndOperator.h"
#include "NFAOperators/OrOperator.h"
#include "NFAOperators/KleeneClosureOperator.h"
#include "NFAOperators/PositiveClosureOperator.h"

class NFABuilder{
public:
    NFABuilder();
    virtual ~NFABuilder();

    static Machine* build_machine(Rule rule) ;
};


#endif
