#ifndef NFA_GENERATOR_H_  /* Include guard */
#define NFA_GENERATOR_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "lexical_analyzer_generator/rule_preprocessing/Rule.h"
#include "lexical_analyzer_generator/data_structures/transition_table/Transition_Table.h"
#include "lexical_analyzer_generator/data_structures/automata/Machine.h"
#include "lexical_analyzer_generator/nfa_generation/NFA_Machine_Builder.h"
#include <vector>

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
