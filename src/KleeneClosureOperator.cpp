#include "KleeneClosureOperator.h"

KleeneClosureOperator::KleeneClosureOperator() {
	// TODO Auto-generated constructor stub

}

KleeneClosureOperator::~KleeneClosureOperator() {
	// TODO Auto-generated destructor stub
}


Machine* KleeneClosureOperator::apply(Machine* m){
	State* start = new State(NumberGenerator::getNextUniqueInt());
	State* end = new State(NumberGenerator::getNextUniqueInt());

	start->add_transition('\0', m->get_start());
	start->add_transition('\0', end);

	m->get_end()->add_transition('\0', m->get_start());
	m->get_end()->add_transition('\0', end);

	m->set_start(start);
	m->set_end(end);
	return m;


	/*
	Machine* result = new Machine();
	m->get_start()->add_transition('\0', m->get_end());
	m->get_end()->add_transition('\0', m->get_start());
	result->set_start(m->get_start());
	return result;

	*/
}
