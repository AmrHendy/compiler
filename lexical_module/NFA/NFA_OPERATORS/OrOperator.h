#ifndef OrOPERATOR_H_  /* Include guard */
#define OrOPERATOR_H_

#include "../../STRUCTURES/State.h"
#include "../../STRUCTURES/Machine.h"
#include "../../GENERATORS/NumberGenerator.h"

class OrOperator
{
public:
    OrOperator(void);
    virtual ~OrOperator(void);

    static Machine* apply(Machine* m1, Machine* m2);

};


#endif
