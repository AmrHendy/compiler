#ifndef DFATABLEBUILDER_H_  /* Include guard */
#define DFATABLEBUILDER_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "Machine.h"
#include "TransitionTable.h"
#include "CompositeState.h"
#include <algorithm>
#include "Alpha.h"

/* CLASS DEFINITIONS */
/*********************************************/
class DFATableBuilder
{
	private:
	/* attributes */
	Machine nfa_machine;

	public:
	/* constructor */
    DFATableBuilder(Machine nfa_machine);
    virtual ~DFATableBuilder(void);

    /* interface functions */
	TransitionTable generate_dfa_table(void);
};


#endif
