#ifndef DFA_GENERATOR_H_  /* Include guard */
#define DFA_GENERATOR_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "lexical_analyzer_generator/data_structures/automata/Machine.h"
#include "lexical_analyzer_generator/data_structures/transition_table/Transition_Table.h"

/* CLASS DEFINITIONS */
/*********************************************/
class DFA_Generator
{
private:
    /* attributes */
    Transition_Table nfa_table; // not used till now

public:
    /* constructor */
    DFA_Generator(void);
    DFA_Generator(Transition_Table nfa_table); // not used until now
    ~DFA_Generator(void);

    /* interface functions */
    Transition_Table generate_minimized_dfa_table(void);

};


#endif
