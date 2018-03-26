#ifndef MACHINE_H_
#define MACHINE_H_

#include "../GENERATORS/NumberGenerator.h"
#include "State.h"
#include "../LOGGER/Logger.h"


class Machine
{
public:
	Machine();
    Machine(char character);
    virtual ~Machine();

    /* setters and getters */
    void set_start(State* start);
    State* get_start();
    void set_end(State* start);
    State* get_end();

    /* Logging */
    void print();

private:
	State* start = new State(-1);
	State* end = new State(-1);
};


#endif
