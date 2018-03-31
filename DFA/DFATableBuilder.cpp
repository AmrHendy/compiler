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
    /* get table first entry */
    CompositeState* start_state = new CompositeState();
    vector<CompositeState> states_id ;

    start_state->add_state(*nfa_machine.get_start());
    start_state = start_state->find_equivalent_states(*start_state);
    start_state->set_id(0) ;

    q.push(start_state);
    states_id.push_back(*start_state);

    while(!q.empty())
    {
        CompositeState* curr = q.front();
        q.pop();
        /* add new row */
        dfa_table.insert_new_row(curr);
        /* get transitions of this new entry */
        for (char i : Alpha::getAlphabet())
        {
            /* get states reachable by this state(s) when applying char i */
            CompositeState* to_state = curr->get_transition(i) ;
            if(!to_state->get_size() == 0)
            {
                to_state = to_state->find_equivalent_states(*to_state);

                if(find(states_id.begin(), states_id.end(), *to_state) == states_id.end())
                {
                    to_state->set_id(states_id.size());
                    states_id.push_back(*to_state);
                    q.push(to_state) ;
                }
                else
                {
                    to_state->set_id(find(states_id.begin(), states_id.end(), *to_state) - states_id.begin());
                }

                dfa_table.add_transition(curr, i, to_state);


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

    cout << "begin repartitioning :- \n" ;

    clock_t begin = clock() ;

    while(!p_rapper.is_finished())
    {
        p_rapper.re_partition();
    }

    clock_t end = clock() ;

    cout << "repartitioning took " << double(end - begin) / CLOCKS_PER_SEC << " sec.\n";


    cout << "begin generating min table :- \n" ;

    begin = clock() ;


    /* REMOVE EQUAVILENT STATES AND MODIFY TABLE  */
    Dfa_table_min table_min(dfa_table,p_rapper) ;
    TransitionTable* dfa_min = table_min.get_min_table() ;

    end = clock() ;

    cout << "generate min table took " << double(end - begin) / CLOCKS_PER_SEC << " sec.\n";


    dfa_min->print("dfa_min : ");

    return *dfa_min;
}
