#ifndef NFA_GENERATOR_H_  /* Include guard */
#define NFA_GENERATOR_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "Rule.h"
#include "Transition_Table"
#include "Machine.h"
#include "NFA_Machine_Builder.h"
#include <vector>
#include "OR_Operator.h"

/* CLASS DEFINITIONS */
/*********************************************/
class NFA_Generator
{
	private:
	/* attributes */
	vector<Rule> processed_rules;

	public:
	/* constructor */
    NFA_Generator(vector<Rule> processed_rules);
    ~NFA_Generator(void);

    /* interface functions */
    Machine generate_nfa_machine(void);
    Transition_Table generate_nfa_table(void);

};


#endif