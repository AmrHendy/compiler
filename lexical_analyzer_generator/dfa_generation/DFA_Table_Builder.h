#ifndef DFA_TABLE_BUILDER_H_  /* Include guard */
#define DFA_TABLE_BUILDER_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
using namespace std;

/* CLASS DEFINITIONS */
/*********************************************/
class DFA_Table_Builder
{
	public:
	/* constructor */
    DFA_Table_Builder(void);   // This is the constructor declaration
    ~DFA_Table_Builder(void);  // This is the destructor: declaration

    /* interface functions */
	void generate_dfa_table(State start);    
	Complex_State get_epsilon_transition(Complex_State start);
 
};


#endif // COMMANDS_H_