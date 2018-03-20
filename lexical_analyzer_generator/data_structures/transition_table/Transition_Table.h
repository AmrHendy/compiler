#ifndef TRANSITION_TABLE_H_  /* Include guard */
#define TRANSITION_TABLE_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
using namespace std;

/* CLASS DEFINITIONS */
/*********************************************/
class Transition_Table
{
	private:
	/* attributes */
	vector<Row> rows ;
  	set<char> alphabet ;

	public:
	/* constructor */
    Transition_Table(void);
    ~Transition_Table(void);

    /* interface functions */
    void insert_new_row(Composite_State id_state);
 	void add_row_transition (Composite_State id_state, char input_char, Composite_State to_state);
 	Composite_State find_transition(Composite_State from_state, char input);
 	bool row_found(Composite_State id_state);

 	Composite_State get_start_state(void);
 	Composite_State find_equivalent_states(Composite_State start);


};


#endif