#include "NFA.h"

#include <iostream>

NFA::NFA(vector<Rule> processed_rules) {
	NFA::processed_rules = processed_rules;
}

NFA::~NFA() {
	// TODO Auto-generated destructor stub
}

Machine* NFA::generate_nfa_machine() {
	vector<Machine*> machines;

	NumberGenerator::setCurrentInt(1);

	/* build each rule into nfa machine individually */
	for(Rule r : processed_rules)
	{
		machines.push_back(NFABuilder::build_machine(r));
	}

	cout << "Finishing all single NFAS" << endl;

	/* combine all rules into single machine */
	Machine* nfa_result = machines[0];
	State* start = new State(NumberGenerator::getNextUniqueInt());
	State* end = new State(NumberGenerator::getNextUniqueInt());
	start->add_transition('\0', nfa_result->get_start());
	nfa_result->set_start(start);
	nfa_result->get_end()->add_transition('\0', end);
	nfa_result->set_end(end);

	for( int i = 1 ; i < machines.size() ; i++ )
	{
		machines[i]->get_end()->add_transition('\0', nfa_result->get_end());
		nfa_result->get_start()->add_transition('\0', machines[i]->get_start());
	}
	cout << "Finishing overall NFA" << endl;
	// this will be total number of char in all rules * 2 + 2
	// as for each char we make new machine = 2 states
	// for any operation we don't need new states
	// at last we compine using two new states
	cout << "Total Number of states = " << NumberGenerator::getNextUniqueInt() - 1 << endl;
	return nfa_result;
}
