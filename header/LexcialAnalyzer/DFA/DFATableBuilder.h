#ifndef DFATABLEBUILDER_H_  /* Include guard */
#define DFATABLEBUILDER_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "../MachineStructure/Machine.h"
#include "../MachineStructure/TransitionTable.h"
#include "../MachineStructure/CompositeState.h"
#include "../MachineStructure/Partition.h"
#include "../Helper/Alpha.h"
#include <algorithm>



/* CLASS DEFINITIONS */
/*********************************************/
class DFATableBuilder
{
	public:
	/* constructor */
    DFATableBuilder(Machine* nfa_machine);
    virtual ~DFATableBuilder(void);

    /* interface functions */
	TransitionTable generate_dfa_table(void);
	TransitionTable minimize_dfa_table(TransitionTable dfa_table);


private:
	/* attributes */
	Machine* nfa_machine;

	bool re_partition(vector<Partition>* partitions , TransitionTable dfa_table);
	void generate_partition_ids(vector<Partition> all_partitions , Partition* partition , TransitionTable dfa_table );
	Partition get_partition_belong(vector<Partition> partitions , CompositeState* c);
};


#endif
