#ifndef NFA_H_
#define NFA_H_

#include "NFA_OPERATORS/OrOperator.h"
#include "../Rule_Extractor/Rule.h"
#include "../STRUCTURES/Machine.h"
#include "NFABuilder.h"
//#include "Transition_Table"
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
