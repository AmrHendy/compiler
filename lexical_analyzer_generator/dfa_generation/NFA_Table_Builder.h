#ifndef NFA_TABLE_BUILDER_H_  /* Include guard */
#define NFA_TABLE_BUILDER_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
#include "lexical_analyzer_generator/data_structures/automata/Machine.h"

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
    NFA_Table_Builder(Machine nfa_machine);   // This is the constructor declaration
    ~NFA_Table_Builder(void);  // This is the destructor: declaration

    /* interface functions */
    void generate_nfa_table(void);

};


#endif // COMMANDS_H_
