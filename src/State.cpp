#include "State.h"

State::State(int id)
{
	acceptance_state = false;
	State::id = id;
}


State::State()
{
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


bool State::operator==(const State s)
{

	return s.id == State::id;
  //return this == &s;
}

void State::set_matched_rule(Rule matched_rule){
	State::matched_rule = matched_rule;
}

Rule State::get_matched_rule(void){
	return matched_rule;
}
