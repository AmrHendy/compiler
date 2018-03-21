#ifndef MACHINE_H_
#define MACHINE_H_

#include "State.h"

class Machine
{
public:
    Machine(char character);
    virtual ~Machine(void);

    /* setters and getters */
    void set_start(State start);
    State get_start(void);
    void set_end(State start);
    State get_end(void);

private:
	State start;
	State end;
};


#endif
