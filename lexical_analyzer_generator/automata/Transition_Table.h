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
    Transition_Table(void);   // This is the constructor declaration
    ~Transition_Table(void);  // This is the destructor: declaration

    /* interface functions */
    void add_row(Compl_state id);
 	void add_transition (Compl_state id , char trans , state to );
 	void add_transition (Compl_state id , char trans , Compl_state to );
 	bool row_found(Compl_state id);


};


#endif // COMMANDS_H_