#ifndef NFA_GENERATOR_H_  /* Include guard */
#define NFA_GENERATOR_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
using namespace std;

/* CLASS DEFINITIONS */
/*********************************************/
class NFA_Generator
{
	public:
	/* constructor */
    NFA_Generator(vector<Rule> processed_rules);   // This is the constructor declaration
    ~NFA_Generator(void);  // This is the destructor: declaration

    /* interface functions */
    Transition_Table generate_nfa_table();
 
};


#endif // COMMANDS_H_