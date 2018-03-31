#ifndef KLEENECLOSUREOPERATOR_H_
#define KLEENECLOSUREOPERATOR_H_

#include "../../STRUCTURES/State.h"
#include "../../STRUCTURES/Machine.h"
#include "../../GENERATORS/NumberGenerator.h"

class KleeneClosureOperator
{
public:
    KleeneClosureOperator();
    virtual ~KleeneClosureOperator();

    static Machine* apply(Machine* m);
};

#endif /* POSITIVECLOSUREOPERATOR_H_ */
