#ifndef MACHINE_H_  /* Include guard */
#define MACHINE_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
#include "State.c"
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
    void tmp(void);

    /* setters and getters */
    State get_start(void);
    State get_end(void);
 
};


#endif // COMMANDS_H_