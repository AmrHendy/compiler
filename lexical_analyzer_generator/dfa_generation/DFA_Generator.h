#ifndef DFA_GENERATOR_H_  /* Include guard */
#define DFA_GENERATOR_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
using namespace std;

/* CLASS DEFINITIONS */
/*********************************************/
class DFA_Generator
{
	public:
	/* constructor */
    DFA_Generator(Transition_Table dfa_table);   // This is the constructor declaration
    ~DFA_Generator(void);  // This is the destructor: declaration

    /* interface functions */
    Transition_Table generate_minimized_dfa_table();
    
 
};


#endif // COMMANDS_H_