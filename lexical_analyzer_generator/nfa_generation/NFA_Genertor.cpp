/* IMPORT LIBRARIES */
/*********************************************/
#include "NFA_Generator.h"
using namespace std ;

/* CONSTRUCTOR */
/*********************************************/
NFA_Generator::NFA_Generator(vector<Rule> processed_rules)
{
   /* nothing */
	this -> processed_rules = processed_rules ;
}

NFA_Generator::NFA_Generator(void)
{
	/* nothing */
}

/* INTERFACE FUNCTIONS */
/*********************************************/
Transition_Table
NFA_Generator::generate_nfa_table(void)
{
  
  NFA_Machine_Builder machine_builder;
  vector<Machine> machines ;
  
  for( Rule i : processed_rules )
  {
    machines.push_back(machine_builder.get_machine(i)) ;
  }
  
  Machine overall_machine = machines[0] ;
  for( int i = 1 ; i < machines.size() ; i++ )
  {
    overall_machine = machines[i] | overall_machine ;
  }
  
  return overall_machine ;
}

