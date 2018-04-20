#ifndef POSITIVECLOSUREOPERATOR_H_
#define POSITIVECLOSUREOPERATOR_H_

#include "../../MachineStructure/State.h"
#include "../../MachineStructure/Machine.h"
#include "../../Helper/NumberGenerator.h"

class PositiveClosureOperator
{
public:
    PositiveClosureOperator();
    virtual ~PositiveClosureOperator();

    static Machine* apply(Machine* m);

};

#endif /* POSITIVECLOSUREOPERATOR_H_ */
