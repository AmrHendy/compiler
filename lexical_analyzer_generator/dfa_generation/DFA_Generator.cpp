/* INCLUDE HEADER */
/*********************************************/
#include "lexical_analyzer_generator/dfa_generation/DFA_Generator.h"
#include "lexical_analyzer_generator/data_structures/transition_table/Transition_Table.h"
#include "lexical_analyzer_generator/dfa_generation/DFA_Table_Builder.h"

/* CONSTRUCTOR */
/*********************************************/
DFA_Generator::DFA_Generator(Transition_Table nfa_table)
{
    this->nfa_table = nfa_table;
}

DFA_Generator::DFA_Generator()
{
    /* nothing */
}

/* SETTERS AND GETTERS */
/*********************************************/
Transition_Table
DFA_Generator::generate_minimized_dfa_table(void)
{
    /* 01 obtain DFA table */
    DFA_Table_Builder dfa_table_builder(nfa_table);
    Transition_Table dfa_table = dfa_table_builder.generate_dfa_table();

    return dfa_table_builder.minimize_dfa_table(dfa_table) ;

}

