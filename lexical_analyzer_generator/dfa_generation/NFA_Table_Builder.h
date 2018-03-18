#ifndef NFA_TABLE_BUILDER_H_  /* Include guard */
#define NFA_TABLE_BUILDER_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "Machine.h"

/* CLASS DEFINITIONS */
/*********************************************/
class NFA_Table_Builder
{
	private:
	/* attributes */
	Machine nfa_machine;

	public:
	/* constructor */
    NFA_Table_Builder(Machine nfa_machine);
    ~NFA_Table_Builder(void);

    /* interface functions */
    Transition_Table generate_nfa_table(void);
 
};


#endif