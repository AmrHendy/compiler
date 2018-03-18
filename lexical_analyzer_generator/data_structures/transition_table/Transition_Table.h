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
 	bool row_found(Composite_State id_state);

	//void add_transition (Composite_State id , char trans , state to );


};


#endif