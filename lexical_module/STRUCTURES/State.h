#ifndef STATE_H_
#define STATE_H_

#include <map>
#include <vector>
#include "../Rule_Extractor/Rule.h"
//#include "../../LOGGER/Logger.h"

using namespace std;

class State
{
public:
    State(int id);

    virtual ~State();

    int get_id();

    void add_transition(char    input,
                        State * to_state);

    bool transition_found(char    input,
                          State * to_state);

    State * get_transition(char input,
                           int  index);

    vector<State *> get_transitions(char);

    void add_transitions(State *);

    int size_transition(char input);

    void set_start();

    bool is_start();

    void set_accepted();

    bool is_acceptance();

    void set_matched_rule(Rule matched_rule);

    Rule get_matched_rule(void);

    bool operator ==(const State s) const;

    bool operator !=(const State s) const;

    bool operator <(const State s) const;

    bool operator >(const State s) const;

    void print();

private:
    map<char, vector<State *> > transitions;
    Rule                        matched_rule     = Rule("", "", 0);
    bool                        acceptance_state = false;
    bool                        start_state      = false;
    int                         id;
};
#endif


//~ Formatted by Jindent --- http://www.jindent.com
