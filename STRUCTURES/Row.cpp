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

Row::Row(void)
{
	this->id_state = new CompositeState();
    /* nothing */
}


Row::~Row(void)
{
    /* nothing */
}

/* INTERFACE METHODS */
/*********************************************/
CompositeState*
Row::get_transition(char input)
{
    if(transitions[input] != nullptr)
        return transitions[input] ;
    return new CompositeState() ;
}

void
Row::set_transition(char alpha, CompositeState* c)
{
    transitions[alpha] = c ;
}

CompositeState*
Row::get_id_state(void)
{
    return id_state;
}

void
Row::insert_transition(char input_char, CompositeState* s)
{
    transitions[input_char] = s;
}


void
Row::print()
{
    int id_st = id_state->get_id() ;
    Logger::print_string(patch::to_string(id_st) + "\t", Files::tables_file ) ;
    for(char c : Alpha::getAlphabet() )
    {
        CompositeState* s = get_transition(c) ;
        id_st = s->get_id() ;
        if(id_st == -1)
            Logger::print_string("-\t", Files::tables_file ) ;
        else
            Logger::print_string(patch::to_string(id_st) + "\t", Files::tables_file ) ;
    }
    Logger::print_string("\n",Files::tables_file);
}

