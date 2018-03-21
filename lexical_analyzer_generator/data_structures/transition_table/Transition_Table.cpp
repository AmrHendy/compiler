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

vector<Composite_State>
Transition_Table::get_start_states(){
    vector<Composite_State> res ;
    for (Row r : rows)
    {
        Composite_State id = r.get_id() ;
        if(id.is_accept_state())
        {
            res.push_back(id) ;
        }
    }
    return res ;
}

vector<Composite_State>
Transition_Table::get_end_states(){
    vector<Composite_State> res ;
    for (Row r : rows)
    {
        Composite_State id = r.get_id() ;
        if(!id.is_accept_state())
        {
            res.push_back(id) ;
        }
    }
    return res ;
}

/* INTERFACE METHODS */
/*********************************************/
void
Transition_Table::add_row(Composite_State id)
{
    if(!row_found(id))
        rows.push_back(Row(id)) ;
}

void
Transition_Table::add_row(Row r)
{
   rows.push_back(r) ;
}

Row
Transition_Table::get_row(Composite_State id)
{
    for(Row i : rows)
        if(i.id == id)
            return i ;
}

void
Transition_Table::add_transition (Composite_State id, char trans, State to )
{

    alphabet.insert(trans);

    if(!row_found(id))
        rows.push_back(Row(id)) ;

    for (Row i : rows)
    {
        if(i.id == id)
            i.transtions[trans].insert_new_state(to) ;
    }
}

void
Transition_Table::add_transition (Composite_State id, char trans, Composite_State to )
{

    alphabet.insert(trans);

    if(!row_found(id))
        rows.push_back(Row(id)) ;

    for (Row i : rows)
    {
        if(i.id == id)
            i.transtions[trans].insert_comp_state(to) ;
    }
}


Composite_State
Transition_Table::get_transition(Composite_State id, char trans){
    return get_row(id).transtions[trans] ;
}

bool
Transition_Table::row_found(Composite_State id)
{
    for(Row i : rows)
        if(i.id == id)
            return true ;
    return false ;
}


Transition_Table
Transition_Table::get_equavilent_table(vector<Partition> partitions){

    /* EQUAVILENT TABLE */
    Transition_Table equ ;

    for(Row r : rows){
        Composite_State essential_state = get_partition_belong(partitions , r.id).get_states()[0] ;
        /* STATE IS REDUNDANT */
        if(!(r.id == essential_state))
            continue ;
        /* REPLACE ALL STATES IN ROW WITH THIER ESSENTIAL STATES */
        for(char c : alphabet){
            Composite_State to = r.transtions[c] ;
            /* STATE TO NOT FOUND */
            if(to.get_states().empty())
                continue ;
            /* REPLACE STATE WITH IT'S ESSENTIAL */
            r.transtions[c] = get_partition_belong(partitions , to).get_states()[0] ;
        }
        /* ADD ROW TO EQU. TABLE */
        equ.add_row(r) ;
    }

    return equ ;
}

Partition
Transition_Table::get_partition_belong(vector<Partition> partitions , Composite_State c){
    /* LOOK FOR PARTITION STATE C BELONG TO */
    for (Partition p : partitions){
        if(p.belong(c))
            return p ;
    }
}

