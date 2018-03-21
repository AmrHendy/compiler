#ifndef KLEENECLOSUREOPERATOR_H_
#define KLEENECLOSUREOPERATOR_H_

#include "State.h"
#include "Machine.h"


class KleeneClosureOperator{
public:
	KleeneClosureOperator();
	virtual ~KleeneClosureOperator();

    static Machine apply(Machine m);
};

#endif /* POSITIVECLOSUREOPERATOR_H_ */
