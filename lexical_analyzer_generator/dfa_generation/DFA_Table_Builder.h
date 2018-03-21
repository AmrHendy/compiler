#ifndef DFA_TABLE_BUILDER_H_  /* Include guard */
#define DFA_TABLE_BUILDER_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "../data_structures/automata/Machine.h"
#include "../data_structures/transition_table/Transition_Table.h"
#include "../data_structures/transition_table/Composite_State.h"
#include "Partition.h"
#include "vector"
#include <algorithm>

/* CLASS DEFINITIONS */
/*********************************************/
class DFA_Table_Builder
{
private:
    /* ATTRIBUTES */
    Transition_Table nfa_table; // not used till now

public:
    /* CONSTRUCTOR */
    DFA_Table_Builder(Transition_Table nfa_table);  //not used till now
    ~DFA_Table_Builder(void);

    /* INTERFACE FUNCTIONS */
    Transition_Table generate_dfa_table(void);
    Transition_Table minimize_dfa_table(Transition_Table dfa_table);


private:
    /* PRIVATE FUNCTIONS */
    bool re_partition(vector<Partition>* partitions , Transition_Table dfa_table );
    Partition get_partition_belong(vector<Partition> partitions , Composite_State c);
    void generate_partition_ids
        (vector<Partition> all_partitions , Partition* partition , Transition_Table dfa_table );


};


#endif
