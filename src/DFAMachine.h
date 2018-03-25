#ifndef DFAMachine_H_  /* Include guard */
#define DFAMachine_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "Machine.h"
#include "TransitionTable.h"
#include "DFATableBuilder.h"

/* CLASS DEFINITIONS */
/*********************************************/
class DFAMachine
{
	private:
	/* attributes */
	Machine* nfa_machine;
	TransitionTable minimized_dfa_table; // not used till now
	bool table_calculated_flag;

	public:
	/* constructor */
    DFAMachine(Machine* nfa_machine);
    virtual ~DFAMachine(void);

    /* interface functions */
    TransitionTable generate_minimized_dfa_table(void);
    TransitionTable get_minimized_dfa_table();
};
#endif
