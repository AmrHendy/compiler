#include "../../../../header/LexcialAnalyzer/NFA/NFAOperators/KleeneClosureOperator.h"


KleeneClosureOperator::KleeneClosureOperator() {
	// TODO Auto-generated constructor stub

}

KleeneClosureOperator::~KleeneClosureOperator() {
	// TODO Auto-generated destructor stub
}


Machine* KleeneClosureOperator::apply(Machine* m){
	m->get_start()->add_transition('\0', m->get_end());
	m->get_end()->add_transition('\0', m->get_start());
	return m;
}
