/* IMPORT LIBRARIES */
/*********************************************/
#include "TransitionTable.h"
using namespace std;

/* CONSTRUCTOR */
/*********************************************/
TransitionTable::TransitionTable(void)
{
	/* nothing */
}

TransitionTable::~TransitionTable(void)
{
	/* nothing */
}

/* INTERFACE METHODS */
/*********************************************/
void
TransitionTable::insert_new_row (CompositeState id_state)
{
	if(!row_found(id_state))
	{
	  rows.push_back(Row(id_state));
	}
}


void
TransitionTable::add_row_transition (CompositeState id_state, char input_char, CompositeState to_state)
{
	for (Row r : this->rows)
	{
	  if(r.get_id_state() == id_state)
	  {
	      r.get_transitions()[input_char] = to_state;
	      break;

	  }
	}
}


CompositeState
TransitionTable::find_transition(CompositeState from_state, char input)
{
	for(Row r:this->rows)
	{
		if(r.get_id_state() == from_state)
		{
			return r.get_transitions().at(input);
		}
	}
	return CompositeState();
}


bool
TransitionTable::row_found(CompositeState id_state)
{
	for(Row r : this->rows)
	{
		if(r.get_id_state() == id_state)
		{
			return true ;
		}
	}
	return false ;
}



CompositeState
TransitionTable::get_start_state(void)
{
	return rows.front().get_id_state();
}
