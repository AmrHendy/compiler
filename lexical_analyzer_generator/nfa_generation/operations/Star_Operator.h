#ifndef STAR_OPERATOR_H_  /* Include guard */
#define STAR_OPERATOR_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "lexical_analyzer_generator/data_structures/automata/State.h"
#include "lexical_analyzer_generator/data_structures/automata/Machine.h"

/* CLASS DEFINITIONS */
/*********************************************/
class STAR_Operator
{
public:
    /* constructor */
    STAR_Operator(void);
    ~STAR_Operator(void);

    /* interface functions */
    Machine apply(Machine m);

};


#endif
