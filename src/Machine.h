#ifndef MACHINE_H_
#define MACHINE_H_

#include "State.h"
#include "NumberGenerator.h"


class Machine
{
public:
    Machine(char character);
    Machine();
    virtual ~Machine();

    /* setters and getters */
    void set_start(State* start);
    State* get_start();
    void set_end(State* start);
    State* get_end();

//private:
	State *start;
	State *end;
};


#endif
