#ifndef TOKENIZER_H_  /* Include guard */
#define TOKENIZER_H_

/* IMPORT LIBRARIES */
/*********************************************/
#include <stdio.h>
#include <studio.h>
using namespace std;

/* CLASS DEFINITIONS */
/*********************************************/
class Tokenizer
{
	public:
	/* attributes */
	Transtion_Table minimized_dfa_table;
	String user_prog;

	/* constructor */
    Tokenizer(Transtion_Table minimized_dfa_table, string user_program_directory);
    ~Tokenizer(void);

    /* interface functions */
    Token next_token();
    
 
};


#endif // COMMANDS_H_