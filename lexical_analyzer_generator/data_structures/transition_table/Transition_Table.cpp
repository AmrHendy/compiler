/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
#include "Transition_Table.h"
using namespace std;

/* CONSTRUCTOR */
/*********************************************/
Transition_Table::Transition_Table(void)
{
	/* nothing */
}

Transition_Table::~Transition_Table(void)
{
	/* nothing */
}

/* INTERFACE METHODS */
/*********************************************/
void
Transition_Table::insert_new_row (Composite_State id_state)
{
	if(!row_found(id_state))
	{
	  this->rows.push_back(Row(id_state));
	}
}

void
Transition_Table::add_row_transition (Composite_State id_state, char input_char, Composite_State to_state)
{
	for (Row r : this->rows)
	{
	  if(r.id_state == id_state)
	  {
	      r.transitions.insert(pair(input_char, to_state));
	      break;

	  }
	}    
}


Composite_State
Transition_Table::find_transition(Composite_State from_state, char input)
{
	for(Row r:this->rows)
	{
		if(r.id_state == from_state)
		{
			return r.get_transitions().at(input);
		}
	}
	return NULL;
}


bool
Transition_Table::row_found(Composite_State id_state)
{
	for(Row r : this->rows)
	{
		if(r.id_state == id_state)
		{
			return true ;
		}
	}
	return false ;
}



Composite_State
Transition_Table::get_start_state(void)
{
	this->rows.front().get_id_state();
}


/*****************************************
	this function is not working properly
*****************************************/
Composite_State
Transition_Table::find_equivalent_states(Composite_State start)
{
	vector<Composite_State> result;
	vector<Composite_State> stack;
    stack.push_back(start);

    while(!stack.empty())
    {
    	Composite_State current = stack.back() ; stack.pop_back();
    	Composite_State next = find_transition(current, '\0');
    	if ( std::find(result.begin(), result.end(), next) != vector.end() )
        {continue;}
    	result.push_back(current);
    }


}



