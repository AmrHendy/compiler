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
add_row(Compl_state id){
	if(!row_found(id))
	  rows.add(Row(id)) ;
}

void
add_transition (Compl_state id , char trans , state to ){

	alphabet.insert(trans);

	if(!row_found(id))
	  rows.add(Row(id)) ;

	for (Row i : rows){
	  if(i.id == id)
	      i.transtions[trans].add_state(to) ;
	}    
}

void
add_transition (Compl_state id , char trans , Compl_state to ){

	alphabet.insert(trans);

	if(!row_found(id))
	  rows.add(Row(id)) ;

	for (Row i : rows){
	  if(i.id == id)
	      i.transtions[trans].add_state(to) ;
	}    
}

bool
row_found(Compl_state id){
	for(Row i : rows)
	  if(i.id == id)
	    return true ;
	return false ;
}