#ifndef ANDOPERATOR_H_  /* Include guard */
#define ANDOPERATOR_H_

#include "State.h"
#include "Machine.h"

class AndOperator
{
public:
    AndOperator(void);
    virtual ~AndOperator(void);

    static Machine apply(Machine m1, Machine m2);

};


#endif
