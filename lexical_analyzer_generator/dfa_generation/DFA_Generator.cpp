/* INCLUDE HEADER */
/*********************************************/
#include "DFA_Genertor.h"

/* CONSTRUCTOR */
/*********************************************/
DFA_Genertor::DFA_Genertor(Machine nfa_machine)
{
   this->nfa_machine = nfa_machine;
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


}

