/* INCLUDE HEADER */
/*********************************************/
#include "lexical_analyzer_generator/nfa_generation/operations/Plus_Operator.h"

/* CONSTRUCTOR */
/*********************************************/
PLUS_Operator::PLUS_Operator(void)
{
    /* nothing */
}

PLUS_Operator::~PLUS_Operator(void)
{
    /* nothing */
}

/* INTERFACE METHODS */
/*********************************************/
Machine
PLUS_Operator::apply(Machine m)
{
    /*
    Machine result=malloc(sizeof(Machine));

    State end=malloc(sizeof(State));
    m.get_end().add_transition('\0', m.get_start());
    m.get_end().add_transition('\0', end);

    result.set_start(m.get_start());
    result.set_end(end);

    return result;
    */
}
