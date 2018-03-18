#ifndef STATE_H_  /* Include guard */
#define STATE_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <unordered_map>
#include <vector>
#include "Token.h"

/* CLASS DEFINITIONS */
/*********************************************/
class State
{
	private:
	/* attributes */
	unordered_map < char, vector<State> > transitions;
	bool acceptance_state;
    Token matched_token;

	public:
	/* constructor */
    State(void);
    ~State(void);

    /* interface functions */
    void add_transition(char input, State to_state);
    vector<State> get_transition(char input);
    //void add_transition(pair<State,char>);
    //vector<State> get_char_transtions(char trans);

    /* setters and getters */
    void set_acceptance(bool value);
    bool is_acceptance(void);
    void set_token(Token matched_token);
    Token get_token(void);

};


#endif
