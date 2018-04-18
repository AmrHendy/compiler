#ifndef NFA_H_
#define NFA_H_

#include "NFAOperators/OrOperator.h"
#include "../RuleExtractor/Rule.h"
#include "../MachineStructure/Machine.h"
#include "NFABuilder.h"
#include <vector>

class NFA {
public:
	NFA(vector<Rule> processed_rules);
	virtual ~NFA();

	Machine* generate_nfa_machine();
	//Transition_Table generate_nfa_table(void);

private:
	vector<Rule> processed_rules;
};

#endif /* NFA_H_ */
