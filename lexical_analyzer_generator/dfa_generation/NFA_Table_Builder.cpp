/* IMPORT LIBRARIES */
/*********************************************/
#include "NFA_Table_Builder.h"

/* CONSTRUCTOR */
/*********************************************/
NFA_Table_Builder::NFA_Table_Builder(Machine nfa_machine)
{
	this->nfa_machine = nfa_machine;
}

NFA_Table_Builder::~NFA_Table_Builder(void)
{
	/* nothing */
}

/* SETTERS AND GETTERS */
/*********************************************/
Transition_Table
NFA_Table_Builder::generate_nfa_table(void)
{
  vector<Composite_State> stack;
  Transition_Table nfa_table=malloc(sizeof(Transition_Table));
  /* get table first entry */
  Composite_State start_state;
  start_state.insert_new_state(this->nfa_machine.get_start());
  stack.push_back(start_state);

  while(!stack.empty())
  {
    Composite_State tmp=stack.back() ; stack.pop_back();
    if(!nfa_table.row_found(tmp))
    {
      /* add new row */
      nfa_table.insert_new_row(tmp);
      /* get transitions of this new entry */
      for (char i : alphabet){
        /* get states reachable by this state(s) when applying char i */
        Composite_State to_state = tmp.get_transtion(i) ;
        if(to_state!=NULL)
        {
          /* this state has transition of char i */
          nfa_table.add_row_transition(tmp, i, to_state);
          vector<State> simple_states = to_state.get_states();
          for(State s:simple_states)
          {
            Composite_State current; current.insert_new_state(s);
            stack.push_back(current) ;  
          }
          
        }
        
      }
      
    }
    
  }

  return nfa_table;

}