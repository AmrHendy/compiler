/* IMPORT LIBRARIES */
/*********************************************/
#include "Row.h"

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
map<char,CompositeState*>
Row::get_transitions(void)
{
	return transitions;
}


CompositeState*
Row::get_id_state(void)
{
	return id_state;
}
