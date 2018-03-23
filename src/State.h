#ifndef STATE_H_
#define STATE_H_

#include <map>
#include <vector>
//#include "Token.h"

using namespace std;

class State
{

public:
    State();
    virtual ~State();

    void add_transition(char input, State to_state);
    vector<State> get_transition(char input);


    /* setters and getters */
    void set_acceptance(bool value);
    bool is_acceptance();
    //void set_token(Token matched_token);
    //Token get_token(void);
    void set_start(bool value);
    bool is_start();
    bool operator==(const State& s);

private:
	map<char, vector<State> > transitions;
	bool acceptance_state;
	bool start_state;
	//Token matched_token;
};


#endif