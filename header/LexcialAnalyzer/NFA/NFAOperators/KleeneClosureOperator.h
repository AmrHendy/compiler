#ifndef KLEENECLOSUREOPERATOR_H_
#define KLEENECLOSUREOPERATOR_H_

#include "../../MachineStructure/State.h"
#include "../../MachineStructure/Machine.h"
#include "../../Helper/NumberGenerator.h"

class KleeneClosureOperator
{
public:
    KleeneClosureOperator();
    virtual ~KleeneClosureOperator();

    static Machine* apply(Machine* m);
};

#endif /* POSITIVECLOSUREOPERATOR_H_ */
