/*
 * Tokenizer.cpp
 * Created on: Mar 23, 2018
 * Author: Amr Hendy
 */

#include "../../../header/LexcialAnalyzer/Tokenizer/Tokenizer.h"

/* CONSTRUCTOR */
/*********************************************/
Tokenizer::Tokenizer(TransitionTable minimized_dfa_table, string user_program_directory)
{
    /* read user file */
    user_program = FileReader::readUserProgram(user_program_directory);
    /* initialize tokenizer attributes */
    Tokenizer::minimized_dfa_table = minimized_dfa_table;
    current_index = 0;
}


Tokenizer::Tokenizer()
{

}

Tokenizer::~Tokenizer()
{
    // TODO Auto-generated destructor stub
}


/* INTERFACE FUNCTIONS */
/*********************************************/
Token
Tokenizer::next_token()
{
    /* initialize helpers */
    CompositeState* current_state = minimized_dfa_table.get_start_state();
    CompositeState* last_acceptance_state;
    int last_acceptance_index = -1;
    int start_index = current_index ;

    while(current_index < (int) user_program.size())
    {
        /* read new char into buffer */
        char current_char = user_program.at(current_index);

        /* transition in table according to input char */
        current_state = minimized_dfa_table.toke_get_transition(current_state, current_char);
        /* check current state */

        if(current_state->get_size() == 0)
        {
            if(last_acceptance_index != -1)
            {
                string lexeme;
                lexeme = user_program.substr(start_index, last_acceptance_index - start_index + 1);
                current_index = last_acceptance_index + 1;
                vector<Rule> conflicting_rules = last_acceptance_state->get_rules();
                return get_correct_token(conflicting_rules, lexeme);
            }
            else
            {
                current_index = start_index + 1;
                if(current_char != ' ')
                    cout << "'" << user_program[start_index] << "'" << "\tError do not match any rules"<<  endl;
                return next_token();
            }
        }

        if(current_state->is_acceptance())
        {
            last_acceptance_state = current_state;
            last_acceptance_index = current_index;
        }
        current_index++;
    }


    if(last_acceptance_index != -1)
    {
        string lexeme;
        lexeme = user_program.substr(start_index, last_acceptance_index - start_index + 1);
        current_index = last_acceptance_index + 1;
        vector<Rule> conflicting_rules = last_acceptance_state->get_rules();
        last_acceptance_index = -1;
        return get_correct_token(conflicting_rules, lexeme);
    }
    else if(start_index == (int) user_program.size() )
    {
        return Token("INVALID","INVALID","INVALID");
    }
    else
    {
        current_index = start_index + 1;
        return next_token();
    }
}

Token
Tokenizer::get_correct_token(vector<Rule> conflicting_rules, string lexeme)
{
    Token result = Token("", "", "");
    int min_priority = 10000;
    for(Rule rule : conflicting_rules)
    {
        if(rule.getPriority() < min_priority)
        {
            min_priority = rule.getPriority();
            result = Token(rule.getRuleName(), rule.getRulePattern(), lexeme);
        }
    }
    return result;
}
