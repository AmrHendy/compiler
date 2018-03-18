/* INCLUDE HEADER */
/*********************************************/
#include "DFA_Genertor.h"

/* CONSTRUCTOR */
/*********************************************/
DFA_Genertor::DFA_Genertor(Machine nfa_machine)
{
   this->nfa_machine = nfa_machine;
}

DFA_Genertor::DFA_Genertor(Transition_Table nfa_table)
{
   this->nfa_table = nfa_table;
}

DFA_Genertor::DFA_Genertor(void)
{
	/* nothing */
}

/* SETTERS AND GETTERS */
/*********************************************/
Transition_Table
DFA_Genertor::generate_minimized_dfa_table(void);
{
	/* 01 obtain DFA table */
	DFA_Table_Builder dfa_table_builder(nfa_machine);
	Transition_Table dfa_table = dfa_table_builder.generate_dfa_table();

	/* 02 minimize DFA table */
	//Table_Minimizer table_minimizer(dfa_table);
	//dfa_table = table_minimizer.minimize_table();

	return dfa_table;

}

