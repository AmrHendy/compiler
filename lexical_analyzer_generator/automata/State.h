#ifndef STATE_H_  /* Include guard */
#define STATE_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
#include <list>
#include <utility>
#include "State.h"

using namespace std;

/* CLASS DEFINITIONS */
/*********************************************/
class State
{
	private:
	/* attributes */
	list<pair<State,char>> transitions;
	bool acceptance;
    char* token_value;


	public:
	/* constructor */
    State(void);   // This is the constructor declaration
    ~State(void);  // This is the destructor: declaration

    /* interface functions */
    void add_transition(pair<State,char>);

    /* setters and getters */


};


#endif // COMMANDS_H_
