/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
#include "Composite_State.h"
using namespace std;

/* CONSTRUCTOR */
/*********************************************/
Composite_State::Composite_State(void)
{
	/* nothing */
} 

Composite_State::~Composite_State(void)
{
	/* nothing */
}

/* INTERFACE METHODS */
/*********************************************/
bool
operator == (const Compl_state& c)
{
	set<State> c_states = c.get_states() ;
	for(State i : c_states){
	  if(this->states.count(i) == 0)
	    return false ;
	}
	return true ;
}

set<State>
get_states(void)
{
	return this->states;
}

void
add_state(Compl_state n)
{
	for(State i : n.states)
	{
		this-> states.insert(i) ;
	}
}

void
add_state(state n)
{
	this-> states.insert(n) ;  
}

void
add_states(vector<State> states)
{
	for(State i : states){
	  states.insert(i) ;
	}
}