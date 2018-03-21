/* IMPORT LIBRARIES */
/*********************************************/
#include "DFA_Table_Builder.h"

/* CONSTRUCTOR */
/*********************************************/
DFA_Table_Builder::DFA_Table_Builder(Transition_Table nfa_table)
{
    this->nfa_table = nfa_table;
}

DFA_Table_Builder::~DFA_Table_Builder(void)
{
    /* nothing */
}

/* INTERFACE METHODS */
/*********************************************/
Transition_Table
DFA_Table_Builder::generate_dfa_table(void)
{
    Transition_Table* dfa_table = new Transition_Table() ;
    // TODO use NFA table to get dfa table
}

Transition_Table
DFA_Table_Builder::minimize_dfa_table(Transition_Table dfa_table)
{
    // TODO minimize dfa table
}



