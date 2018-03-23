/* IMPORT LIBRARIES */
/*********************************************/
#include "DFATableBuilder.h"

/* CONSTRUCTOR */
/*********************************************/
DFATableBuilder::DFATableBuilder(Machine nfa_machine)
{
    DFATableBuilder::nfa_machine = nfa_machine;
}

DFATableBuilder::~DFATableBuilder(void)
{
  /* nothing */
}

/* INTERFACE METHODS */
/*********************************************/

/****************************************
** generate dfa table from nfa machine **
****************************************/
TransitionTable
DFATableBuilder::generate_dfa_table(void)
{
  queue<CompositeState> q;
  TransitionTable dfa_table = TransitionTable();
  /* get table first entry */
  CompositeState start_state;
  start_state.insert_new_state(nfa_machine.get_start());
  start_state = start_state.find_equivalent_states(start_state);
  q.push(start_state);

  while(!q.empty())
  {
    CompositeState curr = q.front();
    q.pop();
    if(!dfa_table.row_found(curr))
    {
      /* add new row */
      dfa_table.insert_new_row(curr);
      /* get transitions of this new entry */
      for (char i : Alpha::getAlphabet()){
        /* get states reachable by this state(s) when applying char i */
        CompositeState to_state = curr.get_transition(i) ;
        if(!to_state.isNull())
        {
          to_state = to_state.find_equivalent_states(to_state);
          q.push(to_state) ;
          dfa_table.add_row_transition(curr, i, to_state);
        }
      }
    }
  }
  return dfa_table;

}
