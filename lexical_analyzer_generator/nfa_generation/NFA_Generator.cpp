/* INCLUDE HEADER */
/*********************************************/
#include "lexical_analyzer_generator/data_structures/automata/Machine.h"
#include "lexical_analyzer_generator/nfa_generation/NFA_Generator.h"
#include "lexical_analyzer_generator/nfa_generation/NFA_Machine_Builder.h"

using namespace std ;

/* CONSTRUCTOR */
/*********************************************/
NFA_Generator::NFA_Generator(vector<Rule> processed_rules)
{
    /* nothing */
    this-> processed_rules = processed_rules;
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

