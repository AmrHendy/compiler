/* INCLUDE HEADER */
/*********************************************/
#include "State.h"
#include <algorithm>
#include "lexical_analyzer_generator/data_structures/transition_table/Composite_State.h"

/* CONSTRUCTOR */
/*********************************************/
State::State(void)
{
    /* nothing */
}

State::~State(void)
{
    /* nothing */
}

/* INTERFACE METHODS */
/*********************************************/
void
State::add_transition(char input, State to_state)
{
    transitions[input].push_back(to_state) ;
}

vector<State>
State::get_transition(char input)
{
    return transitions[input] ;
}

map<char,vector<State>>
State::get_all_transitions(){
    return this->transitions ;
}


/* SETTERS AND GETTERS */
/*********************************************/
void
State::set_acceptance(bool value)
{
    this->acceptance_state = value;
}

bool
State::is_acceptance(void)
{
    return this->acceptance_state;
}

void
State::set_token(Token matched_token)
{
    this->matched_token = matched_token;
}

Token
State::get_token(void)
{
    return this->matched_token;
}


/* operators */
/*******************************************/

bool
State::operator == (const State& s){
    map<char,vector<State>> transitions_1 =  s.transitions ;
    map<char,vector<State>> transitions_2 = this->transitions ;

    for(pair<char,vector<State>> i : transitions_1){
        vector<State> v1 = transitions_2[i.first] ;
        vector<State> v2 = i.second ;

        if(v1.size() != v2.size())
            return false ;
        else{
            for(State s : v1)
                    if( find(v2.begin() , v2.end() , s) == v2.end() )
                        return false ;
        }
    }
    return true ;
}



/*
void
State::add_transition(pair<State, char> transition)
{
    this->transitions.push_back(transition) ;
}


vector<State> get_char_transtions(char trans){
	vector<State> res ;
	vector<pair<State,char>> transtions = this->get_transitions() ;
	for(pair<State,char> i : transitions ){
			  	if(i.second == trans)
	        res.push_back(i.first) ;
	}
	return res ;
}
*/
