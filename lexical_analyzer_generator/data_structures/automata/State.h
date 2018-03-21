#ifndef STATE_H_  /* Include guard */
#define STATE_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <map>
#include <vector>
#include "lexical_tokenizer/Token.h"
#include "State.h"

using namespace std ;


/* CLASS DEFINITIONS */
/*********************************************/
class State
{
private:
    /* attributes */
    map < char, vector<State> > transitions;
    bool acceptance_state;
    Token matched_token;

public:
    /* constructor */
    State(void);
    ~State(void);

    /* interface functions */
    void add_transition(char input, State to_state);
    vector<State> get_transition(char input);
    map<char,vector<State>> get_all_transitions();

    //void add_transition(pair<State,char>);

    /* operators */
    bool operator == (const State& s) ;


    /* setters and getters */
    void set_acceptance(bool value);
    bool is_acceptance(void);
    void set_token(Token matched_token);
    Token get_token(void);

};


#endif
