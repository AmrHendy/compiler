#ifndef STATE_H_
#define STATE_H_

#include <map>
#include <vector>
#include "Rule.h"

using namespace std;

class State
{

public:
    State(int id);
    State();
    virtual ~State();

    void add_transition(char input, State to_state);
    vector<State> get_transition(char input);


    /* setters and getters */
    void set_acceptance(bool value);
    bool is_acceptance();
    void set_matched_rule(Rule matched_rule);
    Rule get_matched_rule(void);
    bool operator==(const State s);

private:
	map<char, vector<State> > transitions;
	bool acceptance_state;
	Rule matched_rule = Rule("", "", 0);
	int id;
};


#endif
