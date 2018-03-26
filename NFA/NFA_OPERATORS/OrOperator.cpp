#include "OrOperator.h"

OrOperator::OrOperator()
{

}

OrOperator::~OrOperator()
{

}

Machine* OrOperator::apply(Machine* m1, Machine* m2){
	Machine* result = new Machine();

//	Logger::print_string("oring \n");

//	m1->print();

//	Logger::print_string("with \n");

//	m2->print();

	m1->get_start()->add_transitions(m2->get_start());
	m1->get_end()->add_transition('\0' , m2->get_end());
	free(m2->get_start()) ;


	result->set_start(m1->get_start());
	result->set_end(m2->get_end());

//	Logger::print_string("result is \n");

//	result->print();

	return result;
//	Machine* result = new Machine();
//
//	State* start = new State(NumberGenerator::getNextUniqueInt());
//	start->add_transition('\0', m1->get_start());
//	start->add_transition('\0', m2->get_start());
//	result->set_start(start);
//
//	State* end = new State(NumberGenerator::getNextUniqueInt());
//	m1->get_end()->add_transition('\0', end);
//	m2->get_end()->add_transition('\0', end);
//	result->set_end(end);
//	return result;

}
