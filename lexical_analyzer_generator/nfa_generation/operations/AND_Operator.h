#ifndef AND_OPERATOR_H_  /* Include guard */
#define AND_OPERATOR_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "State.h"
#include "Machine.h"

/* CLASS DEFINITIONS */
/*********************************************/
class AND_Operator
{
	public:
	/* constructor */
    AND_Operator(void);
    ~AND_Operator(void);

    /* interface functions */
    Machine apply(Machine m1, Machine m2);
 
};


#endif