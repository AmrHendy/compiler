#ifndef ROW_H_  /* Include guard */
#define ROW_H_

/* IMPORT LIBRARIES */

/** ****************************************** */

#include "CompositeState.h"
#include <map>

/* CLASS DEFINITIONS */
/*********************************************/
class Row
{
	private:
	/* attributes */
	CompositeState* id_state;
  	map<char,CompositeState> transitions;

	public:
	/* constructor */
    Row(CompositeState* id_state);
    virtual ~Row(void);

    /* interface functions */
    map<char,CompositeState> get_transitions(void);
    CompositeState* get_id_state(void);

    void insert_transition(char input_char, CompositeState s);

    CompositeState* get_destination_state(char ch);

};

#endif
