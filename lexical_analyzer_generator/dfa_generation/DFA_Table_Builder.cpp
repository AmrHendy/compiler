/* IMPORT LIBRARIES */
/*********************************************/
#include <algorithm>
#include "DFA_Table_Builder.h"
using namespace std;

/* CONSTRUCTOR */
/*********************************************/
DFA_Table_Builder::DFA_Table_Builder(Compl_state id){
      this-> id = id ;
  } 

DFA_Table_Builder::~DFA_Table_Builder(void)
{

}

/* INTERFACE METHODS */
/*********************************************/
void
DFA_Table_Builder::generate_dfa_table(State start)
{
  Complex_State start_state;
  tmp.add_state(start);
  
  vector<Complex_State> stack;
  stack.push_back(start_state);

  while(!stack.empty())
  {
    Complex_State tmp=stack.back() ; stack.pop_back();
    if(!Table.row_found(tmp))
    {
      /*find equivalent states*/
      tmp=get_epsilon_transitions(tmp);
      /*add new row*/
      Table.add_row(tmp);
      /* get transitions of this new entry */
      for (char i : alphabet){
        Compl_state level_one = get_transtions(tmp,i) ;
        Compl_state level_two = get_epsilon_transtion(level_one,'\0') ;
        stack.push_back() ;
      }
      get_transitions();
      
    }
    
  }

}

Complex_State
DFA_Table_Builder::get_epsilon_transition(Complex_State start)
{
  vector<State> result;
  vector<State> tmp_stack = start.get_transition('\0') ;

  while(!tmp_stack.empty)
  {
    State tmp_state = stack.pop();
    result.insert(tmp_state);
    vector<State> tmp_transitions = tmp_state.get_transition('\0');
    for(State s:tmp_transitions)
    {
      if ( std::find(tmp_transitions.begin(), tmp_transitions.end(), s) != vector.end() )
      {
        continue;
      }
      else
      {
        tmp_stack.insert(s);
      }
    }
  }
}


