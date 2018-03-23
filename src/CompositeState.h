#ifndef COMPOSITESTATE_H_
#define COMPOSITESTATE_H_

#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include "State.h"

using namespace std;

class CompositeState {
public:
	CompositeState();
	virtual ~CompositeState();

	void insert_new_state(State new_state);
	CompositeState get_transition(char input);
	CompositeState find_equivalent_states(CompositeState start);
	vector<State> get_states();
	bool is_acceptance();
	bool operator ==(CompositeState c);


	//vector<Token> get_tokens(void);

private:
	vector<State> states;

	CompositeState vector_to_composite(vector<State> states);
};

#endif /* COMPOSITESTATE_H_ */
