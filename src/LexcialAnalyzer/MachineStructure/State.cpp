#include "../../../header/LexcialAnalyzer/MachineStructure/State.h"

State::State(int id)
{
    acceptance_state = false;
    this -> id = id;
}

State::~State()
{
    this -> transitions.clear() ;
}

int State::get_id()
{
    return id;
}

void
State::add_transition(char input, State* to_state)
{
    if(!transition_found(input,to_state))
        transitions[input].push_back(to_state);
}

bool
State::transition_found(char input, State* to_state)
{
    vector<State*> tr = transitions[input] ;
    for(State* s : tr)
    {
        if( (*s) == (*to_state) )
            return true ;
    }
    return false ;
}

State*
State::get_transition(char input, int index)
{
    return transitions[input][index] ;
}

vector<State*>
State::get_transitions(char c)
{
    return transitions[c] ;
}

void
State::add_transitions (State* s)
{
    for(char c : Alpha::alpha)
    {
        vector<State*> v = s->get_transitions(c) ;
        for(State* s : v)
        {
            if(find(transitions[c].begin(), transitions[c].end(), s) == transitions[c].end() )
            {
                transitions[c].push_back(s) ;
            }
        }
    }
}

int
State::size_transition(char input)
{
    return transitions[input].size() ;
}

void
State::set_start()
{
    this -> start_state = true ;
}

bool
State::is_start()
{
    return this -> start_state ;
}

void State::set_accepted()
{
    acceptance_state = true ;
}

bool State::is_acceptance()
{
    return acceptance_state;
}

void State::set_matched_rule(Rule matched_rule)
{
    State::matched_rule = matched_rule;
}

Rule State::get_matched_rule(void)
{
    return matched_rule;
}

bool State::operator == (const State s) const
{
    return  id == s.id ;
}

bool State::operator != (const State s) const
{
    return id != s.id ;
}

bool State::operator < (const State s) const
{
    return id < s.id ;
}

bool State::operator > (const State s) const
{
    return id > s.id ;
}

void State::print()
{
    /*
    	string str = "\t\tstate { id = " ;
    	str += patch::to_string(id) ;
    	str += " accept = " ;
    	str += patch::to_string(acceptance_state) ;
    	str += " start = " ;
    	str += patch::to_string(start_state) ;
    	string rule_name = matched_rule.getRuleName() ;
    	str += " rule = " ;
    	str += rule_name ;
    	string rule_pattern = matched_rule.getRulePattern() ;
    	str += " rule_pattern = " ;
    	str += rule_pattern ;
    	int rule_priority = matched_rule.getPriority() ;
    	str += " rule_priority = " ;
    	str += patch::to_string(rule_priority) ;
    	Logger::logger.print_string(str);
    */

//	string str = "" ;
//	for(char c : Alpha::getAlphabet()){
//		vector<State*> tos = transitions[c];
//		for(State* s : tos){
//			int to_id = s->get_id() ;
//		  str+= "\t" +patch::to_string(id)
//			 + " -> "
//			 + patch::to_string(to_id)
//			 + "[ label= "
//			 + patch::to_string(c)
//			 + " ];\n";
//		  	 s->print();
//		}
//	}
//	Logger::print_string(str);
}


