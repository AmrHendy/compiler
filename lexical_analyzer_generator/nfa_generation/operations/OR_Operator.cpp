/* INCLUDE HEADER */
/*********************************************/
#include "OR_Operator.h"

/* CONSTRUCTOR */
/*********************************************/
OR_Operator::OR_Operator(void)
{
	/* nothing */
}

OR_Operator::~OR_Operator(void)
{
	/* nothing */
}

/* INTERFACE METHODS */
/*********************************************/
Machine
OR_Operator::apply(Machine m1, Machine m2)
{
	Machine result=malloc(sizeof(Machine));

	State start=malloc(sizeof(State));
	start.add_transition('\0', m1.get_start());
	start.add_transition('\0', m2.get_start());
	result.set_start(start);

	State end=malloc(sizeof(State));
	m1.get_end().add_transition('\0', end);
	m2.get_end().add_transition('\0', end);
	result.set_end(end);

	return result;
}
