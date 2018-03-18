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
insert_new_row (Composite_State id_state)
{
	if(!row_found(id_state))
	{
	  this->rows.push_back(Row(id_state));
	}
}

void
add_row_transition (Composite_State id_state, char input_char, Composite_State to_state)
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

bool
row_found(Composite_State id_state)
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