#ifndef COMPOSITE_STATE_H_  /* Include guard */
#define COMPOSITE_STATE_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "lexical_analyzer_generator/data_structures/automata/State.h"
#include <vector>

using namespace std ;

/* CLASS DEFINITIONS */
/*********************************************/
class Composite_State
{
private:
    /* attributes */
    vector <State> states;

public:
    /* constructor */
    Composite_State(void);
    Composite_State(vector<State> states) ;
    Composite_State(State state) ;
    ~Composite_State(void);

    /* interface functions */
    void insert_new_state(State new_state);
    void insert_comp_state(Composite_State new_state);
    Composite_State get_transition(char input);
    Composite_State find_equivalent_states();
    bool is_accept_state() ;
    vector<State> get_states(void);

    /* operators */
    bool operator == (Composite_State& c) ;

    /*void add_transition(pair<State,char>);
    vector<State> get_char_transtions(char trans);*/

private:
    /* utility functions */
    Composite_State vector_to_composite(vector<State> states);




};


#endif
