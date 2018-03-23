#include "CompositeState.h"

CompositeState::CompositeState() {
	// TODO Auto-generated constructor stub

}

CompositeState::~CompositeState() {
	// TODO Auto-generated destructor stub
}


void CompositeState::insert_new_state(State* new_state) {
	if(find(states.begin() , states.end(), new_state) == states.end()){
		states.push_back(new_state);
	}
}

CompositeState* CompositeState::get_transition(char input) {
	vector<State*> result;
	for(int index = 0; index < states.size(); index++){
		State* s = states[index];
		vector<State*> transitions = s->get_transition(input);
		for(State* next : transitions){
			if (find(result.begin(), result.end(), next) == result.end()){
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



bool CompositeState::is_acceptance(void)
{
	for(State* s : states){
		// s represents constituent_state
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
		if(find(result.begin(), result.end(), curr) == result.end())result.push_back(curr);
		vector<State*> epsilon_transitions = curr->get_transition('\0');
		for(State* child : epsilon_transitions){
			if(find(result.begin(), result.end(), child) == result.end()){
				q.push(child);
			}
		}
	}
	return vector_to_composite(result);
}


vector<State*> CompositeState::get_states() {
	return states;
}

bool CompositeState::operator ==(CompositeState* c){
	vector<State*> c_states = c->get_states();
	for(State* s : c_states){
	  if(find(states.begin(), states.end(), s) == states.end())
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
