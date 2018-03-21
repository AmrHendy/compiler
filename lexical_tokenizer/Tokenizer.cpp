/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
#include "lexical_tokenizer/Tokenizer.h"
#include "lexical_analyzer_generator/data_structures/transition_table/Transition_Table.h"

using namespace std;


/* MEMBER FUNCTION IMPLEMENTATION */
/*********************************************/
Tokenizer::Tokenizer()
{

}

Tokenizer::~Tokenizer()
{

}

Tokenizer::Tokenizer(Transition_Table minimized_dfa_table, string user_program_directory)
{
    this->minimized_dfa_table = minimized_dfa_table;
    this->user_prog = user_program_directory ;
}

Token Tokenizer::next_token()
{

}
