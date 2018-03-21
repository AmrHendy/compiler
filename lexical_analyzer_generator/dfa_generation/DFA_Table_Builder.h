#ifndef DFA_TABLE_BUILDER_H_  /* Include guard */
#define DFA_TABLE_BUILDER_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "lexical_analyzer_generator/data_structures/automata/Machine.h"
#include "lexical_analyzer_generator/data_structures/transition_table/Transition_Table.h"
#include "lexical_analyzer_generator/data_structures/transition_table/Composite_State.h"
#include <algorithm>

/* CLASS DEFINITIONS */
/*********************************************/
class DFA_Table_Builder
{
private:
    /* attributes */
    Transition_Table nfa_table; // not used till now

public:
    /* constructor */
    DFA_Table_Builder(Transition_Table nfa_table);  //not used till now
    ~DFA_Table_Builder(void);

    /* interface functions */
    Transition_Table generate_dfa_table(void);
    Transition_Table minimize_dfa_table(Transition_Table dfa_table);
};


#endif
