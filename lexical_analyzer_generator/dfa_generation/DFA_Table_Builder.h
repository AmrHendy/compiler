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
	Transition_Table nfa_table; // not used till now

	public:
	/* constructor */
    DFA_Table_Builder(Machine nfa_machine);
    DFA_Table_Builder(Transition_Table nfa_table);  //not used till now
    ~DFA_Table_Builder(void);

    /* interface functions */
	Transition_Table generate_dfa_table(void);
	Transition_Table nfa_table_to_dfa_table(void);
 
};


#endif