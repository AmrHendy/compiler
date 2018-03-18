#ifndef PLUS_OPERATOR_H_  /* Include guard */
#define PLUS_OPERATOR_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "State.h"
#include "Machine.h"

/* CLASS DEFINITIONS */
/*********************************************/
class PLUS_Operator
{
	public:
	/* constructor */
    PLUS_Operator(void);
    ~PLUS_Operator(void);

    /* interface functions */
    Machine apply(Machine m);
 
};


#endif