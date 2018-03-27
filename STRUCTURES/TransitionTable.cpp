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

int
TransitionTable::size(){
	return this -> rows.size() ;
}

void
TransitionTable::insert_new_row (Row* r)
{
	if(!row_found(*r->get_id_state()))
	{
	  rows.push_back(r);
	}
}

void
TransitionTable::insert_new_row (CompositeState* id_state)
{
	rows.push_back(new Row(id_state));
}

bool
TransitionTable::row_found(CompositeState id){
	for (Row* r : rows)
		if(*r->get_id_state() == id)
			return true ;
	return false ;
}

Row*
TransitionTable::get_row(int index){
	return rows[index] ;
}

void
TransitionTable::add_transition (CompositeState id_state, char input_char, CompositeState* to_state)
{
	if(id_state.get_size() == 0 || to_state == nullptr || to_state->get_size() == 0)
		return ;

	for (Row* r : this->rows)
	{
	  if(*r->get_id_state() == id_state)
	  {
		  r->insert_transition(input_char, to_state);
	      break;
	  }
	}
}

CompositeState*
TransitionTable::get_transition(CompositeState from_state, char input)
{
	for(Row* r : rows)
	{
		if( *r->get_id_state() == from_state )
		{
			return r->get_transition(input);
		}
	}
	return new CompositeState() ;
}

CompositeState*
TransitionTable::get_start_state(void)
{
	for (Row* r : rows)
	{
		if(r->get_id_state()->is_start())
			return r->get_id_state();
	}
	return new CompositeState() ;
}

vector<CompositeState*>
TransitionTable::get_acceptance_states(){
    vector<CompositeState*> res ;
    for (Row* r : rows)
    {
        CompositeState* id = r->get_id_state() ;
        if(id->is_acceptance())
        {
            res.push_back(id) ;
        }
    }
    return res ;
}

vector<CompositeState*>
TransitionTable::get_non_acceptance_states(){
    vector<CompositeState*> res ;
    for (Row* r : rows)
    {
        CompositeState* id = r->get_id_state() ;
        if(!id->is_acceptance())
        {
            res.push_back(id) ;
        }
    }
    return res ;
}


void
TransitionTable::print(string s) {
	Logger::print_string(s + "\n\t" , Files::tables_file) ;
	char dcare = '~' ;
	for(char c : Alpha::alpha)
		if(c!='\0')
			Logger::print_string(patch::to_string(c) + "\t" , Files::tables_file) ;
		else
			Logger::print_string(patch::to_string(dcare) + "\t" , Files::tables_file) ;
	Logger::print_string("\n" , Files::tables_file) ;
	for(Row* r : rows){
		r->print() ;
	}
	Logger::print_string("\n -------------------------- \n" , Files::tables_file) ;
}


