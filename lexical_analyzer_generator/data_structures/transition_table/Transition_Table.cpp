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

/* getters and setters */
set<char> Transition_Table::get_alphabet()
{
   return alphabet ;
}



/* INTERFACE METHODS */
/*********************************************/
void
Transition_Table::add_row(Composite_State id){
	if(!row_found(id))
	  rows.push_back(Row(id)) ;
}

void
Transition_Table::add_transition (Composite_State id , char trans , State to ){

	alphabet.insert(trans);

	if(!row_found(id))
	  rows.push_back(Row(id)) ;

	for (Row i : rows){
	  if(i.id == id)
	      i.transtions[trans].insert_new_state(to) ;
	}
}

void
Transition_Table::add_transition (Composite_State id , char trans , Composite_State to ){

	alphabet.insert(trans);

	if(!row_found(id))
	  rows.push_back(Row(id)) ;

	for (Row i : rows){
	  if(i.id == id)
	      i.transtions[trans].insert_comp_state(to) ;
	}
}

bool
Transition_Table::row_found(Composite_State id){
	for(Row i : rows)
	  if(i.id == id)
	    return true ;
	return false ;
}
