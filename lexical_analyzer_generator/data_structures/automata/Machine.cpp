/* INCLUDE HEADER */
/*********************************************/
#include "Machine.h"

/* CONSTRUCTOR */
/*********************************************/
Machine::Machine(char basic_char)
{
    /* constructor for the single character machine */
    this->start.add_transition(basic_char, this->end);
}

Machine::Machine(void)
{

}


Machine::~Machine(void)
{

}

/* SETTERS AND GETTERS */
/*********************************************/
State
Machine::get_start(void)
{
    return this-> start ;
}

State
Machine::get_end(void)
{
    return this-> end ;
}

void
Machine::set_start(State start)
{
    this->start = start ;
}

void
Machine::set_end(State start)
{
    this->end = end ;
}


/* INTERFACE METHODS */
/*********************************************/
/*void Machine::add_transition_start(pair<State, char> transition)
{
    this->start.add_transition(transition) ;
}

void Machine::add_transition_end(pair<State, char> transition)
{
    this->end.add_transition(transition) ;
}
*/
