#ifndef NFA_Machine_BUILDER_H_  /* Include guard */
#define NFA_Machine_BUILDER_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "lexical_analyzer_generator/data_structures/automata/State.h"
#include "lexical_analyzer_generator/data_structures/automata/Machine.h"
#include "lexical_analyzer_generator/rule_preprocessing/Rule.h"
#include "lexical_analyzer_generator/rule_preprocessing/RuleElement.h"
#include "lexical_analyzer_generator/nfa_generation/operations/AND_Operator.h"
#include "lexical_analyzer_generator/nfa_generation/operations/OR_Operator.h"
#include "lexical_analyzer_generator/nfa_generation/operations/Plus_Operator.h"
#include "lexical_analyzer_generator/nfa_generation/operations/Star_Operator.h"

/* CLASS DEFINITIONS */
/*********************************************/
class NFA_Machine_Builder
{
private:
    /* attributes */
    AND_Operator and_operator;
    OR_Operator or_operator;
    PLUS_Operator plus_operator;
    STAR_Operator star_operator;

public:
    /* constructor */
    NFA_Machine_Builder(void);   // This is the constructor declaration
    ~NFA_Machine_Builder(void);  // This is the destructor: declaration

    /* interface functions */
    Machine build_machine(Rule rule) ;


};


#endif
