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
map<char,CompositeState>
Row::get_transitions(void)
{
	return transitions;
}


CompositeState*
Row::get_id_state(void)
{
	return id_state;
}


void
Row::insert_transition(char input_char, CompositeState s)
{
	transitions[input_char] = s;
}


CompositeState* Row::get_destination_state(char ch){
	return &(transitions[ch]);
}

