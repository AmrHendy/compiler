/* INCLUDE HEADER */
/*********************************************/
#include "State.h"

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
	Composite_State to_states = transitions.find(input);
	if(to_states==NULL)
	{
		// input was not found
		Composite_State tmp=malloc(sizeof(Composite_State));
		tmp.insert_new_state(to_state);
		transitions.insert({input, tmp});
	}
	else
	{
		// input was found
		to_states.insert_new_state(to_state);
	}
}

Composite_State
State::get_transition(char input)
{
	return transitions.find(input);
}

/* SETTERS AND GETTERS */
/*********************************************/
void
State::set_acceptance(bool value)
{
	this.acceptance_state = value;
}

bool
State::is_acceptance(void)
{
	return this.acceptance_state;
}

void
State::set_token(Token matched_token)
{
	this.matched_token = matched_token;
}

Token
State::get_token(void)
{
	return this.matched_token;
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