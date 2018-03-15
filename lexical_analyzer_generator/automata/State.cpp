/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
#include "State.h"

using namespace std;


/* CONSTRUCTOR */
/*********************************************/
State::State(void)
{

}

State::~State(void)
{

}

/* SETTERS AND GETTERS */
/*********************************************/


/* INTERFACE METHODS */
/*********************************************/
void State::add_transition(pair<State, char> transition)
{
    this->transitions.push_back(transition) ;
}

