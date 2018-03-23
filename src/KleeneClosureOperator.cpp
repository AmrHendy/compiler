#include "KleeneClosureOperator.h"

KleeneClosureOperator::KleeneClosureOperator() {
	// TODO Auto-generated constructor stub

}

KleeneClosureOperator::~KleeneClosureOperator() {
	// TODO Auto-generated destructor stub
}


Machine* KleeneClosureOperator::apply(Machine* m){
	Machine* result = new Machine();

	State* start = new State(NumberGenerator::getNextUniqueInt());
	State* end = new State(NumberGenerator::getNextUniqueInt());

	start->add_transition('\0', m->get_start());
	start->add_transition('\0', end);

	m->get_end()->add_transition('\0', m->get_start());
	m->get_end()->add_transition('\0', end);

	result->set_start(start);
	result->set_end(end);

	return result;
}
