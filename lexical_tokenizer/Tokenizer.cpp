/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
using namespace std;


/* MEMBER FUNCTION IMPLEMENTATION */
/*********************************************/
Tokenizer::Tokenizer(Transtion_Table minimized_dfa_table, string user_program_directory);
{
    this.minimized_dfa_table=minimized_dfa_table;
    this.user_program=read_user_prog();

}

Tokenizer::~Tokenizer(void)
{

}
