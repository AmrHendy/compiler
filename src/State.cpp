#include "State.h"

State::State()
{
	start_state = false;
	acceptance_state = false;
}

State::~State()
{

}

/* Epsilon transition will be on form {'\0', nextState}. */
void State::add_transition(char input, State to_state){
	//??
	//we don't need this as map don't return null pointer ever.
	//in case of that input not found it will return empty vector (size = 0) but not null
	/*
	if(to_states==NULL)
	{
		// input was not found
		vector<State> tmp=malloc(sizeof(vector<State>));
		tmp.push_back(to_state);
		transitions.insert({input, tmp});
	}*/
	//else
	//{
		// input was found
		transitions[input].push_back(to_state);
	//}
}

vector<State> State::get_transition(char input){
	return transitions[input];
}


void State::set_acceptance(bool value){
	acceptance_state = value;
}

bool State::is_acceptance(){
	return acceptance_state;
}


void State::set_start(bool value){
	start_state = value;
}

bool State::is_start(){
	return start_state;
}


bool State::operator==(const State& s)
{
  return this == &s;
}


/*
void State::set_token(Token matched_token){
	this.matched_token = matched_token;
}

Token State::get_token(void){
	return this.matched_token;
}
*/
