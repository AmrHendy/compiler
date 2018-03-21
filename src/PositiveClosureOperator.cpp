#include "PositiveClosureOperator.h"

PositiveClosureOperator::PositiveClosureOperator() {
	// TODO Auto-generated constructor stub

}

PositiveClosureOperator::~PositiveClosureOperator() {
	// TODO Auto-generated destructor stub
}


Machine PositiveClosureOperator::apply(Machine m){
	Machine result = Machine();

	State end = State();
	m.get_end().add_transition('\0', m.get_start());
	m.get_end().add_transition('\0', end);

	result.set_start(m.get_start());
	result.set_end(end);

	return result;
}
