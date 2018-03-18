#ifndef COMPOSITE_STATE_H_  /* Include guard */
#define COMPOSITE_STATE_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "State.h"
#include <vector>

/* CLASS DEFINITIONS */
/*********************************************/
class Composite_State
{
	private:
	/* attributes */
	vector <State> states;

	public:
	/* constructor */
    State(void);
    ~State(void);

    /* interface functions */
    void insert_new_state(State new_state);
    Composite_State get_transition(char input);
    Composite_State find_equivalent_states(Composite_State start);
    vector<State> get_states(void);

    /*void add_transition(pair<State,char>);
    vector<State> get_char_transtions(char trans);*/

    private:
    /* utility functions */
    Composite_State vector_to_composite(vector<State> states);




};


#endif
