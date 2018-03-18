#ifndef NFA_RULE_BUILDER_H_  /* Include guard */
#define NFA_RULE_BUILDER_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "State.h"
#include "Machine.h"
#include "Rule.h"
#include "RuleElement.h"
#include "AND_Operator.h"
#include "OR_Operator.h"
#include "PLUS_Operator.h"
#include "STAR_Operator.h"

/* CLASS DEFINITIONS */
/*********************************************/
class NFA_Rule_Builder
{
	private:
	/* attributes */
	AND_Operator and_operator;
	OR_Operator or_operator;
	PLUS_Operator plus_operator;
	STAR_Operator star_operator;

	public:
	/* constructor */
    NFA_Rule_Builder(void);   // This is the constructor declaration
    ~NFA_Rule_Builder(void);  // This is the destructor: declaration

    /* interface functions */
    Machine build_machine(Rule rule) ;
    
 
};


#endif