/* INCLUDE HEADER */
/*********************************************/
#include "NFA_Generator.h"

/* CONSTRUCTOR */
/*********************************************/
NFA_Generator::NFA_Generator(vector<Rule> processed_rules)
{
   /* nothing */
	this-> processed_rules = processed_rules;
}

NFA_Generator::NFA_Generator(void)
{
	/* nothing */
}

/* INTERFACE FUNCTIONS */
/*********************************************/
Machine
NFA_Generator::generate_nfa_machine(void)
{
  NFA_Machine_Builder machine_builder;
  vector<Machine> machines;
  /* build each rule into nfa machine individually */
  for(Rule r : processed_rules)
  {
    machines.push_back(machine_builder.build_machine(r));
  }
  /* combine all rules into single machine */
  OR_Operator or_operator;
  Machine overall_machine = machines[0] ;
  for( int i = 1 ; i < machines.size() ; i++ )
  {
    overall_machine = or_operator.apply(overall_machine, machines[i]);
  }
  
  return overall_machine;
}


Transition_Table
generate_nfa_table(void)
{
  
}

