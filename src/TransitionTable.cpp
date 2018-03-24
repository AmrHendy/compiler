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
TransitionTable::insert_new_row (CompositeState* id_state)
{
	if(!row_found(id_state))
	{
	  rows.push_back(new Row(id_state));
	}
}


void
TransitionTable::add_row_transition (CompositeState* id_state, char input_char, CompositeState to_state)
{
	for (Row* r : this->rows)
	{
	  if(*(r->get_id_state()) == *id_state)
	  {
		  r->insert_transition(input_char, to_state);
	      break;
	  }
	}
}


CompositeState*
TransitionTable::find_transition(CompositeState* from_state, char input)
{
	for(Row* r : rows)
	{
		if(*(r->get_id_state()) == (*from_state))
		{
			return r->get_destination_state(input);
			//return &(r->get_transitions()[input]);
		}
	}
	return NULL;
}


bool
TransitionTable::row_found(CompositeState* id_state)
{
	for(Row* r : this->rows)
	{
		if(*(r->get_id_state()) == *id_state)
		{
			return true ;
		}
	}
	return false ;
}



CompositeState*
TransitionTable::get_start_state(void)
{
	return rows[0]->get_id_state();
}

void
TransitionTable::insert_new_row(Row* r)
{
   rows.push_back(r);
}


Row*
TransitionTable::get_row(CompositeState* id)
{
    for(Row* i : rows){
        if(*(i->get_id_state()) == (*id)){
        	return i ;
        }
    }
}

CompositeState*
TransitionTable::get_transition(CompositeState* id, char trans){
    return &(get_row(id)->get_transitions()[trans]);
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

TransitionTable
TransitionTable::get_equavilent_table(vector<Partition> partitions){

    /* EQUAVILENT TABLE */
    TransitionTable equ ;

    for(Row* r : rows){
        CompositeState* essential_state = get_partition_belong(partitions , r->get_id_state()).get_states()[0] ;
        /* STATE IS REDUNDANT */
        if(!(*(r->get_id_state()) == (*essential_state)))
            continue ;
        /* REPLACE ALL STATES IN ROW WITH THIER ESSENTIAL STATES */
        for(char c : Alpha::getAlphabet()){
            CompositeState* to = &((r->get_transitions())[c]);
            /* STATE TO NOT FOUND */
            if(to->get_states().empty())
                continue ;
            /* REPLACE STATE WITH IT'S ESSENTIAL */
            r->get_transitions()[c] = *(get_partition_belong(partitions , to).get_states()[0]) ;
        }
        /* ADD ROW TO EQU. TABLE */
        equ.insert_new_row(r) ;
    }
    return equ ;
}


Partition
TransitionTable::get_partition_belong(vector<Partition> partitions , CompositeState* c){
    /* LOOK FOR PARTITION STATE C BELONG TO */
    for (Partition p : partitions){
        if(p.belong(c))
            return p;
    }
    return NULL;
}
