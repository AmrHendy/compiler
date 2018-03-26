#include "KleeneClosureOperator.h"

KleeneClosureOperator::KleeneClosureOperator() {
	// TODO Auto-generated constructor stub

}

KleeneClosureOperator::~KleeneClosureOperator() {
	// TODO Auto-generated destructor stub
}


Machine* KleeneClosureOperator::apply(Machine* m){

//	m->get_end()->add_transition('\0', m->get_start());
//	m->get_start()->add_transition('\0', m->get_end());
//	Machine* result = new Machine() ;
//	result->set_start(m->get_start());
//	return result ;

//	Logger::print_string("closure on \n");

//	m->print();

//	Logger::print_string("result \n");

	m->get_end()->add_transitions(m->get_start());
	m->get_start()->add_transition('\0' , m->get_end());

//	m->print();

	return m;


//	Machine* result = new Machine();
//
//	State* start = new State(NumberGenerator::getNextUniqueInt());
//	State* end = new State(NumberGenerator::getNextUniqueInt());
//
//	start->add_transition('\0', m->get_start());
//	start->add_transition('\0', end);
//
//	m->get_end()->add_transition('\0', m->get_start());
//	m->get_end()->add_transition('\0', end);
//
//	result->set_start(start);
//	result->set_end(end);
//
//	return result;
}
