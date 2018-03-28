#include "CompositeState.h"
#include <iostream>

CompositeState::CompositeState() {
	// TODO Auto-generated constructor stub

}

CompositeState::~CompositeState() {
	// TODO Auto-generated destructor stub
}


void CompositeState::insert_new_state(State* new_state) {
	if(states_ids[new_state->get_id()] == 0){
		states.push_back(new_state);
		states_ids[new_state->get_id()] = 1;
	}
}

CompositeState* CompositeState::get_transition(char input) {
	CompositeState* result = new CompositeState();
	for(int index = 0; index < states.size(); index++){
		State* s = states[index];
		vector<State*> transitions = s->get_transition(input);
		for(State* next : transitions){
			result->insert_new_state(next);
		}
	}
	return result;
}


bool CompositeState::is_acceptance()
{
	for(State* s : states){
		if(s->is_acceptance()){
			return true;
		}
	}
	return false;
}


/* this function return all equivalent states to start composite state. */
CompositeState* CompositeState::find_equivalent_states(CompositeState* start) {
	CompositeState* result = new CompositeState();
	queue<State*> q;
	for(State* s : start->get_states()){
		q.push(s);
	}
	while(!q.empty()){
		State* curr = q.front();
		q.pop();
		result->insert_new_state(curr);
		vector<State*> epsilon_transitions = curr->get_transition('\0');
		for(State* child : epsilon_transitions){
			if(!result->contain_state(child)){
				q.push(child);
			}
		}
	}
	return result;
}


vector<State*> CompositeState::get_states() {
	return states;
}


bool CompositeState::operator ==(CompositeState c){
	for(State* s : c.get_states()){
		if(states_ids[s->get_id()] == 0){
			return false ;
		}
	}
	return true ;
}

bool CompositeState::isNull(){
	return states.size() == 0;
}


vector<Rule> CompositeState::get_matched_rules(void) {
	vector<Rule> result;
	for(State* s : states){
		if(s->is_acceptance()){
			result.push_back(s->get_matched_rule());
		}
	}
	return result;
}


bool CompositeState::contain_state(State* s){
	return states_ids[s->get_id()] != 0;
}

