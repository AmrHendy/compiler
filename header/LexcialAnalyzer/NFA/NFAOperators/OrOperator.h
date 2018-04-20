#ifndef OrOPERATOR_H_  /* Include guard */
#define OrOPERATOR_H_

#include "../../MachineStructure/State.h"
#include "../../MachineStructure/Machine.h"
#include "../../Helper/NumberGenerator.h"

class OrOperator
{
public:
    OrOperator(void);
    virtual ~OrOperator(void);

    static Machine* apply(Machine* m1, Machine* m2);

};


#endif
