#ifndef DFATABLEBUILDER_H_  /* Include guard */
#define DFATABLEBUILDER_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "../STRUCTURES/Machine.h"
#include "../STRUCTURES/TransitionTable.h"
#include "../STRUCTURES/CompositeState.h"
#include "../GENERATORS/Alpha.h"
#include "../STRUCTURES/Partition.h"
#include "DfaTableMin.h"
#include <algorithm>


/* CLASS DEFINITIONS */
/*********************************************/
class DFATableBuilder
{
public:
    /* constructor */
    DFATableBuilder(Machine nfa_machine);
    virtual ~DFATableBuilder(void);

    /* interface functions */
    TransitionTable generate_dfa_table(void);
    TransitionTable minimize_dfa_table(TransitionTable dfa_table);


private:
    /* attributes */
    Machine nfa_machine;
};


#endif
