#ifndef ANDOPERATOR_H_  /* Include guard */
#define ANDOPERATOR_H_

#include "../../STRUCTURES/State.h"
#include "../../STRUCTURES/Machine.h"

class AndOperator
{
public:
    AndOperator(void);
    virtual ~AndOperator(void);

    static Machine* apply(Machine* m1, Machine* m2);

};


#endif
