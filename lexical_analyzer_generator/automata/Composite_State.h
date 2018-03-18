#ifndef COMPOSITE_STATE_H_  /* Include guard */
#define COMPOSITE_STATE_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
using namespace std;

/* CLASS DEFINITIONS */
/*********************************************/
class Composite_State
{
	private:
	/* attributes */
	set<State> states;


	public:
	/* constructor */
    State(void);   // This is the constructor declaration
    ~State(void);  // This is the destructor: declaration

    /* interface functions */
    void add_transition(pair<State,char>);
    vector<State> get_char_transtions(char trans);

    /* setters and getters */


};


#endif // COMMANDS_H_
