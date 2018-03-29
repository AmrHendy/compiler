/*
 * DFA.cpp
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */

#include "DFAMachine.h"
#include <ctime>

DFAMachine::DFAMachine(Machine nfa_machine) {
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

	clock_t begin = clock();

	cout << "Begin building DFA table :- \n" ;

	DFATableBuilder dfa_table_builder(nfa_machine);
	TransitionTable dfa_table = dfa_table_builder.generate_dfa_table();

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << "Finishing building DFA Table took " << elapsed_secs << "sec.\n" ;

	/* 02 minimize DFA table */

	cout << "Begin minimizing DFA table :- \n" ;

	begin = clock();

    dfa_table = dfa_table_builder.minimize_dfa_table(dfa_table);

    end = clock();

    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	cout << "Finishing minimizing DFA Table took " << elapsed_secs << "sec.\n" ;

    return dfa_table;
}



