#ifndef POSITIVECLOSUREOPERATOR_H_
#define POSITIVECLOSUREOPERATOR_H_

#include "State.h"
#include "Machine.h"


class PositiveClosureOperator {
public:
	PositiveClosureOperator();
	virtual ~PositiveClosureOperator();

    static Machine apply(Machine m);

};

#endif /* POSITIVECLOSUREOPERATOR_H_ */
