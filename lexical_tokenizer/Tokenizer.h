#ifndef TOKENIZER_H_  /* Include guard */
#define TOKENIZER_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Tokenizer.h"
#include "lexical_analyzer_generator/data_structures/transition_table/Transition_Table.h"

using namespace std;

/* CLASS DEFINITIONS */
/*********************************************/
class Tokenizer
{
public:
    /* attributes */
    Transition_Table minimized_dfa_table;
    string user_prog;

    /* constructor */
    Tokenizer() ;
    Tokenizer(Transition_Table minimized_dfa_table, string user_program_directory);
    ~Tokenizer(void);

    /* interface functions */
    Token next_token();


};


#endif // COMMANDS_H_
