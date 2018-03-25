#include "CompositeState.h"
#include <iostream>

CompositeState::CompositeState() {
	// TODO Auto-generated constructor stub

}

CompositeState::~CompositeState() {
	// TODO Auto-generated destructor stub
}


void CompositeState::insert_new_state(State* new_state) {
	if(!is_contain_state(states, new_state)){
		states.push_back(new_state);
	}
}

CompositeState* CompositeState::get_transition(char input) {
	vector<State*> result;
	for(int index = 0; index < states.size(); index++){
		State* s = states[index];
		vector<State*> transitions = s->get_transition(input);
		for(State* next : transitions){
			if (!is_contain_state(result, next)){
				result.push_back(next);
			}
		}
	}
	return vector_to_composite(result);
}


CompositeState* CompositeState::vector_to_composite(vector<State*> states) {
	CompositeState* result = new CompositeState();
	for(State* s : states){
		result->insert_new_state(s);
	}
	return result;
}



bool CompositeState::is_acceptance()
{
	for(State* s : states){
		// represents constituent_state
		if(s->is_acceptance()){
			return true;
		}
	}
	return false;
}


/* this function return all equivalent states to start composite state. */
CompositeState* CompositeState::find_equivalent_states(CompositeState* start) {
	vector<State*> result;
	queue<State*> q;
	for(State* s : start->get_states()){
		q.push(s);
	}
	while(!q.empty()){
		State* curr = q.front();
		q.pop();
		if(!is_contain_state(result, curr))result.push_back(curr);
		vector<State*> epsilon_transitions = curr->get_transition('\0');
		for(State* child : epsilon_transitions){
			if(!is_contain_state(result, child)){
				q.push(child);
			}
		}
	}
	return vector_to_composite(result);
}


vector<State*> CompositeState::get_states() {
	return states;
}

bool CompositeState::operator ==(CompositeState c){
	vector<State*> c_states = c.get_states();

	for(State* s : c_states){
		if(!is_contain_state(states, s))
			return false ;
	}
	return true ;
}

bool CompositeState::isNull(){
	return states.size() == 0;
}


vector<Rule> CompositeState::get_matched_rules(void)
{
	vector<Rule> result;
	for(State* s : states)
	{
		if(s->is_acceptance()){
			result.push_back(s->get_matched_rule());
		}
	}
	return result;
}


bool CompositeState::is_contain_state(vector<State*> vec, State* s){
	vector<State> vecc;
	for(State* s : vec) vecc.push_back(*s);
	return find(vecc.begin(), vecc.end(), *s) != vecc.end();
}

