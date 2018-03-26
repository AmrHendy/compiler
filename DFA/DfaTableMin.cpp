/*
 * Dfatablemin.cpp
 *
 *  Created on: Mar 25, 2018
 *      Author: abdelrhman
 */

#include "DfaTableMin.h"

Dfa_table_min::Dfa_table_min(TransitionTable dfa_table , Partition_Rapper p_rapper) {
	this -> dfa_table  = dfa_table ;
	this -> p_rapper = p_rapper ;
}

TransitionTable Dfa_table_min::get_min_table(){
	TransitionTable equ ;
	vector<CompositeState> essentials ;
	for(int i=0 ; i < dfa_table.size() ; i++){

		Row* r = dfa_table.get_row(i) ;

		CompositeState* from = r->get_id_state() ;
		CompositeState* essential = p_rapper.get_essential(from) ;

		if(find(essentials.begin(),essentials.end(),*essential) == essentials.end()){
			essentials.push_back(*essential);
		}

		if(*from != *essential)
			continue ;

		for(char c : Alpha::getAlphabet()){
			CompositeState* to = r->get_transition(c) ;
			/* STATE TO NOT FOUND */
			if(to->get_size() == 0)
				continue ;
			/* REPLACE STATE WITH IT'S ESSENTIAL */
			r->set_transition(c,p_rapper.get_essential(to));
		}

		equ.insert_new_row(r);
	}
	int siz = equ.size() ;
	Logger::print_string("Min table finished with " + patch::to_string(siz) + "row\n" , Files::log_file) ;
	return equ ;
}
