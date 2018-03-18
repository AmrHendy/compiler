#ifndef DFA_TABLE_BUILDER_H_  /* Include guard */
#define DFA_TABLE_BUILDER_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "Machine"
#include "Transition_Table.h"
#include "Composite_State.h"
#include <algorithm>

/* CLASS DEFINITIONS */
/*********************************************/
class DFA_Table_Builder
{
	private:
	/* attributes */
	Machine nfa_machine;
	Transition_Table dfa_table;

	public:
	/* constructor */
    DFA_Table_Builder(void);
    ~DFA_Table_Builder(void);

    /* interface functions */
	void generate_dfa_table(void);

	private:
	/* utility functions */
	Composite_State find_equivalent_states(Composite_State state);
 
};


#endif