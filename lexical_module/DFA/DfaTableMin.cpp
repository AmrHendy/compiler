/*
 * Dfatablemin.cpp
 *
 *  Created on: Mar 25, 2018
 *      Author: abdelrhman
 */

#include "DfaTableMin.h"

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

            for(int j = 0 ; j < dfa_table.size() ; j++)
            {
                CompositeState* alternative = dfa_table.get_row(j)->get_transition(c) ;
                if(alternative->get_id() != -1  && from->get_id() == p_rapper.get_essential(dfa_table.get_row(j)->get_id_state())->get_id())
                {
                    to = alternative ;
                    vector<Rule> to_rules = to->get_matched_rules();
                    if(!to_rules.empty())
                        transition_rules.push_back(to_rules);
                }
            }

            /* STATE TO NOT FOUND */
            if(to->get_id() == -1)
                continue ;

            CompositeState* to_ess = p_rapper.get_essential(to) ;
            CompositeState* to_add = new CompositeState();
            to_add->set_id(to_ess->get_id()) ;
            to_add->add_states(to_ess->get_states());

            vector<Rule> col_rules ;

            for(vector<Rule> v : transition_rules)
                for(Rule r : v){
                	if(find(col_rules.begin() ,col_rules.end() , r) == col_rules.end())
						col_rules.push_back(r) ;
                }

            to_add->set_rules(col_rules);


            n_r->set_transition(c,to_add);
        }

        equ->insert_new_row(n_r);
    }
    int siz = equ->size() ;
    Logger::print_string("Min table finished with " + patch::to_string(siz) + "row\n", Files::log_file) ;
    return equ ;
}


/*

int main(){
	TransitionTable table = TransitionTable();

	CompositeState* A = new CompositeState() ;
	A->set_id(1);
	A->set_start();
	CompositeState* B = new CompositeState() ;
	B->set_id(2);

	State accept = State(12);
	accept.set_accepted();

	CompositeState* C = new CompositeState() ;
	C->set_id(3);
	C->add_state(accept);
	CompositeState* D = new CompositeState() ;
	D->set_id(4);
	D->add_state(accept);
	CompositeState* E = new CompositeState() ;
	E->set_id(5);
	E->add_state(accept);
	CompositeState* F = new CompositeState() ;
	E->set_id(6);

	Alpha::insertAlphabet('0');
	Alpha::insertAlphabet('1');

	table.insert_new_row(A);
	table.insert_new_row(B);
	table.insert_new_row(C);
	table.insert_new_row(D);
	table.insert_new_row(E);
	table.insert_new_row(F);

	table.add_transition(A,'0',B);
	table.add_transition(A,'1',C);
	table.add_transition(B,'0',A);
	table.add_transition(B,'1',D);
	table.add_transition(C,'0',E);
	table.add_transition(C,'1',F);
	table.add_transition(D,'0',E);
	table.add_transition(D,'1',F);
	table.add_transition(E,'0',E);
	table.add_transition(E,'1',F);
	table.add_transition(F,'0',F);
	table.add_transition(F,'1',F);

	table.print("initial");

	Partition_Rapper rapp = Partition_Rapper(table);
	Partition final = Partition(0,table.get_acceptance_states());
	Partition inti = Partition(1,table.get_non_acceptance_states());

	rapp.add_partition(final);
	rapp.add_partition(inti);

	while(!rapp.is_finished())
		rapp.re_partition();

	Dfa_table_min minimizer = Dfa_table_min(table , rapp);

	minimizer.get_min_table()->print("minimized");

}

*/

