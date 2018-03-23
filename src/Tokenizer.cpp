/*
 * Tokenizer.cpp
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */

#include "Tokenizer.h"

/* CONSTRUCTOR */
/*********************************************/
Tokenizer::Tokenizer(TransitionTable minimized_dfa_table, string user_program_directory)
{
	/* read user file */
	user_program = FileHandler::readUserProgram(user_program_directory);
	/* initialize tokenizer attributes */
	Tokenizer::minimized_dfa_table = minimized_dfa_table;
	current_index = 0;
}


Tokenizer::Tokenizer(){

}

Tokenizer::~Tokenizer() {
	// TODO Auto-generated destructor stub
}


/* INTERFACE FUNCTIONS */
/*********************************************/
Token
Tokenizer::next_token()
{
	/* initialize helpers */
	CompositeState current_state = minimized_dfa_table.get_start_state();
	CompositeState last_acceptance_state;
	int last_acceptance_index = -1;
	int start_index = current_index;

	while(true)
	{
		/* read new char into buffer */
		char current_char = user_program.at(current_index);

		/* transition in table according to input char */
		current_state = minimized_dfa_table.find_transition(current_state, current_char);
		/* check current state */
		if(current_state.isNull())
		{
			/* i.e. no such transition */
			/* roll back to last acceptance */
			//special case if last acccpetance index = -1;

			if(last_acceptance_index != -1){
				string lexeme;
				lexeme = user_program.substr(start_index, last_acceptance_index - start_index);
				current_index = last_acceptance_index + 1;
				vector<Rule> conflicting_rules = last_acceptance_state.get_matched_rules();
				return get_correct_token(conflicting_rules, lexeme);
			}
			else{
				current_index = start_index + 1;
				//report erros
				continue;
			}
		}

		if(current_state.is_acceptance() == true)
		{
			last_acceptance_state = current_state;
			last_acceptance_index = current_index;
		}
		current_index++;
	}
}



Token
Tokenizer::get_correct_token(vector<Rule> conflicting_rules, string lexeme)
{
	Token result = Token("", "", "");
	int max_priority = 0;
	for(Rule rule : conflicting_rules)
	{
		if(rule.getPriority() > max_priority){
			max_priority = rule.getPriority();
			result = Token(rule.getRuleName(), rule.getRulePattern(), lexeme);
		}
	}
	return result;
}
