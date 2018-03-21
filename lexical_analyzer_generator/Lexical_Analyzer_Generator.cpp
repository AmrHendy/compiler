/* IMPORT LIBRARIES */
/*********************************************/
#include "Lexical_Analyzer_Generator.h"
#include "lexical_analyzer_generator/rule_preprocessing/Rule_Preprocessor.h"
#include "lexical_analyzer_generator/nfa_generation/NFA_Generator.h"
#include "lexical_analyzer_generator/rule_preprocessing/Rule.h"
#include "lexical_analyzer_generator/dfa_generation/DFA_Generator.h"

using namespace std ;

/* CONSTRUCTOR */
/*********************************************/
Lexical_Analyzer_Generator::Lexical_Analyzer_Generator(string language_rules_directory)
{
    /* nothing */
    this -> language_rules_directory = language_rules_directory ;
}

Lexical_Analyzer_Generator::~Lexical_Analyzer_Generator(void)
{

}

/* SETTERS AND GETTERS */
/*********************************************/
Transition_Table
Lexical_Analyzer_Generator::generate_minimal_dfa(void)
{
    /* 01 process rules */
    Rule_Preprocessor rule_Preprocessor(language_rules_directory);
    vector<Rule> processed_rules=rule_Preprocessor.getRules();

    /* 02 generate nfa table */
    NFA_Generator nfa_generator(processed_rules);
    Transition_Table nfa_table = nfa_generator.generate_nfa_table();
    Machine nfa_machine = nfa_generator.generate_nfa_machine();

    /* 03 generate dfa table */
    DFA_Generator dfa_generator(nfa_table);
    Transition_Table minimized_dfa_table = dfa_generator.generate_minimized_dfa_table();

    return minimized_dfa_table;

}

