#ifndef MACHINE_H_  /* Include guard */
#define MACHINE_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "State.h"
#include <utility>

/* CLASS DEFINITIONS */
/*********************************************/
class Machine
{
	private:
	/* attributes */
	State start;
    State end;

	public:
	/* constructor */
    Machine(char character);
    Machine(void);
    ~Machine(void);

    /* setters and getters */
    void set_start(State start);
    State get_start(void);
    void set_end(State start);
    State get_end(void);

    /* interface functions */
    /*void add_transition_start(pair<State,char>) ;
    void add_transition_end(pair<State,char>) ;*/

};


#endif
