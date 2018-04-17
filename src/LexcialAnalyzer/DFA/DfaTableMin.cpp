/*
 * Dfatablemin.cpp
 *
 *  Created on: Mar 25, 2018
 *      Author: abdelrhman
 */

#include "../../../header/LexcialAnalyzer/DFA/DfaTableMin.h"

Dfa_table_min::Dfa_table_min(TransitionTable dfa_table, Partition_Rapper p_rapper)
{
    this -> dfa_table  = dfa_table ;
    this -> p_rapper = p_rapper ;
}

TransitionTable*
Dfa_table_min::get_min_table()
{
    TransitionTable* equ = new TransitionTable();

    for(int i=0 ; i < dfa_table.size() ; i++)
    {

        Row* r = dfa_table.get_row(i) ;

        CompositeState* from = r->get_id_state() ;
        CompositeState* essential = p_rapper.get_essential(from) ;

        if(from->get_id() != essential->get_id())
            continue ;

        Row* n_r = new Row(r->get_id_state());

        for(char c : Alpha::getAlphabet())
        {
            CompositeState* to = r->get_transition(c) ;

            vector<vector<Rule>> transition_rules ;

            for(int j=0 ; j < dfa_table.size() ; j++)
            {
                CompositeState* alternative = dfa_table.get_row(j)->get_transition(c) ;
                if(alternative->get_size() !=0  && *from == *p_rapper.get_essential(dfa_table.get_row(j)->get_id_state()))
                {
                    to = alternative ;
                    vector<Rule> to_rules = to->get_matched_rules();
                    if(!to_rules.empty())
                        transition_rules.push_back(to_rules);
                }
            }

            /* STATE TO NOT FOUND */
            if(to->get_size() == 0)
                continue ;

            CompositeState* to_ess = p_rapper.get_essential(to) ;
            CompositeState* to_add = new CompositeState();
            to_add->set_id(to_ess->get_id()) ;
            to_add->add_states(to_ess->get_states());

            vector<Rule> col_rules ;

            for(vector<Rule> v : transition_rules)
                for(Rule r : v)
                    col_rules.push_back(r) ;

            to_add->set_rules(col_rules);


            n_r->set_transition(c,to_add);
        }

        equ->insert_new_row(n_r);
    }
    int siz = equ->size() ;
    Logger::print_string("Min table finished with " + patch::to_string(siz) + "row\n", Files::log_file) ;
    return equ ;
}
