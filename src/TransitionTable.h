#ifndef TRANSITIONTABLE_H_  /* Include guard */
#define TRANSITIONTABLE_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
#include <vector>
#include "CompositeState.h"
#include "Row.h"

using namespace std;

/* CLASS DEFINITIONS */
/*********************************************/
class TransitionTable
{
	private:
	/* attributes */
	vector<Row> rows ;

	public:
	/* constructor */
    TransitionTable(void);
    virtual ~TransitionTable(void);

    /* interface functions */
    void insert_new_row(CompositeState id_state);
 	void add_row_transition (CompositeState id_state, char input_char, CompositeState to_state);
 	CompositeState find_transition(CompositeState from_state, char input);
 	bool row_found(CompositeState id_state);
 	CompositeState get_start_state(void);
};


#endif
