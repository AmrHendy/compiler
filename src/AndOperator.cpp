#include "AndOperator.h"

AndOperator::AndOperator()
{

}

AndOperator::~AndOperator()
{

}

Machine AndOperator::apply(Machine m1, Machine m2){
	Machine result = Machine();
	result.set_start(m1.get_start());
	result.set_end(m2.get_end());
	//Epsilon used in transition = '\0'
	m1.get_end().add_transition('\0', m2.get_start());
	return result;
}
