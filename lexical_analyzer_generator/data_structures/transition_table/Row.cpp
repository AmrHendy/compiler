/* IMPORT LIBRARIES */
/*********************************************/
#include "Row.h"

/* CONSTRUCTOR */
/*********************************************/
Row::Row(Composite_State id_state)
{
	this->id_state = id_state ;
} 

Row::~Row(void)
{
	/* nothing */
}

/* INTERFACE METHODS */
/*********************************************/
map<char,Compl_state>
Row::get_transitions(void)
{
	return this->transitions;
}

Compl_state
Row::get_id_state(void)
{
	return this->id_state;
}