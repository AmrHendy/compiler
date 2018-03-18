/* IMPORT LIBRARIES */
/*********************************************/
#include "NFA_Machine_Builder.h"
#include "Rule.h"
#include "RuleElement.h"
using namespace std ;

/* CONSTRUCTOR */
/*********************************************/
NFA_Machine_Builder::NFA_Machine_Builder(void)
{
   /* nothing */
}

NFA_Machine_Builder::NFA_Machine_Builder(void)
{
	/* nothing */
}

/* INTERFACE FUNCTIONS */
/*********************************************/
Machine
NFA_Machine_Builder::get_machine(Rule r)
{
  vector<RuleElement> elements = toPostfix() ;
  vector<Machine> stack ;
  for(RuleElement i : elements){
    if(!i.isOp()){
      stack.push_back(Machine(i.getChar())) ;
    }else{
      if(i.getChar() == '|'){
        Machine m1 = stack.back() ; stack.pop_back() ;
        Machine m2 = stack.back() ; stack.pop_back() ;
        stack.push_back(m1 | m2) ;
      }else if(i.getChar() == '.'){
        Machine m1 = stack.back() ; stack.pop_back() ;
        Machine m2 = stack.back() ; stack.pop_back() ;
        stack.push_back(m1 * m2) ;
      }else if(i.getChar() == '*'){
        Machine m1 = stack.back() ; stack.pop_back() ;
        stack.push_back(kleen_closure(m1)) ;
      }else if(i.getChar() == '+'){
        Machine m1 = stack.back() ; stack.pop_back() ;
        stack.push_back(positive_closure(m1)) ;
      }
    }
  }
  if(stack.size() > 1 || stack.empty() )
    return NULL ;
  return stack[0] ;
}
