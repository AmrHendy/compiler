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


	/*
	OrOperator or_operator;
	nfa_result = machines[0];
	for( int i = 1 ; i < machines.size() ; i++ )
	{
		nfa_result = or_operator.apply(nfa_result, machines[i]);
	}
	cout << "Finishing overall NFA" << endl;
	*/

	/* combine all rules into single machine */
	Machine* nfa_result = machines[0];
	State* start = new State(NumberGenerator::getNextUniqueInt());
	start->add_transition('\0', nfa_result->get_start());
	nfa_result->set_start(start);

	for( int i = 1 ; i < machines.size() ; i++ )
	{
		nfa_result->get_start()->add_transition('\0', machines[i]->get_start());
	}
	cout << "Finishing overall NFA" << endl;
	return nfa_result;
}
