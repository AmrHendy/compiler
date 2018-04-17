#ifndef DFATABLEBUILDER_H_  /* Include guard */
#define DFATABLEBUILDER_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "../MachineStructure/Machine.h"
#include "../MachineStructure/TransitionTable.h"
#include "../MachineStructure/CompositeState.h"
#include "../MachineStructure/Partition.h"
#include "../Helper/Alpha.h"
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
