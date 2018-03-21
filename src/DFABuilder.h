#ifndef DFABUILDER_H_
#define DFABUILDER_H_

#include "Machine.h"

class DFABuilder {
public:
	DFABuilder();
	virtual ~DFABuilder();

    static Machine build_dfa_machine(Machine nfa_machine);
};

#endif /* DFABUILDER_H_ */
