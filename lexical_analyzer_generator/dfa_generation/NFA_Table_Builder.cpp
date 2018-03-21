/* IMPORT LIBRARIES */
/*********************************************/
#include <algorithm>
#include "NFA_Table_Builder.h"
#include "lexical_analyzer_generator/data_structures/transition_table/Transition_Table.h"

using namespace std ;

/* CONSTRUCTOR */
/*********************************************/
NFA_Table_Builder::NFA_Table_Builder(Machine nfa_machine)
{
    this->nfa_machine = nfa_machine;
}

NFA_Table_Builder::~NFA_Table_Builder(void)
{
    /* nothing */
}

/* SETTERS AND GETTERS */
/*********************************************/
void
NFA_Table_Builder::generate_nfa_table(void)
{
    Transition_Table table ;
    vector<State> stak ;
    vector<State> vis ;

    stak.push_back(nfa_machine.get_start() );
    vis.push_back(stak.back()) ;

    while(!stak.empty())
    {
        State from = stak.back() ;
        stak.pop_back() ;
        map<char,vector<State>> transitions = from.get_all_transitions();
        for(pair<char,vector<State>> i : transitions)
        {
            for(State j : i.second){
                State to = j ;
                table.add_transition(Composite_State(from), i.first , to) ;
                if( find (vis.begin() , vis.end() , to ) == vis.end() )
                {
                    stak.push_back(to) ;
                    vis.push_back(to) ;
                }
            }
        }
    }
}

