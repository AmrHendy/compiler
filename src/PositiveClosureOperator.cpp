#include "PositiveClosureOperator.h"

PositiveClosureOperator::PositiveClosureOperator() {
	// TODO Auto-generated constructor stub

}

PositiveClosureOperator::~PositiveClosureOperator() {
	// TODO Auto-generated destructor stub
}


Machine* PositiveClosureOperator::apply(Machine* m){
	m->get_end()->add_transition('\0', m->get_start());
	return m;
}
