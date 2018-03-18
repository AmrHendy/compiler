/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
#include "State.h"

using namespace std;


/* CONSTRUCTOR */
/*********************************************/
State::State(void)
{

}

State::~State(void)
{

}

/* SETTERS AND GETTERS */
/*********************************************/


/* INTERFACE METHODS */
/*********************************************/
void State::add_transition(pair<State, char> transition)
{
    this->transitions.push_back(transition) ;
}

vector<State> get_char_transtions(char trans){
	vector<State> res ;
	vector<pair<State,char>> transtions = this->get_transitions() ;
	for(pair<State,char> i : transitions ){
			  	if(i.second == trans)
	        res.push_back(i.first) ;
	}
	return res ;	
}