/* IMPORT LIBRARIES */
/*********************************************/

#include "lexical_analyzer.h"
#include "lexical_analyzer_generator/Lexical_Analyzer_Generator.h"
#include "lexical_tokenizer/Tokenizer.h"

using namespace std;

/* MEMBER FUNCTION IMPLEMENTATION */
/*********************************************/
Lexical_Analyzer::Lexical_Analyzer(string language_rules_directory, string user_prog_directory)
{
    Lexical_Analyzer_Generator lexical_analyzer_generator(language_rules_directory);
    Transition_Table minimized_dfa_table=lexical_analyzer_generator.generate_minimal_dfa();
    this->tokenizer = Tokenizer(minimized_dfa_table, user_prog_directory);
}

Lexical_Analyzer::~Lexical_Analyzer(void)
{

}

/* INTERFACE FUNCTIONS */
/*********************************************/
Token
Lexical_Analyzer::next_token()
{
    return this->tokenizer.next_token();
}
