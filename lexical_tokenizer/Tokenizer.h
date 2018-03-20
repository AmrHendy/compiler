#ifndef TOKENIZER_H_  /* Include guard */
#define TOKENIZER_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include "Transtion_Table.h"
#include <string>
#include "Token.h"
#include "User_Prog_Reader.h"

/* CLASS DEFINITIONS */
/*********************************************/
class Tokenizer
{
	public:
	/* attributes */
	Transtion_Table minimized_dfa_table;
	string user_prog;

	/* constructor */
    Tokenizer(Transtion_Table minimized_dfa_table, string user_program_directory);
    ~Tokenizer(void);

    /* interface functions */
    Token next_token();
    
    private:
    /* utility functions */
 	Token get_correct_token(vector<Token> conflicting_tokens);

};


#endif