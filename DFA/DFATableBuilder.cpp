/* IMPORT LIBRARIES */
/*********************************************/
#include "DFATableBuilder.h"

#include <iostream>

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
  queue<CompositeState*> q;
  TransitionTable dfa_table = TransitionTable();
  CompositeState* start_state = new CompositeState();
  /* get table first entry */
  start_state->add_state(*nfa_machine.get_start());
  start_state = start_state->find_equivalent_states(*start_state);
  q.push(start_state);

  NumberGenerator::setCurrentInt(0);

  while(!q.empty())
  {
    CompositeState* curr = q.front();
    q.pop();
    if(!dfa_table.row_found(*curr))
    {
      curr->set_id(NumberGenerator::getNextUniqueInt());
      /* add new row */
      dfa_table.insert_new_row(curr);
      /* get transitions of this new entry */
      for (char i : Alpha::getAlphabet()){
        /* get states reachable by this state(s) when applying char i */
        CompositeState* to_state = curr->get_transition(i) ;
        if(to_state->get_size() != 0)
        {
          to_state = to_state->find_equivalent_states(*to_state);
          q.push(to_state) ;
          dfa_table.add_transition(*curr, i, to_state);
        }
      }
    }
  }

  dfa_table.print("dfa table : ");

  return dfa_table;

}

TransitionTable
DFATableBuilder::minimize_dfa_table(TransitionTable dfa_table)
{
	Partition_Rapper p_rapper(dfa_table) ;

    /* SPLIT START STATES FROM END STATES */
    Partition start_states(0, dfa_table.get_non_acceptance_states()) ;
    Partition end_states(1, dfa_table.get_acceptance_states()) ;

    /* BUILD ALL PARTITIONS */
    p_rapper.add_partition(start_states) ;
    p_rapper.add_partition(end_states) ;

    while(!p_rapper.is_finished()){
    	p_rapper.re_partition();
    }

    /* REMOVE EQUAVILENT STATES AND MODIFY TABLE  */
    Dfa_table_min table_min(dfa_table,p_rapper) ;
    TransitionTable dfa_min = table_min.get_min_table() ;

    dfa_min.print("dfa_min : ");

    return dfa_min;
}
