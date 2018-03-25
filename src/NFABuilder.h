#ifndef NFABUILDER_H_  /* Include guard */
#define NFABUILDER_H_

#include "Machine.h"
#include "Rule.h"
#include "AndOperator.h"
#include "OrOperator.h"
#include "KleeneClosureOperator.h"
#include "PositiveClosureOperator.h"

class NFABuilder{
public:
    NFABuilder();
    virtual ~NFABuilder();

    static Machine* build_machine(Rule rule) ;
};


#endif
