#ifndef COMPOSITE_STATE_H_  /* Include guard */
#define COMPOSITE_STATE_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "State.h"

/* CLASS DEFINITIONS */
/*********************************************/
class Composite_State
{
	private:
	/* attributes */
	set <State> states;

	public:
	/* constructor */
    State(void);
    ~State(void);

    /* interface functions */
    bool insert_new_state(State new_state);
    Composite_State get_transition(char input);

    void add_transition(pair<State,char>);
    vector<State> get_char_transtions(char trans);


};


#endif
