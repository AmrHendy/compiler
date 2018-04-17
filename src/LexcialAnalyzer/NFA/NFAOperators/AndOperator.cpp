#include "../../../../header/LexcialAnalyzer/NFA/NFAOperators/AndOperator.h"

AndOperator::AndOperator()
{

}

AndOperator::~AndOperator()
{

}

Machine* AndOperator::apply(Machine* m1, Machine* m2)
{

    Machine* n = new Machine() ;

//	Logger::print_string("Anding \n");
//	m1->print();
//	Logger::print_string("with \n");
//	m2->print();
//	Logger::print_string("result is \n");

    m1->get_end()->add_transitions(m2->get_start());
    n->set_start(m1->get_start());
    n->set_end(m2->get_end());
    free(m2->get_start());

//	n->print();

    return n;
}
