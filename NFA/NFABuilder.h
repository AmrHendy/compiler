#ifndef NFABUILDER_H_  /* Include guard */
#define NFABUILDER_H_

#include <vector>
#include "../STRUCTURES/Machine.h"
#include "../Rule_Extractor/Rule.h"
#include "NFA_OPERATORS/AndOperator.h"
#include "NFA_OPERATORS/OrOperator.h"
#include "NFA_OPERATORS/KleeneClosureOperator.h"
#include "NFA_OPERATORS/PositiveClosureOperator.h"

class NFABuilder{
public:
    NFABuilder();
    virtual ~NFABuilder();

    static Machine* build_machine(Rule rule) ;
};


#endif
