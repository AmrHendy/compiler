#ifndef POSITIVECLOSUREOPERATOR_H_
#define POSITIVECLOSUREOPERATOR_H_

#include "../../STRUCTURES/State.h"
#include "../../STRUCTURES/Machine.h"
#include "../../GENERATORS/NumberGenerator.h"


class PositiveClosureOperator
{
public:
    PositiveClosureOperator();
    virtual ~PositiveClosureOperator();

    static Machine* apply(Machine* m);

};

#endif /* POSITIVECLOSUREOPERATOR_H_ */
