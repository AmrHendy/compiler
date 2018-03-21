#include "CompositeState.h"

CompositeState::CompositeState() {
	// TODO Auto-generated constructor stub

}

CompositeState::~CompositeState() {
	// TODO Auto-generated destructor stub
}


void CompositeState::insert_new_state(State new_state) {
	states.push_back(new_state);
}

CompositeState CompositeState::get_transition(char input) {
	vector<State> result;
	for(State s : states){
		vector<State> transitions = s.get_transition(input);
		for(State next : transitions){
			if (find(result.begin(), result.end(), next) == result.end()){
				result.push_back(next);
			}
		}
	}
	return vector_to_composite(result);
}


CompositeState CompositeState::vector_to_composite(vector<State> states) {
	CompositeState result = CompositeState();
	for(State s : states){
		result.insert_new_state(s);
	}
	return result;
}



bool CompositeState::is_acceptance(void)
{
	for(State s : states){
		/* s represents constituent_state */
		if(s.is_acceptance()){
			return true;
		}
	}
	return false;
}


/*
vector<Token> CompositeState::get_tokens(void)
{
	vector<Token> result;
	for(State s:this->states)
	{
		result.push_back(s.get_token());
	}
	return result;
}
*/


/* this function return all equivalent states to start not including start itself. */
CompositeState CompositeState::find_equivalent_states(CompositeState start) {
  /*
  * this function finds all states reachable by "epsilon" from given state
  */
	set<State> result;
	queue<State> q;
	for(State s : start.get_states()){
		q.push(s);
	}
	while(!q.empty()){
		State curr = q.front();
		q.pop();
		result.insert(curr);
		vector<State> epsilon_transitions = curr.get_transition('\0');
		for(State child : epsilon_transitions){
			if(result.count(child) == 0){
				q.push(child);
			}
		}
	}
	vector<State> result_vector;
	for(State s : result){
		result_vector.push_back(s);
	}
	return vector_to_composite(result_vector);
}


vector<State> CompositeState::get_states() {
	return states;
}


bool CompositeState::operator ==(CompositeState c) {
	vector<State> c_states = c.get_states();
	for(State s : c_states){
	  if(find(states.begin(), states.end(), s) == states.end())
	    return false ;
	}
	return true ;
}


