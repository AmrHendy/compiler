#include "../../../../header/LexcialAnalyzer/NFA/NFAOperators/OrOperator.h"

OrOperator::OrOperator()
{

}

OrOperator::~OrOperator()
{

}

Machine* OrOperator::apply(Machine* m1, Machine* m2)
{
    Machine* result = new Machine();

    m1->get_start()->add_transitions(m2->get_start());
    m1->get_end()->add_transition('\0', m2->get_end());
    free(m2->get_start()) ;


    result->set_start(m1->get_start());
    result->set_end(m2->get_end());

    return result;
}
