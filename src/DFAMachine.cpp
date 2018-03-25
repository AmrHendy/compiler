/*
 * DFA.cpp
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */

#include "DFAMachine.h"

DFAMachine::DFAMachine(Machine* nfa_machine) {
	// TODO Auto-generated constructor stub
	DFAMachine::nfa_machine = nfa_machine;
	table_calculated_flag = false;
}

DFAMachine::~DFAMachine() {
	// TODO Auto-generated destructor stub
}

TransitionTable DFAMachine::get_minimized_dfa_table(){
	if(table_calculated_flag)return minimized_dfa_table;
	table_calculated_flag = true;
	minimized_dfa_table = generate_minimized_dfa_table();
	return minimized_dfa_table;
}


TransitionTable DFAMachine::generate_minimized_dfa_table(){
	/*	NFA_Table_Builder nfa_table_builder(nfa_machine);
		Transition_Table nfa_table = nfa_table_builder.generate_nfa_table();*/
	/* 	01 obtain DFA table */
	DFATableBuilder dfa_table_builder(nfa_machine);
	TransitionTable dfa_table = dfa_table_builder.generate_dfa_table();

	/* 02 minimize DFA table */
	//dfa_table = dfa_table_builder.minimize_dfa_table(dfa_table);
	return dfa_table;
}



