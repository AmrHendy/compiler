#include "OrOperator.h"

OrOperator::OrOperator()
{

}

OrOperator::~OrOperator()
{

}

Machine* OrOperator::apply(Machine* m1, Machine* m2){
	m1->get_start()->add_transition('\0', m2->get_start());
	m1->get_end()->add_transition('\0', m2->get_end());
	Machine* result = new Machine() ;
	result->set_start(m1->get_start());
	result->set_end(m1->get_end());
	return result ;
//
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
//
}
