#ifndef MACHINE_H_  /* Include guard */
#define MACHINE_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
#include <utility>
#include "State.h"


using namespace std;

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
    Machine(char character);   // This is the constructor declaration
    ~Machine(void);  // This is the destructor: declaration

    /* interface functions */
    void add_transition_start(pair<State,char>) ;
    void add_transition_end(pair<State,char>) ;

    /* setters and getters */
    State get_start(void);
    State get_end(void);
    void set_start(State start);
    void set_end(State start);

    /* overloading operators */
    Machine operator | (Machine& m) ;
    Machine operator * (Machine& m) ;
    Machine kleen_closure (Machine& m) ;
    Machine postive_closure (Machine& m) ;


};


#endif // COMMANDS_H_
