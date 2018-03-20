/* IMPORT LIBRARIES */
/*********************************************/
#include "Tokenizer.h"

/* CONSTRUCTOR */
/*********************************************/
Tokenizer::Tokenizer(Transtion_Table minimized_dfa_table, string user_program_directory);
{
	/* read user file */
	User_Prog_Reader prog_reader(user_program_directory);
	this->user_program = prog_reader.read_file();
	/* initialize tokenizer attributes */
	this.minimized_dfa_table=minimized_dfa_table;
	current_index = 0;
	prog_size = user_program.size();

}

Tokenizer::~Tokenizer(void)
{
 	/* nothing */  
}


/* INTERFACE FUNCTIONS */
/*********************************************/
Token
next_token(void)
{
	/* initialize helpers */
	current_state = minimized_dfa_table.get_start_state();
	last_acceptance_state = NULL;
	last_acceptance_index = -1;
	token_buffer = "";

	while(true)
	{
		/* read new char into buffer */
		current_char = user_program.at(current_index);
		/* transition in table according to input char */
		current_state = find_transition(current_state, current_char);
		/* check current state */
		if(current_state == NULL)
		{
			/* i.e. no such transition */
			/* roll back to last acceptance */
			current_index = last_acceptance_index;
			vector<Token> conflicting_tokens = last_acceptance_state.get_tokens();
			/* PENDING IMPLMENTTION *********************************************************** */
			return get_correct_token(conflicting_tokens);
		}

		if(current_state.is_acceptance() == true)
		{
			last_acceptance_state = current_state;
			last_acceptance_index = current_index;
		}

		/* check to see end of string */
		current_index++;
		//if(current_index < prog_size) {break;}
	}


}



Token
get_correct_token(vector<Token> conflicting_tokens)
{
	Token result = conflicting_tokens.tail();

	for(Token t:conflicting_tokens)
	{
		/*
		**
		** HOW TO IMPLEMENT THIS FUNCTION
		**
		*/
	}

	return result
}


