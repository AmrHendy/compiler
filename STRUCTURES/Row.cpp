/* IMPORT LIBRARIES */
/*********************************************/
#include "Row.h"
#include <iostream>
/* CONSTRUCTOR */
/*********************************************/
Row::Row(CompositeState* id_state)
{
	Row::id_state = id_state ;
}

Row::~Row(void)
{
	/* nothing */
}

/* INTERFACE METHODS */
/*********************************************/
CompositeState*
Row::get_transition(char input)
{
	if(transitions[input] != nullptr)
		return transitions[input] ;
	return new CompositeState() ;
}

void
Row::set_transition(char alpha , CompositeState* c){
	transitions[alpha] = c ;
}

CompositeState*
Row::get_id_state(void)
{
	return id_state;
}

void
Row::insert_transition(char input_char, CompositeState* s)
{
	transitions[input_char] = s;
}
