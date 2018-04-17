#include "../../../header/LexcialAnalyzer/NFA/NFA.h"

NFA::NFA(vector<Rule> processed_rules)
{
    NFA::processed_rules = processed_rules;
}

NFA::~NFA()
{
    // TODO Auto-generated destructor stub
}

Machine* NFA::generate_nfa_machine()
{
    vector<Machine*> machines;

    NumberGenerator::setCurrentInt(1);

    /* build each rule into nfa machine individually */
    for(Rule r : processed_rules)
    {
        machines.push_back(NFABuilder::build_machine(r));
        machines.back()->get_end()->set_accepted();
        machines.back()->get_end()->set_matched_rule(r);
    }

    /* combine all rules into single machine */
    Machine* nfa_result = machines[0];
    State* start = new State(NumberGenerator::getNextUniqueInt());
    start->add_transitions(nfa_result->get_start());
    nfa_result->set_start(start);

    for( int i = 1 ; i < (int) machines.size() ; i++ )
    {
        nfa_result->get_start()->add_transitions(machines[i]->get_start());
    }


    nfa_result->get_start()->set_start();

    nfa_result->print();

    return nfa_result;
}

