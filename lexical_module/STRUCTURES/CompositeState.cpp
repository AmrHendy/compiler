#include "CompositeState.h"
#include <iostream>
#include "../GENERATORS/NumberGenerator.h"


CompositeState::CompositeState()
{
    this -> id = -1 ;
    this -> start = 0 ;
    this -> accept = 0 ;
}

CompositeState::CompositeState(set<State> states)
{
    for (State s : states)
    {
        add_state(s) ;
    }
}

CompositeState::~CompositeState()
{
    this->states.clear() ;
}

int
CompositeState::get_size()
{
    return this -> states.size() ;
}

bool
CompositeState::contains (State to_find)
{
    return states_ids[to_find.get_id()] ;
}

void
CompositeState::add_state(State new_state)
{
    if(new_state.is_acceptance())
    {
        rules.push_back(new_state.get_matched_rule()) ;
        accept = 1 ;
    }
    if(new_state.is_start())
        start = 1  ;
    if(states_ids[new_state.get_id()] == 0)
    {
        states_ids[new_state.get_id()] = 1;
        states.insert(new_state);
    }
}

void
CompositeState::add_states(set<State> new_state)
{
    for(State s : new_state)
        add_state(s) ;
}

void
CompositeState::add_states(CompositeState new_state)
{
    for(State s : new_state.get_states())
        add_state(s) ;
}

set<State>
CompositeState::get_states()
{
    return this -> states ;
}

CompositeState*
CompositeState::get_transition(char input)
{
    CompositeState* result = new CompositeState() ;
    for(State s : states)
    {
        for(int i=0 ; i < s.size_transition(input) ; i++)
        {
            State* to = s.get_transition(input,i) ;
            result->add_state(*to);
        }
    }
    return result ;
}

CompositeState*
CompositeState::find_equivalent_states(CompositeState start)
{
    CompositeState* result = new CompositeState();
    queue<State> q;
    for(State s : start.get_states())
    {
        q.push(s);
    }
    while(!q.empty())
    {
        State curr = q.front();
        q.pop();
        result->add_state(curr);
        vector<State*> epsilon_transitions = curr.get_transitions('\0');
        for(State* child : epsilon_transitions)
        {
            if(!result->contains(*child))
            {
                q.push(*child);
            }
        }
    }
    return result;
}


vector<Rule>
CompositeState::get_matched_rules()
{
    return rules ;
}

void
CompositeState::set_start()
{
    start = 1;
}

bool
CompositeState::is_acceptance()
{
    return accept ;
}

bool
CompositeState::is_start()
{
    return start ;
}

void
CompositeState::set_rules(vector<Rule> r)
{
    this->rules = r ;
}

vector<Rule>
CompositeState::get_rules()
{
    return this -> rules ;
}

bool
CompositeState::is_empty()
{
    return this->get_size() == 0 ;
}

void
CompositeState::set_id(int id)
{
    this -> id = id ;
}

int
CompositeState::get_id()
{
    return this -> id ;
}

bool
CompositeState::operator ==(CompositeState c)
{
    for(State s : c.get_states())
    {
        if(states_ids[s.get_id()] == 0)
            return false ;
    }
    return true ;
}

bool
CompositeState::operator !=(CompositeState c)
{
    for(State s : c.get_states())
    {
        if(states_ids[s.get_id()] == 0)
            return true ;
    }
    return false ;
}

void CompositeState::print()
{
    Logger::logger.print_string("\t\tcomp_state{ \n", Files::log_file) ;
    for(State s : states )
    {
        s.print() ;
    }
    Logger::logger.print_string("\n\t\t}", Files::log_file);
}

