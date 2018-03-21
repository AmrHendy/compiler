/* INCLUDE HEADER */
/*********************************************/
#include "Composite_State.h"
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std ;


/* CONSTRUCTOR */
/*********************************************/
Composite_State::Composite_State(void)
{
    /* nothing */
}

Composite_State::~Composite_State(void)
{
    /* nothing */
}

Composite_State::Composite_State(vector<State>states)
{
    for (State s : states)
        this-> insert_new_state(s) ;
}


Composite_State::Composite_State(State state)
{
    this -> states.push_back(state) ;
}


/* INTERFACE METHODS */
/*********************************************/

bool Composite_State::is_accept_state()
{
    vector<State> id_states = this -> get_states() ;
    for (State s : id_states)
        if(s.is_acceptance())
        {
            return true ;
        }
    return false ;
}




void
Composite_State::insert_new_state(State new_state)
{
    if( find(states.begin(), states.end(), new_state) == states.end() )
        this->states.push_back(new_state);
}

void
Composite_State::insert_comp_state(Composite_State new_state)
{
    vector<State> to_add = new_state.get_states() ;
    for(State s : to_add)
        if( find(states.begin(), states.end(), s) == states.end() )
            this->states.push_back(s);
}

Composite_State
Composite_State::get_transition(char input)
{
    vector<State> result;
    for(State s:states)
    {
        vector<State> transitions = s.get_transition(input);
        for(State next : transitions)
        {
            if ( find( result.begin(), result.end(), next ) != result.end() )
            {
                continue;
            }
            result.push_back(next);
        }
    }
    return vector_to_composite(result);
}

Composite_State
Composite_State::find_equivalent_states()
{
    /*
    * this function finds all states reachable by "epsilon" from given state
    */
    vector<State> result;
    vector<State> start_states = this->get_states();
    for(State s:start_states)
    {
        vector<State> stack;
        stack.push_back(s);
        while(!stack.empty())
        {
            State current = stack.back() ;
            stack.pop_back();
            result.push_back(current);
            vector<State> epsilon_transitions = current.get_transition('\0');

            for(State next:epsilon_transitions)
            {
                if ( find(result.begin(), result.end(), next) != result.end() )
                {
                    continue;
                }
                stack.push_back(next);
            }
        }

    }

    return vector_to_composite(result);


}


vector<State>
Composite_State::get_states(void)
{
    return this->states;
}

bool
Composite_State::operator == (Composite_State& c)
{
    vector<State> c_states = c.get_states() ;
    for(State i : c_states)
    {
        if( find(states.begin(), states.end(), i) != states.end() )
            return false ;
    }
    return true ;
}


/* UTILITY FUNCTIONS */
/*********************************************/
Composite_State
Composite_State::vector_to_composite(vector<State> states)
{
    Composite_State* result = new Composite_State(states) ;
    return *result;
}
