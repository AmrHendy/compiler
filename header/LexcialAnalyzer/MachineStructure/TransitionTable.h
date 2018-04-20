#ifndef TRANSITIONTABLE_H_  /* Include guard */
#define TRANSITIONTABLE_H_

/* IMPORT LIBRARIES */

/** ****************************************** */

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include "CompositeState.h"
#include "Row.h"
#include "Partition.h"
#include "../Helper/Alpha.h"

using namespace std;

/* CLASS DEFINITIONS */
/*********************************************/
class TransitionTable
{
public:
	/* constructor */
    TransitionTable(void);
    virtual ~TransitionTable(void);

    /* interface functions */
    void insert_new_row(CompositeState* id_state);
    void insert_new_row(Row* row);
    void add_row_transition (CompositeState* id_state, char input_char, CompositeState to_state);
 	CompositeState* find_transition(CompositeState* from_state, char input);
    CompositeState* get_transition(CompositeState* id, char trans);
 	CompositeState* get_start_state(void);
    vector<CompositeState*> get_acceptance_states();
    vector<CompositeState*> get_non_acceptance_states();
    Row* get_row(CompositeState* id);
    TransitionTable get_equavilent_table(vector<Partition> partitions) ;
 	bool row_found(CompositeState* id_state);

private:
	/* attributes */
	vector<Row*> rows ;
    Partition get_partition_belong(vector<Partition> partitions, CompositeState* c);

};
#endif
