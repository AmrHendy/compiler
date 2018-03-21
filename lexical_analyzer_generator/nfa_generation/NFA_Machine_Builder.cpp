/* INCLUDE HEADER */
/*********************************************/
#include "NFA_Machine_Builder.h"
#include "lexical_analyzer_generator/rule_preprocessing/Rule.h"
#include "lexical_analyzer_generator/rule_preprocessing/RuleElement.h"

/* CONSTRUCTOR */
/*********************************************/
NFA_Machine_Builder::NFA_Machine_Builder(void)
{
    /* nothing */
}

NFA_Machine_Builder::~NFA_Machine_Builder(void)
{
    /* nothing */
}

/* INTERFACE FUNCTIONS */
/*********************************************/
Machine
NFA_Machine_Builder::build_machine(Rule rule)
{
    /* convert rule to postfix */
    vector<RuleElement> elements = rule.toPostfix() ;
    /* build machine */
    vector<Machine> stack;
    for(RuleElement element : elements)
    {
        if(!element.isOp())
        {
            /* this is a simple character */
            stack.push_back(Machine(element.getChar())) ;
            continue;
        }

        /* this is an operator */
        if(element.getChar() == '|')
        {
            Machine m1 = stack.back() ;
            stack.pop_back();
            Machine m2 = stack.back() ;
            stack.pop_back();
            stack.push_back(or_operator.apply(m1,m2));
        }
        else if(element.getChar() == '.')
        {
            Machine m1 = stack.back() ;
            stack.pop_back() ;
            Machine m2 = stack.back() ;
            stack.pop_back() ;
            stack.push_back(and_operator.apply(m1,m2)) ;
        }
        else if(element.getChar() == '*')
        {
            Machine m1 = stack.back() ;
            stack.pop_back() ;
            stack.push_back(star_operator.apply(m1)) ;
        }
        else if(element.getChar() == '+')
        {
            Machine m1 = stack.back() ;
            stack.pop_back() ;
            stack.push_back(plus_operator.apply(m1)) ;
        }

    }

    if(stack.size() > 1 || stack.empty() )
    {
        return NULL ;
    }

    return stack[0] ;
}
