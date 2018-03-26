#ifndef TRANSITIONTABLE_H_  /* Include guard */
#define TRANSITIONTABLE_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
#include <vector>
#include "CompositeState.h"
#include "Row.h"
#include "../GENERATORS/Alpha.h"

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
    int size() ;
    void insert_new_row(Row* row);
    void insert_new_row(CompositeState* id_state);
    bool row_found(CompositeState id_state);
    Row* get_row(int index) ;


    void add_transition (CompositeState id , char input_char, CompositeState* to_state);
    CompositeState* get_transition(CompositeState id , char trans);
    CompositeState* get_start_state(void) ;

    vector<CompositeState*> get_acceptance_states() ;
    vector<CompositeState*> get_non_acceptance_states() ;

    void print(string s) ;

private:
	/* attributes */
	vector<Row*> rows ;
};

#endif

    //Partition get_partition_belong(vector<Partition> partitions, CompositeState* c);
	//  TransitionTable get_equavilent_table(vector<Partition> partitions) ;
