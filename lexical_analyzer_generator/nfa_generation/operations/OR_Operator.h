#ifndef OR_OPERATOR_H_  /* Include guard */
#define OR_OPERATOR_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "lexical_analyzer_generator/data_structures/automata/State.h"
#include "lexical_analyzer_generator/data_structures/automata/Machine.h"

/* CLASS DEFINITIONS */
/*********************************************/
class OR_Operator
{
public:
    /* constructor */
    OR_Operator(void);
    ~OR_Operator(void);

    /* interface functions */
    Machine apply(Machine m1, Machine m2);

};


#endif
