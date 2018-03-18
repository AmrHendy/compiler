/* IMPORT LIBRARIES */
/*********************************************/
#include "NFA_Table_Builder.h"
using namespace std ;

/* CONSTRUCTOR */
/*********************************************/
NFA_Table_Builder::NFA_Table_Builder(Machine nfa_machine)
{
	this->nfa_machine = nfa_machine;
}

~NFA_Table_Builder::NFA_Table_Builder(void)
{
	/* nothing */
}

/* SETTERS AND GETTERS */
/*********************************************/
void
generate_nfa_table(void)
{
	Transition_Table table ;
    vector<State> stack ;
    map<State,bool> vis ;
    
    stack.push_back( nfa_machine.get_start() );
    vis[stack.back()] = 1 ;
  
    while(!stack.empty()){
      Compl_state from = Compl_state(stack.back()) , stack.pop_back() ;
      vector<pair<State,char>> transitions = from.get_transtions() ;
      for(pair<State,char> i : transitions){
          Compl_state to = Compl_state(i.first) ;
          table.add_transtion(from , i.second , to) ;
          if(!vis[to]){ 
            stack.push_back(to) ;
            vis[to] = 1 ;
          }
      }
    }
}

