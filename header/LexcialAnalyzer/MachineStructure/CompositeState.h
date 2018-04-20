#ifndef COMPOSITESTATE_H_
#define COMPOSITESTATE_H_

#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include "State.h"
#include "../RuleExtractor/Rule.h"


using namespace std;

class CompositeState {
public:
	CompositeState();
	virtual ~CompositeState();

	void insert_new_state(State* new_state);
	CompositeState* get_transition(char input);
	CompositeState* find_equivalent_states(CompositeState* start);
	vector<State*> get_states();
	bool is_acceptance();
	bool isNull();
	bool operator ==(CompositeState c);
	bool contain_state(State* s);

	vector<Rule> get_matched_rules(void);

private:
	vector<State*> states;
	unordered_map<int,int> states_ids;
};

#endif /* COMPOSITESTATE_H_ */
