/* INCLUDE HEADER */
/*********************************************/
#include "Composite_State.h"

/* CONSTRUCTOR */
/*********************************************/
Composite_State::Composite_State(void)
{
	/* nothing */
} 

Composite_State::~Composite_State(void)
{
	/* nothing */
}

/* INTERFACE METHODS */
/*********************************************/
void
DFA_Table_Builder::insert_new_state(State new_state)
{
	this->states.push_back(new_state);
}

Composite_State
DFA_Table_Builder::get_transition(char input)
{
	vector<State> result;
	for(State s:states)
	{
		vector<State> transitions=s.get_transition(input);
		for(State next:transitions)
		{
			if ( std::find(result.begin(), result.end(), next) != vector.end() )
			{
				continue;
			}
			result.push_back(next);
		}
	}
	return vector_to_composite(result);
}

Composite_State
DFA_Table_Builder::find_equivalent_states(Composite_State start)
{
  /*
  * this function finds all states reachable by "epsilon" from given state
  */
  vector<State> result;
  vector<State> start_states = start.get_states();
  for(State s:start_states)
  {
    vector<State> stack;
    stack.push_back(s);
    while(!stack.empty())
    {
      State current = stack.back() ; stack.pop_back();
      result.push_back(current);
      vector<State> epsilon_transitions = current.get_transition('\0');

      for(State next:epsilon_transitions)
      {
        if ( std::find(result.begin(), result.end(), next) != vector.end() )
        {
          continue;
        }
        stack.push_back(next);
      }
    }

  }

  return vector_to_composite(result);


}


vector<State>
DFA_Table_Builder::get_states(void)
{
	return this->states;
}


bool
DFA_Table_Builder::operator == (const Compl_state& c)
{
	set<State> c_states = c.get_states() ;
	for(State i : c_states){
	  if(this->states.count(i) == 0)
	    return false ;
	}
	return true ;
}


/* UTILITY FUNCTIONS */
/*********************************************/
Composite_State
DFA_Table_Builder::vector_to_composite(vector<State> states)
{
	Composite_State result = malloc(sizeof(Composite_State));
	for(State s:states)
	{
		result.insert_new_state(s);
	}
	return result;
}