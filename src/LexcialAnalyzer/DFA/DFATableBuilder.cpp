/* IMPORT LIBRARIES */
/*********************************************/

#include "../../../header/LexcialAnalyzer/DFA/DFATableBuilder.h"
#include <iostream>

//* CONSTRUCTOR */
/*********************************************/
DFATableBuilder::DFATableBuilder(Machine* nfa_machine)
{
    DFATableBuilder::nfa_machine = nfa_machine;
}

DFATableBuilder::~DFATableBuilder(void)
{
  /* nothing */
}

TransitionTable
DFATableBuilder::generate_dfa_table(void)
{
  queue<CompositeState*> q;
  TransitionTable dfa_table = TransitionTable();
  /* get table first entry */
  CompositeState* start_state = new CompositeState();
  start_state->insert_new_state(nfa_machine->get_start());
  start_state = start_state->find_equivalent_states(start_state);
  q.push(start_state);
  while(!q.empty())
  {
    CompositeState* curr = q.front();
    q.pop();
    if(!dfa_table.row_found(curr))
    {
      /* add new row */
      dfa_table.insert_new_row(curr);
      /* get transitions of this new entry */
      for (char i : Alpha::getAlphabet()) {
        /* get states reachable by this state(s) when applying char i */
        CompositeState* to_state = curr->get_transition(i) ;
        if(!to_state->isNull())
        {
          to_state = to_state->find_equivalent_states(to_state);
          q.push(to_state) ;
          dfa_table.add_row_transition(curr, i, *to_state);
        }
      }
    }
  }
  return dfa_table;

}

TransitionTable
DFATableBuilder::minimize_dfa_table(TransitionTable dfa_table)
{
    /* SPLIT START STATES FROM END STATES */
    Partition start_states('0', dfa_table.get_non_acceptance_states()) ;
    Partition end_states('1', dfa_table.get_acceptance_states()) ;

    /* BUILD ALL PARTITIONS */
    vector<Partition> partitions ;
    partitions.push_back(start_states) ;
    partitions.push_back(end_states) ;

    while(re_partition(&partitions, dfa_table));

    /* REMOVE EQUAVILENT STATES AND MODIFY TABLE  */
    return dfa_table.get_equavilent_table(partitions) ;
}


/* PRIVATE FUNCTIONS */
bool DFATableBuilder::re_partition(vector<Partition>* partitions , TransitionTable dfa_table )
{
    /* NEW PARTIONS GENERATED */
    vector<Partition> n_partitions ;
    int siz = (*partitions).size() ;
    /* GENERATE IDS FOR PARTIONS */
    for (int i = 0 ; i < siz ; i++){
        (*partitions)[i].set_identifier('0' + i) ;
    }


    for(Partition p : *partitions){
        /* GENERATE IDENTIFIERS FOR PARTITION STATES */
        generate_partition_ids(*partitions , &p , dfa_table ) ;
        /* SPLIT PARTITION TO NEW PARTITIONS ACCORDING TO NEW IDENTIFIERS */
        vector<Partition> to_add = p.split() ;
        /* ADD NEW PARTITIONS */
        for(Partition n_p : to_add)
            n_partitions.push_back(n_p) ;
    }

    if(partitions->size() == n_partitions.size()){
        return false ;
    }

    partitions = &n_partitions ;

    return true ;
}


void DFATableBuilder::generate_partition_ids(vector<Partition> all_partitions , Partition* partition , TransitionTable dfa_table ){
    /* GET STATES OF THE PARTITION */
    vector<CompositeState*> states = partition -> get_states() ;
    /* NEW IDENTIFIERS FOR PARTITION STATES */
    vector<string> ids ;

    for(CompositeState* c : states){
        /* NEW IDENTIFIER FOR STATE i IN PARTITION */
        string id = "" ;
        /* ALPHABET */
        set<char> alpha = Alpha::getAlphabet();
        /* APPEND TO STATE ID PARTITION ID */
        for (char i : alpha ){
            /* GET STATE WILL GO TO IF STATE C TOOK I */
            CompositeState* to = dfa_table.get_transition(c , i) ;
            /* STATE TO IS NOT FOUND */
            if(to->get_states().empty()){
            	id.push_back('#');
            	continue;
            }
            /* GET PARTITION STATE TO BELONG TO */
            char partition_id = get_partition_belong(all_partitions,to).get_identifier() ;
            /* APPEND PARTITION ID TO STATE ID */
            id.push_back(partition_id) ;
        }
        ids.push_back(id);
    }

    /* SET IDS OF STATES */
    partition->set_state_id(ids) ;
}


Partition
DFATableBuilder::get_partition_belong(vector<Partition> partitions, CompositeState* c){
    /* LOOK FOR PARTITION STATE C BELONG TO */
    for (Partition p : partitions){
        if(p.belong(c))
            return p ;
    }
    return NULL;
}
