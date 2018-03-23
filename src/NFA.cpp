#include "NFA.h"

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

	/* combine all rules into single machine */
	OrOperator or_operator;
	Machine* overall_machine = machines[0];
	for( int i = 1 ; i < machines.size() ; i++ )
	{
		overall_machine = or_operator.apply(overall_machine, machines[i]);
	}
	return overall_machine;
}

