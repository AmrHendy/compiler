#ifndef STAR_OPERATOR_H_  /* Include guard */
#define STAR_OPERATOR_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "State.h"
#include "Machine.h"

/* CLASS DEFINITIONS */
/*********************************************/
class STAR_Operator
{
	public:
	/* constructor */
    Star_Operator(void);
    ~Star_Operator(void);

    /* interface functions */
    Machine apply(Machine m);
 
};


#endif