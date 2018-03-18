#ifndef NFA_TABLE_BUILDER_H_  /* Include guard */
#define NFA_TABLE_BUILDER_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
using namespace std;

/* CLASS DEFINITIONS */
/*********************************************/
class NFA_Table_Builder
{
	private:
	/* attributes */
	Machine nfa_machine;

	public:
	/* constructor */
    NFA_Table_Builder(void);   // This is the constructor declaration
    ~NFA_Table_Builder(void);  // This is the destructor: declaration

    /* interface functions */
    void generate_nfa_table(void);
 
};


#endif // COMMANDS_H_