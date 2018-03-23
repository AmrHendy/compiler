#include "KleeneClosureOperator.h"

KleeneClosureOperator::KleeneClosureOperator() {
	// TODO Auto-generated constructor stub

}

KleeneClosureOperator::~KleeneClosureOperator() {
	// TODO Auto-generated destructor stub
}


Machine KleeneClosureOperator::apply(Machine m){
	Machine result = Machine();

	State start = State(NumberGenerator::getNextUniqueInt());
	State end = State(NumberGenerator::getNextUniqueInt());

	start.add_transition('\0', m.get_start());
	start.add_transition('\0', end);

	m.get_end().add_transition('\0', m.get_start());
	m.get_end().add_transition('\0', end);

	result.set_start(start);
	result.set_end(end);

	return result;
}
