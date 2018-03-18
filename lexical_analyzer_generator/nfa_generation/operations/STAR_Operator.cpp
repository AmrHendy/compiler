/* INCLUDE HEADER */
/*********************************************/
#include "STAR_Operator.h"

/* CONSTRUCTOR */
/*********************************************/
STAR_Operator::STAR_Operator(void)
{
	/* nothing */
}

STAR_Operator::~STAR_Operator(void)
{
	/* nothing */
}

/* INTERFACE METHODS */
/*********************************************/
Machine
STAR_Operator::apply(Machine m)
{
	Machine result=malloc(sizeof(Machine));

	State start=malloc(sizeof(State));
	State end=malloc(sizeof(State));

	start.add_transition('\0', m.get_start());
	start.add_transition('\0', end);

	m.get_end().add_transition('\0', m.get_start());
	m.get_end().add_transition('\0', end);

	result.set_start(start);
	result.set_end(end);

	return result;
}
