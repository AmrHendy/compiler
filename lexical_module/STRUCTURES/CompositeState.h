#ifndef COMPOSITESTATE_H_
#define COMPOSITESTATE_H_

#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include "State.h"
#include "../Rule_Extractor/Rule.h"
#include "../LOGGER/Logger.h"

using namespace std;

class CompositeState
{
public:

    /* CONSTRUCTORS AND DESTRUCTORS */
    CompositeState();

    CompositeState(set<State> states);

    virtual ~CompositeState();

    int get_size();

    bool contains(State to_find);

    void add_state(State new_state);

    void add_states(set<State> new_state);

    void add_states(CompositeState new_state);

    set<State> get_states();

    void set_id(int id);

    int get_id();

    CompositeState * get_transition(char input);

    CompositeState * find_equivalent_states(CompositeState start);

    vector<Rule> get_matched_rules();

    void set_start();

    bool is_acceptance();

    bool is_start();

    bool is_empty();

    void set_rules(vector<Rule> r);

    vector<Rule> get_rules();

    bool operator ==(CompositeState c);

    bool operator !=(CompositeState c);

    bool operator <(CompositeState c);

    bool operator >(CompositeState c);

    void print();

private:
    set<State>              states;
    vector<Rule>            rules;
    unordered_map<int, int> states_ids;
    bool                    start;
    bool                    accept;
    int                     id;
};
#endif /* COMPOSITESTATE_H_ */


//~ Formatted by Jindent --- http://www.jindent.com
